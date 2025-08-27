#define GetVehicleBoot(%0,%1,%2,%3)				GetVehicleOffset((%0),VEHICLE_OFFSET_BOOT,(%1),(%2),(%3))

enum OffsetTypes {
	VEHICLE_OFFSET_BOOT,
	VEHICLE_OFFSET_HOOD,
	VEHICLE_OFFSET_ROOF
};

GetVehicleOffset(vehicleid, OffsetTypes:type,&Float:x,&Float:y,&Float:z)
{
	new Float:fPos[4],Float:fSize[3];

	if(!IsValidVehicle(vehicleid)){
		x = y =	z = 0.0;
		return 0;
	} else {
		GetVehiclePos(vehicleid,fPos[0],fPos[1],fPos[2]);
		GetVehicleZAngle(vehicleid,fPos[3]);
		GetVehicleModelInfo(GetVehicleModel(vehicleid),VEHICLE_MODEL_INFO_SIZE,fSize[0],fSize[1],fSize[2]);

		switch(type){
			case VEHICLE_OFFSET_BOOT: {
				x = fPos[0] - (floatsqroot(fSize[1] + fSize[1]) * floatsin(-fPos[3],degrees));
				y = fPos[1] - (floatsqroot(fSize[1] + fSize[1]) * floatcos(-fPos[3],degrees));
 				z = fPos[2];
			}
			case VEHICLE_OFFSET_HOOD: {
				x = fPos[0] + (floatsqroot(fSize[1] + fSize[1]) * floatsin(-fPos[3],degrees));
				y = fPos[1] + (floatsqroot(fSize[1] + fSize[1]) * floatcos(-fPos[3],degrees));
	 			z = fPos[2];
			}
			case VEHICLE_OFFSET_ROOF: {
				x = fPos[0];
				y = fPos[1];
				z = fPos[2] + floatsqroot(fSize[2]);
			}
		}
	}
	return 1;
}
#include <YSI_Coding\y_hooks>

new STREAMER_TAG_AREA:JualTambang, STREAMER_TAG_AREA:PeleburanMiner[5], STREAMER_TAG_AREA:PencucianBatu, Miningtime[MAX_PLAYERS][19];

CreateAreaMiner()
{
	//Penjualan
	JualTambang = CreateDynamicCircle(2742.2322, -2363.2864, 1.5, 0, 0, -1);
	//Peleburan
	PeleburanMiner[0] = CreateDynamicCircle(-797.836059, -2276.645996, 2.0, 0, 0, -1);
	PeleburanMiner[1] = CreateDynamicCircle(2151.00, -2272.14, 2.0 , 0, 0, -1);
	PeleburanMiner[2] = CreateDynamicCircle(2148.86, -2269.98, 2.0 , 0, 0, -1);
	PeleburanMiner[3] = CreateDynamicCircle(2146.89, -2268.07, 2.0 , 0, 0, -1);
	PeleburanMiner[4] = CreateDynamicCircle(2145.32, -2266.44, 2.0 , 0, 0, -1);
	//Mencuci Batu
	PencucianBatu = CreateDynamicCircle(-759.741027, -2243.501464, 2.0, 0, 0, -1);

	new strings[128];
	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk mencuci batu");
	CreateDynamic3DTextLabel(strings, -1, -759.741027, -2243.501464, 27.824132, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk mengolah batu");
	CreateDynamic3DTextLabel(strings, -1, -797.836059, -2276.645996, 43.296405, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
}

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(pData[playerid][pJob] == 5 || pData[playerid][pJob2] == 5)
		{
			forex(i, 5)
			{
				if(areaid == PeleburanMiner[i])
				{
					TombolY(playerid, "Untuk Mengolah Batu");
				}
			}
			if(areaid == JualTambang)
			{
				TombolY(playerid, "Untuk Menjual Hasil Tambang");
			}
			if(areaid == PencucianBatu)
			{
				TombolY(playerid, "Untuk mencuci Batu");
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(pData[playerid][pJob] == 3 || pData[playerid][pJob2] == 3)
		{
			forex(i, 5)
			{
				if(areaid == PeleburanMiner[i])
				{
					HideInfoTombol(playerid);
				}
			}
			if(areaid == JualTambang)
			{
				HideInfoTombol(playerid);
			}
			if(areaid == PencucianBatu)
			{
				HideInfoTombol(playerid);
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES)
    {
		if(pData[playerid][pJob] == 5 || pData[playerid][pJob2] == 5 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
		{
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 2771.944580, -1625.254150, 11.126003))
			{
				new str[1028];
				format(str, sizeof(str), "Name\t"YELLOW_E"Price\n"WHITE_E"Component\t"GREEN_E"$15\n"WHITE_E"Material\t"GREEN_E"$30");
				ShowPlayerDialog(playerid, DIALOG_SELL_MINE, DIALOG_STYLE_TABLIST_HEADERS, "Menu Penambang", str, "Select", "Close");
			}
			if(pData[playerid][pJobTime] > 0)
				return Error(playerid, "Anda harus menunggu "GREY2_E"%d "WHITE_E"detik untuk bisa bekerja kembali.", pData[playerid][pJobTime]);

			if(IsPlayerInRangeOfPoint(playerid, 10.0, -759.741027, -2243.501464, 27.824132))
			{ 
				if(Inventory_Count(playerid, "Batu") < 1) return ErrorMsg(playerid, "Anda tidak memiliki item batu");			
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				SetTimerEx("miner1", 10000, false, "d", playerid);
				ShowProgressbar(playerid, "Cuci Batu...", 10);
			}
			if(IsPlayerInRangeOfPoint(playerid, 10.0, -797.836059, -2276.645996, 43.296405))
			{ 
				if(Inventory_Count(playerid, "Batu Cucian") < 1) return ErrorMsg(playerid, "Anda tidak memiliki item batu");
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				SetTimerEx("miner2", 10000, false, "d", playerid);
				ShowProgressbar(playerid, "Olah Batu...", 10);
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2387.3579,-2026.0120,43.5005))
			{
				if(Miningtime[playerid][0] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][0] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2417.4827,-2022.5900,43.5005))
			{
				if(Miningtime[playerid][1] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][1] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2424.5183,-2016.6841,43.5005))
			{
				if(Miningtime[playerid][2] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");				
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][2] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2376.8691,-2023.9138,23.1958))
			{
				if(Miningtime[playerid][3] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][3] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2384.4912,-2023.5466,23.1958))
			{
				if(Miningtime[playerid][4] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][4] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2387.9297,-2007.2063,12.7049))
			{
				if(Miningtime[playerid][5] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][5] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2395.8586,-2008.6282,13.2695))
			{
				if(Miningtime[playerid][6] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][6] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2405.2861,-2011.2119,17.3423))
			{
				if(Miningtime[playerid][7] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][7] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2406.8208,-2014.3508,13.3556))
			{
				if(Miningtime[playerid][8] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][8] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2410.9949,-2018.7457,12.8039))
			{
				if(Miningtime[playerid][9] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][9] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2403.0862,-2019.7799,12.7058))
			{
				if(Miningtime[playerid][10] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][10] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2392.8853,-2021.1140,12.7344))
			{
				if(Miningtime[playerid][11] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][11] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2384.3491,-2022.0701,12.7524))
			{
				if(Miningtime[playerid][12] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][12] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2355.3667,-2021.5289,12.6521))
			{
				if(Miningtime[playerid][13] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][13] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2337.8516,-2020.8882,12.7035))
			{
				if(Miningtime[playerid][14] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][14] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2335.6116,-2016.2134,12.7428))
			{
				if(Miningtime[playerid][15] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][15] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2346.1118,-2012.1272,14.9186))
			{
				if(Miningtime[playerid][16] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][16] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2352.4146,-2011.2720,13.7720))
			{
				if(Miningtime[playerid][17] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][17] = gettime() + 120;
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2363.7483,-2007.0499,13.3002))
			{
				if(Miningtime[playerid][18] >= gettime()) return 1;
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Batu") > 200) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 200 batu");
				ApplyAnimation(playerid, "BASEBALL", "Bat_M", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Mining", "miner");
				SetPlayerAttachedObject(playerid, 9, 18635, 6, 0.021, 0.000, -0.037, 9.000, 0.000, 0.000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
				Miningtime[playerid][18] = gettime() + 120;
			}
		}
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

function miner1(playerid)
{
    clearAnimations(playerid);
    Inventory_Add(playerid, "Batu Cucian", 2936, 5);
    Inventory_Remove(playerid, "Batu", 5);
    RemovePlayerAttachedObject(playerid, 9);
    return 1;
}

function miner2(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		switch(random(3))
		{
			case 0:
			{
				clearAnimations(playerid);
				Inventory_Remove(playerid, "Batu Cucian", 2);
				Inventory_Add(playerid, "Component", 1967, 5);
				RemovePlayerAttachedObject(playerid, 9);
			}
			case 1:
			{
				clearAnimations(playerid);
				Inventory_Remove(playerid, "Batu Cucian", 2);
				Inventory_Add(playerid, "Component", 1967, 10);
				RemovePlayerAttachedObject(playerid, 9);
			}
			case 2:
			{
				clearAnimations(playerid);
				Inventory_Remove(playerid, "Batu Cucian", 2);
				Inventory_Add(playerid, "Component", 1967, 15);
				RemovePlayerAttachedObject(playerid, 9);
			}
		}
	}
    return 1;
}

function BarMoveMiner(playerid)
{

}
function miner(playerid)
{
	new rand = RandomEx(1, 5);
    clearAnimations(playerid);
    Inventory_Add(playerid, "Batu", 3929, rand);
    RemovePlayerAttachedObject(playerid, 9);
    return 1;
}