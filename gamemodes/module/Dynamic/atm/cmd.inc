CMD:createatm(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
		
	new id = Iter_Free(ATMS), query[512];
	if(id == -1) return Error(playerid, "Can't add any more ATM.");
 	new Float: x, Float: y, Float: z;
 	GetPlayerPos(playerid, x, y, z);
 	/*GetPlayerFacingAngle(playerid, a);
 	x += (3.0 * floatsin(-a, degrees));
	y += (3.0 * floatcos(-a, degrees));
	z -= 1.0;*/
	
	AtmData[id][atmX] = x;
	AtmData[id][atmY] = y;
	AtmData[id][atmZ] = z;
	AtmData[id][atmRX] = AtmData[id][atmRY] = AtmData[id][atmRZ] = 0.0;
	AtmData[id][atmInt] = GetPlayerInterior(playerid);
	AtmData[id][atmWorld] = GetPlayerVirtualWorld(playerid);
	AtmData[id][atmStatus] = 0;
	
	Atm_Refresh(id);
	Iter_Add(ATMS, id);
	
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO atms SET id='%d', posx='%f', posy='%f', posz='%f', posrx='%f', posry='%f', posrz='%f', interior='%d', world='%d', status='%d'", id, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ], AtmData[id][atmRX], AtmData[id][atmRY], AtmData[id][atmRZ], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid), AtmData[id][atmStatus]);
	mysql_tquery(g_SQL, query, "OnAtmCreated", "ii", playerid, id);
	return 1;
}

CMD:editatm(playerid, params[])
{
    if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
	
	if(pData[playerid][pEditing] != -1) return Error(playerid, "You're already editing.");

	static
    id,
     type[24],
      string[128];

    if(sscanf(params, "ds[24]S()[128]", id, type, string))
    {
        Usage(playerid, "/editatm [id] [name]");
        SendClientMessage(playerid, COLOR_YELLOW, "[NAMES]:{FFFFFF} position, status");
        return 1;
    }

	if(!Iter_Contains(ATMS, id))
		return Error(playerid, "Invalid ID.");

	if(!strcmp(type, "position", true))
	{
		if(!IsPlayerInRangeOfPoint(playerid, 30.0, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]))
			return Error(playerid, "You're not near the atm you want to edit.");

		pData[playerid][pEditing] = id;
		pData[playerid][pEditType] = EDIT_ATM;
		EditDynamicObject(playerid, AtmData[id][atmObjID]);
	}
	else if(!strcmp(type, "status", true))
	{
		new statusid;
		if(sscanf(string, "d", statusid))
			return Usage(playerid, "/editatm [id] [statusid] (0. Good || 1. Not Good)");

		if(statusid < 0 || statusid > 1)
			return Error(playerid, "status id only 0 or 1");

		AtmData[id][atmStatus] = statusid;

		Atm_Refresh(id);
		Atm_Save(id);

		SendAdminMessage(COLOR_RED, "%s has adjusted atm status ID: %d to %d.", pData[playerid][pAdminname], id, statusid);
	}
	return 1;
}

CMD:removeatm(playerid, params[])
{
    if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
		
	new id, query[512];
	if(sscanf(params, "i", id)) return Usage(playerid, "/removeatm [id]");
	if(!Iter_Contains(ATMS, id)) return Error(playerid, "Invalid ID.");
	
	if(Atm_BeingEdited(id)) return Error(playerid, "Can't remove specified atm because its being edited.");
	DestroyDynamicObject(AtmData[id][atmObjID]);
	DestroyDynamic3DTextLabel(AtmData[id][atmLabel]);
	
	AtmData[id][atmX] = AtmData[id][atmY] = AtmData[id][atmZ] = AtmData[id][atmRX] = AtmData[id][atmRY] = AtmData[id][atmRZ] = 0.0;
	AtmData[id][atmInt] = AtmData[id][atmWorld] = 0;
	AtmData[id][atmObjID] = -1;
	AtmData[id][atmLabel] = Text3D: -1;
	Iter_Remove(ATMS, id);
	
	mysql_format(g_SQL, query, sizeof(query), "DELETE FROM atms WHERE id=%d", id);
	mysql_tquery(g_SQL, query);
	Servers(playerid, "Menghapus ID Atm %d.", id);
	return 1;
}

CMD:gotoatm(playerid, params[])
{
	new id;
	if(pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
		
	if(sscanf(params, "d", id))
		return Usage(playerid, "/gotoatm [id]");
	if(!Iter_Contains(ATMS, id)) return Error(playerid, "ATM ID tidak ada.");
	
	SetPlayerPosition(playerid, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ], 2.0);
    SetPlayerInterior(playerid, AtmData[id][atmInt]);
    SetPlayerVirtualWorld(playerid, AtmData[id][atmWorld]);
	Servers(playerid, "Teleport ke ID ATM %d", id);
	return 1;
}