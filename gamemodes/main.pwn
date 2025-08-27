#if defined DCRP
 _____ ____ ___  ____  _____       _   _    ____  _____ _   _ 
|  ___/ ___/ _ \|  _ \| ____|     | | / \  |  _ \| ____| \ | |
| |_ | |  | | | | | | |  _|    _  | |/ _ \ | | | |  _| |  \| |
|  _|| |__| |_| | |_| | |___  | |_| / ___ \| |_| | |___| |\  |
|_|   \____\___/|____/|_____|  \___/_/   \_\____/|_____|_| \_|
#else
#endif
#pragma compress 0
#pragma dynamic	 1000000
#define CGEN_MEMORY 20000
#define YSI_NO_HEAP_MALLOC
#if defined MAKE_PELER
#include <profiler>
#endif

#include "resources/[cfg]/assets/cfg.pwn"

forward OnGameModeInitEx();
forward OnGameModeExitEx();

stock DatabaseConnection()
{
	dcrp_query = mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE);
	if (dcrp_query == MYSQL_INVALID_HANDLE || mysql_errno(dcrp_query) != 0)
	{
		print("DCRP: Connection To MYSQL Failed! Server Shutting Down!");
		SendRconCommand("exit");
	}
	else
	{
		print("DCRP: Database successfully connected to MySQL.");
	}
	return 1;
}

public OnGameModeInit()
{
	#if defined MAKE_PELER
	Profiler_Start();
	#endif
	DatabaseConnection();
	ShowNameTags(false);
	EnableTirePopping(0);
	CreateTextDraw();
	LoadWarungArea();
	LoadArea();
	LoadServerPickup();	
	ManualVehicleEngineAndLights();
	EnableStuntBonusForAll(0);
	AllowInteriorWeapons(1);
	DisableInteriorEnterExits();
	LimitPlayerMarkerRadius(15.0);
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_OFF);

	SetGameModeText(sprintf("%s", TEXT_GAMEMODE));
	SendRconCommand(sprintf("weburl %s", TEXT_WEBURL));
	SendRconCommand(sprintf("language %s", TEXT_LANGUAGE));
	SendRconCommand("mapname San Andreas");
	BlockGarages(.text="Tutup");

	//DATBASE LOAD
	mysql_tquery(dcrp_query, "SELECT * FROM `brankas_ems`", "LoadBrankasEms");
	mysql_tquery(dcrp_query, "SELECT * FROM `brankas_bengkel`", "LoadBrankasBengkel");
	mysql_tquery(dcrp_query, "SELECT * FROM `brankas_lounges`", "LoadBrankasLounges");
	mysql_tquery(dcrp_query, "SELECT * FROM `buttons`", "LoadButtons");
	mysql_tquery(dcrp_query, "SELECT * FROM `doors`", "LoadDoors");
	mysql_tquery(dcrp_query, "SELECT * FROM `families`", "Families_Load");
	mysql_tquery(dcrp_query, "SELECT * FROM `house`", "LoadRumah");
	mysql_tquery(dcrp_query, "SELECT * FROM `gate`", "LoadGate");
	mysql_tquery(dcrp_query, "SELECT * FROM `actors`", "Actor_Load");
	mysql_tquery(dcrp_query, "SELECT * FROM `bike_rentals`", "Rental_Load");
	mysql_tquery(dcrp_query, "SELECT * FROM `public_garage`", "LoadPublicGarage");
	mysql_tquery(dcrp_query, "SELECT * FROM `gudang`", "LoadGudang");
	mysql_tquery(dcrp_query, "SELECT * FROM `warung`", "LoadWarung");
	mysql_tquery(dcrp_query, "SELECT * FROM `pasar`", "LoadPasar");
	mysql_tquery(dcrp_query, "SELECT * FROM `robbery`", "LoadDynamicRobbery");
	mysql_tquery(dcrp_query, "SELECT * FROM `atms`", "LoadATM");
	mysql_tquery(dcrp_query, "SELECT * FROM `trash`", "LoadTrash");
	mysql_tquery(dcrp_query, "SELECT * FROM `stuffs`", "LoadBrankasGoodside");
	mysql_tquery(dcrp_query, "SELECT * FROM `ladang`", "LoadKanabis");
	mysql_tquery(dcrp_query, "SELECT * FROM `icons`", "Icons_Load", "");
	mysql_tquery(dcrp_query, "SELECT * FROM `label_fivem`", "LoadLabel");
	mysql_tquery(dcrp_query, "SELECT * FROM `dynamic_rusun`", "Rusun_Load");
	mysql_tquery(dcrp_query, "SELECT * FROM `hunting`", "LoadDeer");
	mysql_tquery(dcrp_query, "SELECT * FROM `weeds`", "Weed_Load");
	mysql_tquery(dcrp_query, "SELECT * FROM `voucher`", "LoadVoucher");
	mysql_tquery(dcrp_query, "SELECT * FROM `objects`", "LoadDynamicObject");
	mysql_tquery(dcrp_query, "SELECT * FROM `slotmachine`", "LoadSlotMachine");
	mysql_tquery(dcrp_query, "SELECT * FROM `objecttext`", "ObjectText_Load");
	mysql_tquery(dcrp_query, "SELECT * FROM `uranium`", "Load_Uranium");
	mysql_tquery(dcrp_query, "SELECT * FROM `tags` ORDER BY `tagId` ASC LIMIT "#MAX_DYNAMIC_TAGS";", "Tags_Load");

	for (new i; i < sizeof(ColorList); i++) {
        format(color_string, sizeof(color_string), "%s{%06x}%03d %s", color_string, ColorList[i] >>> 8, i, ((i+1) % 16 == 0) ? ("\n") : (""));
    }

    for (new i; i < sizeof(FontNames); i++) {
        format(object_font, sizeof(object_font), "%s%s\n", object_font, FontNames[i]);
    }
	
	for(new i = 0; i < sizeof(BarrierInfo);i ++)
	{
		new
		Float:X = BarrierInfo[i][brPos_X],
		Float:Y = BarrierInfo[i][brPos_Y];

		ShiftCords(0, X, Y, BarrierInfo[i][brPos_A]+90.0, 3.5);
		CreateDynamicObject(966,BarrierInfo[i][brPos_X],BarrierInfo[i][brPos_Y],BarrierInfo[i][brPos_Z],0.00000000,0.00000000,BarrierInfo[i][brPos_A]);
		if(!BarrierInfo[i][brOpen])
		{
			gBarrier[i] = CreateDynamicObject(968,BarrierInfo[i][brPos_X],BarrierInfo[i][brPos_Y],BarrierInfo[i][brPos_Z]+0.8,0.00000000,90.00000000,BarrierInfo[i][brPos_A]+180);
			MoveObject(gBarrier[i],BarrierInfo[i][brPos_X],BarrierInfo[i][brPos_Y],BarrierInfo[i][brPos_Z]+0.7,BARRIER_SPEED,0.0,0.0,BarrierInfo[i][brPos_A]+180);
			MoveObject(gBarrier[i],BarrierInfo[i][brPos_X],BarrierInfo[i][brPos_Y],BarrierInfo[i][brPos_Z]+0.75,BARRIER_SPEED,0.0,90.0,BarrierInfo[i][brPos_A]+180);
		}
		else gBarrier[i] = CreateDynamicObject(968,BarrierInfo[i][brPos_X],BarrierInfo[i][brPos_Y],BarrierInfo[i][brPos_Z]+0.8,0.00000000,20.00000000,BarrierInfo[i][brPos_A]+180);
	}

	//MPRICE STUFF
	OldTembagaPrice = TembagaPrice;
	OldBesiPrice = BesiPrice;
	OldEmasPrice = EmasPrice;
	OldBerlianPrice = BerlianPrice;
	OldMaterialPrice = MaterialPrice;
	OldAlumuniumPrice = AlumuniumPrice;
	OldKaretPrice = KaretPrice;
	OldKacaPrice = KacaPrice;
	OldBajaPrice = BajaPrice;
	OldAyamKemasPrice = AyamKemasPrice;
	OldSusuOlahPrice = SusuOlahPrice;
	OldPakaianPrice = PakaianPrice;
	OldKayuKemasPrice = KayuKemasPrice;
	OldGasPrice = GasPrice;
	
	SetTimer("WeatherRotator", 1800000, true);
	CallLocalFunction("OnGameModeInitEx", "");

	OpenVote = 0;
    VoteYes = 0;
    VoteNo = 0;
    VoteTime = 0;
    VoteText[0] = EOS;
	return 1;
} 

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	#if defined DEBUG_MODE
	    printf("[debug] OnPlayerInteriorChange(PID : %d New-Int : %d Old-Int : %d)", playerid, newinteriorid, oldinteriorid);
	#endif

	CancelEdit(playerid);

	foreach(new i : Player) if (AccountData[i][pSpec] != INVALID_PLAYER_ID && AccountData[i][pSpec] == playerid)
	{
		SetPlayerInterior(i, GetPlayerInterior(playerid));
		SetPlayerVirtualWorld(i, GetPlayerVirtualWorld(playerid));
	}

	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
    if (!AccountData[playerid][IsLoggedIn])
    {
		GameTextForPlayer(playerid, "~r~Stay in your world bastard!", 2000, 4);
		SendClientMessageEx(playerid, X11_RED, "[AntiCheat]:"LIGHTGREY" Anda ditendang karena diduga Fake Spawn!");
        KickEx(playerid);
    }
    return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	if(SQL_IsCharacterLogged(playerid) && AccountData[playerid][pAdmin] > 0)
	{
		if(!IsPlayerConnected(clickedplayerid)) return 0;
		if(clickedplayerid == playerid) return 0;

		new title[127];
		format(title, sizeof(title), ""PINK1"DCRP"WHITE"- %s(%d)", ReturnName(clickedplayerid), clickedplayerid);
		ShowPlayerDialog(playerid, DIALOG_CLICKPLAYER, DIALOG_STYLE_LIST, title, 
		""PINK1"Menu Admin\n\
		\nSpectator Pemain\
		\n"GRAY"Tarik Pemain\
		\nTeleport Ke Pemain\
		\n"GRAY"Banned Pemain\
		\nKick Pemain\
		\n"GRAY"Stats Pemain", "Pilih", "Batal");
		ClickPlayerID[playerid] = clickedplayerid;
	}
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetCameraData(playerid);

	if(!AccountData[playerid][IsLoggedIn])
	{		
		new query[268];
		mysql_format(dcrp_query, query, sizeof(query), "SELECT * FROM `playerucp` WHERE `ucp` = '%s' LIMIT 1", AccountData[playerid][pUCP]);
		mysql_pquery(dcrp_query, query, "CheckPlayerUCP", "id", playerid, g_RaceCheck[playerid]);
		SetPlayerColor(playerid, X11_GRAY);
	}
	return 1;
}

public OnGameModeExit()
{
	#if defined DEBUG_MODE
	    printf("[debug] OnGameModeExit()");
	#endif

    SaveAll();
	
	foreach(new playerid : Player)
		TerminateConnection(playerid);

	CallLocalFunction("OnGameModeExitEx", "");
	mysql_close(dcrp_query);
	#if defined MAKE_PELER
	Profiler_Dump();
	Profiler_Stop();
	#endif
	return 1;
}

forward OnPlayerCarJacking(playerid);
public OnPlayerCarJacking(playerid)
{
	new Float:playerPos[3];
	GetPlayerPos(playerid, playerPos[0], playerPos[1], playerPos[2]);
	AccountData[playerid][pWorld] = GetPlayerVirtualWorld(playerid);
	
	SetPlayerPos(playerid, playerPos[0], playerPos[1], playerPos[2] + 9.0);
	TogglePlayerControllable(playerid, false);
	ShowPlayerFooter(playerid, "No Jacking!", 5000);
	SetPlayerVirtualWorld(playerid, (playerid+1));
	SetTimerEx("OnPlayerCarJackingUpdate", 5500, false, "d", playerid);
	return 1;	
}

forward OnPlayerCarJackingUpdate(playerid);
public OnPlayerCarJackingUpdate(playerid)
{
	TogglePlayerControllable(playerid, true);
	SetPlayerVirtualWorld(playerid, AccountData[playerid][pWorld]);
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
		new driverid = GetVehicleDriver(vehicleid);
		if(driverid != INVALID_PLAYER_ID && IsPlayerInVehicle(driverid, vehicleid) && !IsVehicleEmpty(vehicleid) && IsPlayerChangeSeat[playerid] == false)
		{
			SetTimerEx("OnPlayerCarJacking", 250, false, "d", playerid);
		}
		new vehicle_near = GetNearestVehicle(playerid);
		if((vehicle_near = Vehicle_ReturnID(vehicleid)) != RETURN_INVALID_VEHICLE_ID)
		{
			if(PlayerVehicle[vehicle_near][pVehFaction] == FACTION_POLISI)
			{
				if(AccountData[playerid][pFaction] != FACTION_POLISI && AccountData[playerid][pFaction] != FACTION_BENGKEL)
				{
					RemovePlayerFromVehicle(playerid);
					new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz);
					ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini milik faction Polisi!");
				}
			}
			else if(PlayerVehicle[vehicle_near][pVehFaction] == FACTION_PEMERINTAH)
			{
				if(AccountData[playerid][pFaction] != FACTION_PEMERINTAH && AccountData[playerid][pFaction] != FACTION_BENGKEL)
				{
					RemovePlayerFromVehicle(playerid);
					new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz);
					ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini milik faction Pemerintah!");
				}
			}
			else if(PlayerVehicle[vehicle_near][pVehFaction] == FACTION_EMS)
			{
				if(AccountData[playerid][pFaction] != FACTION_EMS && AccountData[playerid][pFaction] != FACTION_BENGKEL)
				{
					RemovePlayerFromVehicle(playerid);
					new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz);
					ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini milik faction EMS!");
				}
			}
			else if(PlayerVehicle[vehicle_near][pVehFaction] == FACTION_TRANS)
			{
				if(AccountData[playerid][pFaction] != FACTION_TRANS && AccountData[playerid][pFaction] != FACTION_BENGKEL && AccountData[playerid][pFaction] != FACTION_POLISI)
				{
					RemovePlayerFromVehicle(playerid);
					new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz);
					ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini milik faction Transportasi!");
				}
			}
			else if(PlayerVehicle[vehicle_near][pVehFaction] == FACTION_BENGKEL)
			{
				if(AccountData[playerid][pFaction] != FACTION_POLISI && AccountData[playerid][pFaction] != FACTION_BENGKEL)
				{
					RemovePlayerFromVehicle(playerid);
					new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz);
					ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini milik faction Bengkel!");
				}
			}
			else if(PlayerVehicle[vehicle_near][pVehFaction] == FACTION_PEDAGANG)
			{
				if(AccountData[playerid][pFaction] != FACTION_PEDAGANG && AccountData[playerid][pFaction] != FACTION_BENGKEL)
				{
					RemovePlayerFromVehicle(playerid);
					new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz);
					ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini milik faction Pedagang!");
				}
			}
		}
	}
	return 1;
}

forward TrackSuspect(suspectid, policeid);
public TrackSuspect(suspectid, policeid)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(suspectid, x, y, z);

	SetPlayerRaceCheckpoint(policeid, 1, x, y, z, 0.0, 0.0, 0.0, 5.0);
	Info(policeid, "Tracking Suspect Updated!");
	pMapCP[policeid] = true;
	return 1;
}

public OnPlayerText(playerid, text[])
{
	if(!AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
		return 0;

	if(AccountData[playerid][pAdmin] > 0 && AccountData[playerid][pAdminDuty])
	{
		if(strlen(text) > 64)
		{
			SendNearbyMessage(playerid, 15.0, -1, "Admin "RED"%s"WHITE": (( %.64s...", AccountData[playerid][pAdminname], text);
			SendNearbyMessage(playerid, 15.0, -1, "...%s ))", text[64]);
		}
		else 
		{
			SendNearbyMessage(playerid, 15.0, -1, "Admin "RED"%s"WHITE": (( %s ))", AccountData[playerid][pAdminname], text);
		}
	}
	return 0;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
	if (result != -1 && !AccountData[playerid][IsLoggedIn])
	{
		SendClientMessage(playerid, -1, ""RED"[AntiCheat]"ARWIN1" Anda ditendang dari server karena menggunakan CMD dalam keadaan tidak login!");
		return KickEx(playerid);
	}
	
    if (result == -1)
    {
		if(AccountData[playerid][pStyleNotif] == 1) //TD
		{
			ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("~b~Perintah ~b~'/%s' ~b~tidak diketahui, ~b~'/help' ~b~untuk info lanjut!", cmd));
		}
		else
		{
			ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Perintah "YELLOW"'/%s'"WHITE" tidak diketahui, "YELLOW"'/help'"WHITE" untuk info lanjut!", cmd));
		}
		return 0;
    }
	return 1;
}

public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
	return 1;
}

public OnPlayerConnect(playerid)
{
	g_RaceCheck[playerid] ++;
	ResetVariables(playerid);
	ReturnIP(playerid);
	CreatePlayerTextDraws(playerid);
	OnLoadMixerProperty(playerid);
	Player_ToggleTelportAntiCheat(playerid, false);
	Player_ToggleAntiHealthHack(playerid, false);
	Player_ToggleDisableAntiCheat(playerid, false);
	EnableAntiCheatForPlayer(playerid, 11, true);
	EnableAntiCheatForPlayer(playerid, 19, true);
	EnableAntiCheatForPlayer(playerid, 4, true);

	if(g_RestartServer || g_AsuransiTime)
	{
		TextDrawShowForPlayer(playerid, gServerTextdraws[0]);
	}

	GetPlayerName(playerid, AccountData[playerid][pUCP], MAX_PLAYER_NAME + 1);
	PlayerSpawn[playerid] = 0;

    if(AccountData[playerid][pHead] < 0) return AccountData[playerid][pHead] = 20;
    if(AccountData[playerid][pPerut] < 0) return AccountData[playerid][pPerut] = 20;
    if(AccountData[playerid][pRFoot] < 0) return AccountData[playerid][pRFoot] = 20;
    if(AccountData[playerid][pLFoot] < 0) return AccountData[playerid][pLFoot] = 20;
    if(AccountData[playerid][pLHand] < 0) return AccountData[playerid][pLHand] = 20;
    if(AccountData[playerid][pRHand] < 0) return AccountData[playerid][pRHand] = 20;
	
	PantaiArea[playerid] = CreateDynamicRectangle(345.3125, -2094.787811279297, 415.3125, -2007.7878112792969);
	Compass_OnPlayerConnect(playerid);
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		RemovePlayerFromVehicle(playerid);
	}

	KillTimer(AccountData[playerid][pDutyTimer]);
	RemoveDrag(playerid);
	CheckDrag(playerid);
	Report_Clear(playerid);
	Ask_Clear(playerid);

	g_RaceCheck[playerid] ++;
	
	if (AccountData[playerid][IsLoggedIn])
	{
		UpdatePlayerData(playerid);
		UnloadPlayerVehicle(playerid);

		if (AccountData[playerid][pJobVehicle] != 0)
		{
			DestroyJobVehicle(playerid);
			AccountData[playerid][pJobVehicle] = 0;
		}
	}

	if(IsValidDynamic3DTextLabel(AccountData[playerid][pAdoTag])) DestroyDynamic3DTextLabel(AccountData[playerid][pAdoTag]);
	if(IsValidDynamic3DTextLabel(AccountData[playerid][pMaskLabel])) DestroyDynamic3DTextLabel(AccountData[playerid][pMaskLabel]);

    if(AccountData[playerid][pAdminDuty] == 1)
	if(IsValidDynamic3DTextLabel(AccountData[playerid][pLabelDuty]))
		DestroyDynamic3DTextLabel(AccountData[playerid][pLabelDuty]);

	new reasontext[526], frmxt[255], Float:pX, Float:pY, Float:pZ;
	GetPlayerPos(playerid, pX, pY, pZ);

	switch(reason)
	{
	    case 0: format(reasontext, sizeof(reasontext), "Timeout/Crash");
	    case 1: format(reasontext, sizeof(reasontext), "Quit");
		case 2: format(reasontext, sizeof(reasontext), "Kicked/Banned");
	}

	format(frmxt, sizeof(frmxt), "Player ["YELLOW"%d"WHITE"]"YELLOW" %s | %s"WHITE" Telah keluar dari server.\nReason: "RED"%s", playerid, AccountData[playerid][pName], AccountData[playerid][pUCP], reasontext);
	labelDisconnect[playerid] = CreateDynamic3DTextLabel(frmxt, -1, pX, pY, pZ, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), -1, 15.0, -1, 0);
	labelDisconnectTimer[playerid] = SetTimerEx("DestroyLabelOut", 5000, false, "i", playerid);
	
	if(AccountData[playerid][phoneDurringConversation])
	{
		CutCallingLine(playerid);
	}
	TerminateConnection(playerid);
	Compass_OnPlayerDisconnect(playerid, reason);
	return 1;
}	

public OnPlayerSpawn(playerid)
{
	if(PlayerSpawn[playerid] == 1)
	{

		if(!AccountData[playerid][pSpawned])
		{
			AccountData[playerid][pSpawned] = 1;
			SetCameraBehindPlayer(playerid);
			Streamer_ToggleIdleUpdate(playerid, true);
			StopAudioStreamForPlayer(playerid);
			
			GivePlayerMoney(playerid, AccountData[playerid][pMoney]);
			SetPlayerScore(playerid, AccountData[playerid][pLevel]);
			SetPlayerHealth(playerid, AccountData[playerid][pHealth]);
			SetPlayerArmour(playerid, AccountData[playerid][pArmour]);
			SetPlayerInterior(playerid, AccountData[playerid][pInt]);
			SetPlayerVirtualWorld(playerid, AccountData[playerid][pWorld]);
			PreloadAnimations(playerid);

			TogglePlayerControllable(playerid, false);
			static Float:X, Float:Y, Float:Z;
			GetPlayerPos(playerid, X, Y, Z);
			AccountData[playerid][pFreeze] = 1;
			AccountData[playerid][pFreezeTimer] = SetTimerEx("SetPlayerToUnfreeze", 7000, false, "iffff", playerid, X, Y, Z); //defer SetPlayerToUnfreeze[time](playerid);
			Player_ToggleTelportAntiCheat(playerid, true);

			SetPlayerSkillLevel(playerid, WEAPONSKILL_DESERT_EAGLE, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SHOTGUN, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SPAS12_SHOTGUN, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SNIPERRIFLE, 999);

			SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 0);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_MICRO_UZI, 0);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, 0);

			SendClientMessageEx(playerid, -1, "{BABABA}</> "WHITE"Selamat datang kembali "PINK1"%s.", ReturnName(playerid));
			SendClientMessageEx(playerid, -1, "{BABABA}</> "WHITE"Hari ini "YELLOW"%s", ReturnTime());
			SendClientMessage(playerid, -1, "{BABABA}</>"WHITE"Perlu bantuan? Tanyakan lewat "YELLOW"'/ask'"WHITE", atau laporkan masalah dengan "YELLOW"'/report'!");
			SendClientMessage(playerid, -1, "{BABABA}</> "WHITE"Kena bug visual? Tenang, "YELLOW"'/fixme'"WHITE" siap menyelamatkan hari kamu.");
			SendClientMessage(playerid, -1, "{BABABA}</>"WHITE"Gabung komunitas: "YELLOW"discord.gg/DCRP");


			if(VoucherData[0][voucherExists] && AccountData[playerid][pKompensasi] < 1)
			{
				SendClientMessageEx(playerid, -1, "[i] Anda memiliki kompensasi yang belum di claim! gunakan "YELLOW"'/klaimkompensasi'"WHITE" untuk mengambil kompensasi");
			}
			if(AccountData[playerid][pDutyPD] || AccountData[playerid][pDutyPemerintah] || AccountData[playerid][pDutyEms] 
				|| AccountData[playerid][pDutyBengkel] || AccountData[playerid][pDutyTrans] || AccountData[playerid][pDutyPedagang])
			{
				AccountData[playerid][pDutyTimer] = SetTimerEx("FactDutyHour", 1000, true, "d", playerid);
			}
		}

		if(IsPlayerInEvent(playerid))
		 	return 0;
		
		Streamer_ToggleIdleUpdate(playerid, true);
		PreloadAnimations(playerid);
		if(AccountData[playerid][pUsingUniform])
		{
			SetPlayerSkin(playerid, AccountData[playerid][pUniform]);
		}
		else
		{
			SetPlayerSkin(playerid, AccountData[playerid][pSkin]);
		}

		if(AccountData[playerid][pInjured] == 1 && AccountData[playerid][pInjuredTime] != 0)
		{
			TogglePlayerControllable(playerid, false);
			SetPlayerPos(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ]);
			SetPlayerFacingAngle(playerid, AccountData[playerid][pPosA]);
			SetPlayerInterior(playerid, AccountData[playerid][pInt]);
			SetPlayerVirtualWorld(playerid, AccountData[playerid][pWorld]);
		}

		if(AccountData[playerid][pAdminDuty] > 0)
		{
			SetPlayerColor(playerid, X11_DARKRED);
		}
		SetTimerEx("TimersSpawn", 5000, false, "d", playerid);
	}
	else
	{

		if(PlayerChar[playerid][0][0] != EOS) SetPlayerSkin(playerid, CharSkin[playerid][0]);
		else SetPlayerSkin(playerid, RandomEx(1, 255));
		SetPlayerVirtualWorld(playerid, playerid);

		SetPlayerPos(playerid, 349.8621,-2052.0586,7.8359+0.1);
		SetPlayerFacingAngle(playerid, 90.4918);
		ApplyAnimation(playerid,"SWORD","sword_block",50.0 ,0,1,0,1,1);

		SetPlayerCameraPos(playerid,349.625427,-2041.445068,12.335951);
		SetPlayerCameraLookAt(playerid,389.015380,-2029.534667,20.905969);
		InterpolateCameraPos(playerid,349.625427,-2041.445068,12.335951,348.775085,-2056.439941,8.165917,2000,CAMERA_MOVE);
		InterpolateCameraLookAt(playerid,389.015380,-2029.534667,20.905969,349.924926,-2052.058105,7.835937,2000,CAMERA_MOVE);
	}
	Compass_OnPlayerUpdate(playerid);
	return 1;
}

forward TimersSpawn(playerid);
public TimersSpawn(playerid)
{
	if(!AccountData[playerid][pSpawned])
		return 0;

	if(AccountData[playerid][pJail] > 0)
	{
		SpawnPlayerInJail(playerid);
	}
	if(AccountData[playerid][pArrestTime] > 0)
	{
		SetPlayerArrest(playerid, AccountData[playerid][pArrest]);
	}
	TogglePlayerControllable(playerid, 1);
	SetPlayerInterior(playerid, AccountData[playerid][pInt]);
	SetPlayerVirtualWorld(playerid, AccountData[playerid][pWorld]);
	AttachPlayerToys(playerid);
	SetWeapons(playerid);

	Compass_OnPlayerUpdate(playerid);
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	if(!AccountData[playerid][pSpawned])
		return 0;

	foreach(new i : Player) if (IsPlayerConnected(i))
	{
		if(AccountData[i][pAdmin] > 0 && AccountData[i][pTheStars] > 0)
		{
			SendDeathMessageToPlayer(i, killerid, playerid, reason);
			return 1;
		}
	}
	new reasontext[596];
	switch(reason)
	{
		case 0: reasontext = "Tangan Kosong";
		case 1: reasontext = "Brass Knuckles";
		case 2: reasontext = "Golf Club";
		case 3: reasontext = "Nite Stick";
		case 4: reasontext = "Knife";
		case 5: reasontext = "Basebal Bat";
		case 6: reasontext = "Shovel";
		case 7: reasontext = "Pool Cue";
		case 8: reasontext = "Katana";
		case 9: reasontext = "Chain Shaw";
		case 14: reasontext = "Cane";
		case 18: reasontext = "Molotov";
		case 22: reasontext = "Colt 45";
		case 23: reasontext = "SLC";
		case 24: reasontext = "Desert Eagle";
		case 25: reasontext = "Shotgun";
		case 26: reasontext = "Sawnoff Shotgun";
		case 27: reasontext = "Combat Shotgun";
		case 28: reasontext = "Micro SMG/Uzi";
		case 29: reasontext = "MP5";
		case 30: reasontext = "AK-47";
		case 31: reasontext = "M4";
		case 32: reasontext = "Tec-9";
		case 33: reasontext = "Coutry Rifle";
		case 38: reasontext = "Mini Gun";
		case 49: reasontext = "Tertabrak Kendaraan";
		case 50: reasontext = "Helicopter Blades";
		case 51: reasontext = "Explode";
		case 53: reasontext = "Drowned";
		case 54: reasontext = "Splat";
		case 255: reasontext = "Suicide";
	}

	SetPlayerArmedWeapon(playerid, 0);
	return 1;
}

public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ )
{
	new weaponid = EditingWeapon[playerid];
	if(response)
	{
		if(weaponid)
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
 
			ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil merubah posisi letak %s", weaponname));
           
			EditingWeapon[playerid] = 0;
            mysql_format(dcrp_query, string, sizeof(string), "INSERT INTO weaponsettings (Owner, WeaponID, PosX, PosY, PosZ, RotX, RotY, RotZ) VALUES ('%d', %d, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f) ON DUPLICATE KEY UPDATE PosX = VALUES(PosX), PosY = VALUES(PosY), PosZ = VALUES(PosZ), RotX = VALUES(RotX), RotY = VALUES(RotY), RotZ = VALUES(RotZ)", AccountData[playerid][pID], weaponid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ);
            mysql_tquery(dcrp_query, string);
		}

		if(AccountData[playerid][toySelected] != -1)
		{
			new id = AccountData[playerid][toySelected];
			pToys[playerid][id][toy_x] = fOffsetX;
			pToys[playerid][id][toy_y] = fOffsetY;
			pToys[playerid][id][toy_z] = fOffsetZ;
			pToys[playerid][id][toy_rx] = fRotX;
			pToys[playerid][id][toy_ry] = fRotY;
			pToys[playerid][id][toy_rz] = fRotZ;
			pToys[playerid][id][toy_sx] = fScaleX;
			pToys[playerid][id][toy_sy] = fScaleY;
			pToys[playerid][id][toy_sz] = fScaleZ;
			
			MySQL_SavePlayerToys(playerid);
			ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil menyimpan kordinat baru.");
			AccountData[playerid][toySelected] = -1;
		}
	}
	else
	{
		if(EditingWeapon[playerid])
		{
			new enum_index = weaponid - 22;
			SetPlayerAttachedObject(playerid, GetWeaponObjectSlot(weaponid), GetWeaponModel(weaponid), WeaponSettings[playerid][enum_index][Bone], fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, 1.0, 1.0, 1.0);
			EditingWeapon[playerid] = 0;
		}

		if(AccountData[playerid][toySelected] != -1)
		{
			new id = AccountData[playerid][toySelected];
			SetPlayerAttachedObject(playerid,
				id,
				modelid,
				boneid,
				pToys[playerid][id][toy_x],
				pToys[playerid][id][toy_y],
				pToys[playerid][id][toy_z],
				pToys[playerid][id][toy_rx],
				pToys[playerid][id][toy_ry],
				pToys[playerid][id][toy_rz],
				pToys[playerid][id][toy_sx],
				pToys[playerid][id][toy_sy],
				pToys[playerid][id][toy_sz]);
			AccountData[playerid][toySelected] = -1;
		}
	}
	SetPVarInt(playerid, "UpdatedToy", 1);
	return 1;
}


public OnPlayerEditDynamicObject(playerid, STREAMER_TAG_OBJECT: objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	if(AccountData[playerid][EditingDeerID] != -1 && Iter_Contains(Hunt, AccountData[playerid][EditingDeerID]))
	{
		if(response == EDIT_RESPONSE_FINAL)
	    {
	        new etid = AccountData[playerid][EditingDeerID];
	        HuntData[etid][DeerPOS][0] = x;
	        HuntData[etid][DeerPOS][1] = y;
	        HuntData[etid][DeerPOS][2] = z;
	        HuntData[etid][DeerROT][0] = rx;
	        HuntData[etid][DeerROT][1] = ry;
	        HuntData[etid][DeerROT][2] = rz;

	        SetDynamicObjectPos(objectid, HuntData[etid][DeerPOS][0], HuntData[etid][DeerPOS][1], HuntData[etid][DeerPOS][2]);
	        SetDynamicObjectRot(objectid, HuntData[etid][DeerROT][0], HuntData[etid][DeerROT][1], HuntData[etid][DeerROT][2]);

			Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, HuntData[etid][DeerLabel], E_STREAMER_X, HuntData[etid][DeerPOS][0]);
			Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, HuntData[etid][DeerLabel], E_STREAMER_Y, HuntData[etid][DeerPOS][1]);
			Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, HuntData[etid][DeerLabel], E_STREAMER_Z, HuntData[etid][DeerPOS][2] + 1.1);

		    HuntSave(etid);
	        AccountData[playerid][EditingDeerID] = -1;
	    }
	    if(response == EDIT_RESPONSE_CANCEL)
	    {
	        new etid = AccountData[playerid][EditingDeerID];
	        SetDynamicObjectPos(objectid, HuntData[etid][DeerPOS][0], HuntData[etid][DeerPOS][1], HuntData[etid][DeerPOS][2]);
	        SetDynamicObjectRot(objectid, HuntData[etid][DeerROT][0], HuntData[etid][DeerROT][1], HuntData[etid][DeerROT][2]);
	        AccountData[playerid][EditingDeerID] = -1;
	    }
	}
	else if(AccountData[playerid][EditingLADANGID] != -1 && Iter_Contains(Ladang, AccountData[playerid][EditingLADANGID]))
	{
		if(response == EDIT_RESPONSE_FINAL)
	    {
	        new etid = AccountData[playerid][EditingLADANGID];
	        LadangData[etid][kanabisX] = x;
	        LadangData[etid][kanabisY] = y;
	        LadangData[etid][kanabisZ] = z;
	        LadangData[etid][kanabisRX] = rx;
	        LadangData[etid][kanabisRY] = ry;
	        LadangData[etid][kanabisRZ] = rz;

	        SetDynamicObjectPos(objectid, LadangData[etid][kanabisX], LadangData[etid][kanabisY], LadangData[etid][kanabisZ]);
	        SetDynamicObjectRot(objectid, LadangData[etid][kanabisRX], LadangData[etid][kanabisRY], LadangData[etid][kanabisRZ]);

		    Ladang_Save(etid);
	        AccountData[playerid][EditingLADANGID] = -1;
	    }

	    if(response == EDIT_RESPONSE_CANCEL)
	    {
	        new etid = AccountData[playerid][EditingLADANGID];
	        SetDynamicObjectPos(objectid, LadangData[etid][kanabisX], LadangData[etid][kanabisY], LadangData[etid][kanabisZ]);
	        SetDynamicObjectRot(objectid, LadangData[etid][kanabisRX], LadangData[etid][kanabisRY], LadangData[etid][kanabisRZ]);
	        AccountData[playerid][EditingLADANGID] = -1;
	    }
	}
	else if(AccountData[playerid][EditingATMID] != -1 && Iter_Contains(ATMS, AccountData[playerid][EditingATMID]))
	{
		if(response == EDIT_RESPONSE_FINAL)
	    {
	        new etid = AccountData[playerid][EditingATMID];
	        AtmData[etid][atmX] = x;
	        AtmData[etid][atmY] = y;
	        AtmData[etid][atmZ] = z;
	        AtmData[etid][atmRX] = rx;
	        AtmData[etid][atmRY] = ry;
	        AtmData[etid][atmRZ] = rz;

	        SetDynamicObjectPos(objectid, AtmData[etid][atmX], AtmData[etid][atmY], AtmData[etid][atmZ]);
	        SetDynamicObjectRot(objectid, AtmData[etid][atmRX], AtmData[etid][atmRY], AtmData[etid][atmRZ]);

		  	Atm_Refresh(etid);
		    Atm_Save(etid);
	        AccountData[playerid][EditingATMID] = -1;
	    }

	    if(response == EDIT_RESPONSE_CANCEL)
	    {
	        new etid = AccountData[playerid][EditingATMID];
	        SetDynamicObjectPos(objectid, AtmData[etid][atmX], AtmData[etid][atmY], AtmData[etid][atmZ]);
	        SetDynamicObjectRot(objectid, AtmData[etid][atmRX], AtmData[etid][atmRY], AtmData[etid][atmRZ]);
	        AccountData[playerid][EditingATMID] = -1;
	    }
	}
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	if(pMapCP[playerid])
	{
		ShowTDN(playerid, NOTIFICATION_INFO, "Anda berhasil sampai ke lokasi tujuan");
		DisablePlayerRaceCheckpoint(playerid);
		pMapCP[playerid] = false;
	}
	if(AccountData[playerid][pTrackCar] == 1)
	{
		ShowTDN(playerid, NOTIFICATION_INFO, "Anda berhasil sampai ke lokasi tujuan");
		AccountData[playerid][pTrackCar] = 0;
		DisablePlayerRaceCheckpoint(playerid);
	}
	if(AccountData[playerid][pTrackHoused] == 1)
	{
		ShowTDN(playerid, NOTIFICATION_INFO, "Anda berhasil sampai ke lokasi tujuan");
		AccountData[playerid][pTrackHoused] = 0;
		DisablePlayerRaceCheckpoint(playerid);
	}
	if(AccountData[playerid][pDiPesawat])
	{
		DisablePlayerCheckpoint(playerid);
		AccountData[playerid][pDiPesawat] = false;
		AccountData[playerid][pPosX] = 1750.4976;
		AccountData[playerid][pPosY] = -2516.3225;
		AccountData[playerid][pPosZ] = 13.5969;
		AccountData[playerid][pPosA] = 90.1848;
		AccountData[playerid][pInDoor] = 7;
		SetPlayerVirtualWorldEx(playerid, 0);
		SetPlayerInteriorEx(playerid, 0);
		SetPlayerPositionEx(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ], AccountData[playerid][pPosA], 6000);
	}
	if(jobs::mixer[playerid][mixerDuty][1])
    {
        DisablePlayerCheckpoint(playerid);
        PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MENUMPAHKAN");
        ShowProgressBar(playerid);
        jobs::mixer[playerid][mixerDuty][1] = false;
        jobs::mixer[playerid][mixerTimer] = SetTimerEx("CorLokasi", 1000, true, "i", playerid);
    }
    if(jobs::mixer[playerid][mixerDuty][2])
    {
        if(IsPlayerInAnyVehicle(playerid))
        {	
            RemovePlayerFromVehicle(playerid);
            DestroyVehicle(jobs::mixer[playerid][mixerVehicle]);
            GiveMoney(playerid, 150);
            jobs::mixer[playerid][mixerDuty][2] = false;
            jobs::mixer_reset_enum(playerid);
        }
    }
	return 1;
}

Dialog:DeathRespawnConf(playerid, response, listitem, inputtext[])
{
	if(!response) return 1;
	if(!IsPlayerInjured(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak sedang Pingsan!");

	SetPlayerHealthEx(playerid, 100.0);
	AccountData[playerid][pHunger] = 100;
	AccountData[playerid][pThirst] = 100;
	AccountData[playerid][pStress] = 0;
	AccountData[playerid][pInjured] = 0;
	AccountData[playerid][pInjuredTime] = 0;
	Inventory_Clear(playerid);
	ResetPlayerWeaponsEx(playerid);
	
	ShowTDN(playerid, NOTIFICATION_INFO, "Kamu koma dan dilarikan ke Rumah Sakit");

	SetPlayerPositionEx(playerid, 1333.4708,722.0023,11.6093,93.9083, 5000);
	//SetPlayerVirtualWorldEx(playerid, 1);
	//SetPlayerInteriorEx(playerid, 1);

	foreach(new pid : Player) {
		if(AccountData[pid][pFaction] == FACTION_EMS && AccountData[pid][pDutyEms]) {
			SendClientMessageEx(pid, -1, ""YELLOW"[Koma]"WHITE_E" %s telah terbangun di ruang koma", ReturnName(playerid));
		}
	}

	AddPMoneyLog(AccountData[playerid][pName], AccountData[playerid][pUCP], "KOMA", 0);
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_WALK) && IsPlayerInRangeOfPoint(playerid, 2.0, 641.2187,1238.3390,11.6796))
    {
		if(jobs::mixer[playerid][mixerDuty][0]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memulai pekerjaan");
        if(GetPlayerJob(playerid) != JOB_DRIVER_MIXERS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan pekerja supir mixer");
        jobs::mixer[playerid][mixerVehicle] = CreateVehicle(524, 639.8187,1250.2065,11.6333,306.5278, 5, 5, 60000, false);
		if(IsValidVehicle(jobs::mixer[playerid][mixerVehicle]))
		{
			VehicleCore[jobs::mixer[playerid][mixerVehicle]][vCoreFuel]=MAX_FUEL_FULL;
		    PutPlayerInVehicle(playerid, jobs::mixer[playerid][mixerVehicle], 0);
			jobs::mixer[playerid][mixerDuty][0] = true;
		}
		SetPlayerRaceCheckpoint(playerid, 1, 590.0992,1243.8767,11.7188, 0.0, 0.0, 0.0, 5.0);
        ShowPlayerFooter(playerid, "~w~Isi kendaraan dengan~n~~g~beton ~w~di belakang", 3000, 1);
    }
    if(PRESSED(KEY_CROUCH) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInRangeOfPoint(playerid, 3.0, 590.0992,1243.8767,11.7188))
    {
        if(GetPlayerJob(playerid) != JOB_DRIVER_MIXERS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan pekerja supir mixer");
        ShowMixTD(playerid);
    }
	if(PRESSED(KEY_CTRL_BACK) && AccountData[playerid][pFlashShown] && !IsPlayerInAnyVehicle(playerid))
	{
		switch(AccountData[playerid][pFlashOn])
		{
			case false:
            {
				if (!IsPlayerPlayingAnimation(playerid, "ped", "phone_talk"))
				{
					ApplyAnimationEx(playerid, "ped", "phone_talk", 1.1, 1, 1, 1, 1, 1, 1);
				}
				
                AccountData[playerid][pFlashOn] = true;
                SetPlayerAttachedObject(playerid, 5, 19295, 1,  0.068000, 0.606000, 0.000000,  0.000000, -4.500000, 12.299996,  1.000000, 1.000000, 1.020000); // Light Objects
                ShowPlayerFooter(playerid, "~w~Senter ~g~Nyala", 3000);
            }
            case true:
            {
                AccountData[playerid][pFlashOn] = false;
                RemovePlayerAttachedObject(playerid, 5);
                ShowPlayerFooter(playerid, "~w~Senter ~r~Mati", 3000);
            }
		}
	}

	if(newkeys & KEY_FIRE && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && IsPlayerInDynamicArea(playerid, AreaData[BandaraGreenZone]))
	{
		ClearAnimations(playerid, 1);
        SetPlayerArmedWeapon(playerid, 0);

        new lstring[512];
        SetPVarInt(playerid, "GreenzoneWarning", GetPVarInt(playerid, "GreenzoneWarning")+1);
		format(lstring, sizeof(lstring), "Anda tidak dapat memukul / menembak di Area Greenzone.\n"RED"%d/5"WHITE" anda akan ditendang dari server.", GetPVarInt(playerid, "GreenzoneWarning"));
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""PINK1"DCRP"WHITE"Green Zone", lstring, "Tutup", "");

        if(GetPVarInt(playerid, "GreenzoneWarning") == 5)
		{
			format(lstring, sizeof(lstring), "Anda telah ditendang dari server karena mendapatkan\n"RED"5"WHITE" peringatan Greenzone!");
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""PINK1"DCRP"WHITE"Green Zone Warning", lstring, "Keluar", "");
			DeletePVar(playerid, "GreenzoneWarning");
            KickEx(playerid);
        }
	}

	if((newkeys & KEY_JUMP) && !IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && !IsPlayerInEvent(playerid) && !DurringHunting[playerid] && !AccountData[playerid][pAdminDuty])
	{
		PlayerPressedJump[playerid] ++;
		SetTimerEx("PressJumpReset", 3000, false, "d", playerid); // Makes it where if they dont spam the jump key, they wont fall

		if(PlayerPressedJump[playerid] >= 3)
		{
			new Float: POS[3];
			GetPlayerPos(playerid, POS[0], POS[1], POS[2]);
			SetPlayerPos(playerid, POS[0], POS[1], POS[2] - 0.2);
			ApplyAnimationEx(playerid, "PED", "FALL_collapse", 4.1, 0, 1, 0, 0, 0, 1); // applies the fallover animation
			PlayerPlayNearbySound(playerid, 1163);
			PlayerPressedJump[playerid] = 0;
		}
	}

	if(newkeys & KEY_JUMP && !(oldkeys & KEY_JUMP) && !AccountData[playerid][pInjured])
	{
		if(AccountData[playerid][pRFoot] < 50 || AccountData[playerid][pLFoot] < 50)
		{
			ApplyAnimation(playerid, "GYMNASIUM", "gym_jog_falloff", 4.1, 0, 1, 1, 0, 0);
		}
	}

	if(newkeys & KEY_YES && OpenVote == 1 && !PlayerVoting[playerid] && !AccountData[playerid][ActivityTime])
	{

		ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda Setuju untuk Voting yang sedang berjalan");

		PlayerVoting[playerid] = true;
		VoteYes += 1;
		SendClientMessageToAllEx(-1, ""YELLOW"VOTE:"WHITE" %s // Yes: "GREEN"%d"WHITE" // No: "RED"%d", VoteText, VoteYes, VoteNo);
		SendClientMessageToAllEx(-1, "~> Gunakan "GREEN"Y"WHITE" untuk Yes & "RED"N"WHITE" untuk Tidak");
	}

	if(newkeys & KEY_NO && OpenVote == 1 && !PlayerVoting[playerid] && !AccountData[playerid][ActivityTime])
	{

		ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda Tidak Setuju untuk Voting yang sedang berjalan");

		PlayerVoting[playerid] = true;
		VoteNo += 1;
		SendClientMessageToAllEx(-1, ""YELLOW"VOTE:"WHITE" %s // Yes: "GREEN"%d"WHITE" // No: "RED"%d", VoteText, VoteYes, VoteNo);
		SendClientMessageToAllEx(-1, "~> Gunakan "GREEN"Y"WHITE" untuk Yes & "RED"N"WHITE" untuk Tidak");
	}

	if(PRESSED(KEY_ACTION))
	{
		static vehicleid;

		if(IsPlayerInAnyVehicle(playerid) && ((vehicleid = GetPlayerVehicleID(playerid)) != INVALID_VEHICLE_ID))
		{
			if(GetVehicleModel(vehicleid) == 509 || GetVehicleModel(vehicleid) == 481 || GetVehicleModel(vehicleid) == 510)
			{
				new Float:x, Float:y, Float:z;
				GetPlayerPos(playerid, x, y, z);
				SetPlayerPos(playerid, x, y, z);

				ApplyAnimationEx(playerid, "PED", "BIKE_fall_off", 4.1, 0, 1, 1, 1, 0, 1);
			}
		}
	}

	if(newkeys & KEY_JUMP && !(oldkeys & KEY_JUMP) && GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CUFFED && !AccountData[playerid][pInjured])
	{
		ApplyAnimation(playerid, "GYMNASIUM", "gym_jog_falloff", 4.1, 0, 1, 1, 0, 0);
	}
	if(newkeys & KEY_CTRL_BACK)
	{
		if(AccountData[playerid][pInjured])
		{
		    Dialog_Show(playerid, DeathRespawnConf, DIALOG_STYLE_MSGBOX, ""PINK1"DCRP"WHITE"- Konfirmasi Koma",
		    "Apakah anda benar benar yakin ingin melakukan tindakan ini?\n"RED"NOTE: Tindakan ini dapat menghilangkan semua barang di tas termasuk uang cash", "Iya", "Tidak");
		}
	}
	if(newkeys & KEY_SECONDARY_ATTACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
		foreach(new famid : Families)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, FamData[famid][famExtPos][0], FamData[famid][famExtPos][1], FamData[famid][famExtPos][2]))
			{
				if(IsDoorMyFamilie(playerid) == AccountData[playerid][pFamily])
				{
					if(FamData[famid][famIntPos][0] == 0.0 && FamData[famid][famIntPos][1] == 0.0 && FamData[famid][famIntPos][2] == 0.0)
						return ShowTDN(playerid, NOTIFICATION_ERROR, "Interior ini masih kosong!");

					if(AccountData[playerid][pFaction] == FACTION_NONE)
						if(AccountData[playerid][pFamily] == -1)
							return ShowTDN(playerid, NOTIFICATION_ERROR, "Kamu tidak memiliki Akses untuk masuk kedalam sini!");
					
					AccountData[playerid][UsingDoor] = true;
					Player_ToggleTelportAntiCheat(playerid, false);
					SetPlayerPositionEx(playerid, FamData[famid][famIntPos][0], FamData[famid][famIntPos][1], FamData[famid][famIntPos][2], FamData[famid][famIntPos][3], 5000);

					SetPlayerInterior(playerid, FamData[famid][famInterior]);
					SetPlayerVirtualWorld(playerid, famid);
					SetCameraBehindPlayer(playerid);
					SetPlayerWeather(playerid, 0);
					AccountData[playerid][pInFamily] = famid;
				}
				else ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Families ini!");
			}
			new infamily = AccountData[playerid][pInFamily];
			if(AccountData[playerid][pInFamily] != -1 && IsPlayerInRangeOfPoint(playerid, 2.5, FamData[infamily][famIntPos][0], FamData[infamily][famIntPos][1],FamData[infamily][famIntPos][2]))
			{
				AccountData[playerid][pInFamily] = -1;
				AccountData[playerid][UsingDoor] = true;
				Player_ToggleTelportAntiCheat(playerid, false);
				SetPlayerPositionEx(playerid, FamData[infamily][famExtPos][0], FamData[infamily][famExtPos][1], FamData[infamily][famExtPos][2], FamData[infamily][famExtPos][3], 5000);

				SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
				SetCameraBehindPlayer(playerid);
				SetPlayerWeather(playerid, WorldWeather);
				Player_ToggleTelportAntiCheat(playerid, true);
			}
		}
	}
	
	if(newkeys & KEY_LOOK_BEHIND)
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) return 0;

		new vehid = GetNearestVehicleToPlayer(playerid, 3.0, false);
		if(vehid == INVALID_VEHICLE_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada kendaraan apapun di sekitar!");

		foreach(new iter : PvtVehicles)
		{
			if(PlayerVehicle[iter][pVehExists])
			{
				if(PlayerVehicle[iter][pVehPhysic] == vehid)
				{
					if(PlayerVehicle[iter][pVehOwnerID] != AccountData[playerid][pID]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini bukan milik anda!");
					
					PlayerPlaySound(playerid, 1147, 0.0, 0.0, 0.0);
					PlayerVehicle[iter][pVehLocked] = !(PlayerVehicle[iter][pVehLocked]);

					PlayerPlayNearbySound(playerid, SOUND_LOCK_CAR_DOOR);
					LockVehicle(PlayerVehicle[iter][pVehPhysic], PlayerVehicle[iter][pVehLocked]);
					ToggleVehicleLights(PlayerVehicle[iter][pVehPhysic], PlayerVehicle[iter][pVehLocked]);
					ShowPlayerFooter(playerid, sprintf("~w~%s %s", GetVehicleName(PlayerVehicle[iter][pVehPhysic]), PlayerVehicle[iter][pVehLocked] ? ("~r~Terkunci") : ("~g~Terbuka")), 4000);
					return 1;
				}
			}
		}

		if(AccountData[playerid][pJobVehicle] != 0)
		{
			if (vehid == JobVehicle[AccountData[playerid][pJobVehicle]][Vehicle])
			{
				PlayerPlaySound(playerid, 1147, 0.0, 0.0, 0.0);
				JobVehicle[AccountData[playerid][pJobVehicle]][Locked] = !(JobVehicle[AccountData[playerid][pJobVehicle]][Locked]);

				PlayerPlayNearbySound(playerid, SOUND_LOCK_CAR_DOOR);
				LockVehicle(JobVehicle[AccountData[playerid][pJobVehicle]][Vehicle], JobVehicle[AccountData[playerid][pJobVehicle]][Locked]);
				ToggleVehicleLights(JobVehicle[AccountData[playerid][pJobVehicle]][Vehicle], JobVehicle[AccountData[playerid][pJobVehicle]][Locked]);
				ShowPlayerFooter(playerid, sprintf("~w~%s %s", GetVehicleName(JobVehicle[AccountData[playerid][pJobVehicle]][Vehicle]), JobVehicle[AccountData[playerid][pJobVehicle]][Locked] ? ("~r~Terkunci") : ("~g~Terbuka")), 4000);
			}
			return 1;
		}

		if(PlayerElectricJob[playerid][ElectricVehicle] == vehid)
		{
			PlayerPlaySound(playerid, 1147, 0.0, 0.0, 0.0);
			PlayerElectricJob[playerid][ElectricLocked] = !(PlayerElectricJob[playerid][ElectricLocked]);

			PlayerPlayNearbySound(playerid, SOUND_LOCK_CAR_DOOR);
			LockVehicle(PlayerElectricJob[playerid][ElectricVehicle], PlayerElectricJob[playerid][ElectricLocked]);
			ToggleVehicleLights(PlayerElectricJob[playerid][ElectricVehicle], PlayerElectricJob[playerid][ElectricLocked]);
			ShowPlayerFooter(playerid, sprintf("~w~%s %s", GetVehicleName(PlayerElectricJob[playerid][ElectricVehicle]), PlayerElectricJob[playerid][ElectricLocked] ? ("~r~Terkunci") : ("~g~Terbuka")), 4000);
			return 1;
		}
	}
	if(newkeys & KEY_YES)
	{
		if(IsPlayerInjured(playerid))
		{
		    SetPlayerInterior(playerid, 0);
		    SetPlayerVirtualWorld(playerid, 0);
		}
	}
	if((newkeys & KEY_NO) && aOfferID[playerid] == INVALID_PLAYER_ID)
	{
		if (AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Tidak dapat membuka radial saat actvitity berjalan!");
		if (AccountData[playerid][pInjured]) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda tidak ddapat melakukan ini ketika sedang pingsan!");	
		ShowRadialMenu(playerid, true);
	}
	//-----[ Toll System ]-----	
	if(newkeys & KEY_CROUCH)
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			new forcount = MuchNumber(sizeof(BarrierInfo));
			for(new i = 0; i < forcount;i ++)
			{
				if(i < sizeof(BarrierInfo))
				{
					if(IsPlayerInRangeOfPoint(playerid,8.0,BarrierInfo[i][brPos_X],BarrierInfo[i][brPos_Y],BarrierInfo[i][brPos_Z]))
					{
						if(BarrierInfo[i][brOrg] == TEAM_NONE)
						{
							if(!BarrierInfo[i][brOpen])
							{
								if(AccountData[playerid][pMoney] < 50 && !IsVehicleFaction(GetPlayerVehicleID(playerid)))
								{
									ShowTDN(playerid, NOTIFICATION_INFO, "Untuk membayar Toll anda membutuhkan "GREEN"$50");
								}
								else if(IsVehicleFaction(GetPlayerVehicleID(playerid)))
								{
									MoveDynamicObject(gBarrier[i],BarrierInfo[i][brPos_X],BarrierInfo[i][brPos_Y],BarrierInfo[i][brPos_Z]+0.7,BARRIER_SPEED,0.0,0.0,BarrierInfo[i][brPos_A]+180);
									SetTimerEx("BarrierClose",5000,0,"i",i);
									BarrierInfo[i][brOpen] = true;
									ShowTDN(playerid, NOTIFICATION_INFO, "Hati hati dijalan, Pintu akan tertutup selama 5 detik");
									if(BarrierInfo[i][brForBarrierID] != -1)
									{
										new barrierid = BarrierInfo[i][brForBarrierID];
										MoveDynamicObject(gBarrier[barrierid],BarrierInfo[barrierid][brPos_X],BarrierInfo[barrierid][brPos_Y],BarrierInfo[barrierid][brPos_Z]+0.7,BARRIER_SPEED,0.0,0.0,BarrierInfo[barrierid][brPos_A]+180);
										BarrierInfo[barrierid][brOpen] = true;
									}
								}
								else
								{
									MoveDynamicObject(gBarrier[i],BarrierInfo[i][brPos_X],BarrierInfo[i][brPos_Y],BarrierInfo[i][brPos_Z]+0.7,BARRIER_SPEED,0.0,0.0,BarrierInfo[i][brPos_A]+180);
									SetTimerEx("BarrierClose",5000,0,"i",i);
									BarrierInfo[i][brOpen] = true;
									ShowTDN(playerid, NOTIFICATION_INFO, "Hati hati dijalan, Pintu akan tertutup selama 5 detik");
									ShowItemBox(playerid, "Uang", "Removed_$50", 2);
									TakeMoney(playerid, 50);
									if(BarrierInfo[i][brForBarrierID] != -1)
									{
										new barrierid = BarrierInfo[i][brForBarrierID];
										MoveDynamicObject(gBarrier[barrierid],BarrierInfo[barrierid][brPos_X],BarrierInfo[barrierid][brPos_Y],BarrierInfo[barrierid][brPos_Z]+0.7,BARRIER_SPEED,0.0,0.0,BarrierInfo[barrierid][brPos_A]+180);
										BarrierInfo[barrierid][brOpen] = true;
									}
								}
							}
						}
						else ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat membuka toll ini!");
						break;
					}
				}
			}
		}
	}
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	new vehicleid = GetPlayerVehicleID(playerid);
	if((oldstate == PLAYER_STATE_ONFOOT && newstate == PLAYER_STATE_DRIVER) && AccountData[playerid][pTogAutoEngine])
	{
		if(!GetEngineStatus(vehicleid))
		{
			if(IsEngineVehicle(vehicleid) && !IsADealerVehicle(playerid, vehicleid))
			{
				AccountData[playerid][pTurningEngine] = true;
				SetTimerEx("EngineStatus", 2500, false, "id", playerid, vehicleid);
				SendRPMeAboveHead(playerid, "Mencoba menghidupkan mesin kendaraan", X11_PLUM1);
			}
		}
	}
	if(newstate == PLAYER_STATE_WASTED && AccountData[playerid][pJail] < 1)
    {	
		if(IsPlayerInEvent(playerid))
			return 1;

		SetPlayerArmedWeapon(playerid, 0);
		ResetPlayer(playerid);

		if(!AccountData[playerid][pInjured] && !IsPlayerInEvent(playerid))
		{
			AccountData[playerid][pInjured] = 1;
			AccountData[playerid][pInjuredTime] = 3600;
			
			AccountData[playerid][pInt] = GetPlayerInterior(playerid);
			AccountData[playerid][pWorld] = GetPlayerVirtualWorld(playerid);

			GetPlayerPos(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ]);
			GetPlayerFacingAngle(playerid, AccountData[playerid][pPosA]);
		}
	}
	//Spec Player
	if(newstate == PLAYER_STATE_ONFOOT)
	{
		if(AccountData[playerid][playerSpectated] != 0)
		{
			foreach(new ii : Player)
			{
				if(AccountData[ii][pSpec] == playerid)
				{
					PlayerSpectatePlayer(ii, playerid);
					SendClientMessageEx(ii, -1, ""YELLOW"SPEC:"WHITE" %s(%d) sekarang berjalan kaki.", AccountData[playerid][pName], playerid);
				}
			}
		}
	}
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
		if(AccountData[playerid][pInjured] == 1)
        {
            //RemoveFromVehicle(playerid);
			RemovePlayerFromVehicle(playerid);
            SetPlayerHealthEx(playerid, 99999);
        }
		foreach (new ii : Player) if(AccountData[ii][pSpec] == playerid) 
		{
            PlayerSpectateVehicle(ii, GetPlayerVehicleID(playerid));
        }
		//GangZoneHideForPlayer(playerid, GangZoneData[gzSafezone]);
	}
    
	new vehicle_index = -1;
	if((vehicle_index = Vehicle_ReturnID(vehicleid)) != RETURN_INVALID_VEHICLE_ID)
	{
		if((newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER) && PlayerVehicle[vehicle_index][vehAudio])
		{
			PlayVehicleAudio(playerid, vehicle_index);
		}
	}
	
	if((oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER) && AccountData[playerid][pVehAudioPlay])
	{
		StopAudioStreamForPlayer(playerid);
		AccountData[playerid][pVehAudioPlay] = 0;
	}
	if(oldstate == PLAYER_STATE_DRIVER)
    {	
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CARRY || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CUFFED)
            return RemovePlayerFromVehicle(playerid);/*RemoveFromVehicle(playerid);*/
		
		forex(i, 33)
		{
			PlayerTextDrawHide(playerid, SpedoJaden[playerid][i]);
		}
		//GangZoneShowForPlayer(playerid, GangZoneData[gzSafezone], 0x1DF0BB85);
	}
	if(oldstate == PLAYER_STATE_PASSENGER)
	{
		//GangZoneShowForPlayer(playerid, GangZoneData[gzSafezone], 0x1DF0BB85);
	}
	else if(newstate == PLAYER_STATE_DRIVER)
    {	
		static pviterid = -1;

		if((pviterid = Vehicle_Nearest2(playerid)) != -1)
		{
			if(IsABike(PlayerVehicle[pviterid][pVehPhysic]) || GetVehicleModel(PlayerVehicle[pviterid][pVehPhysic]) == 424)
			{
				if(PlayerVehicle[pviterid][pVehLocked])
				{
					RemovePlayerFromVehicle(playerid);
					ClearAnimations(playerid, 1);
					ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini terkunci!");
					return 1;
				}
			}
		}
		if(!IsEngineVehicle(vehicleid))
        {
            SwitchVehicleEngine(vehicleid, true);
        }
		
		forex(i, 33)
		{
			PlayerTextDrawShow(playerid, SpedoJaden[playerid][i]);
		}
		new Float:health;
        GetVehicleHealth(GetPlayerVehicleID(playerid), health);
        VehicleHealthSecurityData[GetPlayerVehicleID(playerid)] = health;
        VehicleHealthSecurity[GetPlayerVehicleID(playerid)] = true;
		
		if(AccountData[playerid][playerSpectated] != 0)
  		{
			foreach(new ii : Player)
			{
    			if(AccountData[ii][pSpec] == playerid)
			    {
        			PlayerSpectateVehicle(ii, vehicleid);
					SendClientMessageEx(ii, -1, ""YELLOW"SPEC:"WHITE" %s(%d) sekarang mengendarai %s(%d).", AccountData[playerid][pName], playerid, GetVehicleModelName(GetVehicleModel(vehicleid)), vehicleid);
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
	if(1 <= weaponid <= 46 && AccountData[playerid][pGuns][g_aWeaponSlots[weaponid]] == weaponid)
	{
		AccountData[playerid][pAmmo][g_aWeaponSlots[weaponid]]--;
		if(AccountData[playerid][pGuns][g_aWeaponSlots[weaponid]] != 0 && !AccountData[playerid][pAmmo][g_aWeaponSlots[weaponid]])
		{
			AccountData[playerid][pGuns][g_aWeaponSlots[weaponid]] = 0;
		}
	}

	if(PlayerHasTazer(playerid) && AccountData[playerid][pFaction] == FACTION_POLISI)
	{
		SetPlayerArmedWeapon(playerid, 0);
		PlayerPlayNearbySound(playerid, 6003);
	}
	return 1;
}

stock GivePlayerHealth(playerid,Float:Health)
{
	new Float:health; GetPlayerHealth(playerid,health);
	SetPlayerHealth(playerid,health+Health);
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
	if(damagedid != INVALID_PLAYER_ID && weaponid == WEAPON_CHAINSAW) {
        TogglePlayerControllable(playerid, 0);
        SetPlayerArmedWeapon(playerid, 0);
        TogglePlayerControllable(playerid, 1);
        SetCameraBehindPlayer(playerid);

        SetPVarInt(playerid, "ChainsawWarning", GetPVarInt(playerid, "ChainsawWarning")+1);

        if(GetPVarInt(playerid, "ChainsawWarning") == 3) {
			SendClientMessageToAllEx(X11_RED, "[AntiCheat]:"YELLOW" %s(%d)"LIGHTGREY" telah ditendang dari server karena Abusing Chainsaw!", ReturnName(playerid), playerid);
            DeletePVar(playerid, "ChainsawWarning");
            KickEx(playerid);
        }
    }
	else if(damagedid != INVALID_PLAYER_ID)
	{
		AccountData[damagedid][pLastShot] = playerid;
		AccountData[damagedid][pShotTime] = gettime();
		if(AccountData[playerid][pFaction] == FACTION_POLISI && PlayerHasTazer(playerid) && !AccountData[damagedid][pStunned])
		{
			if(GetPlayerState(damagedid) != PLAYER_STATE_ONFOOT)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut harus keadaan onfoot untuk dilumpuhkan!");
			
			if(GetPlayerDistanceFromPlayer(playerid, damagedid) > 5.0)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Kamu harus lebih dekat untuk melumpuhkan pemain tersebut!");
			
			AccountData[damagedid][pStunned] = 10;
			TogglePlayerControllable(damagedid, 0);
			
			ApplyAnimation(damagedid, "CRACK", "crckdeth4", 4.0, 0, 0, 0, 1, 0, 1);
			ShowTDN(damagedid, NOTIFICATION_WARNING, "Kamu terkena stun gun / taser!");
		}
	}
	return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
	if(!IsPlayerInEvent(playerid))
	{
		new sakit = RandomEx(1, 4);
		new asakit = RandomEx(1, 5);
		new bsakit = RandomEx(1, 7);
		new csakit = RandomEx(1, 4);
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 9)
		{
			AccountData[playerid][pHead] -= 20;
		}
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 3)
		{
			AccountData[playerid][pPerut] -= sakit;
		}
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 6)
		{
			AccountData[playerid][pRHand] -= bsakit;
		}
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 5)
		{
			AccountData[playerid][pLHand] -= asakit;
		}
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 8)
		{
			AccountData[playerid][pRFoot] -= csakit;
		}
		if(issuerid != INVALID_PLAYER_ID && GetPlayerWeapon(issuerid) && bodypart == 7)
		{
			AccountData[playerid][pLFoot] -= bsakit;	
		}
	}
	if(issuerid != INVALID_PLAYER_ID && bodypart == 3 && weaponid >= 22 && weaponid <= 45)
	{
		static Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		foreach(new i : Player) if (IsPlayerConnected(i)) if (SQL_IsCharacterLogged(i))
		{
			if(AccountData[i][pFaction] == FACTION_POLISI && AccountData[i][pDutyPD])
			{
				SendClientMessageEx(i, X11_ORANGE1, "[WAR ALERT]"WHITE" Terdeteksi penembakan di daerah %s.", GetLocation(x, y, z));
			}
		}
	}
    return 1;
}

ptask Inspike_Timer[1000](playerid)
{
	if(!AccountData[playerid][pSpawned]) 
		return 0;

	static s_Keys, s_UpDown, s_LeftRight;
    GetPlayerKeys( playerid, s_Keys, s_UpDown, s_LeftRight );

    if ( AccountData[playerid][pFreeze] && ( s_Keys || s_UpDown || s_LeftRight ) )
        return 0;

	CheckPlayerInSpike(playerid);
    return 1;
}

task VehicleUpdate[40000]()
{
	foreach(new i: Vehicle) if (IsEngineVehicle(i) && GetEngineStatus(i))
	{
		if (GetFuel(i) > 0)
		{
			VehicleCore[i][vCoreFuel] --;
			if (GetFuel(i) <= 0)
			{
				SwitchVehicleEngine(i, false);
				VehicleCore[i][vCoreFuel] = 0;
			}
		}
		if(GetFuel(i) > 100)
        {
			VehicleCore[i][vCoreFuel] = 100;
		}
	}
	return 1;
}

timer Vehicle_UpdatePosition[2000](vehicleid)
{
	new
		Float:x,
		Float:y,
		Float:z,
		Float:a
	;

	GetVehiclePos(vehicleid, x, y, z);
	GetVehicleZAngle(vehicleid, a);

	SetVehiclePos(vehicleid, x, y, z);
	SetVehicleZAngle(vehicleid, a);
	return 1;
}

public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
	new vehicle_index; // Index = Vehicle id ingame, vehicleid = Index DB
    vehicle_index = Vehicle_ReturnID(vehicleid);
    if(vehicle_index != RETURN_INVALID_VEHICLE_ID)
    {
		new panels, doors, lights, tires;
		GetVehicleDamageStatus(PlayerVehicle[vehicle_index][pVehPhysic], panels, doors, lights, tires);
		if(PlayerVehicle[vehicle_index][pVehBodyUpgrade] == 3 && PlayerVehicle[vehicle_index][pVehBodyRepair] > 0)
		{
			panels = doors = lights = tires = 0;
            UpdateVehicleDamageStatus(PlayerVehicle[vehicle_index][pVehPhysic], panels, doors, lights, tires);
			PlayerVehicle[vehicle_index][pVehBodyRepair] -= 50.0;
		}
		else if(PlayerVehicle[vehicle_index][pVehBodyRepair] <= 0)
		{
			PlayerVehicle[vehicle_index][pVehBodyRepair] = 0;
		}
	}
	if(GetPlayerJob(playerid) == JOB_DRIVER_MIXERS)
	{
		if(jobs::mixer[playerid][mixerSlump] > 0 && IsValidVehicle(vehicleid))
		{
			new rand = RandomEx(2,4);
			jobs::mixer[playerid][mixerSlump]-=rand;

			new Float: progressvalue; 
			progressvalue = jobs::mixer[playerid][mixerSlump]*61/100;
			PlayerTextDrawTextSize(playerid, jobs::PBMixer[playerid][2], progressvalue, 14.0);
			PlayerTextDrawShow(playerid, jobs::PBMixer[playerid][2]);
		}
	}
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	new Float: vhealth;

	AntiCheatGetVehicleHealth(vehicleid, vhealth);
	SetVehicleHealth(vehicleid, vhealth);
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	defer Vehicle_UpdatePosition(vehicleid);

	for (new vid = 1; vid < sizeof(JobVehicle); vid ++) if (JobVehicle[vid][Vehicle] != INVALID_VEHICLE_ID)
	{
		if (vehicleid == JobVehicle[vid][Vehicle])
		{
			foreach(new i : Player)
			{
				if (AccountData[i][pJobVehicle] == JobVehicle[vid][Vehicle])
				{
					if (AccountData[i][pJobVehicle] != 0)
					{
						DestroyJobVehicle(i);
						AccountData[i][pJobVehicle] = 0;
						break;
					}
				}
			}
		}
	}

	foreach(new i : PvtVehicles) if (vehicleid == PlayerVehicle[i][pVehPhysic] && IsValidVehicle(PlayerVehicle[i][pVehPhysic]))
	{
		if (PlayerVehicle[i][pVehRental] == -1)
		{
			PlayerVehicle[i][pVehInsuranced] = true;
			
			foreach(new pid : Player) if(PlayerVehicle[i][pVehOwnerID] == AccountData[pid][pID])
			{
				Syntax(pid, "Kendaraan anda rusak dan sudah dikirimkan ke Asuransi!");
			}
			
			for (new slot = 0; slot < MAX_VEHICLE_OBJECT; slot ++) if (VehicleObjects[i][slot][vehObjectExists])
			{
				if (VehicleObjects[i][slot][vehObject] != INVALID_STREAMER_ID)
					DestroyDynamicObject(VehicleObjects[i][slot][vehObject]);
				
				VehicleObjects[i][slot][vehObject] = INVALID_STREAMER_ID;
			}

			if (IsValidVehicle(PlayerVehicle[i][pVehPhysic]))
				DestroyVehicle(PlayerVehicle[i][pVehPhysic]);
			
			PlayerVehicle[i][pVehPhysic] = INVALID_VEHICLE_ID;
		}
		else
		{
			PlayerVehicle[i][pVehRental] = -1;
			PlayerVehicle[i][pVehRentTime] = 0;
			PlayerVehicle[i][pVehExists] = false;

			foreach(new pid : Player) if(PlayerVehicle[i][pVehOwnerID] == AccountData[pid][pID])
			{
				Info(pid, "Kendaaraanmu rental anda telah hancur. Anda dikenakan denda sebesar "GREEN"%s!", FormatMoney(PlayerVehicle[i][pVehPrice]/2));
				TakeMoney(pid, (PlayerVehicle[i][pVehPrice]/2));
			}

			if(IsValidVehicle(PlayerVehicle[i][pVehPhysic])) 
			{
				DestroyVehicle(PlayerVehicle[i][pVehPhysic]);
				PlayerVehicle[i][pVehPhysic] = INVALID_VEHICLE_ID;
			}

			new cQuery[200];
			mysql_format(dcrp_query, cQuery, sizeof(cQuery), "DELETE FROM `player_vehicles` WHERE `id` = '%d'", PlayerVehicle[i][pVehID]);
			mysql_tquery(dcrp_query, cQuery);

			Vehicle_ResetVariable(i);
			Iter_Remove(PvtVehicles, i);
		}
	}

	//ini untuk menghapus kendaraan yang dispawn oleh admin
	if(VehicleCore[vehicleid][vehAdmin])
	{
		DestroyVehicle(VehicleCore[vehicleid][vehAdminPhysic]);
		VehicleCore[vehicleid][vehAdminPhysic] = INVALID_VEHICLE_ID;
		VehicleCore[vehicleid][vehAdmin] = false;
	}
	return 1;
}

public OnVehicleSirenStateChange(playerid, vehicleid, newstate)
{
	if(newstate)
	{
		SwitchVehicleLight(vehicleid, true);
		vehicleid = GetPlayerVehicleID(playerid);
		
		foreach(new i : PvtVehicles)
		{
			if(vehicleid == PlayerVehicle[i][pVehPhysic])
			{
				if(PlayerVehicle[i][pVehFaction] != FACTION_POLISI && PlayerVehicle[i][pVehFaction] != FACTION_EMS) 
					return 0;

				gToggleELM[vehicleid] = true;
				gELMTimer[vehicleid] = SetTimerEx("ToggleELM", 80, true, "d", vehicleid);
			}
		}
	}
	else 
	{
		static panels, doors, lights, tires;

		gToggleELM[vehicleid] = false;
		KillTimer(gELMTimer[vehicleid]);

		GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
		UpdateVehicleDamageStatus(vehicleid, panels, doors, 0, tires);
	}
	return 1;
}

hook OnVehicleCreated(vehicleid)
{
	TrunkVehEntered[vehicleid] = INVALID_PLAYER_ID;
	return 1;
}

hook OnVehicleDestroyed(vehicleid)
{
	new index = -1;
    new playerid = GetVehicleDriver(vehicleid);
	if((index = Vehicle_GetID(vehicleid)) != -1)
	{
		if(PlayerVehicle[index][vehSirenOn])
		{
			PlayerVehicle[index][vehSirenOn] = false;
			if(IsValidDynamicObject(PlayerVehicle[index][vehSirenObject]))
			{
				DestroyDynamicObject(PlayerVehicle[index][vehSirenObject]);
				PlayerVehicle[index][vehSirenObject] = INVALID_STREAMER_ID;
			}
		}

		if(IsBagasiOpened[PlayerVehicle[index][pVehPhysic]])
		{
			IsBagasiOpened[PlayerVehicle[index][pVehPhysic]] = false;
		}

		if(TrunkVehEntered[PlayerVehicle[index][pVehPhysic]] != INVALID_PLAYER_ID)
		{
			new Float:x, Float:y, Float:z;
			GetVehicleBoot(vehicleid, x, y, z);
			PlayerSpectateVehicle(TrunkVehEntered[PlayerVehicle[index][pVehPhysic]], INVALID_VEHICLE_ID);

			SetSpawnInfo(TrunkVehEntered[PlayerVehicle[index][pVehPhysic]], 0, AccountData[TrunkVehEntered[PlayerVehicle[index][pVehPhysic]]][pSkin], x, y, z, 0.0, 0, 0, 0, 0, 0, 0);
			TogglePlayerSpectating(TrunkVehEntered[PlayerVehicle[index][pVehPhysic]], false);
			SetPVarInt(TrunkVehEntered[PlayerVehicle[index][pVehPhysic]], "PlayerInTrunk", 0);
			AccountData[TrunkVehEntered[PlayerVehicle[index][pVehPhysic]]][pTempVehID] = INVALID_VEHICLE_ID;
			TrunkVehEntered[PlayerVehicle[index][pVehPhysic]] = INVALID_PLAYER_ID;
		}

		for (new slot = 0; slot < MAX_VEHICLE_OBJECT; slot ++) if (VehicleObjects[index][slot][vehObjectExists])
		{
			if (VehicleObjects[index][slot][vehObject] != INVALID_STREAMER_ID)
				DestroyDynamicObject(VehicleObjects[index][slot][vehObject]);
			
			VehicleObjects[index][slot][vehObject] = INVALID_STREAMER_ID;
		}
		
		PlayerVehicle[index][pVehPhysic] = INVALID_VEHICLE_ID;
	}
	if(playerid != INVALID_PLAYER_ID && jobs::mixer[playerid][mixerDuty][0] && IsValidVehicle(jobs::mixer[playerid][mixerVehicle]))
	{
		for(new i; i < 4; i++)
		{
			PlayerTextDrawHide(playerid, jobs::PBMixer[playerid][i]);
        }
		jobs::mixer_reset_enum(playerid);
		ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda berhasil menyelesaikan pekerjaan!");
	}
	if(gToggleELM[vehicleid])
	{
		gToggleELM[vehicleid] = false;
		KillTimer(gELMTimer[vehicleid]);
	}
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	if(AccountData[playerid][pTogAutoEngine] && !IsABicycle(vehicleid))
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			if(GetEngineStatus(vehicleid)) 
			{
				AccountData[playerid][pTempVehID] = vehicleid;
				SetTimerEx("EngineTurnOff", 1500, false, "dd", playerid, vehicleid);
			}
		}
	}
	return 1;
}

forward EngineTurnOff(playerid, vehicleid);
public EngineTurnOff(playerid, vehicleid)
{
	if(AccountData[playerid][pTempVehID] == vehicleid)
	{
		SwitchVehicleEngine(vehicleid, false);
		SendRPMeAboveHead(playerid, "Mesin mati", X11_LIGHTGREEN);	
	
		AccountData[playerid][pTempVehID] = INVALID_VEHICLE_ID;
	}
	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
   	if((AccountData[playerid][pAdmin] >= 1 || AccountData[playerid][pTheStars] >= 1) && AccountData[playerid][pAdminDuty] == 1)
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if(vehicleid > 0 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
        {
            SetVehiclePos(vehicleid, fX, fY, fZ+10);
        }
        else
        {
            SetPlayerPosFindZ(playerid, fX, fY, 999.0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
        }
    }

	if(AccountData[playerid][pAdmin] >= 1 || AccountData[playerid][pTheStars] >= 1)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(vehicleid > 0 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			SetPVarFloat(playerid, "tpX", fX);
			SetPVarFloat(playerid, "tpY", fY);
			SetPVarFloat(playerid, "tpZ", fZ + 5.0);
		}
		else 
		{
			SetPVarFloat(playerid, "tpX", fX);
			SetPVarFloat(playerid, "tpY", fY);
			SetPVarFloat(playerid, "tpZ", fZ);
		}
	}
    return 1;
}

Dialog:DOKUMENT_MENU(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan");
	}

	switch(listitem)
	{
		case 1: // lihat ktp
		{
			if(!AccountData[playerid][Ktp]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki KTP!");
			ShowKTPTD(playerid);
		}
		case 2: // Tunjukan KTP
		{
			if(!AccountData[playerid][Ktp]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki KTP!");
			foreach(new i : Player) if (IsPlayerConnected(i)) if (i != playerid)
			{
				if(IsPlayerNearPlayer(playerid, i, 3.0))
				{
					ShowMyKTPTD(playerid, i);
				}
			}
		}
		case 3: // Lihat SIM
		{
			DisplayLicensi(playerid, playerid);
		}
		case 4: // Tunjukan SIM
		{
			foreach(new i : Player) if (IsPlayerConnected(i)) if (i != playerid)
			{
				if(IsPlayerNearPlayer(playerid, i, 3.0))
				{
					DisplayLicensi(i, playerid);
				}
			}
		}
		case 5: // Lihat SKWB
		{
			if (!AccountData[playerid][pSKWB]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki SKWB!");

			DisplaySKWB(playerid, playerid);
		}
		case 6: // tunjukan SKWB
		{
			if(!AccountData[playerid][pSKWB]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki SKWB!");
			
			foreach(new i : Player) if (IsPlayerConnected(i))
			{
				if(IsPlayerNearPlayer(playerid, i, 3.0))
				{
					DisplaySKWB(playerid, i);
				}
			}
		}

		case 8: //lihat bpjs
		{
			if(!AccountData[playerid][pBPJS]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki BPJS/Expired!");
			DisplayBPJS(playerid, playerid);
		}
		case 9: //tunjukan bpjs
		{
			if(!AccountData[playerid][pBPJS]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki BPJS/Expired!");
			foreach(new i : Player) if (IsPlayerConnected(i)) if (i != playerid)
			{   
				if(IsPlayerNearPlayer(playerid, i, 3.0))
				{
					DisplayBPJS(i, playerid);
				}
			}
		}
		case 10: //lihat skck
		{
			if(!AccountData[playerid][pSKCK]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki SKCK/Expired!");
			DisplaySKCK(playerid, playerid);
		}
		case 11: //tunjuk skck
		{
			if(!AccountData[playerid][pSKCK]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki SKCK/Expired!");
			foreach(new i : Player) if (IsPlayerConnected(i)) if (i != playerid)
			{   
				if(IsPlayerNearPlayer(playerid, i, 3.0))
				{
					DisplaySKCK(i, playerid);
				}
			}
		}
		case 12: //lihat sks
		{
			if(!AccountData[playerid][pSKS]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Surat Keterangan Sehat/Expired!");
			DisplaySKS(playerid, playerid);
		}
		case 13: //tunjuk sks
		{
			if(!AccountData[playerid][pSKS]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Surat Keterangan Sehat/Expired!");
			foreach(new i : Player) if (IsPlayerConnected(i)) if (i != playerid)
			{   
				if(IsPlayerNearPlayer(playerid, i, 3.0))
				{
					DisplaySKS(i, playerid);
				}
			}
		}
	}
	return 1;
}


public OnClickDynamicPlayerTextDraw(playerid, PlayerText: textid)
{
	//innventory
    for(new i = 0; i < 16; i++)
    {
        if(textid == INDEXTD[playerid][i])
        {
            invenPlayed[playerid] = (invenIndex[playerid] - 1) * 16;
            if(InventoryData[playerid][i + invenPlayed[playerid]][invExists])
            {
                InventoryUnSelect(playerid);

                AccountData[playerid][pSelectInv] = i;
                AccountData[playerid][pSelectItem] = i + invenPlayed[playerid];
                InventorySelect(playerid, i);

                PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
                
                new name[48];
                strunpack(name, InventoryData[playerid][i + invenPlayed[playerid]][invItem]);
            }
            else
            {
                if(AccountData[playerid][pSelectItem] != -1)
                {
                    ItemSwitch(playerid, AccountData[playerid][pSelectItem], i + invenPlayed[playerid], AccountData[playerid][pSelectInv]);
                }
            }
        }
    }
    if(textid == INVINFO[playerid][1])
    {
        Inventory_Close(playerid);
    }

    if(textid == INVINFO[playerid][27])
    {
        AccountData[playerid][pUseTextdraw] = 0;

        forex(i, 37)
        {
			if(IsValidDynamicPlayerTextDraw(playerid, INVINFO[playerid][i]))
            	PlayerTextDrawHide(playerid, INVINFO[playerid][i]);
        }
        for (new u = 0; u < 16; u ++)
        {
            PlayerTextDrawHide(playerid, MODELTD[playerid][u]);
            PlayerTextDrawHide(playerid, NAMETD[playerid][u]);
            PlayerTextDrawHide(playerid, AMOUNTTD[playerid][u]);
            PlayerTextDrawHide(playerid, INDEXTD[playerid][u]);
            PlayerTextDrawHide(playerid, GARISBAWAH[playerid][u]);
            PlayerTextDrawColor(playerid, INDEXTD[playerid][u], 1667457892);
        }
        
        Inventory_Show(playerid, playerid, 1);
    }

    if(textid == INVINFO[playerid][28])
    {
        AccountData[playerid][pUseTextdraw] = 0;

        forex(i, 37) 
        {
			if(IsValidDynamicPlayerTextDraw(playerid, INVINFO[playerid][i]))
            	PlayerTextDrawHide(playerid, INVINFO[playerid][i]);
        }
        for (new u = 0; u < 16; u ++) 
        {
            PlayerTextDrawHide(playerid, MODELTD[playerid][u]);
            PlayerTextDrawHide(playerid, NAMETD[playerid][u]);
            PlayerTextDrawHide(playerid, AMOUNTTD[playerid][u]);
            PlayerTextDrawHide(playerid, INDEXTD[playerid][u]);
            PlayerTextDrawHide(playerid, GARISBAWAH[playerid][u]);
            PlayerTextDrawColor(playerid, INDEXTD[playerid][u], 1667457892);
        }
        
        Inventory_Show(playerid, playerid, 2);
    }

    if(textid == INVINFO[playerid][10])
    {
        new id = AccountData[playerid][pSelectItem];

        if(id == -1)
        {
            ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item yang akan digunakan!");
        }
        else
        {
            if(AccountData[playerid][pActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang melakukan sesuatu, harap tunggu!");
            new string[64];
            strunpack(string, InventoryData[playerid][id][invItem]);
            if(!PlayerHasItem(playerid, string))
            {
                ShowTDN(playerid, NOTIFICATION_ERROR, "Anda Tidak Memiliki Barang Tersebut");
            }
            else
            {
                Inventory_Close(playerid);
                CallLocalFunction("OnPlayerUseItem", "dds", playerid, id, string);
            }
        }
    }
    else if(textid == INVINFO[playerid][12])
    {
        // if(IsValidProgressBarTextdraw(playerid))
        //    return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang melakukan sesuatu, harap tunggu!");

        new
            itemid = AccountData[playerid][pSelectItem],
			amount = AccountData[playerid][pAmountInv],
            tstr[32];

        if(itemid == -1)
        {
            ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item yang akan dibuang/dijatuhkan!");
        }
        else
        {
            if (AccountData[playerid][pAmountInv] < 1)
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Masukan Jumlah Terlebih Dahulu!");

            if(IsPlayerInRangeOfPoint(playerid, 200.0, 1690.9669,719.7434,10.8203))
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat drop item di sini!");
                
            strunpack(tstr, InventoryData[playerid][itemid][invItem]);
            if(Inventory_Count(playerid, tstr) < AccountData[playerid][pAmountInv])
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Barang anda tidak mencukupi!");

            new den = TrashNearest(playerid);
            if(den >= 0)
            {
                ApplyAnimation(playerid, "GRENADE", "WEAPON_THROWU", 4.1, 0, 0, 0, 0, 0, 0);

                new mstr[32];
                format(mstr, sizeof(mstr), "Removed_%dx", amount);
                ShowItemBox(playerid, tstr, mstr, 2);
                
                ItemDelete(playerid, tstr, amount);
                Inventory_Close(playerid);
				SendRPMeAboveHead(playerid, sprintf("Membuang %d %s miliknya ke tong sampah", amount, tstr), X11_PLUM1);
            }
			else if(IsPeleburanArea(playerid))
			{
				if(AccountData[playerid][pFaction] != FACTION_POLISI) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota kepolisian!");
				if(AccountData[playerid][pInjured]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang pingsan!");
				if(amount < 1 || amount > InventoryData[playerid][AccountData[playerid][pSelectItem]][invQuantity]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid!");

				ItemDelete(playerid, tstr, amount);
				Inventory_Close(playerid);
				ShowItemBox(playerid, tstr, sprintf("Removed_%dx", amount), 2);
				ApplyAnimation(playerid, "GRENADE", "WEAPON_throwu", 4.1, 0, 0, 0, 0, 0, 1);
				
				SendRPMeAboveHead(playerid, sprintf("Melempar %d %s ke tempat peleburan", amount, tstr), X11_PLUM1);
			}
            else 
            {
                for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if (!strcmp(g_aInventoryItems[i][e_InventoryItem], tstr, true))
                {
                    if(g_aInventoryItems[i][e_InventoryDrop] == false) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak bisa membuang item ini");
					if(!strcmp(tstr, "Radio", true))
					{
						if(ToggleRadio[playerid] || RadioMicOn[playerid])
						{
							ToggleRadio[playerid] = false;
							RadioMicOn[playerid] = false;
							CallRemoteFunction("UpdatePlayerVoiceMicToggle", "dd", playerid, false);
							CallRemoteFunction("UpdatePlayerVoiceRadioToggle", "dd", playerid, false);
							CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, true, 0);
							PlayerTextDrawSetString(playerid, RadioTD[playerid][12], "0");
						}
					}
                    DropPlayerItem(playerid, itemid, amount);
                }
            }
        }
    }
    else if(textid == INVINFO[playerid][13])
    {
        new id = AccountData[playerid][pSelectItem];
		new frmxt[355];
        if(id != -1)
        {
            if (AccountData[playerid][pAmountInv] < 1)
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Masukan Jumlah Terlebih Dahulu");

			new count = 0;
			foreach(new i : Player) if(i != playerid) if(IsPlayerNearPlayer(playerid, i, 2.5))
			{
				format(frmxt, sizeof(frmxt), "%sPlayer ID: %d\n", frmxt, i);
				NearestPlayer[playerid][count++] = i;
			}
			
			if(count == 0)
			{
				PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
				Inventory_Close(playerid);
				return ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""PINK1"FCODE "WHITE"- Give Item",
				"Tidak ada player yang dekat dengan anda!", "Tutup", "");
			}
			else ShowPlayerDialog(playerid, DIALOG_GIVE, DIALOG_STYLE_LIST, ""PINK1"FCODE "WHITE"- Give Item", frmxt, "Pilih", "Close");
            //ShowDialogInteraction(playerid, DIALOG_GIVE, "CityStars {FF0000}/{FFFFFF}/ Inventory");
        }
        else ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item yang akan diberikan!");
    }
    else if(textid == INVINFO[playerid][14])
    {
        CancelSelectTextDraw(playerid);
        ShowPlayerDialog(playerid, DIALOG_AMOUNT, DIALOG_STYLE_INPUT, ""PINK1"FCODE "WHITE"- Set Amount", "Mohon masukan jumlah item yang akan diberikan:", "Berikan", "Batal");
    }
	//=================[ ELEKTRIKAN ]====================
	// Electrician Job TextDraw Handler
	if(textid == KerjaInfo[playerid][23]) // MEMULAI BEKERJA
	{
		if(ToggleElectric == 1) 
		{
			ShowTDN(playerid, NOTIFICATION_ERROR, "Job Electric sedang dimatikan karena alasan tertentu.");
			return 1;
		}
		
		Dialog_Show(playerid, ElectricanMenu, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Electrican Job",
		"Membuat group baru\n\
		Undang ke dalam group\n\
		Keluarkan dari group\n\
		Join Group\n\
		Mulai Pekerjaan\n\
		Berhenti pekerjaan", "Pilih", "Batal");
		
		HideElectricianJobTD(playerid);
		return 1;
	}
	else if(textid == KerjaInfo[playerid][24]) // MENUTUP
	{
		HideElectricianJobTD(playerid);
		return 1;
	}
	//=================[ SUSUSAPI ]====================
	if(textid == SusuInfo[playerid][23]) // MEMULAI KERJA
	{
		
		ShowPlayerDialog(playerid, DIALOG_SUSU_START, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Susu Job",
		"Mulai Perah susu\nSelesaikan Pekerjaan", "Pilih", "Batal");
		
		HideSusuJobTD(playerid);
		return 1;
	}
	else if(textid == SusuInfo[playerid][24]) // MENUTUP
	{
		HideSusuJobTD(playerid);
		return 1;
	}
	//=================[ RADIAL SYSTEMS ]====================
    if(textid == RadialBall[playerid][0])
    {
        ShowRadialMenu(playerid, false);
    }
    if(textid == RadialBall[playerid][1])
    {
		PlayerPlaySound(playerid, 21000, 0.0, 0.0, 0.0);
		ShowRadialMenu(playerid, false);
		callcmd::fashion(playerid);
    }
    //ACTION MENU
    if(textid == RadialBall[playerid][2])
    {
		new frmtx[300], count = 0;

		foreach(new i : Player) if (i != playerid) if (IsPlayerNearPlayer(playerid, i, 2.5))
		{
			format(frmtx, sizeof(frmtx), "%sPlayer ID: %d\n", frmtx, i);
			NearestPlayer[playerid][count++] = i;
		}
			
		if (AccountData[playerid][pFaction] == FACTION_NONE && AccountData[playerid][pFamily] == -1)
		{
			Dialog_Show(playerid, PANEL_NONE, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Menu Warga", "Drag/Undrag Person", "Pilih", "Batal");
			ShowRadialMenu(playerid, false);
		}
		else if (AccountData[playerid][pFaction] == FACTION_TRANS && AccountData[playerid][pFamily] == -1)
		{
			Dialog_Show(playerid, PANEL_NONE, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Menu Warga", "Drag/Undrag Person", "Pilih", "Batal");
			ShowRadialMenu(playerid, false);
		}
		else
		{
			if (count > 0)
			{
				Dialog_Show(playerid, DialogKantongPanel, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE" - Faction Panel", frmtx, "Pilih", "Batal");
			}
			else ShowTDN(playerid, NOTIFICATION_WARNING, "Tidak ada orang disekitar anda!");
			
			return ShowRadialMenu(playerid, false);
		}
		
		if (AccountData[playerid][pFamily] > -1 && AccountData[playerid][pFamilyRank] > 1)
		{
			if (count > 0)
			{
				Dialog_Show(playerid, FamiliesKantongList, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE" - Faction Panel (Gang)", frmtx, "Pilih", "Batal");
			}
			else ShowTDN(playerid, NOTIFICATION_WARNING, "Tidak ada orang disekitar anda!");
			return ShowRadialMenu(playerid, false);
		}
    }
    if(textid == RadialBall[playerid][3])
    {
		new frmxt[355];
        new count = 0;
		foreach(new i : Player) if(i != playerid) if(IsPlayerNearPlayer(playerid, i, 2.5))
        {
			format(frmxt, sizeof(frmxt), "%sPlayer ID: %d\n", frmxt, i);
			NearestPlayer[playerid][count++] = i;
		}
			
		if(count == 0)
		{
			PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
			ShowRadialMenu(playerid, false);
			return ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""PINK1"DCRP"WHITE"Give Money",
			"Tidak ada player yang dekat dengan anda!", "Tutup", "");
		}
		else ShowPlayerDialog(playerid, DIALOG_GIVECASH, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"Give Money", frmxt, "Pilih", "Close");
        ShowRadialMenu(playerid, false);
    }
    if(textid == RadialBall[playerid][4])
    {
		PlayerPlaySound(playerid, 21000, 0.0, 0.0, 0.0);
		ShowRadialMenu(playerid, false);
		ShowingSmartphone(playerid);
    }

    if(textid == RadialBall[playerid][5])
    {
		PlayerPlaySound(playerid, 21000, 0.0, 0.0, 0.0);
		ShowRadialMenu(playerid, false);

		if(AccountData[playerid][ActivityTime] != 0)
		{
			CancelSelectTextDraw(playerid);
			return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, tunggu sampai progress selesai!");
		}
		
		Inventory_Show(playerid, playerid, 1);
		PlayerPlaySound(playerid, 1039, 0.0, 0.0, 0.0);
    }

    if(textid == RadialBall[playerid][6])
    {
        PlayerPlaySound(playerid, 21000, 0.0, 0.0, 0.0);
        ShowRadialMenu(playerid, false);
        new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
        if(vehid == INVALID_VEHICLE_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada kendaraan apapun di sekitar!"), CancelSelectTextDraw(playerid);
            
        static string[178];
        NearestVehicleID[playerid] = vehid;
        format(string, sizeof(string), "Mesin\
        \n"GRAY"Kunci\
        \nLampu\
        \n"GRAY"Hood buka/tutup\
        \nTrunk buka/tutup\
        \n"GRAY"Bagasi\
        \nHolster\
        \n"GRAY"Masuk ke dalam bagasi");
            
        ShowPlayerDialog(playerid, DIALOG_VEHICLE_MENU, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Vehicle Menu",
        string, "Pilih", "Batal");
    }
    if(textid == RadialBall[playerid][7])
    {
        PlayerPlaySound(playerid, 21000, 0.0, 0.0, 0.0);
        ShowRadialMenu(playerid, false);
        Dialog_Show(playerid, DOKUMENT_MENU, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Dokument",
        ""YELLOW"Identitas:\
        \n\n> Lihat KTP\
        \n"GRAY"> Tunjukan KTP\
        \n> Lihat SIM\
        \n"GRAY"> Tunjukan SIM\
        \n> Lihat SKWB\
        \n"GRAY"> Tunjukan SKWB\
        \n\n"YELLOW"Dokument:\
        \n\n> Lihat BPJS\
        \n"GRAY"> Perlihatkan BPJS\
        \n> Lihat SKCK\
        \n"GRAY"> Perlihatkan SKCK\
        \n> Lihat SKS\
        \n"GRAY"> Perlihatkan SKS", "Pilih", "Batal");
    }
	//job mixer
	if(textid == jobs::Pmixer[playerid][5])
	{
		jobs::mixer_select_case(playerid, 1);
	}
	if(textid == jobs::Pmixer[playerid][6])
	{
		jobs::mixer_select_case(playerid, 2);
	}
	if(textid == jobs::Pmixer[playerid][7])
	{
		jobs::mixer_select_case(playerid, 3);
	}
	if(textid == jobs::Pmixer[playerid][8])
	{
		jobs::mixer_select_case(playerid, 4);
	}
	if(textid == jobs::Pmixer[playerid][9])
	{
		jobs::mixer_select_case(playerid, 5);
	}
	if(textid == jobs::Pmixer[playerid][10])//confirm
	{
		jobs::mixer_confirm(playerid);
	}
	//phone_funcs
	
	if(textid == JadenDcrpPhone[playerid][49])
    {
        Toggle_PhoneTD(playerid, false);
        CancelSelectTextDraw(playerid);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        RemovePlayerAttachedObject(playerid, 9);
        AccountData[playerid][phoneShown] = false;
        SendRPMeAboveHead(playerid, "Menutup HP Miliknya.", X11_PLUM1);
    }

    if(textid == JadenDcrpPhone[playerid][38])
    {
        ShowPlayerDialog(playerid, DialogOpenContact, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Kontak", "Tambahkan Kontak Baru\nLihat Daftar Kontak", "Pilih", "Batal");
    }

    if(textid == JadenDcrpPhone[playerid][39])
    {
        if(IsBusWorking(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang bekerja sebagai supir bus!");
        if(DurringSweeping[playerid]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang bekerja sebagai pembersih jalan!");
        if(PlayerKargoVars[playerid][KargoStarted]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang bekerja sebagai Supir Kargo!");

        if(AccountData[playerid][pFaction] == FACTION_EMS && AccountData[playerid][pDutyEms]) 
		{
            Dialog_Show(playerid, GpsMenu, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Menu Gps",
            "Lokasi GPS\n"GRAY"Signal Emergency (EMS)", "Pilih", "Batal");
        } 
		else 
		{
            GPS::Display(playerid);
        }
    }

    if(textid == JadenDcrpPhone[playerid][44])
    {
        new strings[255];
        format(strings, sizeof(strings), "Status: %s\
        \nShare Contacts", AccountData[playerid][AirdropPermission] ? ""LIGHTGREEN"Share Contact diizinkan" : ""RED"Share Contact tidak diizinkan");
        
        ShowPlayerDialog(playerid, DIALOG_AIRDROPDISPLAY, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Airdrop", strings, "Pilih", "Batal");
    }

    if(textid == JadenDcrpPhone[playerid][45])
    {
        Dialog_Show(playerid, SettingPhone, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Pengaturan",
        "Tentang Ponsel\
        \n"GRAY"Ubah Nada Dering Telepon\
        \nHapus Nada Dering\
        \n"GRAY"%s Mode Pesawat", "Pilih", "Batal", AccountData[playerid][phoneAirplaneMode] ? "Matikan" : "Nyalakan");
    }

    if(textid == JadenDcrpPhone[playerid][43])
    {
		if(!AccountData[playerid][IsLoggedIn]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus terkoneksi ke dalam server!");
		if(!GetOwnedVeh(playerid)) return ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""PINK1"DCRP"WHITE"- Kepemilikan Kendaraan", "Anda tidak memiliki kendaraan apapun!", "Tutup", "");

		new count = GetOwnedVeh(playerid);
		static 
			vid,
			list[512],
			CMDString[4056],
			Status1[512],
			StatusSpawn[512],
			PlateStatus[128]
		;

		CMDString = "";
		strcat(CMDString, "VID\tModel(Database ID)\tPlate(Masa Berlaku)\tRental/Status/\n", sizeof(CMDString));
		Loop(itt, (count + 1), 1)
		{
			vid = ReturnPlayerVehID(playerid, itt);

			if(PlayerVehicle[vid][pVehPlateOwn]) {
				format(PlateStatus, sizeof(PlateStatus), "- ("DARKRED"Permanent"WHITE")");
			} else {
				format(PlateStatus, sizeof(PlateStatus), " (Kosong)");
			}

			if(PlayerVehicle[vid][pVehPhysic] == INVALID_VEHICLE_ID) {
				format(StatusSpawn, sizeof(StatusSpawn), "[Despawned]");
			} else {
				format(StatusSpawn, sizeof(StatusSpawn), "%d", PlayerVehicle[vid][pVehPhysic]);
			}

			if(PlayerVehicle[vid][pVehRental] > 0 && PlayerVehicle[vid][pVehRentTime] != 0) {
				new currentTime = PlayerVehicle[vid][pVehRentTime] - gettime();
				new hours = (currentTime % 86400) / 3600;
				new minutes = (currentTime % 3600) / 60;
				new seconds = currentTime % 60;

				format(Status1, sizeof(Status1), "%d Jam %d Menit %d Detik", hours, minutes, seconds);
			} else {
				format(Status1, sizeof(Status1), ""GREEN"Dimiliki");
			}

			if(itt == count)
			{
				format(list, sizeof(list), "%s\t%s [%d]\t%s %s\t%s"WHITE"/%s/\n", StatusSpawn, GetVehicleModelName(PlayerVehicle[vid][pVehModelID]), PlayerVehicle[vid][pVehID], PlayerVehicle[vid][pVehPlate], PlateStatus, Status1, GetMyVehicleStatus(vid, "Spawned"));
			}
			else format(list, sizeof(list), "%s\t%s [%d]\t%s %s\t%s"WHITE"/%s/\n", StatusSpawn, GetVehicleModelName(PlayerVehicle[vid][pVehModelID]), PlayerVehicle[vid][pVehID], PlayerVehicle[vid][pVehPlate], PlateStatus, Status1, GetMyVehicleStatus(vid, "Spawned"));
			strcat(CMDString, list);
		}
		ShowPlayerDialog(playerid, DialogMyVeh, DIALOG_STYLE_TABLIST_HEADERS, ""PINK1"DCRP"WHITE"- Kepemilikan Kendaraan", CMDString, "Cari", "Cancel");
        //callcmd::DCRPkendaraan(playerid, "");
    }

    if(textid == JadenDcrpPhone[playerid][40])
    {
        ShowContactList(playerid);
    }

    if(textid == JadenDcrpPhone[playerid][48])
    {
        Toggle_PhoneTD(playerid, false);
        Toggle_SpotifyTD(playerid, true);
    }

    if(textid == JadenDCRPSpotify[playerid][46])
    {
        Toggle_SpotifyTD(playerid, false);
        Toggle_PhoneTD(playerid, true);
    }

    if(textid == JadenDcrpPhone[playerid][47])
    {
        if(AccountData[playerid][phoneAirplaneMode]) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Smartphone sedang dalam Mode Pesawat!");

        ShowPlayerDialog(playerid, DIALOG_YELLOW_PAGE_MENU, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Yellow Pages",
        "Melihat antrian iklan\nKirim iklan baru", "Pilih", "Batal");
    }

    if(textid == JadenDcrpPhone[playerid][37])
    {
        ShowPlayerDialog(playerid, DialogTelepon, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Telepon", "Mohon masukan nomor telepon yang ingin anda hubungi:", "Telfon", "Batal");
    }

    if(textid == JadenDcrpPhone[playerid][42])
    {
        Toggle_PhoneTD(playerid, false);
        Toggle_BankTD(playerid, true);
    }

    if(textid == JadenDCRPTelponan[playerid][43])
    {
        Toggle_CallTD(playerid, false);
        PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][38]);
        PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][39]);
        PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][43]);
        CancelSelectTextDraw(playerid);
        AccountData[playerid][phoneShown] = false;
    }

    if(textid == JadenDcrpPhone[playerid][46])
    {
        if(AccountData[playerid][phoneAirplaneMode]) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Smartphone sedang dalam Mode Pesawat!");

        if(AccountData[playerid][pTaxiPlayer] != INVALID_PLAYER_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang menjadi penumpang di Trans!");
        
        ShowPlayerDialog(playerid, DIALOG_TRANSORDER, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Pesan Transportasi",
        "Hai, kamu ingin memesan Trans, mau kemana hari ini?", "Input", "Batal");
    }

    if(textid == JadenDCRPBankHP[playerid][54])
    {
        Toggle_BankTD(playerid, false);
        Toggle_PhoneTD(playerid, true);
    }

    if(textid == JadenDCRPXLogin[playerid][39])
    {
        Toggle_TwitterHome(playerid, false);
        Toggle_PhoneTD(playerid, true);
    }
    
    if(textid == JadenDCRPXHome[playerid][41])
    {
        Toggle_TwitterHomepage(playerid, false);
        Toggle_PhoneTD(playerid, true);
    }

    if(textid == JadenDcrpPhone[playerid][41])
    {
        Toggle_PhoneTD(playerid, false);
        if(!AccountData[playerid][Twitter])
        {
            Toggle_TwitterHome(playerid, true);
        }
        else
        {
            Toggle_TwitterHomepage(playerid, true);
        }
    }

    if(textid == JadenDCRPBankHP[playerid][50])
    {
        ShowPlayerDialog(playerid, DialogTransfer, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Transfer", 
        "Mohon masukkan nomor rekening yang ingin anda transfer:", "Submit", "Batal");
    }

    if(textid == JadenDCRPBankHP[playerid][51]) // Invoice
    {
        PlayerPlaySound(playerid, 21000, 0.0, 0.0, 0.0);
        ShowPlayerInvoice(playerid);
    }

    if(textid == JadenDCRPSpotify[playerid][36]) // Earphone
    {
        if(AccountData[playerid][pEarphone] != 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Earphone!");
        
        ShowPlayerDialog(playerid, DialogSpotify, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Spotify", "Matikan Musik\nPutar Musik", "Select", "Cancel");
    }

    if(textid == JadenDCRPSpotify[playerid][37]) // boomboox
    {
        if(!AccountData[playerid][pVip]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan pengguna VIP!");

        if(GetPVarType(playerid, "PlacedBB"))
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.0, GetPVarFloat(playerid, "BBX"), GetPVarFloat(playerid, "BBY"), GetPVarFloat(playerid, "BBZ")))
			{
				ShowPlayerDialog(playerid, DANN_BOOMBOX, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Boombox", "Matikan Boombox\nPutar Musik", "Select", "Cancel");
			}
			else
			{
	   			return ShowTDN(playerid, NOTIFICATION_ERROR, "~g~[!]~w~: Kamu tidak berada didekat boombox mu!");
			}
	    }
	    else
	    {
	    	ShowTDN(playerid, NOTIFICATION_ERROR, "Kamu tidak menaruh boombox sebelumnya!");
		}  
    }

    if(textid == JadenDCRPXLogin[playerid][38]) // Daftar
    {
        if(AccountData[playerid][phoneAirplaneMode]) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Smartphone sedang dalam Mode Pesawat!");

        ShowPlayerDialog(playerid, DIALOG_TWITTER_SIGN, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Daftar Twitter",
        "Hai, selamat datang di Twitter!\
        \nSilahkan masukkan username Twitter kamu, ini akan ditampilkan pada setiap post tweet yang kamu buat:\
        \nIngat: Username hanya dapat berupa huruf dan angka, tidak menggunakan simbol!\
        \nPanjang username 7 - 24 karakter!", "Set", "Batal");
    }

    if(textid == JadenDCRPXLogin[playerid][35]) // Login Jika sudah punya akun twitter
    {
        if(AccountData[playerid][phoneAirplaneMode]) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Smartphone sedang dalam Mode Pesawat!");

        ShowPlayerDialog(playerid, DIALOG_TWITTER_LOGIN, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Login Twitter", 
        "Hai, selamat datang di Twitter!\
        \nSilahkan masukkan username Twitter kamu yang telah terdaftar:", "Input", "Batal");
    }

    if(textid == JadenDCRPXHome[playerid][37]) // Tweet
    {
        if(AccountData[playerid][phoneAirplaneMode]) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Smartphone sedang dalam Mode Pesawat!");

        ShowPlayerTwitterPage(playerid);
        AccountData[playerid][CurrentlyReadTwitter] = true;
    }

    if(textid == JadenDCRPXHome[playerid][38]) // Logout Twitter
    {
        Toggle_TwitterHomepage(playerid, false);
        Toggle_TwitterHome(playerid, true);
        AccountData[playerid][Twitter] = false;
    }

    if(textid == JadenDCRPTelponan[playerid][38])
    {
        foreach(new i : Player) if(IsPlayerConnected(i) && AccountData[i][phoneCallingWithPlayerID] == playerid)
        {
            new phoneCallFromID = i;
            ApplyAnimation(phoneCallFromID, "ped", "phone_out", 4.0, 0, 0, 0, 0, 0, 1);
            RemovePlayerAttachedObject(phoneCallFromID, 9);
            
            ApplyAnimation(playerid, "ped", "phone_out", 4.0, 0, 0, 0, 0, 0, 1);
            RemovePlayerAttachedObject(playerid, 9);

            if(AccountData[playerid][phoneShown]) {
                AccountData[playerid][phoneShown] = false;
            }
            
            if(AccountData[phoneCallFromID][phoneShown]) {
                AccountData[phoneCallFromID][phoneShown] = false;
            }

            HideAllSmartphone(playerid), HideAllSmartphone(phoneCallFromID);
            Toggle_CallTD(playerid, false), Toggle_CallTD(phoneCallFromID, false);
            CancelSelectTextDraw(playerid), CancelSelectTextDraw(phoneCallFromID);
            PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][38]);
            PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][39]);
            PlayerTextDrawHide(phoneCallFromID, JadenDCRPTelponan[playerid][43]);
            StopAudioStreamForPlayer(playerid);
            
            AccountData[playerid][phoneCallingTime] = 0;
            AccountData[playerid][phoneCallingWithPlayerID] = INVALID_PLAYER_ID;
            AccountData[playerid][phoneIncomingCall] = false;
            AccountData[playerid][phoneIncomingCall] = false;
            
            AccountData[phoneCallFromID][phoneCallingTime] = 0;
            AccountData[phoneCallFromID][phoneCallingWithPlayerID] = INVALID_PLAYER_ID;
            AccountData[phoneCallFromID][phoneIncomingCall] = false;
            AccountData[phoneCallFromID][phoneIncomingCall] = false;
        }
    }

    if(textid == JadenDCRPTelponan[playerid][39])
    {
        if(AccountData[playerid][phoneDurringConversation]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang dalam percakapan!");
        if(AccountData[playerid][pInjured]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang pingsan tidak dapat mengangkat panggilan!");
        foreach(new i : Player) if (IsPlayerConnected(i) && AccountData[i][phoneCallingWithPlayerID] == playerid)
        {
            new callingWithPlayerID = i;
            AccountData[playerid][phoneDurringConversation] = true;
            AccountData[playerid][phoneIncomingCall] = false;
            AccountData[playerid][phoneCallingTime] = 0;
            AccountData[playerid][phoneCallingWithPlayerID] = callingWithPlayerID;

            AccountData[callingWithPlayerID][phoneDurringConversation] = true;
            AccountData[callingWithPlayerID][phoneIncomingCall] = false;
            AccountData[callingWithPlayerID][phoneCallingTime] = 0;
            AccountData[callingWithPlayerID][phoneCallingWithPlayerID] = playerid;

            ApplyAnimationEx(playerid, "ped", "phone_talk", 3.1, 0, 1, 0, 1, 1, 1);
            SetPlayerAttachedObject(playerid, 9, 18870, 6,  0.099000, 0.009999, 0.000000,  78.200027, 179.000061, -1.500000,  1.000000, 1.000000, 1.000000); // 276
            
            ApplyAnimationEx(callingWithPlayerID, "ped", "phone_talk", 3.1, 0, 1, 0, 1, 1, 1);
            SetPlayerAttachedObject(callingWithPlayerID, 9, 18870, 6,  0.099000, 0.009999, 0.000000,  78.200027, 179.000061, -1.500000,  1.000000, 1.000000, 1.000000); // 276
            
            static contnstr[25];
            format(contnstr, sizeof(contnstr), "%s", AccountData[callingWithPlayerID][pPhone]);
            for(new cid; cid < MAX_CONTACTS; ++cid)
            {
                if(ContactData[playerid][cid][contactExists])
                {
                    if(!strcmp(ContactData[playerid][cid][contactNumber], AccountData[callingWithPlayerID][pPhone], false))
                    {
                        format(contnstr, sizeof(contnstr), "%s", ContactData[playerid][cid][contactName]);
                    }
                }
            }
            PlayerTextDrawSetString(playerid, JadenDCRPTelponan[playerid][34], contnstr);
            StopAudioStreamForPlayer(playerid);

            HideAllSmartphone(playerid), HideAllSmartphone(callingWithPlayerID);
            PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][39]);
            PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][38]);
            PlayerTextDrawShow(playerid, JadenDCRPTelponan[playerid][43]);
            Toggle_CallTD(playerid, true), Toggle_CallTD(callingWithPlayerID, true);
            CancelSelectTextDraw(playerid), CancelSelectTextDraw(callingWithPlayerID);
            CallRemoteFunction("ConnectPlayerCalling", "dd", playerid, callingWithPlayerID);
        }
    }

    if(textid == JadenDCRPTelponan[playerid][43])
    {
        new callDurringWithPlayerID = AccountData[playerid][phoneCallingWithPlayerID];
        if(!AccountData[playerid][phoneIncomingCall] && callDurringWithPlayerID != INVALID_PLAYER_ID)
        {
            if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
            {
                ClearAnimations(playerid, 1);
                ApplyAnimation(playerid, "ped", "phone_out", 4.0, 0, 0, 0, 0, 0, 1);
            }
            
            if(!IsPlayerInAnyVehicle(callDurringWithPlayerID) && GetPlayerState(callDurringWithPlayerID) == PLAYER_STATE_ONFOOT)
            {
                ClearAnimations(callDurringWithPlayerID, 1);
                ApplyAnimation(callDurringWithPlayerID, "ped", "phone_out", 4.0, 0, 0, 0, 0, 0, 1);
            }
            RemovePlayerAttachedObject(playerid, 9);
            RemovePlayerAttachedObject(callDurringWithPlayerID, 9);
            CallRemoteFunction("DisconnectPlayerCalling", "dd", playerid, callDurringWithPlayerID);

            if(AccountData[playerid][phoneShown]) {
                AccountData[playerid][phoneShown] = false;
            }
            
            if(AccountData[callDurringWithPlayerID][phoneShown]) {
                AccountData[callDurringWithPlayerID][phoneShown] = false;
            }

            HideAllSmartphone(playerid), HideAllSmartphone(callDurringWithPlayerID);
            Toggle_CallTD(playerid, false), Toggle_CallTD(callDurringWithPlayerID, false);
            PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][43]), PlayerTextDrawHide(callDurringWithPlayerID, JadenDCRPTelponan[callDurringWithPlayerID][43]);
            PlayerTextDrawHide(callDurringWithPlayerID, JadenDCRPTelponan[callDurringWithPlayerID][38]), PlayerTextDrawHide(callDurringWithPlayerID, JadenDCRPTelponan[callDurringWithPlayerID][39]);
            CancelSelectTextDraw(playerid), CancelSelectTextDraw(callDurringWithPlayerID);
            StopAudioStreamForPlayer(callDurringWithPlayerID);
            AccountData[playerid][phoneCallingWithPlayerID] = INVALID_PLAYER_ID;
            AccountData[playerid][phoneDurringConversation] = false;
            AccountData[playerid][phoneIncomingCall] = false;
            AccountData[playerid][phoneCallingTime] = 0;
            
            AccountData[callDurringWithPlayerID][phoneCallingWithPlayerID] = INVALID_PLAYER_ID;
            AccountData[callDurringWithPlayerID][phoneDurringConversation] = false;
            AccountData[callDurringWithPlayerID][phoneIncomingCall] = false;
            AccountData[callDurringWithPlayerID][phoneCallingTime] = 0;
            Info(playerid, "Telepon terputus...");
            Info(callDurringWithPlayerID, "Telepon terputus...");
        }
        else
        {
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
            RemovePlayerAttachedObject(playerid, 9);

            if(AccountData[playerid][phoneShown]) {
                AccountData[playerid][phoneShown] = false;
            }
            PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][43]);
            HideAllSmartphone(playerid);
            Toggle_CallTD(playerid, false);
            CancelSelectTextDraw(playerid);
            AccountData[playerid][phoneCallingWithPlayerID] = INVALID_PLAYER_ID;
            AccountData[playerid][phoneDurringConversation] = false;
            AccountData[playerid][phoneIncomingCall] = false;
            AccountData[playerid][phoneCallingTime] = 0;
            Info(playerid, "Nomor tersebut berada di panggilan lain/tidak aktif...");
        }
    }
	//showroom
	new showroomID = GetPVarInt(playerid, "SelectShowroomID");
    if(textid == SVRP_Showroom[playerid][17]) // Next Veh
    {
        if(showroomID != 0)
        {
            if(showroomID == 1) // Truk
            {
                if(SelectVeh[playerid] == sizeof(TrukShowroom) - 1)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] ++;
                VehicleTruckSelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(TrukShowroom[SelectVeh[playerid]]), FormatMoney(TrukCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
            else if(showroomID == 2) // Suv
            {
                if(SelectVeh[playerid] == sizeof(SuvShowroom) - 1)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] ++;
                VehicleSuvSelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(SuvShowroom[SelectVeh[playerid]]), FormatMoney(SuvCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
            else if(showroomID == 3) // Motor
            {
                if(SelectVeh[playerid] == sizeof(MotorShowroom) - 1)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] ++;
                VehicleMotorSelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(MotorShowroom[SelectVeh[playerid]]), FormatMoney(MotorCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
            else if(showroomID == 4) // Low ride
            {
                if(SelectVeh[playerid] == sizeof(ClassicShowroom) - 1)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] ++;
                VehicleLowriderSelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(ClassicShowroom[SelectVeh[playerid]]), FormatMoney(ClassicCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
            else if(showroomID == 5) // Compact
            {
                if(SelectVeh[playerid] == sizeof(CompactShowroom) - 1)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] ++;
                VehicleCompactSelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(CompactShowroom[SelectVeh[playerid]]), FormatMoney(CompactCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
            else if(showroomID == 6) // Luxury
            {
                if(SelectVeh[playerid] == sizeof(LuxuryShowroom) - 1)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] ++;
                VehicleLuxurySelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(LuxuryShowroom[SelectVeh[playerid]]), FormatMoney(LuxuryCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
        }
    }
    else if(textid == SVRP_Showroom[playerid][16]) // Previous veh
    {
        if(showroomID != 0)
        {
            if(showroomID == 1) // truk
            {
                if(SelectVeh[playerid] == 0)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] --;
                VehicleTruckSelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(TrukShowroom[SelectVeh[playerid]]), FormatMoney(TrukCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
            else if(showroomID == 2) // Suv
            {
                if(SelectVeh[playerid] == 0)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] --;
                VehicleSuvSelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(SuvShowroom[SelectVeh[playerid]]), FormatMoney(SuvCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
            else if(showroomID == 3) // Motor
            {
                if(SelectVeh[playerid] == 0)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] --;
                VehicleMotorSelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(MotorShowroom[SelectVeh[playerid]]), FormatMoney(MotorCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
            else if(showroomID == 4) // Lowrider
            {
                if(SelectVeh[playerid] == 0)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] --;
                VehicleLowriderSelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(ClassicShowroom[SelectVeh[playerid]]), FormatMoney(ClassicCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
            else if(showroomID == 5) // Compact
            {
                if(SelectVeh[playerid] == 0)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] --;
                VehicleCompactSelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(CompactShowroom[SelectVeh[playerid]]), FormatMoney(CompactCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
            else if(showroomID == 6) // Luxury
            {
                if(SelectVeh[playerid] == 0)
                {
                    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
                    return 0;
                }
                else SelectVeh[playerid] --;
                VehicleLuxurySelect(playerid);

                PlayerTextDrawSetString(playerid, SVRP_Showroom[playerid][22], sprintf("%s~n~~g~%s", GetVehicleModelName(LuxuryShowroom[SelectVeh[playerid]]), FormatMoney(LuxuryCost(playerid))));
                PlayerTextDrawShow(playerid, SVRP_Showroom[playerid][22]);
            }
        }
    }
    else if(textid == SVRP_Showroom[playerid][14]) // Keluar Showroom
    {
        EnableAntiCheatForPlayer(playerid, 4, true);
        DestroyVehicle(ShowroomVeh[playerid]);
        ShowroomVeh[playerid] = INVALID_VEHICLE_ID;
        for(new i; i < 23; i ++) PlayerTextDrawHide(playerid, SVRP_Showroom[playerid][i]);
        SetPlayerPositionEx(playerid, 1042.3744, 234.2350, 15.5392, 265.1649, 1500);
        SetPlayerVirtualWorld(playerid, 0);
        SetCameraBehindPlayer(playerid);
        SetPVarInt(playerid, "SelectShowroomID", 0);
        SelectVeh[playerid] = 0;
        CancelSelectTextDraw(playerid);
    }
    else if(textid == SVRP_Showroom[playerid][15]) // Buy
    {
        if(showroomID != 0)
        {
            if(showroomID == 1) // Truk
            {
                new count = 0, modelid = TrukShowroom[SelectVeh[playerid]], cost = TrukCost(playerid);
                if(modelid <= 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Model ID Kendaraan tidak valid!");
                if(AccountData[playerid][pMoney] < cost) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak mencukupi!");
                foreach(new iter : PvtVehicles) if (PlayerVehicle[iter][pVehExists])
                {
                    if(PlayerVehicle[iter][pVehOwnerID] == AccountData[playerid][pID])
                    {
                        count ++;
                    }
                }

                if(count >= GetPlayerVehicleLimit(playerid)) return ShowTDN(playerid, NOTIFICATION_WARNING, "Slot kendaraan anda sudah penuh!");
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Pembelian berhasil dilakukan.");
                TakeMoney(playerid, cost);
                ShowroomVehicle_Create(playerid, modelid, 538.3013,-1282.8287,17.2422,270.0565, random(255), random(255), cost);
                static shstr[128];
                format(shstr, sizeof(shstr), "Membeli kendaraan %s seharga %s", GetVehicleModelName(modelid), FormatMoney(cost));
                AddPMoneyLog(AccountData[playerid][pName], AccountData[playerid][pUCP], shstr, cost);
                
                Toggle_ShowroomTD(playerid, false);
                SetPVarInt(playerid, "SelectShowroomID", 0);
                SelectVeh[playerid] = 0;
            }
            else if(showroomID == 2) // Suv
            {
                new count = 0, modelid = SuvShowroom[SelectVeh[playerid]], cost = SuvCost(playerid);
                if(modelid <= 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Model ID Kendaraan tidak valid!");
                if(AccountData[playerid][pMoney] < cost) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak mencukupi!");
                foreach(new iter : PvtVehicles) if (PlayerVehicle[iter][pVehExists])
                {
                    if(PlayerVehicle[iter][pVehOwnerID] == AccountData[playerid][pID])
                    {
                        count ++;
                    }
                }

                if(count >= GetPlayerVehicleLimit(playerid)) return ShowTDN(playerid, NOTIFICATION_WARNING, "Slot kendaraan anda sudah penuh!");
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Pembelian berhasil dilakukan.");
                TakeMoney(playerid, cost);
                ShowroomVehicle_Create(playerid, modelid, 538.3013,-1282.8287,17.2422,270.0565, random(255), random(255), cost);
                static shstr[128];
                format(shstr, sizeof(shstr), "Membeli kendaraan %s seharga %s", GetVehicleModelName(modelid), FormatMoney(cost));
                AddPMoneyLog(AccountData[playerid][pName], AccountData[playerid][pUCP], shstr, cost);
                
                Toggle_ShowroomTD(playerid, false);
                SetPVarInt(playerid, "SelectShowroomID", 0);
                SelectVeh[playerid] = 0;
            }
            else if(showroomID == 3) // Motor
            {
                new count = 0, modelid = MotorShowroom[SelectVeh[playerid]], cost = MotorCost(playerid);
                if(modelid <= 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Model ID Kendaraan tidak valid!");
                if(AccountData[playerid][pMoney] < cost) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak mencukupi!");
                foreach(new iter : PvtVehicles) if (PlayerVehicle[iter][pVehExists])
                {
                    if(PlayerVehicle[iter][pVehOwnerID] == AccountData[playerid][pID])
                    {
                        count ++;
                    }
                }

                if(count >= GetPlayerVehicleLimit(playerid)) return ShowTDN(playerid, NOTIFICATION_WARNING, "Slot kendaraan anda sudah penuh!");
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Pembelian berhasil dilakukan.");
                TakeMoney(playerid, cost);
                ShowroomVehicle_Create(playerid, modelid, 538.3013,-1282.8287,17.2422,270.0565, random(255), random(255), cost);
                static shstr[128];
                format(shstr, sizeof(shstr), "Membeli kendaraan %s seharga %s", GetVehicleModelName(modelid), FormatMoney(cost));
                AddPMoneyLog(AccountData[playerid][pName], AccountData[playerid][pUCP], shstr, cost);
                
                Toggle_ShowroomTD(playerid, false);
                SetPVarInt(playerid, "SelectShowroomID", 0);
                SelectVeh[playerid] = 0;
            }
            else if(showroomID == 4) // Low
            {
                new count = 0, modelid = ClassicShowroom[SelectVeh[playerid]], cost = ClassicCost(playerid);
                if(modelid <= 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Model ID Kendaraan tidak valid!");
                if(AccountData[playerid][pMoney] < cost) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak mencukupi!");
                foreach(new iter : PvtVehicles) if (PlayerVehicle[iter][pVehExists])
                {
                    if(PlayerVehicle[iter][pVehOwnerID] == AccountData[playerid][pID])
                    {
                        count ++;
                    }
                }

                if(count >= GetPlayerVehicleLimit(playerid)) return ShowTDN(playerid, NOTIFICATION_WARNING, "Slot kendaraan anda sudah penuh!");
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Pembelian berhasil dilakukan.");
                TakeMoney(playerid, cost);
                ShowroomVehicle_Create(playerid, modelid, 538.3013,-1282.8287,17.2422,270.0565, random(255), random(255), cost);
                static shstr[128];
                format(shstr, sizeof(shstr), "Membeli kendaraan %s seharga %s", GetVehicleModelName(modelid), FormatMoney(cost));
                AddPMoneyLog(AccountData[playerid][pName], AccountData[playerid][pUCP], shstr, cost);
                
                Toggle_ShowroomTD(playerid, false);
                SetPVarInt(playerid, "SelectShowroomID", 0);
                SelectVeh[playerid] = 0;
            }
            else if(showroomID == 5) // Compact
            {
                new count = 0, modelid = CompactShowroom[SelectVeh[playerid]], cost = CompactCost(playerid);
                if(modelid <= 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Model ID Kendaraan tidak valid!");
                if(AccountData[playerid][pMoney] < cost) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak mencukupi!");
                foreach(new iter : PvtVehicles) if (PlayerVehicle[iter][pVehExists])
                {
                    if(PlayerVehicle[iter][pVehOwnerID] == AccountData[playerid][pID])
                    {
                        count ++;
                    }
                }

                if(count >= GetPlayerVehicleLimit(playerid)) return ShowTDN(playerid, NOTIFICATION_WARNING, "Slot kendaraan anda sudah penuh!");
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Pembelian berhasil dilakukan.");
                TakeMoney(playerid, cost);
                ShowroomVehicle_Create(playerid, modelid, 538.3013,-1282.8287,17.2422,270.0565, random(255), random(255), cost);
                static shstr[128];
                format(shstr, sizeof(shstr), "Membeli kendaraan %s seharga %s", GetVehicleModelName(modelid), FormatMoney(cost));
                AddPMoneyLog(AccountData[playerid][pName], AccountData[playerid][pUCP], shstr, cost);
                
                Toggle_ShowroomTD(playerid, false);
                SetPVarInt(playerid, "SelectShowroomID", 0);
                SelectVeh[playerid] = 0;
            }
            else if(showroomID == 6) // Luxury
            {
                new count = 0, modelid = LuxuryShowroom[SelectVeh[playerid]], cost = LuxuryCost(playerid);
                if(modelid <= 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Model ID Kendaraan tidak valid!");
                if(AccountData[playerid][pMoney] < cost) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak mencukupi!");
                foreach(new iter : PvtVehicles) if (PlayerVehicle[iter][pVehExists])
                {
                    if(PlayerVehicle[iter][pVehOwnerID] == AccountData[playerid][pID])
                    {
                        count ++;
                    }
                }

                if(count >= GetPlayerVehicleLimit(playerid)) return ShowTDN(playerid, NOTIFICATION_WARNING, "Slot kendaraan anda sudah penuh!");
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Pembelian berhasil dilakukan.");
                TakeMoney(playerid, cost);
                ShowroomVehicle_Create(playerid, modelid, 538.3013,-1282.8287,17.2422,270.0565, random(255), random(255), cost);
                static shstr[128];
                format(shstr, sizeof(shstr), "Membeli kendaraan %s seharga %s", GetVehicleModelName(modelid), FormatMoney(cost));
                AddPMoneyLog(AccountData[playerid][pName], AccountData[playerid][pUCP], shstr, cost);
                
                Toggle_ShowroomTD(playerid, false);
                SetPVarInt(playerid, "SelectShowroomID", 0);
                SelectVeh[playerid] = 0;
            }
        }
    }
	//radio
	if(textid == RadioTD[playerid][11]) //set freq
    {   
        ShowPlayerDialog(playerid, DIALOG_RADIO_FREQ, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Radio Fx",
        "Masukkan frekuensi radio yang ingin diterapkan pada kolom dibawah ini\
        \n(Frekuensi harus berada diantara 0 - 9999)\
        \nCatatan: Masukkan frekuensi 0 untuk memutuskan saluran frekuensi/netral", "Submit", "Batal");
    }
    else if(textid == RadioTD[playerid][10]) // Close
    {
        SendRPMeAboveHead(playerid, "Menutup Radio miliknya.", X11_PLUM1);
        if(!IsPlayerInAnyVehicle(playerid))
        {
            ClearAnimations(playerid, 1);
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        }
        RemovePlayerAttachedObject(playerid, 9);
        RadioTextdrawToggle(playerid, false);
        CancelSelectTextDraw(playerid);
    }
    else if(textid == RadioTD[playerid][9]) // Power
    {
        RadioMicOn[playerid] = false;
        CallRemoteFunction("UpdatePlayerVoiceMicToggle", "dd", playerid, false);
        switch(ToggleRadio[playerid])
        {
            case false:
            {
                ToggleRadio[playerid] = true;
                CallRemoteFunction("UpdatePlayerVoiceRadioToggle", "dd", playerid, true);
                if(!IsPlayerInAnyVehicle(playerid))
                {
                    ClearAnimations(playerid, 1);
                    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
                }
                RemovePlayerAttachedObject(playerid, 9);
                ShowTDN(playerid, NOTIFICATION_INFO, "Berhasil menyalakan radio");
                
                CancelSelectTextDraw(playerid);
            }
            case true:
            {
                ToggleRadio[playerid] = false;
                CallRemoteFunction("UpdatePlayerVoiceRadioToggle", "dd", playerid, false);
                if(!IsPlayerInAnyVehicle(playerid))
                {
                    ClearAnimations(playerid, 1);
                    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
                }
                RemovePlayerAttachedObject(playerid, 9);
                ShowTDN(playerid, NOTIFICATION_INFO, "Berhasil mematikan radio");
                
                CancelSelectTextDraw(playerid);
            }
        }
    }
	//toys
	if(textid == P_TOYS[playerid][1]) // X Minus
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_x] -= 0.020;
	
		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][2]) // X Plus
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_x] += 0.020;
		
		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][5]) // Y Plus
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_y] += 0.020;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][7]) // Z Minus
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_z] -= 0.020;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][8]) // Z Plus
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_z] += 0.020;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][10]) // Rot x Minus
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_rx] -= 3.0;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][11]) // Rot x Minus
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_rx] += 3.0;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][13]) // Rot y Minus
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_ry] -= 3.0;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][14]) // Rot y Minus
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_ry] += 3.0;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][16]) // rot z min 
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_rz] -= 3.0;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][17]) // rot z plus 
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_rz] += 3.0;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][19]) // skale x min 
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_sx] -= 0.020;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][20]) // skale x plus
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_sx] += 0.020;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][22]) // skale y min 
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_sy] -= 0.020;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][23]) // skale y plus 
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_sy] += 0.020;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][25]) // skale z min 
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_sz] -= 0.020;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][26]) // skale z plus 
	{
		pToys[playerid][AccountData[playerid][toySelected]][toy_sz] += 0.020;

		SetPlayerAttachedObject(playerid,
			AccountData[playerid][toySelected],
			pToys[playerid][AccountData[playerid][toySelected]][toy_model],
			pToys[playerid][AccountData[playerid][toySelected]][toy_bone],
			pToys[playerid][AccountData[playerid][toySelected]][toy_x],
			pToys[playerid][AccountData[playerid][toySelected]][toy_y],
			pToys[playerid][AccountData[playerid][toySelected]][toy_z],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry],
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy],
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz]);
		
		SetPVarInt(playerid, "UpdatedToy", 1);
	}
	if(textid == P_TOYS[playerid][27]) // Keluar
	{
		HideTDToys(playerid);
		MySQL_SavePlayerToys(playerid);
		ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil menyimpan Kordinat Baru");
	}
	//atm
	if(textid == ATMTD[playerid][77])// Withdraw
	{
		ShowPlayerDialog(playerid, DIALOG_ATM_WITHDRAW, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Fleeca Bank", "Mohon masukan berapa jumlah uang yang anda ingin anda ambil:", "Submit", "Batal");
	}
	if(textid == ATMTD[playerid][80])// Deposit
	{
		ShowPlayerDialog(playerid, DIALOG_ATM_DEPOSIT, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Fleeca Bank", "Mohon masukan berapa jumlah uang yang ingin anda masukkan:", "Submit", "Batal");
	}
	if(textid == ATMTD[playerid][67])// Transfer
	{
		ShowPlayerDialog(playerid, DIALOG_ATM_TRANSFER, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Fleeca Bank", "Mohon masukkan nomor rekening yang ingin anda transfer:", "Submit", "Batal");
	}
	if(textid == ATMTD[playerid][81])// Log Out
	{
		HideATMTD(playerid);
	}
	/* Clothes Sistem */
	if(textid == P_MENUCLOTHES[playerid][0]) // Pakaian
	{
		static Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SetPlayerCameraPos(playerid, x + 0.2, y + 1.4, z + 0.8);
		SetPlayerCameraLookAt(playerid, x, y - 1.0, z + 0.2);
		for(new pdip; pdip < 14; pdip++)
		{
			PlayerTextDrawHide(playerid, P_MENUCLOTHES[playerid][pdip]);
		}

		for(new txd; txd < 16; txd++)
		{
			PlayerTextDrawShow(playerid, P_CLOTHESSELECT[playerid][txd]);
		}
		BuyClothes[playerid] = 1;
		CSelect[playerid] = 0;

		SetPlayerSkin(playerid, (AccountData[playerid][pGender] == 1) ? ClothesSkinMale[CSelect[playerid]] : ClothesSkinFemale[CSelect[playerid]]);

		static minsty[128];
		format(minsty, sizeof minsty, "%02d/%d", CSelect[playerid] + 1, ((AccountData[playerid][pGender] == 1) ? sizeof(ClothesSkinMale) : sizeof(ClothesSkinFemale)));
		PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);

		PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][1], "PAKAIAN");
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
		SelectTextDraw(playerid, 0x72D172FF);
	}
	if(textid == P_MENUCLOTHES[playerid][2]) // Topi Dan Helmet
	{
		static Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SetPlayerCameraPos(playerid, x + 0.2, y + 1.4, z + 1.0);
		SetPlayerCameraLookAt(playerid, x, y - 1.0, z + 0.5);

		for(new txid; txid < 14; txid++)
		{
			PlayerTextDrawHide(playerid, P_MENUCLOTHES[playerid][txid]);
		}
		
		for(new txd; txd < 16; txd++)
		{
			PlayerTextDrawShow(playerid, P_CLOTHESSELECT[playerid][txd]);
		}
		BuyTopi[playerid] = 1;
		SelectAcc[playerid] = 0;

		RemovePlayerAttachedObject(playerid, 0);
		SetPlayerAttachedObject(playerid, 9, AksesorisHat[SelectAcc[playerid]], 2, 0.356, 0.005, -0.004, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);

		static minsty[128];
		format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(AksesorisHat));
		PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);

		PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][1], "TOPI/HELM");
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
		SelectTextDraw(playerid, 0x72D172FF);
	}
	if(textid == P_MENUCLOTHES[playerid][3]) // Kacamata Toys
	{
		static Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SetPlayerCameraPos(playerid, x + 0.2, y + 1.4, z + 1.0);
		SetPlayerCameraLookAt(playerid, x, y - 1.0, z + 0.5);

		for(new txid; txid < 14; txid++)
		{
			PlayerTextDrawHide(playerid, P_MENUCLOTHES[playerid][txid]);
		}
		
		for(new txd; txd < 16; txd++)
		{
			PlayerTextDrawShow(playerid, P_CLOTHESSELECT[playerid][txd]);
		}
		BuyGlasses[playerid] = 1;
		SelectAcc[playerid] = 0;

		RemovePlayerAttachedObject(playerid, 1);
		SetPlayerAttachedObject(playerid, 9, GlassesToys[SelectAcc[playerid]], 2, 0.35, 0.24, -0.19, 0.0, 90.5, 86.0, 1.0, 1.0, 1.0);

		static minsty[128];
		format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(GlassesToys));
		PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);

		PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][1], "KACAMATA");
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
		SelectTextDraw(playerid, COLOR_GREY);
	}
	if(textid == P_MENUCLOTHES[playerid][4]) // Aksesoris
	{
		static Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SetPlayerCameraPos(playerid, x + 0.2, y + 1.6, z + 0.5);
		SetPlayerCameraLookAt(playerid, x, y - 1.0, z);
		
		for(new pdip; pdip < 14; pdip++)
		{
			PlayerTextDrawHide(playerid, P_MENUCLOTHES[playerid][pdip]);
		}

		for(new txd; txd < 16; txd++)
		{
			PlayerTextDrawShow(playerid, P_CLOTHESSELECT[playerid][txd]);
		}
		BuyTAksesoris[playerid] = 1;
		SelectAcc[playerid] = 0;

		RemovePlayerAttachedObject(playerid, 2);
		SetPlayerAttachedObject(playerid, 9, AksesorisToys[SelectAcc[playerid]], 2, -0.392, 0.362, 0.000, 0.000, 0.000, 0.0000, 1.000, 1.000, 1.000);

		static minsty[128];
		format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(AksesorisToys));
		PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
		
		PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][1], "AKSESORIS");
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
		SelectTextDraw(playerid, 0x72D172FF);
	}
	if(textid == P_MENUCLOTHES[playerid][5]) // Tas / Backpack
	{
		static Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SetPlayerCameraPos(playerid, x + 0.2, y + 1.6, z + 0.5);
		SetPlayerCameraLookAt(playerid, x, y - 1.0, z);

		for(new pdip; pdip < 14; pdip++)
		{
			PlayerTextDrawHide(playerid, P_MENUCLOTHES[playerid][pdip]);
		}

		for(new txd; txd < 16; txd++)
		{
			PlayerTextDrawShow(playerid, P_CLOTHESSELECT[playerid][txd]);
		}
		BuyBackpack[playerid] = 1;
		SelectAcc[playerid] = 0;

		RemovePlayerAttachedObject(playerid, 3);
		SetPlayerAttachedObject(playerid, 9, BackpackToys[SelectAcc[playerid]], 2, -0.392, 0.362, 0.000, 0.000, 0.000, 0.0000, 1.000, 1.000, 1.000);

		static minsty[128];
		format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(BackpackToys));
		PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);

		PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][1], "TAS/KOPER");
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
		SelectTextDraw(playerid, 0x72D172FF);
	}
	if(textid == P_MENUCLOTHES[playerid][1]) // Batal
	{
		ShowTDN(playerid, NOTIFICATION_INFO, "Anda membatalkan pilihan");
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, 1);
		for(new txd; txd < 14; txd ++)
		{
			PlayerTextDrawHide(playerid, P_MENUCLOTHES[playerid][txd]);
		}
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
		CancelSelectTextDraw(playerid);
	}
	if(textid == P_CLOTHESSELECT[playerid][12]) // Kembali
	{
		if(BuyClothes[playerid] == 1)
		{
			for(new txd; txd < 16; txd ++)
			{
				PlayerTextDrawHide(playerid, P_CLOTHESSELECT[playerid][txd]);
			}
			SetPlayerCameraFacingStore(playerid);
			BuyClothes[playerid] = 0;
			CSelect[playerid] = 0;
			if(AccountData[playerid][pUsingUniform])
			{
				SetPlayerSkin(playerid, AccountData[playerid][pUniform]);
			}
			else 
			{
				SetPlayerSkin(playerid, AccountData[playerid][pSkin]);
			}
		}

		if(BuyTopi[playerid] == 1)
		{
			for(new txd; txd < 16; txd ++)
			{
				PlayerTextDrawHide(playerid, P_CLOTHESSELECT[playerid][txd]);
			}
			SetPlayerCameraFacingStore(playerid);
			BuyTopi[playerid] = 0;
			SelectAcc[playerid] = 0;
			AttachPlayerToys(playerid);
			RemovePlayerAttachedObject(playerid, 9);
		}

		if(BuyGlasses[playerid] == 1)
		{
			for(new txd; txd < 16; txd ++)
			{
				PlayerTextDrawHide(playerid, P_CLOTHESSELECT[playerid][txd]);
			}
			SetPlayerCameraFacingStore(playerid);
			BuyGlasses[playerid] = 0;
			SelectAcc[playerid] = 0;
			AttachPlayerToys(playerid);
			RemovePlayerAttachedObject(playerid, 9);
		}

		if(BuyTAksesoris[playerid] == 1)
		{
			for(new txd; txd < 16; txd ++)
			{
				PlayerTextDrawHide(playerid, P_CLOTHESSELECT[playerid][txd]);
			}
			SetPlayerCameraFacingStore(playerid);
			BuyTAksesoris[playerid] = 0;
			SelectAcc[playerid] = 0;
			AttachPlayerToys(playerid);
			RemovePlayerAttachedObject(playerid, 9);
		}

		if(BuyBackpack[playerid] == 1)
		{
			for(new txd; txd < 16; txd ++)
			{
				PlayerTextDrawHide(playerid, P_CLOTHESSELECT[playerid][txd]);
			}
			SetPlayerCameraFacingStore(playerid);
			BuyBackpack[playerid] = 0;
			SelectAcc[playerid] = 0;
			AttachPlayerToys(playerid);
			RemovePlayerAttachedObject(playerid, 9);
		}
	}
	if(textid == P_CLOTHESSELECT[playerid][5]) // Next Cloth
	{
		if(BuyClothes[playerid] == 1)
		{
			if(CSelect[playerid] == ((AccountData[playerid][pGender] == 1) ? sizeof(ClothesSkinMale) - 1 : sizeof(ClothesSkinFemale) - 1))
			{
				PlayerPlaySound(playerid, 4203, 0, 0, 0);
				return 0;
			}
			else CSelect[playerid] ++;
			SetPlayerSkin(playerid, (AccountData[playerid][pGender] == 1) ? ClothesSkinMale[CSelect[playerid]] : ClothesSkinFemale[CSelect[playerid]]);
		
			static minsty[128];
			format(minsty, sizeof minsty, "%02d/%d", CSelect[playerid] + 1, ((AccountData[playerid][pGender] == 1) ? sizeof(ClothesSkinMale) : sizeof(ClothesSkinFemale)));
			PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
			ApplyAnimation(playerid, "CLOTHES", "CLO_Pose_Torso", 4.1, 0, 0, 0, 0, 0, 1);
		}

		if(BuyTopi[playerid] == 1)
		{
			if(SelectAcc[playerid] == sizeof(AksesorisHat) - 1)
			{
				PlayerPlaySound(playerid, 4203, 0, 0, 0);
				return 0;
			}
			else SelectAcc[playerid] ++;

			SetPlayerAttachedObject(playerid, 9, AksesorisHat[SelectAcc[playerid]], 2, 0.269, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
			
			static minsty[128];
			format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(AksesorisHat));
			PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
		}

		if(BuyGlasses[playerid] == 1)
		{
			if(SelectAcc[playerid] == sizeof(GlassesToys) - 1)
			{
				PlayerPlaySound(playerid, 4203, 0, 0, 0);
				return 0;
			}
			else SelectAcc[playerid] ++;

			SetPlayerAttachedObject(playerid, 9, GlassesToys[SelectAcc[playerid]], 2, 0.35, 0.24, -0.19, 0.0, 90.5, 86.0, 1.0, 1.0, 1.0);

			static minsty[128];
			format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(GlassesToys));
			PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
		}

		if(BuyTAksesoris[playerid] == 1)
		{
			if(SelectAcc[playerid] == sizeof(AksesorisToys) - 1)
			{
				PlayerPlaySound(playerid, 4203, 0, 0, 0);
				return 0;
			}
			else SelectAcc[playerid] ++;

			SetPlayerAttachedObject(playerid, 9, AksesorisToys[SelectAcc[playerid]], 2, -0.392, 0.362, 0.000, 0.000, 0.000, 0.0000, 1.000, 1.000, 1.000);

			static minsty[128];
			format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(AksesorisToys));
			PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
		}

		if(BuyBackpack[playerid] == 1)
		{
			if(SelectAcc[playerid] == sizeof(BackpackToys) - 1)
			{
				PlayerPlaySound(playerid, 4203, 0, 0, 0);
				return 0;
			}
			else SelectAcc[playerid] ++;

			SetPlayerAttachedObject(playerid, 9, BackpackToys[SelectAcc[playerid]], 2, -0.392, 0.362, 0.000, 0.000, 0.000, 0.0000, 1.000, 1.000, 1.000);

			static minsty[128];
			format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(BackpackToys));
			PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
		}
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
	}
	if(textid == P_CLOTHESSELECT[playerid][4]) // Prev Cloth
	{
		if(BuyClothes[playerid] == 1)
		{
			if(CSelect[playerid] == 0)
			{
				PlayerPlaySound(playerid, 4203, 0, 0, 0);
				return 0;
			}
			else CSelect[playerid] --;
			SetPlayerSkin(playerid, (AccountData[playerid][pGender] == 1) ? ClothesSkinMale[CSelect[playerid]] : ClothesSkinFemale[CSelect[playerid]]);

			static minsty[128];
			format(minsty, sizeof minsty, "%02d/%d", CSelect[playerid] + 1, ((AccountData[playerid][pGender] == 1) ? sizeof(ClothesSkinMale) : sizeof(ClothesSkinFemale)));
			PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
			ApplyAnimation(playerid, "CLOTHES", "CLO_Pose_Torso", 4.1, 0, 0, 0, 0, 0, 1);
		}

		if(BuyTopi[playerid] == 1)
		{
			if(SelectAcc[playerid] == 0)
			{
				PlayerPlaySound(playerid, 4203, 0, 0, 0);
				return 0;
			}
			else SelectAcc[playerid] --;

			SetPlayerAttachedObject(playerid, 9, AksesorisHat[SelectAcc[playerid]], 2, 0.269, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
			
			static minsty[128];
			format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(AksesorisHat));
			PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
		}

		if(BuyGlasses[playerid] == 1)
		{
			if(SelectAcc[playerid] == 0)
			{
				PlayerPlaySound(playerid, 4203, 0, 0, 0);
				return 0;
			}
			else SelectAcc[playerid] --;

			SetPlayerAttachedObject(playerid, 9, GlassesToys[SelectAcc[playerid]], 2, 0.35, 0.24, -0.19, 0.0, 90.5, 86.0, 1.0, 1.0, 1.0);

			static minsty[128];
			format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(GlassesToys));
			PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
		}

		if(BuyTAksesoris[playerid] == 1)
		{
			if(SelectAcc[playerid] == 0)
			{
				PlayerPlaySound(playerid, 4203, 0, 0, 0);
				return 0;
			}
			else SelectAcc[playerid] --;

			SetPlayerAttachedObject(playerid, 9, AksesorisToys[SelectAcc[playerid]], 2, -0.392, 0.362, 0.000, 0.000, 0.000, 0.0000, 1.000, 1.000, 1.000);

			static minsty[128];
			format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(AksesorisToys));
			PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
		}

		if(BuyBackpack[playerid] == 1)
		{
			if(SelectAcc[playerid] == 0)
			{
				PlayerPlaySound(playerid, 4203, 0, 0, 0);
				return 0;
			}
			else SelectAcc[playerid] --;

			SetPlayerAttachedObject(playerid, 9, BackpackToys[SelectAcc[playerid]], 2, -0.392, 0.362, 0.000, 0.000, 0.000, 0.0000, 1.000, 1.000, 1.000);

			static minsty[128];
			format(minsty, sizeof minsty, "%02d/%d", SelectAcc[playerid] + 1, sizeof(BackpackToys));
			PlayerTextDrawSetString(playerid, P_CLOTHESSELECT[playerid][14], minsty);
		}
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
	}
	if(textid == P_CLOTHESSELECT[playerid][8]) // Rot Kiri
	{
		static Float:x, Float:y, Float:z, Float:angle;
		GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, angle);

		SetPlayerPos(playerid, x, y, z);
		SetPlayerFacingAngle(playerid, angle - 15.0);
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
	}
	if(textid == P_CLOTHESSELECT[playerid][9]) // Rot Kanana
	{
		static Float:x, Float:y, Float:z, Float:angle;
		GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, angle);

		SetPlayerPos(playerid, x, y, z);
		SetPlayerFacingAngle(playerid, angle + 15.0);
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
	}
	if(textid == P_CLOTHESSELECT[playerid][2]) // Beli Clothes
	{
		if(BuyClothes[playerid] == 1)
		{
			new price = 200;

			if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang tidak cukup! (Price: $200)");
			TakeMoney(playerid, price);
			ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda membeli baju seharga ~g~$200");
			
			AccountData[playerid][pSkin] = GetPlayerSkin(playerid);
			for(new tx; tx < 16; tx++)
			{
				PlayerTextDrawHide(playerid, P_CLOTHESSELECT[playerid][tx]);
			}
			BuyClothes[playerid] = 0;
			SetPlayerSkin(playerid, AccountData[playerid][pSkin]);
			CancelSelectTextDraw(playerid);
			SetCameraBehindPlayer(playerid);
			TogglePlayerControllable(playerid, 1);
		}

		if(BuyTopi[playerid] == 1)
		{
			AccountData[playerid][toySelected] = 0;

			new price = 80;
			if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang kamu tidak cukup! (Price: $80)");
			TakeMoney(playerid, price);
			pToys[playerid][AccountData[playerid][toySelected]][toy_model] = AksesorisHat[SelectAcc[playerid]];
			pToys[playerid][AccountData[playerid][toySelected]][toy_status] = 1;
			pToys[playerid][AccountData[playerid][toySelected]][toy_x] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_y] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_z] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx] = 1.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy] = 1.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz] = 1.0;
			
			ShowPlayerDialog(playerid, DIALOG_TOYPOSISIBUY, DIALOG_STYLE_LIST, ""DCRP"DCRP"WHITE"- Ubah Tulang(Bone)", 
			"Spine\
			\n"GRAY"Head\
			\nLeft Upper Arm\
			\n"GRAY"Right Upper Arm\
			\nLeft Hand\
			\n"GRAY"Right Hand\
			\nLeft Thigh\
			\n"GRAY"Right Thigh\
			\nLeft Foot\
			\n"GRAY"Right Foot\
			\nRight Calf\
			\n"GRAY"Left Calf\
			\nLeft Forearm\
			\n"GRAY"Right Forearm\
			\nLeft Clavicle\
			\n"GRAY"Right Clavicle\
			\nNeck\
			\n"GRAY"Jaw", "Select", "Cancel");

			SetCameraBehindPlayer(playerid);
			TogglePlayerControllable(playerid, 1);
			ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda membeli Topi seharga ~g~$80");
			for(new txd; txd < 16; txd++)
			{
				PlayerTextDrawHide(playerid, P_CLOTHESSELECT[playerid][txd]);
			}
			BuyTopi[playerid] = 0;
			RemovePlayerAttachedObject(playerid, 9);
			CancelSelectTextDraw(playerid);
		}

		if(BuyGlasses[playerid] == 1)
		{
			AccountData[playerid][toySelected] = 1;

			new price = 50;
			if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang kamu tidak cukup! (Price: $50)");
			TakeMoney(playerid, price);
			pToys[playerid][AccountData[playerid][toySelected]][toy_model] = GlassesToys[SelectAcc[playerid]];
			pToys[playerid][AccountData[playerid][toySelected]][toy_status] = 1;
			pToys[playerid][AccountData[playerid][toySelected]][toy_x] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_y] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_z] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx] = 1.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy] = 1.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz] = 1.0;
			
			ShowPlayerDialog(playerid, DIALOG_TOYPOSISIBUY, DIALOG_STYLE_LIST, ""DCRP"DCRP"WHITE"- Ubah Tulang(Bone)", 
			"Spine\
			\n"GRAY"Head\
			\nLeft Upper Arm\
			\n"GRAY"Right Upper Arm\
			\nLeft Hand\
			\n"GRAY"Right Hand\
			\nLeft Thigh\
			\n"GRAY"Right Thigh\
			\nLeft Foot\
			\n"GRAY"Right Foot\
			\nRight Calf\
			\n"GRAY"Left Calf\
			\nLeft Forearm\
			\n"GRAY"Right Forearm\
			\nLeft Clavicle\
			\n"GRAY"Right Clavicle\
			\nNeck\
			\n"GRAY"Jaw", "Select", "Cancel");

			SetCameraBehindPlayer(playerid);
			TogglePlayerControllable(playerid, 1);
			ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda membeli Kacamata seharga ~g~$50");
			for(new txd; txd < 16; txd++)
			{
				PlayerTextDrawHide(playerid, P_CLOTHESSELECT[playerid][txd]);
			}
			BuyGlasses[playerid] = 0;
			RemovePlayerAttachedObject(playerid, 9);
			CancelSelectTextDraw(playerid);
		}

		if(BuyTAksesoris[playerid] == 1)
		{
			AccountData[playerid][toySelected] = 2;

			new price = 100;
			if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang kamu tidak cukup! (Price: $100)");
			TakeMoney(playerid, price);
			pToys[playerid][AccountData[playerid][toySelected]][toy_model] = AksesorisToys[SelectAcc[playerid]];
			pToys[playerid][AccountData[playerid][toySelected]][toy_status] = 1;
			pToys[playerid][AccountData[playerid][toySelected]][toy_x] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_y] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_z] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx] = 1.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy] = 1.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz] = 1.0;
			
			ShowPlayerDialog(playerid, DIALOG_TOYPOSISIBUY, DIALOG_STYLE_LIST, ""DCRP"DCRP"WHITE"- Ubah Tulang(Bone)", 
			"Spine\
			\n"GRAY"Head\
			\nLeft Upper Arm\
			\n"GRAY"Right Upper Arm\
			\nLeft Hand\
			\n"GRAY"Right Hand\
			\nLeft Thigh\
			\n"GRAY"Right Thigh\
			\nLeft Foot\
			\n"GRAY"Right Foot\
			\nRight Calf\
			\n"GRAY"Left Calf\
			\nLeft Forearm\
			\n"GRAY"Right Forearm\
			\nLeft Clavicle\
			\n"GRAY"Right Clavicle\
			\nNeck\
			\n"GRAY"Jaw", "Select", "Cancel");

			SetCameraBehindPlayer(playerid);
			TogglePlayerControllable(playerid, 1);
			ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda membeli Aksesoris seharga ~g~$100");
			for(new txd; txd < 16; txd++)
			{
				PlayerTextDrawHide(playerid, P_CLOTHESSELECT[playerid][txd]);
			}
			BuyTAksesoris[playerid] = 0;
			RemovePlayerAttachedObject(playerid, 9);
			CancelSelectTextDraw(playerid);
		}

		if(BuyBackpack[playerid] == 1)
		{
			AccountData[playerid][toySelected] = 3;

			new price = 100;
			if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang kamu tidak cukup! (Price: 100)");
			TakeMoney(playerid, price);
			pToys[playerid][AccountData[playerid][toySelected]][toy_model] = BackpackToys[SelectAcc[playerid]];
			pToys[playerid][AccountData[playerid][toySelected]][toy_status] = 1;
			pToys[playerid][AccountData[playerid][toySelected]][toy_x] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_y] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_z] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_rx] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_ry] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_rz] = 0.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sx] = 1.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sy] = 1.0;
			pToys[playerid][AccountData[playerid][toySelected]][toy_sz] = 1.0;
			
			ShowPlayerDialog(playerid, DIALOG_TOYPOSISIBUY, DIALOG_STYLE_LIST, ""DCRP"DCRP"WHITE"- Ubah Tulang(Bone)", 
			"Spine\
			\n"GRAY"Head\
			\nLeft Upper Arm\
			\n"GRAY"Right Upper Arm\
			\nLeft Hand\
			\n"GRAY"Right Hand\
			\nLeft Thigh\
			\n"GRAY"Right Thigh\
			\nLeft Foot\
			\n"GRAY"Right Foot\
			\nRight Calf\
			\n"GRAY"Left Calf\
			\nLeft Forearm\
			\n"GRAY"Right Forearm\
			\nLeft Clavicle\
			\n"GRAY"Right Clavicle\
			\nNeck\
			\n"GRAY"Jaw", "Select", "Cancel");

			SetCameraBehindPlayer(playerid);
			TogglePlayerControllable(playerid, 1);
			ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda membeli Tas seharga ~g~$100");
			for(new txd; txd < 16; txd++)
			{
				PlayerTextDrawHide(playerid, P_CLOTHESSELECT[playerid][txd]);
			}
			BuyBackpack[playerid] = 0;
			RemovePlayerAttachedObject(playerid, 9);
			CancelSelectTextDraw(playerid);
		}
		ApplyAnimation(playerid, "CLOTHES", "CLO_Buy", 4.1, 0, 0, 0, 0, 0, 1);
		PlayerPlaySound(playerid, 1053, 0, 0, 0);
	}
	if(textid == Garage_TD[playerid][29])
	{
		foreach(new gkid : PublicGarage) if(IsPlayerInRangeOfPoint(playerid, 3.5, PublicGarage[gkid][pgPOS][0], PublicGarage[gkid][pgPOS][1], PublicGarage[gkid][pgPOS][2]))
		{
			new i = AccountData[playerid][pTakeVehicle];

			if(PlayerVehicle[i][pVehParked] != -1)
			{
				GetVehicles(i, PublicGarage[gkid][pgSpawnPOS][0], PublicGarage[gkid][pgSpawnPOS][1], PublicGarage[gkid][pgSpawnPOS][2], PublicGarage[gkid][pgSpawnPOS][3]);
				SetTimerEx("ForcedPlayerHopInVehicle", 1500, false, "idd", playerid, PlayerVehicle[i][pVehPhysic], 0);

				forex(a, 31)
				{
					PlayerTextDrawHide(playerid, Garage_TD[playerid][a]);
				}
				CancelSelectTextDraw(playerid);
			}
		}
	}
	if(textid == Garage_TD[playerid][5])
	{
		AccountData[playerid][pUseGarage] = 0;
		forex(a, 31)
		{
			PlayerTextDrawHide(playerid, Garage_TD[playerid][a]);
		}
		CancelSelectTextDraw(playerid);
	}

	if(textid == Garage_TD[playerid][8])
	{
		new vehid = AccountData[playerid][pGarage][0];
		AccountData[playerid][pTakeVehicle] = vehid;

		GarageString(playerid, vehid);
	}

	if(textid == Garage_TD[playerid][12])
	{
		new vehid = AccountData[playerid][pGarage][1];
		AccountData[playerid][pTakeVehicle] = vehid;

		GarageString(playerid, vehid);
	}

	if(textid == Garage_TD[playerid][16])
	{
		new vehid = AccountData[playerid][pGarage][2];
		AccountData[playerid][pTakeVehicle] = vehid;

		GarageString(playerid, vehid);
	}

	if(textid == Garage_TD[playerid][20])
	{
		new vehid = AccountData[playerid][pGarage][3];
		AccountData[playerid][pTakeVehicle] = vehid;

		GarageString(playerid, vehid);
	}
	return 1;
}

RemovePlayerWeapon(playerid, weaponid)
{
	// Reset the player's weapons.
	ResetPlayerWeapons(playerid);
	// Set the armed slot to zero.
	SetPlayerArmedWeapon(playerid, 0);
	// Set the weapon in the slot to zero.
	AccountData[playerid][pGuns][g_aWeaponSlots[weaponid]] = 0;
	AccountData[playerid][pACTime] = gettime() + 2;
	// Set the player's weapons.
	SetWeapons(playerid);
	return 1;
}

SetCameraData(playerid)
{
	switch(random(1))
	{
	    case 0:
	    {
			InterpolateCameraPos(playerid, 425.3333, -1906.5029, 31.1991, 270.8635, -2167.8223, 28.7726, 9000);
			InterpolateCameraLookAt(playerid, 270.8635, -2167.8223, 28.7726, 425.3333, -1906.5029, 31.1991, 9000);
	    }

		case 1:
	    {
			InterpolateCameraPos(playerid, 425.3333, -1906.5029, 31.1991, 270.8635, -2167.8223, 28.7726, 9000);
			InterpolateCameraLookAt(playerid, 270.8635, -2167.8223, 28.7726, 425.3333, -1906.5029, 31.1991, 9000);
	    }
	}
	return 1;
}

stock Float:GetVehicleSpeed(vehicleid)
{
	new Float:x,Float:y,Float:z;
	GetVehicleVelocity(vehicleid,x,y,z);
	return floatmul(VectorSize(x,y,z),170.0);
}

stock SetCinematicCamera(playerid)
{
    static Float:x, Float:y, Float:z, Float:angle;
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, angle);

    new Float:camX, Float:camY, Float:camZ;
    camZ = z + 1.0;

    switch (PlayerCameraView[playerid])
    {
        case 0: // Belakang
        {
            camX = x - (3.0 * floatsin(-angle, degrees));
            camY = y - (3.0 * floatcos(-angle, degrees));
        }
        case 1: // Kanan
        {
            camX = x + (3.0 * floatcos(-angle, degrees));
            camY = y - (3.0 * floatsin(-angle, degrees));
        }
        case 2: // Depan
        {
            camX = x + (3.0 * floatsin(-angle, degrees));
            camY = y + (3.0 * floatcos(-angle, degrees));
        }
        case 3: // Kiri
        {
            camX = x - (3.0 * floatcos(-angle, degrees));
            camY = y + (3.0 * floatsin(-angle, degrees));
        }
    }

    SetPlayerCameraPos(playerid, camX, camY, camZ);      // Posisi kamera
    SetPlayerCameraLookAt(playerid, x, y, z + 1.0);      // Fokus ke pemain
}
