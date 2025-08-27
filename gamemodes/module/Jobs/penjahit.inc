#include <YSI_Coding\y_hooks>

CreatePenjahitPoint()
{
	new strings[128];
	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk membuat kain");
	CreateDynamic3DTextLabel(strings, -1,1953.718505, -2099.230712, 1017.689636, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);	

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk membuat kain");
	CreateDynamic3DTextLabel(strings, -1, 1953.714355, -2104.150634, 1017.689636, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk membuat kain");
	CreateDynamic3DTextLabel(strings, -1, 1953.717895, -2108.722656, 1017.689636, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk membuat kain");
	CreateDynamic3DTextLabel(strings, -1, 1953.713623, -2113.488281, 1017.689636, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk membuat benang");
	CreateDynamic3DTextLabel(strings, -1, 1940.284667, -2100.066894, 1013.468750, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk menjahit Pakaian");
	CreateDynamic3DTextLabel(strings, -1,1950.036621, -2110.907470, 1017.689636, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk menjahit Pakaian");
	CreateDynamic3DTextLabel(strings, -1,1950.040405, -2107.943603, 1017.689636, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk menjahit Pakaian");
	CreateDynamic3DTextLabel(strings, -1,1950.039306, -2105.057861, 1017.689636, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk menjahit Pakaian");
	CreateDynamic3DTextLabel(strings, -1, 1950.036499, -2101.701416, 1017.689636, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk menjahit Pakaian");
	CreateDynamic3DTextLabel(strings, -1, -191.6072,1097.5171,568.0355, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk menjahit Pakaian");
	CreateDynamic3DTextLabel(strings, -1, -186.1082,1097.5187,568.0365, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(pData[playerid][pJob] == 15 || pData[playerid][pJob2] == 15)
	{
		if(newkeys & KEY_YES)
		{
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1940.284667, -2100.066894, 1013.468750))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Create Benang...", "Benang");		
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5,1953.718505, -2099.230712, 1017.689636))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Benang") < 2) return ErrorMsg(playerid, "Anda tidak memiliki cukup benang (2)");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Create Kain...", "Kain");		
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1953.714355, -2104.150634, 1017.689636))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Benang") < 2) return ErrorMsg(playerid, "Anda tidak memiliki cukup benang (2)");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Create Kain...", "Kain");		
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1953.717895, -2108.722656, 1017.689636))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Benang") < 2) return ErrorMsg(playerid, "Anda tidak memiliki cukup benang (2)");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Create Kain...", "Kain");		
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1953.713623, -2113.488281, 1017.689636))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Benang") < 2) return ErrorMsg(playerid, "Anda tidak memiliki cukup benang (2)");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Create Kain...", "Kain");		
			}

			if(IsPlayerInRangeOfPoint(playerid, 1.5,1950.036621, -2110.907470, 1017.689636))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Kain") < 1) return ErrorMsg(playerid, "Anda tidak memiliki cukup Kain (1)");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Create Pakaian...", "Pakaian");		
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1950.040405, -2107.943603, 1017.689636))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Kain") < 1) return ErrorMsg(playerid, "Anda tidak memiliki cukup Kain (1)");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Create Pakaian...", "Pakaian");		
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1950.039306, -2105.057861, 1017.689636))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Kain") < 1) return ErrorMsg(playerid, "Anda tidak memiliki cukup Kain (1)");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Create Pakaian...", "Pakaian");		
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1950.036499, -2101.701416, 1017.689636))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Kain") < 1) return ErrorMsg(playerid, "Anda tidak memiliki cukup Kain (1)");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Create Pakaian...", "Pakaian");		
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 2785.728759, -1604.146362, 10.921875))
			{
				if(Inventory_Count(playerid, "Pakaian") < 1) return ErrorMsg(playerid, "Anda membutuhkan minimal 1 Pakaian");
				new jumlahpakaian = Inventory_Count(playerid, "Pakaian"), price = jumlahpakaian*30;
				Inventory_Remove(playerid, "Pakaian", jumlahpakaian);
				GivePlayerMoneyEx(playerid, price);
				new strings[150];
				format(strings, sizeof(strings), "Anda berhasil menjual %d pakaian dengan harga %s", jumlahpakaian, FormatMoney(price));
				SuccesMsg(playerid, strings);										
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

function Benang(playerid)
{
	clearAnimations(playerid);
	Inventory_Add(playerid, "Benang", 1901, 2);
	return 1;
}

function Kain(playerid)
{
	clearAnimations(playerid);
	Inventory_Remove(playerid, "Benang", 2);
	Inventory_Add(playerid, "Kain", 19873, 1);
	return 1;
}

function Pakaian(playerid)
{
	clearAnimations(playerid);
	Inventory_Remove(playerid, "Kain", 1);
	Inventory_Add(playerid, "Pakaian", 2705, 1);
	return 1;
}
