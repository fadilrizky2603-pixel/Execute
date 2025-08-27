#include <YSI\y_hooks>

new STREAMER_TAG_3D_TEXT_LABEL:ChristmastLabel[4];

hook OnGameModeInit()
{
	ChristmastLabel[0] = CreateDynamic3DTextLabel(""YELLOW"'/xmas'", -1, 1603.327758, -2311.205810, 12.570240 + 2.0, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1, 0);
	ChristmastLabel[1] = CreateDynamic3DTextLabel(""YELLOW"'/xmas'", -1, 2753.635498, -2424.200927, 12.583185 + 2.0, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1, 0);
	ChristmastLabel[2] = CreateDynamic3DTextLabel(""YELLOW"'/xmas'", -1, 2426.088623, -1247.288940, 22.838201 + 2.0, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1, 0);
	ChristmastLabel[3] = CreateDynamic3DTextLabel(""YELLOW"'/xmas'", -1, 1510.782104, -1723.617065, 12.546875 + 2.0, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1, 0);
	ChristmastLabel[3] = CreateDynamic3DTextLabel(""YELLOW"'/xmas'", -1, 377.438049, -2008.618530, 6.830090 + 2.0, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1, 0);
	ChristmastLabel[3] = CreateDynamic3DTextLabel(""YELLOW"'/xmas'", -1, -54.555156, 1061.601074, 18.752178 + 2.0, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1, 0);
	return 1;
}

ChrismastTreeArea(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 3.0, 1603.327758, -2311.205810, 12.570240)) return 1;	
	if(IsPlayerInRangeOfPoint(playerid, 3.0, 2753.635498, -2424.200927, 12.583185)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 3.0, 2426.088623, -1247.288940, 22.838201)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 3.0, 1510.782104, -1723.617065, 12.546875)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 3.0, 377.438049, -2008.618530, 6.830090)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 3.0, -54.555156, 1061.601074, 18.752178)) return 1;
	return 0;
}

CMD:xmas(playerid, params[])
{
	if(AccountData[playerid][pXmasTime] != 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah mengambil hadiah XMAS!");
	if(!ChrismastTreeArea(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada didekat Pohon Natal!");

	new rands = RandomEx(1, 100);
	switch(rands)
	{
		case 1..5:
		{
			new randomweapon = RandomEx(1, 8);
			GivePlayerWeaponEx(playerid, randomweapon, 1);
		}
		case 6..9:
		{
			GiveMoney(playerid, 550);
			ShowItemBox(playerid, "Uang", "Received_$550", 2);
		}
		case 10..13:
		{
			GiveMoney(playerid, 1500);
			ShowItemBox(playerid, "Uang", "Received_$1,500", 2);
		}
		case 14..20:
		{
			ItemAdd(playerid, "Nasi Goreng", 10);
			ItemAdd(playerid, "Kopi Kenangan", 10);
			ShowItemBox(playerid, "Nasi Goreng", "Received_10x", 2);
			ShowItemBox(playerid, "Kopi Kenangan", "Received_10x", 2);
		}
		case 21..56:
		{
			ItemAdd(playerid, "Pancingan", 5);
			ItemAdd(playerid, "Umpan", 50);
			ShowItemBox(playerid, "Pancingan", "Received_5x", 2);
			ShowItemBox(playerid, "Umpan", "Received_50x", 2);
		}
		case 57..90:
		{
			GiveMoney(playerid, 550);
			ShowItemBox(playerid, "Uang", "Received_$550", 2);
		}
		case 91..99:
		{
			ItemAdd(playerid, "Nasi Goreng", 5);
			ItemAdd(playerid, "Kopi Kenangan", 5);
			ShowItemBox(playerid, "Nasi Goreng", "Received_5x", 2);
			ShowItemBox(playerid, "Kopi Kenangan", "Received_5x", 2);
		}
	}	
	ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda berhasil mengambil hadiah natal!");
	AccountData[playerid][pXmasTime] = gettime() + 43200; // 12 jam 
	return 1;
}