CMD:despawnpd(playerid, params[])
{
	// Sapd Vehicle
	if(IsPlayerInRangeOfPoint(playerid, 8.0, 1068.30, -1667.76, 14.01))
	{
		if(pData[playerid][pFaction] != 1)
	        return ErrorMsg(playerid, "Anda bukan bagian dari SAPD");
	        
		new vehicleid = GetPlayerVehicleID(playerid);
        if(!IsEngineVehicle(vehicleid))
			return ErrorMsg(playerid, "Anda sedang tidak berada di dalam kendaraan");
		
		DestroyVehicle(vehicleid);

        for(new v = 0; v < sizeof(SAPDVeh); v++)
        {
            if(SAPDVeh[v] == vehicleid)
            {
                SAPDVeh[v] = INVALID_VEHICLE_ID;
                break;
            }
        }

		pData[playerid][pSpawnSapd] = 0;
    	InfoTD_MSG(playerid, 4000, "~w~SAPD Vehicles ~r~Despawned");
    }
    return 1;
}

CMD:spawnpd(playerid, params[])
{
    // Sapd Vehicle
	if(IsPlayerInRangeOfPoint(playerid, 8.0, 1068.30, -1667.76, 14.01))
	{
		if(pData[playerid][pFaction] != 1)
	        return ErrorMsg(playerid, "Anda bukan bagian dari SAPD");

	    new ZENN[10000], String[10000];
	    strcat(ZENN, "Vehicles Name\tType\n");
		format(String, sizeof(String), "Police LS (1-ADAM-2)\tCars\n");// 596
		strcat(ZENN, String);
		format(String, sizeof(String), "Police LS (1-LINCOLN-2)\tCars\n");// 596
		strcat(ZENN, String);
		format(String, sizeof(String), "Police LS (1-JOHN-2)\tCars\n");// 596
		strcat(ZENN, String);
		format(String, sizeof(String), "Police Ranger (1-ALPHA-2)\tCars\n"); // 599
		strcat(ZENN, String);
		format(String, sizeof(String), "Police S.W.A.T (1-RAPID-2)\tCars\n"); // 601
		strcat(ZENN, String);
		format(String, sizeof(String), "Enforcer (1-KING-2)\tCars\n"); // 427
		strcat(ZENN, String);
		format(String, sizeof(String), "F.B.I Truck (1-VICTOR-2)\tCars\n"); // 528
		strcat(ZENN, String);
		format(String, sizeof(String), "Police Sultan (STAFF-2)\tUnique Cars\n"); // 560
		strcat(ZENN, String);
		format(String, sizeof(String), "Police Bullet (1-HOTEL-2)\tUnique Cars\n"); //541
		strcat(ZENN, String);
		format(String, sizeof(String), "Police HPV-1000 (1-MARY-1)\tMotorcycle\n");  // 523
		strcat(ZENN, String);
		format(String, sizeof(String), "Police TowTruck (SAPD-TW)\tTruck\n");// 596
		strcat(ZENN, String);
		ShowPlayerDialog(playerid,DIALOG_SAPD_GARAGE, DIALOG_STYLE_TABLIST_HEADERS,"Static Vehicles SA:PD", ZENN, "Spawn","Cancel");
	}
	return 1;
}

#include <YSI_Coding\y_hooks>

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == DIALOG_SAPD_GARAGE)
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
					SAPDVeh[0] = CreateVehicle(596, x, y, z, a, 0, 1, 700, 1);
					SetVehicleNumberPlate(SAPDVeh[0], "1-ADAM-2");
					SetValidVehicleHealth(SAPDVeh[0], 3000);
					vCore[SAPDVeh[0]][vFuel] = 100;
					AddVehicleComponent(SAPDVeh[0], 1010);
					PutPlayerInVehicle(playerid, SAPDVeh[0], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[0], 0);
			    	LinkVehicleToInterior(SAPDVeh[0], 0);
					pData[playerid][pSpawnSapd] = 1;
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
					SAPDVeh[1] = CreateVehicle(596, x, y, z, a, 0, 1, 700, 1);
					vCore[SAPDVeh[1]][vFuel] = 100;
					AddVehicleComponent(SAPDVeh[1], 1010);
					SetVehicleNumberPlate(SAPDVeh[1], "1-LINCOLN-2");
					SetValidVehicleHealth(SAPDVeh[1], 3000);
					PutPlayerInVehicle(playerid, SAPDVeh[1], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[1], 0);
			    	LinkVehicleToInterior(SAPDVeh[1], 0);
					pData[playerid][pSpawnSapd] = 1;
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
					SAPDVeh[2] = CreateVehicle(596, x, y, z, a, 0, 1, 700, 1);
					vCore[SAPDVeh[2]][vFuel] = 100;
					AddVehicleComponent(SAPDVeh[2], 1010);
					SetVehicleNumberPlate(SAPDVeh[2], "1-JOHN-2");
					SetValidVehicleHealth(SAPDVeh[2], 3000);
					PutPlayerInVehicle(playerid, SAPDVeh[2], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[2], 0);
			    	LinkVehicleToInterior(SAPDVeh[2], 0);
					pData[playerid][pSpawnSapd] = 1;
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
					SAPDVeh[3] = CreateVehicle(599, x, y, z, a, 0, 1, 700, 1);
					vCore[SAPDVeh[3]][vFuel] = 100;
					AddVehicleComponent(SAPDVeh[3], 1010);
					SetVehicleNumberPlate(SAPDVeh[3], "1-ALPHA-2");
					SetValidVehicleHealth(SAPDVeh[3], 3000);
					PutPlayerInVehicle(playerid, SAPDVeh[3], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[3], 0);
			    	LinkVehicleToInterior(SAPDVeh[3], 0);
					pData[playerid][pSpawnSapd] = 1;
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
					SAPDVeh[4] = CreateVehicle(601, x, y, z, a, 0, 1, 700, 1);
					vCore[SAPDVeh[4]][vFuel] = 100;
					AddVehicleComponent(SAPDVeh[4], 1010);
					SetVehicleNumberPlate(SAPDVeh[4], "1-RAPID-2");
					SetValidVehicleHealth(SAPDVeh[4], 3000);
					PutPlayerInVehicle(playerid, SAPDVeh[4], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[4], 0);
			    	LinkVehicleToInterior(SAPDVeh[4], 0);
					pData[playerid][pSpawnSapd] = 1;
				}
				case 5:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SAPDVeh[5] = CreateVehicle(427, x, y, z, a, 0, 1, 700, 1);
					vCore[SAPDVeh[5]][vFuel] = 100;
					AddVehicleComponent(SAPDVeh[5], 1010);
					SetVehicleNumberPlate(SAPDVeh[5], "1-KING-2");
					SetValidVehicleHealth(SAPDVeh[5], 3000);
					PutPlayerInVehicle(playerid, SAPDVeh[5], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[5], 0);
			    	LinkVehicleToInterior(SAPDVeh[5], 0);
					pData[playerid][pSpawnSapd] = 1;
				}
				case 6:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SAPDVeh[6] = CreateVehicle(528, x, y, z, a, 0, 1, 700, 1);
					vCore[SAPDVeh[6]][vFuel] = 100;
					AddVehicleComponent(SAPDVeh[6], 1010);
					SetVehicleNumberPlate(SAPDVeh[6], "1-VICTOR-2");
					SetValidVehicleHealth(SAPDVeh[6], 3000);
					PutPlayerInVehicle(playerid, SAPDVeh[6], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[6], 0);
			    	LinkVehicleToInterior(SAPDVeh[6], 0);
					pData[playerid][pSpawnSapd] = 1;
				}
				case 7:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SAPDVeh[7] = CreateVehicle(560, x, y, z, a, 0, 0, 700, 1);
					vCore[SAPDVeh[7]][vFuel] = 100;
					AddVehicleComponent(SAPDVeh[7], 1010);
					tmpobjid = CreateDynamicObject(19419,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
					AttachDynamicObjectToVehicle(tmpobjid, SAPDVeh[7], 0.000, -0.290, 0.800, 0.000, 0.000, 0.000);
					tmpobjid = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
					SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
					SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF}911", 130, "Quartz MS", 25, 1, 0, 0, 1);
					AttachDynamicObjectToVehicle(tmpobjid, SAPDVeh[7], 1.061, 0.631, 0.180, 0.000, 0.000, 0.000);
					tmpobjid = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
					SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
					SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF}911", 130, "Quartz MS", 25, 1, 0, 0, 1);
					AttachDynamicObjectToVehicle(tmpobjid, SAPDVeh[7], -1.069, 0.609, 0.200, 0.000, 0.000, 178.100);
					tmpobjid = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
					SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
					SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF}SAPD", 130, "Quartz MS", 40, 1, 0, 0, 1);
					AttachDynamicObjectToVehicle(tmpobjid, SAPDVeh[7], 1.071, 0.320, -0.080, 0.000, 0.000, 0.000);
					tmpobjid = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
					SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
					SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF}SAPD", 130, "Quartz MS", 40, 1, 0, 0, 1);
					AttachDynamicObjectToVehicle(tmpobjid, SAPDVeh[7], -1.076, 0.340, -0.080, 0.000, 0.000, -178.999);
					SetVehicleNumberPlate(SAPDVeh[7], "STAFF-2");
					SetValidVehicleHealth(SAPDVeh[7], 3000);
					PutPlayerInVehicle(playerid, SAPDVeh[7], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[7], 0);
			    	LinkVehicleToInterior(SAPDVeh[7], 0);
					pData[playerid][pSpawnSapd] = 1;
				}
				case 8:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SAPDVeh[8] = CreateVehicle(541, x, y, z, a, 0, 0, 700, 1);
					vCore[SAPDVeh[8]][vFuel] = 100;
					AddVehicleComponent(SAPDVeh[8], 1010);
					SetVehicleNumberPlate(SAPDVeh[8], "1-HOTEL-2");
					SetValidVehicleHealth(SAPDVeh[8], 3000);
					PutPlayerInVehicle(playerid, SAPDVeh[8], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[8], 0);
			    	LinkVehicleToInterior(SAPDVeh[8], 0);
					pData[playerid][pSpawnSapd] = 1;
				}
				case 9:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SAPDVeh[9] = CreateVehicle(523, x, y, z, a, 0, 1, 700, 1);
					vCore[SAPDVeh[9]][vFuel] = 100;
					AddVehicleComponent(SAPDVeh[9], 1010);
					SetVehicleNumberPlate(SAPDVeh[9], "1-MARY-1");
					SetValidVehicleHealth(SAPDVeh[9], 3000);
					PutPlayerInVehicle(playerid, SAPDVeh[9], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[9], 0);
			    	LinkVehicleToInterior(SAPDVeh[9], 0);
					pData[playerid][pSpawnSapd] = 1;
				}
				case 10:
				{
					static
						Float:x,
						Float:y,
						Float:z,
						Float:a;
					GetPlayerPos(playerid, x, y, z);
					GetPlayerFacingAngle(playerid, a);
					SAPDVeh[10] = CreateVehicle(525, x, y, z, a, 0, 1, 700, 1);
					SetVehicleNumberPlate(SAPDVeh[10], "SAPD-TW");
					SetValidVehicleHealth(SAPDVeh[10], 3000);
					vCore[SAPDVeh[10]][vFuel] = 100;
					PutPlayerInVehicle(playerid, SAPDVeh[10], 0);
					InfoTD_MSG(playerid, 4000, "Kendaraan ~b~SAPD ~w~berhasil di spawn");
					SetVehicleVirtualWorld(SAPDVeh[10], 0);
			    	LinkVehicleToInterior(SAPDVeh[10], 0);
					pData[playerid][pSpawnSapd] = 1;
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}