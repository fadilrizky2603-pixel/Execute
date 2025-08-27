CMD:despawngs(playerid, params[])
{
	// Sapd Vehicle
	if(IsPlayerInRangeOfPoint(playerid, 8.0, 1245.3647, -2055.2239, 59.8362) || IsPlayerInRangeOfPoint(playerid, 8.0, 1245.3647, -2055.2239, 59.8362)
	|| IsPlayerInRangeOfPoint(playerid, 8.0, 1245.3647, -2055.2239, 59.8362) || IsPlayerInRangeOfPoint(playerid, 8.0, 1245.3647, -2055.2239, 59.8362))
	{
		if(pData[playerid][pFaction] != 2)
	        return ErrorMsg(playerid, "Anda bukan bagian dari SAGS");
	        
		new vehicleid = GetPlayerVehicleID(playerid);
        if(!IsEngineVehicle(vehicleid))
			return ErrorMsg(playerid, "Anda sedang tidak berada di dalam kendaraan");

		DestroyVehicle(vehicleid);

        for(new v = 0; v < sizeof(SAGSVeh); v++)
        {
            if(SAGSVeh[v] == vehicleid)
            {
                SAGSVeh[v] = INVALID_VEHICLE_ID;
                break;
            }
        }
		pData[playerid][pSpawnSags] = 0;
    	InfoTD_MSG(playerid, 4000, "~w~SAGS Vehicles ~r~Despawned");
    }
    return 1;
}

CMD:spawngs(playerid, params[])
{
    // Sapd Vehicle
	if(IsPlayerInRangeOfPoint(playerid, 8.0, 1245.3647, -2055.2239, 59.8362) || IsPlayerInRangeOfPoint(playerid, 8.0, 1245.3647, -2055.2239, 59.8362)
	|| IsPlayerInRangeOfPoint(playerid, 8.0, 1245.3647, -2055.2239, 59.8362) || IsPlayerInRangeOfPoint(playerid, 8.0, 1245.3647, -2055.2239, 59.8362))
	{
		if(pData[playerid][pFaction] != 2)
	        return Error(playerid, "Anda bukan bagian dari SAGS");

	    new ZENN[10000], String[10000];
	    strcat(ZENN, "Vehicles Name\tType\n");
		format(String, sizeof(String), "Stretch\tCars"); //409
		strcat(ZENN, String);
		format(String, sizeof(String), "Hustler\tCars\n"); //545
		strcat(ZENN, String);
		format(String, sizeof(String), "Stafford\tCars\n"); //580
		strcat(ZENN, String);
		format(String, sizeof(String), "Landstalker	\tCars\n"); //400
		strcat(ZENN, String);
		format(String, sizeof(String), "BF-400\tMotorcycle\n"); //581
		strcat(ZENN, String);
		ShowPlayerDialog(playerid,DIALOG_SAGS_GARAGE, DIALOG_STYLE_TABLIST_HEADERS,"Static Vehicles SA:PD", ZENN, "Spawn","Cancel");
	}
	return 1;
}

CMD:gsvault(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 5.0, -995.0111,1456.7094,1340.6270))
	{
		if(pData[playerid][pFaction] != 2)
	        return Error(playerid, "Anda bukan bagian dari SAGS");

		ShowPlayerDialog(playerid, DIALOG_GSVAULT, DIALOG_STYLE_LIST, "Goverments Vault", "Deposit\nWithdraw\n", "Select", "Close");
	}
	return 1;
}

#include <YSI_Coding\y_hooks>

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == DIALOG_SAGS_GARAGE)
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
					SAGSVeh[0] = CreateVehicle(409, x, y, z, a, 3, 3, 700, 0);
					SetVehicleNumberPlate(SAGSVeh[0], "SAGS-1");
					SetValidVehicleHealth(SAGSVeh[0], 3000);
					vCore[SAGSVeh[0]][vFuel] = 100;
					PutPlayerInVehicle(playerid, SAGSVeh[0], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~g~SAGS ~w~berhasil di spawn");
					pData[playerid][pSpawnSags] = 1;
					SetVehicleVirtualWorld(SAGSVeh[0], 0);
			    	LinkVehicleToInterior(SAGSVeh[0], 0);
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
					SAGSVeh[1] = CreateVehicle(545, x, y, z, a, 3, 3, 700, 0);
					vCore[SAGSVeh[1]][vFuel] = 100;
					SetVehicleNumberPlate(SAGSVeh[1], "SAGS-2");
					SetValidVehicleHealth(SAGSVeh[1], 3000);
					PutPlayerInVehicle(playerid, SAGSVeh[1], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~g~SAGS ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAGSVeh[1], 0);
			    	LinkVehicleToInterior(SAGSVeh[1], 0);
					pData[playerid][pSpawnSags] = 1;
				}
				case 2:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SAGSVeh[2] = CreateVehicle(580, x, y, z, a, 3, 3, 700, 0);
					vCore[SAGSVeh[2]][vFuel] = 100;
					SetVehicleNumberPlate(SAGSVeh[2], "SAGS-3");
					SetValidVehicleHealth(SAGSVeh[2], 3000);
					PutPlayerInVehicle(playerid, SAGSVeh[2], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~g~SAGS ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAGSVeh[2], 0);
			    	LinkVehicleToInterior(SAGSVeh[2], 0);
					pData[playerid][pSpawnSags] = 1;
				}
				case 3:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SAGSVeh[3] = CreateVehicle(400, x, y, z, a, 3, 3, 700, 0);
					SetVehicleFuel(SAGSVeh[3], 100);
					vCore[SAGSVeh[3]][vFuel] = 100;
					SetVehicleNumberPlate(SAGSVeh[3], "SAGS-4");
					SetValidVehicleHealth(SAGSVeh[3], 3000);
					PutPlayerInVehicle(playerid, SAGSVeh[3], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~g~SAGS ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAGSVeh[3], 0);
			    	LinkVehicleToInterior(SAGSVeh[3], 0);
					pData[playerid][pSpawnSags] = 1;
				}
				case 4:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SAGSVeh[4] = CreateVehicle(581, x, y, z, a, 3, 3, 700, 0);
					vCore[SAGSVeh[4]][vFuel] = 100;
					SetVehicleNumberPlate(SAGSVeh[4], "SAGS-5");
					SetValidVehicleHealth(SAGSVeh[4], 3000);
					PutPlayerInVehicle(playerid, SAGSVeh[4], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~g~SAGS ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAGSVeh[4], 0);
			    	LinkVehicleToInterior(SAGSVeh[4], 0);
					pData[playerid][pSpawnSags] = 1;
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}
