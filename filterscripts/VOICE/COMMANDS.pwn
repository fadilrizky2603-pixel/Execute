CMD:togr(playerid, params[])
{
	if(pData[playerid][pTogRadio] == 0)
	{
		if(pData[playerid][pFreqRadio] >= 1)
		{
            new msgTogRadio[256];
            format(msgTogRadio, sizeof msgTogRadio, "Anda berhasil ~g~'TERHUBUNG' ~w~ke Frequensi ~g~%d", pData[playerid][pFreqRadio]);
            SuccesMsg(playerid, msgTogRadio);
			ConnectToFrequensi(playerid, pData[playerid][pFreqRadio], false);
            pData[playerid][pTogRadio] = 1;
		}
        else
        {
            SuccesMsg(playerid, "Radio berhasil di aktifkan");
            pData[playerid][pTogRadio] = 1;
        }
	}
	else if(pData[playerid][pTogRadio] == 1)
	{
		if(pData[playerid][pFreqRadio] >= 1)
		{
            new msgTogRadio[256];
            format(msgTogRadio, sizeof msgTogRadio, "Anda telah ~r~TERPUTUS ~w~dari Frequensi ~r~%d", pData[playerid][pFreqRadio]);
			InfoMsg(playerid, msgTogRadio);
            DisconnectToFrequensi(playerid, pData[playerid][pFreqRadio], true);
            pData[playerid][pTogRadio] = 0;
		}
        else
        {
            SuccesMsg(playerid, "Radio berhasil di nonaktifkan");
            pData[playerid][pTogRadio] = 0;
        }
	}
	return 1;
}

CMD:rv(playerid, params[])
{
//	ShowPlayerDialog(playerid, DIALOG_NANDA, DIALOG_STYLE_INPUT, "equency", "Input Frequensi Radio yang ingin kamu hubungkan (1 - 99999)", "Hubungkan", "Tutup");
    return 1;
}

CMD:vm(playerid, params[])
{
    new rstring[300];
    format(rstring, sizeof(rstring), "{0638FF}Normal\n{FF0000}Teriak\n{FFFF00}Berbisik");
    //ShowPlayerDialog(playerid, DIALOG_MVOICE, DIALOG_STYLE_LIST, "Voice Mode", rstring, "Pilih","Batalkan");
    ShowPlayerDialog(playerid, DIALOG_MVOICE, DIALOG_STYLE_TABLIST_HEADERS, "Voice Mode {FFFF00}'/vm'", "Mode\tRadius\t\n\
    {0638FF}Normal\t20.0\t\n\
    {FF0000}Teriak\t80.0\t\n\
    {FFFF00}Berbisik\t10.0\t", "Select");
    return 1;
}