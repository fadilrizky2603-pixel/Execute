CMD:createsignal(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new sgid = Iter_Free(Signal), query[512];

	if(sgid == -1)
		return Error(playerid, "Can't add any more signal tower.");

	new Float: x, Float: y, Float: z, Float: a;
 	GetPlayerPos(playerid, x, y, z);
 	GetPlayerFacingAngle(playerid, a);
 	x += (3.0 * floatsin(-a, degrees));
	y += (3.0 * floatcos(-a, degrees));
	z -= 1.0;

	sgData[sgid][sgStatus] = 0;
	sgData[sgid][sgX] = x;
	sgData[sgid][sgY] = y;
	sgData[sgid][sgZ] = z;
	sgData[sgid][sgRX] = sgData[sgid][sgRY] = sgData[sgid][sgRZ] = 0.0;
	sgData[sgid][sgInt] = GetPlayerInterior(playerid);
	sgData[sgid][sgVW] = GetPlayerVirtualWorld(playerid);

	SendStaffMessage(COLOR_RED, "%s telah membuat signal tower ID: %d.", pData[playerid][pAdminname], sgid);
	Signal_Refresh(sgid);
	Iter_Add(Signal, sgid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO sigenal SET id='%d', status='%d'", sgid, sgData[sgid][sgStatus]);
	mysql_tquery(g_SQL, query, "OnSignalCreated", "i", sgid);
	return 1;
}

CMD:editsignal(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
    	return PermissionError(playerid);

    static
     sgid,
   	  type[24],
       string[128];

    if(sscanf(params, "ds[24]S()[128]", sgid, type, string))
    {
        Usage(playerid, "/editsignal [id] [name]");
        Names(playerid, "position, status, delete");
        return 1;
    }

    if(!Iter_Contains(Signal, sgid)) 
		return Error(playerid, "Invalid ID.");

	if(Signal_BeingEdited(sgid)) 
		return Error(playerid, "Can't edited specified signal tower because its being edited.");

	if(!strcmp(type, "position", true))
    {
    	if(pData[playerid][pEditing] != -1) 
			return Error(playerid, "You're already editing.");

    	if(!IsPlayerInRangeOfPoint(playerid, 30.0, sgData[sgid][sgX], sgData[sgid][sgY], sgData[sgid][sgZ])) 
			return Error(playerid, "You're not near the signal tower you want to edit.");

		pData[playerid][pEditing] = sgid;
		pData[playerid][pEditType] = EDIT_SIGNAL;
		EditDynamicObject(playerid, sgData[sgid][sgObj]);
    }
    if(!strcmp(type, "status", true))
    {
    	new status;

        if(sscanf(string, "d", status))
            return Usage(playerid, "/editsignal [id] [status] [statusid 1.Safe 2.Troubled]");

        if(status < 0 || status > 1)
        	return Error(playerid, "status tidak bisa kurang dari angka 0 dan lebih dari 1");

        if(status == 0)
        {
        	KillTimer(sgData[sgid][sgTimer]);
		    sgData[sgid][sgSeconds] = 0;
	    	sgData[sgid][sgTimer] = -1;
			sgData[sgid][sgStatus] = 0;

	        Signal_Save(sgid);
			Signal_Refresh(sgid);
		}
		if(status == 1)
		{
			sgData[sgid][sgSeconds] = 60 * 20;
			sgData[sgid][sgStatus] = 1;
	        Signal_Save(sgid);
			Signal_Refresh(sgid);
		}
		SendAdminMessage(COLOR_RED, "%s has adjusted the status of Signal Tower ID: %d to %d.", pData[playerid][pAdminname], sgid, status);
    }
    else if(!strcmp(type, "delete", true))
    {
		new query[512];
		if(IsValidDynamicObject(sgData[sgid][sgObj]))
			DestroyDynamicObject(sgData[sgid][sgObj]);

		if(IsValidDynamic3DTextLabel(sgData[sgid][sgLabel]))
			DestroyDynamic3DTextLabel(sgData[sgid][sgLabel]);

		sgData[sgid][sgX] = sgData[sgid][sgY] = sgData[sgid][sgZ] = 0;
		sgData[sgid][sgRX] = sgData[sgid][sgRY] = sgData[sgid][sgRZ] = 0.0;
		sgData[sgid][sgInt] = sgData[sgid][sgVW] = 0;
		sgData[sgid][sgObj] = -1;
		sgData[sgid][sgLabel] = Text3D: -1;

		KillTimer(sgData[sgid][sgTimer]);
	    sgData[sgid][sgSeconds] = 0;
    	sgData[sgid][sgTimer] = -1;

		Iter_Remove(Signal, sgid);
		
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM sigenal WHERE id=%d", sgid);
		mysql_tquery(g_SQL, query);
		SendStaffMessage(COLOR_RED, "Staff %s menghapus Signal Tower ID %d.", pData[playerid][pAdminname], sgid);
	}
    return 1;
}

CMD:gotosignal(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		PermissionError(playerid);

	new sgid;
	if(sscanf(params, "d", sgid))
		return Usage(playerid, "/gotosignal [id]");

	if(!Iter_Contains(Signal, sgid))
		return Error(playerid, "Invalid ID!");

	SetPlayerPos(playerid, sgData[sgid][sgX]+2.5, sgData[sgid][sgY]+2.5, sgData[sgid][sgZ]);
	SetPlayerInterior(playerid, sgData[sgid][sgInt]);
	SetPlayerVirtualWorld(playerid, sgData[sgid][sgVW]);

	Info(playerid, "Anda telah diteleportkan menuju Signal Tower ID: %d", sgid);
	return 1;
}

CMD:asignal(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return PermissionError(playerid);

	if(GetAdminSignal() <= 0)
		return Error(playerid, "Mission dealer sedang kosong.");

	new id, count = GetAdminSignal(), mission[2024], lstr[3024], status[1024];

	strcat(mission,"ID\tSTATUS\tLOCATION\tDISTANCE\n",sizeof(mission));
	Loop(itt, (count + 1), 1)
	{
		id = ReturnAdminSignalID(itt);
		if(sgData[id][sgStatus] == 0)
		{
			status = "{00ff00}Good";
		}
		else if(sgData[id][sgStatus] == 1)
		{
			status = "{ff0000}Troubled";
		}
		else
		{
			status = "{ff0000}Unknown";
		}
		if(itt == count)
		{
			format(lstr,sizeof(lstr), "%d.\t%s\t%s"WHITE_E"\t%0.0fm\n", id, status, GetLocation(sgData[id][sgX], sgData[id][sgY], sgData[id][sgZ]), GetPlayerDistanceFromPoint(playerid, sgData[id][sgX], sgData[id][sgY], sgData[id][sgZ]));
		}
		else format(lstr,sizeof(lstr), "%d.\t%s\t%s"WHITE_E"\t%0.0fm\n", id, status, GetLocation(sgData[id][sgX], sgData[id][sgY], sgData[id][sgZ]), GetPlayerDistanceFromPoint(playerid, sgData[id][sgX], sgData[id][sgY], sgData[id][sgZ]));
		strcat(mission, lstr, sizeof(mission));
	}
	ShowPlayerDialog(playerid, DIALOG_ADMIN_SIGNAL, DIALOG_STYLE_TABLIST_HEADERS,"Signal In City",mission,"Select","Cancel");
	return 1;
}