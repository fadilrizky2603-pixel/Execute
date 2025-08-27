CMD:createhouse(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
	
	new hid = Iter_Free(Houses), address[128];
	if(hid == -1) return Error(playerid, "You cant create more door!");
	new price, type, query[512];
	if(sscanf(params, "dd", price, type)) return Usage(playerid, "/createhouse [price] [type, 1.small 2.medium 3.Big]");
	format(hData[hid][hOwner], 128, "-");
	format(hData[hid][hOwner2], 128, "-");
	GetPlayerPos(playerid, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]);
	GetPlayerFacingAngle(playerid, hData[hid][hExtposA]);
	hData[hid][hPrice] = price;
	hData[hid][hType] = type;
	address = GetLocation(hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]);
	format(hData[hid][hAddress], 128, address);
	hData[hid][hLocked] = 1;
	
	hData[hid][hMoney] = 0;
	hData[hid][hComponent] = 0;
    hData[hid][hMaterial] = 0;
    hData[hid][hMarijuana] = 0;
    hData[hid][hEphedrine] = 0;
    hData[hid][hCocaine] = 0;
    hData[hid][hMeth] = 0;

	hData[hid][hInt] = 0;
	hData[hid][hIntposX] = 0;
	hData[hid][hIntposY] = 0;
	hData[hid][hIntposZ] = 0;
	hData[hid][hIntposA] = 0;
	hData[hid][hVisit] = 0;
	House_Type(hid);
	
	for (new i = 0; i < 10; i ++) 
	{
        hData[hid][hWeapon][i] = 0;
        hData[hid][hAmmo][i] = 0;
    }
    House_Refresh(hid);
	Iter_Add(Houses, hid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO houses SET ID='%d', owner='%s', owner2='%s', price='%d', type='%d', extposx='%f', extposy='%f', extposz='%f', extposa='%f', address='%s'", hid, hData[hid][hOwner], hData[hid][hOwner2], hData[hid][hPrice], hData[hid][hType], hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ], hData[hid][hExtposA], hData[hid][hAddress]);
	mysql_tquery(g_SQL, query, "OnHousesCreated", "i", hid);
	return 1;
}

function OnHousesCreated(hid)
{
	House_Save(hid);
	return 1;
}

CMD:gotohouse(playerid, params[])
{
	new hid;
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
		
	if(sscanf(params, "d", hid))
		return Usage(playerid, "/gotohouse [id]");
	if(!Iter_Contains(Houses, hid)) return Error(playerid, "The house you specified ID of doesn't exist.");
	SetPlayerPosition(playerid, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ], hData[hid][hExtposA]);
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
	SendClientMessageEx(playerid, COLOR_WHITE, "You has teleport to house id %d", hid);
	pData[playerid][pInDoor] = -1;
	pData[playerid][pInHouse] = -1;
	
	return 1;
}

CMD:typehouses(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
	
	new count = 0;
	foreach(new hid : Houses)
	{
		if(hData[hid][hType] == 1)
		{
			House_Type(hid);
			House_Refresh(hid);
			House_Save(hid);
		}
		if(hData[hid][hType] == 2)
		{
			House_Type(hid);
			House_Refresh(hid);
			House_Save(hid);
		}
		if(hData[hid][hType] == 3)
		{
			House_Type(hid);
			House_Refresh(hid);
			House_Save(hid);
		}
		count++;
	}
	Servers(playerid, "Anda telah me reset house interior type sebanyak %d rumah.", count);
	return 1;
}

CMD:sphouseall(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
	
	new type, price;
	if(sscanf(params, "dd", type, price))
	{
		Usage(playerid, "/sphouseall [type] [price] [1.Low 2.Medium 3.High]");
		return 1;
	}

	if(type < 0 || type > 3)
		return Error(playerid, "House type only 1-3");

	new count = 0;
	foreach(new hid : Houses)
	{
		if(Iter_Contains(Houses, hid))
		{
			if(hData[hid][hType] == type)
			{
				hData[hid][hPrice] = price;
				House_Refresh(hid);
				House_Save(hid);
			}
			count++;
		}
	}
	SendStaffMessage(COLOR_RED, "Staff %s telah mengeset harga semua rumah type %d menjadi %s.", pData[playerid][pAdminname], type, FormatMoney(price));
	return 1;
}

CMD:edithouse(playerid, params[])
{
    static
        hid,
        type[24],
        string[128];

    if(pData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    if(sscanf(params, "ds[24]S()[128]", hid, type, string))
    {
        Usage(playerid, "/edithouse [id] [name]");
        Names(playerid, "location, interior, locked, owner, owner2, price, type, reset, delete");
        return 1;
    }
    if((hid < 0 || hid >= MAX_HOUSES))
        return Error(playerid, "You have specified an invalid ID.");
	if(!Iter_Contains(Houses, hid)) return Error(playerid, "The house you specified ID of doesn't exist.");

    if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]);
		GetPlayerFacingAngle(playerid, hData[hid][hExtposA]);
        House_Save(hid);
		House_Refresh(hid);

        SendAdminMessage(COLOR_LRED, "%s has adjusted the location of house ID: %d.", pData[playerid][pAdminname], hid);
    }
    else if(!strcmp(type, "interior", true))
    {
        GetPlayerPos(playerid, hData[hid][hIntposX], hData[hid][hIntposY], hData[hid][hIntposZ]);
		GetPlayerFacingAngle(playerid, hData[hid][hIntposA]);
		hData[hid][hInt] = GetPlayerInterior(playerid);

        House_Save(hid);
		House_Refresh(hid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the interior spawn of house ID: %d.", pData[playerid][pAdminname], hid);
    }
    else if(!strcmp(type, "locked", true))
    {
        new locked;

        if(sscanf(string, "d", locked))
            return Usage(playerid, "/edithouse [id] [locked] [0/1]");

        if(hData[hid][hLocked] >= 2)
        	return Error(playerid, "Kamu mengubah status locked rumah yang disegel");

        if(locked < 0 || locked > 1)
            return Error(playerid, "You must specify at least 0 or 1.");

        hData[hid][hLocked] = locked;
        House_Save(hid);
		House_Refresh(hid);

        if(locked) {
            SendAdminMessage(COLOR_RED, "%s has locked house ID: %d.", pData[playerid][pAdminname], hid);
        }
        else {
            SendAdminMessage(COLOR_RED, "%s has unlocked house ID: %d.", pData[playerid][pAdminname], hid);
        }
    }
    else if(!strcmp(type, "price", true))
    {
        new price;

        if(sscanf(string, "d", price))
            return Usage(playerid, "/edithouse [id] [Price] [Amount]");

        hData[hid][hPrice] = price;

        House_Save(hid);
		House_Refresh(hid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the price of house ID: %d to %d.", pData[playerid][pAdminname], hid, price);
    }
	else if(!strcmp(type, "type", true))
    {
        new htype;

        if(sscanf(string, "d", htype))
            return Usage(playerid, "/edithouse [id] [Type] [1.small 2.medium 3.Big]");

        if(htype < 0 || htype > 3)
        	return Error(playerid, "House type only 1 - 3");
        
        hData[hid][hType] = htype;
		House_Type(hid);
        House_Save(hid);
		House_Refresh(hid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the type of house ID: %d to %d.", pData[playerid][pAdminname], hid, htype);
    }
    else if(!strcmp(type, "owner", true))
    {
        new owners[MAX_PLAYER_NAME];

        if(sscanf(string, "s[32]", owners))
            return Usage(playerid, "/edithouse [id] [owner] [player name] (use '-' to no owner)");

        format(hData[hid][hOwner], MAX_PLAYER_NAME, owners);
  		hData[hid][hVisit] = gettime() + (86400 * 30);
  		
        House_Save(hid);
		House_Refresh(hid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the owner of house ID: %d to %s", pData[playerid][pAdminname], hid, owners);
    }
    else if(!strcmp(type, "owner2", true))
    {
        new ownerss[MAX_PLAYER_NAME];

        if(sscanf(string, "s[32]", ownerss))
            return Usage(playerid, "/edithouse [id] [owner2] [player name] (use '-' to no owner)");

        format(hData[hid][hOwner2], MAX_PLAYER_NAME, ownerss);
  
        House_Save(hid);
		House_Refresh(hid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the owner2 of house ID: %d to %s", pData[playerid][pAdminname], hid, ownerss);
    }
    else if(!strcmp(type, "reset", true))
    {
        HouseReset(hid);
		House_Save(hid);
		House_Refresh(hid);
        SendAdminMessage(COLOR_RED, "%s has reset house ID: %d.", pData[playerid][pAdminname], hid);
    }
	else if(!strcmp(type, "delete", true))
	{
		HouseReset(hid);
		
		DestroyDynamic3DTextLabel(hData[hid][hLabel]);
        DestroyDynamicPickup(hData[hid][hPickup]);
        DestroyDynamicCP(hData[hid][hCP]);
        DestroyDynamicMapIcon(hData[hid][hIcon]);
		
		hData[hid][hExtposX] = 0;
		hData[hid][hExtposY] = 0;
		hData[hid][hExtposZ] = 0;
		hData[hid][hExtposA] = 0;
		hData[hid][hPrice] = 0;
		hData[hid][hInt] = 0;
		hData[hid][hIntposX] = 0;
		hData[hid][hIntposY] = 0;
		hData[hid][hIntposZ] = 0;
		hData[hid][hIntposA] = 0;
		hData[hid][hLabel] = Text3D: INVALID_3DTEXT_ID;
		hData[hid][hPickup] = -1;
		
		Iter_Remove(Houses, hid);
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM houses WHERE ID=%d", hid);
		mysql_tquery(g_SQL, query);
        SendAdminMessage(COLOR_RED, "%s has delete house ID: %d.", pData[playerid][pAdminname], hid);
	}
    return 1;
}

/*
CMD:buyhouse(playerid, params[])
{
	foreach(new hid : Houses)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.5, hData[hid][hExtpos][0], hData[hid][hExtpos][1], hData[hid][hExtpos][2]))
		{
			if(hData[hid][hPrice] > pData[playerid][pMoney]) return Error(playerid, "Not enough money, you can't afford this houses.");
			if(strcmp(hData[hid][hOwner], "-")) return Error(playerid, "Someone already owns this house.");
			if(pData[playerid][pVip] == 1)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 2) return Error(playerid, "You can't buy any more houses.");
				#endif
			}
			else if(pData[playerid][pVip] == 2)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 3) return Error(playerid, "You can't buy any more houses.");
				#endif
			}
			else if(pData[playerid][pVip] == 3)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 4) return Error(playerid, "You can't buy any more houses.");
				#endif
			}
			else
			{
				#if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 1) return Error(playerid, "You can't buy any more houses.");
				#endif
			}
			GivePlayerMoneyEx(playerid, -hData[hid][hPrice]);
			GetPlayerName(playerid, hData[hid][hOwner], MAX_PLAYER_NAME);
			hData[hid][hVisit] = gettime();
			
			House_Refresh(hid);
			House_Save(hid);
		}
	
	}
	return 1;
}*/
CMD:lockhouse(playerid, params[])
{
	foreach(new hid : Houses)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.5, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]))
		{
			if(!Player_OwnsHouse2(playerid, hid)) 
				return Error(playerid, "You don't own this house.");

			if(hData[hid][hLocked] >= 2)
        		return Error(playerid, "Rumah ini sedang disegel pemerintah");

			if(!hData[hid][hLocked])
			{
				hData[hid][hLocked] = 1;
				House_Save(hid);

				InfoTD_MSG(playerid, 4000, "You have ~r~locked~w~ your house!");
				PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
			}
			else
			{
				hData[hid][hLocked] = 0;
				House_Save(hid);

				InfoTD_MSG(playerid, 4000, "You have ~g~unlocked~w~ your house!");
				PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
			}
		}
	}
	return 1;
}

CMD:givehouse(playerid, params[])
{
	new hid, otherid;
	if(sscanf(params, "ud", otherid, hid)) return Usage(playerid, "/givehouse [playerid/name] [id] | /myhouse - for show info");
	if(hid == -1) return Error(playerid, "Invalid id");
	
	if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
        return Error(playerid, "The specified player is disconnected or not near you.");
	
	if(!Player_OwnsHouse(playerid, hid)) 
		return Error(playerid, "You dont own this id house.");

	if(hData[hid][hLocked] >= 2)
        return Error(playerid, "Kamu tidak dapat memberi rumah yang sedang disegel pemerintah");
	
	if(pData[otherid][pVip] == 1)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_HouseCount(otherid) + 1 > 2) return Error(playerid, "Target player cant own any more houses.");
		#endif
	}
	else if(pData[otherid][pVip] == 2)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_HouseCount(otherid) + 1 > 3) return Error(playerid, "Target player cant own any more houses.");
		#endif
	}
	else if(pData[otherid][pVip] == 3)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_HouseCount(otherid) + 1 > 4) return Error(playerid, "Target player cant own any more houses.");
		#endif
	}
	else
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_HouseCount(otherid) + 1 > 1) return Error(playerid, "Target player cant own any more houses.");
		#endif
	}
	format(hData[hid][hOwner], MAX_PLAYER_NAME, pData[otherid][pName]);

	House_Refresh(hid);
	House_Save(hid);
	Info(playerid, "Anda memberikan rumah id: %d kepada %s", hid, ReturnName(otherid));
	Info(otherid, "%s memberikan rumah id: %d kepada anda", ReturnName(playerid), hid);
	return 1;
}

CMD:sellhouse(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 910.90, 256.46, 1289.98)) return Error(playerid, "Anda harus berada di City Hall!");
	if(GetOwnedHouses(playerid) == -1) return Error(playerid, "You don't have a houses.");
	new hid, _tmpstring[128], count = GetOwnedHouses(playerid), CMDSString[1024];
	CMDSString = "";
	new lock[128];
	Loop(itt, (count + 1), 1)
	{
	    hid = ReturnPlayerHousesID(playerid, itt);
		if(hData[hid][hLocked] == 0)
		{
			lock = ""GREEN_LIGHT"Unlocked"WHITE_E"";
		}
		else if(hData[hid][hLocked] == 1)
		{
			lock = ""RED_E"Locked"WHITE_E"";
		}
		else
		{
			lock = ""RED_E"Sealed"WHITE_E"";
		}
		if(itt == count)
		{
		    format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s   (%s{FFFF2A})\n", itt, hData[hid][hAddress], lock);
		}
		else format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s  (%s{FFFF2A})\n", itt, hData[hid][hAddress], lock);
		strcat(CMDSString, _tmpstring);
	}
	ShowPlayerDialog(playerid, DIALOG_SELL_HOUSES, DIALOG_STYLE_LIST, "Sell Houses", CMDSString, "Sell", "Cancel");
	return 1;
}

CMD:myhouse(playerid, const params[])
{
	if(GetOwnedHouses(playerid) == 0) return Error(playerid, "You don't have a houses.");
	//if(!Player_OwnsBusiness(playerid, id)) return Error(playerid, "You don't own this business.");
	new hid, _tmpstring[128], count = GetOwnedHouses(playerid), CMDSString[1024];
	CMDSString = "";
	new lock[128];
	Loop(itt, (count + 1), 1)
	{
	    hid = ReturnPlayerHousesID(playerid, itt);
		if(hData[hid][hLocked] == 0)
		{
			lock = ""GREEN_LIGHT"Unlocked"WHITE_E"";
		}
		else if(hData[hid][hLocked] == 1)
		{
			lock = ""RED_E"Locked"WHITE_E"";
		}
		else
		{
			lock = ""RED_E"Sealed"WHITE_E"";
		}
		if(itt == count)
		{
		    format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s   (%s)\n", itt, hData[hid][hAddress], lock);
		}
		else format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s  (%s)\n", itt, hData[hid][hAddress], lock);
		strcat(CMDSString, _tmpstring);
	}
	ShowPlayerDialog(playerid, DIALOG_MY_HOUSES, DIALOG_STYLE_LIST, ""GOLD_E"Local Prime {0000FF}Houses", CMDSString, "Select", "Cancel");
	return 1;
}

CMD:hm(playerid, params[])
{
	if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse]))
		if(pData[playerid][pFaction] != 1)
			return Error(playerid, "Kamu bukan pemilik rumah.");

	if(hData[pData[playerid][pInHouse]][hLocked] >= 2)
		return Error(playerid, "Rumah ini sedang disegel oleh pemerintah");

	House_OpenStorage(playerid, pData[playerid][pInHouse]);
    return 1;
}

CMD:givehousekey(playerid, params[])
{
	new hid, otherid;
	if(sscanf(params, "ud", otherid, hid)) return Usage(playerid, "/givehousekey [playerid/name] [houseid] | /myhouse - for show info");
	if(hid == -1) return Error(playerid, "Invalid id");
	
	if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
        return Error(playerid, "The specified player is disconnected or not near you.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid playerid!");

	if(!Player_OwnsHouse(playerid, hid)) 
		return Error(playerid, "You dont own this id house.");

	if(hData[hid][hLocked] >= 2)
		return Error(playerid, "Kamu tidak dapat memberi kunci rumah yang sedang disegel");
	
	GetPlayerName(otherid, hData[hid][hOwner2], MAX_PLAYER_NAME);

	House_Refresh(hid);
	House_Save(hid);
	Info(playerid, "Anda memberikan kunci rumah id: %d kepada %s", hid, ReturnName(otherid));
	Info(otherid, "%s memberikan kunci rumah id: %d kepada anda", ReturnName(playerid), hid);
	return 1;
}

CMD:takehousekey(playerid, params[])
{
	new otherid, hid;
	if(sscanf(params, "ud", otherid, hid))
		return Usage(playerid, "/takehousekey [playerid/name] [houseid] | /myhouse - for show info");

	if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
        return Error(playerid, "The specified player is disconnected or not near you.");

    if(otherid == playerid)
		return Error(playerid, "Invalid playerid!");
	
	if(!Player_OwnsHouse(playerid, hid))
		return Error(playerid, "You dont own this id house.");

	if(!strcmp(hData[hid][hOwner2], "-"))
		return Error(playerid, "Rumah ini tidak memiliki pemilik kedua");

	if(strcmp(hData[hid][hOwner2], pData[otherid][pName], true))
		return Error(playerid, "Player tersebut tidak memegang kunci rumah anda");

	format(hData[hid][hOwner2], MAX_PLAYER_NAME, "-");

	House_Refresh(hid);
	House_Save(hid);
	Info(playerid, "Anda telah mengambil kunci rumah id: %d dari %s", hid, ReturnName(otherid));
	Info(otherid, "%s mengambil kunci rumah id: %d dari anda", ReturnName(playerid), hid);
	return 1;
}
//--------------[ House Dialog ]----------
