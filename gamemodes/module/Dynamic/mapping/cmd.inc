CMD:mappinghelp(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new line3[2480];
	strcat(line3, ""WHITE_E"Mapping Commands:"LB2_E"\n\n\
 	/cobject /dobject /eobject /showmtl /hidemtl\n\
 	/cmtext /dmtext /emtext /showmtid /hidemtid");
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""ORANGE_E"MAPPING SYSTEM"YELLOW_E" COMMANDS", line3, "OK","");
	return 1;
}

CMD:showmtl(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new count = 0;
	foreach(new i : MAPO)
	{
		if(Iter_Contains(MAPO, i))
		{
			if(IsValidDynamic3DTextLabel(MapoData[i][mapoLabel]))
				DestroyDynamic3DTextLabel(MapoData[i][mapoLabel]);

			new str[128];
			format(str, sizeof(str), "[ID: %d]\n Object Model: %d", i, MapoData[i][mapoObject]);
			MapoData[i][mapoLabel] = CreateDynamic3DTextLabel(str, COLOR_LIGHTGREEN, MapoData[i][mapoX], MapoData[i][mapoY], MapoData[i][mapoZ] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, MapoData[i][mapoWorld], MapoData[i][mapoInt], -1, 10.0);
		}
		count++;
	}
	SendStaffMessage(COLOR_RED, "%s telah menampilkan %d id textlabel object mapping", pData[playerid][pAdminname], count);
	return 1;
}

CMD:hidemtl(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new count = 0;
	foreach(new i : MAPO)
	{
		if(Iter_Contains(MAPO, i))
		{
			if(IsValidDynamic3DTextLabel(MapoData[i][mapoLabel]))
				DestroyDynamic3DTextLabel(MapoData[i][mapoLabel]);
		}
		count++;
	}
	SendStaffMessage(COLOR_RED, "%s telah menyembunyikan %d id text label pada object mapping", pData[playerid][pAdminname], count);
	return 1;
}

CMD:cobject(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
	
	new objectid;
	if(sscanf(params, "i", objectid)) 
	{
		Usage(playerid, "/cobject [objectid]");
		return 1;
	}
	new id = Iter_Free(MAPO), query[512];
	if(id == -1) return Error(playerid, "Can't add any more Object.");

	new Float: x, Float: y, Float: z, Float: a;
 	GetPlayerPos(playerid, x, y, z);
 	GetPlayerFacingAngle(playerid, a);
 	x += (3.0 * floatsin(-a, degrees));
	y += (3.0 * floatcos(-a, degrees));
	z -= 1.0;

	MapoData[id][mapoObject] = objectid;
	MapoData[id][mapoX] = x;
	MapoData[id][mapoY] = y;
	MapoData[id][mapoZ] = z;
	MapoData[id][mapoRX] = MapoData[id][mapoRY] = MapoData[id][mapoRZ] = 0.0;
	MapoData[id][mapoInt] = GetPlayerInterior(playerid);
	MapoData[id][mapoWorld] = GetPlayerVirtualWorld(playerid);
	
	SendAdminMessage(COLOR_RED, "%s telah membuat object ID: %d.", pData[playerid][pAdminname], id);

	Mapo_Refresh(id);
	Iter_Add(MAPO, id);
	
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO mappingingame SET id='%d', objectmodel='%d', posx='%f', posy='%f', posz='%f', posrx='%f', posry='%f', posrz='%f', interior='%d', world='%d'", id, MapoData[id][mapoObject], MapoData[id][mapoX], MapoData[id][mapoY], MapoData[id][mapoZ], MapoData[id][mapoRX], MapoData[id][mapoRY], MapoData[id][mapoRZ], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
	mysql_tquery(g_SQL, query, "OnMapoCreated", "ii", playerid, id);
	return 1;
}

CMD:eobject(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
    	return PermissionError(playerid);

    static
        mid,
        type[24],
         string[128];

    if(sscanf(params, "ds[24]S()[128]", mid, type, string))
    {
        Usage(playerid, "/eobject [id] [name]");
        Names(playerid, "position, object");
        return 1;
    }

    if(!Iter_Contains(MAPO, mid)) 
		return Error(playerid, "Invalid ID.");

	if(Mapo_BeingEdited(mid)) 
		return Error(playerid, "Can't edited specified object because its being edited.");

    if(!strcmp(type, "position", true))
    {
    	if(pData[playerid][pEditing] != -1) 
			return Error(playerid, "You're already editing.");

    	if(!IsPlayerInRangeOfPoint(playerid, 30.0, MapoData[mid][mapoX], MapoData[mid][mapoY], MapoData[mid][mapoZ])) 
			return Error(playerid, "You're not near the atm you want to edit.");

		pData[playerid][pEditing] = mid;
		pData[playerid][pEditType] = EDIT_MAP;
		EditDynamicObject(playerid, MapoData[mid][mapoObjID]);
    }
    else if(!strcmp(type, "object", true))
    {
    	if(pData[playerid][pEditing] != -1) 
			return Error(playerid, "You're already editing.");

    	if(!IsPlayerInRangeOfPoint(playerid, 30.0, MapoData[mid][mapoX], MapoData[mid][mapoY], MapoData[mid][mapoZ])) 
			return Error(playerid, "You're not near the atm you want to edit.");

        new omodel;
        if(sscanf(string, "d", omodel))
            return Usage(playerid, "/eobject [id] [object] [objectid]");

		MapoData[mid][mapoObject] = omodel;
		Mapo_Refresh(mid);
		Mapo_Save(mid);
    }
    return 1;
}

CMD:dobject(playerid, params[])
{
    if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
		
	new id, query[512];
	if(sscanf(params, "i", id)) return Usage(playerid, "/dobject [id]");
	if(!Iter_Contains(MAPO, id)) return Error(playerid, "Invalid ID.");
	if(Mapo_BeingEdited(id))  return Error(playerid, "Can't deleted specified object because its being edited.");
	
	DestroyDynamicObject(MapoData[id][mapoObjID]);
	DestroyDynamic3DTextLabel(MapoData[id][mapoLabel]);
	
	pData[playerid][pEditing] = -1;
	MapoData[id][mapoX] = MapoData[id][mapoY] = MapoData[id][mapoZ] = MapoData[id][mapoRX] = MapoData[id][mapoRY] = MapoData[id][mapoRZ] = 0.0;
	MapoData[id][mapoInt] = MapoData[id][mapoWorld] = 0;
	MapoData[id][mapoObjID] = -1;
	MapoData[id][mapoLabel] = Text3D: -1;
	Iter_Remove(MAPO, id);
	DestroyDynamicObject(MapoData[id][mapoObjID]);
	mysql_format(g_SQL, query, sizeof(query), "DELETE FROM mappingingame WHERE id=%d", id);
	mysql_tquery(g_SQL, query);
	Servers(playerid, "Menghapus ID Object %d.", id);
	return 1;
}

CMD:gotoobj(playerid, params[])
{
	new id;
	if(pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
		
	if(sscanf(params, "d", id))
		return Usage(playerid, "/gotoobject [id]");
	if(!Iter_Contains(MAPO, id)) return Error(playerid, "MAPO ID tidak ada.");
	
	SetPlayerPosition(playerid, MapoData[id][mapoX], MapoData[id][mapoY], MapoData[id][mapoZ], 2.0);
    SetPlayerInterior(playerid, MapoData[id][mapoInt]);
    SetPlayerVirtualWorld(playerid, MapoData[id][mapoWorld]);
	Servers(playerid, "Teleport ke ID MAPO %d", id);
	return 1;
}
