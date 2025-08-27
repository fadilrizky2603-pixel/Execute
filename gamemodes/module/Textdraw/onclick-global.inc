public OnClickDynamicTextDraw(playerid, Text:textid)
{
	if(pData[playerid][pVtoySelect] != -1 && pData[playerid][pGetVTOYID] != -1)
	{
		new vehicleid = pData[playerid][pGetVTOYID], slotid = pData[playerid][pVtoySelect];
		if(textid == ModTD[0])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtX]+0.1;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);
			
			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				posisi, 
				vToys[vehicleid][slotid][vtY], 
				vToys[vehicleid][slotid][vtZ], 
				vToys[vehicleid][slotid][vtRX], 
				vToys[vehicleid][slotid][vtRY], 
				vToys[vehicleid][slotid][vtRZ]);

			vToys[vehicleid][slotid][vtX] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[1])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtX]-0.1;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				posisi, 
				vToys[vehicleid][slotid][vtY], 
				vToys[vehicleid][slotid][vtZ], 
				vToys[vehicleid][slotid][vtRX], 
				vToys[vehicleid][slotid][vtRY], 
				vToys[vehicleid][slotid][vtRZ]);

			vToys[vehicleid][slotid][vtX] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[2])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtY]+0.1;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				vToys[vehicleid][slotid][vtX], 
				posisi, 
				vToys[vehicleid][slotid][vtZ], 
				vToys[vehicleid][slotid][vtRX], 
				vToys[vehicleid][slotid][vtRY], 
				vToys[vehicleid][slotid][vtRZ]);

			vToys[vehicleid][slotid][vtY] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[3])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtY]-0.1;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				vToys[vehicleid][slotid][vtX], 
				posisi, 
				vToys[vehicleid][slotid][vtZ], 
				vToys[vehicleid][slotid][vtRX], 
				vToys[vehicleid][slotid][vtRY], 
				vToys[vehicleid][slotid][vtRZ]);

			vToys[vehicleid][slotid][vtY] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[4])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtZ]+0.1;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				vToys[vehicleid][slotid][vtX], 
				vToys[vehicleid][slotid][vtY], 
				posisi, 
				vToys[vehicleid][slotid][vtRX], 
				vToys[vehicleid][slotid][vtRY], 
				vToys[vehicleid][slotid][vtRZ]);

			vToys[vehicleid][slotid][vtZ] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[5])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtZ]-0.1;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				vToys[vehicleid][slotid][vtX], 
				vToys[vehicleid][slotid][vtY], 
				posisi, 
				vToys[vehicleid][slotid][vtRX], 
				vToys[vehicleid][slotid][vtRY], 
				vToys[vehicleid][slotid][vtRZ]);

			vToys[vehicleid][slotid][vtZ] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}

		else if(textid == ModTD[6])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtRX]+22.5;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				vToys[vehicleid][slotid][vtX], 
				vToys[vehicleid][slotid][vtY], 
				vToys[vehicleid][slotid][vtZ], 
				posisi, 
				vToys[vehicleid][slotid][vtRY], 
				vToys[vehicleid][slotid][vtRZ]);

			vToys[vehicleid][slotid][vtRX] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[7])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtRX]-22.5;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				vToys[vehicleid][slotid][vtX], 
				vToys[vehicleid][slotid][vtY], 
				vToys[vehicleid][slotid][vtZ], 
				posisi, 
				vToys[vehicleid][slotid][vtRY], 
				vToys[vehicleid][slotid][vtRZ]);

			vToys[vehicleid][slotid][vtRX] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[8])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtRY]+22.5;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				vToys[vehicleid][slotid][vtX], 
				vToys[vehicleid][slotid][vtY], 
				vToys[vehicleid][slotid][vtZ], 
				vToys[vehicleid][slotid][vtRX], 
				posisi, 
				vToys[vehicleid][slotid][vtRZ]);

			vToys[vehicleid][slotid][vtRY] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[9])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtRY]-22.5;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				vToys[vehicleid][slotid][vtX], 
				vToys[vehicleid][slotid][vtY], 
				vToys[vehicleid][slotid][vtZ], 
				vToys[vehicleid][slotid][vtRX], 
				posisi, 
				vToys[vehicleid][slotid][vtRZ]);

			vToys[vehicleid][slotid][vtRY] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[10])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtRZ]+22.5;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				vToys[vehicleid][slotid][vtX], 
				vToys[vehicleid][slotid][vtY], 
				vToys[vehicleid][slotid][vtZ], 
				vToys[vehicleid][slotid][vtRX], 
				vToys[vehicleid][slotid][vtRY], 
				posisi);

			vToys[vehicleid][slotid][vtRZ] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[11])
		{
			new Float:posisi = vToys[vehicleid][slotid][vtRZ]-22.5;

			if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
				DestroyObject(vToys[vehicleid][slotid][vtObj]);

			vToys[vehicleid][slotid][vtObj] = CreateObject(vToys[vehicleid][slotid][vtModelid], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0);

			AttachObjectToVehicle(vToys[vehicleid][slotid][vtObj], 
				vehicleid,
				vToys[vehicleid][slotid][vtX], 
				vToys[vehicleid][slotid][vtY], 
				vToys[vehicleid][slotid][vtZ], 
				vToys[vehicleid][slotid][vtRX], 
				vToys[vehicleid][slotid][vtRY], 
				posisi);

			vToys[vehicleid][slotid][vtRZ] = posisi;

			SetPVarInt(vehicleid, "UpdatedVtoy", 1);
		}
		else if(textid == ModTD[18])
		{
			for(new i = 0; i < 19; i++)
			{
				TextDrawHideForPlayer(playerid, ModTD[i]);
			}

			//Clear Edit Progress
			CancelSelectTextDraw(playerid);
			TogglePlayerControllable(playerid, 1);
			MySQL_SaveVehicleToys(vehicleid);
			
			PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);

			pData[playerid][pGetVTOYID] = -1;
			pData[playerid][pVtoySelect] = -1;

			InfoTD_MSG(playerid, 4000, "~g~~h~Vehicle Toy Position Updated~y~!");
		}
	}
	if(textid == AtmKeluar)
	{
        HideAtm(playerid);
	    ApplyAnimation(playerid, "CRIB", "CRIB_Use_Switch",4.0,0,0,0,0,0), PlayerPlaySound(playerid, 4203, 0,0,0);
	}
	if(textid == AtmWD)
	{
        new str[512];
		format(str, sizeof(str), ""WHITE_E"Bank Money: "GREEN_LIGHT"%s\n\n"WHITE_E"Masukan jumlah uang yang ingin kamu withdraw:", FormatMoney(pData[playerid][pBankMoney]));
		ShowPlayerDialog(playerid, DIALOG_ATMWITHDRAW, DIALOG_STYLE_INPUT, "Atm Withdraw", str, "Withdraw", "Cancel");
		ApplyAnimation(playerid, "CRIB", "CRIB_Use_Switch",4.0,0,0,0,0,0), PlayerPlaySound(playerid, 4203, 0,0,0);
	}
	if(textid == AtmDepo)
	{
	    new mstr[512];
		format(mstr, sizeof(mstr), "{F6F6F6}You have "LB_E"%s {F6F6F6}in bank account.\n\nType in the amount you want to deposit below:", FormatMoney(pData[playerid][pBankMoney]));
		ShowPlayerDialog(playerid, DIALOG_BANKDEPOSIT, DIALOG_STYLE_INPUT, ""LB_E"Atm", mstr, "Deposit", "Cancel");
		ApplyAnimation(playerid, "CRIB", "CRIB_Use_Switch",4.0,0,0,0,0,0), PlayerPlaySound(playerid, 4203, 0,0,0);
	}
	if(textid == AtmTF)
	{
	    ShowPlayerDialog(playerid, DIALOG_ATMREKENING, DIALOG_STYLE_INPUT, ""LB_E"Bank", "Masukan jumlah uang:", "Transfer", "Cancel");
		ApplyAnimation(playerid, "CRIB", "CRIB_Use_Switch",4.0,0,0,0,0,0), PlayerPlaySound(playerid, 4203, 0,0,0);
	}
	if(textid == AtmPay)
	{
	    DisplayPaycheck(playerid);
	}
	/*if(textid == AtmLima)
	{
		new amount = 5000;
	    if(pData[playerid][pBankMoney] < amount)
		{
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Atm Withdraw", "Saldo ATM anda tidak mencukupi!", "Close", "");
			return 1;
		}
		if(amount > AtmData[id][atmStock])
		{
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Atm Withdraw", "Stock ATM tidak mencukupi!", "Close", "");
			return 1;
		}

		pData[playerid][pBankMoney] -= amount;
		AtmData[id][atmStock] -= amount;
			
		GivePlayerMoneyEx(playerid, amount);
		SendNearbyMessage(playerid, 15.0, COLOR_PURPLE,  "** %s menarik uang sejumlah %s dari mesin atm", ReturnName(playerid), FormatMoney(amount));
	}
	if(textid == AtmSepuluh)
	{
	    new amount = 10000;
	    if(pData[playerid][pBankMoney] < amount)
		{
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Atm Withdraw", "Saldo ATM anda tidak mencukupi!", "Close", "");
			return 1;
		}
		if(amount > AtmData[id][atmStock])
		{
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Atm Withdraw", "Stock ATM tidak mencukupi!", "Close", "");
			return 1;
		}

		pData[playerid][pBankMoney] -= amount;
		AtmData[id][atmStock] -= amount;
			
		GivePlayerMoneyEx(playerid, amount);
		SendNearbyMessage(playerid, 15.0, COLOR_PURPLE,  "** %s menarik uang sejumlah %s dari mesin atm", ReturnName(playerid), FormatMoney(amount));
	}
	if(textid == AtmSatuLima)
	{
	    new amount = 15000;
	    if(pData[playerid][pBankMoney] < amount)
		{
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Atm Withdraw", "Saldo ATM anda tidak mencukupi!", "Close", "");
			return 1;
		}
		if(amount > AtmData[id][atmStock])
		{
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Atm Withdraw", "Stock ATM tidak mencukupi!", "Close", "");
			return 1;
		}

		pData[playerid][pBankMoney] -= amount;
		AtmData[id][atmStock] -= amount;
			
		GivePlayerMoneyEx(playerid, amount);
		SendNearbyMessage(playerid, 15.0, COLOR_PURPLE,  "** %s menarik uang sejumlah %s dari mesin atm", ReturnName(playerid), FormatMoney(amount));
	}
	if(textid == AtmDuapuluh)
	{
	    new amount = 20000;
	    if(pData[playerid][pBankMoney] < amount)
		{
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Atm Withdraw", "Saldo ATM anda tidak mencukupi!", "Close", "");
			return 1;
		}
		if(amount > AtmData[id][atmStock])
		{
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Atm Withdraw", "Stock ATM tidak mencukupi!", "Close", "");
			return 1;
		}

		pData[playerid][pBankMoney] -= amount;
		AtmData[id][atmStock] -= amount;
			
		GivePlayerMoneyEx(playerid, amount);
		SendNearbyMessage(playerid, 15.0, COLOR_PURPLE,  "** %s menarik uang sejumlah %s dari mesin atm", ReturnName(playerid), FormatMoney(amount));
	}
	if(textid == AtmDuaLima)
	{
	    new amount = 25000;
	    if(pData[playerid][pBankMoney] < amount)
		{
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Atm Withdraw", "Saldo ATM anda tidak mencukupi!", "Close", "");
			return 1;
		}
		if(amount > AtmData[id][atmStock])
		{
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Atm Withdraw", "Stock ATM tidak mencukupi!", "Close", "");
			return 1;
		}

		pData[playerid][pBankMoney] -= amount;
		AtmData[id][atmStock] -= amount;
			
		GivePlayerMoneyEx(playerid, amount);
		SendNearbyMessage(playerid, 15.0, COLOR_PURPLE,  "** %s menarik uang sejumlah %s dari mesin atm", ReturnName(playerid), FormatMoney(amount));
	}*/
	//BAJU SYSTEM
	if(textid == ListBaju[2])//exit
	{
	    SetPlayerSkin(playerid, pData[playerid][pSkin]);
        for(new i = 0; i < 8; i++)
		{
			TextDrawHideForPlayer(playerid, SelectBaju[i]);
		}
		for(new xx = 0; xx < 6; xx++)
		{
			TextDrawHideForPlayer(playerid, ListBaju[xx]);
		}
		CancelSelectTextDraw(playerid);
	}
	if(textid == ListBaju[0])//baju
	{
	    for(new i = 0; i < 8; i++)
		{
			TextDrawShowForPlayer(playerid, SelectBaju[i]);
		}
	}
	if(textid == ListBaju[1])//aksesoris
	{
	    for(new i = 0; i < 8; i++)
		{
			TextDrawHideForPlayer(playerid, SelectBaju[i]);
		}
		for(new xx = 0; xx < 6; xx++)
		{
			TextDrawHideForPlayer(playerid, ListBaju[xx]);
		}
		CancelSelectTextDraw(playerid);
	    new string[248];
		if(pToys[playerid][0][toy_model] == 0)
		{
			strcat(string, ""dot"Slot 1\n");
		}
		else strcat(string, ""dot"Slot 1 "RED_E"(Used)\n");

		if(pToys[playerid][1][toy_model] == 0)
		{
			strcat(string, ""dot"Slot 2\n");
		}
		else strcat(string, ""dot"Slot 2 "RED_E"(Used)\n");

		if(pToys[playerid][2][toy_model] == 0)
		{
			strcat(string, ""dot"Slot 3\n");
		}
		else strcat(string, ""dot"Slot 3 "RED_E"(Used)\n");

		if(pToys[playerid][3][toy_model] == 0)
		{
			strcat(string, ""dot"Slot 4\n");
		}
		else strcat(string, ""dot"Slot 4 "RED_E"(Used)\n");
		ShowPlayerDialog(playerid, DIALOG_TOYBUY, DIALOG_STYLE_LIST, "OLD CITY- Aksesoris", string, "Pilih", "Batal");
	}
	if(textid == SelectBaju[0])//kiri
	{
	    cskin[playerid]--;
		if(pData[playerid][pVip] < 1)
		{
			if(pData[playerid][pGender] == 1)
			{
				if(cskin[playerid] < 0) cskin[playerid] = sizeof ShopSkinMale - 1;
				SetPlayerSkin(playerid, ShopSkinMale[cskin[playerid]]);
			}
			else
			{
				if(cskin[playerid] < 0) cskin[playerid] = sizeof ShopSkinFemale - 1;
				SetPlayerSkin(playerid, ShopSkinFemale[cskin[playerid]]);
			}
		} else {
			if(pData[playerid][pGender] == 1)
			{
				if(cskin[playerid] < 0) cskin[playerid] = sizeof VipSkinMale - 1;
				SetPlayerSkin(playerid, VipSkinMale[cskin[playerid]]);
			}
			else
			{
				if(cskin[playerid] < 0) cskin[playerid] = sizeof VipSkinFemale - 1;
				SetPlayerSkin(playerid, VipSkinFemale[cskin[playerid]]);
			}
		}
		return 1;
	}
	if(textid == SelectBaju[1])//kanan
	{
	    cskin[playerid]++;
		if(pData[playerid][pVip] < 1)
		{
			if(pData[playerid][pGender] == 1)
			{
				if(cskin[playerid] >= sizeof ShopSkinMale) cskin[playerid] = 0;
				SetPlayerSkin(playerid, ShopSkinMale[cskin[playerid]]);
			}
			else
			{
				if(cskin[playerid] >= sizeof ShopSkinFemale) cskin[playerid] = 0;
				SetPlayerSkin(playerid, ShopSkinFemale[cskin[playerid]]);
			}
		} else {
			if(pData[playerid][pGender] == 1)
			{
				if(cskin[playerid] >= sizeof VipSkinMale) cskin[playerid] = 0;
				SetPlayerSkin(playerid, VipSkinMale[cskin[playerid]]);
			}
			else
			{
				if(cskin[playerid] >= sizeof VipSkinFemale) cskin[playerid] = 0;
				SetPlayerSkin(playerid, VipSkinFemale[cskin[playerid]]);
			}
		}
		return 1;
	}
	if(textid == SelectBaju[4])//beli
	{
	    pData[playerid][pSkin] = GetPlayerSkin(playerid);
        GivePlayerMoneyEx(playerid, -500);
        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "> %s telah membeli baju seharga $500 <", ReturnName(playerid));
        ShowItemBox(playerid, "Uang", "Removed_$500", 1212, 3);
    	for(new i = 0; i < 7; i++)
		{
			TextDrawShowForPlayer(playerid, SelectBaju[i]);
		}
		return 1;
	}
	if(textid == SelectBaju[6])//exit
	{
	    SetPlayerSkin(playerid, pData[playerid][pSkin]);
	    for(new i = 0; i < 8; i++)
		{
			TextDrawHideForPlayer(playerid, SelectBaju[i]);
		}
	}
	return 0;
}