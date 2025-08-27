//function
function OnPlayerGiveInvItem(p1, p2, itemid, name[], value)
{
	if(Inventory_Count(p1, name) < value)
		return ErrorMsg(p1, "Anda tidak memiliki cukup Items");
	
	Inventory_Remove(p1, name, value);
	Inventory_Add(p2, name, InventoryData[p1][itemid][invModel], value);
	ShowItemBox(p2, name, sprintf("RECEIVED_%dx", value), InventoryData[p1][itemid][invModel], 4);
	ShowItemBox(p1, name, sprintf("REMOVED_%dx", value), InventoryData[p1][itemid][invModel], 4);
	return 1;
}
function OnInventoryAdd(playerid, itemid)
{
    InventoryData[playerid][itemid][invID] = cache_insert_id();
    return 1;
}

function OnDroppedItem(itemid)
{
    if(itemid == -1 || !DroppedItems[itemid][droppedModel])
        return 0;

    DroppedItems[itemid][droppedID] = cache_insert_id();
    return 1;
}

function LoadInventory(playerid)
{
	new rows = cache_num_rows();

    for (new i = 0; i < rows && i < MAX_INVENTORY; i ++) {
        InventoryData[playerid][i][invExists] = true;
        cache_get_value_name_int(i, "invID", InventoryData[playerid][i][invID]);
        cache_get_value_name_int(i, "invModel", InventoryData[playerid][i][invModel]);
        cache_get_value_name_int(i, "invSlot", InventoryData[playerid][i][invSlot]);
        cache_get_value_name_int(i, "invQuantity", InventoryData[playerid][i][invQuantity]);
        cache_get_value_name(i, "invItem", InventoryData[playerid][i][invItem], 64);
        for (new id = 0; id < sizeof(g_aInventoryItems); id ++) if(!strcmp(g_aInventoryItems[id][e_InventoryItem], InventoryData[playerid][i][invItem], true))
		{
			pData[playerid][pWeight] += float(InventoryData[playerid][i][invQuantity])*g_aInventoryItems[id][e_InventoryWeight];
		}
    }
    return 1;
}

function ShowInventoryFrisk(playerid, targetid) {
    if (!IsPlayerConnected(playerid))
        return 0;

    new
    items[MAX_INVENTORY],
        amounts[MAX_INVENTORY],
        str[512],
        string[352],
        lstr[1024],
        weaponid,
        ammo,
        count = 0;

    format(str, sizeof(str), "Name\tAmmount\n");
    format(str, sizeof(str), "%s\nMoney\t%s", str, FormatMoney(pData[targetid][pMoney]));
    if(pData[targetid][pIDCardTime] > 0)
	{
		format(lstr, sizeof(lstr), "%sID-Card\t%s", lstr, ReturnTimelapse(gettime(), pData[targetid][pIDCardTime]));
	}
	if(pData[targetid][pDriveLicTime] > 0)
	{
		format(lstr, sizeof(lstr), "%s\nDrive-Lic\t%s", lstr, ReturnTimelapse(gettime(), pData[targetid][pDriveLicTime]));
	}
	if(pData[targetid][pWeapLicTime] > 0)
	{
		format(lstr, sizeof(lstr), "%s\nWeapon-Lic\t%s", lstr, ReturnTimelapse(gettime(), pData[targetid][pWeapLicTime]));
	}
	if(pData[targetid][pLumberLicTime] > 0)
	{
		format(lstr, sizeof(lstr), "%s\nLumber-Lic\t%s", lstr, ReturnTimelapse(gettime(), pData[targetid][pLumberLicTime]));
	}
	if(pData[targetid][pTruckLicTime] > 0)
	{
		format(lstr, sizeof(lstr), "%s\nTruck-Lic\t%s", lstr, ReturnTimelapse(gettime(), pData[targetid][pTruckLicTime]));
	}
	if(pData[targetid][pFood] > 0)
	{
		format(lstr, sizeof(lstr), "%s\nFood\t%d", lstr, pData[targetid][pFood]);
	}
	if(pData[targetid][pSeed] > 0)
	{
		format(lstr, sizeof(lstr), "%s\n[Farmer]Seed\t%d", lstr, pData[targetid][pSeed]);
	}
	if(pData[targetid][pPotato] > 0)
	{
		format(lstr, sizeof(lstr), "%s\n[Farmer]Potato\t%d kg", lstr, pData[targetid][pPotato]);
	}
	if(pData[targetid][pWheat] > 0)
	{
		format(lstr, sizeof(lstr), "%s\n[Farmer]Wheat\t%d kg", lstr, pData[targetid][pWheat]);
	}
	if(pData[targetid][pOrange] > 0)
	{
		format(lstr, sizeof(lstr), "%s\n[Farmer]Orange\t%d kg", lstr, pData[targetid][pOrange]);
	}
	if(pData[targetid][pFish] > 0)
	{
		format(lstr, sizeof(lstr), "%s\nFish\t%d kg", lstr, pData[targetid][pFish]);
	}

    for(new i = 0; i < 13; i ++)
    {
        GetPlayerWeaponData(targetid, i, weaponid, ammo);

        if(weaponid > 0)
			format(str, sizeof(str), "%s\n"RED_E"%s\t"RED_E"%d", str, ReturnWeaponName(weaponid), ammo);
    }
    forex(i, MAX_INVENTORY) {
        if (InventoryData[targetid][i][invExists]) {
            count++;
            items[i] = InventoryData[targetid][i][invModel];
            amounts[i] = InventoryData[targetid][i][invQuantity];
            strunpack(string, InventoryData[targetid][i][invItem]);
            format(str, sizeof(str), "%s\n%s\t%d", str, string, amounts[i]);
        }
    }
    new gstr[200];
    format(gstr, sizeof(gstr), "Inventory | %s", pData[targetid][pName]);
    ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, gstr, str, "Close", "");
    return 1;
}

function HideBackPackDialog(playerid)
{
    
	for(new a = 0; a < 23; a++)
	{
		if(IsValidDynamicPlayerTextDraw(playerid, txd_inventory[playerid][a]))
			PlayerTextDrawHide(playerid, txd_inventory[playerid][a]);
	}

	for(new i = 0; i < MAX_INVENTORY; i++)
	{
		if(IsValidDynamicPlayerTextDraw(playerid, itemname[playerid][i]))
			PlayerTextDrawHide(playerid, itemname[playerid][i]);
		if(IsValidDynamicPlayerTextDraw(playerid, indexinv[playerid][i]))
			PlayerTextDrawHide(playerid, indexinv[playerid][i]);
		if(IsValidDynamicPlayerTextDraw(playerid, modelinv[playerid][i]))
			PlayerTextDrawHide(playerid, modelinv[playerid][i]);
		if(IsValidDynamicPlayerTextDraw(playerid, itemamountname[playerid][i]))
			PlayerTextDrawHide(playerid, itemamountname[playerid][i]);
	}

	ShowHunger(playerid);
	ShowLogo(playerid);

    SelectInventory[playerid] = -1;
	AmmountInventory[playerid] = -1;
	InventoryOpen[playerid] = false;
    CancelSelectTextDraw(playerid);
    return 1;
}

//DropItem Calback
function Dropped_Load()
{
	static
        rows;
    rows = cache_num_rows();
    for (new i = 0; i < rows; i ++) if(i < MAX_DROPPED_ITEMS)
    {
        cache_get_value_name_int(i, "ID", DroppedItems[i][droppedID]);

        cache_get_value_name(i, "itemName", DroppedItems[i][droppedItem], 32);
        cache_get_value_name(i, "itemPlayer", DroppedItems[i][droppedPlayer], 24);

        cache_get_value_name_int(i, "itemModel", DroppedItems[i][droppedModel]);
        cache_get_value_name_int(i, "itemQuantity", DroppedItems[i][droppedQuantity]);
        cache_get_value_name_int(i, "itemAmmo", DroppedItems[i][droppedAmmo]);
        cache_get_value_name_int(i, "itemWeapon", DroppedItems[i][droppedWeapon]);
        cache_get_value_name_float(i, "itemX", DroppedItems[i][droppedPos][0]);
        cache_get_value_name_float(i, "itemY", DroppedItems[i][droppedPos][1]);
        cache_get_value_name_float(i, "itemZ", DroppedItems[i][droppedPos][2]);
        cache_get_value_name_int(i, "itemInt", DroppedItems[i][droppedInt]);
        cache_get_value_name_int(i, "itemWorld", DroppedItems[i][droppedWorld]);
        cache_get_value_name_int(i, "itemTime", DroppedItems[i][droppedTime]);

        if(IsWeaponModel(DroppedItems[i][droppedModel])) 
        {
            DroppedItems[i][droppedObject] = CreateDynamicObject(DroppedItems[i][droppedModel], DroppedItems[i][droppedPos][0], DroppedItems[i][droppedPos][1], DroppedItems[i][droppedPos][2], 93.7, 120.0, 120.0, DroppedItems[i][droppedWorld], DroppedItems[i][droppedInt]);
        } 
        else 
        {
            DroppedItems[i][droppedObject] = CreateDynamicObject(DroppedItems[i][droppedModel], DroppedItems[i][droppedPos][0], DroppedItems[i][droppedPos][1], DroppedItems[i][droppedPos][2], 0.0, 0.0, 0.0, DroppedItems[i][droppedWorld], DroppedItems[i][droppedInt]);
        }
        new str[200];
        format(str, sizeof(str), "{FFFF00}/pickup\n{FFFFFF}%s", DroppedItems[i][droppedItem]);
        DroppedItems[i][droppedText3D] = CreateDynamic3DTextLabel(str, -1, DroppedItems[i][droppedPos][0], DroppedItems[i][droppedPos][1], DroppedItems[i][droppedPos][2], 2.5, _, _, _, DroppedItems[i][droppedWorld],DroppedItems[i][droppedInt]);
    }
    printf("[DATABASE] Dropped Item(s) berhasil dimuat sebanyak: %d", rows);
	return 1;
}

function OnPlayerUseInvItem(playerid, itemid, const string:name[])
{
	if(!Inventory_HasItem(playerid, name))
	{
		SelectInventory[playerid] = -1;
		return ErrorMsg(playerid, "Anda tidak memiliki Items yang di pilih");
	}
	if(!strcmp(name, "Snack"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Makan Snack <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Eating...", 4);
        SetTimerEx("makansnack", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Red Money"))
	{
		return ErrorMsg(playerid, "Anda tidak dapat menggunakan Items ini");
	}
	else if(!strcmp(name, "Pizza Stack"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Makan Pizza <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Eating...", 4);
        SetTimerEx("makanpizza", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Ephedrine"))
	{
		if(pData[playerid][pStress] <= 10)
			return ErrorMsg(playerid, "Saat ini status anda sudah tidak Stress");
		pData[playerid][pStress] -= 30;
		Inventory_Remove(playerid, "Ephedrine", 1);
		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",2.1,0,0,0,0,0);
		SetPlayerChatBubble(playerid, "> Makan Obat <", COLOR_PURPLE, 10.0, 4000 );
		HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Water"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Minum Water <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Drinking...", 4);
        SetTimerEx("minumwater", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Sprunk"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Minum Sprunk <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Drinking...", 4);
        SetTimerEx("minumsprunk", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Jus Jeruk"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Minum Jus Jeruk <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Drinking...", 4);
        SetTimerEx("minumjusjeruk", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Nasi Goreng"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Makan Nasi Goreng <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Eating...", 4);
        SetTimerEx("makannasgor", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);		
	}
	else if(!strcmp(name, "Milk"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Minum Milk <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Drinking...", 4);
        SetTimerEx("minummilk", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Steak"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Makan Steak <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Eating...", 4);
        SetTimerEx("makansteak", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);		
	}
	else if(!strcmp(name, "Roti"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Makan Roti <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Eating...", 4);
        SetTimerEx("makanroti", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Rokok"))
	{
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);
		Inventory_Remove(playerid, "Rokok", 1);
		HideBackPackDialog(playerid);
		SetPlayerChatBubble(playerid, "> Menghisap Rokok <", COLOR_PURPLE, 10.0, 4000 );
		Info(playerid, "Gunakan mouse click atau tombol punch untuk memulai menghisap");
		smokecig[playerid] = 1;
	}
	else if(!strcmp(name, "Wine"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Minum Beer <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Drinking...", 4);
        SetTimerEx("minumbeer1", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);		
	}
	else if(!strcmp(name, "Whiskey"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Minum Beer <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Drinking...", 4);
        SetTimerEx("minumbeer2", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);		
	}
	else if(!strcmp(name, "Vodka"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Minum Beer <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Drinking...", 4);
        SetTimerEx("minumbeer3", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);		
	}
	else if(!strcmp(name, "Blue Moon"))
	{
		if(Inventory_Count(playerid, "Sampah") > 14)
			return ErrorMsg(playerid, "Sampah anda sudah penuh");

        ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
        SetPlayerChatBubble(playerid, "> Minum Beer <", COLOR_PURPLE, 10.0, 4000 );
        ShowProgressbar(playerid, "Drinking...", 4);
        SetTimerEx("minumbeer4", 4000, false, "i", playerid);
        HideBackPackDialog(playerid);		
	}
	else if(!strcmp(name, "Skateboard"))
	{
		if(!IsPlayerInAnyVehicle(playerid))
		{
			HideBackPackDialog(playerid);
			ApplyAnimation(playerid, "CARRY","null",0,0,0,0,0,0,0);
			ApplyAnimation(playerid, "SKATE","null",0,0,0,0,0,0,0);
			ApplyAnimation(playerid, "CARRY","crry_prtial",4.0,0,0,0,0,0);
			Info(playerid, "Gunakan {FFFF00}[Y] {FFFFFF}untuk memulai menggunakan skateboard");
			Info(playerid, "Gunakan {FFFF00}'/skateoff' {FFFFFF}untuk berhenti menggunakan skateboard");
			if(!InfoSkate[playerid][sActive])
			{
				InfoSkate[playerid][sActive] = true;
				#if TYPE_SKATE == 0
					SetPlayerAttachedObject(playerid,INDEX_SKATE,19878,6,-0.055999,0.013000,0.000000,-84.099983,0.000000,-106.099998,1.000000,1.000000,1.000000);
				#else
					SetPlayerAttachedObject(playerid,INDEX_SKATE,19878,1,0.055999,-0.173999,-0.007000,-95.999893,-1.600010,24.099992,1.000000,1.000000,1.000000);
				#endif
					PlayerPlaySound(playerid,21000,0,0,0);
					Info(playerid, "Anda mendapatkan kembali skateboard anda");
			}
		}
		else ErrorMsg(playerid, "Anda tidak dapat menggunakan skateboard di dalam kendaraan");
	}	
	else if(!strcmp(name, "Phone"))
	{
		HideBackPackDialog(playerid);
		PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
		callcmd::h(playerid, "");
	}
	else if(!strcmp(name, "Boombox"))
	{
		callcmd::pickveh(playerid, "place");
		HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Medkit"))
	{
		new Float:darahh;
		/*if(pData[playerid][pFirstAid])
			return Error(playerid, "You already using a Medkit");*/

		if (ReturnHealth(playerid) > 99)
		    return ErrorMsg(playerid, "Health anda sudah mencapai maksimum");

	    GetPlayerHealth(playerid, darahh);
	    SetPlayerHealthEx(playerid, darahh+50);
	    Inventory_Remove(playerid, "Medkit", 1);

	    SetPlayerChatBubble(playerid, "> Menggunakan Medkit <", COLOR_PURPLE, 10.0, 4000 );
	    HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Fuel Can"))
	{
		if(IsPlayerInAnyVehicle(playerid))
			return ErrorMsg(playerid, "Anda harus berada diluar kendaraan!");

		if(pData[playerid][pActivityTime] > 5) return ErrorMsg(playerid, "Anda masih memiliki activity progress!");
		if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
		new vehicleid = GetNearestVehicleToPlayer(playerid, 3.5, false);
		if(IsValidVehicle(vehicleid))
		{
			new fuel = vCore[vehicleid][vFuel];
			
			if(GetEngineStatus(vehicleid))
				return ErrorMsg(playerid, "Matikan terlebih dahulu kendaraan anda");
			
			if(fuel >= 100)
				return ErrorMsg(playerid, "Bensin kendaraan ini sudah penuh");
			
			if(!IsEngineVehicle(vehicleid))
				return ErrorMsg(playerid, "Kendaraan ini tidak dapat di isi bensin");

			if(!GetHoodStatus(vehicleid))
				return ErrorMsg(playerid, "Buka terlebih dahulu Hood kendaraan anda");

			Inventory_Remove(playerid, "Fuel Can", 1);
			Info(playerid, "Don't move from your position or you will failed to refulling this vehicle.");
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 0, 0, 0, 0, 0, 1);
			ShowProgressbar(playerid, "Refulling...", 10);
			SetTimerEx("RefullCar", 10000, false, "id", playerid, vehicleid);
			SetPlayerChatBubble(playerid, "> Menggunakan Fuel Can <", COLOR_PURPLE, 10.0, 4000 );
			HideBackPackDialog(playerid);
		}

	}
	else if(!strcmp(name,"Test Drug")) 
	{
		if(Inventory_Count(playerid, "Test Drug") < 1)
			return Error(playerid, "You dont have test drug.");
			
		Inventory_Remove(playerid, "Test Drug", 1);
		SetPlayerChatBubble(playerid, "> Testing Drug <", COLOR_PURPLE, 10.0, 4000 );

		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",2.1,0,0,0,0,0);
		HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Component"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Portable Radio"))
	{
		SelectTextDraw(playerid, SERVER_TEXTDRAW_COLOR);
		HideBackPackDialog(playerid);		
		CallRemoteFunction("OnPlayerUseRadio", "i", playerid);
	}
	else if(!strcmp(name, "Material"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Benang"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Kain"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Pakaian"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Sampah"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Repair Kit"))
	{
		return callcmd::repair(playerid, "");
	}
	else if(!strcmp(name, "Wheat"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Orange"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Potato"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Food"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Kanabis"))
	{
		return ErrorMsg(playerid, "Item tidak dapat di gunakan");
	}
	else if(!strcmp(name, "Medicine"))
	{
		pData[playerid][pSick] = 0;
		pData[playerid][pSickTime] = 0;
		SetPlayerDrunkLevel(playerid, 0);
		Inventory_Remove(playerid, "Medicine", 1);
		SetPlayerChatBubble(playerid, "> Menggunakan Medicine <", COLOR_PURPLE, 10.0, 4000 );
		HideBackPackDialog(playerid);
		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",2.1,0,0,0,0,0);
	}
	else if(!strcmp(name, "Bandage"))
	{
		if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
		if (ReturnHealth(playerid) > 99) return ErrorMsg(playerid, "Health anda sudah mencapai maksimum");
		    		
		SetPlayerChatBubble(playerid, "> Menggunakan Bandage <", COLOR_PURPLE, 10.0, 4000 );
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, 9, 11738, 5, 0.105, 0.086, 0.22, -80.3, 3.3, 28.7, 0.35, 0.35, 0.35);
		TogglePlayerControllable(playerid, 0);
		ShowProgressbar(playerid, "Equiping...", 5);
		pData[playerid][pTimebandage] = SetTimerEx("pakebandage", 5000, false, "i", playerid);
		HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Kevlar"))
	{
		if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
		HideBackPackDialog(playerid);
		TogglePlayerControllable(playerid, 0);
		SetPlayerChatBubble(playerid, "> Menggunakan Kevlar <", COLOR_PURPLE, 10.0, 4000 );
		ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
		ShowProgressbar(playerid, "Equiping...", 5);
		SetTimerEx("pakekevlar", 5000, false, "i", playerid);
	}
	else if(!strcmp(name, "Marijuana"))
	{
		new Float:armor;
		GetPlayerArmour(playerid, armor);
		if(armor+25 > 95)
		{
			SyntaxMsg(playerid, "Anda mengalami overdosis!");
			TextDrawShowForPlayer(playerid, Text:RedScreen);
			SetTimerEx("ShowRedScreen", 1000, 0, "d", playerid);
			if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
			{
				ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.1, 1, 1, 1, 1, 1, 1);
			}
			SetPlayerArmourEx(playerid, 95);
		}
		Inventory_Remove(playerid, "Marijuana", 1);
		pData[playerid][pUseDrug]++;
		SetPlayerArmourEx(playerid, armor+20);
		pData[playerid][pStress] -= 5;
		SetPlayerDrunkLevel(playerid, 4000);
		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",2.1,0,0,0,0,0);
		SetPlayerChatBubble(playerid, "> Menggunakan Marijuana <", COLOR_PURPLE, 10.0, 4000 );
		HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Cocaine"))
	{
		new Float:armor;
		GetPlayerArmour(playerid, armor);
		if(armor+25 > 95)
		{
			SyntaxMsg(playerid, "Anda mengalami overdosis!");
			TextDrawShowForPlayer(playerid, Text:RedScreen);
			SetTimerEx("ShowRedScreen", 1000, 0, "d", playerid);
			if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
			{
				ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.1, 1, 1, 1, 1, 1, 1);
			}
			SetPlayerArmourEx(playerid, 95);
		}
		Inventory_Remove(playerid, "Cocaine", 1);
		pData[playerid][pUseDrug]++;
		SetPlayerArmourEx(playerid, armor+20);
		pData[playerid][pStress] -= 5;
		SetPlayerDrunkLevel(playerid, 4000);
		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",2.1,0,0,0,0,0);
		SetPlayerChatBubble(playerid, "> Menggunakan Cocaine <", COLOR_PURPLE, 10.0, 4000 );
		HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Meth"))
	{
		new Float:armor, Float:health;
		GetPlayerArmour(playerid, armor);
		GetPlayerHealth(playerid, health);
		if(armor+25 > 95)
		{
			Error(playerid, "Over dosis!");
			TextDrawShowForPlayer(playerid, Text:RedScreen);
			SetTimerEx("ShowRedScreen", 1000, 0, "d", playerid);
			if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
			{
				ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.1, 1, 1, 1, 1, 1, 1);
			}
			SetPlayerArmourEx(playerid, 95);
		}
		else if(health+25 > 95)
		{
			Error(playerid, "Over dosis!");
			TextDrawShowForPlayer(playerid, Text:RedScreen);
			SetTimerEx("ShowRedScreen", 1000, 0, "d", playerid);
			if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
			{
				ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.1, 1, 1, 1, 1, 1, 1);
			}
			SetPlayerHealthEx(playerid, 95);
			return 1;
		}

		Inventory_Remove(playerid, "Meth", 1);
		pData[playerid][pUseDrug]++;
		SetPlayerArmourEx(playerid, armor+20);
		SetPlayerHealthEx(playerid, health+20);
		SetPlayerDrunkLevel(playerid, 4000);
		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",2.1,0,0,0,0,0);
		SetPlayerChatBubble(playerid, "> Menggunakan Meth <", COLOR_PURPLE, 10.0, 4000 );
		HideBackPackDialog(playerid);
	}
	else if(!strcmp(name, "Clip Pistol"))
	{
		if(GetPlayerWeapon(playerid) == 0)
		return Error(playerid, "Kamu harus memegang senjata api");

		new weaponid = GetPlayerWeapon(playerid), ammo = GetPlayerAmmo(playerid);

		if(weaponid < 22 || weaponid > 32)
			return Error(playerid, "this weapon does not support to use clip");

		if(weaponid >= 22 && weaponid <= 24) //PISTOL
		{
			if(weaponid == 22 || weaponid == 23)
			{
				GivePlayerWeaponEx(playerid, weaponid, ammo+50);
			}
			else
			{
				GivePlayerWeaponEx(playerid, weaponid, ammo+34);
			}
			Inventory_Remove(playerid, "Clip Pistol", 1);
			new strz[200];
			format(strz, sizeof(strz), "Mengisi ulang peluru senjata %s dengan Pistol Clip", ReturnWeaponName(weaponid));
			SuccesMsg(playerid, strz);
			ApplyAnimation(playerid, "PYTHON", "python_reload", 4.1, 0, 0, 0, 0, 0);
			HideBackPackDialog(playerid);
		}
	}
	else if(!strcmp(name, "Clip Rifle"))
	{
		if(GetPlayerWeapon(playerid) == 0)
		return Error(playerid, "Kamu harus memegang senjata api");

		new weaponid = GetPlayerWeapon(playerid), ammo = GetPlayerAmmo(playerid);

		if(weaponid < 28 || weaponid > 32)
			return Error(playerid, "this weapon does not support to use clip");

		if(weaponid >= 28 && weaponid <= 32) //Rifle
		{
			Inventory_Remove(playerid, "Clip Rifle", 1);
			GivePlayerWeaponEx(playerid, weaponid, ammo+200);
			new strz[200];
			format(strz, sizeof(strz), "Mengisi ulang peluru senjata %s dengan Rifle Clip", ReturnWeaponName(weaponid));
			SuccesMsg(playerid, strz);
			ApplyAnimation(playerid, "RIFLE", "RIFLE_load", 4.1, 0, 0, 0, 0, 0);
			HideBackPackDialog(playerid);
		}
	}
	else if (!strcmp(name, "Note")) {
        //if(AccountData[playerid][pInjured] return 0;
        //OpenInventory(playerid, false);
		HideBackPackDialog(playerid);
        new noteText[100];
        strunpack(noteText, InventoryData[playerid][itemid][invExists]);

        // Show the note text using textdraw
        for (new j = 0; j < 18; j++)
        {
            PlayerTextDrawShow(playerid, CharacterNote[playerid][Note::p_td][j]);
        }
        PlayerTextDrawSetString(playerid, CharacterNote[playerid][Note::p_td][15], "Close");
        PlayerTextDrawSetString(playerid, CharacterNote[playerid][Note::p_td][16], noteText);
        PlayerTextDrawSetSelectable(playerid, CharacterNote[playerid][Note::p_td][17], 0);
        CharacterNote[playerid][ReadMode] = true;
        SelectTextDraw(playerid, COLOR_RED);
    } 
	return 1;
}