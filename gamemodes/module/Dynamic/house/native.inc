Player_OwnsHouse(playerid, houseid)
{
	if(houseid == -1) return 0;
	if(!IsPlayerConnected(playerid)) return 0;
	if(!strcmp(hData[houseid][hOwner], pData[playerid][pName], true)) return 1;
	return 0;
}

Player_OwnsHouse2(playerid, houseid)
{
	if(houseid == -1) return 0;
	if(!IsPlayerConnected(playerid)) return 0;
	if(!strcmp(hData[houseid][hOwner], pData[playerid][pName], true) || !strcmp(hData[houseid][hOwner2], pData[playerid][pName], true)) return 1;
	return 0;
}

Player_HouseCount(playerid)
{
	#if LIMIT_PER_PLAYER != 0
    new count;
	foreach(new i : Houses)
	{
		if(Player_OwnsHouse(playerid, i)) count++;
	}

	return count;
	#else
	return 0;
	#endif
}

HouseReset(houseid)
{
	format(hData[houseid][hOwner], MAX_PLAYER_NAME, "-");
	format(hData[houseid][hOwner2], MAX_PLAYER_NAME, "-");
	hData[houseid][hLocked] = 1;
    hData[houseid][hMoney] = 0;
    hData[houseid][hComponent] = 0;
    hData[houseid][hMaterial] = 0;

    hData[houseid][hMarijuana] = 0;
    hData[houseid][hEphedrine] = 0;
    hData[houseid][hCocaine] = 0;
    hData[houseid][hMeth] = 0;

	hData[houseid][hWeapon] = 0;
	hData[houseid][hAmmo] = 0;
	hData[houseid][hVisit] = 0;
	House_Type(houseid);
	
	for (new i = 0; i < 10; i ++)
    {
        hData[houseid][hWeapon][i] = 0;

		hData[houseid][hAmmo][i] = 0;
    }
}
	
/*GetHouseOwnerID(houseid)
{
	foreach(new i : Player)
	{
		if(!strcmp(hData[houseid][hOwner], pData[i][pName], true)) return i;
	}
	return INVALID_PLAYER_ID;
}*/

House_WeaponStorage(playerid, houseid)
{
    if(houseid == -1)
        return 0;

    static
        string[320];

    string[0] = 0;

    for (new i = 0; i < 5; i ++)
    {
        if(!hData[houseid][hWeapon][i])
            format(string, sizeof(string), "%sEmpty Slot\n", string);

        else
            format(string, sizeof(string), "%s%s (Ammo: %d)\n", string, ReturnWeaponName(hData[houseid][hWeapon][i]), hData[houseid][hAmmo][i]);
    }
    ShowPlayerDialog(playerid, HOUSE_WEAPONS, DIALOG_STYLE_LIST, "Weapon Storage", string, "Select", "Cancel");
    return 1;
}

House_OpenStorage(playerid, houseid)
{
    if(houseid == -1)
        return 0;

    new
        items[1],
        string[10 * 32];

    for (new i = 0; i < 5; i ++) if(hData[houseid][hWeapon][i]) 
	{
        items[0]++;
    }
    if(!Player_OwnsHouse2(playerid, houseid))
    {
    	format(string, sizeof(string), "Weapon Storage (%d/5)", items[0]);
    }
    else if(hData[houseid][hType] == 1)
    {
        format(string, sizeof(string), "Weapon Storage (%d/5)\nMoney Safe (%s/$1.000,000)\nComponent Safe (%d/5000)\nMaterial Safe (%d/5000)\n"RED_E"Marijuana Safe (%dg/1000g)\n"RED_E"Ephedrine Safe (%dg/1000g)\n"RED_E"Cocaine Safe (%dg/1000g)\n"RED_E"Meth Safe (%dg/1000g)"WHITE_E"", items[0], FormatMoney(hData[houseid][hMoney]), hData[houseid][hComponent], hData[houseid][hMaterial], hData[houseid][hMarijuana], hData[houseid][hEphedrine], hData[houseid][hCocaine], hData[houseid][hMeth]);
    }
    else if(hData[houseid][hType] == 2)
    {
    	format(string, sizeof(string), "Weapon Storage (%d/5)\nMoney Safe (%s/$3.000,000)\nComponent Safe (%d/10000)\nMaterial Safe (%d/10000)\n"RED_E"Marijuana Safe (%dg/3000g)\n"RED_E"Ephedrine Safe (%dg/3000g)\n"RED_E"Cocaine Safe (%dg/3000g)\n"RED_E"Meth Safe (%dg/3000g)"WHITE_E"", items[0], FormatMoney(hData[houseid][hMoney]), hData[houseid][hComponent], hData[houseid][hMaterial], hData[houseid][hMarijuana], hData[houseid][hEphedrine], hData[houseid][hCocaine], hData[houseid][hMeth]);
    }
    else if(hData[houseid][hType] == 3)
    {
    	format(string, sizeof(string), "Weapon Storage (%d/5)\nMoney Safe (%s/$5.000,000)\nComponent Safe (%d/15000)\nMaterial Safe (%d/15000)\n"RED_E"Marijuana Safe (%dg/5000g)\n"RED_E"Ephedrine Safe (%dg/5000g)\n"RED_E"Cocaine Safe (%dg/5000g)\n"RED_E"Meth Safe (%dg/5000g)"WHITE_E"", items[0], FormatMoney(hData[houseid][hMoney]), hData[houseid][hComponent], hData[houseid][hMaterial], hData[houseid][hMarijuana], hData[houseid][hEphedrine], hData[houseid][hCocaine], hData[houseid][hMeth]);
    }
    ShowPlayerDialog(playerid, HOUSE_STORAGE, DIALOG_STYLE_LIST, "House Storage", string, "Select", "Cancel");
    return 1;
}

GetOwnedHouses(playerid)
{
	new tmpcount;
	foreach(new hid : Houses)
	{
	    if(!strcmp(hData[hid][hOwner], pData[playerid][pName], true))
	    {
     		tmpcount++;
		}
	}
	return tmpcount;
}
ReturnPlayerHousesID(playerid, hslot)
{
	new tmpcount;
	if(hslot < 1 && hslot > LIMIT_PER_PLAYER) return -1;
	foreach(new hid : Houses)
	{
	    if(!strcmp(pData[playerid][pName], hData[hid][hOwner], true))
	    {
     		tmpcount++;
       		if(tmpcount == hslot)
       		{
        		return hid;
  			}
	    }
	}
	return -1;
}

House_Save(houseid)
{
	new cQuery[1536];
	format(cQuery, sizeof(cQuery), "UPDATE houses SET owner='%s', owner2='%s', address='%s', price='%d', type='%d', locked='%d', money='%d', component='%d', material='%d', marijuana='%d', ephedrine='%d', cocaine='%d', meth='%d'",
	hData[houseid][hOwner],
	hData[houseid][hOwner2],
	hData[houseid][hAddress],
	hData[houseid][hPrice],
	hData[houseid][hType],
	hData[houseid][hLocked],
	hData[houseid][hMoney],
	hData[houseid][hComponent],
    hData[houseid][hMaterial],
    hData[houseid][hMarijuana],
    hData[houseid][hEphedrine],
    hData[houseid][hCocaine],
    hData[houseid][hMeth]
	);
	
	for (new i = 0; i < 10; i ++) 
	{
        format(cQuery, sizeof(cQuery), "%s, houseWeapon%d='%d', houseAmmo%d='%d'", cQuery, i + 1, hData[houseid][hWeapon][i], i + 1, hData[houseid][hAmmo][i]);
    }
	
	format(cQuery, sizeof(cQuery), "%s, houseint='%d', extposx='%f', extposy='%f', extposz='%f', extposa='%f', intposx='%f', intposy='%f', intposz='%f', intposa='%f', visit='%d' WHERE ID='%d'",
        cQuery,
        hData[houseid][hInt],
        hData[houseid][hExtposX],
        hData[houseid][hExtposY],
		hData[houseid][hExtposZ],
		hData[houseid][hExtposA],
		hData[houseid][hIntposX],
		hData[houseid][hIntposY],
		hData[houseid][hIntposZ],
		hData[houseid][hIntposA],
		hData[houseid][hVisit],
        houseid
    );
	return mysql_tquery(g_SQL, cQuery);
}

House_Type(houseid)
{
	if(hData[houseid][hType] == 1)
	{
	    switch(random(4))
		{
			case 0:
			{
				hData[houseid][hIntposX] = 377.15;
				hData[houseid][hIntposY] = 1417.41;
				hData[houseid][hIntposZ] = 1081.33;
				hData[houseid][hIntposA] = 85.69;
				hData[houseid][hInt] = 15;
			}
			case 1:
			{
				hData[houseid][hIntposX] = 387.22;
				hData[houseid][hIntposY] = 1471.70;
				hData[houseid][hIntposZ] = 1080.19;
				hData[houseid][hIntposA] = 85.69;
				hData[houseid][hInt] = 15;
			}
			case 2:
			{
				hData[houseid][hIntposX] = 261.12;
				hData[houseid][hIntposY] = 1284.30;
				hData[houseid][hIntposZ] = 1080.26;
				hData[houseid][hIntposA] = 85.69;
				hData[houseid][hInt] = 4;
			}
			case 3:
			{
				hData[houseid][hIntposX] = 260.85;
				hData[houseid][hIntposY] = 1237.24;
				hData[houseid][hIntposZ] = 1084.26;
				hData[houseid][hIntposA] = 85.69;
				hData[houseid][hInt] = 9;
			}
		}
	}
	if(hData[houseid][hType] == 2)
	{
	    switch(random(3))
		{
			case 0:
			{
				hData[houseid][hIntposX] = 446.99;
				hData[houseid][hIntposY] = 1397.07;
				hData[houseid][hIntposZ] = 1084.30;
				hData[houseid][hIntposA] = 353.78;
				hData[houseid][hInt] = 2;
			}
			case 1:
			{
				hData[houseid][hIntposX] = 22.88;
				hData[houseid][hIntposY] = 1403.33;
				hData[houseid][hIntposZ] = 1084.44;
				hData[houseid][hIntposA] = 353.78;
				hData[houseid][hInt] = 5;
			}
			case 2:
			{
				hData[houseid][hIntposX] = 2196.85;
				hData[houseid][hIntposY] = -1204.25;
				hData[houseid][hIntposZ] = 1049.02;
				hData[houseid][hIntposA] = 84.70;
				hData[houseid][hInt] = 6;
			}
		}
	}
	if(hData[houseid][hType] == 3)
	{
	    switch(random(3))
		{
			case 0:
			{
				hData[houseid][hIntposX] = 2324.53;
				hData[houseid][hIntposY] = -1149.54;
				hData[houseid][hIntposZ] = 1050.71;
				hData[houseid][hIntposA] = 353.78;
				hData[houseid][hInt] = 12;
			}
			case 1:
			{
				hData[houseid][hIntposX] = 225.68;
				hData[houseid][hIntposY] = 1021.45;
				hData[houseid][hIntposZ] = 1084.02;
				hData[houseid][hIntposA] = 353.78;
				hData[houseid][hInt] = 7;
			}
			case 2:
			{
				hData[houseid][hIntposX] = 234.19;
				hData[houseid][hIntposY] = 1063.73;
				hData[houseid][hIntposZ] = 1084.21;
				hData[houseid][hIntposA] = 353.78;
				hData[houseid][hInt] = 6;
			}
		}
	}
}

House_Refresh(houseid)
{
    if(houseid != -1)
    {
        if(IsValidDynamic3DTextLabel(hData[houseid][hLabel]))
            DestroyDynamic3DTextLabel(hData[houseid][hLabel]);

        if(IsValidDynamicPickup(hData[houseid][hPickup]))
            DestroyDynamicPickup(hData[houseid][hPickup]);
			
		if(IsValidDynamicCP(hData[houseid][hCP]))
            DestroyDynamicCP(hData[houseid][hCP]);

        if(IsValidDynamicMapIcon(hData[houseid][hIcon]))
        	DestroyDynamicMapIcon(hData[houseid][hIcon]);

        static
        string[255];
		
		new type[128];
		if(hData[houseid][hType] == 1)
		{
			type= "Low";
		}
		else if(hData[houseid][hType] == 2)
		{
			type= "Medium";
		}
		else if(hData[houseid][hType] == 3)
		{
			type= "High";
		}
		else
		{
			type= "Unknow";
		}

        if(strcmp(hData[houseid][hOwner], "-"))
		{
			if(hData[houseid][hLocked] != 2)
			{
				format(string, sizeof(string), "[ID: %d]\n{FFFFFF}House Type {FFFF00}%s\n"WHITE_E"Owned by %s\nKlik "GREEN_E"'Y' "WHITE_E"Untuk memasuki rumah", houseid, type, hData[houseid][hOwner]);
				hData[houseid][hPickup] = CreateDynamicPickup(1273, 23, hData[houseid][hExtposX], hData[houseid][hExtposY], hData[houseid][hExtposZ]+0.2, 0, 0, _, 10.0);
				hData[houseid][hIcon] = CreateDynamicMapIcon(hData[houseid][hExtposX], hData[houseid][hExtposY], hData[houseid][hExtposZ], 32, -1, -1, -1, -1, 50.0);
        	}
        	else
        	{
        		format(string, sizeof(string), "[ID: %d]\n{FFFFFF}House Type {FFFF00}%s\n"WHITE_E"Owned by %s\n"RED_E"this house is being sealed by the government"WHITE_E"\nKlik "GREEN_E"'Y' "WHITE_E"Untuk memasuki rumah", houseid, type, hData[houseid][hOwner]);
				hData[houseid][hPickup] = CreateDynamicPickup(1273, 23, hData[houseid][hExtposX], hData[houseid][hExtposY], hData[houseid][hExtposZ]+0.2, 0, 0, _, 10.0);
				hData[houseid][hIcon] = CreateDynamicMapIcon(hData[houseid][hExtposX], hData[houseid][hExtposY], hData[houseid][hExtposZ], 32, -1, -1, -1, -1, 50.0);
        	}
        }
        else
        {
        	format(string, sizeof(string), "[ID: %d]\n{00FF00}This house for sell\n{FFFFFF}House Type: {FFFF00}%s\n{FFFFFF}House Price: {FFFF00}%s\n\nKlik "GREEN_E"'Y' "WHITE_E"Untuk membeli rumah", houseid, type, FormatMoney(hData[houseid][hPrice]));
            hData[houseid][hPickup] = CreateDynamicPickup(1273, 23, hData[houseid][hExtposX], hData[houseid][hExtposY], hData[houseid][hExtposZ]+0.2, 0, 0, _, 10.0);
            hData[houseid][hIcon] = CreateDynamicMapIcon(hData[houseid][hExtposX], hData[houseid][hExtposY], hData[houseid][hExtposZ], 31, -1, -1, -1, -1, 50.0);
        }
		//hData[houseid][hCP] = CreateDynamicCP(hData[houseid][hIntposX], hData[houseid][hIntposY], hData[houseid][hIntposZ], 1.0, houseid, hData[houseid][hInt], -1, 3.0);
        hData[houseid][hLabel] = CreateDynamic3DTextLabel(string, COLOR_GREEN, hData[houseid][hExtposX], hData[houseid][hExtposY], hData[houseid][hExtposZ]+0.5, 2.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0);
    }
    return 1;
}