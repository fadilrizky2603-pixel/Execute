//kentang 760
//gandum 804
//jeruk 949
//ganja 19473
//-383.67, -1438.90, 26.32
//Drug 2653.3169 -2410.5852 3001.0859

enum E_PLANT
{
	// loaded from db
	PlantType,
	PlantTime,
	Float:PlantX,
	Float:PlantY,
	Float:PlantZ,
	//temp
	bool:PlantHarvest,
	PlantTimer,
	PlantObjID,
	PlantCP,
	Text3D:PlantLabel
}

new PlantData[MAX_PLANT][E_PLANT],
	Iterator:Plants<MAX_PLANT>;
	
GetClosestPlant(playerid, Float: range = 2.0)
{
	new id = -1, Float: dist = range, Float: tempdist;
	foreach(new i : Plants)
	{
	    tempdist = GetPlayerDistanceFromPoint(playerid, PlantData[i][PlantX], PlantData[i][PlantY], PlantData[i][PlantZ]);

	    if(tempdist > range) continue;
		if(tempdist <= dist)
		{
			dist = tempdist;
			id = i;
		}
	}
	return id;
}

GetNearPlant(playerid, Float: range = 3.5)
{
	new id = -1, Float: dist = range, Float: tempdist;
	foreach(new i : Plants)
	{
	    tempdist = GetPlayerDistanceFromPoint(playerid, PlantData[i][PlantX], PlantData[i][PlantY], PlantData[i][PlantZ]);

	    if(tempdist > range) continue;
		if(tempdist <= dist)
		{
			dist = tempdist;
			id = i;
		}
	}
	return id;
}

GetPlantName(planttype) {
    new type[24];

    switch(planttype) {
        case 0: type = "None";
        case 1: type = "Potato";
        case 2: type = "Wheat";
        case 3: type = "Orange";
        case 4: type = "Kanabis";
    }
    return type;
}

Plant_Refresh(id)
{
	if(id != -1)
    {
		if(IsValidDynamicObject(PlantData[id][PlantObjID]))
			DestroyDynamicObject(PlantData[id][PlantObjID]);
		
		if(IsValidDynamicCP(PlantData[id][PlantCP]))
			DestroyDynamicCP(PlantData[id][PlantCP]);
		
		if(IsValidDynamic3DTextLabel(PlantData[id][PlantLabel]))
			DestroyDynamic3DTextLabel(PlantData[id][PlantLabel]);

		if(PlantData[id][PlantType] == 1)
		{
			PlantData[id][PlantObjID] = CreateDynamicObject(760, PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ]-1.5, 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0);
			PlantData[id][PlantCP] = CreateDynamicCP(PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ], 2.0, 0, 0, -1, 2.0);
			PlantData[id][PlantLabel] = CreateDynamic3DTextLabel(sprintf("Type: %s", GetPlantName(PlantData[id][PlantType])), -1, PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ], 2.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
		}
		else if(PlantData[id][PlantType] == 2)
		{
			PlantData[id][PlantObjID] = CreateDynamicObject(804, PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ]-1.0, 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0);
			PlantData[id][PlantCP] = CreateDynamicCP(PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ], 2.0, 0, 0, -1, 2.0);
			PlantData[id][PlantLabel] = CreateDynamic3DTextLabel(sprintf("Type: %s", GetPlantName(PlantData[id][PlantType])), -1, PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ], 2.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
		}
		else if(PlantData[id][PlantType] == 3)
		{
			PlantData[id][PlantObjID] = CreateDynamicObject(949, PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ]-1.0, 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0);
			PlantData[id][PlantCP] = CreateDynamicCP(PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ], 2.0, 0, 0, -1, 2.0);
			PlantData[id][PlantLabel] = CreateDynamic3DTextLabel(sprintf("Type: %s", GetPlantName(PlantData[id][PlantType])), -1, PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ], 2.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
		}
		else if(PlantData[id][PlantType] == 4)
		{
			PlantData[id][PlantObjID] = CreateDynamicObject(19473, PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ]-2.0, 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0);
			PlantData[id][PlantCP] = CreateDynamicCP(PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ], 2.0, 0, 0, -1, 2.0);
			PlantData[id][PlantLabel] = CreateDynamic3DTextLabel(sprintf("Type: %s", GetPlantName(PlantData[id][PlantType])), -1, PlantData[id][PlantX], PlantData[id][PlantY], PlantData[id][PlantZ], 2.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
		}
	}
	return 1;
}

function PlantGrowup(id)
{
	if(id != -1)
	{
		if(PlantData[id][PlantTime] > 0)
		{
			PlantData[id][PlantTime]--;
		}
		if(PlantData[id][PlantTime] < 2300 && PlantData[id][PlantTime] > 2298)
		{
			Plant_Refresh(id);
		}
		if(PlantData[id][PlantTime] < 5 && PlantData[id][PlantTime] > 1)
		{
			Plant_Refresh(id);
		}
	}
	return 1;
}

function LoadPlants()
{
    new id;
	
	new rows = cache_num_rows();
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", id);
			cache_get_value_name_int(i, "type", PlantData[id][PlantType]);
			cache_get_value_name_int(i, "time", PlantData[id][PlantTime]);
			cache_get_value_name_float(i, "posx", PlantData[id][PlantX]);
			cache_get_value_name_float(i, "posy", PlantData[id][PlantY]);
			cache_get_value_name_float(i, "posz", PlantData[id][PlantZ]);
			Iter_Add(Plants, id);
			
			PlantData[id][PlantHarvest] = false;
			Plant_Refresh(id);
			PlantData[id][PlantTimer] = SetTimerEx("PlantGrowup", 1000, true, "i", id);
		}
		printf("[DATABASE] Number of farmer plant Loaded: %d.", rows);
	}
}

Plant_Save(id)
{
	new cQuery[512];
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "UPDATE plants SET type='%d', time='%d', posx='%f', posy='%f', posz='%f' WHERE id='%d'",
	PlantData[id][PlantType],
	PlantData[id][PlantTime],
	PlantData[id][PlantX],
	PlantData[id][PlantY],
	PlantData[id][PlantZ],
	id
	);
	return mysql_tquery(g_SQL, cQuery);
}

function OnPlantCreated(playerid, id)
{
	Plant_Refresh(id);
	Plant_Save(id);
	return 1;
}

function HarvestPlant(playerid)
{
	if(pData[playerid][pHarvestID] != -1)
	{
		new id = pData[playerid][pHarvestID];
		new kg = RandomEx(5, 10);
		
		if(pData[playerid][pActivityTime] >= 100)
		{
			if(PlantData[id][PlantType] == 1)
			{
				Inventory_Add(playerid, "Potato", 19577, kg);
				Info(playerid, "Anda mendapatkan hasil panen potato/kentang seberat "GREEN_E"%d kg.", kg);
			}
			else if(PlantData[id][PlantType] == 2)
			{
				Inventory_Add(playerid, "Wheat", 2247, kg);
				Info(playerid, "Anda mendapatkan hasil panen wheat/gandum seberat "GREEN_E"%d kg.", kg);
			}
			else if(PlantData[id][PlantType] == 3)
			{
				Inventory_Add(playerid, "Orange", 19574, kg);
				Info(playerid, "Anda mendapatkan hasil panen orange/jeruk seberat "GREEN_E"%d kg.", kg);
			}
			else if(PlantData[id][PlantType] == 4)
			{
				Inventory_Add(playerid, "Kanabis", 19473, kg);
				Info(playerid, "Anda mendapatkan hasil panen Kanabis seberat "GREEN_E"%d kg.", kg);
			}
			
			SuccesMsg(playerid, "Harvesting done!");
			KillTimer(pData[playerid][pHarvest]);
			pData[playerid][pActivityTime] = 0;
			pData[playerid][pHarvestID] = -1;
			
			
			pData[playerid][pEnergy] -= 1;
			clearAnimations(playerid);
			StopLoopingAnim(playerid);
			SetPlayerSpecialAction(playerid, 0);
			
			new query[128];
			PlantData[id][PlantType] = 0;
			PlantData[id][PlantTime] = 0;
			PlantData[id][PlantX] = 0.0;
			PlantData[id][PlantY] = 0.0;
			PlantData[id][PlantZ] = 0.0;
			PlantData[id][PlantHarvest] = false;
			KillTimer(PlantData[id][PlantTimer]);
			PlantData[id][PlantTimer] = -1;
			DestroyDynamicObject(PlantData[id][PlantObjID]);
			DestroyDynamicCP(PlantData[id][PlantCP]);
			DestroyDynamic3DTextLabel(PlantData[id][PlantLabel]);
			mysql_format(g_SQL, query, sizeof(query), "DELETE FROM plants WHERE id='%d'", id);
			mysql_tquery(g_SQL, query);
			Iter_Remove(Plants, id);
			return 1;
		}
		else if(pData[playerid][pActivityTime] < 100)
		{
			pData[playerid][pActivityTime] += 10;
			
			ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 1);
		}
	}
	return 1;
}

Player_ResetHarvest(playerid)
{
	if(!IsPlayerConnected(playerid) || pData[playerid][pHarvestID] == -1) return 0;
	
	new id = pData[playerid][pHarvestID];
	PlantData[id][PlantHarvest] = false;
	return 1;
}

//------------[ Farmer Commands ]------------

CMD:plant(playerid, params[])
{
	if(isnull(params)) return Usage(playerid, "/plant [plant/harvest/destroy/sell]");
	if(!strcmp(params, "plant", true))
	{
		if(pData[playerid][pJob] == 7 || pData[playerid][pJob2] == 7)
		{
			if(GetPlayerInterior(playerid) > 0) return ErrorMsg(playerid, "Anda tidak dapat menanam disini");
			if(GetPlayerVirtualWorld(playerid) > 0) return ErrorMsg(playerid, "Anda tidak dapat menanam disini");
			
			new mstr[512], tstr[64];
			format(tstr, sizeof(tstr), ""WHITE_E"My Seed: "GREEN_E"%d", pData[playerid][pSeed]);
			format(mstr, sizeof(mstr), "Plant\tSeed\n\
			"WHITE_E"Potato\t"GREEN_E"5 Seed\n\
			"WHITE_E"Wheat\t"GREEN_E"18 Seed\n\
			"WHITE_E"Orange\t"GREEN_E"11 Seed\n\
			"RED_E"Kanabis\t"GREEN_E"25 Seed");
			ShowPlayerDialog(playerid, DIALOG_PLANT, DIALOG_STYLE_TABLIST_HEADERS, tstr, mstr, "Plant", "Close");
		}
		else return ErrorMsg(playerid, "Anda bukan Farmer");
	}
	else if(!strcmp(params, "harvest", true))
	{
		if(pData[playerid][pJob] == 7 || pData[playerid][pJob2] == 7)
		{
			if(IsPlayerInRangeOfPoint(playerid, 100.0, -263.49, -1508.27, 5.66) || IsPlayerInRangeOfPoint(playerid, 100.0, -424.36, -1330.72, 27.46)
			|| IsPlayerInRangeOfPoint(playerid, 100.0, -243.84, -1366.69, 9.95) || IsPlayerInRangeOfPoint(playerid, 100.0, -563.65, -1344.91, 22.39))
			{
				new id = GetClosestPlant(playerid);
				if(id == -1) return ErrorMsg(playerid, "Anda harus berada di dekat tanaman tersebut");
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(PlantData[id][PlantTime] > 1) return SyntaxMsg(playerid, "Belum saat anda nya memanen Tanaman");
				if(PlantData[id][PlantHarvest] == true) return ErrorMsg(playerid, "Tanaman ini sudah di panen oleh orang lain");
				if(GetPlayerWeapon(playerid) != WEAPON_KNIFE) return ErrorMsg(playerid, "Anda tidak memiliki pisau");
				
				pData[playerid][pHarvestID] = id;
				pData[playerid][pHarvest] = SetTimerEx("HarvestPlant", 1000, true, "i", playerid);
				ShowProgressbar(playerid, "Harvesting...", 10);
				SetPlayerArmedWeapon(playerid, WEAPON_KNIFE);
				ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 1);

				PlantData[id][PlantHarvest] = true;
			}
			else return ErrorMsg(playerid, "Anda sedang tidak berada di area Farmer");
		}
		else return ErrorMsg(playerid, "Anda bukan bagian dari Farmer");
	}
	else if(!strcmp(params, "destroy", true))
	{
		if(pData[playerid][pFaction] == 1 || pData[playerid][pFaction] == 2)
		{
			if(IsPlayerInRangeOfPoint(playerid, 100.0, -263.49, -1508.27, 5.66) || IsPlayerInRangeOfPoint(playerid, 100.0, -424.36, -1330.72, 27.46)
			|| IsPlayerInRangeOfPoint(playerid, 100.0, -243.84, -1366.69, 9.95) || IsPlayerInRangeOfPoint(playerid, 100.0, -563.65, -1344.91, 22.39))
			{
				new id = GetClosestPlant(playerid);
				if(id == -1) return ErrorMsg(playerid, "Anda harus dekat dengan tanaman");
				if(PlantData[id][PlantHarvest] == true) return ErrorMsg(playerid, "Tanaman ini sudah di panen oleh orang lain");
				
				new query[128];
				PlantData[id][PlantType] = 0;
				PlantData[id][PlantTime] = 0;
				PlantData[id][PlantX] = 0.0;
				PlantData[id][PlantY] = 0.0;
				PlantData[id][PlantZ] = 0.0;
				PlantData[id][PlantHarvest] = false;
				KillTimer(PlantData[id][PlantTimer]);
				PlantData[id][PlantTimer] = -1;
				DestroyDynamicObject(PlantData[id][PlantObjID]);
				DestroyDynamicCP(PlantData[id][PlantCP]);
				DestroyDynamic3DTextLabel(PlantData[id][PlantLabel]);
				mysql_format(g_SQL, query, sizeof(query), "DELETE FROM plants WHERE id='%d'", id);
				mysql_tquery(g_SQL, query);
				Iter_Remove(Plants, id);
				ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 1);
				Info(playerid, "You has destroyed this plant!");
			}
			else return ErrorMsg(playerid, "Anda harus berada di Farmer Area");
		}
		else return ErrorMsg(playerid, "Anda tidak dapat menghancurkan Tanaman ini");
	}
	else if(!strcmp(params, "sell", true))
	{
		if(!IsPlayerInRangeOfPoint(playerid, 3.5, -382.97, -1426.43, 26.31))
			return ErrorMsg(playerid, "Anda harus berada di Warehouse Farmer");
			
		new potato = pData[playerid][pPotato] * PotatoPrice,
		wheat = pData[playerid][pWheat] * WheatPrice,
		orange = pData[playerid][pOrange] * OrangePrice;
		
		new total = pData[playerid][pPotato] + pData[playerid][pWheat] + pData[playerid][pOrange];
		new pay = potato + wheat + orange;
		
		if(total < 1) return ErrorMsg(playerid, "Anda tidak memiliki tanaman");
		GivePlayerMoneyEx(playerid, pay);
		Food += total;
		Gandum += pData[playerid][pWheat];
		Server_MinMoney(pay);
		
		pData[playerid][pPotato] = 0;
		pData[playerid][pWheat] = 0;
		pData[playerid][pOrange] = 0;
		Info(playerid, "You selling "RED_E"%d kg "WHITE_E"all plant to "GREEN_E"%s", total, FormatMoney(pay));
	}
	return 1;
}

CMD:price(playerid, params[])
{
	if(pData[playerid][pJob] == 7 || pData[playerid][pJob2] == 7)
	{
		new mstr[512], tstr[64];
		format(tstr, sizeof(tstr), ""WHITE_E"My Food: "GREEN_E"%d", pData[playerid][pFood]);
		format(mstr, sizeof(mstr), "Name\tPrice\n\
		"WHITE_E"Sprunk\t"GREEN_E"%s\n\
		"WHITE_E"Snack\t"GREEN_E"%s\n\
		"WHITE_E"Ice Cream Orange\t"GREEN_E"%s\n\
		"WHITE_E"Hotdog\t"GREEN_E"%s", FormatMoney(pData[playerid][pPrice1]), FormatMoney(pData[playerid][pPrice2]), FormatMoney(pData[playerid][pPrice3]), FormatMoney(pData[playerid][pPrice4]));
		ShowPlayerDialog(playerid, DIALOG_EDIT_PRICE, DIALOG_STYLE_TABLIST_HEADERS, tstr, mstr, "Edit", "Close");
	}
	else return ErrorMsg(playerid, "Anda bukan bagian dari Farmer");
	return 1;
}

CMD:offer(playerid, params[])
{
	if(pData[playerid][pJob] == 7 || pData[playerid][pJob2] == 7)
	{
		if(!IsPlayerInAnyVehicle(playerid))
			return ErrorMsg(playerid, "Anda harus berada di kendaraan Hotdog");
		
		new modelid = GetVehicleModel(GetPlayerVehicleID(playerid));
		if(modelid != 423 && modelid != 588)
			return ErrorMsg(playerid, "Anda harus berada di kendaraan Hotdog");
		
		new otherid;
		if(sscanf(params, "u", otherid))
			return SyntaxMsg(playerid, "/offer [playerid/PartOfName]");
		
		if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
			return ErrorMsg(playerid, "Player tersebut sedang tidak berada di dekat anda");
		
		pData[otherid][pOffer] = playerid;
		new mstr[512], tstr[64];
		format(tstr, sizeof(tstr), ""WHITE_E"Food Stock: "GREEN_E"%d", pData[playerid][pFood]);
		format(mstr, sizeof(mstr), "Name\tPrice\n\
		"WHITE_E"Sprunk\t"GREEN_E"%s\n\
		"WHITE_E"Snack\t"GREEN_E"%s\n\
		"WHITE_E"Ice Cream Orange\t"GREEN_E"%s\n\
		"WHITE_E"Hotdog\t"GREEN_E"%s", FormatMoney(pData[playerid][pPrice1]), FormatMoney(pData[playerid][pPrice2]), FormatMoney(pData[playerid][pPrice3]), FormatMoney(pData[playerid][pPrice4]));
		ShowPlayerDialog(otherid, DIALOG_OFFER, DIALOG_STYLE_TABLIST_HEADERS, tstr, mstr, "Buy", "Close");
	}
	else return ErrorMsg(playerid, "Anda bukan bagian dari farmer");
	return 1;
}