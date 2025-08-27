CMD:createven(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
	
	new query[512];
	new venid = Iter_Free(Vending);

	if(venid == -1) return Error(playerid, "You cant create more vending!");

	new price;
	if(sscanf(params, "d", price))
		return Usage(playerid, "/createven [price]");


	format(vmData[venid][venOwner], 128, "-");
	vmData[venid][venPrice] = price;

	new Float: x, Float: y, Float: z, Float: a;
 	GetPlayerPos(playerid, x, y, z);
 	GetPlayerFacingAngle(playerid, a);
 	x += (3.0 * floatsin(-a, degrees));
	y += (3.0 * floatcos(-a, degrees));
	z -= 1.0;

	vmData[venid][venX] = x;
	vmData[venid][venY] = y;
	vmData[venid][venZ] = z;
	vmData[venid][venRX] = vmData[venid][venRY] = vmData[venid][venRZ] = 0.0;
	vmData[venid][venInt] = GetPlayerInterior(playerid);
	vmData[venid][venWorld] = GetPlayerVirtualWorld(playerid);
	vmData[venid][venProduct] = 0;
	vmData[venid][venDrinkPrice] = 0;
	vmData[venid][venMoney] = 0;

	SendStaffMessage(COLOR_RED, "%s telah membuat vending machine ID: %d.", pData[playerid][pAdminname], venid);

  	Vending_Refresh(venid);
	Iter_Add(Vending, venid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO vendingmachine SET ID='%d', owner='%s', price='%d'", venid, vmData[venid][venOwner], vmData[venid][venOwner], vmData[venid][venPrice]);
	mysql_tquery(g_SQL, query, "OnVendingCreated", "i", venid);
	return 1;
}

CMD:editven(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
    	return PermissionError(playerid);

    static
     venid,
    	 type[24],
        	 string[128];

    if(sscanf(params, "ds[24]S()[128]", venid, type, string))
    {
        Usage(playerid, "/editven [id] [name]");
        Names(playerid, "position, location, price, owner, stock, money, reset, delete");
        return 1;
    }

    if(!Iter_Contains(Vending, venid)) 
		return Error(playerid, "Invalid ID.");

	if(Vending_BeingEdited(venid)) 
		return Error(playerid, "Can't edited specified vending because its being edited.");

	if(!strcmp(type, "position", true))
    {
    	if(pData[playerid][pEditing] != -1) 
			return Error(playerid, "You're already editing.");

    	if(!IsPlayerInRangeOfPoint(playerid, 30.0, vmData[venid][venX], vmData[venid][venY], vmData[venid][venZ])) 
			return Error(playerid, "You're not near the vending you want to edit.");

		pData[playerid][pEditing] = venid;
		pData[playerid][pEditType] = EDIT_VENDING;
		EditDynamicObject(playerid, vmData[venid][venObject]);
    }
	if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, vmData[venid][venX], vmData[venid][venY], vmData[venid][venZ]);

        Vending_Save(venid);
		Vending_Refresh(venid);

        SendAdminMessage(COLOR_RED, "%s has adjusted the location of vending ID: %d.", pData[playerid][pAdminname], venid);
    }
    if(!strcmp(type, "price", true))
    {
    	new price;

        if(sscanf(string, "d", price))
            return Usage(playerid, "/editven [id] [price] [Ammount]");

        if(price < 1)
        	return Error(playerid, "price tidak bisa kurang dari angka 1");

		vmData[venid][venPrice] = price;

        Vending_Save(venid);
		Vending_Refresh(venid);

		SendAdminMessage(COLOR_RED, "%s has adjusted the price of vending ID: %d to %s.", pData[playerid][pAdminname], venid, FormatMoney(price));
    }
    else if(!strcmp(type, "owner", true))
    {
        new owners[MAX_PLAYER_NAME];

        if(sscanf(string, "s[32]", owners))
            return Usage(playerid, "/editven [id] [owner] [player name] (use '-' to no owner)");

        format(vmData[venid][venOwner], MAX_PLAYER_NAME, owners);
        vmData[venid][venVisit] = gettime() + (86400 * 30);
        
        Vending_Save(venid);
		Vending_Refresh(venid);

       	SendAdminMessage(COLOR_RED, "%s has adjusted the owner of vending ID: %d to %s", pData[playerid][pAdminname], venid, owners);
    }
    if(!strcmp(type, "stock", true))
    {
    	new prod;

        if(sscanf(string, "d", prod))
            return Usage(playerid, "/editven [id] [product] [Ammount]");

        if(prod < 1 || prod > 100)
        	return Error(playerid, "stock tidak bisa kurang dari 1 dan lebih dari 100");

		vmData[venid][venProduct] = prod;

        Vending_Save(venid);
		Vending_Refresh(venid);

		SendAdminMessage(COLOR_RED, "%s has adjusted the stock of vending ID: %d to %d.", pData[playerid][pAdminname], venid, prod);
    }
    else if(!strcmp(type, "money", true))
    {
        new money;

        if(sscanf(string, "d", money))
            return Usage(playerid, "/editven [id] [money] [Ammount]");

        if(money < 1 || money > 10000)
        	return Error(playerid, "money tidak bisa kurang dari $1 dan lebih dari $10.000");

        vmData[venid][venMoney] = money;

        Vending_Save(venid);
		Vending_Refresh(venid);

       	SendAdminMessage(COLOR_RED, "%s has adjusted the money of vending ID: %d to %s.", pData[playerid][pAdminname], venid, FormatMoney(money));
    }
	else if(!strcmp(type, "reset", true))
    {
		Vending_Reset(venid);
		Vending_Save(venid);

        SendAdminMessage(COLOR_RED, "%s has reset vending ID: %d.", pData[playerid][pAdminname], venid);
	}
    else if(!strcmp(type, "delete", true))
    {
		Vending_Reset(venid);

		new query[512];
		if(IsValidDynamicObject(vmData[venid][venObject]))
			DestroyDynamicObject(vmData[venid][venObject]);

		if(IsValidDynamic3DTextLabel(vmData[venid][venLabel]))
			DestroyDynamic3DTextLabel(vmData[venid][venLabel]);

		vmData[venid][venX] = vmData[venid][venY] = vmData[venid][venZ] = vmData[venid][venRX] = vmData[venid][venRY] = vmData[venid][venRZ] = 0.0;
		vmData[venid][venInt] = vmData[venid][venWorld] = 0;
		vmData[venid][venObject] = -1;
		vmData[venid][venLabel] = Text3D: -1;

		Iter_Remove(Vending, venid);
		
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM vendingmachine WHERE id=%d", venid);
		mysql_tquery(g_SQL, query);
		SendStaffMessage(COLOR_RED, "Staff %s menghapus Vending Machine ID %d.", pData[playerid][pAdminname], venid);
	}
    return 1;
}

CMD:vmedit(playerid, const params[])
{
	foreach(new venid : Vending)
	{
		if(IsPlayerInRangeOfPoint(playerid, 5.0, vmData[venid][venX], vmData[venid][venY], vmData[venid][venZ]))
		{
			if(!Player_OwnsVending(playerid, venid))
				return Error(playerid, "Kamu bukan pemilik vending machine ini.");

			if(Vending_BeingEdited(venid))
				return Error(playerid, "Vending ini sedang dalam perbaikan admin!");

			pData[playerid][pGetVENID] = venid;
			new mstr[248], lstr[512];
			format(mstr,sizeof(mstr),""WHITE_E"VENDING ID %d", venid);
			format(lstr,sizeof(lstr),""WHITE_E"Drink Price \t({00FF00}%s/1 Drink)\n{FFFFFF}Money Storage \t({00ff00}%s{ffffff})\t(%d)", FormatMoney(vmData[venid][venDrinkPrice]), FormatMoney(vmData[venid][venMoney]), vmData[venid][venProduct]);
			ShowPlayerDialog(playerid, VENDING_MENU, DIALOG_STYLE_TABLIST, mstr, lstr,"Select","Close");
			pData[playerid][pGetVENID] = venid;
		}
	}
	return 1;
}

CMD:gotoven(playerid, params[])
{
	new id;
	if(pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
		
	if(sscanf(params, "d", id))
		return Usage(playerid, "/gotoven [id]");
	if(!Iter_Contains(Vending, id)) return Error(playerid, "VENDING ID tidak ada.");
	
	SetPlayerPosition(playerid, vmData[id][venX], vmData[id][venY], vmData[id][venZ], 2.0);
    SetPlayerInterior(playerid, vmData[id][venInt]);
    SetPlayerVirtualWorld(playerid, vmData[id][venWorld]);
	Servers(playerid, "Teleport ke ID VENDING %d", id);
	return 1;
}

CMD:buydrink(playerid, params[])
{
	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT || pData[playerid][pInjured] == 1 || pData[playerid][pCuffed] == 1) 
		return Error(playerid, "You can't do at this moment.");
	{
		foreach(new venid : Vending)
		{
			if(IsPlayerInRangeOfPoint(playerid, 5.0, vmData[venid][venX], vmData[venid][venY], vmData[venid][venZ]))
			{
				if(strcmp(vmData[venid][venOwner], "-")) 
				{
					if(vmData[venid][venDrinkPrice] > pData[playerid][pMoney]) 
						return Error(playerid, "Kamu tidak memiliki uang.");

					if(vmData[venid][venProduct] == 0)
						return Error(playerid, "vending machine ini telah kehabisan stock");

					if(vmData[venid][venDrinkPrice] == 0)
						return Error(playerid, "Harga minuman belum di set");

					if(Vending_BeingEdited(venid))
						return Error(playerid, "Vending ini sedang dalam perbaikan admin!");

					vmData[venid][venProduct] -= 1;
					vmData[venid][venMoney] += vmData[venid][venDrinkPrice];
					GivePlayerMoneyEx(playerid, -vmData[venid][venDrinkPrice]);
					Inventory_Add(playerid, "Sprunk", 2958, 1);
					Info(playerid, "Kamu telah berhasil membeli 1 botol minuman di vending machine seharga "GREEN_LIGHT"%s"WHITE_E"", FormatMoney(vmData[venid][venDrinkPrice]));
					SendNearbyMessage(playerid, 3.0, COLOR_PURPLE, "** %s membeli minuman di vending machine dan langsung meminumnya", ReturnName(playerid));
					Vending_Save(venid);
					VendingLabel_Refresh(venid);
				}
				else return Error(playerid, "Vending Machine ini belum memiliki pemilik");
			}
		}
	}
	return 1;
}

GetOwnedVending(playerid)
{
	new tmpcount;
	foreach(new venid : Vending)
	{
	    if(!strcmp(vmData[venid][venOwner], pData[playerid][pName], true))
	    {
     		tmpcount++;
		}
	}
	return tmpcount;
}
ReturnPlayerVendingID(playerid, hslot)
{
	new tmpcount;
	if(hslot < 1 && hslot > LIMIT_PER_PLAYER) return -1;
	foreach(new venid : Vending)
	{
	    if(!strcmp(pData[playerid][pName], vmData[venid][venOwner], true))
	    {
     		tmpcount++;
       		if(tmpcount == hslot)
       		{
        		return venid;
  			}
	    }
	}
	return -1;
}

CMD:myvending(playerid)
{
	if(GetOwnedVending(playerid) == 0) return Error(playerid, "Anda tidak memiliki vending machine.");
	//if(!Player_OwnsBusiness(playerid, id)) return Error(playerid, "You don't own this business.");
	new venid, _tmpstring[128], count = GetOwnedVending(playerid), CMDSString[512];
	CMDSString = "";
	Loop(itt, (count + 1), 1)
	{
	    venid = ReturnPlayerVendingID(playerid, itt);
		if(itt == count)
		{
		    format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s (ID: %d)\n", itt, GetLocation(vmData[venid][venX], vmData[venid][venY], vmData[venid][venZ]), venid);
		}
		else format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s (ID: %d)\n", itt, GetLocation(vmData[venid][venX], vmData[venid][venY], vmData[venid][venZ]), venid);
		strcat(CMDSString, _tmpstring);
	}
	ShowPlayerDialog(playerid, DIALOG_MY_VENDING, DIALOG_STYLE_LIST, "{FF0000}Local Prime{0000FF}Vending", CMDSString, "Select", "Cancel");
	return 1;
}