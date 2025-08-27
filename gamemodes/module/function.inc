function LoadUcpAccount(playerid, race_check)
{
	new rows = cache_num_rows(), query[254], PlayerIP[16];
	
	if (race_check != g_MysqlRaceCheck[playerid])
		return KickEx(playerid);

	if(rows)
	{
		new discordid[30];
		cache_get_value_name_int(0, "reg_id", pData[playerid][pUcpID]);
		cache_get_value_name_int(0, "register", pData[playerid][pUcpRegister]);
		cache_get_value_name_int(0, "pin_code", pData[playerid][pUcpPin]);
		cache_get_value_name(0, "discordid", discordid);
		format(pData[playerid][pDiscordID], 30, "%s", discordid);

		InterpolateCameraPos(playerid, -1274.089843, -2561.346435, 64.243041, -1171.794189, -2693.083984, 61.785053, 10000, 1);
		InterpolateCameraLookAt(playerid, -1272.289184, -2564.918212, 64.229293, -1170.353271, -2696.815185, 61.749427, 10000, 1);
		if(GeStatustUcpLogin(playerid) != 0)
		{
			Error(playerid, "Akun UCP sedang di gunakan, silahkan coba lagi nanti");
			KickEx(playerid);
			return 1;
		}
		if(pData[playerid][pUcpRegister] != 0)
		{
			new lstring[512];
			format(lstring, sizeof(lstring), "{FFFFFF}Selamat datang di {FFD700}Kampung Indo Roleplay\n{FFFFFF}anda dapat melakukan login dengan UCP ini!\nNama UCP: {FFFF00}%s{00FF00}\n{00FF00}Kesempatan Login (%d/3){FFFFFF}\n(Input password anda di bawah ini untuk melakukan login)", pData[playerid][pName], pData[playerid][pAttemps]);
			ShowPlayerDialog(playerid, UCP_LOGIN, DIALOG_STYLE_PASSWORD, "Account Login", lstring, "Login", "Abort");
			pData[playerid][LoginTimer] = SetTimerEx("OnLoginTimeout", SECONDS_TO_LOGIN * 1000, false, "i", playerid);
		}
		else
		{
			new lstring[512];
			format(lstring, sizeof(lstring), "{FFFFFF}Selamat datang di {FFD700}Kampung Indo Roleplay{FFFFFF}\nAkun ini membutuhkan kode pin!\nNama UCP: {FFFF00}%s{00FF00}\n{00FF00}Kesempatan Login (%d/3){FFFFFF}\n(Input PIN kode yang telah di berikan oleh BOT discord)", pData[playerid][pName], pData[playerid][pAttemps]);
			ShowPlayerDialog(playerid, UCP_PIN, DIALOG_STYLE_INPUT, "Account Verification", lstring, "Register", "Abort");
		}
	}
	else
	{
		if(IsValidUcpName(pData[playerid][pName]))
		{
			new str[512];
			format(str, sizeof(str), ""WHITE_E"UCP Name: "YELLOW_E"%s\n\n"RED_E"ERROR: "WHITE_E"Akun UCP dengan nama tersebut belum terdaftar di database.", pData[playerid][pName]);
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Account Verification", str, "Close", "");
			KickEx(playerid);
		}
	}
	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `banneds` WHERE `name` = '%s' OR `ip` = '%s' OR (`longip` != 0 AND (`longip` & %i) = %i) LIMIT 1", pData[playerid][pName], pData[playerid][pIP], BAN_MASK, (Ban_GetLongIP(PlayerIP) & BAN_MASK));
	mysql_tquery(g_SQL, query, "CheckBan", "i", playerid);
	return 1;
}

function CheckBan(playerid)
{
	if(cache_num_rows() > 0)
	{
		new Reason[40], PlayerName[24], BannedName[24];
	    new banTime_Int, banDate, banIP[16];
		cache_get_value_name(0, "name", BannedName);
		cache_get_value_name(0, "admin", PlayerName);
		cache_get_value_name(0, "reason", Reason);
		cache_get_value_name(0, "ip", banIP);
		cache_get_value_name_int(0, "ban_expire", banTime_Int);
		cache_get_value_name_int(0, "ban_date", banDate);

		new currentTime = gettime();
        if(banTime_Int != 0 && banTime_Int <= currentTime) // Unban the player.
		{
			new query[248];
			mysql_format(g_SQL, query, sizeof(query), "DELETE FROM banneds WHERE name = '%s'", pData[playerid][pName]);
			mysql_tquery(g_SQL, query);
				
			Servers(playerid, "Welcome back to server, its been %s since your ban was lifted.", ReturnTimelapse(banTime_Int, gettime()));
		}
		else
		{
			foreach(new pid : Player)
			{
				if(pData[pid][pTogLog] == 0)
				{
					SendClientMessageEx(pid, COLOR_RED, "Server: "GREY2_E"%s(%i) has been auto-kicked for ban evading.", pData[playerid][pName], playerid);
				}
			}
			new query[248], PlayerIP[16];
  			mysql_format(g_SQL, query, sizeof query, "UPDATE `banneds` SET `last_activity_timestamp` = %i WHERE `name` = '%s'", gettime(), pData[playerid][pName]);
			mysql_tquery(g_SQL, query);
				
			pData[playerid][IsLoggedIn] = false;
			printf("[BANNED INFO]: Ban Getting Called on %s", pData[playerid][pName]);
			GetPlayerIp(playerid, PlayerIP, sizeof(PlayerIP));
			
			InfoTD_MSG(playerid, 4000, "~r~~h~You are banned from this server!");
			//for(new l; l < 20; l++) SendClientMessage(playerid, COLOR_DARK, "\n");
			SendClientMessage(playerid, COLOR_RED, "You are banned from this server!");
			if(banTime_Int == 0)
			{
				new lstr[512];
				format(lstr, sizeof(lstr), "{FF0000}You are banned from this server!\n\n"LB2_E"Ban Info:\n{FF0000}UCP Name/Character Name: {778899}%s\n{FF0000}IP: {778899}%s\n{FF0000}Admin: {778899}%s\n{FF0000}Ban Date: {778899}%s\n{FF0000}Ban Reason: {778899}%s\n{FF0000}Ban Time: {778899}Permanent\n\n{FFFFFF}Merasa tidak bersalah terkena banned? Appeal di Discord Kampung Indo Roleplay", BannedName, PlayerIP, PlayerName, ReturnDate(banDate), Reason);
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"BANNED", lstr, "Exit", "");
			}
			else
			{
				new lstr[512];
				format(lstr, sizeof(lstr), "{FF0000}You are banned from this server!\n\n"LB2_E"Ban Info:\n{FF0000}UCP Name/Character Name: {778899}%s\n{FF0000}IP: {778899}%s\n{FF0000}Admin: {778899}%s\n{FF0000}Ban Date: {778899}%s\n{FF0000}Ban Reason: {778899}%s\n{FF0000}Ban Time: {778899}%s\n\n{FFFFFF}Merasa tidak bersalah terkena banned? Appeal di Discord Kampung Indo Roleplay ", BannedName, PlayerIP, PlayerName, ReturnDate(banDate), Reason, ReturnTimelapse(gettime(), banTime_Int));
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"BANNED", lstr, "Exit", "");
			}
			KickEx(playerid);
			return 1;
  		}
	}
	return 1;
}

function AssignPlayerData(playerid)
{
	new aname[MAX_PLAYER_NAME], ucpname[MAX_PLAYER_NAME], twname[MAX_PLAYER_NAME], twbio[MAX_PLAYER_NAME], email[40], age[128], ip[128], regdate[50], lastlogin[50];
	
	if(pData[playerid][pID] < 1)
	{
		Error(playerid, "Database player not found!");
		KickEx(playerid);
		return 1;
	}
	//cache_get_value_name_int(0, "reg_id", pData[playerid][pID]);
	cache_get_value_name(0, "ucp_name", ucpname);
	format(pData[playerid][pUcp], MAX_PLAYER_NAME, "%s", ucpname);
	cache_get_value_name(0, "adminname", aname);
	format(pData[playerid][pAdminname], MAX_PLAYER_NAME, "%s", aname);
	cache_get_value_name(0, "twittername", twname);
	format(pData[playerid][pTwittername], MAX_PLAYER_NAME, "%s", twname);
	cache_get_value_name(0, "twitterbio", twbio);
	format(pData[playerid][pTwitterbio], MAX_PLAYER_NAME, "%s", twbio);
	cache_get_value_name(0, "ip", ip);
	format(pData[playerid][pIP], 128, "%s", ip);
	cache_get_value_name(0, "email", email);
	format(pData[playerid][pEmail], 40, "%s", email);
	cache_get_value_name_int(0, "admin", pData[playerid][pAdmin]);
	cache_get_value_name_int(0, "helper", pData[playerid][pHelper]);
	cache_get_value_name_int(0, "streamer", pData[playerid][pStreamObj]);
	cache_get_value_name_int(0, "level", pData[playerid][pLevel]);
	cache_get_value_name_int(0, "levelup", pData[playerid][pLevelUp]);
	cache_get_value_name_int(0, "vip", pData[playerid][pVip]);
	cache_get_value_name_int(0, "vip_time", pData[playerid][pVipTime]);
	cache_get_value_name_int(0, "boost", pData[playerid][pBooster]);
	cache_get_value_name_int(0, "boost_time", pData[playerid][pBoostTime]);
	cache_get_value_name_int(0, "gold", pData[playerid][pGold]);
	cache_get_value_name(0, "reg_date", regdate);
	format(pData[playerid][pRegDate], 128, "%s", regdate);
	cache_get_value_name(0, "last_login", lastlogin);
	format(pData[playerid][pLastLogin], 128, "%s", lastlogin);
	cache_get_value_name_int(0, "money", pData[playerid][pMoney]);
	cache_get_value_name_int(0, "bmoney", pData[playerid][pBankMoney]);
	cache_get_value_name_int(0, "brek", pData[playerid][pBankRek]);
	cache_get_value_name_int(0, "phone", pData[playerid][pPhone]);
	cache_get_value_name_int(0, "phonecredit", pData[playerid][pPhoneCredit]);
	cache_get_value_name_int(0, "phonebook", pData[playerid][pPhoneBook]);
	cache_get_value_name_int(0, "gpsins", pData[playerid][pGpsIns]);
	cache_get_value_name_int(0, "twtins", pData[playerid][pTwtIns]);
	cache_get_value_name_int(0, "aonains", pData[playerid][pAonaIns]);
	cache_get_value_name_int(0, "wt", pData[playerid][pWT]);
	cache_get_value_name_int(0, "hours", pData[playerid][pHours]);
	cache_get_value_name_int(0, "minutes", pData[playerid][pMinutes]);
	cache_get_value_name_int(0, "seconds", pData[playerid][pSeconds]);
	cache_get_value_name_int(0, "paycheck", pData[playerid][pPaycheck]);
	cache_get_value_name_int(0, "skin", pData[playerid][pSkin]);
	cache_get_value_name_int(0, "facskin", pData[playerid][pFacSkin]);
	cache_get_value_name_int(0, "gender", pData[playerid][pGender]);
	cache_get_value_name(0, "age", age);
	format(pData[playerid][pAge], 128, "%s", age);
	cache_get_value_name_int(0, "indoor", pData[playerid][pInDoor]);
	cache_get_value_name_int(0, "inhouse", pData[playerid][pInHouse]);
	cache_get_value_name_float(0, "posx", pData[playerid][pPosX]);
	cache_get_value_name_float(0, "posy", pData[playerid][pPosY]);
	cache_get_value_name_float(0, "posz", pData[playerid][pPosZ]);
	cache_get_value_name_float(0, "posa", pData[playerid][pPosA]);
	cache_get_value_name_int(0, "interior", pData[playerid][pInt]);
	cache_get_value_name_int(0, "world", pData[playerid][pWorld]);
	cache_get_value_name_float(0, "health", pData[playerid][pHealth]);
	cache_get_value_name_float(0, "armour", pData[playerid][pArmour]);
	cache_get_value_name_int(0, "hunger", pData[playerid][pHunger]);
	cache_get_value_name_int(0, "energy", pData[playerid][pEnergy]);
	cache_get_value_name_int(0, "stress", pData[playerid][pStress]);
	cache_get_value_name_int(0, "sick", pData[playerid][pSick]);
	cache_get_value_name_int(0, "hospital", pData[playerid][pHospital]);
	cache_get_value_name_int(0, "injured", pData[playerid][pInjured]);
	cache_get_value_name_int(0, "duty", pData[playerid][pOnDuty]);
	cache_get_value_name_int(0, "dutytime", pData[playerid][pOnDutyTime]);
	cache_get_value_name_int(0, "faction", pData[playerid][pFaction]);
	cache_get_value_name_int(0, "factionrank", pData[playerid][pFactionRank]);
	cache_get_value_name_int(0, "factionlead", pData[playerid][pFactionLead]);
	cache_get_value_name_int(0, "family", pData[playerid][pFamily]);
	cache_get_value_name_int(0, "familyrank", pData[playerid][pFamilyRank]);
	cache_get_value_name_int(0, "workshop", pData[playerid][pWorkshop]);
	cache_get_value_name_int(0, "workshoprank", pData[playerid][pWorkshopRank]);
	cache_get_value_name_int(0, "jail", pData[playerid][pJail]);
	cache_get_value_name_int(0, "jail_time", pData[playerid][pJailTime]);
	cache_get_value_name_int(0, "rehab", pData[playerid][pRehab]);
	cache_get_value_name_int(0, "rehab_time", pData[playerid][pRehabTime]);
	cache_get_value_name_int(0, "robbing", pData[playerid][pRobbing]);
	cache_get_value_name_int(0, "robbing_time", pData[playerid][pRobbingTime]);
	cache_get_value_name_int(0, "arrest", pData[playerid][pArrest]);
	cache_get_value_name_int(0, "arrest_time", pData[playerid][pArrestTime]);
	cache_get_value_name_int(0, "warn", pData[playerid][pWarn]);
	cache_get_value_name_int(0, "job", pData[playerid][pJob]);
	cache_get_value_name_int(0, "job2", pData[playerid][pJob2]);
	cache_get_value_name_int(0, "jobtime", pData[playerid][pJobTime]);
	cache_get_value_name_int(0, "sidejobtime", pData[playerid][pSideJobTime]);
	cache_get_value_name_int(0, "exitjob", pData[playerid][pExitJob]);
	cache_get_value_name_int(0, "mask", pData[playerid][pMask]);
	cache_get_value_name_int(0, "helmet", pData[playerid][pHelmet]);
	cache_get_value_name_int(0, "fightingstyle", pData[playerid][pFightingStyle]);
	cache_get_value_name_int(0, "food", pData[playerid][pFood]);
	cache_get_value_name_int(0, "seed", pData[playerid][pSeed]);
	cache_get_value_name_int(0, "potato", pData[playerid][pPotato]);
	cache_get_value_name_int(0, "wheat", pData[playerid][pWheat]);
	cache_get_value_name_int(0, "orange", pData[playerid][pOrange]);
	cache_get_value_name_int(0, "price1", pData[playerid][pPrice1]);
	cache_get_value_name_int(0, "price2", pData[playerid][pPrice2]);
	cache_get_value_name_int(0, "price3", pData[playerid][pPrice3]);
	cache_get_value_name_int(0, "price4", pData[playerid][pPrice4]);
	cache_get_value_name_int(0, "plant", pData[playerid][pPlant]);
	cache_get_value_name_int(0, "plant_time", pData[playerid][pPlantTime]);
	cache_get_value_name_int(0, "fishtool", pData[playerid][pFishTool]);
	cache_get_value_name_int(0, "fish", pData[playerid][pFish]);
	cache_get_value_name_int(0, "worm", pData[playerid][pWorm]);
	cache_get_value_name_int(0, "idcard", pData[playerid][pIDCard]);
	cache_get_value_name_int(0, "idcard_time", pData[playerid][pIDCardTime]);
	cache_get_value_name_int(0, "drivelic", pData[playerid][pDriveLic]);
	cache_get_value_name_int(0, "drivelic_time", pData[playerid][pDriveLicTime]);
	cache_get_value_name_int(0, "lumberlic", pData[playerid][pLumberLic]);
	cache_get_value_name_int(0, "lumberlic_time", pData[playerid][pLumberLicTime]);
	cache_get_value_name_int(0, "trucklic", pData[playerid][pTruckLic]);
	cache_get_value_name_int(0, "trucklic_time", pData[playerid][pTruckLicTime]);
	cache_get_value_name_int(0, "weaponlic", pData[playerid][pWeapLic]);
	cache_get_value_name_int(0, "weaponlic_time", pData[playerid][pWeapLicTime]);
	cache_get_value_name_int(0, "spawn_tdtime", pData[playerid][pSpaTime]);
	cache_get_value_name_int(0, "togpm", pData[playerid][pTogPM]);
	cache_get_value_name_int(0, "toglog", pData[playerid][pTogLog]);
	cache_get_value_name_int(0, "togads", pData[playerid][pTogAds]);
	cache_get_value_name_int(0, "togwt", pData[playerid][pTogWT]);
	cache_get_value_name_int(0, "togreport", pData[playerid][pTogReport]);
	cache_get_value_name_int(0, "togask", pData[playerid][pTogAsk]);
	cache_get_value_name_int(0, "togadminchat", pData[playerid][pTogAdminchat]);
	cache_get_value_name_int(0, "togspeedcam", pData[playerid][pTogSpeedcam]);
	cache_get_value_name_int(0, "daging", pData[playerid][pDaging]);
	cache_get_value_name_int(0, "gandum", pData[playerid][pGandum]);
	cache_get_value_name_int(0, "susu", pData[playerid][pSusu]);
	cache_get_value_name_int(0, "susuolah", pData[playerid][pSusuolah]);
	cache_get_value_name_int(0, "staterpack", pData[playerid][pStarterPack]);
	cache_get_value_name_int(0, "kepala", pData[playerid][pHead]);
	cache_get_value_name_int(0, "perut", pData[playerid][pPerut]);
	cache_get_value_name_int(0, "tkanan", pData[playerid][pRHand]);
	cache_get_value_name_int(0, "tkiri", pData[playerid][pLHand]);
	cache_get_value_name_int(0, "kkanan", pData[playerid][pRFoot]);
	cache_get_value_name_int(0, "kkiri", pData[playerid][pLFoot]);
	cache_get_value_name_int(0, "accent", pData[playerid][pAccent]);
	cache_get_value_name_int(0, "asktime", pData[playerid][pAskTime]);
	cache_get_value_name_int(0, "suspect", pData[playerid][pSuspect]);
	cache_get_value_name_int(0, "getloctimer", pData[playerid][pSuspectTimer]);
	cache_get_value_name_int(0, "phonestatus", pData[playerid][pUsePhone]);
	cache_get_value_name_int(0, "waktuduty", pData[playerid][pDutyHour]);
	cache_get_value_name_int(0, "robdelay", pData[playerid][pRobTime]);
	cache_get_value_name_int(0, "usedrug", pData[playerid][pUseDrug]);
	cache_get_value_name_int(0, "weapskill", pData[playerid][pWeaponSkill]);
	cache_get_value_name_float(0, "beratbagasi", pData[playerid][pBeratBagasi]);
	
	cache_get_value_name_int(0, "Gun1", pData[playerid][pGuns][0]);
	cache_get_value_name_int(0, "Gun2", pData[playerid][pGuns][1]);
	cache_get_value_name_int(0, "Gun3", pData[playerid][pGuns][2]);
	cache_get_value_name_int(0, "Gun4", pData[playerid][pGuns][3]);
	cache_get_value_name_int(0, "Gun5", pData[playerid][pGuns][4]);
	cache_get_value_name_int(0, "Gun6", pData[playerid][pGuns][5]);
	cache_get_value_name_int(0, "Gun7", pData[playerid][pGuns][6]);
	cache_get_value_name_int(0, "Gun8", pData[playerid][pGuns][7]);
	cache_get_value_name_int(0, "Gun9", pData[playerid][pGuns][8]);
	cache_get_value_name_int(0, "Gun10", pData[playerid][pGuns][9]);
	cache_get_value_name_int(0, "Gun11", pData[playerid][pGuns][10]);
	cache_get_value_name_int(0, "Gun12", pData[playerid][pGuns][11]);
	cache_get_value_name_int(0, "Gun13", pData[playerid][pGuns][12]);
	
	cache_get_value_name_int(0, "Ammo1", pData[playerid][pAmmo][0]);
	cache_get_value_name_int(0, "Ammo2", pData[playerid][pAmmo][1]);
	cache_get_value_name_int(0, "Ammo3", pData[playerid][pAmmo][2]);
	cache_get_value_name_int(0, "Ammo4", pData[playerid][pAmmo][3]);
	cache_get_value_name_int(0, "Ammo5", pData[playerid][pAmmo][4]);
	cache_get_value_name_int(0, "Ammo6", pData[playerid][pAmmo][5]);
	cache_get_value_name_int(0, "Ammo7", pData[playerid][pAmmo][6]);
	cache_get_value_name_int(0, "Ammo8", pData[playerid][pAmmo][7]);
	cache_get_value_name_int(0, "Ammo9", pData[playerid][pAmmo][8]);
	cache_get_value_name_int(0, "Ammo10", pData[playerid][pAmmo][9]);
	cache_get_value_name_int(0, "Ammo11", pData[playerid][pAmmo][10]);
	cache_get_value_name_int(0, "Ammo12", pData[playerid][pAmmo][11]);
	cache_get_value_name_int(0, "Ammo13", pData[playerid][pAmmo][12]);
	
	for (new i; i < 17; i++)
	{
		WeaponSettings[playerid][i][Position][0] = -0.116;
		WeaponSettings[playerid][i][Position][1] = 0.189;
		WeaponSettings[playerid][i][Position][2] = 0.088;
		WeaponSettings[playerid][i][Position][3] = 0.0;
		WeaponSettings[playerid][i][Position][4] = 44.5;
		WeaponSettings[playerid][i][Position][5] = 0.0;
		WeaponSettings[playerid][i][Bone] = 1;
		WeaponSettings[playerid][i][Hidden] = false;
	}
	WeaponTick[playerid] = 0;
	EditingWeapon[playerid] = 0;
	new string[128];
	mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM weaponsettings WHERE Owner = '%d'", pData[playerid][pID]);
	mysql_tquery(g_SQL, string, "OnWeaponsLoaded", "d", playerid);

	new invQuery[256];
	mysql_format(g_SQL, invQuery, sizeof(invQuery), "SELECT * FROM `inventory` WHERE `ID` = '%d'", pData[playerid][pID]);
	mysql_tquery(g_SQL, invQuery, "LoadInventory", "d", playerid);
	
	KillTimer(pData[playerid][LoginTimer]);
	pData[playerid][LoginTimer] = 0;
	pData[playerid][IsLoggedIn] = true;

	MySQL_LoadPlayerToys(playerid);
	LoadPlayerVehicle(playerid);
	LoadArea(playerid);
	CreateJobAyam1();
	CreateAreaMiner();
	RefreshMapJobSapi(playerid);
	RefreshMapSacf(playerid);
	if(pData[playerid][pSpaTime] >= gettime())
	{
		SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
	    SpawnPlayer(playerid);
		return 1;
	}
	else
	{
		ShowSpawnMenu(playerid);
	}
	return 1;
}

function OnPlayerRegister(playerid)
{
	if(pData[playerid][IsLoggedIn] == true)
		return Error(playerid, "You already logged in!");
		
	pData[playerid][pID] = cache_insert_id();
	pData[playerid][IsLoggedIn] = true;

	pData[playerid][pPosX] = DEFAULT_POS_X;
	pData[playerid][pPosY] = DEFAULT_POS_Y;
	pData[playerid][pPosZ] = DEFAULT_POS_Z;
	pData[playerid][pPosA] = DEFAULT_POS_A;
	pData[playerid][pInt] = 0;
	pData[playerid][pWorld] = 0;
	pData[playerid][pGender] = 0;
	
	format(pData[playerid][pAdminname], MAX_PLAYER_NAME, "None");
	format(pData[playerid][pEmail], 40, "None");
	format(pData[playerid][pTwittername], 40, "None");
	format(pData[playerid][pTwitterbio], 40, "None");
	pData[playerid][pHealth] = 100.0;
	pData[playerid][pArmour] = 0.0;
	pData[playerid][pLevel] = 1;
	pData[playerid][pHunger] = 100;
	pData[playerid][pEnergy] = 100;
	pData[playerid][pStress] = 0;
	GivePlayerMoneyEx(playerid, FirstSpawnPrice);
	pData[playerid][pBankMoney] = 500;
	pData[playerid][pWorkshop] = -1;

	pData[playerid][pSick] = 0;

	pData[playerid][pHead] = 100;
	pData[playerid][pPerut] = 100;
	pData[playerid][pRHand] = 100;
	pData[playerid][pLHand] = 100;
	pData[playerid][pRFoot] = 100;
	pData[playerid][pLFoot] = 100;
	IsPlayerLanding[playerid] = 1;
	
	new query[128], rand = RandomEx(111111, 999999);
	new rek = rand+pData[playerid][pID];
	mysql_format(g_SQL, query, sizeof(query), "SELECT brek FROM players WHERE brek='%d'", rek);
	mysql_tquery(g_SQL, query, "BankRek", "id", playerid, rek);

	//Next Step
	SetPlayerSpawn(playerid);
	return 1;
}

function BankRek(playerid, brek)
{
	if(cache_num_rows() > 0)
	{
		//Rekening Exist
		new query[128], rand = RandomEx(11111, 99999);
		new rek = rand+pData[playerid][pID];
		mysql_format(g_SQL, query, sizeof(query), "SELECT brek FROM players WHERE brek='%d'", rek);
		mysql_tquery(g_SQL, query, "BankRek", "is", playerid, rek);
		Info(playerid, "Your Bank rekening number is same with someone. We will research new.");
	}
	else
	{
		new query[128];
	    mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET brek='%d' WHERE reg_id=%d", brek, pData[playerid][pID]);
		mysql_tquery(g_SQL, query);
		pData[playerid][pBankRek] = brek;
	}
    return true;
}

function PhoneNumber(playerid, phone)
{
	if(cache_num_rows() > 0)
	{
		//Rekening Exist
		new query[128], rand = RandomEx(1111, 9888);
		new phones = rand+pData[playerid][pID];
		mysql_format(g_SQL, query, sizeof(query), "SELECT phone FROM players WHERE phone='%d'", phones);
		mysql_tquery(g_SQL, query, "PhoneNumber", "is", playerid, phones);
		Info(playerid, "Your Phone number is same with someone. We will research new.");
	}
	else
	{
		new query[128];
	    mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET phone='%d' WHERE reg_id=%d", phone, pData[playerid][pID]);
		mysql_tquery(g_SQL, query);
		pData[playerid][pPhone] = phone;
	}
    return true;
}

function OnLoginTimeout(playerid)
{
	pData[playerid][LoginTimer] = 0;

	Error(playerid, "Anda sudah terlalu lama diam saat Login");
	Error(playerid, "Disconnecting from the server...");
	KickEx(playerid);
	return 1;
}


function _KickPlayerDelayed(playerid)
{
	Kick(playerid);
	return 1;
}

function SafeLogin(playerid)
{
	// Main Menu Features.
	SetPlayerVirtualWorld(playerid, 0);
	
	//Filtering Invalid UCP Format Name
	if(!IsValidUcpName(pData[playerid][pName]))
    {
        Error(playerid, "Nama tidak sesuai dengan format UCP.");
        Error(playerid, "Penggunaan nama harus mengikuti format UCP.");
        Error(playerid, "Sebagai contoh: Rulay, Kaizo dll.");
        KickEx(playerid);
    }
}

//---------[ Textdraw ]----------

// Info textdraw timer for hiding the textdraw
function InfoTD_MSG(playerid, ms_time, const text[])
{
	if(GetPVarInt(playerid, "InfoTDshown") != -1)
	{
	    PlayerTextDrawHide(playerid, notipcenter[playerid][0]);
	    KillTimer(GetPVarInt(playerid, "InfoTDshown"));
	}

    PlayerTextDrawSetString(playerid, notipcenter[playerid][0], text);
    PlayerTextDrawShow(playerid, notipcenter[playerid][0]);
	SetPVarInt(playerid, "InfoTDshown", SetTimerEx("InfoTD_Hide", ms_time, false, "i", playerid));
	return 1;
}

function InfoTD_Hide(playerid)
{
	SetPVarInt(playerid, "InfoTDshown", -1);
	PlayerTextDrawHide(playerid, notipcenter[playerid][0]);
	return 1;
}

//---------[Admin Function ]----------

function a_ChangeAdminName(otherplayer, playerid, nname[])
{
	if(cache_num_rows() > 0)
	{
		// Name Exists
		Error(playerid, "Akun "DARK_E"'%s' "GREY_E"Telah ada! Harap gunakan yang lain", nname);
	}
	else
	{
		new query[1028];
	    format(query, sizeof(query), "UPDATE players SET adminname='%e' WHERE reg_id=%d", nname, pData[otherplayer][pID]);
		mysql_tquery(g_SQL, query);
		format(pData[otherplayer][pAdminname], MAX_PLAYER_NAME, "%s", nname);
		Servers(playerid, "You has set admin name player %s to %s", pData[otherplayer][pName], nname);
	}
    return true;
}

function LoadStats(playerid, PlayersName[])
{
	if(!cache_num_rows())
	{
		Error(playerid, "Account '%s' does not exist.", PlayersName);
	}
	else
	{
		new email[40], admin, helper, level, levelup, vip, viptime, coin, regdate[40], lastlogin[40], money, bmoney, brek,
			jam, menit, detik, gender, age[40], faction, family, warn, job, job2, int, world;
		cache_get_value_index(0, 0, email);
		cache_get_value_index_int(0, 1, admin);
		cache_get_value_index_int(0, 2, helper);
		cache_get_value_index_int(0, 3, level);
		cache_get_value_index_int(0, 4, levelup);
		cache_get_value_index_int(0, 5, vip);
		cache_get_value_index_int(0, 6, viptime);
		cache_get_value_index_int(0, 7, coin);
		cache_get_value_index(0, 8, regdate);
		cache_get_value_index(0, 9, lastlogin);
		cache_get_value_index_int(0, 10, money);
		cache_get_value_index_int(0, 11, bmoney);
		cache_get_value_index_int(0, 12, brek);
		cache_get_value_index_int(0, 13, jam);
		cache_get_value_index_int(0, 14, menit);
		cache_get_value_index_int(0, 15, detik);
		cache_get_value_index_int(0, 16, gender);
		cache_get_value_index(0, 17, age);
		cache_get_value_index_int(0, 18, faction);
		cache_get_value_index_int(0, 19, family);
		cache_get_value_index_int(0, 20, warn);
		cache_get_value_index_int(0, 21, job);
		cache_get_value_index_int(0, 22, job2);
		cache_get_value_index_int(0, 23, int);
		cache_get_value_index_int(0, 24, world);
		
		new header[248], scoremath = ((level)*5), fac[24], Cache:checkfamily, gstr[2468], query[128];
	
		if(faction == 1)
		{
			fac = "San Andreas Police";
		}
		else if(faction == 2)
		{
			fac = "San Andreas Goverment";
		}
		else if(faction == 3)
		{
			fac = "San Andreas Medic";
		}
		else if(faction == 4)
		{
			fac = "San Andreas News";
		}
		else
		{
			fac = "None";
		}
		
		new name[40];
		if(admin == 1)
		{
			name = ""RED_E"Administrator(1)";
		}
		else if(admin == 2)
		{
			name = ""RED_E"Senior Admin(2)";
		}
		else if(admin == 3)
		{
			name = ""RED_E"Lead Admin(3)";
		}
		else if(admin == 4)
		{
			name = ""RED_E"Head Admin(4)";
		}
		else if(admin== 5)
		{
			name = ""RED_E"Server Owner(5)";
		}
		else if(helper >= 1 && admin == 0)
		{
			name = ""GREEN_E"Helper";
		}
		else
		{
			name = "None";
		}
		
		new name1[30];
		if(vip == 1)
		{
			name1 = ""LG_E"Regular(1)";
		}
		else if(vip == 2)
		{
			name1 = ""YELLOW_E"Premium(2)";
		}
		else if(vip == 3)
		{
			name1 = ""PURPLE_E"VIP Player(3)";
		}
		else
		{
			name1 = "None";
		}
		
		format(query, sizeof(query), "SELECT * FROM `familys` WHERE `ID`='%d'", family);
		checkfamily = mysql_query(g_SQL, query);

		new atext[512];

		new boost = pData[playerid][pBooster];
		new boosttime = pData[playerid][pBoostTime];
		if(boost == 1)
		{
			atext = "{7fff00}Yes";
		}
		else 
		{
			atext = "{ff0000}No";
		}
		
		new rows = cache_num_rows(), fname[128];
		
		if(rows)
		{
			new fam[128];
			cache_get_value_name(0, "name", fam);
			format(fname, 128, fam);
		}
		else
		{
			format(fname, 128, "None");
		}
		
		format(header,sizeof(header),"Stats:"YELLOW_E"%s"WHITE_E" ("BLUE_E"%s"WHITE_E")", PlayersName, ReturnTime());
		format(gstr,sizeof(gstr),""RED_E"In Character"WHITE_E"\n");
		format(gstr,sizeof(gstr),"%sGender: [%s] | Money: ["GREEN_E"%s"WHITE_E"] | Bank: ["GREEN_E"%s"WHITE_E"] | Rekening Bank: [%d] | Phone Number: [None]\n", gstr,(gender == 2) ? ("Female") : ("Male") , FormatMoney(money), FormatMoney(bmoney), brek);
		format(gstr,sizeof(gstr),"%sBirdthdate: [%s] | Job: [None] | Job2: [None] | Faction: [%s] | Family: [%s]\n\n", gstr, age, fac, fname);
		format(gstr,sizeof(gstr),"%s"RED_E"Out of Character"WHITE_E"\n",gstr);
		format(gstr,sizeof(gstr),"%sLevel score: [%d/%d] | Email: [%s] | Warning:[%d/10] | Last Login: [%s]\n", gstr, levelup, scoremath, email, warn, lastlogin);
		format(gstr,sizeof(gstr),"%sStaff: [%s"WHITE_E"] | Time Played: [%d hour(s) %d minute(s) %02d second(s)] | Gold Coin: [%d]\n", gstr, name, jam, menit, detik, coin);
		if(vip != 0)
		{
			format(gstr,sizeof(gstr),"%sInterior: [%d] | Virtual World: [%d] | Register Date: [%s] | VIP Level: [%s"WHITE_E"] | VIP Time: [%s] | Roleplay Booster: [%s"WHITE_E"] | Boost Time: [%s]", gstr, int, world, regdate, name1, ReturnTimelapse(gettime(), viptime), boost, ReturnTimelapse(gettime(), boosttime));
		}
		else
		{
			format(gstr,sizeof(gstr),"%sInterior: [%d] | Virtual World: [%d] | Register Date: [%s] | VIP Level: [%s"WHITE_E"] | VIP Time: [None] | Roleplay Booster: [%s"WHITE_E"] | Boost Time: [%s]", gstr, int, world, regdate, name1, boost, ReturnTimelapse(gettime(), boosttime));
		}
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, header, gstr, "Close", "");
		
		cache_delete(checkfamily);
	}
	return true;
}

function CheckPlayerIP(playerid, zplayerIP[])
{
	new count = cache_num_rows(), datez, line[248], tstr[64], lstr[128];
	if(count)
	{
		datez = 0;
 		line = "";
 		format(line, sizeof(line), "Names matching IP: %s:\n\n", zplayerIP);
 		for(new i = 0; i != count; i++)
		{
			// Get the name  ache and append it to the dialog content
			cache_get_value_index(i, 0, lstr);
			strcat(line, lstr);
			datez ++;

			if(datez == 5)
				strcat(line, "\n"), datez = 0;
			else
				strcat(line, "\t\t");
		}

		tstr = "{ACB5BA}Aliases for {70CAFA}", strcat(tstr, zplayerIP);
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, tstr, line, "Close", "");
	}
	else
 	{
		Error(playerid, "No other accounts from this IP!");
	}
	return 1;
}

function CheckPlayerIP2(playerid, zplayerIP[])
{
	new rows = cache_num_rows(), datez, line[248], tstr[64], lstr[128];
	if(!rows)
	{
		Error(playerid, "No other accounts from this IP!");
	}
	else
 	{
 		datez = 0;
 		line = "";
 		format(line, sizeof(line), "Names matching IP: %s:\n\n", zplayerIP);
 		for(new i = 0; i != rows; i++)
		{
			// Get the name from the cache and append it to the dialog content
			cache_get_value_index(i, 0, lstr);
			strcat(line, lstr);
			datez ++;

			if(datez == 5)
				strcat(line, "\n"), datez = 0;
			else
				strcat(line, "\t\t");
		}

		tstr = "{ACB5BA}Aliases for {70CAFA}", strcat(tstr, zplayerIP);
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, tstr, line, "Close", "");
	}
	return 1;
}

function JailPlayer(playerid)
{
	ShowPlayerDialog(playerid, -1, DIALOG_STYLE_LIST, "Close", "Close", "Close", "Close");
	SetPlayerPositionEx(playerid, -310.64, 1894.41, 34.05, 178.17, 2000);
	SetPlayerInterior(playerid, 10);
	SetPlayerVirtualWorld(playerid, 100);
	SetPlayerWantedLevel(playerid, 0);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	//ResetPlayerWeaponsEx(playerid);
	
	pData[playerid][pInHouse] = -1;
	pData[playerid][pInDoor] = -1;
	pData[playerid][pCuffed] = 0;
	PlayerPlaySound(playerid, 1186, 0, 0, 0);
	return true;
}

function RehabPlayer(playerid)
{
	ShowPlayerDialog(playerid, -1, DIALOG_STYLE_LIST, "Close", "Close", "Close", "Close");
	SetPlayerPositionEx(playerid, 1153.74, -1330.82, -44.28+0.2, 359.26, 2000);
	SetPlayerInterior(playerid, 10);
	SetPlayerVirtualWorld(playerid, 100);
	SetPlayerWantedLevel(playerid, 0);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	//ResetPlayerWeaponsEx(playerid);
	
	pData[playerid][pInHouse] = -1;
	pData[playerid][pInDoor] = -1;
	pData[playerid][pCuffed] = 0;
	PlayerPlaySound(playerid, 1186, 0, 0, 0);
	return true;
}

//-----------[ Banneds Function ]----------

function OnOBanQueryData(adminid, NameToBan[], banReason[], banTime)
{
	new mstr[512];
	mstr = "";
	if(!cache_num_rows())
	{
		Error(adminid, "Account '%s' does not exist.", NameToBan);
	}
	else
	{
		new datez, PlayerIP[16];
		cache_get_value_index(0, 0, PlayerIP);
		if(banTime != 0)
	    {
			datez = gettime() + (banTime * 86400);
            Servers(adminid, "You have temp-banned %s (IP: %s) from the server.", NameToBan, PlayerIP);
			SendClientMessageToAllEx(COLOR_RED, "Server: "GREY2_E"Admin %s telah membanned offline player %s selama %d hari. [Reason: %s]", pData[adminid][pAdminname], NameToBan, banTime, banReason);
		}
		else
		{
			Servers(adminid, "You have permanent-banned %s (IP: %s) from the server.", NameToBan, PlayerIP);
			SendClientMessageToAllEx(COLOR_RED, "Server: "GREY2_E"Admin %s telah membanned offline player %s secara permanent. [Reason: %s]", pData[adminid][pAdminname], NameToBan, banReason);
		}
		new query[512];
		mysql_format(g_SQL, query, sizeof(query), "INSERT INTO banneds(name, ip, admin, reason, ban_date, ban_expire) VALUES ('%s', '%s', '%s', '%s', UNIX_TIMESTAMP(), %d)", NameToBan, PlayerIP, pData[adminid][pAdminname], banReason, datez);
		mysql_tquery(g_SQL, query);
	}
	return true;
}

function OnOBanUcpQueryData(adminid, NameToBan[], banReason[], banTime)
{
	new mstr[512];
	mstr = "";
	if(!cache_num_rows())
	{
		Error(adminid, "Account UCP '%s' does not exist.", NameToBan);
	}
	else
	{
		new datez, PlayerIP[16];
		cache_get_value_index(0, 0, PlayerIP);
		if(banTime != 0)
	    {
			datez = gettime() + (banTime * 86400);
            Servers(adminid, "You have temp-banned %s (IP: %s) from the server.", NameToBan, PlayerIP);
			SendClientMessageToAllEx(COLOR_RED, "Server: "GREY2_E"Admin %s telah membanned offline UCP %s selama %d hari. [Reason: %s]", pData[adminid][pAdminname], NameToBan, banTime, banReason);
		}
		else
		{
			Servers(adminid, "You have permanent-banned %s (IP: %s) from the server.", NameToBan, PlayerIP);
			SendClientMessageToAllEx(COLOR_RED, "Server: "GREY2_E"Admin %s telah membanned offline UCP %s secara permanent. [Reason: %s]", pData[adminid][pAdminname], NameToBan, banReason);
		}
		new query[512];
		mysql_format(g_SQL, query, sizeof(query), "INSERT INTO banneds(name, ip, admin, reason, ban_date, ban_expire) VALUES ('%s', '%s', '%s', '%s', UNIX_TIMESTAMP(), %d)", NameToBan, PlayerIP, pData[adminid][pAdminname], banReason, datez);
		mysql_tquery(g_SQL, query);
	}
	return true;
}


//-------------[ Player Update Function ]----------

function DragUpdate(playerid, targetid)
{
    if(pData[targetid][pDragged] && pData[targetid][pDraggedBy] == playerid)
    {
        static
        Float:fX,
        Float:fY,
        Float:fZ,
        Float:fAngle;

        GetPlayerPos(playerid, fX, fY, fZ);
        GetPlayerFacingAngle(playerid, fAngle);

        fX -= 3.0 * floatsin(-fAngle, degrees);
        fY -= 3.0 * floatcos(-fAngle, degrees);

        SetPlayerPos(targetid, fX, fY, fZ);
        SetPlayerInterior(targetid, GetPlayerInterior(playerid));
        SetPlayerVirtualWorld(targetid, GetPlayerVirtualWorld(playerid));
		//ApplyAnimation(targetid, "PED", "BIKE_fall_off", 4.1, 0, 1, 1, 1, 0, 1);
		ApplyAnimation(targetid,"PED","WALK_civi",4.1,1,1,1,1,1);
    }
    return 1;
}

function UnfreezePee(playerid)
{
    TogglePlayerControllable(playerid, 1);
    clearAnimations(playerid);
	StopLoopingAnim(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	return 1;
}

function UnfreezeSleep(playerid)
{
    TogglePlayerControllable(playerid, 1);
    pData[playerid][pEnergy] = 100;
	pData[playerid][pHunger] -= 3;
    clearAnimations(playerid);
	StopLoopingAnim(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	SuccesMsg(playerid, "Sleeping Done!");
	return 1;
}

function RefullCar(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
    {
		if(IsValidVehicle(vehicleid))
		{
			vCore[vehicleid][vFuel] = 100;
			SuccesMsg(playerid, "Refulling done!");
			//SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has successfully refulling the vehicle.", ReturnName(playerid));
			KillTimer(pData[playerid][pActivity]);
			pData[playerid][pActivityTime] = 0;
		}
		else
		{
			Error(playerid, "Refulling fail! Anda tidak berada didekat kendaraan tersebut!");
			KillTimer(pData[playerid][pActivity]);
			pData[playerid][pActivityTime] = 0;
		}
	}
	else
	{
		Error(playerid, "Refulling fail! Anda tidak berada didekat kendaraan tersebut!");
		KillTimer(pData[playerid][pActivity]);
		pData[playerid][pActivityTime] = 0;
		return 1;
	}
	return 1;
}

//Bank
function SearchRek(playerid, rek)
{
	if(!cache_num_rows())
	{
		// Rekening tidak ada
		Error(playerid, "Rekening bank "YELLOW_E"'%d' "WHITE_E"tidak terdaftar!", rek);
		pData[playerid][pTransfer] = 0;
	    
	}
	else
	{
	    // Proceed
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "SELECT username,brek FROM players WHERE brek='%d'", rek);
		mysql_tquery(g_SQL, query, "SearchRek2", "id", playerid, rek);
	}
}

function SearchRek2(playerid, rek)
{
	if(cache_num_rows())
	{
		new name[128], brek, mstr[128];
		cache_get_value_index(0, 0, name);
		cache_get_value_index_int(0, 1, brek);
		
		//format(pData[playerid][pTransferName], 128, "%s" name);
		pData[playerid][pTransferName] = name;
		pData[playerid][pTransferRek] = brek;
		format(mstr, sizeof(mstr), ""WHITE_E"No Rek Target: "YELLOW_E"%d\n"WHITE_E"Nama Target: "YELLOW_E"%s\n"WHITE_E"Jumlah: "GREEN_E"%s\n\n"WHITE_E"Anda yakin akan melanjutkan mentransfer?", brek, name, FormatMoney(pData[playerid][pTransfer]));
		ShowPlayerDialog(playerid, DIALOG_BANKCONFIRM, DIALOG_STYLE_MSGBOX, ""LB_E"Bank", mstr, "Transfer", "Cancel");
	}
	return true;
}

//Atm
function SearchRekAtm(playerid, rek)
{
	if(!cache_num_rows())
	{
		// Rekening tidak ada
		Error(playerid, "Rekening bank "YELLOW_E"'%d' "WHITE_E"tidak terdaftar!", rek);
		pData[playerid][pTransfer] = 0;
	    
	}
	else
	{
	    // Proceed
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "SELECT username,brek FROM players WHERE brek='%d'", rek);
		mysql_tquery(g_SQL, query, "SearchRekAtm2", "id", playerid, rek);
	}
}

function SearchRekAtm2(playerid, rek)
{
	if(cache_num_rows())
	{
		new name[128], brek, mstr[128];
		cache_get_value_index(0, 0, name);
		cache_get_value_index_int(0, 1, brek);
		
		//format(pData[playerid][pTransferName], 128, "%s" name);
		pData[playerid][pTransferName] = name;
		pData[playerid][pTransferRek] = brek;
		format(mstr, sizeof(mstr), ""WHITE_E"No Rek Target: "YELLOW_E"%d\n"WHITE_E"Nama Target: "YELLOW_E"%s\n"WHITE_E"Jumlah: "GREEN_E"%s\n\n"WHITE_E"Anda yakin akan melanjutkan mentransfer?", brek, name, FormatMoney(pData[playerid][pTransfer]));
		ShowPlayerDialog(playerid, DIALOG_ATMCONFIRM, DIALOG_STYLE_MSGBOX, ""LB_E"Bank", mstr, "Transfer", "Cancel");
	}
	return true;
}

//----------[ JOB FUNCTION ]-------------

//Server Timer
function pCountDown()
{
	Count--;
	if(0 >= Count)
	{
		Count = -1;
		KillTimer(countTimer);
		foreach(new ii : Player)
		{
 			if(showCD[ii] == 1)
   			{
   				InfoTD_MSG(ii, 4000, "~w~GO~r~!~g~!~b~!");
   				PlayerPlaySound(ii, 1057, 0, 0, 0);
   				showCD[ii] = 0;
			}
		}
	}
	else
	{
		foreach(new ii : Player)
		{
 			if(showCD[ii] == 1)
   			{
				InfoTD_MSG(ii, 4000, CountText[Count-1]);
				PlayerPlaySound(ii, 1056, 0, 0, 0);
   			}
		}
	}
	return 1;
}

//----------[ Other Function ]-----------

function SetPlayerToUnfreeze(playerid, Float:x, Float:y, Float:z, Float:a)
{
    if(!IsPlayerInRangeOfPoint(playerid, 15.0, x, y, z))
        return 0;

    pData[playerid][pFreeze] = 0;
    SetPlayerPos(playerid, x, y, z);
	SetPlayerFacingAngle(playerid, a);
    TogglePlayerControllable(playerid, 1);
    return 1;
}

stock GetName(playerid)
{
	new name[MAX_PLAYER_NAME];
 	GetPlayerName(playerid,name,sizeof(name));
	return name;
}

function SetVehicleToUnfreeze(playerid, vehicleid, Float:x, Float:y, Float:z, Float:a)
{
    if(!IsPlayerInRangeOfPoint(playerid, 15.0, x, y, z))
        return 0;

    pData[playerid][pFreeze] = 0;
    SetVehiclePos(vehicleid, x, y, z);
	SetVehicleZAngle(vehicleid, a);
    TogglePlayerControllable(playerid, 1);
    return 1;
}

//NERF DARAH KETIKA VALUE LAPAR ATAU HAUS DIBAWAH 5
/*
function NerfHpEnegyHunger(playerid)
{
	if(pData[playerid][pSpawned] == 1 && pData[playerid][IsLoggedIn] == true)
	{
		if(pData[playerid][pInjured] == 0 || pData[playerid][pHospital] == 0 || pData[playerid][pJail] == 0)
		{
			if(pData[playerid][pHunger] <= 5 || pData[playerid][pEnergy] <= 5)
			{
				if(pData[playerid][pNerfHP] != 0)
				{
					new Float:health;
					pData[playerid][pNerfHP] = 0;
					GetPlayerHealth(playerid, Float:health);
					SetPlayerHealthEx(playerid, health - 3);
					Info(playerid, "Kamu harus makan dan minum agar darahmu tidak berkurang!");
				}
			}
		}
	}
	return 1;
}*/

function ShowRedScreen(playerid)
{
	if(pData[playerid][pRedScreen] <= 8)
	{
		TextDrawHideForPlayer(playerid, Text:RedScreen);
		SetTimerEx("DirectRedScreen", 2000, 0, "d", playerid);
	}
	else
	{
		pData[playerid][pRedScreen] = 0;
		TextDrawHideForPlayer(playerid, Text:RedScreen);
		SetPlayerDrunkLevel(playerid, 0);
		clearAnimations(playerid);
		StopLoopingAnim(playerid);
	}
	return 1;
}

function DirectRedScreen(playerid)
{
	pData[playerid][pRedScreen] += 1;
	TextDrawShowForPlayer(playerid, Text:RedScreen);
	SetTimerEx("ShowRedScreen", 1000, 0, "d", playerid);
	return 1;
}

function ChangeTwitterName(playerid, name[])
{
	if(cache_num_rows() > 0)
	{
		new str[254];
		format(str, sizeof(str), "ERROR: Sudah ada akun twitter yang memiliki username tersebut!\n\nUsername mu sekarang: @%s\nMasukan nama twitter yang kamu inginkan:", pData[playerid][pTwittername]);
		ShowPlayerDialog(playerid, TWITTER_NAME, DIALOG_STYLE_INPUT, "Twitter Name", str, "Yes", "No");
	}
	else
	{
		new query[512];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET twittername = '%s' WHERE reg_id = '%d'", name, pData[playerid][pID]);
		mysql_tquery(g_SQL, query);

		format(pData[playerid][pTwittername], 40, name);
		Info(playerid, "Kamu telah merubah username twitter mu menjadi @%s", pData[playerid][pTwittername]);
	}
	return 1;
}

function ChangeTwitterBio(playerid, name[])
{
	if(cache_num_rows() > 0)
	{
		new str[254];
		format(str, sizeof(str), "ERROR: Sudah ada twitter yang memiliki nio tersebut!\n\nBio mu sekarang: %s\nMasukan bio yang kamu inginkan:", pData[playerid][pTwitterbio]);
		ShowPlayerDialog(playerid, TWITTER_NAME, DIALOG_STYLE_INPUT, "Twitter Bio", str, "Yes", "No");
	}
	else
	{
		new query[512];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET twitterbio = '%s' WHERE reg_id = '%d'", name, pData[playerid][pID]);
		mysql_tquery(g_SQL, query);

		format(pData[playerid][pTwitterbio], 40, name);
		Info(playerid, "Kamu telah merubah nio twitter mu menjadi %s", pData[playerid][pTwitterbio]);
	}
	return 1;
}

function TimerUntogglePlayer(playerid)
{
	TogglePlayerControllable(playerid, 1);
	return 1;
}

function VipSetNumber(playerid, phnumber)
{
	new rows = cache_num_rows();
	if(rows > 0)
	{
		Error(playerid, "Nomor tersebut sudah yang memiliki!");
	}
	else
	{
		pData[playerid][pPhone] = phnumber;
		pData[playerid][pVipNumber] = gettime() + 30;
		Info(playerid, "Kamu telah merubah nomor hanphone mu menjadi "YELLOW_E"%d"WHITE_E"", pData[playerid][pPhone]);

		new cQuery[254];
		mysql_format(g_SQL, cQuery, sizeof(cQuery), "UPDATE players SET phone = '%d' WHERE reg_id = '%d'", phnumber, pData[playerid][pID]);
		mysql_tquery(g_SQL, cQuery);
	}
}

function AdminSetNumber(playerid, phnumber)
{
	new rows = cache_num_rows();
	if(rows > 0)
	{
		Error(playerid, "Nomor tersebut sudah yang memiliki!");
	}
	else
	{
		pData[playerid][pPhone] = phnumber;
		Info(playerid, "Kamu telah merubah nomor hanphone mu menjadi "YELLOW_E"%d"WHITE_E"", pData[playerid][pPhone]);

		new cQuery[254];
		mysql_format(g_SQL, cQuery, sizeof(cQuery), "UPDATE players SET phone = '%d' WHERE reg_id = '%d'", phnumber, pData[playerid][pID]);
		mysql_tquery(g_SQL, cQuery);
	}
}

function cookingsacf(playerid, type)
{
	if(!IsPlayerConnected(playerid)) return 0;
	{
		{
			if(IsPlayerInRangeOfPoint(playerid, 1.5, 586.45, -1820.44, 6.08))
			{
				SuccesMsg(playerid, "Anda telah berhasil memasak");
				pData[playerid][pLoading] = false;
				pData[playerid][pEnergy] -= 3;
			}
		}
	}
	return 1;
}

function pakebandage(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	{
		TogglePlayerControllable(playerid, 1);
		pData[playerid][pLoading] = false;
		clearAnimations(playerid);

		RemovePlayerAttachedObject(playerid, 9);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

		new Float:darahhh;
		GetPlayerHealth(playerid, darahhh);
		SetPlayerHealthEx(playerid, darahhh+10);
		InfoMsg(playerid, "Restore +10 Health");
		Inventory_Remove(playerid, "Bandage", 1);
	}
	return 1;
}

function pakekevlar(playerid)
{
	TogglePlayerControllable(playerid, 1);
	clearAnimations(playerid);
	SetPlayerArmourEx(playerid, 95);
	Inventory_Remove(playerid, "Kevlar", 1);
	return 1;
}

function HashRegPassword(playerid, hashid)
{
	new
		query[256],
		PlayerIP[16],
		hash[BCRYPT_HASH_LENGTH];

    bcrypt_get_hash(hash, sizeof(hash));

	GetPlayerIp(playerid, PlayerIP, sizeof(PlayerIP));
	mysql_format(g_SQL, query, sizeof query, "UPDATE ucp SET password = '%e', ip = '%e', register = '1', reg_date = CURRENT_TIMESTAMP() WHERE ucp_name = '%s'", hash, PlayerIP, pData[playerid][pName]);
	mysql_tquery(g_SQL, query);
	MySQL_LoadUcpCharacter(playerid);
	return 1;
}

function OnPlayerPasswordChecked(playerid, bool:success)
{
    if(!IsPlayerConnected(playerid)) return 0; // Check if the player is still connected

    if(!success)
    {
        pData[playerid][pAttemps]++;

        if (pData[playerid][pAttemps] >= 3) // Maximum login attempts reached
        {
            ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, 
                "Account Login", "{FFFFFF}You have mistyped your password too often (3 times).", 
                "Okay", "");
            
            return KickEx(playerid);
        }
        else 
        {
            new lstring[512];
            format(lstring, sizeof(lstring), "{FFFFFF}Welcome to {FFD700}Kampung Indo Roleplay\n{FFFFFF}You can log in using this UCP!\nUCP Name: {FFFF00}%s{FF0000}\n{00FF00}Login Attempts (%d/3){FFFFFF}\n(The password you entered is incorrect, please try again)", pData[playerid][pName], pData[playerid][pAttemps]);

            ShowPlayerDialog(playerid, UCP_LOGIN, DIALOG_STYLE_PASSWORD, 
                "Account Login", lstring, "Login", "Abort");
        }
    }
    else
    {
        MySQL_LoadUcpCharacter(playerid); // Proceed with login if password is correct
    }
    return 1;
}

/*function PlayerNameTags(playerid)
{
	new strc[1000];
	format(strc, sizeof(strc), "%s [%d]", pData[playerid][pUcp], playerid);
	Update3DTextLabelText(PlayerTags[playerid], -1, strc);
}*/

function revivenewplayer(playerid)
{
	pData[playerid][pInjured] = 0;
	pData[playerid][pHospital] = 0;
	pData[playerid][pSick] = 0;
	pData[playerid][pHead] = 100;
	pData[playerid][pPerut] = 100;
	pData[playerid][pRHand] = 100;
	pData[playerid][pLHand] = 100;
	pData[playerid][pRFoot] = 100;
	pData[playerid][pLFoot] = 100;
	clearAnimations(playerid);
	StopLoopingAnim(playerid);
	HideTDdeath(playerid);
	Toggleaccdeath[playerid] = 0;
	SetPlayerHealthEx(playerid, 100.0);
}

function mediclocal(playerid)
{
	pData[playerid][pInjured] = 0;
	pData[playerid][pHospital] = 0;
	pData[playerid][pSick] = 0;
	pData[playerid][pHead] = 100;
	pData[playerid][pPerut] = 100;
	pData[playerid][pRHand] = 100;
	pData[playerid][pLHand] = 100;
	pData[playerid][pRFoot] = 100;
	pData[playerid][pLFoot] = 100;
	clearAnimations(playerid);
	StopLoopingAnim(playerid);
	HideTDdeath(playerid);
	Toggleaccdeath[playerid] = 0;
	SetPlayerHealthEx(playerid, 100.0);
	GivePlayerMoneyEx(playerid, -500);	
}

stock CountFaction(faction)
{
	new count = 0;
	foreach(new i : Player) if(pData[i][pFaction] == faction && pData[i][pOnDuty])
	{
		count++;
	}
	return count;
}

stock GetElapsedTime(time, &hours, &minutes, &seconds)
{
	hours = 0;
	minutes = 0;

	if (time >= 3600)
	{
		hours = (time / 3600);
		time -= (hours * 3600);
	}
	while (time >= 60)
	{
	    minutes++;
	    time -= 60;
	}
	
	seconds = time; // Assign value ke seconds
	return seconds; // Kembalikan nilai seconds
}

stock IsPlayerNearPlayer(playerid, targetid, Float:radius)
{
	static
		Float:fX,
		Float:fY,
		Float:fZ;

	GetPlayerPos(targetid, fX, fY, fZ);

	return (GetPlayerInterior(playerid) == GetPlayerInterior(targetid) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(targetid)) && IsPlayerInRangeOfPoint(playerid, radius, fX, fY, fZ);
}

stock IsPlayerNearBoot(playerid, vehicleid)
{
	static
		Float:fX,
		Float:fY,
		Float:fZ;

	GetVehicleBooot(vehicleid, fX, fY, fZ);

	return (GetPlayerVirtualWorld(playerid) == GetVehicleVirtualWorld(vehicleid)) && IsPlayerInRangeOfPoint(playerid, 3.5, fX, fY, fZ);
}

stock GetVehicleBooot(vehicleid, &Float:x, &Float:y, &Float:z)
{
	if (!GetVehicleModel(vehicleid) || vehicleid == INVALID_VEHICLE_ID)
	    return (x = 0.0, y = 0.0, z = 0.0), 0;

	static
	    Float:pos[7]
	;
	GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, pos[0], pos[1], pos[2]);
	GetVehiclePos(vehicleid, pos[3], pos[4], pos[5]);
	GetVehicleZAngle(vehicleid, pos[6]);

	x = pos[3] - (floatsqroot(pos[1] + pos[1]) * floatsin(-pos[6], degrees));
	y = pos[4] - (floatsqroot(pos[1] + pos[1]) * floatcos(-pos[6], degrees));
 	z = pos[5];

	return 1;
}

function makansnack(playerid)
{
	Inventory_Remove(playerid, "Snack", 1);
	TogglePlayerControllable(playerid, 1);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pHunger] += 10;
	return 1;
}

function makanpizza(playerid)
{
	Inventory_Remove(playerid, "Pizza Stack", 1);
	TogglePlayerControllable(playerid, 1);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pHunger] += 40;
	return 1;
}

function minumwater(playerid)
{
	Inventory_Remove(playerid, "Water", 1);
	TogglePlayerControllable(playerid, 1);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pEnergy] += 20;
	return 1;
}

function minumsprunk(playerid)
{
	Inventory_Remove(playerid, "Sprunk", 1);
	TogglePlayerControllable(playerid, 1);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pEnergy] += 15;
	return 1;
}

function minumjusjeruk(playerid)
{
	Inventory_Remove(playerid, "Jus Jeruk", 1);
	TogglePlayerControllable(playerid, 1);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pEnergy] += 40;
	return 1;
}

function makannasgor(playerid)
{
	Inventory_Remove(playerid, "Nasi Goreng", 1);
	TogglePlayerControllable(playerid, 1);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pHunger] += 60;
	return 1;
}

function minummilk(playerid)
{
	Inventory_Remove(playerid, "Milk", 1);
	TogglePlayerControllable(playerid, 1);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pEnergy] += 20;
	return 1;
}

function minumbeer1(playerid)
{
	Inventory_Remove(playerid, "Wine", 1);
	TogglePlayerControllable(playerid, 1);
	SetPlayerDrunkLevel(playerid, 2500);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pEnergy] += 10;
	pData[playerid][pHunger] -= 5;
	return 1;
}

function minumbeer2(playerid)
{
	Inventory_Remove(playerid, "Whiskey", 1);
	TogglePlayerControllable(playerid, 1);
	SetPlayerDrunkLevel(playerid, 2500);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pEnergy] += 10;
	pData[playerid][pHunger] -= 5;
	return 1;
}

function minumbeer3(playerid)
{
	Inventory_Remove(playerid, "Vodka", 1);
	TogglePlayerControllable(playerid, 1);
	SetPlayerDrunkLevel(playerid, 2500);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pEnergy] += 10;
	pData[playerid][pHunger] -= 5;
	return 1;
}
function minumbeer4(playerid)
{
	Inventory_Remove(playerid, "Blue Moon", 1);
	TogglePlayerControllable(playerid, 1);
	SetPlayerDrunkLevel(playerid, 2500);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pEnergy] += 10;
	pData[playerid][pHunger] -= 5;
	return 1;
}

function makansteak(playerid)
{
	Inventory_Remove(playerid, "Steak", 1);
	TogglePlayerControllable(playerid, 1);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pHunger] += 50;
	return 1;
}

function makanroti(playerid)
{
	Inventory_Remove(playerid, "Roti", 1);
	TogglePlayerControllable(playerid, 1);
	Inventory_Add(playerid, "Sampah", 2840, 1);
	pData[playerid][pHunger] += 40;
	return 1;
}

stock SQL_Escape(const string[])
{
    new escaped[128];
    new i = 0, j = 0;
    while (string[i] != '\0' && j < sizeof(escaped) - 1)
    {
        if (string[i] != '\'' && string[i] != '\"' && string[i] != ',') 
        {
            escaped[j++] = string[i];
        }
        i++;
    }
    escaped[j] = '\0'; 
    return escaped;
}
