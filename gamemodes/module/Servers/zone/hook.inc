#include <YSI_Coding\y_hooks>

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(IsPlayerInDynamicArea(playerid, eaData[playerid][balkot]))
		{
			if(areaid == eaData[playerid][balkot])
			{
				TombolY(playerid, "Untuk Menu pemerintah");
			}
		}
		if(IsPlayerInDynamicArea(playerid, eaData[playerid][centraljob]))
		{
			if(areaid == eaData[playerid][centraljob])
			{
				TombolY(playerid, "Untuk Menu Job");
			}
		}
		if(IsPlayerInDynamicArea(playerid, eaData[playerid][farmer]))
		{
			if(areaid == eaData[playerid][farmer])
			{
				TombolY(playerid, "Untuk Menu Farmer");
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP:checkpointid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(IsPlayerInDynamicCP(playerid, eaData[playerid][Buysusu]))
		{
			if(checkpointid == eaData[playerid][Buysusu])
			{
				TombolY(playerid, "Untuk Beli/Jual Susu");
			}
		}
		else if(IsPlayerInDynamicCP(playerid, eaData[playerid][jobfarmer]))
		{
			if(checkpointid == eaData[playerid][jobfarmer])
			{
				TombolY(playerid, "Untuk Beli/Jual Bahan");
			}
		}
		else if(IsPlayerInDynamicCP(playerid, eaData[playerid][Crafting]))
		{
			if(checkpointid == eaData[playerid][Crafting])
			{
				TombolY(playerid, "Untuk Crafting");
			}
		}
		else if(IsPlayerInDynamicCP(playerid, eaData[playerid][Showroom]))
		{
			if(checkpointid == eaData[playerid][Showroom])
			{
				TombolY(playerid, "Untuk Beli Kendaraan");
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP:checkpointid)
{
	if(checkpointid == eaData[playerid][Buysusu])
	{
		HideInfoTombol(playerid);
	}
	if(checkpointid == eaData[playerid][jobfarmer])
	{
		HideInfoTombol(playerid);
	}
	if(checkpointid == eaData[playerid][Crafting])
	{
		HideInfoTombol(playerid);
	}
	if(checkpointid == eaData[playerid][Showroom])
	{
		HideInfoTombol(playerid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
	if(areaid == eaData[playerid][balkot])
	{
		HideInfoTombol(playerid);
	}
	if(areaid == eaData[playerid][centraljob])
	{
		HideInfoTombol(playerid);
	}
	if(areaid == eaData[playerid][farmer])
	{
		HideInfoTombol(playerid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}