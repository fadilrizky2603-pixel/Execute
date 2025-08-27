#include <YSI\y_hooks>

new PlayerText: RadioTD[MAX_PLAYERS][13];
//new PlayerText: VoiceLeft[MAX_PLAYERS][3];

new bool: ToggleRadio[MAX_PLAYERS] = { false, ... };
new bool: RadioMicOn[MAX_PLAYERS] = { false, ... };
new PlayerInFreq[MAX_PLAYERS];

VoiceSistemLoadTextdraw(playerid)
{
    RadioTD[playerid][0] = CreatePlayerTextDraw(playerid, 383.000, 360.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][0], 80.000, 90.000);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][0], 572785407);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadioTD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][0], 1);

    RadioTD[playerid][1] = CreatePlayerTextDraw(playerid, 450.000, 330.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][1], 6.000, 30.000);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][1], 572785407);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadioTD[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][1], 1);

    RadioTD[playerid][2] = CreatePlayerTextDraw(playerid, 388.000, 375.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][2], 70.000, 45.000);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][2], -421070081);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, RadioTD[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][2], 1);

    RadioTD[playerid][3] = CreatePlayerTextDraw(playerid, 430.000, 350.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][3], 15.000, 10.000);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][3], 572785407);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, RadioTD[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][3], 1);

    RadioTD[playerid][4] = CreatePlayerTextDraw(playerid, 388.000, 426.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][4], 25.000, 15.000);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][4], 1684301055);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, RadioTD[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][4], 1);

    RadioTD[playerid][5] = CreatePlayerTextDraw(playerid, 433.000, 426.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][5], 25.000, 15.000);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][5], 1684301055);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, RadioTD[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][5], 1);

    RadioTD[playerid][6] = CreatePlayerTextDraw(playerid, 415.500, 426.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][6], 15.000, 15.000);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][6], 1684301055);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, RadioTD[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][6], 1);

    RadioTD[playerid][7] = CreatePlayerTextDraw(playerid, 390.000, 377.000, "FREQUENCY");
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][7], 0.170, 0.898);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, RadioTD[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, RadioTD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][7], 1);

    RadioTD[playerid][8] = CreatePlayerTextDraw(playerid, 423.000, 364.000, "Walkie Talkie");
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][8], 0.149, 0.799);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][8], 2);
    PlayerTextDrawColor(playerid, RadioTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][8], 150);
    PlayerTextDrawFont(playerid, RadioTD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][8], 1);

    RadioTD[playerid][9] = CreatePlayerTextDraw(playerid, 400.500, 429.000, "POWER");
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][9], 0.158, 0.999);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][9], 15.000, 20.000);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][9], 2);
    PlayerTextDrawColor(playerid, RadioTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][9], 150);
    PlayerTextDrawFont(playerid, RadioTD[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][9], 1);

    RadioTD[playerid][10] = CreatePlayerTextDraw(playerid, 423.000, 429.000, "X");
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][10], 0.158, 0.999);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][10], 15.000, 12.000);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][10], 2);
    PlayerTextDrawColor(playerid, RadioTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, RadioTD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][10], 1);

    RadioTD[playerid][11] = CreatePlayerTextDraw(playerid, 444.500, 429.000, "SET");
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][11], 0.158, 0.999);
    PlayerTextDrawTextSize(playerid, RadioTD[playerid][11], 15.000, 20.000);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][11], 2);
    PlayerTextDrawColor(playerid, RadioTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, RadioTD[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, RadioTD[playerid][11], 1);

    RadioTD[playerid][12] = CreatePlayerTextDraw(playerid, 423.000, 387.000, "0");
    PlayerTextDrawLetterSize(playerid, RadioTD[playerid][12], 0.469, 2.299);
    PlayerTextDrawAlignment(playerid, RadioTD[playerid][12], 2);
    PlayerTextDrawColor(playerid, RadioTD[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, RadioTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, RadioTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, RadioTD[playerid][12], -1);
    PlayerTextDrawFont(playerid, RadioTD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, RadioTD[playerid][12], 1);

    /*VoiceLeft[playerid][0] = CreatePlayerTextDraw(playerid, 119.000, 429.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, VoiceLeft[playerid][0], 4.000, -4.000);
    PlayerTextDrawAlignment(playerid, VoiceLeft[playerid][0], 1);
    PlayerTextDrawColor(playerid, VoiceLeft[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, VoiceLeft[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, VoiceLeft[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, VoiceLeft[playerid][0], 255);
    PlayerTextDrawFont(playerid, VoiceLeft[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, VoiceLeft[playerid][0], 1);

    VoiceLeft[playerid][1] = CreatePlayerTextDraw(playerid, 114.000, 429.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, VoiceLeft[playerid][1], 4.000, -4.000);
    PlayerTextDrawAlignment(playerid, VoiceLeft[playerid][1], 1);
    PlayerTextDrawColor(playerid, VoiceLeft[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, VoiceLeft[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, VoiceLeft[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, VoiceLeft[playerid][1], 255);
    PlayerTextDrawFont(playerid, VoiceLeft[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, VoiceLeft[playerid][1], 1);

    VoiceLeft[playerid][2] = CreatePlayerTextDraw(playerid, 109.000, 429.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, VoiceLeft[playerid][2], 4.000, -4.000);
    PlayerTextDrawAlignment(playerid, VoiceLeft[playerid][2], 1);
    PlayerTextDrawColor(playerid, VoiceLeft[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, VoiceLeft[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, VoiceLeft[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, VoiceLeft[playerid][2], 255);
    PlayerTextDrawFont(playerid, VoiceLeft[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, VoiceLeft[playerid][2], 1);*/

}

VoiceSistemUnloadTextdraw(playerid)
{
    for(new x = 0; x < 13; x++)
    {
        PlayerTextDrawDestroy(playerid, RadioTD[playerid][x]);
    }
    /*for(new x = 0; x < 3; x++)
    {
        PlayerTextDrawDestroy(playerid, VoiceLeft[playerid][x]);
    }*/
}

RadioTextdrawToggle(playerid, bool: toggle)
{
    if(!toggle)
    {
        for(new x; x < 13; x++)
        {
            PlayerTextDrawHide(playerid, RadioTD[playerid][x]);
        }
    }
    else
    {
        for(new x; x < 13; x++)
        {
            PlayerTextDrawShow(playerid, RadioTD[playerid][x]);
        }
    }
    return 1;
}

//-----------------------------------------------------------------
hook OnPlayerConnect(playerid)
{
    ToggleRadio[playerid] = false;
    RadioMicOn[playerid] = false;
    PlayerInFreq[playerid] = 0;
    VoiceSistemLoadTextdraw(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    ToggleRadio[playerid] = false;
    RadioMicOn[playerid] = false;
    PlayerInFreq[playerid] = 0;
    VoiceSistemUnloadTextdraw(playerid);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    //PlayerTextDrawShow(playerid, VoiceLeft[playerid][0]);
    //PlayerTextDrawShow(playerid, VoiceLeft[playerid][1]);
    return 1;
}

ptask Radio_Timer[1000](playerid)
{
    if (IsPlayerInWater(playerid))
	{
		if (PlayerHasItem(playerid, "Smartphone"))
		{
			ItemDelete(playerid, "Smartphone", Inventory_Count(playerid, "Smartphone"));
            ShowItemBox(playerid, "Smartphone", "Removed_1x", 2);
			Info(playerid, "Smartphone anda rusak karena terkena air!");
		}

		if (PlayerHasItem(playerid, "Radio"))
		{
            if (ToggleRadio[playerid] && PlayerInFreq[playerid] != 0)
            {
                ToggleRadio[playerid] = false;
                RadioMicOn[playerid] = false;
                PlayerInFreq[playerid] = 0;
                CallRemoteFunction("UpdatePlayerVoiceMicToggle", "dd", playerid, false);
                CallRemoteFunction("UpdatePlayerVoiceRadioToggle", "dd", playerid, false);
                CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, false, 0);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][12], "0");
                RemovePlayerAttachedObject(playerid, 9);
                
                ItemDelete(playerid, "Radio", Inventory_Count(playerid, "Radio"));
                ShowItemBox(playerid, "Radio", "Removed_1x", 2);
                Info(playerid, "Radio anda rusak dan saluran terputus karena terkena air!");
            }
            else
            {
                ItemDelete(playerid, "Radio", Inventory_Count(playerid, "Radio"));
                ShowItemBox(playerid, "Radio", "Removed_1x", 2);
                Info(playerid, "Radio anda rusak karena terkena air!");
            }
		}
	}
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case DIALOG_RADIO_FREQ:
        {
            if(!response) return 1;
            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DIALOG_RADIO_FREQ, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Radio Fx",
            "Error: Tidak dapat diisi kosong!\nMasukkan frekuensi radio yang ingin diterapkan pada kolom dibawah ini\
            \n(Frekuensi harus berada diantara 0 - 9999)\
            \nCatatan: Masukkan frekuensi 0 untuk memutuskan saluran frekuensi/netral", "Submit", "Batal");

            if(!IsNumeric(inputtext)) return ShowPlayerDialog(playerid, DIALOG_RADIO_FREQ, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Radio Fx",
            "Error: Hanya dapat diisi angka!\nMasukkan frekuensi radio yang ingin diterapkan pada kolom dibawah ini\
            \n(Frekuensi harus berada diantara 0 - 9999)\
            \nCatatan: Masukkan frekuensi 0 untuk memutuskan saluran frekuensi/netral", "Submit", "Batal");

            if(strval(inputtext) < 0 || strval(inputtext) > 9999) return ShowPlayerDialog(playerid, DIALOG_RADIO_FREQ, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Radio Fx",
            "Error: Frequency dimulai dari 0 - 9999!\nMasukkan frekuensi radio yang ingin diterapkan pada kolom dibawah ini\
            \n(Frekuensi harus berada diantara 0 - 9999)\
            \nCatatan: Masukkan frekuensi 0 untuk memutuskan saluran frekuensi/netral", "Submit", "Batal");

            new freq = strval(inputtext);
            PlayerInFreq[playerid] = freq;
            
            if(freq == 0)
            {
                ToggleRadio[playerid] = false;
                RadioMicOn[playerid] = false;
                CallRemoteFunction("UpdatePlayerVoiceMicToggle", "dd", playerid, false);
                CallRemoteFunction("UpdatePlayerVoiceRadioToggle", "dd", playerid, false);
                CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, false, freq);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][12], "0");
		        PlayerTextDrawShow(playerid, RadioTD[playerid][12]);
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil memutuskan saluran radio");
            }
            else if(freq == 1)
            {
                if(AccountData[playerid][pFaction] != FACTION_POLISI && AccountData[playerid][pFaction] != FACTION_EMS && AccountData[playerid][pFaction] != FACTION_GOJEK) return ShowTDN(playerid, NOTIFICATION_ERROR, "Freq 1 khusus Polisi tetapi dapat dimasuki EMS!");

                CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, true, freq);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][12], "1");
		        PlayerTextDrawShow(playerid, RadioTD[playerid][12]);
                ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil terhubung ke frequency ~y~%d", freq));
            }
            else if(freq == 2)
            {
                if(AccountData[playerid][pFaction] != FACTION_POLISI && AccountData[playerid][pFaction] != FACTION_EMS && AccountData[playerid][pFaction] != FACTION_GOJEK) return ShowTDN(playerid, NOTIFICATION_ERROR, "Freq 2 khusus EMS tetapi dapat dimasuki Polisi!");

                CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, true, freq);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][12], "2");
		        PlayerTextDrawShow(playerid, RadioTD[playerid][12]);
                ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil terhubung ke frequency ~y~%d", freq));
            }
            else if(freq == 3)
            {
                if(AccountData[playerid][pFaction] != FACTION_PEMERINTAH) return ShowTDN(playerid, NOTIFICATION_ERROR, "Freq 3 khusus Instansi Pemerntah DCRP!");

                CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, true, freq);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][12], "3");
		        PlayerTextDrawShow(playerid, RadioTD[playerid][12]);
                ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil terhubung ke frequency ~y~%d", freq));
            }
            else if(freq == 4)
            {
                if(AccountData[playerid][pFaction] != FACTION_POLISI && AccountData[playerid][pFaction] != FACTION_EMS && AccountData[playerid][pFaction] != FACTION_TRANS && AccountData[playerid][pFaction] != FACTION_GOJEK) return ShowTDN(playerid, NOTIFICATION_ERROR, "Freq 4 khusus Transportasi tetapi dapat dimasuki Polisi dan EMS!");

                CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, true, freq);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][12], "4");
		        PlayerTextDrawShow(playerid, RadioTD[playerid][12]);
                ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil terhubung ke frequency ~y~%d", freq));
            }
            else if(freq == 5)
            {
                if(AccountData[playerid][pFaction] != FACTION_POLISI && AccountData[playerid][pFaction] != FACTION_EMS && AccountData[playerid][pFaction] != FACTION_BENGKEL && AccountData[playerid][pFaction] != FACTION_GOJEK) return ShowTDN(playerid, NOTIFICATION_ERROR, "Freq 5 khusus Bengkel tetapi dapat dimasuki Polisi dan EMS!");

                CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, true, freq);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][12], "5");
		        PlayerTextDrawShow(playerid, RadioTD[playerid][12]);
                ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil terhubung ke frequency ~y~%d", freq));
            }
            else if(freq == 6)
            {
                if(AccountData[playerid][pFaction] != FACTION_POLISI && AccountData[playerid][pFaction] != FACTION_EMS && AccountData[playerid][pFaction] != FACTION_PEDAGANG && AccountData[playerid][pFaction] != FACTION_GOJEK) return ShowTDN(playerid, NOTIFICATION_ERROR, "Freq 6 khusus Pedagang tetapi dapat dimasuki Polisi dan EMS!");

                CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, true, freq);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][12], "6");
		        PlayerTextDrawShow(playerid, RadioTD[playerid][12]);
                ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil terhubung ke frequency ~y~%d", freq));
            }
            else if(freq == 7)
            {
                if(AccountData[playerid][pFaction] != FACTION_POLISI && AccountData[playerid][pFaction] != FACTION_EMS && AccountData[playerid][pFaction] != FACTION_GOJEK) return ShowTDN(playerid, NOTIFICATION_ERROR, "Freq 7 - 10 khusus Saluran Gabungan Polisi dan EMS!");

                CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, true, freq);
                PlayerTextDrawSetString(playerid, RadioTD[playerid][12], "7");
		        PlayerTextDrawShow(playerid, RadioTD[playerid][12]);
                ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil terhubung ke frequency ~y~%d", freq));
            }
            else
            {
                PlayerTextDrawSetString(playerid, RadioTD[playerid][12], sprintf("%d", freq));
		        PlayerTextDrawShow(playerid, RadioTD[playerid][12]);
                CallRemoteFunction("AssignFreqToFSVoice", "ddd", playerid, true, freq);
                ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil terhubung ke frequency ~y~%d", freq));
            }
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
            RemovePlayerAttachedObject(playerid, 9);
            CancelSelectTextDraw(playerid);
        }
        case DIALOG_VOICEKEYS:
        {
            if(!response) return 1;
            switch(listitem)
            {
                case 0: // B Default
                {
                    ShowTDN(playerid, NOTIFICATION_SUKSES, "Voice Keys berhasil diubah menjadi Tombol B");
                    CallRemoteFunction("UpdatePlayerVoiceKeys", "dd", playerid, 1); // Default
                }
                case 1: // B Default
                {
                    ShowTDN(playerid, NOTIFICATION_SUKSES, "Voice Keys berhasil diubah menjadi Tombol R");
                    CallRemoteFunction("UpdatePlayerVoiceKeys", "dd", playerid, 2); // Default
                }
                case 2: // B Default
                {
                    ShowTDN(playerid, NOTIFICATION_SUKSES, "Voice Keys berhasil diubah menjadi Tombol X");
                    CallRemoteFunction("UpdatePlayerVoiceKeys", "dd", playerid, 3); // Default
                }
                case 3: // B Default
                {
                    ShowTDN(playerid, NOTIFICATION_SUKSES, "Voice Keys berhasil diubah menjadi Tombol Z");
                    CallRemoteFunction("UpdatePlayerVoiceKeys", "dd", playerid, 4); // Default
                }
                case 4: // Tombol Mouse Tengah
                {
                    ShowTDN(playerid, NOTIFICATION_SUKSES, "Voice Keys berhasil diubah menjadi Shift Key");
                    CallRemoteFunction("UpdatePlayerVoiceKeys", "dd", playerid, 5); // Default
                }
            }
        }
        case DIALOG_VOICEMODE:
        {
            if(!response) return 1;
            switch(listitem)
            {
                case 0: // teriak
                {
                    /*PlayerTextDrawShow(playerid, VoiceLeft[playerid][0]);
                    PlayerTextDrawShow(playerid, VoiceLeft[playerid][1]);
                    PlayerTextDrawShow(playerid, VoiceLeft[playerid][2]);*/
                    Info(playerid, "Berhasil mengubah voice mode menjadi "RED"Teriak");
                    CallRemoteFunction("UpdatePlayerVoiceDistance", "ddf", playerid, 3, 30.0);
                }
                case 1: // Normal
                {
                    /*PlayerTextDrawShow(playerid, VoiceLeft[playerid][0]);
                    PlayerTextDrawShow(playerid, VoiceLeft[playerid][1]);
                    PlayerTextDrawHide(playerid, VoiceLeft[playerid][2]);*/
                    Info(playerid, "Berhasil mengubah voice mode menjadi "SKYBLUE"Normal");
                    CallRemoteFunction("UpdatePlayerVoiceDistance", "ddf", playerid, 2, 15.0);
                }
                case 2: // Teriak
                {
                    /*PlayerTextDrawShow(playerid, VoiceLeft[playerid][0]);
                    PlayerTextDrawHide(playerid, VoiceLeft[playerid][1]);
                    PlayerTextDrawHide(playerid, VoiceLeft[playerid][2]);*/
                    Info(playerid, "Berhasil mengubah voice mode menjadi "YELLOW"Berbisik");
                    CallRemoteFunction("UpdatePlayerVoiceDistance", "ddf", playerid, 1, 8.0);
                }
            }
        }
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ((newkeys & KEY_YES))
    {
        if(AccountData[playerid][pInjured] == 1)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menggunakan radio saat pingsan!");

        if (PlayerHasItem(playerid, "Radio") && ToggleRadio[playerid] && PlayerInFreq[playerid] >= 1)
        {   
            switch(RadioMicOn[playerid])
            {
                case false:
                {
                    RadioMicOn[playerid] = true;
                    ShowPlayerFooter(playerid, "~w~Mic Radio~n~~g~Aktif", 2500);
                    CallRemoteFunction("UpdatePlayerVoiceMicToggle", "dd", playerid, true);
                }
                case true:
                {
                    
                    RadioMicOn[playerid] = false;
                    ShowPlayerFooter(playerid, "~w~Mic Radio~n~~r~Mati", 2500);
                    CallRemoteFunction("UpdatePlayerVoiceMicToggle", "dd", playerid, false);
                }
            }
        }
    }
    return 1;
}

CMD:sv(playerid, params[])
{
    if(!IsPlayerConnected(playerid)) return 0;

    ShowPlayerDialog(playerid, DIALOG_VOICEMODE, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Voice Range",
    ""RED"Teriak\
    \nNormal\
    \n"YELLOW"Berbisik", "Pilih", "Batal");
    return 1;
}

CMD:vkeys(playerid, params[])
{
    if(!IsPlayerConnected(playerid))
        return 0;
    
    ShowPlayerDialog(playerid, DIALOG_VOICEKEYS, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Voice Keybind",
    "Keybind: B (Default)\
    \n"GRAY"Keybind: R\
    \nKeybind: X\
    \n"GRAY"Keybind: Z\
    \nKeybind: SHIFT", "Pilih", "Batal");
    return 1;
}

CMD:atakeradio(playerid, params[])
{
	if(AccountData[playerid][pAdmin] < 3) return PermissionError(playerid);

	new 
		otherid
	;
	if(sscanf(params, "u", otherid)) return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/atakeradio [name/playerid]");
	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(!PlayerHasItem(otherid, "Radio")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak memiliki Radio!");

    ItemDelete(otherid, "Radio", Inventory_Count(otherid, "Radio"));
    ShowItemBox(otherid, "Radio", "Removed_1x", 2);
	SendClientMessageEx(otherid, X11_ARWIN, "[AdmCmd] "RED"%s"ARWIN1" telah mengambil Radio anda.", AccountData[playerid][pAdminname]);
	SendStaffMessage(X11_ARWIN, ""RED"%s"ARWIN1" telah mengambil Radio pemain "YELLOW"%s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
    if(ToggleRadio[otherid] || RadioMicOn[otherid])
    {
        ToggleRadio[otherid] = false;
        RadioMicOn[otherid] = false;
        CallRemoteFunction("UpdatePlayerVoiceMicToggle", "dd", otherid, false);
        CallRemoteFunction("UpdatePlayerVoiceRadioToggle", "dd", otherid, false);
        CallRemoteFunction("AssignFreqToFSVoice", "ddd", otherid, true, 0);
        PlayerTextDrawSetString(otherid, RadioTD[otherid][12], "0");
    }

	return 1;
}