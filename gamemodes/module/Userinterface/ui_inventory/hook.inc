#include <YSI_Coding\y_hooks>

hook OnDialogResponse(playerid, dialogid, response, listitem, const inputtext[])
{
	if(dialogid == INVENTORY_AMOUNT)
	{
		if(response)
		{
			new value = strval(inputtext);
			if(InventoryData[playerid][SelectInventory[playerid]][invQuantity] < value) return Error(playerid, "Kamu tidak memiliki %s sebanyak %d", InventoryData[playerid][SelectInventory[playerid]][invItem],value); {
				AmmountInventory[playerid] = value;
				PlayerTextDrawSetString(playerid, txd_inventory[playerid][18], inputtext);
			}
		}
	}
	if(dialogid == INVENTORY_GIVE)
	{
		if(!response) return 1;
		new count = 0;

		new Float:x,
			Float:y,
			Float:z,
			string[32];

		new itemid = SelectInventory[playerid];
		new value = AmmountInventory[playerid];

		new targetid = nearPlayers[playerid][listitem]; // Ambil ID player target

		if(!IsPlayerConnected(targetid)) return ErrorMsg(playerid, "Pemain tidak valid");

		if(!IsPlayerInRangeOfPoint(targetid, 3.0, x, y, z)) return ErrorMsg(playerid, "Target sudah terlalu jauh");

		if(Inventory_Count(playerid, InventoryData[playerid][itemid][invItem]) >= value)
		{
			Inventory_Remove(playerid, InventoryData[playerid][itemid][invItem], value);
			Inventory_Add(targetid, InventoryData[playerid][itemid][invItem], InventoryData[playerid][itemid][invModel], value);
			HideBackPackDialog(playerid);
			HideBackPackDialog(targetid);
		}
		else
		{
			ErrorMsg(playerid, "Anda tidak memiliki cukup Items");
		}
	}	
	
	if(dialogid == INVENTORY_PICKUP)
	{
		if(response)
		{
			new itemid = NearestItems[playerid][listitem];
			PickupItem(playerid, itemid);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

Dialog:INVENTORY_ID(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
	new count = 0;

    new Float:x,
        Float:y,
        Float:z,
		itemid = -1,
		string[32];

	GetPlayerPos(playerid, x, y, z);

	foreach(new userid : Player)
	{
		if(pData[userid][pSpawned] && userid != playerid && IsPlayerInRangeOfPoint(userid, 2.0, x, y, z) && count++ == listitem)
		{
			if (!IsPlayerNearPlayer(playerid, userid, 6.0)) return ErrorMsg(playerid, "Anda tidak berada di dekat pemain itu.");
			if (userid == INVALID_PLAYER_ID) return ErrorMsg(playerid, "Id pemain tidak valid.");
			itemid = SelectInventory[playerid];
			if (itemid == -1)
				return 0;
			strunpack(string, InventoryData[playerid][itemid][invItem]);

			if(AmmountInventory[playerid] < 1) return ErrorMsg(playerid, "Kamu belum mengatur jumlah untuk di berikan");
			if(AmmountInventory[playerid] > InventoryData[playerid][itemid][invQuantity]) return ErrorMsg(playerid, "Kamu tidak memiliki %s sebanyak itu", string);

			if (InventoryData[playerid][itemid][invQuantity] == 1)
			{
				new id = Inventory_Add(userid, string, InventoryData[playerid][itemid][invModel], AmmountInventory[playerid]);

				if (id == -1)
					return ErrorMsg(playerid, "Slot Inventory player tersebut FULL.");
				HideBackPackDialog(playerid);
				Inventory_Remove(playerid, string, AmmountInventory[playerid]);
			}
			else
			{
				new id = Inventory_Add(userid, string, InventoryData[playerid][itemid][invModel], AmmountInventory[playerid]);


				if (id == -1)
					return ErrorMsg(playerid, "Slot Inventory player tersebut FULL.");
				HideBackPackDialog(playerid);
				Inventory_Remove(playerid, string, AmmountInventory[playerid]);
			}
    	}
	}
    return 1;
}