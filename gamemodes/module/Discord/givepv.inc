CMD:givepv(playerid, params[])
{
	new vehid, otherid;
	if(sscanf(params, "ud", otherid, vehid)) return Usage(playerid, "/givepv [playerid/name] [vehid] | /v my(mypv) - for find vehid");
	if(vehid == INVALID_VEHICLE_ID) return Error(playerid, "Invalid id");
	if(strcmp(pvData[vehid][cPlate], "None")) return Error(playerid, "Kendaraan tidak memiliki plat yang aktif!");

	if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
		return Error(playerid, "The specified player is disconnected or not near you.");

	new count = 0, limit = MAX_PLAYER_VEHICLE + pData[otherid][pVip];
	foreach(new ii : PVehicles)
	{
		if(pvData[ii][cOwner] == pData[otherid][pID])
			count++;
	}
	if(count >= limit)
	{
		Error(playerid, "This player have too many vehicles, sell a vehicle first!");
		return 1;
	}
	foreach(new i : PVehicles)
	{
		if(vehid == pvData[i][cVeh])
		{
			if(pvData[i][cOwner] == pData[playerid][pID])
			{
				new nearid = GetNearestVehicleToPlayer(playerid, 5.0, false);
				if(vehid == nearid)
				{
					if(pvData[i][cRent] != 0) return Error(playerid, "You can't give rental vehicle!");
					Info(playerid, "Anda memberikan kendaraan %s(%d) anda kepada %s.", GetVehicleName(vehid), GetVehicleModel(vehid), ReturnName(otherid));
					Info(otherid, "%s Telah memberikan kendaraan %s(%d) kepada anda.(/mypv)", ReturnName(playerid), GetVehicleName(vehid), GetVehicleModel(vehid));
					pvData[i][cOwner] = pData[otherid][pID];

					SendDiscordMessage(1, sprintf("**%s** player memberikan kendaraan**__%s(%d)__** kepada **%s**", ReturnName(playerid), GetVehicleName(vehid), GetVehicleModel(vehid), ReturnName(otherid)));

					/*new DCC_Channel:channel;
					channel = DCC_FindChannelById("1327254779793117245");
					new DCC_Embed:embed = DCC_CreateEmbed(.title = "Logs Send Vehicle");
					new str1[350], str2[350];

					format(str1, sizeof str1, "**__Pemberi__**");
					format(str2, sizeof str2, "\n%s", ReturnName(playerid));
					DCC_AddEmbedField(embed, str1, str2, false);
					format(str1, sizeof str1, "**__Penerima__**");
					format(str2, sizeof str2, "\n%s", ReturnName(otherid));
					DCC_AddEmbedField(embed, str1, str2, false);
					format(str1, sizeof str1, "**__Vehicle Name__**");
					format(str2, sizeof str2, "\n%d", GetVehicleName(vehid));
					DCC_AddEmbedField(embed, str1, str2, false);
					format(str1, sizeof str1, "**__Vehicle ID__**");
					format(str2, sizeof str2, "\n%d", GetVehicleModel(vehid));
					DCC_AddEmbedField(embed, str1, str2, false);
					DCC_SendChannelEmbedMessage(channel, embed);*/

					new query[128];
					mysql_format(g_SQL, query, sizeof(query), "UPDATE vehicle SET owner='%d' WHERE id='%d'", pData[otherid][pID], pvData[i][cID]);
					mysql_tquery(g_SQL, query);
					return 1;
				}
				else return Error(playerid, "Anda harus berada di dekat kendaraan yang anda jual!");
			}
			else return Error(playerid, "ID kendaraan ini bukan punya mu! gunakan /v my(/mypv) untuk mencari ID.");
		}
	}
	return 1;
}