CMD:cmtext(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new mtid = Iter_Free(Matext), query[512];
	if(mtid == -1)
		return Error(playerid, "You cant create more matext!");

	new text[254];
	if(sscanf(params, "s", text))
		return Usage(playerid, "/cmtext [text]");

	new Float:x, Float:y, Float:z, Float:a;
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);

	x += 1.0 * floatsin(-a, degrees);
	y += 1.0 * floatcos(-a, degrees);

	format(mtData[mtid][mtText], 254, text);
	mtData[mtid][mtX] = x;
	mtData[mtid][mtY] = y;
	mtData[mtid][mtZ] = z;
	mtData[mtid][mtRX] = 0.0;
	mtData[mtid][mtRY] = 0.0;
	mtData[mtid][mtRZ] = a;
	mtData[mtid][mtSize] = 30; //Default Size adalah 30
    mtData[mtid][mtColor] = 1;
    mtData[mtid][mtBold] = 0;
    mtData[mtid][mtInt] = GetPlayerInterior(playerid);
    mtData[mtid][mtVW] = GetPlayerVirtualWorld(playerid);

    Matext_Refresh(mtid);
    Matext_Label(mtid);
    Iter_Add(Matext, mtid);
   	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO matext SET id='%d', text='%s'", mtid, mtData[mtid][mtText]);
	mysql_tquery(g_SQL, query, "OnMatextCreated", "i", mtid);
	return 1;
}

CMD:emtext(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

    static mtid, type[24], string[128];

	if(sscanf(params, "ds[24]S()[128]", mtid, type, string))
    {
        Usage(playerid, "/emtext [id] [name]");
        Names(playerid, "position, text, size, color, bold");
        return 1;
    }

    if(!Iter_Contains(Matext, mtid))
    	return Error(playerid, "Invalid ID");

    if(!IsPlayerInRangeOfPoint(playerid, 50.0, mtData[mtid][mtX], mtData[mtid][mtY], mtData[mtid][mtZ]))
    	return Error(playerid, "Kamu harus berjarak 50 meter dari id tersebut");
    
    if(Matext_BeingEdited(mtid)) 
		return Error(playerid, "Can't edited specified matext because its being edited.");

    if(!strcmp(type, "position", true))
    {
    	pData[playerid][pEditing] = mtid;
		pData[playerid][pEditType] = EDIT_MATE,
    	Matext_Label(mtid);
    	EditDynamicObject(playerid, mtData[mtid][mtObj]);
    }
    else if(!strcmp(type, "text", true))
    {
    	new txt[254];
    	if(sscanf(string, "s[254]", txt))
    		return Usage(playerid, "/emtext [id] [text] [write text]");

    	format(mtData[mtid][mtText], 254, txt);
    	Matext_Refresh(mtid);
    	Matext_Save(mtid);

    	SendStaffMessage(COLOR_RED, "%s adjusted text of matext ID: %d to (%s)", pData[playerid][pAdminname], mtid, txt);
    }
    else if(!strcmp(type, "size", true))
    {
    	new sze;
    	if(sscanf(string, "d", sze))
    		return Usage(playerid, "/emtext [id] [size] [size number] (default size 30)");

    	mtData[mtid][mtSize] = sze;
    	Matext_Refresh(mtid);
    	Matext_Save(mtid);

    	SendStaffMessage(COLOR_RED, "%s adjusted size text of matext ID: %d to %dpx", pData[playerid][pAdminname], mtid, sze);
    }
    else if(!strcmp(type, "color", true))
    {
    	new colorid;
    	if(sscanf(string, "d", colorid))
    	{
    		Usage(playerid, "/emtext [id] [color] [colorid]");
    		Names(playerid, "1. White | 2. Blue | 3. Red | 4. Yellow");
    		return 1;
    	}

   		if(colorid < 0 || colorid > 4)
    	return Error(playerid, "Color ID only 1-4!");

    	mtData[mtid][mtColor] = colorid;
	    Matext_Refresh(mtid);
	    Matext_Save(mtid);

		SendStaffMessage(COLOR_RED, "%s adjusted color text of matext ID: %d to %d", pData[playerid][pAdminname], mtid, colorid);
    }
    else if(!strcmp(type, "bold", true))
    {
    	new boldid;
    	if(sscanf(string, "d", boldid))
    		return Usage(playerid, "/emtext [id] [bold] (0.No || 1.Yes)");

    	if(boldid < 0 || boldid > 1)
    		return Error(playerid, "Type bold only 0 or 1!");

    	mtData[mtid][mtBold] = boldid;
    	Matext_Refresh(mtid);
    	Matext_Save(mtid);

    	SendStaffMessage(COLOR_RED, "%s adjusted bold text of matext ID: %d to %d", pData[playerid][pAdminname], mtid, boldid);
    }
    return 1;
}

CMD:dmtext(playerid, params[])
{
    if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
		
	new id, query[512];
	if(sscanf(params, "i", id)) 
		return Usage(playerid, "/dmtext [id]");

	if(!Iter_Contains(Matext, id)) 
		return Error(playerid, "Invalid ID.");

	if(Matext_BeingEdited(id)) 
		return Error(playerid, "Can't deleted specified matext because its being edited.");
	
	DestroyDynamicObject(mtData[id][mtObj]);
	DestroyDynamic3DTextLabel(mtData[id][mtLabel]);
	
	pData[playerid][pEditing] = -1;
	mtData[id][mtX] = mtData[id][mtY] = mtData[id][mtZ] = 0.0;
	mtData[id][mtRX] = mtData[id][mtRY] = mtData[id][mtRZ] = 0.0;
	mtData[id][mtInt] = mtData[id][mtVW] = 0;
	mtData[id][mtObj] = -1;
	mtData[id][mtLabel] = Text3D: -1;

	Iter_Remove(Matext, id);
	mysql_format(g_SQL, query, sizeof(query), "DELETE FROM matext WHERE id=%d", id);
	mysql_tquery(g_SQL, query);
	Servers(playerid, "Menghapus Matext ID %d.", id);
	return 1;
}

CMD:showmtid(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new count = 0;
	foreach(new mtid : Matext)
	{
		if(Iter_Contains(Matext, mtid))
		{
			Matext_Label(mtid);
		}
		count++;
	}
	SendStaffMessage(COLOR_RED, "%s telah menampilkan %d id textlabel material text", pData[playerid][pAdminname], count);
	return 1;
}

CMD:hidemtid(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new count = 0;
	foreach(new mtid : Matext)
	{
		if(Iter_Contains(Matext, mtid))
		{
			if(IsValidDynamic3DTextLabel(mtData[mtid][mtLabel]))
				DestroyDynamic3DTextLabel(mtData[mtid][mtLabel]);
		}
		count++;
	}
	SendStaffMessage(COLOR_RED, "%s telah menyembunyikan %d id text label pada material text", pData[playerid][pAdminname], count);
	return 1;
}