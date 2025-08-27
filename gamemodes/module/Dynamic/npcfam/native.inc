Npcfam_Save(id)
{
	new cQuery[1024];
	format(cQuery, sizeof(cQuery), "UPDATE npcfamily SET owner = '%d', type = '%d', posx = '%f', posy = '%f', posz = '%f', posa = '%f', world= '%d', interior = '%d', money = '%d', material = '%d', marijuana = '%d', cocaine = '%d', meth = '%d', price0 = '%d', price1 = '%d', price3 = '%d', price4 = '%d', price5 = '%d', price6 = '%d', price7 = '%d' WHERE id = '%d'",
	nfData[id][nfOwner],
	nfData[id][nfType],
	nfData[id][nfPosX],
	nfData[id][nfPosY],
	nfData[id][nfPosZ],
	nfData[id][nfPosA],
	nfData[id][nfVw],
	nfData[id][nfInt],
	nfData[id][nfMoney],
	nfData[id][nfMaterial],
	nfData[id][nfMarijuana],
	nfData[id][nfCocaine],
	nfData[id][nfMeth],
	nfData[id][nfPrice][0],
	nfData[id][nfPrice][1],
	nfData[id][nfPrice][2],
	nfData[id][nfPrice][3],
	nfData[id][nfPrice][4],
	nfData[id][nfPrice][5],
	nfData[id][nfPrice][6],
	id
	);

	return mysql_tquery(g_SQL, cQuery);
}

Npcfam_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamicPickup(nfData[id][nfPickup]))
			DestroyDynamicPickup(nfData[id][nfPickup]);

		if(IsValidDynamic3DTextLabel(nfData[id][nfLabel]))
			DestroyDynamic3DTextLabel(nfData[id][nfLabel]);

		new str[1024], type[128];
		if(nfData[id][nfType] == 1)
		{
			type = "Drugs";
		}
		else
		{
			type = "Weapon";
		}


		format(str, sizeof(str), "[NPCFAM ID: %d]\n"WHITE_E"Owner: "GREEN_LIGHT"%s\n"WHITE_E"Type: "GREEN_LIGHT"%s\n"WHITE_E"Location: "GREEN_LIGHT"%s\n"WHITE_E"/buy - to buy this product", id, fData[nfData[id][nfOwner]][fName], type, GetLocation(nfData[id][nfPosX], nfData[id][nfPosY], nfData[id][nfPosZ]));
		nfData[id][nfPickup] = CreateDynamicPickup(1239, 23, nfData[id][nfPosX], nfData[id][nfPosY], nfData[id][nfPosZ], nfData[id][nfVw], nfData[id][nfInt], _, 10.0);
		nfData[id][nfLabel] = CreateDynamic3DTextLabel(str, COLOR_YELLOW, nfData[id][nfPosX], nfData[id][nfPosY], nfData[id][nfPosZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, nfData[id][nfVw], nfData[id][nfInt]);
	}
	return 1;
}

Npcfam_BuyMenu(playerid, nfid)
{
    if(nfid <= -1 )
        return 0;

    static string[1024], hstr[512];
    new fid = nfData[nfid][nfOwner];

    switch(nfData[nfid][nfType])
    {
        case 1:
        {
            format(string, sizeof(string), "Produk\tStock\tHarga\n{ffffff}Marijuana\t%d gram\t{7fff00}%s\n{ffffff}Cocaine\t%d gram\t{7fff00}%s\n{ffffff}Meth\t%d gram\t{7fff00}%s",
                nfData[nfid][nfMarijuana],
                FormatMoney(nfData[nfid][nfPrice][0]),
                nfData[nfid][nfCocaine],
                FormatMoney(nfData[nfid][nfPrice][1]),
                nfData[nfid][nfMeth],
                FormatMoney(nfData[nfid][nfPrice][2])
            );
            ShowPlayerDialog(playerid, NPCFAM_BUYPROD, DIALOG_STYLE_TABLIST_HEADERS, fData[fid][fName], string, "Buy", "Cancel");
        }
        case 2:
        {
            format(string, sizeof(string), "Produk\tAmmo\tHarga\n{ffffff}Colt45 (Mat: 250)\t70\t{7fff00}%s\n{ffffff}Desert Eagle (Mat: 500) \t34\t{7fff00}%s\n{ffffff}Shotgun (Mat: 400)\t20\t{7fff00}%s\n{ffffff}AK-47 (Mat: 750) \t200\t{7fff00}%s\n{ffffff}Micro SMG/Uzi (Mat: 300) \t200\t{7fff00}%s\n{ffffff}Patched Bomb (Mat: 500) \t1\t{7fff00}%s",
                FormatMoney(nfData[nfid][nfPrice][0]),
                FormatMoney(nfData[nfid][nfPrice][1]),
                FormatMoney(nfData[nfid][nfPrice][2]),
                FormatMoney(nfData[nfid][nfPrice][3]),
                FormatMoney(nfData[nfid][nfPrice][4]),
                FormatMoney(nfData[nfid][nfPrice][5]),
                FormatMoney(nfData[nfid][nfPrice][6])
            );
            format(hstr, sizeof(hstr), "%s (Material: %d)", fData[fid][fName], nfData[nfid][nfMaterial]);
            ShowPlayerDialog(playerid, NPCFAM_BUYPROD, DIALOG_STYLE_TABLIST_HEADERS, hstr, string, "Buy", "Cancel");
        }
    }
    return 1;
}

Npcfam_ProductMenu(playerid, nfid)
{
    if(nfid <= -1)
        return 0;

    static string[1024], hstr[512];
    new fid = nfData[nfid][nfOwner];

    switch(nfData[nfid][nfType])
    {
        case 1:
        {
            format(string, sizeof(string), "Produk\tStock\tHarga\n{ffffff}Marijuana\t%d gram\t{7fff00}%s\n{ffffff}Cocaine\t%d gram\t{7fff00}%s\n{ffffff}Meth\t%d gram\t{7fff00}%s",
                nfData[nfid][nfMarijuana],
                FormatMoney(nfData[nfid][nfPrice][0]),
                nfData[nfid][nfCocaine],
                FormatMoney(nfData[nfid][nfPrice][1]),
                nfData[nfid][nfMeth],
                FormatMoney(nfData[nfid][nfPrice][2])
            );
            ShowPlayerDialog(playerid, NPCFAM_EDITPROD, DIALOG_STYLE_TABLIST_HEADERS, fData[fid][fName], string, "Set", "Cancel");
        }
        case 2:
        {
            format(string, sizeof(string), "Produk\tAmmo\tHarga\n{ffffff}Colt45 (Mat: 250)\t70\t{7fff00}%s\n{ffffff}Desert Eagle (Mat: 500) \t34\t{7fff00}%s\n{ffffff}Shotgun (Mat: 400)\t20\t{7fff00}%s\n{ffffff}Rifle (Mat: 750)\t30\t{7fff00}%s\n{ffffff}AK-47 (Mat: 750) \t200\t{7fff00}%s\n{ffffff}Micro SMG/Uzi (Mat: 300) \t200\t{7fff00}%s\n{ffffff}Patched Bomb (Mat: 500) \t1\t{7fff00}%s",
                FormatMoney(nfData[nfid][nfPrice][0]),
                FormatMoney(nfData[nfid][nfPrice][1]),
                FormatMoney(nfData[nfid][nfPrice][2]),
                FormatMoney(nfData[nfid][nfPrice][3]),
                FormatMoney(nfData[nfid][nfPrice][4]),
                FormatMoney(nfData[nfid][nfPrice][5]),
                FormatMoney(nfData[nfid][nfPrice][6])
            );

            format(hstr, sizeof(hstr), "%s (Material: %d)", fData[fid][fName], nfData[nfid][nfMaterial]);
            ShowPlayerDialog(playerid, NPCFAM_EDITPROD, DIALOG_STYLE_TABLIST_HEADERS, hstr, string, "Set", "Cancel");
        }
    }
    return 1;
}

Npcfam_Reset(nfid)
{
	nfData[nfid][nfPosX] = 0;
	nfData[nfid][nfPosY] = 0;
	nfData[nfid][nfPosZ] = 0;
	nfData[nfid][nfPosA] = 0;

	nfData[nfid][nfMoney] = 0;
	nfData[nfid][nfMaterial] = 0;
	nfData[nfid][nfMarijuana] = 0;
	nfData[nfid][nfCocaine] = 0;
	nfData[nfid][nfMeth] = 0;

	nfData[nfid][nfPrice][0] = 0;
	nfData[nfid][nfPrice][1] = 0;
	nfData[nfid][nfPrice][2] = 0;
	nfData[nfid][nfPrice][3] = 0;
	nfData[nfid][nfPrice][4] = 0;
	nfData[nfid][nfPrice][5] = 0;
	nfData[nfid][nfPrice][6] = 0;
	nfData[nfid][nfPrice][7] = 0;

	Npcfam_Refresh(nfid);

	DestroyDynamicPickup(nfData[nfid][nfPickup]);
	DestroyDynamic3DTextLabel(nfData[nfid][nfLabel]);

	nfData[nfid][nfOwner] = -1;
	nfData[nfid][nfPickup] = -1;
	nfData[nfid][nfLabel] = Text3D: INVALID_3DTEXT_ID;
}

NpcfamCount(fid)
{
    new tmpcount;
    foreach(new nfid : NPCFam)
    {
        if(nfData[nfid][nfOwner] == fid)
        {
        	tmpcount++;
        }
    }
    return tmpcount;
}

CMD:createnpcfam(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new nfid = Iter_Free(NPCFam), famid, type;
	if(sscanf(params, "dd", famid, type))
		return Usage(playerid, "/createnpcfam [famid] [type] (Type: 1. Drug 2. Weapon)");

	if(!Iter_Contains(FAMILYS, famid))
		return Error(playerid, "Invalid Family ID!");

	if(type < 1 || type > 2)
		return Error(playerid, "Type only 1 or 2");

	if(NpcfamCount(famid) >= 2)
		return Error(playerid, "Family hanya bisa memiliki 2 NPC!");
	
	new Float:x, Float:y, Float:z, Float:a;
	GetPlayerPos(playerid, x, y , z);

	nfData[nfid][nfOwner] = famid;
	nfData[nfid][nfType] = type;

	nfData[nfid][nfPosX] = x;
	nfData[nfid][nfPosY] = y;
	nfData[nfid][nfPosZ] = z;
	nfData[nfid][nfPosA] = a;

	nfData[nfid][nfVw] = GetPlayerVirtualWorld(playerid);
	nfData[nfid][nfInt] = GetPlayerInterior(playerid);

	nfData[nfid][nfMoney] = 0;
	nfData[nfid][nfMaterial] = 0;
	nfData[nfid][nfMarijuana] = 0;
	nfData[nfid][nfCocaine] = 0;
	nfData[nfid][nfMeth] = 0;
	
	nfData[nfid][nfPrice][0] = 0;
	nfData[nfid][nfPrice][1] = 0;
	nfData[nfid][nfPrice][2] = 0;
	nfData[nfid][nfPrice][3] = 0;
	nfData[nfid][nfPrice][4] = 0;
	nfData[nfid][nfPrice][5] = 0;
	nfData[nfid][nfPrice][6] = 0;
	nfData[nfid][nfPrice][7] = 0;

	Npcfam_Refresh(nfid);
	Iter_Add(NPCFam, nfid);

	new cQuery[1024];
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "INSERT INTO npcfamily SET id = '%d', owner = '%d', type = '%d'", nfid, nfData[nfid][nfOwner], nfData[nfid][nfType]);
	mysql_tquery(g_SQL, cQuery, "OnNpcfamCreated", "d", nfid);

	SendAdminMessage(COLOR_RED, "%s has created NPC Family ID: %d.", pData[playerid][pAdminname], nfid);
	return 1;
}