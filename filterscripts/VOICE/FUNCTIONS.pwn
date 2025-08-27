function InfoTD_RTD(playerid, ms_time, text[])
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
}

function InfoTDR_Hide(playerid)
{
	SetPVarInt(playerid, "InfoTDRshown", -1);
	PlayerTextDrawHide(playerid, RadiopTD[playerid][0]);
 	PlayerTextDrawHide(playerid, RadiopTD[playerid][1]);
}

function ConnectToFrequensi(playerid, freq, bool:rConnected)
{
    if(freq == 0) return 1;
    if(rConnected == true)
    {
        new msgFreq[256];
        format(msgFreq, sizeof msgFreq, "Anda telah ~r~TERPUTUS ~w~dari Frequensi ~r~%d ~w~dan ~g~'TERHUBUNG' ~w~ke Frequensi ~g~%d", pData[playerid][pFreqRadio], freq);
        InfoMsg(playerid, msgFreq);

        SvDetachSpeakerFromStream(radioStream[pData[playerid][pFreqRadio]], playerid);
        SvDetachListenerFromStream(radioStream[pData[playerid][pFreqRadio]], playerid);

        pData[playerid][pFreqRadio] = freq;

        SvAttachListenerToStream(radioStream[freq], playerid);
    }
    else if(rConnected == false)
    {
        pData[playerid][pFreqRadio] = freq;
        SvAttachListenerToStream(radioStream[freq], playerid);

        new string[128];
        format(string, 128, "Anda berhasil ~g~'TERHUBUNG' ~w~ke Frequensi ~g~%d", freq);
        SuccesMsg(playerid, string);
    }
    return 1;
}

function DisconnectToFrequensi(playerid, freq, bool:togOnRadio)
{
    SvDetachListenerFromStream(radioStream[freq], playerid);
    SvDetachSpeakerFromStream(radioStream[freq], playerid);

    new msgFreq[256];
    format(msgFreq, 256, "Anda telah ~R~'TERPUTUS' ~w~dari Frequensi ~r~%d", freq);
    InfoMsg(playerid, msgFreq);

    if(togOnRadio == false)
    {
        pData[playerid][pFreqRadio] = 0;
    }
    return 1;
}

// ---=== STOCK ===---

stock GetPlayerNameEx(playerid)
{
    new getName[MAX_PLAYER_NAME];
    GetPlayerName(playerid, getName, MAX_PLAYER_NAME);
    return getName;
}

stock ResetDataVoicePlayer(playerid)
{
    pData[playerid][pID] = 0;
    pData[playerid][pTogRadio] = 0;
    pData[playerid][pTogMic] = 0;
    pData[playerid][pFreqRadio] = 0;
    pData[playerid][pSfxTurnOn] = 0;
    pData[playerid][pSfxTurnOff] = 0;
    pData[playerid][IsLoggedIn] = false;
}

stock SendMessageToFrequensi(freq, msg[])
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i))
        {
            if(pData[i][pFreqRadio] > 0 && pData[i][pFreqRadio] == freq)
            {
            	new getMsg[256];
            	format(getMsg, 256, "{FFFF00}[RADIO] {FFFFFF}%s", msg);
                SendClientMessage(i, -1, getMsg);
            }
        }
    }
    return 1;
}
