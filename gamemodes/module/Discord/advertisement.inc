CMD:ads(playerid, params[])
{
	if(pData[playerid][pVip] != 0)
	{
		if(GetPVarInt(playerid, "delay") > gettime()) 
			return ErrorMsg(playerid, "Anda harus menunggu 10 menit untuk menggunakannya lagi");

		if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
			return ErrorMsg(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

		if(Inventory_Count(playerid, "Phone") < 1)
			return ErrorMsg(playerid, "Anda tidak memiliki Ponsel");
		
		if(isnull(params))
		{
			SyntaxMsg(playerid, "/ads [text] | 1 text $2");
			return 1;
		}
		if(strlen(params) >= 100 ) return ErrorMsg(playerid, "Anda tidak dapat menuliskan lebih dari 100 kata");
		new payout = strlen(params) * 2;
		if(pData[playerid][pMoney] < payout) return ErrorMsg(playerid, "Uang anda tidak mencukupi");
		
		GivePlayerMoneyEx(playerid, -payout);
		Server_AddMoney(payout);
		SetPVarInt(playerid, "delay", gettime() + 600);
		foreach(new ii : Player)
		{
			if(pData[ii][pTogAds] == 0)
			{
                
                new DCC_Channel:channel;
                channel = DCC_FindChannelById("1324765314063532154");
                new DCC_Embed:embed = DCC_CreateEmbed(.title = "Advertisement");
                new str1[350], str2[350];

                format(str1, sizeof str1, "**__Advertisement__**");
                format(str2, sizeof str2, "\n%s", params);
                DCC_AddEmbedField(embed, str1, str2, false);
                format(str1, sizeof str1, "**__Contact Info__**");
                format(str2, sizeof str2, "\n%s", pData[playerid][pName]);
                DCC_AddEmbedField(embed, str1, str2, false);
                format(str1, sizeof str1, "**__Phone Number__**");
                format(str2, sizeof str2, "\n%d", pData[playerid][pPhone]);
				DCC_AddEmbedField(embed, str1, str2, false);
				format(str1, sizeof str1, "**__Bank Rekening__**");
                format(str2, sizeof str2, "\n%d", pData[playerid][pBankRek]);
				DCC_AddEmbedField(embed, str1, str2, false);
				DCC_SendChannelEmbedMessage(channel, embed);

				SendClientMessageEx(ii, COLOR_ORANGE2, "[IKLAN] "GREEN_E"%s.", params);
				SendClientMessageEx(ii, COLOR_ORANGE2, "Contact Info: ["GREEN_E"%s"ORANGE_E2"] Ph: ["GREEN_E"%d"ORANGE_E2"] Bank Rek: ["GREEN_E"%d"ORANGE_E2"]", pData[playerid][pName], pData[playerid][pPhone], pData[playerid][pBankRek]);
			}
		}
		Add_AdsLog(playerid, params);
	}
	else
	{
		if(GetPVarInt(playerid, "delay") > gettime()) 
			return ErrorMsg(playerid, "Anda harus menunggu 10 menit untuk menggunakannya");

		if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
			return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

		if(!IsPlayerInRangeOfPoint(playerid, 3.0, 1385.32, -17.19, 1001.00)) 
			return ErrorMsg(playerid, "Anda harus berada di SA-News");
		
		if(Inventory_Count(playerid, "Phone") < 1)
			return ErrorMsg(playerid, "Anda tidak memiliki Ponsel");
		
		if(isnull(params))
		{
			SyntaxMsg(playerid, "/ads [text] | 1 karakter $2");
			return 1;
		}
		if(strlen(params) >= 100 ) return ErrorMsg(playerid, "Anda tidak dapat menuliskan lebih dari 100 kata");
		new payout = strlen(params) * 2;
		if(pData[playerid][pMoney] < payout) return ErrorMsg(playerid, "Uanga anda tidak mencukupi");
		
		GivePlayerMoneyEx(playerid, -payout);
		Server_AddMoney(payout);
		SetPVarInt(playerid, "delay", gettime() + 600);
		foreach(new ii : Player)
		{
			if(pData[ii][pTogAds] == 0)
			{
                new DCC_Channel:channel;
                channel = DCC_FindChannelById("1324765314063532154");
                new DCC_Embed:embed = DCC_CreateEmbed(.title = "Advertisement");
                new str1[350], str2[350];

                format(str1, sizeof str1, "**__Advertisement__**");
                format(str2, sizeof str2, "\n%s", params);
                DCC_AddEmbedField(embed, str1, str2, false);
                format(str1, sizeof str1, "**__Contact Info__**");
                format(str2, sizeof str2, "\n%s", pData[playerid][pName]);
                DCC_AddEmbedField(embed, str1, str2, false);
                format(str1, sizeof str1, "**__Phone Number__**");
                format(str2, sizeof str2, "\n%d", pData[playerid][pPhone]);
				DCC_AddEmbedField(embed, str1, str2, false);
				format(str1, sizeof str1, "**__Bank Rekening__**");
                format(str2, sizeof str2, "\n%d", pData[playerid][pBankRek]);
				DCC_AddEmbedField(embed, str1, str2, false);
				DCC_SendChannelEmbedMessage(channel, embed);
                
				SendClientMessageEx(ii, COLOR_ORANGE2, "[IKLAN] "GREEN_E"%s.", params);
				SendClientMessageEx(ii, COLOR_ORANGE2, "Contact Info: ["GREEN_E"%s"ORANGE_E2"] Ph: ["GREEN_E"%d"ORANGE_E2"] Bank Rek: ["GREEN_E"%d"ORANGE_E2"]", pData[playerid][pName], pData[playerid][pPhone], pData[playerid][pBankRek]);
			}
		}
		Add_AdsLog(playerid, params);
	}
	return 1;
}