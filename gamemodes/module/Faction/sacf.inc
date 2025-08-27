/*

	SAN ANDREAS CAFE FOOD

*/
#include <YSI_Coding\y_hooks>

enum E_SACFAREA
{
	STREAMER_TAG_CP:Masaksacf
}
new Sacfarea[MAX_PLAYERS][E_SACFAREA];

DeleteSacfMap(playerid)
{
	if(IsValidDynamicCP(Sacfarea[playerid][Masaksacf]))
	{
		DestroyDynamicCP(Sacfarea[playerid][Masaksacf]);
		Sacfarea[playerid][Masaksacf] = STREAMER_TAG_CP: -1;
	}
}

RefreshMapSacf(playerid)
{
	DeleteSacfMap(playerid);

	if(pData[playerid][pFaction] == 5)
	{
		if(!pData[playerid][pOndutysacf])
		{
			Sacfarea[playerid][Masaksacf] = CreateDynamicCP(589.003, -1811.97, 6.37406, 1.5, -1, -1, -1, 30.0);
		}
		else
		{
			Sacfarea[playerid][Masaksacf] = CreateDynamicCP(0.0, 0.0, 0.0, 0.0, -1, -1, -1, 0.0);
		}
	}
	return 1;
}

hook OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP:checkpointid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && pData[playerid][pFaction] == 5 && pData[playerid][pOndutysacf] == true)
	{
		if(IsPlayerInDynamicCP(playerid, Sacfarea[playerid][Masaksacf]))
		{
			if(checkpointid == Sacfarea[playerid][Masaksacf])
			{
				TombolY(playerid, "Untuk Memasak");
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP:checkpointid)
{
	if(checkpointid == Sacfarea[playerid][Masaksacf])
	{
		HideInfoTombol(playerid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && pData[playerid][pFaction] == 5 && pData[playerid][pOndutysacf] == true)
    {
    	if(IsPlayerInRangeOfPoint(playerid, 1.5, 332.35, -1829.42, 4.49))
    	{
    		return callcmd::cooking(playerid, "");
    	}
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

CMD:despawncf(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 8.0, 564.6272,-1800.2198,6.0625) || IsPlayerInRangeOfPoint(playerid, 8.0, 564.6272,-1800.2198,6.0625)
	|| IsPlayerInRangeOfPoint(playerid, 8.0, 564.6272,-1800.2198,6.0625) || IsPlayerInRangeOfPoint(playerid, 8.0, 564.6272,-1800.2198,6.0625))
	{
		if(pData[playerid][pFaction] != 5)
			return ErrorMsg(playerid, "Anda bukan bagian dari SACF");

		new vehicleid = GetPlayerVehicleID(playerid);
		if(!IsEngineVehicle(vehicleid))
			return ErrorMsg(playerid, "Anda sedang tidak berada didalam kendaraan.");

		DestroyVehicle(vehicleid);
		
        for(new v = 0; v < sizeof(SACFVeh); v++)
        {
            if(SACFVeh[v] == vehicleid)
            {
                SACFVeh[v] = INVALID_VEHICLE_ID;
                break;
            }
        }

		pData[playerid][pSpawnSacf] = 0;
		InfoTD_MSG(playerid, 4000, "~w~SACF Vehicles ~r~Despawned");
	}
	return 1;
}

CMD:spawncf(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 8.0, 564.6272,-1800.2198,6.0625) || IsPlayerInRangeOfPoint(playerid, 8.0, 564.6272,-1800.2198,6.0625)
	|| IsPlayerInRangeOfPoint(playerid, 8.0, 564.6272,-1800.2198,6.0625) || IsPlayerInRangeOfPoint(playerid, 8.0, 564.6272,-1800.2198,6.0625))
	{
		if(pData[playerid][pFaction] != 5)
			return ErrorMsg(playerid, "Anda bukan bagian dari SACF");
			
		new Zann[10000], String[10000];
		strcat(Zann, "Vehicles Name\tType\n");
		format(String, sizeof(String), "Pizza Boy\tMotorcycle\n");// 448
		strcat(Zann, String);
		format(String, sizeof(String), "Hot Dog\tCars\n");// 588
		strcat(Zann, String);
		ShowPlayerDialog(playerid, DIALOG_SACF_GARAGE, DIALOG_STYLE_TABLIST_HEADERS,"Static Vehicles SA:CF", Zann, "Spawn","Cancel");
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == DIALOG_SACF_GARAGE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SACFVeh[0] = CreateVehicle(448, x, y, z, a, 1, 3, 700, 0);
					SetVehicleNumberPlate(SACFVeh[0], "SACF-1");
					SetVehicleFuel(SACFVeh[0], 100);
					PutPlayerInVehicle(playerid, SACFVeh[0], 0);
					SetVehicleVirtualWorld(SACFVeh[0], 0);
			    	LinkVehicleToInterior(SACFVeh[0], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~r~SACF ~w~berhasil di spawn");
					pData[playerid][pSpawnSacf] = 1;
				}
				case 1:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SACFVeh[1] = CreateVehicle(588, x, y, z, a, 1, 3, 700, 0);
					SetVehicleNumberPlate(SACFVeh[1], "SACF-2");
					SetVehicleFuel(SACFVeh[1], 100);
					PutPlayerInVehicle(playerid, SACFVeh[1], 0);
					SetVehicleVirtualWorld(SACFVeh[1], 0);
			    	LinkVehicleToInterior(SACFVeh[1], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~r~SACF ~w~berhasil di spawn");
					pData[playerid][pSpawnSacf] = 1;
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}