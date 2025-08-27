#include <map-zones>

//Player Update Time
task onlineTimer[1000]()
{	
	// Increase server uptime
	new time[3];
	gettime(time[0], time[1], time[2]);
	up_seconds ++;
	if(up_seconds == 60)
	{
	    up_seconds = 0, up_minutes ++;
	    if(up_minutes == 60)
	    {
	        up_minutes = 0, up_hours ++;
	        if(up_hours == 24) up_hours = 0, up_days ++;

			// Random Signal Status Error
			foreach(new sgid: Signal)
			{
				if(Iter_Contains(Signal, sgid) && Iter_Random(Signal))
				{
					sgData[sgid][sgSeconds] = 60 * 20;
					sgData[sgid][sgStatus] = 1;
					Signal_Save(sgid);
					Signal_Refresh(sgid);
				}
			}
			new rand = RandomEx(0, 22);
			SetWorldTime(time[0]);
			SetWeather(rand);
		}
	}
	foreach(new hid : Houses)
	{
		if(Iter_Contains(Houses, hid))
		{
			if(strcmp(hData[hid][hOwner], "-"))
			{
				if(hData[hid][hVisit] != 0 && hData[hid][hVisit] <= gettime())
				{
					HouseReset(hid);
					House_Save(hid);
				}
			}
		}
	}
	foreach(new venid : Vending)
	{
		if(Iter_Contains(Vending, venid))
		{
			if(strcmp(vmData[venid][venOwner], "-"))
			{
				if(vmData[venid][venVisit] != 0 && vmData[venid][venVisit] <= gettime())
				{
					Vending_Reset(venid);
					Vending_Save(venid);
				}
			}
		}
	}
	foreach(new drid : Dealer)
	{
		if(Iter_Contains(Dealer, drid))
		{
			if(strcmp(drData[drid][dOwner], "-"))
			{
				if(drData[drid][dVisit] != 0 && drData[drid][dVisit] <= gettime())
				{
					Dealer_Reset(drid);
					Dealer_Save(drid);
				}
			}
		}
	}
	return 1;
}

ptask PlayerUpdate[1000](playerid)
{
    if(pData[playerid][IsLoggedIn] == false) return 0;
	if(pData[playerid][pSpawned] == 0) return 0;
    {
		// Online Timer
		if(pData[playerid][IsLoggedIn] == true)
		{
			pData[playerid][pPaycheck] ++;
			pData[playerid][pSeconds] ++, pData[playerid][pCurrSeconds] ++;
			if(pData[playerid][pSpaTime] > 0)
			{
				pData[playerid][pSpaTime]--;
			}
			if(pData[playerid][pOnDuty] >= 1)
			{
				pData[playerid][pOnDutyTime]++;
			}
			if(pData[playerid][pSeconds] == 60)
			{
				new scoremath = ((pData[playerid][pLevel])*5);

		    	pData[playerid][pMinutes]++, pData[playerid][pCurrMinutes] ++;
		    	pData[playerid][pSeconds] = 0, pData[playerid][pCurrSeconds] = 0;
				
				switch(pData[playerid][pMinutes])
				{
					case 20:
					{
						if(pData[playerid][pBooster] == 1)
						{
							AddPlayerSalary(playerid, "Bonus Boost ( RP Booster )", 500);
						}
						Servers(playerid, "Gunakan "YELLOW_E"'/help'"WHITE_E" untuk melihat command");
						Info(playerid, "Jika anda sekarat dan tidak ada medis gunakan {FFFF00}/medic");
					}
				    case 40:
		            {
						if(pData[playerid][pBooster] == 1)
						{
							pData[playerid][pPaycheck] = 3601;
						}
						if(pData[playerid][pPaycheck] >= 3600)
						{
							Info(playerid, "Waktunya mengambil paycheck!");
							Servers(playerid, "silahkan pergi ke bank atau ATM terdekat untuk mengambil paycheck.");
							PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
						}
						Info(playerid, "Gunakan Telepon anda untuk menghubungi Instansi");
					}
					case 60:
					{
						if(pData[playerid][pPaycheck] >= 3600)
						{
							Info(playerid, "Waktunya mengambil paycheck!");
							Servers(playerid, "silahkan pergi ke bank atau ATM terdekat untuk mengambil paycheck.");
							PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
						}
						
						pData[playerid][pHours] ++;
						pData[playerid][pLevelUp] += 1;
						pData[playerid][pMinutes] = 0;
						UpdatePlayerData(playerid);
			            
						if(pData[playerid][pLevelUp] >= scoremath)
						{
							new mstr[128];
							pData[playerid][pLevel] += 1;
							pData[playerid][pHours] ++;
							SetPlayerScore(playerid, pData[playerid][pLevel]);
							format(mstr,sizeof(mstr),"~g~Level Up!~n~~w~Sekarang anda level ~r~%d", pData[playerid][pLevel]);
							InfoTD_MSG(playerid, 6000, mstr);
						}
					}
				}
				if(pData[playerid][pCurrMinutes] == 60)
				{
				    pData[playerid][pCurrMinutes] = 0;
				    pData[playerid][pCurrHours] ++;
				}
			}
   		}
		
		// Booster Expired Checking
		if(pData[playerid][pBooster] > 0)
		{
			if(pData[playerid][pBoostTime] != 0 && pData[playerid][pBoostTime] <= gettime())
			{
				Info(playerid, "Maaf, Booster player anda sudah habis! sekarang anda adalah player biasa!");
				pData[playerid][pBooster] = 0;
				pData[playerid][pBoostTime] = 0;
			}
		}
		//VIP Expired Checking
		if(pData[playerid][pVip] > 0)
		{
			if(pData[playerid][pVipTime] != 0 && pData[playerid][pVipTime] <= gettime())
			{
				Info(playerid, "Maaf, Level VIP player anda sudah habis! sekarang anda adalah player biasa!");
				pData[playerid][pVip] = 0;
				pData[playerid][pVipTime] = 0;
			}
		}
		//ID Card Expired Checking
		if(pData[playerid][pIDCard] > 0)
		{
			if(pData[playerid][pIDCardTime] != 0 && pData[playerid][pIDCardTime] <= gettime())
			{
				Info(playerid, "Masa berlaku ID Card anda telah habis, silahkan perpanjang kembali!");
				pData[playerid][pIDCard] = 0;
				pData[playerid][pIDCardTime] = 0;
			}
		}
		//Weapon License Expired
		if(pData[playerid][pWeapLic] > 0)
		{
			if(pData[playerid][pWeapLicTime] != 0 && pData[playerid][pWeapLicTime] <= gettime())
			{
				Info(playerid, "Masa berlaku Weapon License anda telah habis, silahkan perpanjang kembali!");
				pData[playerid][pWeapLic] = 0;
				pData[playerid][pWeapLicTime] = 0;
			}
		}
		//Robbing Expired
		if(pData[playerid][pRobbing] > 0)
		{
			if(pData[playerid][pRobbingTime] != 0 && pData[playerid][pRobbingTime] <= gettime())
			{
				Info(playerid, "Robbing time anda telah selesai, kamu bisa melakukan perampokan kembali!");
				pData[playerid][pRobbing] = 0;
				pData[playerid][pRobbingTime] = 0;
			}
		}
		//Lumber License
		if(pData[playerid][pLumberLic] > 0)
		{
			if(pData[playerid][pLumberLicTime] != 0 && pData[playerid][pLumberLicTime] <= gettime())
			{
				Info(playerid, "Masa berlaku Lumber License anda telah habis, silahkan perpanjang kembali!");
				pData[playerid][pLumberLic] = 0;
				pData[playerid][pLumberLicTime] = 0;
			}
		}
		//Trucker License
		if(pData[playerid][pTruckLic] > 0)
		{
			if(pData[playerid][pTruckLicTime] != 0 && pData[playerid][pTruckLicTime] <= gettime())
			{
				Info(playerid, "Masa berlaku Truck License anda telah habis, silahkan perpanjang kembali!");
				pData[playerid][pTruckLic] = 0;
				pData[playerid][pTruckLicTime] = 0;
			}
		}

		if(pData[playerid][pExitJob] != 0 && pData[playerid][pExitJob] <= gettime())
		{
			Info(playerid, "Now you can exit from your current job!");
			pData[playerid][pExitJob] = 0;
		}
		if(pData[playerid][pDriveLic] > 0)
		{
			if(pData[playerid][pDriveLicTime] != 0 && pData[playerid][pDriveLicTime] <= gettime())
			{
				Info(playerid, "Masa berlaku Driving anda telah habis, silahkan perpanjang kembali!");
				pData[playerid][pDriveLic] = 0;
				pData[playerid][pDriveLicTime] = 0;
			}
		}
		//Player JobTime Delay
		if(pData[playerid][pJobTime] > 0)
		{
			pData[playerid][pJobTime]--;
		}
		if(pData[playerid][pSideJobTime] > 0)
		{
			pData[playerid][pSideJobTime]--;
		}
		// Duty Delay
		if(pData[playerid][pDutyHour] > 0)
		{
			pData[playerid][pDutyHour]--;
		}
		// Rob Delay
		if(pData[playerid][pRobTime] > 0)
		{
			pData[playerid][pRobTime]--;
		}
		// Get Loc timer
		if(pData[playerid][pSuspectTimer] > 0)
		{
			pData[playerid][pSuspectTimer]--;
		}
		// Speedcam Timer
		if(pData[playerid][TimerSpeedcam] > 0)
		{
			pData[playerid][TimerSpeedcam]--;
		}
		//Warn Player Check
		if(pData[playerid][pWarn] >= 20)
		{
			new ban_time = gettime() + (5 * 86400), query[512], PlayerIP[16], giveplayer[24];
			GetPlayerIp(playerid, PlayerIP, sizeof(PlayerIP));
			GetPlayerName(playerid, giveplayer, sizeof(giveplayer));
			pData[playerid][pWarn] = 0;
			//SetPlayerPosition(ii, 227.46, 110.0, 999.02, 360.0000, 10);
			BanPlayerMSG(playerid, playerid, "20 Total Warning", true);
			SendClientMessageToAllEx(COLOR_RED, "Server: "GREY2_E"Player %s(%d) telah otomatis dibanned permanent dari server. [Reason: 20 Total Warning]", giveplayer, playerid);
			
			mysql_format(g_SQL, query, sizeof(query), "INSERT INTO banneds(name, ip, admin, reason, ban_date, ban_expire) VALUES ('%s', '%s', 'Server Ban', '20 Total Warning', %i, %d)", giveplayer, PlayerIP, gettime(), ban_time);
			mysql_tquery(g_SQL, query);
			KickEx(playerid);
		}
		//Farmer
		if(pData[playerid][pPlant] >= 20)
		{
			pData[playerid][pPlant] = 0;
			pData[playerid][pPlantTime] = 600;
		}
		if(pData[playerid][pPlantTime] > 0)
		{
			pData[playerid][pPlantTime]--;
			if(pData[playerid][pPlantTime] < 1)
			{
				pData[playerid][pPlantTime] = 0;
				pData[playerid][pPlant] = 0;
			}
		}
		new pid = GetClosestPlant(playerid);
		if(pid != -1)
		{
			if(IsPlayerInDynamicCP(playerid, PlantData[pid][PlantCP]) && pid != -1)
			{
				new type[24], mstr[128];
				if(PlantData[pid][PlantType] == 1)
				{
					type = "Potato";
				}
				else if(PlantData[pid][PlantType] == 2)
				{
					type = "Wheat";
				}
				else if(PlantData[pid][PlantType] == 3)
				{
					type = "Orange";
				}
				else if(PlantData[pid][PlantType] == 4)
				{
					type = "Marijuana";
				}
				if(PlantData[pid][PlantTime] > 1)
				{
					format(mstr, sizeof(mstr), "~w~Plant Type: ~g~%s ~n~~w~Plant Time: ~r~%s", type, ConvertToMinutes(PlantData[pid][PlantTime]));
					InfoTD_MSG(playerid, 6000, mstr);
				}
				else
				{
					format(mstr, sizeof(mstr), "~w~Plant Type: ~g~%s ~n~~w~Plant Time: ~g~Now", type);
					InfoTD_MSG(playerid, 6000, mstr);
				}
			}
		}
		if(GetPlayerScore(playerid) < 3)//artinya kalau level dibawah 2 bakalan ke kick terkena anti cheat weapon hack
 		{
			if(GetPlayerWeapon(playerid) == 10)//id 25 sama dengan senjata shotgun
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 11)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 12)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 13)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 14)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 15)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 16)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
        	if(GetPlayerWeapon(playerid) == 17)//id 38 sama dengan senjata minigun
			{	
				ResetPlayerWeaponsEx(playerid); 
		   		Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 18)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 19)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 20)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 21)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 22)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 23)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 24)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 25)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 26)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 27)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 28)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 29)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 30)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 32)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 32)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 33)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 34)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 35)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 36)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 37)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 38)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 39)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
			if(GetPlayerWeapon(playerid) == 40)
			{
				ResetPlayerWeaponsEx(playerid);   
		    	Kick(playerid);
			}
		}
	}
    return 1;
}

ptask EnergyUpdate[80000](playerid)
{	
	if(pData[playerid][IsLoggedIn] == false) return 0;
	if(pData[playerid][pSpawned] == 0) return 0;
	if(!pData[playerid][pAdminDuty])
	{
		if(pData[playerid][pHunger] > 0)
		{
		    pData[playerid][pHunger] --;
		}
		if(pData[playerid][pEnergy] > 0)
		{
			pData[playerid][pEnergy] --;
		}
		if(pData[playerid][pHunger] <= 0)
		{
			pData[playerid][pSick] = 1;
			pData[playerid][pHunger] = 0;
		}
		if(pData[playerid][pEnergy] <= 0)
		{
			pData[playerid][pSick] = 1;
			pData[playerid][pEnergy] = 0;
		}
	}
	return 1;
}

ptask playerTimer[1000](playerid)
{
	if(pData[playerid][IsLoggedIn] == false) return 0;
	if(pData[playerid][pSpawned] == 0) return 0;
	//Anti-Cheat Vehicle health hack
	for(new v, j = GetVehiclePoolSize(); v <= j; v++) if(GetVehicleModel(v))
    {
        new Float:health;
        GetVehicleHealth(v, health);
        if( (health > VehicleHealthSecurityData[v]) && VehicleHealthSecurity[v] == false)
        {
			if(GetPlayerVehicleID(playerid) == v)
			{
				new playerState = GetPlayerState(playerid);
				if(playerState == PLAYER_STATE_DRIVER)
				{
					SetValidVehicleHealth(v, VehicleHealthSecurityData[v]);
					SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {FFFFFF}%s telah di kick otomatis oleh {00A2FF}LOCALPRIME-BOT", pData[playerid][pName]);
					SendClientMessageToAllEx(-1, "~> {FF0000}Vehicle Health Hack");
					KickEx(playerid);
				}
			}
        }
        if(VehicleHealthSecurity[v] == true)
        {
            VehicleHealthSecurity[v] = false;
        }
        VehicleHealthSecurityData[v] = health;
    }
    if(pData[playerid][pOnDuty] >= 1)
	{
		pData[playerid][pOnDutyTime]++;
	}
	if(pData[playerid][pStress] == 1)
	{
		KillTimer(pData[playerid][pStressTime]);
	}
	//Update healing
	pData[playerid][pStressTime] = SetTimerEx("HealingStress", 25000, true, "d", playerid);
	//SAPD Tazer/Taser
	UpdateTazer(playerid);
	//SAPD Road Spike
	CheckPlayerInSpike(playerid);
	//SPEEDLIMIT
	GetSpeedCam(playerid);
	//speedlimit speed limit
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && LimitSpeed[playerid])
	{
	    new a, b, c;
		GetPlayerKeys(playerid, a, b ,c);
	    if(a == 8 && GetVehicleSpeedLimit(GetPlayerVehicleID(playerid), 0) > LimitSpeed[playerid])
	    {
	        new newspeed = GetVehicleSpeedLimit(GetPlayerVehicleID(playerid), 0) - LimitSpeed[playerid];
	    	ModifyVehicleSpeed(GetPlayerVehicleID(playerid), -newspeed);
	    }
	}
	if(pData[playerid][pLevel] < 1)
	{
		pData[playerid][pInjured] = 0;
	    pData[playerid][pHospital] = 0;
	    pData[playerid][pHunger] = 100;
	    pData[playerid][pEnergy] = 100;
	    pData[playerid][pStress] = 0;
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
    //Speed Hack unyu unyu
    new jembutveh = GetPlayerVehicleID(playerid);
    if(EVF::GetVehicleSpeed(jembutveh) > 220 || GetKecepatanPlayer(playerid) > 220)
    {
        SendClientMessageToAllEx(-1, "{FF3939}AdmCMD: {FFFFFF}%s telah di kick otomatis oleh {00A2FF}LOCALPRIME-BOT", pData[playerid][pName]);
        SendClientMessageToAllEx(-1, "~> {FF0000}Speed Hacks");
        KickEx(playerid);
    }
	//Anti Armour Hacks
	new Float:A;
	GetPlayerArmour(playerid, A);
	if(A > 98)
	{
		SetPlayerArmourEx(playerid, 0);
		SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {FFFFFF}%s telah di kick otomatis oleh {00A2FF}LOCALPRIME-BOT", pData[playerid][pName]);
		SendClientMessageToAllEx(-1, "~> {FF0000}Armor Hack");
		KickEx(playerid);
	}
	//Weapon AC
	if(pData[playerid][pSpawned] == 1)
    {
        if(GetPlayerWeapon(playerid) != pData[playerid][pWeapon])
        {
            pData[playerid][pWeapon] = GetPlayerWeapon(playerid);

            if(pData[playerid][pWeapon] >= 1 && pData[playerid][pWeapon] <= 45 && pData[playerid][pWeapon] != 40 && pData[playerid][pWeapon] != 22 && pData[playerid][pWeapon] != 2 && pData[playerid][pGuns][g_aWeaponSlots[pData[playerid][pWeapon]]] != GetPlayerWeapon(playerid))
            {
            	pData[playerid][pWeaponAC]++;
                SendAdminMessage(-1, "{FFFFFF}%s[%d] terdeteksi menggunakan {FFFF00}'weapon-hack' {FFFFFF}(%s). {FFFF00}'/spec <id>'", pData[playerid][pName], playerid, ReturnWeaponName(pData[playerid][pWeapon]));
                //SendClientMessageToAllEx(COLOR_RED, "BotCmd: %s was kicked by BOT. Reason: used weapon hacks (%s).", pData[playerid][pName], ReturnWeaponName(pData[playerid][pWeapon]));
                SetWeapons(playerid); //Reload old weapons

                if(pData[playerid][pWeaponAC] >= 5)
                {
                	pData[playerid][pWeaponAC] = 0;
                	SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {FFFFFF}%s telah di kick otomatis oleh {00A2FF}LOCALPRIME-BOT", pData[playerid][pName]);
					SendClientMessageToAllEx(-1, "~> {FF0000}Weapon Hack");
					SetWeapons(playerid);
					KickEx(playerid);
                }
            }
        }
    }
	//Weapon Atth
	if(NetStats_GetConnectedTime(playerid) - WeaponTick[playerid] >= 250)
	{
		static weaponid, ammo, objectslot, count, index;
 
		for (new i = 2; i <= 7; i++) //Loop only through the slots that may contain the wearable weapons
		{
			GetPlayerWeaponData(playerid, i, weaponid, ammo);
			index = weaponid - 22;
		   
			if (weaponid && ammo && !WeaponSettings[playerid][index][Hidden] && IsWeaponWearable(weaponid) && EditingWeapon[playerid] != weaponid)
			{
				objectslot = GetWeaponObjectSlot(weaponid);
 
				if (GetPlayerWeapon(playerid) != weaponid)
					SetPlayerAttachedObject(playerid, objectslot, GetWeaponModel(weaponid), WeaponSettings[playerid][index][Bone], WeaponSettings[playerid][index][Position][0], WeaponSettings[playerid][index][Position][1], WeaponSettings[playerid][index][Position][2], WeaponSettings[playerid][index][Position][3], WeaponSettings[playerid][index][Position][4], WeaponSettings[playerid][index][Position][5], 1.0, 1.0, 1.0);
 
				else if (IsPlayerAttachedObjectSlotUsed(playerid, objectslot)) RemovePlayerAttachedObject(playerid, objectslot);
			}
		}
		for (new i = 4; i <= 8; i++) if (IsPlayerAttachedObjectSlotUsed(playerid, i))
		{
			count = 0;
 
			for (new j = 22; j <= 38; j++) if (PlayerHasWeapon(playerid, j) && GetWeaponObjectSlot(j) == i)
				count++;
 
			if(!count) RemovePlayerAttachedObject(playerid, i);
		}
		WeaponTick[playerid] = NetStats_GetConnectedTime(playerid);
	}
	
	//Player Update Online Data
	//GetPlayerHealth(playerid, pData[playerid][pHealth]);
    //GetPlayerArmour(playerid, pData[playerid][pArmour]);
	/*if(pData[playerid][pSpawned] == 1 && pData[playerid][IsLoggedIn] == true)
    {
	    if(pData[playerid][pInjured] == 0 || pData[playerid][pHospital] == 0 || pData[playerid][pJail] == 0)
		{
			if(pData[playerid][pHunger] <= 5 || pData[playerid][pEnergy] <= 5)
			{
				if(pData[playerid][pNerfHP] != 1)
				{
					pData[playerid][pNerfHP] = 1;
					SetTimerEx("NerfHpEnegyHunger", 300000, 0, "i", playerid);
				}
			}
		}
	}*/

	if(pData[playerid][pJail] <= 0)
	{
		if(pData[playerid][pHunger] > 100)
		{
			pData[playerid][pHunger] = 100;
		}
		if(pData[playerid][pHunger] < 0)
		{
			pData[playerid][pHunger] = 0;
		}
		if(pData[playerid][pEnergy] > 100)
		{
			pData[playerid][pEnergy] = 100;
		}
		if(pData[playerid][pEnergy] < 0)
		{
			pData[playerid][pEnergy] = 0;
		}
	}
	
	if(pData[playerid][IsLoggedIn] == true)
	{
/*        PlayerTextDrawSetString(playerid, hbeexp[playerid][34], sprintf("%d", GetPlayerHealth(playerid, pData[playerid][pHealth])));
		PlayerTextDrawSetString(playerid, hbeexp[playerid][35], sprintf("%d", pData[playerid][pArmour]));
		PlayerTextDrawSetString(playerid, hbeexp[playerid][36], sprintf("%d", pData[playerid][pHunger]));
		PlayerTextDrawSetString(playerid, hbeexp[playerid][37], sprintf("%d", pData[playerid][pEnergy]));
		PlayerTextDrawSetString(playerid, hbeexp[playerid][38], sprintf("%d", pData[playerid][pStress]));*/
		
		new AgusSamp[258];
		new Float: HealthPlayer[MAX_PLAYERS], Float:ArmorPlayer[MAX_PLAYERS];
		new Float: healths, Float: armours;

		GetPlayerHealth(playerid, healths);
		GetPlayerArmour(playerid, armours);

		HealthPlayer[playerid] = healths;
		ArmorPlayer[playerid] = armours;

		pData[playerid][pHealth] = healths;
		pData[playerid][pArmour] = armours;

		format(AgusSamp, sizeof(AgusSamp), "%.0f", pData[playerid][pHealth]);
		PlayerTextDrawSetString(playerid, hbeexp[playerid][34], AgusSamp);

		format(AgusSamp, sizeof(AgusSamp), "%.0f", pData[playerid][pArmour]);
		PlayerTextDrawSetString(playerid, hbeexp[playerid][35], AgusSamp);

		format(AgusSamp, sizeof(AgusSamp), "%d", pData[playerid][pHunger]);
		PlayerTextDrawSetString(playerid, hbeexp[playerid][36], AgusSamp);

		format(AgusSamp, sizeof(AgusSamp), "%d", pData[playerid][pEnergy]);
		PlayerTextDrawSetString(playerid, hbeexp[playerid][37], AgusSamp);

		PlayerTextDrawSetString(playerid, hbeexp[playerid][38], sprintf("%d", pData[playerid][pStress]));

	}
	else
	{

	}
	
	if(pData[playerid][pHospital] == 1)
    {
		SetPlayerPosition(playerid, -2177.69, 1931.77, 1192.71, 355.24, 1);

		
		SetPlayerInterior(playerid, 1);
		SetPlayerVirtualWorld(playerid, playerid + 100);

		TogglePlayerControllable(playerid, 0);
		pData[playerid][pInjured] = 0;
		pData[playerid][pHospitalTime]++;
		new mstr[64];
		format(mstr, sizeof(mstr), "~n~~n~~n~~w~Recovering... %d", 15 - pData[playerid][pHospitalTime]);
		InfoMsg(playerid, mstr);

		ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
		ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
        if(pData[playerid][pHospitalTime] >= 15)
        {
            pData[playerid][pHospitalTime] = 0;
            pData[playerid][pHospital] = 0;
			pData[playerid][pHunger] = 50;
			pData[playerid][pEnergy] = 50;
			SetPlayerHealthEx(playerid, 50);
			pData[playerid][pSick] = 0;
			GivePlayerMoneyEx(playerid, -500);
			SetPlayerHealthEx(playerid, 70);
			ResetPlayerWeaponsEx(playerid);
			HideTDdeath(playerid);
			Toggleaccdeath[playerid] = 0;

            for (new i; i < 20; i++)
            {
                SendClientMessage(playerid, -1, "");
            }

			SendClientMessage(playerid, COLOR_GREY, "--------------------------------------------------------------------------------------------------------");
            SendClientMessage(playerid, COLOR_WHITE, "Kamu telah keluar dari rumah sakit, kamu membayar $500 kerumah sakit.");
            SendClientMessage(playerid, COLOR_GREY, "--------------------------------------------------------------------------------------------------------");
			
			SetPlayerPosition(playerid, -2177.69, 1931.77, 1192.71, 355.24, 1);

            TogglePlayerControllable(playerid, 1);
            SetCameraBehindPlayer(playerid);

            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 4);
			clearAnimations(playerid);
			pData[playerid][pSpawned] = 1;
			SetPVarInt(playerid, "GiveUptime", -1);
		}
    }
	if(pData[playerid][pInjured] == 1 && pData[playerid][pHospital] != 1)
    {
		ShowTDdeath(playerid);

		if(GetPVarInt(playerid, "GiveUptime") == -1)
		{
			SetPVarInt(playerid, "GiveUptime", gettime());
		}
		
		if(GetPVarInt(playerid,"GiveUptime"))
        {
            if((gettime()-GetPVarInt(playerid, "GiveUptime")) > 900)
            {
                Info(playerid, "Anda mengalami koma, gunakan {FFFF00}'/death' {FFFFFF}untuk spawn");
                SetPVarInt(playerid, "GiveUptime", 0);
            }
        }
		
        ApplyAnimation(playerid, "CRACK", "null", 4.0, 0, 0, 0, 1, 0, 1);
        ApplyAnimation(playerid, "CRACK", "crckdeth4", 4.0, 0, 0, 0, 1, 0, 1);
        SetPlayerHealthEx(playerid, 100);
    }
	if(pData[playerid][pInjured] == 0 && pData[playerid][pGender] != 0) //Pengurangan Data
	{
		if(++ pData[playerid][pHungerTime] >= 120)
		{
			if(pData[playerid][pHunger] > 0)
			{
				pData[playerid][pHunger]--;
			}
			else if(pData[playerid][pHunger] <= 0)
			{
				new Float:hp;
				GetPlayerHealth(playerid, hp);
				SetPlayerHealth(playerid, hp - 5);
				Info(playerid, "Sepertinya anda kelaparan, segeralah pergi ke cafe atau market terdekat untuk mendapatkan makanan");
				return 1;
			}
			pData[playerid][pHungerTime] = 0;
		}
		if(++ pData[playerid][pEnergyTime] >= 120)
		{
			if(pData[playerid][pEnergy] > 0)
			{
				pData[playerid][pEnergy]--;
			}
			else if(pData[playerid][pEnergy] <= 0)
			{
				new Float:hp;
				GetPlayerHealth(playerid, hp);
				SetPlayerHealth(playerid, hp - 5);
				Info(playerid, "Sepertinya anda kehausan, segeralah pergi ke cafe atau market terdekat untuk mendapatkan minuman");
				return 1;
			}
			pData[playerid][pEnergyTime] = 0;
		}
		/*if(pData[playerid][pSick] == 1)
		{
			if(++ pData[playerid][pSickTime] >= 200)
			{
				if(pData[playerid][pSick] >= 1)
				{
					new Float:hp;
					GetPlayerHealth(playerid, hp);
					SetPlayerHealthEx(playerid, hp - 3);
					SetPlayerDrunkLevel(playerid, 8000);
					ApplyAnimation(playerid,"CRACK","crckdeth2",4.1,0,1,1,1,1,1);
					Info(playerid, "Sepertinya anda sakit, segeralah pergi ke dokter/gunakan medicine agar darahmu tidak berkurang.");
					pData[playerid][pSickTime] = 0;
				}
			}
		}*/
	}
	
	//Jail Player
	if(pData[playerid][pJail] > 0)
	{
		if(pData[playerid][pJailTime] > 0)
		{
			pData[playerid][pJailTime]--;
			new hours, seconds, minutes;
			GetElapsedTime(pData[playerid][pJailTime], hours, minutes, seconds);
			new mstr[128];
			format(mstr, sizeof(mstr), "Time: %d detik", pData[playerid][pJailTime]);
			PlayerTextDrawShow(playerid, Time[playerid][0]);			
			PlayerTextDrawSetString(playerid, Time[playerid][0], mstr);
			//InfoTD_MSG(playerid, 1000, mstr);
		}
		else
		{
			pData[playerid][pJail] = 0;
			pData[playerid][pJailTime] = 0;
			//SpawnPlayer(playerid);
			SetPlayerPositionEx(playerid, 2519.7756, -1498.6208, 24.0000, 180.1557, 2000);
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			SendClientMessageToAllEx(-1, "{00A2FF}SERVER: {FFFFFF}%s {7D7D7D}telah terbebas dari penjara oleh server.", pData[playerid][pName]);
			PlayerTextDrawHide(playerid, Time[playerid][0]);
		}
	}
	//Rehab Player
	if(pData[playerid][pRehab] > 0)
	{
		if(pData[playerid][pRehabTime] > 0)
		{
			pData[playerid][pRehabTime]--;
			new mstr[128];
			format(mstr, sizeof(mstr), "Time: %d detik", pData[playerid][pRehabTime]);
			PlayerTextDrawShow(playerid, Time[playerid][0]);			
			PlayerTextDrawSetString(playerid, Time[playerid][0], mstr);
		}
		else
		{
			pData[playerid][pUseDrug] = 0;
			pData[playerid][pRehab] = 0;
			pData[playerid][pRehabTime] = 0;
			//SpawnPlayer(playerid);
			SetPlayerPositionEx(playerid, 2519.7756, -1498.6208, 24.0000, 180.1557, 2000);
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			Info(playerid, "You have been released from the rehabilitation period");
			PlayerTextDrawHide(playerid, Time[playerid][0]);
		}
	}
	//Arreset Player
	if(pData[playerid][pArrest] > 0)
	{
		if(pData[playerid][pArrestTime] > 0)
		{
			pData[playerid][pArrestTime]--;
			new mstr[128];
			format(mstr, sizeof(mstr), "Time: %d detik", pData[playerid][pArrestTime]);
			PlayerTextDrawShow(playerid, Time[playerid][0]);			
			PlayerTextDrawSetString(playerid, Time[playerid][0], mstr);
		}
		else
		{
			pData[playerid][pArrest] = 0;
			pData[playerid][pArrestTime] = 0;
			//SpawnPlayer(playerid);
			SetPlayerPositionEx(playerid, 1097.26, -1665.73, 15.03, 180.1557, 2000);
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			InfoMsg(playerid, "Anda telah terbebas dari penjara");
			PlayerTextDrawHide(playerid, Time[playerid][0]);
		}
	}
	//JOB BUS
	new vehid = GetPlayerVehicleID(playerid);
	if(IsABusVeh(vehid) && pData[playerid][pBuswaiting] == true)
	{
		if(pData[playerid][pBustime] > 0)
		{
			pData[playerid][pBustime]--;
			new mstr[50];
			format(mstr, sizeof(mstr), "Mohon tunggu selama %s detik lagi", ConvertToMinutes(pData[playerid][pBustime]));
			InfoMsg(playerid, mstr);
			PlayerPlaySound(playerid, 43000, 0.0, 0.0, 0.0);		
		}
		else if(pData[playerid][pBustime] < 1)
		{
			if(IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket9))
			{
				pData[playerid][pBuswaiting] = false;
				pData[playerid][pBustime] = 0;
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, buspointmarket10, 7.0);
			}
			else if(IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket16))
			{
				pData[playerid][pBuswaiting] = false;
				pData[playerid][pBustime] = 0;
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, buspointmarket17, 7.0);
			}
			else if(IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket24))
			{
				pData[playerid][pBuswaiting] = false;
				pData[playerid][pBustime] = 0;
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, buspointmarket25, 7.0);
			}
			else if(IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket29))
			{
				pData[playerid][pBuswaiting] = false;
				pData[playerid][pBustime] = 0;
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, buspointmarket30, 7.0);
			}
			else if(IsPlayerInRangeOfPoint(playerid, 7.0,buspointmarket33))
			{
				pData[playerid][pBuswaiting] = false;
				pData[playerid][pBustime] = 0;
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, buspointmarket34, 7.0);
			}
			else if(IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor7))
			{
				pData[playerid][pBuswaiting] = false;
				pData[playerid][pBustime] = 0;
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, buspointelcor8, 7.0);
			}
			else if(IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor10))
			{
				pData[playerid][pBuswaiting] = false;
				pData[playerid][pBustime] = 0;
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, buspointelcor11, 7.0);
			}
			else if(IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor15))
			{
				pData[playerid][pBuswaiting] = false;
				pData[playerid][pBustime] = 0;
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, buspointelcor16, 7.0);
			}
			else if(IsPlayerInRangeOfPoint(playerid, 7.0,buspointelcor21))
			{
				pData[playerid][pBuswaiting] = false;
				pData[playerid][pBustime] = 0;
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, buspointelcor22, 7.0);
			}
		}
	}
	return 1;
}

ptask PlayerVehicleUpdate[200](playerid)
{
	if(pData[playerid][pSpawned] == 0) return 0;
	new vehicleid = GetPlayerVehicleID(playerid);
	if(IsValidVehicle(vehicleid))
	{
		if(!GetEngineStatus(vehicleid) && IsEngineVehicle(vehicleid))
		{	
			SwitchVehicleEngine(vehicleid, false);
		}
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			new Float:fHealth;
			GetVehicleHealth(vehicleid, fHealth);
			if(IsValidVehicle(vehicleid) && fHealth <= 350.0)
			{
				SetValidVehicleHealth(vehicleid, 300.0);
				SwitchVehicleEngine(vehicleid, false);
				InfoTD_MSG(playerid, 6000, "~r~Totalled!");
			}
		}
		if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			new tstr[100];

			format(tstr, sizeof(tstr), "%.0f", EVF::GetVehicleSpeed(vehicleid));
			PlayerTextDrawSetString(playerid, SpeedoPakCik[playerid][3], tstr);
			//TextDrawSetString(NSpeedo[1], tstr);

			PlayerTextDrawTextSize(playerid, SpeedoPakCik[playerid][16], vCore[vehicleid][vFuel] * (3.049/100), -22.000);
			PlayerTextDrawShow(playerid, SpeedoPakCik[playerid][16]);
		}
	}
	return 1;
}

task VehicleUpdate[50000]()
{
    static time_now;
    time_now = gettime(); // Simpan waktu sekarang agar tidak dipanggil berulang

    // Loop untuk kendaraan umum
    foreach (new i : Vehicle)
    {
        if (!IsEngineVehicle(i) || !GetEngineStatus(i))
            continue; // Skip kendaraan yang tidak memiliki mesin atau mati

        new driver = GetVehicleDriver(i);

        if (vCore[i][vFuel] > 100)
            vCore[i][vFuel] = 100;

        if (vCore[i][vFuel] > 0)
        {
            vCore[i][vFuel]--;

            if (vCore[i][vFuel] <= 10)
            {
                Info(driver, "Bensin kendaraan anda akan habis, pergilah ke Pom Bensin terdekat.");
            }
        }
        else
        {
            vCore[i][vFuel] = 0;
            InfoTD_MSG(driver, 3000, "Vehicle out of ~r~Fuel!");
            SwitchVehicleEngine(i, false);
        }
    }

    // Loop untuk kendaraan pribadi
    foreach (new ii : PVehicles)
    {
        if (!IsValidVehicle(pvData[ii][cVeh]))
            continue; // Skip kendaraan yang tidak valid

        // Update plat kendaraan
        if (pvData[ii][cPlateTime] > 0 && pvData[ii][cPlateTime] <= time_now)
        {
            format(pvData[ii][cPlate], 32, "None");
            SetVehicleNumberPlate(pvData[ii][cVeh], pvData[ii][cPlate]);
            pvData[ii][cPlateTime] = 0;
        }

        // Kendaraan sewa yang sudah habis waktunya
        if (pvData[ii][cRent] > 0 && pvData[ii][cRent] <= time_now)
        {
            pvData[ii][cRent] = 0;

            new query[128];
            mysql_format(g_SQL, query, sizeof(query), "DELETE FROM vehicle WHERE id = '%d'", pvData[ii][cID]);
            mysql_tquery(g_SQL, query);

            MySQL_ResetVehicleToys(ii);

            if (IsValidVehicle(pvData[ii][cVeh]))
                DestroyVehicle(pvData[ii][cVeh]);

            pvData[ii][cVeh] = 0;
            Iter_Remove(PVehicles, ii);
        }

        // Reset waktu klaim kendaraan jika sudah habis
        if (pvData[ii][cClaimTime] > 0 && pvData[ii][cClaimTime] <= time_now)
        {
            pvData[ii][cClaimTime] = 0;
        }
    }
}

/*ptask LocationUpdt[1000](playerid)
{
	if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 0;
	new MapZone:zone = GetPlayerMapZone(playerid);
    new name[MAX_MAP_ZONE_NAME];
    GetMapZoneName(zone, name);
    new string[128];
    format(string, sizeof(string), "%s", name);
    PlayerTextDrawSetString(playerid, NSpeedo[playerid][5], string);
	return 1;
}*/
