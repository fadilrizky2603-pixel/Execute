GetClosestATM(playerid, Float: range = 3.0)
{
	new id = -1, Float: dist = range, Float: tempdist;
	foreach(new i : ATMS)
	{
	    tempdist = GetPlayerDistanceFromPoint(playerid, AtmData[i][atmX], AtmData[i][atmY], AtmData[i][atmZ]);

	    if(tempdist > range) continue;
		if(tempdist <= dist && GetPlayerInterior(playerid) == AtmData[i][atmInt] && GetPlayerVirtualWorld(playerid) == AtmData[i][atmWorld])
		{
			dist = tempdist;
			id = i;
		}
	}
	return id;
}

Atm_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamicObject(AtmData[id][atmObjID]))
			DestroyDynamicObject(AtmData[id][atmObjID]);

		if(IsValidDynamic3DTextLabel(AtmData[id][atmLabel]))
			DestroyDynamic3DTextLabel(AtmData[id][atmLabel]);
		
		if(IsValidDynamicArea(AtmData[id][atmArea]))
			DestroyDynamicArea(AtmData[id][atmArea]);

		new str[1024];
		if(AtmData[id][atmStatus] == 0)
		{
			AtmData[id][atmObjID] = CreateDynamicObject(11688, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ], AtmData[id][atmRX], AtmData[id][atmRY], AtmData[id][atmRZ], AtmData[id][atmWorld], AtmData[id][atmInt], -1, 90.0, 90.0);
			SetDynamicObjectMaterial(AtmData[id][atmObjID], 1, 19130, "matarrows", "green", 0x00000000);
			SetDynamicObjectMaterial(AtmData[id][atmObjID], 3, 6060, "shops2_law", "atmflat", 0x00000000);
			format(str, sizeof(str), "ID: %d\nATM Status: {00FF00}Bagus\n{FFFF00}[Y] {FFFFFF}untuk membuka ATM", id);
		}
		else
		{
			AtmData[id][atmObjID] = CreateDynamicObject(11688, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ], AtmData[id][atmRX], AtmData[id][atmRY], AtmData[id][atmRZ], AtmData[id][atmWorld], AtmData[id][atmInt], -1, 90.0, 90.0);
			SetDynamicObjectMaterial(AtmData[id][atmObjID], 1, 19130, "matarrows", "green", 0x00000000);
			SetDynamicObjectMaterial(AtmData[id][atmObjID], 3, 6060, "shops2_law", "atmflat", 0x00000000);
			format(str, sizeof(str), "ID: %d\nATM Status: {FF0000}Rusak\n{FFFF00}[Y] {FFFFFF}untuk membuka ATM", id);
		}
		AtmData[id][atmLabel] = CreateDynamic3DTextLabel(str, -1, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, AtmData[id][atmWorld], AtmData[id][atmInt], -1, 10.0);
		AtmData[id][atmArea] = CreateDynamicCircle(AtmData[id][atmX], AtmData[id][atmY], 1.5, AtmData[id][atmWorld], AtmData[id][atmInt], -1);
	}
	return 1;
}

Atm_Save(id)
{
	new cQuery[512];
	format(cQuery, sizeof(cQuery), "UPDATE atms SET posx='%f', posy='%f', posz='%f', posrx='%f', posry='%f', posrz='%f', interior='%d', world='%d', status='%d' WHERE id='%d'",
	AtmData[id][atmX],
	AtmData[id][atmY],
	AtmData[id][atmZ],
	AtmData[id][atmRX],
	AtmData[id][atmRY],
	AtmData[id][atmRZ],
	AtmData[id][atmInt],
	AtmData[id][atmWorld],
	AtmData[id][atmStatus],
	id
	);
	return mysql_tquery(g_SQL, cQuery);
}

Atm_BeingEdited(id)
{
	if(!Iter_Contains(ATMS, id)) return 0;
	foreach(new i : Player) if(pData[i][pEditing] == id) return 1;
	return 0;
}

CreatePlayerAtm(playerid)
{
	AtmPakCik[playerid][0] = CreatePlayerTextDraw(playerid, 176.000, 121.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][0], 33.000, 48.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][0], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][0], 538976511);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][0], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][0], 1);

	AtmPakCik[playerid][1] = CreatePlayerTextDraw(playerid, 416.000, 121.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][1], 33.000, 48.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][1], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][1], 538976511);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][1], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][1], 1);

	AtmPakCik[playerid][2] = CreatePlayerTextDraw(playerid, 176.000, 329.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][2], 33.000, 48.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][2], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][2], 538976511);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][2], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][2], 1);

	AtmPakCik[playerid][3] = CreatePlayerTextDraw(playerid, 417.000, 330.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][3], 33.000, 48.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][3], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][3], 538976511);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][3], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][3], 1);

	AtmPakCik[playerid][4] = CreatePlayerTextDraw(playerid, 193.000, 129.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][4], 237.000, 241.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][4], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][4], 538976511);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][4], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][4], 1);

	AtmPakCik[playerid][5] = CreatePlayerTextDraw(playerid, 181.000, 145.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][5], 263.000, 206.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][5], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][5], 538976511);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][5], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][5], 1);

	AtmPakCik[playerid][6] = CreatePlayerTextDraw(playerid, 221.000, 148.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][6], 1.000, 203.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][6], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][6], 808464639);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][6], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][6], 1);

	AtmPakCik[playerid][7] = CreatePlayerTextDraw(playerid, 225.000, 166.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][7], 209.000, 2.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][7], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][7], 808464639);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][7], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][7], 1);

	AtmPakCik[playerid][8] = CreatePlayerTextDraw(playerid, 365.000, 173.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][8], 1.500, 181.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][8], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][8], 808464639);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][8], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][8], 1);

	AtmPakCik[playerid][9] = CreatePlayerTextDraw(playerid, 188.000, 149.000, "KAMPUNG_INDO");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][9], 0.150, 1.098);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][9], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][9], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][9], 1);

	AtmPakCik[playerid][10] = CreatePlayerTextDraw(playerid, 204.000, 156.000, "BANKING");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][10], 0.170, 1.098);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][10], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][10], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][10], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][10], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][10], 1);

	AtmPakCik[playerid][11] = CreatePlayerTextDraw(playerid, 188.000, 338.000, "[>_Logout");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][11], 0.150, 1.098);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][11], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][11], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][11], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][11], 1);
	PlayerTextDrawSetSelectable(playerid, AtmPakCik[playerid][11], 1);

	AtmPakCik[playerid][12] = CreatePlayerTextDraw(playerid, 188.000, 173.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][12], 29.500, 2.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][12], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][12], 808464639);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][12], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][12], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][12], 1);

	AtmPakCik[playerid][13] = CreatePlayerTextDraw(playerid, 418.000, 133.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][13], 19.000, 29.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][13], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][13], -1329275137);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][13], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][13], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][13], 1);

	AtmPakCik[playerid][14] = CreatePlayerTextDraw(playerid, 424.000, 139.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][14], 7.000, 12.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][14], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][14], 255);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][14], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][14], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][14], 1);

	AtmPakCik[playerid][15] = CreatePlayerTextDraw(playerid, 421.500, 149.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][15], 12.000, 11.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][15], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][15], 255);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][15], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][15], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][15], 1);

	AtmPakCik[playerid][16] = CreatePlayerTextDraw(playerid, 418.000, 141.000, "Aditya_Warmawan");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][16], 0.150, 1.098);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][16], 3);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][16], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][16], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][16], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][16], 1);

	AtmPakCik[playerid][17] = CreatePlayerTextDraw(playerid, 417.000, 152.000, "10000_:WALLET");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][17], 0.140, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][17], 3);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][17], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][17], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][17], 1);

	AtmPakCik[playerid][18] = CreatePlayerTextDraw(playerid, 369.500, 173.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][18], 15.000, 23.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][18], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][18], -1329275137);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][18], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][18], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][18], 1);

	AtmPakCik[playerid][19] = CreatePlayerTextDraw(playerid, 423.500, 173.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][19], 15.000, 23.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][19], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][19], -1329275137);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][19], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][19], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][19], 1);

	AtmPakCik[playerid][20] = CreatePlayerTextDraw(playerid, 423.500, 215.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][20], 15.000, 23.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][20], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][20], -1329275137);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][20], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][20], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][20], 1);

	AtmPakCik[playerid][21] = CreatePlayerTextDraw(playerid, 369.500, 215.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][21], 15.000, 23.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][21], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][21], -1329275137);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][21], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][21], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][21], 1);

	AtmPakCik[playerid][22] = CreatePlayerTextDraw(playerid, 372.000, 187.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][22], 64.000, 38.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][22], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][22], -1329275137);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][22], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][22], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][22], 1);

	AtmPakCik[playerid][23] = CreatePlayerTextDraw(playerid, 378.000, 177.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][23], 53.000, 57.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][23], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][23], -1329275137);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][23], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][23], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][23], 1);

	AtmPakCik[playerid][24] = CreatePlayerTextDraw(playerid, 378.000, 185.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][24], 7.000, 2.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][24], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][24], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][24], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][24], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][24], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][24], 1);

	AtmPakCik[playerid][25] = CreatePlayerTextDraw(playerid, 380.000, 188.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][25], 4.000, 2.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][25], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][25], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][25], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][25], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][25], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][25], 1);

	AtmPakCik[playerid][26] = CreatePlayerTextDraw(playerid, 248.000, 188.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][26], 105.500, 1.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][26], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][26], 1768516095);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][26], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][26], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][26], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][26], 1);

	AtmPakCik[playerid][27] = CreatePlayerTextDraw(playerid, 248.000, 204.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][27], 105.500, 1.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][27], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][27], 1768516095);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][27], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][27], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][27], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][27], 1);

	AtmPakCik[playerid][28] = CreatePlayerTextDraw(playerid, 383.000, 182.000, "VISA");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][28], 0.280, 1.598);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][28], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][28], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][28], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][28], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][28], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][28], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][28], 1);

	AtmPakCik[playerid][29] = CreatePlayerTextDraw(playerid, 248.000, 221.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][29], 105.500, 1.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][29], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][29], 1768516095);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][29], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][29], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][29], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][29], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][29], 1);

	AtmPakCik[playerid][30] = CreatePlayerTextDraw(playerid, 248.000, 239.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][30], 105.500, 1.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][30], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][30], 1768516095);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][30], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][30], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][30], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][30], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][30], 1);

	AtmPakCik[playerid][31] = CreatePlayerTextDraw(playerid, 380.000, 211.000, "Status");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][31], 0.180, 0.999);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][31], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][31], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][31], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][31], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][31], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][31], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][31], 1);

	AtmPakCik[playerid][32] = CreatePlayerTextDraw(playerid, 379.000, 220.000, "ACTIVE");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][32], 0.170, 0.999);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][32], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][32], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][32], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][32], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][32], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][32], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][32], 1);

	AtmPakCik[playerid][33] = CreatePlayerTextDraw(playerid, 248.000, 258.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][33], 105.500, 1.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][33], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][33], 1768516095);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][33], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][33], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][33], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][33], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][33], 1);

	AtmPakCik[playerid][34] = CreatePlayerTextDraw(playerid, 236.000, 184.000, "250.000");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][34], 0.140, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][34], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][34], 1077952767);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][34], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][34], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][34], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][34], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][34], 1);

	AtmPakCik[playerid][35] = CreatePlayerTextDraw(playerid, 236.000, 199.000, "200.000");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][35], 0.140, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][35], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][35], 1077952767);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][35], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][35], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][35], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][35], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][35], 1);

	AtmPakCik[playerid][36] = CreatePlayerTextDraw(playerid, 236.000, 216.000, "150.000");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][36], 0.140, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][36], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][36], 1077952767);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][36], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][36], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][36], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][36], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][36], 1);

	AtmPakCik[playerid][37] = CreatePlayerTextDraw(playerid, 236.000, 234.000, "50.000");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][37], 0.140, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][37], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][37], 1077952767);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][37], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][37], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][37], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][37], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][37], 1);

	AtmPakCik[playerid][38] = CreatePlayerTextDraw(playerid, 242.000, 253.000, "0");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][38], 0.140, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][38], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][38], 1077952767);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][38], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][38], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][38], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][38], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][38], 1);

	AtmPakCik[playerid][39] = CreatePlayerTextDraw(playerid, 248.000, 276.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][39], 105.500, 1.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][39], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][39], 1768516095);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][39], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][39], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][39], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][39], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][39], 1);

	AtmPakCik[playerid][40] = CreatePlayerTextDraw(playerid, 248.000, 295.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][40], 105.500, 1.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][40], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][40], 1768516095);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][40], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][40], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][40], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][40], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][40], 1);

	AtmPakCik[playerid][41] = CreatePlayerTextDraw(playerid, 248.000, 314.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][41], 105.500, 1.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][41], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][41], 1768516095);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][41], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][41], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][41], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][41], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][41], 1);

	AtmPakCik[playerid][42] = CreatePlayerTextDraw(playerid, 236.000, 272.000, "-50.000");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][42], 0.140, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][42], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][42], 1077952767);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][42], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][42], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][42], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][42], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][42], 1);

	AtmPakCik[playerid][43] = CreatePlayerTextDraw(playerid, 236.000, 292.000, "-100.000");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][43], 0.140, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][43], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][43], 1077952767);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][43], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][43], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][43], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][43], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][43], 1);

	AtmPakCik[playerid][44] = CreatePlayerTextDraw(playerid, 236.000, 310.000, "-150.000");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][44], 0.140, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][44], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][44], 1077952767);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][44], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][44], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][44], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][44], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][44], 1);

	AtmPakCik[playerid][45] = CreatePlayerTextDraw(playerid, 229.000, 145.000, "Overview");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][45], 0.280, 1.799);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][45], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][45], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][45], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][45], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][45], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][45], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][45], 1);

	AtmPakCik[playerid][46] = CreatePlayerTextDraw(playerid, 370.000, 242.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][46], 66.500, 3.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][46], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][46], 808464639);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][46], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][46], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][46], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][46], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][46], 1);

	AtmPakCik[playerid][47] = CreatePlayerTextDraw(playerid, 406.000, 251.000, "Balance:_3114673");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][47], 0.158, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][47], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][47], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][47], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][47], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][47], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][47], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][47], 1);

	AtmPakCik[playerid][48] = CreatePlayerTextDraw(playerid, 406.000, 263.000, "REK:_5637835");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][48], 0.167, 0.898);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][48], 2);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][48], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][48], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][48], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][48], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][48], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][48], 1);

	AtmPakCik[playerid][49] = CreatePlayerTextDraw(playerid, 375.000, 280.199, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][49], 60.000, 22.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][49], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][49], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][49], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][49], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][49], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][49], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][49], 1);
	PlayerTextDrawSetSelectable(playerid, AtmPakCik[playerid][49], 1);

	AtmPakCik[playerid][50] = CreatePlayerTextDraw(playerid, 375.000, 306.199, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][50], 60.000, 22.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][50], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][50], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][50], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][50], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][50], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][50], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][50], 1);
	PlayerTextDrawSetSelectable(playerid, AtmPakCik[playerid][50], 1);

	AtmPakCik[playerid][51] = CreatePlayerTextDraw(playerid, 375.000, 332.200, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, AtmPakCik[playerid][51], 60.000, 22.000);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][51], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][51], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][51], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][51], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][51], 255);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][51], 4);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][51], 1);
	PlayerTextDrawSetSelectable(playerid, AtmPakCik[playerid][51], 1);

	AtmPakCik[playerid][52] = CreatePlayerTextDraw(playerid, 388.000, 311.000, "Withdraw");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][52], 0.220, 1.099);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][52], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][52], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][52], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][52], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][52], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][52], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][52], 1);

	AtmPakCik[playerid][53] = CreatePlayerTextDraw(playerid, 391.000, 285.000, "Deposit");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][53], 0.230, 1.199);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][53], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][53], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][53], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][53], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][53], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][53], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][53], 1);

	AtmPakCik[playerid][54] = CreatePlayerTextDraw(playerid, 391.000, 338.000, "Transfer");
	PlayerTextDrawLetterSize(playerid, AtmPakCik[playerid][54], 0.200, 1.099);
	PlayerTextDrawAlignment(playerid, AtmPakCik[playerid][54], 1);
	PlayerTextDrawColor(playerid, AtmPakCik[playerid][54], -1);
	PlayerTextDrawSetShadow(playerid, AtmPakCik[playerid][54], 0);
	PlayerTextDrawSetOutline(playerid, AtmPakCik[playerid][54], 0);
	PlayerTextDrawBackgroundColor(playerid, AtmPakCik[playerid][54], 150);
	PlayerTextDrawFont(playerid, AtmPakCik[playerid][54], 1);
	PlayerTextDrawSetProportional(playerid, AtmPakCik[playerid][54], 1);

	return true;
}

HideAtm(playerid)
{
	CancelSelectTextDraw(playerid);
	for(new i = 0; i < 55; i++)
	{
		PlayerTextDrawHide(playerid, AtmPakCik[playerid][i]);
	}
	return 1;
}
