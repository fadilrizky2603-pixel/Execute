ptask PlayerUpdate[1000](playerid)
{
	if (AccountData[playerid][IsLoggedIn] && AccountData[playerid][pSpawned])
	{
		if(AccountData[playerid][pSpec] != -1)
		{
			new
				targetid = AccountData[playerid][pSpec];
		
			PlayerTextDrawSetString(playerid, SpectatorInfoTD[playerid][1], sprintf("~g~%s_(%d)", ReturnName(targetid), targetid));
			PlayerTextDrawSetString(playerid, SpectatorInfoTD[playerid][2], sprintf("Cash:~y~_%s", FormatMoney(AccountData[targetid][pMoney])));
			PlayerTextDrawSetString(playerid, SpectatorInfoTD[playerid][3], sprintf("HP:~y~_%d.0", GetHealth(targetid)));
			PlayerTextDrawSetString(playerid, SpectatorInfoTD[playerid][4], sprintf("AM:~y~_%d.0", GetArmor(targetid)));
			PlayerTextDrawSetString(playerid, SpectatorInfoTD[playerid][5], sprintf("Int:~y~_%d_~w~WID:~y~_%d", GetPlayerInterior(targetid), GetPlayerVirtualWorld(targetid)));
			PlayerTextDrawSetString(playerid, SpectatorInfoTD[playerid][6], sprintf("Hungry:~y~_%d%%_~w~Thirst:~y~_%d%%", AccountData[targetid][pHunger] , AccountData[targetid][pThirst]));
			PlayerTextDrawSetString(playerid, SpectatorInfoTD[playerid][7], sprintf("FPS:~y~_%d_~w~Ping:~y~_%dms", GetPlayerFPS(targetid), GetPlayerPing(targetid)));
		}
		
		/* Anti Jetpack Hacks */
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK && !AccountData[playerid][pJetpack])
		{
			SendClientMessageToAllEx(X11_ARWIN, "[AdmCmd] "YELLOW"%s(%d)"ARWIN1" telah ditendang dari server karena menggunakan Jetpack Hacks", ReturnName(playerid), playerid);
			KickEx(playerid);
		}
		if ((Anticheat_GetReportAmount(playerid, 6) > 0) && Anticheat_IsReportTimeExpired(playerid, 6))
        {
            Anticheat_ReduceReport(playerid, 6);
            Anticheat_IncreaseReportTime(playerid, 6);
        }
		/* FPS Info */
		if(AccountData[playerid][ToggleFPS])
		{
			PlayerTextDrawSetString(playerid, FPStextdraws[playerid][0], sprintf("~r~FPS:_~w~%d~n~~r~PL:_~w~%.2f", GetPlayerFPS(playerid), GetPlayerPacketLoss(playerid)));
			PlayerTextDrawShow(playerid, FPStextdraws[playerid][0]);
		}

		/* Weapon Attachment */
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
			for (new i = 6; i <= 8; i++) if (IsPlayerAttachedObjectSlotUsed(playerid, i))
			{
				count = 0;

				for (new j = 22; j <= 38; j++) if (PlayerHasWeapon(playerid, j) && GetWeaponObjectSlot(j) == i)
					count++;

				if(!count) RemovePlayerAttachedObject(playerid, i);
			}
			WeaponTick[playerid] = NetStats_GetConnectedTime(playerid);
		}

		/* Anti Money Hack */
		if(GetPlayerMoney(playerid) != AccountData[playerid][pMoney])
		{
			ResetPlayerMoney(playerid);
			GivePlayerMoney(playerid, AccountData[playerid][pMoney]);
		}

		/* Pengurangan Data */
		if(AccountData[playerid][pJail] <= 0) // jika sedang tidak dipenjara admin
		{
			if(AccountData[playerid][pStress] > 100)
			{
				AccountData[playerid][pStress] = 100;
			}
			if(AccountData[playerid][pStress] < 0)
			{
				AccountData[playerid][pStress] = 0;
			}
			if(AccountData[playerid][pHunger] > 100)
			{
				AccountData[playerid][pHunger] = 100;
			}
			if(AccountData[playerid][pHunger] < 0)
			{
				AccountData[playerid][pHunger] = 0;
			}
			if(AccountData[playerid][pThirst] > 100)
			{
				AccountData[playerid][pThirst] = 100;
			}
			if(AccountData[playerid][pThirst] < 0)
			{
				AccountData[playerid][pThirst] = 0;
			}
		}

		/* Textdraw Death */
		if(AccountData[playerid][pInjured])
		{
			if(AccountData[playerid][pInjuredTime] > 0)
			{
				static hours, minutes, seconds;
				GetElapsedTime(AccountData[playerid][pInjuredTime] --, hours, minutes, seconds);
				
				// Split minutes into tens and ones
				new minutes_tens = minutes / 10;
				new minutes_ones = minutes % 10;
				
				// Split seconds into tens and ones
				new seconds_tens = seconds / 10;
				new seconds_ones = seconds % 10;
				
				PlayerTextDrawSetString(playerid, DeathTD[playerid][5], sprintf("%d", minutes_tens)); // menit puluhan
				PlayerTextDrawSetString(playerid, DeathTD[playerid][6], sprintf("%d", minutes_ones)); // menit satuan
				PlayerTextDrawSetString(playerid, DeathTD[playerid][7], sprintf("%d", seconds_tens)); // detik puluhan
				PlayerTextDrawSetString(playerid, DeathTD[playerid][8], sprintf("%d", seconds_ones)); // detik satuan
				
				forex(u, 20)
				{
					PlayerTextDrawShow(playerid, DeathTD[playerid][u]);
				}
				
				ApplyAnimationEx(playerid, "WUZI", "CS_DEAD_GUY", 4.1, 0, 0, 0, 1, 0, 1);
				SetPlayerHealthEx(playerid, 99999);

				if(!AccountData[playerid][pInjuredTime]) 
				{
					SetPlayerHealthEx(playerid, 100.0);
					AccountData[playerid][pHunger] = 100;
					AccountData[playerid][pThirst] = 100;
					AccountData[playerid][pStress] = 0;
					AccountData[playerid][pInjured] = 0;
					AccountData[playerid][pInjuredTime] = 0;
					Inventory_Clear(playerid);
					ResetPlayerWeaponsEx(playerid);

					SendClientMessageEx(playerid, -1, ""YELLOW"[KOMA]: {ffffff}Karakter anda dinyatakan koma dikarenakan kehabisan "RED"darah "WHITE"dan semua "ORANGE"barang "WHITE"dan "GREEN"uangmu "RED"hilang!");

					SetPlayerPositionEx(playerid, 1333.4708,722.0023,11.6093,93.9083, 5000);
					SetPlayerVirtualWorldEx(playerid, 1);
					SetPlayerInteriorEx(playerid, 1);
				}
			}
		}

		/* Pengurangan Data 2 */
		if(AccountData[playerid][pInjured] == 0 && AccountData[playerid][pGender] != 0) 
		{
			HideTdDeath(playerid);
			if(IsAUnstressArea(playerid))
			{
				AccountData[playerid][pStress]--;

				if(AccountData[playerid][pStress] < 95)
				{
					SetPlayerDrunkLevel(playerid, 0);
					TextDrawHideForPlayer(playerid, StressPurple[0]);
				}
			}

			if(AccountData[playerid][pStress] < 99)
			{
				SetPlayerDrunkLevel(playerid, 0);
				TextDrawHideForPlayer(playerid, StressPurple[0]);
			}
			if(++ AccountData[playerid][pStressTime] >= 150)
			{
				if(AccountData[playerid][pInjured] != 1 && !IsPlayerInEvent(playerid))
				{
					AccountData[playerid][pStress]++;

					if(AccountData[playerid][pStress] > 99)
					{
						TextDrawShowForPlayer(playerid, StressPurple[0]);
						SetPlayerDrunkLevel(playerid, 10000);
					}
					/*if(!IsAUnstressArea(playerid))
					{
						AccountData[playerid][pStress]++;

						if(AccountData[playerid][pStress] >= 99)
						{
							TextDrawShowForPlayer(playerid, StressPurple[0]);
							SetPlayerDrunkLevel(playerid, 10000);
						}
					}
					else
					{
						AccountData[playerid][pStress] -= 10;

						if(AccountData[playerid][pStress] < 97)
						{
							SetPlayerDrunkLevel(playerid, 0);
							TextDrawHideForPlayer(playerid, StressPurple[0]);
						}
					}*/
				}
				AccountData[playerid][pStressTime] = 0;
			}
			if(++ AccountData[playerid][pHungerTime] >= 180)
			{
				if(AccountData[playerid][pHunger] > 0 && AccountData[playerid][pInjured] != 1 && !IsPlayerInEvent(playerid))
				{
					AccountData[playerid][pHunger]--;
				}
				else if(AccountData[playerid][pHunger] <= 0 && AccountData[playerid][pInjured] != 1)
				{
					if(IsPlayerInAnyVehicle(playerid))
						RemovePlayerFromVehicle(playerid);
					SetPlayerHealth(playerid, 0.0);
				}
				AccountData[playerid][pHungerTime] = 0;
			}
			if(++ AccountData[playerid][pThirstTime] >= 180)
			{
				if(AccountData[playerid][pThirst] > 0 && AccountData[playerid][pInjured] != 1 && !IsPlayerInEvent(playerid))
				{
					AccountData[playerid][pThirst]--;
				}
				else if(AccountData[playerid][pThirst] <= 0 && AccountData[playerid][pInjured] != 1)
				{
					if(IsPlayerInAnyVehicle(playerid))
						RemovePlayerFromVehicle(playerid);
					SetPlayerHealth(playerid, 0.0);
				}
				AccountData[playerid][pThirstTime] = 0;
			}
		}

		/* Admin Duty Timer */
		if(AccountData[playerid][pAdminDuty])
		{
			AccountData[playerid][aDutyTimer] ++;
		}

		/* Masker Label Update */
		if(AccountData[playerid][pMaskOn])
		{
			new Float:health, Float:armor;
			GetPlayerHealth(playerid, health);
			GetPlayerArmour(playerid, armor);
			if(IsValidDynamic3DTextLabel(AccountData[playerid][pMaskLabel]))
			{
				UpdateDynamic3DTextLabelText(AccountData[playerid][pMaskLabel], -1, sprintf("Mask #%d\nH: ["RED_E"%.2f"WHITE"] A: [%.2f]", AccountData[playerid][pMaskID], health, armor));
			}
		}

		/* Taser Update */
		if(AccountData[playerid][pStunned] > 0)
		{
			AccountData[playerid][pStunned]--;

			if(GetPlayerAnimationIndex(playerid) != 388)
				ApplyAnimation(playerid, "CRACK", "crckdeth4", 4.0, 0, 0, 0, 1, 0, 1);
			
			if(!AccountData[playerid][pStunned])
			{
				TogglePlayerControllable(playerid, 1);
				ShowPlayerFooter(playerid, "~w~Anda tidak lagi ~r~tersengat");
			}
		}

		switch(AccountData[playerid][pHUDMode])
		{
			case 1: // Kiri
			{
				/* Hbe Bar Update */ 
				new Float:Health, Float:Armour, Float:Hunger, Float:Thirst, Float:Stress;
				// Health and Armor bars move left to right
				Health = GetHealth(playerid) * 30.0/100.0;
				Armour = GetArmor(playerid) * 30.0/100.0;
				
				// Hunger, Thirst and Stress bars move top to bottom (using negative values)
				Hunger = AccountData[playerid][pHunger] * -11.0/100.0;
				Thirst = AccountData[playerid][pThirst] * -11.0/100.0;
				Stress = AccountData[playerid][pStress] * -11.0/100.0;

				// Update health bar (red) - horizontal movement
				PlayerTextDrawTextSize(playerid, JadenHbe[playerid][20], Health, -11.0);
				PlayerTextDrawShow(playerid, JadenHbe[playerid][20]);

				// Update armor bar (green) - horizontal movement
				PlayerTextDrawTextSize(playerid, JadenHbe[playerid][21], Armour, -11.0);
				PlayerTextDrawShow(playerid, JadenHbe[playerid][21]);

				// Update hunger bar (orange) - vertical movement
				PlayerTextDrawTextSize(playerid, JadenHbe[playerid][22], 10.0, Hunger);
				PlayerTextDrawShow(playerid, JadenHbe[playerid][22]);

				// Update thirst bar (blue) - vertical movement
				PlayerTextDrawTextSize(playerid, JadenHbe[playerid][23], 10.0, Thirst);
				PlayerTextDrawShow(playerid, JadenHbe[playerid][23]);

				// Update stress bar (purple) - vertical movement
				PlayerTextDrawTextSize(playerid, JadenHbe[playerid][24], 10.0, Stress);
				PlayerTextDrawShow(playerid, JadenHbe[playerid][24]);
			}
			case 2: // Tengah
			{
				/* Hbe Bar Update */ 
				new Float:Health, Float:Armour, Float:Hunger, Float:Thirst, Float:Stress;
				
				// Calculate bar sizes based on values (adjusted to stay within boundaries)
				Health = GetHealth(playerid) * 11.0/100.0; // Reduced to 11.0 to stay within boundaries
				Armour = GetArmor(playerid) * 11.0/100.0;
				Hunger = AccountData[playerid][pHunger] * 11.0/100.0;
				Thirst = AccountData[playerid][pThirst] * 11.0/100.0;
				Stress = AccountData[playerid][pStress] * 11.0/100.0;

				// Update health bar (red)
				PlayerTextDrawTextSize(playerid, HbeTengah[playerid][5], Health, 8.000);
				PlayerTextDrawShow(playerid, HbeTengah[playerid][5]);

				// Update hunger bar (orange)
				PlayerTextDrawTextSize(playerid, HbeTengah[playerid][7], Hunger, 8.000);
				PlayerTextDrawShow(playerid, HbeTengah[playerid][7]);

				// Update thirst bar (blue)
				PlayerTextDrawTextSize(playerid, HbeTengah[playerid][16], Thirst, 8.000);
				PlayerTextDrawShow(playerid, HbeTengah[playerid][16]);

				// Update armor bar (green)
				PlayerTextDrawTextSize(playerid, HbeTengah[playerid][11], Armour, 8.000);
				PlayerTextDrawShow(playerid, HbeTengah[playerid][11]);

				// Update stress bar (purple)
				PlayerTextDrawTextSize(playerid, HbeTengah[playerid][10], Stress, 8.000);
				PlayerTextDrawShow(playerid, HbeTengah[playerid][10]);
			}
		}
		
		/* Good Mood Mode */
		if(AccountData[playerid][pGoodMood])
		{
			AccountData[playerid][pHunger] = 100;
			AccountData[playerid][pThirst] = 100;
			AccountData[playerid][pStress] = 0;
		}

		/* Enum Berat */
		if(AccountData[playerid][pBeratItem] <= 0)
		{
			AccountData[playerid][pBeratItem] = 0;
		}
		else if(AccountData[playerid][pBeratItem] > 50)
		{
			AccountData[playerid][pBeratItem] = 50;
		}

		/* Signal EMS */
		if(SignalExists[playerid] && SignalTimer[playerid] > 0)
		{
			SignalTimer[playerid] --;
			if(!SignalTimer[playerid])
			{
				SignalExists[playerid] = false;
				SignalTimer[playerid] = 0;
				SignalPos[playerid][0] = SignalPos[playerid][1] = SignalPos[playerid][2] = 0.0;
				Info(playerid, "Anda sudah dapat mengirim signal kepada EMS kembali!");
			}
		}

		/* Fixme */
		if(FixmeExists[playerid])
		{
			if(FixmeTime[playerid] != 0 && FixmeTime[playerid] <= gettime())
			{
				FixmeExists[playerid] = false;
				FixmeOption[playerid] = 0;
				FixmeTime[playerid] = 0;
				Info(playerid, "Tidak ada yang merespon fixme anda. Anda dapat mengajukannya kembali!");
			}
		}
	}
	return 1;
}

ptask OnlineTimerUpdate[1500](playerid)
{
	if(!AccountData[playerid][pSpawned])
		return 0;

	AccountData[playerid][OnlineTimer] ++;
	return 1;
}

ptask AlertNeeds_Player[180000](playerid)
{
	if(!AccountData[playerid][pSpawned])
		return 0;

	if(AccountData[playerid][pHunger] <= 20) {
		SendClientMessageEx(playerid, -1, ""VERONADOT"Karakter anda merasakan lapar // %d Persen", AccountData[playerid][pHunger]);
	}
	if(AccountData[playerid][pThirst] <= 20) {
		SendClientMessageEx(playerid, -1, ""VERONADOT"Karakter anda merasakan haus // %d Persen", AccountData[playerid][pThirst]);
	}
	if(AccountData[playerid][pStress] >= 90) {
		SendClientMessageEx(playerid, -1, ""VERONADOT"Karakter anda ingin mengalami stress // %d Persen", AccountData[playerid][pStress]);
	}
	return 1;
}

ptask ac_PlayerUpdate[1000](playerid)
{
	if(!AccountData[playerid][pSpawned] || !AccountData[playerid][IsLoggedIn]) 
		return 0;

	if (GetPlayerWeapon(playerid) != AccountData[playerid][pWeapon])
    {
        AccountData[playerid][pWeapon] = GetPlayerWeapon(playerid);

        if (AccountData[playerid][pWeapon] >= 1 && AccountData[playerid][pWeapon] <= 45 && AccountData[playerid][pWeapon] != 40 && AccountData[playerid][pGuns][g_aWeaponSlots[AccountData[playerid][pWeapon]]] != GetPlayerWeapon(playerid) && !DurringHunting[playerid] && !IsPlayerInEvent(playerid) && !PlayerTaserOn[playerid] && !AccountData[playerid][menuShowed])
        {
            printf("[debug] OnPlayerWeaponHack (UCP: %s Name: %s WeaponID: %d Ammo: %d)", AccountData[playerid][pUCP], ReturnPlayerName(playerid), GetPlayerWeapon(playerid), GetPlayerAmmo(playerid));

            SendAdminMessage(X11_RED, "[AntiCheat]: "YELLOW"%s(%d)"LIGHTGREY" terdeteksi menggunakan (Weapon Hacks: {FFFF00}%s"LIGHTGREY")", ReturnName(playerid), playerid, ReturnWeaponName(AccountData[playerid][pWeapon]));
            ResetWeapons(playerid);
            KickEx(playerid);
        }
        else if (AccountData[playerid][pWeapon] >= 1 && AccountData[playerid][pWeapon] <= 45 && AccountData[playerid][pWeapon] == 40 && AccountData[playerid][pGuns][g_aWeaponSlots[AccountData[playerid][pWeapon]]] != GetPlayerWeapon(playerid) && !DurringHunting[playerid] && !IsPlayerInEvent(playerid) && !PlayerTaserOn[playerid] && !AccountData[playerid][menuShowed])
        {
            printf("[debug] OnPlayerCrasher (UCP: %s Name: %s)", AccountData[playerid][pUCP], ReturnPlayerName(playerid));

            SendAdminMessage(X11_RED, "[AntiCheat]: "YELLOW"%s(%d)"LIGHTGREY" telah ditendang dari server karena terdeteksi menggunakan Crasher.luac", ReturnName(playerid), playerid);
            ResetWeapons(playerid);
            KickEx(playerid);
        }
    }
	static Float:AM;
	GetPlayerArmour(playerid, AM);
	if(AccountData[playerid][pAdmin] < 1 && AccountData[playerid][pTheStars] < 1 && AccountData[playerid][pFaction] != FACTION_POLISI && !IsPlayerInEvent(playerid))
	{
		if(AM >= 100)
		{
			SetPlayerArmourEx(playerid, 0);
			SendClientMessageToAllEx(X11_RED, "[AntiCheat]: "YELLOW"[%s] %s (%d)"ARWIN1" terdeteksi menggunakan armour hack "YELLOW"New :[100.0]", AccountData[playerid][pUCP], ReturnName(playerid), playerid);
			KickEx(playerid);
		}
	}
	new Float:H;
	GetPlayerHealth(playerid, H);
	if(AccountData[playerid][pAdmin] < 1 && AccountData[playerid][pTheStars] < 1 && !AccountData[playerid][pInjured] && !IsPlayerInEvent(playerid))
	{
		if(H > 105.0)
		{
			SetPlayerHealthEx(playerid, 100.0);
			SendClientMessage(playerid, -1, "[i] Sistem kami berhasil mengembalikan darah anda tidak lebih dari "YELLOW"100%%");
		}
	}
	return 1;
}

ptask PlayerDragging_Update[1000](playerid)
{
    if (!AccountData[playerid][pSpawned])
        return 0;

    new targetid = IsDragging[playerid];
    if (targetid != INVALID_PLAYER_ID)
    {
        // Mengambil informasi yang sering digunakan
        new playerInterior = GetPlayerInterior(playerid);
        new playerVirtualWorld = GetPlayerVirtualWorld(playerid);

        // Menyalin data bisnis, rumah, dan pintu
        AccountData[targetid][pInBiz] = AccountData[playerid][pInBiz];
        AccountData[targetid][pInHouse] = AccountData[playerid][pInHouse];
        AccountData[targetid][pInDoor] = AccountData[playerid][pInDoor];

        // Mengambil posisi dan sudut pemain
        new Float:X, Float:Y, Float:Z, Float:Ang;
        GetPlayerPos(playerid, X, Y, Z);
        GetPlayerFacingAngle(playerid, Ang);

        // Memindahkan target berdasarkan posisi pemain
        X += (0.75 * -floatsin(-Ang, degrees));
        Y += (0.75 * -floatcos(-Ang, degrees));
        SetPlayerPos(targetid, X, Y, Z);

        // Menyesuaikan interior dan virtual world hanya jika berbeda
        if (GetPlayerInterior(targetid) != playerInterior)
        {
            SetPlayerInterior(targetid, playerInterior);
        }

        if (GetPlayerVirtualWorld(targetid) != playerVirtualWorld)
        {
            SetPlayerVirtualWorld(targetid, playerVirtualWorld);
        }
    }

    return 1;
}


stock PlayerCompassUpdate(playerid, vehid)
{
	static Float:X, Float:Y, Float:Z, Float:Ang;
	GetPlayerPos(playerid, X, Y, Z);

	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		GetVehicleZAngle(vehid, Ang);
	}
	else
	{
		GetPlayerFacingAngle(playerid, Ang);
	}
	return 1;
}

ptask PlayerVehUpdate[1000](playerid)
{
	if(!AccountData[playerid][pSpawned])
		return 0;

    new vehid = GetPlayerVehicleID(playerid);
	if(IsValidVehicle(vehid))
	{
		if(!GetEngineStatus(vehid) && IsEngineVehicle(vehid) && !IsABike(vehid))
		{
			SwitchVehicleEngine(vehid, false);
		}
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			new Float:vHealth;
			GetVehicleHealth(vehid, vHealth);
			if(IsValidVehicle(vehid) && vHealth <= 350.0)
			{
				SwitchVehicleEngine(vehid, false);
				ShowPlayerFooter(playerid, "~w~Engine~r~ Totalled", 2000);
			}
		}
		if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			new str[128];
			new tstr[32];
			new Float:rz;
			new Float:x, Float:y, Float:z;
			new hours, minutes, seconds;
			GetPlayerPos(playerid, x, y, z);
			gettime(hours, minutes, seconds);

			if(IsPlayerInAnyVehicle(playerid)) {
				GetVehicleZAngle(GetPlayerVehicleID(playerid), rz);
			}
			else {
				GetPlayerFacingAngle(playerid, rz);
			}
			
			if(rz >= 348.75 || rz < 11.25) format(tstr, sizeof(tstr), "Utara");
			else if(rz >= 326.25 && rz < 348.75) format(tstr, sizeof(tstr), "Utara");
			else if(rz >= 303.75 && rz < 326.25) format(tstr, sizeof(tstr), "Utara");
			else if(rz >= 281.25 && rz < 303.75) format(tstr, sizeof(tstr), "Timur");
			else if(rz >= 258.75 && rz < 281.25) format(tstr, sizeof(tstr), "Timur");
			else if(rz >= 236.25 && rz < 258.75) format(tstr, sizeof(tstr), "Timur");
			else if(rz >= 213.75 && rz < 236.25) format(tstr, sizeof(tstr), "Selatan");
			else if(rz >= 191.25 && rz < 213.75) format(tstr, sizeof(tstr), "Selatan");
			else if(rz >= 168.75 && rz < 191.25) format(tstr, sizeof(tstr), "Selatan");
			else if(rz >= 146.25 && rz < 168.75) format(tstr, sizeof(tstr), "Selatan");
			else if(rz >= 123.25 && rz < 146.25) format(tstr, sizeof(tstr), "Selatan");
			else if(rz >= 101.25 && rz < 123.25) format(tstr, sizeof(tstr), "Barat");
			else if(rz >= 78.75 && rz < 101.25) format(tstr, sizeof(tstr), "Barat");
			else if(rz >= 56.25 && rz < 78.75) format(tstr, sizeof(tstr), "Barat");
			else if(rz >= 33.75 && rz < 56.25) format(tstr, sizeof(tstr), "Utara");
			else if(rz >= 11.5 && rz < 33.75) format(tstr, sizeof(tstr), "Utara");

			// Update speed display
			format(str, sizeof(str), "%03d", GetVehicleSpeedKMH(vehid));
			PlayerTextDrawSetString(playerid, SpedoJaden[playerid][24], str);
			PlayerTextDrawShow(playerid, SpedoJaden[playerid][24]);

			// Update speed bars (index 1-17)
			new speed = GetVehicleSpeedKMH(vehid);
			new color = 0x1DF0BBFF; // Color for active bars
			
			for(new i = 1; i <= 17; i++)
			{
				if(speed >= (i * 10)) // Each bar represents 10 km/h
				{
					PlayerTextDrawColor(playerid, SpedoJaden[playerid][i], color);
				}
				else
				{
					PlayerTextDrawColor(playerid, SpedoJaden[playerid][i], 100); // Default color
				}
				PlayerTextDrawShow(playerid, SpedoJaden[playerid][i]);
			}

			// Update fuel gauge (index 19)
			new Float:fuel = GetFuel(vehid);
			new Float:fuelBarSize = fuel * -35.0/100.0; // Scale to match the gauge size
			
			// Ensure fuel bar stays within boundaries
			if(fuelBarSize < -35.0) fuelBarSize = -35.0;
			if(fuelBarSize > 0.0) fuelBarSize = 0.0;
			
			PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][19], 1.000, fuelBarSize);
			PlayerTextDrawShow(playerid, SpedoJaden[playerid][19]);

			// Update location and time display (index 6)
			//format(str, sizeof(str), "%s ~r~/~w~/ %s ~r~/~w~/ %02d:%02d", tstr, GetLocation(x, y, z), hours, minutes);
			//PlayerTextDrawSetString(playerid, SpedoJaden[playerid][6], str);
			//PlayerTextDrawShow(playerid, SpedoJaden[playerid][6]);
			
			// Make sure all textdraws are visible
			forex(i, 33)
			{
				PlayerTextDrawShow(playerid, SpedoJaden[playerid][i]);
			}
		}
	}
	return 1;
}

ptask UpTime[60000]()
{
	static h,m,s,lasth;
    gettime(h,m,s);
	if(lasth != h)
	{
		SetWorldTime(h);
		lasth = h;
	}
}

ptask BomBomCarUpdate[1000](playerid)
{
    if(!AccountData[playerid][pSpawned])
        return 0;

    // Check all slots for this player
    for(new slot = 0; slot < 4; slot++)
    {
        if(boomSlot[slot] == playerid && boomTimer[slot] > 0)
        {
            boomTimer[slot]--;
            PlayerTextDrawSetString(playerid, BoomCarTD[playerid][7], sprintf("Waktu bermain anda tersisa ~bl~%d menit %d detik", (boomTimer[slot] / 60), (boomTimer[slot] % 60)));
            PlayerTextDrawShow(playerid, BoomCarTD[playerid][7]);

            if(boomTimer[slot] <= 0)
            {
                boomSlot[slot] = -1;
                boomTimer[slot] = -1;
                forex(i, 9)
                {
                    PlayerTextDrawHide(playerid, BoomCarTD[playerid][i]);
                }
                ShowTDN(playerid, NOTIFICATION_INFO, "Waktu bermain BomBomCar anda telah habis!");
            }
        }
    }
    return 1;
}