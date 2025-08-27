CMD:creategarkot(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new gkid = Iter_Free(Garkot), query[512];

	if(gkid == -1)
		return Error(playerid, "You cant create more park point!");

	GetPlayerPos(playerid, gkData[gkid][gkX], gkData[gkid][gkY],gkData[gkid][gkZ]);
	GetPlayerFacingAngle(playerid, gkData[gkid][gkA]);
	gkData[gkid][gkInt] = GetPlayerInterior(playerid);
	gkData[gkid][gkVW] = GetPlayerVirtualWorld(playerid);

	Garkot_Refresh(gkid);
	Iter_Add(Garkot, gkid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO garkot SET id='%d'", gkid);
	mysql_tquery(g_SQL, query, "OnParkCreated", "i", gkid);
	return 1;
}

function OnParkCreated(gkid)
{
	Garkot_Save(gkid);
	return 1;
}

CMD:editgarkot(playerid, params[])
{
    static
        gkid,
        type[24],
        string[128];

    if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);

    if(sscanf(params, "ds[24]S()[128]", gkid, type, string))
    {
        Usage(playerid, "/editpark [id] [name]");
        SendClientMessage(playerid, COLOR_YELLOW, "[NAMES]:{FFFFFF} location, delete, spawn");
        return 1;
    }

    if(gkid < 0 || gkid >= MAX_GARKOT)
        return Error(playerid, "You have specified an invalid ID.");

	if(!Iter_Contains(Garkot, gkid))
		return Error(playerid, "The garkot you specified ID of doesn't exist.");

    if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, gkData[gkid][gkX], gkData[gkid][gkY],gkData[gkid][gkZ]);
		GetPlayerFacingAngle(playerid, gkData[gkid][gkA]);
		gkData[gkid][gkInt] = GetPlayerInterior(playerid);
		gkData[gkid][gkVW] = GetPlayerVirtualWorld(playerid);
        Garkot_Save(gkid);
		Garkot_Refresh(gkid);

        SendAdminMessage(COLOR_RED, "%s has adjusted the location of garkot ID: %d.", pData[playerid][pAdminname], gkid);
    }
    else if(!strcmp(type, "delete",true))
    {
    	if(IsValidDynamic3DTextLabel(gkData[gkid][gkText]))
			DestroyDynamic3DTextLabel(gkData[gkid][gkText]);

		if(IsValidDynamicPickup(gkData[gkid][gkPickup]))
			DestroyDynamicPickup(gkData[gkid][gkPickup]);

		if(IsValidDynamicArea(gkData[gkid][gkArea]))
			DestroyDynamicArea(gkData[gkid][gkArea]);

		if(IsValidDynamicObject(gkData[gkid][gkObject]))
			DestroyDynamicObject(gkData[gkid][gkObject]);

		if(IsValidDynamicPickup(gkData[gkid][sgkPickup]))
			DestroyDynamicPickup(gkData[gkid][sgkPickup]);

		if(IsValidDynamicArea(gkData[gkid][sgkArea]))
			DestroyDynamicArea(gkData[gkid][sgkArea]);

		if(IsValidDynamicObject(gkData[gkid][sgkObject]))
			DestroyDynamicObject(gkData[gkid][sgkObject]);

        if(IsValidDynamicMapIcon(gkData[gkid][garkotmap]))
			DestroyDynamicMapIcon(gkData[gkid][garkotmap]);
		
		gkData[gkid][gkX] = 0;
		gkData[gkid][gkY] = 0;
		gkData[gkid][gkZ] = 0;
		gkData[gkid][gkA] = 0;
		gkData[gkid][gkInt] = 0;
		gkData[gkid][gkVW] = 0;

		gkData[gkid][gkPickup] = -1;
		
		Iter_Remove(Garkot, gkid);

		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM garkot WHERE id=%d", gkid);
		mysql_tquery(g_SQL, query);
        SendAdminMessage(COLOR_RED, "%s has delete garkot ID: %d.", pData[playerid][pAdminname], gkid);
    }
    else if(!strcmp(type, "spawn", true))
    {
		GetPlayerPos(playerid, gkData[gkid][sgkX], gkData[gkid][sgkY],gkData[gkid][sgkZ]);
		GetPlayerFacingAngle(playerid, gkData[gkid][sgkA]);
        Garkot_Save(gkid);
		Garkot_Refresh(gkid);

        SendAdminMessage(COLOR_RED, "%s has adjusted the spawn vehicle point of Park ID: %d.", pData[playerid][pAdminname], gkid);
    }
	return 1;
}

CMD:parkveh(playerid, const params[])
{
	new vehid = GetPlayerVehicleID(playerid), count = 0;

	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
		return Error(playerid, "Kamu harus mengendarai kendaraan");

	foreach(new gkid : Garkot)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, gkData[gkid][sgkX], gkData[gkid][sgkY],gkData[gkid][sgkZ]))
		{
			count++;
            foreach(new ii : PVehicles)
            {
                if(vehid == pvData[ii][cVeh])
                {
                    if(pvData[ii][cOwner] == pData[playerid][pID])
                    {
                        if(!IsValidVehicle(pvData[ii][cVeh]))
                            return ErrorMsg(playerid, "Anda tidak memiliki kendaraan di Garkot ini");
                        
                        Vehicle_GetStatus(ii);

                        new strings[150];
						format(strings, sizeof(strings), "Kendaraan ~y~%s ~w~anda berhasil di parkirkan (~y~%d~w~)", GetVehicleName(pvData[ii][cVeh]), gkid);
						InfoTD_MSG(playerid, 4000, strings);
						RemoveVehicleToys(pvData[ii][cVeh]);
						RemovePlayerFromVehicle(playerid);
						SetTimerEx("TimerUntogglePlayer", 8000, 0, "i", playerid);
						if(IsValidVehicle(pvData[ii][cVeh]))
							DestroyVehicle(pvData[ii][cVeh]);

						pvData[ii][cParkid] = gkid;
						pvData[ii][cVeh] = 0;
						for (new ai = 0; ai != MAX_CAR_STORAGE; ai++) {
							CarStorage[ii][ai][cItemExists] = false;
							CarStorage[ii][ai][cItemModel] = 0;
							CarStorage[ii][ai][cItemQuantity] = 0;
							pData[playerid][pBeratBagasi] = 0;
						}
					}
					else return ErrorMsg(playerid, "Kendaraan ini bukan milik anda");
				}
			}
		}
	}

	if(count < 1)
		return ErrorMsg(playerid, "Anda harus berada didekat point public garage");

	return 1;
}

CMD:pickveh(playerid, const params[])
{
	//new msg2[512];
	new count = 0;
	//format(msg2, sizeof(msg2), "#\tModel\n");
	foreach(new gkid : Garkot)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, gkData[gkid][gkX], gkData[gkid][gkY],gkData[gkid][gkZ]))
		{
			count++;
			foreach(new i : PVehicles)
			{
				if(pvData[i][cOwner] == pData[playerid][pID])
				{
					if(gkData[gkid][gkX] == 0) return ErrorMsg(playerid, "Garkot ini belum memiliki spawn point, hubungi Administrator");
					pData[playerid][pGetPARKID] = gkid;
					
					if(GetPVehINPARK(playerid) <= 0)
						return Error(playerid, "Tidak ada kendaraanmu yang terparkir disini");

					/*if(pvData[i][cParkid] == gkid && pvData[i][cClaim] == 0)
					{
						format(msg2, sizeof(msg2), "%s%d\t%s\n", msg2, pvData[i][cVeh], GetVehicleModelName(pvData[i][cModel]));
					}
					new string[1024];
					format(string, sizeof(string), "Park Menu (ID: %d)", pData[playerid][pGetPARKID]);
					ShowPlayerDialog(playerid, GARKOT_PICKUP, DIALOG_STYLE_TABLIST_HEADERS, string, msg2, "Select", "Close");*/
					ShowGarasiTD(playerid, true);
					SelectTextDraw(playerid, COLOR_RED);

					new rawr = GetPVehINPARK(playerid);

					Loop(itt, (rawr + 1), 1)
					{
						new garkotveh = ReturnPVehParkID(playerid, itt);
						PlayerTextDrawSetPreviewModel(playerid, GarasiTD[playerid][44 + (itt - 1) * 3], pvData[garkotveh][cModel]);
						PlayerTextDrawSetString(playerid, GarasiTD[playerid][32 + (itt - 1) * 2], GetVehicleModelName(pvData[garkotveh][cModel]));

						// Show TextDraws untuk setiap kendaraan
						PlayerTextDrawShow(playerid, GarasiTD[playerid][24 + (itt - 1)]);
						PlayerTextDrawShow(playerid, GarasiTD[playerid][28 + (itt - 1)]);
						PlayerTextDrawShow(playerid, GarasiTD[playerid][32 + (itt - 1) * 2]);
						PlayerTextDrawShow(playerid, GarasiTD[playerid][33 + (itt - 1) * 2]);
						PlayerTextDrawShow(playerid, GarasiTD[playerid][40 + (itt - 1)]);
						PlayerTextDrawShow(playerid, GarasiTD[playerid][44 + (itt - 1) * 3]);
						PlayerTextDrawShow(playerid, GarasiTD[playerid][45 + (itt - 1) * 3]);
						PlayerTextDrawShow(playerid, GarasiTD[playerid][46 + (itt - 1) * 3]);
					}
				}
			}
		}
	}

	if(count < 1)
		return ErrorMsg(playerid, "Anda harus berada didekat point Public Garage");

	return 1;
}

CMD:gotopark(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return PermissionError(playerid);

	new gkid;
	if(sscanf(params, "d", gkid))
		return Usage(playerid, "/gotopark [park id]");

	if(!Iter_Contains(Garkot, gkid))
		return Error(playerid, "Invalid Park ID!");
	
	SetPlayerPos(playerid, gkData[gkid][gkX], gkData[gkid][gkY],gkData[gkid][gkZ] + 3.0);
	SetPlayerFacingAngle(playerid, gkData[gkid][gkA]);
	Info(playerid, "Anda telah diteleport menuju park id %d", gkid);
	return 1;
}