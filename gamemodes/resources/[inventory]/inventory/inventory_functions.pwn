#include <YSI\y_hooks>
#define MAX_INVENTORY 				32

new pUseItemTimer[MAX_PLAYERS] = {-1, ...};
new ListedInventory[MAX_PLAYERS][MAX_INVENTORY];
new invenIndex[MAX_PLAYERS];
new invenNumber[MAX_PLAYERS];
new invenPlayed[MAX_PLAYERS];

enum inventoryData 
{
    invExists,
    invID,
    invItem[32 char],
    invModel,
    invQuantity,

    invSlot
};
new InventoryData[MAX_PLAYERS][MAX_INVENTORY][inventoryData];

enum e_InventoryItems
{
	e_InventoryItem[32],
	e_InventoryModel,
    e_InventoryWeight,
    bool:e_InventoryDrop
};

// Nama Dan Model Barang
new const g_aInventoryItems[][e_InventoryItems] = 
{
    {"Nasi Goreng", 2355, 5, true},
    {"Kopi Kenangan", 19835, 5, true},
	{"Batu Kotor", 3930, 30, true},
	{"Nasi Uduk", 19567, 5, true},
    {"Kanabis", 19473, 10, true},
	{"Batu Bersih", 2936, 30, true},
	{"Air Mineral", 19570, 5, true},
	{"Besi", 19809, 20, true},
	{"Tembaga", 11748, 20, true},
	{"Berlian", 19941, 30, true},
    {"Emas", 19941, 20, true},
	{"Smartphone", 18870, 25, true},
    {"Earphone", 19424, 10, true},
    {"Radio", 19942, 25, true},
	{"Kayu", 19793, 30, true},
	{"Kayu Potongan", 1463, 25, true},
	{"Kayu Kemas", 2912, 30, true},
	{"Marijuana", 1575, 10, true},
	{"Benang", 1902, 5, true},
	{"Kain", 11747, 10, true},
	{"Pakaian", 2399, 10, true},
	{"Bandage", 11736, 20, true},
    {"Medkit", 11738, 20, true},
    {"Alprazolam", 1241, 20, true},
	{"Ayam Potong", 2804, 15, true},
	{"Ayam Hidup", 16776, 40, true},
	{"Ayam Kemas", 2768, 20, true},
    {"Sampah Makanan", 2840, 5, false},
    {"Kevlar", 19515, 100, true},
    {"Botol", 19570, 5, true},
    {"Petrol", 19621, 50, true},
    {"Pure Oil", 3632, 50, true},
    {"GAS", 1650, 50, true},
    {"Ikan", 19630, 10, true},
    {"Rokok", 19896, 1, true},
    {"Pancingan", 18632, 10, true},
    {"Umpan", 1603, 1, true},
    {"Hiu", 1608, 50, true},
    {"Penyu", 1609, 45, true},
    {"Ikan Tawar", 1599, 10, true},
    {"Jerigen", 1650, 50, true},
    {"Tools Kit", 19918, 50, true},
    {"Repair Kit", 19921, 50, true},
    {"Uang", 1212, 1, true},
    {"Uang Merah", 1212, 1, true},
    {"Linggis", 18634, 10, true},
    {"Kunci T", 334, 10, true},
    {"Nasi Pecel", 2218, 5, true},
    {"Es Teh", 1546, 5, true},
    {"Bubur Pedas", 19568, 5, true},
    {"Jus Apel", 19564, 5, true},
    {"Boombox", 2103, 50, true},
    {"Kebab A5", 2769, 5, true},
    {"Choco Matcha", 1667, 5, true},
    {"Bakso", 19567, 5, true},
    {"Teh Jeruk", 19563, 5, true},
    {"Susu Murni", 19570, 10, true},
    {"Susu Olahan", 19570, 10, true},
    {"Susu Fresh", 19569, 5, true},
    {"Cabe", 2253, 5, true},
    {"Padi", 804, 5, true},
    {"Tebu", 806, 10, true},
    {"Garam Kristal", 1611, 10, true},
    {"Gula", 1575, 10, true},
    {"Beras", 2060, 10, true},
    {"Sambal", 11722, 10, true},
    {"Garam", 1279, 10, true},
    {"Daging", 2806, 15, true},
    {"Tanduk", 6865, 10, true},
    {"Kulit", 19560, 10, true},
    {"Bulu", 19517, 1, true},
    {"Boxmats", 2912, 30, true},
    {"Baja", 19772, 30, true},
    {"Material", 19843, 30, true},
    {"Kaca", 1649, 25, true},
    {"Karet", 1316, 15, true},
    {"Plastik", 1264, 5, true},
    {"Alumunium", 2937, 30, true},
    {"Backpack", 3026, 500, true},
    {"Masker", 19036, 5, true},
    {"Plat Besi", 3117, 20, true},
    {"Korek Api", 19998, 1, true},
    {"Bibit Cabe", 2663, 5, true},
    {"Bibit Padi", 2663, 5, true},
    {"Bibit Tebu", 2663, 5, true},
    {"Petasan", 3790, 15, true},
    {"KTA", 1581, 1, false},
    {"Tahu Bulat", 19574, 5, true},
    {"Pilox", 365, 15, true},
    {"Chip", 1915, 1, false},
    {"Uranium ACD", 3046, 20, true},
    {"Uranium", 2958, 20, true},
    {"Senter", 18641, 10, true},
    {"Knife", 335, 50, true},
    {"Katana", 339, 50, true},
    {"Colt 45", 346, 150, true},
    {"Silenced 9mm", 374, 150, true},
    {"Micro SMG", 352, 150, true},
    {"Sawn-off Shotgun", 350, 250, true},
    {"Desert Eagle", 348, 150, true},
    {"MP5", 353, 150, true},
    {"TEC-9", 372, 150, true},
    {"Shotgun", 349, 250, true},
    {"AK-47", 355, 350, true},
    {"M4", 356, 350, true},
    {"Rifle", 357, 550, true},
    {"Sniper", 358, 550, true},
    {"Chainsaw", 341, 550, true}
};

/*Function*/
function OnInventoryAdd(playerid, itemid)
{
    InventoryData[playerid][itemid][invID] = cache_insert_id();
    return 1;
}

stock Float:GetPlayerMaxInventory(playerid)
{
	new Float:Weight = 50000;
	if(AccountData[playerid][pVip] == 0) return Weight / 1000;
	if(AccountData[playerid][pVip] == 1) return (Weight + 10000) / 1000;
	if(AccountData[playerid][pVip] == 2) return (Weight + 20000) / 1000;
	if(AccountData[playerid][pVip] == 3) return (Weight + 30000) / 1000;
    if(AccountData[playerid][pVip] == 4) return (Weight + 40000) / 1000;
	return Weight;
}

Float:GetItemAllKG(playerid)
{
	new Float:totalkg;
	forex(inv, MAX_INVENTORY)
	{
		if (InventoryData[playerid][inv][invExists])
		{
			for (new i = 0; i < sizeof(g_aInventoryItems); i ++) 
			{
				if(!strcmp(g_aInventoryItems[i][e_InventoryItem], InventoryData[playerid][inv][invItem], true))
				{
					totalkg += float(InventoryData[playerid][inv][invQuantity])*g_aInventoryItems[i][e_InventoryWeight] / 1000;
				}
			}
		}
	}
	return totalkg;
}

Float:GetItemKG(const items[], quantity)
{
	new Float:totalkg;
	for (new i = 0; i < sizeof(g_aInventoryItems); i ++)
	{
		if(!strcmp(g_aInventoryItems[i][e_InventoryItem], items, true))
		{
			totalkg += float(quantity)*g_aInventoryItems[i][e_InventoryWeight] / 1000;
		}
	}
	return totalkg;
}

stock IsInventoryFull(playerid, const items[], quantity = 1)
{
    if(GetItemAllKG(playerid) + GetItemKG(items, quantity) > GetPlayerMaxInventory(playerid))
    {
        return 1;
    }
    return 0;
}

function Inventory_Clear(playerid)
{
    new
	    string[256];
	    
	forex(i, MAX_INVENTORY)
	{
	    if (InventoryData[playerid][i][invExists])
	    {
	        InventoryData[playerid][i][invExists] = false;
	        InventoryData[playerid][i][invModel] = 0;
	        InventoryData[playerid][i][invQuantity] = 0;
		}
	}
	format(string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d'", AccountData[playerid][pID]);
	return mysql_tquery(dcrp_query, string);
}

Inventory_GetItemID(playerid, const item[])
{
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
	    if (!InventoryData[playerid][i][invExists])
	        continue;

		if (!strcmp(InventoryData[playerid][i][invItem], item)) return i;
	}
	return -1;
}

Inventory_GetFreeID(playerid)
{
	if (Inventory_Items(playerid) >= 32)
		return -1;

	for(new i = 0; i < MAX_INVENTORY; i++)
	{
	    if (!InventoryData[playerid][i][invExists])
	        return i;
	}
	return -1;
}

Inventory_Items(playerid)
{
    new count;

    for(new i = 0; i < MAX_INVENTORY; i++) if (InventoryData[playerid][i][invExists]) 
	{
        count++;
	}
	return count;
}
Inventory_Count(playerid, const item[])
{
	new itemid = Inventory_GetItemID(playerid, item);
	if (itemid != -1)
	    return InventoryData[playerid][itemid][invQuantity];
	return 0;
}

PlayerHasItem(playerid, const item[])
{
	return (Inventory_GetItemID(playerid, item) != -1);
}

stock InventoryWeightFull(playerid)
{
    if(GetItemAllKG(playerid) > GetPlayerMaxInventory(playerid))
    {
        return 1;
    }
    return 0;
}

ItemDelete(playerid, const item[], quantity = 1)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[128];

	if (itemid != -1)
	{
		if (InventoryData[playerid][itemid][invQuantity] > 0)
		{
            AccountData[playerid][pBeratItem] -= GetItemKG(item, quantity);
			InventoryData[playerid][itemid][invQuantity] -= quantity;
		}
		if (quantity == -1 || InventoryData[playerid][itemid][invQuantity] < 1)
		{
			InventoryData[playerid][itemid][invExists] = false;
			InventoryData[playerid][itemid][invModel] = 0;
			InventoryData[playerid][itemid][invQuantity] = 0;

			format(string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d' AND `invID` = '%d'", AccountData[playerid][pID], InventoryData[playerid][itemid][invID]);
			mysql_tquery(dcrp_query, string);
		}
		else if (quantity != -1 && InventoryData[playerid][itemid][invQuantity] > 0)
		{
			format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` - %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, AccountData[playerid][pID], InventoryData[playerid][itemid][invID]);
			mysql_tquery(dcrp_query, string);
		}
		return 1;
	}
	return 0;
}

ItemAdd(playerid, const item[], quantity = 1)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[256];

	if (itemid == -1)
	{
		itemid = Inventory_GetFreeID(playerid);
		if (itemid != -1)
		{
            AccountData[playerid][pBeratItem] += GetItemKG(item, quantity);
			InventoryData[playerid][itemid][invExists] = true;
	        InventoryData[playerid][itemid][invQuantity] = quantity;
	        strpack(InventoryData[playerid][itemid][invItem], item, 32 char);

			for (new id = 0; id < sizeof(g_aInventoryItems); id ++) if(!strcmp(g_aInventoryItems[id][e_InventoryItem], item, true))
			{
				InventoryData[playerid][itemid][invModel] = g_aInventoryItems[id][e_InventoryModel];
			}
			
			format(string, sizeof(string), "INSERT INTO `inventory` (`ID`, `invItem`, `invModel`, `invQuantity`) VALUES('%d', '%s', '%d', '%d')", AccountData[playerid][pID], item, InventoryData[playerid][itemid][invModel], quantity);
			mysql_tquery(dcrp_query, string, "OnInventoryAdd", "dd", playerid, itemid);
			return itemid;
		}
		return -1;
	}
	else
	{
        format(string, sizeof(string), "UPDATE player_characters SET Char_BackpackWeight = '%.3f' WHERE pID = '%d'", AccountData[playerid][pBeratItem], AccountData[playerid][pID]);
        mysql_tquery(dcrp_query, string);

		format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` + %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, AccountData[playerid][pID], InventoryData[playerid][itemid][invID]);
		mysql_tquery(dcrp_query, string);
		InventoryData[playerid][itemid][invQuantity] += quantity;
	}
	return itemid;
}

forward OpenInventory(playerid);
public OpenInventory(playerid)
{
    new
        itemname[24],
        shstr[255],
        count = 0;
    
    strcat(shstr, "Nama Item\tJumlah\tBerat (-)\n");
    for (new i = 0; i < MAX_INVENTORY; i ++) if (InventoryData[playerid][i][invExists])
    {
        strunpack(itemname, InventoryData[playerid][i][invItem]);
        strcat(shstr, sprintf("%s\t%d\t-\n", itemname, InventoryData[playerid][i][invQuantity]));
        ListedInventory[playerid][count ++] = i;
    }
    if(count)
    {
        AccountData[playerid][pStorageSelect] = 0;
        ShowPlayerDialog(playerid, DIALOG_INVENTORY, DIALOG_STYLE_TABLIST_HEADERS, ""PINK1"DCRP"WHITE"- Inventory", shstr, "Pilih", "Batal");
        return 1;
    }
    ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki item apapun di inventory!");
    return 1;
}

function OnPlayerGiveInvItem(playerid, userid, itemid, name[], value)
{
	new str[32], string[128];
	strunpack(string, InventoryData[playerid][itemid][invItem]);
	if(Inventory_Count(playerid, string) < AccountData[playerid][pAmountInv])
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki cukup barang!");

	if(IsInventoryFull(userid, string, AccountData[playerid][pAmountInv])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tas pemain ini tidak kuat menampung lebih banyak item lagi.");
	if(AccountData[playerid][pActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang melakukan sesuatu, harap tunggu!");

	if(AccountData[playerid][IsLoggedIn] == false)
	{
	    ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus dalam keadaan login!");
	    return 0;
	}
	
	for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if (!strcmp(g_aInventoryItems[i][e_InventoryItem], string, true))
	{
		if(g_aInventoryItems[i][e_InventoryDrop] == false) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak bisa memberikan item ini");
		new id = ItemAdd(userid, name, value);
		if (id == -1)
			return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain ini tidak memiliki cukup slot inventory!"), Inventory_Close(playerid);

		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(playerid, name, str, 2);

		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(userid, name, str, 2);

		ItemDelete(playerid, name, value);

		ApplyAnimation(playerid, "DEALER", "shop_pay", 4.1, 0, 1, 1, 0, 0, 1);
		ApplyAnimation(userid, "DEALER", "shop_pay", 4.1, 0, 1, 1, 0, 0, 1);
	}
	return Inventory_Close(playerid);
}

ItemCantUse(const item[])
{
    if(!strcmp(item, "Batu Kotor", true)) return 1;
    if(!strcmp(item, "Batu Bersih", true)) return 1;
    if(!strcmp(item, "Sampah Makanan", true)) return 1;
    if(!strcmp(item, "Hiu", true)) return 1;
    if(!strcmp(item, "Umpan", true)) return 1;
    if(!strcmp(item, "Besi", true)) return 1;
    if(!strcmp(item, "Tembaga", true)) return 1;
    if(!strcmp(item, "Emas", true)) return 1;
    if(!strcmp(item, "Berlian", true)) return 1;
    if(!strcmp(item, "Alumunium", true)) return 1;
    if(!strcmp(item, "Plastik", true)) return 1;
    if(!strcmp(item, "Karet", true)) return 1;
    if(!strcmp(item, "Kayu", true)) return 1;
    if(!strcmp(item, "Kayu Potongan", true)) return 1;
    if(!strcmp(item, "Kayu Kemas", true)) return 1;
    if(!strcmp(item, "Benang", true)) return 1;
    if(!strcmp(item, "Kain", true)) return 1;
    if(!strcmp(item, "Pakaian", true)) return 1;
    if(!strcmp(item, "Botol", true)) return 1;
    if(!strcmp(item, "Petrol", true)) return 1;
    if(!strcmp(item, "Pure Oil", true)) return 1;
    if(!strcmp(item, "GAS", true)) return 1;
    if(!strcmp(item, "Ikan", true)) return 1;
    if(!strcmp(item, "Penyu", true)) return 1;
    if(!strcmp(item, "Ikan Tawar", true)) return 1;
    if(!strcmp(item, "Daging", true)) return 1;
    if(!strcmp(item, "Tanduk", true)) return 1;
    if(!strcmp(item, "Chip", true)) return 1;
    return 0;
}

forward OnPlayerUseItem(playerid, itemid, itemname[]);
public OnPlayerUseItem(playerid, itemid, itemname[])
{
    if(AccountData[playerid][pInjured]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang pingsan!");
    if(ItemCantUse(itemname)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Item tersebut tidak dapat digunakan!");
    if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, tunggu hingga progress selesai!");
    if(!strcmp(itemname, "Nasi Goreng", true))
    {
        if(AccountData[playerid][pHunger] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pHunger] += 45;
        ItemDelete(playerid, "Nasi Goreng");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Nasi Goreng", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 2355, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil nasi goreng lalu memakannya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MAKAN");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Petasan", true))
    {
        if(!PlayerHasItem(playerid, "Korek Api")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki korek api!");
        ApplyAnimationEx(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 1);
        new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x, y, z);
        
        if(FireworkTimer[playerid] != -1)
        {
            KillTimer(FireworkTimer[playerid]);
            FireworkTimer[playerid] = -1;
            if(DestroyDynamicObject(FireworkObject[playerid])) FireworkObject[playerid] = STREAMER_TAG_OBJECT: INVALID_STREAMER_ID;
        }
        FireworkObject[playerid] = CreateDynamicObject(345, x, y, z - 0.4, 90.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), -1, 100.0, 100.0);
        FireworkTimer[playerid] = SetTimerEx("FireUp", 5000, false, "d", playerid);
        SetPVarFloat(playerid, "FireX", x);
        SetPVarFloat(playerid, "FireY", y);
        SetPVarFloat(playerid, "FireZ", z);

        Inventory_Close(playerid);
        ItemDelete(playerid, "Petasan");
        ShowItemBox(playerid, "Petasan", "Removed_1x", 2);
    }
    else if(!strcmp(itemname, "Nasi Pecel", true))
    {
        if(AccountData[playerid][pHunger] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pHunger] += 30;
        ItemDelete(playerid, "Nasi Pecel");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Nasi Pecel", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 2218, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil nasi pecel lalu memakannya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MAKAN");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Bibit Padi", true))
    {
        new wid = Weed_Nearest(playerid);
        new type = 1;

        if(!IsALadangField(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada diladang!");        
        if(AccountData[playerid][pJob] != JOB_FARMER) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan seorang petani!");
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kamu harus on-foot!");
        if(wid != -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Terlalu dekat dengan tanaman lain!");        
        if(Weed_Count() >= MAX_WEED) return ShowTDN(playerid, NOTIFICATION_ERROR, "Ladang sudah mencapai batas maskimal tanaman! (M: 1000)");
        
        ItemDelete(playerid, "Bibit Padi");
        ShowItemBox(playerid, "Bibit Padi", "Removed_1x", 2);
        SetTimerEx("PlantWeed", 3000, false, "dd", playerid, type);
        SendRPMeAboveHead(playerid, "Menanam bibit padi", X11_PLUM1);
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.1, 1, 0, 0, 1, 0, 1);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Bibit Tebu", true))
    {
        new wid = Weed_Nearest(playerid);
        new type = 2;

        if(!IsALadangField(playerid))   
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada diladang!");

        if(AccountData[playerid][pJob] != JOB_FARMER)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan seorang petani!");
        
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Kamu harus on-foot!");

        if(wid != -1)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Terlalu dekat dengan tanaman lain!");
        
        if(Weed_Count() >= MAX_WEED)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Ladang sudah mencapai batas maskimal tanaman! (M: 1000)");
        
        ItemDelete(playerid, "Bibit Tebu");
        ShowItemBox(playerid, "Bibit Tebu", "Removed_1x", 2);
        SetTimerEx("PlantWeed", 3000, false, "dd", playerid, type);
        SendRPMeAboveHead(playerid, "Menanam bibit tebu", X11_PLUM1);
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.1, 1, 0, 0, 1, 0, 1);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Bibit Cabe", true))
    {
        new wid = Weed_Nearest(playerid);
        new type = 3;

        if(!IsALadangField(playerid))   
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada diladang!");

        if(AccountData[playerid][pJob] != JOB_FARMER)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan seorang petani!");

        
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Kamu harus on-foot!");

        if(wid != -1)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Terlalu dekat dengan tanaman lain!");
        
        if(Weed_Count() >= MAX_WEED)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Ladang sudah mencapai batas maskimal tanaman! (M: 1000)");
        
        ItemDelete(playerid, "Bibit Cabe");
        ShowItemBox(playerid, "Bibit Cabe", "Removed_1x", 2);
        SetTimerEx("PlantWeed", 3000, false, "dd", playerid, type);
        SendRPMeAboveHead(playerid, "Menanam bibit cabe", X11_PLUM1);
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.1, 1, 0, 0, 1, 0, 1);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "KTA", true))
    {
        Inventory_Close(playerid);
        SendRPMeAboveHead(playerid, "Menunjukkan Kartu Tanda Anggota", X11_PLUM1);
        foreach(new i : Player) if (IsPlayerNearPlayer(playerid, i, 2.5))
        {
            ShowKTA(playerid, i);
        }
    }
    else if(!strcmp(itemname, "Smartphone", true))
    {
        Inventory_Close(playerid);
        ShowingSmartphone(playerid);
    }
    else if(!strcmp(itemname, "Senter", true))
    {
        if (IsPlayerInAnyVehicle(playerid))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada diluar kendaraan!");
        
        if (AccountData[playerid][ActivityTime] != 0)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat menggunakan ini ketika progress acivity berjalan!");
        
        if (AccountData[playerid][pInjured])
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukan ini ketika sedang pingsan!");
        
        if (AccountData[playerid][phoneShown])
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang membuka Smartphone!");
        
        switch (AccountData[playerid][pFlashShown])
        {
            case false:
            {
                AccountData[playerid][pFlashShown] = true;
                ApplyAnimationEx(playerid, "ped", "phone_talk", 1.1, 1, 1, 1, 1, 1, 1);
                SetPlayerAttachedObject(playerid, JOB_SLOT, 18641, 6,  0.080999, 0.042000, -0.034000,  0.000000, 0.000000, 0.000000,  1.000000, 1.000000, 1.000000); // FLashlight Objects
                SendRPMeAboveHead(playerid, "Mengambil senter dari dalam tas", X11_PLUM1);
            }
            case true:
            {
                AccountData[playerid][pFlashShown] = false;
                StopLoopingAnim(playerid);
                RemovePlayerAttachedObject(playerid, JOB_SLOT);
                if (AccountData[playerid][pFlashOn]) {
                    AccountData[playerid][pFlashOn] = false;
                    RemovePlayerAttachedObject(playerid, 9);
                }
                SendRPMeAboveHead(playerid, "Memasukkan senter ke dalam tas", X11_PLUM1);
            }
        }
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Radio", true))
    {
        if(!PlayerHasItem(playerid, "Radio")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki radio!");
        if(IsPlayerInWater(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat membuka Radio di dalam air!");

        SendRPMeAboveHead(playerid, "Membuka Radio miliknya.", X11_PLUM1);
        if(!IsPlayerInAnyVehicle(playerid))
        {
            ApplyAnimation(playerid, "ped", "Jetpack_Idle", 4.1, 0, 0, 0, 1, 0, 1);
            SetPlayerAttachedObject(playerid, 9, 19942, 5, 0.043000, 0.022999, -0.006000, -112.000022, -34.900020, -8.500002, 1.000000, 1.000000, 1.000000);
        }
        
        Inventory_Close(playerid);
        RadioTextdrawToggle(playerid, true);
        SelectTextDraw(playerid, COLOR_SYNTAX);
        return 1;
    }
    else if(!strcmp(itemname, "Backpack", true))
    {
        if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, harap tunggu!");
        SendRPMeAboveHead(playerid, "Membuka Backpack dan mengeluarkan barangnya", X11_PLUM1);
    
        AccountData[playerid][ActivityTime] = 1;
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MEMBUKA");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);

        ApplyAnimationEx(playerid, "COP_AMBIENT", "Copbrowse_loop", 4.1, 0, 0, 0, 0, 0, 1);
        AccountData[playerid][pOpenBackpackTimer] = SetTimerEx("OpeningBackpack", 1000, true, "i", playerid);
    }
    else if(!strcmp(itemname, "Bubur Pedas", true))
    {
        if(AccountData[playerid][pHunger] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pHunger] += 20;
        ItemDelete(playerid, "Bubur Pedas");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Bubur Pedas", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 19568, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil bubur pedas lalu memakannya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MAKAN");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Jus Apel", true))
    {
        if(AccountData[playerid][pThirst] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pThirst] += 20;
        ItemDelete(playerid, "Jus Apel");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Jus Apel", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 19564, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil jus apel lalu meminumnya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MINUM");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Susu Fresh", true))
    {
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah mu terlebih dahulu");

        if(GetPlayerDrunkLevel(playerid) > 0)
        {
            AccountData[playerid][pThirst] += 15;
            SetPlayerDrunkLevel(playerid, 0);
            ItemDelete(playerid, "Susu Fresh");
            ItemAdd(playerid, "Sampah Makanan");
            ShowItemBox(playerid, "Susu Fresh", "Removed_1x", 2);
            ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

            ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
            SetPlayerAttachedObject(playerid, 9, 19569, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
            SendRPMeAboveHead(playerid, "Mengambil susu fresh lalu meminumnya", X11_PLUM1);

            AccountData[playerid][ActivityTime] = 1;
            pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
            PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MINUM");
            ShowProgressBar(playerid);
        }
        else 
        {
            AccountData[playerid][pThirst] += 15;
            ItemDelete(playerid, "Susu Fresh");
            ItemAdd(playerid, "Sampah Makanan");
            ShowItemBox(playerid, "Susu Fresh", "Removed_1x", 2);
            ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

            ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
            SetPlayerAttachedObject(playerid, 9, 19569, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
            SendRPMeAboveHead(playerid, "Mengambil susu fresh lalu meminumnya", X11_PLUM1);

            AccountData[playerid][ActivityTime] = 1;
            pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
            PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MINUM");
            ShowProgressBar(playerid);
        }
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Es Teh", true))
    {
        if(AccountData[playerid][pThirst] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pThirst] += 25;
        ItemDelete(playerid, "Es Teh");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Es Teh", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 1546, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil es teh lalu meminumnya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MINUM");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Nasi Uduk", true))
    {
        if(AccountData[playerid][pHunger] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pHunger] += 15;
        ItemDelete(playerid, "Nasi Uduk");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Nasi Uduk", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 19567, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil nasi uduk lalu memakannya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MAKAN");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Tahu Bulat", true))
    {
        if(AccountData[playerid][pHunger] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pHunger] += 5;
        ItemDelete(playerid, "Tahu Bulat");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Tahu Bulat", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 19574, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil tahu bulat lalu memakannya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MAKAN");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Kopi Kenangan", true))
    {
        if(AccountData[playerid][pThirst] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pThirst] += 45;
        ItemDelete(playerid, "Kopi Kenangan");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Kopi Kenangan", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 19835, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil kopi kenangan lalu meminumnya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MINUM");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Air Mineral", true))
    {
        if(AccountData[playerid][pThirst] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pThirst] += 25;
        ItemDelete(playerid, "Air Mineral");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Air Mineral", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 19570, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil air mineral lalu meminumnya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MINUM");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Choco Matcha", true))
    {
        if(AccountData[playerid][pThirst] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pThirst] += 20;
        ItemDelete(playerid, "Choco Matcha");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Choco Matcha", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 1667, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil choco matcha lalu meminumnya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MINUM");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Teh Jeruk", true))
    {
        if(AccountData[playerid][pThirst] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pThirst] += 20;
        ItemDelete(playerid, "Teh Jeruk");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Teh Jeruk", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 19563, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil teh jeruk lalu meminumnya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MINUM");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Kebab A5", true))
    {
        if(AccountData[playerid][pHunger] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pHunger] += 20;
        ItemDelete(playerid, "Kebab A5");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Kebab A5", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 2769, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil kebab a5 lalu memakannya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MAKAN");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Bakso", true))
    {
        if(AccountData[playerid][pHunger] >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");
        if(Inventory_Count(playerid, "Sampah Makanan") >= 15) return ShowTDN(playerid, NOTIFICATION_ERROR, "Buang sampah anda terlebih dahulu!");

        AccountData[playerid][pHunger] += 20;
        ItemDelete(playerid, "Bakso");
        ItemAdd(playerid, "Sampah Makanan");
        ShowItemBox(playerid, "Bakso", "Removed_1x", 2);
        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);

        ApplyAnimationEx(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerAttachedObject(playerid, 9, 19567, 6, 0.038, 0.014, 0.031, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
        SendRPMeAboveHead(playerid, "Mengambil bakso lalu memakannya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MAKAN");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Bandage", true))
    {
        new Float:health;
        GetPlayerHealth(playerid, health);
        
        if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, harap tunggu!");
        if(health >= 95.0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memerlukannya saat ini!");

        ApplyAnimation(playerid, "COP_AMBIENT", "Copbrowse_loop", 4.1, 1, 0, 0, 0, 0, 1);
        Inventory_Close(playerid);
        SendRPMeAboveHead(playerid, "Mengambil perban lalu menggunakannya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("UseBandage", 1000, true, "d", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "USE BANDAGE");
        ShowProgressBar(playerid);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Alprazolam", true))
    {
        if(AccountData[playerid][pStress] < 1) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda tidak sedang stress!");
        if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, harap tunggu!");
        
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SendRPMeAboveHead(playerid, "Mengambil Alprazolam lalu menggunakannya", X11_PLUM1);

        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("EatingProgress", 1000, true, "i", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "USING");
        ShowProgressBar(playerid);

        AccountData[playerid][pStress] -= 25;
        ItemDelete(playerid, "Alprazolam");
        ShowItemBox(playerid, "Alprazolam", "Removed_1x", 2);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Marijuana", true))
    {
        if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, harap tunggu!");
        
        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("UseMarijuana", 1000, true, "i", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "USING");
        ShowProgressBar(playerid);

        ApplyAnimation(playerid, "SMOKING", "M_smk_drag", 4.1, 1, 0, 0, 0, 0, 1);
        SendRPMeAboveHead(playerid, "Mengambil marijuana lalu sebat", X11_PLUM1);
        //ShowItemBox(playerid, "Marijuana", "Removed_1x", 2);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Uranium", true))
    {
        if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, harap tunggu!");
        
        AccountData[playerid][ActivityTime] = 1;
        pUseItemTimer[playerid] = SetTimerEx("UseUranium", 1000, true, "i", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "USING");
        ShowProgressBar(playerid);

        ApplyAnimation(playerid, "VENDING", "VEND_Drink2_P", 4.1, 1, 0, 0, 0, 0, 1);
        SendRPMeAboveHead(playerid, "Mengambil uranium lalu menggunakannya", X11_PLUM1);
        //ShowItemBox(playerid, "Uranium", "Removed_1x", 2);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Kevlar", true))
    {
        if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, harap tunggu!");
        new Float:AM;
        GetPlayerArmour(playerid, AM);
        if(AM >= 95) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kevlar anda masih di 95%, tidak dapat menggunakan lagi!");

        pUseItemTimer[playerid] = SetTimerEx("UseKevlar", 1000, true, "i", playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MEMAKAI KEVLAR");
        ShowProgressBar(playerid);
        
        AccountData[playerid][ActivityTime] = 1;
        ApplyAnimationEx(playerid, "COP_AMBIENT", "Copbrowse_loop", 4.1, 1, 0, 0, 0, 0, 1);
        SendRPMeAboveHead(playerid, "Mengambil Kevlar lalu menggunakannya", X11_PLUM1);
        //ShowItemBox(playerid, "Kevlar", "Removed_1x", 2);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Rokok", true))
    {
        if(!PlayerHasItem(playerid, "Korek Api")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki korek api!");

        ItemDelete(playerid, "Rokok");
        ShowItemBox(playerid, "Rokok", "Removed_1x", 2);
        ApplyAnimation(playerid, "SMOKING", "M_smk_in", 4.1, 0, 0, 0, 0, 0, 1);
        SendRPMeAboveHead(playerid, "Mengambil sebatang rokok lalu membakarnya menggunakan korek api", X11_PLUM1);
        Info(playerid, "Gunakan "GREEN"`ALT`"WHITE" untuk menghisap rokok "YELLOW"`/stopsmoke'`"WHITE" untuk membuang rokok");
        Inventory_Close(playerid);

        IsPlayerSmoking[playerid] = true;
        CountSmoking[playerid] = 10;
    }   
    else if(!strcmp(itemname, "Jerigen", true))
    {
        new vehid = GetNearestVehicleToPlayer(playerid, 3.0, false);
        if(vehid == INVALID_VEHICLE_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak didekat kendaraan manapun!");
        
        if(DestroyDynamic3DTextLabel(RefillLabel[playerid]))
            RefillLabel[playerid] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

        RefillLabel[playerid] = CreateDynamic3DTextLabel("Tekan "GREEN"[ALT]"WHITE" Mengisi BBM", -1, 0.0, 0.0, 1.1, 5.0, INVALID_PLAYER_ID, vehid, 1);
        AccountData[playerid][pJerigenUse] = true;
        AccountData[playerid][pTempVehID] = vehid;

        ItemDelete(playerid, "Jerigen");
        ShowItemBox(playerid, "Jerigen", "Removed_1x", 2);
        SetPlayerAttachedObject(playerid, 9, 1650, 6, 0.127, 0.015, 0.042, 0.000, -96.900, -11.000, 1.000, 1.000, 1.000);
        Inventory_Close(playerid);
    }
    else if(!strcmp(itemname, "Tools Kit", true))
    {
        if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, harap tunggu!");

        new vehid = -1, bool: found = false;
        if((vehid = Vehicle_Nearest(playerid)) != -1)
        {
            if(PlayerVehicle[vehid][pVehExists] && IsValidVehicle(PlayerVehicle[vehid][pVehPhysic]))
            {
                AccountData[playerid][ActivityTime] = 1;
                PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MEMPERBAIKI KENDARAAN");
                ShowProgressBar(playerid);

                ApplyAnimationEx(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 0, 0, 1);
                Inventory_Close(playerid);
                pUseItemTimer[playerid] = SetTimerEx("UsingToolkit", 1000, true, "dd", playerid, PlayerVehicle[vehid][pVehPhysic]);
                found = true;
            }
        }
        if(!found) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada kendaraan apapun disekitar!");
    }
    else if(!strcmp(itemname, "Repair Kit", true))
    {
        if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, harap tunggu!");
        if(AccountData[playerid][pFaction] != FACTION_BENGKEL) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya anggota Bengkel yang dapat menggunakan ini!");

        new vehid = -1, bool: found = false;
        if((vehid = Vehicle_Nearest(playerid)) != -1)
        {
            if(PlayerVehicle[vehid][pVehExists] && IsValidVehicle(PlayerVehicle[vehid][pVehPhysic]))
            {
                AccountData[playerid][ActivityTime] = 1;
                PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MEMPERBAIKI KENDARAAN");
                ShowProgressBar(playerid);

                ApplyAnimationEx(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 0, 0, 1);
                Inventory_Close(playerid);
                pUseItemTimer[playerid] = SetTimerEx("UsingRepairKit", 1000, true, "dd", playerid, PlayerVehicle[vehid][pVehPhysic]);
                found = true;
            }
        }
        if(!found) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada kendaraan apapun disekitar!");
    }
    else if(!strcmp(itemname, "Boombox", true))
    {
        new str[128], Float:BBCoord[4], pNames[MAX_PLAYER_NAME];
        GetPlayerPos(playerid, BBCoord[0], BBCoord[1], BBCoord[2]);
        GetPlayerFacingAngle(playerid, BBCoord[3]);
        SetPVarFloat(playerid, "BBX", BBCoord[0]);
        SetPVarFloat(playerid, "BBY", BBCoord[1]);
        SetPVarFloat(playerid, "BBZ", BBCoord[2]);
        GetPlayerName(playerid, pNames, sizeof(pNames));
        BBCoord[0] += (2 * floatsin(-BBCoord[3], degrees));
        BBCoord[1] += (2 * floatcos(-BBCoord[3], degrees));
        BBCoord[2] -= 1.0;
        if(GetPVarInt(playerid, "PlacedBB")) return SendClientMessageEx(playerid, -1, "{00ff00}[!]{ffffff}: Kamu Sudah Memasang Boombox");
        foreach(new i : Player)
        {
            if(GetPVarType(i, "PlacedBB"))
            {
                if(IsPlayerInRangeOfPoint(playerid, 30.0, GetPVarFloat(i, "BBX"), GetPVarFloat(i, "BBY"), GetPVarFloat(i, "BBZ")))
                {
                    SendClientMessageEx(playerid, COLOR_WHITE, "{00ff00}[!]{ffffff}: Tidak dapat memasang, karena terdapat boombox orang lain disini");
                    return 1;
                }
            }
        }
        SendRPMeAboveHead(playerid, "Mengeluarkan Boombox", X11_PLUM1);
        SetPVarInt(playerid, "PlacedBB", CreateDynamicObject(2103, BBCoord[0], BBCoord[1], BBCoord[2], 0.0, 0.0, 0.0, .worldid = GetPlayerVirtualWorld(playerid), .interiorid = GetPlayerInterior(playerid)));
        format(str, sizeof(str), "{ffffff}Pemilik: {ffff00}%s", pNames);
        SetPVarInt(playerid, "BBLabel", _:CreateDynamic3DTextLabel(str, COLOR_YELLOW, BBCoord[0], BBCoord[1], BBCoord[2]+0.6, 5, .worldid = GetPlayerVirtualWorld(playerid), .interiorid = GetPlayerInterior(playerid)));
        SetPVarInt(playerid, "BBArea", CreateDynamicSphere(BBCoord[0], BBCoord[1], BBCoord[2], 30.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid)));
        SetPVarInt(playerid, "BBInt", GetPlayerInterior(playerid));
        SetPVarInt(playerid, "BBVW", GetPlayerVirtualWorld(playerid));
        ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,0,0,0,0,0);
        ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,0,0,0,0,0);
        Inventory_Close(playerid);
    }
    return true;
}

CMD:asetitem(playerid, params[])
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);

	new
		item[32],
		amount;
	if (sscanf(params, "ds[32]", amount, item))
	    return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/setitem [jumlah] [nama item]");
	for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if (!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
	{
        ItemAdd(playerid, g_aInventoryItems[i][e_InventoryItem], amount);
        return SendStaffMessage(X11_ARWIN, ""RED"%s"ARWIN1" men-set item %s sejumlah %d untuk diri sendiri", AccountData[playerid][pAdminname], item, amount);
        // return SendClientMessageEx(playerid, X11_GRAY, "[AdmCmd] berhasil mengset item %s sejumlah %d", item, amount);
	}
	ShowTDN(playerid, NOTIFICATION_WARNING, "Invalid Item Name, Cek /itemlist");
    PlayerPlaySound(playerid, 5205, 0, 0, 0);
	return 1;
}

CMD:aremoveinv(playerid, params[])
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);

    new otherid, itemname[32];
    if(sscanf(params, "us[32]", otherid, itemname)) return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/aremoveinv [name/playerid] [item name]");
    if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(!PlayerHasItem(otherid, itemname)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak memiliki item tersebut!");
    
    ItemDelete(otherid, itemname, Inventory_Count(otherid, itemname));
    SendStaffMessage(X11_ARWIN, ""RED"%s"ARWIN1" Menghapus item %s dari inventory "YELLOW"%s(%d)", AccountData[playerid][pAdminname], itemname, AccountData[otherid][pName], otherid);
    SendClientMessageEx(otherid, X11_ARWIN, "[AdmCmd] "RED"%s"ARWIN1" Menghapus item %s dari inventory anda", AccountData[playerid][pAdminname], itemname, AccountData[otherid][pName], otherid);
    return 1;
}

CMD:giveitem(playerid, params[])
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);

    new otherid, itemname[32], amount;
    if(sscanf(params, "uds[32]", otherid, amount, itemname)) return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/giveitem [name/playerid] [amount] [item name]");
    if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    for(new i = 0; i < sizeof(g_aInventoryItems); i++) if (!strcmp(g_aInventoryItems[i][e_InventoryItem], itemname, true))
    {
        ItemAdd(otherid, g_aInventoryItems[i][e_InventoryItem], amount);
        SendClientMessageEx(otherid, X11_ARWIN, "[AdmCmd]"RED" %s"ARWIN1" telah memberikan anda "YELLOW"%s"ARWIN1" sejumlah "YELLOW"%d", AccountData[playerid][pAdminname], itemname, amount);
        return SendStaffMessage(X11_ARWIN, ""RED"%s"ARWIN1" memberikan "YELLOW"%s(%d)"ARWIN1" %s sejumlah %d", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, itemname, amount);
    }
	ShowTDN(playerid, NOTIFICATION_WARNING, "Invalid Item Name, Cek /itemlist");

    static shstr[125];
	format(shstr, sizeof(shstr), "Menggunakan cmd /giveitem %s(%d amount) kepada pemain %s.", itemname, amount, AccountData[otherid][pName]);
	AddAdminLog(AccountData[playerid][pName], AccountData[playerid][pUCP], GetStaffRank(playerid), shstr);
	return 1;
}

alias:giveitemall("gim")
CMD:giveitemall(playerid, params[])
{
    if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);

    new itemname[32], amounts, bool: found = false;
    if(sscanf(params, "ds[32]", amounts, itemname)) return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/giveitemall [amounts] [item name]");
    for (new i = 0; i < sizeof(g_aInventoryItems); i++)
    {
        if(!strcmp(g_aInventoryItems[i][e_InventoryItem], itemname, true))
        {
            foreach(new player : Player) if (IsPlayerConnected(player) && SQL_IsCharacterLogged(player))
            {
                ItemAdd(player, g_aInventoryItems[i][e_InventoryItem], amounts);
                ShowItemBox(player, g_aInventoryItems[i][e_InventoryItem], sprintf("Received_%dx", amounts), 2);
            }
            SendClientMessageToAllEx(X11_ARWIN, "[AdmCmd]"RED" %s"ARWIN1" Memberikan "YELLOW"%s"ARWIN1" sejumlah "YELLOW"%d"ARWIN1" kepada seluruh pemain online", AccountData[playerid][pAdminname], g_aInventoryItems[i][e_InventoryItem], amounts);
            found = true;
        }
    }
    if(!found) ShowTDN(playerid, NOTIFICATION_WARNING, "Item tidak ditemukan, gunakan '/itemlist'");

    static shstr[125];
	format(shstr, sizeof(shstr), "Menggunakan cmd /giveitemall %s(%d) kepada seluruh pemain online.", itemname, amounts);
	AddAdminLog(AccountData[playerid][pName], AccountData[playerid][pUCP], GetStaffRank(playerid), shstr);
    return 1;
}

CMD:setitem(playerid, params[])
{
    new 
        userid,
        item[32],
        amount;
    
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    
    if(sscanf(params,"uds[32]", userid, amount, item))
        return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/setitem [playerid/Name] [jumlah] [nama item]");

    for(new i = 0; i < sizeof(g_aInventoryItems); i ++) if (!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
    {
        //Inventory_Set(userid, g_aInventoryItems[i][e_InventoryItem], g_aInventoryItems[i][e_InventoryModel], amount);

        SendClientMessageEx(userid, X11_ARWIN, "[AdmCmd]"RED" %s"ARWIN1" memberikan anda %s sejumlah %d", AccountData[playerid][pAdminname], item, amount);
        return SendStaffMessage(X11_ARWIN, ""RED"%s"ARWIN1" memberikan "YELLOW"%s(%d)"ARWIN1" %s sejumlah %d", AccountData[playerid][pAdminname], AccountData[userid][pName], userid, item, amount);
    }
    ShowTDN(playerid, NOTIFICATION_WARNING, "Invalid item name~n~gunakan ~y~'/itemlist'~w~ untuk melihat list");
   
    static shstr[125];
	format(shstr, sizeof(shstr), "Menggunakan cmd /setitem %s(%d amount) kepada pemain %s.", item, amount, AccountData[userid][pName]);
	AddAdminLog(AccountData[playerid][pName], AccountData[playerid][pUCP], GetStaffRank(playerid), shstr);
	return 1;
}

CMD:clearitems(playerid, params[])
{
    if(!SQL_IsCharacterLogged(playerid))
        return 0;
    
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);

    new otherid;
    if(sscanf(params, "u", otherid)) return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/clearitems [name/playerid]");
    if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    Inventory_Clear(otherid);
    SendClientMessageEx(otherid, X11_ARWIN, "[AdmCmd] Admin "RED"%s "ARWIN1"telah menghapus barang barang di inventory anda.", GetAdminName(playerid));
    SendStaffMessage(X11_ARWIN, ""RED"%s"ARWIN1" telah menghapus barang inventory milik "YELLOW"%s(%d).", GetAdminName(playerid), GetRPName(otherid), otherid);
    return 1;
}

CMD:itemlist(playerid, params[])
{
    if(AccountData[playerid][pAdmin] < 1 && AccountData[playerid][pTheStars] < 1) return PermissionError(playerid);

    new
        string[1024];

    if (!strlen(string)) {
        for (new i = 0; i < sizeof(g_aInventoryItems); i ++) {
            format(string, sizeof(string), "%s%s\n", string, g_aInventoryItems[i][e_InventoryItem]);
        }
    }
    return ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Nama Barang", string, "Select", "Cancel");
}

function LoadInventory(playerid)
{
	new cname[64];
	
    new rows = cache_num_rows();

    for (new i = 0; i < rows && i < MAX_INVENTORY; i ++) 
	{
		InventoryData[playerid][i][invExists] = true;
        cache_get_value_name_int(i, "invID", InventoryData[playerid][i][invID]);
		cache_get_value_name_int(i, "invQuantity", InventoryData[playerid][i][invQuantity]);

		cache_get_value_name(i, "invItem",  cname, sizeof(cname));
		strpack(InventoryData[playerid][i][invItem], cname, 32 char);

		for (new id = 0; id < sizeof(g_aInventoryItems); id ++) if(!strcmp(g_aInventoryItems[id][e_InventoryItem], InventoryData[playerid][i][invItem], true))
		{
			InventoryData[playerid][i][invModel] = g_aInventoryItems[id][e_InventoryModel];
		}
	}

	printf("[Player Inventory] Jumlah total item inventory yang dimuat untuk %s [DBID: %d]: %d.", AccountData[playerid][pName], AccountData[playerid][pID], rows);
    return 1;
}


forward OpeningBackpack(playerid);
public OpeningBackpack(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(AccountData[playerid][pOpenBackpackTimer]);
        AccountData[playerid][pOpenBackpackTimer] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if(IsPlayerInjured(playerid))
    {
        KillTimer(AccountData[playerid][pOpenBackpackTimer]);
        AccountData[playerid][pOpenBackpackTimer] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang pingsan!");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 115)
    {
        KillTimer(AccountData[playerid][pOpenBackpackTimer]);
        AccountData[playerid][pOpenBackpackTimer] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
        {
            ClearAnimations(playerid, 1);
            StopLoopingAnim(playerid);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        }

        ItemDelete(playerid, "Backpack");
        ItemAdd(playerid, "Smartphone", 1);
        ItemAdd(playerid, "Nasi Goreng", 10);
        ItemAdd(playerid, "Es Teh", 10);
        ShowItemBox(playerid, "Smartphone", "Received_1x", 2);
        ShowItemBox(playerid, "Nasi Goreng", "Received_10x", 2);
        ShowItemBox(playerid, "Es Teh", "Received_10x", 2);
        ShowItemBox(playerid, "Backpack", "Removed_1x", 2);
    }
    else 
    {
        AccountData[playerid][ActivityTime] += 23;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/115;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward UseUranium(playerid);
public UseUranium(playerid)
{
    if(!IsPlayerConnected(playerid))
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);
		return 0;
	}

	if(AccountData[playerid][pInjured])
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

		ClearAnimations(playerid, 1);
		StopLoopingAnim(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		return 0;
	}

	if(AccountData[playerid][ActivityTime] >= 5)
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

		if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
        {
            ClearAnimations(playerid, 1);
            StopLoopingAnim(playerid);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        }

        static Float:health;
        GetPlayerHealth(playerid, health);
        health += 40;
        if(health > 100)
        {
            health = 100.0;
        }

        SetPlayerHealthEx(playerid, health);
        AccountData[playerid][pHunger] += 50;
        AccountData[playerid][pThirst] += 50;
        ItemDelete(playerid, "Uranium");
        ShowItemBox(playerid, "Uranium", "Removed_1x", 2);
	}
	else
	{
		AccountData[playerid][ActivityTime] ++;

		new Float: progressvalue;
		progressvalue = AccountData[playerid][ActivityTime] * 67/5;
		PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
		PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
		return 0;
	}
	return 1;
}

forward UseMarijuana(playerid);
public UseMarijuana(playerid)
{
	if(!IsPlayerConnected(playerid))
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);
		return 0;
	}

	if(AccountData[playerid][pInjured])
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

		ClearAnimations(playerid, 1);
		StopLoopingAnim(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		return 0;
	}

	if(AccountData[playerid][ActivityTime] >= 5)
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

		if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
        {
            ClearAnimations(playerid, 1);
            StopLoopingAnim(playerid);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        }

		ItemDelete(playerid, "Marijuana");
        ShowItemBox(playerid, "Marijuana", "Removed_1x", 2);
		AccountData[playerid][pStress] -= 25;
        TextDrawHideForPlayer(playerid, StressPurple[0]);
	}
	else
	{
		AccountData[playerid][ActivityTime] ++;

		new Float: progressvalue;
		progressvalue = AccountData[playerid][ActivityTime] * 67/5;
		PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
		PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
		return 0;
	}
	return 1;
}

forward UseBandage(playerid);
public UseBandage(playerid)
{
	if(!IsPlayerConnected(playerid))
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);
		return 0;
	}

	if(AccountData[playerid][pInjured])
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

		ClearAnimations(playerid, 1);
		StopLoopingAnim(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		return 0;
	}

	if(AccountData[playerid][ActivityTime] >= 8)
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

        if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
        {
            ClearAnimations(playerid, 1);
            StopLoopingAnim(playerid);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        }

		new Float: health;
		GetPlayerHealth(playerid, health);
        health += 20;
        if(health > 100.0)
        {
            health = 100.0;
        }
        SetPlayerHealthEx(playerid, health);

		ItemDelete(playerid, "Bandage", 1);
        ShowItemBox(playerid, "Bandage", "Removed_1x", 2);
	}
	else
	{
		AccountData[playerid][ActivityTime] ++;

		new Float: progressvalue;
		progressvalue = AccountData[playerid][ActivityTime] * 67/8;
		PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
		PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
		return 0;
	}
	return 1;
}

forward EatingProgress(playerid);
public EatingProgress(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pUseItemTimer[playerid]);
        pUseItemTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }
    if(AccountData[playerid][pInjured])
    {
        KillTimer(pUseItemTimer[playerid]);
        pUseItemTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
		RemovePlayerAttachedObject(playerid, 9);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya saat ini!");
        return 0;
    }
    if(AccountData[playerid][ActivityTime] >= 5)
    {
        KillTimer(pUseItemTimer[playerid]);
        pUseItemTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
        {
            ClearAnimations(playerid, 1);
            StopLoopingAnim(playerid);
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        }
        RemovePlayerAttachedObject(playerid, 9);
    }
    else 
    {
        AccountData[playerid][ActivityTime] ++;

        static Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/5;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward UsingRepairKit(playerid, vehicleid);
public UsingRepairKit(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid))
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);
		return 0;
	}

	if(vehicleid == INVALID_VEHICLE_ID)
	{
		ShowTDN(playerid, NOTIFICATION_ERROR, "Anda terlalu jauh dari kendaraan!");
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

		ClearAnimations(playerid, 1);
		StopLoopingAnim(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		return 0;
	}

	if(AccountData[playerid][pInjured])
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

		ClearAnimations(playerid, 1);
		StopLoopingAnim(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		return 0;
	}

	if(AccountData[playerid][ActivityTime] >= 10)
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

		ClearAnimations(playerid, 1);
		StopLoopingAnim(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        new index = Vehicle_ReturnID(vehicleid);

        ValidRepairVehicle(vehicleid);
        if(PlayerVehicle[index][pVehEngineUpgrade] == 1)
        {
            SetValidVehicleHealth(vehicleid, 2000);
        }
        else if(PlayerVehicle[index][pVehEngineUpgrade] == 0)
        {
            SetValidVehicleHealth(vehicleid, 1000);
        }

        if(PlayerVehicle[index][pVehBodyUpgrade] == 3)
        {
            PlayerVehicle[index][pVehBodyRepair] = 1000.0;
        }

        ItemDelete(playerid, "Repair Kit");
        ShowItemBox(playerid, "Repair Kit", "Removed_1x", 2);
	}
	else
	{
		AccountData[playerid][ActivityTime] ++;

		new Float: progressvalue;
		progressvalue = AccountData[playerid][ActivityTime] * 67/10;
		PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
		PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
		return 0;
	}
	return 1;
}

forward UsingToolkit(playerid, vehicleid);
public UsingToolkit(playerid, vehicleid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pUseItemTimer[playerid]);
        pUseItemTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if(vehicleid == INVALID_VEHICLE_ID)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda telalu jauh dari kendaraan!");
        KillTimer(pUseItemTimer[playerid]);
        pUseItemTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang pingsan!");
        KillTimer(pUseItemTimer[playerid]);
        pUseItemTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 130)
    {
        KillTimer(pUseItemTimer[playerid]);
        pUseItemTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        
        SetValidVehicleHealth(vehicleid, 1000);
        ItemDelete(playerid, "Tools Kit");
        ShowItemBox(playerid, "Tools Kit", "Removed_1x", 2);
    }
    else 
    {
        AccountData[playerid][ActivityTime] += 16.25;

        static Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/130;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward UseKevlar(playerid);
public UseKevlar(playerid)
{
	if(!IsPlayerConnected(playerid))
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);
		return 0;
	}

	if(AccountData[playerid][pInjured])
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

		ClearAnimations(playerid, 1);
		StopLoopingAnim(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		return 0;
	}

	if(AccountData[playerid][ActivityTime] >= 3)
	{
		KillTimer(pUseItemTimer[playerid]);
		pUseItemTimer[playerid] = -1;
		AccountData[playerid][ActivityTime] = 0;
		HideProgressBar(playerid);

		if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
        {
            ClearAnimations(playerid, 1);
            StopLoopingAnim(playerid);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        }

		new Float: Armour;
		GetPlayerArmour(playerid, Armour);
        Armour += 99.0;
        if(Armour >= 99.0)
        {
            Armour = 99.0;
        }
        SetPlayerArmourEx(playerid, Armour);
		ItemDelete(playerid, "Kevlar");
        ShowItemBox(playerid, "Kevlar", "Removed_1x", 2);
	}
	else
	{
		AccountData[playerid][ActivityTime] ++;

		new Float: progressvalue;
		progressvalue = AccountData[playerid][ActivityTime] * 67/3;
		PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
		PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
		return 0;
	}
	return 1;
}

hook OnPlayerConnect(playerid)
{
    pUseItemTimer[playerid] = -1;
    AccountData[playerid][pOpenBackpackTimer] = -1;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(pUseItemTimer[playerid]);
    KillTimer(AccountData[playerid][pOpenBackpackTimer]);
    AccountData[playerid][pOpenBackpackTimer] = -1;
    pUseItemTimer[playerid] = -1;
    return 1;
}

/*public Float:GetInventoryWeight(item[], quantity)
{
    static Float:totalweight;
    if(!strcmp(item, "Nasi Goreng"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Kopi Kenangan"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Batu Kotor"))
    {
        totalweight = quantity*0.030;
    }
    else if(!strcmp(item, "Nasi Uduk"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Kanabis"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Batu Bersih"))
    {
        totalweight = quantity*0.030;
    }
    else if(!strcmp(item, "Air Mineral"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Besi"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Tembaga"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Berlian"))
    {
        totalweight = quantity*0.25;
    }
    else if(!strcmp(item, "Emas"))
    {
        totalweight = quantity*0.10;
    }
    else if(!strcmp(item, "Smartphone"))
    {
        totalweight = quantity*0.25;
    }
    else if(!strcmp(item, "Radio"))
    {
        totalweight = quantity*0.15;
    }
    else if(!strcmp(item, "Kayu"))
    {
        totalweight = quantity*0.06;
    }
    else if(!strcmp(item, "Kayu Potongan"))
    {
        totalweight = quantity*0.05;
    }
    else if(!strcmp(item, "Kayu Kemas"))
    {
        totalweight = quantity*0.08;
    }
    else if(!strcmp(item, "Marijuana"))
    {
        totalweight = quantity*0.02;
    }
    else if(!strcmp(item, "Benang"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Kain"))
    {
        totalweight = quantity*0.04;
    }
    else if(!strcmp(item, "Pakaian"))
    {
        totalweight = quantity*0.04;
    }
    else if(!strcmp(item, "Bandage"))
    {
        totalweight = quantity*0.02;
    }
    else if(!strcmp(item, "Medkit"))
    {
        totalweight = quantity*0.05;
    }
    else if(!strcmp(item, "Alprazolam"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Ayam Hidup"))
    {
        totalweight = quantity*0.15;
    }
    else if(!strcmp(item, "Ayam Potong"))
    {
        totalweight = quantity*0.10;
    }
    else if(!strcmp(item, "Ayam Kemas"))
    {
        totalweight = quantity*0.05;
    }
    else if(!strcmp(item, "Sampah Makanan"))
    {
        totalweight = quantity*0.005;
    }
    else if(!strcmp(item, "Kevlar"))
    {
        totalweight = quantity*0.90;
    }
    else if(!strcmp(item, "Botol"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Petrol"))
    {
        totalweight = quantity*0.50;
    }
    else if(!strcmp(item, "Pure Oil"))
    {
        totalweight = quantity*0.50;
    }
    else if(!strcmp(item, "GAS"))
    {
        totalweight = quantity*0.60;
    }
    else if(!strcmp(item, "Ikan"))
    {
        totalweight = quantity*0.02;
    }
    else if(!strcmp(item, "Rokok"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Pancingan"))
    {
        totalweight = quantity*0.08;
    }
    else if(!strcmp(item, "Umpan"))
    {
        totalweight = quantity*0.02;
    }
    else if(!strcmp(item, "Hiu"))
    {
        totalweight = quantity*0.90;
    }
    else if(!strcmp(item, "Penyu"))
    {
        totalweight = quantity*0.80;
    }
    else if(!strcmp(item, "Ikan Tawar"))
    {
        totalweight = quantity*0.03;
    }
    else if(!strcmp(item, "Jerigen"))
    {
        totalweight = quantity*0.25;
    }
    else if(!strcmp(item, "Tools Kit"))
    {
        totalweight = quantity*0.30;
    }
    else if(!strcmp(item, "Repair Kit"))
    {
        totalweight = quantity*0.35;
    }
    else if(!strcmp(item, "Linggis"))
    {
        totalweight = quantity*0.05;
    }
    else if(!strcmp(item, "Kunci T"))
    {
        totalweight = quantity*0.05;
    }
    else if(!strcmp(item, "Nasi Pecel"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Bubur Pedas"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Es Teh"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Jus Apel"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Boombox"))
    {
        totalweight = quantity*0.20;
    }
    else if(!strcmp(item, "Kebab A5"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Bakso"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Choco Matcha"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Teh Jeruk"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Susu Murni"))
    {
        totalweight = quantity*0.02;
    }
    else if(!strcmp(item, "Susu Olahan"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Susu Fresh"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Cabe"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Padi"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Garam Kristal"))
    {
        totalweight = quantity*0.006;
    }
    else if(!strcmp(item, "Tebu"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Beras"))
    {
        totalweight = quantity*0.04;
    }
    else if(!strcmp(item, "Sambal"))
    {
        totalweight = quantity*0.02;
    }
    else if(!strcmp(item, "Gula"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Garam"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Daging"))
    {
        totalweight = quantity*0.02;
    }
    else if(!strcmp(item, "Tanduk"))
    {
        totalweight = quantity*0.03;
    }
    else if(!strcmp(item, "Kulit"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Bulu"))
    {
        totalweight = quantity*0.01;
    }
    else if(!strcmp(item, "Boxmats"))
    {
        totalweight = quantity*0.04;
    }
    else if(!strcmp(item, "Baja"))
    {
        totalweight = quantity*0.05;
    }
    else if(!strcmp(item, "Material"))
    {
        totalweight = quantity*0.025;
    }
    else if(!strcmp(item, "Kaca"))
    {
        totalweight = quantity*0.015;
    }
    else if(!strcmp(item, "Karet"))
    {
        totalweight = quantity*0.006;
    }
    else if(!strcmp(item, "Plastik"))
    {
        totalweight = quantity*0.005;
    }
    else if(!strcmp(item, "Alumunium"))
    {
        totalweight = quantity*0.010;
    }
    else if(!strcmp(item, "Backpack"))
    {
        totalweight = quantity*0.50;
    }
    else if(!strcmp(item, "Masker"))
    {
        totalweight = quantity*0.005;
    }
    else if(!strcmp(item, "Plat Besi"))
    {
        totalweight = quantity*0.025;
    }
    else if(!strcmp(item, "Korek Api"))
    {
        totalweight = quantity*0.010;
    }
    else if(!strcmp(item, "Bibit Tebu"))
    {
        totalweight = quantity*0.015;
    }
    else if(!strcmp(item, "Bibit Padi"))
    {
        totalweight = quantity*0.015;
    }
    else if(!strcmp(item, "Bibit Cabe"))
    {
        totalweight = quantity*0.015;
    }
    else if(!strcmp(item, "Petasan"))
    {
        totalweight = quantity*0.010;
    }
    else if(!strcmp(item, "KTA"))
    {
        totalweight = quantity*0.005;
    }
    else if(!strcmp(item, "Tahu Bulat"))
    {
        totalweight = quantity*0.005;
    }
    else if(!strcmp(item, "Pilox"))
    {
        totalweight = quantity*0.005;
    }
    else if(!strcmp(item, "Uranium ACD"))
    {
        totalweight = quantity*0.020;
    }
    else if(!strcmp(item, "Uranium"))
    {
        totalweight = quantity*0.010;
    }
    else if(!strcmp(item, "Senter"))
    {
        totalweight = quantity*0.006;
    }
    return totalweight;
}

stock Inventory_Remove(playerid, const item[], quantity = 1)
{
	new
		itemid = Inventory_GetItemID(playerid, item);

	if (itemid != -1)
	{
	    if (InventoryData[playerid][itemid][invQuantity] > 0)
	    {
            CallLocalFunction("KuranginBerat", "isd", playerid, item, quantity);
	        InventoryData[playerid][itemid][invQuantity] -= quantity;
		}
		if (quantity == -1 || InventoryData[playerid][itemid][invQuantity] < 1)
		{
		    InventoryData[playerid][itemid][invExists] = false;
		    InventoryData[playerid][itemid][invModel] = 0;
		    InventoryData[playerid][itemid][invQuantity] = 0;
	        mysql_tquery(dcrp_query, sprintf("DELETE FROM `inventory` WHERE `ID` = '%d' AND `invID` = '%d'", AccountData[playerid][pID], InventoryData[playerid][itemid][invID]));
		}
		else if (quantity != -1 && InventoryData[playerid][itemid][invQuantity] > 0)
		{
            mysql_tquery(dcrp_query, sprintf("UPDATE `inventory` SET `invQuantity` = `invQuantity` - %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, AccountData[playerid][pID], InventoryData[playerid][itemid][invID]));
		}
		return 1;
	}
	return 0;
}
FUNC::TambahkanBerat(playerid, item[], quantity)
{
    if(AccountData[playerid][pBeratItem] >= 50) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh"), Inventory_Close(playerid);

    AccountData[playerid][pBeratItem] += GetItemKG(item, quantity);
    return 1;
}

FUNC::KuranginBerat(playerid, item[], quantity)
{
    AccountData[playerid][pBeratItem] -= GetItemKG(item, quantity);
    return 1;
}

stock Inventory_Add(playerid, const item[], model, quantity = 1)
{
	new
		itemid = Inventory_GetItemID(playerid, item);

	if (itemid == -1)
	{
	    itemid = Inventory_GetFreeID(playerid);

	    if (itemid != -1)
	    {
            CallLocalFunction("TambahkanBerat", "isd", playerid, item, quantity);
	        InventoryData[playerid][itemid][invExists] = true;
	        InventoryData[playerid][itemid][invModel] = model;
	        InventoryData[playerid][itemid][invQuantity] = quantity;

	        strpack(InventoryData[playerid][itemid][invItem], item, 32 char);

            mysql_tquery(dcrp_query, sprintf("INSERT INTO `inventory` (`ID`, `invItem`, `invModel`, `invQuantity`) VALUES('%d', '%s', '%d', '%d')", AccountData[playerid][pID], item, model, quantity),"OnInventoryAdd", "dd", playerid, itemid);
	        return itemid;
		}
		return -1;
	}
	else
	{
        if(GetTotalWeightFloat(playerid) > 50) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh!"), Inventory_Close(playerid);
        
        if(!strcmp(item, "Nasi Goreng"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Kopi Kenangan"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Batu Kotor"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.030;
        }
        else if(!strcmp(item, "Nasi Uduk"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Kanabis"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Batu Bersih"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.030;
        }
        else if(!strcmp(item, "Air Mineral"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Besi"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Tembaga"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Berlian"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.25;
        }
        else if(!strcmp(item, "Emas"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.10;
        }
        else if(!strcmp(item, "Smartphone"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.25;
        }
        else if(!strcmp(item, "Radio"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.15;
        }
        else if(!strcmp(item, "Kayu"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.06;
        }
        else if(!strcmp(item, "Kayu Potongan"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.05;
        }
        else if(!strcmp(item, "Kayu Kemas"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.08;
        }
        else if(!strcmp(item, "Marijuana"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.02;
        }
        else if(!strcmp(item, "Benang"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Kain"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.04;
        }
        else if(!strcmp(item, "Pakaian"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.04;
        }
        else if(!strcmp(item, "Bandage"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.02;
        }
        else if(!strcmp(item, "Medkit"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.05;
        }
        else if(!strcmp(item, "Alprazolam"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Ayam Hidup"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.15;
        }
        else if(!strcmp(item, "Ayam Potong"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.10;
        }
        else if(!strcmp(item, "Ayam Kemas"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.05;
        }
        else if(!strcmp(item, "Sampah Makanan"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.005;
        }
        else if(!strcmp(item, "Kevlar"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.90;
        }
        else if(!strcmp(item, "Botol"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Petrol"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.50;
        }
        else if(!strcmp(item, "Pure Oil"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.50;
        }
        else if(!strcmp(item, "GAS"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.60;
        }
        else if(!strcmp(item, "Ikan"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.02;
        }
        else if(!strcmp(item, "Rokok"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Pancingan"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.08;
        }
        else if(!strcmp(item, "Umpan"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.02;
        }
        else if(!strcmp(item, "Hiu"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.90;
        }
        else if(!strcmp(item, "Penyu"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.80;
        }
        else if(!strcmp(item, "Ikan Tawar"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.03;
        }
        else if(!strcmp(item, "Jerigen"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.25;
        }
        else if(!strcmp(item, "Tools Kit"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.30;
        }
        else if(!strcmp(item, "Repair Kit"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.35;
        }
        else if(!strcmp(item, "Linggis"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.05;
        }
        else if(!strcmp(item, "Kunci T"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.05;
        }
        else if(!strcmp(item, "Nasi Pecel"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Bubur Pedas"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Es Teh"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Jus Apel"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Boombox"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.20;
        }
        else if(!strcmp(item, "Kebab A5"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Bakso"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Choco Matcha"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Teh Jeruk"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Susu Murni"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.02;
        }
        else if(!strcmp(item, "Susu Olahan"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Susu Fresh"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Cabe"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Padi"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Garam Kristal"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.006;
        }
        else if(!strcmp(item, "Tebu"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Beras"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.04;
        }
        else if(!strcmp(item, "Sambal"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.02;
        }
        else if(!strcmp(item, "Gula"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Garam"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Daging"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.02;
        }
        else if(!strcmp(item, "Tanduk"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.03;
        }
        else if(!strcmp(item, "Kulit"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Bulu"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.01;
        }
        else if(!strcmp(item, "Boxmats"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.04;
        }
        else if(!strcmp(item, "Baja"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.05;
        }
        else if(!strcmp(item, "Material"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.025;
        }
        else if(!strcmp(item, "Kaca"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.015;
        }
        else if(!strcmp(item, "Karet"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.006;
        }
        else if(!strcmp(item, "Plastik"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.005;
        }
        else if(!strcmp(item, "Alumunium"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.010;
        }
        else if(!strcmp(item, "Backpack"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.50;
        }
        else if(!strcmp(item, "Masker"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.005;
        }
        else if(!strcmp(item, "Plat Besi"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.025;
        }
        else if(!strcmp(item, "Korek Api"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.010;
        }
        else if(!strcmp(item, "Bibit Tebu"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.015;
        }
        else if(!strcmp(item, "Bibit Padi"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.015;
        }
        else if(!strcmp(item, "Bibit Cabe"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.015;
        }
        else if(!strcmp(item, "Petasan"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.010;
        }
        else if(!strcmp(item, "KTA"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.005;
        }
        else if(!strcmp(item, "Tahu Bulat"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.005;
        }
        else if(!strcmp(item, "Pilox"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.005;
        }
        else if(!strcmp(item, "Uranium ACD"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.020;
        }
        else if(!strcmp(item, "Uranium"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.010;
        }
        else if(!strcmp(item, "Senter"))
        {
            AccountData[playerid][pBeratItem] += quantity*0.006;
        }
	    InventoryData[playerid][itemid][invQuantity] += quantity;
        mysql_tquery(dcrp_query, sprintf("UPDATE player_characters SET Char_BackpackWeight = '%.3f' WHERE pID = '%d'", AccountData[playerid][pBeratItem], AccountData[playerid][pID]));

	    mysql_tquery(dcrp_query, sprintf("UPDATE `inventory` SET `invQuantity` = `invQuantity` + %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, AccountData[playerid][pID], InventoryData[playerid][itemid][invID]));
    }
	return itemid;
}*/