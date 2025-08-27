#define FILTERSCRIPT

#include <a_samp>
#include <sampvoice>
#include <sscanf2>
#include <Pawn.CMD>
#include <textdraw-streamer>
#include <ui-notifications>

enum
{
    DIALOG_NANDA,
    DIALOG_VOICEMODE,
    DIALOG_NONE,
}

#define function%0(%1) forward %0(%1); public %0(%1)
#define     MAX_FREQUENSI   99999
#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

new SV_LSTREAM:localStream[MAX_PLAYERS] = SV_NULL;
new SV_GSTREAM:radioStream[MAX_FREQUENSI] = SV_NULL;
new PlayerText:RadioTD[MAX_PLAYERS][11];
new PlayerText:RadiopTD[MAX_PLAYERS][2];
new FreqRadio[MAX_PLAYERS];
new TogMic[MAX_PLAYERS];
new TogRadio[MAX_PLAYERS];

main()
{

}

public OnFilterScriptInit()
{
    for(new i = 0; i < MAX_FREQUENSI; i++)
    {
        radioStream[i] = SvCreateGStream(0xDB881AFF, "Radio");
    }
    return 1;
}

public SV_VOID:OnPlayerActivationKeyPress(SV_UINT:playerid, SV_UINT:keyid)
{
    new str[200];
    if(keyid == 0x42 && FreqRadio[playerid] >= 1 && TogMic[playerid] == 1 && TogRadio[playerid] == 1)
    {
        PlayerPlaySound(playerid, 41603, 0.0, 0.0, 0.0);
        ApplyAnimation(playerid, "ped", "phone_talk", 4.1, 1, 1, 1, 1, 1, 1);
        if(!IsPlayerAttachedObjectSlotUsed(playerid, 9)) SetPlayerAttachedObject(playerid, 9, 19942, 2, 0.0300, 0.1309, -0.1060, 118.8998, 19.0998, 164.2999);
        
        format(str, sizeof(str), "{FF8B06}> RADIO <");
        SetPlayerChatBubble(playerid, str, -1, 20.0, 1000000);
        SvAttachSpeakerToStream(radioStream[FreqRadio[playerid]], playerid);
    }

    if (keyid == 0x42 && localStream[playerid]) SvAttachSpeakerToStream(localStream[playerid], playerid); // Local Stream
    format(str, sizeof(str), "{00FF00}> TALKING <");
    SetPlayerChatBubble(playerid, str, -1, 20.0, 1000000);
}

public SV_VOID:OnPlayerActivationKeyRelease(SV_UINT:playerid, SV_UINT:keyid)
{
    new str[200];
    if(keyid == 0x42 && FreqRadio[playerid] >= 1 && TogMic[playerid] == 1 && TogRadio[playerid] == 1)
    {
        PlayerPlaySound(playerid, 41603, 0.0, 0.0, 0.0);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        if(IsPlayerAttachedObjectSlotUsed(playerid, 9)) RemovePlayerAttachedObject(playerid, 9);
        
        format(str, sizeof(str), "{FF8B06}> RADIO <");
        SetPlayerChatBubble(playerid, str, -1, 0.0, 0);
        SvDetachSpeakerFromStream(radioStream[FreqRadio[playerid]], playerid);
    }

    if (keyid == 0x42 && localStream[playerid]) SvDetachSpeakerFromStream(localStream[playerid], playerid); // Local Stream
    format(str, sizeof(str), "{00FF00}> TALKING <");
    SetPlayerChatBubble(playerid, str, -1, 0.0, 0);
}

public OnPlayerConnect(playerid)
{
    if(SvGetVersion(playerid) == SV_NULL)
    {
        ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "SAMP Voice","{FF0000}SAMP Voice not detected!{FFFFFF}\nPlayers are required to use the SAMP voice plugin before playing on the server\n\nTutorial\n{FFAE00}- you must join discord.gg/localprime-rp\n- then if you have, you must install it on the PC resource channel\n- If you have installed it, watch the video made by the admin so that the installation can run smoothly.", "", "");
    }
    else if((localStream[playerid] = SvCreateDLStreamAtPlayer(20.0, SV_INFINITY, playerid, 0x0300ffff, "")))
    {
        SvAddKey(playerid, 0x42);
    }

    TogRadio[playerid] = 0;

    RadioTD[playerid][0] = CreatePlayerTextDraw(playerid, 589.000000, 429.000000, "VOICE MODE:");
    PlayerTextDrawFont(playerid, RadioTD[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][0], 0.241666, 1.300000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][0], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][0], 3);
    PlayerTextDrawColor(playerid, RadioTD[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][0], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][0], 0);

    RadioTD[playerid][1] = CreatePlayerTextDraw(playerid, 591.000000, 429.000000, "~b~NORMAL");
    PlayerTextDrawFont(playerid, RadioTD[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][1], 0.241666, 1.300000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][1], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][1], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][1], 0);

    RadioTD[playerid][2] = CreatePlayerTextDraw(playerid, 353.000000, 386.000000, "ld_dual:white");
    PlayerTextDrawFont(playerid, RadioTD[playerid][2], 4);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][2], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][2], 74.000000, 68.000000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][2], 387984895);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][2], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][2], 0);

    RadioTD[playerid][3] = CreatePlayerTextDraw(playerid, 353.000000, 363.000000, "ld_dual:white");
    PlayerTextDrawFont(playerid, RadioTD[playerid][3], 4);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][3], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][3], 9.000000, 25.500000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][3], 387984895);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][3], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][3], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][3], 0);

    RadioTD[playerid][4] = CreatePlayerTextDraw(playerid, 354.500000, 365.000000, "ld_dual:white");
    PlayerTextDrawFont(playerid, RadioTD[playerid][4], 4);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][4], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][4], 6.000000, 8.000000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][4], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][4], -16776961);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][4], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][4], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][4], 1);

    RadioTD[playerid][5] = CreatePlayerTextDraw(playerid, 354.500000, 388.000000, "ld_dual:white");
    PlayerTextDrawFont(playerid, RadioTD[playerid][5], 4);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][5], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][5], 71.000000, 21.500000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][5], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][5], 1296911871);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][5], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][5], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][5], 0);

    RadioTD[playerid][6] = CreatePlayerTextDraw(playerid, 354.500000, 415.000000, "ld_dual:white");
    PlayerTextDrawFont(playerid, RadioTD[playerid][6], 4);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][6], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][6], 34.000000, 21.500000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][6], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][6], 1296911871);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][6], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][6], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][6], 1);

    RadioTD[playerid][7] = CreatePlayerTextDraw(playerid, 391.500000, 415.000000, "ld_dual:white");
    PlayerTextDrawFont(playerid, RadioTD[playerid][7], 4);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][7], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][7], 34.000000, 21.500000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][7], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][7], 1296911871);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][7], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][7], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][7], 1);

    RadioTD[playerid][8] = CreatePlayerTextDraw(playerid, 390.000000, 392.000000, "0");
    PlayerTextDrawFont(playerid, RadioTD[playerid][8], 1);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][8], 0.283333, 1.500000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][8], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][8], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][8], 2);
    PlayerTextDrawColor(playerid, RadioTD[playerid][8], -1);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][8], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][8], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][8], 0);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][8], 0);

    RadioTD[playerid][9] = CreatePlayerTextDraw(playerid, 371.000000, 420.000000, "FREQ");
    PlayerTextDrawFont(playerid, RadioTD[playerid][9], 1);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][9], 0.208333, 1.250000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][9], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][9], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][9], 2);
    PlayerTextDrawColor(playerid, RadioTD[playerid][9], -1);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][9], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][9], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][9], 0);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][9], 0);

    RadioTD[playerid][10] = CreatePlayerTextDraw(playerid, 408.000000, 420.000000, "SWITCH");
    PlayerTextDrawFont(playerid, RadioTD[playerid][10], 1);
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][10], 0.208333, 1.250000);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][10], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][10], 0);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][10], 2);
    PlayerTextDrawColor(playerid, RadioTD[playerid][10], -1);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][10], 255);
    PlayerTextDrawBoxColor(playerid, RadioTD[playerid][10], 50);
    PlayerTextDrawUseBox(playerid, RadioTD[playerid][10], 0);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][10], 0);

    RadiopTD[playerid][0] = CreatePlayerTextDraw(playerid, 322.000000, 63.000000, "MIC RADIO");
    PlayerTextDrawFont(playerid, RadiopTD[playerid][0], 3);
    PlayerTextDrawLetterSize(playerid, RadiopTD[playerid][0], 0.920833, 3.249999);
    PlayerTextDrawTextSize(playerid, RadiopTD[playerid][0], 400.000000, 168.500000);
    PlayerTextDrawSetOutline(playerid, RadiopTD[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, RadiopTD[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, RadiopTD[playerid][0], 2);
    PlayerTextDrawColor(playerid, RadiopTD[playerid][0], -1378294017);
    PlayerTextDrawBackgroundColor(playerid, RadiopTD[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, RadiopTD[playerid][0], 50);
    PlayerTextDrawUseBox(playerid, RadiopTD[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, RadiopTD[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, RadiopTD[playerid][0], 0);

    RadiopTD[playerid][1] = CreatePlayerTextDraw(playerid, 321.000000, 92.000000, "~g~ON");
    PlayerTextDrawFont(playerid, RadiopTD[playerid][1], 3);
    PlayerTextDrawLetterSize(playerid, RadiopTD[playerid][1], 0.920833, 3.249999);
    PlayerTextDrawTextSize(playerid, RadiopTD[playerid][1], 400.000000, 168.500000);
    PlayerTextDrawSetOutline(playerid, RadiopTD[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, RadiopTD[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, RadiopTD[playerid][1], 2);
    PlayerTextDrawColor(playerid, RadiopTD[playerid][1], -1378294017);
    PlayerTextDrawBackgroundColor(playerid, RadiopTD[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, RadiopTD[playerid][1], 50);
    PlayerTextDrawUseBox(playerid, RadiopTD[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, RadiopTD[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, RadiopTD[playerid][1], 0);
    return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_FIRE))
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
            if(TogMic[playerid] == 0)
            {
                if(TogRadio[playerid] == 0) return 1;
                if(FreqRadio[playerid] == 0) return ErrorMsg(playerid, "Anda belum terhubung ke Frequensi Radio manapun");

                InfoTD_RTD(playerid, 3000, "~g~ON");

                TogMic[playerid] = 1;
            }
            else if(TogMic[playerid] == 1)
            {
                if(TogRadio[playerid] == 0) return 1;
                if(FreqRadio[playerid] == 0) return ErrorMsg(playerid, "Anda belum terhubung ke Frequensi Radio manapun");

                InfoTD_RTD(playerid, 3000, "~r~OFF");

                TogMic[playerid] = 0;
            }
        }
    }
    if(PRESSED(KEY_WALK))
    {
        if(TogMic[playerid] == 0)
        {
            if(TogRadio[playerid] == 0) return 1;
            if(FreqRadio[playerid] == 0) return ErrorMsg(playerid, "Anda belum terhubung ke Frequensi Radio manapun");

            InfoTD_RTD(playerid, 3000, "~g~ON");

            TogMic[playerid] = 1;
        }
        else if(TogMic[playerid] == 1)
        {
            if(TogRadio[playerid] == 0) return 1;
            if(FreqRadio[playerid] == 0) return ErrorMsg(playerid, "Anda belum terhubung ke Frequensi Radio manapun");

            InfoTD_RTD(playerid, 3000, "~r~OFF");

            TogMic[playerid] = 0;
        }
    }
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    if (localStream[playerid])
    {
        SvDeleteStream(localStream[playerid]);
        localStream[playerid] = SV_NULL;
    }

    TogRadio[playerid] = 0;
    TogMic[playerid] = 0;
    FreqRadio[playerid] = 0;
    return 1;
}

public OnFilterScriptExit()
{
    for(new i = 0; i < MAX_FREQUENSI; i++)
    {
        SvDeleteStream(radioStream[i]);
    }
    return 1;
}

function OnPlayerUseRadio(playerid)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER || GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
    {
        SetPlayerChatBubble(playerid, "> Membuka Radio <", 0xD0AEEBFF, 15.0, 5000);
        SelectTextDraw(playerid, 0xBABABAFF);
        for(new i = 2; i < 11; i++)
        {
            PlayerTextDrawShow(playerid, RadioTD[playerid][i]);
        }
        return 1;
    }

    ApplyAnimation(playerid, "ped", "Jetpack_Idle", 4.1, 1, 0, 0, 1, 0, 1);
    SetPlayerAttachedObject(playerid, 9, 18868, 5, 0.135999, 0.017999, -0.053999, -91.299995, -88.799972, -2.199998, 1.000000, 1.000000, 1.000000);
    SetPlayerChatBubble(playerid, "> Membuka Radio <", 0xD0AEEBFF, 15.0, 5000);
    for(new i = 2; i < 11; i++)
    {
        PlayerTextDrawShow(playerid, RadioTD[playerid][i]);
    }
    SelectTextDraw(playerid, 0xBABABAFF);
    return 1;
}

public OnClickDynamicPlayerTextDraw(playerid, PlayerText:textid)
{
    if(textid == RadioTD[playerid][4])
    {
        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER || GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
        {
            for(new i = 0; i < 11; i++)
            {
                PlayerTextDrawHide(playerid, RadioTD[playerid][i]);
            }
            CancelSelectTextDraw(playerid);
            return 1;
        }

        for(new i = 0; i < 11; i++)
        {
            PlayerTextDrawHide(playerid, RadioTD[playerid][i]);
        }
        CancelSelectTextDraw(playerid);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
        ClearAnimations(playerid);
        RemovePlayerAttachedObject(playerid, 9);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    }
    if(textid == RadioTD[playerid][6])
    {
//        ShowPlayerDialog(playerid, DIALOG_NANDA, DIALOG_STYLE_INPUT, "equency", "Input Frequensi Radio yang ingin kamu hubungkan (1 - 99999)", "Hubungkan", "Tutup");
    }
    if(textid == RadioTD[playerid][7])
    {
        if(TogRadio[playerid] == 0)
        {
            if(FreqRadio[playerid] >= 1)
            {
                SuccesMsg(playerid, "Anda berhasil mengaktifkan Radio");
                ConnectToFrequensi(playerid, FreqRadio[playerid], false);
                TogRadio[playerid] = 1;
            }
            else
            {
                SuccesMsg(playerid, "Anda berhasil mengaktifkan Radio");
                TogRadio[playerid] = 1;
            }
        }
        else if(TogRadio[playerid] == 1)
        {
            if(FreqRadio[playerid] >= 1)
            {
                SuccesMsg(playerid, "Radio berhasil di nonaktifkan");
                DisconnectToFrequensi(playerid, FreqRadio[playerid], true);
                TogRadio[playerid] = 0;
            }
            else
            {
                SuccesMsg(playerid, "Radio berhasil di nonaktifkan");
                TogRadio[playerid] = 0;
            }
        }
    }
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == DIALOG_NANDA)
    {
        if(response)
        {
            new Frequensi = strval(inputtext);

            if(isnull(inputtext))
            {
 //               ShowPlayerDialog(playerid, DIALOG_NANDA, DIALOG_STYLE_INPUT, "equency", "{FF0000}Frequensi yang anda masukan salah!\nInput Frequensi Radio yang ingin kamu hubungkan (1 - 99999)", "Hubungkan", "Tutup");
                return 1;
            }
            if(Frequensi > 99999 || Frequensi < 0)
            {
 //               ShowPlayerDialog(playerid, DIALOG_NANDA, DIALOG_STYLE_INPUT, "equency", "{FF0000}Frequensi yang anda masukan salah!\nInput Frequensi Radio yang ingin kamu hubungkan (1 - 99999)", "Hubungkan", "Tutup");
                return 1;
            }
            if(FreqRadio[playerid] >= 1)
            {
                ConnectToFrequensi(playerid, Frequensi, true);
                new strv[200];
                format(strv, sizeof(strv), "%d", Frequensi);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][8], strv);
            }
            else
            {
                ConnectToFrequensi(playerid, Frequensi, false);
                new strv[200];
                format(strv, sizeof(strv), "%d", Frequensi);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][8], strv);                
            }
        }
    }
    return 1;
}


function ConnectToFrequensi(playerid, freq, bool:rConnected)
{
    if(freq == 0) return 1;
    if(rConnected == true)
    {
        new msgFreq[256];
        format(msgFreq, sizeof(msgFreq), "Anda telah ~r~TERPUTUS ~w~dari Frequensi ~r~%d ~w~dan ~g~'TERHUBUNG' ~w~ke Frequensi ~g~%d", FreqRadio[playerid], freq);
        InfoMsg(playerid, msgFreq);

        SvDetachSpeakerFromStream(radioStream[FreqRadio[playerid]], playerid);
        SvDetachListenerFromStream(radioStream[FreqRadio[playerid]], playerid);

        FreqRadio[playerid] = freq;

        SvAttachListenerToStream(radioStream[freq], playerid);
    }
    else if(rConnected == false)
    {
        FreqRadio[playerid] = freq;
        SvAttachListenerToStream(radioStream[freq], playerid);

        new string[128];
        format(string, sizeof(string), "Anda berhasil ~g~'TERHUBUNG' ~w~ke Frequensi ~g~%d", freq);
        SuccesMsg(playerid, string);
    }
    return 1;
}

function DisconnectToFrequensi(playerid, freq, bool:togOnRadio)
{
    SvDetachListenerFromStream(radioStream[freq], playerid);
    SvDetachSpeakerFromStream(radioStream[freq], playerid);

    new strvz[256];
    format(strvz, sizeof(strvz), "Anda telah terputus dari Frequensi ~r~%d", freq);
    InfoMsg(playerid, strvz);

    if(togOnRadio == false)
    {
        FreqRadio[playerid] = 0;
    }
    return 1;
}

function InfoTD_RTD(playerid, ms_time, const text[])
{
    if(GetPVarInt(playerid, "InfoTDRshown") != -1)
    {
        PlayerTextDrawHide(playerid, RadiopTD[playerid][0]);
        PlayerTextDrawHide(playerid, RadiopTD[playerid][1]);
        KillTimer(GetPVarInt(playerid, "InfoTDRshown"));
    }

    PlayerTextDrawSetString(playerid, RadiopTD[playerid][1], text);
    PlayerTextDrawShow(playerid, RadiopTD[playerid][0]);
    PlayerTextDrawShow(playerid, RadiopTD[playerid][1]);
    SetPVarInt(playerid, "InfoTDRshown", SetTimerEx("InfoTDR_Hide", ms_time, false, "i", playerid));
    return 1;
}

function InfoTDR_Hide(playerid)
{
    SetPVarInt(playerid, "InfoTDRshown", -1);
    PlayerTextDrawHide(playerid, RadiopTD[playerid][0]);
    PlayerTextDrawHide(playerid, RadiopTD[playerid][1]);
    return 1;
}