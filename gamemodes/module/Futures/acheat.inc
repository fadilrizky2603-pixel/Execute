/* Credits to pottus from 420Dayz*/
#define         NUM_SHOT_CHECK          10
#define         EXCESS_AMOUNT           7

forward OnPlayerExcessAccuracy(playerid, total);

static PlayerTargetShots[MAX_PLAYERS];
static PlayerTargetHits[MAX_PLAYERS];
static LastShots[MAX_PLAYERS][NUM_SHOT_CHECK];
static Currshot[MAX_PLAYERS];
static TotalChecks[MAX_PLAYERS];

#include <YSI_Coding\y_hooks>
hook OnGameModeInitEx()
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
        for(new j = 0; j < NUM_SHOT_CHECK; j++) { LastShots[i][j] = -1; }
	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	// player was targeted
	if(GetPlayerTargetPlayer(playerid) != INVALID_PLAYER_ID)
	{
		// Was a player hit?
		if(hittype == BULLET_HIT_TYPE_PLAYER)
		{
			// No NPCs
			if(!IsPlayerNPC(hitid))
			{
				// Check if player shot is standing still
				new Float:vx, Float:vy, Float:vz;
				GetPlayerVelocity(hitid, vx, vy, vz);

				if(vx != 0.0 || vy != 0.0 || vz != 0.0)
				{
					PlayerTargetShots[playerid]++;
					PlayerTargetHits[playerid]++;
					LastShots[playerid][Currshot[playerid]] = 1;

					new total = CheckLastShots(playerid);

					if(total > 0)
					{
						TotalChecks[playerid]++;
						CallLocalFunction("OnPlayerExcessAccuracy", "ii", playerid, total);
					}

					Currshot[playerid]++;
					if(Currshot[playerid] == NUM_SHOT_CHECK)
					{
						Currshot[playerid] = 0;
						for(new i = 0; i < NUM_SHOT_CHECK; i++) { LastShots[playerid][i] = -1; }
					}
				}
			}
		}
		else
		{
			PlayerTargetShots[playerid]++;
			LastShots[playerid][Currshot[playerid]] = 0;

			new total = CheckLastShots(playerid);

			if(total > 0)
			{
				TotalChecks[playerid]++;
				CallLocalFunction("OnPlayerExcessAccuracy", "ii", playerid, total);
			}
			
			Currshot[playerid]++;
			if(Currshot[playerid] == NUM_SHOT_CHECK)
			{
				Currshot[playerid] = 0;
				for(new i = 0; i < NUM_SHOT_CHECK; i++) { LastShots[playerid][i] = -1; }
			}
		}
	}

	if (funcidx("AntiEA_OnPlayerWeaponShot") != -1)
  	{
    	return CallLocalFunction("AntiEA_OnPlayerWeaponShot", "iiiifff", playerid, weaponid, hittype, hitid, fX, fY, fZ);
  	}
  	return 1;
 }

#if defined _ALS_OnPlayerWeaponShot
	#undef OnPlayerWeaponShot
#else
	#define _ALS_OnPlayerWeaponShot
#endif
#define OnPlayerWeaponShot AntiEA_OnPlayerWeaponShot

forward AntiEA_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);


hook OnPlayerDisconnectEx(playerid)
{
	PlayerTargetShots[playerid] = 0;
	PlayerTargetHits[playerid] = 0;
	Currshot[playerid] = 0;
	TotalChecks[playerid] = 0;
	for(new i = 0; i < NUM_SHOT_CHECK; i++) { LastShots[playerid][i] = -1; }

	return Y_HOOKS_CONTINUE_RETURN_1;
}

GetPlayerShotStats(playerid, &shots, &hits, &Float:accuracy)
{
	if(IsPlayerConnected(playerid))
	{
		shots = PlayerTargetShots[playerid];
	    hits = PlayerTargetHits[playerid];
	    accuracy = floatdiv(float(PlayerTargetHits[playerid]), float(PlayerTargetShots[playerid]));
		return 1;
	}
	return 0;
}

CheckLastShots(playerid)
{
	new count;
	for(new i = 0; i < NUM_SHOT_CHECK; i++)
	{
	    if(LastShots[playerid][i] == -1) return 0;
	    if(LastShots[playerid][i]) count++;
	}

	if(count >= EXCESS_AMOUNT) return count;
	return 0;
}

public OnPlayerExcessAccuracy(playerid, total)
{
	new shots, hits, Float:accuracy;
    GetPlayerShotStats(playerid, shots, hits, accuracy);

	new line[128];
	format(line, sizeof(line), "Aimbot Check: %s(%i) Total Shots: %i Total Hits: %i Accuracy: %.2f (%i/10) Total Checks: %i", ReturnName(playerid), playerid, shots, hits, accuracy, total, TotalChecks[playerid]);

	if(pData[playerid][pAdmin] > 1)
	{
		SendClientMessage(playerid, COLOR_WHITE, line);
	}
	return 1;
}

DEFINE_HOOK_REPLACEMENT( Unoccupied , Uncp );
#include <YSI_Coding\y_timers>
#include <YSI_Coding\y_hooks>

#include <callbacks.inc>

#define CHEAT_TYPES 6

enum
{
	CHEAT_FLY_HACK,
	CHEAT_SPEED_HACK,
	CHEAT_INVISIBLE,
	CHEAT_JETPACK,
	CHEAT_TROLL_1,
	CHEAT_FAKE_KILL_1
};

enum AC_Enums
{
	AC_Warnings[CHEAT_TYPES],
	AC_Kicked,
	Float: AC_POS[3],
	AC_LFWeapon,
	Float: AC_Velocity[3],
	/*AC_EnterVeh,
	AC_EnterVeh_Tick
	AC_VehicleSeat,
	AC_TempOwn*/
};

new 
	AC_VARIABLE[MAX_PLAYERS][AC_Enums];

function cheatDetect(playerid, cheat_id)
{
	if(pData[playerid][pAdmin]) return 0;
	switch(cheat_id)
	{
		case CHEAT_FLY_HACK:
		{
			new 
				playerAnim = GetPlayerAnimationIndex(playerid);

			if(playerAnim == 958 || playerAnim == 1231 || playerAnim == 1189 || playerAnim == 1538 || playerAnim == 1539)
			{
				if(getPlayerSpeed(playerid) > 150 && GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID)
				{
					if(AC_VARIABLE[playerid][AC_Warnings][CHEAT_FLY_HACK] > 4) 
						return OnCheatDetect(playerid, "Fly-Hack #6");

					OnWarningExecute(playerid, CHEAT_FLY_HACK, "Fly-Hack #6");
				}
			}
		}
		case CHEAT_SPEED_HACK:
		{
			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && !IsAPlane(GetPlayerVehicleID(playerid)) && EVF::GetVehicleSpeed(playerid) > 250)
			{
				if(AC_VARIABLE[playerid][AC_Warnings][CHEAT_SPEED_HACK] > 7) 
						return OnCheatDetect(playerid, "Speed-Hack #5");

				OnWarningExecute(playerid, CHEAT_SPEED_HACK, "Speed-Hack #5");
			}
		}
		case CHEAT_INVISIBLE:
		{
			if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING) 
				return OnCheatDetect(playerid, "Invisible/Spectate #4");
		}
		case CHEAT_JETPACK:
		{
			if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK) 
				return OnCheatDetect(playerid, "Jetpack #3");
		}
		case CHEAT_TROLL_1:
		{
			new 
				Float: velX, Float: velY, Float: velZ,
				Float: X, Float: Y, Float: Z;

			GetPlayerPos(playerid, X, Y, Z);

			if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && !IsPlayerInAnyVehicle(playerid))
			{
				if(Z > 5.0000)
				{
					GetPlayerVelocity(playerid, velX, velY, velZ);

					new 
						Float: velXAmount = velX - AC_VARIABLE[playerid][AC_Velocity][0],
						Float: velYAmount = velY - AC_VARIABLE[playerid][AC_Velocity][1];

					if(velXAmount > 3.0 || velXAmount < -4.0 || velYAmount  > 10.0 || velYAmount < -10.0 || velZ == 0.100000) 
						return OnCheatDetect(playerid, "Fake-Kill #1");
				}

				GetPlayerVelocity(playerid, AC_VARIABLE[playerid][AC_Velocity][0], AC_VARIABLE[playerid][AC_Velocity][1], AC_VARIABLE[playerid][AC_Velocity][2]);
			}

			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				GetVehicleVelocity(GetPlayerVehicleID(playerid), velX, velY, velZ);

				if(velY == -90.000000 && velZ == 0.100000) 
					return OnCheatDetect(playerid, "Troll-Hack #2");
			}
		}
		case CHEAT_FAKE_KILL_1:
		{
			if(AC_VARIABLE[playerid][AC_Warnings][CHEAT_FAKE_KILL_1] > 3) 
				return OnCheatDetect(playerid, "Fake-Kill #1");

			OnWarningExecute(playerid, CHEAT_SPEED_HACK, "Fake-Kill #1");
		}
	}

	return true;
}

OnWarningExecute(playerid, cheat_id, const cheat_name[])
{
	if(AC_VARIABLE[playerid][AC_Kicked]) 
		return true;

	AC_VARIABLE[playerid][AC_Warnings][cheat_id] ++;

	new 
		String[146];

	format(String, sizeof String, "{FF3939}AdmCMD: {FFFFFF}%s telah terdeteksi menggunakan %s {FF0000}'%d warnings!' {FFFFFF}(/spec %d)", 
		ReturnName(playerid), cheat_name, AC_VARIABLE[playerid][AC_Warnings][cheat_id], playerid);
	va_SendClientMessageToAll(COLOR_RED, String);

	return true;
}

OnCheatDetect(playerid, const cheat_name[])
{
	if(AC_VARIABLE[playerid][AC_Kicked]) 
		return true;

	new 
		String[100];

	format(String, sizeof String, "{FF3939}AdmCMD: {FFFFFF}%s telah di kick otomatis oleh {00A2FF}Local Prime-BOT", ReturnName(playerid));
	va_SendClientMessageToAll(COLOR_RED, String);
	format(String, sizeof String, "~> {FF0000}%s", cheat_name);
	va_SendClientMessageToAll(COLOR_RED, String);

	AC_VARIABLE[playerid][AC_Kicked] = true;
	KickEx(playerid);

	return true;
}

getPlayerSpeed(playerid)
{
	new 
		Float: X, Float: Y, Float: Z;

	GetPlayerVelocity(playerid, X, Y, Z);

	return floatround(200 * floatsqroot(X * X + Y * Y + Z * Z));
}

task onCheatTime[1000]()
{
	foreach(new i : Player)
	{
        if(pData[i][IsLoggedIn] == false) return 0;
	    if(pData[i][pSpawned] == 0) return 0;
		if(!AC_VARIABLE[i][AC_Kicked])
		{
			for(new x = 0; x < 5; x ++) cheatDetect(i, x);

			#if defined AC_DEBUG_MODE
				va_SendClientMessage(i, -1, "[OLD] X: %f, Y: %f, Z: %f", AC_VARIABLE[i][AC_POS][0], AC_VARIABLE[i][AC_POS][1], AC_VARIABLE[i][AC_POS][2]);
			#endif

			#if defined AC_DEBUG_MODE
				va_SendClientMessage(i, -1, "[NEW] X: %f, Y: %f, Z: %f", AC_VARIABLE[i][AC_POS][0], AC_VARIABLE[i][AC_POS][1], AC_VARIABLE[i][AC_POS][2]);
				va_SendClientMessage(i, -1, "Anim: %d / Vehicle: %d", GetPlayerAnimationIndex(i), GetPlayerVehicleID(i));
			#endif
		}
	}

	return true;
}

clearAnimations(playerid)
{
	ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
    ClearAnimations(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	return true;
}

//================== PUBLICS ==================//

hook OnPlayerConnect(playerid)
{
	AC_VARIABLE[playerid][AC_Kicked] = false;
	AC_VARIABLE[playerid][AC_LFWeapon] = 0;
	for(new i = 0; i < CHEAT_TYPES; i ++) if(AC_VARIABLE[playerid][AC_Warnings][i] > 0) AC_VARIABLE[playerid][AC_Warnings][i] = 0;
	for(new i = 0; i < 3; i ++) AC_VARIABLE[playerid][AC_Velocity][i] = -1;

	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(PRESSED(KEY_FIRE))
		{
			if(GetPlayerWeapon(playerid) == WEAPON_DEAGLE) AC_VARIABLE[playerid][AC_LFWeapon] = gettime();
		}
		else if(PRESSED(KEY_CROUCH))
		{
			if(gettime() - AC_VARIABLE[playerid][AC_LFWeapon] < 1)
			{
				clearAnimations(playerid);
				SetPlayerArmedWeapon(playerid, 0);

				InfoTD_MSG(playerid, 4000, "~r~~h~C-BUG IS NOT ALLOWED!");
			}
		}
	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
	if(damagedid != INVALID_PLAYER_ID && bodypart == 0 && weaponid < 16) cheatDetect(playerid, CHEAT_FAKE_KILL_1);

	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnUncpVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z)
{
	if((new_x != new_x || new_y != new_y || new_z != new_z ||
		floatabs(new_x) >= 25000.0 || floatabs(new_y) >= 25000.0 || floatabs(new_z) >= 25000.0)) 
			return OnCheatDetect(playerid, "Troll-Hack #3");

	new 
		Float: X, Float: Y, Float: Z;

	GetVehiclePos(vehicleid, X, Y, Z);

	if(passenger_seat > 0)
	{
		new 
			Float: difference = new_z - Z;

		if(difference >= -5.0 && (floatabs(new_x - X) >= 12.0 || floatabs(new_y - Y) >= 12.0)) 
			return OnCheatDetect(playerid, "Troll-Hack #4");
	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}