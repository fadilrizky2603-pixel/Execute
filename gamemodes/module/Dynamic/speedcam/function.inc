function LoadSpeedcam()
{
    new rows = cache_num_rows();
 	if(rows)
  	{
   		new camid;
		for(new i; i < rows; i++)
		{
  			cache_get_value_name_int(i, "ID", camid);
		    cache_get_value_name_float(i, "camx", camData[camid][camX]);
		    cache_get_value_name_float(i, "camy", camData[camid][camY]);
		    cache_get_value_name_float(i, "camz", camData[camid][camZ]);
		   	cache_get_value_name_float(i, "camrx", camData[camid][camRX]);
		    cache_get_value_name_float(i, "camry", camData[camid][camRY]);
		    cache_get_value_name_float(i, "camrz", camData[camid][camRZ]);
		    cache_get_value_name_int(i, "camworld", camData[camid][camWorld]);
			cache_get_value_name_int(i, "camint", camData[camid][camInt]);
			cache_get_value_name_int(i, "camspeed", camData[camid][camSpeed]);
			Speedcam_Refresh(camid);
			Iter_Add(Speedcam, camid);
	    }
	    printf("[DATABASE] Number of speed cam loaded: %d.", rows);
		//Profiler_Stop();
	}
}


function GetSpeedCam(playerid)
{
	if(pData[playerid][TimerSpeedcam] <= 0)
	{
		foreach(new camid : Speedcam)
		{
			if(IsPlayerInRangeOfPoint(playerid, 15.0, camData[camid][camX], camData[camid][camY], camData[camid][camZ]))
			{
				if(IsPlayerInAnyVehicle(playerid))
				{
					new vehid = GetPlayerVehicleID(playerid);
					foreach(new ii : PVehicles)
					{
						if(vehid == pvData[ii][cVeh])	
						{
							if(EVF::GetVehicleSpeed(pvData[ii][cVeh]) > camData[camid][camSpeed])
							{
								pData[playerid][TimerSpeedcam] = 10;
								Info(playerid, "Kamu melebehi batas kecepatan di wilayah ini, kecepatan mu %.0f/Mph", EVF::GetVehicleSpeed(pvData[ii][cVeh]));
								if(pData[playerid][pTogSpeedcam] == 0)
								{
									SendFactionMessage(1, COLOR_RADIO, "[SPEED CAM] has seen a vehicle that exceeds the speed");
									SendFactionMessage(1, COLOR_RADIO, "Location : %s || Model : %s || Plate : %s || Vehicle Speed : %.0f/Mph", GetLocation(camData[camid][camX], camData[camid][camY], camData[camid][camZ]), GetVehicleName(pvData[ii][cVeh]), pvData[ii][cPlate], EVF::GetVehicleSpeed(pvData[ii][cVeh]));
								}	
								return 1;
							}
						}
					}
				}
			}
		}
	}
	return 1;
}

function OnSpeedcamCreated(camid)
{
	Speedcam_Save(camid);
	return 1;
}




