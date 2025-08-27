#include <a_samp>
#include <core>
#include <float>
#include <easyDialog>
#include <sampvoice>
#include <Pawn.CMD>

#define SERVER_NAME "Local Prime Roleplay"
main() {}

#define MAX_FREQUENCY (1000)


#define LIGHTBLUE                    "{EEFF00}"
#define WHITE                        "{FFFFFF}"
#define YELLOW        				 "{C38A39}"
#define GREEN 						 "{0FF903}"

new SV_GSTREAM:RadioFrequency[MAX_FREQUENCY];
new SV_GSTREAM:PhoneFrequency[MAX_FREQUENCY];

new PhoneFreq[MAX_PLAYERS];

new SV_LSTREAM:lstream[MAX_PLAYERS] = { SV_NULL, ... };

enum playerData {
    pToggleRadio,
	pFrequency,
	pRadioTalk,
	pCallLine,
	pIncomingCall,
	pVoicemode
}

new PlayerData[MAX_PLAYERS][playerData];

new CurrentAnim[MAX_PLAYERS];

new PlayerText: voicemenu[MAX_PLAYERS][7];

forward SV_OnPlayerRadioTalk(playerid, playerData:mode);
public SV_OnPlayerRadioTalk(playerid, playerData:mode)
{
    PlayerData[playerid][pRadioTalk] = mode;
	return 1;
}


forward SV_OnPlayerRadio(playerid, playerData:mode, freq);
public SV_OnPlayerRadio(playerid, playerData:mode, freq)
{
	PlayerData[playerid][pFrequency] = freq;
    PlayerData[playerid][pToggleRadio] = mode;
    if(PlayerData[playerid][pToggleRadio])
    {
        
		SvAttachListenerToStream(RadioFrequency[PlayerData[playerid][pFrequency]], playerid);
    }
    else
    {
        SvDetachListenerFromStream(RadioFrequency[PlayerData[playerid][pFrequency]], playerid);
    }
	return 1;
}

SendClientMessageEx(playerid, color, const text[], {Float, _}:...)
{
    static
        args,
            str[144];

    if((args = numargs()) == 3)
    {
            SendClientMessage(playerid, color, text);
    }
    else
    {
        while (--args >= 3)
        {
            #emit LCTRL 5
            #emit LOAD.alt args
            #emit SHL.C.alt 2
            #emit ADD.C 12
            #emit ADD
            #emit LOAD.I
            #emit PUSH.pri
        }
        #emit PUSH.S text
        #emit PUSH.C 144
        #emit PUSH.C str
        #emit PUSH.S 8
        #emit SYSREQ.C format
        #emit LCTRL 5
        #emit SCTRL 4

        SendClientMessage(playerid, color, str);

        #emit RETN
    }
    return 1;
}


forward SV_CancelCall(playerid, targetid, frequency);
public SV_CancelCall(playerid, targetid, frequency)
{
	PhoneFreq[playerid] = frequency;
	PhoneFreq[targetid] = frequency;

	PlayerData[playerid][pCallLine] = INVALID_PLAYER_ID;
	PlayerData[targetid][pCallLine] = INVALID_PLAYER_ID;

	PlayerData[playerid][pIncomingCall] = 0;
	PlayerData[targetid][pIncomingCall] = 0;

	SvDetachListenerFromStream(PhoneFrequency[frequency], playerid);
	SvDetachListenerFromStream(PhoneFrequency[frequency], targetid);

	SvDetachSpeakerFromStream(PhoneFrequency[frequency], playerid);
	SvDetachSpeakerFromStream(PhoneFrequency[frequency], targetid);

	SendClientMessageEx(playerid, -1, "[DEBUG] Telah menutup handphone dari id %d (frequency: %d)", targetid, frequency);
	SendClientMessageEx(targetid, -1, "[DEBUG] Telah menutup handphone dari id %d (frequency: %d)", playerid, frequency);
	return 1;
}

forward SV_OnPlayerPhone(playerid, targetid, frequency);
public SV_OnPlayerPhone(playerid, targetid, frequency)
{
	PlayerData[playerid][pCallLine] = targetid;
	PlayerData[targetid][pCallLine] = targetid;
	PhoneFreq[playerid] = frequency;
	PhoneFreq[targetid] = frequency;

	SvAttachListenerToStream(PhoneFrequency[PhoneFreq[playerid]], playerid);
	SvAttachListenerToStream(PhoneFrequency[PhoneFreq[playerid]], targetid);

	SendClientMessageEx(playerid, -1, "[DEBUG] Telah tersambung ke frekuensi phone id %d (frequency: %d)", targetid, frequency);
	SendClientMessageEx(targetid, -1, "[DEBUG] Telah tersambung ke frekuensi phone id %d (frequency: %d)", playerid, frequency);
	return 1;
}

public SV_VOID:OnPlayerActivationKeyPress(SV_UINT:playerid, SV_UINT:keyid) 
{
	if(keyid == 0x42)
	{
		if(PlayerData[playerid][pCallLine] != INVALID_PLAYER_ID && !PlayerData[playerid][pIncomingCall])
		{
			SetPlayerChatBubble(playerid, ""WHITE"(( Cellphone ))", 0xFFFF00AA, 10.0, 60000);
			SvAttachSpeakerToStream(PhoneFrequency[PhoneFreq[playerid]], playerid);
		}
		if (keyid == 0x42 && PlayerData[playerid][pToggleRadio] == 1 && PlayerData[playerid][pRadioTalk] && RadioFrequency[PlayerData[playerid][pFrequency]] >= 1)
		{
			if(GetPlayerAnimationIndex(playerid) == 1275 || GetPlayerAnimationIndex(playerid) == 1189)
			{
				CurrentAnim[playerid] = 1;
				ApplyAnimation(playerid, "ped", "phone_talk", 4.1, 0, 1, 1, 1, 1, 1);
			}
			else
			{
				CurrentAnim[playerid] = 0;
			}
			
			if(!IsPlayerAttachedObjectSlotUsed(playerid, 9)) SetPlayerAttachedObject(playerid, 9, 18868, 6, 0.0789, 0.0050, -0.0049, 84.9999, -179.2999, -1.6999, 1.0000, 1.0000, 1.0000);

			for(new i = GetPlayerPoolSize(); i != -1; --i)
			{
				if(IsPlayerConnected(i))
				{
					if(PlayerData[i][pFrequency] == PlayerData[playerid][pFrequency] && PlayerData[i][pToggleRadio] == 1)
					{
						new Float:x, Float:y, Float:z;
						GetPlayerPos(i, Float:x, Float:y, Float:z);
						PlayerPlaySound(i, 21000, Float:x, Float:y, Float:z);
						SetTimerEx("RadioSound", 300, false, "d", i);
					}
				}
			}
			SetPlayerChatBubble(playerid, ""YELLOW"[Radio]", 0x87CEEBAA, 10.0, 60000);
			SvAttachSpeakerToStream(RadioFrequency[PlayerData[playerid][pFrequency]], playerid);
		}

		if (keyid == 0x42 && !PlayerData[playerid][pRadioTalk] && lstream[playerid])
		{ 
			SvAttachSpeakerToStream(lstream[playerid], playerid);
			SetPlayerChatBubble(playerid, ""GREEN" Talking...", 0xFFFF00AA, 10.0, 60000);
		}
	}
}

forward RadioSound(playerid);
public RadioSound(playerid)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, Float:x, Float:y, Float:z);
	PlayerPlaySound(playerid, 21000, Float:x, Float:y, Float:z);
	return 1;
}

public SV_VOID:OnPlayerActivationKeyRelease(SV_UINT:playerid, SV_UINT:keyid) 
{
	if (keyid == 0x42 && PlayerData[playerid][pCallLine] != INVALID_PLAYER_ID && !PlayerData[playerid][pIncomingCall])
	{
		SetPlayerChatBubble(playerid, "", -1, 10.0, 5000);
		SvDetachSpeakerFromStream(PhoneFrequency[PhoneFreq[playerid]], playerid);	
	}
	if (keyid == 0x42 && PlayerData[playerid][pToggleRadio] == 1 && PlayerData[playerid][pRadioTalk] && RadioFrequency[PlayerData[playerid][pFrequency]] >= 1)
	{
		SetPlayerChatBubble(playerid, "", -1, 10.0, 5000);
		SvDetachSpeakerFromStream(RadioFrequency[PlayerData[playerid][pFrequency]], playerid);

		if(!IsPlayerInAnyVehicle(playerid))
		{
			ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
			// SetTimerEx("SafeClearAnim", 250, 0, "i", playerid);
		}

		if(IsPlayerAttachedObjectSlotUsed(playerid, 9)) RemovePlayerAttachedObject(playerid, 9);
	}
	if (keyid == 0x42 && lstream[playerid]) SvDetachSpeakerFromStream(lstream[playerid], playerid), SetPlayerChatBubble(playerid, "", -1, 10.0, 5000);
}

forward SafeClearAnim(playerid);
public SafeClearAnim(playerid)
{
	ClearAnimations(playerid, 1);
} 

public OnPlayerSpawn(playerid)
{
	for(new i = 0; i < 2; i++)
	PlayerTextDrawShow(playerid, voicemenu[playerid][i]);
	PlayerTextDrawShow(playerid, voicemenu[playerid][6]);
	return 1;
}

public OnPlayerConnect(playerid) {

	CheckVoicePlugins(playerid);
	CreateAllPTextdraw(playerid);

	PhoneFreq[playerid] = 0;
    PlayerData[playerid][pToggleRadio] = 0;
	PlayerData[playerid][pFrequency] = 0;
	PlayerData[playerid][pRadioTalk] = 0;
	PlayerData[playerid][pCallLine] = INVALID_PLAYER_ID;
	PlayerData[playerid][pIncomingCall] = 0;
	PlayerData[playerid][pVoicemode] = 0;

	return 1;
}

stock KickEx(playerid)
{
	SetTimerEx("KickPlayer", 400, false, "d", playerid);
	return 1;
}

forward KickPlayer(playerid);
public KickPlayer(playerid)
{
	Kick(playerid);
}
stock CheckVoicePlugins(playerid)
{
	if (!SvGetVersion(playerid))
	{
		Dialog_Show(playerid, DIALOG_VOICE_ERROR, DIALOG_STYLE_MSGBOX, ""LIGHTBLUE""SERVER_NAME""WHITE" - Penjaga", "{FF0000}Untuk bermain di server Local Prime diwajibkan untuk menginstal plugins sampvoice\n\nOfficial Discord @: {FFFF00}https://discord.gg/localprimerp", "Close", "");

		KickEx(playerid);
	}
	else if (!SvHasMicro(playerid))
	{
		Dialog_Show(playerid, DIALOG_VOICE_ERROR, DIALOG_STYLE_MSGBOX, ""LIGHTBLUE""SERVER_NAME""WHITE" - Penjaga", "{FF0000}Untuk bermain di server Local Prime diwajibkan untuk menggunakan microphone\n\nOfficial Discord @: {FFFF00}https://discord.gg/localprimerp", "Close", "");
		KickEx(playerid);
	}
	if ((lstream[playerid] = SvCreateDLStreamAtPlayer(15.0, SV_INFINITY, playerid, 0xff0000ff, "L")))
	{
		PhoneFreq[playerid] = 0;
		PlayerData[playerid][pToggleRadio] = 0;
		PlayerData[playerid][pFrequency] = 0;
		PlayerData[playerid][pRadioTalk] = 0;
		PlayerData[playerid][pCallLine] = INVALID_PLAYER_ID;
		PlayerData[playerid][pIncomingCall] = 0;
		SvAddKey(playerid, 0x42);
	}
	return 1;
}

YCMD:sv(playerid, params[])
{
    Dialog_Show(playerid, DIALOG_VOICE_MODE, DIALOG_STYLE_TABLIST, ""LIGHTBLUE""SERVER_NAME""WHITE" - Voice Mode", "Berbisik (5.0 Meters)\nNormal (15.00 Meters)\nTeriak (35.00 Meters)", "Pilih", "Keluar");
    return 1;
}

Dialog:DIALOG_VOICE_MODE(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            lstream[playerid] = SvCreateDLStreamAtPlayer(10.0, SV_INFINITY, playerid, 0xff0000ff, "L");
			SendClientMessageEx(playerid, -1, "{90EE90}[Info]"WHITE" Kamu telah mengubah mode voice ke berbisik.");
			PlayerTextDrawSetString(playerid, voicemenu[playerid][6],"Low"); 
			PlayerTextDrawShow(playerid, voicemenu[playerid][3]);
			PlayerData[playerid][pVoicemode] = 0;
        }
        case 1:
        {
            lstream[playerid] = SvCreateDLStreamAtPlayer(15.0, SV_INFINITY, playerid, 0xff0000ff, "L");
            SendClientMessageEx(playerid, -1, "{90EE90}[Info]"WHITE" Kamu telah mengubah mode voice ke normal.");
			PlayerTextDrawSetString(playerid, voicemenu[playerid][6],"Medium"); 
			PlayerTextDrawShow(playerid, voicemenu[playerid][4]);
			PlayerData[playerid][pVoicemode] = 1;
        }
        case 2:
        {
            lstream[playerid] = SvCreateDLStreamAtPlayer(20.0, SV_INFINITY, playerid, 0xff0000ff, "L");
            SendClientMessageEx(playerid, -1, "{90EE90}[Info]"WHITE" Kamu telah mengubah mode voice ke berteriak.");
			PlayerTextDrawSetString(playerid, voicemenu[playerid][6],"High"); 
			PlayerTextDrawShow(playerid, voicemenu[playerid][5]);
			PlayerData[playerid][pVoicemode] = 2;
        }
    }
    return 1;
}

public OnPlayerDisconnect(playerid, reason) 
{
	PhoneFreq[playerid] = 0;
    PlayerData[playerid][pToggleRadio] = 0;
	PlayerData[playerid][pFrequency] = 0;
	PlayerData[playerid][pRadioTalk] = 0;
	PlayerData[playerid][pCallLine] = INVALID_PLAYER_ID;
	PlayerData[playerid][pIncomingCall] = 0;
	return 1;
}

public OnFilterScriptInit() {
	SvDebug(SV_TRUE);
	
	for(new i; i < MAX_FREQUENCY; i++)
    {        
        RadioFrequency[i] = SvCreateGStream(0xffff0000, "Radio");
    }
	for(new i; i < MAX_FREQUENCY; i++)
	{
		PhoneFrequency[i] = SvCreateGStream(0xffff0000, "Telpon");
	}
	return 1;
	
}

stock CreateAllPTextdraw(playerid)
{
	voicemenu[playerid][0] = CreatePlayerTextDraw(playerid, 621.000, 432.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, voicemenu[playerid][0], 9.000, 11.000);
	PlayerTextDrawAlignment(playerid, voicemenu[playerid][0], 1);
	PlayerTextDrawColor(playerid, voicemenu[playerid][0], 100);
	PlayerTextDrawSetShadow(playerid, voicemenu[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, voicemenu[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, voicemenu[playerid][0], 255);
	PlayerTextDrawFont(playerid, voicemenu[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, voicemenu[playerid][0], 1);

	voicemenu[playerid][1] = CreatePlayerTextDraw(playerid, 611.000, 432.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, voicemenu[playerid][1], 9.000, 11.000);
	PlayerTextDrawAlignment(playerid, voicemenu[playerid][1], 1);
	PlayerTextDrawColor(playerid, voicemenu[playerid][1], 100);
	PlayerTextDrawSetShadow(playerid, voicemenu[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, voicemenu[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, voicemenu[playerid][1], 255);
	PlayerTextDrawFont(playerid, voicemenu[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, voicemenu[playerid][1], 1);

	voicemenu[playerid][2] = CreatePlayerTextDraw(playerid, 601.000, 432.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, voicemenu[playerid][2], 9.000, 11.000);
	PlayerTextDrawAlignment(playerid, voicemenu[playerid][2], 1);
	PlayerTextDrawColor(playerid, voicemenu[playerid][2], 100);
	PlayerTextDrawSetShadow(playerid, voicemenu[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, voicemenu[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, voicemenu[playerid][2], 255);
	PlayerTextDrawFont(playerid, voicemenu[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, voicemenu[playerid][2], 1);

	voicemenu[playerid][3] = CreatePlayerTextDraw(playerid, 601.000, 432.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, voicemenu[playerid][3], 9.000, 11.000);
	PlayerTextDrawAlignment(playerid, voicemenu[playerid][3], 1);
	PlayerTextDrawColor(playerid, voicemenu[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, voicemenu[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, voicemenu[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, voicemenu[playerid][3], 255);
	PlayerTextDrawFont(playerid, voicemenu[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, voicemenu[playerid][3], 1);

	voicemenu[playerid][4] = CreatePlayerTextDraw(playerid, 611.000, 432.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, voicemenu[playerid][4], 9.000, 11.000);
	PlayerTextDrawAlignment(playerid, voicemenu[playerid][4], 1);
	PlayerTextDrawColor(playerid, voicemenu[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, voicemenu[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, voicemenu[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, voicemenu[playerid][4], 255);
	PlayerTextDrawFont(playerid, voicemenu[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, voicemenu[playerid][4], 1);

	voicemenu[playerid][5] = CreatePlayerTextDraw(playerid, 621.000, 432.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, voicemenu[playerid][5], 9.000, 11.000);
	PlayerTextDrawAlignment(playerid, voicemenu[playerid][5], 1);
	PlayerTextDrawColor(playerid, voicemenu[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, voicemenu[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, voicemenu[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, voicemenu[playerid][5], 255);
	PlayerTextDrawFont(playerid, voicemenu[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, voicemenu[playerid][5], 1);

	voicemenu[playerid][6] = CreatePlayerTextDraw(playerid, 581.000, 433.000, "Normal");
	PlayerTextDrawLetterSize(playerid, voicemenu[playerid][6], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, voicemenu[playerid][6], 1);
	PlayerTextDrawColor(playerid, voicemenu[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, voicemenu[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, voicemenu[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, voicemenu[playerid][6], 150);
	PlayerTextDrawFont(playerid, voicemenu[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, voicemenu[playerid][6], 1);
	return 1;
}