CMD:itemlist(playerid, const params[])
{
	new
	    string[5000];

	if (!strlen(string)) {
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) {
			format(string, sizeof(string), "%s%s\n", string, g_aInventoryItems[i][e_InventoryItem]);
		}
	}
	return ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_LIST, "List of Items", string, "Select", "Cancel");
}

CMD:setitem(playerid, const params[])
{
	if(pData[playerid][pAdmin] < 6) return PermissionError(playerid);
	new
	    userid,
		item[320],
		amount;

	if (sscanf(params, "uds[320]", userid, amount, item))
	    return Usage(playerid, "/setitem [playerid/name] [amount] [item name]");
    for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
    {
        //if(amount > g_aInventoryItems[i][e_InventoryMax]) return Error(playerid, "Jumlah item sudah maksimal (%d)", g_aInventoryItems[i][e_InventoryMax]);

		new id;
		if(!strcmp(item, "Desert Eagle", true)) {
			id = Inventory_Add(userid, g_aInventoryItems[i][e_InventoryItem], g_aInventoryItems[i][e_InventoryModel], amount, 1);
		} else {
			id = Inventory_SetQuantity(userid, g_aInventoryItems[i][e_InventoryItem], amount);
		}
        if(id == -1) return Error(playerid, "Inventory slot anda sudah penuh");
        else return Servers(playerid, "You have set %s's \"%s\" to %d.", ReturnName(playerid), item, amount);
    }
    ErrorMsg(playerid, "Pastikan item yang anda set, berada di inventory. {FFFF00}/setitem");
    return 1;
}

//Drop Item
CMD:pickup(playerid)
{
	new
        count = 0,
        id = Item_Nearest(playerid),
        string[1080];

    if (id != -1)
    {
        string = "";
        format(string, sizeof(string), "Item Name\tQuantity\n");
        for (new i = 0; i < MAX_DROPPED_ITEMS; i ++) 
        if (count < MAX_LISTED_ITEMS && DroppedItems[i][droppedModel] && IsPlayerInRangeOfPoint(playerid, 1.5, DroppedItems[i][droppedPos][0], DroppedItems[i][droppedPos][1], DroppedItems[i][droppedPos][2]) && GetPlayerInterior(playerid) == DroppedItems[i][droppedInt] && GetPlayerVirtualWorld(playerid) == DroppedItems[i][droppedWorld]) {
            NearestItems[playerid][count++] = i;
            format(string, sizeof(string), "%s%s\t%d\n", string, DroppedItems[i][droppedItem], DroppedItems[i][droppedQuantity]);
        }
        if (count == 1)
        {
            if (DroppedItems[id][droppedWeapon] != 0)
            {
                GivePlayerWeapon(playerid, DroppedItems[id][droppedWeapon], DroppedItems[id][droppedAmmo]);

                Item_Delete(id);
                //SendNearbyMessage(playerid, 30.0, X11_PURPLE, "** %s has picked up a %s.", GetName(playerid), GetWeaponName(DroppedItems[id][droppedWeapon]));
                return 1;
            }
            else if (PickupItem(playerid, id))
            {
                //SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has picked up a \"%s\".", GetPlayerNameEx(playerid), DroppedItems[id][droppedItem]);
            }
            //else Error(playerid, "You don't have any room in your inventory.");
        }
        else ShowPlayerDialog(playerid, INVENTORY_PICKUP, DIALOG_STYLE_TABLIST_HEADERS, "Pickup Items", string, "Pickup", "Cancel");
    }
	return 1;
}

CMD:spawnitem(playerid, const params[])
{
    if(pData[playerid][pAdmin] < 5) return PermissionError(playerid);

    if(isnull(params))
        return Usage(playerid, "/spawnitem (item name), gunakan {FFFF00}'/itemlist' untuk melihat list item");

    static
        Float:x,
        Float:y,
        Float:z;

    GetPlayerPos(playerid, x, y, z);

    for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], params, true))
    {
        new id = DropItem(g_aInventoryItems[i][e_InventoryItem], INVALID_PLAYER_ID, g_aInventoryItems[i][e_InventoryModel], 1, x, y, z - 0.9, GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));

        if(id == -1)
            return Error(playerid, "Server ini sudah mencapai limit spawn item");

        Servers(playerid, "Anda telah membuat \"%s\" gunakan {FFFF00}'/setquantity' {FFFFFF}untuk mengubah jumlah item", g_aInventoryItems[i][e_InventoryItem]);
        return 1;
    }
    Error(playerid, "Nama item tidak valid, gunakan {FFFF00}'/itemlist' {FFFFFF}untuk melihat list item");
    return 1;
}

CMD:setquantity(playerid, const params[])
{
    static
        id = -1,
        amount;

    if(pData[playerid][pAdmin] < 5) return PermissionError(playerid);

    if((id = Item_Nearest(playerid)) == -1)
        return Error(playerid, "Anda harus berada di dekat item tersebut");

    if(sscanf(params, "d", amount))
        return Usage(playerid, "/setquantity (amount)");

    if(amount < 1)
        return Error(playerid, "Item yang anda masukan tidak boleh di bawah 1");

    Item_SetQuantity(id, amount);
    Servers(playerid, "Anda telah mengubah jumlah item \"%s\" menjadi %d.", DroppedItems[id][droppedItem], amount);
    return 1;
}

CMD:destroyitem(playerid, const params[])
{
    if(pData[playerid][pAdmin] < 4) return PermissionError(playerid);

    static
        id = -1;

    if((id = Item_Nearest(playerid)) == -1)
        return Error(playerid, "Anda sedang tidak berada di dekat item apapun");

    Servers(playerid, "Anda telah menghapus item \"%s\".", DroppedItems[id][droppedItem]);
    Item_Delete(id);
    return 1;
}

CMD:clearitem(playerid, const params[])
{
	if(pData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
	new targetid;
	if(sscanf(params, "u", targetid))
		return Usage(playerid, "clearitem");

	if(targetid == INVALID_PLAYER_ID)
		return Error(playerid, "Player ID tidak valid");

	Inventory_Clear(targetid);

	Info(targetid, "Administrator {A60000}%s {FFFFFF}melakukan pembersihkan inventory kepada anda", pData[playerid][pAdminname]);
	SendStaffMessage(-1, "{A60000}%s {FFFFFF}telah menggunakan {FFFF00}'/clearitem' {FFFFFF}command kepada {FFFF00}%s", pData[playerid][pAdminname], pData[targetid][pName]);
	return 1;
}