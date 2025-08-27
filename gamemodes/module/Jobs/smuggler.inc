/*CreateJoinDrugDealer()
{
	new strings[254];

	//JOIN JOB
	CreateDynamicPickup(1239, 23, 2989.5288, 2762.0352, -0.5533, -1);
	format(strings, sizeof(strings), "Drug Dealer\n{FFFFFF}/joinjob - to get drug dealer job");
	CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2165.21, -1673.13, 15.07, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); 

	//DRUG SMUGGLING
	CreateDynamicPickup(1575, 23, 51.96, -292.28, 1.70, -1);
	format(strings, sizeof(strings), "Drug Smuggling\n"WHITE_E"Cost: $500\n/smuggledrugs [ephedrine/cocaine]");
	CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 51.96, -292.28, 1.70+0.2, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); 

	//COOK METH
	CreateDynamicPickup(1577, 23, 1.21, 2.80, 999.42, -1);
	format(strings, sizeof(strings), "Cooking Meth"WHITE_E"\nRequires ephedrine\n/cookmeth - to begin cooking.");
	CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 1.21, 2.80, 999.42+0.2, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
}*/

CMD:buycocaine(playerid, params[])
{
	new ammount;

	if(!IsPlayerInRangeOfPoint(playerid, 3.5, 870.3434, -25.2242, 63.9634))
		return 1;

	if(sscanf(params, "d", ammount))
		return SyntaxMsg(playerid, "/buycocaine [jumlah]");

	if(ammount * CocainePrice > pData[playerid][pMoney])
		return ErrorMsg(playerid, "Uang anda tidak mencukupi");

	if(ammount <= 0)
		return ErrorMsg(playerid, "Jumlah harus diatas 0");

	if(ammount > Cocaine)
		return ErrorMsg(playerid, "Jumlah stok cocaine tidak mencukupi");

	Inventory_Add(playerid, "Cocaine", 1580, ammount);
	Cocaine -= ammount;
	GivePlayerMoneyEx(playerid, -ammount * CocainePrice);
	Server_AddMoney(ammount * CocainePrice);
	Info(playerid, "Anda berhasil membeli %d cocaine dengan harga %s", ammount, FormatMoney(CocainePrice * ammount));
	SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s membeli %d cocaine dengan harga %s", ReturnName(playerid), ammount,  FormatMoney(CocainePrice * ammount));
	return 1;
}


/*CMD:buydrugs(playerid, params[])
{
	if(pData[playerid][pJobTime] > 0) 
		return Error(playerid, "Anda harus menunggu "GREY2_E"%d "WHITE_E"detik untuk bisa bekerja kembali.", pData[playerid][pJobTime]);
	
	if(pData[playerid][pJob] == 12 || pData[playerid][pJob2] == 12)
	{
		new type[128], ammount;
		if(sscanf(params, "s[128]d", type, ammount))
			return Usage(playerid, "/buydrug [ephedrine/cocaine] [ammount]");

		if(!strcmp(type, "ephedrine", true))
		{
			if(!IsPlayerInRangeOfPoint(playerid, 3.5, 323.81, 1117.20, 1083.88))
				return Error(playerid, "Kamu tidak berada di dekat point pembelian ephedrine");

			if(ammount * EphedrinePrice > pData[playerid][pMoney])
			 	return Error(playerid, "Uang kamu tidak mencukupi");

			if(ammount <= 0)
			 	return Error(playerid, "jumlah harus diatas 0!");

			if(ammount > Ephedrine)
				return Error(playerid, "Jumlah stok ephedrine tidak mencukupi");

			Inventory_Add(playerid, "Ephedrine", 1580, ammount);
			Ephedrine -= ammount;
			GivePlayerMoneyEx(playerid, -ammount * EphedrinePrice);
			Server_AddMoney(ammount * EphedrinePrice);
			Info(playerid, "Kamu berhasil membeli %d ephedrine dengan harga %s", ammount, FormatMoney(EphedrinePrice * ammount));
			SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s membeli %d raw ephedrine dengan harga %s", ReturnName(playerid), ammount, FormatMoney(EphedrinePrice * ammount));
		}
		else if(!strcmp(type, "cocaine", true))
		{
			if(!IsPlayerInRangeOfPoint(playerid, 3.5, 2342.76, -1186.81, 1027.97))
				return Error(playerid, "Kamu tidak berada di dekat point pembelian cocaine");

			if(ammount * CocainePrice > pData[playerid][pMoney])
			 	return Error(playerid, "Uang kamu tidak mencukupi");

			if(ammount <= 0)
			 	return Error(playerid, "jumlah harus diatas 0!");

			if(ammount > Cocaine)
				return Error(playerid, "Jumlah stok cocaine tidak mencukupi");

			Inventory_Add(playerid, "Cocaine", 1580, ammount);
			Cocaine -= ammount;
			GivePlayerMoneyEx(playerid, -ammount * CocainePrice);
			Server_AddMoney(ammount * CocainePrice);
			Info(playerid, "Kamu berhasil membeli %d cocaine dengan harga %s", ammount, FormatMoney(CocainePrice * ammount));
			SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s membeli %d cocaine dengan harga %s", ReturnName(playerid), ammount,  FormatMoney(CocainePrice * ammount));
		}
	}
	else return Error(playerid, "Kamu bukan pekerja drug dealer");
	return 1;
}*/

/*CMD:smuggledrugs(playerid, params[])
{
	if(pData[playerid][pJob] == 12 || pData[playerid][pJob2] == 12)
	{
		if(pData[playerid][pDrugDealer] != 0)
			return Error(playerid, "Kamu masih memiliki paket yang belum diantar");

		if(!IsPlayerInRangeOfPoint(playerid, 3.5, 51.96, -292.28, 1.70))
			return Error(playerid, "Kamu tidak berada didekat point drug smuggling");
		
		new type[128];
		if(sscanf(params, "s[128]", type))
			return Usage(playerid, "/smuggledrugs [ephedrine/cocaine]");

		if(500 > pData[playerid][pMoney])
			return Error(playerid, "Kamu harus memegang $500 ditanganmu");

		if(!strcmp(type, "ephedrine", true))
		{
			if(Ephedrine > 500)
				return Error(playerid, "Stok Raw Ephedrine digudang sudah penuh");

			pData[playerid][pDrugDealer] = 2;
			GivePlayerMoneyEx(playerid, -500);
			SetPlayerCheckpoint(playerid, 2167.21, -1672.69, 15.07, 3.5);
			Info(playerid, "Kamu telah mengambil paket smuggling Raw Ephedrine dengan harga $500");
			Info(playerid, "Antar menuju checkpoint yang telah ditandai");
		}
		else if(!strcmp(type, "cocaine", true))
		{
			if(Cocaine > 500)
				return Error(playerid, "Stok cocaine digudang sudah penuh");

			pData[playerid][pDrugDealer] = 3;
			GivePlayerMoneyEx(playerid, -500);
			SetPlayerCheckpoint(playerid, 2351.82, -1168.90, 27.98, 3.5);
			Info(playerid, "Kamu telah mengambil paket smuggling cocaine dengan harga $500");
			Info(playerid, "Antar menuju checkpoint yang telah ditandai");
		}
	}
	else return Error(playerid, "Kamu bukan pekerja drug dealer");
	return 1;
}*/

CMD:cookmeth(playerid, params[])
{
	if(pData[playerid][pJob] == 12 || pData[playerid][pJob2] == 12)
	{
		if(IsValidLoadingBar(playerid)) 
			return InfoTD_MSG(playerid, 4000, "Anda masih memiliki ~y~ProgressBar~w~, silahkan tunggu");
		if(!IsPlayerInRangeOfPoint(playerid, 3.5, 1.21, 2.80, 999.42))
			return ErrorMsg(playerid, "Anda sedang tidak berada di cookmeth point");

		if(Inventory_Count(playerid, "Muriatic") <= 0 || Inventory_Count(playerid, "Ephedrine") < 2)
			return ErrorMsg(playerid, "Kamu membutuhkan 1 muriatic acid & 2 ephedrine untuk membuat meth");

		if(pData[playerid][pActivityTime] > 5)
			return ErrorMsg(playerid, "Anda masih memiliki activity progress!");

		TogglePlayerControllable(playerid, 0);
		ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
		pData[playerid][pMethBar] = SetTimerEx("CookMeth", 10000, false, "d", playerid);
		ShowProgressbar(playerid, "Cooking...", 10);
	}
	else return ErrorMsg(playerid, "Kamu bukan pekerja drug dealer");
	return 1;
}

function CookMeth(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pJob] == 12 || pData[playerid][pJob2] == 12)
	{
		{
			TogglePlayerControllable(playerid, 1);
			clearAnimations(playerid);
			InfoMsg(playerid, "Meth +1");
			SuccesMsg(playerid, "Berhasil membuat 1kg meth!");

			Inventory_Remove(playerid, "Muriatic", 1);
			Inventory_Remove(playerid, "Ephedrine", 2);
			Inventory_Add(playerid, "Meth", 1580, 1);
		}
	}
	return 1;
}