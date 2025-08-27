Bisnis_Save(id)
{
	new cQuery[2248];
	format(cQuery, sizeof(cQuery), "UPDATE bisnis SET owner='%s', ownerid='%d', name='%s', price='%d', type='%d', locked='%d', money='%d', prod='%d', bprice0='%d', bprice1='%d', bprice2='%d', bprice3='%d', bprice4='%d', bprice5='%d', bprice6='%d', bprice7='%d', bprice8='%d', bprice9='%d', extposx='%f', extposy='%f', extposz='%f', extposa='%f', visit='%d', restock='%d' WHERE ID='%d'",
	bData[id][bOwner],
	bData[id][bOwnerID],
	bData[id][bName],
	bData[id][bPrice],
	bData[id][bType],
	bData[id][bLocked],
	bData[id][bMoney],
	bData[id][bProd],
	bData[id][bP][0],
	bData[id][bP][1],
	bData[id][bP][2],
	bData[id][bP][3],
	bData[id][bP][4],
	bData[id][bP][5],
	bData[id][bP][6],
	bData[id][bP][7],
	bData[id][bP][8],
	bData[id][bP][9],
	bData[id][bExtposX],
	bData[id][bExtposY],
	bData[id][bExtposZ],
	bData[id][bExtposA],
	bData[id][bVisit],
	bData[id][bRestock],
	id
	);
	return mysql_tquery(g_SQL, cQuery);
}
	
Player_OwnsBisnis(playerid, id)
{
	return (bData[id][bOwnerID] == pData[playerid][pID]) || (!strcmp(bData[id][bOwner], pData[playerid][pName], true));
}

Player_BisnisCount(playerid)
{
	#if LIMIT_PER_PLAYER != 0
    new count;
	foreach(new i : Bisnis)
	{
		if(Player_OwnsBisnis(playerid, i)) count++;
	}

	return count;
	#else
	return 0;
	#endif
}

Bisnis_Reset(id)
{
	format(bData[id][bOwner], MAX_PLAYER_NAME, "-");
	format(bData[id][bName], 128, "-");
	bData[id][bOwnerID] = -1;
	bData[id][bLocked] = 1;
    bData[id][bMoney] = 0;
	bData[id][bProd] = 0;
	bData[id][bVisit] = 0;
	bData[id][bRestock] = 0;
	bData[id][bP][0] = 0;
	bData[id][bP][1] = 0;
	bData[id][bP][2] = 0;
	bData[id][bP][3] = 0;
	bData[id][bP][4] = 0;
	bData[id][bP][5] = 0;
	bData[id][bP][6] = 0;
	bData[id][bP][7] = 0;
	bData[id][bP][8] = 0;
	bData[id][bP][9] = 0;
	Bisnis_Refresh(id);
}

GetOwnedBisnis(playerid)
{
	new tmpcount;
	foreach(new bid : Bisnis)
	{
	    if(!strcmp(bData[bid][bOwner], pData[playerid][pName], true) || (bData[bid][bOwnerID] == pData[playerid][pID]))
	    {
     		tmpcount++;
		}
	}
	return tmpcount;
}
ReturnPlayerBisnisID(playerid, hslot)
{
	new tmpcount;
	if(hslot < 1 && hslot > LIMIT_PER_PLAYER) return -1;
	foreach(new bid : Bisnis)
	{
	    if(!strcmp(pData[playerid][pName], bData[bid][bOwner], true) || (bData[bid][bOwnerID] == pData[playerid][pID]))
	    {
     		tmpcount++;
       		if(tmpcount == hslot)
       		{
        		return bid;
  			}
	    }
	}
	return -1;
}

Bisnis_BuyMenu(playerid, bizid)
{

    static
        string[512];

    switch(bData[bizid][bType])
    {
        case 1:
        {
            format(string, sizeof(string), "Produk\tHarga\n{ffffff}Wine\t{7fff00}%s\n{ffffff}Whiskey\t{7fff00}%s\n{ffffff}Vodka\t{7fff00}%s\n{ffffff}Blue Moon\t{7fff00}%s",
                FormatMoney(bData[bizid][bP][0]),
                FormatMoney(bData[bizid][bP][1]),
                FormatMoney(bData[bizid][bP][2]),
                FormatMoney(bData[bizid][bP][3])
            );
            ShowPlayerDialog(playerid, BISNIS_BUYPROD, DIALOG_STYLE_TABLIST_HEADERS, bData[bizid][bName], string, "Buy", "Cancel");
        }
        case 2:
        {
            format(string, sizeof(string), "Produk\tHarga\n{ffffff}Snack\t{7fff00}%s\n{ffffff}Sprunk\t{7fff00}%s\n{ffffff}Jerry can\t{7fff00}%s\n{ffffff}Rokok\t{7fff00}%s\n{ffffff}Air Mineral\t{7fff00}%s\n",
                FormatMoney(bData[bizid][bP][0]),
                FormatMoney(bData[bizid][bP][1]),
                FormatMoney(bData[bizid][bP][2]),
                FormatMoney(bData[bizid][bP][3]),
				FormatMoney(bData[bizid][bP][4]),
				FormatMoney(bData[bizid][bP][5])
            );
            ShowPlayerDialog(playerid, BISNIS_BUYPROD, DIALOG_STYLE_TABLIST_HEADERS, bData[bizid][bName], string, "Buy", "Cancel");
        }
        case 3:
        {
            for(new xx = 0; xx < 6; xx++)
			{
				TextDrawShowForPlayer(playerid, ListBaju[xx]);
			}
			SelectTextDraw(playerid, COLOR_YELLOW);
        }
        case 4:
        {
            format(string, sizeof(string), "Alat\tHarga\n{ffffff}Skateboard\t{7fff00}%s\n{ffffff}Knife\t{7fff00}%s\n{ffffff}Baseball Bat\t{7fff00}%s\n{ffffff}Shovel\t{7fff00}%s\n{ffffff}Chainsaw\t{7fff00}%s\n{ffffff}Cane\t{7fff00}%s\n{ffffff}Fishing Tool\t{7fff00}%s\n{ffffff}Worm\t{7fff00}%s\n{FFFFFF}Mask\t{7fff00}%s",
                FormatMoney(bData[bizid][bP][0]),
                FormatMoney(bData[bizid][bP][1]),
                FormatMoney(bData[bizid][bP][2]),
                FormatMoney(bData[bizid][bP][3]),
				FormatMoney(bData[bizid][bP][4]),
				FormatMoney(bData[bizid][bP][5]),
				FormatMoney(bData[bizid][bP][6]),
				FormatMoney(bData[bizid][bP][7]),
				FormatMoney(bData[bizid][bP][8])
            );
            ShowPlayerDialog(playerid, BISNIS_BUYPROD, DIALOG_STYLE_TABLIST_HEADERS, bData[bizid][bName], string, "Buy", "Cancel");
        }
		case 5:
        {
            format(string, sizeof(string), "Produk\tHarga\n{ffffff}Iphone 20 Pro\t{7fff00}%s\n{ffffff}Ganti Nomor Ponsel\t{7fff00}%s\n{ffffff}Phone Credit\t{7fff00}%s\n{ffffff}Phone Book\t{7fff00}%s\n{ffffff}Portable Radio\t{7fff00}%s\n{ffffff}Kuota 10gb\t{7fff00}%s\n{ffffff}Boombox\t{7fff00}%s\n",
                FormatMoney(bData[bizid][bP][0]),
                FormatMoney(bData[bizid][bP][1]),
                FormatMoney(bData[bizid][bP][2]),
                FormatMoney(bData[bizid][bP][3]),
				FormatMoney(bData[bizid][bP][4]),
				FormatMoney(bData[bizid][bP][5]),
				FormatMoney(bData[bizid][bP][6])
            );
            ShowPlayerDialog(playerid, BISNIS_BUYPROD, DIALOG_STYLE_TABLIST_HEADERS, bData[bizid][bName], string, "Buy", "Cancel");
        }
    }
    return 1;
}

Bisnis_ProductMenu(playerid, bizid)
{
    if(bizid <= -1)
        return 0;

    static
        string[512];

    switch (bData[bizid][bType])
    {
        case 1:
        {
            format(string, sizeof(string), "Produk\tHarga\n{ffffff}Wine\t{7fff00}%s\n{ffffff}Whiskey\t{7fff00}%s\n{ffffff}Vodka\t{7fff00}%s\n{ffffff}Blue Moon\t{7fff00}%s",
                FormatMoney(bData[bizid][bP][0]),
                FormatMoney(bData[bizid][bP][1]),
                FormatMoney(bData[bizid][bP][2]),
                FormatMoney(bData[bizid][bP][3])
            );
            ShowPlayerDialog(playerid, BISNIS_EDITPROD, DIALOG_STYLE_TABLIST_HEADERS, "Business: Modify Item", string, "Modify", "Cancel");
        }
        case 2:
        {
            format(string, sizeof(string), "Produk\tHarga\n{ffffff}Snack\t{7fff00}%s\n{ffffff}Sprunk\t{7fff00}%s\n{ffffff}Jerry Can\t{7fff00}%s\n{ffffff}Rokok\t{7fff00}%s\n{ffffff}Air Mineral\t{7fff00}%s",
                FormatMoney(bData[bizid][bP][0]),
                FormatMoney(bData[bizid][bP][1]),
                FormatMoney(bData[bizid][bP][2]),
                FormatMoney(bData[bizid][bP][3]),
				FormatMoney(bData[bizid][bP][4]),
				FormatMoney(bData[bizid][bP][5])
            );
            ShowPlayerDialog(playerid, BISNIS_EDITPROD,DIALOG_STYLE_TABLIST_HEADERS, "Business - Harga Barang", string, "Ubah", "Batal");
        }
        case 3:
        {
            format(string, sizeof(string), "Aksesoris\tHarga\n{ffffff}Clothes\t{7fff00}%s\n{ffffff}Toys\t{7fff00}%s\n{ffffff}Mask\t{7fff00}%s\n{ffffff}Helmet\t{7fff00}%s",
                FormatMoney(bData[bizid][bP][0]),
                FormatMoney(bData[bizid][bP][1]),
                FormatMoney(bData[bizid][bP][2]),
                FormatMoney(bData[bizid][bP][3])
            );
            ShowPlayerDialog(playerid, BISNIS_EDITPROD,DIALOG_STYLE_TABLIST_HEADERS, "Business: Modify Item", string, "Modify", "Cancel");
        }
        case 4:
        {
            format(string, sizeof(string), "Alat\tHarga\n{ffffff}Skateboard\t{7fff00}%s\n{ffffff}Knife\t{7fff00}%s\n{ffffff}Baseball Bat\t{7fff00}%s\n{ffffff}Shovel\t{7fff00}%s\n{ffffff}Chainsaw\t{7fff00}%s\n{ffffff}Cane\t{7fff00}%s\n{ffffff}Fishing Tool\t{7fff00}%s\n{ffffff}Worm\t{7fff00}%s\n{FFFFFF}Mask\t{7fff00}%s",
                FormatMoney(bData[bizid][bP][0]),
                FormatMoney(bData[bizid][bP][1]),
                FormatMoney(bData[bizid][bP][2]),
                FormatMoney(bData[bizid][bP][3]),
				FormatMoney(bData[bizid][bP][4]),
				FormatMoney(bData[bizid][bP][5]),
				FormatMoney(bData[bizid][bP][6]),
				FormatMoney(bData[bizid][bP][7]),
				FormatMoney(bData[bizid][bP][8])
            );
            ShowPlayerDialog(playerid, BISNIS_EDITPROD,DIALOG_STYLE_TABLIST_HEADERS, "Business: Modify Item", string, "Modify", "Cancel");
        }
		case 5:
        {
            format(string, sizeof(string), "Produk\tHarga\n{ffffff}Iphone 20 Pro\t{7fff00}%s\n{ffffff}Ganti Nomor Ponsel\t{7fff00}%s\n{ffffff}Phone Credit\t{7fff00}%s\n{ffffff}Phone Book\t{7fff00}%s\n{ffffff}Portable Radio\t{7fff00}%s\n{ffffff}Kuota 10gb\t{7fff00}%s\n{ffffff}Boombox\t{7fff00}%s",
                FormatMoney(bData[bizid][bP][0]),
                FormatMoney(bData[bizid][bP][1]),
                FormatMoney(bData[bizid][bP][2]),
                FormatMoney(bData[bizid][bP][3]),
				FormatMoney(bData[bizid][bP][4]),
				FormatMoney(bData[bizid][bP][5]),
				FormatMoney(bData[bizid][bP][6])
            );
            ShowPlayerDialog(playerid, BISNIS_EDITPROD,DIALOG_STYLE_TABLIST_HEADERS, "Business: Modify Item", string, "Modify", "Cancel");
        }
    }
    return 1;
}

Bisnis_Refresh(id)
{
    if(id != -1)
    {
        if(IsValidDynamic3DTextLabel(bData[id][bLabel]))
            DestroyDynamic3DTextLabel(bData[id][bLabel]);
			
		if(IsValidDynamicMapIcon(bData[id][bMap]))
			DestroyDynamicMapIcon(bData[id][bMap]);

        static tstr[128];
		
		new type[128];
		if(bData[id][bType] == 1)
		{
			type= "Clubhouse";
		}
		else if(bData[id][bType] == 2)
		{
			type= "Market";
		}
		else if(bData[id][bType] == 3)
		{
			type= "Clothes";
		}
		else if(bData[id][bType] == 4)
		{
			type= "Equipment";
		}
		else if(bData[id][bType] == 5)
		{
			type= "Electronics";
		}
		else
		{
			type= "Unknown";
		}
        if(strcmp(bData[id][bOwner], "-") || bData[id][bOwnerID] != 0)
		{
			//format(tstr, 128, "{FFFFFF}ID: %d\nOwner: {FFFF00}%s\nNama Bisnis: %s\nPress "LG_E"'Y' {FFFFFF}Untuk Membeli", id, bData[id][bOwner], bData[id][bName]);
        	format(tstr, sizeof(tstr), "{FFFFFF}ID: %d\nPemilik: %s\nNama: %s\n{FFFF00}[Y] {FFFFFF}to buy", id, bData[id][bOwner], bData[id][bName]);
        }
        else
        {
			format(tstr, sizeof(tstr), "{FFFFFF}ID: %d\nBisnis ini di jual\nHarga: {00FF00}%s\n{FFFFFF}Type: {FFFF00}%s\n{FFFF00}[Y] {FFFFFF}untuk membeli bisnis", id, FormatMoney(bData[id][bPrice]), type);
		}
		bData[id][bLabel] = CreateDynamic3DTextLabel(tstr, -1, bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0);
		
		if(bData[id][bType] == 1)
		{
			bData[id][bMap] = CreateDynamicMapIcon(bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ], 50, -1, -1, -1, -1, 700.0);
		}
		else if(bData[id][bType] == 2)
		{
			bData[id][bMap] = CreateDynamicMapIcon(bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ], 17, -1, -1, -1, -1, 700.0);
		}
		else if(bData[id][bType] == 3)
		{
			bData[id][bMap] = CreateDynamicMapIcon(bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ], 45, -1, -1, -1, -1, 700.0);
		}
		else if(bData[id][bType] == 4)
		{
			bData[id][bMap] = CreateDynamicMapIcon(bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ], 25, -1, -1, -1, -1, 700.0);
		}
		else if(bData[id][bType] == 5)
		{
			bData[id][bMap] = CreateDynamicMapIcon(bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ], 48, -1, -1, -1, -1, 700.0);
		}
		else
		{
			DestroyDynamicMapIcon(bData[id][bMap]);
		}
    }
    return 1;
}

GetAnyBusiness()
{
	new tmpcount;
	foreach(new id : Bisnis)
	{
     	tmpcount++;
	}
	return tmpcount;
}

ReturnBusinessID(slot)
{
	new tmpcount;
	if(slot < 1 && slot > MAX_BISNIS) return -1;
	foreach(new id : Bisnis)
	{
        tmpcount++;
        if(tmpcount == slot)
        {
            return id;
        }
	}
	return -1;
}