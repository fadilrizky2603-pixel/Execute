CMD:savepos(playerid, params[])
{
	if(!strlen(params))
		return SendClientMessage(playerid, 0xCECECEFF, "Gunakan: /savepos [judul]");

    extract params -> new string:message[1000]; else return SendClientMessage(playerid, 0xCECECEFF, "Gunakan: /savepos [judul]");

   	GetPlayerVehicleID(playerid);
	new msg[500];
	new Float:PPos[5];

	GetPlayerPos(playerid, PPos[0], PPos[1], PPos[2]);
	GetPlayerFacingAngle(playerid, PPos[3]);
	format(msg, sizeof(msg), "\nSetPlayerPos(playerid, %f,%f,%f);\nSetPlayerFacingAngle(playerid, %f);\nJudul : %s", PPos[0], PPos[1], PPos[2], PPos[3], message);
/*	DCC_SendChannelMessage(g_discord_savepos, msg);*/
    new File:fhandle;
    fhandle = fopen("coordinates.txt",io_append);
    fwrite(fhandle, msg);
    fclose(fhandle);
	SuccesMsg(playerid, "Coordinat Posisi Kamu Berhasil Di Save!");

    new DCC_Channel:channel;
	channel = DCC_FindChannelById("1325472156242677843");
 	new DCC_Embed:embed = DCC_CreateEmbed(.title = message);
	new str1[350], str2[350];

	format(str1, sizeof str1, "**GOTOCO**");
	format(str2, sizeof str2, "\n/gotoco %f %f %f %i", PPos[0], PPos[1], PPos[2], GetPlayerInterior(playerid));
	DCC_AddEmbedField(embed, str1, str2, false);
	format(str1, sizeof str1, "**KOORDINAT 1**");
	format(str2, sizeof str2, "\n%f, %f, %f", PPos[0], PPos[1], PPos[2]);
	DCC_AddEmbedField(embed, str1, str2, false);
	format(str1, sizeof str1, "**KOORDINAT 2**");
	format(str2, sizeof str2, "\n%f, %f, %f, %f", PPos[0], PPos[1], PPos[2], PPos[3]);
	DCC_AddEmbedField(embed, str1, str2, false);
	format(str1, sizeof str1, "**KOORDINAT X**");
	format(str2, sizeof str2, "\n%f", PPos[0]);
	DCC_AddEmbedField(embed, str1, str2, false);
	format(str1, sizeof str1, "**KOORDINAT Y**");
	format(str2, sizeof str2, "\n%f", PPos[1]);
	DCC_AddEmbedField(embed, str1, str2, false);
	format(str1, sizeof str1, "**KOORDINAT Z**");
	format(str2, sizeof str2, "\n%f", PPos[2]);
	DCC_AddEmbedField(embed, str1, str2, false);
	format(str1, sizeof str1, "**KOORDINAT A**");
	format(str2, sizeof str2, "\n%f", PPos[3]);
	DCC_AddEmbedField(embed, str1, str2, false);
	DCC_SendChannelEmbedMessage(channel, embed);
    return 1;
}