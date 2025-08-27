CMD:createspeedcam(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
	
	new camid = Iter_Free(Speedcam), query[512];

	if(camid == -1) return Error(playerid, "You cant create more speedcam!");

	new maxspeed;
	if(sscanf(params, "d", maxspeed))
		return Usage(playerid, "/createspeedcam [maxspeed/mph]");

	if(maxspeed < 10 || maxspeed > 250)
		return Error(playerid, "Max speed only 10 - 250/Mph");

	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);

	camData[camid][camX] = x+2.0;
	camData[camid][camY] = y+2.0;
	camData[camid][camZ] = z+0.5;
	camData[camid][camRX] = camData[camid][camRY] = camData[camid][camRZ] = 0.0;
	camData[camid][camWorld] = GetPlayerVirtualWorld(playerid);
	camData[camid][camInt] = GetPlayerInterior(playerid);
	camData[camid][camSpeed] = maxspeed;

	SendStaffMessage(COLOR_RED, "%s telah membuat speedcam ID: %d.", pData[playerid][pAdminname], camid);
  	Speedcam_Refresh(camid);
	Iter_Add(Speedcam, camid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO speedcam SET ID='%d', camspeed='%d'", camid, camData[camid][camSpeed]);
	mysql_tquery(g_SQL, query, "OnSpeedcamCreated", "i", camid);
	return 1;
}

CMD:editspeedcam(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
    	return PermissionError(playerid);

    static
     camid,
      type[24],
       string[128];

    if(sscanf(params, "ds[24]S()[128]", camid, type, string))
    {
        Usage(playerid, "/editspeedcam [id] [name]");
        Names(playerid, "position, location, maxspeed, delete");
        return 1;
    }

    if(!Iter_Contains(Speedcam, camid)) 
		return Error(playerid, "Invalid ID.");

	if(Speedcam_BeingEdited(camid))
    	return Error(playerid, "Can't edited specified speedcam because its being edited.");

	if(!strcmp(type, "position", true))
    {
    	if(pData[playerid][pEditing] != -1) 
			return Error(playerid, "You're already editing.");

    	if(!IsPlayerInRangeOfPoint(playerid, 30.0, camData[camid][camX], camData[camid][camY], camData[camid][camZ])) 
			return Error(playerid, "You're not near the speedcam you want to edit.");

		pData[playerid][pEditing] = camid;
		pData[playerid][pEditType] = EDIT_SPEEDCAM;
		EditDynamicObject(playerid, camData[camid][camObj]);
    }
	if(!strcmp(type, "location", true))
    {
    	new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);

		camData[camid][camX] = x+2.0;
		camData[camid][camY] = y+2.0;
		camData[camid][camZ] = z+0.5;

		Speedcam_Refresh(camid);
        Speedcam_Save(camid);

        SendAdminMessage(COLOR_RED, "%s has adjusted the location of Speedcam ID: %d.", pData[playerid][pAdminname], camid);
    }
    if(!strcmp(type, "maxspeed", true))
    {
    	new ammount;

        if(sscanf(string, "d", ammount))
            return Usage(playerid, "/editspeedcam [id] [maxspeed] [ammount]");

        if(ammount < 10 || ammount > 250)
        	return Error(playerid, "Max speed tidak bisa kurang dari 10 dan lebih dari 250");

		camData[camid][camSpeed] = ammount;

		Speedcam_Refresh(camid);
        Speedcam_Save(camid);

		SendAdminMessage(COLOR_RED, "%s has adjusted the maxspeed of Speedcam ID: %d to %d/Mph.", pData[playerid][pAdminname], camid, ammount);
    }
    else if(!strcmp(type, "delete", true))
    {
		new query[512];
		if(IsValidDynamicObject(camData[camid][camObj]))
			DestroyDynamicObject(camData[camid][camObj]);

		if(IsValidDynamic3DTextLabel(camData[camid][camLabel]))
			DestroyDynamic3DTextLabel(camData[camid][camLabel]);

		camData[camid][camX] = camData[camid][camY] = camData[camid][camZ] = camData[camid][camRX] = camData[camid][camRY] = camData[camid][camRZ] = 0.0;
		camData[camid][camWorld] = camData[camid][camInt] = 0;
		camData[camid][camObj] = -1;
		camData[camid][camLabel] = Text3D: -1;

		Iter_Remove(Speedcam, camid);
		
		mysql_format(g_SQL, query, sizeof(query), " speedcam WHERE id=%d", camid);
		mysql_tquery(g_SQL, query);
		SendStaffMessage(COLOR_RED, "Staff %s menghapus Speedcam ID %d.", pData[playerid][pAdminname], camid);
	}
    return 1;
}

CMD:gotospeedcam(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return PermissionError(playerid);

	new camid;
	if(sscanf(params, "d", camid))
		return Usage(playerid, "/gotospeedcam [id]");

	if(!Iter_Contains(Speedcam, camid))
		return Error(playerid, "Invalid ID.");

	SetPlayerPos(playerid, camData[camid][camX]+0.5, camData[camid][camY]+0.5, camData[camid][camZ]+0.5);
	SetPlayerInterior(playerid, camData[camid][camInt]);
	SetPlayerVirtualWorld(playerid, camData[camid][camWorld]);
	Info(playerid, "Kamu telah diteleport menuju speedcam id: %d", camid);
	return 1;
}