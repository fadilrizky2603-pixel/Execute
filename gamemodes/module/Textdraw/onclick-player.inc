public OnClickDynamicPlayerTextDraw(playerid, PlayerText:textid)
{
	if(textid == SpawnMenu[playerid][0]) { //bandara
		switch(random(1)) {
			case 0: {
				pData[playerid][pPosX] = 1638.170410;
				pData[playerid][pPosY] = -2359.558349;
				pData[playerid][pPosZ] = 1020.330627;
				pData[playerid][pPosA] = 0.925984;
			}
			case 1: {
				pData[playerid][pPosX] = 1647.830322;
				pData[playerid][pPosY] = -2359.368408;
				pData[playerid][pPosZ] = 1020.330627;
				pData[playerid][pPosA] = 1.570473;
			}
		}
		HideSpawnMenu(playerid);
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerVirtualWorld(playerid, 0);
		TogglePlayerControllable(playerid, 1);
		StopAudioStreamForPlayer(playerid);
		SetPlayerSpawn(playerid);
		SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
		SpawnPlayer(playerid);
		
		Servers(playerid, "Hallo "LB_E"%s"WHITE_E"! Selamat datang di Kampung Indo Roleplay", ReturnName(playerid));
		Servers(playerid, "Berhasil memuat basis data karakter anda dalam "RED_E"%dms", GetPlayerPing(playerid));
		Servers(playerid, "Jangan lupa untuk ikuti aturan server!");
    }
	if(textid == SpawnMenu[playerid][1]) { //motel
		switch(random(7)) {
			case 0: {
				pData[playerid][pPosX] = 354.713836;
				pData[playerid][pPosY] = -1804.891357;
				pData[playerid][pPosZ] = 5.491479;
				pData[playerid][pPosA] = 12.947015;
			}
			case 1: {
				pData[playerid][pPosX] = 351.271911;
				pData[playerid][pPosY] = -1805.068969;
				pData[playerid][pPosZ] = 5.488469;
				pData[playerid][pPosA] = 0.664113;
			}
			case 2: {
				pData[playerid][pPosX] = 348.209136;
				pData[playerid][pPosY] = -1804.800048;
				pData[playerid][pPosZ] = 5.488334;
				pData[playerid][pPosA] = 8.998944;
			}
			case 3: {
				pData[playerid][pPosX] = 345.383056;
				pData[playerid][pPosY] = -1804.671997;
				pData[playerid][pPosZ] = 5.488209;
				pData[playerid][pPosA] = 5.706949;
			}
			case 4: {
				pData[playerid][pPosX] = 342.009063;
				pData[playerid][pPosY] = -1804.585205;
				pData[playerid][pPosZ] = 5.493349;
				pData[playerid][pPosA] = 11.848342;
			}
			case 5: {
				pData[playerid][pPosX] = 338.663055;
				pData[playerid][pPosY] = -1804.755859;
				pData[playerid][pPosZ] = 5.493201;
				pData[playerid][pPosA] = 21.426654;
			}
			case 6: {
				pData[playerid][pPosX] = 334.323211;
				pData[playerid][pPosY] = -1804.739379;
				pData[playerid][pPosZ] = 5.498299;
				pData[playerid][pPosA] = 11.775903;
			}
		}
		HideSpawnMenu(playerid);
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerVirtualWorld(playerid, 0);
		TogglePlayerControllable(playerid, 1);
		StopAudioStreamForPlayer(playerid);
		SetPlayerSpawn(playerid);
		SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
		SpawnPlayer(playerid);

		Servers(playerid, "Hallo "LB_E"%s"WHITE_E"! Selamat datang di Kampung Indo Roleplay", ReturnName(playerid));
		Servers(playerid, "Berhasil memuat basis data karakter anda dalam "RED_E"%dms", GetPlayerPing(playerid));
		Servers(playerid, "Jangan lupa untuk ikuti aturan server!");
    }
	if(textid == SpawnMenu[playerid][2]) { //carnaval

		pData[playerid][pPosX] = 369.016387;
		pData[playerid][pPosY] = -2067.411621;
		pData[playerid][pPosZ] = 1020.330627;
		pData[playerid][pPosA] = 0359.928680;
		HideSpawnMenu(playerid);
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerVirtualWorld(playerid, 0);
		TogglePlayerControllable(playerid, 1);
		StopAudioStreamForPlayer(playerid);
		SetPlayerSpawn(playerid);
		SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
		SpawnPlayer(playerid);
	
		Servers(playerid, "Hallo "LB_E"%s"WHITE_E"! Selamat datang di Kampung Indo Roleplay", ReturnName(playerid));
		Servers(playerid, "Berhasil memuat basis data karakter anda dalam "RED_E"%dms", GetPlayerPing(playerid));
		Servers(playerid, "Jangan lupa untuk ikuti aturan server!");
    }
	if(textid == SpawnMenu[playerid][3]) { //house
		new hid, count = GetOwnedHouses(playerid), string[200], string2[1000];
		string2 = "";
		if(GetOwnedHouses(playerid) == 0)
		{
			ErrorMsg(playerid, "Anda tidak memiliki rumah");
			return 1;
		}

		Loop(itt, (count + 1), 1)
		{
			if(itt == count)
			{
				format(string, sizeof(string), "{FFFFFF}%d.\t%s\n", itt, hData[hid][hAddress]);
				strcat(string2, string);
			}
		}

		ShowPlayerDialog(playerid, DIALOG_HOUSELIST, DIALOG_STYLE_LIST, "Pilih Rumah", string2, "Spawn", "Cancel");

    }
	if(textid == SpawnMenu[playerid][4]) { //faction

		if(pData[playerid][pFaction] == 1) { //sapd
			pData[playerid][pPosX] = 1118.314208;
			pData[playerid][pPosY] = -1667.613525;
			pData[playerid][pPosZ] = 15.039628;
			pData[playerid][pPosA] = 252.603317;
		}
		else if(pData[playerid][pFaction] == 2) { //gov
			pData[playerid][pPosX] = 1403.0681158;
			pData[playerid][pPosY] = 1523.833984;
			pData[playerid][pPosZ] = 3010.839843;
			pData[playerid][pPosA] = 3.488575;
		}
		else if(pData[playerid][pFaction] == 3) { //medic
			pData[playerid][pPosX] = -2171.087646;
			pData[playerid][pPosY] = 1932.368896;
			pData[playerid][pPosZ] = 1192.101806;
			pData[playerid][pPosA] = 354.864440;
		}
		else if(pData[playerid][pFaction] == 4) { //sanews
			pData[playerid][pPosX] = 1405.901855;
			pData[playerid][pPosY] = -6.619709;
			pData[playerid][pPosZ] = 1001.524291;
			pData[playerid][pPosA] = 178.163879;
		}
		else if(pData[playerid][pFaction] == 5) { //pedagang
			pData[playerid][pPosX] = 584.916259;
			pData[playerid][pPosY] = -1812.886230;
			pData[playerid][pPosZ] = 6.085509;
			pData[playerid][pPosA] = 174.519882;
		}
		else if(pData[playerid][pFaction] == 6) { //mecha
			pData[playerid][pPosX] = 207.665878;
			pData[playerid][pPosY] = -223.619079;
			pData[playerid][pPosZ] = 9.198939;
			pData[playerid][pPosA] = 197.968917;
		}
		else {
			ErrorMsg(playerid, "Anda tidak bergabung dalam faction manapun!");
		}
		HideSpawnMenu(playerid);
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerVirtualWorld(playerid, 0);
		TogglePlayerControllable(playerid, 1);
		StopAudioStreamForPlayer(playerid);
		SetPlayerSpawn(playerid);
		SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
		SpawnPlayer(playerid);

		Servers(playerid, "Hallo "LB_E"%s"WHITE_E"! Selamat datang di Kampung Indo Roleplay", ReturnName(playerid));
		Servers(playerid, "Berhasil memuat basis data karakter anda dalam "RED_E"%dms", GetPlayerPing(playerid));
		Servers(playerid, "Jangan lupa untuk ikuti aturan server!");
    }
	if(textid == SpawnMenu[playerid][5]) { //last exits
		SetPlayerInterior(playerid, pData[playerid][pInt]);
		SetPlayerVirtualWorld(playerid, pData[playerid][pWorld]);
		SetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
		SetPlayerFacingAngle(playerid, pData[playerid][pPosA]);
		SetCameraBehindPlayer(playerid);
		HideSpawnMenu(playerid);
		TogglePlayerControllable(playerid, 1);
		SetPlayerSpawn(playerid);
		SpawnPlayer(playerid);
		LoadAnims(playerid);
		pData[playerid][pPos][0] = pData[playerid][pPosX],
		pData[playerid][pPos][1] = pData[playerid][pPosY],
		pData[playerid][pPos][2] = pData[playerid][pPosZ];
		pData[playerid][pPos][3] = pData[playerid][pPosA];
		InterpolateCameraPos(playerid, pData[playerid][pPos][0]-2.5, pData[playerid][pPos][1],250.00,pData[playerid][pPos][0]-2.5, pData[playerid][pPos][1], pData[playerid][pPos][2]+2.5,2500,CAMERA_MOVE);
		InterpolateCameraLookAt(playerid, pData[playerid][pPos][0], pData[playerid][pPos][1], pData[playerid][pPos][2], pData[playerid][pPos][0], pData[playerid][pPos][1], pData[playerid][pPos][2], 2500, CAMERA_MOVE);

		Servers(playerid, "Hallo "LB_E"%s"WHITE_E"! Selamat datang di Kampung Indo Roleplay", ReturnName(playerid));
		Servers(playerid, "Berhasil memuat basis data karakter anda dalam "RED_E"%dms", GetPlayerPing(playerid));
		Servers(playerid, "Jangan lupa untuk ikuti aturan server!");

    }
	if(textid == GarasiTD[playerid][24]) //mobil 1
	{
		SelectGarasi[playerid] = 1;

		new vehid = ReturnPVehParkID(playerid, SelectGarasi[playerid]);

		new string[256], vehName[32];
		format(vehName, sizeof(vehName), GetVehicleModelName(pvData[vehid][cModel]));

		new Float:vehHealth;
		GetVehicleHealth(vehid, vehHealth);
		format(string, sizeof(string), "Models: %s\nHealth: %.0f%%", vehName, vehHealth / 10.0);

		PlayerTextDrawSetString(playerid, GarasiTD[playerid][72], string);
		for(new i = 56; i < 73; i++)
		{
			PlayerTextDrawShow(playerid, GarasiTD[playerid][i]);
		}
	}
	if(textid == GarasiTD[playerid][25]) // mobil 2
	{
		SelectGarasi[playerid] = 2;

		new vehid = ReturnPVehParkID(playerid, SelectGarasi[playerid]);

		new string[256], vehName[32];
		format(vehName, sizeof(vehName), GetVehicleModelName(pvData[vehid][cModel]));

		new Float:vehHealth;
		GetVehicleHealth(vehid, vehHealth);
		format(string, sizeof(string), "Models: %s\nHealth: %.0f%%", vehName, vehHealth);

		PlayerTextDrawSetString(playerid, GarasiTD[playerid][72], string);
		for(new i = 56; i < 73; i++)
		{
			PlayerTextDrawShow(playerid, GarasiTD[playerid][i]);
		}
		
	}
	if(textid == GarasiTD[playerid][26]) // mobil 3
	{
		SelectGarasi[playerid] = 3;

		new vehid = ReturnPVehParkID(playerid, SelectGarasi[playerid]);

		new string[256], vehName[32];
		format(vehName, sizeof(vehName), GetVehicleModelName(pvData[vehid][cModel]));

		new Float:vehHealth;
		GetVehicleHealth(vehid, vehHealth);
		format(string, sizeof(string), "Models: %s\nHealth: %.0f%%", vehName, vehHealth);

		PlayerTextDrawSetString(playerid, GarasiTD[playerid][72], string);
		for(new i = 56; i < 73; i++)
		{
			PlayerTextDrawShow(playerid, GarasiTD[playerid][i]);
		}
	}
	if(textid == GarasiTD[playerid][27]) // mobil 4
	{
		SelectGarasi[playerid] = 4;

		new vehid = ReturnPVehParkID(playerid, SelectGarasi[playerid]);

		new string[256], vehName[32];
		format(vehName, sizeof(vehName), GetVehicleModelName(pvData[vehid][cModel]));

		new Float:vehHealth;
		GetVehicleHealth(vehid, vehHealth);
		format(string, sizeof(string), "Models: %s\nHealth: %.0f%%", vehName, vehHealth);

		PlayerTextDrawSetString(playerid, GarasiTD[playerid][72], string);
		for(new i = 56; i < 73; i++)
		{
			PlayerTextDrawShow(playerid, GarasiTD[playerid][i]);
		}
	}

	if(textid == GarasiTD[playerid][22]) //exit
	{
		ShowGarasiTD(playerid, false);
		CancelSelectTextDraw(playerid);
	}
	if(textid == GarasiTD[playerid][68]) //takeout
	{
		new i = ReturnPVehParkID(playerid, SelectGarasi[playerid]);
		new gkid = pData[playerid][pGetPARKID];
		new str[200];

		pvData[i][cParkid] = -1;
		pvData[i][cPosX] = gkData[gkid][sgkX];
		pvData[i][cPosY] = gkData[gkid][sgkY];
		pvData[i][cPosZ] = gkData[gkid][sgkZ];
		pvData[i][cPosA] = gkData[gkid][sgkA];

		
		PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
		OnPlayerVehicleRespawn(i);
		SetPlayerArmedWeapon(playerid, 0);
		AttachVehicleToys(pvData[i][cVeh]);
		PutPlayerInVehicle(playerid, pvData[i][cVeh], 0);
		
		/*
		SetValidVehicleHealth(pvData[i][cVeh], 2500);
		SetVehiclePos(pvData[i][cVeh], pvData[i][cPosX], pvData[i][cPosY], pvData[i][cPosZ] + 3.0);
		SetVehicleZAngle(pvData[i][cVeh], pvData[i][cPosA]);
		SetVehicleFuel(pvData[i][cVeh], 1000);
		*/
		format(str, sizeof(str), "SELECT * FROM `carstorage` WHERE `ID` = '%d'", pvData[i][cID]);
		mysql_tquery(g_SQL, str, "OnLoadCarStorage", "d", i);

		InfoMsg(playerid, "Your succesfully spawn your vehicle");
		format(str, sizeof(str), "SELECT * FROM `carstorage` WHERE `ID` = '%d'", pvData[i][cID]);
		mysql_tquery(g_SQL, str, "OnLoadCarStorage", "d", i);
		ShowGarasiTD(playerid, false);
		CancelSelectTextDraw(playerid);
	}
	if(textid == Stream_TD[playerid][6])
    {
         SendClientMessage(playerid, -1, "You have successfully exited live!");
         PlayerTextDrawHide(playerid, Stream_TD[playerid][0]);
         PlayerTextDrawHide(playerid, Stream_TD[playerid][1]);
   	     PlayerTextDrawHide(playerid, Stream_TD[playerid][2]);
   	     PlayerTextDrawHide(playerid, Stream_TD[playerid][3]);
   	     PlayerTextDrawHide(playerid, Stream_TD[playerid][4]);
   	     PlayerTextDrawHide(playerid, Stream_TD[playerid][5]);
   	     PlayerTextDrawHide(playerid, Stream_TD[playerid][6]);
         CancelSelectTextDraw(playerid);
         StopPlayerWatchingCamera(playerid);
         return 1;
    }
	if(textid == CharacterNote[playerid][Note::p_td][14]) {
        if(CharacterNote[playerid][ReadMode]) {
            CharacterNote[playerid][ReadMode] = false;    
            ShowPlayerNote(playerid, false);
        } else {
            ShowPlayerNote(playerid, false);
            ApplyAnimation(playerid, "GRENADE", "WEAPON_throwu", 4.1, 0, 0, 0, 0, 0, 1);
            new Float:x,
                Float:y,
                Float:z;
            GetPlayerPos(playerid, x, y, z);
            PlayerDropNote(pData[playerid][pName], CharacterNote[playerid][Text], x, y, z, GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
        }
    }
    if(textid == CharacterNote[playerid][Note::p_td][17]) {
        if(CharacterNote[playerid][ReadMode]) return 0;
        Dialog_Show(playerid, DialogNoteCreate, DIALOG_STYLE_INPUT, "Kampung Indo - Note", "{FFFFFF}Please enter the text you want to create", "Submit", "Cancel");
        // CancelSelectTextDraw(playerid);
        // CharacterNote[playerid][Exists] = false;
    }
	if(textid == RadialMenuHytam[playerid][4])// Panel Buka Smartphone
	{   
		HideRadial(playerid);
        callcmd::h(playerid, "");
	}
	if(textid == RadialMenuHytam[playerid][1])// Panel Kendaraan89 
	{
		HideRadial(playerid);
		ShowPlayerDialog(playerid, DIALOG_KENDARAAN, DIALOG_STYLE_LIST, "Vehicle Menu","Engine\nLight\nHood\nTrunk\nLock\nNeon\nMasukkan ke dalam bagasi", "Select", "Cancel");
	}
	if(textid == RadialMenuHytam[playerid][2])// Panel Dokumen
	{

		HideRadial(playerid);
		DisplayDokumen(playerid);

	}
	if(textid == RadialMenuHytam[playerid][6])// Panel Pakaian
	{
		callcmd::toys(playerid, "");
		HideRadial(playerid);
	}
	if(textid == RadialMenuHytam[playerid][3])// Panel Inventory
	{
		HideRadial(playerid);
		CreatePlayerInventoryTD(playerid);
		InfoMsg(playerid, "Jika TextDraw Tidak Bisa Di Klik /cursor");
		SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "{FFFFFF}ACTION : {D0AEEB}%s membuka tas", ReturnName(playerid));
	}
	if(textid == RadialMenuHytam[playerid][0])// Close Panel
	{
		HideRadial(playerid);
	}
	if(textid == RadialMenuHytam[playerid][7])// Emote panel
	{
		HideRadial(playerid);
		callcmd::emotemenu(playerid, "");
	}
	if(textid == RadialMenuHytam[playerid][5])// Action panel
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		if(pData[playerid][pFamily] != -1)
		{
			foreach(new ii : Player) if(IsPlayerConnected(ii) && IsPlayerInRangeOfPoint(ii, 3.0, x, y, z))
			{
				ShowPlayerDialog(playerid, DIALOG_FMENU, DIALOG_STYLE_LIST, "Family Menu" , "Menggeledah\nMengikat Seseorang\nMembuka Ikatan\nMemasukan paksa (Kendaraan)\nMengeluarkan Paksa (Kendaraan)\nGendong Paksa\nMelepaskan Gendongan" , "Select" , "Cancel");
			}
		}
		if(pData[playerid][pFaction] == 1)
		{
			foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 2) && i != playerid)
			{
				ShowPlayerDialog(playerid, DIALOG_PDMENU, DIALOG_STYLE_LIST, "Police Menu" , "Menggeledah\nMemborgol Seseorang\nMembuka Borgol\nMemasukan paksa (Kendaraan)\nMengeluarkan Paksa (Kendaraan)\nGendong Paksa\nMelepaskan Gendongan" , "Select" , "Cancel");
			}
		}
		if(pData[playerid][pFaction] == 3)
		{
			foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 2) && i != playerid)
			{
				ShowPlayerDialog(playerid, DIALOG_EMSMENU, DIALOG_STYLE_LIST, "Medic Menu" , "Memasukan paksa (Kendaraan)\nMengeluarkan paksa (Kendaraan)\nGendong Paksa\nMelepaskan Gendongan" , "Select" , "Cancel");
			}
		}
		if(pData[playerid][pFaction] == 6)
		{
			if(pData[playerid][pMechVeh] == INVALID_VEHICLE_ID)
			{
				new vehicleid = GetNearestVehicleToPlayer(playerid, 3.5, false);
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(vehicleid == INVALID_VEHICLE_ID) return Error(playerid, "Anda tidak berada di dekat kendaraan mana pun.");
				if(pData[playerid][pActivityTime] > 5) return Error(playerid, "Anda sudah memeriksa kendaraan!");
				
				Info(playerid, "Jangan beranjak dari posisi Anda atau Anda akan gagal memeriksa kendaraan ini!");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				pData[playerid][pMechanic] = SetTimerEx("CheckCar", 10000, false, "dd", playerid, vehicleid);
				ShowProgressbar(playerid, "Examining...", 10);
				return 1;
			}
			
			if(GetNearestVehicleToPlayer(playerid, 3.5, false) == pData[playerid][pMechVeh])
			{
				new Dstring[800], Float:health, engine;
				new panels, doors, light, tires, body;
				GetVehicleHealth(pData[playerid][pMechVeh], health);
				if(health > 100.0) health = 100.0;
				if(health > 0.0) health *= -1;
				engine = floatround(health, floatround_round) / 10 + 100;
				
				GetVehicleDamageStatus(pData[playerid][pMechVeh], panels, doors, light, tires);
				new cpanels = panels / 1000000;
				new lights = light / 2;
				new pintu;
				if(doors != 0) pintu = 5;
				if(doors == 0) pintu = 0;
				body = cpanels + lights + pintu + 20;

				format(Dstring, sizeof(Dstring), "Service Name\tComponent\n");
				format(Dstring, sizeof(Dstring), "%sEngine Fix\t%d\n", Dstring, engine);
				format(Dstring, sizeof(Dstring), "%sBody Fix\t%d\n", Dstring, body);
				format(Dstring, sizeof(Dstring), "%sSpray Car\t12\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sPaint Job Car\t30\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sWheels Car\t25\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sSpoiler Car\t21\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sHood Car\t21\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sVents Car\t21\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sLights Car\t21\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sExhausts\t24\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sFront bumpers\t30\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sRear Bumpers\t30\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sRoofs Car\t21\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sSide skirts\t27\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sBullbars\t15\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sStereo\t45\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sHydraulics\t45\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sNitro 1\t75\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sNitro 2\t112\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sNitro 3\t150\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sNeon\t135", Dstring);
				ShowPlayerDialog(playerid, DIALOG_SERVICE, DIALOG_STYLE_TABLIST_HEADERS, "Mech Service", Dstring, "Service", "Cancel");
			}
			else
			{
				KillTimer(pData[playerid][pMechanic]);
				pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
				pData[playerid][pActivityTime] = 0;
				Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
				return 1;
			}
		}
	}
	if(textid == emoteList[playerid][29]) {
        // TODO: Next page anim
        if (animPage[playerid] < 20) {
            animPage[playerid]++;
            SyncAnimPage(playerid);
            new animDetailStr[128];
            for (new i = 0; i < 10; i++) {
                new index = (animPage[playerid] * 10) + i - 10;
                if (index < 0 || index >= sizeof(Anim::g_AnimDetails)) continue;
                format(animDetailStr, sizeof(animDetailStr), "%s", Anim::g_AnimDetails[index][Anim::e_AnimationName]);
                PlayerTextDrawSetString(playerid, emoteList[playerid][19 + i], animDetailStr);
                PlayerTextDrawShow(playerid, emoteList[playerid][19 + i]);
                PlayerPlaySound(playerid, 1039, 0.0, 0.0, 0.0);     
            }
        }
    }
    if(textid == emoteList[playerid][30]) {
        // TODO: Prev page anim
        if (animPage[playerid] > 1) {
            animPage[playerid]--;
            SyncAnimPage(playerid);
            new animDetailStr[128];
            for (new i = 0; i < 10; i++) {
                new index = (animPage[playerid] * 10) + i - 10;
                if (index < 0 || index >= sizeof(Anim::g_AnimDetails)) continue;
                format(animDetailStr, sizeof(animDetailStr), "%s", Anim::g_AnimDetails[index][Anim::e_AnimationName]);
                PlayerTextDrawSetString(playerid, emoteList[playerid][19 + i], animDetailStr);
                PlayerTextDrawShow(playerid, emoteList[playerid][19 + i]);
            }
        }
        PlayerPlaySound(playerid, 1039, 0.0, 0.0, 0.0);     
    }
    if(textid == emoteList[playerid][34]) { // Close Animation Page
        forex(i, 35) {
            PlayerTextDrawHide(playerid, emoteList[playerid][i]);
        }
        animPage[playerid] = 1;
        CancelSelectTextDraw(playerid);
    }
    for(new i = 0; i < 10; i++) {
        if(textid == emoteList[playerid][i + 8]) {
            new ePage = i + ((animPage[playerid]-1) * 10);
            ApplyAnimation(playerid, Anim::g_AnimDetails[ePage][Anim::e_AnimLib], Anim::g_AnimDetails[ePage][Anim::e_AnimName], Anim::g_AnimDetails[ePage][Anim::e_AnimDelta], Anim::g_AnimDetails[ePage][Anim::e_AnimLoop], Anim::g_AnimDetails[ePage][Anim::e_AnimLX], Anim::g_AnimDetails[ePage][Anim::e_AnimLY], Anim::g_AnimDetails[ePage][Anim::e_AnimFreeze], Anim::g_AnimDetails[ePage][Anim::e_AnimTime]);
            return 1;
        }
    }
	for(new i = 0; i<MAX_REMEMBERS; i++) if(textid == RobTD[playerid][i])
	{
		if(RememberData[playerid][i][remindersMustClicked])
		{
			PlayerPlaySound(playerid, 21001, 0,0,0);
			PlayerTextDrawColor(playerid, RobTD[playerid][i], SERVER_TEXTDRAW_COLOR);
			PlayerTextDrawShow(playerid, RobTD[playerid][i]);
			RobCount[playerid]++;
			if(RobCount[playerid] >= 5) RobWarung_Succes(playerid);
		}
		else RobValue[playerid] -= 1.0;
	}
	static oldID = -1; // Pindahkan deklarasi oldID ke luar loop
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
		if (modelinv[playerid][i] != PlayerText:-1)
		{
			if (textid == indexinv[playerid][i])
			{
				if (InventoryData[playerid][i][invExists])
				{
					MenuStore_UnselectRow(playerid);
					MenuStore_SelectRow(playerid, i);
					PlayerPlaySound(playerid, 43000, 0,0,0);
					oldID = i;
				}
				else if (!InventoryData[playerid][i][invExists])
				{
					if (oldID != -1)
					{
						InventoryData[playerid][i][invExists] = InventoryData[playerid][oldID][invExists];
						InventoryData[playerid][i][invModel] = InventoryData[playerid][oldID][invModel];
						InventoryData[playerid][i][invQuantity] = InventoryData[playerid][oldID][invQuantity];
						format(InventoryData[playerid][i][invItem], 32, "%s", InventoryData[playerid][oldID][invItem]);

						InventoryData[playerid][oldID][invExists] = false;
						InventoryData[playerid][oldID][invModel] = 0;
						InventoryData[playerid][oldID][invQuantity] = 0;
						format(InventoryData[playerid][oldID][invItem], 32, "");

						PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][i], InventoryData[playerid][i][invModel]);
						PlayerTextDrawSetString(playerid, itemname[playerid][i], InventoryData[playerid][i][invItem]);
						PlayerTextDrawSetString(playerid, itemamountname[playerid][i], "%dx", InventoryData[playerid][i][invQuantity]);

						PlayerTextDrawShow(playerid, modelinv[playerid][i]);
						PlayerTextDrawShow(playerid, itemname[playerid][i]);
						PlayerTextDrawShow(playerid, itemamountname[playerid][i]);

						PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][oldID], InventoryData[playerid][oldID][invModel]);
						PlayerTextDrawSetString(playerid, itemname[playerid][oldID], InventoryData[playerid][oldID][invItem]);
						PlayerTextDrawSetString(playerid, itemamountname[playerid][oldID],  "%dx", InventoryData[playerid][oldID][invQuantity]);

						PlayerTextDrawHide(playerid, modelinv[playerid][oldID]);
						PlayerTextDrawHide(playerid, itemname[playerid][oldID]);
						PlayerTextDrawHide(playerid, itemamountname[playerid][oldID]);
						
						oldID = -1;
						MenuStore_UnselectRow(playerid);
					}
				}
			}
		}
	}
	/*for(new i = 0; i < MAX_INVENTORY; i++) 
	{

		if(textid == indexinv[playerid][i])
		{
			SelectInventory[playerid] = i;
		}
	}*/
	if(textid == txd_inventory[playerid][14])
	{
		new id = SelectInventory[playerid];

		if(id == -1)
		{
			ErrorMsg(playerid,"Slot tersebut tidak memiliki Items");
		}
		else
		{
			new string[64];
			strunpack(string, InventoryData[playerid][id][invItem]);

			if(!Inventory_HasItem(playerid, string))
			{
				ErrorMsg(playerid,"Anda tidak memiliki Items tersebut");
				CreatePlayerInventoryTD(playerid);
			}
			else
			{
				CallLocalFunction("OnPlayerUseInvItem", "dds", playerid, id, string);
			}
		}
	}
	if(textid == txd_inventory[playerid][15]) // Berikan
    {
        new
            itemid = SelectInventory[playerid],
            string[64];

        strunpack(string, InventoryData[playerid][itemid][invItem]);
        SelectInventory[playerid] = itemid;

        new Float:x,
            Float:y,
            Float:z,
            nearhim[855],
            count;

        GetPlayerPos(playerid, x, y, z);

        foreach(new i : Player) if(pData[i][pSpawned] && i != playerid && IsPlayerInRangeOfPoint(i, 2.0, x, y, z)) {
            if(count % 2 == 0) strcat(nearhim, sprintf(""WHITE"Kantong - "YELLOW"%s (%d)\n", ReturnName(i), i));
            else strcat(nearhim, sprintf(""GREY"Kantong - "YELLOW"%s (%d)\n", ReturnName(i), i));
            count ++;
        }
        if(count > 0) Dialog_Show(playerid, INVENTORY_ID, DIALOG_STYLE_LIST, ""YELLOW""SERVER_NAME""WHITE" - Inventory ID", sprintf("%s", nearhim), "Pilih", "Batal");
            else ErrorMsg(playerid, "Tidak ada orang di sekitar mu");
    }
	if(textid == txd_inventory[playerid][13])
	{
		if(SelectInventory[playerid] == -1) return ErrorMsg(playerid, "Anda harus memilih items yang ingin di gunakan");
		ShowPlayerDialog(playerid, INVENTORY_AMOUNT, DIALOG_STYLE_INPUT, "Ammount:", "Silahkan Masukkan Jumlah Yang Ingin Anda\nBerikan, Gunakan Atau Drop:", "Input", "Close");
	}
	if(textid == txd_inventory[playerid][17]) //close inv
	{
		HideBackPackDialog(playerid);
		SelectInventory[playerid] = -1;
		AmmountInventory[playerid] = -1;
		InventoryOpen[playerid] = false;
	}
	if(textid == txd_inventory[playerid][16])
	{
		new id = SelectInventory[playerid];
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], InventoryData[playerid][id][invItem], true)) {
            if(g_aInventoryItems[i][e_InventoryDrop] == false) return ErrorMsg(playerid, "Anda tidak dapat menjatuhkan item ini");
        }
			//Drop Item
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		DropItem(InventoryData[playerid][id][invItem], playerid, InventoryData[playerid][id][invModel], AmmountInventory[playerid], x, y, z-1, GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
		ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,0,0,0,0,0);
		HideBackPackDialog(playerid);
		Info(playerid, "Gunakan {FFFF00}'/pickup' {FFFFFF}untuk mengambil barang yang di jatuhkan");
	}
	if(textid == DiaTelpon[playerid][27]) //accept
	{
		callcmd::p(playerid, "");
	}
	if(textid == GwTelpon[playerid][25])
	{
		callcmd::hu(playerid, "");
	}
	if(textid == DiaTelpon[playerid][25])
	{
		callcmd::hu(playerid, "");
	}
	if(textid == AtmPakCik[playerid][51])
	{
		ShowPlayerDialog(playerid, DIALOG_BANKREKENING, DIALOG_STYLE_INPUT, "ATM - Transfer", "Mohon masukan jumlah uang yang ingin di transfer:", "Input", "Batal");
	}
	if(textid == AtmPakCik[playerid][50])
	{
		ShowPlayerDialog(playerid, DIALOG_BANKWITHDRAW, DIALOG_STYLE_INPUT, "ATM - Withdraw", "Mohon masukan jumlah uang yang ingin di withdraw:", "Input", "Cancel");
	}
	if(textid == AtmPakCik[playerid][49])
	{
		ShowPlayerDialog(playerid, DIALOG_BANKDEPOSIT, DIALOG_STYLE_INPUT, "ATM - Deposit", "Mohon masukan jumlah uang yang ingin di depo:", "Input", "Cancel");
	}
	if(textid == AtmPakCik[playerid][11])
	{
		CancelSelectTextDraw(playerid);
		for(new i = 0; i < 55; i++)
		{
			PlayerTextDrawHide(playerid, AtmPakCik[playerid][i]);
		}
		ShowHunger(playerid);
		ShowLogo(playerid);
	}
	return 1;
}
