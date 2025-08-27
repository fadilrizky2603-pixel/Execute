CreateKanabisPoint()
{
    new strings[500];
    format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk melakukan proses kanabis");
    CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2294.4365,-1788.6649,1600.7520, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

    format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk melakukan proses kanabis");
    CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2299.4194,-1788.6136,1600.7520, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

    format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk melakukan proses kanabis");
    CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2304.7258,-1788.7726,1600.7520, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

    format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk melakukan proses kanabis");
    CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2304.6892,-1784.3356,1600.7520, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

    format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk melakukan proses kanabis");
    CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2299.2473,-1784.3361,1600.7520, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

    format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk melakukan proses kanabis");
    CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2294.6379,-1784.3369,1600.7520, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

}

#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_YES)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 2294.4365,-1788.6649,1600.7520))
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(Inventory_Count(playerid, "Kanabis") < 10) return ErrorMsg(playerid, "Kanabis anda tidak mencukupi (10)");
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
			ShowProgressbar(playerid, "Mengolah kanabis", 15);
			SetTimerEx("proseskanabis", 15000, false, "i", playerid);
		}
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 2299.4194,-1788.6136,1600.7520))
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(Inventory_Count(playerid, "Kanabis") < 10) return ErrorMsg(playerid, "Kanabis anda tidak mencukupi (10)");
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
			ShowProgressbar(playerid, "Mengolah kanabis", 15);
			SetTimerEx("proseskanabis", 15000, false, "i", playerid);
		}
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 2304.7258,-1788.7726,1600.7520))
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(Inventory_Count(playerid, "Kanabis") < 10) return ErrorMsg(playerid, "Kanabis anda tidak mencukupi (10)");
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
			ShowProgressbar(playerid, "Mengolah kanabis", 15);
			SetTimerEx("proseskanabis", 15000, false, "i", playerid);
		}
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 2304.6892,-1784.3356,1600.7520))
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(Inventory_Count(playerid, "Kanabis") < 10) return ErrorMsg(playerid, "Kanabis anda tidak mencukupi (10)");
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
			ShowProgressbar(playerid, "Mengolah kanabis", 15);
			SetTimerEx("proseskanabis", 15000, false, "i", playerid);
		}
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 2299.2473,-1784.3361,1600.7520))
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(Inventory_Count(playerid, "Kanabis") < 10) return ErrorMsg(playerid, "Kanabis anda tidak mencukupi (10)");
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
			ShowProgressbar(playerid, "Mengolah kanabis", 15);
			SetTimerEx("proseskanabis", 15000, false, "i", playerid);
		}
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 2294.6379,-1784.3369,1600.7520))
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(Inventory_Count(playerid, "Kanabis") < 10) return ErrorMsg(playerid, "Kanabis anda tidak mencukupi (10)");
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
			ShowProgressbar(playerid, "Mengolah kanabis", 15);
			SetTimerEx("proseskanabis", 15000, false, "i", playerid);			
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

function proseskanabis(playerid)
{
	switch(random(2))
	{
		case 0:
		{
			Inventory_Remove(playerid, "Kanabis", 1);
			Inventory_Add(playerid, "Marijuana", 1578, 1);
			clearAnimations(playerid);
		}
		case 1:
		{
			Inventory_Remove(playerid, "Kanabis", 1);
			Inventory_Add(playerid, "Marijuana", 1578, 2);
			clearAnimations(playerid);
		}
	}
	return 1;
}