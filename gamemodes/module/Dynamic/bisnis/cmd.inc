CMD:createbiz(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
	
	new query[512];
	new bid = Iter_Free(Bisnis), address[128];
	if(bid == -1) return Error(playerid, "You cant create more door!");
	new price, type;
	if(sscanf(params, "dd", price, type)) return SyntaxMsg(playerid, "/createbusiness [price] [type, 1.Clubhouse 2.Market 3.Clothes 4.Equipment 5.Electronics]");
	format(bData[bid][bOwner], 128, "-");
	bData[bid][bOwnerID] = -1;
	GetPlayerPos(playerid, bData[bid][bExtposX], bData[bid][bExtposY], bData[bid][bExtposZ]);
	GetPlayerFacingAngle(playerid, bData[bid][bExtposA]);
	bData[bid][bPrice] = price;
	bData[bid][bType] = type;
	address = GetLocation(bData[bid][bExtposX], bData[bid][bExtposY], bData[bid][bExtposZ]);
	format(bData[bid][bName], 128, address);
	bData[bid][bLocked] = 1;
	bData[bid][bMoney] = 0;
	bData[bid][bProd] = 0;
	bData[bid][bP][0] = 0;
	bData[bid][bP][1] = 0;
	bData[bid][bP][2] = 0;
	bData[bid][bP][3] = 0;
	bData[bid][bP][4] = 0;
	bData[bid][bP][5] = 0;
	bData[bid][bP][6] = 0;
	bData[bid][bP][7] = 0;
	bData[bid][bP][8] = 0;
	bData[bid][bP][9] = 0;
	bData[bid][bVisit] = 0;
	bData[bid][bRestock] = 0;

	Iter_Add(Bisnis, bid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO bisnis SET ID='%d', owner='%s', ownerid='%d', price='%d', type='%d', extposx='%f', extposy='%f', extposz='%f', extposa='%f', name='%s'", bid, bData[bid][bOwner], bData[bid][bOwnerID], bData[bid][bPrice], bData[bid][bType], bData[bid][bExtposX], bData[bid][bExtposY], bData[bid][bExtposZ], bData[bid][bExtposA], bData[bid][bName]);
	mysql_tquery(g_SQL, query, "OnBisnisCreated", "ii", playerid, bid);
	return 1;
}

function OnBisnisCreated(playerid, bid)
{
    Bisnis_Refresh(bid);
	Servers(playerid, "Business [%d] berhasil di buat!", bid);
	return 1;
}

function GetClosestBusiness(playerid, type)
{
	new
	    Float:distance[2] = {99999.0, 0.0},
	    index = -1;

	for(new i = 0; i < MAX_BISNIS; i ++)
	{
		if((bData[i][bType] == type))
		{
			distance[1] = GetPlayerDistanceFromPoint(playerid, bData[i][bExtposX], bData[i][bExtposY], bData[i][bExtposZ]);

			if(distance[0] > distance[1])
			{
			    distance[0] = distance[1];
			    index = i;
			}
		}
	}

	return index;
}

CMD:gotobiz(playerid, params[])
{
	new bid;
	if(pData[playerid][pAdmin] < 1)
		return PermissionError(playerid);
		
	if(sscanf(params, "d", bid))
		return SyntaxMsg(playerid, "/gotobiz [id]");
	if(!Iter_Contains(Bisnis, bid)) return Error(playerid, "The Bisnis you specified ID of doesn't exist.");
	SetPlayerPosition(playerid, bData[bid][bExtposX], bData[bid][bExtposY], bData[bid][bExtposZ], bData[bid][bExtposA]);
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
	SendClientMessageEx(playerid, COLOR_WHITE, "You has teleport to bisnis id %d", bid);
	pData[playerid][pInDoor] = -1;
	pData[playerid][pInHouse] = -1;
	pData[playerid][pInBiz] = -1;
	return 1;
}

CMD:editbiz(playerid, params[])
{
    static
        bid,
        type[24],
        string[128];

    if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

    if(sscanf(params, "ds[24]S()[128]", bid, type, string))
    {
        SyntaxMsg(playerid, "/editbiz [id] [name]");
        SendClientMessage(playerid, COLOR_YELLOW, "[NAMES]:{FFFFFF} location, locked, owner, price, type, product, restock, reset");
        return 1;
    }
    if((bid < 0 || bid >= MAX_BISNIS))
        return Error(playerid, "You have specified an invalid ID.");
	if(!Iter_Contains(Bisnis, bid)) return Error(playerid, "The bisnis you specified ID of doesn't exist.");

    if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, bData[bid][bExtposX], bData[bid][bExtposY], bData[bid][bExtposZ]);
		GetPlayerFacingAngle(playerid, bData[bid][bExtposA]);

		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET extposx='%f', extposy='%f', extposz='%f', extposa='%f' WHERE ID='%d'", bData[bid][bExtposX], bData[bid][bExtposY], bData[bid][bExtposZ], bData[bid][bExtposA], bid);
		mysql_tquery(g_SQL, query);

		Bisnis_Refresh(bid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the location of bisnis ID: %d.", pData[playerid][pAdminname], bid);
    }
    else if(!strcmp(type, "locked", true))
    {
        new locked;

        if(sscanf(string, "d", locked))
            return SyntaxMsg(playerid, "/editbisnis [id] [locked] [0/1]");

        if(locked < 0 || locked > 1)
            return Error(playerid, "You must specify at least 0 or 1.");

        bData[bid][bLocked] = locked;
		
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET locked='%d' WHERE ID='%d'", bData[bid][bLocked], bid);
		mysql_tquery(g_SQL, query);

		Bisnis_Refresh(bid);

        if(locked) {
            SendAdminMessage(COLOR_RED, "%s has locked bisnis ID: %d.", pData[playerid][pAdminname], bid);
        }
        else {
            SendAdminMessage(COLOR_RED, "%s has unlocked bisnis ID: %d.", pData[playerid][pAdminname], bid);
        }
    }
    else if(!strcmp(type, "price", true))
    {
        new price;

        if(sscanf(string, "d", price))
            return SyntaxMsg(playerid, "/editbisnis [id] [Price] [Amount]");

        bData[bid][bPrice] = price;
		
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET price='%d' WHERE ID='%d'", bData[bid][bPrice], bid);
		mysql_tquery(g_SQL, query);

		Bisnis_Refresh(bid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the price of bisnis ID: %d to %d.", pData[playerid][pAdminname], bid, price);
    }
	else if(!strcmp(type, "type", true))
    {
        new btype;

        if(sscanf(string, "d", btype))
            return SyntaxMsg(playerid, "/editbisnis [id] [Type] [1.Fastfood 2.Market 3.Clothes 4.Equipment 5.Electronics]");

        bData[bid][bType] = btype;

		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET type='%d' WHERE ID='%d'", bData[bid][bType], bid);
		mysql_tquery(g_SQL, query);

		Bisnis_Refresh(bid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the type of bisnis ID: %d to %d.", pData[playerid][pAdminname], bid, btype);
    }
	else if(!strcmp(type, "product", true))
    {
        new prod;

        if(sscanf(string, "d", prod))
            return SyntaxMsg(playerid, "/editbisnis [id] [product] [Ammount]");

        bData[bid][bProd] = prod;
		
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d' WHERE ID='%d'", bData[bid][bProd], bid);
		mysql_tquery(g_SQL, query);

		Bisnis_Refresh(bid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the product of bisnis ID: %d to %d.", pData[playerid][pAdminname], bid, prod);
    }
	else if(!strcmp(type, "money", true))
    {
        new money;

        if(sscanf(string, "d", money))
            return SyntaxMsg(playerid, "/editbisnis [id] [money] [Ammount]");

        bData[bid][bMoney] = money;
		
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET money='%d' WHERE ID='%d'", bData[bid][bMoney], bid);
		mysql_tquery(g_SQL, query);

		Bisnis_Refresh(bid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the money of bisnis ID: %d to %s.", pData[playerid][pAdminname], bid, FormatMoney(money));
    }
	else if(!strcmp(type, "restock", true))
    {
        new prod;

        if(sscanf(string, "d", prod))
            return SyntaxMsg(playerid, "/editbisnis [id] [restock] [0-1]");
		
		if(prod == 0)
		{
			bData[bid][bRestock] = 0;
			
			new query[128];
			mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET restock='%d' WHERE ID='%d'", bData[bid][bRestock], bid);
			mysql_tquery(g_SQL, query);

			Bisnis_Refresh(bid);
			SendAdminMessage(COLOR_RED, "%s has adjusted the restock of bisnis ID: %d to disable.", pData[playerid][pAdminname], bid);
		}
		else if(prod == 1)
		{
			bData[bid][bRestock] = 1;
			
			new query[128];
			mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET restock='%d' WHERE ID='%d'", bData[bid][bRestock], bid);
			mysql_tquery(g_SQL, query);

			Bisnis_Refresh(bid);
			SendAdminMessage(COLOR_RED, "%s has adjusted the restock of bisnis ID: %d to enable.", pData[playerid][pAdminname], bid);
		}
		else return Error(playerid, "Hanya id 0-1");
    }
	else if(!strcmp(type, "owner", true))
    {
		new otherid;
        if(sscanf(string, "d", otherid))
            return SyntaxMsg(playerid, "/editbiz [id] [owner] [playerid] (use '-1' to no owner/ reset)");
		if(otherid == -1)
			return format(bData[bid][bOwner], MAX_PLAYER_NAME, "-");

        format(bData[bid][bOwner], MAX_PLAYER_NAME, pData[otherid][pName]);
		bData[bid][bOwnerID] = pData[otherid][pID];
		bData[bid][bVisit] = gettime() + (86400 * 30);

		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET owner='%s', ownerid='%d' WHERE ID='%d'", bData[bid][bOwner], bData[bid][bOwnerID], bid);
		mysql_tquery(g_SQL, query);

		Bisnis_Refresh(bid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the owner of business ID: %d to %s", pData[playerid][pAdminname], bid, pData[otherid][pName]);
    }
    else if(!strcmp(type, "reset", true))
    {
        Bisnis_Reset(bid);
		Bisnis_Save(bid);
		Bisnis_Refresh(bid);
        SendAdminMessage(COLOR_RED, "%s has reset bisnis ID: %d.", pData[playerid][pAdminname], bid);
    }
	else if(!strcmp(type, "delete", true))
    {
		Bisnis_Reset(bid);
		
		DestroyDynamic3DTextLabel(bData[bid][bLabel]);
		DestroyDynamicMapIcon(bData[bid][bMap]);
		
		bData[bid][bExtposX] = 0;
		bData[bid][bExtposY] = 0;
		bData[bid][bExtposZ] = 0;
		bData[bid][bExtposA] = 0;
		bData[bid][bPrice] = 0;
		bData[bid][bLabel] = Text3D: INVALID_3DTEXT_ID;
		
		Iter_Remove(Bisnis, bid);
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM bisnis WHERE ID=%d", bid);
		mysql_tquery(g_SQL, query);
        SendAdminMessage(COLOR_RED, "%s has delete bisnis ID: %d.", pData[playerid][pAdminname], bid);
	}
    return 1;
}

CMD:lockbisnis(playerid, params[])
{
	foreach(new bid : Bisnis)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.5, bData[bid][bExtposX], bData[bid][bExtposY], bData[bid][bExtposZ]))
		{
			if(!Player_OwnsBisnis(playerid, bid)) return Error(playerid, "Kamu tidak memiliki Bisnis ini.");
			if(!bData[bid][bLocked])
			{
				bData[bid][bLocked] = 1;
				
				new query[128];
				mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET locked='%d' WHERE ID='%d'", bData[bid][bLocked], bid);
				mysql_tquery(g_SQL, query);

				InfoTD_MSG(playerid, 4000, "Bisnis anda berhasil ~r~Dikunci!");
				PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
			}
			else
			{
				bData[bid][bLocked] = 0;
				
				new query[128];
				mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET locked='%d' WHERE ID='%d'", bData[bid][bLocked], bid);
				mysql_tquery(g_SQL, query);

				InfoTD_MSG(playerid, 4000, "Bisnis anda berhasil ~g~Dibuka");
				PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
			}
		}
	}
	return 1;
}

CMD:sellbusiness(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 1487.868408,-1789.390747,-34.880939)) return ErrorMsg(playerid, "Anda harus berada di kantor pemerintah");
	if(GetOwnedBisnis(playerid) == -1) return Error(playerid, "Anda tidak memiliki bisnis.");
	//if(!Player_OwnsBusiness(playerid, id)) return Error(playerid, "You don't own this business.");
	new hid, _tmpstring[128], count = GetOwnedBisnis(playerid), CMDSString[512];
	CMDSString = "";
	new lock[128];
	Loop(itt, (count + 1), 1)
	{
	    hid = ReturnPlayerBisnisID(playerid, itt);
		if(hData[hid][hLocked] == 1)
		{
			lock = "{FF0000}Terbuka";
		
		}
		else
		{
			lock = "{00FF00}Terkunci";
		}
		if(itt == count)
		{
		    format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s   (%s{FFFF2A})\n", itt, bData[hid][bName], lock);
		}
		else format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s  (%s{FFFF2A})\n", itt, bData[hid][bName], lock);
		strcat(CMDSString, _tmpstring);
	}
	ShowPlayerDialog(playerid, DIALOG_SELL_BISNIS, DIALOG_STYLE_LIST, "Sell Bisnis", CMDSString, "Sell", "Cancel");
	return 1;
}

CMD:mybis(playerid)
{
	if(GetOwnedBisnis(playerid) == -1) return ErrorMsg(playerid, "Anda tidak memiliki bisnis.");
	//if(!Player_OwnsBusiness(playerid, id)) return Error(playerid, "You don't own this business.");
	new hid, _tmpstring[128], count = GetOwnedBisnis(playerid), CMDSString[512];
	CMDSString = "";
	new lock[128];
	Loop(itt, (count + 1), 1)
	{
	    hid = ReturnPlayerBisnisID(playerid, itt);
		if(hData[hid][hLocked] == 1)
		{
			lock = "{FF0000}Dikunci{ffffff}";
		
		}
		else
		{
			lock = "{00FF00}Dibuka{ffffff}";
		}
		if(itt == count)
		{
		    format(_tmpstring, sizeof(_tmpstring), "%d.\t%s   {ffffff}(%s)\n", itt, bData[hid][bName], lock);
		}
		else format(_tmpstring, sizeof(_tmpstring), "%d.\t%s  {ffffff}(%s)\n", itt, bData[hid][bName], lock);
		strcat(CMDSString, _tmpstring);
	}
	ShowPlayerDialog(playerid, DIALOG_MY_BISNIS, DIALOG_STYLE_LIST, "Local Prime - Bisnis Saya", CMDSString, "Pilih", "Batal");
	return 1;
}

CMD:bm(playerid, const params[])
{
	if(pData[playerid][pInBiz] == -1) return 0;
	if(!Player_OwnsBisnis(playerid, pData[playerid][pInBiz])) return ErrorMsg(playerid, "Anda bukan pemilik bisnis ini");
    ShowPlayerDialog(playerid, BISNIS_MENU, DIALOG_STYLE_LIST, "Local Prime - Bisnis Menu","Bisnis Info\nGanti Nama\nPendapatan Bisnis\nHarga Product\nRequest Restock","Pilih","Tutup");
    return 1;
}

CMD:givebusiness(playerid, params[])
{
	new bid, otherid;
	if(sscanf(params, "ud", otherid, bid)) return SyntaxMsg(playerid, "/givebisnis [playerid/name] [id] | /mybusiness - for show info");
	if(bid == -1) return Error(playerid, "Invalid id");
	
	if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
        return Error(playerid, "Player tersebut telah disconnect/tidak berada didekat dirimu.");
	
	if(!Player_OwnsBisnis(playerid, bid)) return Error(playerid, "Kamu tidak memiliki Bisnis ini.");
	if(pData[otherid][pVip] == 1)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_BisnisCount(otherid) + 1 > 2) return Error(playerid, "Target Player tidak dapat memiliki bisnis lebih.");
		#endif
	}
	else if(pData[otherid][pVip] == 2)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_BisnisCount(otherid) + 1 > 3) return Error(playerid, "Target Player tidak dapat memiliki bisnis lebih.");
		#endif
	}
	else if(pData[otherid][pVip] == 3)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_BisnisCount(otherid) + 1 > 4) return Error(playerid, "Target Player tidak dapat memiliki bisnis lebih.");
		#endif
	}
	else
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_BisnisCount(otherid) + 1 > 1) return Error(playerid, "Target Player tidak dapat memiliki bisnis lebih.");
		#endif
	}
	GetPlayerName(otherid, bData[bid][bOwner], MAX_PLAYER_NAME);
	bData[bid][bOwnerID] = pData[otherid][pID];
	bData[bid][bVisit] = gettime() + (86400 * 30);
	
	new query[128];
	mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET owner='%s', ownerid='%d', visit='%d' WHERE ID='%d'", bData[bid][bOwner], bData[bid][bOwnerID], bData[bid][bVisit], bid);
	mysql_tquery(g_SQL, query);

	Bisnis_Refresh(bid);
	Info(playerid, "Anda memberikan bisnis id: %d kepada %s", bid, ReturnName(otherid));
	Info(otherid, "%s memberikan bisnis id: %d kepada anda", bid, ReturnName(playerid));
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	//-----[ Bisnis ]-----
	if((newkeys & KEY_YES))
	{
	    foreach(new bid : Bisnis)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.0, bData[bid][bExtposX], bData[bid][bExtposY], bData[bid][bExtposZ]) && strcmp(bData[bid][bOwner], "-"))
			{
				if(bData[bid][bLocked])
					return ErrorMsg(playerid, "Bisnis ini sedang tutup");

				pData[playerid][pInBiz] = bid;
				Bisnis_BuyMenu(playerid, pData[playerid][pInBiz]);
			}
		}
	}
	if((newkeys & KEY_YES ))
	{
		foreach(new id : Bisnis)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ]) && !strcmp(bData[id][bOwner], "-"))
			{
				if(bData[id][bPrice] > pData[playerid][pMoney]) return ErrorMsg(playerid, "Uang anda tidak cukup, anda tidak dapat membeli bisnis ini");
				if(strcmp(bData[id][bOwner], "-")) return ErrorMsg(playerid, "Seseorang sudah memiliki bisnis ini");
				if(pData[playerid][pVip] == 1)
				{
					#if LIMIT_PER_PLAYER > 0
					if(Player_BisnisCount(playerid) + 1 > 2) return ErrorMsg(playerid, "Anda tidak dapat membeli bisnis lagi");
					#endif
				}
				else if(pData[playerid][pVip] == 2)
				{
					#if LIMIT_PER_PLAYER > 0
					if(Player_BisnisCount(playerid) + 1 > 3) return ErrorMsg(playerid, "Anda tidak dapat membeli bisnis lagi");
					#endif
				}
				else if(pData[playerid][pVip] == 3)
				{
					#if LIMIT_PER_PLAYER > 0
					if(Player_BisnisCount(playerid) + 1 > 4) return ErrorMsg(playerid, "Anda tidak dapat membeli bisnis lagi");
					#endif
				}
				else
				{
					#if LIMIT_PER_PLAYER > 0
					if(Player_BisnisCount(playerid) + 1 > 1) return ErrorMsg(playerid, "Anda tidak dapat membeli bisnis lagi");
					#endif
				}
				GivePlayerMoneyEx(playerid, -bData[id][bPrice]);
				GetPlayerName(playerid, bData[id][bOwner], MAX_PLAYER_NAME);
				bData[id][bOwnerID] = pData[playerid][pID];
				bData[id][bVisit] = gettime() + (86400 * 30);
				new str[522], query[500];
				format(str,sizeof(str),"[BIZ]: %s membeli bisnis id %d seharga %s!", GetRPName(playerid), id, FormatMoney(bData[id][bPrice]));
				SuccesMsg(playerid, str);
				mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET owner='%s', ownerid='%d', visit='%d' WHERE ID='%d'", bData[id][bOwner], bData[id][bOwnerID], bData[id][bVisit], id);
				mysql_tquery(g_SQL, query);
				Bisnis_Save(id);
				Bisnis_Refresh(id);
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}
