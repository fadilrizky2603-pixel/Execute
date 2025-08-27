CMD:despawnmd(playerid, params[])
{
	// Samd Vehicle
	if(IsPlayerInRangeOfPoint(playerid, 8.0, 2032.25, -1416.00, 16.99) || IsPlayerInRangeOfPoint(playerid, 8.0, 2032.25, -1416.00, 16.99))
	{
		if(pData[playerid][pFaction] != 3)
	        return ErrorMsg(playerid, "Anda bukan bagian dari SAMD");
	        
		new vehicleid = GetPlayerVehicleID(playerid);
        if(!IsEngineVehicle(vehicleid))
			return ErrorMsg(playerid, "Anda sedang tidak berada di dalam kendaraan");
		
		DestroyVehicle(vehicleid);

        for(new v = 0; v < sizeof(SAMDVeh); v++)
        {
            if(SAMDVeh[v] == vehicleid)
            {
                SAMDVeh[v] = INVALID_VEHICLE_ID;
                break;
            }
        }
		pData[playerid][pSpawnSamd] = 0;
    	InfoTD_MSG(playerid, 4000, "~w~SAMD Vehicles ~r~Despawned");
    }
    return 1;
}
CMD:spawnmd(playerid, params[])
{
    // Samd Vehicle
	if(IsPlayerInRangeOfPoint(playerid, 8.0, 2032.25, -1416.00, 16.99))
	{
		if(pData[playerid][pFaction] != 3)
	        return ErrorMsg(playerid, "Anda bukan bagian dari SAMD");

	    new Zann[10000], String[10000];
	    strcat(Zann, "Vehicles Name\tType\n");
		format(String, sizeof(String), "Ambulance\tCars\n");// 416
		strcat(Zann, String);
		format(String, sizeof(String), "Fire Truck\tCars\n");// 407
		strcat(Zann, String);
		format(String, sizeof(String), "Premier\tCars\n"); // 426
		strcat(Zann, String);
		ShowPlayerDialog(playerid,DIALOG_SAMD_GARAGE, DIALOG_STYLE_TABLIST_HEADERS,"Static Vehicles SA:MD", Zann, "Spawn","Cancel");
	}
	return 1;
}

// STATISTIC VEHICLE SAMD //
#include <YSI_Coding\y_hooks>

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == DIALOG_SAMD_GARAGE)
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
					SAMDVeh[0] = CreateVehicle(416, x, y, z, a, 1, 3, 700, 1);
					SetVehicleNumberPlate(SAMDVeh[0], "SAMD-1");
					SetValidVehicleHealth(SAMDVeh[0], 3000);
					vCore[SAMDVeh[0]][vFuel] = 100;
					PutPlayerInVehicle(playerid, SAMDVeh[0], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~r~SAMD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAMDVeh[0], 0);
			    	LinkVehicleToInterior(SAMDVeh[0], 0);
					pData[playerid][pSpawnSamd] = 1;
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
					SAMDVeh[1] = CreateVehicle(407, x, y, z, a, 1, 3, 700, 1);
					SetVehicleNumberPlate(SAMDVeh[1], "SAMD-2");
					SetValidVehicleHealth(SAMDVeh[1], 3000);
					vCore[SAMDVeh[1]][vFuel] = 100;
					PutPlayerInVehicle(playerid, SAMDVeh[1], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~r~SAMD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAMDVeh[1], 0);
			    	LinkVehicleToInterior(SAMDVeh[1], 0);
					pData[playerid][pSpawnSamd] = 1;
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
					SAMDVeh[2] = CreateVehicle(426, x, y, z, a, 3, 3, 700, 1);
					SetVehicleNumberPlate(SAMDVeh[2], "SAMD-3");
					SetValidVehicleHealth(SAMDVeh[2], 3000);
					tmpobjid = CreateDynamicObject(19620,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
					AttachDynamicObjectToVehicle(tmpobjid, SAMDVeh[2], 0.000, -0.100, 0.659, 0.000, 0.000, 0.000);
					vCore[SAMDVeh[2]][vFuel] = 100;
					PutPlayerInVehicle(playerid, SAMDVeh[2], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~r~SAMD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAMDVeh[2], 0);
			    	LinkVehicleToInterior(SAMDVeh[2], 0);
					pData[playerid][pSpawnSamd] = 1;
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

/*CMD:callsign(playerid, params[])
{
    new vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
	new string[32];
	if(!IsPlayerInAnyVehicle(playerid))
		return Error(playerid, "You're not in a vehicle.");

	if (pData[playerid][pFaction] != 1 && pData[playerid][pFaction] != 3)
		return Error(playerid, "You must be a SAPD or SAMD!");

	if(vehiclecallsign[GetPlayerVehicleID(playerid)] == 1)
	{
 		Delete3DTextLabel(vehicle3Dtext[vehicleid]);
	    vehiclecallsign[vehicleid] = 0;
	    SendClientMessage(playerid, COLOR_RED, "CALLSIGN: {FFFFFF}Callsign removed.");
	    return 1;
	}
	if(sscanf(params, "s[32]",string))
		return SendSyntaxMessage(playerid, "/callsign [callsign]");

	if(vehiclecallsign[GetPlayerVehicleID(playerid)] == 0)
	{
		vehicle3Dtext[vehicleid] = Create3DTextLabel(string, COLOR_WHITE, 0.0, 0.0, 0.0, 10.0, 0, 1);
		Attach3DTextLabelToVehicle(vehicle3Dtext[vehicleid], vehicleid, 0.0, -2.8, 0.0);
		vehiclecallsign[vehicleid] = 1;
		SendClientMessage(playerid, COLOR_RED, "CALLSIGN: {FFFFFF}Type {FFFF00}/callsign {FFFFFF}again to remove.");
	}
	return 1;
}*/
