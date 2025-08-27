CMD:createactor(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new actid = Iter_Free(Actors), skinid, query[512];

	if(actid == -1)
		return Error(playerid, "Actor Full");

	if(sscanf(params, "d", skinid))
		return Usage(playerid, "/createactor [skinid]");

	if(skinid < 0 || skinid > 299)
        return Error(playerid, "Invalid skin ID. Skins range from 0 to 299.");

	new Float:x, Float:y, Float:z, Float:a;
	format(ActData[actid][actName], 128, "None");
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);
	ActData[actid][actSkin] = skinid;
	ActData[actid][actBizid] = -1;
	ActData[actid][actX] = x;
	ActData[actid][actY] = y;
	ActData[actid][actZ] = z;
	ActData[actid][actA] = a;
	ActData[actid][actVuln] = 1;
	ActData[actid][actAnim] = 0;
	ActData[actid][actInt] = GetPlayerInterior(playerid);
	ActData[actid][actVW] = GetPlayerVirtualWorld(playerid);

	SendStaffMessage(COLOR_RED, "%s telah membuat actor ID: %d.", pData[playerid][pAdminname], actid);
	Actor_Refresh(actid);
	Iter_Add(Actors, actid);
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO actors SET id='%d', vuln='%d'", actid, ActData[actid][actVuln]);
	mysql_tquery(g_SQL, query, "OnActorCreated", "i", actid);
	return 1;
}

CMD:gotoactor(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
	 return PermissionError(playerid);

	new actid;
	if(sscanf(params, "d", actid))
		return Usage(playerid, "/gotoactor [id]");

	if(!Iter_Contains(Actors, actid)) 
		return Error(playerid, "Invalid ID.");

	SetPlayerPos(playerid, ActData[actid][actX], ActData[actid][actY], ActData[actid][actZ]+3.5);
	SetPlayerInterior(playerid, ActData[actid][actInt]);
	SetPlayerVirtualWorld(playerid, ActData[actid][actVW]);
	return 1;
}

CMD:editactor(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	static
     actid,
      type[24],
       string[128];

	if(sscanf(params, "ds[24]S()[128]", actid, type, string))
	{
		Usage(playerid, "/editactor [id] [type]");
		SendClientMessage(playerid, COLOR_YELLOW, "[NAME]:{FFFFFF}position, skin, anim, name, delete");
		return 1;
	}

	if(!Iter_Contains(Actors, actid))
		return Error(playerid, "Invalid Actor ID");

	if(!strcmp(type, "position", true))
	{
		if(ActData[actid][actBizid] != -1)
			return Error(playerid, "Kamu tidak bisa merubah posisi actor");

		new Float:x, Float:y, Float:z, Float:a;
		GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, a);
		ActData[actid][actX] = x;
		ActData[actid][actY] = y;
		ActData[actid][actZ] = z;
		ActData[actid][actA] = a;
		ActData[actid][actInt] = GetPlayerInterior(playerid);
		ActData[actid][actVW] = GetPlayerVirtualWorld(playerid);

		Actor_Refresh(actid);
		Actor_Save(actid);
	}
	if(!strcmp(type, "skin", true))
	{
		new skinid;
		if(sscanf(string, "d", skinid))
			return Usage(playerid, "/editactor [id] [skin] [skinid]");

		if(skinid < 0 || skinid > 299)
        	return Error(playerid, "Invalid skin ID. Skins range from 0 to 299.");

		ActData[actid][actSkin] = skinid;
		Actor_Refresh(actid);
		Actor_Save(actid);
	}
	if(!strcmp(type, "anim", true))
	{
		new animid;
		if(sscanf(string, "d", animid))
		{
			Usage(playerid, "/editactor [id] [anim] [animid]");
			new str[1024];
			format(str, sizeof(str), ""YELLOW_E"0."WHITE_E" Disable Animations\n");
			format(str, sizeof(str), "%s"YELLOW_E"1."WHITE_E" Injured\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"2."WHITE_E" Handsup\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"3."WHITE_E" Sit\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"4."WHITE_E" Lean\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"5."WHITE_E" Dance\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"6."WHITE_E" Dealstance\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"7."WHITE_E" Riotchant\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"8."WHITE_E" Wave\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"9."WHITE_E" Hide\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"10."WHITE_E" Crossarms\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"11."WHITE_E" Laugh\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"12."WHITE_E" Talk\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"13."WHITE_E" Fucku\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"14."WHITE_E" Tired\n", str);
			format(str, sizeof(str), "%s"YELLOW_E"15."WHITE_E" Chairsit\n", str);
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "{ff0000}Anim ID Actor", str, "Yes", "");
			return 1;
		}

		if(animid < 0 || animid > 15)
			return Error(playerid, "Anim only 0-15!");

		ActData[actid][actAnim] = animid;
		Actor_Refresh(actid);
		Actor_Save(actid);
	}
	if(!strcmp(type, "name", true))
    {
    	if(ActData[actid][actBizid] != -1)
			return Error(playerid, "Kamu tidak bisa merubah nama actor");

        new text[128];
        if(sscanf(string, "s[128]", text))
            return Usage(playerid, "/editactor [id] [name] [actor name]");

        if(strlen(text) > 20)
            return Error(playerid, "Text tidak boleh lebih dari 20 character!");

        format(ActData[actid][actName], 128, text);
        Actor_Save(actid);
        Actor_Refresh(actid);

        SendStaffMessage(playerid,"Staff %s merubah name actor id : %d menjadi '%s'", pData[playerid][pAdminname], actid, ActData[actid][actName]);
    }
	if(!strcmp(type, "delete", true))
	{
		if(ActData[actid][actBizid] != -1)
			return Error(playerid, "Kamu tidak dapat menghapus actor yang terkait dengan!");
		
		new query[512];
		if(IsValidDynamicActor(ActData[actid][actObj]))
			DestroyDynamicActor(ActData[actid][actObj]);

		if(IsValidDynamic3DTextLabel(ActData[actid][actLabel]))
			DestroyDynamic3DTextLabel(ActData[actid][actLabel]);

		ActData[actid][actX] = ActData[actid][actY] = ActData[actid][actZ] = ActData[actid][actA] = 0;
		ActData[actid][actInt] = ActData[actid][actVW] = 0;

		Iter_Remove(Actors, actid);

		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM actors WHERE id=%d", actid);
		mysql_tquery(g_SQL, query);
		SendStaffMessage(COLOR_RED, "Staff %s menghapus Actor ID %d.", pData[playerid][pAdminname], actid);
	}
	return 1;
}