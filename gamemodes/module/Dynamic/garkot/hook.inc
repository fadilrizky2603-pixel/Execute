#include <YSI_Coding/y_hooks>
hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		foreach(new id : Garkot)
		{
			if(IsPlayerInDynamicArea(playerid, gkData[id][gkArea]))
			{
				if(areaid == gkData[id][gkArea])
				{
					TombolY(playerid, "Mengambil Kendaraan");
				}
			}
		}
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		foreach(new id : Garkot)
		{
			if(IsPlayerInDynamicArea(playerid, gkData[id][sgkArea]))
			{
				if(areaid == gkData[id][sgkArea])
				{
					if(IsPlayerAndroid(playerid))
					{
						TombolH(playerid, "Memasukan Kendaraan");
					}
					else
					{
						TombolH(playerid, "Memasukan Kendaraan");
					}
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
	foreach(new id : Garkot)
	{
		if(areaid == gkData[id][gkArea])
		{
			HideInfoTombol(playerid);
		}
		if(areaid == gkData[id][sgkArea])
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
		foreach(new id : Garkot)
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.5, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]))
			{
				return callcmd::pickveh(playerid, "");
			}	
		}
	}
	if(PRESSED(KEY_CROUCH) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		foreach(new id : Garkot)
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.5, gkData[id][sgkX], gkData[id][sgkY], gkData[id][sgkZ]))
			{
				return callcmd::parkveh(playerid, "");
			}	
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}