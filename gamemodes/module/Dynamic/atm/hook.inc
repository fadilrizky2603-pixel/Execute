#include <YSI_Coding\y_hooks>

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		foreach(new id : ATMS)
		{
			if(IsPlayerInDynamicArea(playerid, AtmData[id][atmArea]))
			{
				if(areaid == AtmData[id][atmArea])
				{
					TombolY(playerid, "Membuka atm");
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
	foreach(new id : ATMS)
	{
		if(areaid == AtmData[id][atmArea])
		{
			HideInfoTombol(playerid);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_YES) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		foreach(new id : ATMS)
		{
			if(IsPlayerInRangeOfPoint(playerid, 1.5, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]))
			{
				if(AtmData[id][atmStatus] == 1)
					return Error(playerid, "Atm sedang rusak tidak dapat digunakan");

				ApplyAnimation(playerid, "CRIB", "CRIB_Use_Switch",4.0,0,0,0,0,0);
				for(new i = 0; i < 55; i++)
				{
						PlayerTextDrawShow(playerid, AtmPakCik[playerid][i]);
				}
				HideHunger(playerid);
				HideLogo(playerid);
				new atm[5000];
				format(atm, 1000, "%s", GetRPName(playerid));
				PlayerTextDrawSetString(playerid, AtmPakCik[playerid][16], atm);
				format(atm,1000, "REK:_%d", pData[playerid][pBankRek]);
				PlayerTextDrawSetString(playerid, AtmPakCik[playerid][48], atm);
				format(atm, 1000, "~g~%s~w~_:WALLET", FormatMoney(pData[playerid][pBankMoney]));
				PlayerTextDrawSetString(playerid, AtmPakCik[playerid][17], atm);
				format(atm,1000, "Balance:_~g~%s", FormatMoney(pData[playerid][pMoney]));
				PlayerTextDrawSetString(playerid, AtmPakCik[playerid][47], atm);
				SelectTextDraw(playerid, COLOR_RED);
			}	
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}