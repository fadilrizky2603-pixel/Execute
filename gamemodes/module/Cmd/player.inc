//-------------[ Player Commands ]-------------//
CMD:vm(playerid, params[])
{
    //ShowPlayerDialog(playerid, DIALOG_MVOICE, DIALOG_STYLE_LIST, "Voice Mode", rstring, "Pilih","Batalkan");
    ShowPlayerDialog(playerid, DIALOG_VOICEMODE, DIALOG_STYLE_TABLIST_HEADERS, "Voice Mode {FFFF00}'/vm'", "Mode\tRadius\t\n{FFFFFF}Medium\t{FFFB00}20.0\t\n{FFFFFF}High\t{FFFB00}80.0\t\n{FAFAFA}Low\t{FFFB00}10.0\t", "Select", "Batal");
    return 1;
}

CMD:claimsp(playerid, const params[])
{
	if(pData[playerid][pStarterPack] == 1) 
		return ErrorMsg(playerid, "Anda tidak dapat mengambil StarterPack lagi");
		
	pData[playerid][pStarterPack] = 1;
	GivePlayerMoneyEx(playerid, 15000);

	Inventory_Add(playerid, "Jus Jeruk", 19563, 5);
	Inventory_Add(playerid, "Roti", 19579, 5);
	InfoTD_MSG(playerid, 4000, "Anda berhasil claim ~y~Starter-Pack");
	
	return 1;
}
CMD:stats(playerid, const params[])
{
	if(pData[playerid][IsLoggedIn] == false)
	{
	    Error(playerid, "You must be logged in to check statistics!");
	    return 1;
	}
	
	DisplayStats(playerid, playerid);
	return 1;
}
CMD:gps(playerid, const params[])
{
	ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "Maps", "Lokasi Umum\nLokasi Pekerjaan\n{FFE5CC}Lokasi Garkot{FFFFFF}\n{00FFEF}Lokasi Toko{FFFFFF}\n{FF8000}Lokasi Pom Bensin{FFFFFF}\n{8D6D48}Lokasi Workshop{FFFFFF}\n{00FF00}Lokasi ATM{FFFFFF}\n{FFFF00}Property Saya{FFFFFF}\n{FFFFFF}Lokasi Berangkas Umum\n{FF0000}Disable Checkpoint!", "Select", "Close");
	return 1;
}

CMD:testobj(playerid, const params[])
{
	CreatePlayerObject(playerid, 17011, 1513.8694, 14.9613, 23.1506, 0.100000, -88.099990, 96.099998);
	return 1;
}

CMD:sid(playerid, const params[])
{
	if(TogPTags[playerid] == 0)
	{
		for (new ii = 0; ii < MAX_PLAYERS; ii++)
		{
			if(pData[ii][IsLoggedIn] == true)
			{
				new nametag[128];
				format(nametag, sizeof(nametag), "%d - HP: [{FF0000}%.1f{FFFFFF}]\nAR: [{C1C1C1}%.1f{FFFFFF}]", ii, pData[ii][pHealth], pData[ii][pArmour]);
				PlayerTags[ii] = CreatePlayer3DTextLabel(playerid, nametag, -1, 0.0, 0.0, 0.3, 10, ii, 0);
			}
		}
		TogPTags[playerid] = 1;
		Info(playerid, "Berhasil mengaktifkan ID Tags Players");
	}
	else
	{
		for (new ii = 0; ii < MAX_PLAYERS; ii++)
		{
			DeletePlayer3DTextLabel(playerid, PlayerTags[ii]);
		}
		TogPTags[playerid] = 0;
		Info(playerid, "Berhasil menonkatifkan ID Tags Players");
	}
	return 1;
}


CMD:give(playerid, const params[])
{
	if(IsPlayerConnected(playerid)) 
	{
		new name[24], ammount, otherid;
		if(sscanf(params, "us[24]d", otherid, name, ammount))
		{
			SyntaxMsg(playerid, "/give [playerid] [name] [ammount]");
			Info(playerid, "[Food] - [Gandum] - [Seed] - [Potato] - [Wheat] - [Orange]");
			return 1;
		}
		if(otherid == INVALID_PLAYER_ID || otherid == playerid || !NearPlayer(playerid, otherid, 3.0))
			return ErrorMsg(playerid, "Player tersebut sedang tidak berada di dekat anda");

		if(strcmp(name,"seed",true) == 0) 
		{
			if(pData[playerid][pSeed] < ammount)
				return ErrorMsg(playerid, "Items anda tidak mencukupi");

			if(ammount < 1) return ErrorMsg(playerid, "Tidak dapat memberikan kurang dari 1");

			pData[playerid][pSeed] -= ammount;
			pData[otherid][pSeed] += ammount;
			Info(playerid, "Anda telah berhasil memberikan Seed kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "%s telah berhasil memberikan Seed kepada anda sejumlah %d.", ReturnName(playerid), ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
	}
	return 1;
}

CMD:setnumber(playerid, const params[])
{
	if(pData[playerid][pVip] < 1)
		return ErrorMsg(playerid, "Hanya player VIP yang bisa mengakses ini");
	
	new str[200];
	if(pData[playerid][pVipNumber] >= gettime())
	{
		format(str, sizeof(str), "Anda harus menunggu %d second sebelum menganti Nomor lagi", pData[playerid][pVipNumber] - gettime());
		ErrorMsg(playerid, str);
		return 1;
	}

	new number;
	if(sscanf(params, "d", number))
		return SyntaxMsg(playerid, "Gunakan /setnumber [number]");

	if(number < 1111 || number > 99999)
		return ErrorMsg(playerid, "Hanya bisa 4 & 5 Digit");

	new cQuery[254];
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "SELECT phone FROM players WHERE phone = '%d'", number);
	mysql_tquery(g_SQL, cQuery, "VipSetNumber", "dd", playerid, number);
	return 1;
}

CMD:cc( playerid, params[], help) 
{
	for(new j; j < 20; j++ ) 
	{
		SendClientMessage(playerid, COLOR_WHITE, " ");
	}
	return 1;
}

CMD:ccall( playerid, params[], help) 
{
	if(pData[playerid][pAdmin] < 2)
		return PermissionError(playerid);

	for(new j; j < 20; j++ ) 
	{
		va_SendClientMessageToAll(-1, " ");
	}
	return 1;
}

CMD:dice(playerid, const params[])
{
	SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s melempar dadu yang mendarat di angka %d.", ReturnName(playerid), random(6) + 1);
	return 1;
}

CMD:flipcoin(playerid, const params[])
{
	SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s melempar koin yang mendarat di %s.", ReturnName(playerid), (random(2)) ? ("Heads") : ("Tails"));
	return 1;
}

CMD:dicebet(playerid, const params[])
{
	new otherid, amount;

	if(sscanf(params, "dd", otherid, amount))
	    return Usage(playerid, "/dicebet [playerid] [amount]");

    if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 5.0))
	    return ErrorMsg(playerid, "Player yang di tentukan tidak ada atau sedang tidak di sekitar");

	if(otherid == playerid)
	    return ErrorMsg(playerid, "Tidak dapat melakukannya pada diri sendiri");

	if(amount < 1)
	    return ErrorMsg(playerid, "Jumlah yang anda isikan tidak boleh kosong");

	if(pData[playerid][pMoney] < amount)
	    return ErrorMsg(playerid, "Uang yang anda masukan tidak cukup untuk bertaruh");

	if(gettime() - pData[playerid][pLastBet] < 10)
	    return Error(playerid, "You can only use this command every 10 seconds. Please wait %d more seconds.", 10 - (gettime() - pData[playerid][pLastBet]));

	pData[otherid][pDiceOffer] = playerid;
	pData[otherid][pDiceBet] = amount;
	pData[otherid][pDiceRigged] = 0;
	pData[playerid][pLastBet] = gettime();

	Info(otherid, "* %s has initiated a dice bet with you for %s (/accept dicebet).", ReturnName(playerid), FormatMoney(amount));
	Info(playerid, "* You have initiated a dice bet against %s for %s.", ReturnName(otherid), FormatMoney(amount));
	return 1;
}

/*CMD:joinjob(playerid, const params[])
{
	if(pData[playerid][pIDCard] <= 0)
		return Error(playerid, "Anda tidak memiliki ID-Card.");
		
	if(pData[playerid][pVip] > 0)
	{
		if(pData[playerid][pJob] == 0 || pData[playerid][pJob2] == 0)
		{
			if(pData[playerid][pJob] == 0)
			{
				if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 5.0, 2165.21, -1673.13, 15.07))
				{
					pData[playerid][pGetJob] = 12;
					Info(playerid, "Anda telah berhasil mendaftarkan job Drug Dealer. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 5.0, 1366.16, -1274.58, 13.54))
				{
					pData[playerid][pGetJob] = 13;
					Info(playerid, "Anda telah berhasil mendaftarkan job Weapon Dealer. /accept job untuk konfirmasi.");
				}
				else return Error(playerid, "Anda sudah memiliki job atau tidak berada di dekat pendaftaran job.");
			}
			else if(pData[playerid][pJob2] == 0)
			{
				if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 5.0, 2989.5288, 2762.0352, -0.5533))
				{
					pData[playerid][pGetJob2] = 12;
					Info(playerid, "Anda telah berhasil mendaftarkan job Drug Dealer. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 5.0, 1366.16, -1274.58, 13.54))
				{
					pData[playerid][pGetJob2] = 13;
					Info(playerid, "Anda telah berhasil mendaftarkan job Weapon Dealer. /accept job untuk konfirmasi.");
				}
				else return Error(playerid, "Anda sudah memiliki job atau tidak berada di dekat pendaftaran job.");
			}
			else return Error(playerid, "Anda sudah memiliki 2 pekerjaan!");
		}
		else return Error(playerid, "Anda sudah memiliki 2 pekerjaan!");
	}
	else
	{
		if(pData[playerid][pJob] > 0)
			return Error(playerid, "Anda hanya bisa memiliki 1 pekerjaan!");
		
		if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 5.0, 2165.21, -1673.13, 15.07))
		{
			pData[playerid][pGetJob] = 12;
			Info(playerid, "Anda telah berhasil mendaftarkan job Drug Dealer. /accept job untuk konfirmasi.");
		}
		else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 5.0, 1366.16, -1274.58, 13.54))
		{
			pData[playerid][pGetJob] = 13;
			Info(playerid, "Anda telah berhasil mendaftarkan job Weapon Dealer. /accept job untuk konfirmasi.");
		}
		else return Error(playerid, "Anda sudah memiliki job atau tidak berada di dekat pendaftaran job.");
	}
	return 1;
}*/

CMD:vip(playerid, const params[])
{
	new text[1024];
	if(pData[playerid][pVip] == 0)
		return ErrorMsg(playerid, "Anda bukan bagian dari VIP");

	if(pData[playerid][pTogVip] == 1)
		return ErrorMsg(playerid, "Anda belum mengaktifkan VIP. Gunakan /togvip");
	
	if(sscanf(params,"s[1024]", text))
        return SyntaxMsg(playerid, "/vip [text]");

    if(strval(text) > 1024)
        return ErrorMsg(playerid,"Text yang anda masukan terlalu panjang");

    new name[40];
	if(pData[playerid][pVip] == 1)
	{
		name = "Regular(1)";
	}
	else if(pData[playerid][pVip] == 2)
	{
		name = "Premium(2)";
	}
	else if(pData[playerid][pVip] == 3)
	{
		name = "High(3)";
	}
	else
	{
		name = "None";
	}
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i))
		{
			if(pData[i][pVip] > 0 && pData[i][pTogVip] == 0)
			{
				SendClientMessageEx(i, COLOR_FAMILY, ""FAMILY_E"[VIP CHAT] %s %s: %s", name, ReturnName(playerid), text);
			}
		}
	}
	return 1;
}

CMD:togvip(playerid, const params[])
{
	if(pData[playerid][pVip] == 0)
		return ErrorMsg(playerid, "Anda bukan bagian dari VIP");

	if(pData[playerid][pTogVip] == 0)
	{
		pData[playerid][pTogVip] = 1;
		SuccesMsg(playerid, "VIP Chat berhasil di non-aktifkan");
	}
	else
	{
		pData[playerid][pTogVip] = 0;
		SuccesMsg(playerid, "VIP Chat berhasil di aktifkan");
	}
	return 1;
}

CMD:shakehand(playerid, const params[])
{
	new otherid, type;
	if(sscanf(params, "ui", otherid, type))
	    return SyntaxMsg(playerid, "/shakehand [playerid] [type (1-6)]");

	if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
	    return ErrorMsg(playerid, "Player yang di tuju tidak ada di sekitar anda");

	if(otherid == playerid)
	    return ErrorMsg(playerid, "Anda tidak dapat Shake Hand pada diri sendiri");

	if(!(1 <= type <= 6))
	    return ErrorMsg(playerid, "Type shake Hand yang anda masukan salah. 1-6");

	pData[otherid][pShakeOffer] = playerid;
	pData[otherid][pShakeType] = type;

	Info(otherid, "%s has offered to shake your hand. (/accept handshake)", ReturnName(playerid));
	Info(playerid, "You have sent %s a handshake offer.", ReturnName(otherid));
	return 1;
}

CMD:calculate(playerid, const params[])
{
	new option, Float:value1, Float:value2;
	if(Inventory_Count(playerid, "Phone") < 1)
		return ErrorMsg(playerid, "Anda tidak memiliki Ponsel");

	if(pData[playerid][pUsePhone] == 0) 
		return ErrorMsg(playerid, "Saat ini status Handphone anda sedang mati");

	if(sscanf(params, "fcf", value1, option, value2))
	{
	    Usage(playerid, "/calculate [value 1] [option] [value 2]");
	    Usage(playerid, "List opsi: (+) Menambah (-) Berkurang (*) Berkembang (/) Membagi");
	    return 1;
	}
	if(option == '/' && value2 == 0)
	{
	    return ErrorMsg(playerid, "Anda tidak dapat membagi dengan angka nol.");
	}

	if(option == '+') 
	{
	    Info(playerid, "Hasil: %0.0f + %0.0f = %0.0f", value1, value2, value1 + value2);
	} 
	else if(option == '-') 
	{
	    Info(playerid, "* Hasil: %0.0f - %0.0f = %0.0f", value1, value2, value1 - value2);
	} 
	else if(option == '*' || option == 'x') 
	{
		Info(playerid, "* Hasil: %0.0f * %0.0f = %0.0f", value1, value2, value1 * value2);
	}
	else if(option == '/') 
	{
		Info(playerid, "* Hasil: %0.0f / %0.0f = %0.0f", value1, value2, value1 / value2);
	}
	return 1;
}

CMD:help(playerid, const params[])
{
	new str[512], info[512];
	format(str, sizeof(str), "Account Commands\nOther Commands\nVehicle Commands\nJobs Commands\nFaction/Family Commands\nAuto RP Commands\nWorkshop Commands\nVending Commands\nDealer Commands\nHouse Commands\nPrivate Farm Commands\nRobbing Commands\nServer Credits\n");
	strcat(info, str);
	ShowPlayerDialog(playerid, DIALOG_HELP, DIALOG_STYLE_LIST, "Local Prime Roleplay Help Menu", info, "Select", "Close");
	return 1;
}

CMD:dcp(playerid, const params[])
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	if(pData[playerid][pSideJob] > 1 || pData[playerid][pCP] > 1)
		return Error(playerid, "Harap selesaikan Pekerjaan mu terlebih dahulu");

	DisablePlayerCheckpoint(playerid);
	DisablePlayerRaceCheckpoint(playerid);
	SuccesMsg(playerid, "Anda berhasil menonaktifkan Checkpoint");
	return 1;
}

CMD:togphone(playerid)
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	if(Inventory_Count(playerid, "Phone") < 1)
		return ErrorMsg(playerid, "Anda tidak memilik phone!");

	if(pData[playerid][pUsePhone] == 0)
	{
		pData[playerid][pUsePhone] = 1;
		SuccesMsg(playerid, "Handphone anda berhasil di aktifkan");
	}
	else
	{
		pData[playerid][pUsePhone] = 0;
		SuccesMsg(playerid, "Handphone anda berhasil di nonaktifkan");
	}
	return 1;
}

CMD:savestats(playerid, const params[])
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	if(pData[playerid][IsLoggedIn] == false)
		return Error(playerid, "Kamu belum login!");
		
	UpdatePlayerData(playerid);
	Servers(playerid, "Statistik Anda sukses disimpan kedalam Database!");
	return 1;
}

CMD:gshop(playerid, const params[])
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	new Dstring[512];
	format(Dstring, sizeof(Dstring), "Gold Shop\tPrice\n\
	Instant Change Name\t500 Gold\n");
	format(Dstring, sizeof(Dstring), "%sClear Warning\t500 Gold\n", Dstring);
	format(Dstring, sizeof(Dstring), "%sVIP Level 1(14 Days)\t300 Gold\n", Dstring);
	format(Dstring, sizeof(Dstring), "%sVIP Level 2(14 Days)\t400 Gold\n", Dstring);
	format(Dstring, sizeof(Dstring), "%sVIP Level 3(14 Days)\t500 Gold\n", Dstring);
	ShowPlayerDialog(playerid, DIALOG_GOLDSHOP, DIALOG_STYLE_TABLIST_HEADERS, "Gold Shop", Dstring, "Buy", "Cancel");
	return 1;
}

CMD:death(playerid, const params[])
{
    if(pData[playerid][pInjured] == 0)
        return ErrorMsg(playerid, "Kamu belum injured.");
		
	if(pData[playerid][pJail] > 0)
		return ErrorMsg(playerid, "Kamu tidak bisa menggunakan ini saat diJail!");
		
	if(pData[playerid][pArrest] > 0)
		return ErrorMsg(playerid, "Kamu tidak bisa melakukan ini saat tertangkap polisi!");

    if((gettime()-GetPVarInt(playerid, "GiveUptime")) < 900)
        return ErrorMsg(playerid, "Kamu harus menunggu 15 menit untuk kembali kerumah sakit");

    SuccesMsg(playerid, "Anda berhasil terbangun dari Pingsan");
	pData[playerid][pHospitalTime] = 0;
	pData[playerid][pHospital] = 1;
    return 1;
}

CMD:health(playerid, const params[])
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	new hstring[512], info[512];
	new hh = pData[playerid][pHead];
	new hp = pData[playerid][pPerut];
	new htk = pData[playerid][pRHand];
	new htka = pData[playerid][pLHand];
	new hkk = pData[playerid][pRFoot];
	new hkka = pData[playerid][pLFoot];
	new leveldrug[128];
	if(pData[playerid][pUseDrug] >= 1 && pData[playerid][pUseDrug] <= 10)
	{
		leveldrug = "{00ff00}LOW USER";
	}
	else if(pData[playerid][pUseDrug] >= 11 && pData[playerid][pUseDrug] <= 20)
	{
		leveldrug = ""YELLOW_E"MEDIUM USER";
	}
	else if(pData[playerid][pUseDrug] >= 21)
	{
		leveldrug = "{ff0000}HARD USER";
	}
	else
	{
		leveldrug = "{00ff00}NOT USER";
	}
	format(hstring, sizeof(hstring),"[Bagian Tubuh]\tKondisi\n{ffffff}Kepala\t{7fffd4}%d.0%\n{ffffff}Perut\t{7fffd4}%d.0%\n{ffffff}Tangan Kanan\t{7fffd4}%d.0%\n{ffffff}Tangan Kiri\t{7fffd4}%d.0%\n",hh,hp,htk,htka);
	strcat(info, hstring);
    format(hstring, sizeof(hstring),"{ffffff}Kaki Kanan\t{7fffd4}%d.0%\n{ffffff}Kaki Kiri\t{7fffd4}%d.0%\n{ffffff}Status Urine :\t%s\n",hkk,hkka,leveldrug);
    strcat(info, hstring);
	ShowPlayerDialog(playerid, DIALOG_HEALTH, DIALOG_STYLE_TABLIST_HEADERS,"Health Condition",info,"Oke","");
    return 1;
}

CMD:sleep(playerid, const params[])
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	if(pData[playerid][pInjured] == 1)
        return InfoTD_MSG(playerid, 4000, "Anda tidak dapat menggunakan ~y~/sleep ~w~saat Injured");
	
	if(pData[playerid][pInHouse] == -1)
		return ErrorMsg(playerid, "Anda sedang tidak berada di dalam rumah");
	
	InfoMsg(playerid, "Sleeping... Harap Tunggu");
	TogglePlayerControllable(playerid, 0);
	new time = (100 - pData[playerid][pEnergy]) * (400);
    SetTimerEx("UnfreezeSleep", time, 0, "i", playerid);
	switch(random(6))
	{
		case 0: ApplyAnimation(playerid, "INT_HOUSE", "BED_In_L",4.1,0,0,0,1,1);
		case 1: ApplyAnimation(playerid, "INT_HOUSE", "BED_In_R",4.1,0,0,0,1,1);
		case 2: ApplyAnimation(playerid, "INT_HOUSE", "BED_Loop_L",4.1,1,0,0,1,1);
		case 3: ApplyAnimation(playerid, "INT_HOUSE", "BED_Loop_R",4.1,1,0,0,1,1);
		case 4: ApplyAnimation(playerid, "INT_HOUSE", "BED_Out_L",4.1,0,1,1,0,0);
		case 5: ApplyAnimation(playerid, "INT_HOUSE", "BED_Out_R",4.1,0,1,1,0,0);
	}
	return 1;
}

/*CMD:salary(playerid, const params[])
{
	new query[256], count;
	format(query, sizeof(query), "SELECT * FROM salary WHERE owner='%d'", pData[playerid][pID]);
	new Cache:result = mysql_query(g_SQL, query);
	new rows = cache_num_rows();
	if(rows) 
	{
		new str[2048];
		for(new i; i < rows; i++)
		{
			new info[64];
			cache_get_value_int(i, "id", pSalary[playerid][i][salaryId]);
			cache_get_value_int(i, "money", pSalary[playerid][i][salaryMoney]);
			cache_get_value(i, "info", info);
			format(pSalary[playerid][i][salaryInfo], 64, "%s", info);
			cache_get_value_int(i, "date", pSalary[playerid][i][salaryDate]);
			
			format(str, sizeof(str), "%s%s\t%s\t%s\n", str, ReturnDate(pSalary[playerid][i][salaryDate]), pSalary[playerid][i][salaryInfo], FormatMoney(pSalary[playerid][i][salaryMoney]));
			count++;
			if(count >= 10) break;
		}
		format(str, sizeof(str), "Date\tInfo\tCash\n", str);
		if(count >= 10)
		{
			format(str, sizeof(str), "%s\nNext >>>", str);
		}
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Salary Details", str, "Close", "");
	}
	else 
	{
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Notice", "Kamu tidak memiliki salary saat ini!", "Ok", "");
	}
	cache_delete(result);
	return 1;
}*/

CMD:time(playerid)
{
	if(pData[playerid][IsLoggedIn] == false)
		return Error(playerid, "Kamu harus login!");
		
	new line2[1200];
	new paycheck = 3600 - pData[playerid][pPaycheck];
	if(paycheck < 1)
	{
		paycheck = 0;
	}
	
	format(line2, sizeof(line2), ""WHITE_E"Paycheck Time: "YELLOW_E"%d remaining\n"WHITE_E"Delay Job: "RED_E"%d Detik\n"WHITE_E"Delay Side Job: "RED_E"%d Detik\n"WHITE_E"Plant Time(Farmer): "RED_E"%d Detik\n"WHITE_E"Arrest Time: "RED_E"%d Detik\n"WHITE_E"Jail Time: "RED_E"%d Detik\n", paycheck, pData[playerid][pJobTime], pData[playerid][pSideJobTime], pData[playerid][pPlantTime], pData[playerid][pArrestTime], pData[playerid][pJailTime]);
   	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""ORANGE_E"LT:RP"WHITE_E"Time", line2, "Oke", "");
	return 1;
}

/*CMD:idcard(playerid, const params[])
{
	if(pData[playerid][pIDCard] == 0) return Error(playerid, "Anda tidak memiliki id card!");
	new sext[40];
	if(pData[playerid][pGender] == 1) { sext = "Male"; } else { sext = "Female"; }
	SendNearbyMessage(playerid, 20.0, COLOR_GREEN, "[ID-Card] "GREY3_E"Name: %s | Gender: %s | Brithday: %s | Expire: %s.", pData[playerid][pName], sext, pData[playerid][pAge], ReturnTimelapse(gettime(), pData[playerid][pIDCardTime]));
	return 1;
}*/
CMD:idcard(playerid, const params[])
{
	if(pData[playerid][pIDCard] == 0) return ErrorMsg(playerid, "Anda tidak memiliki KTP");

	new strings[256], fac[24];
	if(pData[playerid][pFaction] == 1)
	{
		fac = "Police";
	}
	else if(pData[playerid][pFaction] == 2)
	{
		fac = "Goverment";
	}
	else if(pData[playerid][pFaction] == 3)
	{
		fac = "Medic";
	}
	else if(pData[playerid][pFaction] == 4)
	{
		fac = "News";
	}
	else if(pData[playerid][pFaction] == 5)
	{
		fac = "Pedagang";
	}
	else
	{
		fac = "Pengangguran";
	}
	new sext[50];
	if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }

	format(strings, sizeof(strings), "%s", pData[playerid][pName]);
	PlayerTextDrawSetString(playerid, NatKTP[playerid][19], strings);

	format(strings, sizeof(strings), "%s", pData[playerid][pAge]);
	PlayerTextDrawSetString(playerid, NatKTP[playerid][20], strings);

	format(strings, sizeof(strings), "%s", sext);
	PlayerTextDrawSetString(playerid, NatKTP[playerid][21], strings);

	format(strings, sizeof(strings), "%s", fac);
	PlayerTextDrawSetString(playerid, NatKTP[playerid][22], strings);

	format(strings, sizeof(strings), "%s", pData[playerid][pUcp]);
	PlayerTextDrawSetString(playerid, NatKTP[playerid][27], strings);

	format(strings, sizeof(strings), "%s", ReturnTimelapse(gettime(), pData[playerid][pIDCardTime]));
	PlayerTextDrawSetString(playerid, NatKTP[playerid][24], strings);

	if(GetPlayerSkin(playerid) != GetPVarInt(playerid, "ktp_skin"))
	{
		PlayerTextDrawSetPreviewModel(playerid, NatKTP[playerid][26], GetPlayerSkin(playerid));
		SetPVarInt(playerid, "ktp_skin", GetPlayerSkin(playerid));
	}
	for(new i = 0; i < 28; i++)
	{
		PlayerTextDrawShow(playerid, NatKTP[playerid][i]);
	}
	Usage(playerid, "Gunakan {FFFF00}'/hcard' {FFFFFF}untuk menutup KTP");
	return 1;
}

CMD:showidcard(playerid, const params[])
{
	if(pData[playerid][pIDCard] == 0) return ErrorMsg(playerid, "Anda tidak memiliki KTP");

	new strings[640];
	new otherid = Player_Near(playerid);
    new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	if(IsPlayerInRangeOfPoint(otherid, 2, Float:x, Float:y, Float:z))
	{
		new fac[24];
		if(pData[playerid][pFaction] == 1)
		{
			fac = "Police";
		}
		else if(pData[playerid][pFaction] == 2)
		{
			fac = "Goverment";
		}
		else if(pData[playerid][pFaction] == 3)
		{
			fac = "Medic";
		}
		else if(pData[playerid][pFaction] == 4)
		{
			fac = "News";
		}
		else if(pData[playerid][pFaction] == 5)
		{
			fac = "Pedagang";
		}
		else
		{
			fac = "Pengangguran";
		}
		new sext[50];
		if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }

		format(strings, sizeof(strings), "%s", pData[playerid][pName]);
		PlayerTextDrawSetString(otherid, NatKTP[playerid][19], strings);

		format(strings, sizeof(strings), "%s", pData[playerid][pAge]);
		PlayerTextDrawSetString(otherid, NatKTP[playerid][20], strings);

		format(strings, sizeof(strings), "%s", sext);
		PlayerTextDrawSetString(otherid, NatKTP[playerid][21], strings);

		format(strings, sizeof(strings), "%s", fac);
		PlayerTextDrawSetString(otherid, NatKTP[playerid][22], strings);

		format(strings, sizeof(strings), "%s", pData[playerid][pUcp]);
		PlayerTextDrawSetString(otherid, NatKTP[playerid][27], strings);

		format(strings, sizeof(strings), "%s", ReturnTimelapse(gettime(), pData[playerid][pIDCardTime]));
		PlayerTextDrawSetString(otherid, NatKTP[playerid][24], strings);

		if(GetPlayerSkin(playerid) != GetPVarInt(playerid, "ktp_skin"))
		{
			PlayerTextDrawSetPreviewModel(otherid, NatKTP[playerid][26], GetPlayerSkin(playerid));
			SetPVarInt(playerid, "ktp_skin", GetPlayerSkin(playerid));
		}
		for(new i = 0; i < 28; i++)
		{
			PlayerTextDrawShow(otherid, NatKTP[playerid][i]);
		}
		Usage(otherid, "Gunakan {FFFF00}'/hcard' {FFFFFF}untuk menutup KTP");
	}
	return 1;
}

/*CMD:drivelic(playerid, const params[])
{
	if(pData[playerid][pDriveLic] == 0) return Error(playerid, "Anda tidak memiliki Driving License/SIM!");
	new sext[40];
	if(pData[playerid][pGender] == 1) { sext = "Male"; } else { sext = "Female"; }
	SendNearbyMessage(playerid, 20.0, COLOR_GREEN, "[Drive-Lic] "GREY3_E"Name: %s | Gender: %s | Brithday: %s | Expire: %s.", pData[playerid][pName], sext, pData[playerid][pAge], ReturnTimelapse(gettime(), pData[playerid][pDriveLicTime]));
	return 1;
}*/

CMD:drivelic(playerid, const params[])
{
	if(pData[playerid][pDriveLic] == 0) return ErrorMsg(playerid, "Anda tidak memiliki SIM");

	new strings[256], fac[24];
	if(pData[playerid][pFaction] == 1)
	{
		fac = "Police";
	}
	else if(pData[playerid][pFaction] == 2)
	{
		fac = "Goverment";
	}
	else if(pData[playerid][pFaction] == 3)
	{
		fac = "Medic";
	}
	else if(pData[playerid][pFaction] == 4)
	{
		fac = "News";
	}
	else if(pData[playerid][pFaction] == 5)
	{
		fac = "Pedagang";
	}
	else
	{
		fac = "Pengangguran";
	}

	format(strings, sizeof(strings), "%s", pData[playerid][pName]);
	PlayerTextDrawSetString(playerid, NatDriveLic[playerid][20], strings);

	format(strings, sizeof(strings), "%s", pData[playerid][pAge]);
	PlayerTextDrawSetString(playerid, NatDriveLic[playerid][21], strings);

	format(strings, sizeof(strings), "%s", fac);
	PlayerTextDrawSetString(playerid, NatDriveLic[playerid][22], strings);

	format(strings, sizeof(strings), "%s", pData[playerid][pUcp]);
	PlayerTextDrawSetString(playerid, NatDriveLic[playerid][24], strings);

	format(strings, sizeof(strings), "%s", ReturnTimelapse(gettime(), pData[playerid][pIDCardTime]));
	PlayerTextDrawSetString(playerid, NatDriveLic[playerid][23], strings);

	if(GetPlayerSkin(playerid) != GetPVarInt(playerid, "sim_skin"))
	{
		PlayerTextDrawSetPreviewModel(playerid, NatDriveLic[playerid][8], GetPlayerSkin(playerid));
		SetPVarInt(playerid, "sim_skin", GetPlayerSkin(playerid));
	}
	for(new i = 0; i < 25; i++)
	{
		PlayerTextDrawShow(playerid, NatDriveLic[playerid][i]);
	}
	Usage(playerid, "Gunakan {FFFF00}'/hcard' {FFFFFF}untuk menutup SIM");
	return 1;
}

CMD:showdrivelic(playerid, const params[])
{
	if(pData[playerid][pDriveLic] == 0) return ErrorMsg(playerid, "Anda tidak memiliki SIM");
	
	new strings[640];
	new otherid = Player_Near(playerid);
    new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	if(IsPlayerInRangeOfPoint(otherid, 2, Float:x, Float:y, Float:z))
	{
		new fac[24];
		if(pData[playerid][pFaction] == 1)
		{
			fac = "Police";
		}
		else if(pData[playerid][pFaction] == 2)
		{
			fac = "Goverment";
		}
		else if(pData[playerid][pFaction] == 3)
		{
			fac = "Medic";
		}
		else if(pData[playerid][pFaction] == 4)
		{
			fac = "News";
		}
		else if(pData[playerid][pFaction] == 5)
		{
			fac = "Pedagang";
		}
		else
		{
			fac = "Pengangguran";
		}

		format(strings, sizeof(strings), "%s", pData[playerid][pName]);
		PlayerTextDrawSetString(otherid, NatDriveLic[playerid][20], strings);

		format(strings, sizeof(strings), "%s", pData[playerid][pAge]);
		PlayerTextDrawSetString(otherid, NatDriveLic[playerid][21], strings);

		format(strings, sizeof(strings), "%s", fac);
		PlayerTextDrawSetString(otherid, NatDriveLic[playerid][22], strings);

		format(strings, sizeof(strings), "%s", pData[playerid][pUcp]);
		PlayerTextDrawSetString(otherid, NatDriveLic[playerid][24], strings);

		format(strings, sizeof(strings), "%s", ReturnTimelapse(gettime(), pData[playerid][pIDCardTime]));
		PlayerTextDrawSetString(otherid, NatDriveLic[playerid][23], strings);

		if(GetPlayerSkin(playerid) != GetPVarInt(playerid, "sim_skin"))
		{
			PlayerTextDrawSetPreviewModel(otherid, NatDriveLic[playerid][8], GetPlayerSkin(playerid));
			SetPVarInt(playerid, "sim_skin", GetPlayerSkin(playerid));
		}
		for(new i = 0; i < 25; i++)
		{
			PlayerTextDrawShow(otherid, NatDriveLic[playerid][i]);
		}
		Usage(otherid, "Gunakan {FFFF00}'/hcard' {FFFFFF}untuk menutup SIM");
	}
	return 1;
}

CMD:hcard(playerid, const params[])
{
	for(new i = 0; i < 28; i++)
	{
		PlayerTextDrawHide(playerid, NatKTP[playerid][i]);
	}
	for(new i = 0; i < 25; i++)
	{
		PlayerTextDrawHide(playerid, NatDriveLic[playerid][i]);
	}
	return 1;
}

CMD:newidcard(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 910.90, 256.46, 1289.98)) return ErrorMsg(playerid, "Anda harus berada di Balai Kota");
	if(pData[playerid][pIDCard] != 0) return ErrorMsg(playerid, "Saat ini anda sudah memiliki ID-Card");
	if(pData[playerid][pMoney] < 500) return ErrorMsg(playerid, "Uang anda tidak cukup untuk membuat ID-Card");
	new sext[40], mstr[128];
	if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }
	format(mstr, sizeof(mstr), "{FFFFFF}Nama: %s\nNegara: San Andreas\nTgl Lahir: %s\nJenis Kelamin: %s\nBerlaku hingga 14 hari!", pData[playerid][pName], pData[playerid][pAge], sext);
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "ID-Card", mstr, "Tutup", "");
	pData[playerid][pIDCard] = 1;
	pData[playerid][pIDCardTime] = gettime() + (15 * 86400);
	GivePlayerMoneyEx(playerid, -500);
	Server_AddMoney(500);
	return 1;
}

CMD:newage(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 910.90, 256.46, 1289.98)) return ErrorMsg(playerid, "Anda harus berada di Balai Kota");
	//if(pData[playerid][pIDCard] != 0) return Error(playerid, "Anda sudah memiliki ID Card!");
	if(pData[playerid][pMoney] < 2000) return ErrorMsg(playerid, "Uang anda tidak cukup untuk mengganti umur");
	if(pData[playerid][IsLoggedIn] == false) return Error(playerid, "Anda harus login terlebih dahulu!");
	ShowPlayerDialog(playerid, DIALOG_CHANGEAGE, DIALOG_STYLE_INPUT, "Tanggal Lahir", "Masukan tanggal lahir (Tgl/Bulan/Tahun): 15/04/1998", "Change", "Cancel");
	return 1;
}

CMD:newdrivelic(playerid, const params[])
{
    //if(!IsPlayerInRangeOfPoint(playerid, 3.0, -2033.43, -117.49, 1035.17)) return ErrorMsg(playerid, "Anda harus berada di tempat Sekolah Mengemudi");
    if(pData[playerid][pDriveLic] != 0) return ErrorMsg(playerid, "Anda sudah");
    if(pData[playerid][pMoney] < 500) return ErrorMsg(playerid, "Uang anda tidak mencukupi untuk membuat SIM");
    Info(playerid, "Pergi keluar gedung dan kendarai mobil berwarna putih");
    pData[playerid][pGetSIM] = 1;
    GivePlayerMoneyEx(playerid, -500);
    Server_AddMoney(500);
    return 1;
}

CMD:newlumberlic(playerid, const params[])
{
	if(pData[playerid][pLumberLic] != 0) return Error(playerid, "Anda sudah memiliki Lumber Jack License!");
	if(pData[playerid][pMoney] < 100) return Error(playerid, "Anda butuh $100 untuk membuat Lumber Jack License.");
	new sext[40], mstr[128];
	if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }
	format(mstr, sizeof(mstr), "{FFFFFF}Nama: %s\nNegara: San Fiero\nTgl Lahir: %s\nJenis Kelamin: %s\nBerlaku hingga 14 hari!", pData[playerid][pName], pData[playerid][pAge], sext);
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Lumber Jack License", mstr, "Tutup", "");
	pData[playerid][pLumberLic] = 1;
	pData[playerid][pLumberLicTime] = gettime() + (15 * 86400);
	GivePlayerMoneyEx(playerid, -5000);
	Server_AddMoney(5000);
	return 1;
}

CMD:newtrucklic(playerid, const params[])
{
	if(pData[playerid][pTruckLic] != 0) return Error(playerid, "Anda sudah memiliki Truck License!");
	if(pData[playerid][pMoney] < 5000) return Error(playerid, "Anda butuh $50.00 untuk membuat Truck License.");
	new sext[40], mstr[128];
	if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }
	format(mstr, sizeof(mstr), "{FFFFFF}Nama: %s\nNegara: San Fiero\nTgl Lahir: %s\nJenis Kelamin: %s\nBerlaku hingga 14 hari!", pData[playerid][pName], pData[playerid][pAge], sext);
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Truck License", mstr, "Tutup", "");
	pData[playerid][pTruckLic] = 1;
	pData[playerid][pTruckLicTime] = gettime() + (15 * 86400);
	GivePlayerMoneyEx(playerid, -5000);
	Server_AddMoney(5000);
	return 1;
}

/*CMD:newdrivelic(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 252.22, 117.43, 1003.21)) return Error(playerid, "Anda harus berada di SAPD!");
	if(pData[playerid][pDriveLic] != 0) return Error(playerid, "Anda sudah memiliki Driving License!");
	if(pData[playerid][pMoney] < 200) return Error(playerid, "Anda butuh $200 untuk membuat Driving License.");
	new sext[40], mstr[128];
	if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }
	format(mstr, sizeof(mstr), "{FFFFFF}Nama: %s\nNegara: San Andreas\nTgl Lahir: %s\nJenis Kelamin: %s\nBerlaku hingga 14 hari!", pData[playerid][pName], pData[playerid][pAge], sext);
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Driving License", mstr, "Tutup", "");
	pData[playerid][pDriveLic] = 1;
	pData[playerid][pDriveLicTime] = gettime() + (15 * 86400);
	GivePlayerMoneyEx(playerid, -200);
	Server_AddMoney(200);
	return 1;
}*/

CMD:buyplate(playerid, const params[])
{
	new bool:found = false, msg2[512], Float:fx, Float:fy, Float:fz;
	format(msg2, sizeof(msg2), "ID\tModel\tPlate\tPlate Time\n");
	foreach(new i : PVehicles)
	{
		if(pvData[i][cOwner] == pData[playerid][pID])
		{
			if(strcmp(pvData[i][cPlate], "None"))
			{
				GetVehiclePos(pvData[i][cVeh], fx, fy, fz);
				format(msg2, sizeof(msg2), "%s%d\t%s\t%s\t%s\n", msg2, pvData[i][cVeh], GetVehicleModelName(pvData[i][cModel]), pvData[i][cPlate], ReturnTimelapse(gettime(), pvData[i][cPlateTime]));
				found = true;
			}
			else
			{
				GetVehiclePos(pvData[i][cVeh], fx, fy, fz);
				format(msg2, sizeof(msg2), "%s%d\t%s\t%s\tNone\n", msg2, pvData[i][cVeh], GetVehicleModelName(pvData[i][cModel]), pvData[i][cPlate]);
				found = true;
			}
		}
	}
	if(found)
		ShowPlayerDialog(playerid, DIALOG_BUYPLATE, DIALOG_STYLE_TABLIST_HEADERS, "Vehicles Plate", msg2, "Buy", "Close");
	else
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Vehicles Plate", "Anda tidak memeliki kendaraan", "Close", "");
			
	return 1;
}

CMD:buyinsu(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 369.19, -86.98, 1.57)) return Error(playerid, "Anda harus berada di Asuransi!");
		
	new vehid;
	if(sscanf(params, "d", vehid)) return Usage(playerid, "/buyinsu [vehid] | /v my(mypv) - for find vehid");
	if(vehid == INVALID_VEHICLE_ID) return Error(playerid, "Invalid id");
			
	foreach(new i : PVehicles)
	{
		if(vehid == pvData[i][cVeh])
		{
			if(pvData[i][cOwner] == pData[playerid][pID] && pvData[i][cClaim] == 0)
			{
				if(pData[playerid][pMoney] < 1500) return Error(playerid, "Anda butuh $15.00 untuk membeli Insurance.");
				GivePlayerMoneyEx(playerid, -1500);
				pvData[i][cInsu]++;
				Info(playerid, "Model: %s || Total Insurance: %d || Insurance Price: $15.00", GetVehicleModelName(pvData[i][cModel]), pvData[i][cInsu]);
			}
			else return Error(playerid, "ID kendaraan ini bukan punya mu! gunakan /v my(/mypv) untuk mencari ID.");
		}
	}
	return 1;
}

CMD:claimpv(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 369.19, -86.98, 1.57))
		return ErrorMsg(playerid, "Anda harus berada di Asuransi!");

	if(GetVehiclesInsurance(playerid) == 0)
		return ErrorMsg(playerid, "Belum saat nya anda mengambil kendaraan /myinsu");

	new vehid, _tmpstring[128], count = GetVehiclesInsurance(playerid), CMDSString[1024];
	CMDSString = "";
	
	Loop(itt, (count + 1), 1)
	{
	    vehid = ReturnPVehiclesInsuID(playerid, itt);
		if(itt == count)
		{
		    format(_tmpstring, sizeof(_tmpstring), "%d\t%s\tClaimed\n", itt, GetVehicleModelName(pvData[vehid][cModel]));
		}
		else format(_tmpstring, sizeof(_tmpstring), "%d\t%s\tClaimed\n", itt, GetVehicleModelName(pvData[vehid][cModel]));
		strcat(CMDSString, _tmpstring);
	}
	ShowPlayerDialog(playerid, VEHICLE_INSURANCE, DIALOG_STYLE_LIST, "Claim Vehicles Insurance", CMDSString, "Select", "Cancel");
	return 1;
}

CMD:sellpv(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 1550.7578,-2172.9170,13.6469)) return ErrorMsg(playerid, "Anda harus berada di kantor Asuransi");
	
	new vehid;
	if(sscanf(params, "d", vehid)) return Usage(playerid, "/sellpv [vehid] | /v my(mypv) - for find vehid");
	if(vehid == INVALID_VEHICLE_ID) return ErrorMsg(playerid, "ID Kendaraan yang anda masukan salah");
			
	foreach(new i : PVehicles)
	{
		if(vehid == pvData[i][cVeh])
		{
			if(pvData[i][cOwner] == pData[playerid][pID])
			{
				if(!IsValidVehicle(pvData[i][cVeh])) return ErrorMsg(playerid, "Kendaraan anda belum di spawn");
				if(pvData[i][cRent] != 0) return ErrorMsg(playerid, "Anda tidak dapat menjual kendaraan Rental");
				new pay = pvData[i][cPrice] / 3;
				GivePlayerMoneyEx(playerid, pay);
				
				Info(playerid, "Anda menjual kendaraan model %s(%d) dengan harga "LG_E"%s", GetVehicleName(vehid), GetVehicleModel(vehid), FormatMoney(pay));
				new query[128];
				mysql_format(g_SQL, query, sizeof(query), "DELETE FROM vehicle WHERE id = '%d'", pvData[i][cID]);
				mysql_tquery(g_SQL, query);
				MySQL_ResetVehicleToys(i);
				if(IsValidVehicle(pvData[i][cVeh])) 
					DestroyVehicle(pvData[i][cVeh]);

				pvData[i][cVeh] = 0;
				
				Iter_Remove(PVehicles, i);
			}
			else return InfoTD_MSG(playerid, 4000, "ID Kendaraan yang anda masukan salah, ~y~/myv");
		}
	}
	return 1;
}

CMD:newrek(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, -982.49, 1448.46, 1340.62)) return ErrorMsg(playerid, "Anda harus berada di Pusat Bank");
	if(pData[playerid][pMoney] < 500) return ErrorMsg(playerid, "Uang anda tidak mencukupi untuk membuat rekening baru");
	new query[128], rand = RandomEx(111111, 999999);
	new rek = rand+pData[playerid][pID];
	mysql_format(g_SQL, query, sizeof(query), "SELECT brek FROM players WHERE brek='%d'", rek);
	mysql_tquery(g_SQL, query, "BankRek", "id", playerid, rek);
	SuccesMsg(playerid, "Rekening Bank anda berhasil di perbarui");
	GivePlayerMoneyEx(playerid, -500);
	Server_AddMoney(500);
	return 1;
}

CMD:bank(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, -983.95, 1448.46, 1340.62)) return Error(playerid, "Anda harus berada di bank point!");
	new tstr[128];
	format(tstr, sizeof(tstr), ""ORANGE_E"No Rek: "LB_E"%d", pData[playerid][pBankRek]);
	ShowPlayerDialog(playerid, DIALOG_BANK, DIALOG_STYLE_LIST, tstr, "Deposit Money\nWithdraw Money\nCheck Balance\nTransfer Money\nSign Paycheck", "Select", "Cancel");
	return 1;
}

CMD:items(playerid, const params[])
{
	if(pData[playerid][IsLoggedIn] == false)
	{
	    Error(playerid, "You must be logged in to check items!");
	    return true;
	}
	DisplayItems(playerid, playerid);
	return 1;
}

CMD:frisk(playerid, const params[])
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	new otherid;
	if(sscanf(params, "u", otherid))
        return Usage(playerid, "/frisk [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
        return ErrorMsg(playerid, "Player tersebut sedang tidak berada didekat anda.");

    if(otherid == playerid)
        return ErrorMsg(playerid, "Anda tidak dapat melakukan Frisk pada diri sendiri.");

    pData[otherid][pFriskOffer] = playerid;

    Info(otherid, "%s has offered to frisk you (type \"/accept frisk or /deny frisk\").", ReturnName(playerid));
    Info(playerid, "You have offered to frisk %s.", ReturnName(otherid));
	return 1;
}

CMD:inspect(playerid, const params[])
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	new otherid;
	if(sscanf(params, "u", otherid))
        return Usage(playerid, "/inspect [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
        return ErrorMsg(playerid, "Player tersebut sedang tidak berada didekat mu.");

    if(otherid == playerid)
        return ErrorMsg(playerid, "Anda tidak dapat melakukan Inspect pada diri sendiri.");

    pData[otherid][pInsOffer] = playerid;

    Info(otherid, "%s has offered to inspect you (type \"/accept inspect or /deny inspect\").", ReturnName(playerid));
    Info(playerid, "You have offered to inspect %s.", ReturnName(otherid));
	return 1;
}

CMD:reqloc(playerid, const params[])
{
	new otherid;
	if(sscanf(params, "u", otherid))
        return Usage(playerid, "/reqloc [playerid/PartOfName]");

	if(Inventory_Count(playerid, "Phone") < 1)
		return ErrorMsg(playerid, "Anda tidak memiliki ponsel");

    if(pData[playerid][pUsePhone] == 0)
    	return ErrorMsg(playerid, "Ponsel anda sedang dalam keadaaan offline");

	if(Inventory_Count(otherid, "Phone") < 1)
		return ErrorMsg(playerid, "Player tersebut tidak memiliki Ponsel");

    if(pData[otherid][pUsePhone] == 0)
    	return ErrorMsg(playerid, "Ponsel yang anda tuju sedang Offline");

    if(otherid == playerid)
        return ErrorMsg(playerid, "Anda tidak dapat mengirim lokasi pada diri sendiri");

	if(GetSignalNearest(playerid) == 0)
		return ErrorMsg(playerid, "Ponsel anda tidak mendapatkan sinyal di wilayah ini.");

	if(GetSignalNearest(otherid) == 0)
		return ErrorMsg(playerid, "Ponsel tersebut sedang mengalami gangguan sinyal.");

    pData[otherid][pLocOffer] = playerid;

    Info(otherid, "%s has offered to request share his location (type \"/accept reqloc or /deny reqloc\").", ReturnName(playerid));
    Info(playerid, "You have offered to share your location %s.", ReturnName(otherid));
	return 1;
}

CMD:accept(playerid, const params[])
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	if(IsPlayerConnected(playerid)) 
	{
        if(isnull(params)) 
		{
            Usage(playerid, "/accept [name]");
            Names(playerid, "faction, family, workshop, drag, frisk, inspect, job, reqloc, rob, handshake, dicebet, weapon");
            return 1;
        }
		if(strcmp(params,"faction",true) == 0) 
		{
            if(IsPlayerConnected(pData[playerid][pFacOffer])) 
			{
                if(pData[playerid][pFacInvite] > 0) 
				{
                    pData[playerid][pFaction] = pData[playerid][pFacInvite];
					pData[playerid][pFactionRank] = 1;
					new str[200];
					format(str, sizeof(str), "Anda telah menerima invite Faction dari %s", pData[pData[playerid][pFacOffer]][pName]);
					SuccesMsg(playerid, str);
					format(str, sizeof(str), "%s telah menerima invite Faciton anda", pData[playerid][pName]);
					SuccesMsg(pData[playerid][pFacOffer], str);
					pData[playerid][pFacInvite] = 0;
					pData[playerid][pFacOffer] = -1;
				}
				else
				{
					ErrorMsg(playerid, "Invalid faction id!");
					return 1;
				}
            }
            else 
			{
                ErrorMsg(playerid, "Tidak ada player yang menawari anda!");
                return 1;
            }
        }
		if(strcmp(params,"family",true) == 0) 
		{
            if(IsPlayerConnected(pData[playerid][pFamOffer])) 
			{
                if(pData[playerid][pFamInvite] > -1) 
				{
                    pData[playerid][pFamily] = pData[playerid][pFamInvite];
					pData[playerid][pFamilyRank] = 1;
					Info(playerid, "Anda telah menerima invite family dari %s", pData[pData[playerid][pFamOffer]][pName]);
					Info(pData[playerid][pFamOffer], "%s telah menerima invite family yang anda tawari", pData[playerid][pName]);
					pData[playerid][pFamInvite] = 0;
					pData[playerid][pFamOffer] = -1;
				}
				else
				{
					Error(playerid, "Invalid family id!");
					return 1;
				}
            }
            else 
			{
                Error(playerid, "Tidak ada player yang menawari anda!");
                return 1;
            }
        }
        if(strcmp(params,"workshop",true) == 0)
		{
            if(IsPlayerConnected(pData[playerid][pWsOffer]))
			{
                if(pData[playerid][pWsInvite] > -1)
				{
                    pData[playerid][pWorkshop] = pData[playerid][pWsInvite];
					pData[playerid][pWorkshopRank] = 1;
					Info(playerid, "Anda telah menerima invite workshop dari %s", pData[pData[playerid][pWsOffer]][pName]);
					Info(pData[playerid][pWsOffer], "%s telah menerima invite workshop yang anda tawari", pData[playerid][pName]);
					pData[playerid][pWsInvite] = 0;
					pData[playerid][pWsOffer] = -1;
					UpdatePlayerData(playerid);
				}
				else
				{
					Error(playerid, "Invalid workshop id!");
					return 1;
				}
            }
            else
			{
                Error(playerid, "Tidak ada player yang menawari anda!");
                return 1;
            }
        }
		else if(strcmp(params,"drag",true) == 0)
		{
			new dragby = GetPVarInt(playerid, "DragBy");
			if(dragby == INVALID_PLAYER_ID || dragby == playerid)
				return Error(playerid, "Player itu Disconnect.");
        
			if(!NearPlayer(playerid, dragby, 5.0))
				return Error(playerid, "Kamu harus didekat Player.");
        
			pData[playerid][pDragged] = 1;
			pData[playerid][pDraggedBy] = dragby;

			pData[playerid][pDragTimer] = SetTimerEx("DragUpdate", 1000, true, "ii", dragby, playerid);
			SendNearbyMessage(dragby, 30.0, COLOR_PURPLE, "* %s grabs %s and starts dragging them, (/undrag).", ReturnName(dragby), ReturnName(playerid));
			return true;
		}
		else if(strcmp(params,"frisk",true) == 0)
		{
			if(pData[playerid][pFriskOffer] == INVALID_PLAYER_ID || !IsPlayerConnected(pData[playerid][pFriskOffer]))
				return Error(playerid, "Player tersebut belum masuk!");
			
			if(!NearPlayer(playerid, pData[playerid][pFriskOffer], 5.0))
				return Error(playerid, "Kamu harus didekat Player.");
			
			ShowInventoryFrisk(pData[playerid][pFriskOffer], playerid);	
			//DisplayItems(pData[playerid][pFriskOffer], playerid);
			Servers(playerid, "Anda telah berhasil menaccept tawaran frisk kepada %s.", ReturnName(pData[playerid][pFriskOffer]));
			pData[playerid][pFriskOffer] = INVALID_PLAYER_ID;
		}
		else if(strcmp(params,"inspect",true) == 0)
		{
			if(pData[playerid][pInsOffer] == INVALID_PLAYER_ID || !IsPlayerConnected(pData[playerid][pFriskOffer]))
				return Error(playerid, "Player tersebut belum masuk!");
			
			if(!NearPlayer(playerid, pData[playerid][pInsOffer], 5.0))
				return Error(playerid, "Kamu harus didekat Player.");
				
			new hstring[512], info[512];
			new hh = pData[playerid][pHead];
			new hp = pData[playerid][pPerut];
			new htk = pData[playerid][pRHand];
			new htka = pData[playerid][pLHand];
			new hkk = pData[playerid][pRFoot];
			new hkka = pData[playerid][pLFoot];
			format(hstring, sizeof(hstring),"Bagian Tubuh\tKondisi\n{ffffff}Kepala\t{7fffd4}%d.0%\n{ffffff}Perut\t{7fffd4}%d.0%\n{ffffff}Tangan Kanan\t{7fffd4}%d.0%\n{ffffff}Tangan Kiri\t{7fffd4}%d.0%\n",hh,hp,htk,htka);
			strcat(info, hstring);
			format(hstring, sizeof(hstring),"{ffffff}Kaki Kanan\t{7fffd4}%d.0%\n{ffffff}Kaki Kiri\t{7fffd4}%d.0%\n",hkk,hkka);
			strcat(info, hstring);
			ShowPlayerDialog(pData[playerid][pInsOffer],DIALOG_HEALTH,DIALOG_STYLE_TABLIST_HEADERS,"Health Condition",info,"Oke","");
			Servers(playerid, "Anda telah berhasil menaccept tawaran Inspect kepada %s.", ReturnName(pData[playerid][pInsOffer]));
			pData[playerid][pInsOffer] = INVALID_PLAYER_ID;
		}
		else if(strcmp(params,"job",true) == 0) 
		{
			if(pData[playerid][pGetJob] > 0)
			{
				pData[playerid][pJob] = pData[playerid][pGetJob];
				Info(playerid, "Anda telah berhasil mendapatkan pekerjaan baru. gunakan /help untuk informasi.");
				pData[playerid][pGetJob] = 0;
				pData[playerid][pExitJob] = gettime() + (1 * 86400);
			}
			else if(pData[playerid][pGetJob2] > 0)
			{
				pData[playerid][pJob2] = pData[playerid][pGetJob2];
				Info(playerid, "Anda telah berhasil mendapatkan pekerjaan baru. gunakan /help untuk informasi.");
				pData[playerid][pGetJob2] = 0;
				pData[playerid][pExitJob] = gettime() + (1 * 86400);
			}
		}
		else if(strcmp(params,"reqloc",true) == 0)
		{
			if(pData[playerid][pLocOffer] == INVALID_PLAYER_ID || !IsPlayerConnected(pData[playerid][pLocOffer]))
				return Error(playerid, "Player tersebut belum masuk!");
				
			new Float:sX, Float:sY, Float:sZ;
			GetPlayerPos(playerid, sX, sY, sZ);
			SetPlayerCheckpoint(pData[playerid][pLocOffer], sX, sY, sZ, 5.0);
			Servers(playerid, "Anda telah berhasil menaccept tawaran Share Lokasi kepada %s.", ReturnName(pData[playerid][pLocOffer]));
			Servers(pData[playerid][pLocOffer], "Lokasi %s telah tertandai.", ReturnName(playerid));
			pData[playerid][pLocOffer] = INVALID_PLAYER_ID;
		}
		else if(strcmp(params,"rob",true) == 0)
		{
			new offerid = pData[playerid][pRobOffer];
			if(offerid == -1)
				return Error(playerid, "Belum ada yang mengivnite mu untuk melakukan robbing");

			if(!IsPlayerConnected(offerid))
				return Error(playerid, "Player tersebut belum masuk!");

			if(!NearPlayer(playerid, offerid, 5.0))
				return Error(playerid, "Kamu harus didekat Player yang menginvite mu.");

			Servers(playerid, "Anda telah berhasil menaccept tawaran bergabung kedalam Robbery %s.", ReturnName(pData[playerid][pRobOffer]));
			Servers(offerid, "%s Menerima ajakan Robbing anda.", ReturnName(playerid));

			pData[playerid][pMemberRob] = offerid;
			pData[playerid][pRobOffer] = -1;
			
			pData[offerid][pRobLeader] = 1;
			pData[offerid][pRobMember] += 1;
		}
		else if(!strcmp(params, "handshake", true))
		{
		    new offeredby = pData[playerid][pShakeOffer];

		    if(offeredby == INVALID_PLAYER_ID)
		        return Error(playerid, "You haven't received any offers for a handshake.");

		    if(!NearPlayer(playerid, offeredby, 5.0))
		        return Error(playerid, "The player who initiated the offer is out of range.");

		    clearAnimations(playerid);
			clearAnimations(offeredby);

			SetPlayerToFacePlayer(playerid, offeredby);
			SetPlayerToFacePlayer(offeredby, playerid);

			switch(pData[playerid][pShakeType])
			{
			    case 1:
			    {
					ApplyAnimation(playerid,  "GANGS", "hndshkaa", 4.0, 0, 0, 0, 0, 0, 1);
					ApplyAnimation(offeredby, "GANGS", "hndshkaa", 4.0, 0, 0, 0, 0, 0, 1);
				}
				case 2:
				{
					ApplyAnimation(playerid, "GANGS", "hndshkba", 4.0, 0, 0, 0, 0, 0, 1);
					ApplyAnimation(offeredby, "GANGS", "hndshkba", 4.0, 0, 0, 0, 0, 0, 1);
				}
				case 3:
				{
					ApplyAnimation(playerid, "GANGS", "hndshkda", 4.0, 0, 0, 0, 0, 0, 1);
					ApplyAnimation(offeredby, "GANGS", "hndshkda", 4.0, 0, 0, 0, 0, 0, 1);
				}
				case 4:
				{
					ApplyAnimation(playerid, "GANGS", "hndshkea", 4.0, 0, 0, 0, 0, 0, 1);
					ApplyAnimation(offeredby, "GANGS", "hndshkea", 4.0, 0, 0, 0, 0, 0, 1);
				}
				case 5:
				{
					ApplyAnimation(playerid, "GANGS", "hndshkfa", 4.0, 0, 0, 0, 0, 0, 1);
					ApplyAnimation(offeredby, "GANGS", "hndshkfa", 4.0, 0, 0, 0, 0, 0, 1);
				}
				case 6:
				{
				    ApplyAnimation(playerid, "GANGS", "prtial_hndshk_biz_01", 4.0, 0, 0, 0, 0, 0);
				    ApplyAnimation(offeredby, "GANGS", "prtial_hndshk_biz_01", 4.0, 0, 0, 0, 0, 0);
				}
		    }

		    Info(playerid, "* You have accepted %s's handshake offer.", ReturnName(offeredby));
		    Info(offeredby, "* %s has accepted your handshake offer.", ReturnName(playerid));

	  		pData[playerid][pShakeOffer] = INVALID_PLAYER_ID;
		}
		else if(!strcmp(params, "dicebet", true))
		{
		    new offeredby = pData[playerid][pDiceOffer], amount = pData[playerid][pDiceBet];

		    if(offeredby == INVALID_PLAYER_ID)
		        return Error(playerid, "You haven't received any offers for dice betting.");

		    if(!NearPlayer(playerid, offeredby, 5.0))
		        return Error(playerid, "The player who initiated the offer is out of range.");

		    if(pData[playerid][pMoney] < amount)
		        return Error(playerid, "You can't afford to accept this bet.");

		    if(pData[playerid][pMoney] < amount)
		        return Error(playerid, "That player can't afford to accept this bet.");

			new rand[2];

			if(pData[playerid][pDiceRigged])
			{
			    rand[0] = 4 + random(3);
			    rand[1] = random(3) + 1;
			}
			else
			{
				for(new x = 0; x < random(50)*random(50)+30; x++)
				{
					rand[0] = random(6) + 1;
				}
				for(new x = 0; x < random(50)*random(50)+30; x++)
				{
					rand[1] = random(6) + 1;
				}
			}

			SendNearbyMessage(offeredby, 20.0, COLOR_PURPLE, "* %s rolls a dice which lands on the number %d.", ReturnName(offeredby), rand[0]);
			SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s rolls a dice which lands on the number %d.", ReturnName(playerid), rand[1]);

			if(rand[0] > rand[1])
			{
			    GivePlayerMoneyEx(offeredby, amount);
			    GivePlayerMoneyEx(playerid, -amount);

			    Info(offeredby, "* You have won %s from your dice bet with %s.", FormatMoney(amount), ReturnName(playerid));
			    Info(playerid, "* You have lost %s from your dice bet with %s.", FormatMoney(amount), ReturnName(offeredby));
			}
			else if(rand[0] == rand[1])
			{
				Info(offeredby, "* The bet of %s was a tie. You kept your money as a result!", FormatMoney(amount));
			    Info(playerid, "* The bet of %s was a tie. You kept your money as a result!", FormatMoney(amount));
			}
			else
			{
			    GivePlayerMoneyEx(offeredby, -amount);
			    GivePlayerMoneyEx(playerid, amount);

			    Info(playerid, "* You have won %s from your dice bet with %s.", FormatMoney(amount), ReturnName(offeredby));
			    Info(offeredby, "* You have lost %s from your dice bet with %s.", FormatMoney(amount), ReturnName(playerid));
			}

		    pData[playerid][pDiceOffer] = INVALID_PLAYER_ID;
		}
		else if(strcmp(params,"weapon",true) == 0) 
		{
			if(pData[playerid][pWeaponOffer] == INVALID_PLAYER_ID || !IsPlayerConnected(pData[playerid][pWeaponOffer]))
				return Error(playerid, "Player tersebut belum masuk!");

			if(pData[playerid][pMoney] < pData[playerid][pWeaponPriceOffer])
				return Error(playerid, "Uang kamu tidak mencukupi untuk membeli senjata tersebut!");

			if(Inventory_Count(pData[playerid][pWeaponOffer], "Material") < pData[playerid][pWeaponMatsOffer])
				return Error(playerid, "Jumlah material penjual tidak mencukupi");

			GivePlayerMoneyEx(pData[playerid][pWeaponOffer], pData[playerid][pWeaponPriceOffer]);
			GivePlayerMoneyEx(playerid, -pData[playerid][pWeaponPriceOffer]);

			GivePlayerWeaponEx(playerid, pData[playerid][pWeaponidOffer], pData[playerid][pWeaponAmmoOffer]);
			
			Info(pData[playerid][pWeaponOffer], "%s telah menerima senjata %s yang anda tawarkan", ReturnName(playerid), ReturnWeaponName(pData[playerid][pWeaponidOffer]));
			Info(playerid, "Kamu telah menerima senjata %s dengan harga "RED_E"%s"WHITE_E"", ReturnWeaponName(pData[playerid][pWeaponidOffer]), FormatMoney(pData[playerid][pWeaponPriceOffer]));

			if(pData[pData[playerid][pWeaponOffer]][pWeaponSkill] <= 40)
			{
				pData[pData[playerid][pWeaponOffer]][pWeaponSkill] += 1;
			}
			Inventory_Remove(pData[playerid][pWeaponOffer], "Material", pData[playerid][pWeaponMatsOffer]);
			pData[playerid][pWeaponidOffer] = 0;
			pData[playerid][pWeaponAmmoOffer] = 0;
			pData[playerid][pWeaponMatsOffer] = 0;
			pData[playerid][pWeaponPriceOffer] = 0;
			pData[playerid][pWeaponOffer] = INVALID_PLAYER_ID;
		}
	}
	return 1;
}

CMD:deny(playerid, const params[])
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	if(IsPlayerConnected(playerid)) 
	{
        if(isnull(params)) 
		{
            Usage(playerid, "/deny [name]");
            Names(playerid, "faction, drag, frisk, inspect, job1, job2, reqloc, rob");
            return 1;
        }
		if(strcmp(params,"faction",true) == 0) 
		{
            if(pData[playerid][pFacOffer] > -1) 
			{
                if(pData[playerid][pFacInvite] > 0) 
				{
					Info(playerid, "Anda telah menolak faction dari %s", ReturnName(pData[playerid][pFacOffer]));
					Info(pData[playerid][pFacOffer], "%s telah menolak invite faction yang anda tawari", ReturnName(playerid));
					pData[playerid][pFacInvite] = 0;
					pData[playerid][pFacOffer] = -1;
				}
				else
				{
					Error(playerid, "Invalid faction id!");
					return 1;
				}
            }
            else 
			{
                Error(playerid, "Tidak ada player yang menawari anda!");
                return 1;
            }
        }
		else if(strcmp(params,"drag",true) == 0)
		{
			new dragby = GetPVarInt(playerid, "DragBy");
			if(dragby == INVALID_PLAYER_ID || dragby == playerid)
				return Error(playerid, "Player itu Disconnect.");

			Info(playerid, "Anda telah menolak drag.");
			Info(dragby, "Player telah menolak drag yang anda tawari.");
			
			DeletePVar(playerid, "DragBy");
			pData[playerid][pDragged] = 0;
			pData[playerid][pDraggedBy] = INVALID_PLAYER_ID;
			return 1;
		}
		else if(strcmp(params,"frisk",true) == 0)
		{
			if(pData[playerid][pFriskOffer] == INVALID_PLAYER_ID || !IsPlayerConnected(pData[playerid][pFriskOffer]))
				return Error(playerid, "Player tersebut belum masuk!");
			
			Info(playerid, "Anda telah menolak tawaran frisk kepada %s.", ReturnName(pData[playerid][pFriskOffer]));
			pData[playerid][pFriskOffer] = INVALID_PLAYER_ID;
			return 1;
		}
		else if(strcmp(params,"inspect",true) == 0)
		{
			if(pData[playerid][pInsOffer] == INVALID_PLAYER_ID || !IsPlayerConnected(pData[playerid][pInsOffer]))
				return Error(playerid, "Player tersebut belum masuk!");
			
			Info(playerid, "Anda telah menolak tawaran Inspect kepada %s.", ReturnName(pData[playerid][pInsOffer]));
			pData[playerid][pInsOffer] = INVALID_PLAYER_ID;
			return 1;
		}
		else if(strcmp(params,"job1",true) == 0) 
		{
			if(pData[playerid][pJob] == 0) return Error(playerid, "Anda tidak memiliki job apapun.");
			if(pData[playerid][pExitJob] != 0) return Error(playerid, "You must wait 1 days for exit from your current job!");
			if(pData[playerid][pJob] != 0)
			{
				pData[playerid][pJob] = 0;
				Info(playerid, "Anda berhasil keluar dari pekerjaan anda.");
				return 1;
			}
		}
		else if(strcmp(params,"job2",true) == 0) 
		{
			if(pData[playerid][pJob2] == 0) return Error(playerid, "Anda tidak memiliki job apapun.");
			if(pData[playerid][pJob2] != 0)
			{
				pData[playerid][pJob2] = 0;
				Info(playerid, "Anda berhasil keluar dari pekerjaan anda.");
				return 1;
			}
		}
		else if(strcmp(params,"reqloc",true) == 0) 
		{
			if(pData[playerid][pLocOffer] == INVALID_PLAYER_ID || !IsPlayerConnected(pData[playerid][pLocOffer]))
				return Error(playerid, "Player tersebut belum masuk!");
			
			Info(playerid, "Anda telah menolak tawaran Share Lokasi kepada %s.", ReturnName(pData[playerid][pLocOffer]));
			pData[playerid][pLocOffer] = INVALID_PLAYER_ID;
		}
		else if(strcmp(params,"rob",true) == 0) 
		{
			if(pData[playerid][pRobOffer] == INVALID_PLAYER_ID || !IsPlayerConnected(pData[playerid][pRobOffer]))
				return Error(playerid, "Player tersebut belum masuk!");
			
			Info(playerid, "Anda telah menolak tawaran Rob kepada %s.", ReturnName(pData[playerid][pRobOffer]));
			pData[playerid][pRobOffer] = INVALID_PLAYER_ID;
		}
	}
	return 1;
}

CMD:enter(playerid, const params[])
{
	if(pData[playerid][pInjured] == 0)
    {
		foreach(new did : Doors)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.8, dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ]))
			{
				if(dData[did][dGarage] == 1 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
				{
					if(dData[did][dIntposX] == 0.0 && dData[did][dIntposY] == 0.0 && dData[did][dIntposZ] == 0.0)
						return Error(playerid, "Interior entrance masih kosong, atau tidak memiliki interior.");

					if(dData[did][dLocked])
						return Error(playerid, "Bangunan ini di Kunci untuk sementara.");
						
					if(dData[did][dFaction] > 0)
					{
						if(dData[did][dFaction] != pData[playerid][pFaction])
							return Error(playerid, "Pintu ini hanya untuk fraksi.");
					}
					if(dData[did][dFamily] > 0)
					{
						if(dData[did][dFamily] != pData[playerid][pFamily])
							return Error(playerid, "Pintu ini hanya untuk Family.");
					}
					
					if(dData[did][dVip] > pData[playerid][pVip])
						return Error(playerid, "VIP Level mu tidak cukup.");
					
					if(dData[did][dAdmin] > pData[playerid][pAdmin])
						return Error(playerid, "Admin level mu tidak cukup.");
						
					if(strlen(dData[did][dPass]))
					{
						if(sscanf(params, "s[256]", params)) return Usage(playerid, "/enter [password]");
						if(strcmp(params, dData[did][dPass])) return Error(playerid, "Password Salah.");
						
						if(dData[did][dCustom])
						{
							SetVehiclePositionEx(playerid, GetPlayerVehicleID(playerid), dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
						}
						else
						{
							SetVehiclePosition(playerid, GetPlayerVehicleID(playerid), dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
						}
						pData[playerid][pInDoor] = did;
						SetPlayerInterior(playerid, dData[did][dIntint]);
						SetPlayerVirtualWorld(playerid, dData[did][dIntvw]);
						SetCameraBehindPlayer(playerid);
						SetPlayerWeather(playerid, 0);
					}
					else
					{
						if(dData[did][dCustom])
						{
							SetVehiclePositionEx(playerid, GetPlayerVehicleID(playerid), dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
						}
						else
						{
							SetVehiclePosition(playerid, GetPlayerVehicleID(playerid), dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
						}
						pData[playerid][pInDoor] = did;
						SetPlayerInterior(playerid, dData[did][dIntint]);
						SetPlayerVirtualWorld(playerid, dData[did][dIntvw]);
						SetCameraBehindPlayer(playerid);
						SetPlayerWeather(playerid, 0);
					}
				}
				else
				{
					if(dData[did][dIntposX] == 0.0 && dData[did][dIntposY] == 0.0 && dData[did][dIntposZ] == 0.0)
						return Error(playerid, "Interior entrance masih kosong, atau tidak memiliki interior.");

					if(dData[did][dLocked])
						return Error(playerid, "Pintu ini ditutup sementara");
						
					if(dData[did][dFaction] > 0)
					{
						if(dData[did][dFaction] != pData[playerid][pFaction])
							return Error(playerid, "Pintu ini hanya untuk faction.");
					}
					if(dData[did][dFamily] > 0)
					{
						if(dData[did][dFamily] != pData[playerid][pFamily])
							return Error(playerid, "Pintu ini hanya untuk family.");
					}
					
					if(dData[did][dVip] > pData[playerid][pVip])
						return Error(playerid, "Your VIP level not enough to enter this door.");
					
					if(dData[did][dAdmin] > pData[playerid][pAdmin])
						return Error(playerid, "Your admin level not enough to enter this door.");

					if(strlen(dData[did][dPass]))
					{
						if(sscanf(params, "s[256]", params)) return Usage(playerid, "/enter [password]");
						if(strcmp(params, dData[did][dPass])) return Error(playerid, "Invalid door password.");
						
						if(dData[did][dCustom])
						{
							SetPlayerPositionEx(playerid, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
						}
						else
						{
							SetPlayerPosition(playerid, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
						}
						pData[playerid][pInDoor] = did;
						SetPlayerInterior(playerid, dData[did][dIntint]);
						SetPlayerVirtualWorld(playerid, dData[did][dIntvw]);
						SetCameraBehindPlayer(playerid);
						SetPlayerWeather(playerid, 0);
						TogglePlayerControllable(playerid, 0);
						SetTimerEx("TimerUntogglePlayer", 3000, 0, "d", playerid);
					}
					else
					{
						if(dData[did][dCustom])
						{
							SetPlayerPositionEx(playerid, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
						}
						else
						{
							SetPlayerPosition(playerid, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ], dData[did][dIntposA]);
						}
						pData[playerid][pInDoor] = did;
						SetPlayerInterior(playerid, dData[did][dIntint]);
						SetPlayerVirtualWorld(playerid, dData[did][dIntvw]);
						SetCameraBehindPlayer(playerid);
						SetPlayerWeather(playerid, 0);
						TogglePlayerControllable(playerid, 0);
						SetTimerEx("TimerUntogglePlayer", 3000, 0, "d", playerid);
					}
				}
			}
			if(IsPlayerInRangeOfPoint(playerid, 2.8, dData[did][dIntposX], dData[did][dIntposY], dData[did][dIntposZ]))
			{
				if(dData[did][dGarage] == 1 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
				{
					if(dData[did][dFaction] > 0)
					{
						if(dData[did][dFaction] != pData[playerid][pFaction])
							return Error(playerid, "Pintu ini hanya untuk faction.");
					}
				
					if(dData[did][dCustom])
					{
						SetVehiclePositionEx(playerid, GetPlayerVehicleID(playerid), dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ], dData[did][dExtposA]);
					}
					else
					{
						SetVehiclePosition(playerid, GetPlayerVehicleID(playerid), dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ], dData[did][dExtposA]);
					}
					pData[playerid][pInDoor] = -1;
					SetPlayerInterior(playerid, dData[did][dExtint]);
					SetPlayerVirtualWorld(playerid, dData[did][dExtvw]);
					SetCameraBehindPlayer(playerid);
					SetPlayerWeather(playerid, WorldWeather);
				}
				else
				{
					if(dData[did][dFaction] > 0)
					{
						if(dData[did][dFaction] != pData[playerid][pFaction])
							return Error(playerid, "Pintu ini hanya untuk faction.");
					}
					
					if(dData[did][dCustom])
						SetPlayerPositionEx(playerid, dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ], dData[did][dExtposA]);

					else
						SetPlayerPositionEx(playerid, dData[did][dExtposX], dData[did][dExtposY], dData[did][dExtposZ], dData[did][dExtposA]);
					
					pData[playerid][pInDoor] = -1;
					SetPlayerInterior(playerid, dData[did][dExtint]);
					SetPlayerVirtualWorld(playerid, dData[did][dExtvw]);
					SetCameraBehindPlayer(playerid);
					SetPlayerWeather(playerid, WorldWeather);
				}
			}
        }
		//Houses
		foreach(new hid : Houses)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]))
			{
				if(hData[hid][hIntposX] == 0.0 && hData[hid][hIntposY] == 0.0 && hData[hid][hIntposZ] == 0.0)
					return Error(playerid, "Interior house masih kosong, atau tidak memiliki interior.");

				if(hData[hid][hLocked] >= 2)
					return Error(playerid, "Rumah ini sedang disegel oleh pemerintah");
				
				if(hData[hid][hLocked])
					return Error(playerid, "Rumah ini terkunci!");
				
				pData[playerid][pInHouse] = hid;
				SetPlayerPositionEx(playerid, hData[hid][hIntposX], hData[hid][hIntposY], hData[hid][hIntposZ], hData[hid][hIntposA]);

				SetPlayerInterior(playerid, hData[hid][hInt]);
				SetPlayerVirtualWorld(playerid, hid);
				SetCameraBehindPlayer(playerid);
				SetPlayerWeather(playerid, 0);
			}
        }
		new inhouseid = pData[playerid][pInHouse];
		if(pData[playerid][pInHouse] != -1 && IsPlayerInRangeOfPoint(playerid, 2.8, hData[inhouseid][hIntposX], hData[inhouseid][hIntposY], hData[inhouseid][hIntposZ]))
		{
			SetPlayerPositionEx(playerid, hData[inhouseid][hExtposX], hData[inhouseid][hExtposY], hData[inhouseid][hExtposZ], hData[inhouseid][hExtposA]);

			pData[playerid][pInHouse] = -1;
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			SetCameraBehindPlayer(playerid);
			SetPlayerWeather(playerid, WorldWeather);
		}
		//Family
		foreach(new fid : FAMILYS)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.8, fData[fid][fExtposX], fData[fid][fExtposY], fData[fid][fExtposZ]))
			{
				if(fData[fid][fIntposX] == 0.0 && fData[fid][fIntposY] == 0.0 && fData[fid][fIntposZ] == 0.0)
					return Error(playerid, "Interior masih kosong, atau tidak memiliki interior.");

				if(pData[playerid][pFaction] == 0)
					if(pData[playerid][pFamily] == -1)
						return Error(playerid, "You dont have registered for this door!");
					
				SetPlayerPositionEx(playerid, fData[fid][fIntposX], fData[fid][fIntposY], fData[fid][fIntposZ], fData[fid][fIntposA]);

				SetPlayerInterior(playerid, fData[fid][fInt]);
				SetPlayerVirtualWorld(playerid, fid);
				SetCameraBehindPlayer(playerid);
				//pData[playerid][pInBiz] = fid;
				SetPlayerWeather(playerid, 0);
			}
			if(IsPlayerInRangeOfPoint(playerid, 2.8, fData[fid][fIntposX], fData[fid][fIntposY], fData[fid][fIntposZ]))
			{
				SetPlayerPositionEx(playerid, fData[fid][fExtposX], fData[fid][fExtposY], fData[fid][fExtposZ], fData[fid][fExtposA]);

				SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
				SetCameraBehindPlayer(playerid);
				SetPlayerWeather(playerid, WorldWeather);
				//
			}
        }
	}
	return 1;
}

CMD:drag(playerid, const params[])
{
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/drag [playerid/PartOfName] || /undrag [playerid]");

    if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "Player itu Disconnect.");

    if(otherid == playerid)
        return Error(playerid, "Kamu tidak bisa menarik diri mu sendiri.");

    if(!NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "Kamu harus didekat Player.");

    if(!pData[otherid][pInjured])
        return Error(playerid, "kamu tidak bisa drag orang yang tidak mati.");

    SetPVarInt(otherid, "DragBy", playerid);
    Info(otherid, "%s Telah menawari drag kepada anda, /accept drag untuk menerimanya /deny drag untuk membatalkannya.", ReturnName(playerid));
	Info(playerid, "Anda berhasil menawari drag kepada player %s", ReturnName(otherid));
    return 1;
}

CMD:undrag(playerid, const params[])
{
	new otherid;
    if(sscanf(params, "u", otherid)) return Usage(playerid, "/undrag [playerid]");
	if(pData[otherid][pDragged])
    {
        DeletePVar(playerid, "DragBy");
        DeletePVar(otherid, "DragBy");
        pData[otherid][pDragged] = 0;
        pData[otherid][pDraggedBy] = INVALID_PLAYER_ID;

        KillTimer(pData[otherid][pDragTimer]);
        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s releases %s from their grip.", ReturnName(playerid), ReturnName(otherid));
    }
    return 1;
}

CMD:mask(playerid, const params[])
{
	if(pData[playerid][pMask] <= 0)
		return Error(playerid, "Anda tidak memiliki topeng!");
		
	switch (pData[playerid][pMaskOn])
    {
        case 0:
        {
        	new sstring[64];
        	new Float:pX, Float:pY, Float:pZ;
        	GetPlayerPos(playerid, pX, pY, pZ);
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s takes out a mask and puts it on.", ReturnName(playerid));
            pData[playerid][pMaskOn] = 1;
            format(sstring, sizeof(sstring), "%s", ReturnName(playerid));
		    pData[playerid][pMaskLabel] = Create3DTextLabel(sstring, -1, 0, 0, -0.25, 25, playerid, 10);
      		SetPlayerAttachedObject(playerid, 9, 19801, 2, 0.064999, 0.028999, 0.000000, 0.000000, 80.300003, 178.900009, 1.330000, 1.25, 1.125000);
		    Attach3DTextLabelToPlayer(pData[playerid][pMaskLabel], playerid, 0, 0, 0.39);
        }
        case 1:
        {
        	Delete3DTextLabel(pData[playerid][pMaskLabel]);
            pData[playerid][pMaskOn] = 0;
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s takes their mask off and puts it away.", ReturnName(playerid));
            RemovePlayerAttachedObject(playerid, 9);
        }
    }
	return 1;
}

/*CMD:snt(playerid, const params[])
{
	if(LabelPlayer[playerid] == 0)
	{
		foreach(new i : Player)
		{
			if(IsPlayerConnected(i))
			{
				LabelPlayers[playerid] = CreateDynamic3DTextLabel((sprintf("[%d] %s", i, pData[i][pUcp])), COLOR_WHITE, 0.0, 0.0, 0.2, 15.0, i,  INVALID_VEHICLE_ID,  0, GetPlayerVirtualWorld(i), GetPlayerInterior(i), playerid, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
				LabelPlayer[playerid] = 1;
			}
		}
	}
	else if(LabelPlayer[playerid] == 1)
	{
		LabelPlayer[playerid] = 0;
		if(IsValidDynamic3DTextLabel(LabelPlayers[playerid]))
			DestroyDynamic3DTextLabel(LabelPlayers[playerid]);
	}
	return 1;	
}*/

CMD:stuck(playerid, const params[])
{
	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT || pData[playerid][pInjured] == 1 || pData[playerid][pCuffed] == 1) 
		return Error(playerid, "You can't do at this moment.");

    if(gettime() - pData[playerid][pLastStuck] < 5)
	    return SendClientMessageEx(playerid, COLOR_GREY, "You can only use this command every 5 seconds.");

	new
	    Float:x,
    	Float:y,
    	Float:z;

	GetPlayerPos(playerid, x, y, z);
	SetPlayerPos(playerid, x, y, z + 0.5);

	clearAnimations(playerid);
   	StopLoopingAnim(playerid);
	TogglePlayerControllable(playerid, 1);

	ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.1, 0, 0, 0, 0, 0, 1);
	SendClientMessage(playerid, COLOR_GREY, "You are no longer stuck.");

	pData[playerid][pLastStuck] = gettime();
	return 1;
}

//Text and Chat Commands
CMD:try(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

    if(isnull(params))
        return Usage(playerid, "/try [action]");

	if(GetPVarType(playerid, "Caps")) UpperToLower(params);
    if(strlen(params) > 64) 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s %.64s ..", ReturnName(playerid), params);
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, ".. %s, %s", params[64], (random(2) == 0) ? ("and success") : ("but fail"));
    }
    else {
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s %s, %s", ReturnName(playerid), params, (random(2) == 0) ? ("and success") : ("but fail"));
    }
	printf("[TRY] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

CMD:ado(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

    new flyingtext[164], Float:x, Float:y, Float:z;

    if(isnull(params))
	{
        Usage(playerid, "/ado [text]");
		Info(playerid, "Use /ado off to disable or delete the ado tag.");
		return 1;
	}
    if(strlen(params) > 128)
        return Error(playerid, "Max text can only maximmum 128 characters.");

    if (!strcmp(params, "off", true))
    {
        if (!pData[playerid][pAdoActive])
            return Error(playerid, "You're not actived your 'ado' text.");

        if (IsValidDynamic3DTextLabel(pData[playerid][pAdoTag]))
            DestroyDynamic3DTextLabel(pData[playerid][pAdoTag]);

        Servers(playerid, "You're removed your ado text.");
        pData[playerid][pAdoActive] = false;
        return 1;
    }

    FixText(params);
    format(flyingtext, sizeof(flyingtext), "* %s *\n(( %s ))", ReturnName(playerid), params);

	if(GetPVarType(playerid, "Caps")) UpperToLower(params);
    if(strlen(params) > 64) 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* [ADO]: %.64s ..", params);
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, ".. %s", params[64]);
    }
    else 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* [ADO]: %s", params);
    }

    GetPlayerPos(playerid, x, y, z);
    if(pData[playerid][pAdoActive])
    {
        if (IsValidDynamic3DTextLabel(pData[playerid][pAdoTag]))
            UpdateDynamic3DTextLabelText(pData[playerid][pAdoTag], COLOR_PURPLE, flyingtext);
        else
            pData[playerid][pAdoTag] = CreateDynamic3DTextLabel(flyingtext, COLOR_PURPLE, x, y, z, 15, _, _, 1, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
    }
    else
    {
        pData[playerid][pAdoActive] = true;
        pData[playerid][pAdoTag] = CreateDynamic3DTextLabel(flyingtext, COLOR_PURPLE, x, y, z, 15, _, _, 1, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
    }
	printf("[ADO] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

CMD:ab(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

    new flyingtext[164], Float:x, Float:y, Float:z;

    if(isnull(params))
	{
        Usage(playerid, "/ab [text]");
		Info(playerid, "Use /ab off to disable or delete the ado tag.");
		return 1;
	}
    if(strlen(params) > 128)
        return Error(playerid, "Max text can only maximmum 128 characters.");

    if (!strcmp(params, "off", true))
    {
        if (!pData[playerid][pBActive])
            return Error(playerid, "You're not actived your 'ab' text.");

        if (IsValidDynamic3DTextLabel(pData[playerid][pBTag]))
            DestroyDynamic3DTextLabel(pData[playerid][pBTag]);

        Servers(playerid, "You're removed your ab text.");
        pData[playerid][pBActive] = false;
        return 1;
    }

    FixText(params);
    format(flyingtext, sizeof(flyingtext), "* %s *\n(( OOC : %s ))", ReturnName(playerid), params);

	if(GetPVarType(playerid, "Caps")) UpperToLower(params);
    if(strlen(params) > 64) 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* [AB]: %.64s ..", params);
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, ".. %s", params[64]);
    }
    else 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* [AB]: %s", params);
    }

    GetPlayerPos(playerid, x, y, z);
    if(pData[playerid][pBActive])
    {
        if (IsValidDynamic3DTextLabel(pData[playerid][pBTag]))
            UpdateDynamic3DTextLabelText(pData[playerid][pBTag], COLOR_PURPLE, flyingtext);
        else
            pData[playerid][pBTag] = CreateDynamic3DTextLabel(flyingtext, COLOR_PURPLE, x, y, z, 15, _, _, 1, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
    }
    else
    {
        pData[playerid][pBActive] = true;
        pData[playerid][pBTag] = CreateDynamic3DTextLabel(flyingtext, COLOR_PURPLE, x, y, z, 15, _, _, 1, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
    }
	printf("[AB] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

CMD:ame(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

    new flyingtext[164];

    if(isnull(params))
        return Usage(playerid, "/ame [action]");

    if(strlen(params) > 128)
        return Error(playerid, "Max action can only maximmum 128 characters.");

	if(GetPVarType(playerid, "Caps")) UpperToLower(params);
    if(strlen(params) > 64) 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* [AME]: %.64s ..", params);
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, ".. %s", params[64]);
    }
    else 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* [AME]: %s", params);
    }
    format(flyingtext, sizeof(flyingtext), "* %s %s*", ReturnName(playerid), params);
    SetPlayerChatBubble(playerid, flyingtext, COLOR_PURPLE, 10.0, 10000);
	printf("[AME] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

/*CMD:me(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

    if(isnull(params))
        return Usage(playerid, "/me [action]");

    if(strlen(params) > 64) 
		return Error(playerid, "Karakter yang anda masukan tidak boleh lebih dari 64 kata");

	SendClientMessage(playerid, -1, "{C2A3DA}ACTION: {FFFFFF}%s", params);
    new str[200];
    format(str, sizeof(str), "{C2A3DA}*%s", params);
    SetPlayerChatBubble(playerid, str, -1, 5.0, 5000); 

	//printf("[ME] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}*/

CMD:me(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

    if(isnull(params))
        return Usage(playerid, "/me [action]");
	
	if(GetPVarType(playerid, "Caps")) UpperToLower(params);
    if(strlen(params) > 64) 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s %.64s ..", ReturnName(playerid), params);
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, ".. %s", params[64]);
    }
    else 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s %s", ReturnName(playerid), params);
    }
	printf("[ME] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

CMD:do(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

    if(isnull(params))
        return Usage(playerid, "/do [description]");

	if(GetPVarType(playerid, "Caps")) UpperToLower(params);
    if(strlen(params) > 64) 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %.64s ..", params);
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, ".. %s (( %s ))", params[64], ReturnName(playerid));
    }
    else 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s (( %s ))", params, ReturnName(playerid));
    }
	printf("[DO] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

CMD:toglog(playerid)
{
	if(!pData[playerid][pTogLog])
	{
		pData[playerid][pTogLog] = 1;
		Info(playerid, "Anda telah menonaktifkan log server.");
	}
	else
	{
		pData[playerid][pTogLog] = 0;
		Info(playerid, "Anda telah mengaktifkan log server.");
	}
	return 1;
}

CMD:togpm(playerid)
{
	if(!pData[playerid][pTogPM])
	{
		pData[playerid][pTogPM] = 1;
		Info(playerid, "Anda telah menonaktifkan PM");
	}
	else
	{
		pData[playerid][pTogPM] = 0;
		Info(playerid, "Anda telah mengaktifkan PM");
	}
	return 1;
}

CMD:togads(playerid)
{
	if(!pData[playerid][pTogAds])
	{
		pData[playerid][pTogAds] = 1;
		Info(playerid, "Anda telah menonaktifkan Ads/Iklan.");
	}
	else
	{
		pData[playerid][pTogAds] = 0;
		Info(playerid, "Anda telah mengaktifkan Ads/Iklan.");
	}
	return 1;
}

CMD:togwt(playerid)
{
	if(!pData[playerid][pTogWT])
	{
		pData[playerid][pTogWT] = 1;
		Info(playerid, "Anda telah menonaktifkan Walkie Talkie.");
	}
	else
	{
		pData[playerid][pTogWT] = 0;
		Info(playerid, "Anda telah mengaktifkan Walkie Talkie.");
	}
	return 1;
}

CMD:pm(playerid, const params[])
{	
	if(pData[playerid][IsLoggedIn] == false)
		return Error(playerid, "You must be logged in to use this command!");

    static text[128], otherid;
    if(sscanf(params, "us[128]", otherid, text))
        return Usage(playerid, "/pm [playerid/PartOfName] [message]");

    if(pData[playerid][pTogPM])
        return Error(playerid, "You must enable private messaging first.");

    if(pData[otherid][pAdminDuty])
        return Error(playerid, "You can't pm'ing admin duty now!");
		
	if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "Player yang anda tuju tidak valid.");

    if(otherid == playerid)
        return Error(playerid, "Tidak dapan PM diri sendiri.");

    if(pData[otherid][pTogPM] && pData[playerid][pAdmin] < 1)
        return Error(playerid, "Player tersebut menonaktifkan pm.");

    if(IsPlayerInRangeOfPoint(otherid, 50, 2184.32, -1023.32, 1018.68))
				return Error(playerid, "Anda tidak dapat melakukan ini, orang yang dituju sedang berada di OOC Zone");

    //GameTextForPlayer(otherid, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~y~New message!", 3000, 3);
    PlayerPlaySound(otherid, 1085, 0.0, 0.0, 0.0);

    SendClientMessageEx(otherid, COLOR_YELLOW, "(( PM from %s (%d): %s ))", pData[playerid][pName], playerid, text);
    SendClientMessageEx(playerid, COLOR_YELLOW, "(( PM to %s (%d): %s ))", pData[otherid][pName], otherid, text);
	//Info(otherid, "/togpm for tog enable/disable PM");
	SendStaffMessage(-1, "(( {FFFF00}<PM-SPY>{FFFFFF} %s (%d) to %s (%d): %s ))", pData[playerid][pName], playerid, pData[otherid][pName], otherid, text);
    return 1;
}

/*CMD:whisper(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	new text[128], otherid;
    if(sscanf(params, "us[128]", otherid, text))
        return Usage(playerid, "/(w)hisper [playerid/PartOfName] [text]");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "Player itu Disconnect or not near you.");

    if(otherid == playerid)
        return Error(playerid, "You can't whisper yourself.");

	if(GetPVarType(playerid, "Caps")) UpperToLower(params);
    if(strlen(text) > 64) 
	{
        SendClientMessageEx(otherid, COLOR_YELLOW, "** Whisper from %s (%d): %.64s", ReturnName(playerid), playerid, text);
        SendClientMessageEx(otherid, COLOR_YELLOW, "...%s **", text[64]);

        SendClientMessageEx(playerid, COLOR_YELLOW, "** Whisper to %s (%d): %.64s", ReturnName(otherid), otherid, text);
        SendClientMessageEx(playerid, COLOR_YELLOW, "...%s **", text[64]);
    }
    else 
	{
        SendClientMessageEx(otherid, COLOR_YELLOW, "** Whisper from %s (%d): %s **", ReturnName(playerid), playerid, text);
        SendClientMessageEx(playerid, COLOR_YELLOW, "** Whisper to %s (%d): %s **", ReturnName(otherid), otherid, text);
    }
    SendNearbyMessage(playerid, 10.0, COLOR_PURPLE, "* %s mutters something in %s's ear.", ReturnName(playerid), ReturnName(otherid));
	
	foreach(new i : Player) if((pData[i][pAdmin]) && pData[i][pSPY] > 0)
    {
        SendClientMessageEx(i, COLOR_YELLOW2, "[SPY Whisper] %s (%d) to %s (%d): %s", pData[playerid][pName], playerid, pData[otherid][pName], otherid, text);
    }
    return 1;
}*/

/*CMD:l(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

    if(isnull(params))
        return Usage(playerid, "/(l)ow [low text]");

	if(GetPVarType(playerid, "Caps")) UpperToLower(params);
	if(IsPlayerInAnyVehicle(playerid))
	{
		foreach(new i : Player)
		{
			if(IsPlayerInAnyVehicle(i) && GetPlayerVehicleID(i) == GetPlayerVehicleID(playerid))
			{
				if(strlen(params) > 64) 
				{
					SendClientMessageEx(i, COLOR_WHITE, "[car] %s says: %.64s ..", ReturnName(playerid), params);
					SendClientMessageEx(i, COLOR_WHITE, "...%s", params[64]);
				}
				else 
				{
					SendClientMessageEx(i, COLOR_WHITE, "[car] %s says: %s", ReturnName(playerid), params);
				}
				printf("[CAR] %s(%d) : %s", pData[playerid][pName], playerid, params);
			}
		}
	}
	else
	{
		if(strlen(params) > 64) 
		{
			SendNearbyMessage(playerid, 5.0, COLOR_WHITE, "[low] %s says: %.64s ..", ReturnName(playerid), params);
			SendNearbyMessage(playerid, 5.0, COLOR_WHITE, "...%s", params[64]);
		}
		else 
		{
			SendNearbyMessage(playerid, 5.0, COLOR_WHITE, "[low] %s says: %s", ReturnName(playerid), params);
		}
		printf("[LOW] %s(%d) : %s", pData[playerid][pName], playerid, params);
	}
    return 1;
}*/

CMD:t(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	if(isnull(params))
		return Usage(playerid, "/t [typo text]");

	if(strlen(params) < 10)
	{
		SendNearbyMessage(playerid, 20.0, COLOR_WHITE, "%s : %.10s*", ReturnName(playerid), params);
	}
	//printf("[OOC] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

CMD:x(playerid, const params[])
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && pData[playerid][pCuffed] == 0 && pData[playerid][pProgress] == 0)
	{
		TogglePlayerControllable(playerid, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		clearAnimations(playerid);
		StopLoopingAnim(playerid);
	}
	return 1;
}

forward DownloadTwitter(playerid);
public DownloadTwitter(playerid)
{
	pData[playerid][pTwtIns] = 1;
	pData[playerid][pPhoneCredit] -= 6;
	Info(playerid, "Twitter successfully downloaded");
}

forward DownloadGps(playerid);
public DownloadGps(playerid)
{
	pData[playerid][pGpsIns] = 1;
	pData[playerid][pPhoneCredit] -= 8;
	Info(playerid, "Gps successfully downloaded");
}

forward DownloadAona(playerid);
public DownloadAona(playerid)
{
	pData[playerid][pAonaIns] = 1;
	pData[playerid][pPhoneCredit] -= 8;
	Info(playerid, "Gps successfully downloaded");
}

CMD:b(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "OOC Zone, Ketik biasa saja");

    if(isnull(params))
        return SyntaxMsg(playerid, "/b <Text>");
		
	if(pData[playerid][pAdminDuty] == 1)
    {
		if(strlen(params) > 64)
		{
			SendNearbyMessage(playerid, 20.0, -1, "%s | {A60000}%s {FFFFFF}[%d]: (( %.64s ..", GetStaffRank(playerid), pData[playerid][pAdminname], playerid, params);
            SendNearbyMessage(playerid, 20.0, -1, ".. %s ))", params[64]);
		}
		else
        {
            SendNearbyMessage(playerid, 20.0, -1, "%s | {A60000}%s {FFFFFF}[%d]: (( %s ))", GetStaffRank(playerid), pData[playerid][pAdminname], playerid, params);
            return 1;
        }
	}
	else
	{
		if(strlen(params) > 64)
		{
			SendNearbyMessage(playerid, 20.0, -1, "%s | %s [%d]: (( %.64s ..", GetLevelRank(playerid), GetRPName(playerid), playerid, params);
            SendNearbyMessage(playerid, 20.0, -1, ".. %s ))", params[64]);
		}
		else
        {
            SendNearbyMessage(playerid, 20.0, -1, "%s | %s [%d]: (( %s ))", GetLevelRank(playerid), GetRPName(playerid), playerid, params);
            return 1;
        }
	}
    return 1;
}

CMD:call(playerid, const params[])
{
	if(Inventory_Count(playerid, "Phone") < 1)
		return ErrorMsg(playerid, "Anda tidak memilik Ponsel");

	new ph;
	if(pData[playerid][pPhone] == 0) return ErrorMsg(playerid, "Anda tidak memiliki ponsel");
	if(pData[playerid][pUsePhone] == 0) return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");
	if(pData[playerid][pPhoneCredit] <= 0) return ErrorMsg(playerid, "Anda tidak memiliki Phone Credits");

	if(sscanf(params, "d", ph))
	{
		Usage(playerid, "/call [phone number]");
		Info(playerid, "SAPD [911] | SAMD [922]");
		foreach(new ii : Player)
		{	
			if(pData[ii][pTaxiDuty] == 1)
			{
				SendClientMessageEx(playerid, COLOR_GREEN, "{FFFF00}TAXI: {FFFFFF}%s | {00FF00}PH: {FFFFFF}[%d]", ReturnName(ii), pData[ii][pPhone]);
			}
		}
		return 1;
	}
	if(ph == 911)
	{
		if(pData[playerid][pCallTime] >= gettime())
			return Error(playerid, "You must wait %d seconds before sending another call.", pData[playerid][pCallTime] - gettime());
		
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SyntaxMsg(playerid, "Nomor ini hanya untuk emergency call, mohon tunggu respon dari SAPD!");
		SendFactionMessage(1, -1, "{0900FF}911: {FFFFFF}seseorang telah menggunakan panggilan darudat! | PH: {00FF00}%d{FFFFFF} | Lokasi: %s", pData[playerid][pPhone], GetLocation(x, y, z));
	
		pData[playerid][pCallTime] = gettime() + 60;
	}
	if(ph == 922)
	{
		if(pData[playerid][pCallTime] >= gettime())
			return Error(playerid, "You must wait %d seconds before sending another call.", pData[playerid][pCallTime] - gettime());
		
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SyntaxMsg(playerid, "Nomor ini hanya untuk emergency call, mohon tunggu respon dari SAMD!");
		SendFactionMessage(3, -1, "{FF69D8}933: {FFFFFF}seseorang telah menggunakan panggilan darudat! | PH: {00FF00}%d{FFFFFF} | Lokasi: %s", pData[playerid][pPhone], GetLocation(x, y, z));
	
		pData[playerid][pCallTime] = gettime() + 60;
	}
	if(ph == pData[playerid][pPhone]) 
	{
		
		for(new x = 0; x < 26; x++) {
			PlayerTextDrawHide(playerid, NotifX[playerid][x]);
		}
		for(new x = 0; x < 94; x++) {
			PlayerTextDrawHide(playerid, HomeScreen[playerid][x]);
		}
		for(new x = 0; x < 31; x++) {
			PlayerTextDrawHide(playerid, TaxiMenu[playerid][x]);
		}
		for(new x = 0; x < 54; x++) {
			PlayerTextDrawHide(playerid, BankMenu[playerid][x]);
		}
		for(new x = 0; x < 34; x++) {
			PlayerTextDrawHide(playerid, SettingsMenu[playerid][x]);
		}
		for(new x = 0; x < 44; x++) {
			PlayerTextDrawHide(playerid, XMenu[playerid][x]);
		}

		for(new i = 0; i < 27; i++)
		{
			PlayerTextDrawShow(playerid, GwTelpon[playerid][i]);
		}
		PlayerTextDrawSetString(playerid, GwTelpon[playerid][24], "Nomer Non Actived");
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
		CancelSelectTextDraw(playerid);
		RemovePlayerAttachedObject(playerid, 9);
		Info(playerid, "Gunakan {FFFF00}'/cursor' {FFFFFF}untuk mengembalikan fungsi klik");
		return 1;
	}	

	foreach(new ii : Player)
	{
		if(pData[ii][pPhone] == ph)
		{
			if(pData[ii][IsLoggedIn] == false || !IsPlayerConnected(ii))
			{
				
				for(new x = 0; x < 26; x++) {
					PlayerTextDrawHide(playerid, NotifX[playerid][x]);
				}
				for(new x = 0; x < 94; x++) {
					PlayerTextDrawHide(playerid, HomeScreen[playerid][x]);
				}
				for(new x = 0; x < 31; x++) {
					PlayerTextDrawHide(playerid, TaxiMenu[playerid][x]);
				}
				for(new x = 0; x < 54; x++) {
					PlayerTextDrawHide(playerid, BankMenu[playerid][x]);
				}
				for(new x = 0; x < 34; x++) {
					PlayerTextDrawHide(playerid, SettingsMenu[playerid][x]);
				}
				for(new x = 0; x < 44; x++) {
					PlayerTextDrawHide(playerid, XMenu[playerid][x]);
				}

				for(new i = 0; i < 27; i++)
				{
					PlayerTextDrawShow(playerid, GwTelpon[playerid][i]);
				}
				PlayerTextDrawSetString(playerid, GwTelpon[playerid][24], "Nomer Non Actived");
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
				CancelSelectTextDraw(playerid);
				RemovePlayerAttachedObject(playerid, 9);
				Info(playerid, "Gunakan {FFFF00}'/cursor' {FFFFFF}untuk mengembalikan fungsi klik");
				return 1;
			}
			if(pData[ii][pUsePhone] == 0)
			{
				for(new x = 0; x < 26; x++) {
					PlayerTextDrawHide(playerid, NotifX[playerid][x]);
				}
				for(new x = 0; x < 94; x++) {
					PlayerTextDrawHide(playerid, HomeScreen[playerid][x]);
				}
				for(new x = 0; x < 31; x++) {
					PlayerTextDrawHide(playerid, TaxiMenu[playerid][x]);
				}
				for(new x = 0; x < 54; x++) {
					PlayerTextDrawHide(playerid, BankMenu[playerid][x]);
				}
				for(new x = 0; x < 34; x++) {
					PlayerTextDrawHide(playerid, SettingsMenu[playerid][x]);
				}
				for(new x = 0; x < 44; x++) {
					PlayerTextDrawHide(playerid, XMenu[playerid][x]);
				}

				for(new i = 0; i < 27; i++)
				{
					PlayerTextDrawShow(playerid, GwTelpon[playerid][i]);
				}
				PlayerTextDrawSetString(playerid, GwTelpon[playerid][24], "Nomer Non Actived");
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
				CancelSelectTextDraw(playerid);
				RemovePlayerAttachedObject(playerid, 9);
				Info(playerid, "Gunakan {FFFF00}'/cursor' {FFFFFF}untuk mengembalikan fungsi klik");
				return 1;
			}
			if(ToggleCall[ii] == 1)
			{
				
				for(new x = 0; x < 26; x++) {
					PlayerTextDrawHide(playerid, NotifX[playerid][x]);
				}
				for(new x = 0; x < 94; x++) {
					PlayerTextDrawHide(playerid, HomeScreen[playerid][x]);
				}
				for(new x = 0; x < 31; x++) {
					PlayerTextDrawHide(playerid, TaxiMenu[playerid][x]);
				}
				for(new x = 0; x < 54; x++) {
					PlayerTextDrawHide(playerid, BankMenu[playerid][x]);
				}
				for(new x = 0; x < 34; x++) {
					PlayerTextDrawHide(playerid, SettingsMenu[playerid][x]);
				}
				for(new x = 0; x < 44; x++) {
					PlayerTextDrawHide(playerid, XMenu[playerid][x]);
				}

				for(new i = 0; i < 27; i++)
				{
					PlayerTextDrawShow(playerid, GwTelpon[playerid][i]);
				}
				PlayerTextDrawSetString(playerid, GwTelpon[playerid][24], "Nomer Non Actived");
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
				RemovePlayerAttachedObject(playerid, 9);
				CancelSelectTextDraw(playerid);
				Info(playerid, "Gunakan {FFFF00}'/cursor' {FFFFFF}untuk mengembalikan fungsi klik");				
				return 1;
			}
			
			if(pData[ii][pCall] == INVALID_PLAYER_ID)
			{
				pData[playerid][pCall] = ii;
				for(new x = 0; x < 26; x++) {
					PlayerTextDrawHide(playerid, NotifX[playerid][x]);
				}
				for(new x = 0; x < 94; x++) {
					PlayerTextDrawHide(playerid, HomeScreen[playerid][x]);
				}
				for(new x = 0; x < 31; x++) {
					PlayerTextDrawHide(playerid, TaxiMenu[playerid][x]);
				}
				for(new x = 0; x < 54; x++) {
					PlayerTextDrawHide(playerid, BankMenu[playerid][x]);
				}
				for(new x = 0; x < 34; x++) {
					PlayerTextDrawHide(playerid, SettingsMenu[playerid][x]);
				}
				for(new x = 0; x < 44; x++) {
					PlayerTextDrawHide(playerid, XMenu[playerid][x]);
				}

				for(new i = 0; i < 27; i++)
				{
					PlayerTextDrawShow(playerid, GwTelpon[playerid][i]);
				}
				new str[200];
				format(str, sizeof(str), "%s", pData[ii][pName]);
				PlayerTextDrawSetString(playerid, GwTelpon[playerid][24], str);

				for(new x = 0; x < 26; x++) {
					PlayerTextDrawHide(ii, NotifX[playerid][x]);
				}
				for(new x = 0; x < 94; x++) {
					PlayerTextDrawHide(ii, HomeScreen[playerid][x]);
				}
				for(new x = 0; x < 31; x++) {
					PlayerTextDrawHide(ii, TaxiMenu[playerid][x]);
				}
				for(new x = 0; x < 54; x++) {
					PlayerTextDrawHide(ii, BankMenu[playerid][x]);
				}
				for(new x = 0; x < 34; x++) {
					PlayerTextDrawHide(ii, SettingsMenu[playerid][x]);
				}
				for(new x = 0; x < 44; x++) {
					PlayerTextDrawHide(ii, XMenu[playerid][x]);
				}

				for(new i = 0; i < 29; i++)
				{
					PlayerTextDrawShow(ii, DiaTelpon[playerid][i]);
				}
				format(str, sizeof(str), "%s", pData[playerid][pName]);
				PlayerTextDrawSetString(ii, DiaTelpon[ii][24], str);

				RemovePlayerAttachedObject(playerid, 9);
				RemovePlayerAttachedObject(ii, 9);
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
				SetPlayerSpecialAction(ii, SPECIAL_ACTION_USECELLPHONE);
				PlayerPlaySound(playerid, 3600, 0,0,0);
				PlayerPlaySound(ii, 6003, 0,0,0);
				CancelSelectTextDraw(playerid);
				CancelSelectTextDraw(ii);
				SetPlayerChatBubble(playerid, "{C2A3DA}> Menelpon <", -1, 3.0, 5000);
				SetPlayerChatBubble(ii, "{C2A3DA}> Menelpon <", -1, 3.0, 5000);
				Info(playerid, "Gunakan {FFFF00}'/cursor' {FFFFFF}untuk mengembalikan fungsi klik");
				Info(ii, "Gunakan {FFFF00}'/cursor' {FFFFFF}untuk mengembalikan fungsi klik");
			}
			else
			{
				for(new x = 0; x < 26; x++) {
					PlayerTextDrawHide(playerid, NotifX[playerid][x]);
				}
				for(new x = 0; x < 94; x++) {
					PlayerTextDrawHide(playerid, HomeScreen[playerid][x]);
				}
				for(new x = 0; x < 31; x++) {
					PlayerTextDrawHide(playerid, TaxiMenu[playerid][x]);
				}
				for(new x = 0; x < 54; x++) {
					PlayerTextDrawHide(playerid, BankMenu[playerid][x]);
				}
				for(new x = 0; x < 34; x++) {
					PlayerTextDrawHide(playerid, SettingsMenu[playerid][x]);
				}
				for(new x = 0; x < 44; x++) {
					PlayerTextDrawHide(playerid, XMenu[playerid][x]);
				}

				for(new i = 0; i < 27; i++)
				{
					PlayerTextDrawShow(playerid, GwTelpon[playerid][i]);
				}
				PlayerTextDrawSetString(playerid, GwTelpon[playerid][24], "Nomer Non Actived");
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
				RemovePlayerAttachedObject(playerid, 9);
				CancelSelectTextDraw(playerid);
				Info(playerid, "Gunakan {FFFF00}'/cursor' {FFFFFF}untuk mengembalikan fungsi klik");			
			}
		}
	}
	return 1;
}

/*CMD:call(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");
	
	new ph;
	if(pData[playerid][pPhone] == 0) return ErrorMsg(playerid, "Anda tidak memiliki Ponsel!");
	if(pData[playerid][pUsePhone] == 0) return ErrorMsg(playerid, "Handphone anda belum di nyalakan");
	if(pData[playerid][pPhoneCredit] <= 0) return ErrorMsg(playerid, "Anda tidak memiliki Ponsel credits!");

	if(sscanf(params, "d", ph))
	{
		Usage(playerid, "/call [phone number] 911 - SAPD Crime Call | 922 - SAMD Medic Call");
		foreach(new ii : Player)
		{
			if(pData[ii][pMechDuty] == 1)
			{
				SendClientMessageEx(playerid, COLOR_GREEN, "Mekanik Duty: %s | PH: [%d]", ReturnName(ii), pData[ii][pPhone]);
			}
		}
		return 1;
	}
	if(ph == 911)
	{
		if(pData[playerid][pCallTime] >= gettime())
			return Error(playerid, "Anda harus menunggu %d detik sebelum menggunakan panggilan", pData[playerid][pCallTime] - gettime());

		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SyntaxMsg(playerid, "Nomor ini hanya untuk emergency call, mohon tunggu respon dari SAPD!");
		SendFactionMessage(1, -1, "{0000FF}<SAPD CALL> {FFFFFF}seseorang telah menggunakan panggilan {0000FF}'911'{FFFFFF} | Nomor: [{00FF00}%d{FFFFFF}] | Lokasi: %s", pData[playerid][pPhone], GetLocation(x, y, z));
		pData[playerid][pCallTime] = gettime() + 60;
	}
	if(ph == 922)
	{
		if(pData[playerid][pCallTime] >= gettime())
			return Error(playerid, "Anda harus menunggu %d detik sebelum menggunakan panggilan", pData[playerid][pCallTime] - gettime());

		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SyntaxMsg(playerid, "Nomor ini hanya untuk emergency call, mohon tunggu respon dari SAMD!");
		SendFactionMessage(3, -1, "{FF66FF}<SAMD CALL> seseorang telah menggunakan panggilan {FF66FF}'922'{FFFFFF} | Nomor: [{00FF00}%d{FFFFFF}] | Lokasi: %s", pData[playerid][pPhone], GetLocation(x, y, z));
	}
	if(ph == 933)
	{
		if(pData[playerid][pCallTime] >= gettime())
			return Error(playerid, "Anda harus menunggu %d detik sebelum menggunakan panggilan", pData[playerid][pCallTime] - gettime());

		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		Info(playerid, "Your calling has sent to the taxi driver. please wait for respon!");
		pData[playerid][pCallTime] = gettime() + 60;
		foreach(new tx : Player)
		{
			if(pData[tx][pJob] == 1 || pData[tx][pJob2] == 1)
			{
				SendClientMessageEx(tx, -1, "{FFFF00}<TAXI CALL> {FFFFFF}seseorang telah memesan taxi | Nomor: [{00FF00}%d{FFFFFF}] | Lokasi: %s", pData[playerid][pPhone], GetLocation(x, y, z));
			}
		}
	}

	if(ph == pData[playerid][pPhone])
		return ErrorMsg(playerid, "Nomor yang anda tuju sedang sibuk");

	foreach(new ii : Player)
	{
		if(pData[ii][pPhone] == ph)
		{
			if(pData[ii][pUsePhone] == 0) 
				return ErrorMsg(playerid, "Nomor yang anda tuju sedang sibuk atau tidak aktif");

			if(pData[ii][IsLoggedIn] == false || !IsPlayerConnected(ii))
			{
				for(new i = 0; i < 81; i++)
				{
					TextDrawHideForPlayer(playerid, nandaPhoneHome[i]);
				}
				for(new i = 0; i < 40; i++)
				{
					TextDrawShowForPlayer(playerid, nandaPhoneTelpon[i]);
				}
				SelectTextDraw(playerid, COLOR_WHITE);
				new tstr[256];
				format(tstr, sizeof(tstr), "%s", pData[ii][pName]);
				TextDrawSetString(nandaPhoneTelpon[39], tstr);
			}
			if(pData[ii][pCall] == INVALID_PLAYER_ID)
			{
				pData[playerid][pCall] = ii;

				SendClientMessageEx(playerid, -1, "{FFFF00}[CELLPHONE to %d] {FFFFFF}Telepon sedang berdering, mohon tunggu untuk di jawab.", ph);
				for(new i = 0; i < 81; i++)
				{
					TextDrawHideForPlayer(playerid, nandaPhoneHome[i]);
				}
				for(new i = 0; i < 54; i++)
				{
					TextDrawHideForPlayer(playerid, nandaPhoneTaxi[i]);
				}
				for(new i = 0; i < 67; i++)
				{
					TextDrawHideForPlayer(playerid, nandaPhoneBank[i]);
				}
				for(new i = 0; i < 45; i++)
				{
					TextDrawHideForPlayer(playerid, nandaPhoneDering[i]);
				}
				for(new i = 0; i < 40; i++)
				{
					TextDrawShowForPlayer(playerid, nandaPhoneTelpon[i]);
				}
				SelectTextDraw(playerid, COLOR_WHITE);
				new tstr[256];
				format(tstr, sizeof(tstr), "%s", pData[ii][pName]);
				TextDrawSetString(nandaPhoneTelpon[39], tstr);

				//SendClientMessageEx(ii, -1, "{FFFF00}[CELLPHONE form %d] {FFFFFF}Handphone kamu berdering, gunakan {FFFF00}/p {FFFFFF}untuk menjawab", pData[playerid][pPhone]);
				for(new i = 0; i < 81; i++)
				{
					TextDrawHideForPlayer(ii, nandaPhoneHome[i]);
				}
				for(new i = 0; i < 54; i++)
				{
					TextDrawHideForPlayer(ii, nandaPhoneTaxi[i]);
				}
				for(new i = 0; i < 67; i++)
				{
					TextDrawHideForPlayer(ii, nandaPhoneBank[i]);
				}
				for(new i = 0; i < 40; i++)
				{
					TextDrawHideForPlayer(ii, nandaPhoneTelpon[i]);
				}
				for(new i = 0; i < 45; i++)
				{
					TextDrawShowForPlayer(ii, nandaPhoneDering[i]);
				}
				SelectTextDraw(ii, COLOR_WHITE);
				format(tstr, sizeof(tstr), "%s", pData[ii][pName]);
				TextDrawSetString(nandaPhoneDering[44], tstr);

				ToggleCall[ii] = 1;
				PlayerPlaySound(playerid, 3600, 0,0,0);
				PlayerPlaySound(ii, 6003, 0,0,0);
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
				SetPlayerSpecialAction(ii, SPECIAL_ACTION_USECELLPHONE);
				SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s takes out a cellphone and calling someone.", ReturnName(playerid));
			}
			else
			{
				for(new i = 0; i < 81; i++)
				{
					TextDrawHideForPlayer(playerid, nandaPhoneHome[i]);
				}
				for(new i = 0; i < 54; i++)
				{
					TextDrawHideForPlayer(playerid, nandaPhoneTaxi[i]);
				}
				for(new i = 0; i < 67; i++)
				{
					TextDrawHideForPlayer(playerid, nandaPhoneBank[i]);
				}
				for(new i = 0; i < 40; i++)
				{
					TextDrawHideForPlayer(playerid, nandaPhoneTelpon[i]);
				}
				for(new i = 0; i < 45; i++)
				{
					TextDrawHideForPlayer(playerid, nandaPhoneDering[i]);
				}
				CancelSelectTextDraw(playerid);
				ClearAnimations(playerid, 0);
				return 1;
			}
		}
	}
	return 1;
}*/

CMD:p(playerid, const params[])
{
	if(pData[playerid][pCall] != INVALID_PLAYER_ID)
		return ErrorMsg(playerid, "Anda sedang menelpon seseorang");

	if(pData[playerid][pInjured] != 0)
		return ErrorMsg(playerid, "Saat ini anda tidak dapat menelpon");

	foreach(new ii : Player)
	{
		if(playerid == pData[ii][pCall])
		{
			pData[ii][pPhoneCredit]--;
			pData[playerid][pCall] = ii;
			for(new x = 0; x < 26; x++) {
				PlayerTextDrawHide(playerid, NotifX[playerid][x]);
			}
			for(new x = 0; x < 94; x++) {
				PlayerTextDrawHide(playerid, HomeScreen[playerid][x]);
			}
			for(new x = 0; x < 31; x++) {
				PlayerTextDrawHide(playerid, TaxiMenu[playerid][x]);
			}
			for(new x = 0; x < 54; x++) {
				PlayerTextDrawHide(playerid, BankMenu[playerid][x]);
			}
			for(new x = 0; x < 34; x++) {
				PlayerTextDrawHide(playerid, SettingsMenu[playerid][x]);
			}
			for(new x = 0; x < 44; x++) {
				PlayerTextDrawHide(playerid, XMenu[playerid][x]);
			}

			for(new i = 0; i < 27; i++)
			{
				PlayerTextDrawShow(playerid, GwTelpon[playerid][i]);
			}
			for(new i = 0; i < 29; i++)
			{
				PlayerTextDrawShow(playerid, DiaTelpon[playerid][i]);
			}
			new str[200];
			format(str, sizeof(str), "%s", pData[ii][pName]);
			PlayerTextDrawSetString(playerid, GwTelpon[playerid][24], str);

			for(new x = 0; x < 26; x++) {
				PlayerTextDrawHide(playerid, NotifX[playerid][x]);
			}
			for(new x = 0; x < 94; x++) {
				PlayerTextDrawHide(playerid, HomeScreen[playerid][x]);
			}
			for(new x = 0; x < 31; x++) {
				PlayerTextDrawHide(playerid, TaxiMenu[playerid][x]);
			}
			for(new x = 0; x < 54; x++) {
				PlayerTextDrawHide(playerid, BankMenu[playerid][x]);
			}
			for(new x = 0; x < 34; x++) {
				PlayerTextDrawHide(playerid, SettingsMenu[playerid][x]);
			}
			for(new x = 0; x < 44; x++) {
				PlayerTextDrawHide(playerid, XMenu[playerid][x]);
			}

			for(new i = 0; i < 27; i++)
			{
				PlayerTextDrawShow(playerid, GwTelpon[playerid][i]);
			}
			for(new i = 0; i < 29; i++)
			{
				PlayerTextDrawShow(playerid, DiaTelpon[playerid][i]);
			}
			format(str, sizeof(str), "%s", pData[playerid][pName]);
			PlayerTextDrawSetString(ii, DiaTelpon[ii][24], str);

			SetPlayerSpecialAction(ii, SPECIAL_ACTION_USECELLPHONE);
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);

			ToggleCall[playerid] = 1;
			ToggleCall[ii] = 1;

			new targetid = pData[playerid][pCall];
			OnPhone[targetid] = SvCreateGStream(0xFFA200FF, "inPhone");

			if(OnPhone[targetid])
			{
				SvAttachListenerToStream(OnPhone[targetid], targetid);
				SvAttachListenerToStream(OnPhone[targetid], playerid);
			}

			if(OnPhone[targetid] && pData[playerid][pCall] != INVALID_PLAYER_ID)
			{
				SvAttachSpeakerToStream(OnPhone[targetid], playerid);
			}

			if(OnPhone[targetid] && pData[targetid][pCall] != INVALID_PLAYER_ID)
			{
				SvAttachSpeakerToStream(OnPhone[targetid], targetid);
			}			
		}
	}
	return 1;
}

/*CMD:p(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	if(pData[playerid][pCall] != INVALID_PLAYER_ID)
		return Error(playerid, "Anda sudah sedang menelpon seseorang!");
		
	if(pData[playerid][pInjured] != 0)
		return Error(playerid, "You cant do that in this time.");
		
	foreach(new ii : Player)
	{
		if(playerid == pData[ii][pCall])
		{
			pData[ii][pPhoneCredit]--;
			
			pData[playerid][pCall] = ii;
			//SendClientMessageEx(ii, COLOR_YELLOW, "[CELLPHONE] "WHITE_E"phone is connected, type '/hu' to stop!");
			//SendClientMessageEx(playerid, COLOR_YELLOW, "[CELLPHONE] "WHITE_E"phone is connected, type '/hu' to stop!");
			for(new i = 0; i < 40; i++)
			{
				TextDrawHideForPlayer(playerid, nandaPhoneTelpon[i]);
			}
			for(new i = 0; i < 45; i++)
			{
				TextDrawShowForPlayer(playerid, nandaPhoneDering[i]);
			}
			for(new i = 0; i < 40; i++)
			{
				TextDrawHideForPlayer(ii, nandaPhoneTelpon[i]);
			}
			for(new i = 0; i < 45; i++)
			{
				TextDrawShowForPlayer(ii, nandaPhoneDering[i]);
			}
			SelectTextDraw(playerid, COLOR_WHITE);
			SelectTextDraw(ii, COLOR_WHITE);
			new tstr[256];
			format(tstr, sizeof(tstr), "%s", pData[ii][pName]);
			TextDrawSetString(nandaPhoneDering[44], tstr);
			format(tstr, sizeof(tstr), "%s", pData[playerid][pName]);
			TextDrawSetString(nandaPhoneDering[44], tstr);

			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
			ToggleCall[playerid] = 1;
			ToggleCall[ii] = 1;
			SetPlayerSpecialAction(ii, SPECIAL_ACTION_USECELLPHONE);
			SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s answers their cellphone.", ReturnName(playerid));
			SendNearbyMessage(ii, 20.0, COLOR_PURPLE, "* %s answers their cellphone.", ReturnName(ii));
			new targetid = pData[playerid][pCall];

			OnPhone[targetid] = SvCreateGStream(0xFFA200FF, "InPhone");

			if(OnPhone[targetid])
			{
				SvAttachListenerToStream(OnPhone[targetid], targetid);
				SvAttachListenerToStream(OnPhone[targetid], playerid);
			}

			if(OnPhone[targetid] && pData[playerid][pCall] != INVALID_PLAYER_ID)
			{
				SvAttachSpeakerToStream(OnPhone[targetid], playerid);
			}

			if(OnPhone[targetid] && pData[targetid][pCall] != INVALID_PLAYER_ID)
			{
				SvAttachSpeakerToStream(OnPhone[targetid], targetid);
			}
		}
	}
	return 1;
}*/

CMD:hu(playerid, const params[])
{
	new caller = pData[playerid][pCall];
	if(IsPlayerConnected(caller) && caller != INVALID_PLAYER_ID)
	{
		for(new i = 0; i < 29; i++)
		{
			PlayerTextDrawHide(caller, DiaTelpon[caller][i]);
		}
		for(new i = 0; i < 27; i++)
		{
			PlayerTextDrawHide(caller, GwTelpon[caller][i]);
		}
		CancelSelectTextDraw(caller);
		CancelSelectTextDraw(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
		SetPlayerSpecialAction(caller, SPECIAL_ACTION_STOPUSECELLPHONE);

		pData[caller][pCall] = INVALID_PLAYER_ID;
		pData[playerid][pCall] = INVALID_PLAYER_ID;
		ToggleCall[caller] = 0;
		TogglePhone[caller] = 0;
		ToggleCall[playerid] = 0;
		TogglePhone[playerid] = 0;

		if (OnPhone[caller] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[caller], caller);
		}
		if(OnPhone[caller] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[caller], playerid);
		}
		if(OnPhone[caller])
		{
			SvDetachListenerFromStream(OnPhone[caller], caller);
			SvDetachListenerFromStream(OnPhone[caller], playerid);
			SvDeleteStream(OnPhone[caller]);
			OnPhone[caller] = SV_NULL;
		}
		if(OnPhone[playerid] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[playerid], caller);
		}
		if(OnPhone[playerid] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[playerid], playerid);
		}
		if(OnPhone[playerid])
		{
			SvDetachListenerFromStream(OnPhone[playerid], caller);
			SvDetachListenerFromStream(OnPhone[playerid], playerid);
			SvDeleteStream(OnPhone[playerid]);
			OnPhone[playerid] = SV_NULL;
		}				
	}
	return 1;
}

/*CMD:hu(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	new caller = pData[playerid][pCall];
	if(IsPlayerConnected(caller) && caller != INVALID_PLAYER_ID)
	{
		for(new i = 0; i < 40; i++)
		{
			TextDrawHideForPlayer(caller, nandaPhoneTelpon[i]);
		}
		for(new i = 0; i < 45; i++)
		{
			TextDrawHideForPlayer(caller, nandaPhoneDering[i]);
		}
		CancelSelectTextDraw(caller);
		clearAnimations(caller);

		for(new i = 0; i < 40; i++)
		{
			TextDrawHideForPlayer(playerid, nandaPhoneTelpon[i]);
		}
		for(new i = 0; i < 45; i++)
		{
			TextDrawHideForPlayer(playerid, nandaPhoneDering[i]);
		}
		CancelSelectTextDraw(playerid);
		clearAnimations(playerid);

		pData[caller][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(caller, SPECIAL_ACTION_STOPUSECELLPHONE);
		SendNearbyMessage(caller, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(caller));
		SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(playerid));
		ToggleCall[caller] = 0;
		TogglePhone[caller] = 0;
		ToggleCall[playerid] = 0;
		TogglePhone[playerid] = 0;
		pData[playerid][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);


		if (OnPhone[caller] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[caller], caller);
		}
		if(OnPhone[caller] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[caller], playerid);
		}
		if(OnPhone[caller])
		{
			SvDetachListenerFromStream(OnPhone[caller], caller);
			SvDetachListenerFromStream(OnPhone[caller], playerid);
			SvDeleteStream(OnPhone[caller]);
			OnPhone[caller] = SV_NULL;
		}
		if(OnPhone[playerid] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[playerid], caller);
		}
		if(OnPhone[playerid] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[playerid], playerid);
		}
		if(OnPhone[playerid])
		{
			SvDetachListenerFromStream(OnPhone[playerid], caller);
			SvDetachListenerFromStream(OnPhone[playerid], playerid);
			SvDeleteStream(OnPhone[playerid]);
			OnPhone[playerid] = SV_NULL;
		}
	}
	return 1;
}*/

CMD:offcall(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	new caller = pData[playerid][pCall];
	if(IsPlayerConnected(caller) && caller != INVALID_PLAYER_ID)
	{
		for(new i = 0; i < 27; i++)
		{
			PlayerTextDrawHide(caller, GwTelpon[playerid][i]);
		}
		for(new i = 0; i < 29; i++)
		{
			PlayerTextDrawHide(caller, DiaTelpon[playerid][i]);
		}
		CancelSelectTextDraw(caller);
		clearAnimations(caller);

		for(new i = 0; i < 27; i++)
		{
			PlayerTextDrawHide(playerid, GwTelpon[playerid][i]);
		}
		for(new i = 0; i < 29; i++)
		{
			PlayerTextDrawHide(playerid, DiaTelpon[playerid][i]);
		}
		CancelSelectTextDraw(playerid);
		clearAnimations(playerid);

		pData[caller][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(caller, SPECIAL_ACTION_STOPUSECELLPHONE);
		SendNearbyMessage(caller, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(caller));
		SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(playerid));
		ToggleCall[caller] = 0;
		TogglePhone[caller] = 0;
		ToggleCall[playerid] = 0;
		TogglePhone[playerid] = 0;
		pData[playerid][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);


		if (OnPhone[caller] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[caller], caller);
		}
		if(OnPhone[caller] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[caller], playerid);
		}
		if(OnPhone[caller])
		{
			SvDetachListenerFromStream(OnPhone[caller], caller);
			SvDetachListenerFromStream(OnPhone[caller], playerid);
			SvDeleteStream(OnPhone[caller]);
			OnPhone[caller] = SV_NULL;
		}
		if(OnPhone[playerid] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[playerid], caller);
		}
		if(OnPhone[playerid] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[playerid], playerid);
		}
		if(OnPhone[playerid])
		{
			SvDetachListenerFromStream(OnPhone[playerid], caller);
			SvDetachListenerFromStream(OnPhone[playerid], playerid);
			SvDeleteStream(OnPhone[playerid]);
			OnPhone[playerid] = SV_NULL;
		}
	}
	return 1;
}

CMD:offcl(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	new caller = pData[playerid][pCall];
	if(IsPlayerConnected(caller) && caller != INVALID_PLAYER_ID)
	{
		for(new i = 0; i < 27; i++)
		{
			PlayerTextDrawHide(caller, GwTelpon[playerid][i]);
		}
		for(new i = 0; i < 29; i++)
		{
			PlayerTextDrawHide(caller, DiaTelpon[playerid][i]);
		}
		CancelSelectTextDraw(caller);
		clearAnimations(caller);

		for(new i = 0; i < 27; i++)
		{
			PlayerTextDrawHide(playerid, GwTelpon[playerid][i]);
		}
		for(new i = 0; i < 29; i++)
		{
			PlayerTextDrawHide(playerid, DiaTelpon[playerid][i]);
		}
		CancelSelectTextDraw(playerid);
		clearAnimations(playerid);

		pData[caller][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(caller, SPECIAL_ACTION_STOPUSECELLPHONE);
		SendNearbyMessage(caller, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(caller));
		SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(playerid));
		ToggleCall[caller] = 0;
		TogglePhone[caller] = 0;
		ToggleCall[playerid] = 0;
		TogglePhone[playerid] = 0;
		pData[playerid][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);


		if (OnPhone[caller] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[caller], caller);
		}
		if(OnPhone[caller] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[caller], playerid);
		}
		if(OnPhone[caller])
		{
			SvDetachListenerFromStream(OnPhone[caller], caller);
			SvDetachListenerFromStream(OnPhone[caller], playerid);
			SvDeleteStream(OnPhone[caller]);
			OnPhone[caller] = SV_NULL;
		}
		if(OnPhone[playerid] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[playerid], caller);
		}
		if(OnPhone[playerid] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[playerid], playerid);
		}
		if(OnPhone[playerid])
		{
			SvDetachListenerFromStream(OnPhone[playerid], caller);
			SvDetachListenerFromStream(OnPhone[playerid], playerid);
			SvDeleteStream(OnPhone[playerid]);
			OnPhone[playerid] = SV_NULL;
		}
	}
	return 1;
}

CMD:offc(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	new caller = pData[playerid][pCall];
	if(IsPlayerConnected(caller) && caller != INVALID_PLAYER_ID)
	{
		for(new i = 0; i < 27; i++)
		{
			PlayerTextDrawHide(caller, GwTelpon[playerid][i]);
		}
		for(new i = 0; i < 29; i++)
		{
			PlayerTextDrawHide(caller, DiaTelpon[playerid][i]);
		}
		CancelSelectTextDraw(caller);
		clearAnimations(caller);

		for(new i = 0; i < 27; i++)
		{
			PlayerTextDrawHide(playerid, GwTelpon[playerid][i]);
		}
		for(new i = 0; i < 29; i++)
		{
			PlayerTextDrawHide(playerid, DiaTelpon[playerid][i]);
		}
		CancelSelectTextDraw(playerid);
		clearAnimations(playerid);

		pData[caller][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(caller, SPECIAL_ACTION_STOPUSECELLPHONE);
		SendNearbyMessage(caller, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(caller));
		SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(playerid));
		ToggleCall[caller] = 0;
		TogglePhone[caller] = 0;
		ToggleCall[playerid] = 0;
		TogglePhone[playerid] = 0;
		pData[playerid][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);


		if (OnPhone[caller] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[caller], caller);
		}
		if(OnPhone[caller] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[caller], playerid);
		}
		if(OnPhone[caller])
		{
			SvDetachListenerFromStream(OnPhone[caller], caller);
			SvDetachListenerFromStream(OnPhone[caller], playerid);
			SvDeleteStream(OnPhone[caller]);
			OnPhone[caller] = SV_NULL;
		}
		if(OnPhone[playerid] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[playerid], caller);
		}
		if(OnPhone[playerid] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
			SvDetachSpeakerFromStream(OnPhone[playerid], playerid);
		}
		if(OnPhone[playerid])
		{
			SvDetachListenerFromStream(OnPhone[playerid], caller);
			SvDetachListenerFromStream(OnPhone[playerid], playerid);
			SvDeleteStream(OnPhone[playerid]);
			OnPhone[playerid] = SV_NULL;
		}
	}
	return 1;
}

CMD:sms(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	new ph, text[50];
	//if(pData[playerid][pPhone] == 0) return Error(playerid, "Anda tidak memiliki Ponsel!");

	if(Inventory_Count(playerid, "Phone") < 1)
		return ErrorMsg(playerid, "Anda tidak memilik phone!");
	
	if(pData[playerid][pPhoneCredit] <= 0) return Error(playerid, "Anda tidak memiliki Ponsel credits!");
	if(pData[playerid][pInjured] != 0) return Error(playerid, "You cant do at this time.");

	if(GetSignalNearest(playerid) == 0)
		return Error(playerid, "Perangkat anda tidak mendapatkan sinyal di wilayah ini.");
	
	if(sscanf(params, "ds[50]", ph, text))
        return Usage(playerid, "/sms [phone number] [message max 50 text]");
	
	foreach(new ii : Player)
	{
		if(pData[ii][pPhone] == ph)
		{
			if(pData[ii][pUsePhone] == 0) return Error(playerid, "Tidak dapat SMS, Ponsel tersebut yang dituju sedang Offline");

			if(GetSignalNearest(ii) == 0) return Error(playerid, "Ponsel tersebut sedang mengalami gangguan sinyal");

			if(IsPlayerInRangeOfPoint(ii, 20, 2179.9531,-1009.7586,1021.6880))
				return Error(playerid, "Anda tidak dapat melakukan ini, orang yang dituju sedang berada di OOC Zone");

			if(ii == INVALID_PLAYER_ID || !IsPlayerConnected(ii)) return Error(playerid, "This number is not actived!");
			SendClientMessageEx(playerid, COLOR_YELLOW, "[SMS to %d]"WHITE_E" %s", ph, text);
			SendClientMessageEx(ii, COLOR_YELLOW, "[SMS from %d]"WHITE_E" %s", pData[playerid][pPhone], text);
			Info(ii, "Gunakan "LB_E"'@<text>' "WHITE_E"untuk membalas SMS!");
			PlayerPlaySound(ii, 6003, 0,0,0);
			pData[ii][pSMS] = pData[playerid][pPhone];
			
			pData[playerid][pPhoneCredit] -= 1;
			return 1;
		}
	}
	return 1;
}

CMD:setfreq(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	if(Inventory_Count(playerid, "Portable Radio") < 1)
		return ErrorMsg(playerid, "Anda tidak memilik walkie talkie!");
	
	new channel;
	if(sscanf(params, "d", channel))
		return SyntaxMsg(playerid, "/setfreq [channel 1 - 1000]");
	
	if(pData[playerid][pTogWT] == 1) return Error(playerid, "Your walkie talkie is turned off.");
	if(channel == pData[playerid][pWT]) return Error(playerid, "You are already in this channel.");
	
	if(channel > 0 && channel <= 1000)
	{
		foreach(new i : Player)
		{
		    if(pData[i][pWT] == channel)
		    {
				SendClientMessageEx(i, COLOR_LIME, "[WT] "WHITE_E"%s has joined in to this channel!", ReturnName(playerid));
		    }
		}
		Info(playerid, "You have set your walkie talkie channel to "LIME_E"%d", channel);
		pData[playerid][pWT] = channel;
	}
	else
	{
		Error(playerid, "Invalid channel id! 1 - 1000");
	}
	return 1;
}

/*CMD:savestats(playerid, const params[])
{
	UpdateWeapons(playerid);
	UpdatePlayerData(playerid);
	Info(playerid, "Your data have been saved!");
	return 1;
}*/




//------------------[ Bisnis and Buy Commands ]-------
CMD:buy(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	if(IsPlayerInRangeOfPoint(playerid, 2.5, 1996.39, -2065.53, 13.54))
	{
		if(pData[playerid][pDaging] >= 500) return ErrorMsg(playerid, "Anda sudah membawa 500 Daging!");
		new mstr[200];
		format(mstr, sizeof(mstr), ""WHITE_E"Masukan jumlah daging:\nDaging Stock: "GREEN_E"%d\n"WHITE_E"Harga Daging"GREEN_E"%s / item", Daging, FormatMoney(DagingPrice));
		ShowPlayerDialog(playerid, DIALOG_DAGING, DIALOG_STYLE_INPUT, "Beli Daging", mstr, "Buy", "Cancel");
	}
	//Apotek
	if(IsPlayerInRangeOfPoint(playerid, 2.5, -2012.4336, 122.6201, 10027.6240))
	{
		if(pData[playerid][pFaction] != 3)
			return Error(playerid, "Medical only!");
			
		new mstr[200];
		format(mstr, sizeof(mstr), "Product\tPrice\nMedicine\t"GREEN_E"%d\nMedkit\t"GREEN_E"%d\nEphedrine\t"GREEN_E"%d\nBandage\t"GREEN_E"$100", FormatMoney(MedicinePrice), FormatMoney(MedkitPrice), FormatMoney(EphedrinePrice));
		ShowPlayerDialog(playerid, DIALOG_APOTEK, DIALOG_STYLE_TABLIST_HEADERS, "Apotek", mstr, "Buy", "Cancel");
	}
	//Food and Seed
	if(IsPlayerInRangeOfPoint(playerid, 2.5, -382.97, -1426.43, 26.31))
	{
		new mstr[200];
		format(mstr, sizeof(mstr), "Product\tPrice\nFood\t"GREEN_E"%s\nSeed\t"GREEN_E"%s", FormatMoney(FoodPrice), FormatMoney(SeedPrice));
		ShowPlayerDialog(playerid, DIALOG_FOOD, DIALOG_STYLE_TABLIST_HEADERS, "Food", mstr, "Buy", "Cancel");
	}
	//NPC Family
	foreach(new nfid : NPCFam)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, nfData[nfid][nfPosX], nfData[nfid][nfPosY], nfData[nfid][nfPosZ]))
		{
			if(pData[playerid][pLevel] < 3)
				return Error(playerid, "Kamu harus level 3 untuk mengakses ini");
			
			pData[playerid][pGetNPCFAMID] = nfid;
			Npcfam_BuyMenu(playerid, nfid);
		}
	}
	//Buy Vending
	foreach(new venid : Vending)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.5, vmData[venid][venX], vmData[venid][venY], vmData[venid][venZ]))
		{

			if(vmData[venid][venPrice] > pData[playerid][pMoney]) 
				return Error(playerid, "Not enough money, you can't afford this vending.");

			if(strcmp(vmData[venid][venOwner], "-")) 
				return Error(playerid, "Someone already owns this vending.");

			if(pData[playerid][pVip] == 1)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_VendingCount(playerid) + 1 > 2) return Error(playerid, "You can't buy any more vending machine.");
				#endif
			}
			else if(pData[playerid][pVip] == 2)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_VendingCount(playerid) + 1 > 3) return Error(playerid, "You can't buy any more vending machine.");
				#endif
			}
			else if(pData[playerid][pVip] == 3)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_VendingCount(playerid) + 1 > 4) return Error(playerid, "You can't buy any more vending machine.");
				#endif
			}
			else
			{
				#if LIMIT_PER_PLAYER > 0
				if(Player_VendingCount(playerid) + 1 > 1) return Error(playerid, "You can't buy any more vending machine.");
				#endif
			}

			GivePlayerMoneyEx(playerid, -vmData[venid][venPrice]);
			Server_AddMoney(vmData[venid][venPrice]);

			format(vmData[venid][venOwner], MAX_PLAYER_NAME, pData[playerid][pName]);
			vmData[venid][venVisit] = gettime() + (86400 * 30);
			
			Vending_Save(venid);
			Vending_Refresh(venid);
		}
	}
	//Buy Workshop
	foreach(new wid : Workshop)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.5, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
		{

			if(wData[wid][wPrice] > pData[playerid][pMoney]) 
				return Error(playerid, "Not enough money, you can't afford this workshop.");

			if(strcmp(wData[wid][wLeader], "-")) 
				return Error(playerid, "Someone already owns this workshop.");

			if(pData[playerid][pVip] == 1)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_WorkshopCount(playerid) + 1 > 1) return Error(playerid, "You can't buy any more workshop.");
				#endif
			}
			else if(pData[playerid][pVip] == 2)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_WorkshopCount(playerid) + 1 > 1) return Error(playerid, "You can't buy any more workshop.");
				#endif
			}
			else if(pData[playerid][pVip] == 3)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_WorkshopCount(playerid) + 1 > 1) return Error(playerid, "You can't buy any more workshop.");
				#endif
			}
			else
			{
				#if LIMIT_PER_PLAYER > 0
				if(Player_WorkshopCount(playerid) + 1 > 1) return Error(playerid, "You can't buy any more workshop.");
				#endif
			}

			if(pData[playerid][pWorkshop] != -1) 
				return Error(playerid, "Kamu harus keluar dari anggota workshop lain!");

			GivePlayerMoneyEx(playerid, -wData[wid][wPrice]);
			Server_AddMoney(wData[wid][wPrice]);
			format(wData[wid][wLeader], MAX_PLAYER_NAME, pData[playerid][pName]);
			Workshop_Save(wid);
			Workshop_Refresh(wid);

			pData[playerid][pWorkshop] = wid;
			pData[playerid][pWorkshopRank] = 6;
			UpdatePlayerData(playerid);
		}
	}
	//Buy House
	foreach(new hid : Houses)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.5, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]))
		{
			if(hData[hid][hPrice] > pData[playerid][pMoney]) return Error(playerid, "Not enough money, you can't afford this houses.");
			if(strcmp(hData[hid][hOwner], "-")) return Error(playerid, "Someone already owns this house.");
			if(pData[playerid][pVip] == 1)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 2) return Error(playerid, "Kamu tidak dapat membeli rumah lebih.");
				#endif
			}
			else if(pData[playerid][pVip] == 2)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 3) return Error(playerid, "Kamu tidak dapat membeli rumah lebih.");
				#endif
			}
			else if(pData[playerid][pVip] == 3)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 4) return Error(playerid, "Kamu tidak dapat membeli rumah lebih.");
				#endif
			}
			else
			{
				#if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 1) return Error(playerid, "Kamu tidak dapat membeli rumah lebih.");
				#endif
			}
			GivePlayerMoneyEx(playerid, -hData[hid][hPrice]);
			Server_AddMoney(hData[hid][hPrice]);
			format(hData[hid][hOwner], MAX_PLAYER_NAME, pData[playerid][pName]);
			hData[hid][hVisit] = gettime() + (86400 * 30);
			
			House_Refresh(hid);
			House_Save(hid);
		}
	}
	//Buy Private Farmer
	foreach(new pfid : PFarm)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]))
		{
			if(pfData[pfid][pfPrice] > pData[playerid][pMoney]) return Error(playerid, "Not enough money, you can't afford this private farmer.");
			if(strcmp(pfData[pfid][pfOwner], "-")) return Error(playerid, "Someone already owns this private farmer.");
			if(pData[playerid][pVip] == 1)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_PfarmCount(playerid) + 1 > 2) return Error(playerid, "Anda tidak dapat membeli private farmer lagi.");
				#endif
			}
			else if(pData[playerid][pVip] == 2)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_PfarmCount(playerid) + 1 > 3) return Error(playerid, "Anda tidak dapat membeli private farmer lagi.");
				#endif
			}
			else if(pData[playerid][pVip] == 3)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_PfarmCount(playerid) + 1 > 4) return Error(playerid, "Anda tidak dapat membeli private farmer lagi.");
				#endif
			}
			else
			{
				#if LIMIT_PER_PLAYER > 0
				if(Player_PfarmCount(playerid) + 1 > 1) return Error(playerid, "Anda tidak dapat membeli private farmer lagi.");
				#endif
			}
			GivePlayerMoneyEx(playerid, -pfData[pfid][pfPrice]);
			Server_AddMoney(-pfData[pfid][pfPrice]);
			format(pfData[pfid][pfOwner], MAX_PLAYER_NAME, pData[playerid][pName]);
			pfData[pfid][pfVisit] = gettime() + (86400 * 30);
			
			Pfarm_Refresh(pfid);
			Pfarm_Save(pfid);
		}
	}
	//Buy Dealer
	foreach(new deid : Dealer)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, drData[deid][dPosX], drData[deid][dPosY], drData[deid][dPosZ]))
		{
			if(drData[deid][dPrice] > pData[playerid][pMoney]) return Error(playerid, "Not enough money, you can't afford this dealer.");
			if(strcmp(drData[deid][dOwner], "-")) return Error(playerid, "Someone already owns this dealer.");
			if(pData[playerid][pVip] == 1)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_DealerCount(playerid) + 1 > 2) return Error(playerid, "Anda tidak dapat membeli dealer lagi.");
				#endif
			}
			else if(pData[playerid][pVip] == 2)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_DealerCount(playerid) + 1 > 3) return Error(playerid, "Anda tidak dapat membeli dealer lagi.");
				#endif
			}
			else if(pData[playerid][pVip] == 3)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_DealerCount(playerid) + 1 > 4) return Error(playerid, "Anda tidak dapat membeli dealer lagi.");
				#endif
			}
			else
			{
				#if LIMIT_PER_PLAYER > 0
				if(Player_DealerCount(playerid) + 1 > 1) return Error(playerid, "Anda tidak dapat membeli dealer lagi.");
				#endif
			}
			GivePlayerMoneyEx(playerid, -drData[deid][dPrice]);
			Server_AddMoney(-drData[deid][dPrice]);
			format(drData[deid][dOwner], MAX_PLAYER_NAME, pData[playerid][pName]);
			drData[deid][dVisit] = gettime() + (86400 * 30);
			
			Dealer_Refresh(deid);
			Dealer_Save(deid);
		}
	}
	return 1;
}

CMD:licenses(playerid, const params[])
{
	new String[512], text1[1401], text2[1401], text4[1401];
	if(pData[playerid][pDriveLic]) { text1 = "{FFFFFF}[{00BF00}Passed{FFFFFF}]"; } else { text1 = "{FFFFFF}[{FFF00F}Not Passed{FFFFFF}]"; }
	if(pData[playerid][pTruckLic]) { text4 = "{FFFFFF}[{00BF00}Passed{FFFFFF}]"; } else { text4 = "{FFFFFF}[{FFF00F}Not Passed{FFFFFF}]"; }
	if(pData[playerid][pLumberLic]) { text2 = "{FFFFFF}[{00BF00}Passed{FFFFFF}]"; } else { text2 = "{FFFFFF}[{FFF00F}Not Passed{FFFFFF}]"; }
	SendClientMessageEx(playerid, COLOR_RED, "========Your Licenses========");
	format(String, sizeof(String), "{FFFFFF}** Driver's license: %s.", text1);
	SendClientMessageEx(playerid, COLOR_WHITE, String);
	format(String, sizeof(String), "{FFFFFF}** Truck license: %s.", text4);
	SendClientMessageEx(playerid, COLOR_WHITE, String);
	format(String, sizeof(String), "{FFFFFF}** Lumber Jack license: %s.", text2);
	SendClientMessageEx(playerid, COLOR_WHITE, String);
	SendClientMessageEx(playerid, COLOR_RED, "=============================");
	SendClientMessage(playerid, COLOR_RED, "NOTE: {FFFFFF}use '/showlic' to show licenses to other player!");
	return 1;
}

CMD:showlic(playerid, const params[])
{
	new String[512], text1[1401], text2[1401], text3[1401], text4[1401];
	if(pData[playerid][pDriveLic]) 
	{ 
		text1 = "{FFFFFF}[{00BF00}Passed{FFFFFF}]"; 
	} 
	else 
	{ 
		text1 = "{FFFFFF}[{FFF00F}Not Passed{FFFFFF}]"; 
	}

	if(pData[playerid][pWeapLic]) 
	{ 
		text2 = "{FFFFFF}[{00BF00}Passed{FFFFFF}]"; 
	} 
	else 
	{ 
		text2 = "{FFFFFF}[{FFF00F}Not Passed{FFFFFF}]"; 
	}

	if(pData[playerid][pTruckLic]) 
	{ 
		text3 = "{FFFFFF}[{00BF00}Passed{FFFFFF}]"; 
	} 
	else 
	{ 
		text3 = "{FFFFFF}[{FFF00F}Not Passed{FFFFFF}]"; 
	}

	if(pData[playerid][pLumberLic]) 
	{ 
		text4 = "{FFFFFF}[{00BF00}Passed{FFFFFF}]"; 
	} 
	else 
	{ 
		text4 = "{FFFFFF}[{FFF00F}Not Passed{FFFFFF}]"; 
	}
	SendNearbyMessage(playerid, 20.0, COLOR_YELLOW, "========Licenses========");
	format(String, sizeof(String), "{FFFFFF}** Driver's license: %s.", text1);
	SendNearbyMessage(playerid, 20.0, COLOR_WHITE, String);
	format(String, sizeof(String), "{FFFFFF}** Weapon's license: %s.", text2);
	SendNearbyMessage(playerid, 20.0, COLOR_WHITE, String);
	format(String, sizeof(String), "{FFFFFF}** Truck license: %s.", text3);
	SendNearbyMessage(playerid, 20.0, COLOR_WHITE, String);
	format(String, sizeof(String), "{FFFFFF}** Lumber Jack license: %s.", text4);
	SendNearbyMessage(playerid, 20.0, COLOR_WHITE, String);
	SendNearbyMessage(playerid, 20.0, COLOR_YELLOW, "==========================");
	return 1;
}

CMD:jobcenter(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 2.0, 1488.3700, -1791.3699, -34.8809))
	{
		ShowPlayerDialog(playerid, DIALOG_JOBCENTER, DIALOG_STYLE_LIST, "Disnaker", "Job 1\nJob 2 (VIP)", "Select", "Close");
	}
	return 1;
}

CMD:balkotcenter(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 2.0, 1488.1105, -1783.8051, -34.8809))
	{
		ShowPlayerDialog(playerid, DIALOG_BALKOT, DIALOG_STYLE_LIST, "Balai Kota", "Membuat ID Card\nMengubah Tanggal Lahir\nJual Rumah Pribadi\nJual Dealer Pribadi\nBayar Pajak", "Select", "Close");
	}
	return 1;
}

CMD:menufarmer(playerid, const params[])
{
	//Food and Seed
	if(IsPlayerInRangeOfPoint(playerid, 3.5, -382.97, -1426.43, 26.31))
	{
		new mstr[128];
		format(mstr, sizeof(mstr), "Product\n\
		Buy Food\n\
		Buy Seed\n\
		Buy Gandum\n\
		");
		ShowPlayerDialog(playerid, DIALOG_FOOD, DIALOG_STYLE_TABLIST_HEADERS, "Job Farmer", mstr, "Select", "Cancel");
	}
	else return ErrorMsg(playerid, "Kamu tidak di penjualan atau pembelian farmer");
	return 1;
}



CMD:buyveh(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 1097.9308, -1765.0497, 13.3841)) return Error(playerid, "Anda harus berada di showroom kendaraan LTRP!");
	{
		ShowPlayerDialog(playerid, DIALOG_BUY_VEHICLE, DIALOG_STYLE_LIST, "DEALER KENDARAAN - {004BFF}ANDIKA", "BELI KENDARAAN\nRENTAL KENDARAAN", "Select", "Cancel");
	} 
	return 1;
}

CMD:fixme(playerid, const params[])
{
	if(pData[playerid][pSpawned])
	{
		new str[128];
		format(str, sizeof(str), "{FF0000}Wrong Virtual World {FFFFFF}(Bug Visual)\nStuck\nTiba-tiba mati");
		ShowPlayerDialog(playerid, DIALOG_FIXME, DIALOG_STYLE_LIST, "MENU FIX", str, "Select", "Close");
	}
	return 1;
}

CMD:cursor(playerid, const params[])
{
	SelectTextDraw(playerid, SERVER_TEXTDRAW_COLOR);
	SuccesMsg(playerid, "Cursor berhasil di tampilkan");
	return 1;
}

CMD:fcrash(playerid, const params[])
{
	Info(playerid, "Bapak kau kontol nya panjang");
	KickEx(playerid);
	return 1;
}

CMD:skema(playerid, const params[])
{
	Info(playerid, "Bapak kau kontol nya panjang");
	KickEx(playerid);
	return 1;
}

CMD:ror(playerid, const params[])
{
	Info(playerid, "Bapak kau kontol nya panjang");
	KickEx(playerid);
	return 1;
}

CMD:ro(playerid, const params[])
{
	Info(playerid, "Bapak kau kontol nya panjang");
	KickEx(playerid);
	return 1;
}

CMD:medic(playerid, const params[])
{
    if(pData[playerid][pInjured] == 0)
        return ErrorMsg(playerid, "Anda belum injured.");
		
	if(pData[playerid][pJail] > 0)
		return ErrorMsg(playerid, "Anda tidak dapat menggunakan ini saat diJail!");
		
	if(pData[playerid][pArrest] > 0)
		return ErrorMsg(playerid, "Kamu tidak dapat melakukan ini saat tertangkap polisi!");

	if(CountFaction(3) > 0)
		return InfoTD_MSG(playerid, 4000, "Masih ada Medic di kota, gunakan ~y~Y");


	ShowProgressbar(playerid, "Reviving...", 10);
	SetTimerEx("mediclocal", 10000, false, "d", playerid);

	return 1;
}

CMD:sm(playerid, const params[])
{

	new sapdOnDuty = 0;
    new samdOnDuty = 0;

    for (new i = 0; i < MAX_PLAYERS; i++)
    {
        if (IsPlayerConnected(i))
        {
            if (pData[i][pFaction] == 1 && pData[i][pOnDuty]) // Faction ID untuk SAPD
            {
                sapdOnDuty++;
            }
            else if (pData[i][pFaction] == 3 && pData[i][pOnDuty]) // Faction ID untuk SAMD
            {
                samdOnDuty++;
            }
        }
    }

	new status[50];
	if(sapdOnDuty > 2 && samdOnDuty > 1)
	{
		status = "{00FF00}Open";
	}
	else
	{
		status = "{FF0000}Close";
	}

	new statusrobbank[50];
	if(sapdOnDuty > 7 && samdOnDuty > 5)
	{
		statusrobbank = "{00FF00}Open";
	}
	else
	{
		statusrobbank = "{FF0000}Close";
	}

	new statuswar[50];
	if(sapdOnDuty > 10 && samdOnDuty > 5)
	{
		statuswar = "{00FF00}Open";
	}
	else
	{
		statuswar = "{FF0000}Close";
	}

	new ZENN[10000], String[10000];
	strcat(ZENN, "Roleplay\tFaction\tStatus\n");
	format(String, sizeof(String), "Robbery/Scamming\t2 SAPD & 1 SAMD\t%s\n", status);// 596
	strcat(ZENN, String);
	format(String, sizeof(String), "Crafting/Field\t2 SAPD & 1 SAMD\t%s\n", status);// 596
	strcat(ZENN, String);
	format(String, sizeof(String), "Car Steal\t2 SAPD & 1 SAMD\t%s\n", status);// 596
	strcat(ZENN, String);
	format(String, sizeof(String), "Rampok Warung\t2 SAPD & 1 SAMD\t%s\n", status); // 599
	strcat(ZENN, String);
	format(String, sizeof(String), "Rampok Bank\t7 SAPD & 5 SAMD\t%s\n", statusrobbank); // 601
	strcat(ZENN, String);
	format(String, sizeof(String), "Peperangan\t10 SAPD & 5 EMS\t%s\n", statuswar); // 427
	strcat(ZENN, String);
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS,"Local Prime Roleplay - Status Mendung", ZENN, "Close","");
	return 1;
}

CMD:r(playerid, const params[])
{
	if(Inventory_Count(playerid, "Portable Radio") < 1)
		return ErrorMsg(playerid, "Anda tidak memiliki Radio");

	SelectTextDraw(playerid, COLOR_GREY);
	CallRemoteFunction("OnPlayerUseRadio", "i", playerid);
	return 1;
}

CMD:skateoff(playerid, const params[])
{
	if(InfoSkate[playerid][sActive])
	{
		InfoSkate[playerid][sActive] = false;
		DestroyObject(InfoSkate[playerid][sSkate]);
		RemovePlayerAttachedObject(playerid,INDEX_SKATE);
		PlayerPlaySound(playerid,21000,0,0,0);
	}
	return 1;
}
