Tag_Create(playerid)
{
	new id = Iter_Free(SprayTag), Float:x, Float:y, Float:z, Float:a;
	if(id != INVALID_ITERATOR_SLOT)
	{
		GetPlayerPos(playerid, x,y,z);
		GetPlayerFacingAngle(playerid, a);
		format(TagData[id][tagText], 64, TagText[playerid]);
		format(TagData[id][tagFont], 24, TagFont[playerid]);
		TagData[id][tagPos][0] = x;
		TagData[id][tagPos][1] = y;
		TagData[id][tagPos][2] = z; 
		TagData[id][tagPos][3] = 0.0;
		TagData[id][tagPos][4] = 0.0;
		TagData[id][tagPos][5] = a - 90.0;
		TagData[id][tagBold] = TagBold[playerid];
		TagData[id][tagColor] = TagColor[playerid];
		TagData[id][tagSize] = TagSize[playerid];
		TagData[id][tagOwner] = pData[playerid][pID];
		TagData[id][tagInterior] = GetPlayerInterior(playerid);
		TagData[id][tagWorld] = GetPlayerVirtualWorld(playerid);

		Iter_Add(SprayTag, id);

		Tag_Spawn(id);

		mysql_tquery(g_SQL, "INSERT INTO `tags` (`Size`) VALUES(0)", "OnSprayTagCreated", "d", id);

		return id;
	}
	return INVALID_ITERATOR_SLOT;
}

Tag_Delete(id)
{
	if(!Iter_Contains(SprayTag, id))
		return 1;

	new query[128];
	mysql_format(g_SQL, query, 128, "DELETE FROM `tags` WHERE `ID` = '%d'", TagData[id][tagID]);
	mysql_tquery(g_SQL, query);

	if(IsValidDynamicObject(TagData[id][tagObject]))
		DestroyDynamicObject(TagData[id][tagObject]);

	Iter_Remove(SprayTag, id);
	return 1;
}

Tag_Spawn(id)
{
	TagData[id][tagObject] = CreateDynamicObject(19483, TagData[id][tagPos][0], TagData[id][tagPos][1], TagData[id][tagPos][2], TagData[id][tagPos][3], TagData[id][tagPos][4], TagData[id][tagPos][5], TagData[id][tagWorld], TagData[id][tagInterior], -1, 30.0, 30.0);

	SetDynamicObjectMaterialText(
		TagData[id][tagObject],
		0,
		TagData[id][tagText],
		OBJECT_MATERIAL_SIZE_512x512,
		TagData[id][tagFont],
		TagData[id][tagSize],
		TagData[id][tagBold],
		TagData[id][tagColor]
	);

	return 1;
}

ShowTagSetup(playerid)
{
	ShowPlayerDialog(playerid, DIALOG_SPRAYTAG, DIALOG_STYLE_LIST, "Tag - Setup", "Font\nFont Size\nToggle Bold\nText Color\n{FFFF00}Create", "Select", "Close");
	return 1;
}

HexToInt(const string:string[])
{
	if(!string[0])
  	{
  		return 0;
	}
	
  	new cur = 1;
  	new res = 0;
  	
  	for(new i = strlen(string); i > 0; i--)
 	{
  		if(string[i - 1] < 58)
  		{
		  	res= res + cur * (string[i - 1] - 48);
  		}
  		else
  		{
	  		res = res + cur * (string[i - 1] - 65 + 10);
		}
    	cur = cur * 16;
  	}
	return res;
}

Tag_Save(id)
{
	if(!Iter_Contains(SprayTag, id))
		return 1;

	new query[1012];
	mysql_format(g_SQL, query, sizeof(query), "UPDATE `tags` SET ");
	mysql_format(g_SQL, query, sizeof(query), "%s`PosX` = '%f', ", query, TagData[id][tagPos][0]);
	mysql_format(g_SQL, query, sizeof(query), "%s`PosY` = '%f', ", query, TagData[id][tagPos][1]);
	mysql_format(g_SQL, query, sizeof(query), "%s`PosZ` = '%f', ", query, TagData[id][tagPos][2]);
	mysql_format(g_SQL, query, sizeof(query), "%s`RotX` = '%f', ", query, TagData[id][tagPos][3]);
	mysql_format(g_SQL, query, sizeof(query), "%s`RotY` = '%f', ", query, TagData[id][tagPos][4]);
	mysql_format(g_SQL, query, sizeof(query), "%s`RotZ` = '%f', ", query, TagData[id][tagPos][5]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Interior` = '%d', ", query, TagData[id][tagInterior]);
	mysql_format(g_SQL, query, sizeof(query), "%s`World` = '%d', ", query, TagData[id][tagWorld]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Font` = '%s', ", query, TagData[id][tagFont]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Text` = '%s', ", query, TagData[id][tagText]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Bold` = '%d', ", query, TagData[id][tagBold]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Size` = '%d', ", query, TagData[id][tagSize]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Color` = '%d', ", query, TagData[id][tagColor]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Owner` = '%d' ", query, TagData[id][tagOwner]);
	mysql_format(g_SQL, query, sizeof(query), "%sWHERE `ID` = '%d'", query, TagData[id][tagID]);
	mysql_query(g_SQL, query, true);
	return 1;
}