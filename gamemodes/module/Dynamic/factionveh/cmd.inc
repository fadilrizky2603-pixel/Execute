CMD:createsvpoint(playerid, const params[])
{
    if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);

	new svid = Iter_Free(SVPoint), type;
	if(sscanf(params, "d", type))
	{
		Usage(playerid, "/createvpoint [type]");
		Usage(playerid, "[TYPE]: 1.SAPD, 2.SAGS, 3.SAMD, 4.SANEW 5.SACF");
		return 1;
	}
	if(type <= 0 || type >= 6)
		return Error(playerid, "Type only 1-5");

	if(svid >= MAX_SVPOINT)
		return Error(playerid, "Jumlah svpoint dikota sudah terlalu penuh!");

	new Float:x, Float:y, Float:z, Float:a;
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);

	svData[svid][svType] = type;

	svData[svid][svPosX] = x;
	svData[svid][svPosY] = y;
	svData[svid][svPosZ] = z;
	svData[svid][svPosA] = a;

	svData[svid][svVw] = GetPlayerVirtualWorld(playerid);
	svData[svid][svInt] = GetPlayerInterior(playerid);

	Svpoint_Refresh(svid);
	Iter_Add(SVPoint, svid);

	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO faction_vehpoint SET id = '%d', type = '%d'", svid, svData[svid][svType]);
	mysql_tquery(g_SQL, query, "OnSvpointCreated", "d", svid);

    SendStaffMessage(COLOR_RED, "Staff %s has created faction spawnveh point id : %d", pData[playerid][pAdminname], svid);
	return 1;
}

CMD:deletesvpoint(playerid, const params[])
{
    if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);

	new svid;
	if(sscanf(params, "d", svid))
		return Usage(playerid, "/deletesvpoint [svid]");

	if(!Iter_Contains(SVPoint, svid))
		return Error(playerid, "Invalid spawn vehicle point ID!");

	if(IsValidDynamicPickup(svData[svid][svPickup]))
			DestroyDynamicPickup(svData[svid][svPickup]);

	if(IsValidDynamic3DTextLabel(svData[svid][svLabel]))
		DestroyDynamic3DTextLabel(svData[svid][svLabel]);

	svData[svid][svPosX] = 0.0;
	svData[svid][svPosY] = 0.0;
	svData[svid][svPosZ] = 0.0;
	svData[svid][svPosA] = 0.0;

	Iter_Remove(SVPoint, svid);

	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "DELETE FROM faction_vehpoint WHERE id = '%d'", svid);
	mysql_tquery(g_SQL, query);

    SendStaffMessage(COLOR_RED, "Staff %s has deleted faction spawnveh point id : %d", pData[playerid][pAdminname], svid);
	return 1;
}

CMD:gotosvpoint(playerid, const params[])
{
    if(pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);

    new svid;
    if(sscanf(params, "d", svid))
        return Usage(playerid, "/gotosvpoint [svid]");

    if(!Iter_Contains(SVPoint, svid))
        return Error(playerid, "Invalid Sv Point ID!");

    SetPlayerPos(playerid, svData[svid][svPosX], svData[svid][svPosY], svData[svid][svPosZ]);
    SetPlayerVirtualWorld(playerid, svData[svid][svVw]);
    SetPlayerInterior(playerid, svData[svid][svInt]);

    Info(playerid, "Kamu telah diteleport menuju Sv Point ID: %d", svid);
    return 1;
}

CMD:fspawnveh(playerid, const params[])
{
    foreach(new svid : SVPoint)
    {
        if(Iter_Contains(SVPoint, svid))
        {
            if(IsPlayerInRangeOfPoint(playerid, 3.5, svData[svid][svPosX], svData[svid][svPosY], svData[svid][svPosZ]))
            {
                if(pData[playerid][pFaction] != svData[svid][svType])
                    return Error(playerid, "Kamu bukan anggota fraksi ini!");

                pData[playerid][pGetSVPOINTID] = svid;
                Svpoint_Listmenu(playerid, svid);
            }
        }
    }
    return 1;
}

CMD:fdespawnveh(playerid, const params[])
{
    new vehicleid = GetPlayerVehicleID(playerid);
    foreach(new svid : SVPoint)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.5, svData[svid][svPosX], svData[svid][svPosY], svData[svid][svPosZ]))
        {
            if(pData[playerid][pFaction] != svData[svid][svType])
                return Error(playerid, "Kamu bukan anggota fraksi ini!");

            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
                return Error(playerid, "Kamu harus mengendarai kendaraan fraksi");

            pData[playerid][pGetSVPOINTID] = svid;

            foreach(new fvid : FactionVeh)
            {
                if(vehicleid == fvData[fvid][fvVeh])
                {
                    if(fvData[fvid][fvFaction] != svData[svid][svType])
                        return Error(playerid, "Kendaraan tersebut bukan berasal dari spawn point ini!");

                    Info(playerid, "Kamu telah memasukan kendaraan %s kedalam garasi", GetVehicleName(fvData[fvid][fvVeh]));
                    
                    RemovePlayerFromVehicle(playerid);

                    Delete3DTextLabel(fvData[fvid][fvLabel]);
                    fvData[fvid][fvLabel] = Text3D: -1;
                    
                    if(IsValidVehicle(fvData[fvid][fvVeh]))
                        DestroyVehicle(fvData[fvid][fvVeh]);

                    fvData[fvid][fvVeh] = 0;
                    fvData[fvid][fvFaction] = 0; 

                    Iter_Remove(FactionVeh, fvid);
                    return 1;
                }
            }
        }
    }
    return 1;
}