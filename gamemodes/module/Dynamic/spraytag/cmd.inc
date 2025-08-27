CMD:tag(playerid, const params[])
{
	new
	    type[24],
	    string[128];

	if (sscanf(params, "s[24]S()[128]", type, string))
 	{
	 	Usage(playerid, "/tag [names]");
	    Names(playerid, "Names:{FFFFFF} create, destroy, nearest");
		return 1;
	}	
	if(!strcmp(type, "create", true))
	{
		if(pData[playerid][pLevel] < 3)
			return ErrorMsg(playerid, "Level anda tidak mencukupi untuk membuat Tags (Lvl.3)");

		ShowPlayerDialog(playerid, DIALOG_SPRAYTAG_TEXT, DIALOG_STYLE_INPUT, "Tag - Create", "Please input the text:", "Set", "Close");
	}
	else if(!strcmp(type, "destroy", true))
	{
		if(pData[playerid][pAdmin] < 1)
			return PermissionError(playerid);
		
		new id;
		if(sscanf(string, "d", id))
			return SyntaxMsg(playerid, "/tag [destroy] [id]");

		if(!Iter_Contains(SprayTag, id))
			return ErrorMsg(playerid, "Spray Tag id yang anda masukan salah");

		SendAdminMessage(COLOR_RED, "%s telah menghapus tags [ID:%d]", pData[playerid][pAdminname], id);
		Tag_Delete(id);

	}
	else if(!strcmp(type, "nearest", true))
	{
		if(pData[playerid][pAdmin] < 1)
			return PermissionError(playerid);

		new Float:range, bool:has = false;
		if(sscanf(string, "f", range))
			return Usage(playerid, "/tag [nearest] [radius]");

		foreach(new i : SprayTag)
		{
			if(IsPlayerInRangeOfPoint(playerid, range, TagData[i][tagPos][0], TagData[i][tagPos][1], TagData[i][tagPos][2]))
			{
				SendClientMessageEx(playerid, -1, "ID: %d | Creator: %s | Font: %s", i, GetNameFromSQLID(TagData[i][tagOwner]), TagData[i][tagFont]);
				has = true;
			}
		}
		if(!has)
			return ErrorMsg(playerid, "Tidak ada Tags di radius terdekat");
	}
	return 1;
}

GetNameFromSQLID(sqlid)
{
	new query[128], Cache:execut, name[24];
	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `players` WHERE `pID` = '%d' LIMIT 1", sqlid);
	execut = mysql_query(g_SQL, query, true);
	if(cache_num_rows())
	{
		cache_get_value_name(0, "username", name, 24);
	}
	cache_delete(execut);
	return name;
}