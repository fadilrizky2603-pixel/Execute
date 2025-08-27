CMD:createdealer(playerid, const params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);

	new query[512];
	new deid = Iter_Free(Dealer);
	if(deid == -1)
		return Error(playerid, "You cant create more dealer!");

	new price, type;
	if(sscanf(params, "dd", price, type))
	{
		Usage(playerid, "/createdealer [price] [type]");
		Names(playerid, "[NAMES]: {ffffff} 1.Bikes 2.Cars 3.Unique Cars 4.Job Cars 5.Rental Jobs");
		return 1;
	}

	format(drData[deid][dOwner], 128, "-");
	format(drData[deid][dName], 128, "No Name");
	GetPlayerPos(playerid, drData[deid][dPosX], drData[deid][dPosY], drData[deid][dPosZ]);
	GetPlayerFacingAngle(playerid, drData[deid][dPosA]);
	drData[deid][dInt] = GetPlayerInterior(playerid);
	drData[deid][dVW] = GetPlayerVirtualWorld(playerid);
	drData[deid][dPrice] = price;
	drData[deid][dType] = type;
	Dealer_SetPrice(deid);
	Dealer_Refresh(deid);
	Iter_Add(Dealer, deid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO dealer SET id='%d', owner='%s', name='%s', type='%d', price='%d'", deid, drData[deid][dOwner], drData[deid][dName], drData[deid][dType], drData[deid][dPrice]);
	mysql_tquery(g_SQL, query, "OnDealerCreated", "i", deid);
	return 1;
}

function OnDealerCreated(deid)
{
	Dealer_Save(deid);
	return 1;
}

Dealer_Reset(id)
{
	format(drData[id][dOwner], MAX_PLAYER_NAME, "-");
	format(drData[id][dName], 128, "No Name");
	drData[id][dMoney] = 0;
    drData[id][dStock] = 0;
    drData[id][dVisit] = 0;
	Dealer_Refresh(id);
}
	

CMD:editdealer(playerid, const params[])
{
    static
        deid,
        type[24],
        string[128];

    if(pData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    if(sscanf(params, "ds[24]S()[128]", deid, type, string))
    {
        Usage(playerid, "/editdealer [id] [name]");
        Names(playerid, "location, spawnpoint, price, type, owner, prodprice, money, stock, reset, delete");
        return 1;
    }
    if((deid < 0 || deid >= MAX_DEALER))
        return Error(playerid, "You have specified an invalid ID.");

	if(!Iter_Contains(Dealer, deid))
		return Error(playerid, "The dealer you specified ID of doesn't exist.");

    if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, drData[deid][dPosX], drData[deid][dPosY], drData[deid][dPosZ]);
		GetPlayerFacingAngle(playerid, drData[deid][dPosA]);
		drData[deid][dInt] = GetPlayerInterior(playerid);
		drData[deid][dVW] = GetPlayerVirtualWorld(playerid);
        Dealer_Save(deid);
		Dealer_Refresh(deid);

        SendAdminMessage(COLOR_RED, "%s has adjusted the location of dealer ID: %d.", pData[playerid][pAdminname], deid);
    }
    else if(!strcmp(type, "spawnpoint",true))
    {
    	GetPlayerPos(playerid, drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]);
    	GetPlayerFacingAngle(playerid, drData[deid][dVehA]);
    	drData[deid][dVehInt] = GetPlayerInterior(playerid);
    	drData[deid][dVehVW] = GetPlayerVirtualWorld(playerid);
    	Dealer_Save(deid);
    	Dealer_Refresh(deid);

    	SendAdminMessage(COLOR_RED, "%s has adjusted the spawn point vehicle of dealer ID: %d.", pData[playerid][pAdminname], deid);
    }
    else if(!strcmp(type, "price",true))
    {
    	new price;
    	if(sscanf(string, "d", price))
    		return Usage(playerid, "/editdealer [id] [price] [ammount]");

    	if(price < 0)
    		return Error(playerid, "Angka tidak boleh dibawah 0!");

    	drData[deid][dPrice] = price;
    	Dealer_Save(deid);
    	Dealer_Refresh(deid);
    	SendAdminMessage(COLOR_RED, "%s has adjusted the price of dealer ID: %d to %s.", pData[playerid][pAdminname], deid, FormatMoney(price));
    }
    else if(!strcmp(type, "owner", true))
    {
        new owners[MAX_PLAYER_NAME];

        if(sscanf(string, "s[32]", owners))
            return Usage(playerid, "/editdealer [id] [owner] [player name] (use '-' to no owner)");

        format(drData[deid][dOwner], MAX_PLAYER_NAME, owners);
  		drData[deid][dVisit] = gettime() + (86400 * 30);

        Dealer_Save(deid);
		Dealer_Refresh(deid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the owner of dealer ID: %d to %s", pData[playerid][pAdminname], deid, owners);
    }
    else if(!strcmp(type, "stock",true))
    {
    	new ammount;
    	if(sscanf(string, "d", ammount))
    		return Usage(playerid, "/editdealer [id] [stock] [ammount]");

    	if(ammount < 0)
    		return Error(playerid, "Angka tidak boleh dibawah 0!");

    	drData[deid][dStock] = ammount;
    	Dealer_Save(deid);
    	Dealer_Refresh(deid);

    	SendAdminMessage(COLOR_RED, "%s has adjusted the stock vehicle of dealer ID: %d to %d.", pData[playerid][pAdminname], deid, ammount);
    }
    else if(!strcmp(type, "type",true))
    {
    	new typeid;
    	if(sscanf(string, "d", typeid))
    	{
    		Usage(playerid, "/editdealer [id] [type] [typeid]");
    		SendClientMessage(playerid, COLOR_YELLOW, "[NAMES]: {ffffff} 1.Bikes 2.Cars 3.Unique Cars 4.Job Cars 5.Rental Jobs");
    		return 1;
    	}

    	if(typeid < 1 || typeid > 5)
    		return Error(playerid, "Type dealer only 1 - 5!");

    	drData[deid][dType] = typeid;
    	Dealer_SetPrice(deid);
    	Dealer_Save(deid);
    	Dealer_Refresh(deid);
    	SendAdminMessage(COLOR_RED, "%s has adjusted the type of dealer ID: %d to %d.", pData[playerid][pAdminname], deid, typeid);
    }
    else if(!strcmp(type, "prodprice",true))
    {
    	Dealer_SetPrice(deid);
    	Dealer_Save(deid);
    	Dealer_Refresh(deid);
    	SendAdminMessage(COLOR_RED, "%s has adjusted the product price of dealer ID: %d.", pData[playerid][pAdminname], deid);
    }
    else if(!strcmp(type, "money", true))
    {
        new money;

        if(sscanf(string, "d", money))
            return Usage(playerid, "/editdealer [id] [money] [Ammount]");

        if(money < 0)
    		return Error(playerid, "Angka tidak boleh dibawah 0!");

        drData[deid][dMoney] = money;
        Dealer_Save(deid);
		Dealer_Refresh(deid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the money of dealer ID: %d to %s.", pData[playerid][pAdminname], deid, FormatMoney(money));
    }
    else if(!strcmp(type, "reset", true))
    {
        Dealer_Reset(deid);
        Dealer_SetPrice(deid);
		Dealer_Save(deid);
		Dealer_Refresh(deid);
        SendAdminMessage(COLOR_RED, "%s has reset dealer ID: %d.", pData[playerid][pAdminname], deid);
    }
	else if(!strcmp(type, "delete", true))
    {
		Dealer_Reset(deid);
		
		DestroyDynamic3DTextLabel(drData[deid][dLabel]);
		DestroyDynamic3DTextLabel(drData[deid][dLabelSpawn]);
		DestroyDynamicMapIcon(drData[deid][dIcon]);
        DestroyDynamicPickup(drData[deid][dPickup]);
		
		drData[deid][dPrice] = 0;
		drData[deid][dPosX] = 0;
		drData[deid][dPosY] = 0;
		drData[deid][dPosZ] = 0;
		drData[deid][dPosA] = 0;
		drData[deid][dInt] = 0;
		drData[deid][dVW] = 0;

		drData[deid][dVehX] = 0;
		drData[deid][dVehY] = 0;
		drData[deid][dVehZ] = 0;
		drData[deid][dVehA] = 0;
		drData[deid][dVehInt] = 0;
		drData[deid][dVehVW] = 0;

		drData[deid][dLabel] = Text3D: INVALID_3DTEXT_ID;
		drData[deid][dLabelSpawn] = Text3D: INVALID_3DTEXT_ID;
		drData[deid][dPickup] = -1;
		
		Iter_Remove(Dealer, deid);
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM dealer WHERE id=%d", deid);
		mysql_tquery(g_SQL, query);
        SendAdminMessage(COLOR_RED, "%s has delete dealer ID: %d.", pData[playerid][pAdminname], deid);
	}
    return 1;
}

CMD:gotodealer(playerid, const params[])
{
	if(pData[playerid][pAdmin] < 3)
		return PermissionError(playerid);

	new deid, type[128];
	if(sscanf(params, "ds[128]", deid, type))
	{
		Usage(playerid, "/gotodealer [id] [type]");
		SendClientMessage(playerid, COLOR_YELLOW, "[NAMES]:{ffffff} pickup, spawnpoint");
		return 1;
	}

	if(!Iter_Contains(Dealer, deid))
		return Error(playerid, "The Dealer you specified ID of doesn't exist.");
	
	if(!strcmp(type, "pickup", true))
	{
		SetPlayerPos(playerid, drData[deid][dPosX], drData[deid][dPosY], drData[deid][dPosZ]);
		SetPlayerInterior(playerid, drData[deid][dInt]);
		SetPlayerVirtualWorld(playerid, drData[deid][dVW]);
	}
	else if(!strcmp(type, "spawnpoint", true))
	{
		SetPlayerPos(playerid, drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]);
		SetPlayerInterior(playerid, drData[deid][dVehInt]);
		SetPlayerVirtualWorld(playerid, drData[deid][dVehVW]);
	}
	return 1;
}

CMD:dem(playerid, const params[])
{
	foreach(new deid : Dealer)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, drData[deid][dPosX], drData[deid][dPosY], drData[deid][dPosZ]))
		{
			if(drData[deid][dLock] >= 1)
				return Error(playerid, "Dealer ini sedang disegel oleh pemerintah");

			pData[playerid][pGetDEID] = deid;
			if(!Player_OwnsDealer(playerid, pData[playerid][pGetDEID]))
				return Error(playerid, "Kamu bukan pemilik dealer ini.");

			new str[128];
			format(str, sizeof(str), "Dealer Menu (ID : %d)", deid);
		    ShowPlayerDialog(playerid, DEALER_MENU, DIALOG_STYLE_LIST, str,"Dealer Info\nChange Name\nDealer Vault\nProduct Menu","Next","Close");
		}
	}
    return 1;
}

GetOwnedDealer(playerid)
{
	new tmpcount;
	foreach(new deid : Dealer)
	{
	    if(!strcmp(drData[deid][dOwner], pData[playerid][pName], true))
	    {
     		tmpcount++;
		}
	}
	return tmpcount;
}
ReturnPlayerDealerID(playerid, hslot)
{
	new tmpcount;
	if(hslot < 1 && hslot > LIMIT_PER_PLAYER) return -1;
	foreach(new deid : Dealer)
	{
	    if(!strcmp(pData[playerid][pName], drData[deid][dOwner], true))
	    {
     		tmpcount++;
       		if(tmpcount == hslot)
       		{
        		return deid;
  			}
	    }
	}
	return -1;
}

CMD:selldealer(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 910.90, 256.46, 1289.98)) return Error(playerid, "Anda harus berada di City Hall!");
	if(GetOwnedDealer(playerid) == 0) return Error(playerid, "Anda tidak memiliki Dealer.");
	new deid, _tmpstring[128], count = GetOwnedDealer(playerid), CMDSString[512];
	CMDSString = "";
	Loop(itt, (count + 1), 1)
	{
	    deid = ReturnPlayerDealerID(playerid, itt);
		if(itt == count)
		{
		    format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s   (%s{FFFF2A})\n", itt, drData[deid][dName], GetLocation(drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]));
		}
		else format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s  (%s{FFFF2A})\n", itt, drData[deid][dName], GetLocation(drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]));
		strcat(CMDSString, _tmpstring);
	}
	ShowPlayerDialog(playerid, DIALOG_SELL_DEALER, DIALOG_STYLE_LIST, "Sell Dealer", CMDSString, "Sell", "Cancel");
	return 1;
}

CMD:mydealer(playerid)
{
	if(GetOwnedDealer(playerid) == 0) return Error(playerid, "Anda tidak memiliki bisnis dealer.");
	//if(!Player_OwnsBusiness(playerid, id)) return Error(playerid, "You don't own this business.");
	new deid, _tmpstring[128], count = GetOwnedDealer(playerid), CMDSString[512];
	CMDSString = "";
	Loop(itt, (count + 1), 1)
	{
	    deid = ReturnPlayerDealerID(playerid, itt);
		if(itt == count)
		{
		    format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s   {ffffff}(%s)\n", itt, drData[deid][dName], GetLocation(drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]));
		}
		else format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s  {ffffff}(%s)\n", itt, drData[deid][dName], GetLocation(drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]));
		strcat(CMDSString, _tmpstring);
	}
	ShowPlayerDialog(playerid, DIALOG_MY_DEALER, DIALOG_STYLE_LIST, "{FF0000}Local Prime {0000FF}Dealer", CMDSString, "Select", "Cancel");
	return 1;
}

CMD:givedealer(playerid, const params[])
{
	new deid, otherid;
	if(sscanf(params, "ud", otherid, deid)) return Usage(playerid, "/givedealer [playerid/name] [id] | /mydealer - for show info");
	if(deid == -1) return Error(playerid, "Invalid id");
	
	if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
        return Error(playerid, "Player tersebut telah disconnect/tidak berada didekat dirimu.");
	
	if(!Player_OwnsDealer(playerid, deid)) return Error(playerid, "Kamu tidak memiliki Dealer ini.");
	if(pData[otherid][pVip] == 1)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_DealerCount(otherid) + 1 > 2) return Error(playerid, "Target Player tidak dapat memiliki dealer lebih.");
		#endif
	}
	else if(pData[otherid][pVip] == 2)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_DealerCount(otherid) + 1 > 3) return Error(playerid, "Target Player tidak dapat memiliki dealer lebih.");
		#endif
	}
	else if(pData[otherid][pVip] == 3)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_DealerCount(otherid) + 1 > 4) return Error(playerid, "Target Player tidak dapat memiliki dealer lebih.");
		#endif
	}
	else
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_DealerCount(otherid) + 1 > 1) return Error(playerid, "Target Player tidak dapat memiliki dealer lebih.");
		#endif
	}
	format(drData[deid][dOwner], MAX_PLAYER_NAME, pData[otherid][pName]);
	
	Dealer_Refresh(deid);
	Dealer_Save(deid);
	Info(playerid, "Anda memberikan dealer id: %d kepada %s", deid, ReturnName(otherid));
	Info(otherid, "%s memberikan dealer id: %d kepada anda", ReturnName(playerid), deid);
	return 1;
}

CMD:belikendarran(playerid, const params[])
{
	new count = 0;
	foreach(new deid : Dealer)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, drData[deid][dPosX], drData[deid][dPosY], drData[deid][dPosZ]))
		{
			if(drData[deid][dLock] >= 1)
				return Error(playerid, "Dealer ini sedang disegel oleh pemerintah");

			count++;
			pData[playerid][pGetDEID] = deid;
			Dealer_BuyMenu(playerid, pData[playerid][pGetDEID]);
		}
	}

	if(count < 1)
		return Error(playerid, "Kamu harus berada didekat buy point dealer");
	
	return 1;
}

CMD:spdealerall(playerid, const params[])
{
	if(pData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
	
	new type, price;
	if(sscanf(params, "dd", type, price))
	{
		Usage(playerid, "/spdealerall [type] [price]");
		SendClientMessage(playerid, COLOR_YELLOW, "[NAMES]: {ffffff} 1.Bikes 2.Cars 3.Unique Cars 4.Job Cars 5.Rental Jobs");
		return 1;
	}

	if(type < 1 || type > 5)
		return Error(playerid, "Dealer type only 1-5");

	new count = 0;
	foreach(new deid : Dealer)
	{
		if(drData[deid][dType] == type)
		{
			drData[deid][dPrice] = price;
			Dealer_Refresh(deid);
			Dealer_Save(deid);
		}
		count++;
	}
	SendStaffMessage(COLOR_RED, "Staff %s telah mengeset harga semua dealer type %d menjadi %s.", pData[playerid][pAdminname], type, FormatMoney(price));
	return 1;
}

CMD:sipdealerall(playerid, const params[])
{
	if(pData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
	
	new type;
	if(sscanf(params, "dd", type))
	{
		Usage(playerid, "/sipdealerall [type] [1.Bikes 2.Cars 3.Unique Cars 4.Job Cars 5.Rental Jobs]");
		return 1;
	}

	if(type < 1 || type > 5)
		return Error(playerid, "Dealer type only 1-5");
	new count = 0;
	foreach(new deid : Dealer)
	{
		if(drData[deid][dType] == type)
		{
			Dealer_SetPrice(deid);
			Dealer_Refresh(deid);
			Dealer_Save(deid);
		}
		count++;
	}	
	SendStaffMessage(COLOR_RED, "Staff %s telah mengeset Semua harga Kendaraan di dealer %d.", pData[playerid][pAdminname], type);
	return 1;
}

/*
	//--------- [ENUM PLAYER]--------
	//DEALER
	pGetDEID,
	pGetDEIDPRICE,

	//---------[ENUM DIALOG]-----------
	//DEALER SYSTEM
	DIALOG_RENTBOAT,
	DIALOG_RENTBOAT_CONFIRM,
	DIALOG_RENT_BIKECONFIRM,
	DEALER_MENU,
	DEALER_NAME,
	DEALER_VAULT,
	DEALER_WITHDRAW,
	DEALER_DEPOSIT,
	DEALER_EDITPROD,
	DEALER_SETPRICE,



	//----------[ DEALER DIALOG ] -------------
	if(dialogid == DEALER_MENU)
	{
		new deid = pData[playerid][pGetDEID];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{	
					new mstr[248], lstr[512];
					format(mstr,sizeof(mstr),"Dealer ID %d", deid);
					format(lstr,sizeof(lstr),"Dealer Name:\t%s\nDealer Product:\t%d\nDealer Money Vault:\t%s", drData[deid][dName], drData[deid][dStock], FormatMoney(drData[deid][dMoney]));
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, mstr, lstr,"Back","Close");
				}
				case 1:
				{
					new mstr[248];
					format(mstr,sizeof(mstr),"Nama sebelumnya: %s\n\nMasukkan nama dealer yang kamu inginkan\nMaksimal 32 karakter untuk nama bisnis", drData[deid][dName]);
					ShowPlayerDialog(playerid, DEALER_NAME, DIALOG_STYLE_INPUT,"Dealer Name", mstr,"Done","Back");
				}
				case 2: ShowPlayerDialog(playerid, DEALER_VAULT, DIALOG_STYLE_LIST,"Dealer Vault","Deposit\nWithdraw","Next","Back");
				case 3:
				{
					Dealer_ProductMenu(playerid, deid);
				}
				case 4:
				{
					if(drData[deid][dStock] > 50)
						return Error(playerid, "Dealer ini masih memiliki cukup produck.");

					if(drData[deid][dMoney] < 5000)
						return Error(playerid, "Setidaknya anda mempunyai uang dalam dealer anda senilai $50.00 untuk mereproduct.");

					drData[deid][dRestock] = 1;
					Dealer_Save(deid);
					Info(playerid, "Anda berhasil request untuk stock mengisi dealer kepada pekerja hauling, harap tunggu sampai pekerja hauling melayani.");
				}
			}
		}
		return 1;
	}
	if(dialogid == DEALER_NAME)
	{
		if(response)
		{
			new deid = pData[playerid][pGetDEID];

			if(!Player_OwnsDealer(playerid, pData[playerid][pGetDEID])) return Error(playerid, "You don't own this dealer.");
			
			if (isnull(inputtext))
			{
				new mstr[512];
				format(mstr,sizeof(mstr),""RED_E"NOTE: "WHITE_E"Nama Dealer tidak di perbolehkan kosong!\n\n"WHITE_E"Nama sebelumnya: %s\n\nMasukkan nama Bisnis yang kamu inginkan\nMaksimal 32 karakter untuk nama Bisnis", drData[deid][dName]);
				ShowPlayerDialog(playerid, DEALER_NAME, DIALOG_STYLE_INPUT,"Dealer Name", mstr,"Done","Back");
				return 1;
			}
			if(strlen(inputtext) > 32 || strlen(inputtext) < 5)
			{
				new mstr[512];
				format(mstr,sizeof(mstr),""RED_E"NOTE: "WHITE_E"Nama Dealer harus 5 sampai 32 karakter.\n\n"WHITE_E"Nama sebelumnya: %s\n\nMasukkan nama Bisnis yang kamu inginkan\nMaksimal 32 karakter untuk nama Bisnis", drData[deid][dName]);
				ShowPlayerDialog(playerid, DEALER_NAME, DIALOG_STYLE_INPUT,"Dealer Name", mstr,"Done","Back");
				return 1;
			}
			format(drData[deid][dName], 32, ColouredText(inputtext));

			Dealer_Refresh(deid);
			Dealer_Save(deid);

			Servers(playerid, "Dealer name set to: \"%s\".", drData[deid][dName]);
		}
		else return callcmd::dem(playerid, "");
		return 1;
	}
	if(dialogid == DEALER_VAULT)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Uang kamu: %s.\n\nMasukkan berapa banyak uang yang akan kamu simpan di dalam dealer ini", FormatMoney(pData[playerid][pMoney]));
					ShowPlayerDialog(playerid, DEALER_DEPOSIT, DIALOG_STYLE_INPUT, "Deposit", mstr, "Deposit", "Back");
				}
				case 1:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Dealer Vault: %s\n\nMasukkan berapa banyak uang yang akan kamu ambil di dalam dealer ini", FormatMoney(drData[pData[playerid][pGetDEID]][dMoney]));
					ShowPlayerDialog(playerid, DEALER_WITHDRAW, DIALOG_STYLE_INPUT,"Withdraw", mstr,"Withdraw","Back");
				}
			}
		}
		return 1;
	}
	if(dialogid == DEALER_WITHDRAW)
	{
		if(response)
		{
			new deid = pData[playerid][pGetDEID];
			new amount = floatround(strval(inputtext));
			if(amount < 1 || amount > drData[deid][dMoney])
				return Error(playerid, "Invalid amount specified!");

			drData[deid][dMoney] -= amount;
			Dealer_Save(deid);

			GivePlayerMoneyEx(playerid, amount);

			SendClientMessageEx(playerid, COLOR_LBLUE,"DEALER: "WHITE_E"You have withdrawn "GREEN_E"%s "WHITE_E"from the dealer vault.", FormatMoney(strval(inputtext)));
		}
		else
			ShowPlayerDialog(playerid, DEALER_VAULT, DIALOG_STYLE_LIST,"Dealer Vault","Deposit\nWithdraw","Next","Back");
		return 1;
	}
	if(dialogid == DEALER_DEPOSIT)
	{
		if(response)
		{
			new deid = pData[playerid][pGetDEID];
			new amount = floatround(strval(inputtext));
			if(amount < 1 || amount > pData[playerid][pMoney])
				return Error(playerid, "Invalid amount specified!");

			drData[deid][dMoney] += amount;
			Dealer_Save(deid);

			GivePlayerMoneyEx(playerid, -amount);
			
			SendClientMessageEx(playerid, COLOR_LBLUE,"DEALER: "WHITE_E"You have deposit "GREEN_E"%s "WHITE_E"into the dealer vault.", FormatMoney(strval(inputtext)));
		}
		else
			ShowPlayerDialog(playerid, DEALER_VAULT, DIALOG_STYLE_LIST,"Dealer Vault","Deposit\nWithdraw","Next","Back");
		return 1;
	}
	if(dialogid == DEALER_EDITPROD)
	{
		if(Player_OwnsDealer(playerid, pData[playerid][pGetDEID]))
		{
			if(response)
			{
				static
					item[40],
					str[128];

				strmid(item, inputtext, 0, strfind(inputtext, "-") - 1);
				strpack(pData[playerid][pEditingItem], item, 40 char);

				pData[playerid][pProductModify] = listitem;
				format(str,sizeof(str), "Please enter the new product price for %s:", item);
				ShowPlayerDialog(playerid, DEALER_SETPRICE, DIALOG_STYLE_INPUT, "Dealer: Set Price", str, "Modify", "Back");
			}
			else
				return callcmd::dem(playerid, "");
		}
		return 1;
	}
	if(dialogid == DEALER_SETPRICE)
	{
		static
        item[40];
		new deid = pData[playerid][pGetDEID];
		if(Player_OwnsDealer(playerid, pData[playerid][pGetDEID]))
		{
			if(response)
			{
				strunpack(item, pData[playerid][pEditingItem]);

				if(isnull(inputtext))
				{
					new str[128];
					format(str,sizeof(str), "Please enter the new product price for %s:", item);
					ShowPlayerDialog(playerid, DEALER_SETPRICE, DIALOG_STYLE_INPUT, "Dealer: Set Price", str, "Modify", "Back");
					return 1;
				}
				if(strval(inputtext) < 1 || strval(inputtext) > 500000)
				{
					new str[128];
					format(str,sizeof(str), "Please enter the new product price for %s ($1 to $5000.00):", item);
					ShowPlayerDialog(playerid, DEALER_SETPRICE, DIALOG_STYLE_INPUT, "Dealer: Set Price", str, "Modify", "Back");
					return 1;
				}
				drData[deid][dP][pData[playerid][pProductModify]] = strval(inputtext);
				Dealer_Save(deid);

				Servers(playerid, "You have adjusted the price of %s to: %s!", item, FormatMoney(strval(inputtext)));
				Dealer_ProductMenu(playerid, deid);
			}
			else
			{
				Dealer_ProductMenu(playerid, deid);
			}
		}
		return 1;
	}


--------------[CMD PLAYER]--------------
	//Buy Dealer
	foreach(new deid : Dealer)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, drData[deid][dPosX], drData[deid][dPosY], drData[deid][dPosZ]))
		{
			if(drData[deid][dPrice] > pData[playerid][pMoney]) return Error(playerid, "Not enough money, you can't afford this dealer.");
			if(strcmp(drData[deid][dOwner], "-")) return Error(playerid, "Someone already owns this dealer.");
			if(pData[playerid][pVip] == 1)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_DealerCount(playerid) + 1 > 2) return Error(playerid, "Anda tidak dapat membeli bisnis lagi.");
				#endif
			}
			else if(pData[playerid][pVip] == 2)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_DealerCount(playerid) + 1 > 3) return Error(playerid, "Anda tidak dapat membeli bisnis lagi.");
				#endif
			}
			else if(pData[playerid][pVip] == 3)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_DealerCount(playerid) + 1 > 4) return Error(playerid, "Anda tidak dapat membeli bisnis lagi.");
				#endif
			}
			else
			{
				#if LIMIT_PER_PLAYER > 0
				if(Player_DealerCount(playerid) + 1 > 1) return Error(playerid, "Anda tidak dapat membeli bisnis lagi.");
				#endif
			}
			GivePlayerMoneyEx(playerid, -drData[deid][dPrice]);
			Server_AddMoney(-drData[deid][dPrice]);
			GetPlayerName(playerid, drData[deid][dOwner], MAX_PLAYER_NAME);
			
			Dealer_Refresh(deid);
			Dealer_Save(deid);
		}
	}
*/