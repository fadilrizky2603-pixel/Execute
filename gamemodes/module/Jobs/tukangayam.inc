#include <YSI_Coding\y_hooks>
new STREAMER_TAG_AREA:AyamDuty, STREAMER_TAG_AREA:SellAyam,
	STREAMER_TAG_AREA:CutAyam[4], STREAMER_TAG_AREA:OlahAyam[4];

new AyamObject[MAX_PLAYERS][5];

CreateJobAyam1()
{
	AyamDuty = CreateDynamicCircle(1543.54, 21.3636, 1.5, 0, 0, -1);//duty
	SellAyam = CreateDynamicCircle(2753.9253, -2363.1431, 1.5, 0, 0, -1);//jual
	/*Potong*/
	CutAyam[0] = CreateDynamicCircle(-1016.4672, -1037.7102, 1.5, 0, 0, -1);
	CutAyam[1] = CreateDynamicCircle(-1016.4554, -1032.8308, 1.5, 0, 0, -1);
	CutAyam[2] = CreateDynamicCircle(-1020.6729, -1037.3638, 1.5, 0, 0, -1);
	CutAyam[3] = CreateDynamicCircle(-1020.6723, -1032.9146, 1.5, 0, 0, -1);
	/*Olah*/
	OlahAyam[0] = CreateDynamicCircle(-1017.0967, -1045.6171, 1.5, 0, 0, -1);
	OlahAyam[1] = CreateDynamicCircle(-1013.9912, -1042.9500, 1.5, 0, 0, -1);
	OlahAyam[2] = CreateDynamicCircle(-1016.0955, -1043.1119, 1.5, 0, 0, -1);
	OlahAyam[3] = CreateDynamicCircle(-1018.6674, -1042.9143, 1.5, 0, 0, -1);
}

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(pData[playerid][pJob] == 10 || pData[playerid][pJob2] == 10)
		{
			if(areaid == AyamDuty)
			{
				// TombolY(playerid, "Untuk Menu Duty");
			}
			else if(areaid == SellAyam)
			{
				TombolY(playerid, "Untuk Jual/Beli Ayam");
			}
			forex(i, 4)
			{
				if(areaid == CutAyam[i])
				{
					TombolY(playerid, "Untuk Memotong Ayam");
				}
			}
			forex(i, 4)
			{
				if(areaid == OlahAyam[i])
				{
					TombolY(playerid, "Untuk Mengolah Ayam");
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(pData[playerid][pJob] == 10 || pData[playerid][pJob2] == 10)
		{
			if(areaid == AyamDuty)
			{
				HideInfoTombol(playerid);
			}
			else if(areaid == SellAyam)
			{
				HideInfoTombol(playerid);
			}
			forex(i, 4)
			{
				if(areaid == CutAyam[i])
				{
					HideInfoTombol(playerid);
				}
			}
			forex(i, 4)
			{
				if(areaid == OlahAyam[i])
				{
					HideInfoTombol(playerid);
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(pData[playerid][pJob] == 10 || pData[playerid][pJob2] == 10)
	{
		if(newkeys & KEY_YES)
		{
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 2781.684326, -1604.076904, 10.921875))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				new str[1280];
				format(str, sizeof(str), "Nama\t"YELLOW_E"Price\n"WHITE_E"Ayam Packing\t"GREEN_E"$40\n"WHITE_E"Bulu\t"GREEN_E"$15");
				ShowPlayerDialog(playerid, DIALOG_SELL_AYAM, DIALOG_STYLE_TABLIST_HEADERS, "Menu Ayam", str, "Select", "Close");
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1519.3685,23.9024,24.1406))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Ayam Hidup") > 100) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 70 Ayam");
				if(IsValidPlayerObject(playerid, AyamObject[playerid][0]))
				{
					DestroyPlayerObject(playerid, AyamObject[playerid][0]);
					pData[playerid][pTukangAyam] = 2;
					AyamObject[playerid][1] = CreatePlayerObject(playerid, 19079, 1522.2843, 20.5854, 23.118568, 0.000000, 270.000000, 360.000000, 300.0);
					ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.1, 1, 0, 0, 1, 0, 1);
					BarQTE(playerid, "Mengambil Ayam...", "Ayam1");		
				}
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1522.2843,20.5854,24.1406))
			{
				if(pData[playerid][pTukangAyam] == 2)
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Ayam Hidup") > 100) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 70 Ayam");
					if(IsValidPlayerObject(playerid, AyamObject[playerid][1]))
					{
						DestroyPlayerObject(playerid, AyamObject[playerid][1]);
						pData[playerid][pTukangAyam] = 3;
						AyamObject[playerid][2] = CreatePlayerObject(playerid, 19079, 1520.2584, 17.5775, 23.118568, 0.000000, 270.000000, 360.000000, 300.0);
						ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.1, 1, 0, 0, 1, 0, 1);
						BarQTE(playerid, "Mengambil Ayam...", "Ayam1");		
					}
				}
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1520.2584,17.5775,24.1406))
			{
				if(pData[playerid][pTukangAyam] == 3)
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Ayam Hidup") > 100) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 70 Ayam");
					if(IsValidPlayerObject(playerid, AyamObject[playerid][2]))
					{
						DestroyPlayerObject(playerid, AyamObject[playerid][2]);
						pData[playerid][pTukangAyam] = 4;
						AyamObject[playerid][3] = CreatePlayerObject(playerid, 19079, 1515.2158,18.6767,23.118568, 0.000000, 270.000000, 360.000000, 300.0);
						ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.1, 1, 0, 0, 1, 0, 1);
						BarQTE(playerid, "Mengambil Ayam...", "Ayam1");		
					}
				}
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1515.2158,18.6767,24.1406))
			{
				if(pData[playerid][pTukangAyam] == 4)
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Ayam Hidup") > 100) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 70 Ayam");
					if(IsValidPlayerObject(playerid, AyamObject[playerid][3]))
					{
						DestroyPlayerObject(playerid, AyamObject[playerid][3]);
						pData[playerid][pTukangAyam] = 5;
						AyamObject[playerid][4] = CreatePlayerObject(playerid, 19079, 1518.6177, 13.1949, 23.118568, 0.000000, 270.000000, 360.000000, 300.0);
						ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.1, 1, 0, 0, 1, 0, 1);
						BarQTE(playerid, "Mengambil Ayam...", "Ayam1");		
					}
				}
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 1518.6177,13.1949,24.1406))
			{
				if(pData[playerid][pTukangAyam] == 5)
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Ayam Hidup") > 100) return ErrorMsg(playerid, "Inventory anda tidak dapat menampung lebih dari 70 Ayam");
					if(IsValidPlayerObject(playerid, AyamObject[playerid][4]))
					{
						DestroyPlayerObject(playerid, AyamObject[playerid][4]);
						pData[playerid][pTukangAyam] = 1;
						AyamObject[playerid][0] = CreatePlayerObject(playerid, 19079, 1519.3685, 23.9024, 23.118568, 0.000000, 270.000000, 360.000000, 300.0);
						ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.1, 1, 0, 0, 1, 0, 1);
						BarQTE(playerid, "Mengambil Ayam...", "Ayam1");		
					}
				}
			}
			forex(i, 4)
			{
				if(IsPlayerInDynamicArea(playerid, CutAyam[i]))
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Ayam Hidup") < 1)
						return ErrorMsg(playerid, "Anda tidak memiliki ayam hidup!");

					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
					BarQTE(playerid, "Memotonfg Ayam...", "PotongAyam");		
				}
			}
			forex(i, 4)
			{
				if(IsPlayerInDynamicArea(playerid, OlahAyam[i]))
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Ayam Potong") < 1)
						return ErrorMsg(playerid, "Anda tidak memiliki ayam potong!");

					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
					BarQTE(playerid, "Packing Ayam...", "Packing");		
				}
			}
		}
	}
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
	AyamObject[playerid][0] = CreatePlayerObject(playerid, 19079, 1519.3685, 23.9024, 23.118568, 0.000000, 270.000000, 360.000000, 300.0);	
	return Y_HOOKS_CONTINUE_RETURN_1;
}


function Ayam1(playerid)
{
    Inventory_Add(playerid, "Ayam Hidup", 16776, 1);
    return 1;
}

function PotongAyam(playerid)
{
	clearAnimations(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    Inventory_Remove(playerid, "Ayam Hidup", 1);
    Inventory_Add(playerid, "Ayam Potong", 2804, RandomEx(2, 4));
    return 1;
}

function Packing(playerid)
{
	clearAnimations(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    Inventory_Remove(playerid, "Ayam Potong", 3);
    Inventory_Add(playerid, "Ayam Packing", 2770, 1);
    return 1;
}