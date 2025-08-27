Matext_Save(id)
{
	new cQuery[2248];
	format(cQuery, sizeof(cQuery), "UPDATE matext SET text='%s', size='%d', color='%d', bold='%d', x='%f', y='%f', z='%f', rx='%f', ry='%f', rz='%f', interior='%d', world='%d' WHERE id='%d'",
	mtData[id][mtText],
	mtData[id][mtSize],
	mtData[id][mtColor],
	mtData[id][mtBold],
	mtData[id][mtX],
	mtData[id][mtY],
	mtData[id][mtZ],
	mtData[id][mtRX],
	mtData[id][mtRY],
	mtData[id][mtRZ],
	mtData[id][mtInt],
	mtData[id][mtVW],
	id);

	return mysql_tquery(g_SQL, cQuery);
}

Matext_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamicObject(mtData[id][mtObj]))
			DestroyDynamicObject(mtData[id][mtObj]);

		static color;

		switch(mtData[id][mtColor])
		{
		    case 1: color = 0xFFFFFFFF;//Putih
		    case 2: color = 0xFF6347FF;//Biru
		    case 3: color = 0xFFFF6347;//Merah
		    case 4: color = 0xFFFFFF00;//Kuning
		}
		mtData[id][mtObj] = CreateDynamicObject(19482, mtData[id][mtX], mtData[id][mtY], mtData[id][mtZ] - 0.0, mtData[id][mtRX], mtData[id][mtRY], mtData[id][mtRZ], mtData[id][mtVW], mtData[id][mtInt], -1, 90.0, 90.0);
		SetDynamicObjectMaterial(mtData[id][mtObj], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
        SetDynamicObjectMaterialText(mtData[id][mtObj], 0, mtData[id][mtText], 130, "Arial", mtData[id][mtSize], mtData[id][mtBold], color, 0x00000000, 0);
	}
	return 1;
}

Matext_Label(id)
{
	if(id != -1)
	{
		static label[254];

		if(IsValidDynamic3DTextLabel(mtData[id][mtLabel]))
			DestroyDynamic3DTextLabel(mtData[id][mtLabel]);

	    format(label, sizeof(label), "Material Text\nID : %d", id);
        mtData[id][mtLabel] = CreateDynamic3DTextLabel(label, COLOR_LIGHTGREEN, mtData[id][mtX], mtData[id][mtY], mtData[id][mtZ] + 1.5, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, mtData[id][mtVW], mtData[id][mtInt], -1, 10.0);
	}
	return 1;
}

Matext_BeingEdited(mtid)
{
	if(!Iter_Contains(Matext, mtid)) return 0;
	foreach(new i : Player) if(pData[i][pEditing] == mtid) return 1;
	return 0;
}