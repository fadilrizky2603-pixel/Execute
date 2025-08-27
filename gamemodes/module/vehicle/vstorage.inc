

enum e_BagasiItems
{
	e_InventoryItem[32],
	e_InventoryModel,
	Float: e_InventoryWeight
};

new const g_aBagasiItems[][e_BagasiItems] =
{
	{"Phone", 18866, 0.300},
	{"Money", 1212, 0.000},
	{"Medkit", 1580, 0.300},
	{"Portable Radio", 18868, 0.200},
	{"Mask", 19036, 0.700},
	{"Snack", 2768, 0.200},
	{"Red Money", 1212, 0.100},
	{"Water", 2958, 0.100},
	{"Sprunk", 2958, 0.100},
	{"Jus Jeruk", 19563, 0.150},
	{"Weed", 1578, 0.200},
	{"Component", 19627, 0.100},
	{"Material", 17051, 0.100},
	{"Repair Kit", 920, 0.100},
	{"Wheat", 2247, 0.100},
	{"Orange", 19574, 0.100},
	{"Food", 19568, 0.100},
	{"Potato", 19577, 0.100},
	{"Fuel Can", 1650, 1.000},
	{"Fish Rod", 18632, 0.300},
	{"Bait", 19566, 0.100},
	{"Pizza Stack", 19580, 0.100},
	{"Fried rice", 2221, 0.100},
	{"Rokok", 19897, 0.100},
	{"Wine", 1486, 0.300},
	{"Whiskey", 19824, 0.300},
	{"Vodka", 1544, 0.300},
	{"Blue Moon", 1517, 0.300},
	{"Skateboard", 19878, 1.000},
	{"Boombox", 2226, 0.100},
	{"Medicine", 1575, 0.100},
	{"Marijuana", 1578, 0.100},
	{"Kanabis", 19473, 0.100},
	{"Test Drug", 1579, 0.100},
	{"Cocaine", 1575, 0.100},
	{"Muriatic", 1580, 0.100},
	{"Ephedrine", 1580, 0.100},
	{"Meth", 1580, 0.100},
	{"Daging", 2805, 1.000},
	{"Susu", 19570, 0.500},
	{"Susu Olah", 19570, 0.300},
	{"Ikan", 19630, 1.000},
	{"Ayam Hidup", 16776, 1.000},
	{"Ayam Potong", 2804, 0.400},
	{"Ayam Packing", 2770, 1.000},
	{"Kayu Kemas", 1271, 1.000},
	{"Steak", 19882, 0.300},
	{"Milk", 19570, 0.100},
	{"Roti", 19579, 0.100},
	{"Bandage", 11747, 0.300},
	{"Emas", 19941, 0.700},
	{"Tembaga", 3929, 0.800},
	{"Berlian", 1559, 0.700},
	{"Besi", 19845, 0.900},
	{"Batu", 3930, 0.400},
	{"Kevlar", 1242, 1.000},
	{"Batu Cucian", 2936, 0.500},
	{"Benang", 1901, 0.100},
	{"Kain", 19873, 0.100},
	{"Pakaian", 2705, 0.300},
	{"Sampah", 2840, 0.100},
	{"Note", 2684, 0.100},

	{"Linggis", 18634, 0.700},
	{"Kunci T", 18634, 0.700},
	{"Clip Pistol", 19995, 0.800},
	{"Clip Rifle", 19995, 0.800},
	{"Clip Sg", 19995, 0.800},
	{"Clip Smg", 19995, 0.800},

	{"Bomb", 363, 0.300}
};


stock Car_GetFreeID(carid)
{
	if (carid == -1)
	    return 0;

	for (new i = 0; i < MAX_CAR_STORAGE; i ++)
	{
	    if (!CarStorage[carid][i][cItemExists])
	        return i;
	}
	return -1;
}

stock Car_AddItem(carid, item[], model, quantity = 1, slotid = -1)
{
    if (carid == -1 )
	    return 0;

	new
		itemid = Car_GetItemID(carid, item),
		string[128];

    if(pData[carid][pBeratBagasi] >= 50) {Error(carid, "Bagasi anda sudah penuh!"); return -2;}

	if (itemid == -1)
	{
	    itemid = Car_GetFreeID(carid);

	    if (itemid != -1)
	    {
	        if (slotid != -1)
	            itemid = slotid;

            new Float:BeratBagasi;
            for (new i = 0; i < sizeof(g_aBagasiItems); i ++) if(!strcmp(g_aBagasiItems[i][e_InventoryItem], item, true))
            {
                BeratBagasi = float(quantity)*g_aBagasiItems[i][e_InventoryWeight];
            }
            if(pData[carid][pBeratBagasi]+BeratBagasi >= 50) {Error(carid, "Bagasi anda sudah penuh!", 3); return 1;}
            pData[carid][pBeratBagasi] += BeratBagasi;
	        CarStorage[carid][itemid][cItemExists] = true;
	        CarStorage[carid][itemid][cItemModel] = model;
	        CarStorage[carid][itemid][cItemQuantity] = quantity;

	        strpack(CarStorage[carid][itemid][cItemName], item, 32 char);

			format(string, sizeof(string), "INSERT INTO `carstorage` (`ID`, `itemName`, `itemModel`, `itemQuantity`) VALUES('%d', '%s', '%d', '%d')",pvData[carid][cID], item, model, quantity);
			mysql_tquery(g_SQL, string, "OnCarStorageAdd", "dd", carid, itemid);

	        return itemid;
		}
		return -1;
	}
	else
	{
	    format(string, sizeof(string), "UPDATE `carstorage` SET `itemQuantity` = `itemQuantity` + %d WHERE `ID` = '%d' AND `itemID` = '%d'", quantity,pvData[carid][cID], CarStorage[carid][itemid][cItemID]);
	    mysql_tquery(g_SQL, string);

	    CarStorage[carid][itemid][cItemQuantity] += quantity;
		for (new i = 0; i < sizeof(g_aBagasiItems); i ++) if(!strcmp(g_aBagasiItems[i][e_InventoryItem], item, true))
        {
            pData[carid][pBeratBagasi] += quantity*g_aBagasiItems[i][e_InventoryWeight];
        }
	}
	return itemid;
}

stock Car_GetItemID(carid, const item[])
{
	if (carid == -1 )
	    return 0;

	for (new i = 0; i < MAX_CAR_STORAGE; i ++)
	{
	    if (!CarStorage[carid][i][cItemExists])
	        continue;

		if (!strcmp(CarStorage[carid][i][cItemName], item)) return i;
	}
	return -1;
}
	
stock Car_RemoveItem(carid, const item[], quantity = 1)
{
    if (carid == -1 )
	    return 0;

	new
		itemid = Car_GetItemID(carid, item),
		string[128];

    if(pData[carid][pWeight] >= 50) return Error(carid, "Inventory anda sudah penuh!", 3);

	if (itemid != -1)
	{
		for (new i = 0; i < sizeof(g_aBagasiItems); i ++) if(!strcmp(g_aBagasiItems[i][e_InventoryItem], item, true))
		{
			pData[carid][pBeratBagasi] -= quantity*g_aBagasiItems[i][e_InventoryWeight];
			if(pData[carid][pBeratBagasi] <= 0.0) pData[carid][pBeratBagasi] = 0.0;
		}
	    if (CarStorage[carid][itemid][cItemQuantity] > 0)
	    {
	        CarStorage[carid][itemid][cItemQuantity] -= quantity;
		}
		if (quantity == -1 || CarStorage[carid][itemid][cItemQuantity] < 1)
		{
		    CarStorage[carid][itemid][cItemExists] = false;
		    CarStorage[carid][itemid][cItemModel] = 0;
		    CarStorage[carid][itemid][cItemQuantity] = 0;

		    format(string, sizeof(string), "DELETE FROM `carstorage` WHERE `ID` = '%d' AND `itemID` = '%d'",pvData[carid][cID], CarStorage[carid][itemid][cItemID]);
	        mysql_tquery(g_SQL, string);
		}
		else if (quantity != -1 && CarStorage[carid][itemid][cItemQuantity] > 0)
		{
			format(string, sizeof(string), "UPDATE `carstorage` SET `itemQuantity` = `itemQuantity` - %d WHERE `ID` = '%d' AND `itemID` = '%d'", quantity,pvData[carid][cID], CarStorage[carid][itemid][cItemID]);
            mysql_tquery(g_SQL, string);
		}
		return 1;
	}
	return 0;
}

function OnLoadCarStorage(carid)
{
	new name[128];
	new count = cache_num_rows();
	if(count > 0)
	{
	    for(new i = 0; i < count; i++)
	    {
			CarStorage[carid][i][cItemExists] = true;
			cache_get_value_name_int(i, "itemID", CarStorage[carid][i][cItemID]);
			cache_get_value_name_int(i, "itemModel", CarStorage[carid][i][cItemModel]);
			cache_get_value_name_int(i, "itemQuantity", CarStorage[carid][i][cItemQuantity]);

			cache_get_value_name(i, "itemName", name);
			strpack(CarStorage[carid][i][cItemName], name, 32 char);
			for (new id = 0; id < sizeof(g_aBagasiItems); id ++) if(!strcmp(g_aBagasiItems[id][e_InventoryItem], CarStorage[carid][i][cItemName], true))
			{
				pData[carid][pBeratBagasi] += float(CarStorage[carid][i][cItemQuantity])*g_aBagasiItems[id][e_InventoryWeight];
			}	
		}
	}
	return 1;
}
Car_ShowTrunk(playerid, carid)
{
	static
	    string[MAX_CAR_STORAGE * 32],
		name[32];

	string[0] = 0;

	for (new i = 0; i != MAX_CAR_STORAGE; i ++)
	{
	    if (!CarStorage[carid][i][cItemExists])
	        format(string, sizeof(string), "%sEmpty Slot\n", string);
		else {
			strunpack(name, CarStorage[carid][i][cItemName]);

			if (CarStorage[carid][i][cItemQuantity] == 1) {
                format(string, sizeof(string), "%s%s\n", string, name);
			}
			else format(string, sizeof(string), "%s%s (%d)\n", string, name, CarStorage[carid][i][cItemQuantity]);
		}
	}
	pData[playerid][pStorageSelect] = 0;
	ShowPlayerDialog(playerid, DIALOG_TRUNK, DIALOG_STYLE_LIST, sprintf("Vehicle Storage %.3f/50.00", pData[carid][pBeratBagasi]), string, "Select", "Cancel");
	return 1;
}