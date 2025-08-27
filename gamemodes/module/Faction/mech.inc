// Private Vehicle Components

#include <YSI_Coding/y_hooks>

new pv_spoiler[20] = 
{
    1000, 1001, 1002, 1003, 1014, 1015, 1016, 1023, 1058, 1060,
    1049, 1050, 1138, 1139, 1146, 1147, 1158, 1162, 1163, 1164
};

new pv_nitro[3] = {1008, 1009, 1010};

new pv_fbumper[23] = {1117, 1152, 1153, 1155, 1157, 1160, 1165, 1166, 1169, 1170,
                      1171, 1172, 1173, 1174, 1175, 1179, 1181, 1182, 1185, 1188,
                      1189, 1190, 1191};

new pv_rbumper[22] = 
{
    1140, 1141, 1148, 1149, 1150, 1151, 1154, 1156, 1159, 1161,
    1167, 1168, 1176, 1177, 1178, 1180, 1183, 1184, 1186, 1187,
    1192, 1193
};

new pv_exhaust[28] = 
{
    1018, 1019, 1020, 1021, 1022, 1028, 1029, 1037, 1043, 1044,
    1045, 1046, 1059, 1064, 1065, 1066, 1089, 1092, 1104, 1105,
    1113, 1114, 1126, 1127, 1129, 1132, 1135, 1136
};

new pv_bventr[2] = {1142, 1144};
new pv_bventl[2] = {1143, 1145};
new pv_bscoop[4] = {1004, 1005, 1011, 1012};

new pv_roof[17] = {1006, 1032, 1033, 1035, 1038, 1053, 1054, 1055, 1061, 1067, 1068, 1088, 1091, 1103, 1128, 1130, 1131};
new pv_lskirt[21] = {1007, 1026, 1031, 1036, 1039, 1042, 1047, 1048, 1056, 1057, 1069, 1070, 1090, 1093, 1106, 1108, 1118, 1119, 1133, 1122, 1134};
new pv_rskirt[21] = {1017, 1027, 1030, 1040, 1041, 1051, 1052, 1062, 1063, 1071, 1072, 1094, 1095, 1099, 1101, 1102, 1107, 1120, 1121, 1124, 1137};
new pv_hydraulics[1] = {1087};
new pv_base[1] = {1086};
new pv_rbbars[4] = {1109, 1110, 1123, 1125};
new pv_fbbars[2] = {1115, 1116};
new pv_wheels[17] = {1025, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1096, 1097, 1098};

new pv_lights[2] = {1013, 1024};


//Mechanic jobs
CMD:mechduty(playerid, params[])
{
	if(pData[playerid][pFaction] == 6)
	{		
		if(pData[playerid][pMechDuty] == 0)
		{
			pData[playerid][pMechDuty] = 1;
			SetPlayerColor(playerid, COLOR_ORANGE);
			//SendClientMessageToAllEx(COLOR_GREEN, "[MECH]"WHITE_E" %s is now on Mehcanic Duty. Type \"/call 1222\" to call a taxi!", ReturnName(playerid, 0));
		}
		else
		{
			pData[playerid][pMechDuty] = 0;
			SetPlayerColor(playerid, COLOR_WHITE);
			InfoMsg(playerid, "Anda telah off dari mech duty!");
		}
	}
	else return ErrorMsg(playerid, "Anda bukan pekerja mechanic!");
	return 1;
}

CMD:createkit(playerid, const params[])
{
	if(pData[playerid][pFaction] == 6)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, 192.998992, -265.421997, 1.597936))
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(Inventory_Count(playerid, "Component") < 100)
				return Error(playerid, "Kamu harus memiliki 100 component untuk membuat ini");

			if(pData[playerid][pActivityTime] > 5)
				return Error(playerid, "Kamu masih memiliki activity progress");

			TogglePlayerControllable(playerid, 0);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
			pData[playerid][pMechanic] = SetTimerEx("CreateRepairkit", 10000, false, "i", playerid);
			ShowProgressbar(playerid, "Creating...", 10);
		}
		else return Error(playerid, "Kamu harus berada di point repairkit maker");
	}
	else return Error(playerid, "Kamu bukan pekerja mechanic");
	return 1;
}

function CreateRepairkit(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pFaction] == 6)
	{
		{
			if(IsPlayerInRangeOfPoint(playerid, 4.5, 192.998992, -265.421997, 1.597936))
			{
				TogglePlayerControllable(playerid, 1);
				Info(playerid, "Kamu telah selesai membuat 1 repairkit.");
				SuccesMsg(playerid, "Succes Created!");
				pData[playerid][pEnergy] -= 3;
				Inventory_Remove(playerid, "Component", 100);
				Inventory_Add(playerid, "Repair Kit", 920, 1);
				ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.1, 0, 0, 0, 0, 0, 1);
			}
		}
	}
	return 1;
}

//Mech JOB
function CheckCar(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pFaction] == 6 || pData[playerid][pWorkshop] != -1)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.5, false) == vehicleid)
		{
			if(IsValidVehicle(vehicleid))
			{
				pData[playerid][pMechVeh] = vehicleid;
				SuccesMsg(playerid, "Checking done!");
				clearAnimations(playerid);
				return 1;
			}
		}
	}
	return 1;
}

function BodyFix(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pFaction] == 6 || pData[playerid][pWorkshop] != -1)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.5, false) == vehicleid)
		{
			if(IsValidVehicle(vehicleid))
			{
				new panels, doors, light, tires;	
				GetVehicleDamageStatus(vehicleid, panels, doors, light, tires);		
				UpdateVehicleDamageStatus(vehicleid, 0, 0, 0, tires);
				ValidRepairVehicle(vehicleid);
				SuccesMsg(playerid, "Fix body done!");
				pData[playerid][pMechVeh] = vehicleid;
				clearAnimations(playerid);
				return 1;
			}
		}
	}
	return 1;
}

function EngineUpgrade(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pFaction] == 6 || pData[playerid][pWorkshop] != -1)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(IsValidVehicle(vehicleid))
			{
				SetValidVehicleHealth(vehicleid, 2000);
				SuccesMsg(playerid, "Upgrade engine done!");
				pData[playerid][pMechVeh] = vehicleid;
				clearAnimations(playerid);
				return 1;
			}
		}
	}
	return 1;
}

function EngineFix(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pFaction] == 6 || pData[playerid][pWorkshop] != -1)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(IsValidVehicle(vehicleid))
			{
				SetValidVehicleHealth(vehicleid, 1000);
				SuccesMsg(playerid, "Fix engine done!");
				pData[playerid][pMechVeh] = vehicleid;
				clearAnimations(playerid);
				return 1;
			}
		}
	}
	return 1;
}

function SprayCar(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pFaction] == 6 || pData[playerid][pWorkshop] != -1)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(IsValidVehicle(vehicleid))
			{
				
				ChangeVehicleColor(vehicleid, pData[playerid][pMechColor1], pData[playerid][pMechColor2]);
				foreach(new ii : PVehicles)
				{
					if(vehicleid == pvData[ii][cVeh])
					{
						pvData[ii][cColor1] = pData[playerid][pMechColor1];
						pvData[ii][cColor2] = pData[playerid][pMechColor2];
					}
				}
				SuccesMsg(playerid, "Spraying done!");
				pData[playerid][pMechVeh] = vehicleid;
				clearAnimations(playerid);
				return 1;
			}
		}
	}
	return 1;
}

function PaintjobCar(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pFaction] == 6 || pData[playerid][pWorkshop] != -1)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(IsValidVehicle(vehicleid))
			{
				
				ChangeVehiclePaintjob(vehicleid, pData[playerid][pMechColor1]);
				foreach(new ii : PVehicles)
				{
					if(vehicleid == pvData[ii][cVeh])
					{
						pvData[ii][cPaintJob] = pData[playerid][pMechColor1];
					}
				}
				SuccesMsg(playerid, "Painting done!");
				pData[playerid][pMechVeh] = vehicleid;
				clearAnimations(playerid);
				return 1;
			}
		}
	}
	return 1;
}

function ModifCar(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pFaction] == 6 || pData[playerid][pWorkshop] != -1)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(IsValidVehicle(vehicleid))
			{
				
				AddVehicleComponent(vehicleid, pData[playerid][pMechColor1]);
				SavePVComponents(vehicleid, pData[playerid][pMechColor1]);
				if(pData[playerid][pMechColor2] != 0)
				{
					AddVehicleComponent(vehicleid, pData[playerid][pMechColor2]);
					SavePVComponents(vehicleid, pData[playerid][pMechColor2]);
				}
				
				SuccesMsg(playerid, "Modif done!");
				pData[playerid][pMechVeh] = vehicleid;
				clearAnimations(playerid);
				PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
				return 1;
			}
		}
	}
	return 1;
}


function NeonCar(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pFaction] == 6 || pData[playerid][pWorkshop] != -1)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(IsValidVehicle(vehicleid))
			{
				if(pData[playerid][pMechColor1] == 0)
				{
					SetVehicleNeonLights(vehicleid, false, pData[playerid][pMechColor1], 0);
				}
				else
				{
					SetVehicleNeonLights(vehicleid, true, pData[playerid][pMechColor1], 0);
				}
				foreach(new ii : PVehicles)
				{
					if(vehicleid == pvData[ii][cVeh])
					{
						pvData[ii][cNeon] = pData[playerid][pMechColor1];
						
						if(pvData[ii][cNeon] == 0)
						{
							pvData[ii][cTogNeon] = 0;
						}
						else
						{
							pvData[ii][cTogNeon] = 1;
						}
					}
				}
				
				SuccesMsg(playerid, "Neon done!");
				pData[playerid][pMechVeh] = vehicleid;
				clearAnimations(playerid);
				return 1;
			}
		}
	}
	return 1;
}


SavePVComponents(vehicleid, componentid)
{
	foreach(new ii: PVehicles)
	{
		if(vehicleid == pvData[ii][cVeh])
		{
			for(new s = 0; s < 20; s++)
			{
				if(componentid == pv_spoiler[s])
				{
					pvData[ii][cMod][0] = componentid;
				}
			}

			for(new s = 0; s < 3; s++)
			{
				if(componentid == pv_nitro[s])
				{
					pvData[ii][cMod][1] = componentid;
				}
			}

			for(new s = 0; s < 23; s++)
			{
				if(componentid == pv_fbumper[s])
				{
					pvData[ii][cMod][2] = componentid;
				}
			}

			for(new s = 0; s < 22; s++)
			{
				if(componentid == pv_rbumper[s])
				{
					pvData[ii][cMod][3] = componentid;
				}
			}

			for(new s = 0; s < 28; s++)
			{
				if(componentid == pv_exhaust[s])
				{
					pvData[ii][cMod][4] = componentid;
				}
			}

			for(new s = 0; s < 2; s++)
			{
				if(componentid == pv_bventr[s])
				{
					pvData[ii][cMod][5] = componentid;
				}
			}

			for(new s = 0; s < 2; s++)
			{
				if(componentid == pv_bventl[s])
				{
					pvData[ii][cMod][6] = componentid;
				}
			}

			for(new s = 0; s < 4; s++)
			{
				if(componentid == pv_bscoop[s])
				{
					pvData[ii][cMod][7] = componentid;
				}
			}

			for(new s = 0; s < 17; s++)
			{
				if(componentid == pv_roof[s])
				{
					pvData[ii][cMod][8] = componentid;
				}
			}

			for(new s = 0; s < 21; s++)
			{
				if(componentid == pv_lskirt[s])
				{
					pvData[ii][cMod][9] = componentid;
				}
			}

			for(new s = 0; s < 21; s++)
			{
				if(componentid == pv_rskirt[s])
				{
					pvData[ii][cMod][10] = componentid;
				}
			}

			for(new s = 0; s < 1; s++)
			{
				if(componentid == pv_hydraulics[s])
				{
					pvData[ii][cMod][11] = componentid;
				}
			}

			for(new s = 0; s < 1; s++)
			{
				if(componentid == pv_base[s])
				{
					pvData[ii][cMod][12] = componentid;
				}
			}

			for(new s = 0; s < 4; s++)
			{
				if(componentid == pv_rbbars[s])
				{
					pvData[ii][cMod][13] = componentid;
				}
			}

			for(new s = 0; s < 2; s++)
			{
				if(componentid == pv_fbbars[s])
				{
					pvData[ii][cMod][14] = componentid;
				}
			}

			for(new s = 0; s < 17; s++)
			{
				if(componentid == pv_wheels[s])
				{
					pvData[ii][cMod][15] = componentid;
				}
			}

			for(new s = 0; s < 2; s++)
			{
				if(componentid == pv_lights[s])
				{
					pvData[ii][cMod][16] = componentid;
				}
			}
		}
	}
	return 1;
}
