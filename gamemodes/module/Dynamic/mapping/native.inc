Mapo_Save(id)
{
	new cQuery[512];
	format(cQuery, sizeof(cQuery), "UPDATE mappingingame SET objectmodel='%d', posx='%f', posy='%f', posz='%f', posrx='%f', posry='%f', posrz='%f', interior='%d', world='%d' WHERE id='%d'",
	MapoData[id][mapoObject],
	MapoData[id][mapoX],
	MapoData[id][mapoY],
	MapoData[id][mapoZ],
	MapoData[id][mapoRX],
	MapoData[id][mapoRY],
	MapoData[id][mapoRZ],
	MapoData[id][mapoInt],
	MapoData[id][mapoWorld],
	id
	);
	return mysql_tquery(g_SQL, cQuery);
}

Mapo_Refresh(id)
{
	if(IsValidDynamicObject(MapoData[id][mapoObjID]))
		DestroyDynamicObject(MapoData[id][mapoObjID]);

	if(IsValidDynamic3DTextLabel(MapoData[id][mapoLabel]))
		DestroyDynamic3DTextLabel(MapoData[id][mapoLabel]);

	static
	 str[128];

	MapoData[id][mapoObjID] = CreateDynamicObject(MapoData[id][mapoObject], MapoData[id][mapoX], MapoData[id][mapoY], MapoData[id][mapoZ], MapoData[id][mapoRX], MapoData[id][mapoRY], MapoData[id][mapoRZ], MapoData[id][mapoWorld], MapoData[id][mapoInt], -1, 90.0, 90.0);
	format(str, sizeof(str), "[ID: %d]\n Object Model: %d", id, MapoData[id][mapoObject]);
	MapoData[id][mapoLabel] = CreateDynamic3DTextLabel(str, COLOR_LIGHTGREEN, MapoData[id][mapoX], MapoData[id][mapoY], MapoData[id][mapoZ] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, MapoData[id][mapoWorld], MapoData[id][mapoInt], -1, 10.0);
}

Mapo_BeingEdited(mid)
{
	if(!Iter_Contains(MAPO, mid)) return 0;
	foreach(new i : Player) if(pData[i][pEditing] == mid) return 1;
	return 0;
}