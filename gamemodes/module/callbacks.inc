

public OnGameModeInit()
{
	//mysql_log(ALL);
	new MySQLOpt: option_id = mysql_init_options();
	mysql_set_option(option_id, AUTO_RECONNECT, true);
	g_SQL = mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE, option_id);
	if (g_SQL == MYSQL_INVALID_HANDLE || mysql_errno(g_SQL) != 0)
	{
		print("MySQL connection failed. Server is shutting down.");
		SendRconCommand("exit");
		return 1;
	}

	print("MySQL connection is successful.");

	mysql_tquery(g_SQL, "SELECT * FROM `server`", "LoadServer");
	mysql_tquery(g_SQL, "SELECT * FROM `doors`", "LoadDoors");
	mysql_tquery(g_SQL, "SELECT * FROM `familys`", "LoadFamilys");
	mysql_tquery(g_SQL, "SELECT * FROM `houses`", "LoadHouses");
	mysql_tquery(g_SQL, "SELECT * FROM `bisnis`", "LoadBisnis");
	mysql_tquery(g_SQL, "SELECT * FROM `lockers`", "LoadLockers");
	mysql_tquery(g_SQL, "SELECT * FROM `gstations`", "LoadGStations");
	mysql_tquery(g_SQL, "SELECT * FROM `atms`", "LoadATM");
	mysql_tquery(g_SQL, "SELECT * FROM `gates`", "LoadGates");
	mysql_tquery(g_SQL, "SELECT * FROM `vouchers`", "LoadVouchers");
	mysql_tquery(g_SQL, "SELECT * FROM `workshop`", "LoadWorkshop");
	mysql_tquery(g_SQL, "SELECT * FROM `dealer`", "LoadDealer");
	mysql_tquery(g_SQL, "SELECT * FROM `mappingingame`", "LoadMAPO");
	mysql_tquery(g_SQL, "SELECT * FROM `matext`", "LoadMatext");
	mysql_tquery(g_SQL, "SELECT * FROM `vendingmachine`", "LoadVending");
	mysql_tquery(g_SQL, "SELECT * FROM `speedcam`", "LoadSpeedcam");
	mysql_tquery(g_SQL, "SELECT * FROM `trashmaster`", "LoadTrash");
	mysql_tquery(g_SQL, "SELECT * FROM `actors`", "LoadActor");
	mysql_tquery(g_SQL, "SELECT * FROM `privatefarm`", "LoadPfarm");
	mysql_tquery(g_SQL, "SELECT * FROM `rental`", "LoadRental");
	mysql_tquery(g_SQL, "SELECT * FROM `garkot`", "LoadGarkot");
	mysql_tquery(g_SQL, "SELECT * FROM `sigenal`", "LoadSignal");
	mysql_tquery(g_SQL, "SELECT * FROM `jobprice`", "LoadJobPrice");
	mysql_tquery(g_SQL, "SELECT * FROM `npcfamily`", "LoadNpcfam");
	mysql_tquery(g_SQL, "SELECT * FROM `faction_vehpoint`", "LoadSvpoint");
	mysql_tquery(g_SQL, "SELECT * FROM `payphone`", "LoadPayphone");
	mysql_tquery(g_SQL, "SELECT * FROM `pedagang`", "LoadPedagang");
	mysql_tquery(g_SQL, "SELECT * FROM `911calls`", "Emergency_Load");
	mysql_tquery(g_SQL, "SELECT * FROM `bill`", "LoadBill");
	mysql_tquery(g_SQL, "SELECT * FROM `plants`", "LoadPlants");
	//mysql_tquery(g_SQL, "SELECT * FROM `carstorage`", "VehicleInventoryLoaded");
	mysql_tquery(g_SQL, "SELECT * FROM `tags`", "Tag_Load");
	mysql_tquery(g_SQL, "SELECT * FROM `dropped`", "Dropped_Load");
	mysql_tquery(g_SQL, "SELECT * FROM `trees`", "LoadTrees");
	mysql_tquery(g_SQL, "SELECT * FROM `storage`", "LoadStorage");
	mysql_tquery(g_SQL, "SELECT * FROM `notes`", "Notes_Load", "");
	
	CreateTextDraw();
	CreateServerPoint();
	CreatePasarPoint();
	CreateGetSimPoint();
	CreatePaytollAreaid();
	CreateCarStealingPoint();
	CreateCraftingPoint();
	CreatePenjahitPoint();
	CreateLumberPoint();
	CreateKanabisPoint();
	LoadUiAtm();
	//Config Streamer
	StreamerConfig();

	//JOB
	CreateJoinProductionPoint();
	//CreateJoinDrugDealer();
	//CreateJoinWeaponDealer();

	LoadTazerSAPD();
	LoadMap();
	
	new gm[32];
	format(gm, sizeof(gm), "%s", TEXT_GAMEMODE);
	SetGameModeText(gm);
	format(gm, sizeof(gm), "weburl %s", TEXT_WEBURL);
	SendRconCommand(gm);
	format(gm, sizeof(gm), "language %s", TEXT_LANGUAGE);
	SendRconCommand(gm);
	SendRconCommand("mapname San Andreas");
	ManualVehicleEngineAndLights();
	EnableStuntBonusForAll(0);
	AllowInteriorWeapons(1);
	DisableInteriorEnterExits();
	ShowNameTags(0);
	//DisableNameTagLOS();
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_OFF);
	BlockGarages(.text="NO ENTER");
	SetWeather(0);
	
	new strings[258];
	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}untuk membuat createkit"); //
	CreateDynamic3DTextLabel(strings, -1, 192.998992, -265.421997, 1.597936, 5.0);

	format(strings, sizeof(strings), "Press {FFFF00}/buyvtoys {FFFFFF}untuk menggunakan modshop"); //Miner cuci batu
	CreateDynamic3DTextLabel(strings, -1, 205.078491, -229.676666, 1.597974, 5.0);

	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}untuk mencuci Batu"); //Miner cuci batu
	CreateDynamic3DTextLabel(strings, -1, -415.5682, 1199.5940, 0.6993, 5.0);

	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}untuk membeli Kendaraan"); //Showroom
	CreateDynamic3DTextLabel(strings, -1, 1097.9308, -1765.0497, 13.3841, 5.0);

	format(strings, sizeof(strings), "Selamat datang di {E5FF00}Kampung Indo Roleplay\n{FFFFFF}If you feel confused use --> {FFFF00}/help {FFFFFF}\nTo ask something use --> {FFFF00}/ask\n{FFFFFF}If you have problems use --> {FF0000}/report");
	CreateDynamic3DTextLabel(strings, -1, 1678.9425,-2326.6213,13.5469, 15.0);

	format(strings, sizeof(strings), "Selamat datang di {E5FF00}Kampung Indo Roleplay\n{FFFFFF}If you feel confused use --> {FFFF00}/help {FFFFFF}\nTo ask something use --> {FFFF00}/ask\n{FFFFFF}If you have problems use --> {FF0000}/report");
	CreateDynamic3DTextLabel(strings, -1, 2810.0972, -2443.6760, 13.6927, 15.0);

	format(strings, sizeof(strings), "Selamat datang di {E5FF00}Kampung Indo Roleplay\n{FFFFFF}If you feel confused use --> {FFFF00}/help {FFFFFF}\nTo ask something use --> {FFFF00}/ask\n{FFFFFF}If you have problems use --> {FF0000}/report");
	CreateDynamic3DTextLabel(strings, -1, 822.8395, -1344.4669, 13.5177, 15.0);

	CreateDynamicPickup(1581, 23, 1424.269531, 1546.517578, 3010.832275, -1, 1, -1);
	format(strings, sizeof(strings), "{FFFF00}Balai Kota\n{FFFFFF}Press {FFFF00}[Y] {FFFFFF}untuk menu Pemerintah");
	CreateDynamic3DTextLabel(strings, -1, 1424.269531, 1546.517578, 3010.832275, 15.0);
	//Central Balkot = Job
	CreateDynamicPickup(1210, 23, 1332.23, 1562.28, 1113.30, -1, 1, -1);
	format(strings, sizeof(strings), "{FFFF00}Disnaker\n{FFFFFF}Press {FFFF00}[Y] {FFFFFF}untuk menu Disnaker");
	CreateDynamic3DTextLabel(strings, -1, 1332.23, 1562.28, 1113.30, 15.0);

	format(strings, sizeof(strings), "{FFFF00}Starter Pack\n{FFFFFF}Gunakan {00FF00}/claimsp {FFFFFF}\nUntuk mendapatkan perdana awal");
	CreateDynamic3DTextLabel(strings, -1, 1893.8304, -2409.0386, 13.5669, 7.0);

	format(strings, sizeof(strings), "{FFFF00}Starter Pack\n{FFFFFF}Gunakan {00FF00}/claimsp {FFFFFF}\nUntuk mendapatkan perdana awal");
	CreateDynamic3DTextLabel(strings, -1, 2810.3755, -2432.3843, 13.6927, 15.0);

	format(strings, sizeof(strings), "{FFFF00}Starter Pack\n{FFFFFF}Gunakan {00FF00}/claimsp {FFFFFF}\nUntuk mendapatkan perdana awal");
	CreateDynamic3DTextLabel(strings, -1, 821.8114, -1358.8507, -0.5078, 15.0);

	//Pedagang Spawn Veh
	format(strings, sizeof(strings), "{FFFF00}San Andreas Cafe {FFFFFF}\nGunakan {FFFF00}/spawncf {FFFFFF}untuk spawn kendaraan\n{FFFF00}/despawncf {FFFFFF}untuk despawn kendaraan");
	CreateDynamic3DTextLabel(strings, -1, 564.6272, -1800.2198, 6.0625, 10.0);

	//SAPD Spawn Veh
	format(strings, sizeof(strings), "{0900FF}San Andreas Police Department {FFFFFF}\nGunakan {FFFF00}/spawnpd {FFFFFF}untuk spawn kendaraan\n");
	CreateDynamic3DTextLabel(strings, -1, 1560.6748, -1694.7832, 5.8970, 10.0);

	format(strings, sizeof(strings), "{0900FF}San Andreas Police Department {FFFFFF}\nGunakan {FFFF00}/spawnpd {FFFFFF}untuk spawn kendaraan\nGunakan {FFFF00}/despawnpd {FFFFFF}untuk despawn kendaraan");
	CreateDynamic3DTextLabel(strings, -1, 1068.30, -1667.76, 14.01, 10.0);

	//SAMD Spawn Veh
	format(strings, sizeof(strings), "{FF69D8}San Andreas Medic Department {FFFFFF}\nGunakan {FFFF00}/spawnmd {FFFFFF}untuk spawn kendaraan\n{FFFF00}/despawnmd {FFFFFF}untuk despawn kendaraan");
	CreateDynamic3DTextLabel(strings, -1, 2032.25, -1416.00, 16.99, 10.0);

	//SAGS Spawn Veh
	format(strings, sizeof(strings), "{FFFF00}San Andreas Goverment {FFFFFF}\nGunakan {FFFF00}/spawngs {FFFFFF}untuk spawn kendaraan\n{FFFF00}/despawngs {FFFFFF}untuk despawn kendaraan");
	CreateDynamic3DTextLabel(strings, -1, 1245.3647, -2055.2239, 59.8362, 10.0);
	
	format(strings, sizeof(strings), "{FFFFFF}Press {FFFF00}[Y]\n{FFFFFF}untuk memasak");
	CreateDynamic3DTextLabel(strings, COLOR_ORANGE2, 586.45, -1820.44, 6.08, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFFFF}Press {FFFF00}[Y]\n{FFFFFF}untuk memasak");
	CreateDynamic3DTextLabel(strings, COLOR_ORANGE2, 1290.3080, 709.8832, 10.8462, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);	

	CreateDynamicPickup(1098, 23, 345.52, -77.80, 1.41, -1);
	format(strings, sizeof(strings), "{FF0000}Dilarang berdiam disini\nIni adalah tempat Spawn Asuransi!");
	CreateDynamic3DTextLabel(strings, -1, 345.52, -77.80, 1.41, 10.0);

	CreateDynamicPickup(1239, 23, 369.19, -86.98, 1.57, -1);
	format(strings, sizeof(strings), "{FFFF00}Insurance\n{FFFFFF}/sellpv - sell vehicle\n/buyinsu - buy insurance\n/claimpv - claim insurance\n/unrentpv - unrent you rent vehicle");
	CreateDynamic3DTextLabel(strings, COLOR_LBLUE, 369.19, -86.98, 1.57, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Veh insurance
	
	CreateDynamicPickup(1239, 23, 1543.73, -1674.51, 5013.88, -1);
	format(strings, sizeof(strings), "{0900FF}San Andreas Police Department\n{FFFF00}/createplate\n{FFFFFF}untuk membuat plate baru");
	CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 1543.73, -1674.51, 5013.88, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Plate
	
	format(strings, sizeof(strings), "{0900FF}San Andreas Police Department\n{FFFF00}/arrest - {FFFFFF}untuk memenjarakan player\n{FFFF00}/release - {FFFFFF}untuk mengeluarkan dari penjara");
	CreateDynamic3DTextLabel(strings, COLOR_BLUE, 1097.26, -1665.73, 15.03, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // arrest
	
	CreateDynamicPickup(1240, 23, 2025.09, -1404.14, 17.20 -1);
	format(strings, sizeof(strings), "{FF69D8}San Andreas Medic Department\n{FFFFFF}/dropinjured");
	CreateDynamic3DTextLabel(strings, COLOR_PINK, 2025.09, -1404.14, 17.20, 7.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // hospital
	
	CreateDynamicPickup(1239, 23, -982.49, 1448.46, 1340.62, -1);
	format(strings, sizeof(strings), "{477949}Bank\n{FFFF00}/newrek\n{FFFFFF}Untuk membuat rekening baru");
	CreateDynamic3DTextLabel(strings, COLOR_LBLUE, -982.49, 1448.46, 1340.62, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // bank
	
	CreateDynamicPickup(1239, 23, -983.95, 1448.46, 1340.62, -1);
	format(strings, sizeof(strings), "{477949}Bank\n{FFFF00}/bank\n{FFFFFF}Untuk mengakses rekening");
	CreateDynamic3DTextLabel(strings, COLOR_LBLUE, -983.95, 1448.46, 1340.62, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // bank
	
	CreateDynamicPickup(1239, 23, 1385.32, -17.19, 1001.00, -1);
	format(strings, sizeof(strings), "Advertisement\n{FFFF00}/ads\n{FFFFFF}Untuk membuat iklan");
	CreateDynamic3DTextLabel(strings, COLOR_ORANGE2, 1385.32, -17.19, 1001.00, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // iklan

	format(strings, sizeof(strings), "{FFFFFF}Press {FFFF00}[Y]\n{FFFFFF}untuk akses menu sapd");
	CreateDynamic3DTextLabel(strings, COLOR_ORANGE2, 1095.26, -1680.13, 15.03, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "Lumber Jack License\n{FFFF00}/newlumberlic\n{FFFFFF}untuk membuat Lumber Lisensi");
	CreateDynamic3DTextLabel(strings, COLOR_BLUE, 1574.3099, 1596.4216, 1003.5000, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Lumber Lic
	
	//MDC POLICE DEPARTEMENT
	/*CreateDynamicPickup(1239, 23, 1542.10, -1672.46, 5013.88, -1);
	format(strings, sizeof(strings), "MDC\n{FFFF00}/pmdc\n{FFFFFF}Untuk mengecek informasi MDC");
	CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 1542.10, -1672.46, 5013.88, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Police MDC

	//MDC POLICE DEPARTEMENT
	CreateDynamicPickup(1239, 23, 1542.10, -1674.52, 5013.88, -1, 4);
	format(strings, sizeof(strings), "MDC\n{FFFF00}/emdc\n{FFFFFF}Untuk mengecek informasi MDC");
	CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 1542.10, -1674.52, 5013.88, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Repairkit
	*/
	//MEKANIK CITY
	CreateDynamicPickup(1239, 23, -103.02, -1563.78, 2.69, -1);
	format(strings, sizeof(strings), "Repairkit Marker\n{FFFF00}/createkit\n{FFFFFF}Untuk membuat Repair Kit");
	CreateDynamic3DTextLabel(strings, COLOR_YELLOW, -103.02, -1563.78, 2.69, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Repairkit

	//Modshop
	CreateDynamicPickup(1274, 23, -98.76, -1567.80, 2.6931, -1);
	format(strings, sizeof(strings), "Modshop Point\n{FFFF00}/buyvtoys\n{FFFFFF}Untuk membeli kendaraan toys");
	CreateDynamic3DTextLabel(strings, COLOR_YELLOW, -98.76, -1567.80, 2.69, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Modshop

	CreateDynamicPickup(1239, 23, 2206.36, -63.64, 26.48, -1);
	format(strings, sizeof(strings), "Rehabilitation Point\n{FFFF00}/rehab\n{FFFFFF}Untuk memberikan masa rehabilitas");
	CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2206.36, -63.64, 26.48, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Rehabilitation

	//THROW GARBAGE
	CreateDynamicPickup(1239, 23, 2436.29, -2113.88, 13.54, -1);
	format(strings, sizeof(strings), "Garbage Dump\n{FFFF00}/throwgarbage\n{FFFFFF}Untuk mengambil sampah");
	CreateDynamic3DTextLabel(strings, COLOR_GREEN, 2436.29, -2113.88, 13.54+0.2, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // ID Card

	//Rob Bank Object
	RobBankObject[1] = CreateDynamicObject(2634, -990.080994, 1468.404053, 1332.555054, 0.000000, 0.000000, 90.000000);

	//TOL LV
	tolgate[0] = CreateDynamicObject(968, 1807.947021, 821.503417, 10.610667, 0.000000, 89.899971, 0.000000, -1, -1, -1, 200.00, 200.00); //TOLL LV1 23
	tolgate[1] = CreateDynamicObject(968, 1805.447753, 821.524658, 10.560406, 0.000000, -90.299957, -0.000000, -1, -1, -1, 200.00, 200.00); //TOL LV2 25
	tolgate[2] = CreateDynamicObject(968, 1788.649291, 803.113159, 10.900191, 0.000000, 90.299942, -0.099992, -1, -1, -1, 200.00, 200.00); //TOLL LV3 28
	tolgate[3] = CreateDynamicObject(968, 1787.745727, 803.114807, 10.881714, 0.000000, -90.299926, 0.000000, -1, -1, -1, 200.00, 200.00); //TOLL LV4 29

	//TOL FLINT
	tolgate[4] = CreateDynamicObject(968, 41.159236, -1526.555419, 5.092908, 0.000000, 89.999961, 80.200096, -1, -1, -1, 200.00, 200.00); //TOLL FLINT1 92
	tolgate[5] = CreateDynamicObject(968, 65.120658, -1536.429077, 4.809195, 0.000000, -90.199958, 82.400070, -1, -1, -1, 200.00, 200.00); //TOLL FLINT2 91

	//TOL RED BRIDGE
	tolgate[6] = CreateDynamicObject(968, -165.864074, 374.415924, 11.875398, 0.000000, -89.999954, 163.700042, -1, -1, -1, 200.00, 200.00); //TOLL RED BRIDGE1 112
	tolgate[7] = CreateDynamicObject(968, -172.951614, 349.509979, 11.878129, 0.000000, -89.999961, -15.499999, -1, -1, -1, 200.00, 200.00); //TOLL RED BRIDGE2 109

	//TOL GREY BRIDGE
	tolgate[8] = CreateDynamicObject(968, 509.552917, 488.096923, 18.707580, 0.000000, -89.800018, -144.800003, -1, -1, -1, 200.00, 200.00); //TOLL GREY BRIDGE 122
	tolgate[9] = CreateDynamicObject(968, 524.426269, 467.211395, 18.679878, 0.000000, -89.800010, 35.199996, -1, -1, -1, 200.00, 200.00); //TOLL GREY BRIDGE 121

	//Button
	SAPDButton[0] = CreateButton(2514.793945, -1535.144042, 24.885942, 270.000000);
	SAPDButton[1] = CreateButton(2514.864013, -1535.053222, 24.885942, 450.000000);
	SAPDDoor[0] = CreateDynamicObject(1536, 2514.942626, -1534.607177, 23.515935, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.0, 300.0); 
	SAMDButton[0] = CreateButton(-2020.921997, 120.020828, 10028.083984, 90.000000);
	SAMDButton[1] = CreateButton(-2021.052001, 120.020828, 10028.083984, 270.000000);
	SAMDButton[2] = CreateButton(-2024.292846, 131.570739, 10032.130859, 90.000000);
	SAMDButton[3] = CreateButton(-2024.372924, 131.570739, 10032.130859, 270.000000);	
	SAMDButton[4] = CreateButton(-2024.292846, 113.060806, 10032.130859, 90.000000);
	SAMDButton[5] = CreateButton(-2024.372924, 113.100776, 10032.130859, 270.000000);
	SAMDDoor[0]= CreateDynamicObject(1536, -2020.953002, 120.387542, 10026.625000, 0.000000, 0.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00); 	
	SAMDDoor[1]= CreateDynamicObject(1536, -2024.293212, 111.167564, 10030.610351, 0.000000, 0.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00);
	SAMDDoor[2]= CreateDynamicObject(1536, -2024.293212, 129.687591, 10030.610351, 0.000000, 0.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00); 

	//Sidejob Vehicle
	AddBusVehicle();
	AddTruckerVehicle();
	AddDriveSimVehicle();
	AddTrashVehicle();
	AddSweeperVehicle();
	//AddvehShowroom();

	printf("[DATABASE] Number of Dynamic objects loaded: %d", CountDynamicObjects());



	return 1;
}

public OnGameModeExit()
{
	new count = 0, count1 = 0;
	foreach(new gsid : GStation)
	{
		if(Iter_Contains(GStation, gsid))
		{
			count++;
			GStation_Save(gsid);
			Iter_Remove(GStation, gsid);
		}
	}
	//Profiler_Stop();
	printf("[DATABASE] Number of Oil Gas Saved: %d", count);
	
	foreach(new pid : Plants)
	{
		if(Iter_Contains(Plants, pid))
		{
			count1++;
			Plant_Save(pid);
			Iter_Remove(Plants, pid);
		}
	}
	printf("[Farmer Plant] Number of Saved: %d", count1);
	for (new i = 0, j = GetPlayerPoolSize(); i <= j; i++) 
	{
		if (IsPlayerConnected(i))
		{
			CallLocalFunction("OnPlayerDisconect", "dd", i, 1);
		}
	}
	UnloadTazerSAPD();
	//Audio_DestroyTCPServer();
	mysql_close(g_SQL);
	return 1;
}

function SAPDDoorClose()
{
	MoveDynamicObject(SAPDDoor[0], 2514.942626, -1534.607177, 23.515935, 3, 0.000000, 0.000000, 90.000000);
	return 1;
}

function SAMDDoorClose()
{
	MoveDynamicObject(SAMDDoor[0], -2020.953002, 120.387542, 10026.625000, 3, 0.000000, 0.000000, 90.000000);
	MoveDynamicObject(SAMDDoor[1], -2024.293212, 111.167564, 10030.610351, 3, 0.000000, 0.000000, 90.000000);
	MoveDynamicObject(SAMDDoor[2], -2024.293212, 129.687591, 10030.610351, 3, 0.000000, 0.000000, 90.000000);
	return 1;
}

public OnPlayerPressButton(playerid, buttonid)
{
	if(buttonid == SAPDButton[0] || buttonid == SAPDButton[1])
	{
		if(pData[playerid][pFaction] == 1)
		{
			//MoveDynamicObject(SAPDDoor[0], 1456.954223, -1031.244628, 10022.785156, 3, 0.000000, 0.000000, 270.000000);
			MoveDynamicObject(SAPDDoor[0], 2514.94262, -1536.127319, 23.515935, 3, 0.000000, 0.000000, 90.000000);
			SetTimer("SAPDDoorClose", 5000, 0);
		}
		else
		{
			ErrorMsg(playerid, "Access Denied");
			return 1;
		}
	}
	if(buttonid == SAMDButton[0] || buttonid == SAMDButton[1])
	{
		if(pData[playerid][pFaction] == 3)
		{
			MoveDynamicObject(SAMDDoor[0], -2020.953002, 118.857513, 10026.625000, 3, 0.000000, 0.000000, 90.000000);
			SetTimer("SAMDDoorClose", 5000, 0);
		}
		else
		{
			ErrorMsg(playerid, "Access Denied");
			return 1;
		}
	}
	if(buttonid == SAMDButton[2] || buttonid == SAMDButton[3])
	{
		if(pData[playerid][pFaction] == 3)
		{
			MoveDynamicObject(SAMDDoor[2], -2024.29312, 131.307479, 10030.610351, 3, 0.000000, 0.000000, 90.000000);
			SetTimer("SAMDDoorClose", 5000, 0);
		}
		else
		{
			ErrorMsg(playerid, "Access Denied");
			return 1;
		}
	}
	if(buttonid == SAMDButton[4] || buttonid == SAMDButton[5])
	{
		if(pData[playerid][pFaction] == 3)
		{	
			MoveDynamicObject(SAMDDoor[1], -2024.29312, 109.647544, 10030.610351, 3, 0.000000, 0.000000, 90.000000);
			SetTimer("SAMDDoorClose", 5000, 0);
		}
		else
		{
			ErrorMsg(playerid, "Access Denied");
			return 1;
		}
	}
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
		if(IsDRIVESIMCar(vehicleid))
		{
			if(pData[playerid][pGetSIM] != 1)
			{
				RemovePlayerFromVehicle(playerid);
				new Float:slx, Float:sly, Float:slz;
				GetPlayerPos(playerid, slx, sly, slz);
				SetPlayerPos(playerid, slx, sly, slz);
				Error(playerid, "Kamu tidak memiliki izin!");
			}
		}
		if(IsPDCar(vehicleid))
		{
			if(pData[playerid][pFaction] != 1)
			{
				RemovePlayerFromVehicle(playerid);
			    new Float:slx, Float:sly, Float:slz;
				GetPlayerPos(playerid, slx, sly, slz);
				SetPlayerPos(playerid, slx, sly, slz);
			    ErrorMsg(playerid, "Anda bukan bagian dari SAPD");
			}
		}
		if(IsMDCar(vehicleid))
		{
			if(pData[playerid][pFaction] != 3)
			{
				RemovePlayerFromVehicle(playerid);
			    new Float:slx, Float:sly, Float:slz;
				GetPlayerPos(playerid, slx, sly, slz);
				SetPlayerPos(playerid, slx, sly, slz);
			    ErrorMsg(playerid, "Anda bukan bagian dari SAMD");
			}
		}
		if(IsGSCar(vehicleid))
		{
			if(pData[playerid][pFaction] != 2)
			{
				RemovePlayerFromVehicle(playerid);
			    new Float:slx, Float:sly, Float:slz;
				GetPlayerPos(playerid, slx, sly, slz);
				SetPlayerPos(playerid, slx, sly, slz);
			    Error(playerid, "Anda bukan bagian dari SAGS");
			}
		}
		if(IsCFCar(vehicleid))
		{
			if(pData[playerid][pFaction] != 5)
			{
				RemovePlayerFromVehicle(playerid);
			    new Float:slx, Float:sly, Float:slz;
				GetPlayerPos(playerid, slx, sly, slz);
				SetPlayerPos(playerid, slx, sly, slz);
			    Error(playerid, "Anda bukan bagian dari SACF");
			}
		}
		if(IsATruckerVeh(vehicleid))
		{
		    if(pData[playerid][pJob] == 4 || pData[playerid][pJob2] == 4)
			{
				Info(playerid, "Anda akan memulai bekerja sebagai Trucker");
			}
			else
			{
				RemovePlayerFromVehicle(playerid);
				new Float:slx, Float:sly, Float:slz;
				GetPlayerPos(playerid, slx, sly, slz);
				SetPlayerPos(playerid, slx, sly, slz);
				Error(playerid, "Kamu bukan pekerja trucker!");
			}
		}
	}
	return 1;
}

/*public OnVehicleStreamIn(vehicleid, forplayerid)
{
	foreach(new pv : PVehicles)
	{
		if(vehicleid == pvData[pv][cVeh])
		{
			if(IsABike(vehicleid) || GetVehicleModel(vehicleid) == 424)
			{
				if(pvData[pv][cLocked] == 1)
				{
					SetVehicleParamsForPlayer(vehicleid, forplayerid, 0, 1);
				}
			}
		}
	}
	return 1;
}*/

public OnPlayerText(playerid, text[])
{
	if(isnull(text)) return 0;
	if(pData[playerid][pSpawned] == 0 && pData[playerid][IsLoggedIn] == false)
	{
	    ErrorMsg(playerid, "You must be spawned or logged in to use chat.");
	    return 0;
	}	
	if(ServiceIndex[playerid] != 0)
	{
		ProcessServiceCall(playerid, text);
		return 0;
	}
	if(text[0] == '!')
	{
		new tmp[512];
		if(text[1] == ' ')
		{
			format(tmp, sizeof(tmp), "%s", text[2]);
		}
		else
		{
			format(tmp, sizeof(tmp), "%s", text[1]);
		}
		if(pData[playerid][pAdminDuty] == 1)
		{
			if(strlen(tmp) > 64)
			{
				SendNearbyMessage(playerid, 20.0, -1, "%s | {FF0000}%s{FFFFFF}: (( %.64s ..", GetStaffRank(playerid), pData[playerid][pAdminname], tmp);
				SendNearbyMessage(playerid, 20.0, -1, ".. %s ))", tmp[64]);
				return 0;
			}
			else
			{
				SendNearbyMessage(playerid, 20.0, -1, "%s | {FF0000}%s{FFFFFF}: (( %s ))", GetStaffRank(playerid), pData[playerid][pAdminname], tmp);
				return 0;
			}
		}
		else
		{
			if(strlen(tmp) > 64)
			{
				SendNearbyMessage(playerid, 20.0, COLOR_WHITE, "%s: (( %.64s ..", ReturnName(playerid), tmp);
				SendNearbyMessage(playerid, 20.0, COLOR_WHITE, ".. %s ))", tmp[64]);
				return 0;
			}
			else
			{
				SendNearbyMessage(playerid, 20.0, COLOR_WHITE, "%s: (( %s ))", ReturnName(playerid), tmp);
				return 0;
			}
		}
	}
	if(text[0] == '@')
	{
		if(pData[playerid][pSMS] != 0)
		{
			if(pData[playerid][pPhoneCredit] < 1)
			{
				ErrorMsg(playerid, "Anda tidak memiliki Credit");
				return 0;
			}
			if(pData[playerid][pInjured] != 0)
			{
				InfoTD_MSG(playerid, 1000, "Saat ini anda tidak dapat menggunakan ~y~SMS");
				return 0;
			}
			new tmp[512];
			foreach(new ii : Player)
			{
				if(text[1] == ' ')
				{
			 		format(tmp, sizeof(tmp), "%s", text[2]);
				}
				else
				{
				    format(tmp, sizeof(tmp), "%s", text[1]);
				}
				if(pData[ii][pPhone] == pData[playerid][pSMS])
				{
					if(ii == INVALID_PLAYER_ID || !IsPlayerConnected(ii))
					{
						ErrorMsg(playerid, "Nomor yang anda tuju sedang tidak aktif", 3);
						return 0;
					}
					SendClientMessageEx(playerid, COLOR_YELLOW, "<SMS to %d>"WHITE_E" %s", pData[playerid][pSMS], tmp);
					InfoMsg(ii, "Seseorang telah mengirim pesan SMS");
					SendClientMessageEx(ii, COLOR_YELLOW, "<SMS from %d>"WHITE_E" %s", pData[playerid][pPhone], tmp);
					PlayerPlaySound(ii, 6003, 0,0,0);
					pData[ii][pSMS] = pData[playerid][pPhone];
					
					pData[playerid][pPhoneCredit] -= 1;
					return 0;
				}
			}
		}
	}
	else
	{
        // Anti-Caps
        if(GetPVarType(playerid, "Caps"))
        UpperToLower(text);
        new lstr[1024];
        format(lstr, sizeof(lstr), "%s says: %s", ReturnName(playerid), text);
        ProxDetector(10, playerid, lstr, 0xE6E6E6E6, 0xC8C8C8C8, 0xAAAAAAAA, 0x8C8C8C8C, 0x6E6E6E6E);
        SetPlayerChatBubble(playerid, text, COLOR_WHITE, 10.0, 3000);
		return 0;
	}
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
  return 0;
}

public OnPlayerConnect(playerid)
{
	RemoveMap(playerid);
	CreatePlayerAtm(playerid);
	RobWarung_CreateTextDraw(playerid);
	new PlayerIP[16];
	pemainic++;
	TogglePhone[playerid] = 0;
	ToggleCall[playerid] = 0;
	ToggleSid[playerid] = 0;
	Toggleaccdeath[playerid] = 0;
	g_MysqlRaceCheck[playerid]++;
	IsAtEvent[playerid] = 0;
	ResetVariables(playerid);
	CreatePlayerTextDraws(playerid);
	ShowLogo(playerid);
	RefreshMapSacf(playerid);
	LoadArea(playerid);

	if(IsValidDynamic3DTextLabel(TagKeluar[playerid]))
  		DestroyDynamic3DTextLabel(TagKeluar[playerid]);

    pData[playerid][pMeatProgres] = 0;
	LimitSpeed[playerid] = 0; //Buat Disable Speedlimit setiap kali player login

	//ICON SAPD
	SetPlayerMapIcon(playerid, 12, 1126.94, -1692.04, 14.01, 30 , 0, MAPICON_LOCAL); 
	//ICON EMS
	SetPlayerMapIcon(playerid, 13, 2003.29, -1444.97, 13.56, 22 , 0, MAPICON_LOCAL); 
	//ICON BANDARA
	SetPlayerMapIcon(playerid, 14, 1954.64, -2309.93, 13.54, 5 , 0, MAPICON_LOCAL);
	//ICON TRUCKER
	SetPlayerMapIcon(playerid, 15, -68.72, -1130.11, 1.07, 51 , 0, MAPICON_LOCAL);
	//ICON BANK
	SetPlayerMapIcon(playerid, 16, 1465.12, -1011.05, 26.84, 52 , 0, MAPICON_LOCAL);
	//ICON BERANGKAS
	SetPlayerMapIcon(playerid, 17, 2082.7722, -2033.2288, 13.5469, 35, 0, MAPICON_LOCAL);
	//ICON DEALER
	//SetPlayerMapIcon(playerid, 17, 1285.23, -1308.43, 13.54, 55 , 0, MAPICON_LOCAL); //1285.23, -1308.43, 13.54, 92.37

	GetPlayerName(playerid, pData[playerid][pName], MAX_PLAYER_NAME);

	GetPlayerIp(playerid, PlayerIP, sizeof(PlayerIP));
	pData[playerid][pIP] = PlayerIP;
	
	SetTimerEx("SafeLogin", 1000, 0, "i", playerid);

	InterpolateCameraPos(playerid, 1533.116943, -1367.901367, 332.058013, 628.761047, -1764.393554, 19.677539, 35000);
    InterpolateCameraLookAt(playerid, 1529.958251, -1371.210693, 330.040313, 629.909790, -1769.228637, 19.127872, 35000);
	
	for(new j; j < 20; j++ )
	{
		SendClientMessage(playerid, COLOR_WHITE, " ");
	}
	new query[128];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM ucp WHERE ucp_name = '%s' LIMIT 1", pData[playerid][pName]);
    mysql_tquery(g_SQL, query, "LoadUcpAccount", "dd", playerid, g_MysqlRaceCheck[playerid]);
	SetPlayerColor(playerid, COLOR_WHITE);

    if(pData[playerid][pHead] < 0) return pData[playerid][pHead] = 20;

    if(pData[playerid][pPerut] < 0) return pData[playerid][pPerut] = 20;

    if(pData[playerid][pRFoot] < 0) return pData[playerid][pRFoot] = 20;

    if(pData[playerid][pLFoot] < 0) return pData[playerid][pLFoot] = 20;

    if(pData[playerid][pLHand] < 0) return pData[playerid][pLHand] = 20;
   
    if(pData[playerid][pRHand] < 0) return pData[playerid][pRHand] = 20;
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{	
	pData[playerid][pSpaTime] = gettime() + 3600;
	
	for (new ii = 0; ii < MAX_PLAYERS; ii++)
	{
		DeletePlayer3DTextLabel(playerid, PlayerTags[ii]);
	}

    pData[playerid][pMeatProgres] = 0;
	if(IsPlayerInAnyVehicle(playerid))
	{
        RemovePlayerFromVehicle(playerid);
    }

	//UpdateWeapons(playerid);
	g_MysqlRaceCheck[playerid]++;

	pemainic--;
	if(pData[playerid][IsLoggedIn] == true)
	{
		if(IsAtEvent[playerid] == 0)
		{
			UpdatePlayerData(playerid);
		}
		else if(IsAtEvent[playerid] == 1)
        {
            SetPlayerPos(playerid, LastposX[playerid], LastposY[playerid], LastposZ[playerid]);
            SetPlayerVirtualWorld(playerid, LastVW[playerid]);
            SetPlayerInterior(playerid, LastInterior[playerid]);
            SetPlayerHealthEx(playerid, 100.0);

            pData[playerid][pInjured] = 0;
            pData[playerid][pHospital] = 0;
            pData[playerid][pSick] = 0;
            IsAtEvent[playerid] = 0;

            pData[playerid][pPosX] = LastposX[playerid];
            pData[playerid][pPosY] = LastposY[playerid];
            pData[playerid][pPosZ] = LastposZ[playerid];
            pData[playerid][pInt] = LastInterior[playerid];
            pData[playerid][pWorld] = LastVW[playerid];

            SetPlayerTeam(playerid, 0);
            SetPlayerColor(playerid, COLOR_WHITE);
            ResetPlayerWeaponsEx(playerid);
            clearAnimations(playerid);
        }
		UnloadPlayerVehicle(playerid);
		Report_Clear(playerid);
		Ask_Clear(playerid);
		FactionCall_Clear(playerid);
		Player_ResetCutting(playerid);
		Player_RemoveLumber(playerid);
		Player_ResetHarvest(playerid);
		Player_ResetBoombox(playerid);
		Player_ResetPayphone(playerid);
		Player_ResetDamageLog(playerid);
		Player_ResetAdsLog(playerid);
		KillTazerTimer(playerid);
		new Float:x, Float:y, Float:z, strings[500];
		GetPlayerPos(playerid, x, y, z);

		new reasontext[526];
		switch(reason)
		{
			case 0: reasontext = "Timeout/ Crash";
			case 1: reasontext = "Quit";
			case 2: reasontext = "Kicked/ Banned";
		}
		
		SendDiscordMessage(2, sprintf("**%s** player exits to server", pData[playerid][pName]));
		format(strings, sizeof(strings), "(( %s | %s <%d> | DC-ID <%d> | has disconected from server ))\nReason: <%s>", pData[playerid][pName], pData[playerid][pUcp], playerid, pData[playerid][pDiscordID], reasontext);
		TagKeluar[playerid] = CreateDynamic3DTextLabel(strings, 0xC6E2FFFF, x, y, z, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Text Jika Player Disconnect
		SetTimerEx("WaktuKeluar", 10000, false, "d", playerid);
		if(pData[playerid][pRobLeader] == 1)
		{
			foreach(new ii : Player) 
			{
				if(pData[ii][pMemberRob] == playerid)
				{
					SyntaxMsg(ii, "Pemimpin rampok telah keluar dari kota");
					ErrorMsg(ii, "Misi telah di gagalkan");
					pData[ii][pMemberRob] = -1;
					pData[ii][pRobLeader] = -1;
				}
			}
		}
	}
	if(IsValidDynamic3DTextLabel(pData[playerid][AdminTag]))
        DestroyDynamic3DTextLabel(pData[playerid][AdminTag]);

	if(IsValidDynamic3DTextLabel(pData[playerid][pAdoTag]))
        DestroyDynamic3DTextLabel(pData[playerid][pAdoTag]);

    if(IsValidDynamic3DTextLabel(pData[playerid][pBTag]))
        DestroyDynamic3DTextLabel(pData[playerid][pBTag]);
			
	if(IsValidDynamicObject(pData[playerid][pFlare]))
        DestroyDynamicObject(pData[playerid][pFlare]);
    
    if(pData[playerid][pMaskOn] == 1)
        Delete3DTextLabel(pData[playerid][pMaskLabel]);

    if(PlayerAFK[playerid] == 1)
    	Delete3DTextLabel(AFKTags[playerid]);

	if(pData[playerid][pDragged])
    {
        DeletePVar(playerid, "DragBy");
        pData[playerid][pDragged] = 0;
        pData[playerid][pDraggedBy] = INVALID_PLAYER_ID;
        KillTimer(pData[playerid][pDragTimer]);
	}
    pData[playerid][pAdoActive] = false;
	forex(i, MAX_INVENTORY)
	{
		if(!InventoryData[playerid][i][invExists]) 
		{
			InventoryData[playerid][i][invExists] = false;
			InventoryData[playerid][i][invModel] = 0;
			InventoryData[playerid][i][invQuantity] = 0;
		}
	}
	if(VehHauling[playerid] != -1)
	{
		if(pData[playerid][pJob] == 8 || pData[playerid][pJob2] == 8)
		{
		    DestroyVehicle(VehHauling[playerid]);
		}
	}
	if(pData[playerid][LoginTimer])
	{
		KillTimer(pData[playerid][LoginTimer]);
		pData[playerid][LoginTimer] = 0;
	}
	pData[playerid][IsLoggedIn] = false;
	return 1;
}

function WaktuKeluar(playerid)
{
 	if(IsValidDynamic3DTextLabel(TagKeluar[playerid]))
  		DestroyDynamic3DTextLabel(TagKeluar[playerid]);
}

public OnPlayerSpawn(playerid)
{
	StopAudioStreamForPlayer(playerid);
	SetPlayerInterior(playerid, pData[playerid][pInt]);
	SetPlayerVirtualWorld(playerid, pData[playerid][pWorld]);
	SetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
	SetPlayerFacingAngle(playerid, pData[playerid][pPosA]);
	SetCameraBehindPlayer(playerid);
	TogglePlayerControllable(playerid, 0);
	SetPlayerSpawn(playerid);
	LoadAnims(playerid);
	for(new i = 0; i < 5; i++) {
		PlayerTextDrawShow(playerid, voicemenu[playerid][i]);
	}
	PlayerTextDrawShow(playerid, voicemenu[playerid][7]);
	
	SetPlayerSkillLevel(playerid, WEAPON_COLT45, 1);
	SetPlayerSkillLevel(playerid, WEAPON_SILENCED, 1);
	SetPlayerSkillLevel(playerid, WEAPON_DEAGLE, 1);
	SetPlayerSkillLevel(playerid, WEAPON_SHOTGUN, 1);
	SetPlayerSkillLevel(playerid, WEAPON_SAWEDOFF, 1);
	SetPlayerSkillLevel(playerid, WEAPON_SHOTGSPA, 1);
	SetPlayerSkillLevel(playerid, WEAPON_UZI, 1);
	SetPlayerSkillLevel(playerid, WEAPON_MP5, 1);
	SetPlayerSkillLevel(playerid, WEAPON_AK47, 1);
	SetPlayerSkillLevel(playerid, WEAPON_M4, 1);
	SetPlayerSkillLevel(playerid, WEAPON_TEC9, 1);
	SetPlayerSkillLevel(playerid, WEAPON_RIFLE, 1);
	SetPlayerSkillLevel(playerid, WEAPON_SNIPER, 1);
	return 1;
}

SetPlayerSpawn(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(pData[playerid][pGender] == 0)
		{
			SetPlayerColor(playerid, COLOR_WHITE);
			TogglePlayerControllable(playerid,0);
			SetPlayerHealth(playerid, 100.0);
			SetPlayerArmour(playerid, 0.0);
			SetPlayerCameraPos(playerid,1429.946655, -1597.120483, 41);
			SetPlayerCameraLookAt(playerid,247.605590, -1841.989990, 39.802570);
			SetPlayerVirtualWorld(playerid, 0);
			pData[playerid][pStreamObj] = 2000;
			ShowPlayerDialog(playerid, DIALOG_AGE, DIALOG_STYLE_INPUT, "Birth Date", "{FFFFFF}Enter your character's birth date\n(Day/Month/Year)\nExample: 04/15/1998", "Enter", "Cancel");
		}
		else
		{
			SetPlayerColor(playerid, COLOR_WHITE);
			ShowHunger(playerid);
			SetPlayerSkin(playerid, pData[playerid][pSkin]);
			//Streamer
			Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, pData[playerid][pStreamObj], playerid);
			Streamer_Update(playerid, STREAMER_TYPE_OBJECT);
			if(pData[playerid][pOnDuty] >= 1)
			{
				SetPlayerSkin(playerid, pData[playerid][pFacSkin]);
				SetFactionColor(playerid);
			}
			if(pData[playerid][pAdminDuty] > 0)
			{
				SetPlayerColor(playerid, COLOR_ADMIN);
			}
			SetTimerEx("SpawnTimer", 10000, false, "i", playerid);
		}
	}
}

function SpawnTimer(playerid)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, pData[playerid][pMoney]);
	SetPlayerScore(playerid, pData[playerid][pLevel]);
	SetPlayerHealthEx(playerid, pData[playerid][pHealth]);
	SetPlayerArmourEx(playerid, pData[playerid][pArmour]);
	SetPlayerFightingStyle(playerid, pData[playerid][pFightingStyle]);
	pData[playerid][pSpawned] = 1;
	TogglePlayerControllable(playerid, 1);
	SetCameraBehindPlayer(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	clearAnimations(playerid);
	StopLoopingAnim(playerid);
	AttachPlayerToys(playerid);
	SetWeapons(playerid);
	if(pData[playerid][pJail] > 0)
	{
		JailPlayer(playerid);
	}
	if(pData[playerid][pRehab] > 0)
	{
		RehabPlayer(playerid);
	}
	if(pData[playerid][pArrestTime] > 0)
	{
		SetPlayerArrest(playerid, pData[playerid][pArrest]);
	}
	return 1;
}

public OnPlayerSelectionMenuResponse(playerid, extraid, response, listitem, modelid)
{
	switch(extraid)
	{
		case SPAWN_SKIN_MALE:
		{
			if(response)
			{
				pData[playerid][pSkin] = modelid;
				SetPlayerSkin(playerid, modelid);

				SetTimerEx("revivenewplayer", 5000, false, "d", playerid);
			}
		}
		case SPAWN_SKIN_FEMALE:
		{
			if(response)
			{
				pData[playerid][pSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SetTimerEx("revivenewplayer", 5000, false, "d", playerid);
			}
		}
		case VIP_SKIN_MALE:
		{
			if(response)
			{
				pData[playerid][pSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah mengganti skin ID %d.", ReturnName(playerid), modelid);
				SuccesMsg(playerid, "Anda telah berhasil mengganti Skin");
			}
			else
				return InfoMsg(playerid, "Anda telah membatalkan pilihan");
		}
		case SHOP_SKIN_MALE:
		{
			if(response)
			{
				new bizid = pData[playerid][pInBiz], price;
				price = bData[bizid][bP][0];
				pData[playerid][pSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				GivePlayerMoneyEx(playerid, -price);
				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli pakaian ID %d seharga %s.", ReturnName(playerid), modelid, FormatMoney(price));
				bData[bizid][bProd]--;
				bData[bizid][bMoney] += Server_Percent(price);
				Server_AddPercent(price);
				Bisnis_Save(bizid);
				SuccesMsg(playerid, "Anda telah berhasil membeli pakaian baru");
			}
			else return InfoMsg(playerid, "Anda telah membatalkan pilihan");
		}
		case SHOP_SKIN_FEMALE:
		{
			if(response)
			{
				new bizid = pData[playerid][pInBiz], price;
				price = bData[bizid][bP][0];
				pData[playerid][pSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				GivePlayerMoneyEx(playerid, -price);
				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli skin ID %d seharga %s.", ReturnName(playerid), modelid, FormatMoney(price));
				bData[bizid][bProd]--;
				bData[bizid][bMoney] += Server_Percent(price);
				Server_AddPercent(price);
				Bisnis_Save(bizid);
				SuccesMsg(playerid, "Anda telah berhasil membeli pakaian baru");
			}
			else return InfoMsg(playerid, "Anda telah membatalkan pilihan");
		}
		case VIP_SKIN_FEMALE:
		{
			if(response)
			{
				pData[playerid][pSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah mengganti skin ID %d.", ReturnName(playerid), modelid);
				SuccesMsg(playerid, "Anda telah berhasil membeli pakaian baru");
			}
			else
				return InfoMsg(playerid, "Anda telah membatalkan pilihan");
		}
		case SAPD_SKIN_MALE:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case SAPD_SKIN_FEMALE:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case SAPD_SKIN_WAR:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case SAGS_SKIN_MALE:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case SAGS_SKIN_FEMALE:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case SAMD_SKIN_MALE:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case SAMD_SKIN_FEMALE:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case SANA_SKIN_MALE:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case SANA_SKIN_FEMALE:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case SACF_SKIN_MALE:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case SACF_SKIN_FEMALE:
		{
			if(response)
			{
				pData[playerid][pFacSkin] = modelid;
				SetPlayerSkin(playerid, modelid);
				SuccesMsg(playerid, "Berhasil mengubah Faction Skin");
			}
		}
		case TOYS_MODEL:
		{
			if(response)
			{
				new bizid = pData[playerid][pInBiz], price;
				price = bData[bizid][bP][1];
				
				GivePlayerMoneyEx(playerid, -price);
				if(pData[playerid][PurchasedToy] == false) MySQL_CreatePlayerToy(playerid);
				pToys[playerid][pData[playerid][toySelected]][toy_model] = modelid;
				pToys[playerid][pData[playerid][toySelected]][toy_hide] = 0;

				new finstring[750];
				strcat(finstring, ""dot"Spine\n"dot"Head\n"dot"Left upper arm\n"dot"Right upper arm\n"dot"Left hand\n"dot"Right hand\n"dot"Left thigh\n"dot"Right tigh\n"dot"Left foot\n"dot"Right foot");
				strcat(finstring, "\n"dot"Right calf\n"dot"Left calf\n"dot"Left forearm\n"dot"Right forearm\n"dot"Left clavicle\n"dot"Right clavicle\n"dot"Neck\n"dot"Jaw");
				ShowPlayerDialog(playerid, DIALOG_TOYPOSISIBUY, DIALOG_STYLE_LIST, ""WHITE_E"Select Bone", finstring, "Select", "Cancel");
				
				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "> %s telah membeli aksesoris seharga %s <", ReturnName(playerid), FormatMoney(price));
				bData[bizid][bProd]--;
				bData[bizid][bMoney] += Server_Percent(price);
				Server_AddPercent(price);
				new str[500];
				format(str, sizeof(str), "Removed_%s", FormatMoney(price));
				ShowItemBox(playerid, "Uang", str, 1212, 2);
				SuccesMsg(playerid, "Anda telah membeli aksesoris baru");
				new query[128];
				mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
				mysql_tquery(g_SQL, query);
			}
			else return InfoMsg(playerid, "Anda membatalkan pilihan");
		}
		case VIPTOYS_MODEL:
		{
			if(response)
			{
				if(pData[playerid][PurchasedToy] == false) MySQL_CreatePlayerToy(playerid);
				pToys[playerid][pData[playerid][toySelected]][toy_model] = modelid;
				pToys[playerid][pData[playerid][toySelected]][toy_hide] = 0;

				new finstring[750];
				strcat(finstring, ""dot"Spine\n"dot"Head\n"dot"Left upper arm\n"dot"Right upper arm\n"dot"Left hand\n"dot"Right hand\n"dot"Left thigh\n"dot"Right tigh\n"dot"Left foot\n"dot"Right foot");
				strcat(finstring, "\n"dot"Right calf\n"dot"Left calf\n"dot"Left forearm\n"dot"Right forearm\n"dot"Left clavicle\n"dot"Right clavicle\n"dot"Neck\n"dot"Jaw");
				ShowPlayerDialog(playerid, DIALOG_TOYPOSISIBUY, DIALOG_STYLE_LIST, ""WHITE_E"Select Bone", finstring, "Select", "Cancel");
				
				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah mengambil object ID %d di locker.", ReturnName(playerid), modelid);
			}
			else return InfoMsg(playerid, "Anda membatalkan pilihan");
		}
		case VEHICLE_TOYS:
		{
			if(response)
			{
				new vehicleid = GetPlayerVehicleID(playerid), slotid = pData[playerid][pVtoySelect];

				if(pData[playerid][pMoney] < 2500)
					return ErrorMsg(playerid, "Uang anda tidak mencukupi");

				if(pvData[vehicleid][cToys] == false) MySQL_CreateVehicleToys(vehicleid);
					
				vToys[vehicleid][slotid][vtModelid] = modelid;
				vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

				AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
					vehicleid,
					vToys[vehicleid][slotid][vtX], 
					vToys[vehicleid][slotid][vtY], 
					vToys[vehicleid][slotid][vtZ], 
					vToys[vehicleid][slotid][vtRX], 
					vToys[vehicleid][slotid][vtRY], 
					vToys[vehicleid][slotid][vtRZ]);

				MySQL_SaveVehicleToys(vehicleid);

				Servers(playerid, "Gunakan: /vtoys atau untuk mengedit toys");
				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli object ID %d seharga $2.500.", ReturnName(playerid), modelid);
				GivePlayerMoneyEx(playerid, -2500);
			}
			else return InfoMsg(playerid, "Anda membatalkan pilihan");
		}
		case BARRICADE_OBJECT:
		{
			if(response)
			{
				static
					Float:fX,Float:fY,Float:fZ;
				
				new index;
				if((index = Barricade_Create(playerid, 2, modelid, "-")) != -1) 
				{
					SendFactionMessage(1, COLOR_RADIO, "RADIO: %s has dropped a roadblock at %s. (( ID %d ))", pData[playerid][pName], GetLocation(fX, fY, fZ), index);
					pData[playerid][pEditType] = EDIT_BLOCK;
					pData[playerid][pEditing] = index;
					EditDynamicObject(playerid, BarricadeData[index][cadeObject]);
				}
				else 
				{
					Error(playerid, "Roadblock sudah mencapai batas maksimal ("#MAX_DYNAMIC_ROADBLOCK" roadblock).");
				}
			}
		}
	}
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerCameraPos(playerid, 1093.79, -2037.99, 83.57);
	SetPlayerCameraLookAt(playerid, 1093.19, -2037.19, 83.51);
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	DeletePVar(playerid, "UsingSprunk");
	SetPVarInt(playerid, "GiveUptime", -1);
	pData[playerid][pSpawned] = 0;
	Player_ResetCutting(playerid);
	Player_RemoveLumber(playerid);
	Player_ResetHarvest(playerid);
	
	pData[playerid][CarryProduct] = 0;
	
	KillTimer(pData[playerid][pActivity]);
	KillTimer(pData[playerid][pMechanic]);
	KillTimer(pData[playerid][pProducting]);
	KillTimer(pData[playerid][pMasak]);
	KillTimer(pData[playerid][pMeatJob]);
	KillTimer(pData[playerid][pSampah]);
	KillTimer(pData[playerid][pCooking]);
	
	pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
	pData[playerid][pActivityTime] = 0;
	pData[playerid][pTaxiDuty] = 0;
	
	pData[playerid][pMechDuty] = 0;
	
	pData[playerid][pSideJob] = 0;
	DisablePlayerCheckpoint(playerid);
	DisablePlayerRaceCheckpoint(playerid);
	SetPlayerColor(playerid, COLOR_WHITE);
	RemovePlayerAttachedObject(playerid, 9);
	GetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
	foreach(new ii : Player)
    {
        if(pData[ii][pAdmin] > 0)
        {
            SendDeathMessageToPlayer(ii, killerid, playerid, reason);
			SendDiscordMessage(3, sprintf("%s :skull_crossbones: %s :gun: %s", GetRPName(playerid), GetRPName(killerid), ReturnWeaponName(reason)));	
        }
    }
    if(IsAtEvent[playerid] == 0)
    {
    	new asakit = RandomEx(0, 5);
    	new bsakit = RandomEx(0, 9);
    	new csakit = RandomEx(0, 7);
    	new dsakit = RandomEx(0, 6);
    	pData[playerid][pLFoot] -= dsakit;
    	pData[playerid][pLHand] -= bsakit;
    	pData[playerid][pRFoot] -= csakit;
    	pData[playerid][pRHand] -= dsakit;
    	pData[playerid][pHead] -= asakit;
    }
    if(IsAtEvent[playerid] >= 1)
    {
        LeaveEvent(playerid);
    }
	return 1;
}

public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ,Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
	new weaponid = EditingWeapon[playerid];
    if(weaponid)
    {
        if(response == 1)
        {
            new enum_index = weaponid - 22, weaponname[18], string[340];
 
            GetWeaponName(weaponid, weaponname, sizeof(weaponname));
           
            WeaponSettings[playerid][enum_index][Position][0] = fOffsetX;
            WeaponSettings[playerid][enum_index][Position][1] = fOffsetY;
            WeaponSettings[playerid][enum_index][Position][2] = fOffsetZ;
            WeaponSettings[playerid][enum_index][Position][3] = fRotX;
            WeaponSettings[playerid][enum_index][Position][4] = fRotY;
            WeaponSettings[playerid][enum_index][Position][5] = fRotZ;
 
            RemovePlayerAttachedObject(playerid, GetWeaponObjectSlot(weaponid));
            SetPlayerAttachedObject(playerid, GetWeaponObjectSlot(weaponid), GetWeaponModel(weaponid), WeaponSettings[playerid][enum_index][Bone], fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, 1.0, 1.0, 1.0);
 
            Servers(playerid, "You have successfully adjusted the position of your %s.", weaponname);
           
            mysql_format(g_SQL, string, sizeof(string), "INSERT INTO weaponsettings (Owner, WeaponID, PosX, PosY, PosZ, RotX, RotY, RotZ) VALUES ('%d', %d, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f) ON DUPLICATE KEY UPDATE PosX = VALUES(PosX), PosY = VALUES(PosY), PosZ = VALUES(PosZ), RotX = VALUES(RotX), RotY = VALUES(RotY), RotZ = VALUES(RotZ)", pData[playerid][pID], weaponid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ);
            mysql_tquery(g_SQL, string);
        }
		else if(response == 0)
		{
			new enum_index = weaponid - 22;
			SetPlayerAttachedObject(playerid, GetWeaponObjectSlot(weaponid), GetWeaponModel(weaponid), WeaponSettings[playerid][enum_index][Bone], fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, 1.0, 1.0, 1.0);
		}
        EditingWeapon[playerid] = 0;
		return 1;
    }
	else
	{
		if(response == 1)
		{
			InfoTD_MSG(playerid, 1000, "~g~~h~Toy Position Updated~y~!");

			pToys[playerid][index][toy_x] = fOffsetX;
			pToys[playerid][index][toy_y] = fOffsetY;
			pToys[playerid][index][toy_z] = fOffsetZ;
			pToys[playerid][index][toy_rx] = fRotX;
			pToys[playerid][index][toy_ry] = fRotY;
			pToys[playerid][index][toy_rz] = fRotZ;
			pToys[playerid][index][toy_sx] = fScaleX;
			pToys[playerid][index][toy_sy] = fScaleY;
			pToys[playerid][index][toy_sz] = fScaleZ;
			
			MySQL_SavePlayerToys(playerid);
		}
		else if(response == 0)
		{
			InfoTD_MSG(playerid, 1000, "~r~~h~Selection Cancelled~y~!");

			SetPlayerAttachedObject(playerid,
				index,
				modelid,
				boneid,
				pToys[playerid][index][toy_x],
				pToys[playerid][index][toy_y],
				pToys[playerid][index][toy_z],
				pToys[playerid][index][toy_rx],
				pToys[playerid][index][toy_ry],
				pToys[playerid][index][toy_rz],
				pToys[playerid][index][toy_sx],
				pToys[playerid][index][toy_sy],
				pToys[playerid][index][toy_sz]);
		}
		SetPVarInt(playerid, "UpdatedToy", 1);
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}

public OnPlayerEditDynamicObject(playerid, STREAMER_TAG_OBJECT: objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	if(response == EDIT_RESPONSE_FINAL)
	{
		if(pData[playerid][pEditing] != -1 || pData[playerid][pGetPAYPHONEID] != -1)
		{
			if(pData[playerid][pEditType] == EDIT_TREE)
			{
				new etid = pData[playerid][pEditing];
				TreeData[etid][treeX] = x;
				TreeData[etid][treeY] = y;
				TreeData[etid][treeZ] = z;
				TreeData[etid][treeRX] = rx;
				TreeData[etid][treeRY] = ry;
				TreeData[etid][treeRZ] = rz;

				SetDynamicObjectPos(objectid, TreeData[etid][treeX], TreeData[etid][treeY], TreeData[etid][treeZ]);
				SetDynamicObjectRot(objectid, TreeData[etid][treeRX], TreeData[etid][treeRY], TreeData[etid][treeRZ]);

				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, TreeData[etid][treeLabel], E_STREAMER_X, TreeData[etid][treeX]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, TreeData[etid][treeLabel], E_STREAMER_Y, TreeData[etid][treeY]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, TreeData[etid][treeLabel], E_STREAMER_Z, TreeData[etid][treeZ] + 1.5);

				Tree_Save(etid);
				Tree_Refresh(etid);
			}
			else if(pData[playerid][pEditType] == EDIT_ATM)
			{
				new etid = pData[playerid][pEditing];
				AtmData[etid][atmX] = x;
				AtmData[etid][atmY] = y;
				AtmData[etid][atmZ] = z;
				AtmData[etid][atmRX] = rx;
				AtmData[etid][atmRY] = ry;
				AtmData[etid][atmRZ] = rz;

				SetDynamicObjectPos(objectid, AtmData[etid][atmX], AtmData[etid][atmY], AtmData[etid][atmZ]);
				SetDynamicObjectRot(objectid, AtmData[etid][atmRX], AtmData[etid][atmRY], AtmData[etid][atmRZ]);

				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, AtmData[etid][atmLabel], E_STREAMER_X, AtmData[etid][atmX]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, AtmData[etid][atmLabel], E_STREAMER_Y, AtmData[etid][atmY]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, AtmData[etid][atmLabel], E_STREAMER_Z, AtmData[etid][atmZ] + 0.3);

				Atm_Save(etid);
				Atm_Refresh(etid);
			}
			else if(pData[playerid][pEditType] == EDIT_MAP)
			{
				new mapoid = pData[playerid][pEditing];
				MapoData[mapoid][mapoX] = x;
				MapoData[mapoid][mapoY] = y;
				MapoData[mapoid][mapoZ] = z;
				MapoData[mapoid][mapoRX] = rx;
				MapoData[mapoid][mapoRY] = ry;
				MapoData[mapoid][mapoRZ] = rz;

				SetDynamicObjectPos(objectid, MapoData[mapoid][mapoX], MapoData[mapoid][mapoY], MapoData[mapoid][mapoZ]);
				SetDynamicObjectRot(objectid, MapoData[mapoid][mapoRX], MapoData[mapoid][mapoRY], MapoData[mapoid][mapoRZ]);

				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, MapoData[mapoid][mapoLabel], E_STREAMER_X, MapoData[mapoid][mapoX]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, MapoData[mapoid][mapoLabel], E_STREAMER_Y, MapoData[mapoid][mapoY]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, MapoData[mapoid][mapoLabel], E_STREAMER_Z, MapoData[mapoid][mapoZ] + 0.3);

				Mapo_Save(mapoid);
				Mapo_Refresh(mapoid);
			}
			else if(pData[playerid][pEditType] == EDIT_MATE)
			{
				new mtid = pData[playerid][pEditing];
				mtData[mtid][mtX] = x;
				mtData[mtid][mtY] = y;
				mtData[mtid][mtZ] = z;
				mtData[mtid][mtRX] = rx;
				mtData[mtid][mtRY] = ry;
				mtData[mtid][mtRZ] = rz;

				SetDynamicObjectPos(objectid, mtData[mtid][mtX], mtData[mtid][mtY], mtData[mtid][mtZ]);
				SetDynamicObjectRot(objectid, mtData[mtid][mtRX], mtData[mtid][mtRY], mtData[mtid][mtRZ]);

				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, mtData[mtid][mtLabel], E_STREAMER_X, mtData[mtid][mtX]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, mtData[mtid][mtLabel], E_STREAMER_Y, mtData[mtid][mtY]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, mtData[mtid][mtLabel], E_STREAMER_Z, mtData[mtid][mtZ] + 1.5);

				Matext_Save(mtid);
				Matext_Refresh(mtid);
			}
			else if(pData[playerid][pEditType] == EDIT_VENDING)
			{
				new venid = pData[playerid][pEditing];
				vmData[venid][venX] = x;
				vmData[venid][venY] = y;
				vmData[venid][venZ] = z;
				vmData[venid][venRX] = rx;
				vmData[venid][venRY] = ry;
				vmData[venid][venRZ] = rz;

				SetDynamicObjectPos(objectid, vmData[venid][venX], vmData[venid][venY], vmData[venid][venZ]);
				SetDynamicObjectRot(objectid, vmData[venid][venRX], vmData[venid][venRY], vmData[venid][venRZ]);

				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, vmData[venid][venLabel], E_STREAMER_X, vmData[venid][venX]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, vmData[venid][venLabel], E_STREAMER_Y, vmData[venid][venY]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, vmData[venid][venLabel], E_STREAMER_Z, vmData[venid][venZ] + 1.5);

				Vending_Save(venid);
				Vending_Refresh(venid);
			}
			else if(pData[playerid][pEditType] == EDIT_SPEEDCAM)
			{
				new camid = pData[playerid][pEditing];
				camData[camid][camX] = x;
				camData[camid][camY] = y;
				camData[camid][camZ] = z;
				camData[camid][camRX] = rx;
				camData[camid][camRY] = ry;
				camData[camid][camRZ] = rz;

				SetDynamicObjectPos(objectid, camData[camid][camX], camData[camid][camY], camData[camid][camZ]);
				SetDynamicObjectRot(objectid, camData[camid][camRX], camData[camid][camRY], camData[camid][camRZ]);

				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, camData[camid][camLabel], E_STREAMER_X, camData[camid][camX]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, camData[camid][camLabel], E_STREAMER_Y, camData[camid][camY]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, camData[camid][camLabel], E_STREAMER_Z, camData[camid][camZ] + 3.5);

				Speedcam_Save(camid);
				Speedcam_Refresh(camid);
			}
			else if(pData[playerid][pEditType] == EDIT_TRASH)
			{
				new trashid = pData[playerid][pEditing];
				tmData[trashid][tmX] = x;
				tmData[trashid][tmY] = y;
				tmData[trashid][tmZ] = z;
				tmData[trashid][tmRX] = rx;
				tmData[trashid][tmRY] = ry;
				tmData[trashid][tmRZ] = rz;

				SetDynamicObjectPos(objectid, tmData[trashid][tmX], tmData[trashid][tmY], tmData[trashid][tmZ]);
				SetDynamicObjectRot(objectid, tmData[trashid][tmRX], tmData[trashid][tmRY], tmData[trashid][tmRZ]);

				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, tmData[trashid][tmLabel], E_STREAMER_X, tmData[trashid][tmX]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, tmData[trashid][tmLabel], E_STREAMER_Y, tmData[trashid][tmY]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, tmData[trashid][tmLabel], E_STREAMER_Z, tmData[trashid][tmZ] + 0.5);

				Trash_Save(trashid);
				Trash_Refresh(trashid);
			}
			else if(pData[playerid][pEditType] == EDIT_SIGNAL)
			{
				new sgid = pData[playerid][pEditing];
				sgData[sgid][sgX] = x;
				sgData[sgid][sgY] = y;
				sgData[sgid][sgZ] = z;
				sgData[sgid][sgRX] = rx;
				sgData[sgid][sgRY] = ry;
				sgData[sgid][sgRZ] = rz;

				SetDynamicObjectPos(objectid, sgData[sgid][sgX], sgData[sgid][sgY], sgData[sgid][sgZ]);
				SetDynamicObjectRot(objectid, sgData[sgid][sgRX], sgData[sgid][sgRY], sgData[sgid][sgRZ]);

				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, sgData[sgid][sgLabel], E_STREAMER_X, sgData[sgid][sgX]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, sgData[sgid][sgLabel], E_STREAMER_Y, sgData[sgid][sgY]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, sgData[sgid][sgLabel], E_STREAMER_Z, sgData[sgid][sgZ] + 3.5);

				Signal_Save(sgid);
				Signal_Refresh(sgid);
			}
			else if(pData[playerid][pGetPAYPHONEID] != -1)
			{
				new ppid = pData[playerid][pGetPAYPHONEID];

				ppData[ppid][ppX] = x;
				ppData[ppid][ppY] = y;
				ppData[ppid][ppZ] = z;

				ppData[ppid][ppRX] = rx;
				ppData[ppid][ppRY] = ry;
				ppData[ppid][ppRZ] = rz;

				SetDynamicObjectPos(objectid, ppData[ppid][ppX], ppData[ppid][ppY], ppData[ppid][ppZ]);
				SetDynamicObjectRot(objectid, ppData[ppid][ppRX], ppData[ppid][ppRY], ppData[ppid][ppRZ]);

				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, ppData[ppid][ppLabel], E_STREAMER_X, ppData[ppid][ppX]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, ppData[ppid][ppLabel], E_STREAMER_Y, ppData[ppid][ppY]);
				Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, ppData[ppid][ppLabel], E_STREAMER_Z, ppData[ppid][ppZ] + 1.0);

				Payphone_Save(ppid);
				Payphone_Refresh(ppid);
			}
			else if(pData[playerid][pEditType] == EDIT_GATE)
			{
				SetDynamicObjectPos(objectid, x, y, z);
				SetDynamicObjectRot(objectid, rx, ry, rz);
				new id = pData[playerid][pEditing];
				switch(pData[playerid][pEditGate])
				{
					case 1:
					{
						gData[id][gCX] = x;
						gData[id][gCY] = y;
						gData[id][gCZ] = z;
						gData[id][gCRX] = rx;
						gData[id][gCRY] = ry;
						gData[id][gCRZ] = rz;
						if(IsValidDynamic3DTextLabel(gData[id][gText])) DestroyDynamic3DTextLabel(gData[id][gText]);
						new str[64];
						format(str, sizeof(str), "Gate ID: %d", id);
						gData[id][gText] = CreateDynamic3DTextLabel(str, COLOR_WHITE, gData[id][gCX], gData[id][gCY], gData[id][gCZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 10.0);
						
						Servers(playerid, " You have finished editing gate ID %d's closing position.", id);
						gData[id][gStatus] = 0;
						Gate_Save(id);
					}
					case 2:
					{
						gData[id][gOX] = x;
						gData[id][gOY] = y;
						gData[id][gOZ] = z;
						gData[id][gORX] = rx;
						gData[id][gORY] = ry;
						gData[id][gORZ] = rz;
						
						Servers(playerid, " You have finished editing gate ID %d's opening position.", id);

						gData[id][gStatus] = 1;
						Gate_Save(id);
					}
				}
			} 
			else if(pData[playerid][pEditType] == EDIT_TAG)
			{
				new id = pData[playerid][pEditing];
				SetDynamicObjectPos(objectid, x, y, z);
				SetDynamicObjectRot(objectid, rx, ry, rz);
				TagData[id][tagPos][0] = x;
				TagData[id][tagPos][1] = y;
				TagData[id][tagPos][2] = z;
				TagData[id][tagPos][3] = rx;
				TagData[id][tagPos][4] = ry;
				TagData[id][tagPos][5] = rz;

				SuccesMsg(playerid, "Posisi SprayTag berhasil di simpan");
				SuccesMsg(playerid, "SprayTag berhasil di buat");

				Tag_Save(id);
			}
			else if(pData[playerid][pEditType] == EDIT_BLOCK)
            {
                new index = pData[playerid][pEditing];
                BarricadeData[index][cadePos][0] = x;
                BarricadeData[index][cadePos][1] = y;
                BarricadeData[index][cadePos][2] = z;
                BarricadeData[index][cadePos][3] = rx;
                BarricadeData[index][cadePos][4] = ry;
                BarricadeData[index][cadePos][5] = rz;
                Barricade_Sync(index);
            }
		}
		pData[playerid][pEditing] = -1;
		pData[playerid][pEditType] = EDIT_NONE;
		pData[playerid][pGetPAYPHONEID] = -1;
	}
	if(response == EDIT_RESPONSE_CANCEL)
    {
		pData[playerid][pEditing] = -1;
		pData[playerid][pEditType] = EDIT_NONE;
		pData[playerid][pGetPAYPHONEID] = -1;
    }
	return 1;
}

public OnPlayerEnterDynamicArea(playerid, areaid)
{
	if(IsPlayerConnected(playerid))
	{
		foreach(new bbid : Boombox)
		{
			if(Iter_Contains(Boombox, bbid))
			{
				if(areaid == bbData[bbid][bbAreaid])
				{
					new str[250];
					format(str, sizeof(str), "Anda telah memasuki area Boombox (ID: %d)", bbid);
					InfoMsg(playerid, str);
					PlayAudioStreamForPlayer(playerid, bbData[bbid][bbUrl], bbData[bbid][bbPosX], bbData[bbid][bbPosY], bbData[bbid][bbPosZ], 30.0, 1);
				}
			}
		}
		for(new ptid = 0; ptid < 10; ptid++)
		{
			if(areaid == PaytollAreaid[ptid])
			{
				GameTextForPlayer(playerid, "~w~~h~PAYTOLL AREA~n~~r~~h~ /PAYTOLL ~n~~w~~h~TO OPEN TOLL GATE", 3000, 4);
			}
		}
	}
	return 1;
}

public OnPlayerLeaveDynamicArea(playerid, areaid)
{
	if(IsPlayerConnected(playerid))
	{
		foreach(new bbid : Boombox)
		{
			if(Iter_Contains(Boombox, bbid))
			{
				if(areaid == bbData[bbid][bbAreaid])
				{
					StopAudioStreamForPlayer(playerid);
				}
			}
		}
		foreach(new ppid : Payphone)
		{
			if(Iter_Contains(Payphone, ppid))
			{
				if(areaid == ppData[ppid][ppAreaid])
				{
					if(pData[playerid][pGetPAYPHONEID] != -1)
					{
						new caller = pData[playerid][pCall];
						if(IsPlayerConnected(caller) && caller != INVALID_PLAYER_ID)
						{
							pData[caller][pCall] = INVALID_PLAYER_ID;
							SetPlayerSpecialAction(caller, SPECIAL_ACTION_STOPUSECELLPHONE);
							SendNearbyMessage(caller, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(caller));
							
							pData[playerid][pCall] = INVALID_PLAYER_ID;
							SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s puts away their payphone.", ReturnName(playerid));
							SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
							
							Info(playerid, "Kamu terlalu jauh dari jarak payphone, dan panggilan dimatikan");
							
							pData[playerid][pGetPAYPHONEID] = -1;
							ppData[ppid][ppStatus] = 0;

							Payphone_Refresh(ppid);
							Payphone_Save(ppid);
						}
					}
				}
			}
		}
	}
	return 1;
}

/*
public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
	return 1;
}
*/

public OnPlayerEnterRaceCheckpoint(playerid)
{
	if(pData[playerid][pGetSIM] == 1)
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if(GetVehicleModel(vehicleid) == 445)
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint1))
            {
				SetPlayerRaceCheckpoint(playerid, 0, getsimpoint1, getsimpoint2, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint2))
            {
                SetPlayerRaceCheckpoint(playerid, 0, getsimpoint2, getsimpoint3, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint3))
            {
                SetPlayerRaceCheckpoint(playerid, 0, getsimpoint3, getsimpoint4, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint4))
            {
                SetPlayerRaceCheckpoint(playerid, 0, getsimpoint4, getsimpoint5, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint5))
            {
                SetPlayerRaceCheckpoint(playerid, 0, getsimpoint5, getsimpoint6, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint6))
            {
                SetPlayerRaceCheckpoint(playerid, 0, getsimpoint6, getsimpoint7, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint7))
            {
                SetPlayerRaceCheckpoint(playerid, 0, getsimpoint7, getsimpoint8, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint8))
            {
                SetPlayerRaceCheckpoint(playerid, 0, getsimpoint8, getsimpoint9, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint9))
            {
                SetPlayerRaceCheckpoint(playerid, 0, getsimpoint9, getsimpoint10, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint10))
            {
                SetPlayerRaceCheckpoint(playerid, 0, getsimpoint10, getsimpoint11, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint11))
            {
                SetPlayerRaceCheckpoint(playerid, 1, getsimpoint11, getsimpoint12, 7.0);
				DisablePlayerCheckpoint(playerid);
            }
            if (IsPlayerInRangeOfPoint(playerid, 3.0,getsimpoint12))
            {
                new sext[40], mstr[128];
                if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }
                format(mstr, sizeof(mstr), "{FFFFFF}Nama: %s\nNegara: San Andreas\nTgl Lahir: %s\nJenis Kelamin: %s\nBerlaku hingga 14 hari!", pData[playerid][pName], pData[playerid][pAge], sext);
                ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Driving License", mstr, "Tutup", "");
                SuccesMsg(playerid, "Anda telah berhasil menyelesaikan Test Driving");
                pData[playerid][pGetSIM] = 0;
                pData[playerid][pDriveLic] = 1;
                pData[playerid][pDriveLicTime] = gettime() + (15 * 86400);
                DisablePlayerCheckpoint(playerid);
                RemovePlayerFromVehicle(playerid);
                SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
            }
        }
    }
	if(pData[playerid][pTrackCar] == 1)
	{
		SuccesMsg(playerid, "Kendaraan anda berhasil di temukan");
		pData[playerid][pTrackCar] = 0;
		DisablePlayerRaceCheckpoint(playerid);
	}
	if(pData[playerid][pTrackHouse] == 1)
	{
		SuccesMsg(playerid, "Rumah anda berhasil di temukan");
		pData[playerid][pTrackHouse] = 0;
		DisablePlayerRaceCheckpoint(playerid);
	}
	if(pData[playerid][pMissionVen] > -1)
	{
		DisablePlayerRaceCheckpoint(playerid);
		SuccesMsg(playerid, "Anda telah berhasil sampai di tujuan");
		SyntaxMsg(playerid, "/unloadbox");
	}
	DisablePlayerRaceCheckpoint(playerid);
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	pData[playerid][pClikmap] = 0;

	if(IsASweeperVeh(vehicleid))
	{
		pData[playerid][pSideJob] = 0;
		pData[playerid][pSweeperRoute] = 0;
		SweeperCP[playerid] = 0;
		DisablePlayerCheckpoint(playerid);
		SyntaxMsg(playerid, "Anda telah keluar dari kendaraan Sweeper dan harus mengulangnya");
		SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
	}
	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	if(pData[playerid][pAdmin] != 0 && pData[playerid][pAdminDuty] != 0)
	{
		new Float:a;
		GetPlayerFacingAngle(playerid, a);
		SetPlayerPosition(playerid, fX, fY, fZ, a, 0);
		SetPlayerVirtualWorld(playerid, 0);
		SuccesMsg(playerid, "Berhasil berpindah ke tempat yang di tandai");
	}
	//playermark
    if(GetPlayerWayPointStatus(playerid))
    {
        RemovePlayerMapIcon(playerid, 20);
    }
    if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SetDriverMarkerPoint(playerid, fX, fY, fZ);
		SetPlayerWaze(playerid, Float:fX, Float:fY, Float:fZ, 0x8A44E4FF);
    }
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
    new playerState = GetPlayerState(playerid);
    if(RobBankProgress[playerid] == 1)
    {
    	if(playerState == PLAYER_STATE_ONFOOT || playerState == PLAYER_STATE_DRIVER)
    	{
    		if(IsPlayerInRangeOfPoint(playerid, 3.5, 1458.35, -1024.54, 23.82))
    		{
    			RobBankStatus = 1;
    			RobBankText[1] = CreateDynamic3DTextLabel(""YELLOW_E"[ROBBANK]\n"WHITE_E"/placebomb", COLOR_YELLOW, -990.61, 1468.34, 1332.02, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Placed Bomb
    			DisablePlayerCheckpoint(playerid);
    			SuccesMsg(playerid, "Berhasil sampai di bank, lanjutkan dengan memasuki bank");
    		}
    	}
    }
    if(pData[playerid][pJob] == 8 || pData[playerid][pJob2] == 8) //TAKE GAS
    {
    	if(playerState == PLAYER_STATE_DRIVER)
    	{
    		if(HaulingType[playerid] == 1)
    		{
			    if(IsPlayerInRangeOfPoint(playerid, 15.0,  2781.00, -2493.73, 13.75))
			    {
			    	new randgas = Iter_Random(GStation);
			    	AttachTrailerToVehicle(VehHauling[playerid], GetPlayerVehicleID(playerid));
			    	DisablePlayerCheckpoint(playerid);
			    	SetPVarInt(playerid, "RandGAS", randgas);
			    	SetPlayerCheckpoint(playerid, gsData[randgas][gsPosX], gsData[randgas][gsPosY], gsData[randgas][gsPosZ], 4.5);
			    	SuccesMsg(playerid, "Trailer berhasil terpasang");
			    }
		    }
	    }
	}
    if(pData[playerid][pJob] == 8 || pData[playerid][pJob2] == 8) //TAKE DEALER
    {
    	if(playerState == PLAYER_STATE_DRIVER)
    	{
    		if(HaulingType[playerid] == 2)
    		{
    			if(IsAHaulingVeh(GetPlayerVehicleID(playerid)))
    			{
				    if(IsPlayerInRangeOfPoint(playerid, 15.0, 2781.44, -2455.97, 13.73))
				    {
						new deid = pData[playerid][pGetDEIDHAULING];
						AttachTrailerToVehicle(VehHauling[playerid], GetPlayerVehicleID(playerid));
				    	DisablePlayerCheckpoint(playerid);
				    	SetPlayerCheckpoint(playerid, drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ], 4.5);
						Info(playerid, "Anda harus menuju dealer yang berlokasi di %s berjarak %0.0fm", GetLocation(drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]), GetPlayerDistanceFromPoint(playerid, drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]));
				    }
				}
		    }
	    }
	}
	if(pData[playerid][pJob] == 8 || pData[playerid][pJob2] == 8) //SAMPAI SELESAI ANTAR GAS
	{
		if(playerState == PLAYER_STATE_DRIVER)
		{
			if(HaulingType[playerid] == 1)
			{
				new gsrand = GetPVarInt(playerid, "RandGAS");
				if(IsPlayerInRangeOfPoint(playerid, 4.5, gsData[gsrand][gsPosX], gsData[gsrand][gsPosY], gsData[gsrand][gsPosZ]))
				{
					DetachTrailerFromVehicle(GetPlayerVehicleID(playerid));

					DestroyVehicle(VehHauling[playerid]);

					DisablePlayerCheckpoint(playerid);
					GivePlayerMoneyEx(playerid, haulingprice1);
					new str[150];
					format(str, sizeof(str), "Berhasil mengantar trailer sampai tujuan, anda mendapatkan uang $%d", haulingprice1);
					SuccesMsg(playerid, str);

					VehHauling[playerid] = -1;
					HaulingType[playerid] = 0;
					pData[playerid][pJobTime] = 60;
					pData[playerid][pHunger] -= 10;
					pData[playerid][pEnergy] -= 15;
					gsData[gsrand][gsStock] += 5;

					GStation_Save(gsrand);
					GStation_Refresh(gsrand);
				}
			}
		}
	}
	if(pData[playerid][pJob] == 8 || pData[playerid][pJob2] == 8) //SAMPAI SELESAI ANTAR DEALER
	{
		if(playerState == PLAYER_STATE_DRIVER)
		{
			if(HaulingType[playerid] == 2)
			{
				new deid = pData[playerid][pGetDEIDHAULING];
				if(IsPlayerInRangeOfPoint(playerid, 4.5, drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]))
				{
					DetachTrailerFromVehicle(GetPlayerVehicleID(playerid));

					DestroyVehicle(VehHauling[playerid]);

					DisablePlayerCheckpoint(playerid);
					GivePlayerMoneyEx(playerid, haulingprice2);

					VehHauling[playerid] = -1;
					HaulingType[playerid] = 0;

					pData[playerid][pGetDEIDHAULING] = -1;

					drData[deid][dStock] += 5;
					drData[deid][dMoney] -= 20000;

					pData[playerid][pJobTime] = 60;
					pData[playerid][pHunger] -= 10;
					pData[playerid][pEnergy] -= 15;
					
					Dealer_Save(deid);
					Dealer_Refresh(deid);
					new str[250];
					format(str, sizeof(str), "Anda berhasil mengisi 5 stock dealer ini, Anda mendapatkan uang $%s", haulingprice2);
					SuccesMsg(playerid, str);
				}
			}
		}
	}
	if(pData[playerid][pJob] == 12 || pData[playerid][pJob2] == 12)
	{
		if(pData[playerid][pDrugDealer] == 1)
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.5, 2167.21, -1672.69, 15.07))
			{
				pData[playerid][pDrugDealer] = 0;
				pData[playerid][pJobTime] = 30;
				pData[playerid][pHunger] -= 10;
				pData[playerid][pEnergy] -= 15;
				
				DisablePlayerCheckpoint(playerid);
				GivePlayerMoneyEx(playerid, drugdealerprice1);
				pData[playerid][pDrugDealer] = 0;
				
				Marijuana += 20;
				Server_AddMoney(500);
				new str[250];
				format(str, sizeof(str), "Anda telah berhasil mengantar paket Marijuana, dan mendapatkan uang $%d", drugdealerprice1);
				SuccesMsg(playerid, str);
			}
		}
		if(pData[playerid][pDrugDealer] == 2)
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.5, 2167.21, -1672.69, 15.07))
			{
				pData[playerid][pDrugDealer] = 0;
				pData[playerid][pHunger] -= 10;
				pData[playerid][pEnergy] -= 15;

				DisablePlayerCheckpoint(playerid);
				GivePlayerMoneyEx(playerid, drugdealerprice2);
				pData[playerid][pDrugDealer] = 0;
				
				Ephedrine += 20;
				Server_AddMoney(500);
				new str[250];
				format(str, sizeof(str), "Anda telah berhasil mengantar paket RAW Ephedrine, dan mendapatkan uang $%d", drugdealerprice2);
				SuccesMsg(playerid, str);
			}
		}
		else if(pData[playerid][pDrugDealer] == 3)
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.5, 2351.82, -1168.90, 27.98))
			{
				pData[playerid][pDrugDealer] = 0;

				pData[playerid][pJobTime] = 60;
				pData[playerid][pHunger] -= 10;
				pData[playerid][pEnergy] -= 15;

				DisablePlayerCheckpoint(playerid);
				GivePlayerMoneyEx(playerid, drugdealerprice3);

				Cocaine += 20;
				Server_AddMoney(500);
				Info(playerid, "Kamu telah mengantar paket Cocaine sampai tujuan, dan mendapatkan bayaran "GREEN_E"%s"WHITE_E"", FormatMoney(drugdealerprice3));
			}
		}
	}
	if(pData[playerid][pJob] == 13 || pData[playerid][pJob2] == 13)
	{
		if(pData[playerid][pSmuggleMats] == 1)
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.5, 2288.09, -1105.65, 37.97))
			{
				DisablePlayerCheckpoint(playerid);

				pData[playerid][pSmuggleMats] = 0;
				Inventory_Add(playerid, "Material", 17051, 25);
				Inventory_Remove(playerid, "Component", 150);

				Info(playerid, "Kamu telah mengantar mats kegudang, dan mendapatkan "YELLOW_E"15"WHITE_E" material");
			}
		}
	}
	if(pData[playerid][pJob] == 13 || pData[playerid][pJob2] == 13)
	{
		if(pData[playerid][pSmuggleMats] == 2)
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.5, 2173.21, -2264.15, 13.34))
			{
				DisablePlayerCheckpoint(playerid);

				pData[playerid][pSmuggleMats] = 0;
				Inventory_Add(playerid, "Material", 17051, 25);
				Info(playerid, "Kamu telah mengantar mats kegudang, dan mendapatkan "YELLOW_E"15"WHITE_E" material");
			}
		}
	}
    if(pData[playerid][pSideJob] == 3)
    {
    	new vehicleid = GetPlayerVehicleID(playerid);
    	if(GetVehicleModel(vehicleid) == 574)
    	{
    		if(pData[playerid][pSweeperRoute] == 1)
    		{
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweperpoint1))
    			{
    				if(SweeperCP[playerid] == 0)
    				{
    					SetPlayerCheckpoint(playerid, sweperpoint2, 7.0);
    					SweeperCP[playerid] = 1;
    				}
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweperpoint2))
    			{
    				SetPlayerCheckpoint(playerid, sweperpoint3, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweperpoint3))
    			{
    				SetPlayerCheckpoint(playerid, sweperpoint4, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweperpoint4))
    			{
    				SetPlayerCheckpoint(playerid, sweperpoint5, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweperpoint5))
    			{
    				SetPlayerCheckpoint(playerid, sweperpoint6, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweperpoint6))
    			{
    				SetPlayerCheckpoint(playerid, sweperpoint7, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweperpoint7))
    			{
    				SetPlayerCheckpoint(playerid, sweperpoint8, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweperpoint8))
    			{
    				SetPlayerCheckpoint(playerid, sweperpoint9, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweperpoint9))
    			{
    				if(SweeperCP[playerid] == 1)
    				{
    					SetPlayerCheckpoint(playerid, sweperpoint10, 7.0);
    					SweeperCP[playerid] = 2;
						PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    				}
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweperpoint10))
    			{
    				if(SweeperCP[playerid] == 2)
    				{
    					pData[playerid][pSideJob] = 0;
						pData[playerid][pSideJobTime] = 120;
						pData[playerid][pSweeperRoute] = 0;
						SweeperCP[playerid] = 0;
						DisablePlayerCheckpoint(playerid);
						AddPlayerSalary(playerid, "Sweeper (SIDE JOB)", 250);
						InfoTD_MSG(playerid, 2000, "Paycheck telah masuk ke ~y~/salary ~w~anda");
						RemovePlayerFromVehicle(playerid);
						SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
						PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    				}	
    			}
    		}
    		else if(pData[playerid][pSweeperRoute] == 2)
    		{
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweper1))
    			{
    				if(SweeperCP[playerid] == 0)
    				{
    					SetPlayerCheckpoint(playerid, sweper2, 7.0);
    					SweeperCP[playerid] = 1;
						PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    				}
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweper2))
    			{
    				SetPlayerCheckpoint(playerid, sweper3, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweper3))
    			{
    				SetPlayerCheckpoint(playerid, sweper4, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweper4))
    			{
    				SetPlayerCheckpoint(playerid, sweper5, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweper5))
    			{
    				SetPlayerCheckpoint(playerid, sweper6, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweper6))
    			{
    				SetPlayerCheckpoint(playerid, sweper7, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweper7))
    			{
    				SetPlayerCheckpoint(playerid, sweper8, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweper8))
    			{
    				SetPlayerCheckpoint(playerid, sweper9, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweper9))
    			{
    				if(SweeperCP[playerid] == 1)
    				{
    					SetPlayerCheckpoint(playerid, sweper10, 7.0);
    					SweeperCP[playerid] = 2;
						PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    				}
    			}
    			if(IsPlayerInRangeOfPoint(playerid, 7.0, sweper10))
    			{
    				if(SweeperCP[playerid] == 2)
    				{
    					pData[playerid][pSideJob] = 0;
						pData[playerid][pSideJobTime] = 120;
						pData[playerid][pSweeperRoute] = 0;
						SweeperCP[playerid] = 0;
						DisablePlayerCheckpoint(playerid);
						AddPlayerSalary(playerid, "Sweeper (SIDE JOB)", 500);
						InfoTD_MSG(playerid, 2000, "Paycheck telah masuk ke ~y~/salary ~w~anda");
						RemovePlayerFromVehicle(playerid);
						SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
						PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
    				}	
    			}    			
    		}
    	}
    }
	if(pData[playerid][pSideJob] == 2)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(GetVehicleModel(vehicleid) == 431)
		{
			if(pData[playerid][pBusRoute] == 1)
			{
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket1))
				{
					SetPlayerCheckpoint(playerid, buspointmarket2, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket2))
				{
					SetPlayerCheckpoint(playerid, buspointmarket3, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket3))
				{
					SetPlayerCheckpoint(playerid, buspointmarket4, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket4))
				{
					SetPlayerCheckpoint(playerid, buspointmarket5, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket5))
				{
					SetPlayerCheckpoint(playerid, buspointmarket6, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket6))
				{
					SetPlayerCheckpoint(playerid, buspointmarket7, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket7))
				{
					SetPlayerCheckpoint(playerid, buspointmarket8, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket8))
				{
					SetPlayerCheckpoint(playerid, buspointmarket9, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket9))
				{
					pData[playerid][pBuswaiting] = true;
					pData[playerid][pBustime] = 10;
					SyntaxMsg(playerid, "Tunggu selama 10 detik untuk melanjutkan perjalanan");
					PlayerPlaySound(playerid, 43000, 0.0, 0.0, 0.0);
					//SetPlayerCheckpoint(playerid, buspointmarket10, 7.0);
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket10))
				{
					SetPlayerCheckpoint(playerid, buspointmarket11, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket11))
				{
					SetPlayerCheckpoint(playerid, buspointmarket12, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket12))
				{
					SetPlayerCheckpoint(playerid, buspointmarket13, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket13))
				{
					SetPlayerCheckpoint(playerid, buspointmarket14, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket14))
				{
					SetPlayerCheckpoint(playerid, buspointmarket15, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket15))
				{
					SetPlayerCheckpoint(playerid, buspointmarket16, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket16))
				{
					pData[playerid][pBuswaiting] = true;
					pData[playerid][pBustime] = 10;
					SyntaxMsg(playerid, "Tunggu selama 10 detik untuk melanjutkan perjalanan");
					PlayerPlaySound(playerid, 43000, 0.0, 0.0, 0.0);
					//SetPlayerCheckpoint(playerid, buspointmarket17, 7.0);
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket17))
				{
					SetPlayerCheckpoint(playerid, buspointmarket18, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket18))
				{
					SetPlayerCheckpoint(playerid, buspointmarket19, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket19))
				{
					SetPlayerCheckpoint(playerid, buspointmarket20, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket20))
				{
					SetPlayerCheckpoint(playerid, buspointmarket21, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket21))
				{
					SetPlayerCheckpoint(playerid, buspointmarket22, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket22))
				{
					SetPlayerCheckpoint(playerid, buspointmarket23, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket23))
				{
					SetPlayerCheckpoint(playerid, buspointmarket24, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket24))
				{
					pData[playerid][pBuswaiting] = true;
					pData[playerid][pBustime] = 10;
					SyntaxMsg(playerid, "Tunggu selama 10 detik untuk melanjutkan perjalanan");
					PlayerPlaySound(playerid, 43000, 0.0, 0.0, 0.0);
					//SetPlayerCheckpoint(playerid, buspointmarket25, 7.0);
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket25))
				{
					SetPlayerCheckpoint(playerid, buspointmarket26, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket26))
				{
					SetPlayerCheckpoint(playerid, buspointmarket27, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket27))
				{
					SetPlayerCheckpoint(playerid, buspointmarket28, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket28))
				{
					SetPlayerCheckpoint(playerid, buspointmarket29, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket29))
				{
					pData[playerid][pBuswaiting] = true;
					pData[playerid][pBustime] = 10;
					SyntaxMsg(playerid, "Tunggu selama 10 detik untuk melanjutkan perjalanan");
					PlayerPlaySound(playerid, 43000, 0.0, 0.0, 0.0);
					//SetPlayerCheckpoint(playerid, buspointmarket30, 7.0);
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket30))
				{
					SetPlayerCheckpoint(playerid, buspointmarket31, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket31))
				{
					SetPlayerCheckpoint(playerid, buspointmarket32, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket32))
				{
					SetPlayerCheckpoint(playerid, buspointmarket33, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket33))
				{
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
					SetPlayerCheckpoint(playerid, buspointmarket34, 7.0);
					//SetPlayerCheckpoint(playerid, buspointmarket34, 7.0);
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket34))
				{
					pData[playerid][pBuswaiting] = true;
					pData[playerid][pBustime] = 10;
					SyntaxMsg(playerid, "Tunggu selama 10 detik untuk melanjutkan perjalanan");
					PlayerPlaySound(playerid, 43000, 0.0, 0.0, 0.0);
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket35))
				{
					SetPlayerCheckpoint(playerid, buspointmarket36, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket36))
				{
					SetPlayerCheckpoint(playerid, buspointmarket37, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket37))
				{
					SetPlayerCheckpoint(playerid, buspointmarket38, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket38))
				{
					pData[playerid][pSideJob] = 0;
					pData[playerid][pSideJobTime] = 300;
					pData[playerid][pBusRoute] = 0;
					DisablePlayerCheckpoint(playerid);
					AddPlayerSalary(playerid, "Supir Bus (SIDE JOB)", sjbus);
					InfoTD_MSG(playerid, 2000, "Paycheck telah masuk ke ~y~/salary ~w~anda");
					RemovePlayerFromVehicle(playerid);
					SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
				}
			}
			else if(pData[playerid][pBusRoute] == 2)
			{
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor1))
				{
					SetPlayerCheckpoint(playerid, buspointelcor2, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor2))
				{
					SetPlayerCheckpoint(playerid, buspointelcor3, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor3))
				{
					SetPlayerCheckpoint(playerid, buspointelcor4, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor4))
				{
					SetPlayerCheckpoint(playerid, buspointelcor5, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor5))
				{
					SetPlayerCheckpoint(playerid, buspointelcor6, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor6))
				{
					SetPlayerCheckpoint(playerid, buspointelcor7, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor7))
				{
					pData[playerid][pBuswaiting] = true;
					pData[playerid][pBustime] = 10;
					SyntaxMsg(playerid, "Tunggu selama 10 detik untuk melanjutkan perjalanan");
					PlayerPlaySound(playerid, 43000, 0.0, 0.0, 0.0);
					//SetPlayerCheckpoint(playerid, buspointelcor8, 7.0);
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor8))
				{
					SetPlayerCheckpoint(playerid, buspointelcor9, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor9))
				{
					SetPlayerCheckpoint(playerid, buspointelcor10, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor10))
				{
					pData[playerid][pBuswaiting] = true;
					pData[playerid][pBustime] = 10;
					SyntaxMsg(playerid, "Tunggu selama 10 detik untuk melanjutkan perjalanan");
					PlayerPlaySound(playerid, 43000, 0.0, 0.0, 0.0);
					//SetPlayerCheckpoint(playerid, buspointelcor11, 7.0);
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor11))
				{
					SetPlayerCheckpoint(playerid, buspointelcor12, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor12))
				{
					SetPlayerCheckpoint(playerid, buspointelcor13, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor13))
				{
					SetPlayerCheckpoint(playerid, buspointelcor14, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor14))
				{
					SetPlayerCheckpoint(playerid, buspointelcor15, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor15))
				{
					pData[playerid][pBuswaiting] = true;
					pData[playerid][pBustime] = 10;
					SyntaxMsg(playerid, "Tunggu selama 10 detik untuk melanjutkan perjalanan");
					PlayerPlaySound(playerid, 43000, 0.0, 0.0, 0.0);
					//SetPlayerCheckpoint(playerid, buspointelcor16, 7.0);
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor16))
				{
					SetPlayerCheckpoint(playerid, buspointelcor17, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor17))
				{
					SetPlayerCheckpoint(playerid, buspointelcor18, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor18))
				{
					SetPlayerCheckpoint(playerid, buspointelcor19, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor19))
				{
					SetPlayerCheckpoint(playerid, buspointelcor20, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor20))
				{
					SetPlayerCheckpoint(playerid, buspointelcor21, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor21))
				{
					pData[playerid][pBuswaiting] = true;
					pData[playerid][pBustime] = 10;
					SyntaxMsg(playerid, "Tunggu selama 10 detik untuk melanjutkan perjalanan");
					PlayerPlaySound(playerid, 43000, 0.0, 0.0, 0.0);
					//SetPlayerCheckpoint(playerid, buspointelcor22, 7.0);
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor22))
				{
					SetPlayerCheckpoint(playerid, buspointelcor23, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor23))
				{
					SetPlayerCheckpoint(playerid, buspointelcor24, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor24))
				{
					SetPlayerCheckpoint(playerid, buspointelcor25, 7.0);
					PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);     
				}
				if (IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor25))
				{
					pData[playerid][pSideJob] = 0;
					pData[playerid][pSideJobTime] = 300;
					pData[playerid][pBusRoute] = 0;
					DisablePlayerCheckpoint(playerid);
					AddPlayerSalary(playerid, "Supir Bus (SIDE JOB)", sjbus);
					InfoTD_MSG(playerid, 2000, "Paycheck telah masuk ke ~y~/salary ~w~anda");
					RemovePlayerFromVehicle(playerid);
					SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
				}
			}
		}
	}
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	if(pData[playerid][pBusRoute] && IsABusVeh(GetPlayerVehicleID(playerid)))
	{
		pData[playerid][pBuswaiting] = false;
	}
	return 1;
}

forward JobForklift(playerid);
public JobForklift(playerid)
{
	TogglePlayerControllable(playerid, 1);
	InfoTD_MSG(playerid, 1000, "~w~job telah kamu selsaikan!");
	
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(InfoSkate[playerid][sActive] && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		static bool:act;
		if(newkeys & KEY_YES)
		{
			#if MODE_SKATE == 0
			ApplyAnimation(playerid, "SKATE","skate_run",4.1,1,1,1,1,1,1);
			#else
			ApplyAnimation(playerid, "SKATE","skate_sprint",4.1,1,1,1,1,1,1);
			#endif
			if(!act)
			{
				act = true;
				RemovePlayerAttachedObject(playerid,INDEX_SKATE);
				DestroyObject(InfoSkate[playerid][sSkate]);
				InfoSkate[playerid][sSkate] = CreateObject(19878,0,0,0,0,0,0);
				AttachObjectToPlayer(InfoSkate[playerid][sSkate],playerid, -0.2,0,-0.9,0,0,90);
			}
		}
		if(oldkeys & KEY_YES)
		{
			ApplyAnimation(playerid, "CARRY","crry_prtial",4.0,0,0,0,0,0);
			if(act)
			{
				act = false;
				DestroyObject(InfoSkate[playerid][sSkate]);
				RemovePlayerAttachedObject(playerid,INDEX_SKATE);
				#if TYPE_SKATE == 0
				SetPlayerAttachedObject(playerid,INDEX_SKATE,19878,6,-0.055999,0.013000,0.000000,-84.099983,0.000000,-106.099998,1.000000,1.000000,1.000000);
				#else
				SetPlayerAttachedObject(playerid,INDEX_SKATE,19878,1,0.055999,-0.173999,-0.007000,-95.999893,-1.600010,24.099992,1.000000,1.000000,1.000000);
				#endif
			}
		}
	}
	if((newkeys & KEY_YES && pData[playerid][pInjured] == 1 && pData[playerid][pHospital] != 1))
	{
		if(Toggleaccdeath[playerid] == 0)
		{
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			SendFactionMessage(3, -1, "{FF0000}[EMERGENCY INJURED] {FFFF00}[ID:%d] {FFFFFF}%s calling the emergency medical! | Location: {FFFF00}%s", playerid, ReturnName(playerid), GetLocation(x, y, z));
			SendFactionMessage(3, -1, "{FFFFFF}Type {FFFF00}/getlocmd <ID> {FFFFFF}to know their location.");
			SuccesMsg(playerid, "Berhasil mengirim sinyal kepada Medic");
			Toggleaccdeath[playerid] = 1;
		}
		else if(Toggleaccdeath[playerid] == 1)
		{
			SyntaxMsg(playerid, "Saat ini medic sedang menuju ke tempat anda, silahkan tunggu");
		}
	}
	if((newkeys & KEY_FIRE && smokecig[playerid] == 6))
	{
		smokecig[playerid] = 0;
		pData[playerid][pEnergy] -= 10;
		Info(playerid, "Rokok anda sudah habis");
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && pData[playerid][pCuffed] == 0 && pData[playerid][pProgress] == 0)
		{
			TogglePlayerControllable(playerid, 1);
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			clearAnimations(playerid);
			StopLoopingAnim(playerid);
		}
	}
	if((newkeys & KEY_FIRE && smokecig[playerid] == 5))
	{
		pData[playerid][pStress] -= 5;
		smokecig[playerid] = 6;
		Info(playerid, "Kapasitas rokok 20 persen");
	}
	if((newkeys & KEY_FIRE && smokecig[playerid] == 4))
	{
		pData[playerid][pStress] -= 5;
		smokecig[playerid] = 5;
		Info(playerid, "Kapasitas rokok 40 persen");
	}
	if((newkeys & KEY_FIRE && smokecig[playerid] == 3))
	{
		pData[playerid][pStress] -= 5;
		smokecig[playerid] = 4;
		Info(playerid, "Kapasitas rokok 60 persen");
	}
	if((newkeys & KEY_FIRE && smokecig[playerid] == 2))
	{
		pData[playerid][pStress] -= 5;
		smokecig[playerid] = 3;
		Info(playerid, "Kapasitas rokok 80 persen");
	}
	if((newkeys & KEY_FIRE && smokecig[playerid] == 1))
	{
		pData[playerid][pStress] -= 5;
		smokecig[playerid] = 2;
	}
	//fsafe
	if((newkeys & KEY_YES && pData[playerid][pFamily] != -1))
	{
		new fid = pData[playerid][pFamily];
		if(IsPlayerInRangeOfPoint(playerid, 3.0, fData[fid][fSafeposX], fData[fid][fSafeposY], fData[fid][fSafeposZ]))
		{
			ShowPlayerDialog(playerid, FAMILY_SAFE, DIALOG_STYLE_LIST, "Family SAFE", "Storage\nMarijuana\nComponent\nMaterial\nMoney", "Select", "Cancel");
		}
		else
		{
			
		}
	}
	if((newkeys & KEY_YES))
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.0, 2769.373779, -1609.820434, 10.921875))
		{
			new mstr[200];
			format(mstr, sizeof(mstr), ""WHITE_E"Masukan jumlah material:\nMaterial Stock: "GREEN_E"%d\n"WHITE_E"Material Price"GREEN_E"%s / item", Material, FormatMoney(MaterialPrice));
			ShowPlayerDialog(playerid, DIALOG_MATERIAL, DIALOG_STYLE_INPUT, "Buy Material", mstr, "Buy", "Cancel");
		}
		if(IsPlayerInRangeOfPoint(playerid, 3.0, 2772.005615, -1617.289794, 10.921875))
		{
			new mstr[200];
			format(mstr, sizeof(mstr), ""WHITE_E"Masukan jumlah component:\nComponent Stock: "GREEN_E"%d\n"WHITE_E"Component Price"GREEN_E"%s / item", Component, FormatMoney(ComponentPrice));
			ShowPlayerDialog(playerid, DIALOG_COMPONENT, DIALOG_STYLE_INPUT, "Buy Component", mstr, "Buy", "Cancel");
		}
		if(IsPlayerInRangeOfPoint(playerid, 3.0, 2770.871582, -1604.076538, 10.921875))
		{
			new potato = pData[playerid][pPotato] * PotatoPrice,
			wheat = pData[playerid][pWheat] * WheatPrice,
			orange = pData[playerid][pOrange] * OrangePrice;
			
			new total = pData[playerid][pPotato] + pData[playerid][pWheat] + pData[playerid][pOrange];
			new pay = potato + wheat + orange;
			
			if(total < 1) return ErrorMsg(playerid, "Anda tidak memiliki tanaman");
			GivePlayerMoneyEx(playerid, pay);
			Food += total;
			Gandum += pData[playerid][pWheat];
			Server_MinMoney(pay);
			
			pData[playerid][pPotato] = 0;
			pData[playerid][pWheat] = 0;
			pData[playerid][pOrange] = 0;
			Info(playerid, "You selling "RED_E"%d kg "WHITE_E"all plant to "GREEN_E"%s", total, FormatMoney(pay));
		}
		if(IsPlayerInRangeOfPoint(playerid, 3.0, 2775.390869, -1604.076416, 10.921875))
		{
			if(Inventory_Count(playerid, "Material") < 1) return ErrorMsg(playerid, "Anda tidak memiliki Material");
			new jumlahmaterial = Inventory_Count(playerid, "Material"), price = jumlahmaterial*30;
			Inventory_Remove(playerid, "Material", jumlahmaterial);
			GivePlayerMoneyEx(playerid, price);
			Material += 10;
			new strings[150];
			format(strings, sizeof(strings), "Anda berhasil menjual %d material dengan harga %s", jumlahmaterial, FormatMoney(price));
			SuccesMsg(playerid, strings);
		}
		if(IsPlayerInRangeOfPoint(playerid, 5.0, 1068.6592,-304.6219, 73.9922))
		{
			new vehid2 = GetPlayerVehicleID(playerid);
			if(IsPlayerInRangeOfPoint(playerid, 5.0, 1068.6592,-304.6219, 73.9922))
			{
				if(pData[playerid][pRobbingTime] >= gettime()) return ErrorMsg(playerid, "Anda harus menunggu beberapa detik untuk melakukan car steal lagi");
				if(CountFaction(1) < 2) return ErrorMsg(playerid, "SAPD yang ada di kota minimal 2");
				if(CountFaction(3) < 1) return ErrorMsg(playerid, "SAMD yang ada di kota minimal 1");        
				if(pData[playerid][pLevel] < 3) return ErrorMsg(playerid, "Level anda belum mencukupi (3)");
				if(!IsPlayerInAnyVehicle(playerid)) return ErrorMsg(playerid, "Anda harus berada di dalam kendaraan");
				if(IsABusVeh(vehid2) && IsATrashVeh(vehid2) && IsASweeperVeh(vehid2) && IsDRIVESIMCar(vehid2) && pvData[vehid2][cRent] != 0)
					return ErrorMsg(playerid, "Kendaraan ini tidak dapat id curi");
				SetTimerEx("CarStealing", 80000, false, "i", playerid);
				ShowProgressbar(playerid, "Stealing...", 80);
				TogglePlayerControllable(playerid, 0);

				new Float:slx, Float:sly, Float:slz;
				GetPlayerPos(playerid, slx, sly, slz);
				SendFactionMessage(1, -1, "{FF0000}DISPATCH {FFFFFF}: Seseorang telah mencoba melakukan car stealing | Location: %s | ID: %d", GetLocation(slx, sly, slz), playerid);
				SendFactionMessage(1, -1, "Gunakan {FFFF00}'/getlocpd <playerid>'", GetLocation(slx, sly, slz));        
			}
		}
	}
	if((newkeys & KEY_YES))
	{
		if(IsPlayerInRangeOfPoint(playerid, 5.0, 1095.26, -1680.13, 15.03))
		{
			ShowPlayerDialog(playerid, DIALOG_SAPDMENU, DIALOG_STYLE_LIST, "VIP Locker", "Create Plate\nTruck Lisensi\nLumber Lisensi", "Okay", "Cancel");
		}
	}
	if((newkeys & KEY_YES))
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.0, 192.998992, -265.421997, 1.597936))
		{
			callcmd::createkit(playerid, "");
		}
	}
	if((newkeys & KEY_YES))
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, 586.45, -1820.44, 6.08))
		{
			if(!IsPlayerInRangeOfPoint(playerid, 3.5, 586.45, -1820.44, 6.08) && !IsPlayerInRangeOfPoint(playerid, 3.5, 1290.3080, 709.8832, 10.8462)) return ErrorMsg(playerid, "Anda harus berada di dapur SACF");
			if(pData[playerid][pFaction] != 5)
				return ErrorMsg(playerid, "Anda bukan bagian dari Pedagang");

			new Dstring[512];
			format(Dstring, sizeof(Dstring), "Jenis (Jumlah)\tBahan\n", Dstring);
			format(Dstring, sizeof(Dstring), "{ffffff}%sPizza (5)\tPotato 10\n", Dstring);
			format(Dstring, sizeof(Dstring), "{ffffff}%sJus Jeruk (5)\tOrange 5\n", Dstring);
			format(Dstring, sizeof(Dstring), "{ffffff}%sSteak(5)\tFood (5)\n", Dstring);
			format(Dstring, sizeof(Dstring), "{ffffff}%sRoti(5)\tWheat (5)\n", Dstring);
			format(Dstring, sizeof(Dstring), "{FFFFFF}%sNasi Goreng(5)\tWheat + Food (10)", Dstring);
			ShowPlayerDialog(playerid, DIALOG_MENUMASAK, DIALOG_STYLE_TABLIST_HEADERS, "Pedagang - Menu Masak", Dstring, "Pilih", "Batal");
		}
		if(IsPlayerInRangeOfPoint(playerid, 3.5, 1290.3080, 709.8832, 10.8462))
		{
			if(!IsPlayerInRangeOfPoint(playerid, 3.5, 586.45, -1820.44, 6.08) && !IsPlayerInRangeOfPoint(playerid, 3.5, 1290.3080, 709.8832, 10.8462)) return ErrorMsg(playerid, "Anda harus berada di dapur SACF");
			if(pData[playerid][pFaction] != 5)
				return ErrorMsg(playerid, "Anda bukan bagian dari Pedagang");

			new Dstring[512];
			format(Dstring, sizeof(Dstring), "Jenis (Jumlah)\tBahan\n", Dstring);
			format(Dstring, sizeof(Dstring), "{ffffff}%sPizza (5)\tPotato 10\n", Dstring);
			format(Dstring, sizeof(Dstring), "{ffffff}%sJus Jeruk (5)\tOrange 5\n", Dstring);
			format(Dstring, sizeof(Dstring), "{ffffff}%sSteak(5)\tFood (5)\n", Dstring);
			format(Dstring, sizeof(Dstring), "{ffffff}%sRoti(5)\tWheat (5)\n", Dstring);
			format(Dstring, sizeof(Dstring), "{FFFFFF}%sNasi Goreng(5)\tWheat + Food (10)", Dstring);
			ShowPlayerDialog(playerid, DIALOG_MENUMASAK, DIALOG_STYLE_TABLIST_HEADERS, "Pedagang - Menu Masak", Dstring, "Pilih", "Batal");
		}
	}
	if((newkeys & KEY_YES))
	{
		foreach(new pid : Pedagang)
		{
			if(IsPlayerInRangeOfPoint(playerid, 4.0, pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ]))
			{
				if(pData[playerid][pFaction] == 5)
				{
					ShowPedagangMenu(playerid, pid);
				}
			}
		}
	}
	if((newkeys & KEY_LOOK_BEHIND))
	{
		static
			carid = -1;

		if((carid = Vehicle_Nearest(playerid)) != -1)
		{
			if(Vehicle_IsOwner(playerid, carid))
			{
				if(!pvData[carid][cLocked])
				{
					pvData[carid][cLocked] = 1;
					GameTextForPlayer(playerid, "LOCKED", 1000, 3);
					PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
					SwitchVehicleDoors(pvData[carid][cVeh], true);
				}
				else
				{
					pvData[carid][cLocked] = 0;
					GameTextForPlayer(playerid, "UNLOCKED", 1000, 3);
					PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
					SwitchVehicleDoors(pvData[carid][cVeh], false);
				}
			}
		}
		else ErrorMsg(playerid, "Anda sedang tidak berada di dekat kendaraan apapun");
	}
	if((newkeys & KEY_SECONDARY_ATTACK))
    {
		foreach(new did : Doors)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.8, dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ]))
			{
				if(dData[did][dIntposX] == 0.0 && dData[did][dIntposY] == 0.0 && dData[did][dIntposZ] == 0.0)
					return ErrorMsg(playerid, "Interior rumah ini masih kosong");

				if(dData[did][dLocked])
					return ErrorMsg(playerid, "Rumah ini sedang terkunci");
					
				if(dData[did][dFaction] > 0)
				{
					if(dData[did][dFaction] != pData[playerid][pFaction])
						return ErrorMsg(playerid, "Pintu ini hanya untuk fraksi");
				}
				if(dData[did][dFamily] > 0)
				{
					if(dData[did][dFamily] != pData[playerid][pFamily])
						return ErrorMsg(playerid, "Pintu ini hanya untuk Family");
				}
				
				if(dData[did][dVip] > pData[playerid][pVip])
					return ErrorMsg(playerid, "Level VIP anda tidak mencukupi untuk memasuki pintu ini");
				
				if(dData[did][dAdmin] > pData[playerid][pAdmin])
					return ErrorMsg(playerid, "Admin level anda tidak cukup untuk memasuki pintu ini");
					
				if(strlen(dData[did][dPass]))
				{
					new params[256];
					if(sscanf(params, "s[256]", params)) return SyntaxMsg(playerid, "/enter [password]");
					if(strcmp(params, dData[did][dPass])) return ErrorMsg(playerid, "Pintu password yang anda masukan salah");
					
					if(dData[did][dCustom])
					{
						SetPlayerPositionEx(playerid, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
					}
					else
					{
						SetPlayerPosition(playerid, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
					}
					pData[playerid][pInDoor] = did;
					SetPlayerInterior(playerid, dData[did][dIntint]);
					SetPlayerVirtualWorld(playerid, dData[did][dIntvw]);
					SetCameraBehindPlayer(playerid);
					SetPlayerWeather(playerid, 0);
					TogglePlayerControllable(playerid, 0);
					SetTimerEx("TimerUntogglePlayer", 5000, 0, "d", playerid);
				}
				else
				{
					if(dData[did][dCustom])
					{
						SetPlayerPositionEx(playerid, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
					}
					else
					{
						SetPlayerPosition(playerid, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
					}
					pData[playerid][pInDoor] = did;
					SetPlayerInterior(playerid, dData[did][dIntint]);
					SetPlayerVirtualWorld(playerid, dData[did][dIntvw]);
					SetCameraBehindPlayer(playerid);
					SetPlayerWeather(playerid, 0);
					TogglePlayerControllable(playerid, 0);
					SetTimerEx("TimerUntogglePlayer", 5000, 0, "d", playerid);
				}
			}
			if(IsPlayerInRangeOfPoint(playerid, 2.8, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ]))
			{
				if(dData[did][dFaction] > 0)
				{
					if(dData[did][dFaction] != pData[playerid][pFaction])
						return ErrorMsg(playerid, "Pintu ini hanya untuk Faction");
				}
				
				if(dData[did][dCustom])
				{
					SetPlayerPositionEx(playerid, dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ], dData[did][dExtposA]);
				}
				else
				{
					SetPlayerPositionEx(playerid, dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ], dData[did][dExtposA]);
				}
				pData[playerid][pInDoor] = -1;
				SetPlayerInterior(playerid, dData[did][dExtint]);
				SetPlayerVirtualWorld(playerid, dData[did][dExtvw]);
				SetCameraBehindPlayer(playerid);
				SetPlayerWeather(playerid, WorldWeather);
			}
        }
		//Family
		foreach(new fid : FAMILYS)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.8, fData[fid][fExtposX], fData[fid][fExtposY], fData[fid][fExtposZ]))
			{
				if(fData[fid][fIntposX] == 0.0 && fData[fid][fIntposY] == 0.0 && fData[fid][fIntposZ] == 0.0)
					return ErrorMsg(playerid, "Pintu ini tidak memiliki Interior");

				if(pData[playerid][pFaction] == 0)
					if(pData[playerid][pFamily] == -1)
						return ErrorMsg(playerid, "Anda tidak memiliki akses untuk memasuki interior ini");
					
				SetPlayerPositionEx(playerid, fData[fid][fIntposX], fData[fid][fIntposY], fData[fid][fIntposZ], fData[fid][fIntposA]);

				SetPlayerInterior(playerid, fData[fid][fInt]);
				SetPlayerVirtualWorld(playerid, fid);
				SetCameraBehindPlayer(playerid);
				SetPlayerWeather(playerid, 0);
				SetTimerEx("TimerUntogglePlayer", 3000, 0, "d", playerid);
			}
			if(IsPlayerInRangeOfPoint(playerid, 2.8, fData[fid][fIntposX], fData[fid][fIntposY], fData[fid][fIntposZ]))
			{
				SetPlayerPositionEx(playerid, fData[fid][fExtposX], fData[fid][fExtposY], fData[fid][fExtposZ], fData[fid][fExtposA]);

				SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
				SetCameraBehindPlayer(playerid);
				SetPlayerWeather(playerid, WorldWeather);
			}
        }
	}
	if((newkeys & KEY_YES))
	{
		//Houses
		foreach(new hid : Houses)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]))
			{
				if(hData[hid][hIntposX] == 0.0 && hData[hid][hIntposY] == 0.0 && hData[hid][hIntposZ] == 0.0)
					return ErrorMsg(playerid, "Rumah ini tidak memiliki interior");

				if(hData[hid][hLocked] >= 2)
					return ErrorMsg(playerid, "Rumah yang anda masuki, di segel oleh pemerintah");

				if(hData[hid][hLocked])
					return ErrorMsg(playerid, "Rumah sedang di kunci");
				
				pData[playerid][pInHouse] = hid;
				SetPlayerPositionEx(playerid, hData[hid][hIntposX], hData[hid][hIntposY], hData[hid][hIntposZ], hData[hid][hIntposA]);

				SetPlayerInterior(playerid, hData[hid][hInt]);
				SetPlayerVirtualWorld(playerid, hid);
				SetCameraBehindPlayer(playerid);
				SetPlayerWeather(playerid, 0);
				SetTimerEx("TimerUntogglePlayer", 3000, 0, "d", playerid);
			}
        }
		new inhouseid = pData[playerid][pInHouse];
		if(pData[playerid][pInHouse] != -1 && IsPlayerInRangeOfPoint(playerid, 2.8, hData[inhouseid][hIntposX], hData[inhouseid][hIntposY], hData[inhouseid][hIntposZ]))
		{
			pData[playerid][pInHouse] = -1;
			SetPlayerPositionEx(playerid, hData[inhouseid][hExtposX], hData[inhouseid][hExtposY], hData[inhouseid][hExtposZ], hData[inhouseid][hExtposA]);
			
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			SetCameraBehindPlayer(playerid);
			SetPlayerWeather(playerid, WorldWeather);
		}
		//Buy House
		foreach(new hid : Houses)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]))
			{
				if(hData[hid][hPrice] > pData[playerid][pMoney]) return ErrorMsg(playerid, "Uang anda tidak mencukupi untuk membeli rumah ini");
				if(strcmp(hData[hid][hOwner], "-")) return ErrorMsg(playerid, "Seseorang sudah memiliki rumah ini");
				if(pData[playerid][pVip] == 1)
				{
					#if LIMIT_PER_PLAYER > 0
					if(Player_HouseCount(playerid) + 1 > 2) return ErrorMsg(playerid, "Anda tidak dapat membeli rumah lebih dari 2");
					#endif
				}
				else if(pData[playerid][pVip] == 2)
				{
					#if LIMIT_PER_PLAYER > 0
					if(Player_HouseCount(playerid) + 1 > 3) return ErrorMsg(playerid, "Anda tidak dapat membeli rumah lebih dari 3");
					#endif
				}
				else if(pData[playerid][pVip] == 3)
				{
					#if LIMIT_PER_PLAYER > 0
					if(Player_HouseCount(playerid) + 1 > 4) return ErrorMsg(playerid, "Anda tidak dapat membeli rumah lebih dari 4");
					#endif
				}
				else
				{
					#if LIMIT_PER_PLAYER > 0
					if(Player_HouseCount(playerid) + 1 > 1) return ErrorMsg(playerid, "Anda tidak dapat membeli rumah lebih dari 1");
					#endif
				}
				GivePlayerMoneyEx(playerid, -hData[hid][hPrice]);
				Server_AddMoney(hData[hid][hPrice]);
				format(hData[hid][hOwner], MAX_PLAYER_NAME, pData[playerid][pName]);
				hData[hid][hVisit] = gettime() + (86400 * 30);
				
				House_Refresh(hid);
				House_Save(hid);
			}
		}
	}
	//SAPD Taser/Tazer
	if(newkeys & KEY_FIRE && TaserData[playerid][TaserEnabled] && GetPlayerWeapon(playerid) == 0 && !IsPlayerInAnyVehicle(playerid) && TaserData[playerid][TaserCharged])
	{
  		TaserData[playerid][TaserCharged] = false;

	    new Float: x, Float: y, Float: z, Float: health;
     	GetPlayerPos(playerid, x, y, z);
	    PlayerPlaySound(playerid, 6003, 0.0, 0.0, 0.0);
	    ApplyAnimation(playerid, "KNIFE", "KNIFE_3", 4.1, 0, 1, 1, 0, 0, 1);
		pData[playerid][pActivityTime] = 0;
	    TaserData[playerid][ChargeTimer] = SetTimerEx("ChargeUp", 4000, false, "i", playerid);
	    ShowProgressbar(playerid, "Reloading...", 4);
	    
	    for(new i, maxp = GetPlayerPoolSize(); i <= maxp; ++i)
		{
	        if(!IsPlayerConnected(i)) continue;
          	if(playerid == i) continue;
          	if(TaserData[i][TaserCountdown] != 0) continue;
          	if(IsPlayerInAnyVehicle(i)) continue;
			if(GetPlayerDistanceFromPoint(i, x, y, z) > 2.0) continue;
			clearAnimations(i);
			TogglePlayerControllable(i, false);
   			ApplyAnimation(i, "CRACK", "crckdeth2", 4.1, 0, 0, 0, 1, 0, 1);
			PlayerPlaySound(i, 6003, 0.0, 0.0, 0.0);

			GetPlayerHealth(i, health);
			TaserData[i][TaserCountdown] = TASER_BASETIME + floatround((100 - health) / 12);
   			Info(i, "You got tased for %d secounds!", TaserData[i][TaserCountdown]);
			TaserData[i][GetupTimer] = SetTimerEx("TaserGetUp", 1000, true, "i", i);
			break;
	    }
	}
	//Vehicle
	if(GetPVarInt(playerid, "UsingSprunk"))
	{
		if(pData[playerid][pEnergy] >= 100 )
		{
  			SyntaxMsg(playerid, "Energy anda sudah mencapai Maximum");
	   	}
	   	else
	   	{
		    pData[playerid][pEnergy] += 5;
		}
	}
	if(PRESSED( KEY_FIRE ))
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
		{
			foreach(new did : Doors)
			{
				if(IsPlayerInRangeOfPoint(playerid, 2.8, dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ]))
				{
					if(dData[did][dGarage] == 1)
					{
						if(dData[did][dIntposX] == 0.0 && dData[did][dIntposY] == 0.0 && dData[did][dIntposZ] == 0.0)
							return ErrorMsg(playerid, "Interior pintu ini masih kosong");

						if(dData[did][dLocked])
							return ErrorMsg(playerid, "Interior pintu ini masih kosong");
							
						if(dData[did][dFaction] > 0)
						{
							if(dData[did][dFaction] != pData[playerid][pFaction])
								return ErrorMsg(playerid, "Pintu ini hanya untuk Faction");
						}
						if(dData[did][dFamily] > 0)
						{
							if(dData[did][dFamily] != pData[playerid][pFamily])
								return ErrorMsg(playerid, "Pintu ini hanya untuk family");
						}
						
						if(dData[did][dVip] > pData[playerid][pVip])
							return ErrorMsg(playerid, "VIP level anda tidak cukup untuk memasuki pintu ini");
						
						if(dData[did][dAdmin] > pData[playerid][pAdmin])
							return ErrorMsg(playerid, "Admin level anda tidak cukup untuk memasuki pintu ini");
							
						if(strlen(dData[did][dPass]))
						{
							new params[256];
							if(sscanf(params, "s[256]", params)) return SyntaxMsg(playerid, "/enter [password]");
							if(strcmp(params, dData[did][dPass])) return ErrorMsg(playerid, "Pintu password yang anda masukan salah");
							
							if(dData[did][dCustom])
							{
								SetVehiclePositionEx(playerid, GetPlayerVehicleID(playerid), dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
							}
							else
							{
								SetVehiclePosition(playerid, GetPlayerVehicleID(playerid), dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
							}
							pData[playerid][pInDoor] = did;
							SetPlayerInterior(playerid, dData[did][dIntint]);
							SetPlayerVirtualWorld(playerid, dData[did][dIntvw]);
							SetCameraBehindPlayer(playerid);
							SetPlayerWeather(playerid, 0);
							TogglePlayerControllable(playerid, 0);
							SetTimerEx("TimerUntogglePlayer", 10000, 0, "d", playerid);
						}
						else
						{
							if(dData[did][dCustom])
							{
								SetVehiclePositionEx(playerid, GetPlayerVehicleID(playerid), dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
							}
							else
							{
								SetVehiclePosition(playerid, GetPlayerVehicleID(playerid), dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
							}
							pData[playerid][pInDoor] = did;
							SetPlayerInterior(playerid, dData[did][dIntint]);
							SetPlayerVirtualWorld(playerid, dData[did][dIntvw]);
							SetCameraBehindPlayer(playerid);
							SetPlayerWeather(playerid, 0);
							TogglePlayerControllable(playerid, 0);
							SetTimerEx("TimerUntogglePlayer", 10000, 0, "d", playerid);
						}
					}
				}
				if(IsPlayerInRangeOfPoint(playerid, 2.8, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ]))
				{
					if(dData[did][dGarage] == 1)
					{
						if(dData[did][dFaction] > 0)
						{
							if(dData[did][dFaction] != pData[playerid][pFaction])
								return ErrorMsg(playerid, "Pintu ini hanya untuk Faction");
						}
					
						if(dData[did][dCustom])
						{
							SetVehiclePositionEx(playerid, GetPlayerVehicleID(playerid), dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ], dData[did][dExtposA]);
						}
						else
						{
							SetVehiclePosition(playerid, GetPlayerVehicleID(playerid), dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ], dData[did][dExtposA]);
						}
						pData[playerid][pInDoor] = -1;
						SetPlayerInterior(playerid, dData[did][dExtint]);
						SetPlayerVirtualWorld(playerid, dData[did][dExtvw]);
						SetCameraBehindPlayer(playerid);
						SetPlayerWeather(playerid, WorldWeather);
					}
				}
			}
		}
	}
	if((newkeys & KEY_NO))
	{
		if(finfo[playerid][f_player] == true) return ErrorMsg(playerid, "Wait for it, you have time fishing /refishing (to {FF0000}cancel{FFFFFF} fishing)");
		if(IsValidLoadingBar(playerid)) return ErrorMsg(playerid, "Kamu sedang berada di progress bar");
		if(IsValidBarQTE(playerid)) return ErrorMsg(playerid, "Kamu sedang berada di progress bar mini games");
		ShowRadial(playerid);
		PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
	}
	if(IsKeyJustDown(KEY_SECONDARY_ATTACK, newkeys, oldkeys))
	{
		if(GetPVarInt(playerid, "UsingSprunk"))
		{
			DeletePVar(playerid, "UsingSprunk");
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		}
	}
	if(PRESSED( KEY_CROUCH ))
    {
    	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    	{
    		new Float:x, Float:y, Float:z;
    		GetPlayerPos(playerid, x, y, z);
    		for(new ptid; ptid < 10; ptid++)
    		{
    			if(IsPointInDynamicArea(PaytollAreaid[ptid], x, y, z))
    			{
    				OpenPaytoll(playerid);
    			}
    		}
    	}
    }
    if(PRESSED(KEY_YES) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1332.23, 1562.28, 1113.30))
        {
        	new JOB[1000], String[1000];
			strcat(JOB, "Job Name\n");
			format(String, sizeof(String), "Lumber Jack\n"); // 3
			strcat(JOB, String);
			format(String, sizeof(String), "Trucker Biasa\n");// 4
			strcat(JOB, String);
			format(String, sizeof(String), "Penambang\n"); // 5
			strcat(JOB, String);
			format(String, sizeof(String), "Production\n"); // 6
			strcat(JOB, String);
			format(String, sizeof(String), "Farmer\n");// 7
			strcat(JOB, String);
			format(String, sizeof(String), "Trucker Hauling\n"); // 8
			strcat(JOB, String);
			/*format(String, sizeof(String), "Job Pizza\n"); // 9
			strcat(JOB, String);*/
			format(String, sizeof(String), "Tukang Ayam\n"); // 10
			strcat(JOB, String);
			format(String, sizeof(String), "Reflenish\n"); // 11
			strcat(JOB, String);
			format(String, sizeof(String), "Pemeras Susu\n"); // 12
			strcat(JOB, String);
			format(String, sizeof(String), "Penjahit\n"); // 13
			strcat(JOB, String);
			format(String, sizeof(String), "{FF0000}Keluar dari Pekerjaan\n"); // 13
			strcat(JOB, String);
			ShowPlayerDialog(playerid, DIALOG_DAFTAR_JOB1, DIALOG_STYLE_TABLIST_HEADERS,"JOB CENTER", JOB, "Select", "Cancel");
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 1424.269531, 1546.517578, 3010.832275))
        {
        	ShowPlayerDialog(playerid, DIALOG_BALKOT, DIALOG_STYLE_LIST, "Balai Kota", "Membuat ID Card\nMengubah Tanggal Lahir\nJual Rumah Pribadi\nJual Dealer Pribadi\nBayar Pajak", "Select", "Close");
        }
        else if(IsPlayerInRangeOfPoint(playerid, 3.5, -382.97, -1426.43, 26.31))
        {
        	if(IsPlayerInRangeOfPoint(playerid, 3.5, -382.97, -1426.43, 26.31))
			{
				new mstr[128];
				format(mstr, sizeof(mstr), "Product\n\
				Buy Food\n\
				Buy Seed\n\
				Buy Gandum\n\
				");
				ShowPlayerDialog(playerid, DIALOG_FOOD, DIALOG_STYLE_TABLIST_HEADERS, "Job Farmer", mstr, "Select", "Cancel");
			}
			else return ErrorMsg(playerid, "Kamu tidak di penjualan atau pembelian farmer");
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.5, 2779.750244, -1623.891723, 10.921875))
        {
			new mstr[64];
			format(mstr, sizeof(mstr), "Product Susu\n\
				Buy Susu\n\
				Sell Susu\n\
			");
			ShowPlayerDialog(playerid, DIALOG_MILK, DIALOG_STYLE_TABLIST_HEADERS, "Job Milk", mstr, "Select", "Cancel");
        }
        else if(IsPlayerInRangeOfPoint(playerid, 3.0, 1097.9308, -1765.0497, 13.3841))
        {
        	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 1097.9308, -1765.0497, 13.3841)) return Error(playerid, "Anda harus berada di showroom kendaraan LTRP!");
			{
				ShowPlayerDialog(playerid, DIALOG_BUY_VEHICLE, DIALOG_STYLE_LIST, "DEALER KENDARAAN - {EEFF00}LOCALPRIME", "BELI KENDARAAN\nRENTAL KENDARAAN", "Select", "Cancel");
			} 
        }
	}
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_WASTED && pData[playerid][pJail] < 1)
    {	
		if(pData[playerid][pInjured] == 0)
        {
            pData[playerid][pInjured] = 1;
            SetPlayerHealthEx(playerid, 99999);

            pData[playerid][pInt] = GetPlayerInterior(playerid);
            pData[playerid][pWorld] = GetPlayerVirtualWorld(playerid);

            GetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
            GetPlayerFacingAngle(playerid, pData[playerid][pPosA]);
        }
        else
        {
            pData[playerid][pHospital] = 1;
        }
	}
	//Spec Player
	new vehicleid = GetPlayerVehicleID(playerid);
	if(newstate == PLAYER_STATE_ONFOOT)
	{
		if(pData[playerid][playerSpectated] != 0)
		{
			foreach(new ii : Player)
			{
				if(pData[ii][pSpec] == playerid)
				{
					PlayerSpectatePlayer(ii, playerid);
					Servers(ii, ,"%s(%i) is now on foot.", pData[playerid][pName], playerid);
				}
			}
		}
	}
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
    	pData[playerid][pClikmap] = vehicleid;
		if(pData[playerid][pInjured] == 1)
        {
        	RemovePlayerFromVehicle(playerid);
            SetPlayerHealthEx(playerid, 100);
        }
		foreach (new ii : Player) if(pData[ii][pSpec] == playerid) 
		{
            PlayerSpectateVehicle(ii, GetPlayerVehicleID(playerid));
        }
	}
	if(oldstate == PLAYER_STATE_PASSENGER)
	{
		TextDrawHideForPlayer(playerid, DPvehfare);
	}
	if(oldstate == PLAYER_STATE_DRIVER)
    {	
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CARRY || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CUFFED)
            return RemovePlayerFromVehicle(playerid);/*RemoveFromVehicle(playerid);*/

		HideSpeed(playerid);
		if(pData[playerid][pTaxiDuty] == 1)
		{
			pData[playerid][pTaxiDuty] = 0;
			Servers(playerid, "You are no longer on taxi duty!");
		}
		if(pData[playerid][pFare] == 1)
		{
			KillTimer(pData[playerid][pFareTimer]);
			Info(playerid, "Anda telah menonaktifkan taxi fare pada total: {00FF00}%s", FormatMoney(pData[playerid][pTotalFare]));
			pData[playerid][pFare] = 0;
			pData[playerid][pTotalFare] = 0;
		}
	}
	else if(newstate == PLAYER_STATE_DRIVER)
    {
		foreach(new pv : PVehicles)
		{
			if(vehicleid == pvData[pv][cVeh])
			{
				if(IsABike(vehicleid) || GetVehicleModel(vehicleid) == 424)
				{
					if(pvData[pv][cLocked] == 1)
					{
						RemovePlayerFromVehicle(playerid);
						ErrorMsg(playerid, "Sepedah ini dikunci oleh pemilik kendaraan");
						return 1;
					}
				}
			}
		}
		if(IsABusVeh(vehicleid))
		{
			ShowPlayerDialog(playerid, DIALOG_BUS, DIALOG_STYLE_LIST, "Side Job - Bus", "Route Market St\nRoute El Corona St", "Start Job", "Close");
		}
		if(IsATrashVeh(vehicleid))
		{
			if(pData[playerid][pSideJob] != 5)
			{
				ShowPlayerDialog(playerid, DIALOG_TRASHMASTER, DIALOG_STYLE_MSGBOX, "Side Job - Trash Master", "Anda akan bekerja sebagai Trash Master?", "Start Job", "Close");
			}
		}
		if(IsASweeperVeh(vehicleid))
		{
			ShowPlayerDialog(playerid, DIALOG_SWEEPER, DIALOG_STYLE_TABLIST_HEADERS, "Sweeper", "Rute\tLokasi\tUpah\n#1\tMarket\t{00FF00}$250\n#2\tMulholland Intersection\t{00FF00}$500", "Pilih", "Batal");
		}
		if(IsDRIVESIMCar(vehicleid))
        {
            SetPlayerCheckpoint(playerid, getsimpoint1, 3.0);
            InfoMsg(playerid, "Ikuti Checkpoint yang telah di tandai");
        }
       	if(!IsEngineVehicle(vehicleid))
        {
            SwitchVehicleEngine(vehicleid, true);
        }
        if(!GetEngineStatus(vehicleid))
        {
			if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{	
				if(!IsEngineVehicle(vehicleid))
					return ErrorMsg(playerid, "Anda sedang tidak berada di dalam kendaraan");
				if(GetEngineStatus(vehicleid))
				{
					EngineStatus(playerid, vehicleid);
				}
				else
				{
					Action(playerid, "Mencoba menyalakan mesin kendaraan");
					SetPlayerChatBubble(playerid,"> Mencoba menyalakan mesin <",COLOR_PURPLE,30.0,10000);
					SetTimerEx("EngineStatus", 3000, false, "id", playerid, vehicleid);
				}
			}
			else return ErrorMsg(playerid, "Anda harus mengendarai kendaraan anda");
        }
        if(IsEngineVehicle(vehicleid) && pData[playerid][pDriveLic] <= 0)
        {
            SyntaxMsg(playerid, "Anda tidak memiliki SIM, berhati-hatilah.");
        }
		ShowSpeed(playerid);
		new Float:health;
        GetVehicleHealth(GetPlayerVehicleID(playerid), health);
        VehicleHealthSecurityData[GetPlayerVehicleID(playerid)] = health;
        VehicleHealthSecurity[GetPlayerVehicleID(playerid)] = true;
		
		if(pData[playerid][playerSpectated] != 0)
  		{
			foreach(new ii : Player)
			{
    			if(pData[ii][pSpec] == playerid)
			    {
        			PlayerSpectateVehicle(ii, vehicleid);
				    Servers(ii, "%s(%i) is now driving a %s(%d).", pData[playerid][pName], playerid, GetVehicleModelName(GetVehicleModel(vehicleid)), vehicleid);
				}
			}
		}
		SetPVarInt(playerid, "LastVehicleID", vehicleid);
	}
	return 1;
}

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	switch(weaponid){ case 0..18, 39..54: return 1;} //invalid weapons
	if(1 <= weaponid <= 46 && pData[playerid][pGuns][g_aWeaponSlots[weaponid]] == weaponid)
	{
		pData[playerid][pAmmo][g_aWeaponSlots[weaponid]]--;
		if(hittype == 1 && pData[hitid][pGetDamageID] == INVALID_PLAYER_ID)
		{
			pData[hitid][pGetDamageID] = playerid;
		}
		if(pData[playerid][pGuns][g_aWeaponSlots[weaponid]] != 0 && !pData[playerid][pAmmo][g_aWeaponSlots[weaponid]])
		{
			pData[playerid][pGuns][g_aWeaponSlots[weaponid]] = 0;
		}
	}
	else if (weaponid == 9 && pData[playerid][pGuns][g_aWeaponSlots[weaponid]] == weaponid)
	{
	    return 0;
	}
	return 1;
}

GivePlayerHealth(playerid,Float:Health)
{
	new Float:health; GetPlayerHealth(playerid,health);
	SetPlayerHealthEx(playerid,health+Health);
}

public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
	new Float: vehicleHealth, Float:health, playerVehicleId;
    playerVehicleId = GetPlayerVehicleID(playerid);
    GetPlayerHealth(playerid, health);
    GetVehicleHealth(playerVehicleId, vehicleHealth);
    new panels, doors, lights, tires;
    GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
    UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
    if(pData[playerid][pSeatBelt] == 0 || pData[playerid][pHelmetOn] == 0)
    {
    	if(EVF::GetVehicleSpeed(vehicleid) <= 20)
    	{
    		new asakit = RandomEx(0, 1);
    		new bsakit = RandomEx(0, 1);
    		new csakit = RandomEx(0, 1);
    		pData[playerid][pLFoot] -= csakit;
    		pData[playerid][pLHand] -= bsakit;
    		pData[playerid][pRFoot] -= csakit;
    		pData[playerid][pRHand] -= bsakit;
    		pData[playerid][pHead] -= asakit;
    		GivePlayerHealth(playerid, -1);
    		return 1;
    	}
    	if(EVF::GetVehicleSpeed(vehicleid) <= 50)
    	{
    		new asakit = RandomEx(0, 2);
    		new bsakit = RandomEx(0, 2);
    		new csakit = RandomEx(0, 2);
    		new dsakit = RandomEx(0, 2);
    		pData[playerid][pLFoot] -= dsakit;
    		pData[playerid][pLHand] -= bsakit;
    		pData[playerid][pRFoot] -= csakit;
    		pData[playerid][pRHand] -= dsakit;
    		pData[playerid][pHead] -= asakit;
    		GivePlayerHealth(playerid, -2);
    		return 1;
    	}
    	if(EVF::GetVehicleSpeed(vehicleid) <= 90)
    	{
    		new asakit = RandomEx(0, 3);
    		new bsakit = RandomEx(0, 3);
    		new csakit = RandomEx(0, 3);
    		new dsakit = RandomEx(0, 3);
    		pData[playerid][pLFoot] -= csakit;
    		pData[playerid][pLHand] -= csakit;
    		pData[playerid][pRFoot] -= dsakit;
    		pData[playerid][pRHand] -= bsakit;
    		pData[playerid][pHead] -= asakit;
    		GivePlayerHealth(playerid, -5);
    		return 1;
    	}
    	return 1;
    }
    if(pData[playerid][pSeatBelt] == 1 || pData[playerid][pHelmetOn] == 1)
    {
    	if(EVF::GetVehicleSpeed(vehicleid) <= 20)
    	{
    		new asakit = RandomEx(0, 1);
    		new bsakit = RandomEx(0, 1);
    		new csakit = RandomEx(0, 1);
    		pData[playerid][pLFoot] -= csakit;
    		pData[playerid][pLHand] -= bsakit;
    		pData[playerid][pRFoot] -= csakit;
    		pData[playerid][pRHand] -= bsakit;
    		pData[playerid][pHead] -= asakit;
    		GivePlayerHealth(playerid, -1);
    		return 1;
    	}
    	if(EVF::GetVehicleSpeed(vehicleid) <= 50)
    	{
    		new asakit = RandomEx(0, 1);
    		new bsakit = RandomEx(0, 1);
    		new csakit = RandomEx(0, 1);
    		new dsakit = RandomEx(0, 1);
    		pData[playerid][pLFoot] -= dsakit;
    		pData[playerid][pLHand] -= bsakit;
    		pData[playerid][pRFoot] -= csakit;
    		pData[playerid][pRHand] -= dsakit;
    		pData[playerid][pHead] -= asakit;
    		GivePlayerHealth(playerid, -1);
    		return 1;
    	}
    	if(EVF::GetVehicleSpeed(vehicleid) <= 90)
    	{
    		new asakit = RandomEx(0, 1);
    		new bsakit = RandomEx(0, 1);
    		new csakit = RandomEx(0, 1);
    		new dsakit = RandomEx(0, 1);
    		pData[playerid][pLFoot] -= csakit;
    		pData[playerid][pLHand] -= csakit;
    		pData[playerid][pRFoot] -= dsakit;
    		pData[playerid][pRHand] -= bsakit;
    		pData[playerid][pHead] -= asakit;
    		GivePlayerHealth(playerid, -3);
    		return 1;
    	}
    }
    return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
	if(IsAtEvent[playerid] == 0)
	{
		new sakit = RandomEx(1, 4);
		new asakit = RandomEx(1, 5);
		new bsakit = RandomEx(1, 7);
		new csakit = RandomEx(1, 4);
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 9)
		{
			pData[playerid][pHead] -= 20;
		}
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 3)
		{
			pData[playerid][pPerut] -= sakit;
		}
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 6)
		{
			pData[playerid][pRHand] -= bsakit;
		}
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 5)
		{
			pData[playerid][pLHand] -= asakit;
		}
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 8)
		{
			pData[playerid][pRFoot] -= csakit;
		}
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 7)
		{
			pData[playerid][pLFoot] -= bsakit;
		}

		CreateDamageLog(playerid, Float:amount, weaponid, bodypart);
	}
    return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	if(adminVehicle{vehicleid})
	{
		if(IsValidVehicle(vehicleid))
			DestroyVehicle(vehicleid);

		adminVehicle{vehicleid} = false;
	}
	if(IsATruckerVeh(vehicleid))
	{
		if(IsValidDynamicObject(TruckerVehObject[vehicleid]))
			DestroyDynamicObject(TruckerVehObject[vehicleid]);

		TruckerVehObject[vehicleid] = 0;
	}
	foreach(new fvid : FactionVeh)
	{
		if(Iter_Contains(FactionVeh, fvid))
		{
			if(vehicleid == fvData[fvid][fvVeh])
			{
                Delete3DTextLabel(fvData[fvid][fvLabel]);
               	fvData[fvid][fvLabel] = Text3D: -1;
               	
				if(IsValidVehicle(fvData[fvid][fvVeh]))
					DestroyVehicle(fvData[fvid][fvVeh]);
				
				fvData[fvid][fvVeh] = 0;
				fvData[fvid][fvFaction] = 0;

				Iter_Remove(FactionVeh, fvid);
			}
		}
	}
	foreach(new ii : PVehicles)
	{
		if(vehicleid == pvData[ii][cVeh])
		{
			if(pvData[ii][cInsu] > 0)
    		{
				//pvData[ii][cInsu]--;
				pvData[ii][cClaim] = 1;
				pvData[ii][cClaimTime] = gettime() + (1 * 60);
				foreach(new pid : Player) 
				{
					if(pvData[ii][cOwner] == pData[pid][pID])
	        		{
	            		Info(pid, "Kendaraan anda hancur, pergi ke asuransi untuk mengembalikan kendaraan {00FF00}'/myinsu'");
					}
					RemoveVehicleToys(pvData[ii][cVeh]);
					if(IsValidVehicle(pvData[ii][cVeh]))
						DestroyVehicle(pvData[ii][cVeh]);
					
					pvData[ii][cVeh] = 0;
				}
			}
			else
			{
				foreach(new pid : Player)
				{
					if(pvData[ii][cOwner] == pData[pid][pID])
	        		{
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "DELETE FROM vehicle WHERE id = '%d'", pvData[pid][cID]);
						mysql_tquery(g_SQL, query);
						
						MySQL_ResetVehicleToys(ii);
						if(IsValidVehicle(pvData[ii][cVeh]))
							DestroyVehicle(pvData[ii][cVeh]);

						pvData[ii][cVeh] = 0;
						
	            		Info(pid, "Kendaraan anda hancur dan tidak memiliki insuransi.");
						Iter_Remove(PVehicles, ii);
					}
				}
			}
		}
	}
	return 1;
}

public OnPlayerPause(playerid)
{
    PlayerAFK[playerid] = 1;
	return 1;
}

public OnPlayerResume(playerid, time)
{
	if(PlayerAFK[playerid] == 1)
	PlayerAFK[playerid] = 0;
	return 1;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
    if (result == -1)
    {
        ErrorMsg(playerid, "Unknown command, see '/help'");
        return 0;
    }
	printf("[CMD]: %s(%d) menggunakan CMD '%s' (%s)", ReturnName(playerid), playerid, cmd, params);
	SendDiscordMessage(1, sprintf("**%s(%d)** menggunakan CMD **__%s(%d)__**", ReturnName(playerid), playerid, cmd, params));
    return 1;
}
