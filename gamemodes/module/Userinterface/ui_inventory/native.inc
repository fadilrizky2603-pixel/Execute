Inventory_GetInventoryID(playerid, const string:item[])
{
	for (new i = 0; i < MAX_INVENTORY; i ++)
	{
		if (!InventoryData[playerid][i][invExists])
			continue;

		if (!strcmp(InventoryData[playerid][i][invItem], item)) return InventoryData[playerid][i][invID];
	}
	return -1;
}

Inventory_GetItemID(playerid, const string:item[])
{
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
	    if (!InventoryData[playerid][i][invExists])
	        continue;

		if (!strcmp(InventoryData[playerid][i][invItem], item)) return i;
	}
	return -1;
}

Inventory_GetModel(const string:item[])
{
	for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
	{
		return g_aInventoryItems[i][e_InventoryModel];
	}
	return -1;
}

Inventory_GetFreeID(playerid)
{
	if (Inventory_Items(playerid) >= 20)
		return -1;

	for (new i = 0; i < MAX_INVENTORY; i ++)
	{
		if (!InventoryData[playerid][i][invExists])
			return i;
	}
	return -1;
}

Inventory_Items(playerid)
{
	new count;

	for (new i = 0; i != MAX_INVENTORY; i ++) if (InventoryData[playerid][i][invExists]) {
		count++;
	}
	return count;
}

Inventory_Count(playerid, const string:item[])
{
	new itemid = Inventory_GetItemID(playerid, item);

	if (itemid != -1)
		return InventoryData[playerid][itemid][invQuantity];

	return 0;
}

Inventory_HasItem(playerid, const string:item[])
{
	return (Inventory_GetItemID(playerid, item) != -1);
}

Inventory_Set(playerid, const item[], model, amount)
{
    new itemid = Inventory_GetItemID(playerid, item);

    if(amount > 0)
        Inventory_Add(playerid, item, model, amount);

    else if (amount > 0 && itemid != -1)
	    Inventory_SetQuantity(playerid, item, amount);

    else if(amount < 1 && itemid != -1)
        Inventory_Remove(playerid, item, InventoryData[playerid][itemid][invQuantity]);

    return 1;
}

Inventory_SetQuantity(playerid, const string: item[], quantity)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[128];

	if (itemid != -1)
	{
		format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, pData[playerid][pID], InventoryData[playerid][itemid][invID]);
		mysql_tquery(g_SQL, string);

		InventoryData[playerid][itemid][invQuantity] = quantity;
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
		{
			new Float:Weight = float(quantity)*g_aInventoryItems[i][e_InventoryWeight];
			pData[playerid][pWeight] += Weight;
		}
		if(InventoryOpen[playerid])
		{
			UpdateInventoryTD(playerid);
			Inventory_BarUpdate(playerid);
		}
	}
	return 1;
}

Inventory_Add(playerid, const item[], model, quantity = 1, weapon = 0, ammo = 0)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[318],
		value_str[218];

	if(pData[playerid][pWeight] >= 1000.00) return ErrorMsg(playerid, "Inventory anda sudah penuh");
	if (itemid == -1)
	{
		itemid = Inventory_GetFreeID(playerid);

		if (itemid != -1)
		{
			new Float:Weights;
			for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
			{
				Weights = float(quantity)*g_aInventoryItems[i][e_InventoryWeight];
			}
			if(pData[playerid][pWeight]+Weights >= 1000.00) return ErrorMsg(playerid, "Inventory anda sudah penuh");
			pData[playerid][pWeight] += Weights;
			InventoryData[playerid][itemid][invExists] = true;
			InventoryData[playerid][itemid][invModel] = model;
			InventoryData[playerid][itemid][invQuantity] = quantity;
			InventoryData[playerid][itemid][invAmmo] = ammo;
			InventoryData[playerid][itemid][invSlot] = itemid;


			format(InventoryData[playerid][itemid][invItem], 64, "%s", item);
			format(string, sizeof(string), "INSERT INTO `inventory` (`ID`, `invItem`, `invModel`, `invQuantity`, `invSlot`, `invWeapon`, `invAmmo`) VALUES('%d', '%s', '%d', '%d', '%d', '%d', '%d')", pData[playerid][pID], item, model, quantity, itemid, weapon, ammo);
			mysql_tquery(g_SQL, string, "OnInventoryAdd", "dd", playerid, itemid);
			ShowItemBox(playerid, item, sprintf("RECEIVED_%dx", quantity), model, 4);

			if (IsValidDynamicPlayerTextDraw(playerid, PlayerText:itemname[playerid][itemid]))
			{
				PlayerTextDrawSetString(playerid, itemname[playerid][itemid], InventoryData[playerid][itemid][invItem]);
				PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][itemid], model);
			}
			if(InventoryOpen[playerid])
			{
				format(value_str, sizeof(value_str), "%d", InventoryData[playerid][itemid][invQuantity]);
				PlayerTextDrawSetString(playerid, itemamountname[playerid][itemid], value_str);
				PlayerTextDrawShow(playerid, modelinv[playerid][itemid]);
				UpdateInventoryTD(playerid);
				Inventory_BarUpdate(playerid);
			}
			return itemid;
		}
		return -1;
	}
	else
	{
		format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` + %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, pData[playerid][pID], InventoryData[playerid][itemid][invID]);
		mysql_tquery(g_SQL, string);
		ShowItemBox(playerid, item, sprintf("RECEIVED_%dx", quantity), model, 4);

		InventoryData[playerid][itemid][invQuantity] += quantity;
		format(value_str, sizeof(value_str), "%d", InventoryData[playerid][itemid][invQuantity]);
		if(IsValidDynamicPlayerTextDraw(playerid, itemamountname[playerid][itemid])) {
			PlayerTextDrawSetString(playerid, itemamountname[playerid][itemid], value_str);
		}
		if(IsValidDynamicPlayerTextDraw(playerid, modelinv[playerid][itemid])) {
			PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][itemid], model);
		}
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
		{
			pData[playerid][pWeight] += quantity*g_aInventoryItems[i][e_InventoryWeight];
		}
		if(InventoryOpen[playerid])
		{
			UpdateInventoryTD(playerid);
			Inventory_BarUpdate(playerid);
		}
	}
	return itemid;
}

Inventory_Remove(playerid, const item[], quantity = 1)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		invid = Inventory_GetInventoryID(playerid, item),
		model = Inventory_GetModel(item),
		string[128];

	if(pData[playerid][pBeratBagasi] >= 50) return ErrorMsg(playerid, "Bagasi anda sudah penuh!");

	if (itemid != -1)
	{
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
		{
			pData[playerid][pWeight] -= quantity*g_aInventoryItems[i][e_InventoryWeight];
			if(pData[playerid][pWeight] <= 0.0) pData[playerid][pWeight] = 0.0;
		}
		if (InventoryData[playerid][itemid][invQuantity] > 0)
		{
			InventoryData[playerid][itemid][invQuantity] -= quantity;
		}
		ShowItemBox(playerid, item, sprintf("REMOVED_%dx", quantity), model, 4);
		if (quantity == -1 || InventoryData[playerid][itemid][invQuantity] < 1)
		{
			InventoryData[playerid][itemid][invExists] = false;
			InventoryData[playerid][itemid][invModel] = 19300;
			InventoryData[playerid][itemid][invQuantity] = 0;
			InventoryData[playerid][itemid][invAmmo] = 0;
			InventoryData[playerid][itemid][invSlot] = -1;

			format(string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d' AND `invID` = '%d'", pData[playerid][pID], invid);
			mysql_tquery(g_SQL, string);
			if(InventoryOpen[playerid])
			{
				PlayerTextDrawHide(playerid, itemname[playerid][itemid]);
    	        PlayerTextDrawHide(playerid, itemamountname[playerid][itemid]);
				UpdateInventoryTD(playerid);
				Inventory_BarUpdate(playerid);
			}
		}
		else if (quantity != -1 && InventoryData[playerid][itemid][invQuantity] > 0)
		{
			format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` - %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, pData[playerid][pID], InventoryData[playerid][itemid][invID]);
			mysql_tquery(g_SQL, string);
			if(InventoryOpen[playerid])
			{
				UpdateInventoryTD(playerid);
				Inventory_BarUpdate(playerid);
			}
		}
		return 1;
	}
	return 0;
}

Inventory_BarUpdate(playerid)
{
    new str[256], totalall;
    for(new a = 0; a < 27; a++)
	{
		PlayerTextDrawHide(playerid, txd_inventory[playerid][a]);
	}
    for(new i = 0; i < MAX_INVENTORY; i++)
	{
        totalall += floatround(pData[playerid][pWeight]);
        if(totalall < 0) totalall = 0, pData[playerid][pWeight] = 0;
        format(str, sizeof(str), "%.2f/1000.0", float(totalall));
        PlayerTextDrawSetString(playerid, txd_inventory[playerid][3], str);
    }
}

DropItem(const item[], playerid, model, quantity, Float:x, Float:y, Float:z, interior, world, weaponid = 0, ammo = 0)
{
	new
		query[300];
	for (new i = 0; i != MAX_DROPPED_ITEMS; i ++) if (!DroppedItems[i][droppedModel])
	{
		format(DroppedItems[i][droppedItem], 32, item);
		if(playerid == INVALID_PLAYER_ID) format(DroppedItems[i][droppedPlayer], 24, "Admin");
		else format(DroppedItems[i][droppedPlayer], 24, pData[playerid][pName]);

		DroppedItems[i][droppedModel] = model;
		DroppedItems[i][droppedQuantity] = quantity;
		DroppedItems[i][droppedWeapon] = weaponid;
		DroppedItems[i][droppedAmmo] = ammo;
		DroppedItems[i][droppedPos][0] = x;
		DroppedItems[i][droppedPos][1] = y;
		DroppedItems[i][droppedPos][2] = z;
		DroppedItems[i][droppedTime] = gettime();

		DroppedItems[i][droppedInt] = interior;
		DroppedItems[i][droppedWorld] = world;
		Inventory_Remove(playerid, item, quantity);

		if (IsWeaponModel(model)) {
			DroppedItems[i][droppedObject] = CreateDynamicObject(model, x, y, z, 93.7, 120.0, 120.0, world, interior);
		} else {
			DroppedItems[i][droppedObject] = CreateDynamicObject(model, x, y, z, 0.0, 0.0, 0.0, world, interior);
		}
		DroppedItems[i][droppedText3D] = CreateDynamic3DTextLabel(sprintf("{FFFF00}/pickup\n{FFFFFF}%s", item), 0xB0E2FFAA, x, y, z, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, world, interior);

		if (strcmp(item, "Demo Soda") != 0)
		{
			format(query, sizeof(query), "INSERT INTO `dropped` (`itemName`, `itemPlayer`, `itemModel`, `itemQuantity`, `itemWeapon`, `itemAmmo`, `itemX`, `itemY`, `itemZ`, `itemInt`, `itemWorld`, `itemTime`) VALUES('%s', '%s', '%d', '%d', '%d', '%d', '%.4f', '%.4f', '%.4f', '%d', '%d', '%d')", item, DroppedItems[i][droppedPlayer], model, quantity, weaponid, ammo, x, y, z, interior, world, gettime());
			mysql_tquery(g_SQL, query, "OnDroppedItem", "d", i);
		}
		return i;
	}
	return -1;
}

Item_Nearest(playerid)
{
	for (new i = 0; i != MAX_DROPPED_ITEMS; i ++) if (DroppedItems[i][droppedModel] && IsPlayerInRangeOfPoint(playerid, 1.5, DroppedItems[i][droppedPos][0], DroppedItems[i][droppedPos][1], DroppedItems[i][droppedPos][2]))
	{
		if (GetPlayerInterior(playerid) == DroppedItems[i][droppedInt] && GetPlayerVirtualWorld(playerid) == DroppedItems[i][droppedWorld])
			return i;
	}
	return -1;
}

Item_SetQuantity(itemid, amount)
{
	new
		string[64];

	if (itemid != -1 && DroppedItems[itemid][droppedModel])
	{
		DroppedItems[itemid][droppedQuantity] = amount;

		format(string, sizeof(string), "UPDATE `dropped` SET `itemQuantity` = %d WHERE `ID` = '%d'", amount, DroppedItems[itemid][droppedID]);
		mysql_tquery(g_SQL, string);
	}
	return 1;
}

Item_Delete(itemid)
{
	static
		query[64];

	if (itemid != -1 && DroppedItems[itemid][droppedModel])
	{
		DroppedItems[itemid][droppedModel] = 0;
		DroppedItems[itemid][droppedQuantity] = 0;
		DroppedItems[itemid][droppedPos][0] = 0.0;
		DroppedItems[itemid][droppedPos][1] = 0.0;
		DroppedItems[itemid][droppedPos][2] = 0.0;
		DroppedItems[itemid][droppedInt] = 0;
		DroppedItems[itemid][droppedWorld] = 0;
		DroppedItems[itemid][droppedTime] = 0;

		DestroyDynamicObject(DroppedItems[itemid][droppedObject]);
		DestroyDynamic3DTextLabel(DroppedItems[itemid][droppedText3D]);

		format(query, sizeof(query), "DELETE FROM `dropped` WHERE `ID` = '%d'", DroppedItems[itemid][droppedID]);
		mysql_tquery(g_SQL, query);
	}
	return 1;
}

PickupItem(playerid, itemid)
{
	if (itemid != -1 && DroppedItems[itemid][droppedModel])
	{
		new Float:Weight;
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], DroppedItems[itemid][droppedItem], true))
		{
			Weight = float(DroppedItems[itemid][droppedQuantity])*g_aInventoryItems[i][e_InventoryWeight];
		}
		if(pData[playerid][pWeight]+Weight >= 1000.00) return ErrorMsg(playerid, "Inventory anda sudah penuh");
		if(DroppedItems[itemid][droppedWeapon] != 0)
		{
			new id = Inventory_Add(playerid, DroppedItems[itemid][droppedItem], DroppedItems[itemid][droppedModel], DroppedItems[itemid][droppedQuantity], DroppedItems[itemid][droppedWeapon], DroppedItems[itemid][droppedAmmo]);
			ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,0,0,0,0,0);
			if (id == -1)
				return ErrorMsg(playerid, "Slot inventory anda sudah penuh");

			if(id == -2)
			    return 1;
			GivePlayerWeapon(playerid, DroppedItems[itemid][droppedWeapon], DroppedItems[itemid][droppedAmmo]);
			Item_Delete(itemid);
			return 1;
		}
		new id = Inventory_Add(playerid, DroppedItems[itemid][droppedItem], DroppedItems[itemid][droppedModel], DroppedItems[itemid][droppedQuantity]);
		ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,0,0,0,0,0);
		if (id == -1)
			return ErrorMsg(playerid, "Slot inventory anda sudah penuh");

		if(id == -2)
			return 1;
		Item_Delete(itemid);
	}
	return 1;
}

UpdateInventoryTD(playerid)
{
    new str[256], string[256];
	format(str,1000,"%s", GetRPName(playerid));
	PlayerTextDrawSetString(playerid, txd_inventory[playerid][4], str);
	for(new a = 0; a < 23; a++)
	{
		PlayerTextDrawShow(playerid, txd_inventory[playerid][a]);
	}
	for(new a = 0; a < MAX_INVENTORY; a++)
	{
	    PlayerTextDrawShow(playerid, indexinv[playerid][a]);
	}
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
		//totalall += InventoryData[playerid][i][invQuantity];
		format(str, sizeof(str), "%.2f/1000.0", pData[playerid][pWeight]);
		PlayerTextDrawSetString(playerid, txd_inventory[playerid][3], str);
		if(InventoryData[playerid][i][invExists])
		{
			PlayerTextDrawShow(playerid, itemname[playerid][i]);
			PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][i], InventoryData[playerid][i][invModel]);
			PlayerTextDrawShow(playerid, modelinv[playerid][i]);
			strunpack(string, InventoryData[playerid][i][invItem]);
			format(str, sizeof(str), "%s", string);
			PlayerTextDrawSetString(playerid, itemname[playerid][i], str);
		}
		else
		{
			PlayerTextDrawHide(playerid, itemamountname[playerid][i]);
		}
	}
	return 1;
}
