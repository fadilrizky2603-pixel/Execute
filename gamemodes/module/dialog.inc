//----------------[ Dialog System ]--------------
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	printf("[OnDialogResponse]: %s(%d) has used dialog id: %d Listitem: %d", pData[playerid][pName], playerid, dialogid, listitem);
	if(dialogid == UCP_LOGIN)
	{
		if(!response) 
			return KickEx(playerid);

		new pwQuery[256], hash[BCRYPT_HASH_LENGTH];
		mysql_format(g_SQL, pwQuery, sizeof(pwQuery), "SELECT password FROM ucp WHERE ucp_name = '%e' LIMIT 1", pData[playerid][pName]);
		new Cache:result = mysql_query(g_SQL, pwQuery);

		cache_get_value_name(0, "password", hash, sizeof(hash)); // Variabel hash mendapatkan nilai
		cache_delete(result);
		bcrypt_verify(playerid, "OnPlayerPasswordChecked", SQL_Escape(inputtext), hash);
		return 1;
	}
	if(dialogid == UCP_PIN)
	{
		if(response)
		{
			new pin = strval(inputtext);

			new lstring[512];
			if(pin != pData[playerid][pUcpPin])
			{
				pData[playerid][pAttemps]++;
				if(pData[playerid][pAttemps] >= 3)
				{
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Verification Account", ""WHITE_E"You have mistyped your PIN too often (3 times).", "Okay", "");
					KickEx(playerid);
				}
				else
				{
					format(lstring, sizeof(lstring), "{FFFFFF}Selamat datang di {FFD700}Kampung Indo Roleplay{FFFFFF}\nAkun ini membutuhkan kode pin!\n{00FF00}Kesempatan Login (%d/3){FFFFFF}\nNama UCP: {FFFF00}%s{00FF00}\n(PIN Code yang anda masukan salah, silahkan coba lagi)", pData[playerid][pAttemps], pData[playerid][pName]);
					ShowPlayerDialog(playerid, UCP_PIN, DIALOG_STYLE_INPUT, "Verification Account", lstring, "Register", "Abort");
				}
			}
			else
			{
				format(lstring, sizeof(lstring), "{FFFFFF}Selamat datang di {FFD700}Kampung Indo Roleplay{FFFFFF}\nAkun ini berhasil terverifikasi!\nNama UCP: {FFFF00}%s{00FF00}\n(Masukan password yang ingin anda buat)", pData[playerid][pName]);
				ShowPlayerDialog(playerid, UCP_PASSWORD, DIALOG_STYLE_PASSWORD, "Verification Account", lstring, "Register", "Abort");
			}
		}
		else return KickEx(playerid);
		return 1;
	}
	if(dialogid == UCP_PASSWORD)
	{
		if(response)
		{
			new lstring[512];
			if(strlen(inputtext) < 6)
			{
				format(lstring, sizeof(lstring), "{FFFFFF}Selamat datang di {FFD700}Kampung Indo Roleplay{FFFFFF}\nAkun ini berhasil terverifikasi!\nNama UCP: {FFFF00}%s{FF0000}\n(Password yang anda masukan minimal 5 karakter)", pData[playerid][pName]);
				ShowPlayerDialog(playerid, UCP_PASSWORD, DIALOG_STYLE_PASSWORD, "Verification Account", lstring, "Register", "Abort");
				return 1;
			}

			if(strlen(inputtext) > 32)
			{
				format(lstring, sizeof(lstring), "{FFFFFF}Selamat datang di {FFD700}Kampung Indo Roleplay{FFFFFF}\nAkun ini berhasil terverifikasi!\nNama UCP: {FFFF00}%s{FF0000}\n(Password yang anda masukan maximal 32 karakter)", pData[playerid][pName]);
				ShowPlayerDialog(playerid, UCP_PASSWORD, DIALOG_STYLE_PASSWORD, "Verification Account", lstring, "Register", "Abort");
				return 1;
			}

			if(!IsValidPassword(inputtext))
			{
				format(lstring, sizeof(lstring), "{FFFFFF}Selamat datang di {FFD700}Kampung Indo Roleplay{FFFFFF}\nAkun ini berhasil terverifikasi!\nNama UCP: {FFFF00}%s{FF0000}\n(Password yang anda masukan tidak boleh berupa symbol)", pData[playerid][pName]);
				ShowPlayerDialog(playerid, UCP_PASSWORD, DIALOG_STYLE_PASSWORD, "Verification Account", lstring, "Register", "Abort");
				return 1;
			}

			bcrypt_hash(playerid, "HashRegPassword", SQL_Escape(inputtext), BCRYPT_COST);
		}
		else return KickEx(playerid);
		return 1;
	}
	if(dialogid == UCP_CHARACTER)
	{
		if(response)
		{
			if(UcpData[playerid][listitem][ucpCharacter] != EOS)
			{
				GetPlayerName(playerid, pData[playerid][pUcp], MAX_PLAYER_NAME);

				SetPlayerName(playerid, UcpData[playerid][listitem][ucpCharacter]);
				GetPlayerName(playerid, pData[playerid][pName], MAX_PLAYER_NAME);

				MySQL_SpawnUcpCharacter(playerid);
			}
			else
			{
				new lstring[524];
				format(lstring, sizeof(lstring), "{FFFFFF}Example Names: Xeno_tadasi, Albert_Linghart, etc\nRules\n"YELLOW_E"- Make sure the name you enter is not from a Famous character\n- It is forbidden to use meme names such as Agus_Buntung, Windah_BatuBara, etc\n- It is also forbidden to use names that are not in accordance with the culture\n\n{00FF00}(Input the In-Character name you want to create)");
				ShowPlayerDialog(playerid, UCP_CHARACTER_CREATE, DIALOG_STYLE_INPUT, "Create Character", lstring, "Create", "");
			}
		}
		else return KickEx(playerid);
		return 1;
	}
	if(dialogid == UCP_CHARACTER_CREATE)
	{
		if(response)
		{
			new lstring[524];
			if(!IsValidRoleplayName(inputtext))
			{
				ErrorMsg(playerid, "Name does not conform to Roleplay name format.");

				format(lstring, sizeof(lstring), "{FFFFFF}Example Names:  Xeno_tadasi, Albert_Linghart, etc.\n{FF0000}The name format you entered is incorrect!\n{00FF00}(Input the In-Character name you want to create)");
				ShowPlayerDialog(playerid, UCP_CHARACTER_CREATE, DIALOG_STYLE_INPUT, "Create Character", lstring, "Create", "");
				return 1;
			}
			if(strlen(inputtext) > MAX_PLAYER_NAME)
			{
				format(lstring, sizeof(lstring), "{FFFFFF}Example Names: Xeno_tadasi, Albert_Linghart, etc, etc\n{FF0000}The name you enter cannot be longer than %d characters!\n{00FF00}(Input the In-Character name you want to create)", MAX_PLAYER_NAME);
				ShowPlayerDialog(playerid, UCP_CHARACTER_CREATE, DIALOG_STYLE_INPUT, "Create Character", lstring, "Create", "");
				return 1;
			}

			MySQL_CheckCharacterCreate(playerid, inputtext);
		}
		else return MySQL_LoadUcpCharacter(playerid);
		return 1;
	}
	if(dialogid == DIALOG_AGE)
    {
		if(!response) 
			return ShowPlayerDialog(playerid, DIALOG_AGE, DIALOG_STYLE_INPUT, "Birth Date", "{FFFFFF}Enter your character's birth date\n(Day/Month/Year)\nExample: 04/15/1998", "Enter", "Cancel");

		if(response)
		{
			new
				iDay,
				iMonth,
				iYear,
				day,
				month,
				year;
				
			getdate(year, month, day);

			static const
					arrMonthDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

			if(sscanf(inputtext, "p</>ddd", iDay, iMonth, iYear)) {
				ShowPlayerDialog(playerid, DIALOG_AGE, DIALOG_STYLE_INPUT, "Birth Date", "{FFFFFF}Enter your character's birth date\n{FF0000}Invalid birth date input format!{FFFFFF}\n(Day/Month/Year)\nExample: 04/15/1998", "Enter", "Cancel");
			}
			else if(iYear < 1900 || iYear > year) {
				ShowPlayerDialog(playerid, DIALOG_AGE, DIALOG_STYLE_INPUT, "Year of Birth", "{FFFFFF}Enter your character's date of birth\n{FF0000}Invalid birth year input format!{FFFFFF}\n(Day/Month/Year)\nExample: 04/15/1998", "Enter", "Cancel");
			}
			else if(iMonth < 1 || iMonth > 12) {
				ShowPlayerDialog(playerid, DIALOG_AGE, DIALOG_STYLE_INPUT, "Birth Date", "{FFFFFF}Enter your character's birth date\n{FF0000}Invalid birth month input format!{FFFFFF}\n(Day/Month/Year)\nExample: 04/15/1998", "Enter", "Cancel");
			}
			else if(iDay < 1 || iDay > arrMonthDays[iMonth - 1]) {
				ShowPlayerDialog(playerid, DIALOG_AGE, DIALOG_STYLE_INPUT, "Birth Date", "{FFFFFF}Enter your character's birth date\n{FF0000}Invalid birth date input format!{FFFFFF}\n(Day/Month/Year)\nExample: 04/15/1998", "Enter", "Cancel");
			}
			else 
			{
				format(pData[playerid][pAge], 50, inputtext);
				ShowPlayerDialog(playerid, DIALOG_GENDER, DIALOG_STYLE_LIST, "Gender", "{007FD4}Male\n{F700FF}Female", "Select", "Cancel");
			}
		}
		else ShowPlayerDialog(playerid, DIALOG_AGE, DIALOG_STYLE_INPUT, "Birth Date", "{FFFFFF}Enter your character's birth date\n(Day/Month/Year)\nExample: 04/15/1998", "Enter", "Cancel");
		return 1;
	}
	if(dialogid == DIALOG_GENDER)
    {
		if(!response) return ShowPlayerDialog(playerid, DIALOG_GENDER, DIALOG_STYLE_LIST, "Gender", "{007FD4}Male\n{F700FF}Female", "Select", "Cancel");
		if(response)
		{
			switch (listitem) 
			{
				case 0: 
				{
					pData[playerid][pGender] = 1;
					if(IsPlayerLanding[playerid] == 1){
						Login::Screen_Show(playerid, 1);
					}
					SetTimerEx("revivenewplayer", 5000, false, "d", playerid);
					switch (pData[playerid][pGender])
					{
						case 1: 
						{
							pData[playerid][pSkin] = 117;
							SetPlayerSkin(playerid, 117);
						}
						case 2:
						{
							pData[playerid][pSkin] = 150;
							SetPlayerSkin(playerid, 150);
						}
					}
				}
				case 1: 
				{
					pData[playerid][pGender] = 2;
					if(IsPlayerLanding[playerid] == 1){
						Login::Screen_Show(playerid, 1);
					}

					SetTimerEx("revivenewplayer", 5000, false, "d", playerid);
					switch (pData[playerid][pGender])
					{
						case 1: 
						{
							pData[playerid][pSkin] = 117;
							SetPlayerSkin(playerid, 117);
						}
						case 2:
						{
							pData[playerid][pSkin] = 150;
							SetPlayerSkin(playerid, 150);
						}
					}
				}
			}
		}
		else ShowPlayerDialog(playerid, DIALOG_GENDER, DIALOG_STYLE_LIST, "Gender", "{007FD4}Male\n{F700FF}Female", "Select", "Cancel");
		return 1;
	}
	if(dialogid == DIALOG_EMAIL)
	{
		if(response)
		{
			if(isnull(inputtext))
			{
				Error(playerid, "This field cannot be left empty!");
				if(pData[playerid][IsLoggedIn] == false)
					return Error(playerid, "Kamu harus login!");

				ShowPlayerDialog(playerid, DIALOG_EMAIL, DIALOG_STYLE_INPUT, ""WHITE_E"Set Email", ""WHITE_E"Masukkan Email.\nIni akan digunakan sebagai ganti kata sandi.\n\n"RED_E"* "WHITE_E"Email mu tidak akan termunculkan untuk Publik\n"RED_E"* "WHITE_E"Email hanya berguna untuk verifikasi Password yang terlupakan dan berita lainnya\n\
				"RED_E"* "WHITE_E"Be sure to double-check and enter a valid email address!", "Enter", "Exit");
				return 1;
			}
			if(!(2 < strlen(inputtext) < 40))
			{
				Error(playerid, "Please insert a valid email! Must be between 3-40 characters.");
				if(pData[playerid][IsLoggedIn] == false)
					return Error(playerid, "Kamu harus login!");

				ShowPlayerDialog(playerid, DIALOG_EMAIL, DIALOG_STYLE_INPUT, ""WHITE_E"Set Email", ""WHITE_E"Masukkan Email.\nIni akan digunakan sebagai ganti kata sandi.\n\n"RED_E"* "WHITE_E"Email mu tidak akan termunculkan untuk Publik\n"RED_E"* "WHITE_E"Email hanya berguna untuk verifikasi Password yang terlupakan dan berita lainnya\n\
				"RED_E"* "WHITE_E"Be sure to double-check and enter a valid email address!", "Enter", "Exit");
				return 1;
			}
			if(!IsValidPassword(inputtext))
			{
				Error(playerid, "Email can contain only A-Z, a-z, 0-9, _, [ ], ( )  and @");
				if(pData[playerid][IsLoggedIn] == false)
					return Error(playerid, "Kamu harus login!");

				ShowPlayerDialog(playerid, DIALOG_EMAIL, DIALOG_STYLE_INPUT, ""WHITE_E"Set Email", ""WHITE_E"Masukkan Email.\nIni akan digunakan sebagai ganti kata sandi.\n\n"RED_E"* "WHITE_E"Email mu tidak akan termunculkan untuk Publik\n"RED_E"* "WHITE_E"Email hanya berguna untuk verifikasi Password yang terlupakan dan berita lainnya\n\
				"RED_E"* "WHITE_E"Be sure to double-check and enter a valid email address!", "Enter", "Exit");
				return 1;
			}
			new query[512];
			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET email='%e' WHERE reg_id='%d'", inputtext, pData[playerid][pID]);
			mysql_tquery(g_SQL, query);
			Servers(playerid, "Your e-mail has been set to "YELLOW_E"%s!"WHITE_E"(relogin for /stats update)", inputtext);
			return 1;
		}
		return 1;
	}
	if(dialogid == DIALOG_STATS)
	{
		if(response)
		{
			if(pData[playerid][IsLoggedIn] == false)
			{
				Error(playerid, "You must be logged in to check statistics!");
				return 1;
			}
			
			new str[1024], togpm[64], toglog[64], togads[64], togwt[64];
			
			if(pData[playerid][pTogPM] == 0)
			{
				togpm = ""RED_E"Disable";
			}
			else
			{
				togpm = ""LG_E"Enable";
			}
			
			if(pData[playerid][pTogLog] == 0)
			{
				toglog = ""RED_E"Disable";
			}
			else
			{
				toglog = ""LG_E"Enable";
			}
			
			if(pData[playerid][pTogAds] == 0)
			{
				togads = ""RED_E"Disable";
			}
			else
			{
				togads = ""LG_E"Enable";
			}
			
			if(pData[playerid][pTogWT] == 0)
			{
				togwt = ""RED_E"Disable";
			}
			else
			{
				togwt = ""LG_E"Enable";
			}
			
			format(str, sizeof(str), "Settings\tStatus\n"WHITEP_E"Email:\t"GREY3_E"%s\n"WHITEP_E"Change Password\n"WHITEP_E"Toggle PM:\t%s\n"WHITEP_E"Toggle Log Server:\t%s\n"WHITEP_E"Toggle Ads:\t%s\n"WHITEP_E"Toggle WT:\t%s",
			pData[playerid][pEmail], 
			togpm,
			toglog,
			togads,
			togwt
			);
			
			ShowPlayerDialog(playerid, DIALOG_SETTINGS, DIALOG_STYLE_TABLIST_HEADERS, "Settings", str, "Set", "Close");
		}
		return 1;
	}
	if(dialogid == DIALOG_SETTINGS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][IsLoggedIn] == false)
						return Error(playerid, "Kamu harus login!");

					ShowPlayerDialog(playerid, DIALOG_EMAIL, DIALOG_STYLE_INPUT, ""WHITE_E"Set Email", ""WHITE_E"Masukkan Email.\nIni akan digunakan sebagai ganti kata sandi.\n\n"RED_E"* "WHITE_E"Email mu tidak akan termunculkan untuk Publik\n"RED_E"* "WHITE_E"Email hanya berguna untuk verifikasi Password yang terlupakan dan berita lainnya\n\
					"RED_E"* "WHITE_E"Be sure to double-check and enter a valid email address!", "Enter", "Exit");
				}
				case 1:
				{
					return Servers(playerid, "Silahkan menuju discord Kampung Indo Roleplay!");
				}
				case 2:
				{
					return callcmd::togpm(playerid);
				}
				case 3:
				{
					return callcmd::toglog(playerid);
				}
				case 4:
				{
					return callcmd::togads(playerid);
				}
				case 5:
				{
					return callcmd::togwt(playerid);
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_CHANGEAGE)
    {
		if(response)
		{
			new
				iDay,
				iMonth,
				iYear,
				day,
				month,
				year;
				
			getdate(year, month, day);

			static const
					arrMonthDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

			if(sscanf(inputtext, "p</>ddd", iDay, iMonth, iYear)) {
				ShowPlayerDialog(playerid, DIALOG_CHANGEAGE, DIALOG_STYLE_INPUT, "Tanggal Lahir", "Error! Invalid Input\nMasukan tanggal lahir (Tgl/Bulan/Tahun): 15/04/1998", "Pilih", "Batal");
			}
			else if(iYear < 1900 || iYear > year) {
				ShowPlayerDialog(playerid, DIALOG_CHANGEAGE, DIALOG_STYLE_INPUT, "Tahun Lahir", "Error! Invalid Input\nMasukan tanggal lahir (Tgl/Bulan/Tahun): 15/04/1998", "Pilih", "Batal");
			}
			else if(iMonth < 1 || iMonth > 12) {
				ShowPlayerDialog(playerid, DIALOG_CHANGEAGE, DIALOG_STYLE_INPUT, "Bulan Lahir", "Error! Invalid Input\nMasukan tanggal lahir (Tgl/Bulan/Tahun): 15/04/1998", "Pilih", "Batal");
			}
			else if(iDay < 1 || iDay > arrMonthDays[iMonth - 1]) {
				ShowPlayerDialog(playerid, DIALOG_CHANGEAGE, DIALOG_STYLE_INPUT, "Tanggal Lahir", "Error! Invalid Input\nMasukan tanggal lahir (Tgl/Bulan/Tahun): 15/04/1998", "Pilih", "Batal");
			}
			else 
			{
				format(pData[playerid][pAge], 50, inputtext);
				Info(playerid, "New Age for your character is "YELLOW_E"%s.", pData[playerid][pAge]);
				GivePlayerMoneyEx(playerid, -20);
				Server_AddMoney(20);
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_GOLDSHOP)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pGold] < 500) return Error(playerid, "Not enough gold!");
					ShowPlayerDialog(playerid, DIALOG_GOLDNAME, DIALOG_STYLE_INPUT, "Change Name", "Input new nickname:\nExample: Charles_Sanders\n", "Change", "Cancel");
				}
				case 1:
				{
					if(pData[playerid][pGold] < 500) return Error(playerid, "Not enough gold!");
					pData[playerid][pGold] -= 500;
					pData[playerid][pWarn] = 0;
					Info(playerid, "Warning have been reseted for 500 gold. Total Warning: 0");
				}
				case 2:
				{
					if(pData[playerid][pGold] < 300) return Error(playerid, "Not enough gold!");
					pData[playerid][pGold] -= 300;
					pData[playerid][pVip] = 1;
					pData[playerid][pVipTime] = gettime() + (14 * 86400);
					Info(playerid, "You has bought VIP level 1 for 300 gold(14 days).");
				}
				case 3:
				{
					if(pData[playerid][pGold] < 400) return Error(playerid, "Not enough gold!");
					pData[playerid][pGold] -= 400;
					pData[playerid][pVip] = 2;
					pData[playerid][pVipTime] = gettime() + (14 * 86400);
					Info(playerid, "You has bought VIP level 2 for 400 gold(14 days).");
				}
				case 4:
				{
					if(pData[playerid][pGold] < 500) return Error(playerid, "Not enough gold!");
					pData[playerid][pGold] -= 500;
					pData[playerid][pVip] = 3;
					pData[playerid][pVipTime] = gettime() + (14 * 86400);
					Info(playerid, "You has bought VIP level 3 for 500 gold(14 days).");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_GOLDNAME)
	{
		if(response)
		{
			if(strlen(inputtext) < 4) return Error(playerid, "New name can't be shorter than 4 characters!"),  ShowPlayerDialog(playerid, DIALOG_GOLDNAME, DIALOG_STYLE_INPUT, ""WHITE_E"Change Name", "Enter your new name:", "Enter", "Exit");
			if(strlen(inputtext) > 20) return Error(playerid, "New name can't be longer than 20 characters!"),  ShowPlayerDialog(playerid, DIALOG_GOLDNAME, DIALOG_STYLE_INPUT, ""WHITE_E"Change Name", "Enter your new name:", "Enter", "Exit");
			if(!IsValidRoleplayName(inputtext))
			{
				Error(playerid, "Name contains invalid characters, please doublecheck!");
				ShowPlayerDialog(playerid, DIALOG_GOLDNAME, DIALOG_STYLE_INPUT, ""WHITE_E"Change Name", "Enter your new name:", "Enter", "Exit");
				return 1;
			}
			new query[512];
			mysql_format(g_SQL, query, sizeof(query), "SELECT username FROM players WHERE username='%s'", inputtext);
			mysql_tquery(g_SQL, query, "ChangeName", "is", playerid, inputtext);
		}
		return 1;
	}
	//--------------[VENDING MACHINE]-------------------
	if(dialogid == VENDING_MENU)
	{
		new venid = pData[playerid][pGetVENID];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(!Player_OwnsVending(playerid, venid))
						return Error(playerid, "Kamu bukan pemilik vending machine ini.");

					if(pData[playerid][pGetVENID] == -1)
						return Error(playerid, "Kamu harus relog");

					new str[128];
					format(str, sizeof(str), ""WHITE_E"Drink Price: "GREEN_E"%d "WHITE_E" (batas harga hanya $1 sampai $25)", vmData[venid][venDrinkPrice]);
					ShowPlayerDialog(playerid, VENDING_DRINK_PRICE, DIALOG_STYLE_INPUT, "Edit Price", str, "Edit", "Back");
				}
				case 1:
				{
					if(!Player_OwnsVending(playerid, venid))
						return Error(playerid, "Kamu bukan pemilik vending machine ini.");

					if(pData[playerid][pGetVENID] == -1)
						return Error(playerid, "Kamu harus relog");
					
					//Vending Money
					ShowPlayerDialog(playerid, VENDING_MONEY, DIALOG_STYLE_LIST, "Vending Money", "Withdraw Money\nDeposit Money", "Select", "Back");
				}
			}
		}
		return 1;
	}
	if(dialogid == VENDING_DRINK_PRICE)
	{
		new venid = pData[playerid][pGetVENID];
		if(Player_OwnsVending(playerid, pData[playerid][pGetVENID]))
		{
			if(response)
			{
				if(isnull(inputtext))
				{
					new str[128];
					format(str,sizeof(str), "Please enter the new product price for %d:", vmData[venid][venDrinkPrice]);
					ShowPlayerDialog(playerid, VENDING_DRINK_PRICE, DIALOG_STYLE_INPUT, "Vending: Set Price", str, "Modify", "Back");
					return 1;
				}
				if(strval(inputtext) < 1 || strval(inputtext) > 500)
				{
					new str[128];
					format(str,sizeof(str), "Drink Price: %d (batas harga hanya $1 sampai $500)", vmData[venid][venDrinkPrice]);
					ShowPlayerDialog(playerid, VENDING_DRINK_PRICE, DIALOG_STYLE_INPUT, "Vending: Set Price", str, "Modify", "Back");
					return 1;
				}
				vmData[venid][venDrinkPrice] = strval(inputtext);
				Vending_Save(venid);
				VendingLabel_Refresh(venid);

				Servers(playerid, "You have adjusted the price of %d to: %s!", vmData[venid][venDrinkPrice], FormatMoney(strval(inputtext)));
			}
			else
			{
				callcmd::vmedit(playerid, "");
			}
		}
		return 1;
	}
	if(dialogid == VENDING_MONEY)
	{
		if(response)
		{
			new venid = pData[playerid][pGetVENID];
			if(response)
			{
				switch (listitem)
				{
					case 0: 
					{
						if(!Player_OwnsVending(playerid, venid))
							return Error(playerid, "Kamu bukan pemilik vending machine ini.");

						new str[128];
						format(str, sizeof(str), ""WHITE_E"Money Balance: "GREEN_E"%s\n\n"WHITE_E"Please enter how much money you wish to withdraw from the safe:", FormatMoney(vmData[venid][venMoney]));
						ShowPlayerDialog(playerid, VENDING_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw Money", str, "Withdraw", "Back");
					}
					case 1: 
					{
						if(!Player_OwnsVending(playerid, venid))
							return Error(playerid, "Kamu bukan pemilik vending machine ini.");

						new str[128];
						format(str, sizeof(str), ""WHITE_E"Money Balance: "GREEN_E"%s\n\n"WHITE_E"Please enter how much money you wish to deposit into the safe:", FormatMoney(vmData[venid][venMoney]));
						ShowPlayerDialog(playerid, VENDING_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit Money", str, "Deposit", "Back");
					}
				}
			}
			else callcmd::vmedit(playerid, "");
		}
		return 1;
	}
	if(dialogid == VENDING_WITHDRAWMONEY)
	{
		new venid = pData[playerid][pGetVENID];
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), ""WHITE_E"Money Balance: "GREEN_E"%s\n\n"WHITE_E"Please enter how much money you wish to withdraw from the safe:", FormatMoney(vmData[venid][venMoney]));
				ShowPlayerDialog(playerid, VENDING_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw Money", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > vmData[venid][venMoney])
			{
				new str[128];
				format(str, sizeof(str), ""RED_E"ERROR: "WHITE_E"Insufficient funds.\n\nMoney Balance: "GREEN_E"%s\n\n"WHITE_E"Please enter how much money you wish to withdraw from the safe:", FormatMoney(vmData[venid][venMoney]));
				ShowPlayerDialog(playerid, VENDING_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw Money", str, "Withdraw", "Back");
				return 1;
			}
			vmData[venid][venMoney] -= amount;
			GivePlayerMoneyEx(playerid, amount);

			Vending_Save(venid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %s money from vending storage.", ReturnName(playerid), FormatMoney(amount));
			return 1;
		}
		else callcmd::vmedit(playerid, "");
		return 1;
	}
	if(dialogid == DIALOG_GSVAULT)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_GSVAULTDEPOSIT, DIALOG_STYLE_INPUT, "Server Money", "Masukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_GSVAULTWITHDRAW, DIALOG_STYLE_INPUT, "Server Money", "Masukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				}
			}
		}
	}
	if(dialogid == DIALOG_GSVAULTWITHDRAW)
	{
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_GSVAULTWITHDRAW, DIALOG_STYLE_INPUT, "Server Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			if(amount < 1 || amount > ServerMoney)
			{
				ShowPlayerDialog(playerid, DIALOG_GSVAULTWITHDRAW, DIALOG_STYLE_INPUT, "Server Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			ServerMoney -= amount;
			GivePlayerMoneyEx(playerid, amount);
			
			Server_Save();
			Servers(playerid, "Server Money telah di update dan berkurang | {00FF00}-%s", FormatMoney(amount));
			SendStaffMessage(-1, "%s telah menggunakan command {FFFF00}'/gsvault' {FFFFFF}untuk Withdraw uang", pData[playerid][pName]);
		}		
	}
	if(dialogid == DIALOG_GSVAULTDEPOSIT)
	{
		if(response)
		{
			new amount = strval(inputtext);
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_GSVAULTDEPOSIT, DIALOG_STYLE_INPUT, "Server Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			if(amount < 1 || amount > pData[playerid][pMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_GSVAULTDEPOSIT, DIALOG_STYLE_INPUT, "Server Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			ServerMoney += amount;
			GivePlayerMoneyEx(playerid, -amount);

			Server_Save();
			Servers(playerid, "Server Money telah di update dan bertambah | {00FF00}+%s", FormatMoney(amount));
			SendStaffMessage(-1, "%s telah menggunakan command {FFFF00}'/gsvault' {FFFFFF}untuk Deposit uang", pData[playerid][pName]);
		}
	}
	if(dialogid == VENDING_DEPOSITMONEY)
	{
		new venid = pData[playerid][pGetVENID];
		if(vmData[venid][venMoney] > 50000) return Error(playerid, "Penyimpanan sudah penuh!");

		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), ""WHITE_E"Money Balance: "GREEN_E"%s\n\n"WHITE_E"Please enter how much money you wish to deposit into the safe:", FormatMoney(vmData[venid][venMoney]));
				ShowPlayerDialog(playerid, VENDING_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit Money", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > pData[playerid][pMoney])
			{
				new str[128];
				format(str, sizeof(str), ""RED_E"ERROR: "WHITE_E"Insufficient funds.\n\nMoney Balance: "GREEN_E"%s\n\n"WHITE_E"Please enter how much money you wish to deposit into the safe:", FormatMoney(vmData[venid][venMoney]));
				ShowPlayerDialog(playerid, VENDING_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit Money", str, "Deposit", "Back");
				return 1;
			}
			vmData[venid][venMoney] += amount;
			GivePlayerMoneyEx(playerid, -amount);

			Vending_Save(venid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %s money into vending storage.", ReturnName(playerid), FormatMoney(amount));
		}
		else callcmd::vmedit(playerid, "");
		return 1;
	}
	if(dialogid == VENDING_DEPOSITSPRUNK)
	{
		new venid = pData[playerid][pGetVENID];
		if(vmData[venid][venProduct] > 100) return Error(playerid, "Penyimpanan sprunk sudah penuh!");

		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"Sprunk Balance: "GREEN_E"%d\n\n"WHITE_E"Silakan masukkan berapa banyak sprunk yang ingin Anda setorkan ke dalam vending:", vmData[venid][venProduct]);
				ShowPlayerDialog(playerid, VENDING_DEPOSITSPRUNK, DIALOG_STYLE_INPUT, "Deposit Sprunk", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Sprunk"))
			{
				new str[1024];
				format(str, sizeof(str), ""RED_E"ERROR: "WHITE_E"Sprunk milikmu tidak mencukupi.\n\nSprunk Balance: "GREEN_E"%d\n\n"WHITE_E"Silakan masukkan berapa banyak sprunk yang ingin Anda setorkan ke dalam vending:", vmData[venid][venProduct]);
				ShowPlayerDialog(playerid, VENDING_DEPOSITSPRUNK, DIALOG_STYLE_INPUT, "Deposit Sprunk", str, "Deposit", "Back");
				return 1;
			}
			vmData[venid][venProduct] += amount;
			Inventory_Remove(playerid, "Sprunk", amount);

			Vending_Save(venid);
			VendingLabel_Refresh(venid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d sprunk into vending storage.", ReturnName(playerid), amount);
		}
		else callcmd::vmedit(playerid, "");
		return 1;
	}
	if(dialogid == DIALOG_MY_VENDING)
	{
		if(response) 
		{
			new venid = ReturnPlayerVendingID(playerid, (listitem + 1));
			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerRaceCheckpoint(playerid, 1, vmData[venid][venX], vmData[venid][venY], vmData[venid][venZ], 0.0, 0.0, 0.0, 4.5);
			Info(playerid, "Vending Machine milikmu yang berlokasi di %s telah di tandai", GetLocation(vmData[venid][venX], vmData[venid][venY], vmData[venid][venZ]));
		}
		return 1;
	}
	/*if(dialogid == DIALOG_MIXER)
	{
		if(!response) return SelectTextDraw(playerid, X11_PINK);
        if(isnull(inputtext)) return ErrorMsg(playerid, "Takaran tidak boleh kosong!");
		if(!IsNumeric(inputtext)) return ErrorMsg(playerid, "Hanya angka!");
		if(strval(inputtext) < 1) return ShowTDN(playerid, ErrorMsg(playerid, "Takaran tidak boleh kurang dari 1!");
		switch(jobs::mixer[playerid][mixerSelectCase])
		{
			case 1:
			{
                PlayerTextDrawSetString(playerid, jobs::Pmixer[playerid][5], inputtext);
				jobs::mixer[playerid][mixerConfirm][0] = strval(inputtext);
				SuccesMsg(playerid, "Berhasil menetapkan takaran semen");
			}
			case 2:
			{
                PlayerTextDrawSetString(playerid, jobs::Pmixer[playerid][6], inputtext);
				jobs::mixer[playerid][mixerConfirm][1] = strval(inputtext);
				SuccesMsg(playerid, "Berhasil menetapkan takaran pasir");
			}
			case 3:
			{
                PlayerTextDrawSetString(playerid, jobs::Pmixer[playerid][7], inputtext);
				jobs::mixer[playerid][mixerConfirm][2] = strval(inputtext);
				SuccesMsg(playerid, "Berhasil menetapkan takaran kerikil 1-2");
			}
			case 4:
			{
                PlayerTextDrawSetString(playerid, jobs::Pmixer[playerid][8], inputtext);
				jobs::mixer[playerid][mixerConfirm][3] = strval(inputtext);
				SuccesMsg(playerid, "Berhasil menetapkan takaran kerikil 2-3");
			}
			case 5:
			{
                PlayerTextDrawSetString(playerid, jobs::Pmixer[playerid][9], inputtext);
				jobs::mixer[playerid][mixerConfirm][4] = strval(inputtext);
				SuccesMsg(playerid, "Berhasil menetapkan takaran air");
			}
		}
		SelectTextDraw(playerid, X11_PINK);
	}*/
	//-------------[WORKSHOP DIALOG]-----------
	if(dialogid == WORKSHOP_MENU)
	{
		if(!response) return 1;
		new wid = pData[playerid][pWorkshop];

		new status[128];
		if(wData[wid][wStatus] == 1)
		{
			status = "{FF0000}Closed";
		}
		else
		{
			status = "{00FF00}Opened";
		}
		switch(listitem) 
		{
			case 0:
			{
				new mstr[248], lstr[512];
				format(mstr,sizeof(mstr),""WHITE_E"Workshop ID %d", wid);
				format(lstr,sizeof(lstr),""WHITE_E"Workshop Name:\t"RED_E"%s\n"WHITE_E"Workshop Status:\t%s\nWorkshop Member\t", wData[wid][wName], status);
				ShowPlayerDialog(playerid, WORKSHOP_INFO, DIALOG_STYLE_TABLIST, mstr, lstr,"Select","Close");
			}
			case 1:
			{
				if(pData[playerid][pOnDuty] == 1)
				{
					pData[playerid][pOnDuty] = 0;
					SetPlayerColor(playerid, COLOR_WHITE);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s mengganti pakaian kerja dengan pakaian biasa", ReturnName(playerid));
				}
				else
				{
					pData[playerid][pOnDuty] = 1;
					SetPlayerColor(playerid, COLOR_WHITE);
					if(pData[playerid][pGender] == 1)
					{
						SetPlayerSkin(playerid, 268);
						pData[playerid][pFacSkin] = 268;
					}
					else
					{
						SetPlayerSkin(playerid, 69); //194
						pData[playerid][pFacSkin] = 69; //194
					}
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s mengambil pakaian kerja dari dalam locker dan langsung memakainya", ReturnName(playerid));
				}
			}
			case 2:
			{
				//Workshop Money
				ShowPlayerDialog(playerid, WORKSHOP_MONEY, DIALOG_STYLE_LIST, "Workshop Money", "Withdraw Money\nDeposit Money", "Select", "Back");
			}
			case 3:
			{
				//Workshop Component
				ShowPlayerDialog(playerid, WORKSHOP_COMPONENT, DIALOG_STYLE_LIST, "Workshop Component", "Withdraw Component\nDeposit Component", "Select", "Back");
			}
			case 4:
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Component") < 100)
					return ErrorMsg(playerid, "Anda harus memiliki 100 component untuk membuat ini");

				if(pData[playerid][pActivityTime] > 5)
					return ErrorMsg(playerid, "Anda masih memiliki activity progress");

				TogglePlayerControllable(playerid, 0);
				
				pData[playerid][pMechanic] = SetTimerEx("WorkshopCreateRepairkit", 10000, false, "id", playerid, pData[playerid][pWorkshop]);
				ShowProgressbar(playerid, "Creating...", 10);
			}
		}
		return 1;
	}
	if(dialogid == WORKSHOP_INFO)
	{
		new wid = pData[playerid][pWorkshop];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pWorkshopRank] < 6)
					return Error(playerid,"Hanya rank 6 yang bisa mengubah nama.");

					new mstr[248];
					format(mstr,sizeof(mstr),""WHITE_E"Nama Workshop: "RED_E"%s\n\n"WHITE_E"Masukkan nama workshop yang kamu inginkan\nMaksimal 32 karakter untuk nama workshop", wData[wid][wName]);
					ShowPlayerDialog(playerid, WORKSHOP_NAME, DIALOG_STYLE_INPUT,"Workshop Name", mstr,"Done","Back");
				}
				case 1:
				{
					return callcmd::lockws(playerid, "");
				}
				case 2:
				{
					if(pData[playerid][pWorkshop] == -1)
						return Error(playerid, "Kamu bukan anggota workshop!");

					new query[512];
					mysql_format(g_SQL, query, sizeof(query), "SELECT username,workshoprank FROM players WHERE workshop = %d", pData[playerid][pWorkshop]);
					mysql_tquery(g_SQL, query, "ShowWorkshopMember", "i", playerid);
				}
			}
		}
		return 1;
	}
	if(dialogid == WORKSHOP_NAME)
	{
		if(response)
		{
			new wid = pData[playerid][pWorkshop];

			if(!Player_OwnsWorkshop(playerid, wid)) return Error(playerid, "You don't own this workshop.");
			
			if (isnull(inputtext))
			{
				new mstr[512];
				format(mstr,sizeof(mstr),""RED_E"NOTE: "WHITE_E"Nama Workshop tidak di perbolehkan kosong!\n\n"WHITE_E"Nama Workshop: "RED_E"%s\n\n"WHITE_E"Masukkan nama Workshop yang kamu inginkan\nMaksimal 32 karakter untuk nama Bisnis", wData[wid][wName]);
				ShowPlayerDialog(playerid, WORKSHOP_NAME, DIALOG_STYLE_INPUT,"Workshop Name", mstr,"Done","Back");
				return 1;
			}
			if(strlen(inputtext) > 32 || strlen(inputtext) < 5)
			{
				new mstr[512];
				format(mstr,sizeof(mstr),""RED_E"NOTE: "WHITE_E"Nama Workshop harus 5 sampai 32 karakter.\n\n"WHITE_E"Nama Workshop: "RED_E"%s\n\n"WHITE_E"Masukkan nama Workshop yang kamu inginkan\nMaksimal 32 karakter untuk nama Bisnis", wData[wid][wName]);
				ShowPlayerDialog(playerid, WORKSHOP_NAME, DIALOG_STYLE_INPUT,"Workshop Name", mstr,"Done","Back");
				return 1;
			}
			format(wData[wid][wName], 32, ColouredText(inputtext));

			Workshop_Refresh(wid);
			Workshop_Save(wid);

			Servers(playerid, "Workshop name set to: \"%s\".", wData[wid][wName]);
		}
		else return callcmd::wsstorage(playerid, "");
		return 1;
	}
	if(dialogid == WORKSHOP_MONEY)
	{
		if(response)
		{
			new wid = pData[playerid][pWorkshop];
			if(wid == -1) return Error(playerid, "Kamu bukan anggota workshop!");
			if(response)
			{
				switch (listitem)
				{
					case 0: 
					{
						if(pData[playerid][pWorkshopRank] < 5)
							return Error(playerid, "Hanya rank 5 dan 6 yang bisa mengambil ini!");
							
						new str[128];
						format(str, sizeof(str), ""WHITE_E"Money Balance: "GREEN_E"%s/$1.500,000\n\n"WHITE_E"Please enter how much money you wish to withdraw from the safe:", FormatMoney(wData[wid][wMoney]));
						ShowPlayerDialog(playerid, WORKSHOP_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw Money", str, "Withdraw", "Back");
					}
					case 1: 
					{
						new str[128];
						format(str, sizeof(str), ""WHITE_E"Money Balance: "GREEN_E"%s/$1.500,000\n\n"WHITE_E"Please enter how much money you wish to deposit into the safe:", FormatMoney(wData[wid][wMoney]));
						ShowPlayerDialog(playerid, WORKSHOP_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit Money", str, "Deposit", "Back");
					}
				}
			}
			else callcmd::wsstorage(playerid, "");
		}
		return 1;
	}
	if(dialogid == WORKSHOP_WITHDRAWMONEY)
	{
		new wid = pData[playerid][pWorkshop];
		if(wid == -1) return Error(playerid, "Kamu bukan anggota workshop!");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), ""WHITE_E"Money Balance: "GREEN_E"%s/$1.500,000\n\n"WHITE_E"Please enter how much money you wish to withdraw from the safe:", FormatMoney(wData[wid][wMoney]));
				ShowPlayerDialog(playerid, WORKSHOP_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw Money", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > wData[wid][wMoney])
			{
				new str[128];
				format(str, sizeof(str), ""RED_E"ERROR: "WHITE_E"Insufficient funds.\n\nMoney Balance: "GREEN_E"%s/$1.500,000\n\n"WHITE_E"Please enter how much money you wish to withdraw from the safe:", FormatMoney(wData[wid][wMoney]));
				ShowPlayerDialog(playerid, WORKSHOP_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw Money", str, "Withdraw", "Back");
				return 1;
			}
			wData[wid][wMoney] -= amount;
			GivePlayerMoneyEx(playerid, amount);

			Workshop_Save(wid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %s money from storage.", ReturnName(playerid), FormatMoney(amount));
			callcmd::wsstorage(playerid, "");
			return 1;
		}
		else callcmd::wsstorage(playerid, "");
		return 1;
	}
	if(dialogid == WORKSHOP_DEPOSITMONEY)
	{
		new wid = pData[playerid][pWorkshop];
		if(wid == -1) return Error(playerid, "Kamu bukan anggota workshop.");
		if(wData[wid][wMoney] > 1500000) return Error(playerid, "Penyimpanan sudah penuh!");

		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), ""WHITE_E"Money Balance: "GREEN_E"%s/$1.500,000\n\n"WHITE_E"Please enter how much money you wish to deposit into the safe:", FormatMoney(wData[wid][wMoney]));
				ShowPlayerDialog(playerid, WORKSHOP_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit Money", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > pData[playerid][pMoney])
			{
				new str[128];
				format(str, sizeof(str), ""RED_E"ERROR: "WHITE_E"Insufficient funds.\n\nMoney Balance: "GREEN_E"%s/$1.500,000\n\n"WHITE_E"Please enter how much money you wish to deposit into the safe:", FormatMoney(wData[wid][wMoney]));
				ShowPlayerDialog(playerid, WORKSHOP_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit Money", str, "Deposit", "Back");
				return 1;
			}
			wData[wid][wMoney] += amount;
			GivePlayerMoneyEx(playerid, -amount);

			Workshop_Save(wid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %s money into storage.", ReturnName(playerid), FormatMoney(amount));
		}
		else callcmd::wsstorage(playerid, "");
		return 1;
	}
	if(dialogid == WORKSHOP_COMPONENT)
	{
		if(response)
		{
			new wid = pData[playerid][pWorkshop];
			if(wid == -1) return Error(playerid, "Kamu bukan anggota workshop!");
			if(response)
			{
				switch (listitem)
				{
					case 0: 
					{
						if(pData[playerid][pWorkshopRank] < 5)
							return Error(playerid, "Hanya rank 5 dan 6 yang bisa mengambil ini!");
							
						new str[128];
						format(str, sizeof(str), ""WHITE_E"Component Balance: "GREEN_E"%d/10.000\n\n"WHITE_E"Please enter how much component you wish to withdraw from the safe:", wData[wid][wComponent]);
						ShowPlayerDialog(playerid, WORKSHOP_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw Component", str, "Withdraw", "Back");
					}
					case 1: 
					{
						new str[128];
						format(str, sizeof(str), ""WHITE_E"Component Balance: "GREEN_E"%d/10.000\n\n"WHITE_E"Please enter how much component you wish to deposit into the safe:", wData[wid][wComponent]);
						ShowPlayerDialog(playerid, WORKSHOP_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit Component", str, "Deposit", "Back");
					}
				}
			}
			else callcmd::wsstorage(playerid, "");
		}
		return 1;
	}
	if(dialogid == WORKSHOP_WITHDRAWCOMPONENT)
	{
		new wid = pData[playerid][pWorkshop];
		if(wid == -1) return Error(playerid, "Kamu bukan anggota workshop!");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), ""WHITE_E"Component Balance: "GREEN_E"%d/10.000\n\n"WHITE_E"Please enter how much component you wish to withdraw from the safe:", wData[wid][wComponent]);
				ShowPlayerDialog(playerid, WORKSHOP_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw Component", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > wData[wid][wComponent])
			{
				new str[128];
				format(str, sizeof(str), ""RED_E"ERROR: "WHITE_E"Insufficient funds.\n\nComponent Balance: "GREEN_E"%d/10.000\n\n"WHITE_E"Please enter how much component you wish to withdraw from the safe:", wData[wid][wComponent]);
				ShowPlayerDialog(playerid, WORKSHOP_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw Component", str, "Withdraw", "Back");
				return 1;
			}
			wData[wid][wComponent] -= amount;
			Inventory_Add(playerid, "Component", 19627, amount);

			Workshop_Save(wid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d component from storage.", ReturnName(playerid), amount);
			callcmd::wsstorage(playerid, "");
			return 1;
		}
		else callcmd::wsstorage(playerid, "");
		return 1;
	}
	if(dialogid == WORKSHOP_DEPOSITCOMPONENT)
	{
		new wid = pData[playerid][pWorkshop];
		if(wid == -1) return Error(playerid, "Kamu bukan anggota workshop.");
		if(wData[wid][wComponent] > 10000) return Error(playerid, "Penyimpanan sudah penuh!");

		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), ""WHITE_E"Component Balance: "GREEN_E"%d/10.000\n\n"WHITE_E"Please enter how much component you wish to deposit into the safe:", wData[wid][wComponent]);
				ShowPlayerDialog(playerid, WORKSHOP_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit Component", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Component"))
			{
				new str[128];
				format(str, sizeof(str), ""RED_E"ERROR: "WHITE_E"Insufficient funds.\n\nComponent Balance: "GREEN_E"%d/10.000\n\n"WHITE_E"Please enter how much component you wish to deposit into the safe:", wData[wid][wComponent]);
				ShowPlayerDialog(playerid, WORKSHOP_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit Component", str, "Deposit", "Back");
				return 1;
			}
			wData[wid][wComponent] += amount;
			Inventory_Remove(playerid, "Component", amount);

			Workshop_Save(wid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d component into storage.", ReturnName(playerid), amount);
		}
		else callcmd::wsstorage(playerid, "");
		return 1;
	}
	//----------[ PFARM DIALOG ] -------------
	if(dialogid == PFARM_MENU)
	{
		new pfid = pData[playerid][pGetPFARM];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{	
					new string[1024];
					format(string, sizeof(string), "Farm ID : %d", pfid);
					ShowPlayerDialog(playerid, PFARM_SEEDS, DIALOG_STYLE_LIST, string, "Deposit Seeds\nWithdraw Seeds", "Yes", "No");
				}
				case 1:
				{
					new string[1024];
					format(string, sizeof(string), "Farm ID : %d", pfid);
					ShowPlayerDialog(playerid, PFARM_POTATO, DIALOG_STYLE_LIST, string, "Deposit Potato\nWithdraw Potato", "Yes", "No");
				}
				case 2:
				{
					new string[1024];
					format(string, sizeof(string), "Farm ID : %d", pfid);
					ShowPlayerDialog(playerid, PFARM_ORANGE, DIALOG_STYLE_LIST, string, "Deposit Orange\nWithdraw Orange", "Yes", "No");
				}
				case 3:
				{
					new string[1024];
					format(string, sizeof(string), "Farm ID : %d", pfid);
					ShowPlayerDialog(playerid, PFARM_WHEAT, DIALOG_STYLE_LIST, string, "Deposit Wheat\nWithdraw Wheat", "Yes", "No");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_MY_PFARM)
	{
		if(response) 
		{
			new pfid = ReturnPlayerPfarmID(playerid, (listitem + 1));
			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerRaceCheckpoint(playerid, 1, pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ], 0.0, 0.0, 0.0, 4.5);
			Info(playerid, "Private Farm milikmu yang berlokasi di %s telah di tandai", GetLocation(pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]));
		}
		return 1;
	}
	if(dialogid == PFARM_SEEDS)
	{
		new pfid = pData[playerid][pGetPFARM];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Seeds kamu: %d.\n\nMasukkan berapa banyak Seeds yang akan kamu simpan di farmer ini", pData[playerid][pSeed]);
					ShowPlayerDialog(playerid, PFARM_DEPOSIT_SEEDS, DIALOG_STYLE_INPUT, "Deposit", mstr, "Deposit", "Back");
				}
				case 1:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Seeds Vault: %d\n\nMasukkan berapa banyak Seeds yang akan kamu ambil dari farmer ini", pfData[pfid][pfSeeds]);
					ShowPlayerDialog(playerid, PFARM_WITHDRAW_SEEDS, DIALOG_STYLE_INPUT,"Withdraw", mstr,"Withdraw","Back");
				}
			}
		}
		return 1;
	}
	if(dialogid == PFARM_POTATO)
	{
		new pfid = pData[playerid][pGetPFARM];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Potato kamu: %d.\n\nMasukkan berapa banyak Potato yang akan kamu simpan di farmer ini", pData[playerid][pPotato]);
					ShowPlayerDialog(playerid, PFARM_DEPOSIT_POTATO, DIALOG_STYLE_INPUT, "Deposit", mstr, "Deposit", "Back");
				}
				case 1:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Potato Vault: %d\n\nMasukkan berapa banyak Potato yang akan kamu ambil dari farmer ini", pfData[pfid][pfPotato]);
					ShowPlayerDialog(playerid, PFARM_WITHDRAW_POTATO, DIALOG_STYLE_INPUT,"Withdraw", mstr,"Withdraw","Back");
				}
			}
		}
		return 1;
	}
	if(dialogid == PFARM_ORANGE)
	{
		new pfid = pData[playerid][pGetPFARM];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Orange kamu: %d.\n\nMasukkan berapa banyak Orange yang akan kamu simpan di farmer ini", pData[playerid][pOrange]);
					ShowPlayerDialog(playerid, PFARM_DEPOSIT_ORANGE, DIALOG_STYLE_INPUT, "Deposit", mstr, "Deposit", "Back");
				}
				case 1:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Orange Vault: %d\n\nMasukkan berapa banyak Orange yang akan kamu ambil dari farmer ini", pfData[pfid][pfOrange]);
					ShowPlayerDialog(playerid, PFARM_WITHDRAW_ORANGE, DIALOG_STYLE_INPUT,"Withdraw", mstr,"Withdraw","Back");
				}
			}
		}
		return 1;
	}
	if(dialogid == PFARM_WHEAT)
	{
		new pfid = pData[playerid][pGetPFARM];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Wheat kamu: %d.\n\nMasukkan berapa banyak Wheat yang akan kamu simpan di farmer ini", pData[playerid][pWheat]);
					ShowPlayerDialog(playerid, PFARM_DEPOSIT_WHEAT, DIALOG_STYLE_INPUT, "Deposit", mstr, "Deposit", "Back");
				}
				case 1:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Wheat Vault: %d\n\nMasukkan berapa banyak Wheat yang akan kamu ambil dari farmer ini", pfData[pfid][pfWheat]);
					ShowPlayerDialog(playerid, PFARM_WITHDRAW_WHEAT, DIALOG_STYLE_INPUT,"Withdraw", mstr,"Withdraw","Back");
				}
			}
		}
		return 1;
	}
	if(dialogid == PFARM_WITHDRAW_SEEDS)
	{
		if(response)
		{
			new pfid = pData[playerid][pGetPFARM];
			new amount = floatround(strval(inputtext));

			if(amount < 1 || amount > pfData[pfid][pfSeeds])
				return Error(playerid, "Invalid amount specified!");

			pfData[pfid][pfSeeds] -= amount;
			Pfarm_Save(pfid);

			pData[playerid][pSeed] += amount;

			SendClientMessageEx(playerid, COLOR_GREEN,"FARM: "WHITE_E"You have withdrawn "GREEN_E"%d"WHITE_E" seeds from the farm vault.", amount);
		}
		else
			ShowPlayerDialog(playerid, PFARM_SEEDS, DIALOG_STYLE_LIST,"Farmer Vault","Deposit Seeds\nWithdraw Seeds","Next","Back");
		return 1;
	}
	if(dialogid == PFARM_DEPOSIT_SEEDS)
	{
		if(response)
		{
			new pfid = pData[playerid][pGetPFARM];
			new amount = floatround(strval(inputtext));
			new maxdp = pData[playerid][pSeed] + amount;

			if(amount < 1 || amount > pData[playerid][pSeed])
				return Error(playerid, "Invalid amount specified!");

			if(maxdp > 1000)
				return Error(playerid, "Anda tidak bisa memasukan seeds lebih dari batas slot");

			pfData[pfid][pfSeeds] += amount;
			Pfarm_Save(pfid);

			pData[playerid][pSeed] -= amount;
			
			SendClientMessageEx(playerid, COLOR_GREEN,"FARM: "WHITE_E"You have deposit "GREEN_E"%d"WHITE_E" seeds into the farm vault.", amount);
		}
		else
			ShowPlayerDialog(playerid, PFARM_SEEDS, DIALOG_STYLE_LIST,"Farmer Vault","Deposit Seeds\nWithdraw Seeds","Next","Back");
		return 1;
	}
	if(dialogid == PFARM_WITHDRAW_POTATO)
	{
		if(response)
		{
			new pfid = pData[playerid][pGetPFARM];
			new amount = floatround(strval(inputtext));

			if(amount < 1 || amount > pfData[pfid][pfPotato])
				return Error(playerid, "Invalid amount specified!");

			pfData[pfid][pfPotato] -= amount;
			Pfarm_Save(pfid);

			pData[playerid][pPotato] += amount;

			SendClientMessageEx(playerid, COLOR_GREEN,"FARM: "WHITE_E"You have withdrawn "GREEN_E"%d"WHITE_E" potato from the farm vault.", amount);
		}
		else
			ShowPlayerDialog(playerid, PFARM_POTATO, DIALOG_STYLE_LIST,"Farmer Vault","Deposit Potato\nWithdraw Potato","Next","Back");
		return 1;
	}
	if(dialogid == PFARM_DEPOSIT_POTATO)
	{
		if(response)
		{
			new pfid = pData[playerid][pGetPFARM];
			new amount = floatround(strval(inputtext));
			new maxdp = pData[playerid][pPotato] + amount;

			if(amount < 1 || amount > pData[playerid][pPotato])
				return Error(playerid, "Invalid amount specified!");

			if(maxdp > 500)
				return Error(playerid, "Anda tidak bisa memasukan potato lebih dari batas slot");

			pfData[pfid][pfPotato] += amount;
			Pfarm_Save(pfid);

			pData[playerid][pPotato] -= amount;
			
			SendClientMessageEx(playerid, COLOR_GREEN,"FARM: "WHITE_E"You have deposit "GREEN_E"%d"WHITE_E" potato into the farm vault.", amount);
		}
		else
			ShowPlayerDialog(playerid, PFARM_POTATO, DIALOG_STYLE_LIST,"Farmer Vault","Deposit Potato\nWithdraw Potato","Next","Back");
		return 1;
	}
	if(dialogid == PFARM_WITHDRAW_ORANGE)
	{
		if(response)
		{
			new pfid = pData[playerid][pGetPFARM];
			new amount = floatround(strval(inputtext));

			if(amount < 1 || amount > pfData[pfid][pfOrange])
				return Error(playerid, "Invalid amount specified!");

			pfData[pfid][pfOrange] -= amount;
			Pfarm_Save(pfid);

			pData[playerid][pOrange] += amount;

			SendClientMessageEx(playerid, COLOR_GREEN,"FARM: "WHITE_E"You have withdrawn "GREEN_E"%d"WHITE_E" orange from the farm vault.", amount);
		}
		else
			ShowPlayerDialog(playerid, PFARM_ORANGE, DIALOG_STYLE_LIST,"Farmer Vault","Deposit Orange\nWithdraw Orange","Next","Back");
		return 1;
	}
	if(dialogid == PFARM_DEPOSIT_ORANGE)
	{
		if(response)
		{
			new pfid = pData[playerid][pGetPFARM];
			new amount = floatround(strval(inputtext));
			new maxdp = pData[playerid][pOrange] + amount;

			if(amount < 1 || amount > pData[playerid][pOrange])
				return Error(playerid, "Invalid amount specified!");

			if(maxdp > 250)
				return Error(playerid, "Anda tidak bisa memasukan orange lebih dari batas slot");

			pfData[pfid][pfOrange] += amount;
			Pfarm_Save(pfid);

			pData[playerid][pOrange] -= amount;
			
			SendClientMessageEx(playerid, COLOR_GREEN,"FARM: "WHITE_E"You have deposit "GREEN_E"%d"WHITE_E" orange into the farm vault.", amount);
		}
		else
			ShowPlayerDialog(playerid, PFARM_ORANGE, DIALOG_STYLE_LIST,"Farmer Vault","Deposit Orange\nWithdraw Orange","Next","Back");
		return 1;
	}
	if(dialogid == PFARM_WITHDRAW_WHEAT)
	{
		if(response)
		{
			new pfid = pData[playerid][pGetPFARM];
			new amount = floatround(strval(inputtext));

			if(amount < 1 || amount > pfData[pfid][pfWheat])
				return Error(playerid, "Invalid amount specified!");

			pfData[pfid][pfWheat] -= amount;
			Pfarm_Save(pfid);

			pData[playerid][pWheat] += amount;

			SendClientMessageEx(playerid, COLOR_GREEN,"FARM: "WHITE_E"You have withdrawn "GREEN_E"%d"WHITE_E" wheat from the farm vault.", amount);
		}
		else
			ShowPlayerDialog(playerid, PFARM_WHEAT, DIALOG_STYLE_LIST,"Farmer Vault","Deposit Wheat\nWithdraw Wheat","Next","Back");
		return 1;
	}
	if(dialogid == PFARM_DEPOSIT_WHEAT)
	{
		if(response)
		{
			new pfid = pData[playerid][pGetPFARM];
			new amount = floatround(strval(inputtext));
			new maxdp = pData[playerid][pOrange] + amount;

			if(amount < 1 || amount > pData[playerid][pWheat])
				return Error(playerid, "Invalid amount specified!");

			if(maxdp > 500)
				return Error(playerid, "Anda tidak bisa memasukan wheat lebih dari batas slot");

			pfData[pfid][pfWheat] += amount;
			Pfarm_Save(pfid);

			pData[playerid][pWheat] -= amount;
			
			SendClientMessageEx(playerid, COLOR_GREEN,"FARM: "WHITE_E"You have deposit "GREEN_E"%d"WHITE_E" wheat into the farm vault.", amount);
		}
		else
			ShowPlayerDialog(playerid, PFARM_WHEAT, DIALOG_STYLE_LIST,"Farmer Vault","Deposit Wheat\nWithdraw Wheat","Next","Back");
		return 1;
	}
	//----------[ DEALER DIALOG ] -------------
	if(dialogid == DEALER_MENU)
	{
		new deid = pData[playerid][pGetDEID];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{	
					new mstr[248], lstr[512];
					format(mstr,sizeof(mstr),"Dealer ID %d", deid);
					format(lstr,sizeof(lstr),"Dealer Name:\t%s\nDealer Product:\t%d\nDealer Money Vault:\t%s", drData[deid][dName], drData[deid][dStock], FormatMoney(drData[deid][dMoney]));
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, mstr, lstr,"Back","Close");
				}
				case 1:
				{
					new mstr[248];
					format(mstr,sizeof(mstr),"Nama sebelumnya: %s\n\nMasukkan nama dealer yang kamu inginkan\nMaksimal 32 karakter untuk nama bisnis", drData[deid][dName]);
					ShowPlayerDialog(playerid, DEALER_NAME, DIALOG_STYLE_INPUT,"Dealer Name", mstr,"Done","Back");
				}
				case 2: ShowPlayerDialog(playerid, DEALER_VAULT, DIALOG_STYLE_LIST,"Dealer Vault","Deposit\nWithdraw","Next","Back");
				case 3:
				{
					Dealer_ProductMenu(playerid, deid);
				}
			}
		}
		return 1;
	}
	if(dialogid == DEALER_NAME)
	{
		if(response)
		{
			new deid = pData[playerid][pGetDEID];

			if(!Player_OwnsDealer(playerid, pData[playerid][pGetDEID])) return Error(playerid, "You don't own this dealer.");
			
			if (isnull(inputtext))
			{
				new mstr[512];
				format(mstr,sizeof(mstr),""RED_E"NOTE: "WHITE_E"Nama Dealer tidak di perbolehkan kosong!\n\n"WHITE_E"Nama sebelumnya: %s\n\nMasukkan nama Bisnis yang kamu inginkan\nMaksimal 32 karakter untuk nama Bisnis", drData[deid][dName]);
				ShowPlayerDialog(playerid, DEALER_NAME, DIALOG_STYLE_INPUT,"Dealer Name", mstr,"Done","Back");
				return 1;
			}
			if(strlen(inputtext) > 32 || strlen(inputtext) < 5)
			{
				new mstr[512];
				format(mstr,sizeof(mstr),""RED_E"NOTE: "WHITE_E"Nama Dealer harus 5 sampai 32 karakter.\n\n"WHITE_E"Nama sebelumnya: %s\n\nMasukkan nama Bisnis yang kamu inginkan\nMaksimal 32 karakter untuk nama Bisnis", drData[deid][dName]);
				ShowPlayerDialog(playerid, DEALER_NAME, DIALOG_STYLE_INPUT,"Dealer Name", mstr,"Done","Back");
				return 1;
			}
			format(drData[deid][dName], 32, ColouredText(inputtext));

			Dealer_Refresh(deid);
			Dealer_Save(deid);

			Servers(playerid, "Dealer name set to: \"%s\".", drData[deid][dName]);
		}
		else return callcmd::dem(playerid, "");
		return 1;
	}
	if(dialogid == DEALER_VAULT)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Uang kamu: %s.\n\nMasukkan berapa banyak uang yang akan kamu simpan di dalam dealer ini", FormatMoney(pData[playerid][pMoney]));
					ShowPlayerDialog(playerid, DEALER_DEPOSIT, DIALOG_STYLE_INPUT, "Deposit", mstr, "Deposit", "Back");
				}
				case 1:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Dealer Vault: %s\n\nMasukkan berapa banyak uang yang akan kamu ambil di dalam dealer ini", FormatMoney(drData[pData[playerid][pGetDEID]][dMoney]));
					ShowPlayerDialog(playerid, DEALER_WITHDRAW, DIALOG_STYLE_INPUT,"Withdraw", mstr,"Withdraw","Back");
				}
			}
		}
		return 1;
	}
	if(dialogid == DEALER_WITHDRAW)
	{
		if(response)
		{
			new deid = pData[playerid][pGetDEID];
			new amount = floatround(strval(inputtext));
			if(amount < 1 || amount > drData[deid][dMoney])
				return Error(playerid, "Invalid amount specified!");

			drData[deid][dMoney] -= amount;
			Dealer_Save(deid);

			GivePlayerMoneyEx(playerid, amount);

			SendClientMessageEx(playerid, COLOR_LBLUE,"DEALER: "WHITE_E"You have withdrawn "GREEN_E"%s "WHITE_E"from the dealer vault.", FormatMoney(strval(inputtext)));
		}
		else
			ShowPlayerDialog(playerid, DEALER_VAULT, DIALOG_STYLE_LIST,"Dealer Vault","Deposit\nWithdraw","Next","Back");
		return 1;
	}
	if(dialogid == DEALER_DEPOSIT)
	{
		if(response)
		{
			new deid = pData[playerid][pGetDEID];
			new amount = floatround(strval(inputtext));
			if(amount < 1 || amount > pData[playerid][pMoney])
				return Error(playerid, "Invalid amount specified!");

			drData[deid][dMoney] += amount;
			Dealer_Save(deid);

			GivePlayerMoneyEx(playerid, -amount);
			
			SendClientMessageEx(playerid, COLOR_LBLUE,"DEALER: "WHITE_E"You have deposit "GREEN_E"%s "WHITE_E"into the dealer vault.", FormatMoney(strval(inputtext)));
		}
		else
			ShowPlayerDialog(playerid, DEALER_VAULT, DIALOG_STYLE_LIST,"Dealer Vault","Deposit\nWithdraw","Next","Back");
		return 1;
	}
	if(dialogid == DEALER_EDITPROD)
	{
		if(Player_OwnsDealer(playerid, pData[playerid][pGetDEID]))
		{
			if(response)
			{
				static
					item[40],
					str[128];

				strmid(item, inputtext, 0, strfind(inputtext, "-") - 1);
				strpack(pData[playerid][pEditingItem], item, 40 char);

				pData[playerid][pProductModify] = listitem;
				format(str,sizeof(str), "Please enter the new product price for %s:", item);
				ShowPlayerDialog(playerid, DEALER_SETPRICE, DIALOG_STYLE_INPUT, "Dealer: Set Price", str, "Modify", "Back");
			}
			else
				return callcmd::dem(playerid, "");
		}
		return 1;
	}
	if(dialogid == DEALER_SETPRICE)
	{
		static
        item[40];
		new deid = pData[playerid][pGetDEID];
		if(Player_OwnsDealer(playerid, pData[playerid][pGetDEID]))
		{
			if(response)
			{
				strunpack(item, pData[playerid][pEditingItem]);

				if(isnull(inputtext))
				{
					new str[128];
					format(str,sizeof(str), "Please enter the new product price for %s:", item);
					ShowPlayerDialog(playerid, DEALER_SETPRICE, DIALOG_STYLE_INPUT, "Dealer: Set Price", str, "Modify", "Back");
					return 1;
				}
				if(strval(inputtext) < 500 || strval(inputtext) > 500000)
				{
					new str[128];
					format(str,sizeof(str), "Please enter the new product price for %s ($500 to $500.000):", item);
					ShowPlayerDialog(playerid, DEALER_SETPRICE, DIALOG_STYLE_INPUT, "Dealer: Set Price", str, "Modify", "Back");
					return 1;
				}
				drData[deid][dP][pData[playerid][pProductModify]] = strval(inputtext);
				Dealer_Save(deid);

				Servers(playerid, "You have adjusted the price of %s to: %s!", item, FormatMoney(strval(inputtext)));
				Dealer_ProductMenu(playerid, deid);
			}
			else
			{
				Dealer_ProductMenu(playerid, deid);
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_MY_DEALER)
	{
		if(!response) return 1;
		SetPVarInt(playerid, "ClickedDealer", ReturnPlayerDealerID(playerid, (listitem + 1)));
		ShowPlayerDialog(playerid, DEALER_INFO, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo {0000FF}Dealer", "Show Information\nTrack Dealer", "Select", "Cancel");
		return 1;
	}
	if(dialogid == DEALER_INFO)
	{
		if(!response) return 1;
		new deid = GetPVarInt(playerid, "ClickedDealer");
		switch(listitem)
		{
			case 0:
			{
				new line9[900], type[128];
				if(drData[deid][dType] == 1)
				{
					type = "Bikes Vehicles";
				}
				else if(drData[deid][dType] == 2)
				{
					type = "Cars";
				}
				else if(drData[deid][dType] == 3)
				{
					type = "Unique Cars";
				}
				else if(drData[deid][dType] == 4)
				{
					type = "Job Cars";
				}
				else if(drData[deid][dType] == 5)
				{
					type = "Rental Jobs";
				}
				else
				{
					type = "Unknown";
				}
				format(line9, sizeof(line9), "Dealer ID: %d\nDealer Owner: %s\nDealer Address: %s\nDealer Type: %s",
				deid, drData[deid][dOwner], GetLocation(drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]), type);

				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Dealer Info", line9, "Close","");
			}
			case 1:
			{
				SetPlayerRaceCheckpoint(playerid, 1, drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ], 0.0, 0.0, 0.0, 3.5);
				Info(playerid, "Ikuti checkpoint untuk menemukan dealer anda!");
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SELL_DEALER)
	{
		if(!response) return 1;
		new str[248];
		SetPVarInt(playerid, "SellingDealer", ReturnPlayerDealerID(playerid, (listitem + 1)));
		format(str, sizeof(str), "Are you sure you will sell dealer id: %d", GetPVarInt(playerid, "SellingDealer"));
				
		ShowPlayerDialog(playerid, DIALOG_SELL_DEALER2, DIALOG_STYLE_MSGBOX, "Sell Dealer", str, "Sell", "Cancel");
	}
	if(dialogid == DIALOG_SELL_DEALER2)
	{
		if(response)
		{
			new deid = GetPVarInt(playerid, "SellingDealer"), price;
			price = drData[deid][dPrice] / 2;
			GivePlayerMoneyEx(playerid, price);
			Info(playerid, "Anda berhasil menjual dealer id (%d) dengan setengah harga("LG_E"%s"WHITE_E") pada saat anda membelinya.", deid, FormatMoney(price));
			Dealer_Reset(deid);
			Dealer_Save(deid);
			Dealer_Refresh(deid);
		}
		DeletePVar(playerid, "SellingDealer");
		return 1;
	}
	//------------[ VEHICLE STORAGE]-------
	if(dialogid == VEHICLE_STORAGE)
	{
		new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					Vehicle_WeaponStorage(playerid, vehid);
				}
				case 1:
				{
					ShowPlayerDialog(playerid, VEHICLE_MONEY, DIALOG_STYLE_LIST, "Money Storage", "Deposit Money\nWithdraw Money", "Select", "Back");
				}
				case 2:
				{
					ShowPlayerDialog(playerid, VEHICLE_COMPONENT, DIALOG_STYLE_LIST, "Component Storage", "Deposit Component\nWithdraw Component", "Select", "Back");
				}
				case 3:
				{
					ShowPlayerDialog(playerid, VEHICLE_MATERIAL, DIALOG_STYLE_LIST, "Material Storage", "Deposit Material\nWithdraw Material", "Select", "Back");
				}
				case 4:
				{
					ShowPlayerDialog(playerid, VEHICLE_SEED, DIALOG_STYLE_LIST, "Seed Storage", "Deposit Seed\nWithdraw Seed", "Select", "Back");
				}
				case 5:
				{
					ShowPlayerDialog(playerid, VEHICLE_MARIJUANA, DIALOG_STYLE_LIST, "Marijuana Storage", "Deposit Marijuana\nWithdraw Marijuana", "Select", "Back");
				}
				case 6:
				{
					ShowPlayerDialog(playerid, VEHICLE_TEMBAGA, DIALOG_STYLE_LIST, "Tembaga Storage", "Deposit Tembaga\nWithdraw Tembaga", "Select", "Back");
				}
				case 7:
				{
					ShowPlayerDialog(playerid, VEHICLE_BESI, DIALOG_STYLE_LIST, "Besi Storage", "Deposit Besi\nWithdraw Besi", "Select", "Back");
				}
				case 8:
				{
					ShowPlayerDialog(playerid, VEHICLE_EMAS, DIALOG_STYLE_LIST, "Emas Storage", "Deposit Emas\nWithdraw Emas", "Select", "Back");
				}
				case 9:
				{
					ShowPlayerDialog(playerid, VEHICLE_BERLIAN, DIALOG_STYLE_LIST, "Berlian Storage", "Deposit Berlian\nWithdraw Berlian", "Select", "Back");
				}
			}
		}
		else SwitchVehicleBoot(vehid, false);
		return 1;
	}
	if(dialogid == VEHICLE_WEAPONS)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						if(pvData[i][cGun][listitem] != 0)
						{
							if(PlayerHasWeapon(playerid, pvData[i][cGun][listitem]))
								return Error(playerid, "Kamu sudah memiliki senjata tersebut");

							GivePlayerWeaponEx(playerid, pvData[i][cGun][listitem], pvData[i][cAmmo][listitem]);

							SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has taken a \"%s\" from vehicle storage.", ReturnName(playerid), ReturnWeaponName(pvData[i][cGun][listitem]));

							pvData[i][cGun][listitem] = 0;
							pvData[i][cAmmo][listitem] = 0;

							Vehicle_WeaponStorage(playerid, vehid);
						}
						else
						{
							new
								weaponid = GetPlayerWeaponEx(playerid),
								ammo = GetPlayerAmmoEx(playerid);

							if(!weaponid)
								return Error(playerid, "You are not holding any weapon!");

							ResetWeapon(playerid, weaponid);
							SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has stored a \"%s\" into vehicle storage.", ReturnName(playerid), ReturnWeaponName(weaponid));

							pvData[i][cGun][listitem] = weaponid;
							pvData[i][cAmmo][listitem] = ammo;
							
							Vehicle_WeaponStorage(playerid, vehid);
						}
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		return 1;
	}
	if(dialogid == VEHICLE_MONEY)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						switch (listitem)
						{
							case 0: 
							{
								new str[128];
								format(str, sizeof(str), "Money Balance: %s/$100.000\n\nMasukan berapa banyak uang yang ingin kamu taruh:", FormatMoney(pvData[i][cMoney]));
								ShowPlayerDialog(playerid, VEHICLE_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit Money", str, "Deposit", "Back");
							}
							case 1: 
							{
								new str[128];
								format(str, sizeof(str), "Money Balance: %s\n\nMasukan berapa banyak uang yang ingin kamu withdraw:", FormatMoney(pvData[i][cMoney]));
								ShowPlayerDialog(playerid, VEHICLE_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw Money", str, "Withdraw", "Back");
							}
						}
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		return 1;
	}
	if(dialogid == VEHICLE_DEPOSITMONEY)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Money Balance: %s\n\nMasukan berapa banyak uang yang ingin kamu deposit:", FormatMoney(pvData[i][cMoney]));
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit Money", str, "Deposit", "Back");
							return 1;
						}
						if(amount < 1 || amount > pData[playerid][pMoney])
						{
							new str[128];
							format(str, sizeof(str), "Error: Kamu tidak memiliki uang sebanyak itu.\n\nMoney Balance: %s/$100.000\n\nMasukan berapa banyak uang yang ingin kamu deposit:", FormatMoney(pvData[i][cMoney]));
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit Money", str, "Deposit", "Back");
							return 1;
						}
						new maxmoney = pvData[i][cMoney] + amount;
						if(maxmoney > 100000)
						{
							new str[128];
							format(str, sizeof(str), "Error: Anda tidak bisa memasukan uang lebih dari batas slot.\n\nMoney Balance: %s/$100.000\n\nMasukan berapa banyak uang yang ingin kamu deposit:", FormatMoney(pvData[i][cMoney]));
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit Component", str, "Deposit", "Back");
							return 1;
						}
						pvData[i][cMoney] += amount;
						GivePlayerMoneyEx(playerid, -amount);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %s money into their vehicle storage.", ReturnName(playerid), FormatMoney(amount));
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_MONEY, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Money\nWithdraw Money", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_WITHDRAWMONEY)
	{	
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Money Balance: %s\n\nMasukan berapa banyak uang yang ingin kamu withdraw:", FormatMoney(pvData[i][cMoney]));
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw Money", str, "Withdraw", "Back");
							return 1;
						}
						if(amount < 1 || amount > pvData[i][cMoney])
						{
							new str[128];
							format(str, sizeof(str), "Error: Dana tidak mencukupi.\n\nMoney Balance: %s\n\nMasukan berapa banyak uang yang ingin kamu withdraw:", FormatMoney(pvData[i][cMoney]));
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw Money", str, "Withdraw", "Back");
							return 1;
						}
						pvData[i][cMoney] -= amount;
						GivePlayerMoneyEx(playerid, amount);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %s money from their vehicle storage.", ReturnName(playerid), FormatMoney(amount));
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_MONEY, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Money\nWithdraw Money", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_COMPONENT)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						switch (listitem)
						{
							case 0: 
							{
								new str[128];
								format(str, sizeof(str), "Component balance: %d/2500\n\nMasukan berapa banyak component yang ingin kamu taruh:", pvData[i][cComponent]);
								ShowPlayerDialog(playerid, VEHICLE_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit Component", str, "Deposit", "Back");
							}
							case 1: 
							{
								new str[128];
								format(str, sizeof(str), "Component balance: %d\n\nMasukan berapa banyak component yang ingin kamu ambil:", pvData[i][cComponent]);
								ShowPlayerDialog(playerid, VEHICLE_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw Component", str, "Withdraw", "Back");
							}
						}
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		return 1;
	}
	if(dialogid == VEHICLE_DEPOSITCOMPONENT)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Component balance: %d/2500\n\nMasukan berapa banyak component yang ingin kamu deposit:", pvData[i][cComponent]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit Component", str, "Deposit", "Back");
							return 1;
						}
						if(amount < 1 || amount > Inventory_Count(playerid, "Component"))
						{
							new str[128];
							format(str, sizeof(str), "Error: Component yang anda miliki tidak mencukupi.\n\nComponent Balance: %d/2500\n\nMasukan berapa banyak component yang ingin kamu deposit:", pvData[i][cComponent]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit Component", str, "Deposit", "Back");
							return 1;
						}
						new maxmat = pvData[i][cComponent] + amount;
						if(maxmat > 2500)
						{
							new str[128];
							format(str, sizeof(str), "Error: Anda tidak bisa memasukan component lebih dari batas slot.\n\nComponent Balance: %d/2500\n\nMasukan berapa banyak component yang ingin kamu deposit:", pvData[i][cComponent]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit Component", str, "Deposit", "Back");
							return 1;
						}
						pvData[i][cComponent] += amount;
						Inventory_Remove(playerid, "Component", amount);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d component into their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_COMPONENT, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Component\nWithdraw Component", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_WITHDRAWCOMPONENT)
	{	
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Component Balance: %d\n\nMasukan berapa banyak component yang ingin kamu withdraw:", pvData[i][cComponent]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw Component", str, "Withdraw", "Back");
							return 1;
						}
						if(amount < 1 || amount > pvData[i][cComponent])
						{
							new str[128];
							format(str, sizeof(str), "Error: Insufficient funds.\n\nComponent Balance: %d\n\nMasukan berapa banyak component yang ingin kamu withdraw:", pvData[i][cComponent]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw Component", str, "Withdraw", "Back");
							return 1;
						}
						Inventory_Add(playerid, "Component", 19627, amount);
						pvData[i][cComponent] -= amount;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d component from their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_COMPONENT, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Component\nWithdraw Component", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_MATERIAL)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						switch (listitem)
						{
							case 0: 
							{
								new str[128];
								format(str, sizeof(str), "Material balance: %d/2500\n\nMasukan berapa banyak material yang ingin kamu taruh:", pvData[i][cMaterial]);
								ShowPlayerDialog(playerid, VEHICLE_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit Material", str, "Deposit", "Back");
							}
							case 1: 
							{
								new str[128];
								format(str, sizeof(str), "Material balance: %d\n\nMasukan berapa banyak material yang ingin kamu ambil:", pvData[i][cMaterial]);
								ShowPlayerDialog(playerid, VEHICLE_WITHDRAWMATERIAL, DIALOG_STYLE_INPUT, "Withdraw Material", str, "Withdraw", "Back");
							}
						}
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		return 1;
	}
	if(dialogid == VEHICLE_DEPOSITMATERIAL)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Material balance: %d\n\nMasukan berapa banyak material yang ingin kamu deposit:", pvData[i][cMaterial]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit Material", str, "Deposit", "Back");
							return 1;
						}
						if(amount < 1 || amount > Inventory_Count(playerid, "Material"))
						{
							new str[128];
							format(str, sizeof(str), "Error: Material yang anda miliki tidak mencukupi.\n\nMaterial Balance: %d/2500\n\nMasukan berapa banyak material yang ingin kamu deposit:", pvData[i][cMaterial]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit Material", str, "Deposit", "Back");
							return 1;
						}
						new maxmat = pvData[i][cMaterial] + amount;
						if(maxmat > 2500)
						{
							new str[128];
							format(str, sizeof(str), "Error: Anda tidak bisa memasukan material lebih dari batas slot.\n\nMaterial Balance: %d/2500\n\nMasukan berapa banyak material yang ingin kamu deposit:", pvData[i][cMaterial]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit Material", str, "Deposit", "Back");
							return 1;
						}
						pvData[i][cMaterial] += amount;
						Inventory_Remove(playerid, "Material", amount);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d material into their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_MATERIAL, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Material\nWithdraw Material", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_WITHDRAWMATERIAL)
	{	
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Material Balance: %d\n\nMasukan berapa banyak material yang ingin kamu withdraw:", pvData[i][cMaterial]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWMATERIAL, DIALOG_STYLE_INPUT, "Withdraw Material", str, "Withdraw", "Back");
							return 1;
						}
						if(amount < 1 || amount > pvData[i][cMaterial])
						{
							new str[128];
							format(str, sizeof(str), "Error: Insufficient funds.\n\nMaterial Balance: %d/2500\n\nMasukan berapa banyak material yang ingin kamu withdraw:", pvData[i][cMaterial]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWMATERIAL, DIALOG_STYLE_INPUT, "Withdraw Material", str, "Withdraw", "Back");
							return 1;
						}
						Inventory_Add(playerid, "Material", 17051, amount);
						pvData[i][cMaterial] -= amount;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d material from their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_MATERIAL, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Material\nWithdraw Material", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_SEED)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						switch (listitem)
						{
							case 0: 
							{
								new str[128];
								format(str, sizeof(str), "Seed balance: %d/1000\n\nMasukan berapa banyak seed yang ingin kamu taruh:", pvData[i][cSeed]);
								ShowPlayerDialog(playerid, VEHICLE_DEPOSITSEED, DIALOG_STYLE_INPUT, "Deposit Seed", str, "Deposit", "Back");
							}
							case 1: 
							{
								new str[128];
								format(str, sizeof(str), "Seed balance: %d\n\nMasukan berapa banyak seed yang ingin kamu ambil:", pvData[i][cSeed]);
								ShowPlayerDialog(playerid, VEHICLE_WITHDRAWSEED, DIALOG_STYLE_INPUT, "Withdraw Seed", str, "Withdraw", "Back");
							}
						}
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		return 1;
	}
	if(dialogid == VEHICLE_DEPOSITSEED)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Seed balance: %d/1000\n\nMasukan berapa banyak seed yang ingin kamu deposit:", pvData[i][cSeed]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITSEED, DIALOG_STYLE_INPUT, "Deposit Seed", str, "Deposit", "Back");
							return 1;
						}
						if(amount < 1 || amount > pData[playerid][pSeed])
						{
							new str[128];
							format(str, sizeof(str), "Error: Seed yang anda miliki tidak mencukupi.\n\nSeed Balance: %d/1000\n\nMasukan berapa banyak seed yang ingin kamu deposit:", pvData[i][cSeed]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITSEED, DIALOG_STYLE_INPUT, "Deposit Seed", str, "Deposit", "Back");
							return 1;
						}
						new maxseed = pvData[i][cSeed] + amount;
						if(maxseed > 1000)
						{
							new str[128];
							format(str, sizeof(str), "Error: Anda tidak bisa memasukan seed lebih dari batas slot.\n\nSeed Balance: %d/1000\n\nMasukan berapa banyak seed yang ingin kamu deposit:", pvData[i][cSeed]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITSEED, DIALOG_STYLE_INPUT, "Deposit Seed", str, "Deposit", "Back");
							return 1;
						}
						pvData[i][cSeed] += amount;
						pData[playerid][pSeed] -= amount;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d seed into their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_SEED, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Seed\nWithdraw Seed", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_WITHDRAWSEED)
	{	
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Seed Balance: %d\n\nMasukan berapa banyak seed yang ingin kamu withdraw:", pvData[i][cSeed]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWSEED, DIALOG_STYLE_INPUT, "Withdraw Seed", str, "Withdraw", "Back");
							return 1;
						}
						if(amount < 1 || amount > pvData[i][cSeed])
						{
							new str[128];
							format(str, sizeof(str), "Error: Insufficient funds.\n\nSeed Balance: %d\n\nMasukan berapa banyak seed yang ingin kamu withdraw:", pvData[i][cSeed]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWSEED, DIALOG_STYLE_INPUT, "Withdraw Seed", str, "Withdraw", "Back");
							return 1;
						}
						pData[playerid][pSeed] += amount;
						pvData[i][cSeed] -= amount;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d seed from their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_SEED, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Seed\nWithdraw Seed", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_MARIJUANA)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						switch (listitem)
						{
							case 0: 
							{
								new str[128];
								format(str, sizeof(str), "Marijuana balance: %dkg/100kg\n\nMasukan berapa banyak marijuana yang ingin kamu taruh:", pvData[i][cMarijuana]);
								ShowPlayerDialog(playerid, VEHICLE_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit Marijuana", str, "Deposit", "Back");
							}
							case 1: 
							{
								new str[128];
								format(str, sizeof(str), "Marijuana balance: %dkg\n\nMasukan berapa banyak marijuana yang ingin kamu ambil:", pvData[i][cMarijuana]);
								ShowPlayerDialog(playerid, VEHICLE_WITHDRAWMARIJUANA, DIALOG_STYLE_INPUT, "Withdraw Marijuana", str, "Withdraw", "Back");
							}
						}
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		return 1;
	}
	if(dialogid == VEHICLE_DEPOSITMARIJUANA)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Marijuana balance: %dkg/100kg\n\nMasukan berapa banyak marijuana yang ingin kamu deposit:", pvData[i][cMarijuana]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit Marijuana", str, "Deposit", "Back");
							return 1;
						}
						if(amount < 1 || amount > Inventory_Count(playerid, "Marijuana"))
						{
							new str[128];
							format(str, sizeof(str), "Error: Marijuana yang anda miliki tidak mencukupi.\n\nMarijuana Balance: %dkg/100kg\n\nMasukan berapa banyak marijuana yang ingin kamu deposit:", pvData[i][cMarijuana]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit Marijuana", str, "Deposit", "Back");
							return 1;
						}
						new maxmarijuana = pvData[i][cMarijuana] + amount;
						if(maxmarijuana > 500)
						{
							new str[128];
							format(str, sizeof(str), "Error: Anda tidak bisa memasukan marijuana lebih dari batas slot.\n\nMarijuana Balance: %dkg/100kg\n\nMasukan berapa banyak marijuana yang ingin kamu deposit:", pvData[i][cMarijuana]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit Marijuana", str, "Deposit", "Back");
							return 1;
						}
						pvData[i][cMarijuana] += amount;
						Inventory_Remove(playerid, "Marijuana", amount);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d marijuana into their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_MARIJUANA, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Marijuana\nWithdraw Marijuana", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_WITHDRAWMARIJUANA)
	{	
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Marijuana Balance: %dkg\n\nMasukan berapa banyak marijuana yang ingin kamu withdraw:", pvData[i][cMarijuana]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWMARIJUANA, DIALOG_STYLE_INPUT, "Withdraw Marijuana", str, "Withdraw", "Back");
							return 1;
						}
						if(amount < 1 || amount > pvData[i][cMarijuana])
						{
							new str[128];
							format(str, sizeof(str), "Error: Insufficient funds.\n\nMarijuana Balance: %dkg\n\nMasukan berapa banyak marijuana yang ingin kamu withdraw:", pvData[i][cMarijuana]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWMARIJUANA, DIALOG_STYLE_INPUT, "Withdraw Marijuana", str, "Withdraw", "Back");
							return 1;
						}
						Inventory_Add(playerid, "Marijuana", 1578, amount);
						pvData[i][cMarijuana] -= amount;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d marijuana from their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_MARIJUANA, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Marijuana\nWithdraw Marijuana", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_TEMBAGA)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						switch (listitem)
						{
							case 0: 
							{
								new str[128];
								format(str, sizeof(str), "Tembaga Balance: %dkg/150kg\n\nMasukan berapa banyak Tembaga yang ingin kamu taruh:", pvData[i][cTembaga]);
								ShowPlayerDialog(playerid, VEHICLE_DEPOSITTEMBAGA, DIALOG_STYLE_INPUT, "Deposit Tembaga", str, "Deposit", "Back");
							}
							case 1: 
							{
								new str[128];
								format(str, sizeof(str), "Tembaga balance: %dkg\n\nMasukan berapa banyak Tembaga yang ingin kamu ambil:", pvData[i][cTembaga]);
								ShowPlayerDialog(playerid, VEHICLE_WITHDRAWTEMBAGA, DIALOG_STYLE_INPUT, "Withdraw Tembaga", str, "Withdraw", "Back");
							}
						}
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		return 1;
	}
	if(dialogid == VEHICLE_DEPOSITTEMBAGA)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Tembaga balance: %dkg/150kg\n\nMasukan berapa banyak Tembaga yang ingin kamu deposit:", pvData[i][cTembaga]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITTEMBAGA, DIALOG_STYLE_INPUT, "Deposit Tembaga", str, "Deposit", "Back");
							return 1;
						}
						if(amount < 1 || amount > Inventory_Count(playerid, "Tembaga"))
						{
							new str[128];
							format(str, sizeof(str), "Error: Tembaga yang anda miliki tidak mencukupi.\n\nTembaga Balance: %dkg/150kg\n\nMasukan berapa banyak Tembaga yang ingin kamu deposit:", pvData[i][cTembaga]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITTEMBAGA, DIALOG_STYLE_INPUT, "Deposit Tembaga", str, "Deposit", "Back");
							return 1;
						}
						new maxtembaga = pvData[i][cTembaga] + amount;
						if(maxtembaga > 150)
						{
							new str[128];
							format(str, sizeof(str), "Error: Anda tidak bisa memasukan Tembaga lebih dari batas slot.\n\nTembaga Balance: %dkg/150kg\n\nMasukan berapa banyak Tembaga yang ingin kamu deposit:", pvData[i][cTembaga]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITTEMBAGA, DIALOG_STYLE_INPUT, "Deposit Tembaga", str, "Deposit", "Back");
							return 1;
						}
						pvData[i][cTembaga] += amount;
						Inventory_Remove(playerid, "Tembaga", amount);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d Tembaga into their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_TEMBAGA, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Tembaga\nWithdraw Tembaga", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_WITHDRAWTEMBAGA)
	{	
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Tembaga Balance: %dkg\n\nMasukan berapa banyak Tembaga yang ingin kamu withdraw:", pvData[i][cTembaga]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWTEMBAGA, DIALOG_STYLE_INPUT, "Withdraw Tembaga", str, "Withdraw", "Back");
							return 1;
						}
						if(amount < 1 || amount > pvData[i][cTembaga])
						{
							new str[128];
							format(str, sizeof(str), "Error: Insufficient funds.\n\nTembaga Balance: %dkg\n\nMasukan berapa banyak Tembaga yang ingin kamu withdraw:", pvData[i][cTembaga]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWTEMBAGA, DIALOG_STYLE_INPUT, "Withdraw Tembaga", str, "Withdraw", "Back");
							return 1;
						}
						Inventory_Add(playerid, "Tembaga", 3929, amount);
						pvData[i][cTembaga] -= amount;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d tembaga from their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_TEMBAGA, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Tembaga\nWithdraw Tembaga", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_BESI)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						switch (listitem)
						{
							case 0: 
							{
								new str[128];
								format(str, sizeof(str), "Besi Balance: %dkg/150kg\n\nMasukan berapa banyak Besi yang ingin kamu taruh:", pvData[i][cBesi]);
								ShowPlayerDialog(playerid, VEHICLE_DEPOSITBESI, DIALOG_STYLE_INPUT, "Deposit Besi", str, "Deposit", "Back");
							}
							case 1: 
							{
								new str[128];
								format(str, sizeof(str), "Besi balance: %dkg\n\nMasukan berapa banyak Besi yang ingin kamu ambil:", pvData[i][cBesi]);
								ShowPlayerDialog(playerid, VEHICLE_WITHDRAWBESI, DIALOG_STYLE_INPUT, "Withdraw Besi", str, "Withdraw", "Back");
							}
						}
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		return 1;
	}
	if(dialogid == VEHICLE_DEPOSITBESI)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Besi balance: %dkg/150kg\n\nMasukan berapa banyak Besi yang ingin kamu deposit:", pvData[i][cBesi]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITBESI, DIALOG_STYLE_INPUT, "Deposit Besi", str, "Deposit", "Back");
							return 1;
						}
						if(amount < 1 || amount > Inventory_Count(playerid, "Besi"))
						{
							new str[128];
							format(str, sizeof(str), "Error: Besi yang anda miliki tidak mencukupi.\n\nBesi Balance: %dkg/150kg\n\nMasukan berapa banyak Besi yang ingin kamu deposit:", pvData[i][cBesi]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITBESI, DIALOG_STYLE_INPUT, "Deposit Besi", str, "Deposit", "Back");
							return 1;
						}
						new maxbesi = pvData[i][cBesi] + amount;
						if(maxbesi > 150)
						{
							new str[128];
							format(str, sizeof(str), "Error: Anda tidak bisa memasukan Besi lebih dari batas slot.\n\nBesi Balance: %dkg/150kg\n\nMasukan berapa banyak Besi yang ingin kamu deposit:", pvData[i][cBesi]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITBESI, DIALOG_STYLE_INPUT, "Deposit Besi", str, "Deposit", "Back");
							return 1;
						}
						pvData[i][cBesi] += amount;
						Inventory_Remove(playerid, "Besi", amount);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d Besi into their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_BESI, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Besi\nWithdraw Besi", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_WITHDRAWBESI)
	{	
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Besi Balance: %dkg\n\nMasukan berapa banyak Besi yang ingin kamu withdraw:", pvData[i][cBesi]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWBESI, DIALOG_STYLE_INPUT, "Withdraw Besi", str, "Withdraw", "Back");
							return 1;
						}
						if(amount < 1 || amount > pvData[i][cBesi])
						{
							new str[128];
							format(str, sizeof(str), "Error: Insufficient funds.\n\nTembaga Balance: %dkg\n\nMasukan berapa banyak Besi yang ingin kamu withdraw:", pvData[i][cBesi]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWBESI, DIALOG_STYLE_INPUT, "Withdraw Besi", str, "Withdraw", "Back");
							return 1;
						}
						Inventory_Add(playerid, "Besi", 19845, amount);
						pvData[i][cBesi] -= amount;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d besi from their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_BESI, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Besi\nWithdraw Besi", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_EMAS)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						switch (listitem)
						{
							case 0: 
							{
								new str[128];
								format(str, sizeof(str), "Emas Balance: %dkg/150kg\n\nMasukan berapa banyak Emas yang ingin kamu taruh:", pvData[i][cEmas]);
								ShowPlayerDialog(playerid, VEHICLE_DEPOSITEMAS, DIALOG_STYLE_INPUT, "Deposit Emas", str, "Deposit", "Back");
							}
							case 1: 
							{
								new str[128];
								format(str, sizeof(str), "Emas balance: %dkg\n\nMasukan berapa banyak Emas yang ingin kamu ambil:", pvData[i][cEmas]);
								ShowPlayerDialog(playerid, VEHICLE_WITHDRAWEMAS, DIALOG_STYLE_INPUT, "Withdraw Emas", str, "Withdraw", "Back");
							}
						}
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		return 1;
	}
	if(dialogid == VEHICLE_DEPOSITEMAS)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Emas balance: %dkg/150kg\n\nMasukan berapa banyak Emas yang ingin kamu deposit:", pvData[i][cEmas]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITEMAS, DIALOG_STYLE_INPUT, "Deposit Emas", str, "Deposit", "Back");
							return 1;
						}
						if(amount < 1 || amount > Inventory_Count(playerid, "Emas"))
						{
							new str[128];
							format(str, sizeof(str), "Error: Emas yang anda miliki tidak mencukupi.\n\nEmas Balance: %dkg/150kg\n\nMasukan berapa banyak Emas yang ingin kamu deposit:", pvData[i][cEmas]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITEMAS, DIALOG_STYLE_INPUT, "Deposit Emas", str, "Deposit", "Back");
							return 1;
						}
						new maxemas = pvData[i][cEmas] + amount;
						if(maxemas > 150)
						{
							new str[128];
							format(str, sizeof(str), "Error: Anda tidak bisa memasukan Emas lebih dari batas slot.\n\nEmas Balance: %dkg/150kg\n\nMasukan berapa banyak Emas yang ingin kamu deposit:", pvData[i][cEmas]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITEMAS, DIALOG_STYLE_INPUT, "Deposit Emas", str, "Deposit", "Back");
							return 1;
						}
						pvData[i][cEmas] += amount;
						Inventory_Remove(playerid, "Emas", amount);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d Emas into their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_EMAS, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Emas\nWithdraw Emas", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_WITHDRAWEMAS)
	{	
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Emas Balance: %dkg\n\nMasukan berapa banyak Emas yang ingin kamu withdraw:", pvData[i][cEmas]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWEMAS, DIALOG_STYLE_INPUT, "Withdraw Emas", str, "Withdraw", "Back");
							return 1;
						}
						if(amount < 1 || amount > pvData[i][cEmas])
						{
							new str[128];
							format(str, sizeof(str), "Error: Insufficient funds.\n\nTembaga Balance: %dkg\n\nMasukan berapa banyak Emas yang ingin kamu withdraw:", pvData[i][cEmas]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWEMAS, DIALOG_STYLE_INPUT, "Withdraw Emas", str, "Withdraw", "Back");
							return 1;
						}
						Inventory_Add(playerid, "Emas", 19941, amount);
						pvData[i][cEmas] -= amount;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d Emas from their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_EMAS, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Emas\nWithdraw Emas", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_BERLIAN)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						switch (listitem)
						{
							case 0: 
							{
								new str[128];
								format(str, sizeof(str), "Berlian Balance: %dkg/150kg\n\nMasukan berapa banyak Berlian yang ingin kamu taruh:", pvData[i][cBerlian]);
								ShowPlayerDialog(playerid, VEHICLE_DEPOSITBERLIAN, DIALOG_STYLE_INPUT, "Deposit Berlian", str, "Deposit", "Back");
							}
							case 1: 
							{
								new str[128];
								format(str, sizeof(str), "Berlian balance: %dkg\n\nMasukan berapa banyak Berlian yang ingin kamu ambil:", pvData[i][cBerlian]);
								ShowPlayerDialog(playerid, VEHICLE_WITHDRAWBERLIAN, DIALOG_STYLE_INPUT, "Withdraw Berlian", str, "Withdraw", "Back");
							}
						}
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		return 1;
	}
	if(dialogid == VEHICLE_DEPOSITBERLIAN)
	{
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Berlian balance: %dkg/150kg\n\nMasukan berapa banyak Berlian yang ingin kamu deposit:", pvData[i][cBerlian]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITBERLIAN, DIALOG_STYLE_INPUT, "Deposit Berlian", str, "Deposit", "Back");
							return 1;
						}
						if(amount < 1 || amount > Inventory_Count(playerid, "Berlian"))
						{
							new str[128];
							format(str, sizeof(str), "Error: Berlian yang anda miliki tidak mencukupi.\n\nBerlian Balance: %dkg/150kg\n\nMasukan berapa banyak Berlian yang ingin kamu deposit:", pvData[i][cBerlian]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITBERLIAN, DIALOG_STYLE_INPUT, "Deposit Berlian", str, "Deposit", "Back");
							return 1;
						}
						new maxberlian = pvData[i][cBerlian] + amount;
						if(maxberlian > 150)
						{
							new str[128];
							format(str, sizeof(str), "Error: Anda tidak bisa memasukan Berlian lebih dari batas slot.\n\nBerlian Balance: %dkg/150kg\n\nMasukan berapa banyak Berlian yang ingin kamu deposit:", pvData[i][cBerlian]);
							ShowPlayerDialog(playerid, VEHICLE_DEPOSITBERLIAN, DIALOG_STYLE_INPUT, "Deposit Berlian", str, "Deposit", "Back");
							return 1;
						}
						pvData[i][cBerlian] += amount;
						Inventory_Remove(playerid, "Berlian", amount);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d Berlian into their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_BERLIAN, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Berlian\nWithdraw Berlian", "Select", "Back");
		return 1;
	}
	if(dialogid == VEHICLE_WITHDRAWBERLIAN)
	{	
		if(response)
		{
			new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			foreach(new i : PVehicles)
			{
				if(vehid == pvData[i][cVeh])
				{
					if(pvData[i][cOwner] == pData[playerid][pID])
					{
						new amount = strval(inputtext);
						if(isnull(inputtext))
						{
							new str[128];
							format(str, sizeof(str), "Berlian Balance: %dkg\n\nMasukan berapa banyak Berlian yang ingin kamu withdraw:", pvData[i][cBerlian]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWBERLIAN, DIALOG_STYLE_INPUT, "Withdraw Berlian", str, "Withdraw", "Back");
							return 1;
						}
						if(amount < 1 || amount > pvData[i][cBerlian])
						{
							new str[128];
							format(str, sizeof(str), "Error: Insufficient funds.\n\nTembaga Balance: %dkg\n\nMasukan berapa banyak Berlian yang ingin kamu withdraw:", pvData[i][cBerlian]);
							ShowPlayerDialog(playerid, VEHICLE_WITHDRAWBERLIAN, DIALOG_STYLE_INPUT, "Withdraw Berlian", str, "Withdraw", "Back");
							return 1;
						}
						Inventory_Add(playerid, "Berlian", 1559, amount);
						pvData[i][cBerlian] -= amount;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d Berlian from their vehicle storage.", ReturnName(playerid), amount);
					}
					else return Error(playerid, "kendaraan ini bukan milikmu.");
				}
			}
		}
		else return ShowPlayerDialog(playerid, VEHICLE_BERLIAN, DIALOG_STYLE_LIST, "Vehicle Storage", "Deposit Berlian\nWithdraw Berlian", "Select", "Back");
		return 1;
	}
	//-----------[ Bisnis Dialog ]------------
	if(dialogid == DIALOG_SELL_BISNISS)
	{
		if(!response) return 1;
		new str[248];
		SetPVarInt(playerid, "SellingBisnis", ReturnPlayerBisnisID(playerid, (listitem + 1)));
		format(str, sizeof(str), "Are you sure you will sell bisnis id: %d", GetPVarInt(playerid, "SellingBisnis"));
				
		ShowPlayerDialog(playerid, DIALOG_SELL_BISNIS, DIALOG_STYLE_MSGBOX, "Sell Bisnis", str, "Sell", "Batal");
	}
	if(dialogid == DIALOG_SELL_BISNIS)
	{
		if(response)
		{
			new bid = GetPVarInt(playerid, "SellingBisnis"), price;
			price = bData[bid][bPrice] / 2;
			GivePlayerMoneyEx(playerid, price);
			Info(playerid, "Anda berhasil menjual bisnis id (%d) dengan setengah harga("LG_E"%s"WHITE_E") pada saat anda membelinya.", bid, FormatMoney(price));
			Bisnis_Reset(bid);
			Bisnis_Save(bid);
			Bisnis_Refresh(bid);
		}
		DeletePVar(playerid, "SellingBisnis");
		return 1;
	}
	if(dialogid == DIALOG_MY_BISNIS)
	{
		if(!response) return true;
		SetPVarInt(playerid, "ClickedBisnis", ReturnPlayerBisnisID(playerid, (listitem + 1)));
		ShowPlayerDialog(playerid, BISNIS_INFO, DIALOG_STYLE_LIST, "{0000FF}My Business", "Show Information\nTrack Bisnis", "Pilih", "Batal");
		return 1;
	}
	if(dialogid == BISNIS_INFO)
	{
		if(!response) return true;
		new bid = GetPVarInt(playerid, "ClickedBisnis");
		switch(listitem)
		{
			case 0:
			{
				new line9[900];
				new lock[128], type[128];
				if(bData[bid][bLocked] == 1)
				{
					lock = "{FF0000}Locked";
			
				}
				else
				{
					lock = "{00FF00}Unlocked";
				}
				if(bData[bid][bType] == 1)
				{
					type = "Fast Food";
			
				}
				else if(bData[bid][bType] == 2)
				{
					type = "Market";
				}
				else if(bData[bid][bType] == 3)
				{
					type = "Clothes";
				}
				else if(bData[bid][bType] == 4)
				{
					type = "Equipment";
				}
				else
				{
					type = "Unknow";
				}
				format(line9, sizeof(line9), "Bisnis ID: %d\nBisnis Owner: %s\nBisnis Name: %s\nBisnis Price: %s\nBisnis Type: %s\nBisnis Status: %s\nBisnis Product: %d",
				bid, bData[bid][bOwner], bData[bid][bName], FormatMoney(bData[bid][bPrice]), type, lock, bData[bid][bProd]);

				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Bisnis Info", line9, "Tutup","");
			}
			case 1:
			{
				pData[playerid][pTrackBisnis] = 1;
				SetPlayerRaceCheckpoint(playerid,1, bData[bid][bExtposX], bData[bid][bExtposY], bData[bid][bExtposZ], 0.0, 0.0, 0.0, 3.5);
				//SetPlayerCheckpoint(playerid, bData[bid][bExtpos][0], bData[bid][bExtpos][1], bData[bid][bExtpos][2], 4.0);
				Info(playerid, "Ikuti checkpoint untuk menemukan bisnis anda!");
			}
		}
		return 1;
	}
	if(dialogid == BISNIS_MENU)
	{
		new bid = pData[playerid][pInBiz];
		new lock[128];
		if(bData[bid][bLocked] == 1)
		{
			lock = "Locked";
		}
		else
		{
			lock = "Unlocked";
		}
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{	
					new mstr[248], lstr[512];
					format(mstr,sizeof(mstr),"Bisnis ID %d", bid);
					format(lstr,sizeof(lstr),"Bisnis Name:\t%s\nBisnis Locked:\t%s\nBisnis Product:\t%d\nBisnis Vault:\t%s", bData[bid][bName], lock, bData[bid][bProd], FormatMoney(bData[bid][bMoney]));
					ShowPlayerDialog(playerid, BISNIS_INFO, DIALOG_STYLE_TABLIST, mstr, lstr,"Kembali","Tutup");
				}
				case 1:
				{
					new mstr[248];
					format(mstr,sizeof(mstr),"Nama sebelumnya: %s\n\nMasukkan nama bisnis yang kamu inginkan\nMaksimal 32 karakter untuk nama bisnis", bData[bid][bName]);
					ShowPlayerDialog(playerid, BISNIS_NAME, DIALOG_STYLE_INPUT,"Bisnis Name", mstr,"Done","Kembali");
				}
				case 2: ShowPlayerDialog(playerid, BISNIS_VAULT, DIALOG_STYLE_LIST,"Bisnis Vault","Deposit\nWithdraw","Next","Kembali");
				case 3:
				{
					Bisnis_ProductMenu(playerid, bid);
				}
				case 4:
				{
					if(bData[bid][bProd] > 100)
						return ErrorMsg(playerid, "Bisnis ini masih memiliki cukup product.");
					if(bData[bid][bMoney] < 1000)
						return ErrorMsg(playerid, "Setidaknya anda mempunyai uang dalam bisnis anda senilai $1.000 untuk merestock product.");
					bData[bid][bRestock] = 1;
					SuccesMsg(playerid, "Anda berhasil request untuk mengisi stock product kepada trucker, harap tunggu sampai pekerja trucker melayani.");
				}
			}
		}
		return 1;
	}
	if(dialogid == BISNIS_INFO)
	{
		if(response)
		{
			return callcmd::bm(playerid, "");
		}
		return 1;
	}
	if(dialogid == BISNIS_NAME)
	{
		if(response)
		{
			new bid = pData[playerid][pInBiz];

			if(!Player_OwnsBisnis(playerid, pData[playerid][pInBiz])) return ErrorMsg(playerid, "Anda bukan pemilik bisnis ini");
			
			if (isnull(inputtext))
			{
				new mstr[512];
				format(mstr,sizeof(mstr),""RED_E"NOTE: "WHITE_E"Nama Bisnis tidak di perbolehkan kosong!\n\n"WHITE_E"Nama sebelumnya: %s\n\nMasukkan nama Bisnis yang kamu inginkan\nMaksimal 32 karakter untuk nama Bisnis", bData[bid][bName]);
				ShowPlayerDialog(playerid, BISNIS_NAME, DIALOG_STYLE_INPUT,"Bisnis Name", mstr,"Done","Kembali");
				return 1;
			}
			if(strlen(inputtext) > 32 || strlen(inputtext) < 5)
			{
				new mstr[512];
				format(mstr,sizeof(mstr),""RED_E"NOTE: "WHITE_E"Nama Bisnis harus 5 sampai 32 karakter.\n\n"WHITE_E"Nama sebelumnya: %s\n\nMasukkan nama Bisnis yang kamu inginkan\nMaksimal 32 karakter untuk nama Bisnis", bData[bid][bName]);
				ShowPlayerDialog(playerid, BISNIS_NAME, DIALOG_STYLE_INPUT,"Bisnis Name", mstr,"Done","Kembali");
				return 1;
			}
			format(bData[bid][bName], 32, ColouredText(inputtext));

			new query[128];
			mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET name='%s' WHERE ID='%d'", bData[bid][bName], bid);
			mysql_tquery(g_SQL, query);

			Bisnis_Refresh(bid);

			Servers(playerid, "Bisnis name set to: \"%s\".", bData[bid][bName]);
		}
		else return callcmd::bm(playerid, "");
		return 1;
	}
	if(dialogid == BISNIS_VAULT)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Uang kamu: %s.\n\nMasukkan berapa banyak uang yang akan kamu simpan di dalam bisnis ini", FormatMoney(pData[playerid][pMoney]));
					ShowPlayerDialog(playerid, BISNIS_DEPOSIT, DIALOG_STYLE_INPUT, "Deposit", mstr, "Deposit", "Kembali");
				}
				case 1:
				{
					new mstr[512];
					format(mstr,sizeof(mstr),"Business Vault: %s\n\nMasukkan berapa banyak uang yang akan kamu ambil di dalam bisnis ini", FormatMoney(bData[pData[playerid][pInBiz]][bMoney]));
					ShowPlayerDialog(playerid, BISNIS_WITHDRAW, DIALOG_STYLE_INPUT,"Withdraw", mstr,"Withdraw","Kembali");
				}
			}
		}
		return 1;
	}
	if(dialogid == BISNIS_WITHDRAW)
	{
		if(response)
		{
			new bid = pData[playerid][pInBiz];
			new amount = floatround(strval(inputtext));
			if(amount < 1 || amount > bData[bid][bMoney])
				return ErrorMsg(playerid, "Jumlah uang salah");

			bData[bid][bMoney] -= amount;
			
			new query[128];
			mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET money='%d' WHERE ID='%d'", bData[bid][bMoney], bid);
			mysql_tquery(g_SQL, query);

			GivePlayerMoneyEx(playerid, amount);

			SendClientMessageEx(playerid, COLOR_LBLUE,"BUSINESS: "WHITE_E"You have withdrawn "GREEN_E"%s "WHITE_E"from the business vault.", FormatMoney(strval(inputtext)));
		}
		else
			ShowPlayerDialog(playerid, BISNIS_VAULT, DIALOG_STYLE_LIST,"Business Vault","Deposit\nWithdraw","Next","Kembali");
		return 1;
	}
	if(dialogid == BISNIS_DEPOSIT)
	{
		if(response)
		{
			new bid = pData[playerid][pInBiz];
			new amount = floatround(strval(inputtext));
			if(amount < 1 || amount > pData[playerid][pMoney])
				return ErrorMsg(playerid, "Jumlah uang salah");

			bData[bid][bMoney] += amount;

			new query[128];
			mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET money='%d' WHERE ID='%d'", bData[bid][bMoney], bid);
			mysql_tquery(g_SQL, query);

			GivePlayerMoneyEx(playerid, -amount);
			
			SendClientMessageEx(playerid, COLOR_LBLUE,"BUSINESS: "WHITE_E"You have deposit "GREEN_E"%s "WHITE_E"into the business vault.", FormatMoney(strval(inputtext)));
		}
		else
			ShowPlayerDialog(playerid, BISNIS_VAULT, DIALOG_STYLE_LIST,"Business Vault","Deposit\nWithdraw","Next","Kembali");
		return 1;
	}
	if(dialogid == BISNIS_BUYPROD)
	{
		static
        bizid = -1,
        price;

		if((bizid = pData[playerid][pInBiz]) != -1 && response)
		{
			price = bData[bizid][bP][listitem];

			if(pData[playerid][pMoney] < price)
				return ErrorMsg(playerid, "Uang anda tidak mencukupi");

			if(bData[bizid][bProd] < 1)
				return ErrorMsg(playerid, "Stock bisnis ini sudah habis");
				
			new Float:health;
			GetPlayerHealth(playerid,health);
			if(bData[bizid][bType] == 1)
			{
				switch(listitem)
				{
					case 0:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");

						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Wine", 1486, 1);
						SetPlayerChatBubble(playerid, "> Membeli Beer <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Wine");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 1:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Whiskey", 19824, 1);
						SetPlayerChatBubble(playerid, "> Membeli Beer <", COLOR_PURPLE, 10.0, 4000);
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);

						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 2:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Vodka", 1544, 1);
						SetPlayerChatBubble(playerid, "> Membeli Beer <", COLOR_PURPLE, 10.0, 4000);
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 3:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Blue Moon", 1517, 1);
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);

						Inventory_Add(playerid, "Water", 2958, 1);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli minuman seharga %s.", ReturnName(playerid), FormatMoney(price));
					}
				}
			}
			else if(bData[bizid][bType] == 2)
			{
				switch(listitem)
				{
					case 0:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Snack", 2768, 1);
						SetPlayerChatBubble(playerid, "> Membeli Snack <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Snack");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 1:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Sprunk", 2958, 1);
						SetPlayerChatBubble(playerid, "> Membeli Snack <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Sprunk");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 2:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Fuel Can", 1650, 1);
						SetPlayerChatBubble(playerid, "> Membeli Fuel Can <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Fuel Can");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 3:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Rokok", 19897, 1);
						SetPlayerChatBubble(playerid, "> Membeli Rokok <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Rokok");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 4:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");

						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Water", 2958, 1);
						SetPlayerChatBubble(playerid, "> Membeli Water <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Water");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);

						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
				}
			}
			else if(bData[bizid][bType] == 3)
			{
				switch(listitem)
				{
					case 0:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						switch(pData[playerid][pGender])
						{
							case 1: ShowPlayerSelectionMenu(playerid, SHOP_SKIN_MALE, "Choose Your Skin", ShopSkinMale, sizeof(ShopSkinMale));
							case 2: ShowPlayerSelectionMenu(playerid, SHOP_SKIN_FEMALE, "Choose Your Skin", ShopSkinFemale, sizeof(ShopSkinFemale));
						}
					}
					case 1:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
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
						ShowPlayerDialog(playerid, DIALOG_TOYBUY, DIALOG_STYLE_LIST, "Kampung Indo - Aksesoris", string, "Pilih", "Batal");
					}
					case 2:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						pData[playerid][pMask] = 1;
						pData[playerid][pMaskID] = random(90000) + 10000;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli mask seharga %s.", ReturnName(playerid), FormatMoney(price));
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 3:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						pData[playerid][pHelmet] = 1;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli Helmet seharga %s.", ReturnName(playerid), FormatMoney(price));
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
				}
			}
			else if(bData[bizid][bType] == 4)
			{
				switch(listitem)
				{
					case 0:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Skateboard", 19878, 1);
						SetPlayerChatBubble(playerid, "> Membeli Skateboard <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Skateboard");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 1:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
			
						if(pData[playerid][pJob] == 7 || pData[playerid][pJob2] == 7 || pData[playerid][pJob] == 11 || pData[playerid][pJob2] == 11)
						{
							GivePlayerMoneyEx(playerid, -price);
							GivePlayerWeaponEx(playerid, 4, 1);
							SetPlayerChatBubble(playerid, "> Membeli Knife <", COLOR_PURPLE, 10.0, 4000);
							SuccesMsg(playerid, "Berhasil membeli Knife");
							bData[bizid][bProd]--;
							bData[bizid][bMoney] += Server_Percent(price);
							Server_AddPercent(price);
						
							new query[128];
							mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
							mysql_tquery(g_SQL, query);
						}
						else return SyntaxMsg(playerid, "Anda harus bergabung dengan Job Ayam atau Farmer");
					}
					case 2:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						GivePlayerWeaponEx(playerid, 5, 1);
						SetPlayerChatBubble(playerid, "> Membeli Baseball Bat <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Baseball Bat");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 3:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						if(pData[playerid][pJob] == 5 || pData[playerid][pJob2] == 5)
						{
							GivePlayerMoneyEx(playerid, -price);
							GivePlayerWeaponEx(playerid, 6, 1);
							SetPlayerChatBubble(playerid, "> Membeli Shovel <", COLOR_PURPLE, 10.0, 4000);
							SuccesMsg(playerid, "Berhasil membeli Shovel");
							bData[bizid][bProd]--;
							bData[bizid][bMoney] += Server_Percent(price);
							Server_AddPercent(price);
						
							new query[128];
							mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
							mysql_tquery(g_SQL, query);
						}
						else return ErrorMsg(playerid, "Hanya untuk Job penambang");
					}
					case 4:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						if(pData[playerid][pJob] == 3 || pData[playerid][pJob2] == 3)
						{
							GivePlayerMoneyEx(playerid, -price);
							GivePlayerWeaponEx(playerid, 9, 1);
							SetPlayerChatBubble(playerid, "> Membeli Chainsaw <", COLOR_PURPLE, 10.0, 4000);
							SuccesMsg(playerid, "Berhasil membeli Chainsaw");
							bData[bizid][bProd]--;
							bData[bizid][bMoney] += Server_Percent(price);
							Server_AddPercent(price);
						
							new query[128];
							mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
							mysql_tquery(g_SQL, query);
						}
						else return ErrorMsg(playerid, "Hanya untuk Job LumberJack");
					}
					case 5:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						GivePlayerWeaponEx(playerid, 15, 1);
						SetPlayerChatBubble(playerid, "> Membeli Cane <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Cane");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 6:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						if(pData[playerid][pFishTool] > 2) return ErrorMsg(playerid, "Anda hanya dapat membeli 2 Fish Tool");
						GivePlayerMoneyEx(playerid, -price);
						pData[playerid][pFishTool]++;
						SetPlayerChatBubble(playerid, "> Membeli Fishing Tool <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Fishing Tool");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 7:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						pData[playerid][pWorm] += 2;
						SetPlayerChatBubble(playerid, "> Membeli Cacing <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Cacing");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 8:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");

						GivePlayerMoneyEx(playerid, -price);
						pData[playerid][pMask] = 1;
						pData[playerid][pMaskID] = random(90000) + 10000;
						SuccesMsg(playerid, "Berhasil membeli Masker");
						SyntaxMsg(playerid, "Gunakan /mask");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
				}
			}
			else if(bData[bizid][bType] == 5)
			{
				switch(listitem)
				{
					case 0:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
						
						if(pData[playerid][pPhone] == 0)
						{
							GivePlayerMoneyEx(playerid, -price);
							
							new query[128], rand = RandomEx(1111, 9888);
							new phone = rand+pData[playerid][pID];
							mysql_format(g_SQL, query, sizeof(query), "SELECT phone FROM players WHERE phone='%d'", phone);
							mysql_tquery(g_SQL, query, "PhoneNumber", "id", playerid, phone);
							
							Inventory_Add(playerid, "Phone", 18866, 1);
							pData[playerid][pPhone] = 1;
							SetPlayerChatBubble(playerid, "> Membeli Ponsel <", COLOR_PURPLE, 10.0, 4000);
							SuccesMsg(playerid, "Berhasil membeli Ponsel");
						}
						else
						{
							GivePlayerMoneyEx(playerid, -price);
							Inventory_Add(playerid, "Phone", 18866, 1);
							SetPlayerChatBubble(playerid, "> Membeli Ponsel <", COLOR_PURPLE, 10.0, 4000);
							SuccesMsg(playerid, "Berhasil membeli Ponsel");
						}
						
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new queryy[128];
						mysql_format(g_SQL, queryy, sizeof(queryy), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, queryy);
					}
					case 1:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						if(Inventory_Count(playerid, "Phone") < 1) return ErrorMsg(playerid, "Anda tidak memiliki ponsel");
						
						new query[128], rand = RandomEx(1111, 9888);
						new phone = rand+pData[playerid][pID];
						mysql_format(g_SQL, query, sizeof(query), "SELECT phone FROM players WHERE phone='%d'", phone);
						mysql_tquery(g_SQL, query, "PhoneNumber", "id", playerid, phone);
						SuccesMsg(playerid, "Nomor Ponsel anda berhasil di ubah");
						
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new queryy[128];
						mysql_format(g_SQL, queryy, sizeof(queryy), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, queryy);
					}
					case 2:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						pData[playerid][pPhoneCredit] += 20;
						SetPlayerChatBubble(playerid, "> Membeli Pulsa <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Ponsel Creadit sebanyak 20");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 3:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						pData[playerid][pPhoneBook] = 1;
						SetPlayerChatBubble(playerid, "> Membeli Phone Book <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Phone Book");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 4:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Portable Radio", 18868, 1);
						SetPlayerChatBubble(playerid, "> Membeli Portable Radio <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Portable Radio");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 5:
					{
						if(price == 0)
							return ErrorMsg(playerid, "Harga produk belum di setel oleh pemilik bisnis");
							
						GivePlayerMoneyEx(playerid, -price);
						pData[playerid][pKuota] += 10000000;
						SetPlayerChatBubble(playerid, "> Membeli Quota <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Quota sebanyak 10GB");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
					case 6:
					{
						if(pData[playerid][pVip] == 0 && pData[playerid][pVip] < 3) return ErrorMsg(playerid, "Hanya player VIP yang bisa mengakses ini");

						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Boombox", 2226, 1);
						SetPlayerChatBubble(playerid, "> Membeli Boombox <", COLOR_PURPLE, 10.0, 4000);
						SuccesMsg(playerid, "Berhasil membeli Boombox");
						bData[bizid][bProd]--;
						bData[bizid][bMoney] += Server_Percent(price);
						Server_AddPercent(price);
						
						new query[128];
						mysql_format(g_SQL, query, sizeof(query), "UPDATE bisnis SET prod='%d', money='%d' WHERE ID='%d'", bData[bizid][bProd], bData[bizid][bMoney], bizid);
						mysql_tquery(g_SQL, query);
					}
				}
			}	
		}
		return 1;
	}
	if(dialogid == BISNIS_EDITPROD)
	{
		if(Player_OwnsBisnis(playerid, pData[playerid][pInBiz]))
		{
			if(response)
			{
				static
					item[40],
					str[128];

				strmid(item, inputtext, 0, strfind(inputtext, "-") - 1);
				strpack(pData[playerid][pEditingItem], item, 40 char);

				pData[playerid][pProductModify] = listitem;
				format(str,sizeof(str), "Please enter the new product price for %s:", item);
				ShowPlayerDialog(playerid, BISNIS_PRICESET, DIALOG_STYLE_INPUT, "Business: Set Price", str, "Modify", "Kembali");
			}
			else
				return callcmd::bm(playerid, "");
		}
		return 1;
	}
	if(dialogid == BISNIS_PRICESET)
	{
		static
        item[40];
		new bizid = pData[playerid][pInBiz];
		if(Player_OwnsBisnis(playerid, pData[playerid][pInBiz]))
		{
			if(response)
			{
				strunpack(item, pData[playerid][pEditingItem]);

				if(isnull(inputtext))
				{
					new str[128];
					format(str,sizeof(str), "Please enter the new product price for %s:", item);
					ShowPlayerDialog(playerid, BISNIS_PRICESET, DIALOG_STYLE_INPUT, "Business: Set Price", str, "Modify", "Kembali");
					return 1;
				}
				if(strval(inputtext) < 1 || strval(inputtext) > 5000)
				{
					new str[128];
					format(str,sizeof(str), "Please enter the new product price for %s ($1 to $5,000):", item);
					ShowPlayerDialog(playerid, BISNIS_PRICESET, DIALOG_STYLE_INPUT, "Business: Set Price", str, "Modify", "Kembali");
					return 1;
				}
				bData[bizid][bP][pData[playerid][pProductModify]] = strval(inputtext);
				Bisnis_Save(bizid);

				Servers(playerid, "You have adjusted the price of %s to: %s!", item, FormatMoney(strval(inputtext)));
				Bisnis_ProductMenu(playerid, bizid);
			}
			else
			{
				Bisnis_ProductMenu(playerid, bizid);
			}
		}
		return 1;
	}
	//-----------[ House Dialog ]------------------
	if(dialogid == DIALOG_SELL_HOUSES)
	{
		if(!response) 
			return 1;
		
		new str[248];
		SetPVarInt(playerid, "SellingHouse", ReturnPlayerHousesID(playerid, (listitem + 1)));
		format(str, sizeof(str), "Are you sure you will sell house id: %d", GetPVarInt(playerid, "SellingHouse"));
				
		ShowPlayerDialog(playerid, DIALOG_SELL_HOUSE, DIALOG_STYLE_MSGBOX, "Sell House", str, "Sell", "Cancel");
	}
	if(dialogid == DIALOG_SELL_HOUSE)
	{
		if(response)
		{
			new hid = GetPVarInt(playerid, "SellingHouse"), price;

			if(hData[hid][hLocked] >= 2)
        		return Error(playerid, "Kamu tidak dapat menjual rumah yang sedang disegel oleh pemerintah");

			price = hData[hid][hPrice] / 2;
			GivePlayerMoneyEx(playerid, price);
			Info(playerid, "Anda berhasil menjual rumah id (%d) dengan setengah harga("LG_E"%s"WHITE_E") pada saat anda membelinya.", hid, FormatMoney(price));
			HouseReset(hid);
			House_Save(hid);
			House_Refresh(hid);
		}
		DeletePVar(playerid, "SellingHouse");
		return 1;
	}
	if(dialogid == DIALOG_MY_HOUSES)
	{
		if(!response) return 1;
		SetPVarInt(playerid, "ClickedHouse", ReturnPlayerHousesID(playerid, (listitem + 1)));
		ShowPlayerDialog(playerid, HOUSE_INFO, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo {0000FF}Houses", "Show Information\nTrack House", "Select", "Cancel");
		return 1;
	}
	if(dialogid == HOUSE_INFO)
	{
		if(!response) return 1;
		new hid = GetPVarInt(playerid, "ClickedHouse");
		switch(listitem)
		{
			case 0:
			{
				new line9[900];
				new lock[128], type[128];
				if(hData[hid][hLocked] == 0)
				{
					lock = ""GREEN_LIGHT"Unlocked"WHITE_E"";
				}
				else if(hData[hid][hLocked] == 1)
				{
					lock = ""RED_E"Locked"WHITE_E"";
				}
				else
				{
					lock = ""RED_E"Sealed"WHITE_E"";
				}
				if(hData[hid][hType] == 1)
				{
					type = "Low";
			
				}
				else if(hData[hid][hType] == 2)
				{
					type = "Medium";
				}
				else if(hData[hid][hType] == 3)
				{
					type = "High";
				}
				else
				{
					type = "Unknown";
				}
				format(line9, sizeof(line9), "House ID: %d\nHouse Owner: %s\nHouse Address: %s\nHouse Price: %s\nHouse Type: %s\nHouse Status: %s",
				hid, hData[hid][hOwner], hData[hid][hAddress], FormatMoney(hData[hid][hPrice]), type, lock);

				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "House Info", line9, "Close","");
			}
			case 1:
			{
				pData[playerid][pTrackHouse] = 1;
				SetPlayerRaceCheckpoint(playerid,1, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ], 0.0, 0.0, 0.0, 3.5);
				//SetPlayerCheckpoint(playerid, hData[hid][hExtpos][0], hData[hid][hExtpos][1], hData[hid][hExtpos][2], 4.0);
				Info(playerid, "Ikuti checkpoint untuk menemukan rumah anda!");
			}
		}
		return 1;
	}
	if(dialogid == HOUSE_STORAGE)
	{
		new hid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) 
			if(pData[playerid][pFaction] != 1)
				return Error(playerid, "You don't own this house.");
		if(response)
		{
			if(listitem == 0) 
			{
				House_WeaponStorage(playerid, hid);
			}
			else if(listitem == 1) 
			{
				ShowPlayerDialog(playerid, HOUSE_MONEY, DIALOG_STYLE_LIST, "Money Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
			else if(listitem == 2) 
			{
				ShowPlayerDialog(playerid, HOUSE_COMPONENT, DIALOG_STYLE_LIST, "Component Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
			else if(listitem == 3) 
			{
				ShowPlayerDialog(playerid, HOUSE_MATERIAL, DIALOG_STYLE_LIST, "Material Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
			else if(listitem == 4) 
			{
				ShowPlayerDialog(playerid, HOUSE_MARIJUANA, DIALOG_STYLE_LIST, "Marijuana Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
			else if(listitem == 5) 
			{
				ShowPlayerDialog(playerid, HOUSE_EPHEDRINE, DIALOG_STYLE_LIST, "Ephedrine Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
			else if(listitem == 6) 
			{
				ShowPlayerDialog(playerid, HOUSE_COCAINE, DIALOG_STYLE_LIST, "Cocaine Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
			else if(listitem == 7) 
			{
				ShowPlayerDialog(playerid, HOUSE_METH, DIALOG_STYLE_LIST, "Meth Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
		}
		return 1;
	}
	if(dialogid == HOUSE_WEAPONS)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) 
			if(pData[playerid][pFaction] != 1)
				return Error(playerid, "You don't own this house.");
				
		if(response)
		{
			if(hData[houseid][hWeapon][listitem] != 0)
			{
				if(PlayerHasWeapon(playerid, hData[houseid][hWeapon][listitem]))
					return Error(playerid, "Kamu sudah memiliki senjata tersebut");

				GivePlayerWeaponEx(playerid, hData[houseid][hWeapon][listitem], hData[houseid][hAmmo][listitem]);

				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has taken a \"%s\" from their weapon storage.", ReturnName(playerid), ReturnWeaponName(hData[houseid][hWeapon][listitem]));

				hData[houseid][hWeapon][listitem] = 0;
				hData[houseid][hAmmo][listitem] = 0;

				House_Save(houseid);
				House_WeaponStorage(playerid, houseid);
			}
			else
			{
				new
					weaponid = GetPlayerWeaponEx(playerid),
					ammo = GetPlayerAmmoEx(playerid);

				if(!weaponid)
					return Error(playerid, "You are not holding any weapon!");

				/*if(weaponid == 23 && pData[playerid][pTazer])
					return Error(playerid, "You can't store a tazer into your safe.");

				if(weaponid == 25 && pData[playerid][pBeanBag])
					return Error(playerid, "You can't store a beanbag shotgun into your safe.");*/

				ResetWeapon(playerid, weaponid);
				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has stored a \"%s\" into their weapon storage.", ReturnName(playerid), ReturnWeaponName(weaponid));

				hData[houseid][hWeapon][listitem] = weaponid;
				hData[houseid][hAmmo][listitem] = ammo;

				House_Save(houseid);
				House_WeaponStorage(playerid, houseid);
			}
		}
		else
		{
			House_OpenStorage(playerid, houseid);
		}
		return 1;
	}
	//HOUSE MONEY STORAGE
	if(dialogid == HOUSE_MONEY)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			switch (listitem)
			{
				case 0: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %s\n\nPlease enter how much money you wish to withdraw from the safe:", FormatMoney(hData[houseid][hMoney]));
					ShowPlayerDialog(playerid, HOUSE_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				}
				case 1: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %s\n\nPlease enter how much money you wish to deposit into the safe:", FormatMoney(hData[houseid][hMoney]));
					ShowPlayerDialog(playerid, HOUSE_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				}
			}
		}
		else House_OpenStorage(playerid, houseid);
		return 1;
	}
	if(dialogid == HOUSE_WITHDRAWMONEY)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %s\n\nPlease enter how much money you wish to withdraw from the safe:", FormatMoney(hData[houseid][hMoney]));
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > hData[houseid][hMoney])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %s\n\nPlease enter how much money you wish to withdraw from the safe:", FormatMoney(hData[houseid][hMoney]));
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			hData[houseid][hMoney] -= amount;
			GivePlayerMoneyEx(playerid, amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %s from their house safe.", ReturnName(playerid), FormatMoney(amount));
		}
		else ShowPlayerDialog(playerid, HOUSE_MONEY, DIALOG_STYLE_LIST, "Money Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_DEPOSITMONEY)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			new amount = strval(inputtext), maxmoney;
			if(hData[houseid][hType] == 1)
			{
				maxmoney = 1000000;
			}
			else if(hData[houseid][hType] == 2)
			{
				maxmoney = 3000000;
			}
			else if(hData[houseid][hType] == 3)
			{
				maxmoney = 5000000;
			}

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %s/%s\n\nPlease enter how much money you wish to deposit into the safe:", FormatMoney(hData[houseid][hMoney]), FormatMoney(maxmoney));
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > pData[playerid][pMoney])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %s/%s\n\nPlease enter how much money you wish to deposit into the safe:", FormatMoney(hData[houseid][hMoney]), FormatMoney(maxmoney));
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(hData[houseid][hMoney] + amount > maxmoney)
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %s/%s\n\nPlease enter how much money you wish to deposit into the safe:", FormatMoney(hData[houseid][hMoney]), FormatMoney(maxmoney));
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			hData[houseid][hMoney] += amount;
			GivePlayerMoneyEx(playerid, -amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %s into their house safe.", ReturnName(playerid), FormatMoney(amount));
		}
		else ShowPlayerDialog(playerid, HOUSE_MONEY, DIALOG_STYLE_LIST, "Money Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	//HOUSE COMPONENT STORAGE
	if(dialogid == HOUSE_COMPONENT)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			switch (listitem)
			{
				case 0: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %d\n\nPlease enter how much component you wish to withdraw from the safe:", hData[houseid][hComponent]);
					ShowPlayerDialog(playerid, HOUSE_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				}
				case 1: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %d\n\nPlease enter how much component you wish to deposit into the safe:", hData[houseid][hComponent]);
					ShowPlayerDialog(playerid, HOUSE_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				}
			}
		}
		else House_OpenStorage(playerid, houseid);
		return 1;
	}
	if(dialogid == HOUSE_WITHDRAWCOMPONENT)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %d\n\nPlease enter how much component you wish to withdraw from the safe:", hData[houseid][hComponent]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > hData[houseid][hComponent])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %d\n\nPlease enter how much component you wish to withdraw from the safe:", hData[houseid][hComponent]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			hData[houseid][hComponent] -= amount;
			Inventory_Add(playerid, "Component", 19627, amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d component from their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_COMPONENT, DIALOG_STYLE_LIST, "Component Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_DEPOSITCOMPONENT)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			new amount = strval(inputtext), maxcomp;
			if(hData[houseid][hType] == 1)
			{
				maxcomp = 5000;
			}
			else if(hData[houseid][hType] == 2)
			{
				maxcomp = 10000;
			}
			else if(hData[houseid][hType] == 3)
			{
				maxcomp = 15000;
			}

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %d/%d\n\nPlease enter how much component you wish to deposit into the safe:", hData[houseid][hComponent], maxcomp);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Component"))
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %d/%d\n\nPlease enter how much component you wish to deposit into the safe:", hData[houseid][hComponent], maxcomp);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(hData[houseid][hComponent] + amount > maxcomp)
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %d/%d\n\nPlease enter how much component you wish to deposit into the safe:", hData[houseid][hComponent], maxcomp);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			hData[houseid][hComponent] += amount;
			Inventory_Remove(playerid, "Component", amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d component into their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_COMPONENT, DIALOG_STYLE_LIST, "Component Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	//HOUSE MATERIAL STORAGE
	if(dialogid == HOUSE_MATERIAL)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			switch (listitem)
			{
				case 0: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %d\n\nPlease enter how much material you wish to withdraw from the safe:", hData[houseid][hMaterial]);
					ShowPlayerDialog(playerid, HOUSE_WITHDRAWMATERIAL, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				}
				case 1: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %d\n\nPlease enter how much material you wish to deposit into the safe:", hData[houseid][hMaterial]);
					ShowPlayerDialog(playerid, HOUSE_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				}
			}
		}
		else House_OpenStorage(playerid, houseid);
		return 1;
	}
	if(dialogid == HOUSE_WITHDRAWMATERIAL)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %d\n\nPlease enter how much material you wish to withdraw from the safe:", hData[houseid][hMaterial]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWMATERIAL, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > hData[houseid][hMaterial])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %d\n\nPlease enter how much material you wish to withdraw from the safe:", hData[houseid][hMaterial]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWMATERIAL, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}

			hData[houseid][hMaterial] -= amount;
			Inventory_Add(playerid, "Material", 17051, amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d material from their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_MATERIAL, DIALOG_STYLE_LIST, "Material Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_DEPOSITMATERIAL)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			new amount = strval(inputtext), maxmat;
			if(hData[houseid][hType] == 1)
			{
				maxmat = 5000;
			}
			else if(hData[houseid][hType] == 2)
			{
				maxmat = 10000;
			}
			else if(hData[houseid][hType] == 3)
			{
				maxmat = 15000;
			}

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %d/%d\n\nPlease enter how much material you wish to deposit into the safe:", hData[houseid][hMaterial], maxmat);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Material"))
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %d/%d\n\nPlease enter how much material you wish to deposit into the safe:", hData[houseid][hMaterial], maxmat);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(hData[houseid][hMaterial] + amount > maxmat)
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %d/%d\n\nPlease enter how much material you wish to deposit into the safe:", hData[houseid][hMaterial], maxmat);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			hData[houseid][hMaterial] += amount;
			Inventory_Remove(playerid, "Material", amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d material into their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_MATERIAL, DIALOG_STYLE_LIST, "Material Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_MARIJUANA)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			switch (listitem)
			{
				case 0: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much marijuana you wish to withdraw from the safe:", hData[houseid][hMarijuana]);
					ShowPlayerDialog(playerid, HOUSE_WITHDRAWMARIJUANA, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				}
				case 1: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much marijuana you wish to deposit into the safe:", hData[houseid][hMarijuana]);
					ShowPlayerDialog(playerid, HOUSE_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				}
			}
		}
		else House_OpenStorage(playerid, houseid);
		return 1;
	}
	if(dialogid == HOUSE_WITHDRAWMARIJUANA)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much marijuana you wish to withdraw from the safe:", hData[houseid][hMarijuana]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWMARIJUANA, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > hData[houseid][hMarijuana])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg\n\nPlease enter how much marijuana you wish to withdraw from the safe:", hData[houseid][hMarijuana]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWMARIJUANA, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			hData[houseid][hMarijuana] -= amount;
			//pData[playerid][pMarijuana] += amount;
			Inventory_Add(playerid, "Marijuana", 1580, amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %dg marijuana from their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_MARIJUANA, DIALOG_STYLE_LIST, "Marijuana Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_DEPOSITMARIJUANA)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			new amount = strval(inputtext), maxmarijuana;
			if(hData[houseid][hType] == 1)
			{
				maxmarijuana = 1000;
			}
			else if(hData[houseid][hType] == 2)
			{
				maxmarijuana = 3000;
			}
			else if(hData[houseid][hType] == 3)
			{
				maxmarijuana = 5000;
			}
			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %dg/%dg\n\nPlease enter how much marijuana you wish to deposit into the safe:", hData[houseid][hMarijuana], maxmarijuana);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Marijuana"))
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg/%dg\n\nPlease enter how much marijuana you wish to deposit into the safe:", hData[houseid][hMarijuana], maxmarijuana);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(hData[houseid][hMarijuana] + amount > maxmarijuana)
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg/%dg\n\nPlease enter how much marijuana you wish to deposit into the safe:", hData[houseid][hMaterial], maxmarijuana);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			hData[houseid][hMarijuana] += amount;
			//pData[playerid][pMarijuana] -= amount;
			Inventory_Remove(playerid, "Marijuana", amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %dg marijuana into their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_MARIJUANA, DIALOG_STYLE_LIST, "Marijuana Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_EPHEDRINE)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			switch (listitem)
			{
				case 0: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much Ephedrine you wish to withdraw from the safe:", hData[houseid][hEphedrine]);
					ShowPlayerDialog(playerid, HOUSE_WITHDRAWEPHEDRINE, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				}
				case 1: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much Ephedrine you wish to deposit into the safe:", hData[houseid][hEphedrine]);
					ShowPlayerDialog(playerid, HOUSE_DEPOSITEPHEDRINE, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				}
			}
		}
		else House_OpenStorage(playerid, houseid);
		return 1;
	}
	if(dialogid == HOUSE_WITHDRAWEPHEDRINE)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much Ephedrine you wish to withdraw from the safe:", hData[houseid][hEphedrine]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWEPHEDRINE, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > hData[houseid][hEphedrine])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg\n\nPlease enter how much Ephedrine you wish to withdraw from the safe:", hData[houseid][hEphedrine]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWEPHEDRINE, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			hData[houseid][hEphedrine] -= amount;
			Inventory_Add(playerid, "Ephedrine", 1580, amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %dg Ephedrine from their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_EPHEDRINE, DIALOG_STYLE_LIST, "Ephedrine Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_DEPOSITEPHEDRINE)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			new amount = strval(inputtext), maxephedrine;
			if(hData[houseid][hType] == 1)
			{
				maxephedrine = 1000;
			}
			else if(hData[houseid][hType] == 2)
			{
				maxephedrine = 3000;
			}
			else if(hData[houseid][hType] == 3)
			{
				maxephedrine = 5000;
			}
			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %dg/%dg\n\nPlease enter how much Ephedrine you wish to deposit into the safe:", hData[houseid][hEphedrine], maxephedrine);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITEPHEDRINE, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Ephedrine"))
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg/%dg\n\nPlease enter how much Ephedrine you wish to deposit into the safe:", hData[houseid][hEphedrine], maxephedrine);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITEPHEDRINE, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(hData[houseid][hEphedrine] + amount > maxephedrine)
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg/%dg\n\nPlease enter how much Ephedrine you wish to deposit into the safe:", hData[houseid][hMaterial], maxephedrine);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITEPHEDRINE, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			hData[houseid][hEphedrine] += amount;
			Inventory_Remove(playerid, "Ephedrine", amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %dg Ephedrine into their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_EPHEDRINE, DIALOG_STYLE_LIST, "Ephedrine Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_COCAINE)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			switch (listitem)
			{
				case 0: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much Cocaine you wish to withdraw from the safe:", hData[houseid][hCocaine]);
					ShowPlayerDialog(playerid, HOUSE_WITHDRAWCOCAINE, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				}
				case 1: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much Cocaine you wish to deposit into the safe:", hData[houseid][hCocaine]);
					ShowPlayerDialog(playerid, HOUSE_DEPOSITCOCAINE, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				}
			}
		}
		else House_OpenStorage(playerid, houseid);
		return 1;
	}
	if(dialogid == HOUSE_WITHDRAWCOCAINE)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much Cocaine you wish to withdraw from the safe:", hData[houseid][hCocaine]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWCOCAINE, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > hData[houseid][hCocaine])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg\n\nPlease enter how much Cocaine you wish to withdraw from the safe:", hData[houseid][hCocaine]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWCOCAINE, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			hData[houseid][hCocaine] -= amount;
			Inventory_Add(playerid, "Cocaine", 1580, amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %dg Cocaine from their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_COCAINE, DIALOG_STYLE_LIST, "Cocaine Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_DEPOSITCOCAINE)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			new amount = strval(inputtext), maxcocaine;
			if(hData[houseid][hType] == 1)
			{
				maxcocaine = 1000;
			}
			else if(hData[houseid][hType] == 2)
			{
				maxcocaine = 3000;
			}
			else if(hData[houseid][hType] == 3)
			{
				maxcocaine = 5000;
			}
			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %dg/%dg\n\nPlease enter how much Cocaine you wish to deposit into the safe:", hData[houseid][hCocaine], maxcocaine);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITCOCAINE, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Cocaine"))
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg/%dg\n\nPlease enter how much Cocaine you wish to deposit into the safe:", hData[houseid][hCocaine], maxcocaine);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITCOCAINE, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(hData[houseid][hCocaine] + amount > maxcocaine)
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg/%dg\n\nPlease enter how much Cocaine you wish to deposit into the safe:", hData[houseid][hMaterial], maxcocaine);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITCOCAINE, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			hData[houseid][hCocaine] += amount;
			Inventory_Remove(playerid, "Cocaine", amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %dg Cocaine into their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_COCAINE, DIALOG_STYLE_LIST, "Cocaine Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_METH)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			switch (listitem)
			{
				case 0: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much Meth you wish to withdraw from the safe:", hData[houseid][hMeth]);
					ShowPlayerDialog(playerid, HOUSE_WITHDRAWMETH, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				}
				case 1: 
				{
					new str[128];
					format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much Meth you wish to deposit into the safe:", hData[houseid][hMeth]);
					ShowPlayerDialog(playerid, HOUSE_DEPOSITMETH, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				}
			}
		}
		else House_OpenStorage(playerid, houseid);
		return 1;
	}
	if(dialogid == HOUSE_WITHDRAWMETH)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %dg\n\nPlease enter how much Meth you wish to withdraw from the safe:", hData[houseid][hMeth]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWMETH, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > hData[houseid][hMeth])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg\n\nPlease enter how much Meth you wish to withdraw from the safe:", hData[houseid][hMeth]);
				ShowPlayerDialog(playerid, HOUSE_WITHDRAWMETH, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			hData[houseid][hMeth] -= amount;
			Inventory_Add(playerid, "Meth", 1580, amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %dg Meth from their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_METH, DIALOG_STYLE_LIST, "Meth Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	if(dialogid == HOUSE_DEPOSITMETH)
	{
		new houseid = pData[playerid][pInHouse];
		if(!Player_OwnsHouse2(playerid, pData[playerid][pInHouse])) return Error(playerid, "You don't own this house.");
		if(response)
		{
			new amount = strval(inputtext), maxmeth;
			if(hData[houseid][hType] == 1)
			{
				maxmeth = 1000;
			}
			else if(hData[houseid][hType] == 2)
			{
				maxmeth = 3000;
			}
			else if(hData[houseid][hType] == 3)
			{
				maxmeth = 5000;
			}
			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Safe Balance: %dg/%dg\n\nPlease enter how much Meth you wish to deposit into the safe:", hData[houseid][hMeth], maxmeth);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMETH, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Meth"))
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg/%dg\n\nPlease enter how much Meth you wish to deposit into the safe:", hData[houseid][hMeth], maxmeth);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMETH, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(hData[houseid][hMeth] + amount > maxmeth)
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nSafe Balance: %dg/%dg\n\nPlease enter how much Meth you wish to deposit into the safe:", hData[houseid][hMaterial], maxmeth);
				ShowPlayerDialog(playerid, HOUSE_DEPOSITMETH, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			hData[houseid][hMeth] += amount;
			Inventory_Remove(playerid, "Meth", amount);

			House_Save(houseid);
			House_OpenStorage(playerid, houseid);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %dg Meth into their house safe.", ReturnName(playerid), amount);
		}
		else ShowPlayerDialog(playerid, HOUSE_METH, DIALOG_STYLE_LIST, "Meth Safe", "Withdraw from safe\nDeposit into safe", "Select", "Back");
		return 1;
	}
	//------------[ Private Player Vehicle Dialog ]--------
	if(dialogid == DIALOG_PVEHMENU)
	{
		if(!response)
			return 1;
		{
			SetPVarInt(playerid, "ClickedPVeh", ReturnPVehiclesID(playerid, (listitem + 1)));

			new string[1024];
			format(string, sizeof(string), "Track Vehicle");
			ShowPlayerDialog(playerid, DIALOG_PVEHMENULIST, DIALOG_STYLE_LIST, "Vehicles Menu", string, "Select", "Close");
		}
	}
	if(dialogid == DIALOG_PVEHMENULIST)
	{
		new id = GetPVarInt(playerid, "ClickedPVeh");
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pvData[id][cParkid] != -1)
					{
						new gkid = pvData[id][cParkid];
						DisablePlayerRaceCheckpoint(playerid);
						SetPlayerRaceCheckpoint(playerid, 1, gkData[gkid][gkX], gkData[gkid][gkY], gkData[gkid][gkZ], 0.0, 0.0, 0.0, 3.5);
						Info(playerid, "Kendaraan %s (ID: %d) yang berlokasi di Public Park %s (PARKID: %d) telah ditandai", GetVehicleModelName(pvData[id][cModel]), pvData[id][cVeh], GetLocation(gkData[gkid][gkX], gkData[gkid][gkY], gkData[gkid][gkZ]), pvData[id][cParkid]);
					}
					else
					{
						new Float:x, Float:y, Float:z;
						GetVehiclePos(pvData[id][cVeh], x, y, z);
						DisablePlayerRaceCheckpoint(playerid);
						SetPlayerRaceCheckpoint(playerid, 1, x, y, z, 0.0, 0.0, 0.0, 3.5);
						Info(playerid, "Kendaraan %s (ID: %d) yang berlokasi di %s telah ditandai", GetVehicleModelName(pvData[id][cModel]), pvData[id][cVeh], GetLocation(x, y, z));
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_GOTOVEH)
	{
		if(response) 
		{
			new Float:posisiX, Float:posisiY, Float:posisiZ,
				carid = strval(inputtext);
			
			GetVehiclePos(carid, posisiX, posisiY, posisiZ);
			Servers(playerid, "Your teleport to %s (vehicle id: %d).", GetLocation(posisiX, posisiY, posisiZ), carid);
			SetPlayerPosition(playerid, posisiX, posisiY, posisiZ+3.0, 4.0, 0);
		}
		return 1;
	}
	if(dialogid == DIALOG_GETVEH)
	{
		if(response) 
		{
			new Float:posisiX, Float:posisiY, Float:posisiZ,
				carid = strval(inputtext);
			
			GetPlayerPos(playerid, posisiX, posisiY, posisiZ);
			Servers(playerid, "Your get spawn vehicle to %s (vehicle id: %d).", GetLocation(posisiX, posisiY, posisiZ), carid);
			SetVehiclePos(carid, posisiX, posisiY, posisiZ+0.5);
		}
		return 1;
	}
	if(dialogid == DIALOG_DELETEVEH)
	{
		if(response) 
		{
			new carid = strval(inputtext);
			
			//for(new i = 0; i != MAX_PRIVATE_VEHICLE; i++) if(Iter_Contains(PVehicles, i))
			foreach(new i : PVehicles)			
			{
				if(carid == pvData[i][cVeh])
				{
					new query[128];
					mysql_format(g_SQL, query, sizeof(query), "DELETE FROM vehicle WHERE id = '%d'", pvData[i][cID]);
					mysql_tquery(g_SQL, query);
					DestroyVehicle(pvData[i][cVeh]);
					Iter_Remove(PVehicles, i);
					Servers(playerid, "Your deleted private vehicle id %d (database id: %d).", pvData[i][cVeh], pvData[i][cID]);
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_BUYPLATE)
	{
		if(response) 
		{
			new carid = strval(inputtext);
			
			//for(new i = 0; i != MAX_PRIVATE_VEHICLE; i++) if(Iter_Contains(PVehicles, i))
			foreach(new i : PVehicles)
			{
				if(carid == pvData[i][cVeh])
				{
					if(pData[playerid][pMoney] < 500) return Error(playerid, "Anda butuh $500 untuk membeli Plate baru.");
					GivePlayerMoneyEx(playerid, -500);
					new rand = RandomEx(1111, 9999);
					format(pvData[i][cPlate], 32, "IDX-%d", rand);
					SetVehicleNumberPlate(pvData[i][cVeh], pvData[i][cPlate]);
					pvData[i][cPlateTime] = gettime() + (15 * 86400);
					Info(playerid, "Model: %s || New plate: %s || Plate Time: %s || Plate Price: $500", GetVehicleModelName(pvData[i][cModel]), pvData[i][cPlate], ReturnTimelapse(gettime(), pvData[i][cPlateTime]));
				}
			}
		}
		return 1;
	}
	//--------------[ Player Toy Dialog ]-------------
	if(dialogid == DIALOG_TOY)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: //slot 1
				{
					pData[playerid][toySelected] = 0;
					if(pToys[playerid][0][toy_model] == 0)
					{
						//ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						new string[512];
						format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot"Change Bone\n"dot"Hide/Show Toy\n"GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
						pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
						pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", string, "Select", "Cancel");
					}
				}
				case 1: //slot 2
				{
					pData[playerid][toySelected] = 1;
					if(pToys[playerid][1][toy_model] == 0)
					{
						//ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						new string[512];
						format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot"Change Bone\n"dot"Hide/Show Toy\n"GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
						pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
						pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", string, "Select", "Cancel");
					}
				}
				case 2: //slot 3
				{
					pData[playerid][toySelected] = 2;
					if(pToys[playerid][2][toy_model] == 0)
					{
						//ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						new string[512];
						format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot"Change Bone\n"dot"Hide/Show Toy\n"GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
						pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
						pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", string, "Select", "Cancel");
					}
				}
				case 3: //slot 4
				{
					pData[playerid][toySelected] = 3;
					if(pToys[playerid][3][toy_model] == 0)
					{
						//ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						new string[512];
						format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot"Change Bone\n"dot"Hide/Show Toy\n"GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
						pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
						pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", string, "Select", "Cancel");
					}
				}
				case 4:
				{
					if(pData[playerid][PurchasedToy] == true)
					{
						for(new i = 0; i < 4; i++)
						{
							pToys[playerid][i][toy_model] = 0;
							pToys[playerid][i][toy_bone] = 1;
							pToys[playerid][i][toy_hide] = 0;
							pToys[playerid][i][toy_x] = 0.0;
							pToys[playerid][i][toy_y] = 0.0;
							pToys[playerid][i][toy_z] = 0.0;
							pToys[playerid][i][toy_rx] = 0.0;
							pToys[playerid][i][toy_ry] = 0.0;
							pToys[playerid][i][toy_rz] = 0.0;
							pToys[playerid][i][toy_sx] = 1.0;
							pToys[playerid][i][toy_sy] = 1.0;
							pToys[playerid][i][toy_sz] = 1.0;
							
							if(IsPlayerAttachedObjectSlotUsed(playerid, i))
							{
								RemovePlayerAttachedObject(playerid, i);
							}
						}
						new string[128];
						mysql_format(g_SQL, string, sizeof(string), "DELETE FROM toys WHERE Owner = '%s'", pData[playerid][pName]);
						mysql_tquery(g_SQL, string);
						pData[playerid][PurchasedToy] = false;
						InfoTD_MSG(playerid, 4000, "~r~~h~All Toy Rested!~y~!");
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_TOYEDIT)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: // edit
				{
					if(pToys[playerid][pData[playerid][toySelected]][toy_hide] != 0)
						return Error(playerid, "Kamu tidak dapat mengedit toys yang sedang hide!");

					//if(IsPlayerAndroid(playerid))
					//	return Error(playerid, "You're connected from android. This feature only for PC users!");
						
					EditAttachedObject(playerid, pData[playerid][toySelected]);
					InfoTD_MSG(playerid, 4000, "~b~~h~You are now editing your toy.");
				}
				case 1: // change bone
				{
					if(pToys[playerid][pData[playerid][toySelected]][toy_hide] != 0)
						return Error(playerid, "Kamu tidak dapat mengedit toys yang sedang hide!");

					new finstring[750];

					strcat(finstring, ""dot"Spine\n"dot"Head\n"dot"Left upper arm\n"dot"Right upper arm\n"dot"Left hand\n"dot"Right hand\n"dot"Left thigh\n"dot"Right tigh\n"dot"Left foot\n"dot"Right foot");
					strcat(finstring, "\n"dot"Right calf\n"dot"Left calf\n"dot"Left forearm\n"dot"Right forearm\n"dot"Left clavicle\n"dot"Right clavicle\n"dot"Neck\n"dot"Jaw");

					ShowPlayerDialog(playerid, DIALOG_TOYPOSISI, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo"WHITE_E"Player Toys", finstring, "Select", "Cancel");
				}
				case 2: //Hide or Show toy
				{
					if(pToys[playerid][pData[playerid][toySelected]][toy_hide] != 0)
					{
						pToys[playerid][pData[playerid][toySelected]][toy_hide] = 0;

						SetPlayerAttachedObject(playerid,
						pData[playerid][toySelected],
						pToys[playerid][pData[playerid][toySelected]][toy_model],
						pToys[playerid][pData[playerid][toySelected]][toy_bone],
						pToys[playerid][pData[playerid][toySelected]][toy_x],
						pToys[playerid][pData[playerid][toySelected]][toy_y],
						pToys[playerid][pData[playerid][toySelected]][toy_z],
						pToys[playerid][pData[playerid][toySelected]][toy_rx],
						pToys[playerid][pData[playerid][toySelected]][toy_ry],
						pToys[playerid][pData[playerid][toySelected]][toy_rz],
						pToys[playerid][pData[playerid][toySelected]][toy_sx],
						pToys[playerid][pData[playerid][toySelected]][toy_sy],
						pToys[playerid][pData[playerid][toySelected]][toy_sz]);

						//MySQL_SavePlayerToys(playerid);
						SetPVarInt(playerid, "UpdatedToy", 1);
						InfoTD_MSG(playerid, 3000, "~r~~h~Toy Showed~y~!");
					}
					else
					{
						pToys[playerid][pData[playerid][toySelected]][toy_hide] = 1;
						if(IsPlayerAttachedObjectSlotUsed(playerid, pData[playerid][toySelected]))
						{
							RemovePlayerAttachedObject(playerid, pData[playerid][toySelected]);
						}
						//MySQL_SavePlayerToys(playerid);
						SetPVarInt(playerid, "UpdatedToy", 1);
						InfoTD_MSG(playerid, 3000, "~r~~h~Toy Hide~y~!");
					}
				}
				case 3: // remove toy
				{
					if(IsPlayerAttachedObjectSlotUsed(playerid, pData[playerid][toySelected]))
					{
						RemovePlayerAttachedObject(playerid, pData[playerid][toySelected]);
					}

					pToys[playerid][pData[playerid][toySelected]][toy_model] = 0;
					pToys[playerid][pData[playerid][toySelected]][toy_hide] = 0;

					InfoTD_MSG(playerid, 3000, "~r~~h~Toy Removed~y~!");
					SetPVarInt(playerid, "UpdatedToy", 1);
					TogglePlayerControllable(playerid, true);
				}
				case 4:	//share toy pos
				{
					if(pToys[playerid][pData[playerid][toySelected]][toy_hide] != 0)
						return Error(playerid, "Kamu tidak dapat membagikan kordinat toys yang sedang di hide!");

					SendNearbyMessage(playerid, 10.0, COLOR_GREEN, "[TOY BY %s] "WHITE_E"PosX: %.3f | PosY: %.3f | PosZ: %.3f | PosRX: %.3f | PosRY: %.3f | PosRZ: %.3f",
					ReturnName(playerid), pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
					pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
				}
				case 5: //Pos X
				{
					if(pToys[playerid][pData[playerid][toySelected]][toy_hide] != 0)
						return Error(playerid, "Kamu tidak dapat mengedit toys yang sedang di hide!");

					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosX: %f\nInput new Toy PosX:(Float)", pToys[playerid][pData[playerid][toySelected]][toy_x]);
					ShowPlayerDialog(playerid, DIALOG_TOYPOSX, DIALOG_STYLE_INPUT, "Toy PosX", mstr, "Edit", "Cancel");
				}
				case 6: //Pos Y
				{
					if(pToys[playerid][pData[playerid][toySelected]][toy_hide] != 0)
						return Error(playerid, "Kamu tidak dapat mengedit toys yang sedang di hide!");

					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosY: %f\nInput new Toy PosY:(Float)", pToys[playerid][pData[playerid][toySelected]][toy_y]);
					ShowPlayerDialog(playerid, DIALOG_TOYPOSY, DIALOG_STYLE_INPUT, "Toy PosY", mstr, "Edit", "Cancel");
				}
				case 7: //Pos Z
				{
					if(pToys[playerid][pData[playerid][toySelected]][toy_hide] != 0)
						return Error(playerid, "Kamu tidak dapat mengedit toys yang sedang di hide!");

					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosZ: %f\nInput new Toy PosZ:(Float)", pToys[playerid][pData[playerid][toySelected]][toy_z]);
					ShowPlayerDialog(playerid, DIALOG_TOYPOSZ, DIALOG_STYLE_INPUT, "Toy PosZ", mstr, "Edit", "Cancel");
				}
				case 8: //Pos RX
				{
					if(pToys[playerid][pData[playerid][toySelected]][toy_hide] != 0)
						return Error(playerid, "Kamu tidak dapat mengedit toys yang sedang di hide!");

					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosRX: %f\nInput new Toy PosRX:(Float)", pToys[playerid][pData[playerid][toySelected]][toy_rx]);
					ShowPlayerDialog(playerid, DIALOG_TOYPOSRX, DIALOG_STYLE_INPUT, "Toy PosRX", mstr, "Edit", "Cancel");
				}
				case 9: //Pos RY
				{
					if(pToys[playerid][pData[playerid][toySelected]][toy_hide] != 0)
						return Error(playerid, "Kamu tidak dapat mengedit toys yang sedang di hide!");

					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosRY: %f\nInput new Toy PosRY:(Float)", pToys[playerid][pData[playerid][toySelected]][toy_ry]);
					ShowPlayerDialog(playerid, DIALOG_TOYPOSRY, DIALOG_STYLE_INPUT, "Toy PosRY", mstr, "Edit", "Cancel");
				}
				case 10: //Pos RZ
				{
					if(pToys[playerid][pData[playerid][toySelected]][toy_hide] != 0)
						return Error(playerid, "Kamu tidak dapat mengedit toys yang sedang di hide!");

					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosRZ: %f\nInput new Toy PosRZ:(Float)", pToys[playerid][pData[playerid][toySelected]][toy_rz]);
					ShowPlayerDialog(playerid, DIALOG_TOYPOSRZ, DIALOG_STYLE_INPUT, "Toy PosRZ", mstr, "Edit", "Cancel");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_TOYPOSISI)
	{
		if(response)
		{
			listitem++;
			pToys[playerid][pData[playerid][toySelected]][toy_bone] = listitem;
			if(IsPlayerAttachedObjectSlotUsed(playerid, pData[playerid][toySelected]))
			{
				RemovePlayerAttachedObject(playerid, pData[playerid][toySelected]);
			}
			listitem = pData[playerid][toySelected];
			SetPlayerAttachedObject(playerid,
					listitem,
					pToys[playerid][listitem][toy_model],
					pToys[playerid][listitem][toy_bone],
					pToys[playerid][listitem][toy_x],
					pToys[playerid][listitem][toy_y],
					pToys[playerid][listitem][toy_z],
					pToys[playerid][listitem][toy_rx],
					pToys[playerid][listitem][toy_ry],
					pToys[playerid][listitem][toy_rz],
					pToys[playerid][listitem][toy_sx],
					pToys[playerid][listitem][toy_sy],
					pToys[playerid][listitem][toy_sz]);
			InfoTD_MSG(playerid, 3000, "~g~~h~Bone Changed~y~!");
			SetPVarInt(playerid, "UpdatedToy", 1);
		}
		return 1;
	}
	if(dialogid == DIALOG_TOYPOSISIBUY)
	{
		if(response)
		{
			listitem++;
			pToys[playerid][pData[playerid][toySelected]][toy_bone] = listitem;
			SetPlayerAttachedObject(playerid, pData[playerid][toySelected], pToys[playerid][pData[playerid][toySelected]][toy_model], listitem);
			//EditAttachedObject(playerid, pData[playerid][toySelected]);
			InfoTD_MSG(playerid, 3000, "~g~~h~Object Attached!~n~~w~Adjust the position than click on the save icon!");
		}
		return 1;
	}
	if(dialogid == DIALOG_TOYBUY)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: //slot 1
				{
					pData[playerid][toySelected] = 0;
					if(pToys[playerid][0][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
				case 1: //slot 2
				{
					pData[playerid][toySelected] = 1;
					if(pToys[playerid][1][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
				case 2: //slot 3
				{
					pData[playerid][toySelected] = 2;
					if(pToys[playerid][2][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
				case 3: //slot 4
				{
					pData[playerid][toySelected] = 3;
					if(pToys[playerid][3][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
				case 4: //slot 5
				{
					pData[playerid][toySelected] = 4;
					if(pToys[playerid][4][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
				case 5: //slot 6
				{
					pData[playerid][toySelected] = 5;
					if(pToys[playerid][5][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_TOYVIP)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: //slot 1
				{
					pData[playerid][toySelected] = 0;
					if(pToys[playerid][0][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
				case 1: //slot 2
				{
					pData[playerid][toySelected] = 1;
					if(pToys[playerid][1][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
				case 2: //slot 3
				{
					pData[playerid][toySelected] = 2;
					if(pToys[playerid][2][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
				case 3: //slot 4
				{
					pData[playerid][toySelected] = 3;
					if(pToys[playerid][3][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
				case 4: //slot 5
				{
					pData[playerid][toySelected] = 4;
					if(pToys[playerid][4][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
				case 5: //slot 6
				{
					pData[playerid][toySelected] = 5;
					if(pToys[playerid][5][toy_model] == 0)
					{
						ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy", "Select", "Cancel");
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_TOYPOSX)
	{
		if(response)
		{
			new Float:posisi = floatstr(inputtext);

			SetPlayerAttachedObject(playerid,
				pData[playerid][toySelected],
				pToys[playerid][pData[playerid][toySelected]][toy_model],
				pToys[playerid][pData[playerid][toySelected]][toy_bone],
				posisi,
				pToys[playerid][pData[playerid][toySelected]][toy_y],
				pToys[playerid][pData[playerid][toySelected]][toy_z],
				pToys[playerid][pData[playerid][toySelected]][toy_rx],
				pToys[playerid][pData[playerid][toySelected]][toy_ry],
				pToys[playerid][pData[playerid][toySelected]][toy_rz],
				pToys[playerid][pData[playerid][toySelected]][toy_sx],
				pToys[playerid][pData[playerid][toySelected]][toy_sy],
				pToys[playerid][pData[playerid][toySelected]][toy_sz]);
			
			pToys[playerid][pData[playerid][toySelected]][toy_x] = posisi;
			SetPVarInt(playerid, "UpdatedToy", 1);
			//MySQL_SavePlayerToys(playerid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
			pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
			ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_TOYPOSY)
	{
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
			SetPlayerAttachedObject(playerid,
				pData[playerid][toySelected],
				pToys[playerid][pData[playerid][toySelected]][toy_model],
				pToys[playerid][pData[playerid][toySelected]][toy_bone],
				pToys[playerid][pData[playerid][toySelected]][toy_x],
				posisi,
				pToys[playerid][pData[playerid][toySelected]][toy_z],
				pToys[playerid][pData[playerid][toySelected]][toy_rx],
				pToys[playerid][pData[playerid][toySelected]][toy_ry],
				pToys[playerid][pData[playerid][toySelected]][toy_rz],
				pToys[playerid][pData[playerid][toySelected]][toy_sx],
				pToys[playerid][pData[playerid][toySelected]][toy_sy],
				pToys[playerid][pData[playerid][toySelected]][toy_sz]);
			
			pToys[playerid][pData[playerid][toySelected]][toy_y] = posisi;
			SetPVarInt(playerid, "UpdatedToy", 1);
			//MySQL_SavePlayerToys(playerid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
			pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
			ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_TOYPOSZ)
	{
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
			SetPlayerAttachedObject(playerid,
				pData[playerid][toySelected],
				pToys[playerid][pData[playerid][toySelected]][toy_model],
				pToys[playerid][pData[playerid][toySelected]][toy_bone],
				pToys[playerid][pData[playerid][toySelected]][toy_x],
				pToys[playerid][pData[playerid][toySelected]][toy_y],
				posisi,
				pToys[playerid][pData[playerid][toySelected]][toy_rx],
				pToys[playerid][pData[playerid][toySelected]][toy_ry],
				pToys[playerid][pData[playerid][toySelected]][toy_rz],
				pToys[playerid][pData[playerid][toySelected]][toy_sx],
				pToys[playerid][pData[playerid][toySelected]][toy_sy],
				pToys[playerid][pData[playerid][toySelected]][toy_sz]);
			
			pToys[playerid][pData[playerid][toySelected]][toy_z] = posisi;
			SetPVarInt(playerid, "UpdatedToy", 1);
			//MySQL_SavePlayerToys(playerid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
			pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
			ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_TOYPOSRX)
	{
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
			SetPlayerAttachedObject(playerid,
				pData[playerid][toySelected],
				pToys[playerid][pData[playerid][toySelected]][toy_model],
				pToys[playerid][pData[playerid][toySelected]][toy_bone],
				pToys[playerid][pData[playerid][toySelected]][toy_x],
				pToys[playerid][pData[playerid][toySelected]][toy_y],
				pToys[playerid][pData[playerid][toySelected]][toy_z],
				posisi,
				pToys[playerid][pData[playerid][toySelected]][toy_ry],
				pToys[playerid][pData[playerid][toySelected]][toy_rz],
				pToys[playerid][pData[playerid][toySelected]][toy_sx],
				pToys[playerid][pData[playerid][toySelected]][toy_sy],
				pToys[playerid][pData[playerid][toySelected]][toy_sz]);
			
			pToys[playerid][pData[playerid][toySelected]][toy_rx] = posisi;
			SetPVarInt(playerid, "UpdatedToy", 1);
			//MySQL_SavePlayerToys(playerid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
			pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
			ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_TOYPOSRY)
	{
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
			SetPlayerAttachedObject(playerid,
				pData[playerid][toySelected],
				pToys[playerid][pData[playerid][toySelected]][toy_model],
				pToys[playerid][pData[playerid][toySelected]][toy_bone],
				pToys[playerid][pData[playerid][toySelected]][toy_x],
				pToys[playerid][pData[playerid][toySelected]][toy_y],
				pToys[playerid][pData[playerid][toySelected]][toy_z],
				pToys[playerid][pData[playerid][toySelected]][toy_rx],
				posisi,
				pToys[playerid][pData[playerid][toySelected]][toy_rz],
				pToys[playerid][pData[playerid][toySelected]][toy_sx],
				pToys[playerid][pData[playerid][toySelected]][toy_sy],
				pToys[playerid][pData[playerid][toySelected]][toy_sz]);
			
			pToys[playerid][pData[playerid][toySelected]][toy_ry] = posisi;
			SetPVarInt(playerid, "UpdatedToy", 1);
			//MySQL_SavePlayerToys(playerid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
			pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
			ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_TOYPOSRZ)
	{
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
			SetPlayerAttachedObject(playerid,
				pData[playerid][toySelected],
				pToys[playerid][pData[playerid][toySelected]][toy_model],
				pToys[playerid][pData[playerid][toySelected]][toy_bone],
				pToys[playerid][pData[playerid][toySelected]][toy_x],
				pToys[playerid][pData[playerid][toySelected]][toy_y],
				pToys[playerid][pData[playerid][toySelected]][toy_z],
				pToys[playerid][pData[playerid][toySelected]][toy_rx],
				pToys[playerid][pData[playerid][toySelected]][toy_ry],
				posisi,
				pToys[playerid][pData[playerid][toySelected]][toy_sx],
				pToys[playerid][pData[playerid][toySelected]][toy_sy],
				pToys[playerid][pData[playerid][toySelected]][toy_sz]);
			
			pToys[playerid][pData[playerid][toySelected]][toy_rz] = posisi;
			SetPVarInt(playerid, "UpdatedToy", 1);
			//MySQL_SavePlayerToys(playerid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			pToys[playerid][pData[playerid][toySelected]][toy_x], pToys[playerid][pData[playerid][toySelected]][toy_y], pToys[playerid][pData[playerid][toySelected]][toy_z],
			pToys[playerid][pData[playerid][toySelected]][toy_rx], pToys[playerid][pData[playerid][toySelected]][toy_ry], pToys[playerid][pData[playerid][toySelected]][toy_rz]);
			ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", string, "Select", "Cancel");
		}
	}
	//-----------[ Player Commands Dialog ]----------
	if(dialogid == DIALOG_HELP)
    {
		if(!response) return 1;
		switch(listitem)
		{
			case 0:
			{
				new str[3500];
				strcat(str, "Commands\tInformation\n");
				strcat(str, "/settings\tUntuk membuka menu setting akunmu\n");
				strcat(str, "/email\tUntuk mengaitkan email pada akunmu\n");
				strcat(str, "/stats\tUntuk melihat statistik akunmu\n");
				strcat(str, "/savestats\tUntuk menyimpan statistik akunmu");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Account Commands", str, "Close", "");
			}
			case 1:
			{
				new str[3500];
				strcat(str, ""LG_E"PLAYER: /help /afk /drag /undrag /pay /stats /items /frisk /use /give /idcard /drivelic /togphone /reqloc /shareloc\n");
				strcat(str, ""LG_E"PLAYER: /weapon /settings /ask /answer /mask /helmet /death /accept /deny /revive /buy /health /destroycp /h (phone)\n");
				strcat(str, ""LG_E"PLAYER: /handshake /animhelp /calculate /accent /gps /inventory(/inv) /fonline /setsuara\n");
				strcat(str, ""LG_E"CHAT: /dcp(destroycp) /b /l /t /s /pm /togpm /vip /togvip /w /o /me /ame /do /ado /try /ab");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Other Commands", str, "Close", "");
			}
			case 2:
			{
				new str[3500];
				strcat(str, "Commands\tInformation\n");
				strcat(str,"/engine\tUntuk menyalakan mesin kendaraan\n");
				strcat(str,"/light\tUntuk menyalakan lampu kendaraan\n");
				strcat(str,"/hood\tUntuk membuka kap depan kendaraan\n");
				strcat(str,"/boot\tUntuk membuka kap belakang kendaraan\n");
				strcat(str,"/lock\tUntuk mengunci kendaraan\n");
				strcat(str,"/myv\tUntuk melihat list kendaraan\n");
				strcat(str,"/myinsu\tUntuk melihat kendaraan yang berada di insu\n");
				strcat(str,"/buyplate\tUntuk membeli plat kendaraan\n");
				strcat(str,"/vstorage\tUntuk melihat isi bagasi kendaraan\n");
				strcat(str,"/tow\tUntuk menarik kendaraan lain\n");
				strcat(str,"/untow\tUntuk melepas dari kendaraan lain\n");
				strcat(str,"/claimpv\tUntuk mengambil kendaraan di dalam insuransi\n");
				strcat(str,"/buyinsu\tUntuk membeli tiket insuransi kendaraan\n");
				strcat(str,"/speedlimit\tUntuk merubah batas kecepatan kendaraan\n");
				strcat(str,"/vname\tUntuk merubah nama kendaraan\n");
				strcat(str,"/snt\tUntuk menampilkan UCP & ID Player\n");
				strcat(str, "/eject\tUntuk menendang keluar penumpang dari dalam kendaraan");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Vehicle Commands", str, "Close", "");
			}
			case 3:
			{
				new line3[1024];
				strcat(line3, "{ffffff}Lumberjack\nTrucker\nMiner\nProduct\nFarmer\nHauling\nPizza Man\nAyam\nReflenish\nWeapon Dealer\nDrug Dealer\nTrash Master(Side Job)");
				ShowPlayerDialog(playerid, DIALOG_JOB, DIALOG_STYLE_LIST, "Job Help", line3, "Pilih", "Batal");
				return 1;
			}
			case 4:
			{
				return callcmd::factionhelp(playerid, "");
			}
			case 5:
			{
				new str[3500];
				strcat(str, "{7fffd4}AUTO RP: {ffffff}rpgun rpcrash rpfall rprob rpfish rpmad rpcj rpdrink\n");
				strcat(str, "{7fffd4}AUTO RP: {ffffff}rpwar rpdie rpfixmeka rpcheckmeka rpfight rpcry rpeat\n");
				strcat(str, "{7fffd4}AUTO RP: {ffffff}rpfear rpdropgun rpgivegun rptakegun rprun rpnodong\n");
				strcat(str, "{7fffd4}AUTO RP: {ffffff}rpshy rpnusuk rplock rpharvest rplockhouse rplockcar\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"LOCALPRIME AUTO RP", str, "Close", "");
			}
			case 6:
			{
				return callcmd::wshelp(playerid);
			}
			case 7:
			{
				new str[3500];
				strcat(str, "Commands\tInformation\n");
				strcat(str, "/buydrink\tUntuk membeli minuman pada mesin vending machine\n");
				strcat(str, "/vmedit\tUntuk membuka menu pada vending machine\n");
				strcat(str, "/myvending\tUntuk lihat list vending machine milik pribadi");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Vending Commands", str, "Close", "");
			}
			case 8:
			{
				new str[3500];
				strcat(str, "Commands\tInformation\n");
				strcat(str, "/buyveh\tUntuk membeli product kendaraan pada dealer point\n");
				strcat(str, "/dem\tUntuk membuka menu setting dealer milik pribadi\n");
				strcat(str, "/mydealer\tUntuk melihat list dealer milik pribadi\n");
				strcat(str, "/givedealer\tUntuk memberikan dealer kepada seseorang\n");
				strcat(str, "/selldealer\tUntuk menjual dealer di balaikota");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Dealer Commands", str, "Close", "");
			}
			case 9:
			{
				new str[3500];
				strcat(str, "Commands\tInformation\n");
				strcat(str, "/buy\tUntuk membeli rumah yang dijual\n");
				strcat(str, "/storage /hm\tUntuk menyimpan/mengambil item dari storage rumah\n");
				strcat(str, "/lockhouse\tUntuk mengunci pintu rumah\n");
				strcat(str, "/unlockhouse\tUntuk membuka kunci pintu rumah\n");
				strcat(str, "/myhouse\tUntuk melihat list rumah milik pribadi\n");
				strcat(str, "/givehouse\tUntuk memberikan rumah kepada seseoarang\n");
				strcat(str, "/givehousekey\tUntuk memberikan kunci rumah kedua\n");
				strcat(str, "/takehousekey\tUntuk mengambil kunci rumah kedua");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "House Commands", str, "Close", "");
			}
			case 10:
			{
				new str[3500];
				strcat(str, "Commands\tInformation\n");
				strcat(str, "/buy\tUntuk membeli private farmer\n");
				strcat(str, "/mypfarm\tUntuk melihat list private farmer milik pribadi\n");
				strcat(str, "/pfmenu\tUntuk membuka menu private farmer\n");
				strcat(str, "/pfarm\tUntuk menanam tanaman pada private farmer point\n");
				strcat(str, "/givepfarm\tUntuk memberikan private farmer kepada seseorang");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "PFarm Commands", str, "Close", "");
			}
			case 11:
			{
				new str[3500];
				strcat(str, "Commands\tInformation\n");
				strcat(str, "/robinvite\tUntuk menginvite seseorang memulai perampokan\n");
				strcat(str, "/robbank\tUntuk memulai perampokan bank dengan kelompokmu\n");
				strcat(str, "/placebomb\tUntuk menempelkan & meledakan Patched Bomb pada brankas bank\n");
				strcat(str, "/robvault\tUntuk mengambil uang dari dalam brankas bank\n");
				strcat(str, "/robatm\tUntuk merampok mesin atm");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Robbing Commands", str, "Close", "");
			}
			case 12:
			{
				//anjay
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_JOB)
    {
		if(!response) return 1;
		switch(listitem)
		{
			case 0:
			{
				new str[3500];
				strcat(str, "{ffffff}Pekerjaan ini khusus untuk Job Center\n\n{7fffd4}CMDS: /(lum)ber\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Lumber Job", str, "Close", "");
			}
			case 1:
			{
				new str[3500];
				strcat(str, "{ffffff}Pekerjaan ini dapat anda dapatkan di Job Center\n\n{7fffd4}CMDS: /loadbox /unloadbox\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Trucker Job", str, "Close", "");
			}
			case 2:
			{
				new str[3500];
				strcat(str, "{ffffff}Pekerjaan ini dapat anda dapatkan di Job Center\n\n{7fffd4}CMDS: /mine\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Miner Job", str, "Close", "");
			}
			case 3:
			{
				new str[3500];
				strcat(str, "{ffffff}Pekerjaan ini dapat anda dapatkan di Job Center\n\n{7fffd4}CMDS: /createproduct /sellproduct\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Production Job", str, "Close", "");
			}
			case 4:
			{
				new str[3500];
				strcat(str, "{ffffff}Pekerjaan ini dapat anda dapatkan di Job Center\n\n{7fffd4}CMDS: /plant /price /offer\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Farmer Job", str, "Close", "");
			}
			case 5:
			{
				new str[3500];
				strcat(str, "{ffffff}Pekerjaan ini dapat anda dapatkan di Job Center\n\n{7fffd4}CMDS: /starthauling /stophauling\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Hauling Job", str, "Close", "");
			}
			case 6:
			{
				new str[3500];
				strcat(str, "{ffffff}Pekerjaan ini dapat anda dapatkan di Job Center\n\n{7fffd4}CMDS: /getpizza /droppizza\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Pizza Job", str, "Close", "");
			}
			case 7:
			{
				new str[3500];
				strcat(str, "{ffffff}Pekerjaan ini dapat anda dapatkan di Job Center\n\n{7fffd4}CMDS: silahkan menuju lokasi untuk memulai\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Chiken Job", str, "Close", "");
			}
			case 8:
			{
				new str[3500];
				strcat(str, "{ffffff}Pekerjaan ini dapat anda dapatkan di Job Center\n\n{7fffd4}CMDS: /loadmoney /unloadmoney /fillatm /repairatm /findatm\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Reflenish Job", str, "Close", "");
			}
			case 9:
			{
				new str[3500];
				strcat(str, "{ffffff}Lokasi pekerjaan ini tersembunyi kamu harus mencari nya sendiri\n\n{7fffd4}CMDS: /smugglemats /sellgun\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Weapon Dealer Job", str, "Close", "");
			}
			case 10:
			{
				new str[3500];
				strcat(str, "{ffffff}Lokasi pekerjaan ini tersembunyi kamu harus mencari nya sendiri\n\n{7fffd4}CMDS: /buydrugs /smuggledrugs /cookmeth\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Drug Dealer Job", str, "Close", "");
			}
			case 11:
			{
				new str[3500];
				strcat(str, "{ffffff}Lokasi side job ini bisa anda cek di GPS Trash Master\n\n{7fffd4}CMDS: /unloadtrash /loadtrash /throwgarbage\n");
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Trash Master (Side Job)", str, "Close", "");
			}
		}
	}
	if(dialogid == DIALOG_GPS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_MORE, DIALOG_STYLE_LIST, "Lokasi Umum", "Departemen Kepolisian\nDepartemen Medis\nRehabilitation Medis\nKantor Berita\nBalai Kota\nSekolah Mengemudi\nPusat Bank\nPemancingan\nGudang Material\nGudang Komponen\nPigPen\nValet Apartemen\nShowroom (Dealership)\nKantor Asuransi\nPasar Lokal (Penjualan Barang)\nMechanic Center", "Select", "Close");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_JOB, DIALOG_STYLE_LIST, "Lokasi Pekerjaan", "Penambang\nTukang Ayam\nPemeras Susu\nLumber Jack\nTrucker Biasa\nTrucker Hauling\nProduction\nFarmer\nTukang ATM\nPenjahit\nPemancingan (Side-Job)\nSupir Bus (Side-Job)\nTukang Sampah (Side-Job)\nSweeper (Side-Job)", "Select", "Close");
				}
				case 2:
				{
					if(GetGarkotNearest(playerid) <= 0)
						return ErrorMsg(playerid, "Tidak ada Garasi Kota di dekat anda");

					new id, count = GetGarkotNearest(playerid), mission[2024], lstr[3024];

					strcat(mission,"No\tLokasi\tJarak\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnGarkotNearestID(playerid, itt);
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d.\t%s\t%0.0fm\n", itt, GetLocation(gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]),GetPlayerDistanceFromPoint(playerid, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]));
						}
						else format(lstr,sizeof(lstr), "%d.\t%s\t%0.0fm\n", itt, GetLocation(gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]), GetPlayerDistanceFromPoint(playerid, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]));
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, GPS_NEAREST_GARKOT, DIALOG_STYLE_TABLIST_HEADERS,"Nearest Public Garage",mission,"Select","Cancel");
				}
				case 3:
				{
					if(GetAnyBusiness() <= 0) return ErrorMsg(playerid, "Tidak ada bisnis di kota ini");
					new id, count = GetAnyBusiness(), location[4096], lstr[596];
					strcat(location,"No\tNama Bisnis\tTipe Bisnis\tJarak\n",sizeof(location));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnBusinessID(itt);

						new type[128];
						if(bData[id][bType] == 1)
						{
							type= "Fast Food";
						}
						else if(bData[id][bType] == 2)
						{
							type= "24/7";
						}
						else if(bData[id][bType] == 3)
						{
							type= "Clothes";
						}
						else if(bData[id][bType] == 4)
						{
							type= "Equipments";
						}
						else if(bData[id][bType] == 5)
						{
							type= "Electronics";
						}
						else
						{
							type= "N/A";
						}
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\t%0.2fm\n", itt, bData[id][bName], type, GetPlayerDistanceFromPoint(playerid, bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\t%0.2fm\n", itt, bData[id][bName], type, GetPlayerDistanceFromPoint(playerid, bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ]));
						strcat(location,lstr,sizeof(location));
					}
					ShowPlayerDialog(playerid, DIALOG_TRACKBUSINESS, DIALOG_STYLE_TABLIST_HEADERS,"List Bisnis",location,"Tandai","Batal");
				}
				case 4:
				{
					if(GetGStationNearest(playerid) <= 0)
						return ErrorMsg(playerid, "Tidak ada Pom Bensin di dekat anda");

					new id, count = GetGStationNearest(playerid), mission[2024], lstr[3024];

					strcat(mission,"No\tLokasi\tJarak\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnGStationNearestID(playerid, itt);
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%0.0fm\n", itt, GetLocation(gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]), GetPlayerDistanceFromPoint(playerid, gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%0.0fm\n", itt, GetLocation(gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]), GetPlayerDistanceFromPoint(playerid, gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]));
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, GPS_NEAREST_GSTATION, DIALOG_STYLE_TABLIST_HEADERS,"Nearest Gas Station",mission,"Select","Cancel");
					return 1;
				}
				case 5:
				{
					if(GetWorkshopNearest() <= 0)
						return ErrorMsg(playerid, "Tidak dapat menemukan workshop dikota");

					new id, count = GetWorkshopNearest(), mission[2024], lstr[3024], wsstatus[128];

					strcat(mission,"No\tNama\tStatus\tJarak\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnWorkshopNearestID(itt);
						if(wData[id][wStatus] == 1)
						{
							wsstatus = "{FF0000}Closed{FFFFFF}";
						}
						else
						{
							wsstatus = "{00FF00}Opened{FFFFFF}";
						}
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\t%0.0fm\n", itt, wData[id][wName], wsstatus, GetPlayerDistanceFromPoint(playerid, wData[id][wExtposX], wData[id][wExtposY], wData[id][wExtposZ]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\t%0.0fm\n", itt, wData[id][wName], wsstatus, GetPlayerDistanceFromPoint(playerid, wData[id][wExtposX], wData[id][wExtposY], wData[id][wExtposZ]));
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, GPS_NEAREST_WORKSHOP, DIALOG_STYLE_TABLIST_HEADERS,"Nearest Workshop",mission,"Select","Cancel");
					return 1;
				}
				case 6:
				{
					if(pData[playerid][pJob] == 11 || pData[playerid][pJob2] == 11)
					{
						if(GetATMStatus() <= 0)
							return ErrorMsg(playerid, "Tidak ada ATM yang kekurangan Stock/Rusak");

						new id, count = GetATMStatus(), mission[2024], lstr[3024], status[128];

						strcat(mission,"No\tLokasi\tStatus\n",sizeof(mission));
						Loop(itt, (count + 1), 1)
						{
							id = ReturnRestockATMID(itt);

							if(AtmData[id][atmStatus] == 0)
							{
								status = ""GREEN_LIGHT"Good";
							}
							else
							{
								status = ""RED_E"Damaged";
							}
							if(itt == count)
							{
								format(lstr,sizeof(lstr), "%d\t%s\t%s\n", itt, GetLocation(AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]), status);
							}
							else format(lstr,sizeof(lstr), "%d\t%s\t%s\n", itt, GetLocation(AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]), status);	
							strcat(mission,lstr,sizeof(mission));
						}
						ShowPlayerDialog(playerid, DIALOG_FIND_ATM, DIALOG_STYLE_TABLIST_HEADERS,"ATM Checker",mission,"Start","Cancel");
					}
					else return ErrorMsg(playerid, "Anda bukan pekerja Reflenish");
					return 1;
				}
				case 7:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_PERSONAL, DIALOG_STYLE_LIST, "Property Saya", "Rumah\nVending\nDealer\nPeternakan Pribadi\nKendaraan Saya", "Select", "No");
				}
				case 8:
				{
					SetPlayerRaceCheckpoint(playerid, 1, 2082.7722, -2033.2288, 13.5469, 0.0, 0.0, 0.0, 3.5); //APARTEMENT
					Info(playerid, "GPS active! Ikuti Checkpoint.");					
				}
				case 9:
				{
					if(pData[playerid][pCP] > 1 || pData[playerid][pSideJob] > 1)
						return ErrorMsg(playerid, "Pekerjaan anda belum selesai");

					DisablePlayerCheckpoint(playerid);
					DisablePlayerRaceCheckpoint(playerid);
				}
			}
		}
	}				
	/*if(dialogid == DIALOG_GPS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pCP] > 1 || pData[playerid][pSideJob] > 1)
						return Error(playerid, "Harap selesaikan Pekerjaan mu terlebih dahulu");

					DisablePlayerCheckpoint(playerid);
					DisablePlayerRaceCheckpoint(playerid);
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_MORE, DIALOG_STYLE_LIST, "GPS PUBLIC", "Police Station\nHospital\nNews Agency\nRehabilitation\nFishing Area\nRental Boat\nMechanic City\nMaterial Store\nComponent Store\nCasino\nStrip Club\nVIP Lounge\nInsurance Vehicle\nCafe Food\nShowroom nanda (Dealership)\n", "Select", "Close");
				}
				case 2:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_PERSONAL, DIALOG_STYLE_LIST, "Personal GPS", "My House\nMy Vending\nMy Dealer\nMy Private Farm\nMy Vehicle", "Select", "No");
				}
				case 3:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_NEAREST, DIALOG_STYLE_LIST, "Nearest GPS", "Nearest Public Garage\nNearest Dealer\nNearest Workshop\nNearest Gas Station\nNearest FindAtm", "Select", "No");
				}
				case 4:
				{
					SetPlayerRaceCheckpoint(playerid,1,  1245.3564, -2048.3530, 60.0434, 0.0, 0.0, 0.0, 3.5); //CITY HALL
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 5:
				{
					SetPlayerRaceCheckpoint(playerid,1, 1220.06, -1814.11, 16.59, 0.0, 0.0, 0.0, 3.5); //DRIVING SCHOOL
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 6:
				{
					SetPlayerRaceCheckpoint(playerid,1, 1464.98, -1011.79, 26.84, 0.0, 0.0, 0.0, 3.5); //BANK
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 7:
				{
					SetPlayerRaceCheckpoint(playerid,1, 332.15, -1516.88, 35.86, 0.0, 0.0, 0.0, 3.5); //APARTEMENT
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 8:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_JOB, DIALOG_STYLE_LIST, "GPS JOBS LOCATION", "Mechanic\nLumber Jack\nTrucker\nMiner\nProduction\nFarmer\nHauling\nPizza Man\nAyam (Pemotong Daging)\nReflenish (Pengisi ATM)\nCow Milker(Pemeras Susu)\nFisherman(Side Job)\nBus(Side Job)\nTrash Master(Side Job)\nSweeper (Side Job)", "Select", "Close");
				}
				case 9:
				{
					if(GetAnyBusiness() <= 0) return ErrorMsg(playerid, "Tidak ada bisnis di kota ini");
					new id, count = GetAnyBusiness(), location[4096], lstr[596];
					strcat(location,"No\tNama Bisnis\tTipe Bisnis\tJarak\n",sizeof(location));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnBusinessID(itt);

						new type[128];
						if(bData[id][bType] == 1)
						{
							type= "Fast Food";
						}
						else if(bData[id][bType] == 2)
						{
							type= "24/7";
						}
						else if(bData[id][bType] == 3)
						{
							type= "Clothes";
						}
						else if(bData[id][bType] == 4)
						{
							type= "Equipments";
						}
						else if(bData[id][bType] == 5)
						{
							type= "Electronics";
						}
						else
						{
							type= "N/A";
						}
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\t%0.2fm\n", itt, bData[id][bName], type, GetPlayerDistanceFromPoint(playerid, bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\t%0.2fm\n", itt, bData[id][bName], type, GetPlayerDistanceFromPoint(playerid, bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ]));
						strcat(location,lstr,sizeof(location));
					}
					ShowPlayerDialog(playerid, DIALOG_TRACKBUSINESS, DIALOG_STYLE_TABLIST_HEADERS,"List Bisnis",location,"Tandai","Batal");
				}
				case 10:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_HEALING, DIALOG_STYLE_LIST, "Healing Location", "Santa Maria Beach\nWarung\nPig Pen", "Select", "No");
				}
			}
		}
	}*/
	if(dialogid == DIALOG_GPS_HEALING)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					SetPlayerRaceCheckpoint(playerid, 1, 371.6579, -2044.5204, 7.6719, 0.0, 0.0, 0.0, 3);
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 1:
				{
					SetPlayerRaceCheckpoint(playerid, 1, 563.8675, -1815.0511, 6.0825, 0.0, 0.0, 0.0, 3);
					Info(playerid, "GPS active! ikuti Checkpoint.");
				}
				case 2:
				{
					SetPlayerRaceCheckpoint(playerid, 1, 2417.0444, -1247.6023, 23.8125, 0.0, 0.0, 0.0, 3);
					Info(playerid, "GPS active! ikuti Checkpoint.");
				}
			}
		}
	}
	if(dialogid == DIALOG_TRACKBUSINESS)
	{
		if(response)
		{
			new id = ReturnBusinessID((listitem + 1));
			pData[playerid][pTrackBisnis] = 1;
			SetPlayerWaze(playerid, Float:bData[id][bExtposX], Float:bData[id][bExtposY], Float:bData[id][bExtposZ], 0x8A44E4FF);
			SetPlayerRaceCheckpoint(playerid, 1, bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ], 0.0, 0.0, 0.0, 3.5);
			Info(playerid, "GPS anda telah aktif");
		}
	}
	if(dialogid == DIALOG_GPS_NEAREST)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(GetGarkotNearest(playerid) <= 0)
						return Error(playerid, "Tidak ada Public Garage yang berjarak 10km (10000 meter) darimu.");

					new id, count = GetGarkotNearest(playerid), mission[2024], lstr[3024];

					strcat(mission,"NO\tLOCATION\tDISTANCE\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnGarkotNearestID(playerid, itt);
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d.\t%s\t%0.0fm\n", itt, GetLocation(gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]),GetPlayerDistanceFromPoint(playerid, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]));
						}
						else format(lstr,sizeof(lstr), "%d.\t%s\t%0.0fm\n", itt, GetLocation(gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]), GetPlayerDistanceFromPoint(playerid, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]));
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, GPS_NEAREST_GARKOT, DIALOG_STYLE_TABLIST_HEADERS,"Nearest Public Garage",mission,"Select","Cancel");
				}
				case 1:
				{
					if(GetDealerNearest(playerid) <= 0)
						return Error(playerid, "Tidak ada dealer yang berjarak 10km (10000 meter) darimu.");

					new id, count = GetDealerNearest(playerid), mission[2024], lstr[3024], type[1024];

					strcat(mission,"NO\tTYPE\tDISTANCE\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnDealerNearestID(playerid, itt);
						if(drData[id][dType] == 1)
						{
							type = "Bikes Vehicles";
						}
						else if(drData[id][dType] == 2)
						{
							type = "Cars";
						}
						else if(drData[id][dType] == 3)
						{
							type = "Unique Cars";
						}
						else if(drData[id][dType] == 4)
						{
							type = "Job Cars";
						}
						else if(drData[id][dType] == 5)
						{
							type = "Rental Jobs";
						}
						else
						{
							type = "{FF0000}Unknown{FFFFFF}";
						}
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%0.0fm\n", itt, type, GetPlayerDistanceFromPoint(playerid, drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%0.0fm\n", itt, type, GetPlayerDistanceFromPoint(playerid, drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]));
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, GPS_NEAREST_DEALER, DIALOG_STYLE_TABLIST_HEADERS,"Nearest Dealer",mission,"Select","Cancel");
				}
				case 2:
				{
					if(GetWorkshopNearest() <= 0)
						return Error(playerid, "Tidak dapat menemukan workshop dikota.");

					new id, count = GetWorkshopNearest(), mission[2024], lstr[3024], wsstatus[128];

					strcat(mission,"NO\tNAME\tSTATUS\tDISTANCE\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnWorkshopNearestID(itt);
						if(wData[id][wStatus] == 1)
						{
							wsstatus = "{FF0000}Closed{FFFFFF}";
						}
						else
						{
							wsstatus = "{00FF00}Opened{FFFFFF}";
						}
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\t%0.0fm\n", itt, wData[id][wName], wsstatus, GetPlayerDistanceFromPoint(playerid, wData[id][wExtposX], wData[id][wExtposY], wData[id][wExtposZ]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\t%0.0fm\n", itt, wData[id][wName], wsstatus, GetPlayerDistanceFromPoint(playerid, wData[id][wExtposX], wData[id][wExtposY], wData[id][wExtposZ]));
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, GPS_NEAREST_WORKSHOP, DIALOG_STYLE_TABLIST_HEADERS,"Nearest Workshop",mission,"Select","Cancel");
					return 1;
				}
				case 3:
				{
					if(GetGStationNearest(playerid) <= 0)
						return Error(playerid, "Tidak ada Gas Station yang berjarak 10km (10000 meter) darimu.");

					new id, count = GetGStationNearest(playerid), mission[2024], lstr[3024];

					strcat(mission,"NO\tLOCATION\tDISTANCE\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnGStationNearestID(playerid, itt);
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%0.0fm\n", itt, GetLocation(gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]), GetPlayerDistanceFromPoint(playerid, gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%0.0fm\n", itt, GetLocation(gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]), GetPlayerDistanceFromPoint(playerid, gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]));
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, GPS_NEAREST_GSTATION, DIALOG_STYLE_TABLIST_HEADERS,"Nearest Gas Station",mission,"Select","Cancel");
					return 1;
				}
				case 4:
				{
					if(pData[playerid][pJob] == 11 || pData[playerid][pJob2] == 11)
					{
						if(GetATMStatus() <= 0)
							return ErrorMsg(playerid, "Tidak ada ATM yang kekurangan Stock/Rusak");

						new id, count = GetATMStatus(), mission[2024], lstr[3024], status[128];

						strcat(mission,"NO\tLOCATION\tSTATUS\n",sizeof(mission));
						Loop(itt, (count + 1), 1)
						{
							id = ReturnRestockATMID(itt);

							if(AtmData[id][atmStatus] == 0)
							{
								status = ""GREEN_LIGHT"Good";
							}
							else
							{
								status = ""RED_E"Damaged";
							}
							if(itt == count)
							{
								format(lstr,sizeof(lstr), "%d\t%s\t%s\n", itt, GetLocation(AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]), status);
							}
							else format(lstr,sizeof(lstr), "%d\t%s\t%s\n", itt, GetLocation(AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]), status);	
							strcat(mission,lstr,sizeof(mission));
						}
						ShowPlayerDialog(playerid, DIALOG_FIND_ATM, DIALOG_STYLE_TABLIST_HEADERS,"ATM Checker",mission,"Start","Cancel");
					}
					else return ErrorMsg(playerid, "Anda bukan pekerja reflenish");
					return 1;
				}
			}
		}
		return 1;
	}
	if(dialogid == GPS_NEAREST_GARKOT)
	{
		if(response)
		{
			new id = ReturnGarkotNearestID(playerid, (listitem+1));
			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerWaze(playerid, Float:gkData[id][gkX], Float:gkData[id][gkY], Float:gkData[id][gkZ], 0x8A44E4FF);
			SetPlayerRaceCheckpoint(playerid, 1, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ], 0.0, 0.0, 0.0, 7.0); //GPS GARKOT
			Info(playerid, "GPS Active! Public Garage (ID: %d) yang berjarak %0.0fm berlokasi di %s telah ditandai", id, GetPlayerDistanceFromPoint(playerid, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]), GetLocation(gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]));
		}
	}
	if(dialogid == GPS_NEAREST_DEALER)
	{
		if(response)
		{
			new id = ReturnDealerNearestID(playerid, (listitem+1));
			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerRaceCheckpoint(playerid, 1, drData[id][dPosX], drData[id][dPosY], drData[id][dPosZ], 0.0, 0.0, 0.0, 7.0); //GPS DEALER
			Info(playerid, "GPS Active! Dealer yang berjarak %0.0fm berlokasi di %s telah ditandai", GetPlayerDistanceFromPoint(playerid, drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]), GetLocation(drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]));
		}
	}
	if(dialogid == GPS_NEAREST_WORKSHOP)
	{
		if(response)
		{
			new id = ReturnWorkshopNearestID((listitem+1));
			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerWaze(playerid, Float:wData[id][wExtposX], Float:wData[id][wExtposY], Float:wData[id][wExtposZ], 0x8A44E4FF);
			SetPlayerRaceCheckpoint(playerid, 1, wData[id][wExtposX], wData[id][wExtposY], wData[id][wExtposZ], 0.0, 0.0, 0.0, 7.0); //GPS WORKSHOP
			Info(playerid, "GPS Active! Workshop yang berjarak %0.0fm berlokasi di %s telah ditandai", GetPlayerDistanceFromPoint(playerid, wData[id][wExtposX], wData[id][wExtposY], wData[id][wExtposZ]), GetLocation(wData[id][wExtposX], wData[id][wExtposY], wData[id][wExtposZ]));
		}
	}
	if(dialogid == GPS_NEAREST_GSTATION)
	{
		if(response)
		{
			new id = ReturnGStationNearestID(playerid, (listitem+1));
			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerWaze(playerid, Float:gsData[id][gsPosX], Float:gsData[id][gsPosY], Float:gsData[id][gsPosZ], 0x8A44E4FF);
			SetPlayerRaceCheckpoint(playerid, 1, gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ], 0.0, 0.0, 0.0, 7.0); //GPS GAS STATION
			Info(playerid, "GPS Active! Gas Station yang berjarak %0.0fm berlokasi di %s telah ditandai", GetPlayerDistanceFromPoint(playerid, gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]), GetLocation(gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]));
		}
	}
	if(dialogid == DIALOG_GPS_PERSONAL)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					return callcmd::myhouse(playerid, "");
				}
				case 1:
				{
					return callcmd::myvending(playerid);
				}
				case 2:
				{
					return callcmd::mydealer(playerid);
				}
				case 3:
				{
					return callcmd::mypfarm(playerid);
				}
				case 4:
				{
					return callcmd::mypv(playerid, "");
				}
			}
		}
	}
	if(dialogid == DIALOG_GPS_JOB)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_MINE, DIALOG_STYLE_LIST, "Penambang Maps", "Tambang Batu\nPencucian Batu\nPeleburan Batu\nPenjualan Tambang", "Select", "Close");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_AYAM, DIALOG_STYLE_LIST, "Pemotong Ayam Maps", "Pengambilan Ayam\nPemroses Ayam\nPenjualan Ayam", "Select", "Close");
				}
				case 2:
				{
					SetPlayerRaceCheckpoint(playerid,1, 303.56, 1140.85, 8.58, 0.0, 0.0, 0.0, 3.5); // Pemeras Susu
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 3:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_LUMBER, DIALOG_STYLE_LIST, "LumberJack", "Pohon\nProses Kayu", "", "");
				}
				case 4:
				{
					SetPlayerRaceCheckpoint(playerid,1, -77.11, -1136.48, 1.07, 0.0, 0.0, 0.0, 3.5); //Trucker
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 5:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2750.03, -2450.83, 13.64, 0.0, 0.0, 0.0, 3.5); //Hauling
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 6:
				{
					SetPlayerRaceCheckpoint(playerid,1, -266.3265, -2156.5869, 28.8457, 0.0, 0.0, 0.0, 3.5); //Production
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");					
				}
				case 7:
				{
					SetPlayerRaceCheckpoint(playerid,1, -382.86, -1438.84, 26.33, 0.0, 0.0, 0.0, 3.5); //Farmer
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 8:
				{
					SyntaxMsg(playerid, "Cari ATM terdekat di sekitar anda");
				}
				case 9:
				{
					SetPlayerRaceCheckpoint(playerid,1, -184.1162, 1111.9359, 19.7422, 0.0, 0.0, 0.0, 3.5); // penjahit
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 10:
				{
					SetPlayerRaceCheckpoint(playerid,1, 370.15, -2038.16, 7.67, 0.0, 0.0, 0.0, 3.5); //Fisherman
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 11:
				{
					SetPlayerRaceCheckpoint(playerid,1, 1698.79, -1545.35, 13.38, 0.0, 0.0, 0.0, 3.5); //Bus
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 12:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2423.56, -2089.59, 13.53, 0.0, 0.0, 0.0, 3.5); //Trash Master
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 13:
				{
					SetPlayerRaceCheckpoint(playerid, 1, 781.1893, -1136.6997, 23.5533, 0.0, 0.0, 0.0, 3.5); //Sweeper
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
			}
		}
	}
	/*if(dialogid == DIALOG_GPS_JOB)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					SetPlayerRaceCheckpoint(playerid,1, -70.81, -1552.75, 2.64, 0.0, 0.0, 0.0, 3.5); //Mechanic City
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 1:
				{
					SetPlayerRaceCheckpoint(playerid,1, -266.06, -2213.47, 29.04, 0.0, 0.0, 0.0, 3.5); //Lumber
					Info(playerid, "GPS active! Ikuti Checkpoint.");
					
				}
				case 2:
				{
					SetPlayerRaceCheckpoint(playerid,1, -77.11, -1136.48, 1.07, 0.0, 0.0, 0.0, 3.5); //Trucker
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 3:
				{
					ShowPlayerDialog(playerid, PPS_MINE, DIALOG_STYLE_LIST, "GPS JOBS MINE", "Tambang Batu\nCuci Batu\nPeleburan Batu\nPenjualan Hasil Tambang", "Select", "Close");
				}
				case 4:
				{
					SetPlayerRaceCheckpoint(playerid,1, -283.20, -2174.58, 28.66, 0.0, 0.0, 0.0, 3.5); //Production
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 5:
				{
					SetPlayerRaceCheckpoint(playerid,1, -382.86, -1438.84, 26.33, 0.0, 0.0, 0.0, 3.5); //Farmer
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 6:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2750.03, -2450.83, 13.64, 0.0, 0.0, 0.0, 3.5); //Hauling
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 7:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2104.72, -1803.92, 13.55, 0.0, 0.0, 0.0, 3.5); //pizza man
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 8:
				{
					ShowPlayerDialog(playerid, DIALOG_GPS_AYAM, DIALOG_STYLE_LIST, "Gps Job Ayam", "Pengambilan Ayam\nProses Ayam\nPenjualan Ayam", "Select", "Close");
				}
				case 9:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2527.9409, -1664.9344, 15.1669, 0.0, 0.0, 0.0, 3.5); //reflenish
					Info(playerid, "GPS active! Ikuti Checkpoint.");
					Info(playerid, "Pergi ke ATM terdekat! & gunakan {ffff00}/repairatm");
				}
				case 10:
				{
					SetPlayerRaceCheckpoint(playerid,1, 303.56, 1140.85, 8.58, 0.0, 0.0, 0.0, 3.5); //reflenish
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 11:
				{
					SetPlayerRaceCheckpoint(playerid,1, 370.15, -2038.16, 7.67, 0.0, 0.0, 0.0, 3.5); //Fisherman
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 12:
				{
					SetPlayerRaceCheckpoint(playerid,1, 1698.79, -1545.35, 13.38, 0.0, 0.0, 0.0, 3.5); //Bus
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 13:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2423.56, -2089.59, 13.53, 0.0, 0.0, 0.0, 3.5); //Trash Master
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
				case 14:
				{
					SetPlayerRaceCheckpoint(playerid,1, 784.0956, -1135.6714, 23.8281, 0.0, 0.0, 0.0, 3.5); //Sweeper
					Info(playerid, "GPS active! Ikuti Checkpoint.");
				}
			}
		}
	}*/
	if(dialogid == DIALOG_GPS_MINE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					SetPlayerRaceCheckpoint(playerid,1, -845.913513, -2251.354980, 22.442436, 0.0, 0.0, 0.0, 3.5); //Ambil batu
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 1:
				{
					SetPlayerRaceCheckpoint(playerid,1, -759.741027, -2243.501464, 27.824132, 0.0, 0.0, 0.0, 3.5); //Cuci batu
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 2:
				{
					SetPlayerRaceCheckpoint(playerid,1, -797.836059, -2276.645996, 43.296405, 0.0, 0.0, 0.0, 3.5); //Lebur batu
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 3:
				{
					SetPlayerRaceCheckpoint(playerid, 1, 2741.9697, -2370.9541, 13.7167, 0.0, 0.0, 0.0, 3.5); //Penjualan
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
			}
		}
	}
	if(dialogid == DIALOG_GPS_AYAM)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					SetPlayerRaceCheckpoint(playerid,1, 1543.54, 21.3636, 24.1406, 0.0, 0.0, 0.0, 3.5); //Ambil ayam
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 1:
				{
					SetPlayerRaceCheckpoint(playerid, 1, -1029.6366, -1025.4781, 129.2188, 0.0, 0.0, 0.0, 3.5); //Proses
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 2:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2753.5605, -2370.8696, 13.7167, 0.0, 0.0, 0.0, 3.5); //Jual ayam
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
			}
		}
	}
	if(dialogid == DIALOG_GPS_LUMBER)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					SetPlayerRaceCheckpoint(playerid,1, -585.6414, -2371.2654, 27.5126, 0.0, 0.0, 0.0, 3.5); //Lumber
				}
				case 1:
				{
					SetPlayerRaceCheckpoint(playerid,1, -449.5992, -75.2461, 59.4415, 0.0, 0.0, 0.0, 3.5);
				}
			}
		}
	}
	if(dialogid == DIALOG_GPS_MORE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					SetPlayerRaceCheckpoint(playerid,1, 1126.94, -1692.04, 14.01, 0.0,0.0,0.0, 3.5); //Kantor Polisi
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 1:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2003.29, -1444.97, 13.56, 0.0, 0.0, 0.0, 3.5); //Rumah Sakit
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
  				case 2:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2215.11, -63.34, 26.48, 0.0, 0.0, 0.0, 3.5); //Rehabilitation Hospital
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 3:
				{
					SetPlayerRaceCheckpoint(playerid,1, 645.63, -1356.65, 13.56, 0.0, 0.0, 0.0, 3.5); //Kantor Berita
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 4:
				{
					SetPlayerRaceCheckpoint(playerid,1,  1245.3564, -2048.3530, 60.0434, 0.0, 0.0, 0.0, 3.5); //CITY HALL
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 5:
				{
					SetPlayerRaceCheckpoint(playerid,1, 1220.06, -1814.11, 16.59, 0.0, 0.0, 0.0, 3.5); //DRIVING SCHOOL
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 6:
				{
					SetPlayerRaceCheckpoint(playerid,1, 1464.98, -1011.79, 26.84, 0.0, 0.0, 0.0, 3.5); //BANK
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 7:
				{
					SetPlayerRaceCheckpoint(playerid,1, 370.15, -2038.16, 7.67, 0.0, 0.0, 0.0, 3.5); //Pemancingan Umum
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 8:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2801.0269, -2370.2046, 13.7167, 0.0, 0.0, 0.0, 3.5); //Material Store
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 9:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2789.0249, -2370.1021, 13.7167, 0.0, 0.0, 0.0, 3.5); //Component Store
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 10:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2420.26, -1224.75, 25.12, 0.0, 0.0, 0.0, 3.5); //Strip Club
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 11:
				{
					SetPlayerRaceCheckpoint(playerid,1, 332.15, -1516.88, 35.86, 0.0, 0.0, 0.0, 3.5); //APARTEMENT
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 12:
				{
					SetPlayerRaceCheckpoint(playerid,1, 1110.1588, -1740.8998, 13.3984, 0.0, 0.0, 0.0, 3.5); //SHOROOM
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 13:
				{
					SetPlayerRaceCheckpoint(playerid,1, 1502.65, -1671.66, 5013.86, 0.0, 0.0, 0.0, 3.5); //ASURANSI
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");
				}
				case 14:
				{
					SetPlayerRaceCheckpoint(playerid,1, 2749.3562, -2405.5037, 13.6947, 0.0, 0.0, 0.0, 3.5); //Pasar
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");			
				}
				case 15:
				{
					SetPlayerRaceCheckpoint(playerid,1, 214.83, -272.91, 1.57, 0.0, 0.0, 0.0, 3.5); //mekanik
					SuccesMsg(playerid, "Anda telah mengaktifkan Maps");			
				}
			}
		}
	}
	if(dialogid == DIALOG_PAY)
	{
		if(response)
		{
			new mstr[128];
			new otherid = GetPVarInt(playerid, "gcPlayer");
			new money = GetPVarInt(playerid, "gcAmount");

			if(otherid == INVALID_PLAYER_ID)
				return Error(playerid, "Player not connected!");
			GivePlayerMoneyEx(otherid, money);
			GivePlayerMoneyEx(playerid, -money);

			format(mstr, sizeof(mstr), "Server: "YELLOW_E"You have sent %s(%i) "GREEN_E"%s", ReturnName(otherid), otherid, FormatMoney(money));
			SendClientMessage(playerid, COLOR_GREY, mstr);
			format(mstr, sizeof(mstr), "Server: "YELLOW_E"%s(%i) has sent you "GREEN_E"%s", ReturnName(playerid), playerid, FormatMoney(money));
			SendClientMessage(otherid, COLOR_GREY, mstr);
			InfoTD_MSG(playerid, 3000, "~g~~h~Money Sent!");
			InfoTD_MSG(otherid, 3000, "~g~~h~Money received!");
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "%s memberikan uang kepada %s sebesar %s", ReturnName(playerid), ReturnName(otherid), FormatMoney(money));
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "%s menerima uang dari %s sebesar %s", ReturnName(otherid), ReturnName(playerid), FormatMoney(money));
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			
			SendDiscordMessage(0, sprintf("**%s** player memberikan uang kepada **%s**, sejumlah : **__%s__**", ReturnName(playerid), ReturnName(otherid), FormatMoney(money)));
			new query[512];
			mysql_format(g_SQL, query, sizeof(query), "INSERT INTO logpay (player,playerid,toplayer,toplayerid,ammount,time) VALUES('%s','%d','%s','%d','%d',UNIX_TIMESTAMP())", pData[playerid][pName], pData[playerid][pID], pData[otherid][pName], pData[otherid][pID], money);
			mysql_tquery(g_SQL, query);
		}
		return 1;
	}
	//-------------[ Player Weapons Atth ]-----------
	if(dialogid == DIALOG_EDITBONE)
	{
		if(response)
		{
			new weaponid = EditingWeapon[playerid], weaponname[18], string[150];
	 
			GetWeaponName(weaponid, weaponname, sizeof(weaponname));
		   
			WeaponSettings[playerid][weaponid - 22][Bone] = listitem + 1;

			Servers(playerid, "You have successfully changed the bone of your %s.", weaponname);
		   
			mysql_format(g_SQL, string, sizeof(string), "INSERT INTO weaponsettings (Owner, WeaponID, Bone) VALUES ('%d', %d, %d) ON DUPLICATE KEY UPDATE Bone = VALUES(Bone)", pData[playerid][pID], weaponid, listitem + 1);
			mysql_tquery(g_SQL, string);
		}
		EditingWeapon[playerid] = 0;
	}
	//------------[ Family Dialog ]------------
	if(dialogid == FAMILY_SAFE)
	{
		if(!response) return 1;
		new fid = pData[playerid][pFamily];
		switch(listitem) 
		{
			case 0: Family_OpenStorage(playerid, fid);
			case 1:
			{
				//Marijuana
				ShowPlayerDialog(playerid, FAMILY_MARIJUANA, DIALOG_STYLE_LIST, "Marijuana", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
			case 2:
			{
				//Component
				ShowPlayerDialog(playerid, FAMILY_COMPONENT, DIALOG_STYLE_LIST, "Component", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
			case 3:
			{
				//Material
				ShowPlayerDialog(playerid, FAMILY_MATERIAL, DIALOG_STYLE_LIST, "Material", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
			case 4:
			{
				//Money
				ShowPlayerDialog(playerid, FAMILY_MONEY, DIALOG_STYLE_LIST, "Money", "Withdraw from safe\nDeposit into safe", "Select", "Back");
			}
		}
		return 1;
	}
	if(dialogid == FAMILY_STORAGE)
	{
		new fid = pData[playerid][pFamily];
		if(response)
		{
			if(listitem == 0) 
			{
				Family_WeaponStorage(playerid, fid);
			}
		}
		return 1;
	}
	if(dialogid == FAMILY_WEAPONS)
	{
		new fid = pData[playerid][pFamily];
		if(response)
		{
			if(fData[fid][fGun][listitem] != 0)
			{
				if(pData[playerid][pFamilyRank] < 5)
					return Error(playerid, "Only boss can taken the weapon!");
					
				if(PlayerHasWeapon(playerid, fData[fid][fGun][listitem]))
					return Error(playerid, "Kamu sudah memiliki senjata tersebut");

				GivePlayerWeaponEx(playerid, fData[fid][fGun][listitem], fData[fid][fAmmo][listitem]);

				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has taken a \"%s\" from their weapon storage.", ReturnName(playerid), ReturnWeaponName(fData[fid][fGun][listitem]));

				fData[fid][fGun][listitem] = 0;
				fData[fid][fAmmo][listitem] = 0;

				Family_Save(fid);
				Family_WeaponStorage(playerid, fid);
			}
			else
			{
				new
					weaponid = GetPlayerWeaponEx(playerid),
					ammo = GetPlayerAmmoEx(playerid);

				if(!weaponid)
					return Error(playerid, "You are not holding any weapon!");

				/*if(weaponid == 23 && pData[playerid][pTazer])
					return Error(playerid, "You can't store a tazer into your safe.");

				if(weaponid == 25 && pData[playerid][pBeanBag])
					return Error(playerid, "You can't store a beanbag shotgun into your safe.");*/

				ResetWeapon(playerid, weaponid);
				SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has stored a \"%s\" into their weapon storage.", ReturnName(playerid), ReturnWeaponName(weaponid));

				fData[fid][fGun][listitem] = weaponid;
				fData[fid][fAmmo][listitem] = ammo;

				Family_Save(fid);
				Family_WeaponStorage(playerid, fid);
			}
		}
		else
		{
			Family_OpenStorage(playerid, fid);
		}
		return 1;
	}
	if(dialogid == FAMILY_MARIJUANA)
	{
		if(response)
		{
			new fid = pData[playerid][pFamily];
			if(fid == -1) return Error(playerid, "You don't have family.");
			if(response)
			{
				switch (listitem)
				{
					case 0: 
					{
						if(pData[playerid][pFamilyRank] < 5)
							return Error(playerid, "Only boss can withdraw marijuana!");
							
						new str[128];
						format(str, sizeof(str), "Marijuana Balance: %d\n\nPlease enter how much marijuana you wish to withdraw from the safe:", fData[fid][fMarijuana]);
						ShowPlayerDialog(playerid, FAMILY_WITHDRAWMARIJUANA, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
					}
					case 1: 
					{
						new str[128];
						format(str, sizeof(str), "Marijuana Balance: %d\n\nPlease enter how much marijuana you wish to deposit into the safe:", fData[fid][fMarijuana]);
						ShowPlayerDialog(playerid, FAMILY_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
					}
				}
			}
			else callcmd::fsafe(playerid);
		}
		return 1;
	}
	if(dialogid == FAMILY_WITHDRAWMARIJUANA)
	{
		new fid = pData[playerid][pFamily];
		if(fid == -1) return Error(playerid, "You don't have family.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Marijuana Balance: %d\n\nPlease enter how much marijuana you wish to withdraw from the safe:", fData[fid][fMarijuana]);
				ShowPlayerDialog(playerid, FAMILY_WITHDRAWMARIJUANA, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > fData[fid][fMarijuana])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nMarijuana Balance: %d\n\nPlease enter how much marijuana you wish to withdraw from the safe:", fData[fid][fMarijuana]);
				ShowPlayerDialog(playerid, FAMILY_WITHDRAWMARIJUANA, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			fData[fid][fMarijuana] -= amount;
			Inventory_Add(playerid, "Marijuana", 1578, amount);

			Family_Save(fid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d marijuana from their family safe.", ReturnName(playerid), amount);
			callcmd::fsafe(playerid);
			return 1;
		}
		else callcmd::fsafe(playerid);
		return 1;
	}
	if(dialogid == FAMILY_DEPOSITMARIJUANA)
	{
		new fid = pData[playerid][pFamily];
		if(fid == -1) return Error(playerid, "You don't have family.");
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Marijuana Balance: %d\n\nPlease enter how much marijuana you wish to deposit into the safe:", fData[fid][fMarijuana]);
				ShowPlayerDialog(playerid, FAMILY_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Marijuana"))
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nMarijuana Balance: %d\n\nPlease enter how much marijuana you wish to deposit into the safe:", fData[fid][fMarijuana]);
				ShowPlayerDialog(playerid, FAMILY_DEPOSITMARIJUANA, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			fData[fid][fMarijuana] += amount;
			Inventory_Remove(playerid, "Marijuana", amount);

			Family_Save(fid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d marijuana into their family safe.", ReturnName(playerid), amount);
		}
		else callcmd::fsafe(playerid);
		return 1;
	}
	if(dialogid == FAMILY_COMPONENT)
	{
		if(response)
		{
			new fid = pData[playerid][pFamily];
			if(fid == -1) return Error(playerid, "You don't have family.");
			if(response)
			{
				switch (listitem)
				{
					case 0: 
					{
						if(pData[playerid][pFamilyRank] < 5)
							return Error(playerid, "Only boss can withdraw component!");
							
						new str[128];
						format(str, sizeof(str), "Component Balance: %d\n\nPlease enter how much component you wish to withdraw from the safe:", fData[fid][fComponent]);
						ShowPlayerDialog(playerid, FAMILY_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
					}
					case 1: 
					{
						new str[128];
						format(str, sizeof(str), "Component Balance: %d\n\nPlease enter how much component you wish to deposit into the safe:", fData[fid][fComponent]);
						ShowPlayerDialog(playerid, FAMILY_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
					}
				}
			}
			else callcmd::fsafe(playerid);
		}
		return 1;
	}
	if(dialogid == FAMILY_WITHDRAWCOMPONENT)
	{
		new fid = pData[playerid][pFamily];
		if(fid == -1) return Error(playerid, "You don't have family.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Component Balance: %d\n\nPlease enter how much component you wish to withdraw from the safe:", fData[fid][fComponent]);
				ShowPlayerDialog(playerid, FAMILY_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > fData[fid][fComponent])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nComponent Balance: %d\n\nPlease enter how much component you wish to withdraw from the safe:", fData[fid][fComponent]);
				ShowPlayerDialog(playerid, FAMILY_WITHDRAWCOMPONENT, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			fData[fid][fComponent] -= amount;
			Inventory_Add(playerid, "Component", 19627, amount);

			Family_Save(fid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d component from their family safe.", ReturnName(playerid), amount);
			callcmd::fsafe(playerid);
			return 1;
		}
		else callcmd::fsafe(playerid);
		return 1;
	}
	if(dialogid == FAMILY_DEPOSITCOMPONENT)
	{
		new fid = pData[playerid][pFamily];
		if(fid == -1) return Error(playerid, "You don't have family.");
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Component Balance: %d\n\nPlease enter how much component you wish to deposit into the safe:", fData[fid][fComponent]);
				ShowPlayerDialog(playerid, FAMILY_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Component"))
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nComponent Balance: %d\n\nPlease enter how much component you wish to deposit into the safe:", fData[fid][fComponent]);
				ShowPlayerDialog(playerid, FAMILY_DEPOSITCOMPONENT, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			fData[fid][fComponent] += amount;
			Inventory_Remove(playerid, "Component", amount);

			Family_Save(fid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d component into their family safe.", ReturnName(playerid), amount);
		}
		else callcmd::fsafe(playerid);
		return 1;
	}
	if(dialogid == FAMILY_MATERIAL)
	{
		if(response)
		{
			new fid = pData[playerid][pFamily];
			if(fid == -1) return Error(playerid, "You don't have family.");
			if(response)
			{
				switch (listitem)
				{
					case 0: 
					{
						if(pData[playerid][pFamilyRank] < 5)
							return Error(playerid, "Only boss can withdraw material!");
							
						new str[128];
						format(str, sizeof(str), "Material Balance: %d\n\nPlease enter how much material you wish to withdraw from the safe:", fData[fid][fMaterial]);
						ShowPlayerDialog(playerid, FAMILY_WITHDRAWMATERIAL, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
					}
					case 1: 
					{
						new str[128];
						format(str, sizeof(str), "Material Balance: %d\n\nPlease enter how much material you wish to deposit into the safe:", fData[fid][fMaterial]);
						ShowPlayerDialog(playerid, FAMILY_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
					}
				}
			}
			else callcmd::fsafe(playerid);
		}
		return 1;
	}
	if(dialogid == FAMILY_WITHDRAWMATERIAL)
	{
		new fid = pData[playerid][pFamily];
		if(fid == -1) return Error(playerid, "You don't have family.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Material Balance: %d\n\nPlease enter how much material you wish to withdraw from the safe:", fData[fid][fMaterial]);
				ShowPlayerDialog(playerid, FAMILY_WITHDRAWMATERIAL, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > fData[fid][fMaterial])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nMaterial Balance: %d\n\nPlease enter how much material you wish to withdraw from the safe:", fData[fid][fMaterial]);
				ShowPlayerDialog(playerid, FAMILY_WITHDRAWMATERIAL, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			fData[fid][fMaterial] -= amount;
			Inventory_Add(playerid, "Material", 17051, amount);

			Family_Save(fid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %d material from their family safe.", ReturnName(playerid), amount);
			callcmd::fsafe(playerid);
			return 1;
		}
		else callcmd::fsafe(playerid);
		return 1;
	}
	if(dialogid == FAMILY_DEPOSITMATERIAL)
	{
		new fid = pData[playerid][pFamily];
		if(fid == -1) return Error(playerid, "You don't have family.");
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Material Balance: %d\n\nPlease enter how much material you wish to deposit into the safe:", fData[fid][fMaterial]);
				ShowPlayerDialog(playerid, FAMILY_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > Inventory_Count(playerid, "Material"))
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nMaterial Balance: %d\n\nPlease enter how much material you wish to deposit into the safe:", fData[fid][fMaterial]);
				ShowPlayerDialog(playerid, FAMILY_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			fData[fid][fMaterial] += amount;
			Inventory_Remove(playerid, "Material", amount);

			Family_Save(fid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %d material into their family safe.", ReturnName(playerid), amount);
		}
		else callcmd::fsafe(playerid );
		return 1;
	}
	if(dialogid == FAMILY_MONEY)
	{
		if(response)
		{
			new fid = pData[playerid][pFamily];
			if(fid == -1) return Error(playerid, "You don't have family.");
			if(response)
			{
				switch (listitem)
				{
					case 0: 
					{
						if(pData[playerid][pFamilyRank] < 5)
							return Error(playerid, "Only boss can withdraw money!");
							
						new str[128];
						format(str, sizeof(str), "Money Balance: %s\n\nPlease enter how much money you wish to withdraw from the safe:", FormatMoney(fData[fid][fMoney]));
						ShowPlayerDialog(playerid, FAMILY_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
					}
					case 1: 
					{
						new str[128];
						format(str, sizeof(str), "Money Balance: %s\n\nPlease enter how much money you wish to deposit into the safe:", FormatMoney(fData[fid][fMoney]));
						ShowPlayerDialog(playerid, FAMILY_DEPOSITMONEY, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
					}
				}
			}
			else callcmd::fsafe(playerid);
		}
		return 1;
	}
	if(dialogid == FAMILY_WITHDRAWMONEY)
	{
		new fid = pData[playerid][pFamily];
		if(fid == -1) return Error(playerid, "You don't have family.");
		
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Money Balance: %s\n\nPlease enter how much money you wish to withdraw from the safe:", FormatMoney(fData[fid][fMoney]));
				ShowPlayerDialog(playerid, FAMILY_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			if(amount < 1 || amount > fData[fid][fMoney])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nMoney Balance: %s\n\nPlease enter how much money you wish to withdraw from the safe:", FormatMoney(fData[fid][fMoney]));
				ShowPlayerDialog(playerid, FAMILY_WITHDRAWMONEY, DIALOG_STYLE_INPUT, "Withdraw from safe", str, "Withdraw", "Back");
				return 1;
			}
			fData[fid][fMoney] -= amount;
			GivePlayerMoneyEx(playerid, amount);

			Family_Save(fid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has withdrawn %s money from their family safe.", ReturnName(playerid), FormatMoney(amount));
			callcmd::fsafe(playerid);
			return 1;
		}
		else callcmd::fsafe(playerid);
		return 1;
	}
	if(dialogid == FAMILY_DEPOSITMONEY)
	{
		new fid = pData[playerid][pFamily];
		if(fid == -1) return Error(playerid, "You don't have family.");
		if(response)
		{
			new amount = strval(inputtext);

			if(isnull(inputtext))
			{
				new str[128];
				format(str, sizeof(str), "Money Balance: %s\n\nPlease enter how much money you wish to deposit into the safe:", FormatMoney(fData[fid][fMoney]));
				ShowPlayerDialog(playerid, FAMILY_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			if(amount < 1 || amount > pData[playerid][pMoney])
			{
				new str[128];
				format(str, sizeof(str), "Error: Insufficient funds.\n\nMoney Balance: %s\n\nPlease enter how much money you wish to deposit into the safe:", FormatMoney(fData[fid][fMoney]));
				ShowPlayerDialog(playerid, FAMILY_DEPOSITMATERIAL, DIALOG_STYLE_INPUT, "Deposit into safe", str, "Deposit", "Back");
				return 1;
			}
			fData[fid][fMoney] += amount;
			GivePlayerMoneyEx(playerid, -amount);

			Family_Save(fid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has deposited %s money into their family safe.", ReturnName(playerid), FormatMoney(amount));
		}
		else callcmd::fsafe(playerid);
		return 1;
	}
	if(dialogid == FAMILY_INFO)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pFamily] == -1)
						return Error(playerid, "You dont have family!");
					new query[512];
					mysql_format(g_SQL, query, sizeof(query), "SELECT name,leader,marijuana,component,material,money FROM familys WHERE ID = %d", pData[playerid][pFamily]);
					mysql_tquery(g_SQL, query, "ShowFamilyInfo", "i", playerid);
				}
				case 1:
				{
					if(pData[playerid][pFamily] == -1)
						return Error(playerid, "You dont have family!");
						
					new lstr[1024];
					format(lstr, sizeof(lstr), "Rank\tName\n");
					foreach(new i: Player)
					{
						if(pData[i][pFamily] == pData[playerid][pFamily])
						{
							format(lstr, sizeof(lstr), "%s%s\t%s(%d)", lstr, GetFamilyRank(i), pData[i][pName], i);
							format(lstr, sizeof(lstr), "%s\n", lstr);
						}
					}
					format(lstr, sizeof(lstr), "%s\n", lstr);
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Family Online", lstr, "Close", "");
					
				}
				case 2:
				{
					if(pData[playerid][pFamily] == -1)
						return Error(playerid, "You dont have family!");
					new query[512];
					mysql_format(g_SQL, query, sizeof(query), "SELECT username,familyrank FROM players WHERE family = %d", pData[playerid][pFamily]);
					mysql_tquery(g_SQL, query, "ShowFamilyMember", "i", playerid);
				}
			}
		}
		return 1;
	}
	//------------[ VIP Locker Dialog ]----------
	if(dialogid == DIALOG_LOCKERVIP)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0: 
				{
					SetPlayerHealthEx(playerid, 100);
				}
				case 1:
				{
					GivePlayerWeaponEx(playerid, 1, 1);
					GivePlayerWeaponEx(playerid, 7, 1);
					GivePlayerWeaponEx(playerid, 15, 1);
				}
				case 2:
				{
					switch (pData[playerid][pGender])
					{
						case 1: ShowPlayerSelectionMenu(playerid, VIP_SKIN_MALE, "Choose Your Skin", VipSkinMale, sizeof(VipSkinMale));
						case 2: ShowPlayerSelectionMenu(playerid, VIP_SKIN_FEMALE, "Choose Your Skin", VipSkinFemale, sizeof(VipSkinFemale));
					}
				}
				case 3:
				{
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

					/*if(pToys[playerid][4][toy_model] == 0)
					{
						strcat(string, ""dot"Slot 5\n");
					}
					else strcat(string, ""dot"Slot 5 "RED_E"(Used)\n");

					if(pToys[playerid][5][toy_model] == 0)
					{
						strcat(string, ""dot"Slot 6\n");
					}
					else strcat(string, ""dot"Slot 6 "RED_E"(Used)\n");*/

					ShowPlayerDialog(playerid, DIALOG_TOYVIP, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"VIP Toys", string, "Select", "Cancel");
				}
			}
		}
	}
	if(dialogid == DIALOG_LOCKERMECH)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0: 
				{
					if(pData[playerid][pOnDuty] == 1)
					{
						pData[playerid][pOnDuty] = 0;
						SetPlayerColor(playerid, COLOR_WHITE);
						SetPlayerSkin(playerid, pData[playerid][pSkin]);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s places their badge and gun in their locker.", ReturnName(playerid));
						ResetWeapon(playerid, 25);
						ResetWeapon(playerid, 27);
						ResetWeapon(playerid, 29);
						ResetWeapon(playerid, 31);
						ResetWeapon(playerid, 33);
						ResetWeapon(playerid, 34);
						KillTimer(DutyTimer);
					}
					else
					{
						pData[playerid][pOnDuty] = 1;
						//SetFactionColor(playerid);
						if(pData[playerid][pGender] == 1)
						{
							SetPlayerSkin(playerid, 50);
							pData[playerid][pFacSkin] = 50;
						}
						else
						{
							SetPlayerSkin(playerid, 224);
							pData[playerid][pFacSkin] = 224;
						}
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s withdraws their badge and on duty from their locker", ReturnName(playerid));
					}
				}
			}
		}
	}
	//-------------[ Faction Commands Dialog ]-----------
	if(dialogid == DIALOG_LOCKERSAPD)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0: 
				{
					if(pData[playerid][pOnDuty] == 1)
					{
						pData[playerid][pOnDuty] = 0;
						SetPlayerColor(playerid, COLOR_WHITE);
						SetPlayerSkin(playerid, pData[playerid][pSkin]);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s places their badge and gun in their locker.", ReturnName(playerid));
						ResetWeapon(playerid, 25);
						ResetWeapon(playerid, 27);
						ResetWeapon(playerid, 29);
						ResetWeapon(playerid, 31);
						ResetWeapon(playerid, 33);
						ResetWeapon(playerid, 34);
						KillTimer(DutyTimer);
					}
					else
					{
						pData[playerid][pOnDuty] = 1;
						//SetFactionColor(playerid);
						if(pData[playerid][pGender] == 1)
						{
							SetPlayerSkin(playerid, 300);
							pData[playerid][pFacSkin] = 300;
						}
						else
						{
							SetPlayerSkin(playerid, 306);
							pData[playerid][pFacSkin] = 306;
						}
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s withdraws their badge and on duty from their locker", ReturnName(playerid));
					}
				}
				case 1: 
				{
					SetPlayerHealthEx(playerid, 100);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s telah mengambil medical kit dari locker", ReturnName(playerid));
				}
				case 2:
				{
					Inventory_Add(playerid, "Kevlar", 1242, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s telah mengambil armour pelindung dari locker", ReturnName(playerid));
				}
				case 3:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
						
					ShowPlayerDialog(playerid, DIALOG_WEAPONSAPD, DIALOG_STYLE_LIST, "SAPD Weapons/Items", "TEST DRUG\nSPRAYCAN\nPARACHUTE\nNITE STICK\nKNIFE\nCOLT45\nSILENCED\nDEAGLE\nSHOTGUN\nSHOTGSPA\nMP5\nM4", "Pilih", "Batal");
				}
				case 4:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
					
					switch (pData[playerid][pGender])
					{
						case 1: ShowPlayerSelectionMenu(playerid, SAPD_SKIN_MALE, "Choose Your Skin", SAPDSkinMale, sizeof(SAPDSkinMale));
						case 2: ShowPlayerSelectionMenu(playerid, SAPD_SKIN_FEMALE, "Choose Your Skin", SAPDSkinFemale, sizeof(SAPDSkinFemale));
					}
				}
				case 5:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "You are not allowed!");
					
					switch (pData[playerid][pGender])
					{
						case 1: ShowPlayerSelectionMenu(playerid, SAPD_SKIN_WAR, "Choose Your Skin", SAPDSkinMale, sizeof(SAPDSkinMale));
						case 2: ShowPlayerSelectionMenu(playerid, SAPD_SKIN_FEMALE, "Choose Your Skin", SAPDSkinFemale, sizeof(SAPDSkinFemale));
					}
				}
				case 6:
				{
					if(pData[playerid][pFactionRank] < 7)
						return ErrorMsg(playerid, "Anda tidak memiliki akses untuk menggunakan berangkas uang");

					ShowPlayerDialog(playerid, DIALOG_MONEYSAPD, DIALOG_STYLE_LIST, "SAPD Vault Money", "Deposit\nWithdraw\n", "Select", "Close");					
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_MONEYSAPD)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_MONEYSAPDDEPOSIT, DIALOG_STYLE_INPUT, "SAPD Vault Money", "Masukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_MONEYSAPDWITHDRAW, DIALOG_STYLE_INPUT, "SAPD Vault Money", "Masukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				}				
			}
		}
	}
	if(dialogid == DIALOG_MONEYSAPDWITHDRAW)
	{
		if(response)
		{
			new amount = strval(inputtext);
			new lid = 0;
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAPDWITHDRAW, DIALOG_STYLE_INPUT, "SAPD Vault Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			if(amount < 1 || amount > lData[lid][lMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAPDWITHDRAW, DIALOG_STYLE_INPUT, "SAPD Vault Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			lData[lid][lMoney] -= amount;
			GivePlayerMoneyEx(playerid, amount);
			Locker_Save(lid);
	        Locker_Refresh(lid);
			SendFactionMessage(1, -1, "{0900FF}SAPDLOG: {FFFFFF}%s telah mengambil uang di berangkas sejumlah %s", pData[playerid][pName], FormatMoney(amount));
		}		
	}
	if(dialogid == DIALOG_MONEYSAPDDEPOSIT)
	{
		if(response)
		{
			new amount = strval(inputtext);
			new lid = 0;
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAPDDEPOSIT, DIALOG_STYLE_INPUT, "SAPD Vault Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			if(amount < 1 || amount > pData[playerid][pMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAPDDEPOSIT, DIALOG_STYLE_INPUT, "SAPD Vault Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			lData[lid][lMoney] += amount;
			GivePlayerMoneyEx(playerid, -amount);
			Locker_Save(lid);
	        Locker_Refresh(lid);
			SendFactionMessage(1, -1, "{0900FF}SAPDLOG: {FFFFFF}%s telah memasukan uang di berangkas sejumlah %s", pData[playerid][pName], FormatMoney(amount));
		}
	}
	if(dialogid == DIALOG_WEAPONSAPD)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0:
				{
					Inventory_Add(playerid, "Test Drug", 1579, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s  open the locker and take the drug test kit.", ReturnName(playerid));
				}
				case 1:
				{
					if(PlayerHasWeapon(playerid, 46))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 41, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(41));
				}
				case 2:
				{
					if(PlayerHasWeapon(playerid, 46))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 46, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(46));
				}
				case 3:
				{
					if(PlayerHasWeapon(playerid, 3))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 3, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(3));
				}
				case 4:
				{
					if(PlayerHasWeapon(playerid, 4))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 4, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(4));
				}
				case 5:
				{
					if(PlayerHasWeapon(playerid, 22))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 22, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(22));
				}
				case 6:
				{
					if(pData[playerid][pFactionRank] < 2)
						return Error(playerid, "You are not allowed!");
					
					if(PlayerHasWeapon(playerid, 23))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 23, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(23));
				}
				case 7:
				{
					if(pData[playerid][pFactionRank] < 2)
						return Error(playerid, "You are not allowed!");
					
					if(PlayerHasWeapon(playerid, 24))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 24, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(24));
				}	
				case 8:
				{
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "You are not allowed!");

					if(PlayerHasWeapon(playerid, 25))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 25, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(25));
				}
				case 9:
				{
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "You are not allowed!");

					if(PlayerHasWeapon(playerid, 27))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 27, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(27));
				}
				case 10:
				{
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "You are not allowed!");

					if(PlayerHasWeapon(playerid, 29))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 29, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(29));
				}
				case 11:
				{
					if(pData[playerid][pFactionRank] < 4)
						return Error(playerid, "You are not allowed!");

					if(PlayerHasWeapon(playerid, 31))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 31, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(31));
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_LOCKERSAGS)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0: 
				{
					if(pData[playerid][pOnDuty] == 1)
					{
						pData[playerid][pOnDuty] = 0;
						SetPlayerColor(playerid, COLOR_WHITE);
						SetPlayerSkin(playerid, pData[playerid][pSkin]);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s places their badge and gun in their locker.", ReturnName(playerid));
					}
					else
					{
						pData[playerid][pOnDuty] = 1;
						//SetFactionColor(playerid);
						if(pData[playerid][pGender] == 1)
						{
							SetPlayerSkin(playerid, 295);
							pData[playerid][pFacSkin] = 295;
						}
						else
						{
							SetPlayerSkin(playerid, 141);
							pData[playerid][pFacSkin] = 141;
						}
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s withdraws their badge and on duty from their locker", ReturnName(playerid));
					}
				}
				case 1: 
				{
					SetPlayerHealthEx(playerid, 100);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s telah mengambil medical kit dari locker", ReturnName(playerid));
				}
				case 2:
				{
					Inventory_Add(playerid, "Kevlar", 1242, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s telah mengambil armour pelindung dari locker", ReturnName(playerid));
				}
				case 3:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
						
					ShowPlayerDialog(playerid, DIALOG_WEAPONSAGS, DIALOG_STYLE_LIST, "SAGS Weapons", "SPRAYCAN\nPARACHUTE\nNITE STICK\nKNIFE\nCOLT45\nSILENCED\nDEAGLE\nMP5", "Pilih", "Batal");
				}
				case 4:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
					switch (pData[playerid][pGender])
					{
						case 1: ShowPlayerSelectionMenu(playerid, SAGS_SKIN_MALE, "Choose Your Skin", SAGSSkinMale, sizeof(SAGSSkinMale));
						case 2: ShowPlayerSelectionMenu(playerid, SAGS_SKIN_FEMALE, "Choose Your Skin", SAGSSkinFemale, sizeof(SAGSSkinFemale));
					}
				}
				case 5:
				{
					if(pData[playerid][pFactionRank] < 5)
						return ErrorMsg(playerid, "Anda tidak memiliki akses untuk menggunakan berangkas uang");
					ShowPlayerDialog(playerid, DIALOG_MONEYSAGS, DIALOG_STYLE_LIST, "SAGS Vault Money", "Deposit\nWithdraw\n", "Select", "Close");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_MONEYSAGS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_MONEYSAGSDEPOSIT, DIALOG_STYLE_INPUT, "SAGS Vault Money", "Masukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_MONEYSAGSWITHDRAW, DIALOG_STYLE_INPUT, "SAGS Vault Money", "Masukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				}				
			}
		}
	}
	if(dialogid == DIALOG_MONEYSAGSWITHDRAW)
	{
		if(response)
		{
			new amount = strval(inputtext);
			new lid = 2;
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAGSWITHDRAW, DIALOG_STYLE_INPUT, "SAGS Vault Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			if(amount < 1 || amount > lData[lid][lMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAGSWITHDRAW, DIALOG_STYLE_INPUT, "SAGS Vault Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			lData[lid][lMoney] -= amount;
			GivePlayerMoneyEx(playerid, amount);
			Locker_Save(lid);
	        Locker_Refresh(lid);
			SendFactionMessage(2, -1, "{FFFF00}SAGSLOG: {FFFFFF}%s telah mengambil uang di berangkas sejumlah %s", pData[playerid][pName], FormatMoney(amount));
		}		
	}
	if(dialogid == DIALOG_MONEYSAGSDEPOSIT)
	{
		if(response)
		{
			new amount = strval(inputtext);
			new lid = 2;
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAGSDEPOSIT, DIALOG_STYLE_INPUT, "SAGS Vault Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			if(amount < 1 || amount > pData[playerid][pMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAGSDEPOSIT, DIALOG_STYLE_INPUT, "SAGS Vault Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			lData[lid][lMoney] += amount;
			GivePlayerMoneyEx(playerid, -amount);
			Locker_Save(lid);
	        Locker_Refresh(lid);
			SendFactionMessage(1, -1, "{FFFF00}SAGSLOG: {FFFFFF}%s telah memasukan uang di berangkas sejumlah %s", pData[playerid][pName], FormatMoney(amount));
		}
	}
	if(dialogid == DIALOG_WEAPONSAGS)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0:
				{
					if(PlayerHasWeapon(playerid, 41))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 41, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(41));
				}
				case 1:
				{
					if(PlayerHasWeapon(playerid, 46))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 46, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(46));
				}
				case 2:
				{
					if(PlayerHasWeapon(playerid, 3))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 3, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(3));
				}
				case 3:
				{
					if(PlayerHasWeapon(playerid, 4))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 4, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(4));
				}
				case 4:
				{
					if(PlayerHasWeapon(playerid, 22))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 22, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(22));
				}
				case 5:
				{
					if(pData[playerid][pFactionRank] < 2)
						return Error(playerid, "You are not allowed!");
					
					if(PlayerHasWeapon(playerid, 23))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 23, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(23));
				}
				case 6:
				{
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "You are not allowed!");
						
					if(PlayerHasWeapon(playerid, 24))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 24, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(24));
				}	
				case 7:
				{
					if(pData[playerid][pFactionRank] < 4)
						return Error(playerid, "You are not allowed!");

					if(PlayerHasWeapon(playerid, 29))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 29, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(29));
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_LOCKERSAMD)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0: 
				{
					if(pData[playerid][pOnDuty] == 1)
					{
						pData[playerid][pOnDuty] = 0;
						SetPlayerColor(playerid, COLOR_WHITE);
						SetPlayerSkin(playerid, pData[playerid][pSkin]);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s places their badge and gun in their locker.", ReturnName(playerid));
					}
					else
					{
						pData[playerid][pOnDuty] = 1;
						//SetFactionColor(playerid);
						if(pData[playerid][pGender] == 1)
						{
							SetPlayerSkin(playerid, 276);
							pData[playerid][pFacSkin] = 276;
						}
						else
						{
							SetPlayerSkin(playerid, 308);
							pData[playerid][pFacSkin] = 308;
						}
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s withdraws their badge and on duty from their locker", ReturnName(playerid));
					}
				}
				case 1: 
				{
					SetPlayerHealthEx(playerid, 100);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s telah mengambil medical kit dari locker", ReturnName(playerid));
				}
				case 2:
				{
					Inventory_Add(playerid, "Kevlar", 1242, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s telah mengambil armour pelindung dari locker", ReturnName(playerid));
				}
				case 3:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
					
					ShowPlayerDialog(playerid, DIALOG_WEAPONSAMD, DIALOG_STYLE_LIST, "SAMD Weapons/Items", "TEST DRUG\nFIREEXTINGUISHER\nPARACHUTE\nNITE STICK\nKNIFE", "Pilih", "Batal");
				}
				case 4:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
					switch (pData[playerid][pGender])
					{
						case 1: ShowPlayerSelectionMenu(playerid, SAMD_SKIN_MALE, "Choose Your Skin", SAMDSkinMale, sizeof(SAMDSkinMale));
						case 2: ShowPlayerSelectionMenu(playerid, SAMD_SKIN_FEMALE, "Choose Your Skin", SAMDSkinFemale, sizeof(SAMDSkinFemale));
					}
				}
				case 5:
				{
					if(pData[playerid][pFactionRank] < 5)
						return ErrorMsg(playerid, "Anda tidak memiliki akses untuk menggunakan berangkas uang");

					ShowPlayerDialog(playerid, DIALOG_MONEYSAMD, DIALOG_STYLE_LIST, "SAMD Vault Money", "Deposit\nWithdraw\n", "Select", "Close");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_MONEYSAMD)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_MONEYSAMDDEPOSIT, DIALOG_STYLE_INPUT, "SAMD Vault Money", "Masukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_MONEYSAMDWITHDRAW, DIALOG_STYLE_INPUT, "SAMD Vault Money", "Masukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				}				
			}
		}
	}
	if(dialogid == DIALOG_MONEYSAMDWITHDRAW)
	{
		if(response)
		{
			new amount = strval(inputtext);
			new lid = 1;
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAMDWITHDRAW, DIALOG_STYLE_INPUT, "SAMD Vault Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			if(amount < 1 || amount > lData[lid][lMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAMDWITHDRAW, DIALOG_STYLE_INPUT, "SAMD Vault Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			lData[lid][lMoney] -= amount;
			GivePlayerMoneyEx(playerid, amount);
			Locker_Save(lid);
	        Locker_Refresh(lid);
			SendFactionMessage(2, -1, "{FF69D8}SAMDLOG: {FFFFFF}%s telah mengambil uang di berangkas sejumlah %s", pData[playerid][pName], FormatMoney(amount));
		}		
	}
	if(dialogid == DIALOG_MONEYSAMDDEPOSIT)
	{
		if(response)
		{
			new amount = strval(inputtext);
			new lid = 1;
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAMDDEPOSIT, DIALOG_STYLE_INPUT, "SAMD Vault Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			if(amount < 1 || amount > pData[playerid][pMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSAMDDEPOSIT, DIALOG_STYLE_INPUT, "SAMD Vault Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			lData[lid][lMoney] += amount;
			GivePlayerMoneyEx(playerid, -amount);
			Locker_Save(lid);
	        Locker_Refresh(lid);
			SendFactionMessage(1, -1, "{FF69D8}SAMDLOG: {FFFFFF}%s telah memasukan uang di berangkas sejumlah %s", pData[playerid][pName], FormatMoney(amount));
		}
	}
	if(dialogid == DIALOG_WEAPONSAMD)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0:
				{
					Inventory_Add(playerid, "Test Drug", 1579, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s  open the locker and take the drug test kit.", ReturnName(playerid));
				}
				case 1:
				{
					if(PlayerHasWeapon(playerid, 42))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 42, 200);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(42));
				}
				case 2:
				{
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "Only rank 3-6 for take this");
					
					if(PlayerHasWeapon(playerid, 46))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 46, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(46));
				}
				case 3:
				{
					if(PlayerHasWeapon(playerid, 3))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 3, 34);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(34));
				}
				case 4:
				{
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "Only rank 3-6 for take this");

					if(PlayerHasWeapon(playerid, 4))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 4, 34);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(4));
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_LOCKERSANEW)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0: 
				{
					if(pData[playerid][pOnDuty] == 1)
					{
						pData[playerid][pOnDuty] = 0;
						SetPlayerColor(playerid, COLOR_WHITE);
						SetPlayerSkin(playerid, pData[playerid][pSkin]);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s places their badge and gun in their locker.", ReturnName(playerid));
					}
					else
					{
						pData[playerid][pOnDuty] = 1;
						//SetFactionColor(playerid);
						if(pData[playerid][pGender] == 1)
						{
							SetPlayerSkin(playerid, 189);
							pData[playerid][pFacSkin] = 189;
						}
						else
						{
							SetPlayerSkin(playerid, 150); //194
							pData[playerid][pFacSkin] = 150; //194
						}
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s withdraws their badge and on duty from their locker", ReturnName(playerid));
					}
				}
				case 1: 
				{
					SetPlayerHealthEx(playerid, 100);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s telah mengambil medical kit dari locker", ReturnName(playerid));
				}
				case 2:
				{
					Inventory_Add(playerid, "Kevlar", 1242, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s telah mengambil armour pelindung dari locker", ReturnName(playerid));
				}
				case 3:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
						
					ShowPlayerDialog(playerid, DIALOG_WEAPONSANEW, DIALOG_STYLE_LIST, "SANEW Weapons", "CAMERA\nPARACHUTE\nNITE STICK\nKNIFE", "Pilih", "Batal");
				}
				case 4:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
					switch (pData[playerid][pGender])
					{
						case 1: ShowPlayerSelectionMenu(playerid, SANA_SKIN_MALE, "Choose Your Skin", SANASkinMale, sizeof(SANASkinMale));
						case 2: ShowPlayerSelectionMenu(playerid, SANA_SKIN_FEMALE, "Choose Your Skin", SANASkinFemale, sizeof(SANASkinFemale));
					}
				}
				case 5:
				{
					if(pData[playerid][pFactionRank] < 5)
						return ErrorMsg(playerid, "Anda tidak memiliki akses untuk menggunakan berangkas uang");

					ShowPlayerDialog(playerid, DIALOG_MONEYSANEW, DIALOG_STYLE_LIST, "SANEW Vault Money", "Deposit\nWithdraw\n", "Select", "Close");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_MONEYSANEW)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_MONEYSANEWDEPOSIT, DIALOG_STYLE_INPUT, "SANEW Vault Money", "Masukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_MONEYSANEWWITHDRAW, DIALOG_STYLE_INPUT, "SANEW Vault Money", "Masukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				}				
			}
		}
	}
	if(dialogid == DIALOG_MONEYSANEWWITHDRAW)
	{
		if(response)
		{
			new amount = strval(inputtext);
			new lid = 3;
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSANEWWITHDRAW, DIALOG_STYLE_INPUT, "SANEW Vault Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			if(amount < 1 || amount > lData[lid][lMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSANEWWITHDRAW, DIALOG_STYLE_INPUT, "SANEW Vault Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			lData[lid][lMoney] -= amount;
			GivePlayerMoneyEx(playerid, amount);
			Locker_Save(lid);
	        Locker_Refresh(lid);
			SendFactionMessage(2, -1, "{FFFF00}SANEWLOG: {FFFFFF}%s telah mengambil uang di berangkas sejumlah %s", pData[playerid][pName], FormatMoney(amount));
		}		
	}
	if(dialogid == DIALOG_MONEYSANEWDEPOSIT)
	{
		if(response)
		{
			new amount = strval(inputtext);
			new lid = 3;
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSANEWDEPOSIT, DIALOG_STYLE_INPUT, "SANEW Vault Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			if(amount < 1 || amount > pData[playerid][pMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSANEWDEPOSIT, DIALOG_STYLE_INPUT, "SANEW Vault Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			lData[lid][lMoney] += amount;
			GivePlayerMoneyEx(playerid, -amount);
			Locker_Save(lid);
	        Locker_Refresh(lid);
			SendFactionMessage(1, -1, "{FFFF00}SANEWLOG: {FFFFFF}%s telah memasukan uang di berangkas sejumlah %s", pData[playerid][pName], FormatMoney(amount));
		}
	}
	if(dialogid == DIALOG_WEAPONSANEW)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0:
				{
					if(PlayerHasWeapon(playerid, 43))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 43, 30);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(43));
				}
				case 1:
				{
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "Only rank 3-6 for take this");

					if(PlayerHasWeapon(playerid, 46))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 46, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(46));
				}
				case 2:
				{
					if(PlayerHasWeapon(playerid, 3))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 3, 30);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(3));
				}
				case 3:
				{
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "Only rank 3-6 for take this");

					if(PlayerHasWeapon(playerid, 4))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");
					
					GivePlayerWeaponEx(playerid, 4, 30);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(4));
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_LOCKERSACF)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0: 
				{
					static
						pid;
						
					if(pData[playerid][pOnDuty] == 1)
					{

						pData[playerid][pOnDuty] = 0;
						RefreshMapSacf(playerid);
						Pedagang_Refresh(pid);
						pData[playerid][pOndutysacf] = false;
						SetPlayerColor(playerid, COLOR_WHITE);
						SetPlayerSkin(playerid, pData[playerid][pSkin]);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s places their badge and gun in their locker.", ReturnName(playerid));
					}
					else
					{

						pData[playerid][pOnDuty] = 1;
						RefreshMapSacf(playerid);
						Pedagang_Refresh(pid);
						pData[playerid][pOndutysacf] = true;
						//SetFactionColor(playerid);
						if(pData[playerid][pGender] == 1)
						{
							SetPlayerSkin(playerid, 189);
							pData[playerid][pFacSkin] = 189;
						}
						else
						{
							SetPlayerSkin(playerid, 150); //194
							pData[playerid][pFacSkin] = 150; //194
						}
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s withdraws their badge and on duty from their locker", ReturnName(playerid));
					}
				}
				case 1: 
				{
					SetPlayerHealthEx(playerid, 100);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s telah mengambil medical kit dari locker", ReturnName(playerid));
				}
				case 2:
				{
					Inventory_Add(playerid, "Kevlar", 1242, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s telah mengambil armour pelindung dari locker", ReturnName(playerid));
				}
				case 3:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
						
					ShowPlayerDialog(playerid, DIALOG_WEAPONSANEW, DIALOG_STYLE_LIST, "SACF Weapons", "PARACHUTE\nNITE STICK\nKNIFE", "Pilih", "Batal");
				}
				case 4:
				{
					if(pData[playerid][pOnDuty] <= 0)
						return Error(playerid, "Kamu harus On duty untuk mengambil barang!");
					switch (pData[playerid][pGender])
					{
						case 1: ShowPlayerSelectionMenu(playerid, SACF_SKIN_MALE, "Choose Your Skin", SACFSkinMale, sizeof(SACFSkinMale));
						case 2: ShowPlayerSelectionMenu(playerid, SACF_SKIN_FEMALE, "Choose Your Skin", SACFSkinFemale, sizeof(SACFSkinFemale));
					}
				}
				case 5:
				{
					if(pData[playerid][pFactionRank] < 5)
						return ErrorMsg(playerid, "Anda tidak memiliki akses untuk menggunakan berangkas uang");

					ShowPlayerDialog(playerid, DIALOG_MONEYSACF, DIALOG_STYLE_LIST, "SACF Vault Money", "Deposit\nWithdraw\n", "Select", "Close");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_MONEYSACF)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_MONEYSACFDEPOSIT, DIALOG_STYLE_INPUT, "SACF Vault Money", "Masukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_MONEYSACFWITHDRAW, DIALOG_STYLE_INPUT, "SACF Vault Money", "Masukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				}				
			}
		}
	}
	if(dialogid == DIALOG_MONEYSACFWITHDRAW)
	{
		if(response)
		{
			new amount = strval(inputtext);
			new lid = 4;
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSACFWITHDRAW, DIALOG_STYLE_INPUT, "SACF Vault Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			if(amount < 1 || amount > lData[lid][lMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSACFWITHDRAW, DIALOG_STYLE_INPUT, "SACF Vault Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di ambil\n{FF0000}Gunakanlah dengan bijak!", "Withdraw", "Close");
				return 1;
			}
			lData[lid][lMoney] -= amount;
			GivePlayerMoneyEx(playerid, amount);
			Locker_Save(lid);
	        Locker_Refresh(lid);
			SendFactionMessage(2, -1, "{FFFF00}SACFLOG: {FFFFFF}%s telah mengambil uang di berangkas sejumlah %s", pData[playerid][pName], FormatMoney(amount));
		}		
	}
	if(dialogid == DIALOG_MONEYSACFDEPOSIT)
	{
		if(response)
		{
			new amount = strval(inputtext);
			new lid = 4;
			if(isnull(inputtext))
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSACFDEPOSIT, DIALOG_STYLE_INPUT, "SACF Vault Money", "{FF0000}Uang yang anda input tidak boleh kosong!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			if(amount < 1 || amount > pData[playerid][pMoney])
			{
				ShowPlayerDialog(playerid, DIALOG_MONEYSACFDEPOSIT, DIALOG_STYLE_INPUT, "SACF Vault Money", "{FF0000}Jumlah uang salah atau tidak mencukupi!\nMasukan jumlah uang yang ingin di masukan", "Deposit", "Close");
				return 1;
			}
			lData[lid][lMoney] += amount;
			GivePlayerMoneyEx(playerid, -amount);
			Locker_Save(lid);
	        Locker_Refresh(lid);
			SendFactionMessage(1, -1, "{FFFF00}SACFLOG: {FFFFFF}%s telah memasukan uang di berangkas sejumlah %s", pData[playerid][pName], FormatMoney(amount));
		}
	}
	if(dialogid == DIALOG_WEAPONSACF)
	{
		if(response)
		{
			switch (listitem) 
			{
				case 0:
				{
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "Only rank 3-6 for take this");

					if(PlayerHasWeapon(playerid, 46))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 46, 1);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(46));
				}
				case 1:
				{
					if(PlayerHasWeapon(playerid, 3))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");

					GivePlayerWeaponEx(playerid, 3, 30);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(3));
				}
				case 2:
				{
					if(pData[playerid][pFactionRank] < 3)
						return Error(playerid, "Only rank 3-6 for take this");

					if(PlayerHasWeapon(playerid, 4))
						return Error(playerid, "Kamu sudah memiliki senjata tersebut");
					
					GivePlayerWeaponEx(playerid, 4, 30);
					SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s reaches inside the locker and equips a %s.", ReturnName(playerid), ReturnWeaponName(4));
				}
			}
		}
		return 1;
	}
	//--------[ DIALOG SERVICE WORKSHOP]
	if(dialogid == WORKSHOP_SERVICE)
	{
		new wid = pData[playerid][pWorkshop];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						new Float:health, comp;
						GetVehicleHealth(pData[playerid][pMechVeh], health);
						if(health > 2000.0) health = 2000.0;
						if(health > 1000.0) health = 2000.0;
						if(health > 0.0) health *= -1;
						comp = floatround(health, floatround_round) / 10 + 100;
						if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
						if(Inventory_Count(playerid, "Component") < comp) return Error(playerid, "Component anda kurang!");
						if(comp <= 0) return Error(playerid, "This vehicle can't be fixing.");
						Inventory_Remove(playerid, "Component", comp);
						Info(playerid, "Anda memperbaiki mesin kendaraan dengan "RED_E"%d component.", comp);
						pData[playerid][pMechanic] = SetTimerEx("EngineFix", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Fixing...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						new panels, doors, light, tires, comp;
						
						GetVehicleDamageStatus(pData[playerid][pMechVeh], panels, doors, light, tires);
						new cpanels = panels / 1000000;
						new lights = light / 2;
						new pintu;
						if(doors != 0) pintu = 5;
						if(doors == 0) pintu = 0;
						comp = cpanels + lights + pintu + 20;
						if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
						if(Inventory_Count(playerid, "Component") < comp) return Error(playerid, "Component anda kurang!");
						if(comp <= 0) return Error(playerid, "This vehicle can't be fixing.");
						Inventory_Remove(playerid, "Component", comp);
						Info(playerid, "Anda memperbaiki body kendaraan dengan "RED_E"%d component.", comp);
						
						pData[playerid][pMechanic] = SetTimerEx("BodyFix", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Fixing...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
							if(Inventory_Count(playerid, "Component") < 300) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 300);
							pData[playerid][pMechanic] = SetTimerEx("EngineUpgrade", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Fixing...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");

							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 3:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 12) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_COLOR, DIALOG_STYLE_INPUT, "Color ID 1", "Enter the color id 1:(0 - 255)", "Next", "Close");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 4:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_PAINTJOB, DIALOG_STYLE_INPUT, "Paintjob", "Enter the vehicle paintjob id:(0 - 2 | 3 - Remove paintJob)", "Paintjob", "Close");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 5:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_WHEELS, DIALOG_STYLE_LIST, "Wheels", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\nTrance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 6:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_SPOILER,DIALOG_STYLE_LIST,"Choose below","Wheel Arc. Alien Spoiler\nWheel Arc. X-Flow Spoiler\nTransfender Win Spoiler\nTransfender Fury Spoiler\nTransfender Alpha Spoiler\nTransfender Pro Spoiler\nTransfender Champ Spoiler\nTransfender Race Spoiler\nTransfender Drag Spoiler\n","Choose","back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 7:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_HOODS, DIALOG_STYLE_LIST, "Hoods", "Fury\nChamp\nRace\nWorx\n", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 8:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_VENTS, DIALOG_STYLE_LIST, "Vents", "Oval\nSquare\n", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 9:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_LIGHTS, DIALOG_STYLE_LIST, "Lights", "Round\nSquare\n", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 10:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_EXHAUSTS, DIALOG_STYLE_LIST, "Exhausts", "Wheel Arc. Alien exhaust\nWheel Arc. X-Flow exhaust\nLow Co. Chromer exhaust\nLow Co. Slamin exhaust\nTransfender Large exhaust\nTransfender Medium exhaust\nTransfender Small exhaust\nTransfender Twin exhaust\nTransfender Upswept exhaust", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 11:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_FRONT_BUMPERS, DIALOG_STYLE_LIST, "Front bumpers", "Wheel Arc. Alien Bumper\nWheel Arc. X-Flow Bumper\nLow co. Chromer Bumper\nLow co. Slamin Bumper", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 12:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_REAR_BUMPERS, DIALOG_STYLE_LIST, "Rear bumpers", "Wheel Arc. Alien Bumper\nWheel Arc. X-Flow Bumper\nLow co. Chromer Bumper\nLow co. Slamin Bumper", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 13:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_ROOFS, DIALOG_STYLE_LIST, "Roofs", "Wheel Arc. Alien\nWheel Arc. X-Flow\nLow Co. Hardtop Roof\nLow Co. Softtop Roof\nTransfender Roof Scoop", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 14:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 27) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_SIDE_SKIRTS, DIALOG_STYLE_LIST, "Side skirts", "Wheel Arc. Alien Side Skirt\nWheel Arc. X-Flow Side Skirt\nLocos Chrome Strip\nLocos Chrome Flames\nLocos Chrome Arches \nLocos Chrome Trim\nLocos Wheelcovers\nTransfender Side Skirt", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
					Info(playerid, "Side blm ada.");
				}
				case 15:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 15) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_BULLBARS, DIALOG_STYLE_LIST, "Bull bars", "Locos Chrome Grill\nLocos Chrome Bars\nLocos Chrome Lights \nLocos Chrome Bullbar", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 16:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						pData[playerid][pMechColor1] = 1086;
						pData[playerid][pMechColor2] = 0;
						
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{	
							if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
							if(Inventory_Count(playerid, "Component") < 45) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 45);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"45 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pMechColor1] = 0;
							pData[playerid][pMechColor2] = 0;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 17:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						pData[playerid][pMechColor1] = 1087;
						pData[playerid][pMechColor2] = 0;
						
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{	
							if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
							if(Inventory_Count(playerid, "Component") < 45) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 45);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"45 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pMechColor1] = 0;
							pData[playerid][pMechColor2] = 0;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 18:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
						pData[playerid][pMechColor1] = 1009;
						pData[playerid][pMechColor2] = 0;
						
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{	
							if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
							if(Inventory_Count(playerid, "Component") < 75) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 75);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"75 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pMechColor1] = 0;
							pData[playerid][pMechColor2] = 0;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 19:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
					
						pData[playerid][pMechColor1] = 1008;
						pData[playerid][pMechColor2] = 0;
						
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{	
							if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
							if(Inventory_Count(playerid, "Component") < 112) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 112);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"112 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pMechColor1] = 0;
							pData[playerid][pMechColor2] = 0;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 20:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
						pData[playerid][pMechColor1] = 1010;
						pData[playerid][pMechColor2] = 0;
						
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{	
							if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
							if(Inventory_Count(playerid, "Component") < 150) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 150);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"150 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pMechColor1] = 0;
							pData[playerid][pMechColor2] = 0;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
				case 21:
				{
					if(IsPlayerInRangeOfPoint(playerid, 50.0, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
					{
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 135) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_NEON,DIALOG_STYLE_LIST,"Neon","RED\nBLUE\nGREEN\nYELLOW\nPINK\nWHITE\nREMOVE","Choose","back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "kamu harus berjarak 10 meter dari point workshopmu");
				}
			}
		}
	}
	//--------[ DIALOG JOB ]--------
	if(dialogid == DIALOG_SERVICE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						new Float:health, comp;
						GetVehicleHealth(pData[playerid][pMechVeh], health);
						if(health > 2500.0) health = 2500.0;
						if(health > 0.0) health *= -1;
						comp = floatround(health, floatround_round) / 10 + 100;
						
						if(Inventory_Count(playerid, "Component") < comp) return Error(playerid, "Component anda kurang!");
						if(comp <= 0) return Error(playerid, "This vehicle can't be fixing.");
						Inventory_Remove(playerid, "Component", comp);
						Info(playerid, "Anda memperbaiki mesin kendaraan dengan "RED_E"%d component.", comp);
						pData[playerid][pMechanic] = BarQTE(playerid, "Fixing Engine", "EngineFix");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						new panels, doors, light, tires, comp;
						
						GetVehicleDamageStatus(pData[playerid][pMechVeh], panels, doors, light, tires);
						new cpanels = panels / 1000000;
						new lights = light / 2;
						new pintu;
						if(doors != 0) pintu = 5;
						if(doors == 0) pintu = 0;
						comp = cpanels + lights + pintu + 20;
						
						if(Inventory_Count(playerid, "Component") < comp) return Error(playerid, "Component anda kurang!");
						if(comp <= 0) return Error(playerid, "This vehicle can't be fixing.");
						Inventory_Remove(playerid, "Component", comp);
						Info(playerid, "Anda memperbaiki body kendaraan dengan "RED_E"%d component.", comp);
						
						pData[playerid][pMechanic] = SetTimerEx("BodyFix", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Fixing...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 12) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_COLOR, DIALOG_STYLE_INPUT, "Color ID 1", "Enter the color id 1:(0 - 255)", "Next", "Close");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 3:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_PAINTJOB, DIALOG_STYLE_INPUT, "Paintjob", "Enter the vehicle paintjob id:(0 - 2 | 3 - Remove paintJob)", "Paintjob", "Close");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 4:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_WHEELS, DIALOG_STYLE_LIST, "Wheels", "Offroad\nMega\nWires\nTwist\nGrove\nImport\nAtomic\nAhab\nVirtual\nAccess\nTrance\nShadow\nRimshine\nClassic\nCutter\nSwitch\nDollar", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 5:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_SPOILER,DIALOG_STYLE_LIST,"Choose below","Wheel Arc. Alien Spoiler\nWheel Arc. X-Flow Spoiler\nTransfender Win Spoiler\nTransfender Fury Spoiler\nTransfender Alpha Spoiler\nTransfender Pro Spoiler\nTransfender Champ Spoiler\nTransfender Race Spoiler\nTransfender Drag Spoiler\n","Choose","back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 6:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_HOODS, DIALOG_STYLE_LIST, "Hoods", "Fury\nChamp\nRace\nWorx\n", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 7:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_VENTS, DIALOG_STYLE_LIST, "Vents", "Oval\nSquare\n", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 8:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_LIGHTS, DIALOG_STYLE_LIST, "Lights", "Round\nSquare\n", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 9:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_EXHAUSTS, DIALOG_STYLE_LIST, "Exhausts", "Wheel Arc. Alien exhaust\nWheel Arc. X-Flow exhaust\nLow Co. Chromer exhaust\nLow Co. Slamin exhaust\nTransfender Large exhaust\nTransfender Medium exhaust\nTransfender Small exhaust\nTransfender Twin exhaust\nTransfender Upswept exhaust", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 10:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_FRONT_BUMPERS, DIALOG_STYLE_LIST, "Front bumpers", "Wheel Arc. Alien Bumper\nWheel Arc. X-Flow Bumper\nLow co. Chromer Bumper\nLow co. Slamin Bumper", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 11:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_REAR_BUMPERS, DIALOG_STYLE_LIST, "Rear bumpers", "Wheel Arc. Alien Bumper\nWheel Arc. X-Flow Bumper\nLow co. Chromer Bumper\nLow co. Slamin Bumper", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 12:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_ROOFS, DIALOG_STYLE_LIST, "Roofs", "Wheel Arc. Alien\nWheel Arc. X-Flow\nLow Co. Hardtop Roof\nLow Co. Softtop Roof\nTransfender Roof Scoop", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 13:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 27) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_SIDE_SKIRTS, DIALOG_STYLE_LIST, "Side skirts", "Wheel Arc. Alien Side Skirt\nWheel Arc. X-Flow Side Skirt\nLocos Chrome Strip\nLocos Chrome Flames\nLocos Chrome Arches \nLocos Chrome Trim\nLocos Wheelcovers\nTransfender Side Skirt", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
					Info(playerid, "Side blm ada.");
				}
				case 14:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 15) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_BULLBARS, DIALOG_STYLE_LIST, "Bull bars", "Locos Chrome Grill\nLocos Chrome Bars\nLocos Chrome Lights \nLocos Chrome Bullbar", "Confirm", "back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 15:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						pData[playerid][pMechColor1] = 1086;
						pData[playerid][pMechColor2] = 0;
						if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 45) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 45);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"45 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pMechColor1] = 0;
							pData[playerid][pMechColor2] = 0;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 16:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						pData[playerid][pMechColor1] = 1087;
						pData[playerid][pMechColor2] = 0;
						if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 45) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 45);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"45 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pMechColor1] = 0;
							pData[playerid][pMechColor2] = 0;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 17:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{
						pData[playerid][pMechColor1] = 1009;
						pData[playerid][pMechColor2] = 0;
						if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 75) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 75);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"75 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pMechColor1] = 0;
							pData[playerid][pMechColor2] = 0;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 18:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{

						pData[playerid][pMechColor1] = 1008;
						pData[playerid][pMechColor2] = 0;
						if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 112) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 112);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"112 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pMechColor1] = 0;
							pData[playerid][pMechColor2] = 0;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 19:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{
						pData[playerid][pMechColor1] = 1010;
						pData[playerid][pMechColor2] = 0;
						if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 150) return Error(playerid, "Component anda kurang!");
							Inventory_Remove(playerid, "Component", 150);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"150 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pMechColor1] = 0;
							pData[playerid][pMechColor2] = 0;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
				case 20:
				{
					if(IsPlayerInRangeOfPoint(playerid, 30.0, 213.761688, -228.352401, 1.597931))
					{
						if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
						if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
						{
							if(Inventory_Count(playerid, "Component") < 135) return Error(playerid, "Component anda kurang!");
							ShowPlayerDialog(playerid, DIALOG_SERVICE_NEON,DIALOG_STYLE_LIST,"Neon","RED\nBLUE\nGREEN\nYELLOW\nPINK\nWHITE\nREMOVE","Choose","back");
						}
						else
						{
							KillTimer(pData[playerid][pMechanic]);
							
							
							pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
							pData[playerid][pActivityTime] = 0;
							Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
							return 1;
						}
					}
					else return Error(playerid, "You must in Mechanic Center Area!");
				}
			}
		}
	}
	if(dialogid == DIALOG_SERVICE_COLOR)
	{
		if(response)
		{
			pData[playerid][pMechColor1] = floatround(strval(inputtext));
			
			if(pData[playerid][pMechColor1] < 0 || pData[playerid][pMechColor1] > 255)
				return ShowPlayerDialog(playerid, DIALOG_SERVICE_COLOR, DIALOG_STYLE_INPUT, "Color ID 1", "Enter the color id 1:(0 - 255)", "Next", "Close");
			
			ShowPlayerDialog(playerid, DIALOG_SERVICE_COLOR2, DIALOG_STYLE_INPUT, "Color ID 2", "Enter the color id 2:(0 - 255)", "Next", "Close");
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_COLOR2)
	{
		if(response)
		{
			pData[playerid][pMechColor2] = floatround(strval(inputtext));
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(pData[playerid][pMechColor2] < 0 || pData[playerid][pMechColor2] > 255)
				return ShowPlayerDialog(playerid, DIALOG_SERVICE_COLOR2, DIALOG_STYLE_INPUT, "Color ID 2", "Enter the color id 2:(0 - 255)", "Next", "Close");
			
			if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
			if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
			{	
				if(Inventory_Count(playerid, "Component") < 12) return Error(playerid, "Component anda kurang!");
				Inventory_Remove(playerid, "Component", 12);
				Info(playerid, "Anda mengganti warna kendaraan dengan "RED_E"12 component.");
				
				pData[playerid][pMechanic] = SetTimerEx("SprayCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
				ShowProgressbar(playerid, "Modifying...", 10);
			}
			else
			{
				KillTimer(pData[playerid][pMechanic]);
				
				
				pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
				pData[playerid][pMechColor1] = 0;
				pData[playerid][pMechColor2] = 0;
				pData[playerid][pActivityTime] = 0;
				Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
				return 1;
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_PAINTJOB)
	{
		if(response)
		{
			pData[playerid][pMechColor1] = floatround(strval(inputtext));
			
			if(pData[playerid][pMechColor1] < 0 || pData[playerid][pMechColor1] > 3)
				return ShowPlayerDialog(playerid, DIALOG_SERVICE_PAINTJOB, DIALOG_STYLE_INPUT, "Paintjob", "Enter the vehicle paintjob id:(0 - 2 | 3 - Remove paintJob)", "Paintjob", "Close");
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
			if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
			{	
				if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
				Inventory_Remove(playerid, "Component", 30);
				Info(playerid, "Anda mengganti paintjob kendaraan dengan "RED_E"30 component.");
				pData[playerid][pMechanic] = SetTimerEx("PaintjobCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
				ShowProgressbar(playerid, "Spraying...", 10);
			}
			else
			{
				KillTimer(pData[playerid][pMechanic]);
				
				
				pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
				pData[playerid][pMechColor1] = 0;
				pData[playerid][pMechColor2] = 0;
				pData[playerid][pActivityTime] = 0;
				Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
				return 1;
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_WHEELS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pMechColor1] = 1025;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					pData[playerid][pMechColor1] = 1074;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					pData[playerid][pMechColor1] = 1076;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 3:
				{
					pData[playerid][pMechColor1] = 1078;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 4:
				{
					pData[playerid][pMechColor1] = 1081;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 5:
				{
					pData[playerid][pMechColor1] = 1082;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 6:
				{
					pData[playerid][pMechColor1] = 1085;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 7:
				{
					pData[playerid][pMechColor1] = 1096;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 8:
				{
					pData[playerid][pMechColor1] = 1097;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 9:
				{
					pData[playerid][pMechColor1] = 1098;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 10:
				{
					pData[playerid][pMechColor1] = 1084;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 11:
				{
					pData[playerid][pMechColor1] = 1073;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 12:
				{
					pData[playerid][pMechColor1] = 1075;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 13:
				{
					pData[playerid][pMechColor1] = 1077;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 14:
				{
					pData[playerid][pMechColor1] = 1079;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 15:
				{
					pData[playerid][pMechColor1] = 1080;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 16:
				{
					pData[playerid][pMechColor1] = 1083;
					pData[playerid][pMechColor2] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{	
						if(Inventory_Count(playerid, "Component") < 25) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 25);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"25 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_SPOILER)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 561 ||
						VehicleModel == 558 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1147;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1049;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1162;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1058;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1164;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1138;
								pData[playerid][pMechColor2] = 0;
							}
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 561 ||
						VehicleModel == 558 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1146;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1050;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1158;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1060;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1163;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1139;
								pData[playerid][pMechColor2] = 0;
							}
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 401 ||
						VehicleModel == 518 ||
						VehicleModel == 527 ||
						VehicleModel == 415 ||
						VehicleModel == 546 ||
						VehicleModel == 603 ||
						VehicleModel == 426 ||
						VehicleModel == 436 ||
						VehicleModel == 405 ||
						VehicleModel == 477 ||
						VehicleModel == 580 ||
						VehicleModel == 550 ||
						VehicleModel == 549)
						{
				
							pData[playerid][pMechColor1] = 1001;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 3:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 518 ||
						VehicleModel == 415 ||
						VehicleModel == 546 ||
						VehicleModel == 517 ||
						VehicleModel == 603 ||
						VehicleModel == 405 ||
						VehicleModel == 477 ||
						VehicleModel == 580 ||
						VehicleModel == 550 ||
						VehicleModel == 549)
						{
				
							pData[playerid][pMechColor1] = 1023;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 4:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 518 ||
						VehicleModel == 415 ||
						VehicleModel == 401 ||
						VehicleModel == 517 ||
						VehicleModel == 426 ||
						VehicleModel == 436 ||
						VehicleModel == 477 ||
						VehicleModel == 547 ||
						VehicleModel == 550 ||
						VehicleModel == 549)
						{
				
							pData[playerid][pMechColor1] = 1003;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 5:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 589 ||
						VehicleModel == 492 ||
						VehicleModel == 547 ||
						VehicleModel == 405)
						{
				
							pData[playerid][pMechColor1] = 1000;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 6:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 527 ||
						VehicleModel == 542 ||
						VehicleModel == 405)
						{
				
							pData[playerid][pMechColor1] = 1014;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 7:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 527 ||
						VehicleModel == 542)
						{
				
							pData[playerid][pMechColor1] = 1015;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 8:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 546 ||
						VehicleModel == 517)
						{
				
							pData[playerid][pMechColor1] = 1002;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
	}
	if(dialogid == DIALOG_SERVICE_HOODS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(
						VehicleModel == 401 ||
						VehicleModel == 518 ||
						VehicleModel == 589 ||
						VehicleModel == 492 ||
						VehicleModel == 426 ||
						VehicleModel == 550)
						{
				
							pData[playerid][pMechColor1] = 1005;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(
						VehicleModel == 401 ||
						VehicleModel == 402 ||
						VehicleModel == 546 ||
						VehicleModel == 426 ||
						VehicleModel == 550)
						{
				
							pData[playerid][pMechColor1] = 1004;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 401)
						{
				
							pData[playerid][pMechColor1] = 1011;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 3:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 549)
						{
				
							pData[playerid][pMechColor1] = 1012;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_VENTS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 401 ||
						VehicleModel == 518 ||
						VehicleModel == 546 ||
						VehicleModel == 517 ||
						VehicleModel == 603 ||
						VehicleModel == 547 ||
						VehicleModel == 439 ||
						VehicleModel == 550 ||
						VehicleModel == 549)
						{
				
							pData[playerid][pMechColor1] = 1142;
							pData[playerid][pMechColor2] = 1143;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 401 ||
						VehicleModel == 518 ||
						VehicleModel == 589 ||
						VehicleModel == 546 ||
						VehicleModel == 517 ||
						VehicleModel == 603 ||
						VehicleModel == 439 ||
						VehicleModel == 550 ||
						VehicleModel == 549)
						{
				
							pData[playerid][pMechColor1] = 1144;
							pData[playerid][pMechColor2] = 1145;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
	}
	if(dialogid == DIALOG_SERVICE_LIGHTS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 401 ||
						VehicleModel == 518 ||
						VehicleModel == 589 ||
						VehicleModel == 400 ||
						VehicleModel == 436 ||
						VehicleModel == 439)
						{
				
							pData[playerid][pMechColor1] = 1013;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 589 ||
						VehicleModel == 603 ||
						VehicleModel == 400)
						{
				
							pData[playerid][pMechColor1] = 1024;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_EXHAUSTS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 558 ||
						VehicleModel == 561 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1034;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1046;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1065;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1064;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1028;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1089;
								pData[playerid][pMechColor2] = 0;
							}
							Inventory_Remove(playerid, "Component", 24);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"24 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 558 ||
						VehicleModel == 561 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1037;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1045;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1066;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1059;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1029;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1092;
								pData[playerid][pMechColor2] = 0;
							}
							Inventory_Remove(playerid, "Component", 24);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"24 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 575 ||
						VehicleModel == 534 ||
						VehicleModel == 567 ||
						VehicleModel == 536 ||
						VehicleModel == 576 ||
						VehicleModel == 535)
						{
							if(VehicleModel == 575)
							{
								pData[playerid][pMechColor1] = 1044;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 534)
							{
								pData[playerid][pMechColor1] = 1126;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 567)
							{
								pData[playerid][pMechColor1] = 1129;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 536)
							{
								pData[playerid][pMechColor1] = 1104;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 576)
							{
								pData[playerid][pMechColor1] = 1113;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 535)
							{
								pData[playerid][pMechColor1] = 1136;
								pData[playerid][pMechColor2] = 0;
							}
							Inventory_Remove(playerid, "Component", 24);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"24 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 3:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 575 ||
						VehicleModel == 534 ||
						VehicleModel == 567 ||
						VehicleModel == 536 ||
						VehicleModel == 576 ||
						VehicleModel == 535)
						{
							if(VehicleModel == 575)
							{
								pData[playerid][pMechColor1] = 1043;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 534)
							{
								pData[playerid][pMechColor1] = 1127;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 567)
							{
								pData[playerid][pMechColor1] = 1132;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 536)
							{
								pData[playerid][pMechColor1] = 1105;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 576)
							{
								pData[playerid][pMechColor1] = 1135;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 535)
							{
								pData[playerid][pMechColor1] = 1114;
								pData[playerid][pMechColor2] = 0;
							}
							Inventory_Remove(playerid, "Component", 24);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"24 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 4:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
						if(
						VehicleModel == 401 ||
						VehicleModel == 518 ||
						VehicleModel == 527 ||
						VehicleModel == 542 ||
						VehicleModel == 589 ||
						VehicleModel == 400 ||
						VehicleModel == 517 ||
						VehicleModel == 603 ||
						VehicleModel == 426 ||
						VehicleModel == 547 ||
						VehicleModel == 405 ||
						VehicleModel == 580 ||
						VehicleModel == 550 ||
						VehicleModel == 549 ||
						VehicleModel == 477)
						{
							
							pData[playerid][pMechColor1] = 1020;
							pData[playerid][pMechColor2] = 0;
								
							Inventory_Remove(playerid, "Component", 24);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"24 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 5:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
						if(
						VehicleModel == 527 ||
						VehicleModel == 542 ||
						VehicleModel == 400 ||
						VehicleModel == 426 ||
						VehicleModel == 436 ||
						VehicleModel == 547 ||
						VehicleModel == 405 ||
						VehicleModel == 477)
						{
							
							pData[playerid][pMechColor1] = 1021;
							pData[playerid][pMechColor2] = 0;
								
							Inventory_Remove(playerid, "Component", 24);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"24 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 6:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 436)
						{
							
							pData[playerid][pMechColor1] = 1022;
							pData[playerid][pMechColor2] = 0;
								
							Inventory_Remove(playerid, "Component", 24);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"24 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 7:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
						if(
						VehicleModel == 518 ||
						VehicleModel == 415 ||
						VehicleModel == 542 ||
						VehicleModel == 546 ||
						VehicleModel == 400 ||
						VehicleModel == 517 ||
						VehicleModel == 603 ||
						VehicleModel == 426 ||
						VehicleModel == 436 ||
						VehicleModel == 547 ||
						VehicleModel == 405 ||
						VehicleModel == 550 ||
						VehicleModel == 549 ||
						VehicleModel == 477)
						{
							
							pData[playerid][pMechColor1] = 1019;
							pData[playerid][pMechColor2] = 0;
								
							Inventory_Remove(playerid, "Component", 24);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"24 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 8:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 24) return Error(playerid, "Component anda kurang!");
						if(
						VehicleModel == 401 ||
						VehicleModel == 518 ||
						VehicleModel == 415 ||
						VehicleModel == 542 ||
						VehicleModel == 546 ||
						VehicleModel == 400 ||
						VehicleModel == 517 ||
						VehicleModel == 603 ||
						VehicleModel == 426 ||
						VehicleModel == 415 ||
						VehicleModel == 547 ||
						VehicleModel == 405 ||
						VehicleModel == 550 ||
						VehicleModel == 549 ||
						VehicleModel == 477)
						{
							
							pData[playerid][pMechColor1] = 1018;
							pData[playerid][pMechColor2] = 0;
								
							Inventory_Remove(playerid, "Component", 24);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"24 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_FRONT_BUMPERS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 561 ||
						VehicleModel == 558 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1171;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1153;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1160;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1155;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1166;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1169;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 30);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"30 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 561 ||
						VehicleModel == 558 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1172;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1152;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1173;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1157;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1165;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1170;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 30);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"30 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 575 ||
						VehicleModel == 534 ||
						VehicleModel == 567 ||
						VehicleModel == 536 ||
						VehicleModel == 576 ||
						VehicleModel == 535)
						{
							if(VehicleModel == 575)
							{
								pData[playerid][pMechColor1] = 1174;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 534)
							{
								pData[playerid][pMechColor1] = 1179;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 567)
							{
								pData[playerid][pMechColor1] = 1189;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 536)
							{
								pData[playerid][pMechColor1] = 1182;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 576)
							{
								pData[playerid][pMechColor1] = 1191;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 535)
							{
								pData[playerid][pMechColor1] = 1115;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 30);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"30 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 3:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 575 ||
						VehicleModel == 534 ||
						VehicleModel == 567 ||
						VehicleModel == 536 ||
						VehicleModel == 576 ||
						VehicleModel == 535)
						{
							if(VehicleModel == 575)
							{
								pData[playerid][pMechColor1] = 1175;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 534)
							{
								pData[playerid][pMechColor1] = 1185;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 567)
							{
								pData[playerid][pMechColor1] = 1188;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 536)
							{
								pData[playerid][pMechColor1] = 1181;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 576)
							{
								pData[playerid][pMechColor1] = 1190;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 535)
							{
								pData[playerid][pMechColor1] = 1116;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 30);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"30 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_REAR_BUMPERS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 561 ||
						VehicleModel == 558 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1149;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1150;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1159;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1154;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1168;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1141;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 30);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"30 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 561 ||
						VehicleModel == 558 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1148;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1151;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1161;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1156;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1167;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1140;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 30);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"30 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 575 ||
						VehicleModel == 534 ||
						VehicleModel == 567 ||
						VehicleModel == 536 ||
						VehicleModel == 576 ||
						VehicleModel == 535)
						{
							if(VehicleModel == 575)
							{
								pData[playerid][pMechColor1] = 1176;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 534)
							{
								pData[playerid][pMechColor1] = 1180;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 567)
							{
								pData[playerid][pMechColor1] = 1187;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 536)
							{
								pData[playerid][pMechColor1] = 1184;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 576)
							{
								pData[playerid][pMechColor1] = 1192;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 535)
							{
								pData[playerid][pMechColor1] = 1109;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 30);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"30 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 3:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 30) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 575 ||
						VehicleModel == 534 ||
						VehicleModel == 567 ||
						VehicleModel == 536 ||
						VehicleModel == 576 ||
						VehicleModel == 535)
						{
							if(VehicleModel == 575)
							{
								pData[playerid][pMechColor1] = 1177;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 534)
							{
								pData[playerid][pMechColor1] = 1178;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 567)
							{
								pData[playerid][pMechColor1] = 1186;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 536)
							{
								pData[playerid][pMechColor1] = 1183;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 576)
							{
								pData[playerid][pMechColor1] = 1193;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 535)
							{
								pData[playerid][pMechColor1] = 1110;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 30);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"30 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_ROOFS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 561 ||
						VehicleModel == 558 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1038;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1054;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1067;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1055;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1088;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1032;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 561 ||
						VehicleModel == 558 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1038;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1053;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1068;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1061;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1091;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1033;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 567 ||
						VehicleModel == 536)
						{
							if(VehicleModel == 567)
							{
								pData[playerid][pMechColor1] = 1130;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 536)
							{
								pData[playerid][pMechColor1] = 1128;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 3:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 567 ||
						VehicleModel == 536)
						{
							if(VehicleModel == 567)
							{
								pData[playerid][pMechColor1] = 1131;
								pData[playerid][pMechColor2] = 0;
							}
							if(VehicleModel == 536)
							{
								pData[playerid][pMechColor1] = 1103;
								pData[playerid][pMechColor2] = 0;
							}
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 4:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 21) return Error(playerid, "Component anda kurang!");
						if(
						VehicleModel == 401 ||
						VehicleModel == 518 ||
						VehicleModel == 589 ||
						VehicleModel == 492 ||
						VehicleModel == 546 ||
						VehicleModel == 603 ||
						VehicleModel == 426 ||
						VehicleModel == 436 ||
						VehicleModel == 580 ||
						VehicleModel == 550 ||
						VehicleModel == 477)
						{

							pData[playerid][pMechColor1] = 1006;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 21);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"21 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_SIDE_SKIRTS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 27) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 561 ||
						VehicleModel == 558 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1036;
								pData[playerid][pMechColor2] = 1040;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1047;
								pData[playerid][pMechColor2] = 1051;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1069;
								pData[playerid][pMechColor2] = 1071;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1056;
								pData[playerid][pMechColor2] = 1062;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1090;
								pData[playerid][pMechColor2] = 1094;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1026;
								pData[playerid][pMechColor2] = 1027;
							}
							
							Inventory_Remove(playerid, "Component", 27);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"27 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 27) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 562 ||
						VehicleModel == 565 ||
						VehicleModel == 559 ||
						VehicleModel == 561 ||
						VehicleModel == 558 ||
						VehicleModel == 560)
						{
							if(VehicleModel == 562)
							{
								pData[playerid][pMechColor1] = 1039;
								pData[playerid][pMechColor2] = 1041;
							}
							if(VehicleModel == 565)
							{
								pData[playerid][pMechColor1] = 1048;
								pData[playerid][pMechColor2] = 1052;
							}
							if(VehicleModel == 559)
							{
								pData[playerid][pMechColor1] = 1070;
								pData[playerid][pMechColor2] = 1072;
							}
							if(VehicleModel == 561)
							{
								pData[playerid][pMechColor1] = 1057;
								pData[playerid][pMechColor2] = 1063;
							}
							if(VehicleModel == 558)
							{
								pData[playerid][pMechColor1] = 1093;
								pData[playerid][pMechColor2] = 1095;
							}
							if(VehicleModel == 560)
							{
								pData[playerid][pMechColor1] = 1031;
								pData[playerid][pMechColor2] = 1030;
							}
							
							Inventory_Remove(playerid, "Component", 27);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"27 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 27) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 575 ||
						VehicleModel == 536 ||
						VehicleModel == 576 ||
						VehicleModel == 567)
						{
							if(VehicleModel == 575)
							{
								pData[playerid][pMechColor1] = 1042;
								pData[playerid][pMechColor2] = 1099;
							}
							if(VehicleModel == 536)
							{
								pData[playerid][pMechColor1] = 1108;
								pData[playerid][pMechColor2] = 1107;
							}
							if(VehicleModel == 576)
							{
								pData[playerid][pMechColor1] = 1134;
								pData[playerid][pMechColor2] = 1137;
							}
							if(VehicleModel == 567)
							{
								pData[playerid][pMechColor1] = 1102;
								pData[playerid][pMechColor2] = 1133;
							}
							
							Inventory_Remove(playerid, "Component", 27);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"27 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 3:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 27) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 534)
						{
				
							pData[playerid][pMechColor1] = 1102;
							pData[playerid][pMechColor2] = 1101;
							
							Inventory_Remove(playerid, "Component", 27);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"27 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 4:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 27) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 534)
						{
				
							pData[playerid][pMechColor1] = 1106;
							pData[playerid][pMechColor2] = 1124;
							
							Inventory_Remove(playerid, "Component", 27);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"27 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 5:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 27) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 535)
						{
				
							pData[playerid][pMechColor1] = 1118;
							pData[playerid][pMechColor2] = 1120;
							
							Inventory_Remove(playerid, "Component", 27);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"27 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 6:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 27) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 535)
						{
				
							pData[playerid][pMechColor1] = 1119;
							pData[playerid][pMechColor2] = 1121;
							
							Inventory_Remove(playerid, "Component", 27);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"27 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 7:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 27) return Error(playerid, "Component anda kurang!");
						if(
						VehicleModel == 401 ||
						VehicleModel == 518 ||
						VehicleModel == 527 ||
						VehicleModel == 415 ||
						VehicleModel == 589 ||
						VehicleModel == 546 ||
						VehicleModel == 517 ||
						VehicleModel == 603 ||
						VehicleModel == 436 ||
						VehicleModel == 439 ||
						VehicleModel == 580 ||
						VehicleModel == 549 ||
						VehicleModel == 477)
						{
				
							pData[playerid][pMechColor1] = 1007;
							pData[playerid][pMechColor2] = 1017;
							
							Inventory_Remove(playerid, "Component", 27);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"27 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_BULLBARS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 15) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 534)
						{
				
							pData[playerid][pMechColor1] = 1100;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 15);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"15 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 15) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 534)
						{
				
							pData[playerid][pMechColor1] = 1123;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 15);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"15 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 15) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 534)
						{
				
							pData[playerid][pMechColor1] = 1125;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 15);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"15 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 3:
				{
					new VehicleModel = GetVehicleModel(pData[playerid][pMechVeh]);
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 15) return Error(playerid, "Component anda kurang!");
						if(VehicleModel == 534)
						{
				
							pData[playerid][pMechColor1] = 1117;
							pData[playerid][pMechColor2] = 0;
							
							Inventory_Remove(playerid, "Component", 15);
							Info(playerid, "Anda memodif kendaraan dengan "RED_E"15 component.");
							
							pData[playerid][pMechanic] = SetTimerEx("ModifCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
							ShowProgressbar(playerid, "Modifying...", 10);
						}
						else return Error(playerid, "This vehicle is not supported!");
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SERVICE_NEON)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pMechColor1] = RED_NEON;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 135) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 135);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"135 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("NeonCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 1:
				{
					pData[playerid][pMechColor1] = BLUE_NEON;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 135) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 135);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"135 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("NeonCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 2:
				{
					pData[playerid][pMechColor1] = GREEN_NEON;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 135) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 135);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"135 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("NeonCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 3:
				{
					pData[playerid][pMechColor1] = YELLOW_NEON;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 135) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 135);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"135 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("NeonCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 4:
				{
					pData[playerid][pMechColor1] = PINK_NEON;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 135) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 135);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"135 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("NeonCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 5:
				{
					pData[playerid][pMechColor1] = WHITE_NEON;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 135) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 135);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"135 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("NeonCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
				case 6:
				{
					pData[playerid][pMechColor1] = 0;
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
					if(GetNearestVehicleToPlayer(playerid, 3.8, false) == pData[playerid][pMechVeh])
					{
						if(Inventory_Count(playerid, "Component") < 135) return Error(playerid, "Component anda kurang!");
						Inventory_Remove(playerid, "Component", 135);
						Info(playerid, "Anda memodif kendaraan dengan "RED_E"135 component.");
						
						pData[playerid][pMechanic] = SetTimerEx("NeonCar", 10000, false, "id", playerid, pData[playerid][pMechVeh]);
						ShowProgressbar(playerid, "Modifying...", 10);
					}
					else
					{
						KillTimer(pData[playerid][pMechanic]);
						
						pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
						pData[playerid][pMechColor1] = 0;
						pData[playerid][pMechColor2] = 0;
						pData[playerid][pActivityTime] = 0;
						Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_PLANT)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pSeed] < 5) return Error(playerid, "Not enough seed!");
					new pid = GetNearPlant(playerid);
					if(pid != -1) return Error(playerid, "You too closes with other plant!");

					new id = Iter_Free(Plants);
					if(id == -1) return Error(playerid, "Cant plant any more plant!");

					//if(pData[playerid][pPlantTime] > 0) return Error(playerid, "You must wait 10 minutes for plant again!");

					if(IsPlayerInRangeOfPoint(playerid, 100.0, -263.49, -1508.27, 5.66) || IsPlayerInRangeOfPoint(playerid, 100.0, -424.36, -1330.72, 27.46)
					|| IsPlayerInRangeOfPoint(playerid, 100.0, -243.84, -1366.69, 9.95) || IsPlayerInRangeOfPoint(playerid, 100.0, -563.65, -1344.91, 22.39))
					{

						pData[playerid][pSeed] -= 5;
						new Float:x, Float:y, Float:z, query[512];
						GetPlayerPos(playerid, x, y, z);

						PlantData[id][PlantType] = 1;
						PlantData[id][PlantTime] = 600;
						PlantData[id][PlantX] = x;
						PlantData[id][PlantY] = y;
						PlantData[id][PlantZ] = z;
						PlantData[id][PlantHarvest] = false;
						PlantData[id][PlantTimer] = SetTimerEx("PlantGrowup", 1000, true, "i", id);
						Plant_Refresh(id);
						Iter_Add(Plants, id);
						mysql_format(g_SQL, query, sizeof(query), "INSERT INTO plants SET id='%d', type='%d', time='%d', posx='%f', posy='%f', posz='%f'", id, PlantData[id][PlantType], PlantData[id][PlantTime], x, y, z);
						mysql_tquery(g_SQL, query, "OnPlantCreated", "di", playerid, id);
						pData[playerid][pPlant]++;
						Info(playerid, "Planting Potato.");
						Info(playerid, "Waktu tanam 10 menit");
					}
					else return Error(playerid, "You must in farmer area!");
				}
				case 1:
				{
					if(pData[playerid][pSeed] < 18) return Error(playerid, "Not enough seed!");
					new pid = GetNearPlant(playerid);
					if(pid != -1) return Error(playerid, "You too closes with other plant!");

					new id = Iter_Free(Plants);
					if(id == -1) return Error(playerid, "Cant plant any more plant!");

					//if(pData[playerid][pPlantTime] > 0) return Error(playerid, "You must wait 10 minutes for plant again!");

					if(IsPlayerInRangeOfPoint(playerid, 100.0, -263.49, -1508.27, 5.66) || IsPlayerInRangeOfPoint(playerid, 100.0, -424.36, -1330.72, 27.46)
					|| IsPlayerInRangeOfPoint(playerid, 100.0, -243.84, -1366.69, 9.95) || IsPlayerInRangeOfPoint(playerid, 100.0, -563.65, -1344.91, 22.39))
					{

						pData[playerid][pSeed] -= 18;
						new Float:x, Float:y, Float:z, query[512];
						GetPlayerPos(playerid, x, y, z);

						PlantData[id][PlantType] = 2;
						PlantData[id][PlantTime] = 600;
						PlantData[id][PlantX] = x;
						PlantData[id][PlantY] = y;
						PlantData[id][PlantZ] = z;
						PlantData[id][PlantHarvest] = false;
						PlantData[id][PlantTimer] = SetTimerEx("PlantGrowup", 1000, true, "i", id);
						Plant_Refresh(id);
						Iter_Add(Plants, id);
						mysql_format(g_SQL, query, sizeof(query), "INSERT INTO plants SET id='%d', type='%d', time='%d', posx='%f', posy='%f', posz='%f'", id, PlantData[id][PlantType], PlantData[id][PlantTime], x, y, z);
						mysql_tquery(g_SQL, query, "OnPlantCreated", "di", playerid, id);
						pData[playerid][pPlant]++;
						Info(playerid, "Planting Wheat.");
						Info(playerid, "Waktu tanam 10 menit");
					}
					else return Error(playerid, "You must in farmer area!");
				}
				case 2:
				{
					if(pData[playerid][pSeed] < 11) return Error(playerid, "Not enough seed!");
					new pid = GetNearPlant(playerid);
					if(pid != -1) return Error(playerid, "You too closes with other plant!");

					new id = Iter_Free(Plants);
					if(id == -1) return Error(playerid, "Cant plant any more plant!");

					//if(pData[playerid][pPlantTime] > 0) return Error(playerid, "You must wait 10 minutes for plant again!");

					if(IsPlayerInRangeOfPoint(playerid, 100.0, -263.49, -1508.27, 5.66) || IsPlayerInRangeOfPoint(playerid, 100.0, -424.36, -1330.72, 27.46)
					|| IsPlayerInRangeOfPoint(playerid, 100.0, -243.84, -1366.69, 9.95) || IsPlayerInRangeOfPoint(playerid, 100.0, -563.65, -1344.91, 22.39))
					{

						pData[playerid][pSeed] -= 11;
						new Float:x, Float:y, Float:z, query[512];
						GetPlayerPos(playerid, x, y, z);

						PlantData[id][PlantType] = 3;
						PlantData[id][PlantTime] = 600;
						PlantData[id][PlantX] = x;
						PlantData[id][PlantY] = y;
						PlantData[id][PlantZ] = z;
						PlantData[id][PlantHarvest] = false;
						PlantData[id][PlantTimer] = SetTimerEx("PlantGrowup", 1000, true, "i", id);
						Plant_Refresh(id);
						Iter_Add(Plants, id);
						mysql_format(g_SQL, query, sizeof(query), "INSERT INTO plants SET id='%d', type='%d', time='%d', posx='%f', posy='%f', posz='%f'", id, PlantData[id][PlantType], PlantData[id][PlantTime], x, y, z);
						mysql_tquery(g_SQL, query, "OnPlantCreated", "di", playerid, id);
						pData[playerid][pPlant]++;
						Info(playerid, "Planting Orange.");
						Info(playerid, "Waktu tanam 10 menit");
					}
					else return Error(playerid, "You must in farmer area!");
				}
				case 3:
				{
					if(pData[playerid][pSeed] < 25) return Error(playerid, "Not enough seed!");
					new pid = GetNearPlant(playerid);
					if(pid != -1) return Error(playerid, "You too closes with other plant!");

					new id = Iter_Free(Plants);
					if(id == -1) return Error(playerid, "Cant plant any more plant!");

					//if(pData[playerid][pPlantTime] > 0) return Error(playerid, "You must wait 10 minutes for plant again!");

					if(IsPlayerInRangeOfPoint(playerid, 100.0, -263.49, -1508.27, 5.66) || IsPlayerInRangeOfPoint(playerid, 100.0, -424.36, -1330.72, 27.46)
					|| IsPlayerInRangeOfPoint(playerid, 100.0, -243.84, -1366.69, 9.95) || IsPlayerInRangeOfPoint(playerid, 100.0, -563.65, -1344.91, 22.39))
					{

						pData[playerid][pSeed] -= 25;
						new Float:x, Float:y, Float:z, query[512];
						GetPlayerPos(playerid, x, y, z);

						PlantData[id][PlantType] = 4;
						PlantData[id][PlantTime] = 1200;
						PlantData[id][PlantX] = x;
						PlantData[id][PlantY] = y;
						PlantData[id][PlantZ] = z;
						PlantData[id][PlantHarvest] = false;
						PlantData[id][PlantTimer] = SetTimerEx("PlantGrowup", 1000, true, "i", id);
						Plant_Refresh(id);
						Iter_Add(Plants, id);
						mysql_format(g_SQL, query, sizeof(query), "INSERT INTO plants SET id='%d', type='%d', time='%d', posx='%f', posy='%f', posz='%f'", id, PlantData[id][PlantType], PlantData[id][PlantTime], x, y, z);
						mysql_tquery(g_SQL, query, "OnPlantCreated", "di", playerid, id);
						pData[playerid][pPlant]++;
						Info(playerid, "Planting {FF0000}Kanabis");
						Info(playerid, "Waktu tanam 20 menit");
					}
					else return Error(playerid, "You must in farmer area!");
				}
			}
		}
	}
	if(dialogid == PFARM_PLANT)
	{
		if(response)
		{
			foreach(new pfid : PFarm)
			{
				switch(listitem)
				{
					case 0:
					{
						if(pData[playerid][pSeed] < 5)
							return Error(playerid, "Not enough seed!");
						
						if(!Iter_Contains(PFarm, pfid))
							return Error(playerid, "Invalid ID.");

						new pid = GetNearPlant(playerid);
						if(pid != -1)
							return Error(playerid, "You too closes with other plant!");

						new id = Iter_Free(Plants);
						if(id == -1)
							return Error(playerid, "Cant plant any more plant!");

						pData[playerid][pSeed] -= 5;
						new Float:x, Float:y, Float:z, query[512];
						GetPlayerPos(playerid, x, y, z);

						PlantData[id][PlantType] = 1;
						PlantData[id][PlantTime] = 600;
						PlantData[id][PlantX] = x;
						PlantData[id][PlantY] = y;
						PlantData[id][PlantZ] = z;
						PlantData[id][PlantHarvest] = false;
						PlantData[id][PlantTimer] = SetTimerEx("PlantGrowup", 1000, true, "i", id);
						Iter_Add(Plants, id);
						mysql_format(g_SQL, query, sizeof(query), "INSERT INTO plants SET id='%d', type='%d', time='%d', posx='%f', posy='%f', posz='%f'", id, PlantData[id][PlantType], PlantData[id][PlantTime], x, y, z);
						mysql_tquery(g_SQL, query, "OnPlantCreated", "di", playerid, id);
						pData[playerid][pPlant]++;
						Info(playerid, "Planting Potato.");
					}
					case 1:
					{
						if(pData[playerid][pSeed] < 18)
							return Error(playerid, "Not enough seed!");

						if(!Iter_Contains(PFarm, pfid))
							return Error(playerid, "Invalid ID.");

						new pid = GetNearPlant(playerid);
						if(pid != -1)
							return Error(playerid, "You too closes with other plant!");

						new id = Iter_Free(Plants);
						if(id == -1)
							return Error(playerid, "Cant plant any more plant!");

						pData[playerid][pSeed] -= 18;
						new Float:x, Float:y, Float:z, query[512];
						GetPlayerPos(playerid, x, y, z);

						PlantData[id][PlantType] = 2;
						PlantData[id][PlantTime] = 600;
						PlantData[id][PlantX] = x;
						PlantData[id][PlantY] = y;
						PlantData[id][PlantZ] = z;
						PlantData[id][PlantHarvest] = false;
						PlantData[id][PlantTimer] = SetTimerEx("PlantGrowup", 1000, true, "i", id);
						Iter_Add(Plants, id);
						mysql_format(g_SQL, query, sizeof(query), "INSERT INTO plants SET id='%d', type='%d', time='%d', posx='%f', posy='%f', posz='%f'", id, PlantData[id][PlantType], PlantData[id][PlantTime], x, y, z);
						mysql_tquery(g_SQL, query, "OnPlantCreated", "di", playerid, id);
						pData[playerid][pPlant]++;
						Info(playerid, "Planting Wheat.");
						Info(playerid, "Waktu Planting : 10 Minutes");
					}
					case 2:
					{
						if(pData[playerid][pSeed] < 11)
							return Error(playerid, "Not enough seed!");

						if(!Iter_Contains(PFarm, pfid))
							return Error(playerid, "Invalid ID.");

						new pid = GetNearPlant(playerid);
						if(pid != -1)
							return Error(playerid, "You too closes with other plant!");

						new id = Iter_Free(Plants);
						if(id == -1)
							return Error(playerid, "Cant plant any more plant!");

						pData[playerid][pSeed] -= 11;
						new Float:x, Float:y, Float:z, query[512];
						GetPlayerPos(playerid, x, y, z);

						PlantData[id][PlantType] = 3;
						PlantData[id][PlantTime] = 600;
						PlantData[id][PlantX] = x;
						PlantData[id][PlantY] = y;
						PlantData[id][PlantZ] = z;
						PlantData[id][PlantHarvest] = false;
						PlantData[id][PlantTimer] = SetTimerEx("PlantGrowup", 1000, true, "i", id);
						Iter_Add(Plants, id);
						mysql_format(g_SQL, query, sizeof(query), "INSERT INTO plants SET id='%d', type='%d', time='%d', posx='%f', posy='%f', posz='%f'", id, PlantData[id][PlantType], PlantData[id][PlantTime], x, y, z);
						mysql_tquery(g_SQL, query, "OnPlantCreated", "di", playerid, id);
						pData[playerid][pPlant]++;
						Info(playerid, "Planting Orange.");
						Info(playerid, "Waktu Planting : 10 Minutes");
					}
					case 3:
					{
						if(pData[playerid][pSeed] < 50)
							return Error(playerid, "Not enough seed!");

						if(!Iter_Contains(PFarm, pfid))
							return Error(playerid, "Invalid ID.");

						new pid = GetNearPlant(playerid);
						if(pid != -1)
							return Error(playerid, "You too closes with other plant!");

						new id = Iter_Free(Plants);
						if(id == -1)
							return Error(playerid, "Cant plant any more plant!");

						pData[playerid][pSeed] -= 50;
						new Float:x, Float:y, Float:z, query[512];
						GetPlayerPos(playerid, x, y, z);

						PlantData[id][PlantType] = 4;
						PlantData[id][PlantTime] = 1200;
						PlantData[id][PlantX] = x;
						PlantData[id][PlantY] = y;
						PlantData[id][PlantZ] = z;
						PlantData[id][PlantHarvest] = false;
						PlantData[id][PlantTimer] = SetTimerEx("PlantGrowup", 1000, true, "i", id);
						Iter_Add(Plants, id);
						mysql_format(g_SQL, query, sizeof(query), "INSERT INTO plants SET id='%d', type='%d', time='%d', posx='%f', posy='%f', posz='%f'", id, PlantData[id][PlantType], PlantData[id][PlantTime], x, y, z);
						mysql_tquery(g_SQL, query, "OnPlantCreated", "di", playerid, id);
						pData[playerid][pPlant]++;
						Info(playerid, "Planting {FFFF00}Marijuana.");
						Info(playerid, "Waktu Planting : 20 Minutes");
					}
				}
			}
		}
	}
	if(dialogid == HAULING_DELIVERY)
	{
		if(HaulingType[playerid] != 0)
			return Error(playerid, "Kamu memiliki tugas pengantaran yang belum diselesaikan (/stophauling jika ingin membatalkan pengantaran)");

		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					VehHauling[playerid] = AddStaticVehicle(584, 2781.00, -2493.73, 13.75+0.2, 89.88, -1, -1);
					vCore[VehHauling[playerid]][vFuel] = 100;
					HaulingType[playerid] = 1;
					SetPlayerCheckpoint(playerid, 2781.00, -2493.73, 13.75, 15.0); //TAKE PETROL
					Info(playerid, "Ikuti checkpoint untuk mengambil trailer yang akan kamu antar menuju gas station");
				}
				case 1:
				{
					if(GetDealerRestock() <= 0)
						return Error(playerid, "Mission dealer sedang kosong.");

					new id, count = GetDealerRestock(), mission[2024], lstr[3024], type[1024];

					strcat(mission,"NO\tNAMES\tTYPE\tLOCATION\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnRestockDealerID(itt);
						if(drData[id][dType] == 1)
						{
							type = "Bikes Vehicles";
						}
						else if(drData[id][dType] == 2)
						{
							type = "Cars";
						}
						else if(drData[id][dType] == 3)
						{
							type = "Unique Cars";
						}
						else if(drData[id][dType] == 4)
						{
							type = "Jobs Vehicles";
						}
						else if(drData[id][dType] == 5)
						{
							type = "Rental Jobs";
						}
						else
						{
							type = "{FF0000}Unknown{FFFFFF}";
						}
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", itt, drData[id][dName], type, GetLocation(drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", itt, drData[id][dName], type, GetLocation(drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]));
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, DIALOG_RESTOCK_DEALER, DIALOG_STYLE_TABLIST_HEADERS,"Dealer Restock",mission,"Start","Cancel");
				}
			}
		}
	}
	if(dialogid == DIALOG_RESTOCK_DEALER)
	{
		if(HaulingType[playerid] != 0)
			return Error(playerid, "Kamu memiliki tugas pengantaran yang belum diselesaikan (/stophauling jika ingin membatalkan pengantaran)");

		if(response)
		{
			new id = ReturnRestockDealerID((listitem + 1)), vehicleid = GetPlayerVehicleID(playerid);
			
			if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER && !IsAHaulingVeh(vehicleid)) 
				return Error(playerid, "Kendaraan ini tidak support untuk melakukan hauling");

			VehHauling[playerid] = AddStaticVehicle(591, 2781.44, -2455.97, 13.73+0.2, 89.67, -1, -1);
			vCore[VehHauling[playerid]][vFuel] = 100;
			HaulingType[playerid] = 2;
			pData[playerid][pGetDEIDHAULING] = id;
			DisablePlayerCheckpoint(playerid);
			SetPlayerCheckpoint(playerid, 2781.44, -2455.97, 13.73, 15.0); //TAKE DEALER
			Info(playerid, "Ikuti checkpoint untuk mengambil trailer yang akan kamu antar menuju dealer");
		}
	}
	if(dialogid == DIALOG_LOADBOX)
	{
		if(response)
		{
			if(GetRestockVending() <= 0)
				return Error(playerid, "Belum ada yang merequest restock vending machine.");

			new id, count = GetRestockVending(), mission[2024], lstr[3024];
					
			strcat(mission,"NO\tLOCATION\tOWNER\n",sizeof(mission));
			Loop(itt, (count + 1), 1)
			{
				id = ReturnRestockVendingID(itt);
				if(itt == count)
				{
					format(lstr,sizeof(lstr), "%d\t%s\t%s\n", itt, GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), vmData[id][venOwner]);
				}
				else format(lstr,sizeof(lstr), "%d\t%s\t%s\n", itt, GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), vmData[id][venOwner]);	
				strcat(mission,lstr,sizeof(mission));
			}
			ShowPlayerDialog(playerid, DIALOG_RESTOCK1, DIALOG_STYLE_TABLIST_HEADERS,"Vending Restock",mission,"Start","Cancel");
		}
		return 1;
	}
	if(dialogid == DIALOG_RESTOCK1)
	{
		if(response)
		{
			new id = ReturnRestockVendingID((listitem + 1)), vehicleid = GetPlayerVehicleID(playerid), caridx= -1;
			
			if(pData[playerid][pMissionVen] > -1)
				return Error(playerid, "Kamu sedang melakukan mission, selesaikan terlebih dahulu!");
				
			pData[playerid][pMissionVen] = id;
			pData[playerid][pDistanceMission] = GetPlayerDistanceFromPoint(playerid, vmData[id][venX], vmData[id][venY], vmData[id][venZ]);

			VehProduct[vehicleid] += 15;
			if ((caridx = Vehicle_Nearest2(playerid)) != -1)
			{
				// Perform some actions with the carid if needed
				pvData[caridx][cProduct] += 15;
			}
			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerRaceCheckpoint(playerid, 1, vmData[id][venX], vmData[id][venY], vmData[id][venZ], 0.0, 0.0, 0.0, 7.0);
			Info(playerid, "Kamu akan mengantar menuju vending machine yang berlokasi di %s berjarak %0.0fm", GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), GetPlayerDistanceFromPoint(playerid, vmData[id][venX], vmData[id][venY], vmData[id][venZ]));
		}
		return 1;
	}
	if(dialogid == DIALOG_MATERIAL)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			new total = Inventory_Count(playerid, "Material") + amount;
			new value = amount * MaterialPrice;
			if(amount < 0 || amount > 1000) return ErrorMsg(playerid, "Amount maximal 0 - 1000.");
			if(total > 1000) return ErrorMsg(playerid, "Material terlalu penuh di Inventory! Maximal 1000.");
			if(pData[playerid][pMoney] < value) return ErrorMsg(playerid, "Uang anda kurang.");
			if(Material < amount) return ErrorMsg(playerid, "Material stock tidak mencukupi.");
			GivePlayerMoneyEx(playerid, -value);
			Inventory_Add(playerid, "Material", 17051, amount);
			Material -= amount;
			Server_AddMoney(value);
			Info(playerid, "Anda berhasil membeli "GREEN_E"%d "WHITE_E"material seharga "RED_E"%s.", amount, FormatMoney(value));
		}
	}
	if(dialogid == DIALOG_COMPONENT)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			new total = Inventory_Count(playerid, "Component") + amount;
			new value = amount * ComponentPrice;
			if(amount < 0 || amount > 1000) return ErrorMsg(playerid, "Amount maximal 0 - 1000");
			if(total > 1000) return ErrorMsg(playerid, "Component terlalu penuh di Inventory! Maximal 1000");
			if(pData[playerid][pMoney] < value) return ErrorMsg(playerid, "Uang anda kurang.");
			if(Component < amount) return ErrorMsg(playerid, "Component stock tidak mencukupi.");
			GivePlayerMoneyEx(playerid, -value);
			Inventory_Add(playerid, "Component", 19627, amount);
			Component -= amount;
			Server_AddMoney(value);
			Info(playerid, "Anda berhasil membeli "GREEN_E"%d "WHITE_E"component seharga "RED_E"%s.", amount, FormatMoney(value));
		}
	}
	if(dialogid == DIALOG_DAGING)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			new total = Inventory_HasItem(playerid, "Daging") + amount;
			new value = amount * DagingPrice;
			if(amount < 0 || amount > 500) return Error(playerid, "amount maximal 0 - 500.");
			if(total > 500) return Error(playerid, "Daging terlalu penuh di Inventory! Maximal 500.");
			if(pData[playerid][pMoney] < value) return Error(playerid, "Uang anda kurang.");
			if(Daging < amount) return Error(playerid, "Daging stock tidak mencukupi.");
			GivePlayerMoneyEx(playerid, -value);
			Inventory_Add(playerid, "Daging", 2805, amount);
			Daging -= amount;
			Server_AddMoney(value);
			Info(playerid, "Anda berhasil membeli "GREEN_E"%d "WHITE_E"daging seharga "RED_E"%s.", amount, FormatMoney(value));
		}
	}
	if(dialogid == DIALOG_DRUGS)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			new total = Inventory_Count(playerid, "Marijuana") + amount;
			new value = amount * MarijuanaPrice;
			if(amount < 0 || amount > 100) return Error(playerid, "amount maximal 0 - 100.");
			if(total > 100) return Error(playerid, "Marijuana full in your inventory! max: 100 kg.");
			if(pData[playerid][pMoney] < value) return Error(playerid, "Uang anda kurang.");
			if(Marijuana < amount) return Error(playerid, "Marijuana stock tidak mencukupi.");
			GivePlayerMoneyEx(playerid, -value);
			Inventory_Add(playerid, "Marijuana", 1578, amount);
			Marijuana -= amount;
			Server_AddMoney(value);
			Info(playerid, "Anda berhasil membeli "GREEN_E"%d "WHITE_E"Marijuana seharga "RED_E"%s.", amount, FormatMoney(value));
		}
	}
	if(dialogid == DIALOG_FOOD)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					//buy food
					if(pData[playerid][pFood] > 500) return Error(playerid, "Anda sudah membawa 500 Food!");
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Masukan jumlah Food:\nFood Stock: "GREEN_E"%d\n"WHITE_E"Food Price"GREEN_E"%s /item", Food, FormatMoney(FoodPrice));
					ShowPlayerDialog(playerid, DIALOG_FOOD_BUY, DIALOG_STYLE_INPUT, "Buy Food", mstr, "Buy", "Cancel");
				}
				case 1:
				{
					//buy seed
					if(pData[playerid][pSeed] > 100) return Error(playerid, "Anda sudah membawa 100 Seed!");
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Masukan jumlah Seed:\nFood Stock: "GREEN_E"%d\n"WHITE_E"Seed Price"GREEN_E"%s /item", Food, FormatMoney(SeedPrice));
					ShowPlayerDialog(playerid, DIALOG_SEED_BUY, DIALOG_STYLE_INPUT, "Buy Seed", mstr, "Buy", "Cancel");
				}
				case 2:
				{
					//wheat
					if(pData[playerid][pWheat] > 500) return Error(playerid, "Anda sudah membawa 500 Wheat!");
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Masukan jumlah Wheat:\nWheat Stock: "GREEN_E"%d\n"WHITE_E"Wheat Price"GREEN_E"%s /item", Gandum, FormatMoney(GandumPrice));
					ShowPlayerDialog(playerid, DIALOG_GANDUM_BUY, DIALOG_STYLE_INPUT, "Buy Wheat", mstr, "Buy", "Cancel");
				}
			}
		}
	}
	if(dialogid == DIALOG_FOOD_BUY)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			new total = Inventory_Count(playerid, "Food") + amount;
			new value = amount * FoodPrice;
			if(amount < 0 || amount > 500) return Error(playerid, "amount maximal 0 - 500.");
			if(total > 500) return Error(playerid, "Food terlalu penuh di Inventory! Maximal 500.");
			if(pData[playerid][pMoney] < value) return Error(playerid, "Uang anda kurang.");
			if(Food < amount) return Error(playerid, "Food stock tidak mencukupi.");
			GivePlayerMoneyEx(playerid, -value);
			Inventory_Add(playerid, "Food", 19568, amount);
			Food -= amount;
			Server_AddMoney(value);
			Info(playerid, "Anda berhasil membeli "GREEN_E"%d "WHITE_E"Food seharga "RED_E"%s.", amount, FormatMoney(value));
		}
	}
	if(dialogid == DIALOG_SEED_BUY)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			new total = pData[playerid][pSeed] + amount;
			new value = amount * SeedPrice;
			if(amount < 0 || amount > 100) return Error(playerid, "amount maximal 0 - 100.");
			if(total > 100) return Error(playerid, "Seed terlalu penuh di Inventory! Maximal 100.");
			if(pData[playerid][pMoney] < value) return Error(playerid, "Uang anda kurang.");
			if(Food < amount) return Error(playerid, "Food stock tidak mencukupi.");
			GivePlayerMoneyEx(playerid, -value);
			pData[playerid][pSeed] += amount;
			Food -= amount;
			Server_AddMoney(value);
			Info(playerid, "Anda berhasil membeli "GREEN_E"%d "WHITE_E"Seed seharga "RED_E"%s.", amount, FormatMoney(value));
		}
	}
	if(dialogid == DIALOG_GANDUM_BUY)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			new total = Inventory_Count(playerid, "Wheat") + amount;
			new value = amount * GandumPrice;
			if(amount < 0 || amount > 500) return Error(playerid, "amount maximal 0 - 500.");
			if(total > 500) return Error(playerid, "Wheat terlalu penuh di Inventory! Maximal 500.");
			if(pData[playerid][pMoney] < value) return Error(playerid, "Uang anda kurang.");
			if(Gandum < amount) return Error(playerid, "Gandum di stock tidak mencukupi.");
			GivePlayerMoneyEx(playerid, -value);
			Inventory_Add(playerid, "Wheat", 2247, amount);
			Gandum -= amount;
			Server_AddMoney(value);
			Info(playerid, "Anda berhasil membeli "GREEN_E"%d "WHITE_E"Wheat seharga "RED_E"%s.", amount, FormatMoney(value));
		}
	}
	if(dialogid == DIALOG_EDIT_PRICE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Masukan harga Sprunk(1 - 500):\nPrice 1(Sprunk): "GREEN_E"%s", FormatMoney(pData[playerid][pPrice1]));
					ShowPlayerDialog(playerid, DIALOG_EDIT_PRICE1, DIALOG_STYLE_INPUT, "Price 1", mstr, "Edit", "Cancel");
				}
				case 1:
				{
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Masukan harga Snack(1 - 500):\nPrice 2(Snack): "GREEN_E"%s", FormatMoney(pData[playerid][pPrice2]));
					ShowPlayerDialog(playerid, DIALOG_EDIT_PRICE2, DIALOG_STYLE_INPUT, "Price 2", mstr, "Edit", "Cancel");
				}
				case 2:
				{
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Masukan harga Ice Cream Orange(1 - 500):\nPrice 3(Ice Cream Orange): "GREEN_E"%s", FormatMoney(pData[playerid][pPrice3]));
					ShowPlayerDialog(playerid, DIALOG_EDIT_PRICE3, DIALOG_STYLE_INPUT, "Price 3", mstr, "Edit", "Cancel");
				}
				case 3:
				{
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Masukan harga Hotdog(1 - 500):\nPrice 4(Hotdog): "GREEN_E"%s", FormatMoney(pData[playerid][pPrice4]));
					ShowPlayerDialog(playerid, DIALOG_EDIT_PRICE4, DIALOG_STYLE_INPUT, "Price 4", mstr, "Edit", "Cancel");
				}
			}
		}
	}
	if(dialogid == DIALOG_EDIT_PRICE1)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			
			if(amount < 0 || amount > 500) return Error(playerid, "Invalid price! 1 - 500.");
			pData[playerid][pPrice1] = amount;
			Info(playerid, "Anda berhasil mengedit price 1(Sprunk) ke "GREEN_E"%s.", FormatMoney(amount));
			return 1;
		}
	}
	if(dialogid == DIALOG_EDIT_PRICE2)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			
			if(amount < 0 || amount > 500) return Error(playerid, "Invalid price! 1 - 500.");
			pData[playerid][pPrice2] = amount;
			Info(playerid, "Anda berhasil mengedit price 2(Snack) ke "GREEN_E"%s.", FormatMoney(amount));
			return 1;
		}
	}
	if(dialogid == DIALOG_EDIT_PRICE3)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			
			if(amount < 0 || amount > 500) return Error(playerid, "Invalid price! 1 - 500.");
			pData[playerid][pPrice3] = amount;
			Info(playerid, "Anda berhasil mengedit price 3(Ice Cream Orange) ke "GREEN_E"%s.", FormatMoney(amount));
			return 1;
		}
	}
	if(dialogid == DIALOG_EDIT_PRICE4)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			
			if(amount < 0 || amount > 500) return Error(playerid, "Invalid price! 1 - 500.");
			pData[playerid][pPrice4] = amount;
			Info(playerid, "Anda berhasil mengedit price 4(Hotdog) ke "GREEN_E"%s.", FormatMoney(amount));
			return 1;
		}
	}
	if(dialogid == DIALOG_OFFER)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new id = pData[playerid][pOffer];
					if(!IsPlayerConnected(id) || !NearPlayer(playerid, id, 4.0))
						return Error(playerid, "You not near with offer player!");
					
					if(pData[playerid][pMoney] < pData[id][pPrice1])
						return Error(playerid, "Not enough money!");
						
					if(pData[id][pFood] < 5)
						return Error(playerid, "Food stock empty!");
					
					GivePlayerMoneyEx(id, pData[id][pPrice1]);
					pData[id][pFood] -= 5;
					
					GivePlayerMoneyEx(playerid, -pData[id][pPrice1]);
					Inventory_Add(playerid, "Sprunk", 2958, 1);
		
					SendNearbyMessage(playerid, 10.0, COLOR_PURPLE, "** %s telah membeli sprunk seharga %s.", ReturnName(playerid), FormatMoney(pData[id][pPrice1]));
				}
				case 1:
				{
					new id = pData[playerid][pOffer];
					if(!IsPlayerConnected(id) || !NearPlayer(playerid, id, 4.0))
						return Error(playerid, "You not near with offer player!");
					
					if(pData[playerid][pMoney] < pData[id][pPrice2])
						return Error(playerid, "Not enough money!");
					
					if(pData[id][pFood] < 5)
						return Error(playerid, "Food stock empty!");
						
					GivePlayerMoneyEx(id, pData[id][pPrice2]);
					pData[id][pFood] -= 5;
					
					GivePlayerMoneyEx(playerid, -pData[id][pPrice2]);
					Inventory_Add(playerid, "Snack", 2768, 1);
					
					SendNearbyMessage(playerid, 10.0, COLOR_PURPLE, "** %s telah membeli snack seharga %s.", ReturnName(playerid), FormatMoney(pData[id][pPrice2]));	
				}
				case 2:
				{
					new id = pData[playerid][pOffer];
					if(!IsPlayerConnected(id) || !NearPlayer(playerid, id, 4.0))
						return Error(playerid, "You not near with offer player!");
					
					if(pData[playerid][pMoney] < pData[id][pPrice3])
						return Error(playerid, "Not enough money!");
					
					if(pData[id][pFood] < 10)
						return Error(playerid, "Food stock empty!");
						
					GivePlayerMoneyEx(id, pData[id][pPrice3]);
					pData[id][pFood] -= 10;
					
					GivePlayerMoneyEx(playerid, -pData[id][pPrice3]);
					pData[playerid][pEnergy] += 30;
					
					SendNearbyMessage(playerid, 10.0, COLOR_PURPLE, "** %s telah membeli ice cream orange seharga %s.", ReturnName(playerid), FormatMoney(pData[id][pPrice3]));
				}
				case 3:
				{
					new id = pData[playerid][pOffer];
					if(!IsPlayerConnected(id) || !NearPlayer(playerid, id, 4.0))
						return Error(playerid, "You not near with offer player!");
					
					if(pData[playerid][pMoney] < pData[id][pPrice4])
						return Error(playerid, "Not enough money!");
						
					if(pData[id][pFood] < 10)
						return Error(playerid, "Food stock empty!");
					
					GivePlayerMoneyEx(id, pData[id][pPrice4]);
					pData[id][pFood] -= 10;
					
					GivePlayerMoneyEx(playerid, -pData[id][pPrice4]);
					pData[playerid][pHunger] += 30;
					
					SendNearbyMessage(playerid, 10.0, COLOR_PURPLE, "** %s telah membeli hotdog seharga %s.", ReturnName(playerid), FormatMoney(pData[id][pPrice4]));
				}
			}
		}
		pData[playerid][pOffer] = -1;
	}
	if(dialogid == DIALOG_APOTEK)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new str[254];
					format(str, sizeof(str), ""WHITE_E"Medicine stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah medicine yang ingin kamu beli:", Apotek, FormatMoney(MedicinePrice));
					ShowPlayerDialog(playerid, DIALOG_BUY_MEDICINE, DIALOG_STYLE_INPUT, "Apotek Menu (Medicine)", str, "Yes", "No");
				}
				case 1:
				{
					new str[254];
					format(str, sizeof(str), ""WHITE_E"Medkit stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah medkit yang ingin kamu beli:", Apotek, FormatMoney(MedicinePrice));
					ShowPlayerDialog(playerid, DIALOG_BUY_MEDKIT, DIALOG_STYLE_INPUT, "Apotek Menu (Medkit)", str, "Yes", "No");
				}
				case 2:
				{
					new str[254];
					format(str, sizeof(str), ""WHITE_E"Ephedrine stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah Ephedrine yang ingin kamu beli:", Apotek, FormatMoney(EphedrinePrice));
					ShowPlayerDialog(playerid, DIALOG_BUY_EPHEDRINE, DIALOG_STYLE_INPUT, "Apotek Menu (Ephedrine)", str, "Yes", "No");
				}
				case 3:
				{
					new str[254];
					format(str, sizeof(str), ""WHITE_E"Bandage stock: "GREEN_E"%d ($100/item)\n\n"WHITE_E"Masukan jumlah bandage yang ingin kamu beli:", Apotek);
					ShowPlayerDialog(playerid, DIALOG_BUY_BANDAGE, DIALOG_STYLE_INPUT, "Apotek Menu (Bandage)", str, "Yes", "No");
				}
			}
		}
	}
	if(dialogid == DIALOG_BUY_MEDICINE)
	{
		if(!response)
			return 1;

		new ammount = strval(inputtext), str[254];

		if(ammount < 1 || isnull(inputtext))
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Jumlah tidak boleh kosong/dibawah angka 1!\n\n"WHITE_E"Medicine stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah medicine yang ingin kamu beli:", Apotek, FormatMoney(MedicinePrice));
			ShowPlayerDialog(playerid, DIALOG_BUY_MEDICINE, DIALOG_STYLE_INPUT, "Apotek Menu (Medicine)", str, "Yes", "No");
			return 1;
		}
		if(Apotek - ammount < 0)
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Jumlah stock medicine tidak mencukupi\n\n"WHITE_E"Medicine stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah medicine yang ingin kamu beli:", Apotek, FormatMoney(MedicinePrice));
			ShowPlayerDialog(playerid, DIALOG_BUY_MEDICINE, DIALOG_STYLE_INPUT, "Apotek Menu (Medicine)", str, "Yes", "No");
			return 1;
		}
		if(pData[playerid][pMoney] < ammount * MedicinePrice)
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Uang kamu tidak mencukupi\n\n"WHITE_E"Medicine stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah medicine yang ingin kamu beli:", Apotek, FormatMoney(MedicinePrice));
			ShowPlayerDialog(playerid, DIALOG_BUY_MEDICINE, DIALOG_STYLE_INPUT, "Apotek Menu (Medicine)", str, "Yes", "No");
			return 1;
		}

		Inventory_Add(playerid, "Medicine", 1575, ammount);
		Apotek -= ammount;
		Server_AddMoney(ammount * MedicinePrice);
		GivePlayerMoneyEx(playerid, -ammount * MedicinePrice);

		SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s membeli %d medicine dengan harga %s", ReturnName(playerid), ammount, FormatMoney(ammount * MedicinePrice));
	}
	if(dialogid == DIALOG_BUY_EPHEDRINE)
	{
		if(!response)
			return 1;

		new ammount = strval(inputtext), str[254];

		if(ammount < 1 || isnull(inputtext))
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Jumlah tidak boleh kosong/dibawah angka 1!\n\n"WHITE_E"Ephedrine stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah Ephedrine yang ingin kamu beli:", Apotek, FormatMoney(EphedrinePrice));
			ShowPlayerDialog(playerid, DIALOG_BUY_EPHEDRINE, DIALOG_STYLE_INPUT, "Apotek Menu (Ephedrine)", str, "Yes", "No");
			return 1;
		}
		if(Apotek - ammount < 0)
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Jumlah stock Ephedrine tidak mencukupi\n\n"WHITE_E"Ephedrine stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah Ephedrine yang ingin kamu beli:", Apotek, FormatMoney(EphedrinePrice));
			ShowPlayerDialog(playerid, DIALOG_BUY_EPHEDRINE, DIALOG_STYLE_INPUT, "Apotek Menu (Ephedrine)", str, "Yes", "No");
			return 1;
		}
		if(pData[playerid][pMoney] < ammount * EphedrinePrice)
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Uang kamu tidak mencukupi\n\n"WHITE_E"Ephedrine stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah Ephedrine yang ingin kamu beli:", Apotek, FormatMoney(EphedrinePrice));
			ShowPlayerDialog(playerid, DIALOG_BUY_EPHEDRINE, DIALOG_STYLE_INPUT, "Apotek Menu (Ephedrine)", str, "Yes", "No");
			return 1;
		}

		Inventory_Add(playerid, "Ephedrine", 1580, ammount);
		Apotek -= ammount;
		Server_AddMoney(ammount * EphedrinePrice);
		GivePlayerMoneyEx(playerid, -ammount * EphedrinePrice);

		SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s membeli %d Ephedrine dengan harga %s", ReturnName(playerid), ammount, FormatMoney(ammount * EphedrinePrice));
	}
	if(dialogid == DIALOG_BUY_MEDKIT)
	{
		if(!response)
			return 1;

		new ammount = strval(inputtext), str[254];

		if(ammount < 1 || isnull(inputtext))
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Jumlah tidak boleh kosong/dibawah angka 1!\n\n"WHITE_E"Medkit stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah medkit yang ingin kamu beli:", Apotek, FormatMoney(MedkitPrice));
			ShowPlayerDialog(playerid, DIALOG_BUY_MEDKIT, DIALOG_STYLE_INPUT, "Apotek Menu (Medkit)", str, "Yes", "No");
			return 1;
		}
		if(Apotek - ammount < 0)
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Jumlah stock medkit tidak mencukupi\n\n"WHITE_E"Medkit stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah medkit yang ingin kamu beli:", Apotek, FormatMoney(MedkitPrice));
			ShowPlayerDialog(playerid, DIALOG_BUY_MEDKIT, DIALOG_STYLE_INPUT, "Apotek Menu (Medkit)", str, "Yes", "No");
			return 1;
		}
		if(pData[playerid][pMoney] < ammount * MedkitPrice)
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Uang kamu tidak mencukupi\n\n"WHITE_E"Medkit stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah medkit yang ingin kamu beli:", Apotek, FormatMoney(MedkitPrice));
			ShowPlayerDialog(playerid, DIALOG_BUY_MEDKIT, DIALOG_STYLE_INPUT, "Apotek Menu (Medkit)", str, "Yes", "No");
			return 1;
		}

		Inventory_Add(playerid, "Medkit", 1580, ammount);
		Apotek -= ammount;
		Server_AddMoney(ammount * MedkitPrice);
		GivePlayerMoneyEx(playerid, -ammount * MedkitPrice);

		SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s membeli %d medkit dengan harga %s", ReturnName(playerid), ammount, FormatMoney(ammount * MedkitPrice));
	}
	if(dialogid == DIALOG_BUY_BANDAGE)
	{
		if(!response)
			return 1;

		new ammount = strval(inputtext), str[254];

		if(ammount < 1 || isnull(inputtext))
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Jumlah tidak boleh kosong/dibawah angka 1!\n\n"WHITE_E"Bandage stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah bandage yang ingin kamu beli:", Apotek, FormatMoney(50));
			ShowPlayerDialog(playerid, DIALOG_BUY_BANDAGE, DIALOG_STYLE_INPUT, "Apotek Menu (Bandage)", str, "Yes", "No");
			return 1;
		}
		if(Apotek - ammount < 0)
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Jumlah stock bandage tidak mencukupi\n\n"WHITE_E"Bandage stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah bandage yang ingin kamu beli:", Apotek, FormatMoney(50));
			ShowPlayerDialog(playerid, DIALOG_BUY_BANDAGE, DIALOG_STYLE_INPUT, "Apotek Menu (Bandage)", str, "Yes", "No");
			return 1;
		}
		if(pData[playerid][pMoney] < ammount * 100)
		{
			format(str, sizeof(str), ""RED_E"ERROR:"WHITE_E" Uang kamu tidak mencukupi\n\n"WHITE_E"Bandage stock: "GREEN_E"%d (%s/item)\n\n"WHITE_E"Masukan jumlah bandage yang ingin kamu beli:", Apotek, FormatMoney(50));
			ShowPlayerDialog(playerid, DIALOG_BUY_BANDAGE, DIALOG_STYLE_INPUT, "Apotek Menu (Bandage)", str, "Yes", "No");
			return 1;
		}

		Inventory_Add(playerid, "Bandage", 11747, ammount);
		Apotek -= ammount;
		Server_AddMoney(ammount * 50);
		GivePlayerMoneyEx(playerid, -ammount * 50);

		SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s membeli %d bandage dengan harga %s", ReturnName(playerid), ammount, FormatMoney(100));
	}
	/*if(dialogid == DIALOG_ATM)
	{
		if(!response) 
			return 1;

		switch(listitem)
		{
			case 0: // Check Balance
			{
				new mstr[512];
				format(mstr, sizeof(mstr), "{F6F6F6}Bank Rekening: "LB_E"%d\n{F6F6F6}Money in your bank account: "LB_E"%s", pData[playerid][pBankRek],FormatMoney(pData[playerid][pBankMoney]));
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""LB_E"Bank", mstr, "Close", "");
			}
			case 1: // Withdraw
			{
				new str[512];
				format(str, sizeof(str), ""WHITE_E"Bank Money: "GREEN_LIGHT"%s\n\n"WHITE_E"Masukan jumlah uang yang ingin kamu withdraw:", FormatMoney(pData[playerid][pBankMoney]));
				ShowPlayerDialog(playerid, DIALOG_ATMWITHDRAW, DIALOG_STYLE_INPUT, "Atm Withdraw", str, "Withdraw", "Cancel");
			}
			case 2: // Transfer Money
			{
				ShowPlayerDialog(playerid, DIALOG_ATMREKENING, DIALOG_STYLE_INPUT, ""LB_E"Bank", "Masukan jumlah uang:", "Transfer", "Cancel");
			}
			case 3: //Paycheck
			{
				DisplayPaycheck(playerid);
			}
		}
	}*/
	if(dialogid == DIALOG_ATM)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new str[200];
					format(str, sizeof(str), "{FFFFFF}Rekening Bank: %d\nSaldo Bank di rekening akun anda: {00FF00}%s", pData[playerid][pBankRek], FormatMoney(pData[playerid][pBankMoney]));
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "{FFFFFF}ATM | Account", str, "Close", "");
				}
				case 1:
				{
					new str[200];
					format(str, sizeof(str), "{FFFFFF}Anda memiliki sejumlah {00FF00}%s {FFFFFF}di akun rekening anda\nInput jumlah uang yang akan di transfer:", FormatMoney(pData[playerid][pBankMoney]));
					ShowPlayerDialog(playerid, DIALOG_ATMREKENING, DIALOG_STYLE_INPUT, "ATM | Transfer", str, "Transfer", "Cancel");
				}
				case 2:
				{
					ShowPlayerDialog(playerid, DIALOG_ATMWITHDRAW, DIALOG_STYLE_LIST, "ATM | Withdraw", "{00FF00}$1000\n{00FF00}$5000\n{00FF00}$10000", "Pilih", "Batal");
				}
				case 3:
				{
				    new mstr[512];
					format(mstr, sizeof(mstr), "{FFFFFF}Input jumlah uang yang akan di masukan:");
					ShowPlayerDialog(playerid, DIALOG_BANKDEPOSIT, DIALOG_STYLE_INPUT, "ATM | Deposit", mstr, "Deposit", "Cancel");
				}
			}
		}
	}
	if(dialogid == DIALOG_ATMREKENING)
	{
		if(!response) 
			return true;

		new amount = floatround(strval(inputtext));
		if(amount > pData[playerid][pBankMoney]) 
			return Error(playerid, "Uang dalam rekening anda kurang.");
		
		if(amount < 1) 
			return Error(playerid, "You have entered an invalid amount!");

		else
		{
			pData[playerid][pTransfer] = amount;
			ShowPlayerDialog(playerid, DIALOG_ATMTRANSFER, DIALOG_STYLE_INPUT, ""LB_E"Bank", "Masukan nomor rekening target:", "Transfer", "Cancel");
		}
	}
	if(dialogid == DIALOG_ATMWITHDRAW)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pBankMoney] < 999)
						return ErrorMsg(playerid, "Anda tidak memiliki saldo uang di bank anda");

					pData[playerid][pBankMoney] -= 1000;
					SuccesMsg(playerid, "Berhasil menarik uang sejumlah $1000");
					GivePlayerMoneyEx(playerid, 1000);
				}
				case 1:
				{
					if(pData[playerid][pBankMoney] < 4999)
						return ErrorMsg(playerid, "Anda tidak memiliki saldo uang di bank anda");

					pData[playerid][pBankMoney] -= 5000;
					SuccesMsg(playerid, "Berhasil menarik uang sejumlah $5000");
					GivePlayerMoneyEx(playerid, 5000);
				}
				case 2:
				{
					if(pData[playerid][pBankMoney] < 9999)
						return ErrorMsg(playerid, "Anda tidak memiliki saldo uang di bank anda");

					pData[playerid][pBankMoney] -= 10000;
					SuccesMsg(playerid, "Berhasil menarik uang sejumlah $10000");
					GivePlayerMoneyEx(playerid, 10000);
				}
			}
		}
		return 1;
	}
	/*if(dialogid == DIALOG_ATMWITHDRAW)
	{
		if(response)
		{
			new ammount = strval(inputtext);
			if(ammount < 1)
			{
				new str[512];
				format(str, sizeof(str), ""WHITE_E"Bank Money: "GREEN_LIGHT"%s\n\n"RED_E"ERROR: "WHITE_E"Jumlah tidak boleh dibawah angka 1!\n"WHITE_E"Masukan jumlah uang yang ingin kamu withdraw:", FormatMoney(pData[playerid][pBankMoney]));
				ShowPlayerDialog(playerid, DIALOG_ATMWITHDRAW, DIALOG_STYLE_INPUT, "Atm Withdraw", str, "Withdraw", "Cancel");
				return 1;
			}
			if(ammount > pData[playerid][pBankMoney])
			{
				new str[512];
				format(str, sizeof(str), ""WHITE_E"Bank Money: "GREEN_LIGHT"%s\n\n"RED_E"ERROR: "WHITE_E"Uang dalam rekening anda tidak mencukupi!\n"WHITE_E"Masukan jumlah uang yang ingin kamu withdraw:", FormatMoney(pData[playerid][pBankMoney]));
				ShowPlayerDialog(playerid, DIALOG_ATMWITHDRAW, DIALOG_STYLE_INPUT, "Atm Withdraw", str, "Withdraw", "Cancel");
				return 1;
			}

			pData[playerid][pBankMoney] -= ammount;
			
			GivePlayerMoneyEx(playerid, ammount);
			SendNearbyMessage(playerid, 15.0, COLOR_PURPLE,  "** %s menarik uang sejumlah %s dari mesin atm", ReturnName(playerid), FormatMoney(ammount));
		}
		return 1;
	}*/
	if(dialogid == DIALOG_ATMREKENING)
	{
		if(!response) return true;
		new amount = floatround(strval(inputtext));
		if(amount > pData[playerid][pBankMoney]) return Error(playerid, "Uang dalam rekening anda kurang.");
		if(amount < 1) return Error(playerid, "You have entered an invalid amount!");

		else
		{
			pData[playerid][pTransfer] = amount;
			ShowPlayerDialog(playerid, DIALOG_ATMTRANSFER, DIALOG_STYLE_INPUT, ""LB_E"Bank", "Masukan nomor rekening target:", "Transfer", "Cancel");
		}
	}
	if(dialogid == DIALOG_ATMTRANSFER)
	{
		if(!response) return true;
		new rek = floatround(strval(inputtext)), query[128];
		
		mysql_format(g_SQL, query, sizeof(query), "SELECT brek FROM players WHERE brek='%d'", rek);
		mysql_tquery(g_SQL, query, "SearchRekAtm", "id", playerid, rek);
		return 1;
	}
	if(dialogid == DIALOG_ATMCONFIRM)
	{
		if(response)
		{
			new query[128], mstr[248];
			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET bmoney=bmoney+%d WHERE brek=%d", pData[playerid][pTransfer], pData[playerid][pTransferRek]);
			mysql_tquery(g_SQL, query);
			
			foreach(new ii : Player)
			{
				if(pData[ii][pBankRek] == pData[playerid][pTransferRek])
				{
					pData[ii][pBankMoney] += pData[playerid][pTransfer];
				}
			}
			
			pData[playerid][pBankMoney] -= pData[playerid][pTransfer];
			
			format(mstr, sizeof(mstr), ""WHITE_E"No Rek Target: "YELLOW_E"%d\n"WHITE_E"Nama Target: "YELLOW_E"%s\n"WHITE_E"Jumlah: "GREEN_E"%s\n\n"WHITE_E"Anda telah berhasil mentransfer!", pData[playerid][pTransferRek], pData[playerid][pTransferName], FormatMoney(pData[playerid][pTransfer]));
			ShowPlayerDialog(playerid, DIALOG_ATMSUKSES, DIALOG_STYLE_MSGBOX, ""LB_E"Transfer Sukses", mstr, "Sukses", "");
		}
	}
	if(dialogid == DIALOG_ATMSUKSES)
	{
		if(response)
		{
			pData[playerid][pTransfer] = 0;
			pData[playerid][pTransferRek] = 0;
		}
	}
	if(dialogid == DIALOG_FIND_ATM)
	{
		if(response) 
		{	
			new id = ReturnRestockATMID((listitem + 1));
			
			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerWaze(playerid, Float:AtmData[id][atmX], Float:AtmData[id][atmY], Float:AtmData[id][atmZ], 0x8A44E4FF);
			SetPlayerRaceCheckpoint(playerid, 1, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ], 0.0, 0.0, 0.0, 7.0);
			Info(playerid, "Kamu akan mengantar menuju ATM yang berlokasi di %s yang berjarak %0.0fm", GetLocation(AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]), GetPlayerDistanceFromPoint(playerid, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]));
		}
		return 1;
	}
	if(dialogid == DIALOG_BANK)
	{
		if(!response) 
			return true;
		
		switch(listitem)
		{
			case 0: // Deposit
			{
				new mstr[512];
				format(mstr, sizeof(mstr), "{F6F6F6}You have "LB_E"%s {F6F6F6}in bank account.\n\nType in the amount you want to deposit below:", FormatMoney(pData[playerid][pBankMoney]));
				ShowPlayerDialog(playerid, DIALOG_BANKDEPOSIT, DIALOG_STYLE_INPUT, ""LB_E"Bank", mstr, "Deposit", "Cancel");
			}
			case 1: // Withdraw
			{
				new mstr[512];
				format(mstr, sizeof(mstr), "{F6F6F6}You have "LB_E"%s {F6F6F6}in your bank account.\n\nType in the amount you want to withdraw below:", FormatMoney(pData[playerid][pBankMoney]));
				ShowPlayerDialog(playerid, DIALOG_BANKWITHDRAW, DIALOG_STYLE_INPUT, ""LB_E"Bank", mstr, "Withdraw", "Cancel");
			}
			case 2: // Check Balance
			{
				new mstr[512];
				format(mstr, sizeof(mstr), "{F6F6F6}You have "LB_E"%s {F6F6F6}in your bank account.", FormatMoney(pData[playerid][pBankMoney]));
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""LB_E"Bank", mstr, "Close", "");
			}
			case 3: //Transfer Money
			{
				ShowPlayerDialog(playerid, DIALOG_BANKREKENING, DIALOG_STYLE_INPUT, ""LB_E"Bank", "Masukan jumlah uang:", "Transfer", "Cancel");
			}
			case 4:
			{
				DisplayPaycheck(playerid);
			}
		}
	}
	if(dialogid == DIALOG_BANKDEPOSIT)
	{
		if(!response) return true;
		new amount = floatround(strval(inputtext));
		if(amount > pData[playerid][pMoney]) return Error(playerid, "You do not have the sufficient funds to make this transaction.");
		if(amount < 1) return Error(playerid, "You have entered an invalid amount!");

		else
		{
			new query[512], lstr[512];
			pData[playerid][pBankMoney] = (pData[playerid][pBankMoney] + amount);
			GivePlayerMoneyEx(playerid, -amount);
			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET bmoney=%d WHERE reg_id=%d", pData[playerid][pBankMoney], pData[playerid][pID]);
			mysql_tquery(g_SQL, query);
			format(lstr, sizeof(lstr), "{F6F6F6}You have successfully deposited "LB_E"%s {F6F6F6}into your bank account.\n"LB_E"Current Balance: {F6F6F6}%s", FormatMoney(amount), FormatMoney(pData[playerid][pBankMoney]));
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""ORANGE_E"Kampung Indo"LB_E"Bank", lstr, "Close", "");
		}
	}
	if(dialogid == DIALOG_BANKWITHDRAW)
	{
		if(!response) return true;
		new amount = floatround(strval(inputtext));
		if(amount > pData[playerid][pBankMoney]) return Error(playerid, "You do not have the sufficient funds to make this transaction.");
		if(amount < 1) return Error(playerid, "You have entered an invalid amount!");
		else
		{
			new query[128], lstr[512];
			pData[playerid][pBankMoney] = (pData[playerid][pBankMoney] - amount);
			GivePlayerMoneyEx(playerid, amount);
			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET bmoney=%d WHERE reg_id=%d", pData[playerid][pBankMoney], pData[playerid][pID]);
			mysql_tquery(g_SQL, query);
			format(lstr, sizeof(lstr), "{F6F6F6}You have successfully withdrawed "LB_E"%s {F6F6F6}from your bank account.\n"LB_E"Current Balance: {F6F6F6}%s", FormatMoney(amount), FormatMoney(pData[playerid][pBankMoney]));
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""ORANGE_E"Kampung Indo"LB_E"Bank", lstr, "Close", "");
		}
	}
	if(dialogid == DIALOG_BANKREKENING)
	{
		if(!response) return true;
		new amount = floatround(strval(inputtext));
		if(amount > pData[playerid][pBankMoney]) return Error(playerid, "Uang dalam rekening anda kurang.");
		if(amount < 1) return Error(playerid, "You have entered an invalid amount!");

		else
		{
			pData[playerid][pTransfer] = amount;
			ShowPlayerDialog(playerid, DIALOG_BANKTRANSFER, DIALOG_STYLE_INPUT, ""LB_E"Bank", "Masukan nomor rekening target:", "Transfer", "Cancel");
		}
	}
	if(dialogid == DIALOG_BANKTRANSFER)
	{
		if(!response) return true;
		new rek = floatround(strval(inputtext)), query[128];
		
		mysql_format(g_SQL, query, sizeof(query), "SELECT brek FROM players WHERE brek='%d'", rek);
		mysql_tquery(g_SQL, query, "SearchRek", "id", playerid, rek);
		return 1;
	}
	if(dialogid == DIALOG_BANKCONFIRM)
	{
		if(response)
		{
			new query[128], mstr[248];
			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET bmoney=bmoney+%d WHERE brek=%d", pData[playerid][pTransfer], pData[playerid][pTransferRek]);
			mysql_tquery(g_SQL, query);
			
			foreach(new ii : Player)
			{
				if(pData[ii][pBankRek] == pData[playerid][pTransferRek])
				{
					pData[ii][pBankMoney] += pData[playerid][pTransfer];
				}
			}
			
			pData[playerid][pBankMoney] -= pData[playerid][pTransfer];
			
			
			format(mstr, sizeof(mstr), ""WHITE_E"No Rek Target: "YELLOW_E"%d\n"WHITE_E"Nama Target: "YELLOW_E"%s\n"WHITE_E"Jumlah: "GREEN_E"%s\n\n"WHITE_E"Anda telah berhasil mentransfer!", pData[playerid][pTransferRek], pData[playerid][pTransferName], FormatMoney(pData[playerid][pTransfer]));
			ShowPlayerDialog(playerid, DIALOG_BANKSUKSES, DIALOG_STYLE_MSGBOX, ""LB_E"Transfer Sukses", mstr, "Sukses", "");
		}
	}
	if(dialogid == DIALOG_BANKSUKSES)
	{
		if(response)
		{
			pData[playerid][pTransfer] = 0;
			pData[playerid][pTransferRek] = 0;
		}
	}
	if(dialogid == DIALOG_ASKS)
	{
		if(response) 
		{
			//new i = strval(inputtext);
			new id = listitem;

			ShowPlayerDialog(playerid, DIALOG_ASKANS, DIALOG_STYLE_INPUT, "Panel Pertanyaan",
			"Apa yang anda ingin lakukan pada Pertanyaan ini?\n"\
			"Input Text di bawah ini untuk menjawab pertanyaan", "Accept", "Denied");
			SetPVarInt(playerid, "TEMP_LISTITEM", id);
		}
	}
	if(dialogid == DIALOG_ASKANS)
	{
		new id = GetPVarInt(playerid, "TEMP_LISTITEM");
		new string[500];
		if(response)
		{

			if(strlen(inputtext) == 0)
			{
				AdminCMD(AskData[id][askPlayer], "{A60000}%s {FFFFFF}telah menerima permintaan {FFFF00}'/ask' {FFFFFF}anda", pData[playerid][pAdminname]);
				SendStaffMessage(-1, "{A60000}%s {FFFFFF}telah menerima permintaan {FFFF00}'/ask' {FFFFFF}pada player %s", pData[playerid][pAdminname], pData[AskData[id][askPlayer]][pName]);
				Ask_Remove(id);
				return 1;
			}
			AdminCMD(AskData[id][askPlayer], "{A60000}%s {FFFFFF}telah menerima permintaan {FFFF00}'/ask' {FFFFFF}anda", pData[playerid][pAdminname]);
			format(string, sizeof(string), "~> %s", inputtext);
			SendClientMessage(AskData[id][askPlayer], -1, string);
			SendStaffMessage(-1, "{A60000}%s {FFFFFF}telah menerima permintaan {FFFF00}'/ask' {FFFFFF}pada player %s", pData[playerid][pAdminname], pData[AskData[id][askPlayer]][pName]);
			Ask_Remove(id);
		}
		else
		{
			SendStaffMessage(-1, "{A60000}%s {FFFFFF}telah menolak permintaan {FFFF00}'/ask' {FFFFFF}pada player %s", pData[playerid][pAdminname], pData[AskData[id][askPlayer]][pName]);
			AdminCMD(AskData[id][askPlayer], "{A60000}%s {FFFFFF}telah menolak permintaan {FFFF00}'/ask' {FFFFFF}anda", pData[playerid][pAdminname]);
			Ask_Remove(id);
		}
	}
	if(dialogid == DIALOG_REPORTS)
	{
		if(response) 
		{
			//new i = strval(inputtext);
			new id = listitem;

			ShowPlayerDialog(playerid, DIALOG_REPORTSANS, DIALOG_STYLE_INPUT, "Panel Laporan",
			"Apa yang anda ingin lakukan pada Laporan ini?\n"\
			"Input Text di bawah ini untuk menjawab pertanyaan", "Accept", "Denied");
			SetPVarInt(playerid, "TEMP_LISTITEM1", id);
		}
	}
	if(dialogid == DIALOG_REPORTSANS)
	{
		new id = GetPVarInt(playerid, "TEMP_LISTITEM1");
		new string[250];
		if(response)
		{
			if(strlen(inputtext) == 0)
			{
				AdminCMD(ReportData[id][rPlayer], "{A60000}%s {FFFFFF}telah menerima permintaan {FF0000}'/report' {FFFFFF}anda", pData[playerid][pAdminname]);
				SendStaffMessage(-1, "{A60000}%s {FFFFFF}telah menerima permintaan {FF0000}'/report' {FFFFFF}pada player %s", pData[playerid][pAdminname], pData[ReportData[id][rPlayer]][pName]);
				Report_Remove(id);
				return 1;
			}
			AdminCMD(ReportData[id][rPlayer], "{A60000}%s {FFFFFF}telah menerima permintaan {FF0000}'/report' {FFFFFF}anda", pData[playerid][pAdminname]);
			format(string, sizeof(string), "~> %s", inputtext);
			SendClientMessage(ReportData[id][rPlayer], -1, string);
			SendStaffMessage(-1, "{A60000}%s {FFFFFF}telah menerima permintaan {FF0000}'/report' {FFFFFF}pada player %s", pData[playerid][pAdminname], pData[ReportData[id][rPlayer]][pName]);
			Report_Remove(id);
		}
		else
		{
			SendStaffMessage(-1, "{A60000}%s {FFFFFF}telah menolak permintaan {FF0000}'/report' {FFFFFF}pada player %s", pData[playerid][pAdminname], pData[ReportData[id][rPlayer]][pName]);
			AdminCMD(ReportData[id][rPlayer], "{A60000}%s {FFFFFF}telah menolak permintaan {FF0000}'/report' {FFFFFF}anda", pData[playerid][pAdminname]);
			Report_Remove(id);
		}
	}
	if(dialogid == DIALOG_BUYPVCP)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					//Bikes
					new str[1024];
					
					format(str, sizeof(str), "Kendaraan\tHarga\n"WHITE_E"%s\t\t"LG_E"%s\n%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n", 
					GetVehicleModelName(481), FormatMoney(GetVehicleCost(481)), 
					GetVehicleModelName(509), FormatMoney(GetVehicleCost(509)),
					GetVehicleModelName(510), FormatMoney(GetVehicleCost(510)),
					GetVehicleModelName(462), FormatMoney(GetVehicleCost(462)),
					GetVehicleModelName(586), FormatMoney(GetVehicleCost(586)),
					GetVehicleModelName(581), FormatMoney(GetVehicleCost(581)),
					GetVehicleModelName(461), FormatMoney(GetVehicleCost(461)),
					GetVehicleModelName(521), FormatMoney(GetVehicleCost(521)),
					GetVehicleModelName(463), FormatMoney(GetVehicleCost(463)),
					GetVehicleModelName(468), FormatMoney(GetVehicleCost(468))
					);
					
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_BIKES, DIALOG_STYLE_TABLIST_HEADERS, "{7fff00}Motorcycle", str, "Buy", "Close");
				}
				case 1:
				{
					//Cars
					new str[1024];
					format(str, sizeof(str), "Kendaraan\tHarga\n"WHITE_E"%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n", 
					GetVehicleModelName(400), FormatMoney(GetVehicleCost(400)), 
					GetVehicleModelName(412), FormatMoney(GetVehicleCost(412)),
					GetVehicleModelName(419), FormatMoney(GetVehicleCost(419)),
					GetVehicleModelName(426), FormatMoney(GetVehicleCost(426)),
					GetVehicleModelName(436), FormatMoney(GetVehicleCost(436)),
					GetVehicleModelName(466), FormatMoney(GetVehicleCost(466)),
					GetVehicleModelName(467), FormatMoney(GetVehicleCost(467)),
					GetVehicleModelName(474), FormatMoney(GetVehicleCost(474)),
					GetVehicleModelName(475), FormatMoney(GetVehicleCost(475)),
					GetVehicleModelName(480), FormatMoney(GetVehicleCost(480)),
					GetVehicleModelName(603), FormatMoney(GetVehicleCost(603)),
					GetVehicleModelName(421), FormatMoney(GetVehicleCost(421)),
					GetVehicleModelName(602), FormatMoney(GetVehicleCost(602)),
					GetVehicleModelName(492), FormatMoney(GetVehicleCost(492)),
					GetVehicleModelName(545), FormatMoney(GetVehicleCost(545)),
					GetVehicleModelName(489), FormatMoney(GetVehicleCost(489)),
					GetVehicleModelName(405), FormatMoney(GetVehicleCost(405)),
					GetVehicleModelName(445), FormatMoney(GetVehicleCost(445)),
					GetVehicleModelName(579), FormatMoney(GetVehicleCost(579)),
					GetVehicleModelName(507), FormatMoney(GetVehicleCost(507))
					);
					
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CARS, DIALOG_STYLE_TABLIST_HEADERS, "{7fff00}Mobil", str, "Buy", "Close");
				}
				case 2:
				{
					//Unique Cars
					new str[1024];
					format(str, sizeof(str), "Kendaraan\tHarga\n"WHITE_E"%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n", 
					GetVehicleModelName(483), FormatMoney(GetVehicleCost(483)), 
					GetVehicleModelName(534), FormatMoney(GetVehicleCost(534)),
					GetVehicleModelName(535), FormatMoney(GetVehicleCost(535)),
					GetVehicleModelName(536), FormatMoney(GetVehicleCost(536)),
					GetVehicleModelName(558), FormatMoney(GetVehicleCost(558)),
					GetVehicleModelName(559), FormatMoney(GetVehicleCost(559)),
					GetVehicleModelName(560), FormatMoney(GetVehicleCost(560)),
					GetVehicleModelName(561), FormatMoney(GetVehicleCost(561)),
					GetVehicleModelName(562), FormatMoney(GetVehicleCost(562)),
					GetVehicleModelName(565), FormatMoney(GetVehicleCost(565)),
					GetVehicleModelName(567), FormatMoney(GetVehicleCost(567)),
					GetVehicleModelName(575), FormatMoney(GetVehicleCost(575)),
					GetVehicleModelName(576), FormatMoney(GetVehicleCost(576))
					);
					
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_UCARS, DIALOG_STYLE_TABLIST_HEADERS, "{7fff00}Kendaraan Unik", str, "Buy", "Close");
				}
				case 3:
				{
					//Job Cars
					new str[1024];
					format(str, sizeof(str), "Kendaraan\tHarga\n"WHITE_E"%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s", 
					GetVehicleModelName(420), FormatMoney(GetVehicleCost(420)), 
					GetVehicleModelName(438), FormatMoney(GetVehicleCost(438)), 
					GetVehicleModelName(413), FormatMoney(GetVehicleCost(413)),
					GetVehicleModelName(414), FormatMoney(GetVehicleCost(414)),
					GetVehicleModelName(422), FormatMoney(GetVehicleCost(422)),
					GetVehicleModelName(440), FormatMoney(GetVehicleCost(440)),
					GetVehicleModelName(455), FormatMoney(GetVehicleCost(455)),
					GetVehicleModelName(456), FormatMoney(GetVehicleCost(456)),
					GetVehicleModelName(478), FormatMoney(GetVehicleCost(478)),
					GetVehicleModelName(482), FormatMoney(GetVehicleCost(482)),
					GetVehicleModelName(498), FormatMoney(GetVehicleCost(498)),
					GetVehicleModelName(499), FormatMoney(GetVehicleCost(499)),
					GetVehicleModelName(423), FormatMoney(GetVehicleCost(423)),
					GetVehicleModelName(588), FormatMoney(GetVehicleCost(588)),
					GetVehicleModelName(524), FormatMoney(GetVehicleCost(524)),
					GetVehicleModelName(525), FormatMoney(GetVehicleCost(525)),
					GetVehicleModelName(543), FormatMoney(GetVehicleCost(543)),
					GetVehicleModelName(552), FormatMoney(GetVehicleCost(552)),
					GetVehicleModelName(554), FormatMoney(GetVehicleCost(554)),
					GetVehicleModelName(578), FormatMoney(GetVehicleCost(578)),
					GetVehicleModelName(609), FormatMoney(GetVehicleCost(609)),
					GetVehicleModelName(403), FormatMoney(GetVehicleCost(403)),
					GetVehicleModelName(514), FormatMoney(GetVehicleCost(514)),
					GetVehicleModelName(515), FormatMoney(GetVehicleCost(515))
					//GetVehicleModelName(530), FormatMoney(GetVehicleCost(530)) //fortklift
					);
					
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_JOBCARS, DIALOG_STYLE_TABLIST_HEADERS, "{7fff00}Kendaraan Job", str, "Buy", "Close");
				}
				case 4:
				{
					// VIP Cars
					new str[1024];
					format(str, sizeof(str), "Kendaraan\tHarga\n"WHITE_E"%s\t\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n%s\t"YELLOW_E"%d gold\n", 
					GetVehicleModelName(522), GetVipVehicleCost(522), 
					GetVehicleModelName(411), GetVipVehicleCost(411), 
					GetVehicleModelName(451), GetVipVehicleCost(451),
					GetVehicleModelName(415), GetVipVehicleCost(415), 
					GetVehicleModelName(402), GetVipVehicleCost(402), 
					GetVehicleModelName(541), GetVipVehicleCost(541), 
					GetVehicleModelName(429), GetVipVehicleCost(429), 
					GetVehicleModelName(506), GetVipVehicleCost(506), 
					GetVehicleModelName(494), GetVipVehicleCost(494), 
					GetVehicleModelName(502), GetVipVehicleCost(502), 
					GetVehicleModelName(503), GetVipVehicleCost(503), 
					GetVehicleModelName(409), GetVipVehicleCost(409), 
					GetVehicleModelName(477), GetVipVehicleCost(477)
					);
					
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCARS, DIALOG_STYLE_TABLIST_HEADERS, "{7fff00}Kendaraan VIP", str, "Buy", "Close");
				}
			}
		}
	}
	if(dialogid == DIALOG_BUYPVCP_BIKES)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 481;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 1:
				{
					new modelid = 509;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 2:
				{
					new modelid = 510;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 3:
				{
					new modelid = 462;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 4:
				{
					new modelid = 586;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 5:
				{
					new modelid = 581;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 6:
				{
					new modelid = 461;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 7:
				{
					new modelid = 521;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 8:
				{
					new modelid = 463;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 9:
				{
					new modelid = 468;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
			}
		}
	}
	if(dialogid == DIALOG_BUYPVCP_CARS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 400;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 1:
				{
					new modelid = 412;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 2:
				{
					new modelid = 419;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 3:
				{
					new modelid = 426;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 4:
				{
					new modelid = 436;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 5:
				{
					new modelid = 466;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 6:
				{
					new modelid = 467;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 7:
				{
					new modelid = 474;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 8:
				{
					new modelid = 475;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 9:
				{
					new modelid = 480;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 10:
				{
					new modelid = 603;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 11:
				{
					new modelid = 421;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 12:
				{
					new modelid = 602;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 13:
				{
					new modelid = 492;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 14:
				{
					new modelid = 545;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 15:
				{
					new modelid = 489;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 16:
				{
					new modelid = 405;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 17:
				{
					new modelid = 445;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 18:
				{
					new modelid = 579;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 19:
				{
					new modelid = 507;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
			}
		}
	}
	if(dialogid == DIALOG_BUYPVCP_UCARS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 483;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 1:
				{
					new modelid = 534;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 2:
				{
					new modelid = 535;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 3:
				{
					new modelid = 536;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 4:
				{
					new modelid = 558;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 5:
				{
					new modelid = 559;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 6:
				{
					new modelid = 560;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 7:
				{
					new modelid = 561;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 8:
				{
					new modelid = 562;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 9:
				{
					new modelid = 565;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 10:
				{
					new modelid = 567;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 11:
				{
					new modelid = 575;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 12:
				{
					new modelid = 576;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
			}
		}
	}
	if(dialogid == DIALOG_BUYPVCP_JOBCARS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 420;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 1:
				{
					new modelid = 403;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 2:
				{
					new modelid = 413;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 3:
				{
					new modelid = 414;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 4:
				{
					new modelid = 422;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 5:
				{
					new modelid = 440;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 6:
				{
					new modelid = 455;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 7:
				{
					new modelid = 456;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 8:
				{
					new modelid = 478;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 9:
				{
					new modelid = 482;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 10:
				{
					new modelid = 498;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 11:
				{
					new modelid = 499;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 12:
				{
					new modelid = 423;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 13:
				{
					new modelid = 588;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 14:
				{
					new modelid = 524;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 15:
				{
					new modelid = 525;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 16:
				{
					new modelid = 543;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 17:
				{
					new modelid = 552;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 18:
				{
					new modelid = 554;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 19:
				{
					new modelid = 578;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 20:
				{
					new modelid = 609;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 21:
				{
					new modelid = 403;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 22:
				{
					new modelid = 514;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 23:
				{
					new modelid = 515;
					new tstr[128], price = GetVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(price));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
			}
		}
	}
	if(dialogid == DIALOG_RENT_JOBCARS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 414;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 1:
				{
					new modelid = 455;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 2:
				{
					new modelid = 456;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 3:
				{
					new modelid = 498;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 4:
				{
					new modelid = 499;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 5:
				{
					new modelid = 609;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 6:
				{
					new modelid = 478;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 7:
				{
					new modelid = 422;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 8:
				{
					new modelid = 543;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 9:
				{
					new modelid = 554;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 10:
				{
					new modelid = 525;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 11:
				{
					new modelid = 438;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
				case 12:
				{
					new modelid = 420;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"$500 / one days", GetVehicleModelName(modelid));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Vehicles", tstr, "Rental", "Batal");
				}
			}
		}
	}
	//
	/*if(dialogid == DIALOG_BUYPVCP_BIKES)
	{
		new deid = pData[playerid][pGetDEID];
		
		if(drData[deid][dP][listitem] == 0)
			return Error(playerid, "Harga kendaraan ini belum di set oleh pemiliknya");

		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 481;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][0];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][0]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 1:
				{
					new modelid = 509;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][1];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][1]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 2:
				{
					new modelid = 510;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][2];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][2]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 3:
				{
					new modelid = 462;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][3];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][3]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 4:
				{
					new modelid = 586;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][4];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][4]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 5:
				{
					new modelid = 581;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][5];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][5]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 6:
				{
					new modelid = 461;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][6];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][6]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 7:
				{
					new modelid = 521;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][7];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][7]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 8:
				{
					new modelid = 463;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][8];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][8]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 9:
				{
					new modelid = 468;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][9];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][9]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_BUYPVCP_CARS)
	{
		new deid = pData[playerid][pGetDEID];

		if(drData[deid][dP][listitem] == 0)
			return Error(playerid, "Harga kendaraan ini belum di set oleh pemiliknya");

		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 400;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][0];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][0]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 1:
				{
					new modelid = 412;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][1];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][1]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 2:
				{
					new modelid = 419;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][2];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][2]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 3:
				{
					new modelid = 426;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][3];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][3]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 4:
				{
					new modelid = 436;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][4];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][4]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 5:
				{
					new modelid = 466;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][5];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][5]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 6:
				{
					new modelid = 467;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][6];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][6]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 7:
				{
					new modelid = 474;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][7];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][7]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 8:
				{
					new modelid = 475;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][8];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][8]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 9:
				{
					new modelid = 480;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][9];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][9]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 10:
				{
					new modelid = 603;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][10];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][10]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 11:
				{
					new modelid = 421;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][11];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][11]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 12:
				{
					new modelid = 602;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][12];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][12]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 13:
				{
					new modelid = 492;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][13];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][13]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 14:
				{
					new modelid = 545;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][14];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][14]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 15:
				{
					new modelid = 489;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][15];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][15]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 16:
				{
					new modelid = 405;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][16];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][16]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 17:
				{
					new modelid = 445;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][17];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][17]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 18:
				{
					new modelid = 579;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][18];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][18]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 19:
				{
					new modelid = 507;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][19];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][19]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_BUYPVCP_UCARS)
	{
		new deid = pData[playerid][pGetDEID];

		if(drData[deid][dP][listitem] == 0)
			return Error(playerid, "Harga kendaraan ini belum di set oleh pemiliknya");

		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 483;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][0];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][0]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 1:
				{
					new modelid = 535;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][1];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][1]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 2:
				{
					new modelid = 536;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][2];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][2]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 3:
				{
					new modelid = 558;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][3];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][3]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 4:
				{
					new modelid = 559;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][4];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][4]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 5:
				{
					new modelid = 560;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][5];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][5]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 6:
				{
					new modelid = 561;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][6];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][6]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 7:
				{
					new modelid = 562;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][7];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][7]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 8:
				{
					new modelid = 565;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][8];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][8]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 9:
				{
					new modelid = 567;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][9];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][9]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 10:
				{
					new modelid = 575;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][10];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][10]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 11:
				{
					new modelid = 576;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][11];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][11]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_BUYPVCP_JOBCARS)
	{
		new deid = pData[playerid][pGetDEID];

		if(drData[deid][dP][listitem] == 0)
			return Error(playerid, "Harga kendaraan ini belum di set oleh pemiliknya");

		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 420;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][0];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][0]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 1:
				{
					new modelid = 438;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][1];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][1]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 2:
				{
					new modelid = 403;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][2];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][2]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 3:
				{
					new modelid = 413;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][3];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][3]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 4:
				{
					new modelid = 414;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][4];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][4]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 5:
				{
					new modelid = 422;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][5];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][5]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 6:
				{
					new modelid = 440;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][6];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][6]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 7:
				{
					new modelid = 455;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][7];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][7]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 8:
				{
					new modelid = 456;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][8];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][8]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 9:
				{
					new modelid = 478;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][9];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][9]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 10:
				{
					new modelid = 482;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][10];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][10]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 11:
				{
					new modelid = 498;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][11];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][11]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 12:
				{
					new modelid = 499;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][12];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][12]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 13:
				{
					new modelid = 423;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][13];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][13]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 14:
				{
					new modelid = 588;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][14];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][14]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 15:
				{
					new modelid = 524;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][15];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][15]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 16:
				{
					new modelid = 525;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][16];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][16]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 17:
				{
					new modelid = 543;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][17];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][17]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 18:
				{
					new modelid = 552;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][18];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][18]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 19:
				{
					new modelid = 554;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][19];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][19]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 20:
				{
					new modelid = 578;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][20];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][20]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 21:
				{
					new modelid = 609;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][21];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][21]));
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
			}
		}
		return 1;
	}*/
	if(dialogid == DIALOG_BUYPVCP_VIPCARS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 522;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 1:
				{
					new modelid = 411;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 2:
				{
					new modelid = 451;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 3:
				{
					new modelid = 415;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 4:
				{
					new modelid = 502;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 5:
				{
					new modelid = 541;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 6:
				{
					new modelid = 429;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 7:
				{
					new modelid = 506;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 8:
				{
					new modelid = 494;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 9:
				{
					new modelid = 502;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 10:
				{
					new modelid = 503;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 11:
				{
					new modelid = 409;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
				case 12:
				{
					new modelid = 477;
					new tstr[128], price = GetVipVehicleCost(modelid);
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d gold", GetVehicleModelName(modelid), price);
					ShowPlayerDialog(playerid, DIALOG_BUYPVCP_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
				}
			}
		}
		return 1;
	}
	/*if(dialogid == DIALOG_RENT_JOBCARS)
	{
		new deid = pData[playerid][pGetDEID];

		if(drData[deid][dP][listitem] == 0)
			return Error(playerid, "Harga kendaraan ini belum di set oleh pemiliknya");
		
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 414;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][0];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][0]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 1:
				{
					new modelid = 455;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][1];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][1]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 2:
				{
					new modelid = 456;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][2];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][2]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 3:
				{
					new modelid = 498;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][3];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][3]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 4:
				{
					new modelid = 499;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][4];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][4]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 5:
				{
					new modelid = 609;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][5];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][5]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 6:
				{
					new modelid = 478;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][6];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][6]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 7:
				{
					new modelid = 422;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][7];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][7]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 8:
				{
					new modelid = 543;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][8];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][8]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 9:
				{
					new modelid = 554;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][9];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][9]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 10:
				{
					new modelid = 525;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][10];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][10]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 11:
				{
					new modelid = 438;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][11];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][11]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 12:
				{
					new modelid = 420;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][12];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][12]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
				case 13:
				{
					new modelid = 403;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					pData[playerid][pGetDEIDPRICE] = drData[deid][dP][13];
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(drData[deid][dP][12]));
					ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARSCONFIRM, DIALOG_STYLE_MSGBOX, "Rental Jobs", tstr, "Rental", "Batal");
				}
			}
		}
		return 1;
	}*/
	if(dialogid == DIALOG_RENTBIKES)
	{
		new renid = pData[playerid][pGetRENID];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 509;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(rnData[renid][rPrice]));
					ShowPlayerDialog(playerid, DIALOG_RENTAL_CONFIRM, DIALOG_STYLE_MSGBOX, "Rental Bikes", tstr, "Rental", "Batal");
				}
				case 1:
				{
					new modelid = 481;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(rnData[renid][rPrice]));
					ShowPlayerDialog(playerid, DIALOG_RENTAL_CONFIRM, DIALOG_STYLE_MSGBOX, "Rental Bikes", tstr, "Rental", "Batal");
				}
				case 2:
				{
					new modelid = 510;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(rnData[renid][rPrice]));
					ShowPlayerDialog(playerid, DIALOG_RENTAL_CONFIRM, DIALOG_STYLE_MSGBOX, "Rental Bikes", tstr, "Rental", "Batal");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_RENTBOAT)
	{
		new renid = pData[playerid][pGetRENID];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new modelid = 453;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(rnData[renid][rPrice]));
					ShowPlayerDialog(playerid, DIALOG_RENTAL_CONFIRM, DIALOG_STYLE_MSGBOX, "Rental Boat", tstr, "Rental", "Batal");
				}
				case 1:
				{
					new modelid = 454;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(rnData[renid][rPrice]));
					ShowPlayerDialog(playerid, DIALOG_RENTAL_CONFIRM, DIALOG_STYLE_MSGBOX, "Rental Boat", tstr, "Rental", "Batal");
				}
				case 2:
				{
					new modelid = 484;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(rnData[renid][rPrice]));
					ShowPlayerDialog(playerid, DIALOG_RENTAL_CONFIRM, DIALOG_STYLE_MSGBOX, "Rental Boat", tstr, "Rental", "Batal");
				}
				case 3:
				{
					new modelid = 595;
					new tstr[128];
					pData[playerid][pBuyPvModel] = modelid;
					format(tstr, sizeof(tstr), ""WHITE_E"Anda akan menyewa kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s / one days", GetVehicleModelName(modelid), FormatMoney(rnData[renid][rPrice]));
					ShowPlayerDialog(playerid, DIALOG_RENTAL_CONFIRM, DIALOG_STYLE_MSGBOX, "Rental Boat", tstr, "Rental", "Batal");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_RENTAL_CONFIRM)
	{
		new modelid = pData[playerid][pBuyPvModel], renid = pData[playerid][pGetRENID];
		if(response)
		{
			if(modelid <= 0)
				return Error(playerid, "Invalid model id.");

			new cost = rnData[renid][rPrice];
			if(pData[playerid][pMoney] < cost)
				return ErrorMsg(playerid, "Anda tidak memiliki cukup Uang");

			new count = 0, limit = MAX_PLAYER_VEHICLE + pData[playerid][pVip];
			foreach(new ii : PVehicles)
			{
				if(pvData[ii][cOwner] == pData[playerid][pID])
					count++;
			}
			if(count >= limit)
			{
				ErrorMsg(playerid, "Slot Kendaraan anda sudah penuh");
				return 1;
			}
			GivePlayerMoneyEx(playerid, -cost);
			new cQuery[1024];
			new Float:x,Float:y,Float:z, Float:a;
			new pid, model, color1, color2, rental;

			pid = pData[playerid][pID];
			color1 = 1;
			color2 = 2;
			model = modelid;
			x = rnData[renid][rVehposX];
			y = rnData[renid][rVehposY];
			z = rnData[renid][rVehposZ]+0.5;
			a = rnData[renid][rVehposA];
			rental = gettime() + (1 * 86400);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "INSERT INTO `vehicle` (`owner`, `model`, `color1`, `color2`, `price`, `x`, `y`, `z`, `a`, `rental`) VALUES (%d, %d, %d, %d, %d, '%f', '%f', '%f', '%f', '%d')", pData[playerid][pID], model, color1, color2, cost, x, y, z, a, rental);
			mysql_tquery(g_SQL, cQuery, "OnVehRenidPV", "ddddddffffd", playerid, pid, model, color1, color2, cost, x, y, z, a, rental);
			return 1;
		}
		else
		{
			pData[playerid][pBuyPvModel] = 0;
		}
		return 1;
	}
	if(dialogid == DIALOG_RENT_JOBCARSCONFIRM)
	{
		new modelid = pData[playerid][pBuyPvModel];
		if(response)
		{
			if(modelid <= 0) return Error(playerid, "Invalid model id.");
			new cost = GetVehicleCost(modelid);
			if(pData[playerid][pMoney] < 500)
			{
				ErrorMsg(playerid, "Anda tidak memiliki cukup Uang");
				return 1;
			}
			new count = 0, limit = MAX_PLAYER_VEHICLE + pData[playerid][pVip];
			foreach(new ii : PVehicles)
			{
				if(pvData[ii][cOwner] == pData[playerid][pID])
					count++;
			}
			if(count >= limit)
			{
				ErrorMsg(playerid, "Slot Kendaraan anda sudah penuh");
				return 1;
			}
			GivePlayerMoneyEx(playerid, -500);
			new cQuery[1024];
			new Float:x,Float:y,Float:z, Float:a;
			new pid, model, color1, color2, rental;

			pid = pData[playerid][pID];
			color1 = 0;
			color2 = 0;
			model = modelid;

			x = 1062.3739;
			y = -1757.9178;
			z = 13.1220;
			a = 269.8789;

			rental = gettime() + (1 * 86400);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "INSERT INTO `vehicle` (`owner`, `model`, `color1`, `color2`, `price`, `x`, `y`, `z`, `a`, `rental`) VALUES (%d, %d, %d, %d, %d, '%f', '%f', '%f', '%f', '%d')", pData[playerid][pID], model, color1, color2, cost, x, y, z, a, rental);
			mysql_tquery(g_SQL, cQuery, "OnVehRentPV", "ddddddffffd", playerid, pid, model, color1, color2, cost, x, y, z, a, rental);
			return 1;
		}
		else
		{
			pData[playerid][pBuyPvModel] = 0;
		}
	}
	if(dialogid == DIALOG_BUYPVCP_CONFIRM)
	{
		new modelid = pData[playerid][pBuyPvModel];
		if(response)
		{
			if(modelid <= 0) return Error(playerid, "Invalid model id.");
			new cost = GetVehicleCost(modelid);
			if(pData[playerid][pMoney] < cost)
			{
				ErrorMsg(playerid, "Anda tidak memiliki cukup Uang");
				return 1;
			}
			new count = 0, limit = MAX_PLAYER_VEHICLE + pData[playerid][pVip];
			foreach(new ii : PVehicles)
			{
				if(pvData[ii][cOwner] == pData[playerid][pID])
					count++;
			}
			if(count >= limit)
			{
				ErrorMsg(playerid, "Slot Kendaraan anda sudah penuh");
				return 1;
			}
			GivePlayerMoneyEx(playerid, -cost);
			new cQuery[1024];
			new Float:x,Float:y,Float:z, Float:a;
			new pid, model, color1, color2;

			pid = pData[playerid][pID];
			color1 = 0;
			color2 = 0;
			model = modelid;
			
			x = 1062.3739;
			y = -1757.9178;
			z = 13.1220;
			a = 269.8789;

			mysql_format(g_SQL, cQuery, sizeof(cQuery), "INSERT INTO `vehicle` (`owner`, `model`, `color1`, `color2`, `price`, `x`, `y`, `z`, `a`) VALUES (%d, %d, %d, %d, %d, '%f', '%f', '%f', '%f')", pData[playerid][pID], model, color1, color2, cost, x, y, z, a);
			mysql_tquery(g_SQL, cQuery, "OnVehBuyPV", "ddddddffff", playerid, pid, model, color1, color2, cost, x, y, z, a);
			return 1;
		}
		else
		{
			pData[playerid][pBuyPvModel] = 0;
		}
	}
	if(dialogid == DIALOG_BUYPVCP_VIPCONFIRM)
	{
		new modelid = pData[playerid][pBuyPvModel];
		if(response)
		{
			if(modelid <= 0) return Error(playerid, "Invalid model id.");
			new cost = GetVipVehicleCost(modelid);
			if(pData[playerid][pGold] < cost)
			{
				ErrorMsg(playerid, "Anda tidak memiliki cukup Uang");
				return 1;
			}
			new count = 0, limit = MAX_PLAYER_VEHICLE + pData[playerid][pVip];
			foreach(new ii : PVehicles)
			{
				if(pvData[ii][cOwner] == pData[playerid][pID])
					count++;
			}
			if(count >= limit)
			{
				ErrorMsg(playerid, "Slot Kendaraan anda sudah penuh");
				return 1;
			}
			pData[playerid][pGold] -= cost;
			new cQuery[1024];
			new Float:x,Float:y,Float:z, Float:a;
			new pid, model, color1, color2;

			pid = pData[playerid][pID];
			color1 = 0;
			color2 = 0;
			model = modelid;

			x = 1280.17;
			y = -1300.65;
			z = 13.34;
			a = 177.06;

			mysql_format(g_SQL, cQuery, sizeof(cQuery), "INSERT INTO `vehicle` (`owner`, `model`, `color1`, `color2`, `price`, `x`, `y`, `z`, `a`) VALUES (%d, %d, %d, %d, %d, '%f', '%f', '%f', '%f')", pData[playerid][pID], model, color1, color2, cost, x, y, z, a);
			mysql_tquery(g_SQL, cQuery, "OnVehBuyVIPPV", "ddddddffff", playerid, pid, model, color1, color2, cost, x, y, z, a);
			return 1;
		}
		else
		{
			pData[playerid][pBuyPvModel] = 0;
		}
	}
	/*if(dialogid == DIALOG_RENT_JOBCARSCONFIRM)
	{
		new deid = pData[playerid][pGetDEID];
		new modelid = pData[playerid][pBuyPvModel];
		if(response)
		{
			if(modelid <= 0) return Error(playerid, "Invalid model id.");
			new cost = pData[playerid][pGetDEIDPRICE];
			if(pData[playerid][pMoney] < cost)
			{
				ErrorMsg(playerid, "Anda tidak memiliki cukup Uang");
				return 1;
			}
			new count = 0, limit = MAX_PLAYER_VEHICLE + pData[playerid][pVip];
			foreach(new ii : PVehicles)
			{
				if(pvData[ii][cOwner] == pData[playerid][pID])
					count++;
			}
			if(count >= limit)
			{
				ErrorMsg(playerid, "Slot Kendaraan anda sudah penuh");
				return 1;
			}
			GivePlayerMoneyEx(playerid, -cost);
			new cQuery[1024];
			new Float:x,Float:y,Float:z, Float:a;
			new pid, model, color1, color2, rental;

			pid = pData[playerid][pID];
			color1 = 0;
			color2 = 0;
			model = modelid;

			x = drData[deid][dVehX];
			y = drData[deid][dVehY];
			z = drData[deid][dVehZ]+0.5;
			a = drData[deid][dVehA];
			rental = gettime() + (1 * 86400);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "INSERT INTO `vehicle` (`owner`, `model`, `color1`, `color2`, `price`, `x`, `y`, `z`, `a`, `rental`) VALUES (%d, %d, %d, %d, %d, '%f', '%f', '%f', '%f', '%d')", pData[playerid][pID], model, color1, color2, cost, x, y, z, a, rental);
			mysql_tquery(g_SQL, cQuery, "OnVehRentPV", "ddddddffffd", playerid, pid, model, color1, color2, cost, x, y, z, a, rental);
			return 1;
		}
		else
		{
			pData[playerid][pBuyPvModel] = 0;
		}
		return 1;
	}
	if(dialogid == DIALOG_BUYPVCP_CONFIRM)
	{
		new deid = pData[playerid][pGetDEID];
		new modelid = pData[playerid][pBuyPvModel];
		if(response)
		{
			if(modelid <= 0) return Error(playerid, "Invalid model id.");
			new cost = pData[playerid][pGetDEIDPRICE];
			if(pData[playerid][pMoney] < cost)
			{
				ErrorMsg(playerid, "Anda tidak memiliki cukup Uang");
				return 1;
			}
			new count = 0, limit = MAX_PLAYER_VEHICLE + pData[playerid][pVip];
			foreach(new ii : PVehicles)
			{
				if(pvData[ii][cOwner] == pData[playerid][pID])
					count++;
			}
			if(count >= limit)
			{
				ErrorMsg(playerid, "Slot Kendaraan anda sudah penuh");
				return 1;
			}
			GivePlayerMoneyEx(playerid, -cost);
			new cQuery[1024];
			new Float:x,Float:y,Float:z, Float:a;
			new pid, model, color1, color2;

			pid = pData[playerid][pID];
			color1 = 0;
			color2 = 0;
			model = modelid;

			x = drData[deid][dVehX];
			y = drData[deid][dVehY];
			z = drData[deid][dVehZ]+0.5;
			a = drData[deid][dVehA];
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "INSERT INTO `vehicle` (`owner`, `model`, `color1`, `color2`, `price`, `x`, `y`, `z`, `a`) VALUES (%d, %d, %d, %d, %d, '%f', '%f', '%f', '%f')", pData[playerid][pID], model, color1, color2, cost, x, y, z, a);
			mysql_tquery(g_SQL, cQuery, "OnVehBuyPV", "ddddddffff", playerid, pid, model, color1, color2, cost, x, y, z, a);
			return 1;
		}
		else
		{
			pData[playerid][pBuyPvModel] = 0;
		}
		return 1;
	}
	if(dialogid == DIALOG_BUYPVCP_VIPCONFIRM)
	{
		new deid = pData[playerid][pGetDEID];
		new modelid = pData[playerid][pBuyPvModel];
		if(response)
		{
			if(modelid <= 0) return Error(playerid, "Invalid model id.");
			new cost = GetVipVehicleCost(modelid);
			if(pData[playerid][pGold] < cost)
			{
				Error(playerid, "Gold anda tidak mencukupi.!");
				return 1;
			}
			new count = 0, limit = MAX_PLAYER_VEHICLE + pData[playerid][pVip];
			foreach(new ii : PVehicles)
			{
				if(pvData[ii][cOwner] == pData[playerid][pID])
					count++;
			}
			if(count >= limit)
			{
				ErrorMsg(playerid, "Slot Kendaraan anda sudah penuh");
				return 1;
			}
			pData[playerid][pGold] -= cost;
			new cQuery[1024];
			new Float:x,Float:y,Float:z, Float:a;
			new pid, model, color1, color2;

			pid = pData[playerid][pID];
			color1 = 0;
			color2 = 0;
			model = modelid;

			x = drData[deid][dVehX];
			y = drData[deid][dVehY];
			z = drData[deid][dVehZ]+0.5;
			a = drData[deid][dVehA];
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "INSERT INTO `vehicle` (`owner`, `model`, `color1`, `color2`, `price`, `x`, `y`, `z`, `a`) VALUES (%d, %d, %d, %d, %d, '%f', '%f', '%f', '%f')", pData[playerid][pID], model, color1, color2, cost, x, y, z, a);
			mysql_tquery(g_SQL, cQuery, "OnVehBuyVIPPV", "ddddddffff", playerid, pid, model, color1, color2, cost, x, y, z, a);
			return 1;
		}
		else
		{
			pData[playerid][pBuyPvModel] = 0;
		}
		return 1;
	}
	if(dialogid == DIALOG_SALARY)
	{
		if(!response) 
		{
			ListPage[playerid]--;
			if(ListPage[playerid] < 0)
			{
				ListPage[playerid] = 0;
				return 1;
			}
		}
		else
		{
			ListPage[playerid]++;
		}
		
		DisplaySalary(playerid);
		return 1;
	}*/
	if(dialogid == DIALOG_PAYCHECK)
	{
		if(response)
		{
			if(pData[playerid][pPaycheck] < 3600) return Error(playerid, "Sekarang belum waktunya anda mengambil paycheck.");
			
			new query[512];
			mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM salary WHERE owner='%d' ORDER BY id ASC LIMIT 30", pData[playerid][pID]);
			new Cache:result = mysql_query(g_SQL, query);
			new rows = cache_num_rows();
			if(rows) 
			{
				new list[2000], date[30], info[16], money, totalduty, gajiduty, totalsal, total, pajak, hasil;
				
				totalduty = pData[playerid][pOnDutyTime];
				for(new i; i < rows; ++i)
				{
					cache_get_value_name(i, "info", info);
					cache_get_value_name(i, "date", date);
					cache_get_value_name_int(i, "money", money);
					totalsal += money;
				}
				
				if(totalduty > 600)
				{
					gajiduty = 600;
				}
				else
				{
					gajiduty = totalduty;
				}
				total = gajiduty + totalsal;
				pajak = total / 100 * 10;
				hasil = total - pajak;
				
				format(list, sizeof(list), "Total gaji yang masuk ke rekening bank anda adalah: "LG_E"%s", FormatMoney(hasil));
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Paycheck", list, "Close", "");
				pData[playerid][pBankMoney] += hasil;
				Server_MinMoney(hasil);
				pData[playerid][pPaycheck] = 0;
				pData[playerid][pOnDutyTime] = 0;
				mysql_format(g_SQL, query, sizeof(query), "DELETE FROM salary WHERE owner='%d'", pData[playerid][pID]);
				mysql_tquery(g_SQL, query);
			}
			else
			{
				new list[2000], totalduty, gajiduty, total, pajak, hasil;
				
				totalduty = pData[playerid][pOnDutyTime];
				
				if(totalduty > 600)
				{
					gajiduty = 600;
				}
				else
				{
					gajiduty = totalduty;
				}
				total = gajiduty;
				pajak = total / 100 * 10;
				hasil = total - pajak;
				
				format(list, sizeof(list), "Total gaji yang masuk ke rekening bank anda adalah: "LG_E"%s", FormatMoney(hasil));
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Paycheck", list, "Close", "");
				pData[playerid][pBankMoney] += hasil;
				Server_MinMoney(hasil);
				pData[playerid][pPaycheck] = 0;
				pData[playerid][pOnDutyTime] = 0;
			}
			cache_delete(result);
		}
	}
	if(dialogid == DIALOG_SWEEPER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(pData[playerid][pSideJobTime] > 0)
		{
			Error(playerid, "Anda harus menunggu "GREY2_E"%d "WHITE_E"detik lagi.", pData[playerid][pSideJobTime]);
			RemovePlayerFromVehicle(playerid);
			SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
			return 1;
		}
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					SetPlayerCheckpoint(playerid, sweperpoint1, 7.0);
					SweeperCP[playerid] = 0;
				}
				case 1:
				{
					SetPlayerCheckpoint(playerid, sweper1, 7.0);
					SweeperCP[playerid] = 0;
				}
			}
			pData[playerid][pSweeperRoute] = listitem+1;
			pData[playerid][pSideJob] = 3;
			Info(playerid, "Anda akan memulai pekerjaan sweeper ikuti checkpoint yang telah di tandai");

		}
		else
		{
			RemovePlayerFromVehicle(playerid);
			SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);			
		}
	}
	if(dialogid == DIALOG_BUS)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(pData[playerid][pSideJobTime] > 0)
		{
			Error(playerid, "Anda harus menunggu "GREY2_E"%d "WHITE_E"detik lagi.", pData[playerid][pSideJobTime]);
			RemovePlayerFromVehicle(playerid);
			SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
			return 1;
		}
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					SetPlayerCheckpoint(playerid, buspointmarket1, 7.0);
				}
				case 1:
				{
					SetPlayerCheckpoint(playerid, buspointelcor1, 7.0);
				}
			}
			pData[playerid][pBusRoute] = listitem+1;
			pData[playerid][pSideJob] = 2;
			Info(playerid, "Kamu berhasil memilih route bus %d, Ikuti checkpoint yang telah ditandai!", pData[playerid][pBusRoute]);
			InfoMsg(playerid, "Ikuti Checkpoint!");
		}
		else
		{
			RemovePlayerFromVehicle(playerid);
			SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
		}
	}
	if(dialogid == DIALOG_TRASHMASTER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(response)
		{
			if(pData[playerid][pSideJobTime] > 0)
			{
				Error(playerid, "Anda harus menunggu "GREY2_E"%d "WHITE_E"detik lagi.", pData[playerid][pSideJobTime]);
				RemovePlayerFromVehicle(playerid);
				SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
				return 1;
			}
			
			pData[playerid][pSideJob] = 5;
			Info(playerid, "Kamu memulai sidejob trash master, pergi untuk mencari tong sampah yang penuh di sekeliling kota");
		}
		else
		{
			RemovePlayerFromVehicle(playerid);
			SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
		}
	}
	if(dialogid == DIALOG_AIRDROP)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_AIRDROP, DIALOG_STYLE_INPUT, "Airdrop", "{FFFFFF}Masukkan Player (ID):", "Give", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				new string[200];
				format(string, sizeof(string), "{FFFFFF}Nama: %s\nNomor: %d\nApakah anda ingin menerimanya?", pData[playerid][pName], pData[playerid][pPhone]);
				ShowPlayerDialog(otherid, DIALOG_AIRDROPACCEPT, DIALOG_STYLE_MSGBOX, "Airdrop", string, "Accept", "Cancel");
				//AddPlayerContact(playerid, pData[otherid][pName], pData[otherid][pPhone]);
				SuccesMsg(playerid, "Anda telah mengirim airdrop kepada player lain");
				SetPVarInt(playerid, "Airdropacc", otherid);
			}
			else ErrorMsg(playerid, "PlayerID yang dimasukkan tidak valid atau tidak berada di sekitar.");
		}
	}
	if(dialogid == DIALOG_AIRDROPACCEPT)
	{
		new str[200], otherid = GetPVarInt(playerid, "Airdropacc");
		if(response)
		{
			AddPlayerContact(playerid, pData[otherid][pName], pData[otherid][pPhone]);
			SuccesMsg(playerid, "Kontak anda berhasil di perbaharui");
			format(str, sizeof(str), "%s telah menerima perminta airdrop anda", pData[playerid][pName]);
			SuccesMsg(otherid, str);
		}
		else
		{
			format(str, sizeof(str), "%s telah menolak permintaan airdrop anda", pData[playerid][pName]);
			InfoMsg(otherid, str);
		}
	}
	if(dialogid == DIALOG_TOGGLEPHONE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pUsePhone] = 1;
					SuccesMsg(playerid, "Berhasil mengaktifkan Telephone");
					return 0;
				}
				case 1:
				{
					pData[playerid][pUsePhone] = 0;
					SuccesMsg(playerid, "Berhasil menonaktifkan Telephone");
					return 0;
				}
				case 2:
				{
					new gstr[256];
					format(gstr,sizeof(gstr),"{C6E2FF}Pemilik: %s\nNomor telepon: %d\nNama model: Iphone 15\nNomor serial: AS6R8127V1JKW\nIMEI (slot 1): 2374236342\nIMEI (slot 2): 8734563737", pData[playerid][pName], pData[playerid][pPhone]);
				}
			}
		}
	}
	if(dialogid == DIALOG_PHONE_SENDSMS)
	{
		if(response)
		{
			new ph = strval(inputtext);
			if (isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_PHONE_SENDSMS, DIALOG_STYLE_INPUT, "Nomor Handphone", "Masukan nomor hp yang ingin anda kirim pesan:", "Lanjut", "Keluar");

			foreach(new ii : Player)
			{
				if(pData[ii][pPhone] == ph)
				{
					if(ii == INVALID_PLAYER_ID || !IsPlayerConnected(ii))
						return ShowPlayerDialog(playerid, DIALOG_PHONE_SENDSMS, DIALOG_STYLE_INPUT, "Nomor Handphone", "Nomor tersebut offline\nMasukan nomor hp yang ingin anda kirim pesan:", "Lanjut", "Keluar");
					
					ShowPlayerDialog(playerid, DIALOG_PHONE_TEXTSMS, DIALOG_STYLE_INPUT, "Masukan Pesan", "Bermasalah: Silahkan masukan pesan yang ingin anda kirim", "Kirim", "Keluar");
					pData[playerid][pContact] = ph;
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_PHONE_DIALUMBER)
	{
		if (response)
		{
			if (isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_PHONE_DIALUMBER, DIALOG_STYLE_INPUT, "Phone", "Masukan nomor yang akan anda hubungi", "Kirim", "Kembali");
			 
			//format(string, 16, "%d", strval(inputtext));
			callcmd::call(playerid, inputtext);
		}
		return 1;
	}
	if(dialogid == DIALOG_TOGGLEPHONE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pUsePhone] = 1;
					SuccesMsg(playerid, "Berhasil mengaktifkan Handphone");
				}
				case 1:
				{
					pData[playerid][pUsePhone] = 0;
					SuccesMsg(playerid, "Berhasil menonaktifkan Handphone");
				}
				case 2:
				{
					new gstr[256];
					format(gstr,sizeof(gstr),"Pemilik: %s\nNomor Telepon: %d\nNama model: Iphone 20Pro\nNomor serial: AS6R8127V1JKW\nIMEI (slot 1): 2374236342\nIMEI (slot 2): 8734563737", pData[playerid][pName], pData[playerid][pPhone]);
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Tentang Ponsel", gstr, "Tutup","");
				}
			}
		}
	}
	if(dialogid == DIALOG_PHONE_TEXTSMS)
	{
		if (response)
		{
			if (isnull(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_PHONE_TEXTSMS, DIALOG_STYLE_INPUT, "Masukan Pesan", "Bermasalah: Silahkan masukan pesan yang ingin anda kirim", "Kirim", "Keluar");
			
			new ph = pData[playerid][pContact];
			if(pData[playerid][pPhoneCredit] <= 0) return Error(playerid, "Anda tidak memiliki Ponsel credits!");
			if(pData[playerid][pInjured] != 0) return Error(playerid, "You cant do at this time.");

			if(GetSignalNearest(playerid) == 0)
				return Error(playerid, "Perangkat anda tidak mendapatkan sinyal di wilayah ini.");
			
			foreach(new ii : Player)
			{
				if(pData[ii][pPhone] == ph)
				{
					if(pData[ii][pUsePhone] == 0) return Error(playerid, "Tidak dapat SMS, Ponsel tersebut yang dituju sedang Offline");

					if(GetSignalNearest(ii) == 0) return Error(playerid, "Ponsel tersebut sedang mengalami gangguan sinyal");

					if(IsPlayerInRangeOfPoint(ii, 20, 2179.9531,-1009.7586,1021.6880))
						return Error(playerid, "Anda tidak dapat melakukan ini, orang yang dituju sedang berada di OOC Zone");

					if(ii == INVALID_PLAYER_ID || !IsPlayerConnected(ii)) return Error(playerid, "This number is not actived!");
					SendClientMessageEx(playerid, COLOR_YELLOW, "[SMS to %d]"WHITE_E" %s", ph, inputtext);
					SendClientMessageEx(ii, COLOR_YELLOW, "[SMS from %d]"WHITE_E" %s", pData[playerid][pPhone], inputtext);
					Info(ii, "Gunakan "LB_E"'@<text>' "WHITE_E"untuk membalas SMS!");
					PlayerPlaySound(ii, 6003, 0,0,0);
					pData[ii][pSMS] = pData[playerid][pPhone];
					
					pData[playerid][pPhoneCredit] -= 1;
					return 1;
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_PHONE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new str[128];
					format(str, sizeof(str), "House Tax\nDealer Tax\nVending Tax");
					ShowPlayerDialog(playerid, MYTAX_MENU, DIALOG_STYLE_LIST, "MyTax Application", str, "Select", "No");
				}
				case 1:
				{
					return callcmd::mybill(playerid);
				}
				case 2:
				{
					DisplayContact(playerid);
				}
				case 3:
				{
					ShowPlayerDialog(playerid, DIALOG_MBANK, DIALOG_STYLE_LIST, "{bab8a2}MBanking", "Check Balance\nTransfer Money\nSign Paycheck", "Select", "Back");
				}
				case 4:
				{
					new string[512], twitter[64], gps[64], ads[64];
					if(pData[playerid][pTwtIns] < 1)
					{
						twitter = ""RED_E"Install";
					}
					else
					{
						twitter = ""LG_E"Terinstall";
					}
					if(pData[playerid][pGpsIns] < 1)
					{
						gps = ""RED_E"Install";
					}
					else
					{
						gps = ""LG_E"Terinstall";
					}
					if(pData[playerid][pAonaIns] < 1)
					{
						ads = ""RED_E"Install";
					}
					else
					{
						ads = ""LG_E"Terinstall";
					}
					format(string, sizeof(string),"Aplikasi\tStatus\n{7fffd4}Twitter ( 6Mb )\t%s\n{bab8a2}Gps ( 8Mb )\t%s\n{fcba03}Ads Of News Agency ( 3Mb )\t%s", twitter, gps, ads);
					ShowPlayerDialog(playerid, DIALOG_APPSTORE, DIALOG_STYLE_TABLIST_HEADERS, "App Store",string,"Download","Back");
				}
				case 5:
				{
					if(pData[playerid][pGpsIns] == 1)
					{
						ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "GPS Menu", "Disable GPS\nPublic GPS\nPersonal GPS\nNearest GPS\nCity Hall\nDriving School\nBank Central\nValet Apartement\nJobs Location", "Select", "Close");
					}
					else if(pData[playerid][pTwtIns] == 1)
					{
						new str[128];
						format(str, sizeof(str), "Set Username\nPost Message");
						ShowPlayerDialog(playerid, TWITTER_MENU, DIALOG_STYLE_LIST, "Twitter Application", str, "Select", "No");
					}
					else if(pData[playerid][pAonaIns] == 1)
					{
						ShowAdsLog(playerid);
					}
					else if(pData[playerid][pGpsIns] == 1 && pData[playerid][pTwtIns] == 1 && pData[playerid][pAonaIns] == 0)
					{
						ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "GPS Menu", "Disable GPS\nPublic GPS\nPersonal GPS\nNearest GPS\nCity Hall\nDriving School\nBank Central\nValet Apartement\nJobs Location", "Select", "Close");
					}
					else if(pData[playerid][pGpsIns] == 0 && pData[playerid][pTwtIns] == 1 && pData[playerid][pAonaIns] == 1)
					{
						ShowAdsLog(playerid);
					}
					else if(pData[playerid][pGpsIns] == 1 && pData[playerid][pTwtIns] == 0 && pData[playerid][pAonaIns] == 1)
					{
						ShowAdsLog(playerid);
					}
					else if(pData[playerid][pGpsIns] == 1 && pData[playerid][pTwtIns] == 1 && pData[playerid][pAonaIns] == 1)
					{
						new str[128];
						format(str, sizeof(str), "Set Username\nPost Message");
						ShowPlayerDialog(playerid, TWITTER_MENU, DIALOG_STYLE_LIST, "Twitter Application", str, "Select", "No");
					}
				}
				case 6:
				{
					if(pData[playerid][pGpsIns] == 1 && pData[playerid][pTwtIns] == 1 && pData[playerid][pAonaIns] == 0)
					{
						new str[128];
						format(str, sizeof(str), "Set Username\nPost Message");
						ShowPlayerDialog(playerid, TWITTER_MENU, DIALOG_STYLE_LIST, "Twitter Application", str, "Select", "No");
					}
					if(pData[playerid][pGpsIns] == 0 && pData[playerid][pTwtIns] == 1 && pData[playerid][pAonaIns] == 1)
					{
						new str[128];
						format(str, sizeof(str), "Set Username\nPost Message");
						ShowPlayerDialog(playerid, TWITTER_MENU, DIALOG_STYLE_LIST, "Twitter Application", str, "Select", "No");
					}
					if(pData[playerid][pGpsIns] == 1 && pData[playerid][pTwtIns] == 0 && pData[playerid][pAonaIns] == 1)
					{
						ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "GPS Menu", "Disable GPS\nPublic GPS\nPersonal GPS\nNearest GPS\nCity Hall\nDriving School\nBank Central\nValet Apartement\nJobs Location", "Select", "Close");
					}
					if(pData[playerid][pGpsIns] == 1 && pData[playerid][pTwtIns] == 1 && pData[playerid][pAonaIns] == 1)
					{
						ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "GPS Menu", "Disable GPS\nPublic GPS\nPersonal GPS\nNearest GPS\nCity Hall\nDriving School\nBank Central\nValet Apartement\nJobs Location", "Select", "Close");
					}
				}
				case 7:
				{
					ShowAdsLog(playerid);
				}
			}
		}
	}
	if(dialogid == DIALOG_APPSTORE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pTwtIns] > 0)
						return Error(playerid, "You have twitter installed");

					if(pData[playerid][pPhoneCredit] <= 6) 
						return Error(playerid, "Phone Credit Not Enaugh!");

					SetTimerEx("DownloadTwitter", 10000, false, "i", playerid);
					GameTextForPlayer(playerid, "Downloading...", 10000, 4);
				}
				case 1:
				{
					if(pData[playerid][pGpsIns] > 0)
						return Error(playerid, "You have gps installed");

					if(pData[playerid][pPhoneCredit] <= 8) 
						return Error(playerid, "Phone Credit Not Enaugh!");

					SetTimerEx("DownloadGps", 10000, false, "i", playerid);
					GameTextForPlayer(playerid, "Downloading...", 10000, 4);
				}
				case 2:
				{
					if(pData[playerid][pAonaIns] > 0)
						return Error(playerid, "You have gps installed");

					if(pData[playerid][pPhoneCredit] <= 3) 
						return Error(playerid, "Phone Credit Not Enaugh!");

					SetTimerEx("DownloadAona", 10000, false, "i", playerid);
					GameTextForPlayer(playerid, "Downloading...", 10000, 4);
				}
			}
		}
		else
		{

		}
	}
	if(dialogid == DIALOG_MBANK)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new str[200];
					format(str, sizeof(str), "{F6F6F6}You have "LB_E"%s {F6F6F6}in your bank account.", FormatMoney(pData[playerid][pBankMoney]));
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""LB_E"MBanking", str, "Close", "");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_BANKREKENING, DIALOG_STYLE_INPUT, ""LB_E"MBanking", "Masukan jumlah uang:", "Transfer", "Cancel");
				}
				case 2:
				{
					DisplayPaycheck(playerid);
				}
			}
		}
		else
		{

		}
	}
	if(dialogid == MYTAX_MENU)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(GetHousesPaytax(playerid) <= 0)
						return Error(playerid, "Kamu tidak memiliki rumah.");

					new id, count = GetHousesPaytax(playerid), mission[2024], lstr[3024], type[128];
					
					strcat(mission,"ID\tTYPE\tLOCATION\tEXPIRED\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnHousesPaytaxID(playerid, itt);
						if(hData[id][hType] == 1)
						{
							type = "Low";
						}
						else if(hData[id][hType] == 2)
						{
							type = "Medium";
						}
						else if(hData[id][hType] == 3)
						{
							type = "High";
						}
						else
						{
							type = "Unknown";
						}
	
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", id, type, GetLocation(hData[id][hExtposX], hData[id][hExtposY], hData[id][hExtposZ]), ReturnTimelapse(gettime(), hData[id][hVisit]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", id, type, GetLocation(hData[id][hExtposX], hData[id][hExtposY], hData[id][hExtposZ]), ReturnTimelapse(gettime(), hData[id][hVisit]));	
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS,"Houses Tax",mission,"Close", "");
				}
				case 1:
				{
					if(GetDealerPaytax(playerid) <= 0)
						return Error(playerid, "Kamu tidak memiliki Dealer.");

					new id, count = GetDealerPaytax(playerid), mission[2024], lstr[3024], type[128];
					
					strcat(mission,"ID\tTYPE\tLOCATION\tEXPIRED\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnDealerPaytaxID(playerid, itt);
						if(drData[id][dType] == 1)
						{
							type = "Bikes Vehicles";
						}
						else if(drData[id][dType] == 2)
						{
							type = "Cars";
						}
						else if(drData[id][dType] == 3)
						{
							type = "Unique Cars";
						}
						else if(drData[id][dType] == 4)
						{
							type = "Job Cars";
						}
						else if(drData[id][dType] == 5)
						{
							type = "Rental Jobs";
						}
	
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", id, type, GetLocation(drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]), ReturnTimelapse(gettime(), drData[id][dVisit]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", id, type, GetLocation(drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]), ReturnTimelapse(gettime(), drData[id][dVisit]));	
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS,"Dealer Tax",mission,"Close", "");
				}
				case 2:
				{
					if(GetVendingPaytax(playerid) <= 0)
						return Error(playerid, "Kamu tidak memiliki Vending Machine.");

					new id, count = GetVendingPaytax(playerid), mission[2024], lstr[3024];
					
					strcat(mission,"ID\tLOCATION\tEXPIRED\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnVendingPaytaxID(playerid, itt);
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\n", id, GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), ReturnTimelapse(gettime(), drData[id][dVisit]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\n", id, GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), ReturnTimelapse(gettime(), drData[id][dVisit]));	
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS,"Vending Tax",mission,"Select","Cancel");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_ADDCTRESPONSE)
	{
		if(!response)
			return 1;
		{
			ShowPlayerDialog(playerid, DIALOG_ADDCT, DIALOG_STYLE_INPUT, "Add Contact", "Masukkan nomor kontak baru yang ingin kamu tambahkan:", "Add", "No");
		}
	}
	if(dialogid == DIALOG_ADDCT)
	{
		if(Player_ContactCount(playerid) + 1 > 20)
			return Error(playerid, "Kamu tidak dapat menyimpan lebih dari 20 contact");

		if(response)
		{
			new number;
			if(sscanf(inputtext, "d", number))
            {
				new mstr[512];
				format(mstr,sizeof(mstr),"NOTE: Nomor Contact tidak di perbolehkan kosong!");
				ShowPlayerDialog(playerid, DIALOG_ADDCT, DIALOG_STYLE_INPUT,"Add Contact", mstr,"Change","Back");
			}
			else if(number < 1 || number > 999999)
			{
				new mstr[512];
				format(mstr,sizeof(mstr),"NOTE: Nomor Contact harus 1 sampai 6 karakter.");
				ShowPlayerDialog(playerid, DIALOG_ADDCT, DIALOG_STYLE_INPUT,"Add Contact", mstr,"Change","Back");
			}
			else
			{
				AddPlayerContact(playerid, "No Name", number);
				Info(playerid, "Nomor Contact (%d) berhasil ditambahkan", number);
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_EDITCTRESPONSE)
	{
		if(!response)
			return 1;
		{
			switch(listitem+1)
			{
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_ADDCT, DIALOG_STYLE_INPUT, "Add Contact", "Masukkan nomor kontak baru yang ingin kamu tambahkan:", "Add", "No");
				}
				case 2..50:
				{
					SetPVarInt(playerid, "ClickedContact", ReturnPlayerContactID(playerid, (listitem)));
					ShowPlayerDialog(playerid, DIALOG_EDITCTMENU, DIALOG_STYLE_LIST, "Contact Menu", "Edit Name\nEdit Number\nCall Contact\nSMS Contact\nShare Lock\nDelete Contact", "Select", "Cancel");
				}
			}
		}
	}
	if(dialogid == DIALOG_EDITCTMENU)
	{
		new dbid = GetPVarInt(playerid, "ClickedContact");
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new query[512];
					mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM phonebook WHERE id='%d' ORDER BY id ASC LIMIT 30", dbid);
					new Cache:result = mysql_query(g_SQL, query);
					new rows = cache_num_rows();

					if(rows)
					{
						new cname[40], string[1024];
						for(new i; i < rows; ++i)
					    {
							cache_get_value_name(i, "cname", cname);

							format(string, sizeof(string), "Contact Name: %s\ntulis nama baru yang ingin anda ubah untuk contact ini", cname);
						}
						ShowPlayerDialog(playerid, DIALOG_EDITNAMECT, DIALOG_STYLE_INPUT, "Edit Contact Name", string, "Yes", "No");
					}
					cache_delete(result);
				}
				case 1:
				{
					new query[512];
					mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM phonebook WHERE id='%d' ORDER BY id ASC LIMIT 30", dbid);
					new Cache:result = mysql_query(g_SQL, query);
					new rows = cache_num_rows();

					if(rows)
					{
						new cnumber, string[1024];
						for(new i; i < rows; ++i)
					    {
							cache_get_value_name_int(i, "cnumber", cnumber);
							
							format(string, sizeof(string), "Contact Number: %d\ntulis nomor baru yang ingin anda ubah untuk contact ini", cnumber);
						}
						ShowPlayerDialog(playerid, DIALOG_EDITNUMBERCT, DIALOG_STYLE_INPUT, "Edit Contact Number", string, "Yes", "No");
					}
					cache_delete(result);
				}
				case 2:
				{
					new query[512];
					mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM phonebook WHERE id='%d' ORDER BY id ASC LIMIT 30", dbid);
					new Cache:result = mysql_query(g_SQL, query);
					new rows = cache_num_rows();

					if(rows)
					{
						new cnumber;
						for(new i; i < rows; ++i)
					    {
							cache_get_value_name_int(i, "cnumber", cnumber);

							new ph = cnumber;

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

								for(new x = 0; x < 27; x++)
								{
									PlayerTextDrawShow(playerid, GwTelpon[playerid][x]);
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

										for(new x = 0; x < 27; x++)
										{
											PlayerTextDrawShow(playerid, GwTelpon[playerid][x]);
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

										for(new x = 0; x < 27; x++)
										{
											PlayerTextDrawShow(playerid, GwTelpon[playerid][x]);
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

										for(new x = 0; x < 27; x++)
										{
											PlayerTextDrawShow(playerid, GwTelpon[playerid][x]);
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

										for(new x = 0; x < 27; x++)
										{
											PlayerTextDrawShow(playerid, GwTelpon[playerid][x]);
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

										for(new x = 0; x < 29; x++)
										{
											PlayerTextDrawShow(ii, DiaTelpon[playerid][x]);
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

										for(new x = 0; x < 27; x++)
										{
											PlayerTextDrawShow(playerid, GwTelpon[playerid][x]);
										}
										PlayerTextDrawSetString(playerid, GwTelpon[playerid][24], "Nomer Non Actived");
										SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
										RemovePlayerAttachedObject(playerid, 9);
										CancelSelectTextDraw(playerid);
										Info(playerid, "Gunakan {FFFF00}'/cursor' {FFFFFF}untuk mengembalikan fungsi klik");	
										return 1;
									}
								}
							}
							cache_delete(result);
						}
					}
				}
				case 3:
				{
					new query[512];
					mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM phonebook WHERE id='%d' ORDER BY id ASC LIMIT 30", dbid);
					new Cache:result = mysql_query(g_SQL, query);
					new rows = cache_num_rows();

					if(rows)
					{
						new cnumber, string[1024];
						for(new i; i < rows; ++i)
					    {
							cache_get_value_name_int(i, "cnumber", cnumber);
							format(string, sizeof(string), "SMS To: %d\n\nTulis pesan yang ingin kamu kirim ke nomor diatas", cnumber);
						}
						ShowPlayerDialog(playerid, DIALOG_SENDMSGCT, DIALOG_STYLE_INPUT, "SMS Contact", string, "Send", "Cancel");
					}
					cache_delete(result);
				}
				case 4:
				{
					new query[512];
					mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM phonebook WHERE id='%d' ORDER BY id ASC LIMIT 30", dbid);
					new Cache:result = mysql_query(g_SQL, query);
					new rows = cache_num_rows();

					if(rows)
					{
						new cnumber;
						for(new i; i < rows; ++i)
					    {
							cache_get_value_name_int(i, "cnumber", cnumber);

							new ph = cnumber;
							if(GetSignalNearest(playerid) == 0)
								return Error(playerid, "Ponsel anda tidak mendapatkan sinyal di wilayah ini.");

							if(ph == pData[playerid][pPhone]) 
								return Error(playerid, "Nomor sedang sibuk!");

							foreach(new ii : Player)
							{
								if(pData[ii][pPhone] == ph)
								{
									if(pData[ii][IsLoggedIn] == false || !IsPlayerConnected(ii)) 
										return Error(playerid, "This number is not actived!");

									if(pData[ii][pUsePhone] == 0) 
										return Error(playerid, "Tidak dapat share loc, Ponsel tersebut yang dituju sedang Offline");
									
									if(IsPlayerInRangeOfPoint(ii, 20, 2179.9531,-1009.7586,1021.6880))
										return Error(playerid, "Anda tidak dapat melakukan ini, orang yang dituju sedang berada di OOC Zone");

									if(GetSignalNearest(ii) == 0)
										return Error(playerid, "Ponsel tersebut sedang mengalami gangguan sinyal.");

									if(pData[ii][pCall] == INVALID_PLAYER_ID)
									{
										PlayerPlaySound(playerid, 3600, 0,0,0);
										PlayerPlaySound(ii, 6003, 0,0,0);

										new Float:x, Float:y, Float:z;
										GetPlayerPos(playerid, x, y, z);
										SetPlayerRaceCheckpoint(ii, 1, x, y, z, 0.0, 0.0, 0.0, 3.5);

										Info(ii, "%s telah memberikan keberadaan lokasinya kepadamu", ReturnName(playerid));
										Info(playerid, "Kamu telah memberikan lokasi mu kepada %s.", ReturnName(ii));
										return 1;
									}
									else
									{
										Error(playerid, "Nomor ini sedang sibuk.");
										return 1;
									}
								}
							}
						}
					}
					cache_delete(result);
				}
				case 5:
				{
					new query[512];
					mysql_format(g_SQL, query, sizeof(query), "DELETE FROM phonebook WHERE id='%d'", dbid);
					new Cache:result = mysql_query(g_SQL, query);

					Info(playerid, "Succes deleted contact in db: %d", dbid);
					cache_delete(result);
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_SENDMSGCT)
	{
		new dbid = GetPVarInt(playerid, "ClickedContact");

		if(Inventory_Count(playerid, "Phone") < 1)
			return ErrorMsg(playerid, "Kamu tidak memilik phone");

		if(pData[playerid][pPhoneCredit] <= 0) 
			return ErrorMsg(playerid, "Anda tidak memiliki Ponsel credits");

		if(pData[playerid][pInjured] != 0) 
			return ErrorMsg(playerid, "Saat ini anda tidak dapat menggunakan SMS");

		if(GetSignalNearest(playerid) == 0)
			return ErrorMsg(playerid, "Ponsel anda tidak mendapatkan sinyal di wilayah ini.");

		if(response)
		{
			if(isnull(inputtext))
			{
				new mstr[512];
				format(mstr,sizeof(mstr),"NOTE: Pesan sms tidak boleh kosong!");
				ShowPlayerDialog(playerid, DIALOG_SENDMSGCT, DIALOG_STYLE_INPUT,"SMS Contact", mstr, "Send","Cancel");
				return 1;
			}
			if(strlen(inputtext) < 1 || strlen(inputtext) > 50)
			{
				new mstr[512];
				format(mstr,sizeof(mstr),"NOTE: Pesan tidak boleh kurang dari 1 dan lebih dari 50 karakter!.");
				ShowPlayerDialog(playerid, DIALOG_SENDMSGCT, DIALOG_STYLE_INPUT,"SMS Contact", mstr, "Send","Cancel");
				return 1;
			}
			new query[512];
			mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM phonebook WHERE id='%d' ORDER BY id ASC LIMIT 30", dbid);
			new Cache:result = mysql_query(g_SQL, query);
			new rows = cache_num_rows();

			if(rows)
			{
				new cnumber, ph;
				for(new i; i < rows; ++i)
			    {
					cache_get_value_name_int(i, "cnumber", cnumber);

					ph = cnumber;
					foreach(new ii : Player)
					{
						if(pData[ii][pPhone] == ph)
						{
							if(pData[ii][pUsePhone] == 0) 
								return Error(playerid, "Tidak dapat SMS, Ponsel tersebut yang dituju sedang Offline");

							if(IsPlayerInRangeOfPoint(ii, 20, 2179.9531,-1009.7586,1021.6880))
								return Error(playerid, "Anda tidak dapat melakukan ini, orang yang dituju sedang berada di OOC Zone");

							if(GetSignalNearest(ii) == 0)
								return Error(playerid, "Ponsel tersebut sedang mengalami gangguan sinyal.");
							
							if(ii == INVALID_PLAYER_ID || !IsPlayerConnected(ii)) return Error(playerid, "This number is not actived!");
							SendClientMessageEx(playerid, COLOR_YELLOW, "[SMS to %d]"WHITE_E" %s", ph, ColouredText(inputtext));
							SendClientMessageEx(ii, COLOR_YELLOW, "[SMS from %d]"WHITE_E" %s", pData[playerid][pPhone], ColouredText(inputtext));
							Info(ii, "Gunakan "LB_E"'@<text>' "WHITE_E"untuk membalas SMS!");
							PlayerPlaySound(ii, 6003, 0,0,0);
							pData[ii][pSMS] = pData[playerid][pPhone];
							
							pData[playerid][pPhoneCredit] -= 1;
							return 1;
						}
					}
				}
			}
			cache_delete(result);
		}
		return 1;
	}
	if(dialogid == DIALOG_EDITNAMECT)
	{
		new dbid = GetPVarInt(playerid, "ClickedContact");
		if(response)
		{
			if(isnull(inputtext))
			{
				new mstr[512];
				format(mstr,sizeof(mstr),"NOTE: Nama Contact tidak di perbolehkan kosong!");
				ShowPlayerDialog(playerid, DIALOG_EDITNAMECT, DIALOG_STYLE_INPUT,"Change Contact Name", mstr,"Change","Back");
				return 1;
			}
			if(strlen(inputtext) > 20 || strlen(inputtext) < 1)
			{
				new mstr[512];
				format(mstr,sizeof(mstr),"NOTE: Nama Contact hanya bisa 1 sampai 20 karakter.");
				ShowPlayerDialog(playerid, DIALOG_EDITNAMECT, DIALOG_STYLE_INPUT,"Change Contact Name", mstr,"Change","Back");
				return 1;
			}
			new query[512];
			mysql_format(g_SQL, query, sizeof(query), "UPDATE phonebook SET cname='%s' WHERE id='%d'", ColouredText(inputtext), dbid);
			mysql_query(g_SQL, query);

			Info(playerid, "Nama contact berhasil diubah menjadi: %s", ColouredText(inputtext));
		}
		return 1;
	}
	if(dialogid == DIALOG_EDITNUMBERCT)
	{
		new dbid = GetPVarInt(playerid, "ClickedContact"), number, mstr[512];
		if(response)
		{
			if(sscanf(inputtext, "d", number))
            {
				format(mstr,sizeof(mstr),"NOTE: Nomor Contact tidak di perbolehkan kosong!");
				ShowPlayerDialog(playerid, DIALOG_EDITNUMBERCT, DIALOG_STYLE_INPUT,"Change Contact Name", mstr,"Change","Back");
			}
			else if(number < 0 || number > 999999)
			{
				format(mstr,sizeof(mstr),"NOTE: Nomor Contact harus 1 sampai 4 karakter.");
				ShowPlayerDialog(playerid, DIALOG_EDITNUMBERCT, DIALOG_STYLE_INPUT,"Change Contact Name", mstr,"Change","Back");
			}
			else
			{
				new query[512];
				mysql_format(g_SQL, query, sizeof(query), "UPDATE phonebook SET cnumber='%d' WHERE id='%d'", strval(inputtext), dbid);
				mysql_query(g_SQL, query);

				Info(playerid, "Nomor contact berhasil diubah menjadi: %d", strval(inputtext));
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_LOCKVEH)
	{
	    if(response)
	    {
	        new count;
         	foreach(new i : PVehicles)
	        {
	            if(pvData[i][cClaim] == 0 && pvData[i][cClaimTime] == 0 && pvData[i][cParkid] == -1)
	            {
	                if(Vehicle_IsOwner(playerid, i) && count++ == listitem)
	                {
						new Float:vPos[3];
						GetVehiclePos(pvData[i][cVeh], vPos[0], vPos[1], vPos[2]);
						if(IsPlayerInRangeOfPoint(playerid, 5.0, vPos[0], vPos[1], vPos[2]))
						{
							if(!pvData[i][cLocked])
							{
								pvData[i][cLocked] = 1;
								GameTextForPlayer(playerid, "LOCKED", 1000, 3);
								PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
								SwitchVehicleDoors(pvData[i][cVeh], true);
							}
							else
							{

								pvData[i][cLocked] = 0;
								GameTextForPlayer(playerid, "UNLOCKED", 1000, 3);
								PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
								SwitchVehicleDoors(pvData[i][cVeh], false);
							}
						}
					}
				}
			}
		}
	}
	if(dialogid == GARKOT_PICKUP)
	{
		if(response)
		{
			new i = ReturnPVehParkID(playerid, (listitem + 1));
			new gkid = pData[playerid][pGetPARKID];
			new str[200];

			pvData[i][cParkid] = -1;
			pvData[i][cPosX] = gkData[gkid][sgkX];
			pvData[i][cPosY] = gkData[gkid][sgkY];
			pvData[i][cPosZ] = gkData[gkid][sgkZ];
			pvData[i][cPosA] = gkData[gkid][sgkA];

			
			PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
			OnPlayerVehicleRespawn(i);
			SetPlayerArmedWeapon(playerid, 0);
			AttachVehicleToys(pvData[i][cVeh]);
			PutPlayerInVehicle(playerid, pvData[i][cVeh], 0);
			
			/*
			SetValidVehicleHealth(pvData[i][cVeh], 2500);
			SetVehiclePos(pvData[i][cVeh], pvData[i][cPosX], pvData[i][cPosY], pvData[i][cPosZ] + 3.0);
			SetVehicleZAngle(pvData[i][cVeh], pvData[i][cPosA]);
			SetVehicleFuel(pvData[i][cVeh], 1000);
			*/
			format(str, sizeof(str), "SELECT * FROM `carstorage` WHERE `ID` = '%d'", pvData[i][cID]);
			mysql_tquery(g_SQL, str, "OnLoadCarStorage", "d", i);

			SuccesMsg(playerid, "Kendaraan anda berhasil di keluarkan");
		}
		return 1;
	}
	if(dialogid == DIALOG_TICKET)
	{
		if(!response)
			return 1;

		new vehid = GetPVarInt(playerid, "GiveTicketVehicle");

		foreach(new ii : PVehicles)
		{
			if(vehid == pvData[ii][cVeh])
			{
				if(pvData[ii][cTicket] >= 1)
					return Error(playerid, "Kendaraan ini sudah memiliki ticket tilang");

				pvData[ii][cTicket] = 1;
				Info(playerid, "Anda telah berhasil memberi tilang kendaraan %s (ID: %d)", GetVehicleModelName(pvData[ii][cModel]), pvData[ii][cVeh]);

				DeletePVar(playerid, "GiveTicketVehicle");
			}
		}
	}
	if(dialogid == DIALOG_CLEARTICKET)
	{
		if(!response)
			return 1;

		new vehid = GetPVarInt(playerid, "ClearVehTicket");

		foreach(new ii : PVehicles)
		{
			if(vehid == pvData[ii][cVeh])
			{
				if(pvData[ii][cTicket] <= 0)
					return Error(playerid, "Kendaraan ini tidak memiliki ticket tilang");

				pvData[ii][cTicket] = 0;
				Info(playerid, "Anda telah berhasil menghapus tilang kendaraan %s (ID: %d)", GetVehicleModelName(pvData[ii][cModel]), pvData[ii][cVeh]);

				DeletePVar(playerid, "ClearVehTicket");
			}
		}
	}
	if(dialogid == DIALOG_ADMIN_SIGNAL)
	{
		if(!response)
			return 1;

		new sgid = ReturnAdminSignalID(listitem+1);

		if(sgData[sgid][sgStatus] == 0)
		{
			sgData[sgid][sgSeconds] = 600;
			sgData[sgid][sgStatus] = 1;
	        Signal_Save(sgid);
			Signal_Refresh(sgid);

			Info(playerid, "Sinyal ID: %d berhasil dimatikan", sgid);
		}
		else
        {
        	KillTimer(sgData[sgid][sgTimer]);
		    sgData[sgid][sgSeconds] = 0;
	    	sgData[sgid][sgTimer] = -1;
			sgData[sgid][sgStatus] = 0;

	        Signal_Save(sgid);
			Signal_Refresh(sgid);

			Info(playerid, "Sinyal ID: %d berhasil diperbaiki", sgid);
		}
	}
	if(dialogid == VEHICLE_INSURANCE)
	{
		if(!response) return 1;
		new vehid = ReturnPVehiclesInsuID(playerid, (listitem + 1));

		pvData[vehid][cClaim] = 0;
		pvData[vehid][cParkid] = -1;
		
		OnPlayerVehicleRespawn(vehid); //1527.21, -2165.95, 13.54, 265.04
		pvData[vehid][cPosX] = 1538.6188;
		pvData[vehid][cPosY] = -2176.4746;
		pvData[vehid][cPosZ] = 13.6469;
		pvData[vehid][cPosA] = 179.7064;
		SetValidVehicleHealth(pvData[vehid][cVeh], 2500);
		SetVehiclePos(pvData[vehid][cVeh], 345.52, -77.80, 1.41);
		SetVehicleZAngle(pvData[vehid][cVeh], 179.7064);
		vCore[pvData[vehid][cVeh]][vFuel] = 100;
		
		Info(playerid, "Anda telah mengclaim kendaraan %s anda.", GetVehicleModelName(pvData[vehid][cModel]));
		return 1;
	}
	if(dialogid == DIALOG_BOOMBOX)
	{
		new bbid = pData[playerid][pGetBOOMBOXID];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new str[254], hstr[254];
					format(hstr, sizeof(hstr), "Boombox URL (ID: %d)", bbid);
					format(str, sizeof(str), "Masukkan URL musik yang ingin kamu setel:");
					ShowPlayerDialog(playerid, DIALOG_BOOMBOX_URL, DIALOG_STYLE_INPUT, hstr, str, "Yes", "No");
				}
				case 1:
				{
					foreach(new i : Player)
					{
						if(IsPlayerInRangeOfPoint(i, 30.0, bbData[bbid][bbPosX], bbData[bbid][bbPosY], bbData[bbid][bbPosZ]))
						{
							StopAudioStreamForPlayer(i);
						}
					}
					bbData[bbid][bbAreaid] = -1;
					Info(playerid, "Kamu telah mematikan boombox milikmu (Boombox ID: %d | Location: %s)", bbid, GetLocation(bbData[bbid][bbPosX], bbData[bbid][bbPosY], bbData[bbid][bbPosZ]));
					SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "** %s telah mematikan boombox miliknya", ReturnName(playerid));
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_BOOMBOX_URL)
	{
		new bbid = pData[playerid][pGetBOOMBOXID], str[254], hstr[254];
		if(response)
		{
			if(isnull(inputtext))
			{
				format(hstr, sizeof(hstr), "Boombox URL (ID: %d)", bbid);
				format(str, sizeof(str), "ERROR: Kotak penginputan URL tidak boleh kosong!");
				ShowPlayerDialog(playerid, DIALOG_BOOMBOX_URL, DIALOG_STYLE_INPUT, hstr, str, "Yes", "No");
			}
			if(strlen(inputtext) > 250)
			{
				format(hstr, sizeof(hstr), "Boombox URL (ID: %d)", bbid);
				format(str, sizeof(str), "ERROR: Panjang URL tidak boleh melebihi dari 128 character!");
				ShowPlayerDialog(playerid, DIALOG_BOOMBOX_URL, DIALOG_STYLE_INPUT, hstr, str, "Yes", "No");
			}

			format(bbData[bbid][bbUrl], 250, inputtext);
			foreach(new i : Player)
			{
				if(IsPlayerInRangeOfPoint(i, 30.0, bbData[bbid][bbPosX], bbData[bbid][bbPosY], bbData[bbid][bbPosZ]))
				{
					PlayAudioStreamForPlayer(i, inputtext, bbData[bbid][bbPosX], bbData[bbid][bbPosY], bbData[bbid][bbPosZ], 30.0, 1);
				}
			}
		}
		return 1;
	}
	if(dialogid == TWITTER_MENU)
	{
		if(GetSignalNearest(playerid) == 0)
			return Error(playerid, "Ponsel anda tidak mendapatkan sinyal di wilayah ini.");

		new str[524];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					format(str, sizeof(str), "Username mu sekarang: @%s\nMasukan nama twitter yang kamu inginkan:", pData[playerid][pTwittername]);
					ShowPlayerDialog(playerid, TWITTER_NAME, DIALOG_STYLE_INPUT, "Twitter Name", str, "Yes", "No");
				}
				case 1:
				{
					format(str, sizeof(str), "Masukan text postingan yang akan dikirim:");
					ShowPlayerDialog(playerid, TWITTER_POST, DIALOG_STYLE_INPUT, "Twitter Post", str, "Yes", "No");
				}
			}
		}
		return 1;
	}
	if(dialogid == TWITTER_NAME)
	{
		if(pData[playerid][pPhoneCredit] <= 0)
			return Error(playerid, "Kamu tidak memiliki phone credit!");
		
		if(response)
		{
			new str[254];
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "ERROR: Kotak penginputan tidak boleh kosong!\n\nUsername mu sekarang: @%s\nMasukan nama twitter yang kamu inginkan:", pData[playerid][pTwittername]);
				ShowPlayerDialog(playerid, TWITTER_NAME, DIALOG_STYLE_INPUT, "Twitter Name", str, "Yes", "No");
				return 1;
			}
			if(strlen(inputtext) > 15)
			{
				format(str, sizeof(str), "ERROR: Panjang text tidak boleh lebih dari 15 character!\n\nUsername mu sekarang: @%s\nMasukan nama twitter yang kamu inginkan:", pData[playerid][pTwittername]);
				ShowPlayerDialog(playerid, TWITTER_NAME, DIALOG_STYLE_INPUT, "Twitter Name", str, "Yes", "No");
				return 1;
			}

			pData[playerid][pPhoneCredit]--;
			PlayerTextDrawSetString(playerid, XMenu[playerid][27], sprintf("%s", pData[playerid][pTwittername]));

			new query[512];
			mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM players WHERE twittername = '%s'", inputtext);
			mysql_tquery(g_SQL, query, "ChangeTwitterName", "ds", playerid, inputtext);
		}
		return 1;
	}
	if(dialogid == TWITTER_BIO)
	{
		if(pData[playerid][pPhoneCredit] <= 0)
			return Error(playerid, "Kamu tidak memiliki phone credit!");
		
		if(response)
		{
			new str[254];
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "ERROR: Kotak penginputan tidak boleh kosong!\n\nBio mu sekarang: %s\nMasukan bio twitter yang kamu inginkan:", pData[playerid][pTwitterbio]);
				ShowPlayerDialog(playerid, TWITTER_BIO, DIALOG_STYLE_INPUT, "Twitter Bio", str, "Yes", "No");
				return 1;
			}
			if(strlen(inputtext) > 50)
			{
				format(str, sizeof(str), "ERROR: Panjang text tidak boleh lebih dari 50 character!\n\nBio mu sekarang: %s\nMasukan bio twitter yang kamu inginkan:", pData[playerid][pTwitterbio]);
				ShowPlayerDialog(playerid, TWITTER_BIO, DIALOG_STYLE_INPUT, "Twitter Bio", str, "Yes", "No");
				return 1;
			}

			pData[playerid][pPhoneCredit]--;
			
			PlayerTextDrawSetString(playerid, XMenu[playerid][28], sprintf("%s", pData[playerid][pTwitterbio]));
			new query[512];
			mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM players WHERE twitterbio = '%s'", inputtext);
			mysql_tquery(g_SQL, query, "ChangeTwitterBio", "ds", playerid, inputtext);
		}
		return 1;
	}
	if(dialogid == TWITTER_POST)
	{
		if(pData[playerid][pPhoneCredit] <= 0)
			return Error(playerid, "Kamu tidak memiliki phone credit!");

		if(pData[playerid][pTwitTime] >= gettime()) return ErrorMsg(playerid, "Anda harus menunggu untuk kembali menggunakan twitter");

		if(response)
		{
			new str[128];
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "ERROR: Kotak penginputan tidak boleh kosong!\n\nMasukan text postingan yang akan dikirim:");
				ShowPlayerDialog(playerid, TWITTER_POST, DIALOG_STYLE_INPUT, "Twitter Post", str, "Yes", "No");
				return 1;
			}
			if(!strcmp(pData[playerid][pTwittername], "None"))
			{
				format(str, sizeof(str), "ERROR: Kamu belum mengatur username twitter mu!\n\nMasukan text postingan yang akan dikirim:");
				ShowPlayerDialog(playerid, TWITTER_POST, DIALOG_STYLE_INPUT, "Twitter Post", str, "Yes", "No");
				return 1;
			}
			if(strlen(inputtext) > 50)
			{
				format(str, sizeof(str), "ERROR: Panjang text tidak boleh lebih dari 50 character!\n\nMasukan text postingan yang akan dikirim:");
				ShowPlayerDialog(playerid, TWITTER_POST, DIALOG_STYLE_INPUT, "Twitter Post", str, "Yes", "No");
				return 1;
			}

			pData[playerid][pPhoneCredit]--;
			pData[playerid][pTwitTime] = gettime() + 600;

			foreach(new i : Player)
			{
				if(IsPlayerConnected(i))
				{
					if(pData[i][pPhone] != 0 && pData[i][pUsePhone] != 0)
					{
						PlayerTextDrawSetString(i, NotifX[playerid][24], sprintf("%s", pData[playerid][pTwittername]));
						PlayerTextDrawSetString(i, NotifX[playerid][25], sprintf("%s", inputtext));
						for(new x = 0; x < 26; x++) {
							PlayerTextDrawShow(i, NotifX[playerid][x]);
						}
						for(new m = 0; m < 44; m++) {
							PlayerTextDrawHide(playerid, XMenu[playerid][m]);
						}
						SetTimerEx("HideNotifX", 5000, false, "d", i);
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_PAYTAX)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(GetHousesPaytax(playerid) <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki rumah");

					new id, count = GetHousesPaytax(playerid), mission[2024], lstr[3024], type[128];
					
					strcat(mission,"ID\tTYPE\tLOCATION\tEXPIRED\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnHousesPaytaxID(playerid, itt);
						if(hData[id][hType] == 1)
						{
							type = "Low";
						}
						else if(hData[id][hType] == 2)
						{
							type = "Medium";
						}
						else if(hData[id][hType] == 3)
						{
							type = "High";
						}
						else
						{
							type = "Unknown";
						}
	
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", id, type, GetLocation(hData[id][hExtposX], hData[id][hExtposY], hData[id][hExtposZ]), ReturnTimelapse(gettime(), hData[id][hVisit]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", id, type, GetLocation(hData[id][hExtposX], hData[id][hExtposY], hData[id][hExtposZ]), ReturnTimelapse(gettime(), hData[id][hVisit]));	
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, DIALOG_PAYTAX_HOUSE, DIALOG_STYLE_TABLIST_HEADERS,"Houses Tax",mission,"Select","Cancel");
				}
				case 1:
				{
					if(GetDealerPaytax(playerid) <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki dealer");

					new id, count = GetDealerPaytax(playerid), mission[2024], lstr[3024], type[128];
					
					strcat(mission,"ID\tTYPE\tLOCATION\tEXPIRED\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnDealerPaytaxID(playerid, itt);
						if(drData[id][dType] == 1)
						{
							type = "Bikes Vehicles";
						}
						else if(drData[id][dType] == 2)
						{
							type = "Cars";
						}
						else if(drData[id][dType] == 3)
						{
							type = "Unique Cars";
						}
						else if(drData[id][dType] == 4)
						{
							type = "Job Cars";
						}
						else if(drData[id][dType] == 5)
						{
							type = "Rental Jobs";
						}
	
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", id, type, GetLocation(drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]), ReturnTimelapse(gettime(), drData[id][dVisit]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", id, type, GetLocation(drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]), ReturnTimelapse(gettime(), drData[id][dVisit]));	
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, DIALOG_PAYTAX_DEALER, DIALOG_STYLE_TABLIST_HEADERS,"Dealer Tax",mission,"Select","Cancel");
				}
				case 2:
				{
					if(GetVendingPaytax(playerid) <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki vending machine");

					new id, count = GetVendingPaytax(playerid), mission[2024], lstr[3024];
					
					strcat(mission,"ID\tLOCATION\tEXPIRED\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnVendingPaytaxID(playerid, itt);
						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\n", id, GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), ReturnTimelapse(gettime(), drData[id][dVisit]));
						}
						else format(lstr,sizeof(lstr), "%d\t%s\t%s\n", id, GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), ReturnTimelapse(gettime(), drData[id][dVisit]));	
						strcat(mission,lstr,sizeof(mission));
					}
					ShowPlayerDialog(playerid, DIALOG_PAYTAX_VENDING, DIALOG_STYLE_TABLIST_HEADERS,"Vending Tax",mission,"Select","Cancel");
				}
				case 3:
				{
					if(GetBisnisPaytax(playerid) <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki bisnis");

					new id, count = GetBisnisPaytax(playerid), mission[2024], lstr[3024], type[128];

					strcat(mission,"ID\tTYPE\tLOCATION\tEXPIRED\n",sizeof(mission));
					Loop(itt, (count + 1), 1)
					{
						id = ReturnBisnisPaytaxID(playerid, itt);
						if(bData[id][bType] == 1)
						{
							type= "Fast Food";
						}
						else if(bData[id][bType] == 2)
						{
							type= "24/7";
						}
						else if(bData[id][bType] == 3)
						{
							type= "Clothes";
						}
						else if(bData[id][bType] == 4)
						{
							type= "Equipments";
						}
						else if(bData[id][bType] == 5)
						{
							type= "Electronics";
						}
						else
						{
							type= "Unknown";
						}

						if(itt == count)
						{
							format(lstr,sizeof(lstr), "%d\t%s\t%s\t%s\n", id, type, GetLocation(bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ]), ReturnTimelapse(gettime(), bData[id][bVisit]));
						}
						strcat(mission,lstr,sizeof(mission));
						ShowPlayerDialog(playerid, DIALOG_PAYTAX_BISNIS, DIALOG_STYLE_TABLIST_HEADERS,"Bisnis Tax",mission,"Select","Cancel");
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_PAYTAX_BISNIS)
	{
		if(response)
		{
			new id = ReturnBisnisPaytaxID(playerid, (listitem + 1));

			if(bData[id][bVisit] > gettime() + (87400 * 7))
				return ErrorMsg(playerid, "Anda tidak dapat membayar pajak bisnis dengan masa expired di bawah 7 hari");
		
			if(pData[playerid][pMoney] < 4000)
				return ErrorMsg(playerid, "Uang anda tidak mencukupi $4000");

			bData[id][bVisit] = gettime() + (86400 + 31);
			Bisnis_Refresh(id);
			Bisnis_Save(id);

			GivePlayerMoneyEx(playerid, -4000);
			Server_AddMoney(4000);
			Info(playerid, "Anda telah membayar pajak bisnis %s (ID: %d) dengan harga {00FF00}$4000 {FFFFFF}(/paytax untuk mengeceknya)", GetLocation(bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ]), id);
		}
		return 1;
	}
	if(dialogid == DIALOG_PAYTAX_HOUSE)
	{
		if(response)
		{
			new id = ReturnHousesPaytaxID(playerid, (listitem + 1));

			if(hData[id][hVisit] > gettime() + (86400 * 7))
				return Error(playerid, "Kamu hanya bisa membayar pajak houses yang masa expired nya dibawah 7 hari");

			if(pData[playerid][pMoney] < 8000)
				return Error(playerid, "Kamu harus memiliki uang sejumlah $8.000"GREEN_E" "WHITE_E"untuk membayar pajak asset rumahnmu");

			hData[id][hVisit] = gettime() + (86400 * 31);
			House_Refresh(id);
			House_Save(id);

			GivePlayerMoneyEx(playerid, -8000);
			Server_AddMoney(8000);
			Info(playerid, "Kamu telah membayar pajak rumah %s (ID: %d) dengan harga "GREEN_E"$60.000 "WHITE_E"(/paytax untuk mengeceknya)", GetLocation(hData[id][hExtposX], hData[id][hExtposY], hData[id][hExtposZ]), id);
		}
		return 1;
	}
	if(dialogid == DIALOG_PAYTAX_DEALER)
	{
		if(response)
		{
			new id = ReturnDealerPaytaxID(playerid, (listitem + 1));

			if(drData[id][dVisit] > gettime() + (86400 * 7))
				return Error(playerid, "Kamu hanya bisa membayar pajak dealer yang masa expired nya dibawah 7 hari");

			if(pData[playerid][pMoney] < 25000)
				return Error(playerid, "Kamu harus memiliki uang sejumlah $25.000"GREEN_E" "WHITE_E"untuk membayar pajak asset dealer");

			drData[id][dVisit] = gettime() + (86400 * 31);
			Dealer_Refresh(id);
			Dealer_Save(id);

			GivePlayerMoneyEx(playerid, -25000);
			Server_AddMoney(25000);
			Info(playerid, "Kamu telah membayar pajak dealer %s (ID: %d) dengan harga "GREEN_E"$25.000 "WHITE_E"(/paytax untuk mengeceknya)", GetLocation(drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]), id);
		}
		return 1;
	}
	if(dialogid == DIALOG_PAYTAX_VENDING)
	{
		if(response)
		{
			new id = ReturnVendingPaytaxID(playerid, (listitem + 1));

			if(vmData[id][venVisit] > gettime() + (86400 * 7))
				return Error(playerid, "Kamu hanya bisa membayar pajak vending yang masa expired nya dibawah 7 hari");

			if(pData[playerid][pMoney] < 20000)
				return Error(playerid, "Kamu harus memiliki uang sejumlah $20.000"GREEN_E" "WHITE_E"untuk membayar pajak asset vending");

			vmData[id][venVisit] = gettime() + (86400 * 31);
			Vending_Refresh(id);
			Vending_Save(id);

			GivePlayerMoneyEx(playerid, -20000);
			Server_AddMoney(20000);
			Info(playerid, "Kamu telah membayar pajak vending %s (ID: %d) dengan harga "GREEN_E"$50.000 "WHITE_E"(/paytax untuk mengeceknya)", GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), id);
		}
		return 1;
	}
	//--------------[ Vehicle Toy Dialog ]-------------
	if(dialogid == DIALOG_VTOY)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(response)
		{
			switch(listitem)
			{
				case 0: //slot 1
				{
					pData[playerid][pVtoySelect] = 0;

					new slotid = pData[playerid][pVtoySelect];
					if(vToys[vehicleid][0][vtModelid] == 0)
					{
						//ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						new string[512];
						format(string, sizeof(string), ""dot"Edit Toy Position(Android/PC)\n"dot""GREY_E"Edit Toy Position(PC)\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
						vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
						vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
						ShowPlayerDialog(playerid, DIALOG_VTOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Vehicle Toys", string, "Select", "Cancel");
					}
				}
				case 1: //slot 2
				{
					pData[playerid][pVtoySelect] = 1;

					new slotid = pData[playerid][pVtoySelect];
					if(vToys[vehicleid][1][vtModelid] == 0)
					{
						//ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						new string[512];
						format(string, sizeof(string), ""dot"Edit Toy Position(Android/PC)\n"dot""GREY_E"Edit Toy Position(PC)\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
						vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
						vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
						ShowPlayerDialog(playerid, DIALOG_VTOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Vehicle Toys", string, "Select", "Cancel");
						//ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos", "Select", "Cancel");
					}
				}
				case 2: //slot 3
				{
					pData[playerid][pVtoySelect] = 2;

					new slotid = pData[playerid][pVtoySelect];
					if(vToys[vehicleid][2][vtModelid] == 0)
					{
						//ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						new string[512];
						format(string, sizeof(string), ""dot"Edit Toy Position(Android/PC)\n"dot""GREY_E"Edit Toy Position(PC)\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
						vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
						vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
						ShowPlayerDialog(playerid, DIALOG_VTOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Vehicle Toys", string, "Select", "Cancel");
						//ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos", "Select", "Cancel");
					}
				}
				case 3: //slot 4
				{
					pData[playerid][pVtoySelect] = 3;

					new slotid = pData[playerid][pVtoySelect];
					if(vToys[vehicleid][3][vtModelid] == 0)
					{
						//ShowPlayerSelectionMenu(playerid, TOYS_MODEL, "Select Toy", ToysModel, sizeof(ToysModel));
					}
					else
					{
						new string[512];
						format(string, sizeof(string), ""dot"Edit Toy Position(Android/PC)\n"dot""GREY_E"Edit Toy Position(PC)\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
						vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
						vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
						ShowPlayerDialog(playerid, DIALOG_VTOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Vehicle Toys", string, "Select", "Cancel");
						//ShowPlayerDialog(playerid, DIALOG_TOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Player Toys", ""dot"Edit Toy Position\n"dot"Change Bone\n"dot"Hide/Show Toy\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos", "Select", "Cancel");
					}
				}
				case 4:
				{
					foreach(new vehid : PVehicles)
					{
						if(vehicleid == pvData[vehid][cVeh])
						{
							MySQL_ResetVehicleToys(vehid);
						}
					}
					InfoTD_MSG(playerid, 3000, "~r~~h~All Toy Reseted!~y~!");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_VTOYEDIT)
	{
		new vehicleid = GetPlayerVehicleID(playerid), slotid = pData[playerid][pVtoySelect];
		if(response)
		{
			switch(listitem)
			{
				case 0: // edit vehicle toys
				{
					for(new i = 0; i < 19; i++)
					{
						TextDrawShowForPlayer(playerid, ModTD[i]);
					}

					pData[playerid][pGetVTOYID] = vehicleid;

					SelectTextDraw(playerid, 0xFF4040AA);
					TogglePlayerControllable(playerid, 0);
					SwitchVehicleEngine(vehicleid, false);
					InfoTD_MSG(playerid, 3000, "~b~~h~You are now editing vehicle toy.");
				}
				case 1:
				{
					EditAttachedObject(playerid, pData[playerid][pVtoySelect]);
				}
				case 2: // remove toy
				{
					if(IsValidObject(vToys[vehicleid][slotid][vtObj]))
						DestroyObject(vToys[vehicleid][slotid][vtObj]);

					vToys[vehicleid][slotid][vtModelid] = 0;

					vToys[vehicleid][slotid][vtX] = 0.0;
					vToys[vehicleid][slotid][vtY] = 0.0;
					vToys[vehicleid][slotid][vtZ] = 0.0;

					vToys[vehicleid][slotid][vtRX] = 0.0;
					vToys[vehicleid][slotid][vtRY] = 0.0;
					vToys[vehicleid][slotid][vtRZ] = 0.0;

					MySQL_SaveVehicleToys(vehicleid);

					InfoTD_MSG(playerid, 3000, "~r~~h~Vehicle Toy Removed~y~!");
					SetPVarInt(vehicleid, "UpdatedVtoy", 1);
					TogglePlayerControllable(playerid, true);
				}
				case 3:	//share toy pos
				{
					SendNearbyMessage(playerid, 10.0, COLOR_GREEN, "[VTOY BY %s] "WHITE_E"PosX: %.3f | PosY: %.3f | PosZ: %.3f | PosRX: %.3f | PosRY: %.3f | PosRZ: %.3f",
					ReturnName(playerid), vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
					vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
				}
				case 4: //Pos X
				{
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosX: %f\nInput new Toy PosX:(Float)", vToys[vehicleid][slotid][vtX]);
					ShowPlayerDialog(playerid, DIALOG_VTOYPOSX, DIALOG_STYLE_INPUT, "Vehicle Toy PosX", mstr, "Edit", "Cancel");
				}
				case 5: //Pos Y
				{
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosY: %f\nInput new Toy PosY:(Float)", vToys[vehicleid][slotid][vtY]);
					ShowPlayerDialog(playerid, DIALOG_VTOYPOSY, DIALOG_STYLE_INPUT, "Vehicle Toy PosY", mstr, "Edit", "Cancel");
				}
				case 6: //Pos Z
				{
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosZ: %f\nInput new Toy PosZ:(Float)", vToys[vehicleid][slotid][vtZ]);
					ShowPlayerDialog(playerid, DIALOG_VTOYPOSZ, DIALOG_STYLE_INPUT, "Vehicle Toy PosZ", mstr, "Edit", "Cancel");
				}
				case 8: //Pos RX
				{
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosRX: %f\nInput new Toy PosRX:(Float)", vToys[vehicleid][slotid][vtRX]);
					ShowPlayerDialog(playerid, DIALOG_VTOYPOSRX, DIALOG_STYLE_INPUT, "Vehicle Toy PosRX", mstr, "Edit", "Cancel");
				}
				case 9: //Pos RY
				{
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosRY: %f\nInput new Toy PosRY:(Float)", vToys[vehicleid][slotid][vtRY]);
					ShowPlayerDialog(playerid, DIALOG_VTOYPOSRY, DIALOG_STYLE_INPUT, "Vehicle Toy PosRY", mstr, "Edit", "Cancel");
				}
				case 10: //Pos RZ
				{
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Current Toy PosRZ: %f\nInput new Toy PosRZ:(Float)", vToys[vehicleid][slotid][vtRZ]);
					ShowPlayerDialog(playerid, DIALOG_VTOYPOSRZ, DIALOG_STYLE_INPUT, "Vehicle Toy PosRZ", mstr, "Edit", "Cancel");
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_VTOYPOSX)
	{
		new vehicleid = GetPlayerVehicleID(playerid), slotid = pData[playerid][pVtoySelect];
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
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
			MySQL_SaveVehicleToys(vehicleid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
			vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
			ShowPlayerDialog(playerid, DIALOG_VTOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Vehicle Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_VTOYPOSY)
	{
		new vehicleid = GetPlayerVehicleID(playerid), slotid = pData[playerid][pVtoySelect];
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
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
			MySQL_SaveVehicleToys(vehicleid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
			vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
			ShowPlayerDialog(playerid, DIALOG_VTOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Vehicle Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_VTOYPOSZ)
	{
		new vehicleid = GetPlayerVehicleID(playerid), slotid = pData[playerid][pVtoySelect];
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
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
			MySQL_SaveVehicleToys(vehicleid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
			vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
			ShowPlayerDialog(playerid, DIALOG_VTOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Vehicle Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_VTOYPOSRX)
	{
		new vehicleid = GetPlayerVehicleID(playerid), slotid = pData[playerid][pVtoySelect];
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
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
			MySQL_SaveVehicleToys(vehicleid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
			vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
			ShowPlayerDialog(playerid, DIALOG_VTOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Vehicle Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_VTOYPOSRY)
	{
		new vehicleid = GetPlayerVehicleID(playerid), slotid = pData[playerid][pVtoySelect];
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
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
			MySQL_SaveVehicleToys(vehicleid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
			vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
			ShowPlayerDialog(playerid, DIALOG_VTOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Vehicle Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_VTOYPOSRZ)
	{
		new vehicleid = GetPlayerVehicleID(playerid), slotid = pData[playerid][pVtoySelect];
		if(response)
		{
			new Float:posisi = floatstr(inputtext);
			
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
			MySQL_SaveVehicleToys(vehicleid);
			
			new string[512];
			format(string, sizeof(string), ""dot"Edit Toy Position(PC Only)\n"dot""GREY_E"Remove Toy\n"dot"Share Toy Pos\nPosX: %f\nPosY: %f\nPosZ: %f\nPosRX: %f\nPosRY: %f\nPosRZ: %f",
			vToys[vehicleid][slotid][vtX], vToys[vehicleid][slotid][vtY], vToys[vehicleid][slotid][vtZ],
			vToys[vehicleid][slotid][vtRX], vToys[vehicleid][slotid][vtRY], vToys[vehicleid][slotid][vtRZ]);
			ShowPlayerDialog(playerid, DIALOG_VTOYEDIT, DIALOG_STYLE_LIST, ""GOLD_E"Kampung Indo "WHITE_E"Vehicle Toys", string, "Select", "Cancel");
		}
	}
	if(dialogid == DIALOG_VTOYBUY)
	{
		if(response)
		{
			new vehicleid = GetPlayerVehicleID(playerid);

			if(vToys[vehicleid][listitem][vtModelid] != 0)
				return Error(playerid, "Slot tersebut sudah terisi!");

			pData[playerid][pVtoySelect] = listitem;
			ShowPlayerSelectionMenu(playerid, VEHICLE_TOYS, "Select Vehicle Toy", VehicleToys, sizeof(VehicleToys));
		}
		return 1;
	}
	if(dialogid == NPCFAM_MENU)
	{	
		new str[512], nfid = pData[playerid][pGetNPCFAMID], fid;

		fid = nfData[nfid][nfOwner];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					format(str, sizeof(str), "Withdraw Money\nDeposit Money");
					ShowPlayerDialog(playerid, NPCFAM_MONEY, DIALOG_STYLE_LIST, fData[fid][fName], str, "Select", "Cancel");
				}
				case 1:
				{
					if(nfData[nfid][nfType] == 1)
					{
						format(str, sizeof(str), "Withdraw Marijuana\nDeposit Marijuana");
						ShowPlayerDialog(playerid, NPCFAM_MARIJUANA, DIALOG_STYLE_LIST, fData[fid][fName], str, "Select", "Cancel");
					}
					if(nfData[nfid][nfType] == 2)
					{
						format(str, sizeof(str), "Withdraw Material\nDeposit Material");
						ShowPlayerDialog(playerid, NPCFAM_MATERIAL, DIALOG_STYLE_LIST, fData[fid][fName], str, "Select", "Cancel");
					}
				}
				case 2:
				{
					if(nfData[nfid][nfType] == 1)
					{
						format(str, sizeof(str), "Withdraw Cocaine\nDeposit Cocaine");
						ShowPlayerDialog(playerid, NPCFAM_COCAINE, DIALOG_STYLE_LIST, fData[fid][fName], str, "Select", "Cancel");
					}
					if(nfData[nfid][nfType] == 2)
					{
						Npcfam_ProductMenu(playerid, nfid);
					}
				}
				case 3:
				{
					format(str, sizeof(str), "Withdraw Meth\nDeposit Meth");
					ShowPlayerDialog(playerid, NPCFAM_METH, DIALOG_STYLE_LIST, fData[fid][fName], str, "Select", "Cancel");
				}
				case 4:
				{
					Npcfam_ProductMenu(playerid, nfid);
				}
			}
		}
		return 1;
	}
	if(dialogid == NPCFAM_MONEY)
	{
		new str[512], nfid = pData[playerid][pGetNPCFAMID], fid;

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					format(str, sizeof(str), "Money Vault: %s\n\nMasukan jumlah uang yang ingin kamu withdraw:", FormatMoney(nfData[nfid][nfMoney]));
					ShowPlayerDialog(playerid, NPCFAM_MONEY_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				}
				case 1:
				{
					format(str, sizeof(str), "Money Vault: %s\n\nMasukan jumlah uang yang ingin kamu depositkan:", FormatMoney(nfData[nfid][nfMoney]));
					ShowPlayerDialog(playerid, NPCFAM_MONEY_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				}
			}
		}
		return 1;
	}
	if(dialogid == NPCFAM_MATERIAL)
	{
		new str[512], nfid = pData[playerid][pGetNPCFAMID], fid;

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					format(str, sizeof(str), "Material Vault: %d\n\nMasukan jumlah material yang ingin kamu withdraw:", nfData[nfid][nfMaterial]);
					ShowPlayerDialog(playerid, NPCFAM_MATERIAL_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				}
				case 1:
				{
					format(str, sizeof(str), "Material Vault: %d\n\nMasukan jumlah material yang ingin kamu depositkan:", nfData[nfid][nfMaterial]);
					ShowPlayerDialog(playerid, NPCFAM_MATERIAL_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				}
			}
		}
		return 1;
	}
	if(dialogid == NPCFAM_MARIJUANA)
	{
		new str[512], nfid = pData[playerid][pGetNPCFAMID], fid;

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					format(str, sizeof(str), "Marijuana Vault: %d gram\n\nMasukan jumlah marijuana yang ingin kamu withdraw:", nfData[nfid][nfMarijuana]);
					ShowPlayerDialog(playerid, NPCFAM_MARIJUANA_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				}
				case 1:
				{
					format(str, sizeof(str), "Marijuana Vault: %d gram\n\nMasukan jumlah marijuana yang ingin kamu depositkan:", nfData[nfid][nfMarijuana]);
					ShowPlayerDialog(playerid, NPCFAM_MARIJUANA_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				}
			}
		}
		return 1;
	}
	if(dialogid == NPCFAM_COCAINE)
	{
		new str[512], nfid = pData[playerid][pGetNPCFAMID], fid;

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					format(str, sizeof(str), "Cocaine Vault: %d gram\n\nMasukan jumlah cocaine yang ingin kamu withdraw:", nfData[nfid][nfCocaine]);
					ShowPlayerDialog(playerid, NPCFAM_COCAINE_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				}
				case 1:
				{
					format(str, sizeof(str), "Cocaine Vault: %d gram\n\nMasukan jumlah cocaine yang ingin kamu depositkan:", nfData[nfid][nfCocaine]);
					ShowPlayerDialog(playerid, NPCFAM_COCAINE_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				}
			}
		}
		return 1;
	}
	if(dialogid == NPCFAM_METH)
	{
		new str[512], nfid = pData[playerid][pGetNPCFAMID], fid;

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					format(str, sizeof(str), "Meth Vault: %d gram\n\nMasukan jumlah meth yang ingin kamu withdraw:", nfData[nfid][nfMeth]);
					ShowPlayerDialog(playerid, NPCFAM_METH_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				}
				case 1:
				{
					format(str, sizeof(str), "Meth Vault: %d gram\n\nMasukan jumlah meth yang ingin kamu depositkan:", nfData[nfid][nfMeth]);
					ShowPlayerDialog(playerid, NPCFAM_METH_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				}
			}
		}
		return 1;
	}
	if(dialogid == NPCFAM_MONEY_WITHDRAW)
	{
		new str[1024], nfid = pData[playerid][pGetNPCFAMID], fid, ammount = strval(inputtext);

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "Money Vault: %s\n\nERROR: Kotak penginputan tidak boleh kosong!\nMasukan jumlah uang yang ingin kamu withdraw:", FormatMoney(nfData[nfid][nfMoney]));
				ShowPlayerDialog(playerid, NPCFAM_MONEY_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				return 1;
			}
			if(ammount < 1 || ammount > nfData[nfid][nfMoney])
			{
				format(str, sizeof(str), "Money Vault: %s\n\nERROR: Uang didalam vault tidak mencukupi!\nMasukan jumlah uang yang ingin kamu withdraw:", FormatMoney(nfData[nfid][nfMoney]));
				ShowPlayerDialog(playerid, NPCFAM_MONEY_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				return 1;
			}

			GivePlayerMoneyEx(playerid, ammount);
			nfData[nfid][nfMoney] -= ammount;
			Npcfam_Save(nfid);

			Info(playerid, "Kamu berhasil menwithdraw %s dari dalam vault NPCFAMID: %d", FormatMoney(ammount), nfid);
		}
		return 1;
	}
	if(dialogid == NPCFAM_MONEY_DEPOSIT)
	{
		new str[1024], nfid = pData[playerid][pGetNPCFAMID], fid, ammount = strval(inputtext);

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "Money Vault: %s\n\nERROR: Kotak penginputan tidak boleh kosong!\nMasukan jumlah uang yang ingin kamu deposit:", FormatMoney(nfData[nfid][nfMoney]));
				ShowPlayerDialog(playerid, NPCFAM_MONEY_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				return 1;
			}
			if(ammount < 1 || ammount > pData[playerid][pMoney])
			{
				format(str, sizeof(str), "Money Vault: %s\n\nERROR: Uang ditanganmu tidak mencukupi!\nMasukan jumlah uang yang ingin kamu deposit:", FormatMoney(nfData[nfid][nfMoney]));
				ShowPlayerDialog(playerid, NPCFAM_MONEY_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				return 1;
			}

			GivePlayerMoneyEx(playerid, -ammount);
			nfData[nfid][nfMoney] += ammount;
			Npcfam_Save(nfid);
			
			Info(playerid, "Kamu berhasil mendepositkan %s kedalam vault NPCFAMID: %d", FormatMoney(ammount), nfid);
		}
		return 1;
	}
	if(dialogid == NPCFAM_MATERIAL_WITHDRAW)
	{
		new str[1024], nfid = pData[playerid][pGetNPCFAMID], fid, ammount = strval(inputtext);

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "Material Vault: %d\n\nERROR: Kotak penginputan tidak boleh kosong!\nMasukan jumlah material yang ingin kamu withdraw:", nfData[nfid][nfMaterial]);
				ShowPlayerDialog(playerid, NPCFAM_MATERIAL_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				return 1;
			}
			if(ammount < 1 || ammount > nfData[nfid][nfMaterial])
			{
				format(str, sizeof(str), "Material Vault: %d\n\nERROR: Material didalam vault tidak mencukupi!\nMasukan jumlah material yang ingin kamu withdraw:", nfData[nfid][nfMaterial]);
				ShowPlayerDialog(playerid, NPCFAM_MATERIAL_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				return 1;
			}

			Inventory_Add(playerid, "Material", 17051, ammount);
			nfData[nfid][nfMaterial] -= ammount;
			Npcfam_Save(nfid);

			Info(playerid, "Kamu berhasil menwithdraw %d material dari dalam vault NPCFAMID: %d", ammount, nfid);
		}
		return 1;
	}
	if(dialogid == NPCFAM_MATERIAL_DEPOSIT)
	{
		new str[1024], nfid = pData[playerid][pGetNPCFAMID], fid, ammount = strval(inputtext);

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "Material Vault: %d\n\nERROR: Kotak penginputan tidak boleh kosong!\nMasukan jumlah material yang ingin kamu deposit:", nfData[nfid][nfMaterial]);
				ShowPlayerDialog(playerid, NPCFAM_MATERIAL_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				return 1;
			}
			if(ammount < 1 || ammount > Inventory_Count(playerid, "Material"))
			{
				format(str, sizeof(str), "Material Vault: %d\n\nERROR: Material ditanganmu tidak mencukupi!\nMasukan jumlah material yang ingin kamu deposit:", nfData[nfid][nfMaterial]);
				ShowPlayerDialog(playerid, NPCFAM_MATERIAL_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				return 1;
			}

			Inventory_Remove(playerid, "Material", ammount);
			nfData[nfid][nfMaterial] += ammount;
			Npcfam_Save(nfid);
			
			Info(playerid, "Kamu berhasil mendepositkan %d material kedalam vault NPCFAMID: %d", ammount, nfid);
		}
		return 1;
	}
	if(dialogid == NPCFAM_MARIJUANA_WITHDRAW)
	{
		new str[1024], nfid = pData[playerid][pGetNPCFAMID], fid, ammount = strval(inputtext);

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "Marijuana Vault: %d gram\n\nERROR: Kotak penginputan tidak boleh kosong!\nMasukan jumlah marijuana yang ingin kamu withdraw:", nfData[nfid][nfMarijuana]);
				ShowPlayerDialog(playerid, NPCFAM_MARIJUANA_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				return 1;
			}
			if(ammount < 1 || ammount > nfData[nfid][nfMarijuana])
			{
				format(str, sizeof(str), "Marijuana Vault: %d gram\n\nERROR: Marijuana didalam vault tidak mencukupi!\nMasukan jumlah marijuana yang ingin kamu withdraw:", nfData[nfid][nfMarijuana]);
				ShowPlayerDialog(playerid, NPCFAM_MARIJUANA_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				return 1;
			}

			Inventory_Add(playerid, "Marijuana", 1578, ammount);
			nfData[nfid][nfMarijuana] -= ammount;
			Npcfam_Save(nfid);

			Info(playerid, "Kamu berhasil menwithdraw %d gram marijuana dari dalam vault NPCFAMID: %d", ammount, nfid);
		}
		return 1;
	}
	if(dialogid == NPCFAM_MARIJUANA_DEPOSIT)
	{
		new str[1024], nfid = pData[playerid][pGetNPCFAMID], fid, ammount = strval(inputtext);

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "Marijuana Vault: %d gram\n\nERROR: Kotak penginputan tidak boleh kosong!\nMasukan jumlah marijuana yang ingin kamu deposit:", nfData[nfid][nfMarijuana]);
				ShowPlayerDialog(playerid, NPCFAM_MARIJUANA_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				return 1;
			}
			if(ammount < 1 || ammount > Inventory_Count(playerid, "Marijuana"))
			{
				format(str, sizeof(str), "Marijuana Vault: %d gram\n\nERROR: Marijuana ditanganmu tidak mencukupi!\nMasukan jumlah marijuana yang ingin kamu deposit:", nfData[nfid][nfMarijuana]);
				ShowPlayerDialog(playerid, NPCFAM_MARIJUANA_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				return 1;
			}

			Inventory_Remove(playerid, "Marijuana", ammount);
			nfData[nfid][nfMarijuana] += ammount;
			Npcfam_Save(nfid);
			
			Info(playerid, "Kamu berhasil mendepositkan %d gram kedalam vault NPCFAMID: %d", ammount, nfid);
		}
		return 1;
	}
	if(dialogid == NPCFAM_COCAINE_WITHDRAW)
	{
		new str[1024], nfid = pData[playerid][pGetNPCFAMID], fid, ammount = strval(inputtext);

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "Cocaine Vault: %d gram\n\nERROR: Kotak penginputan tidak boleh kosong!\nMasukan jumlah cocaine yang ingin kamu withdraw:", nfData[nfid][nfCocaine]);
				ShowPlayerDialog(playerid, NPCFAM_COCAINE_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				return 1;
			}
			if(ammount < 1 || ammount > nfData[nfid][nfMarijuana])
			{
				format(str, sizeof(str), "Cocaine Vault: %d gram\n\nERROR: Cocaine didalam vault tidak mencukupi!\nMasukan jumlah cocaine yang ingin kamu withdraw:", nfData[nfid][nfCocaine]);
				ShowPlayerDialog(playerid, NPCFAM_COCAINE_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				return 1;
			}

			Inventory_Add(playerid, "Cocaine", 1575, ammount);
			nfData[nfid][nfCocaine] -= ammount;
			Npcfam_Save(nfid);

			Info(playerid, "Kamu berhasil menwithdraw %d gram cocaine dari dalam vault NPCFAMID: %d", ammount, nfid);
		}
		return 1;
	}
	if(dialogid == NPCFAM_COCAINE_DEPOSIT)
	{
		new str[1024], nfid = pData[playerid][pGetNPCFAMID], fid, ammount = strval(inputtext);

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "Cocaine Vault: %d gram\n\nERROR: Kotak penginputan tidak boleh kosong!\nMasukan jumlah marijuana yang ingin kamu deposit:", nfData[nfid][nfCocaine]);
				ShowPlayerDialog(playerid, NPCFAM_COCAINE_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				return 1;
			}
			if(ammount < 1 || ammount > Inventory_Count(playerid, "Cocaine"))
			{
				format(str, sizeof(str), "Cocaine Vault: %d gram\n\nERROR: Marijuana ditanganmu tidak mencukupi!\nMasukan jumlah marijuana yang ingin kamu deposit:", nfData[nfid][nfCocaine]);
				ShowPlayerDialog(playerid, NPCFAM_COCAINE_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				return 1;
			}

			Inventory_Remove(playerid, "Cocaine", ammount);
			nfData[nfid][nfCocaine] += ammount;
			Npcfam_Save(nfid);
			
			Info(playerid, "Kamu berhasil mendepositkan %d gram cocaine kedalam vault NPCFAMID: %d", ammount, nfid);
		}
		return 1;
	}
	if(dialogid == NPCFAM_METH_WITHDRAW)
	{
		new str[1024], nfid = pData[playerid][pGetNPCFAMID], fid, ammount = strval(inputtext);

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "Meth Vault: %d gram\n\nERROR: Kotak penginputan tidak boleh kosong!\nMasukan jumlah meth yang ingin kamu withdraw:", nfData[nfid][nfMeth]);
				ShowPlayerDialog(playerid, NPCFAM_METH_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				return 1;
			}
			if(ammount < 1 || ammount > nfData[nfid][nfMeth])
			{
				format(str, sizeof(str), "Meth Vault: %d gram\n\nERROR: Meth didalam vault tidak mencukupi!\nMasukan jumlah meth yang ingin kamu withdraw:", nfData[nfid][nfMeth]);
				ShowPlayerDialog(playerid, NPCFAM_METH_WITHDRAW, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Withdraw", "Cancel");
				return 1;
			}

			Inventory_Add(playerid, "Meth", 1580, ammount);
			nfData[nfid][nfMeth] -= ammount;
			Npcfam_Save(nfid);

			Info(playerid, "Kamu berhasil menwithdraw %d gram meth dari dalam vault NPCFAMID: %d", ammount, nfid);
		}
		return 1;
	}
	if(dialogid == NPCFAM_METH_DEPOSIT)
	{
		new str[1024], nfid = pData[playerid][pGetNPCFAMID], fid, ammount = strval(inputtext);

		fid = nfData[nfid][nfOwner];

		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "Meth Vault: %d gram\n\nERROR: Kotak penginputan tidak boleh kosong!\nMasukan jumlah meth yang ingin kamu deposit:", nfData[nfid][nfMeth]);
				ShowPlayerDialog(playerid, NPCFAM_METH_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				return 1;
			}
			if(ammount < 1 || ammount > Inventory_Count(playerid, "Meth"))
			{
				format(str, sizeof(str), "Meth Vault: %d gram\n\nERROR: Meth ditanganmu tidak mencukupi!\nMasukan jumlah meth yang ingin kamu deposit:", nfData[nfid][nfMeth]);
				ShowPlayerDialog(playerid, NPCFAM_METH_DEPOSIT, DIALOG_STYLE_INPUT, fData[fid][fName], str, "Deposit", "Cancel");
				return 1;
			}

			Inventory_Remove(playerid, "Meth", ammount);
			nfData[nfid][nfMeth] += ammount;
			Npcfam_Save(nfid);
			
			Info(playerid, "Kamu berhasil mendepositkan %d gram meth kedalam vault NPCFAMID: %d", ammount, nfid);
		}
		return 1;
	}
	if(dialogid == NPCFAM_EDITPROD)
	{
		new nfid = pData[playerid][pGetNPCFAMID];

		if(pData[playerid][pFamily] != nfData[nfid][nfOwner])
			return PermissionError(playerid);

		if(pData[playerid][pFamilyRank] < 4)
			return Error(playerid, "Hany rank 5-6 yang bisa mengakses ini");

		if(response)
		{
			static
				item[40],
				str[128];

			strmid(item, inputtext, 0, strfind(inputtext, "-") - 1);
			strpack(pData[playerid][pEditingItem], item, 40 char);

			pData[playerid][pProductModify] = listitem;
			format(str,sizeof(str), "Please enter the new product price for %s:", item);
			ShowPlayerDialog(playerid, NPCFAM_PRICESET, DIALOG_STYLE_INPUT, "NPC Family: Set Price", str, "Modify", "Back");
		}
		else return callcmd::npcfam(playerid, inputtext);
		return 1;
	}
	if(dialogid == NPCFAM_PRICESET)
    {
        static
        	item[40];

        new nfid = pData[playerid][pGetNPCFAMID];

		if(pData[playerid][pFamily] != nfData[nfid][nfOwner])
			return PermissionError(playerid);

		if(pData[playerid][pFamilyRank] < 4)
			return Error(playerid, "Hany rank 5-6 yang bisa mengakses ini");

        if(response)
        {
            strunpack(item, pData[playerid][pEditingItem]);
            if(isnull(inputtext))
            {
                new str[128];
                format(str,sizeof(str), "Please enter the new product price for %s:", item);
                ShowPlayerDialog(playerid, NPCFAM_PRICESET, DIALOG_STYLE_INPUT, "NPC Familiy: Set Price", str, "Set", "Back");
                return 1;
            }
            if(strval(inputtext) < 0 || strval(inputtext) > 2500000)
            {
                new str[128];
                format(str,sizeof(str), "Please enter the new product price for %s ($0 to $2.500,000):", item);
                ShowPlayerDialog(playerid, NPCFAM_PRICESET, DIALOG_STYLE_INPUT, "NPC Familiy: Set Price", str, "Set", "Back");
                return 1;
            }

            nfData[nfid][nfPrice][pData[playerid][pProductModify]] = strval(inputtext);
            Npcfam_Save(nfid);

            Servers(playerid, "You have adjusted the price of %s to: %s!", item, FormatMoney(strval(inputtext)));
            Npcfam_ProductMenu(playerid, nfid);
        }
        else
        {
            Npcfam_ProductMenu(playerid, nfid);
        }
        return 1;
    }
    if(dialogid == NPCFAM_BUYPROD)
	{
		static
        nfid = -1,
        price;

		if((nfid = pData[playerid][pGetNPCFAMID]) != -1 && response)
		{
			price = nfData[nfid][nfPrice][listitem];

			if(listitem != 0 && price <= 0)
				return Error(playerid, "Harga product ini belum di set oleh pemiliknya");
			
			if(pData[playerid][pMoney] < price)
				return Error(playerid, "Not enough money!");

			if(nfData[nfid][nfType] == 1)
			{
				switch(listitem)
				{
					case 0:
					{
						if(nfData[nfid][nfMarijuana] <= 0)
							return Error(playerid, "Stock marijuana tidak mencukupi!");

						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Marijuana", 1578, 1);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli 1gram Marijuana dengan harga %s.", ReturnName(playerid), FormatMoney(price));
						nfData[nfid][nfMarijuana]--;
						nfData[nfid][nfMoney] += Server_Percent(price);
						Server_AddPercent(price);
						Npcfam_Save(nfid);
					}
					case 1:
					{
						if(nfData[nfid][nfCocaine] <= 0)
							return Error(playerid, "Stock marijuana tidak mencukupi!");

						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Cocaine", 1575, 1);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli 1gram Cocaine dengan harga %s.", ReturnName(playerid), FormatMoney(price));
						nfData[nfid][nfCocaine]--;
						nfData[nfid][nfMoney] += Server_Percent(price);
						Server_AddPercent(price);
						Npcfam_Save(nfid);
					}
					case 2:
					{
						if(nfData[nfid][nfMeth] <= 0)
							return Error(playerid, "Stock marijuana tidak mencukupi!");

						GivePlayerMoneyEx(playerid, -price);
						Inventory_Add(playerid, "Meth", 1580, 1);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli 1gram Meth dengan harga %s.", ReturnName(playerid), FormatMoney(price));
						nfData[nfid][nfMeth]--;
						nfData[nfid][nfMoney] += Server_Percent(price);
						Server_AddPercent(price);
						Npcfam_Save(nfid);
					}
				}
			}
			else if(nfData[nfid][nfType] == 2)
			{
				switch(listitem)
				{
					case 0:
					{
						if(nfData[nfid][nfMaterial] < 250)
							return Error(playerid, "Stock material tidak mencukupi");

						if(PlayerHasWeapon(playerid, 22))
							return Error(playerid, "Kamu sudah memiliki senjata tersebut");

						GivePlayerMoneyEx(playerid, -price); //250
						GivePlayerWeaponEx(playerid, 22, 70);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli senjata Colt45 dengan harga %s.", ReturnName(playerid), FormatMoney(price));
						nfData[nfid][nfMaterial] -= 250;
						nfData[nfid][nfMoney] += Server_Percent(price);
						Server_AddPercent(price);
						Npcfam_Save(nfid);
					}
					case 1:
					{
						if(nfData[nfid][nfMaterial] < 500)
							return Error(playerid, "Stock material tidak mencukupi");

						if(PlayerHasWeapon(playerid, 24))
							return Error(playerid, "Kamu sudah memiliki senjata tersebut");

						GivePlayerMoneyEx(playerid, -price); //500
						GivePlayerWeaponEx(playerid, 24, 34);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli senjata Desert Eagle dengan harga %s.", ReturnName(playerid), FormatMoney(price));
						nfData[nfid][nfMaterial] -= 500;
						nfData[nfid][nfMoney] += Server_Percent(price);
						Server_AddPercent(price);
						Npcfam_Save(nfid);
					}
					case 2:
					{
						if(nfData[nfid][nfMaterial] < 400)
							return Error(playerid, "Stock material tidak mencukupi");

						if(PlayerHasWeapon(playerid, 25))
							return Error(playerid, "Kamu sudah memiliki senjata tersebut");

						GivePlayerMoneyEx(playerid, -price); //400
						GivePlayerWeaponEx(playerid, 25, 20);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli senjata Shotgun dengan harga %s.", ReturnName(playerid), FormatMoney(price));
						nfData[nfid][nfMaterial] -= 400;
						nfData[nfid][nfMoney] += Server_Percent(price);
						Server_AddPercent(price);
						Npcfam_Save(nfid);
					}
					case 3:
					{
						if(nfData[nfid][nfMaterial] < 750)
							return Error(playerid, "Stock material tidak mencukupi");

						if(PlayerHasWeapon(playerid, 30))
							return Error(playerid, "Kamu sudah memiliki senjata tersebut");

						GivePlayerMoneyEx(playerid, -price); //750
						GivePlayerWeaponEx(playerid, 30, 200);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli senjata AK-47 dengan harga %s.", ReturnName(playerid), FormatMoney(price));
						nfData[nfid][nfMaterial] -= 750;
						nfData[nfid][nfMoney] += Server_Percent(price);
						Server_AddPercent(price);
						Npcfam_Save(nfid);
					}
					case 4:
					{
						if(nfData[nfid][nfMaterial] < 500)
							return Error(playerid, "Stock material tidak mencukupi");

						if(PlayerHasWeapon(playerid, 28))
							return Error(playerid, "Kamu sudah memiliki senjata tersebut");

						GivePlayerMoneyEx(playerid, -price); //500
						GivePlayerWeaponEx(playerid, 28, 200);
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli senjata Micro SMG/Uzi dengan harga %s.", ReturnName(playerid), FormatMoney(price));
						nfData[nfid][nfMaterial] -= 500;
						nfData[nfid][nfMoney] += Server_Percent(price);
						Server_AddPercent(price);
						Npcfam_Save(nfid);
					}
					case 5:
					{
						if(nfData[nfid][nfMaterial] < 500)
							return Error(playerid, "Stock material tidak mencukupi");

						GivePlayerMoneyEx(playerid, -price); //500
						pData[playerid][pBomb]++;
						SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli senjata Patched Bomb dengan harga %s.", ReturnName(playerid), FormatMoney(price));
						nfData[nfid][nfMaterial] -= 500;
						nfData[nfid][nfMoney] += Server_Percent(price);
						Server_AddPercent(price);
						Npcfam_Save(nfid);
					}
				}
			}
		}
		return 1;
	}
	if(dialogid == PMDC_MENU)
	{
		new str[254];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					PlayerPlaySound(playerid, MDC_SELECT, 0, 0, 0);
					format(str, sizeof(str), "Masukan nomor plat kendaraan yang ingin kamu cari:");
					ShowPlayerDialog(playerid, MDC_VEHICLE, DIALOG_STYLE_INPUT, "MDC Menu (Vehicle)", str, "Yes", "No");
				}
				case 1:
				{
					PlayerPlaySound(playerid, MDC_SELECT, 0, 0, 0);
					format(str, sizeof(str), "Masukan nama pemiliik rumah:");
					ShowPlayerDialog(playerid, MDC_HOUSE, DIALOG_STYLE_INPUT, "MDC Menu (House)", str, "Yes", "No");
				}
				case 2:
				{
					PlayerPlaySound(playerid, MDC_SELECT, 0, 0, 0);
					format(str, sizeof(str), "Masukan Nomor Handphone:");
					ShowPlayerDialog(playerid, MDC_PHONE, DIALOG_STYLE_INPUT, "MDC Menu (Phone Track)", str, "Yes", "No");
				}
				case 3:
				{
					PlayerPlaySound(playerid, MDC_SELECT, 0, 0, 0);
					callcmd::flare(playerid, "");
				}
				case 4:
				{
					PlayerPlaySound(playerid, MDC_SELECT, 0, 0, 0);
        			ShowEmergency(playerid);
				}
			}
		}
		return 1;
	}
	if(dialogid == EMDC_MENU)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					PlayerPlaySound(playerid, MDC_SELECT, 0, 0, 0);
        			ShowEmergency(playerid);
				}
			}
		}
	}
	if(dialogid == MDC_VEHICLE)
	{
		new str[254], count = 0;
		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "ERROR: Kotak penginputan tidak boleh kosong!\n\nMasukan nomor plat kendaraan yang ingin kamu cari:");
				ShowPlayerDialog(playerid, MDC_VEHICLE, DIALOG_STYLE_INPUT, "MDC Menu (Vehicle)", str, "Yes", "No");
				return 1;
			}
			if(strlen(inputtext) > 20)
			{
				format(str, sizeof(str), "ERROR: Tidak boleh lebih dari 20 character!\n\nMasukan nomor plat kendaraan yang ingin kamu cari:");
				ShowPlayerDialog(playerid, MDC_VEHICLE, DIALOG_STYLE_INPUT, "MDC Menu (Vehicle)", str, "Yes", "No");
				return 1;
			}
			format(pData[playerid][pTargetMDC], MAX_PLAYER_NAME, inputtext);
			foreach(new i : PVehicles)
			{
				if(IsValidVehicle(pvData[i][cVeh]))
				{
					if(!strcmp(pvData[i][cPlate], pData[playerid][pTargetMDC]))
					{
						count++;
						format(str, sizeof(str), "%s%s (ID: %d)\n", str, GetVehicleModelName(pvData[i][cModel]), pvData[i][cVeh]);
					}
					ShowPlayerDialog(playerid, MDC_VEHICLE_MENU, DIALOG_STYLE_LIST, "MDC Menu (Vehicle)", str, "Select", "Cancel");
				}
			}

			if(count <= 0)
			{
				format(str, sizeof(str), "ERROR: Tidak dapat menemukan kendaraan dengan plat nomor (%s)\n\nMasukan nomor plat kendaraan yang ingin kamu cari:", pData[playerid][pTargetMDC]);
				ShowPlayerDialog(playerid, MDC_VEHICLE_MENU, DIALOG_STYLE_INPUT, "MDC Menu (Vehicle)", str, "Yes", "No");
			}
		}
		return 1;
	}
	if(dialogid == MDC_HOUSE)
	{
		new str[254], count = 0;
		if(response)
		{
			if(isnull(inputtext))
			{
				format(str, sizeof(str), "ERROR: Kotak penginputan tidak boleh kosong!\n\nMasukan nama pemilik rumah:");
				ShowPlayerDialog(playerid, MDC_HOUSE, DIALOG_STYLE_INPUT, "MDC Menu (House)", str, "Yes", "No");
				return 1;
			}
			if(strlen(inputtext) > 25)
			{
				format(str, sizeof(str), "ERROR: Tidak boleh lebih dari 25 character!\n\nMasukan nama pemilik rumah:");
				ShowPlayerDialog(playerid, MDC_HOUSE, DIALOG_STYLE_INPUT, "MDC Menu (House)", str, "Yes", "No");
				return 1;
			}

			format(pData[playerid][pTargetMDC], MAX_PLAYER_NAME, inputtext);
			for(new i = 0; i < MAX_HOUSES; i++)
			{
				if(Iter_Contains(Houses, i))
				{
					if(!strcmp(hData[i][hOwner], pData[playerid][pTargetMDC]))
					{
						count++;
						format(str, sizeof(str), "%sHouse (ID: %d)\n", str, i);
					}
					ShowPlayerDialog(playerid, MDC_HOUSE_MENU, DIALOG_STYLE_LIST, "MDC Menu (House)", str, "Select", "Cancel");
				}
			}

			if(count <= 0)
			{
				format(str, sizeof(str), "ERROR:\nTidak dapat menemukan rumah dengan pemilik (%s)\n\nMasukan nama pemilik rumah:", pData[playerid][pTargetMDC]);
				ShowPlayerDialog(playerid, MDC_HOUSE, DIALOG_STYLE_INPUT, "MDC Menu (House)", str, "Yes", "No");
			}
		}
		if(dialogid == MDC_PHONE)
		{
			new ph = floatround(strval(inputtext));
			if(response)
			{
				if(isnull(inputtext))
				{
					format(str, sizeof(str), "ERROR: Kotak penginputan tidak boleh kosong!\n\nMasukan Nomor Handphone:");
					ShowPlayerDialog(playerid, MDC_HOUSE, DIALOG_STYLE_INPUT, "MDC Menu (Phone Track)", str, "Yes", "No");
					return 1;
				}
				foreach(new ii : Player)
				{
					if(pData[ii][pPhone] == ph)
					{
						if(pData[ii][pUsePhone] == 0) return Error(playerid, "Ponsel tersebut yang dituju sedang Offline");
						if(IsPlayerInRangeOfPoint(ii, 20, 2179.9531,-1009.7586,1021.6880)) return Error(playerid, "Anda tidak dapat melakukan ini, orang yang dituju sedang berada di OOC Zone");
						if(ii == INVALID_PLAYER_ID || !IsPlayerConnected(ii)) return Error(playerid, "This number is not actived!");
						if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
						Info(playerid, "Kamu mencoba Mencari pemilik Handphone.", 8000);
						pData[playerid][pLoading] = true;
						pData[playerid][pActivityTime] = SetTimerEx("TrackPh", 10000, false, "id", playerid);
						ShowProgressbar(playerid, "Searching...", 10);
					}
				}
			}
			return 1;
		}
	}
	if(dialogid == MDC_VEHICLE_MENU)
	{
		if(response)
		{
			new str[128];
			SetPVarInt(playerid, "MdcVehicleID", ReturnMdcVehicleID(playerid, (listitem+1)));
			format(str, sizeof(str), "Show Information\nTrack Vehicle");
			ShowPlayerDialog(playerid, MDC_VEHICLE_TRACK, DIALOG_STYLE_LIST, "MDC Menu (Vehicle)", str, "Select", "Cancel");
		}
		return 1;
	}
	if(dialogid == MDC_HOUSE_MENU)
	{
		if(response)
		{
			new str[128];
			SetPVarInt(playerid, "MdcHouseID", ReturnMdcHouseID(playerid, (listitem+1)));
			format(str, sizeof(str), "Show Information\nTrack House");
			ShowPlayerDialog(playerid, MDC_HOUSE_TRACK, DIALOG_STYLE_LIST, "MDC Menu (House)", str, "Select", "Cancel");
		}
		return 1;
	}
	if(dialogid == MDC_VEHICLE_TRACK)
	{
		new vehid = GetPVarInt(playerid, "MdcVehicleID"), str[254];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					format(str, sizeof(str),"Vehicle ID: %d\nVehicle Model: %s\nVehicle Plate: %s", pvData[vehid][cVeh], GetVehicleModelName(pvData[vehid][cModel]), pvData[vehid][cPlate]);
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "MDC Menu (Vehicle)", str, "Close", "");
					DeletePVar(playerid, "MdcVehicleID");
				}
				case 1:
				{
					DisablePlayerCheckpoint(playerid);
					DisablePlayerRaceCheckpoint(playerid);

					new Float:x, Float:y, Float:z;
					GetVehiclePos(pvData[vehid][cVeh], x, y, z);
					SetPlayerRaceCheckpoint(playerid, 1, x, y, z, 0.0, 0.0, 0.0, 3.5);
					Info(playerid, "Kendaraan %s (ID: %d) yang berlokasi di %s telah ditandai!", GetVehicleModelName(pvData[vehid][cModel]), pvData[vehid][cVeh], GetLocation(x, y, z));
					DeletePVar(playerid, "MdcVehicleID");
				}
			}
		}
		return 1;
	}
	if(dialogid == MDC_HOUSE_TRACK)
	{
		new hid = GetPVarInt(playerid, "MdcHouseID"), str[254];
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new htype[128];
					if(hData[hid][hType] == 1)
					{
						htype = "Small";
					}
					else if(hData[hid][hType] == 2)
					{
						htype = "Medium";
					}
					else if(hData[hid][hType] == 3)
					{
						htype = "High";
					}
					else
					{
						htype = "None";
					}
					format(str, sizeof(str), "House ID: %d\nHouse Owner: %s\nHouse Owner 2: %s\nHouse Type: %s\nHouse Location: %s", hid, hData[hid][hOwner], hData[hid][hOwner2], htype, GetLocation(hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]));
					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "MDC Menu (House)", str, "Close", "");
					DeletePVar(playerid, "MdcHouseID");
				}
				case 1:
				{
					DisablePlayerCheckpoint(playerid);
					DisablePlayerRaceCheckpoint(playerid);
					SetPlayerRaceCheckpoint(playerid, 1, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ], 0.0, 0.0, 0.0, 3.5);
					Info(playerid, "House (ID: %d) milik %s yang berlokasi di %s telah ditandai", hid, hData[hid][hOwner], GetLocation(hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]));
					DeletePVar(playerid, "MdcHouseID");
				}
			}
		}
		return 1;
	}
    if(dialogid == SVPOINT_SAPD)
    {
        new tstr[512];
        if(!response)
            return 1;

        switch(listitem+1)
        {
            case 1:
            {
                new modelid = 596;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
            case 2:
            {
                new modelid = 407;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
            case 3:
            {
                new modelid = 544;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
            case 4:
            {
                new modelid = 599;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
            case 5:
            {
                new modelid = 601;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
            case 6:
            {
                new modelid = 528;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
            case 7:
            {
                new modelid = 560;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
            case 8:
            {
                new modelid = 523;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
            case 9:
            {
                new modelid = 525;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
            case 10:
            {
                new modelid = 497;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
            case 11:
            {
                new modelid = 411;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAPD)", tstr, "Yes", "No");
            }
        }
    }
    if(dialogid == SVPOINT_SAGS)
    {
        new tstr[512];
        if(!response)
            return 1;

        switch(listitem+1)
        {
            case 1:
            {
                new modelid = 405;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAGS)", tstr, "Yes", "No");
            }
            case 2:
            {
                new modelid = 409;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAGS)", tstr, "Yes", "No");
            }
            case 3:
            {
                new modelid = 411;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAGS)", tstr, "Yes", "No");
            }
            case 4:
            {
                new modelid = 521;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAGS)", tstr, "Yes", "No");
            }
            case 5:
            {
                new modelid = 437;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAGS)", tstr, "Yes", "No");
            }
            case 6:
            {
                new modelid = 487;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAGS)", tstr, "Yes", "No");
            }
        }
    }
    if(dialogid == SVPOINT_SAMD)
    {
        new tstr[512];
        if(!response)
            return 1;

        switch(listitem+1)
        {
            case 1:
            {
                new modelid = 407;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAMD)", tstr, "Yes", "No");
            }
            case 2:
            {
                new modelid = 544;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAMD)", tstr, "Yes", "No");
            }
            case 3:
            {
                new modelid = 416;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAMD)", tstr, "Yes", "No");
            }
            case 4:
            {
                new modelid = 442;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAMD)", tstr, "Yes", "No");
            }
            case 5:
            {
                new modelid = 426;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAMD)", tstr, "Yes", "No");
            }
            case 6:
            {
                new modelid = 586;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAMD)", tstr, "Yes", "No");
            }
            case 7:
            {
                new modelid = 563;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAMD)", tstr, "Yes", "No");
            }
            case 8:
            {
                new modelid = 487;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SAMD)", tstr, "Yes", "No");
            }
        }
    }
    if(dialogid == SVPOINT_SANEWS)
    {
        new tstr[512];
        if(!response)
            return 1;

        switch(listitem+1)
        {
            case 1:
            {
                new modelid = 582;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SANEWS)", tstr, "Yes", "No");
            }
            case 2:
            {
                new modelid = 418;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SANEWS)", tstr, "Yes", "No");
            }
            case 3:
            {
                new modelid = 413;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SANEWS)", tstr, "Yes", "No");
            }
            case 4:
            {
                new modelid = 405;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SANEWS)", tstr, "Yes", "No");
            }
            case 5:
            {
                new modelid = 461;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SANEWS)", tstr, "Yes", "No");
            }
            case 6:
            {
                new modelid = 488;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SANEWS)", tstr, "Yes", "No");
            }
        }
    }
    if(dialogid == SVPOINT_SACF)
    {
        new tstr[512];
        if(!response)
            return 1;

        switch(listitem+1)
        {
            case 1:
            {
                new modelid = 588;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SACF)", tstr, "Yes", "No");
            }
            case 2:
            {
                new modelid = 488;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SACF)", tstr, "Yes", "No");
            }
            case 3:
            {
                new modelid = 423;
                pData[playerid][pSvModelid] = modelid;
                format(tstr, sizeof(tstr), ""WHITE_E"Anda yakin ingin mengeluarkan kendaraan "GREEN_LIGHT"%s"WHITE_E"?", GetVehicleModelName(modelid));
                ShowPlayerDialog(playerid, SVPOINT_SPAWNVEH, DIALOG_STYLE_MSGBOX, "Vehicle Spawn (SACF)", tstr, "Yes", "No");
            }
        }
    }
    if(dialogid == SVPOINT_SPAWNVEH)
    {
        new fvid = Iter_Free(FactionVeh);
        new svid = pData[playerid][pGetSVPOINTID];
        new modelid = pData[playerid][pSvModelid];
        if(response)
        {
            if(svData[svid][svType] == 1) //SAPD
            {
                if(modelid == 497)
                {
                    fvData[fvid][fvPosX] = 1566.16;
                    fvData[fvid][fvPosY] = -1643.75;
                    fvData[fvid][fvPosZ] = 28.40+0.5;
                    fvData[fvid][fvPosA] = 89.69;

                    fvData[fvid][fvColor1] = 0;
                    fvData[fvid][fvColor2] = 1;

                    fvData[fvid][fvFaction] = 1;
                }
                else
                {
                    fvData[fvid][fvPosX] = 1538.62;
                    fvData[fvid][fvPosY] = -1651.09;
                    fvData[fvid][fvPosZ] = 5.89+0.5;
                    fvData[fvid][fvPosA] = 183.14;

                    fvData[fvid][fvColor1] = 0;
                    fvData[fvid][fvColor2] = 1;

                    fvData[fvid][fvFaction] = 1;
                }
                fvData[fvid][fvLabel] = Create3DTextLabel("Police Departement", COLOR_GREY, 0.0, 0.0, 0.0, 15.0, 0, 1);
            }
            else if(svData[svid][svType] == 2) //SAGS
            {
                if(modelid == 487)
                {
                    fvData[fvid][fvPosX] = 1421.19;
                    fvData[fvid][fvPosY] = -1781.88;
                    fvData[fvid][fvPosZ] = 33.42+0.5;
                    fvData[fvid][fvPosA] = 85.81;

                    fvData[fvid][fvColor1] = 0;
                    fvData[fvid][fvColor2] = 0;

                    fvData[fvid][fvFaction] = 2;
                }
                else
                {
                    fvData[fvid][fvPosX] = 1477.23;
                    fvData[fvid][fvPosY] = -1841.65;
                    fvData[fvid][fvPosZ] = 13.54+0.5;
                    fvData[fvid][fvPosA] = 269.76;

                    fvData[fvid][fvColor1] = 0;
                    fvData[fvid][fvColor2] = 0;

                    fvData[fvid][fvFaction] = 2;
                }
                fvData[fvid][fvLabel] = Create3DTextLabel("Goverment Service", COLOR_GREY, 0.0, 0.0, 0.0, 15.0, 0, 1);
            }
            else if(svData[svid][svType] == 3) //SAMD
            {
                if(modelid == 563 || modelid == 487)
                {
                    fvData[fvid][fvPosX] = 1159.78;
                    fvData[fvid][fvPosY] = -1302.98;
                    fvData[fvid][fvPosZ] = 31.49+0.5;
                    fvData[fvid][fvPosA] = 270.99;

                    fvData[fvid][fvColor1] = 3;
                    fvData[fvid][fvColor2] = 1;

                    fvData[fvid][fvFaction] = 3;
                }
                else
                {
                    fvData[fvid][fvPosX] = 1121.55;
                    fvData[fvid][fvPosY] = -1309.98;
                    fvData[fvid][fvPosZ] = 13.63+0.5;
                    fvData[fvid][fvPosA] = 271.55;

                    fvData[fvid][fvColor1] = 3;
                    fvData[fvid][fvColor2] = 1;

                    fvData[fvid][fvFaction] = 3;
                }
                fvData[fvid][fvLabel] = Create3DTextLabel("Medical Departement", COLOR_GREY, 0.0, 0.0, 0.0, 15.0, 0, 1);
            }
            else if(svData[svid][svType] == 4) //SANEWS
            {
                if(modelid == 488)
                {
                    fvData[fvid][fvPosX] = 741.78;
                    fvData[fvid][fvPosY] = -1370.26;
                    fvData[fvid][fvPosZ] = 25.69+0.5;
                    fvData[fvid][fvPosA] = 178.56;

                    fvData[fvid][fvColor1] = -1;
                    fvData[fvid][fvColor2] = -1;

                    fvData[fvid][fvFaction] = 4;
                }
                else
                {
                    fvData[fvid][fvPosX] = 740.23;
                    fvData[fvid][fvPosY] = -1339.85;
                    fvData[fvid][fvPosZ] = 13.84+0.5;
                    fvData[fvid][fvPosA] = 250.85;

                    fvData[fvid][fvColor1] = -1;
                    fvData[fvid][fvColor2] = -1;

                    fvData[fvid][fvFaction] = 4;
                }
                fvData[fvid][fvLabel] = Create3DTextLabel("News Agency", COLOR_GREY, 0.0, 0.0, 0.0, 15.0, 0, 1);
            }
            else if(svData[svid][svType] == 5) //SACF
            {
                if(modelid == 588)
                {
                    fvData[fvid][fvPosX] = 305.87;
                    fvData[fvid][fvPosY] = -1842.32 ;
                    fvData[fvid][fvPosZ] = 3.54+0.5;
                    fvData[fvid][fvPosA] = 3.91;

                    fvData[fvid][fvColor1] = -1;
                    fvData[fvid][fvColor2] = -1;

                    fvData[fvid][fvFaction] = 5;
                }
                else
                {
                    fvData[fvid][fvPosX] = 305.87;
                    fvData[fvid][fvPosY] = -1842.32 ;
                    fvData[fvid][fvPosZ] = 3.54+0.5;
                    fvData[fvid][fvPosA] = 3.91;

                    fvData[fvid][fvColor1] = -1;
                    fvData[fvid][fvColor2] = -1;

                    fvData[fvid][fvFaction] = 5;
                }
                fvData[fvid][fvLabel] = Create3DTextLabel("Cafe Food", COLOR_GREY, 0.0, 0.0, 0.0, 15.0, 0, 1);
            }
            fvData[fvid][fvVeh] = AddStaticVehicle(modelid, fvData[fvid][fvPosX], fvData[fvid][fvPosY], fvData[fvid][fvPosZ], fvData[fvid][fvPosA], fvData[fvid][fvColor1], fvData[fvid][fvColor2]);
            Attach3DTextLabelToVehicle(fvData[fvid][fvLabel], fvData[fvid][fvVeh], 0.0, 0.0, 0.2);
            Info(playerid, "Kendaraan %s (id: %d) dari Faction Vehicle (id: %d) telah di spawn", GetVehicleModelName(modelid), fvData[fvid][fvVeh], svid);
            Info(playerid, "Kendaraan yang anda spawn telah ditandai!");
			vCore[fvData[fvid][fvVeh]][vFuel] = 100;
            DisablePlayerCheckpoint(playerid);
            SetPlayerRaceCheckpoint(playerid, 1, fvData[fvid][fvPosX], fvData[fvid][fvPosY], fvData[fvid][fvPosZ], 0.0, 0.0, 0.0, 3.5);

            pData[playerid][pGetSVPOINTID] = -1;
            pData[playerid][pSvModelid] = -1;

            Iter_Add(FactionVeh, fvid);
        }
        return 1;
    }
	if(dialogid == DIALOG_EMERGENCY_LIST)
	{
		if(!response)
			return 1;

		new fcid = ReturnFactionCallID(playerid, listitem+1);

		if(pData[playerid][pFaction] == 1)
		{
			SendFactionMessage(pData[playerid][pFaction], COLOR_BLUE, "[EMERGENCY CALL] "WHITE_E"%s telah menangani emergency call #%d (From: "YELLOW_E"%s"WHITE_E")", pData[playerid][pName], fcid, ReturnName(fcData[fcid][fcOwner]));
			Info(fcData[fcid][fcOwner], "%s telah meneriman panggilan emergency call 911 anda!", pData[playerid][pName]);
		}
		else if(pData[playerid][pFaction] == 3)
		{
			SendFactionMessage(pData[playerid][pFaction], COLOR_PINK, "[EMERGENCY CALL] "WHITE_E"%s telah menangani emergency call #%d (From: "YELLOW_E"%s"WHITE_E")", pData[playerid][pName], fcid, ReturnName(fcData[fcid][fcOwner]));
			Info(fcData[fcid][fcOwner], "%s telah meneriman panggilan emergency call 922 anda!", pData[playerid][pName]);
		}

		DisablePlayerRaceCheckpoint(playerid);
		SetPlayerRaceCheckpoint(playerid, 1, fcData[fcid][fcPosX], fcData[fcid][fcPosY], fcData[fcid][fcPosZ], 0.0, 0.0, 0.0, 3.5);
		Info(playerid, "Lokasi emergency call yang kamu pilih telah ditandai!");
		
		FactionCall_Delete(fcid);
	}
	if(dialogid == ADSLOG_LIST)
	{
		if(!response)
			return 1;

		new adsid = ReturnAdsLogID((listitem + 1));

		new str[524];
		format(str, sizeof(str), ""WHITE_E"Advertisement ID: "YELLOW_E"%d\n", str, adsid);
		format(str, sizeof(str), "%s"WHITE_E"Poster Owner: "YELLOW_E"%s\n", str, ReturnName(AdsData[adsid][adsOwner]));
		format(str, sizeof(str), "%s"WHITE_E"Phone Number: "YELLOW_E"%d\n", str, pData[playerid][pPhone]);
		format(str, sizeof(str), "%s"WHITE_E"Bank Rek: "YELLOW_E"%d", str, pData[playerid][pBankRek]);

		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Advertisement Logs", str, "Close", "");
	}
	if(dialogid == DIALOG_JOBCENTER)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new JOB[10000], String[10000];
					strcat(JOB, "Job Name\n");
					format(String, sizeof(String), "Lumber Jack\n"); // 3
					strcat(JOB, String);
					format(String, sizeof(String), "Trucker Biasa\n");// 4
					strcat(JOB, String);
					format(String, sizeof(String), "Penambang\n"); // 5
					strcat(JOB, String);
					format(String, sizeof(String), "Production\n"); // 6
					strcat(JOB, String);
					format(String, sizeof(String), "Farmer\n");// 7
					strcat(JOB, String);
					format(String, sizeof(String), "Trucker Hauling\n"); // 8
					strcat(JOB, String);
					/*format(String, sizeof(String), "Job Pizza\n"); // 9
					strcat(JOB, String);*/
					format(String, sizeof(String), "Tukang Ayam\n"); // 10
					strcat(JOB, String);
					format(String, sizeof(String), "Reflenish\n"); // 11
					strcat(JOB, String);
					format(String, sizeof(String), "Pemeras Susu\n"); // 12
					strcat(JOB, String);
					format(String, sizeof(String), "Penjahit\n"); // 13
					strcat(JOB, String);
					format(String, sizeof(String), "{FF0000}Keluar dari Pekerjaan\n"); // 13
					strcat(JOB, String);
					ShowPlayerDialog(playerid, DIALOG_DAFTAR_JOB1, DIALOG_STYLE_TABLIST_HEADERS,"JOB CENTER", JOB, "Select", "Cancel");
				}
				case 1:
				{
					if(pData[playerid][pVip] <= 0) return ErrorMsg(playerid, "Anda bukan bagian dari VIP");
					{
						new JOB[10000], String[10000];
						strcat(JOB, "Job Name\n");
						format(String, sizeof(String), "Lumber Jack\n"); // 3
						strcat(JOB, String);
						format(String, sizeof(String), "Trucker Biasa\n");// 4
						strcat(JOB, String);
						format(String, sizeof(String), "Penambang\n"); // 5
						strcat(JOB, String);
						format(String, sizeof(String), "Production\n"); // 6
						strcat(JOB, String);
						format(String, sizeof(String), "Farmer\n");// 7
						strcat(JOB, String);
						format(String, sizeof(String), "Trucker Hauling\n"); // 8
						strcat(JOB, String);
						/*format(String, sizeof(String), "Job Pizza\n"); // 9
						strcat(JOB, String);*/
						format(String, sizeof(String), "Tukang Ayam\n"); // 10
						strcat(JOB, String);
						format(String, sizeof(String), "Reflenish\n"); // 11
						strcat(JOB, String);
						format(String, sizeof(String), "Pemeras Susu\n"); // 12
						strcat(JOB, String);
						format(String, sizeof(String), "Penjahit\n"); // 13
						strcat(JOB, String);
						format(String, sizeof(String), "{FF0000}Keluar dari Pekerjaan\n"); // 13
						strcat(JOB, String);
						ShowPlayerDialog(playerid, DIALOG_DAFTAR_JOB2, DIALOG_STYLE_TABLIST_HEADERS,"JOB CENTER", JOB, "Select", "Cancel");
					}
				}
			}
		}
	}
	if(dialogid == DIALOG_DAFTAR_JOB1)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 3;
	                    	pData[playerid][pJob] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Tukang Kayu");
							pData[playerid][pGetJob] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 1:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 4;
	                    	pData[playerid][pJob] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Trucker Biasa");
							pData[playerid][pGetJob] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 2:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 5;
	                    	pData[playerid][pJob] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Penambang");
							pData[playerid][pGetJob] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
					}
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");	               
                    return 1;
                }
                case 3:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 6;
	                    	pData[playerid][pJob] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Production");
							pData[playerid][pGetJob] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 4:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 7;
	                    	pData[playerid][pJob] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Farmer");
							pData[playerid][pGetJob] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 5:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 8;
	                    	pData[playerid][pJob] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Hauling");
							pData[playerid][pGetJob] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 6:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");
                	
                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 10;
	                    	pData[playerid][pJob] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Tukang Ayam");
							pData[playerid][pGetJob] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 7:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");
                	
                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 11;
	                    	pData[playerid][pJob] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Reflensih");
							pData[playerid][pGetJob] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 8:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");
                	
                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 14;
	                    	pData[playerid][pJob] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Pemeras Susu");
							pData[playerid][pGetJob] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
							RefreshMapJobSapi(playerid);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 9:
                {
                	if(pData[playerid][pIDCard] <= 0)
                		return ErrorMsg(playerid, "Anda tidak memiliki KTP");

                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 15;
	                    	pData[playerid][pJob] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Penjahit");
							pData[playerid][pGetJob] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 10:
                {
                    if(pData[playerid][pJob] == 0) return ErrorMsg(playerid, "Anda belum bergabung dengan Job Apapun");
                    //if(pData[playerid][pExitJob] != 0) return Error(playerid, "You must wait 1 days for exit from your current job!");
                    if(pData[playerid][pJob] != 0)
                    {
                    	pData[playerid][pJob] = 0;
                    	InfoJob(playerid, "You Have Out Jobs");
                    }
                    return 1;
                }
            }
        }
    }
    if(dialogid == DIALOG_DAFTAR_JOB2)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

					if(pData[playerid][pVip] < 0) 
						return Error(playerid, "Tidak tersedia untuk anda");

                	if(pData[playerid][pJob2] == 0)
					{
	                    if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob2] = 3;
	                    	pData[playerid][pJob2] = pData[playerid][pGetJob2];
	                    	InfoJob(playerid, "You Have Joinned Jobs Lumber Jack");
							pData[playerid][pGetJob2] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 86400);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 1:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

					if(pData[playerid][pVip] < 0) 
						return Error(playerid, "Tidak tersedia untuk anda");

                	if(pData[playerid][pJob2] == 0)
					{
	                    if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob2] = 4;
	                    	pData[playerid][pJob2] = pData[playerid][pGetJob2];
	                    	InfoJob(playerid, "You Have Joinned Jobs Trucker");
							pData[playerid][pGetJob2] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 86400);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 2:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

					if(pData[playerid][pVip] < 0) 
						return Error(playerid, "Tidak tersedia untuk anda");

                	if(pData[playerid][pJob2] == 0)
					{
	                    if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob2] = 5;
	                    	pData[playerid][pJob2] = pData[playerid][pGetJob2];
	                    	InfoJob(playerid, "You Have Joinned Jobs Penambang");
							pData[playerid][pGetJob2] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 86400);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
					}
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");	               
                    return 1;
                }
                case 3:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

					if(pData[playerid][pVip] < 0) 
						return Error(playerid, "Tidak tersedia untuk anda");

                	if(pData[playerid][pJob2] == 0)
					{
	                    if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob2] = 6;
	                    	pData[playerid][pJob2] = pData[playerid][pGetJob2];
	                    	InfoJob(playerid, "You Have Joinned Jobs Production");
							pData[playerid][pGetJob2] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 86400);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 4:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

					if(pData[playerid][pVip] < 0) 
						return Error(playerid, "Tidak tersedia untuk anda");

                	if(pData[playerid][pJob2] == 0)
					{
	                    if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob2] = 7;
	                    	pData[playerid][pJob2] = pData[playerid][pGetJob2];
	                    	InfoJob(playerid, "You Have Joinned Jobs Farmer");
							pData[playerid][pGetJob2] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 86400);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 5:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

					if(pData[playerid][pVip] < 0) 
						return Error(playerid, "Tidak tersedia untuk anda");

                	if(pData[playerid][pJob2] == 0)
					{
	                    if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob2] = 8;
	                    	pData[playerid][pJob2] = pData[playerid][pGetJob2];
	                    	InfoJob(playerid, "You Have Joinned Jobs Trucker Hauling");
							pData[playerid][pGetJob2] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 86400);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 6:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

					if(pData[playerid][pVip] < 0) 
						return Error(playerid, "Tidak tersedia untuk anda");
                	
                	if(pData[playerid][pJob2] == 0)
					{
	                    if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob2] = 10;
	                    	pData[playerid][pJob2] = pData[playerid][pGetJob2];
	                    	InfoJob(playerid, "You Have Joinned Jobs Tukang Ayam");
							pData[playerid][pGetJob2] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 86400);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 7:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");

					if(pData[playerid][pVip] < 0) 
						return Error(playerid, "Tidak tersedia untuk anda");
                	
                	if(pData[playerid][pJob2] == 0)
					{
	                    if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob2] = 11;
	                    	pData[playerid][pJob2] = pData[playerid][pGetJob2];
	                    	InfoJob(playerid, "You Have Joinned Jobs Reflenish");
							pData[playerid][pGetJob2] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 86400);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 8:
                {
                	if(pData[playerid][pIDCard] <= 0)
						return ErrorMsg(playerid, "Anda tidak memiliki KTP");
                	
                	if(pData[playerid][pJob2] == 0)
					{
	                    if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob] = 14;
	                    	pData[playerid][pJob2] = pData[playerid][pGetJob2];
	                    	InfoJob(playerid, "You Have Joinned Jobs Pemeras Susu");
							pData[playerid][pGetJob2] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 86400);
							RefreshMapJobSapi(playerid);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 9:
                {
                	if(pData[playerid][pIDCard] <= 0)
                		return ErrorMsg(playerid, "Anda tidak memiliki KTP");

                	if(pData[playerid][pJob] == 0)
					{
	                    if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1)
	                    {
	                    	pData[playerid][pGetJob2] = 15;
	                    	pData[playerid][pJob2] = pData[playerid][pGetJob];
	                    	InfoJob(playerid, "You Have Joinned Jobs Penjahit");
							pData[playerid][pGetJob2] = 0;
							pData[playerid][pExitJob] = gettime() + (1 * 1);
	                    }
	                    else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
	                }
					else return ErrorMsg(playerid, "Anda sudah memiliki pekerjaan, keluar dari pekarjaan terlebih dahulu");
                    return 1;
                }
                case 10:
                {
                    if(pData[playerid][pJob2] == 0) return ErrorMsg(playerid, "Anda belum bergabung dengan Job Apapun");
                    if(pData[playerid][pExitJob] != 0) return ErrorMsg(playerid, "Anda harus menunggu satu hari untuk keluar Job");
                    if(pData[playerid][pJob2] != 0)
                    {
                    	pData[playerid][pJob2] = 0;
                    	InfoJob(playerid, "You Have Out Jobs");
                    }
                    return 1;
                }
            }
        }
    }
    if(dialogid == DIALOG_BALKOT)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                	if(pData[playerid][pIDCard] != 0) return ErrorMsg(playerid, "Anda sudah memiliki ID Card!");
                	if(pData[playerid][pMoney] < 25) return ErrorMsg(playerid, "Anda butuh $500 untuk membuat ID Card");
                	new sext[40], mstr[128];
                	if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }
                	format(mstr, sizeof(mstr), "{FFFFFF}Nama: %s\nNegara: San Andreas\nTgl Lahir: %s\nJenis Kelamin: %s\nBerlaku hingga 14 hari!", pData[playerid][pName], pData[playerid][pAge], sext);
                	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "ID-Card", mstr, "Tutup", "");
                	pData[playerid][pIDCard] = 1;
                	pData[playerid][pIDCardTime] = gettime() + (15 * 86400);
                	GivePlayerMoneyEx(playerid, -25);
                	Server_AddMoney(25);
                    return 1;
                }
                case 1:
                {
                	if(pData[playerid][pMoney] < 20) return InfoTD_MSG(playerid, 3000, "Anda butuh ~g~$20,00 ~w~untuk mengganti tanggal lahir anda");
                	if(pData[playerid][IsLoggedIn] == false) return ErrorMsg(playerid, "Anda harus login terlebih dahulu");
                	ShowPlayerDialog(playerid, DIALOG_CHANGEAGE, DIALOG_STYLE_INPUT, "Tanggal Lahir", "Masukan tanggal lahir (Tgl/Bulan/Tahun): 15/04/1998", "Change", "Cancel");
                    return 1;
                }
                case 2:
                {
                	if(GetOwnedHouses(playerid) == -1) return ErrorMsg(playerid, "Anda tidak memiliki rumah");
                	new hid, _tmpstring[128], count = GetOwnedHouses(playerid), CMDSString[1024];
                	CMDSString = "";
                	new lock[128];
                	Loop(itt, (count + 1), 1)
                	{
                		hid = ReturnPlayerHousesID(playerid, itt);
                		if(hData[hid][hLocked] == 0)
                		{
                			lock = ""GREEN_LIGHT"Unlocked"WHITE_E"";
                		}
                		else if(hData[hid][hLocked] == 1)
                		{
                			lock = ""RED_E"Locked"WHITE_E"";
                		}
                		else
                		{
                			lock = ""RED_E"Sealed"WHITE_E"";
                		}
                		if(itt == count)
                		{
                			format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s   (%s{FFFF2A})\n", itt, hData[hid][hAddress], lock);
                		}
                		else format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s  (%s{FFFF2A})\n", itt, hData[hid][hAddress], lock);
                		strcat(CMDSString, _tmpstring);
                	}
                	ShowPlayerDialog(playerid, DIALOG_SELL_HOUSES, DIALOG_STYLE_LIST, "Sell Houses", CMDSString, "Sell", "Cancel");
                }
                case 3:
                {
                	if(GetOwnedDealer(playerid) == 0) return ErrorMsg(playerid, "Anda tidak memiliki dealer");
                	new deid, _tmpstring[128], count = GetOwnedDealer(playerid), CMDSString[512];
                	CMDSString = "";
                	Loop(itt, (count + 1), 1)
                	{
                		deid = ReturnPlayerDealerID(playerid, itt);
                		if(itt == count)
                		{
                			format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s   (%s{FFFF2A})\n", itt, drData[deid][dName], GetLocation(drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]));
                		}
                		else format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s  (%s{FFFF2A})\n", itt, drData[deid][dName], GetLocation(drData[deid][dVehX], drData[deid][dVehY], drData[deid][dVehZ]));
                		strcat(CMDSString, _tmpstring);
                	}
                	ShowPlayerDialog(playerid, DIALOG_SELL_DEALER, DIALOG_STYLE_LIST, "Sell Dealer", CMDSString, "Sell", "Cancel");
                }
                case 4:
                {
                	new string[1024];
                	format(string, sizeof(string), "House Tax\nDealer Tax\nVending Tax\nBusiness Tax");
                	ShowPlayerDialog(playerid, DIALOG_PAYTAX, DIALOG_STYLE_LIST, "Paytax Assets", string , "Yes","No");
                }
            }
        }
    }
    if(dialogid == DIALOG_MENU_PLAYER)
    {
    	if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                	
                }
                case 1:
                {
                	
                }
                case 2:
                {
                	
                }
                case 3:
                {
                	
                }
                case 4:
                {
                	
                }
                case 5:
                {
                	
                }
            }
        }
    }
    if(dialogid == DIALOG_MYVEH)
	{
		if(!response) return 1;
		SetPVarInt(playerid, "ClickedVeh", ReturnPlayerVehID(playerid, (listitem + 1)));
		ShowPlayerDialog(playerid, DIALOG_MYVEH_INFO, DIALOG_STYLE_LIST, "Vehicle Info", "Information Vehicle\nTrack Vehicle\nUnstuck Vehicle", "Select", "Cancel");
		return 1;
	}
	if(dialogid == DIALOG_MYVEH_INFO)
	{
		if(!response) return 1;
		new vid = GetPVarInt(playerid, "ClickedVeh");
		switch(listitem)
		{
			case 0:
			{
				
				if(IsValidVehicle(pvData[vid][cVeh]))
				{
					new line9[900];
				
					format(line9, sizeof(line9), "{ffffff}[{7348EB}INFO VEHICLE{ffffff}]:\nVehicle ID: {ffff00}%d\n{ffffff}Model: {ffff00}%s\n{ffffff}Plate: {ffff00}%s{ffffff}\n\n{ffffff}[{7348EB}DATA VEHICLE{ffffff}]:\nInsurance: {ffff00}%d{ffffff}",
					pvData[vid][cVeh], GetVehicleModelName(pvData[vid][cModel]), pvData[vid][cPlate], pvData[vid][cInsu]);

					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Vehicle Info", line9, "Close","");
				}
				else
				{
					new line9[900];
				
					format(line9, sizeof(line9), "{ffffff}[{7348EB}INFO VEHICLE{ffffff}]:\nVehicle UID: {ffff00}%d\n{ffffff}Model: {ffff00}%s\n{ffffff}Plate: {ffff00}%s{ffffff}\n\n{ffffff}[{7348EB}DATA VEHICLE{ffffff}]:\nInsurance: {ffff00}%d{ffffff}",
					pvData[vid][cID], GetVehicleModelName(pvData[vid][cModel]), pvData[vid][cPlate], pvData[vid][cInsu]);

					ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Vehicle Info", line9, "Close","");
				}
			}
			case 1:
			{
				if(IsValidVehicle(pvData[vid][cVeh]))
				{
					new palid = pvData[vid][cVeh];
					new
			        	Float:x,
			        	Float:y,
			        	Float:z;

					pData[playerid][pTrackCar] = 1;
					GetVehiclePos(palid, x, y, z);
					SetPlayerRaceCheckpoint(playerid, 1, x, y, z, 0.0, 0.0, 0.0, 3.5);
					Info(playerid, "Ikuti checkpoint untuk menemukan kendaraan anda!");
				}
				else if(pvData[vid][cParkid] > 0)
				{
					SetPlayerRaceCheckpoint(playerid, 1, pvData[vid][cPosX], pvData[vid][cPosY], pvData[vid][cPosZ], 0.0, 0.0, 0.0, 3.5);
					Info(playerid, "Ikuti checkpoint untuk menemukan kendaraan yang ada di dalam garkot!");
				}
				else if(pvData[vid][cClaim] != 0)
				{
					Info(playerid, "Kendaraan kamu di kantor insuransi!");
				}
				else
					return Error(playerid, "Kendaraanmu belum di spawn!");
			}
			case 2:
            {
                static
                carid = -1;

                if((carid = Vehicle_Nearest(playerid)) != -1)
                {
                    if(Vehicle_IsOwner(playerid, carid))
                    {
                        if(IsValidVehicle(pvData[vid][cVeh]))
                        {
                            Vehicle_GetStatus(vid);
							if(IsValidVehicle(pvData[vid][cVeh]))
								DestroyVehicle(pvData[vid][cVeh]);

							pvData[vid][cVeh] = 0;
                        }
                        SetTimerEx("OnPlayerVehicleRespawn", 3000, false, "d", vid);
                    }
                }
                else Error(playerid, "Kamu tidak berada didekat Kendaraan tersebut.");
            }
		}
		return 1;
	}
    if(dialogid == DIALOG_BAGASI)
    {
    	if(response)
    	{
    		new vehid = GetNearestVehicleToPlayer(playerid, 3.5, false);
    		switch(listitem)
    		{
    			case 0:
    			{
    				Vehicle_WeaponStorage(playerid, vehid);
    			}
    			case 1:
    			{
    				//callcmd::bagasi(playerid, "\0");
    			}
    			case 2:
    			{
    				foreach(new i : PVehicles)
					{
						new string[10 * 32];

						format(string, sizeof(string), "%sMoney Storage ({00ff00}%s{ffffff}/{00ff00}$100.000)\n", string, FormatMoney(pvData[i][cMoney]));
						format(string, sizeof(string), "%sComponent Storage (%d/2500)\n", string, pvData[i][cComponent]);
						format(string, sizeof(string), "%sMaterial Storage (%d/2500)\n", string, pvData[i][cMaterial]);
						ShowPlayerDialog(playerid, VEHICLE_STORAGE, DIALOG_STYLE_LIST, "Vehicle Storage", string, "Select", "Cancel");
					}
    			}
    		}
    	}
    	return 1;
    }
	//
    if(dialogid == DIALOG_MILK)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pFaction] != 5)
						return ErrorMsg(playerid, "Anda harus menjadi bagian dari SACF");

					if(Inventory_Count(playerid, "Susu Olah") > 500) 
						return ErrorMsg(playerid, "Anda sudah membawa susu olahan");
					new mstr[128];
					format(mstr, sizeof(mstr), ""WHITE_E"Masukan jumlah Milk:\nMilk Stock: "GREEN_E"%d\n"WHITE_E"Milk Price"GREEN_E"%s /item", Susu, FormatMoney(SusuPrice));
					ShowPlayerDialog(playerid, DIALOG_MILK_BUY, DIALOG_STYLE_INPUT, "Buy Milk", mstr, "Buy", "Cancel");
				}
				case 1:
				{
					if(Inventory_Count(playerid, "Susu Olah") < 20)
						return ErrorMsg(playerid, "Anda Kurang membawa olahan susu sapi, MAX : 20 olahan susu sapi");

					RemovePlayerAttachedObject(playerid, 9);
					SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
					TogglePlayerControllable(playerid, 1);
					AddPlayerSalary(playerid, "Job (Pemerah Susu Sapi)", jobpemerahprice);
					InfoTD_MSG(playerid, 4000, "Anda telah mendapatkan Pending Salary ~y~/salary");
					Inventory_Remove(playerid, "Susu Olah", 20);
					pData[playerid][pMeatProgres] = 0;
					pData[playerid][pJobTime] = 250;
					Susu += 20;
					Server_Save();
				}
			}
		}
	}
	if(dialogid == DIALOG_MILK_BUY)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			new total = Inventory_HasItem(playerid, "Susu Olah") + amount;
			new value = amount * SusuPrice;
			if(amount < 0 || amount > 500) return Error(playerid, "amount maximal 0 - 500.");
			if(total > 500) return Error(playerid, "Susu terlalu penuh di Inventory! Maximal 500.");
			if(pData[playerid][pMoney] < value) return Error(playerid, "Uang anda kurang.");
			if(Susu < amount) return Error(playerid, "Susu Olahan di stock tidak mencukupi.");
			GivePlayerMoneyEx(playerid, -value);
			Inventory_Add(playerid, "Susu Olah", 19570, amount);
			Susu -= amount;
			Server_AddMoney(value);
			Info(playerid, "Anda berhasil membeli "GREEN_E"%d "WHITE_E"Milk seharga "RED_E"%s.", amount, FormatMoney(value));
		}
	}
	if(dialogid == DIALOG_IKAN_SELL)
	{
		if(response)
		{
			new amount = floatround(strval(inputtext));
			new total = amount - Inventory_HasItem(playerid, "Ikan");
			new value = amount * FishPrice;
			if(total < 1) return Error(playerid, "Ikan anda kurang.");
			if(Inventory_Count(playerid, "Ikan") < 1) return Error(playerid, "Ikan anda kurang.");
			GivePlayerMoneyEx(playerid, value);
			Inventory_Remove(playerid, "Ikan", amount);
			Food += amount;
			Server_AddMoney(value);
			Info(playerid, "Anda berhasil menjual "GREEN_E"%d "WHITE_E"Ikan seharga "RED_E"%s.", amount, FormatMoney(value));
		}
	}
	if(dialogid == GUDANG_SACF)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, PDG_GANDUM, DIALOG_STYLE_LIST, "Gandum", "Ambil Gandum\nMasukan Gandum", "Select","Cancel");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, PDG_DAGING, DIALOG_STYLE_LIST, "Pizza", "Ambil Pizza\nMasukan Pizza", "Select","Cancel");
				}
				case 2:
				{
					ShowPlayerDialog(playerid, PDG_SUSU, DIALOG_STYLE_LIST, "Jus Jeruk", "Ambil Jus Jeruk\nMasukan Jus Jeruk", "Select","Cancel");
				}
				case 3:
				{
					ShowPlayerDialog(playerid, PDG_BIGBURGER, DIALOG_STYLE_LIST, "Nasi Goreng", "Ambil Nasi Goreng\nMasukan Nasi Goreng", "Select","Cancel");
				}
				case 4:
				{
					ShowPlayerDialog(playerid, PDG_ROTI, DIALOG_STYLE_LIST, "Roti", "Ambil Roti\nMasukan Roti", "Select","Cancel");
				}
				case 5:
				{
					ShowPlayerDialog(playerid, PDG_STEAK, DIALOG_STYLE_LIST, "Steak", "Ambil Steak\nMasukan Steak", "Select","Cancel");
				}
				case 6:
				{
					ShowPlayerDialog(playerid, PDG_FOOD, DIALOG_STYLE_LIST, "Food", "Ambil Food\nMasukan Food", "Select", "Cancel");
				}
				case 7:
				{
					ShowPlayerDialog(playerid, PDG_KENTANG, DIALOG_STYLE_LIST, "Kentang", "Ambil Kentang\nMasukan Kentang", "Select", "Cancel");
				}
				case 8:
				{
					ShowPlayerDialog(playerid, PDG_ORANGE, DIALOG_STYLE_LIST, "Orange", "Ambil Jeruk\nMasukan Jeruk", "Select", "Cancel");
				}
				case 9:
				{
					ShowPlayerDialog(playerid, PDG_MILK, DIALOG_STYLE_LIST, "Money", "Withdraw Money\nDeposit Money", "Select","Cancel");
				}
			}
		}
	}
	if(dialogid == PDG_GANDUM)
	{
		if(response)
		{
			new str[256], pid = pData[playerid][pInPdg];
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pdgMenuType] = 1;
					format(str, sizeof str,"Gandum: %d\n\nPlease Input amount to Withdraw", pdgDATA[pid][pdgGandum]);
				}
				case 1:
				{
					pData[playerid][pdgMenuType] = 2;
					format(str, sizeof str,"Gandum: %d\n\nPlease Input amount to Deposit", pdgDATA[pid][pdgGandum]);
				}
			}
			ShowPlayerDialog(playerid, PDG_GANDUM2, DIALOG_STYLE_INPUT, "Gandum Menu", str, "Input","Cancel");
		}
	}
	if(dialogid == PDG_GANDUM2)
	{
		if(response)
		{
			new string[200];
			new amount = strval(inputtext), pid = pData[playerid][pInPdg];
			if(pData[playerid][pdgMenuType] == 1)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah Minimal 1");

				if(pdgDATA[pid][pdgGandum] < amount) return ErrorMsg(playerid, "Jumlah Gandum tidak cukup");

				Inventory_Add(playerid, "Wheat", 2247, amount);
				pdgDATA[pid][pdgGandum] -= amount;
				Pedagang_Save(pid);
				format(string, sizeof(string), "Anda berhasil mengambil %d Wheat dari Gudang", amount);
				SuccesMsg(playerid, string);
			}
			else if(pData[playerid][pdgMenuType] == 2)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah minimal 1");

				if(Inventory_Count(playerid, "Wheat") < amount) return ErrorMsg(playerid, "Jumlah Gandum tidak cukup");

				Inventory_Remove(playerid, "Wheat", amount);
				pdgDATA[pid][pdgGandum] += amount;
				Pedagang_Save(pid);
				format(string, sizeof(string), "Anda berhasil memasukan %d Wheat ke Gudang", amount);
				SuccesMsg(playerid, string);
			}
		}
	}
	if(dialogid == PDG_DAGING)
	{
		if(response)
		{
			new str[256], pid = pData[playerid][pInPdg];
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pdgMenuType] = 1;
					format(str, sizeof str,"Pizza: %d\n\nPlease Input amount to Withdraw", pdgDATA[pid][pdgDaging]);
				}
				case 1:
				{
					pData[playerid][pdgMenuType] = 2;
					format(str, sizeof str,"Pizza: %d\n\nPlease Input amount to Deposit", pdgDATA[pid][pdgDaging]);
				}
			}
			ShowPlayerDialog(playerid, PDG_DAGING2, DIALOG_STYLE_INPUT, "Pizza Menu", str, "Input","Cancel");
		}
	}
	if(dialogid == PDG_DAGING2)
	{
		if(response)
		{
			new string[200];
			new amount = strval(inputtext), pid = pData[playerid][pInPdg];
			if(pData[playerid][pdgMenuType] == 1)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah Minimal 1");

				if(pdgDATA[pid][pdgDaging] < amount) return ErrorMsg(playerid, "Jumlah Pizza tidak cukup");

				Inventory_Add(playerid, "Pizza Stack", 19580, amount);
				pdgDATA[pid][pdgDaging] -= amount;
				Pedagang_Save(pid);
				format(string, sizeof(string), "Anda berhasil mengambil %d Pizza dari Gudang", amount);
				SuccesMsg(playerid, string);
			}
			else if(pData[playerid][pdgMenuType] == 2)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah minimal 1");

				if(Inventory_Count(playerid, "Pizza Stack") < amount) return Error(playerid, "Not Enough Pizza");

				Inventory_Remove(playerid, "Pizza Stack", amount);
				pdgDATA[pid][pdgDaging] += amount;
				Pedagang_Save(pid);
				format(string, sizeof(string), "Anda berhasil memasukan %d Pizza ke Gudang", amount);
				SuccesMsg(playerid, string);
			}
		}
	}
	if(dialogid == PDG_SUSU)
	{
		if(response)
		{
			new str[256], pid = pData[playerid][pInPdg];
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pdgMenuType] = 1;
					format(str, sizeof str,"Jus Jeruk: %d\n\nPlease Input amount to Withdraw", pdgDATA[pid][pdgSusuolah]);
				}
				case 1:
				{
					pData[playerid][pdgMenuType] = 2;
					format(str, sizeof str,"Jus Jeruk: %d\n\nPlease Input amount to Deposit", pdgDATA[pid][pdgSusuolah]);
				}
			}
			ShowPlayerDialog(playerid, PDG_SUSU2, DIALOG_STYLE_INPUT, "Jus Jeruk Menu", str, "Input","Cancel");
		}
	}
	if(dialogid == PDG_SUSU2)
	{
		if(response)
		{
			new str[200];
			new amount = strval(inputtext), pid = pData[playerid][pInPdg];
			if(pData[playerid][pdgMenuType] == 1)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah Minimal 1");

				if(pdgDATA[pid][pdgSusuolah] < amount) return Error(playerid, "Not Enough Jus Jeruk");

				Inventory_Add(playerid, "Jus Jeruk", 19563, amount);
				pdgDATA[pid][pdgSusuolah] -= amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil mengambil %d Jus Jeruk dari Gudang", amount);
				SuccesMsg(playerid, str);
			}
			else if(pData[playerid][pdgMenuType] == 2)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah minimal 1");

				if(Inventory_Count(playerid, "Jus Jeruk") < amount) return Error(playerid, "Not Enough Jus Jeruk");

				Inventory_Remove(playerid, "Jus Jeruk", amount);
				pdgDATA[pid][pdgSusuolah] += amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil memasukan %d Jus Jeruk ke Gudang", amount);
				SuccesMsg(playerid, str);
			}
		}
	}
	if(dialogid == PDG_BIGBURGER)
	{
		if(response)
		{
			new str[256], pid = pData[playerid][pInPdg];
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pdgMenuType] = 1;
					format(str, sizeof str,"Nasi Goreng: %d\n\nPlease Input amount to Withdraw", pdgDATA[pid][pdgBurger]);
				}
				case 1:
				{
					pData[playerid][pdgMenuType] = 2;
					format(str, sizeof str,"Nasi Goreng: %d\n\nPlease Input amount to Deposit", pdgDATA[pid][pdgBurger]);
				}
			}
			ShowPlayerDialog(playerid, PDG_BIGBURGER2, DIALOG_STYLE_INPUT, "Burger Menu", str, "Input","Cancel");
		}
	}
	if(dialogid == PDG_BIGBURGER2)
	{
		if(response)
		{
			new str[200];
			new amount = strval(inputtext), pid = pData[playerid][pInPdg];
			if(pData[playerid][pdgMenuType] == 1)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah Minimal 1");

				if(pdgDATA[pid][pdgBurger] < amount) return ErrorMsg(playerid, "Jumlah Nasi Goreng tidak valid");

				Inventory_Add(playerid, "Nasi Goreng", 2221, amount);
				pdgDATA[pid][pdgBurger] -= amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil mengambil %d Nasi Goreng dari Gudang", amount);
				SuccesMsg(playerid, str);
			}
			else if(pData[playerid][pdgMenuType] == 2)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah minimal 1");

				if(Inventory_Count(playerid, "Nasi Goreng") < amount) return ErrorMsg(playerid, "Jumlah Nasi Goreng tidak valid");

				Inventory_Remove(playerid, "Nasi Goreng", amount);
				pdgDATA[pid][pdgBurger] += amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil memasukan %d Nasi Goreng ke Gudang", amount);
				SuccesMsg(playerid, str);
			}
		}
	}
	if(dialogid == PDG_ROTI)
	{
		if(response)
		{
			new str[256], pid = pData[playerid][pInPdg];
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pdgMenuType] = 1;
					format(str, sizeof str,"Roti: %d\n\nPlease Input amount to Withdraw", pdgDATA[pid][pdgRoti]);
				}
				case 1:
				{
					pData[playerid][pdgMenuType] = 2;
					format(str, sizeof str,"Roti: %d\n\nPlease Input amount to Deposit", pdgDATA[pid][pdgRoti]);
				}
			}
			ShowPlayerDialog(playerid, PDG_ROTI2, DIALOG_STYLE_INPUT, "Roti Menu", str, "Input","Cancel");
		}
	}
	if(dialogid == PDG_ROTI2)
	{
		if(response)
		{
			new str[200];
			new amount = strval(inputtext), pid = pData[playerid][pInPdg];
			if(pData[playerid][pdgMenuType] == 1)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah Minimal 1");

				if(pdgDATA[pid][pdgRoti] < amount) return Error(playerid, "Not Enough Roti");

				Inventory_Add(playerid, "Roti", 19579, amount);
				pdgDATA[pid][pdgRoti] -= amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil mengambil %d Roti dari Gudang", amount);
				SuccesMsg(playerid, str);
			}
			else if(pData[playerid][pdgMenuType] == 2)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah minimal 1");

				if(Inventory_Count(playerid, "Roti") < amount) return Error(playerid, "Not Enough Roti");

				Inventory_Remove(playerid, "Roti", amount);
				pdgDATA[pid][pdgRoti] += amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil memasukan %d Roti ke Gudang", amount);
				SuccesMsg(playerid, str);
			}
		}
	}
	if(dialogid == PDG_STEAK)
	{
		if(response)
		{
			new str[256], pid = pData[playerid][pInPdg];
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pdgMenuType] = 1;
					format(str, sizeof str,"Steak: %d\n\nPlease Input amount to Withdraw", pdgDATA[pid][pdgSteak]);
				}
				case 1:
				{
					pData[playerid][pdgMenuType] = 2;
					format(str, sizeof str,"Steak: %d\n\nPlease Input amount to Deposit", pdgDATA[pid][pdgSteak]);
				}
			}
			ShowPlayerDialog(playerid, PDG_STEAK2, DIALOG_STYLE_INPUT, "Steak Menu", str, "Input","Cancel");
		}
	}
	if(dialogid == PDG_STEAK2)
	{
		if(response)
		{
			new str[200];
			new amount = strval(inputtext), pid = pData[playerid][pInPdg];
			if(pData[playerid][pdgMenuType] == 1)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah Minimal 1");

				if(pdgDATA[pid][pdgSteak] < amount) return Error(playerid, "Not Enough Steak");

				Inventory_Add(playerid, "Steak", 19882, amount);
				pdgDATA[pid][pdgSteak] -= amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil mengambil %d Steak dari Gudang", amount);
				SuccesMsg(playerid, str);
			}
			else if(pData[playerid][pdgMenuType] == 2)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah minimal 1");

				if(Inventory_Count(playerid, "Steak") < amount) return Error(playerid, "Not Enough Steak");

				Inventory_Remove(playerid, "Steak", amount);
				pdgDATA[pid][pdgSteak] += amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil memasukan %d Steak ke Gudang", amount);
				SuccesMsg(playerid, str);
			}
		}
	}
	if(dialogid == PDG_MILK)
	{
		if(response)
		{
			new str[256], pid = pData[playerid][pInPdg];
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pdgMenuType] = 1;
					format(str, sizeof str,"Money: %d\n\nPlease Input amount to Withdraw", pdgDATA[pid][pdgMilk]);
				}
				case 1:
				{
					pData[playerid][pdgMenuType] = 2;
					format(str, sizeof str,"Money: %d\n\nPlease Input amount to Deposit", pdgDATA[pid][pdgMilk]);
				}
			}
			ShowPlayerDialog(playerid, PDG_MILK2, DIALOG_STYLE_INPUT, "Milk Menu", str, "Input","Cancel");
		}
	}
	if(dialogid == PDG_MILK2)
	{
		if(response)
		{
			new str[300];
			new amount = strval(inputtext), pid = pData[playerid][pInPdg];
			if(pData[playerid][pdgMenuType] == 1)
			{
				if(pData[playerid][pFactionRank] < 5)
					return ErrorMsg(playerid, "Hanya Faction leader yang dapat menggunakannya");

				if(amount < 1)
					return Error(playerid, "Jumlah Minimal 1");

				if(pdgDATA[pid][pdgMilk] < amount) return ErrorMsg(playerid, "Uang tidak cukup");

				GivePlayerMoneyEx(playerid, amount);
				pdgDATA[pid][pdgMilk] -= amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil mengambil %d Uang dari Gudang", amount);
				SuccesMsg(playerid, str);
			}
			else if(pData[playerid][pdgMenuType] == 2)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah minimal 1");

				if(pData[playerid][pMoney] < amount) return ErrorMsg(playerid, "Uang tidak cukup");

				GivePlayerMoneyEx(playerid, -amount);
				pdgDATA[pid][pdgMilk] += amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil memasukan %d Uang ke Gudang", amount);
				SuccesMsg(playerid, str);
			}
		}
	}
	if(dialogid == PDG_KENTANG)
	{
		if(response)
		{
			new str[256], pid = pData[playerid][pInPdg];
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pdgMenuType] = 1;
					format(str, sizeof str,"Kentang: %d\n\nPlease Input amount to Withdraw", pdgDATA[pid][pdgKentang]);
				}
				case 1:
				{
					pData[playerid][pdgMenuType] = 2;
					format(str, sizeof str,"Kentang: %d\n\nPlease Input amount to Deposit", pdgDATA[pid][pdgKentang]);
				}
			}
			ShowPlayerDialog(playerid, PDG_KENTANG2, DIALOG_STYLE_INPUT, "Milk Menu", str, "Input","Cancel");
		}
	}
	if(dialogid == PDG_KENTANG2)
	{
		if(response)
		{
			new str[200];
			new amount = strval(inputtext), pid = pData[playerid][pInPdg];
			if(pData[playerid][pdgMenuType] == 1)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah Minimal 1");

				if(pdgDATA[pid][pdgKentang] < amount) return Error(playerid, "Not Enough Kentang");

				Inventory_Add(playerid, "Potato", 19577, amount);
				pdgDATA[pid][pdgKentang] -= amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil mengambil %d Potato dari Gudang", amount);
				SuccesMsg(playerid, str);
			}
			else if(pData[playerid][pdgMenuType] == 2)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah minimal 1");

				if(Inventory_Count(playerid, "Potato") < amount) return Error(playerid, "Not Enough Kentang");

				Inventory_Remove(playerid, "Potato", amount);
				pdgDATA[pid][pdgKentang] += amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil memasukan %d Potato ke Gudang", amount);
				SuccesMsg(playerid, str);
			}
		}
	}
	if(dialogid == PDG_ORANGE)
	{
		if(response)
		{
			new str[256], pid = pData[playerid][pInPdg];
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pdgMenuType] = 1;
					format(str, sizeof str,"Orange: %d\n\nPlease Input amount to Withdraw", pdgDATA[pid][pdgOrange]);
				}
				case 1:
				{
					pData[playerid][pdgMenuType] = 2;
					format(str, sizeof str,"Orange: %d\n\nPlease Input amount to Deposit", pdgDATA[pid][pdgOrange]);
				}
			}
			ShowPlayerDialog(playerid, PDG_ORANGE2, DIALOG_STYLE_INPUT, "Milk Menu", str, "Input","Cancel");
		}
	}
	if(dialogid == PDG_ORANGE2)
	{
		if(response)
		{
			new str[300];
			new amount = strval(inputtext), pid = pData[playerid][pInPdg];
			if(pData[playerid][pdgMenuType] == 1)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah Minimal 1");

				if(pdgDATA[pid][pdgOrange] < amount) return Error(playerid, "Not Enough Orange");

				Inventory_Add(playerid, "Orange", 19574, amount);
				pdgDATA[pid][pdgOrange] -= amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil mengambil %d Orange dari Gudang", amount);
				SuccesMsg(playerid, str);
			}
			else if(pData[playerid][pdgMenuType] == 2)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah minimal 1");

				if(Inventory_Count(playerid, "Orange") < amount) return Error(playerid, "Not Enough Kentang");

				Inventory_Remove(playerid, "Orange", amount);
				pdgDATA[pid][pdgOrange] += amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil memasukan %d Orange ke Gudang", amount);
				SuccesMsg(playerid, str);
			}
		}
	}
	if(dialogid == PDG_FOOD)
	{
		if(response)
		{
			new str[256], pid = pData[playerid][pInPdg];
			switch(listitem)
			{
				case 0:
				{
					pData[playerid][pdgMenuType] = 1;
					format(str, sizeof str,"Food: %d\n\nPlease Input amount to Withdraw", pdgDATA[pid][pdgFood]);
				}
				case 1:
				{
					pData[playerid][pdgMenuType] = 2;
					format(str, sizeof str,"Food: %d\n\nPlease Input amount to Deposit", pdgDATA[pid][pdgFood]);
				}
			}
			ShowPlayerDialog(playerid, PDG_FOOD2, DIALOG_STYLE_INPUT, "Milk Menu", str, "Input","Cancel");
		}
	}
	if(dialogid == PDG_FOOD2)
	{
		if(response)
		{
			new str[200];
			new amount = strval(inputtext), pid = pData[playerid][pInPdg];
			if(pData[playerid][pdgMenuType] == 1)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah Minimal 1");

				if(pdgDATA[pid][pdgFood] < amount) return Error(playerid, "Not Enough Food");

				Inventory_Add(playerid, "Food", 19568, amount);
				pdgDATA[pid][pdgFood] -= amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil mengambil %d Food dari Gudang", amount);
				SuccesMsg(playerid, str);
			}
			else if(pData[playerid][pdgMenuType] == 2)
			{
				if(amount < 1)
					return Error(playerid, "Jumlah minimal 1");

				if(Inventory_Count(playerid, "Food") < amount) return Error(playerid, "Not Enough Food");

				Inventory_Remove(playerid, "Food", amount);
				pdgDATA[pid][pdgFood] += amount;
				Pedagang_Save(pid);
				format(str, sizeof(str), "Anda berhasil memasukan %d Food ke Gudang", amount);
				SuccesMsg(playerid, str);
			}
		}
	}
	if(dialogid == DIALOG_COOKING_SACF)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pFaction] != 5)
						return ErrorMsg(playerid, "You must be part of a SACF faction.");

					if(Inventory_Count(playerid, "Roti") < 20) return ErrorMsg(playerid, "Kamu tidak ada Roti. Min : 20 Roti");
					if(Inventory_Count(playerid, "Daging") < 10) return ErrorMsg(playerid, "Kamu tidak ada daging. MIN : 10 Daging");
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					pData[playerid][pLoading] = true;
					Inventory_Remove(playerid, "Roti", 20);
					Inventory_Remove(playerid, "Daging", 10);
					Inventory_Add(playerid, "Big Burger", 2703, 10);

					TogglePlayerControllable(playerid, 0);
					Info(playerid, "Anda memulai membuat burger!");
					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
					pData[playerid][pMasak] = SetTimerEx("cookingsacf", 10000, false, "i", playerid);
					ShowProgressbar(playerid, "Cooking...", 10);
				}
				case 1:
				{
					if(pData[playerid][pFaction] != 5)
						return ErrorMsg(playerid, "Anda tidak bisa mengakses ini.");

					if(Inventory_Count(playerid, "Gandum") < 10) return ErrorMsg(playerid, "Kamu tidak ada gandum. MIN : 10 Gandum");
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					pData[playerid][pLoading] = true;
					Inventory_Remove(playerid, "Gandum", 10);
					Inventory_Add(playerid, "Roti", 19579, 5);

					TogglePlayerControllable(playerid, 0);
					Info(playerid, "Anda memulai membuat roti!");
					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
					pData[playerid][pMasak] = SetTimerEx("cookingsacf", 10000, false, "i", playerid);
					ShowProgressbar(playerid, "Cooking...", 10);
				}
				case 2:
				{
					if(pData[playerid][pFaction] != 5)
						return ErrorMsg(playerid, "Anda tidak dapat mengakses ini.");

					if(Inventory_Count(playerid, "Daging") < 15) return ErrorMsg(playerid, "Kamu tidak ada Daging. MIN : 15 Daging");
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					pData[playerid][pLoading] = true;
					Inventory_Remove(playerid, "Daging", 15);
					Inventory_Add(playerid, "Steak", 19882, 5);

					TogglePlayerControllable(playerid, 0);
					Info(playerid, "Anda memulai membuat steak!");
					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
					pData[playerid][pMasak] = SetTimerEx("cookingsacf", 10000, false, "i", playerid);
					ShowProgressbar(playerid, "Cooking...", 10);
				}
				case 3:
				{
					if(pData[playerid][pFaction] != 5)
						return ErrorMsg(playerid, "Anda tidak dapat mengakses ini.");
						
					if(Inventory_Count(playerid, "Susu Olah") < 10) return ErrorMsg(playerid, "Kamu tidak ada susu olahan. MIN : 10 Susu Olahan");
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					pData[playerid][pLoading] = true;
					Inventory_Remove(playerid, "Susu Olah", 10);
					Inventory_Add(playerid, "Milk", 19570, 10);

					TogglePlayerControllable(playerid, 0);
					Info(playerid, "Anda memulai membuat susu!");
					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
					pData[playerid][pMasak] = SetTimerEx("cookingsacf", 10000, false, "i", playerid);
					ShowProgressbar(playerid, "Cooking...", 10);
				}
			}
		}
	}
	if(dialogid == DIALOG_CALL_911)
	{
		if(response)
		{
			ServiceType[playerid] = listitem;
			if(ServiceIndex[playerid] == 1) ServiceIndex[playerid] = 2; SendClientMessage(playerid, 0x1394BFFF, "911 Dispatch: OK, Tell us more about what's going on.");
		}
		else
		{
			ServiceIndex[playerid] = 0;
			ServiceRequest[playerid] = 0;
			SendClientMessage(playerid, 0x1394BFFF, "911 Dispatch: Alright we will cancel our units. Thank you.");
		    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		    RemovePlayerAttachedObject(playerid, 3);
		}
	}
	if(dialogid == DIALOG_MDC_911)
	{
		if(response)
		{
			new count;
			PlayerPlaySound(playerid, MDC_SELECT, 0, 0, 0);
			forex(i, MAX_EMERGENCY) if(EmergencyData[i][emgExists])
			{
				if(EmergencyData[i][emgSector] == ReturnSector(playerid) && count++ == listitem)
				{
					pData[playerid][pListitem] = i;
					ShowPlayerDialog(playerid, DIALOG_MDC_911_MENU, DIALOG_STYLE_LIST, "MDC - 911 Menu", "Show Details\nRespond Report\nRemove Report", "Select", "Return");
				}		
			}	
		}
	}
	if(dialogid == DIALOG_MDC_911_MENU)
	{
		if(response)
		{
			new id = pData[playerid][pListitem];
			PlayerPlaySound(playerid, MDC_SELECT, 0, 0, 0);
			if(listitem == 0)
			{
				ShowEmergencyDetails(playerid, id);
			}
			if(listitem == 1)
			{
				SendFactionMessage(1, COLOR_RADIO, "[911] %s %s is now responding 911 report with problem %s", GetFactionRank(playerid), ReturnName(playerid), GetProblemType(EmergencyData[id][emgSector], EmergencyData[id][emgType]));
				SendFactionMessage(3, COLOR_RADIO, "[911] %s %s is now responding 911 report with problem %s", GetFactionRank(playerid), ReturnName(playerid), GetProblemType(EmergencyData[id][emgSector], EmergencyData[id][emgType]));
				SendClientMessageEx(playerid, COLOR_RADIO, "[MDC] {FFFFFF}You have respond to emergency call with problem {FFFF00}%s", GetProblemType(EmergencyData[id][emgSector], EmergencyData[id][emgType]));
				SendClientMessageEx(playerid, COLOR_RADIO, "[MDC] {FFFFFF}Location: %s | Name: %s | Number: %d", EmergencyData[id][emgLocation], EmergencyData[id][emgIssuerName], EmergencyData[id][emgNumber]);
				Emergency_Delete(id);
			}
			if(listitem == 2)
			{
				SendClientMessageEx(playerid, COLOR_RADIO, "[MDC] {FFFFFF}Successfully remove selected emergency call.");
				Emergency_Delete(id);
			}
		}
	}
	if(dialogid == DIALOG_PAYBILL)
	{
		if(response)
		{
			new step = 0, idtag;
			new bt[128];
			foreach(new ib: tagihan)
			{
				if(ib != -1)
				{
					if(bilData[ib][bilTarget] == pData[playerid][pID])
					{
						if(step == listitem)
						{
							idtag = ib;
						}
						step++;
					}
				}
			}
			if(pData[playerid][pBankMoney] < bilData[idtag][bilammount])
			{
				Error(playerid, "your bank money is not enough");
			}
			else
			{
				pData[playerid][pBankMoney] -= bilData[idtag][bilammount];
				Server_AddMoney(bilData[idtag][bilammount]);

				new lockertype = bilData[idtag][bilType];
				switch(lockertype)
				{
					case 1:
					{
						lockertype = 0;
					}
					case 2:
					{
						lockertype = 2;
					}
					case 3:
					{
						lockertype = 1;
					}
					case 4:
					{
						lockertype = 3;
					}
					case 5:
					{
						lockertype = 4;
					}
				}

				Fac_AddMoney(lockertype, bilData[idtag][bilammount]);

				Info(playerid, "You paid bill %s for %s", bilData[idtag][bilName], FormatMoney(bilData[idtag][bilammount]));
				SendFactionMessage(bilData[idtag][bilType], -1, "{FFFF00}Invoice: {FFFFFF}%s telah membayar invoice {FFFF00}%s {FFFFFF}sebesar {00FF00}%s", bilData[idtag][billTargetName], bilData[idtag][bilName], FormatMoney(bilData[idtag][bilammount]));
				Iter_Remove(tagihan, idtag);
				mysql_format(g_SQL, bt, sizeof(bt), "DELETE FROM `bill` WHERE `bid`='%d'", idtag);
				mysql_tquery(g_SQL, bt);
			}
		}
		else
		{	

		}
		return 1;
	}
	if(dialogid == DIALOG_STREAMER_CONFIG)
	{
		if(response)
		{
			new config[] = {2000, 1000, 500, 250};
			new const confignames[][24] = {"High", "Medium", "Low", "Potato"};

			Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, config[listitem], playerid);
			Servers(playerid, "You have adjusted maximum streamed object configuration to {FFFF00}%s", confignames[listitem]);
			Streamer_Update(playerid, STREAMER_TYPE_OBJECT);
			pData[playerid][pStreamObj] = config[listitem];
		}
	}
	if(dialogid == DIALOG_INVOICE)
	{
		if(response)
		{
			new count;
			PlayerPlaySound(playerid, MDC_SELECT, 0, 0, 0);
			forex(i, MAX_BILLS)
			{
				if(bilData[i][bilType] == ReturnFa(playerid) && count++ == listitem)
				{
					pData[playerid][pListitem] = i;
					ShowInvoiceDetails(playerid, i);
				}		
			}
		}
	}
	if(dialogid == DIALOG_FIXME)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					InfoTD_MSG(playerid, 4000, "Berhasil mengirim Laporan ~y~/fixme ~w~kepada Administrator");
					SendStaffMessage(-1, "{FFFF00}[ID:%d] {FFFFFF}%s telah menggunakan {FFFF00}'/fixme' {FFFFFF}| Keluhan: {FF0000}[Wrong VW]", playerid, pData[playerid][pName]);
				}
				case 1:
				{
					InfoTD_MSG(playerid, 4000, "Berhasil mengirim Laporan ~y~/fixme ~w~kepada Administrator");
					SendStaffMessage(-1, "{FFFF00}[ID:%d] {FFFFFF}%s telah menggunakan {FFFF00}'/fixme' {FFFFFF}| Keluhan: {FF0000}[Stuck]", playerid, pData[playerid][pName]);
				}
				case 2:
				{
					InfoTD_MSG(playerid, 4000, "Berhasil mengirim Laporan ~y~/fixme ~w~kepada Administrator");
					SendStaffMessage(-1, "{FFFF00}[ID:%d] {FFFFFF}%s telah menggunakan {FFFF00}'/fixme' {FFFFFF}| Keluhan: {FF0000}[Unexpected Death]", playerid, pData[playerid][pName]);
				}
			}
		}
	}
	if(dialogid == DIALOG_SELL_AYAM)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(Inventory_Count(playerid, "Ayam Packing") < 1)
						return ErrorMsg(playerid, "Anda membutuhkan minimal 1 ayam packing");

					new jumlahayam = Inventory_Count(playerid, "Ayam Packing"), price = jumlahayam*40;
					Inventory_Remove(playerid, "Ayam Packing", jumlahayam);
					GivePlayerMoneyEx(playerid, price);
					new strings[150];
					format(strings, sizeof(strings), "Anda berhasil menjual %d ayam packing dengan harga %s", jumlahayam, FormatMoney(price));
					SuccesMsg(playerid, strings);
				}
				case 1:
				{
					Info(playerid, "Coming soon");
				}
			}
		}
	}
	if(dialogid == DIALOG_SELL_MINE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(Inventory_Count(playerid, "Component") < 1)
						return ErrorMsg(playerid, "Anda membutuhkan minimal 1 Component");

					new jumlah = Inventory_Count(playerid, "Component"), price = jumlah*15;
					Inventory_Remove(playerid, "Component", jumlah);
					GivePlayerMoneyEx(playerid, price);
					new strings[150];
					format(strings, sizeof(strings), "Anda berhasil menjual %d Component dengan harga %s", jumlah, FormatMoney(price));
					SuccesMsg(playerid, strings);
					Component += 10;
				}
			}
		}
	}
	if(dialogid == DIALOG_ASETTINGS)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					return callcmd::togreport(playerid, "");
				}
				case 1:
				{
					return callcmd::togask(playerid, "");
				}
				case 2:
				{
					return callcmd::togadminchat(playerid, "");
				}
				case 3:
				{
					return callcmd::togwt(playerid);
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_VOICEMODE)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if((localStream[playerid] = SvCreateDLStreamAtPlayer(20.0, SV_INFINITY, playerid, 0x0300ffff, "")))
                    PlayerTextDrawSetString(playerid, voicemenu[playerid][7], "Medium"); 
			        PlayerTextDrawShow(playerid, voicemenu[playerid][4]);
					PlayerTextDrawShow(playerid, voicemenu[playerid][5]);
                    PlayerTextDrawHide(playerid, voicemenu[playerid][6]);
                    SvAddKey(playerid, 0x42);
                    SvAddKey(playerid, 0x5A);
                }
                case 1:
                {
                    if((localStream[playerid] = SvCreateDLStreamAtPlayer(80.0, SV_INFINITY, playerid, 0x0300ffff, "")))
                    PlayerTextDrawSetString(playerid, voicemenu[playerid][7],"High"); 
			        PlayerTextDrawShow(playerid, voicemenu[playerid][6]);
                    SvAddKey(playerid, 0x42);
                    SvAddKey(playerid, 0x5A);
                }
                case 2:
                {
                    if((localStream[playerid] = SvCreateDLStreamAtPlayer(10.0, SV_INFINITY, playerid, 0x0300ffff, "")))
                    PlayerTextDrawSetString(playerid, voicemenu[playerid][7],"Low"); 
			        PlayerTextDrawShow(playerid, voicemenu[playerid][4]);
                    PlayerTextDrawHide(playerid, voicemenu[playerid][5]);
                    PlayerTextDrawHide(playerid, voicemenu[playerid][6]);
                    SvAddKey(playerid, 0x42);
                    SvAddKey(playerid, 0x5A);
                }
            }
		}
	}
	if(dialogid == DIALOG_BUY_VEHICLE)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                	ShowPlayerDialog(playerid, DIALOG_BUYPVCP, DIALOG_STYLE_LIST, "{7fffd4}SHOWROOM", "Motorcycle\nMobil\nKendaraan Unik\nKendaraan Job\n", "Select", "Cancel");
                }
                case 1:
                {
                   new str[1024];
                   format(str, sizeof(str), "Kendaraan\tHarga\n"WHITE_E"%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days\n%s\t"LG_E"$500 / one days",
                   	GetVehicleModelName(414), 
                   	GetVehicleModelName(455), 
                   	GetVehicleModelName(456),
                   	GetVehicleModelName(498),
                   	GetVehicleModelName(499),
                   	GetVehicleModelName(609),
                   	GetVehicleModelName(478),
                   	GetVehicleModelName(422),
                   	GetVehicleModelName(543),
                   	GetVehicleModelName(554),
                   	GetVehicleModelName(525),
                   	GetVehicleModelName(438),
                   	GetVehicleModelName(420)
                   	);
                   ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARS, DIALOG_STYLE_TABLIST_HEADERS, "Rent Job Cars", str, "Rent", "Close");
                }
            }
        }
    }
	if(dialogid == DIALOG_FMENU)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_GELEDAHFAMILY, DIALOG_STYLE_INPUT, "Geledah | Family", "{FFFFFF}Masukkan Player (ID):", "Geledah", "Tutup");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_MENGIKATFAMILY, DIALOG_STYLE_INPUT, "Mengikat | Family", "{FFFFFF}Masukkan Player (ID):", "Ikat", "Tutup");
				}
				case 2:
				{
					ShowPlayerDialog(playerid, DIALOG_BUKAIKATFAMILY, DIALOG_STYLE_INPUT, "Buka Ikatan | Family", "{FFFFFF}Masukkan Player (ID):", "Buka Ikat", "Tutup");
				}
				case 3:
				{
					ShowPlayerDialog(playerid, DIALOG_PAKSAVEHFAM, DIALOG_STYLE_INPUT, "Masukan Paksa (Kendaraan) | Family", "{FFFFFF}Masukkan Player (ID):", "Masukan", "Tutup");
				}
				case 4:
				{
					ShowPlayerDialog(playerid, DIALOG_KELUARVEHFAM, DIALOG_STYLE_INPUT, "Keluarkan paksa (Kendaraan) | Family", "{FFFFFF}Masukkan Player (ID):", "Keluarkan", "Tutup");
				}
				case 5:
				{
					ShowPlayerDialog(playerid, DIALOG_GENDONGFAM, DIALOG_STYLE_INPUT, "Gendong paksa | Family", "{FFFFFF}Masukkan Player (ID):", "Gendong", "Tutup");
				}
				case 6:
				{
					ShowPlayerDialog(playerid, DIALOG_UNGENDONGFAM, DIALOG_STYLE_INPUT, "Lepas Gendong | Family", "{FFFFFF}Masukkan Player (ID):", "Lepas", "Tutup");
				}
			}
		}
	}
	if(dialogid == DIALOG_GELEDAHFAMILY)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_GELEDAHFAMILY, DIALOG_STYLE_INPUT, "Geledah | Family", "{FFFFFF}Masukkan Player (ID):", "Geledah", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 0, 0, 0, 0, 0, 1);
				SetPlayerChatBubble(playerid, "> Menggeledah <", COLOR_PURPLE, 3.0, 5000);
				ShowInventoryFrisk(playerid, otherid);
				SyntaxMsg(otherid, "Seseorang telah menggeladah paksa anda");
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}
		}		
	}
	if(dialogid == DIALOG_MENGIKATFAMILY)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_MENGIKATFAMILY, DIALOG_STYLE_INPUT, "Mengikat | Family", "{FFFFFF}Masukkan Player (ID):", "Ikat", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				SuccesMsg(playerid, "Player tersebut berhasil di ikat");
				pData[otherid][pCuffed] = 1;
				SetPlayerSpecialAction(otherid, SPECIAL_ACTION_CUFFED);
				SyntaxMsg(otherid, "Seseorang telah mengikat paksa anda");
				SetPlayerChatBubble(playerid, "> Mengikat <", COLOR_PURPLE, 10.0, 4000);
				SetPlayerChatBubble(otherid, "> Terikat <", COLOR_PURPLE, 10.0, 4000);
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}			
		}
	}
	if(dialogid == DIALOG_BUKAIKATFAMILY)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_BUKAIKATFAMILY, DIALOG_STYLE_INPUT, "Buka Ikatan | Family", "{FFFFFF}Masukkan Player (ID):", "Buka Ikat", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(pData[otherid][pCuffed] == 0)
					return ErrorMsg(playerid, "Player tersebut belum di ikat");

				SuccesMsg(playerid, "Anda berhasil membuka ikatan player tersebut");
				pData[otherid][pCuffed] = 0;
				SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);
				InfoMsg(otherid, "Ikatan anda telah di lepas");
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}
		}
	}
	if(dialogid == DIALOG_PAKSAVEHFAM)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new vehicleid = GetNearestVehicle(playerid, 5.0);
			new seatid = 1;
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_PAKSAVEHFAM, DIALOG_STYLE_INPUT, "Masukan Paksa (Kendaraan) | Family", "{FFFFFF}Masukkan Player (ID):", "Masukan", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER && GetPlayerState(otherid) == PLAYER_STATE_PASSENGER)
					return ErrorMsg(playerid, "Player tersebut sudah di dalam kendaraan");
				if(vehicleid == INVALID_VEHICLE_ID)
					return ErrorMsg(playerid, "Tidak ada kendaraan di sekitar anda");
				if(pData[otherid][pCuffed] == 0)
					return ErrorMsg(playerid, "Player tersebut belum di ikat");

				if(GetPlayerVehicleSeat(otherid) == 1) seatid = 2;
				if(GetPlayerVehicleSeat(otherid) == 2) seatid = 3;
				if(GetPlayerVehicleSeat(otherid) == 3 && seatid == 3) seatid = -1;
				SuccesMsg(playerid, "Anda berhasil memasukan player tersebut ke dalam kendaraan secara paksa");
				SyntaxMsg(otherid, "Seseorang telah memasukan anda ke kekendaraan secara paksa");
				SetPlayerChatBubble(playerid, "> Masukan Paksa <", COLOR_PURPLE, 10.0, 4000);

				if(seatid == -1)
					return Error(playerid,"Kursi kendaraan sudah penuh, tidak dapat memasukan paksa!");

				PutPlayerInVehicle(otherid, vehicleid, seatid);
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}
		}
	}
	if(dialogid == DIALOG_KELUARVEHFAM)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_KELUARVEHFAM, DIALOG_STYLE_INPUT, "Keluarkan paksa (Kendaraan) | Family", "{FFFFFF}Masukkan Player (ID):", "Keluarkan", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(GetPlayerState(otherid) == PLAYER_STATE_PASSENGER)
				{
					SuccesMsg(playerid, "Anda berhasil mengeluarkan player tersebut dari kendaraan secara paksa");
					RemovePlayerFromVehicle(otherid);
					InfoMsg(otherid, "Anda telah di keluarkan dari kendaraan secara paksa");
				}
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}
		}
	}
	if(dialogid == DIALOG_GENDONGFAM)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_GENDONGFAM, DIALOG_STYLE_INPUT, "Gendong paksa | Family", "{FFFFFF}Masukkan Player (ID):", "Gendong", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				new dragby = playerid;
				if(dragby == INVALID_PLAYER_ID || dragby == playerid)
					return ErrorMsg(playerid, "Invalid player id");
				if(pData[otherid][pCuffed] == 0)
					return ErrorMsg(playerid, "Player tersebut belum di ikat");

				pData[otherid][pDragged] = 1;
				pData[otherid][pDraggedBy] = dragby;
				pData[playerid][pDraggedBy] = otherid;

				pData[otherid][pDragTimer] = SetTimerEx("DragUpdate", 1000, true, "ii", dragby, otherid);
				SetPlayerChatBubble(playerid, "> Menyeret <", COLOR_PURPLE, 5.0, 4000);
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}
		}
	}
	if(dialogid == DIALOG_UNGENDONGFAM)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_UNGENDONGFAM, DIALOG_STYLE_INPUT, "Lepas Gendong | Family", "{FFFFFF}Masukkan Player (ID):", "Lepas", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(pData[otherid][pDragged] == 0)
					return ErrorMsg(playerid, "Player tersebut belum tergendong");

				DeletePVar(playerid, "DragBy");
				DeletePVar(otherid, "DragBy");
				pData[otherid][pDragged] = 0;
				pData[otherid][pDraggedBy] = INVALID_PLAYER_ID;
				pData[playerid][pDraggedBy] = INVALID_PLAYER_ID;
				KillTimer(pData[otherid][pDragTimer]);					
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}			
		}
	}
	if(dialogid == DIALOG_PDMENU)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_PDGELEDAH, DIALOG_STYLE_INPUT, "Geledah | SAPD", "{FFFFFF}Masukkan Player (ID):", "Geledah", "Tutup");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_PDBORGOL, DIALOG_STYLE_INPUT, "Borgol | SAPD", "{FFFFFF}Masukkan Player (ID):", "Borgol", "Tutup");
				}
				case 2:
				{
					ShowPlayerDialog(playerid, DIALOG_PDUNBORGOL, DIALOG_STYLE_INPUT, "Membuka Borgol | SAPD", "{FFFFFF}Masukkan Player (ID):", "Unborgol", "Tutup");
				}
				case 3:
				{
					ShowPlayerDialog(playerid, DIALOG_MASUKVEHPD, DIALOG_STYLE_INPUT, "Memasukan Paksa (Kendaraan) | SAPD", "{FFFFFF}Masukkan Player (ID):", "Masukan", "Tutup");
				}
				case 4:
				{
					ShowPlayerDialog(playerid, DIALOG_KELUARVEHPD, DIALOG_STYLE_INPUT, "Keluar Paksa (Kendaraan) | SAPD", "{FFFFFF}Masukkan Player (ID):", "Keluar", "Tutup");
				}
				case 5:
				{
					ShowPlayerDialog(playerid, DIALOG_PDGENDONG, DIALOG_STYLE_INPUT, "Gendong Paksa | SAPD", "{FFFFFF}Masukkan Player (ID):", "Gendong", "Tutup");
				}
				case 6:
				{
					ShowPlayerDialog(playerid, DIALOG_PDUNGENDONG, DIALOG_STYLE_INPUT, "Lepas Gendong | SAPD", "{FFFFFF}Masukkan Player (ID):", "Melepaskan", "Tutup");
				}
			}
		}
	}
	if(dialogid == DIALOG_PDGELEDAH)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_PDGELEDAH, DIALOG_STYLE_INPUT, "Geledah | SAPD", "{FFFFFF}Masukkan Player (ID):", "Geledah", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 0, 0, 0, 0, 0, 1);
				SetPlayerChatBubble(playerid, "> Menggeledah <", COLOR_PURPLE, 3.0, 5000);
				ShowInventoryFrisk(playerid, otherid);
				SyntaxMsg(otherid, "Seseorang telah menggeladah paksa anda");
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}
		}		
	}
	if(dialogid == DIALOG_PDBORGOL)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_PDBORGOL, DIALOG_STYLE_INPUT, "Borgol | SAPD", "{FFFFFF}Masukkan Player (ID):", "Borgol", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				SuccesMsg(playerid, "Player tersebut berhasil di Borgol");
				pData[otherid][pCuffed] = 1;
				SetPlayerSpecialAction(otherid, SPECIAL_ACTION_CUFFED);
				SyntaxMsg(otherid, "Seseorang telah memborgol paksa anda");
				SetPlayerChatBubble(playerid, "> Borgol <", COLOR_PURPLE, 10.0, 4000);
				SetPlayerChatBubble(otherid, "> Terborgol <", COLOR_PURPLE, 10.0, 4000);
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}			
		}
	}
	if(dialogid == DIALOG_PDUNBORGOL)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_PDUNBORGOL, DIALOG_STYLE_INPUT, "Membuka Borgol | SAPD", "{FFFFFF}Masukkan Player (ID):", "Unborgol", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(pData[otherid][pCuffed] == 0)
					return ErrorMsg(playerid, "Player tersebut belum di ikat");

				SuccesMsg(playerid, "Anda berhasil membuka ikatan player tersebut");
				pData[otherid][pCuffed] = 0;
				SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);
				InfoMsg(otherid, "Ikatan anda telah di lepas");
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}
		}
	}
	if(dialogid == DIALOG_MASUKVEHPD)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new vehicleid = GetNearestVehicle(playerid, 5.0);
			new seatid = 1;
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_MASUKVEHPD, DIALOG_STYLE_INPUT, "Memasukan Paksa (Kendaraan) | SAPD", "{FFFFFF}Masukkan Player (ID):", "Masukan", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER && GetPlayerState(otherid) == PLAYER_STATE_PASSENGER)
					return ErrorMsg(playerid, "Player tersebut sudah di dalam kendaraan");
				if(vehicleid == INVALID_VEHICLE_ID)
					return ErrorMsg(playerid, "Tidak ada kendaraan di sekitar anda");
				if(pData[otherid][pCuffed] == 0)
					return ErrorMsg(playerid, "Player tersebut belum di ikat");

				if(GetPlayerVehicleSeat(otherid) == 1) seatid = 2;
				if(GetPlayerVehicleSeat(otherid) == 2) seatid = 3;
				if(GetPlayerVehicleSeat(otherid) == 3 && seatid == 3) seatid = -1;
				SuccesMsg(playerid, "Anda berhasil memasukan player tersebut ke dalam kendaraan secara paksa");
				SyntaxMsg(otherid, "Seseorang telah memasukan anda ke kekendaraan secara paksa");
				SetPlayerChatBubble(playerid, "> Masukan Paksa <", COLOR_PURPLE, 10.0, 4000);

				if(seatid == -1)
					return Error(playerid,"Kursi kendaraan sudah penuh, tidak dapat memasukan paksa!");

				PutPlayerInVehicle(otherid, vehicleid, seatid);
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}			
		}
	}
	if(dialogid == DIALOG_KELUARVEHPD)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_KELUARVEHPD, DIALOG_STYLE_INPUT, "Keluar Paksa (Kendaraan) | SAPD", "{FFFFFF}Masukkan Player (ID):", "Keluar", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(GetPlayerState(otherid) == PLAYER_STATE_PASSENGER)
				{
					SuccesMsg(playerid, "Anda berhasil mengeluarkan player tersebut dari kendaraan secara paksa");
					RemovePlayerFromVehicle(otherid);
					InfoMsg(otherid, "Anda telah di keluarkan dari kendaraan secara paksa");
				}
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}			
		}
	}
	if(dialogid == DIALOG_PDGENDONG)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_PDGENDONG, DIALOG_STYLE_INPUT, "Gendong Paksa | SAPD", "{FFFFFF}Masukkan Player (ID):", "Gendong", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				new dragby = playerid;
				if(dragby == INVALID_PLAYER_ID || dragby == otherid)
					return ErrorMsg(playerid, "Invalid player id");
				if(pData[otherid][pCuffed] == 0)
					return ErrorMsg(playerid, "Player tersebut belum di Borgol");

				pData[otherid][pDragged] = 1;
				pData[otherid][pDraggedBy] = dragby;
				pData[playerid][pDraggedBy] = otherid;

				pData[otherid][pDragTimer] = SetTimerEx("DragUpdate", 1000, true, "ii", dragby, otherid);
				SetPlayerChatBubble(playerid, "> Menyeret <", COLOR_PURPLE, 5.0, 4000);
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}
		}
	}
	if(dialogid == DIALOG_PDUNGENDONG)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_PDUNGENDONG, DIALOG_STYLE_INPUT, "Lepas Gendong | SAPD", "{FFFFFF}Masukkan Player (ID):", "Melepaskan", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(pData[otherid][pDragged] == 0)
					return ErrorMsg(playerid, "Player tersebut belum tergendong");

				DeletePVar(playerid, "DragBy");
				DeletePVar(otherid, "DragBy");
				pData[otherid][pDragged] = 0;
				pData[otherid][pDraggedBy] = INVALID_PLAYER_ID;
				pData[playerid][pDraggedBy] = INVALID_PLAYER_ID;
				KillTimer(pData[otherid][pDragTimer]);					
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}			
		}
	}
	if(dialogid == DIALOG_EMSMENU)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_MASUKVEHEMS, DIALOG_STYLE_INPUT, "Memasukan Paksa (Kendaraan) | SAMD", "{FFFFFF}Masukkan Player (ID):", "Masukan", "Tutup");					
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_KELUARVEHEMS, DIALOG_STYLE_INPUT, "Keluar Paksa (Kendaraan) | SAMD", "{FFFFFF}Masukkan Player (ID):", "Masukan", "Tutup");
				}
				case 2:
				{
					ShowPlayerDialog(playerid, DIALOG_GENDONGEMS, DIALOG_STYLE_INPUT, "Gendong Paksa | SAMD", "{FFFFFF}Masukkan Player (ID):", "Gendong", "Tutup");
				}
				case 3:
				{
					ShowPlayerDialog(playerid, DIALOG_UNGENDONGEMS, DIALOG_STYLE_INPUT, "Lepas Gendong | SAMD", "{FFFFFF}Masukkan Player (ID):", "Lepas", "Tutup");
				}
			}
		}
	}
	if(dialogid == DIALOG_MASUKVEHEMS)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new vehicleid = GetNearestVehicle(playerid, 5.0);
			new seatid = 1;
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_MASUKVEHEMS, DIALOG_STYLE_INPUT, "Memasukan Paksa (Kendaraan) | SAMD", "{FFFFFF}Masukkan Player (ID):", "Masukan", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER && GetPlayerState(otherid) == PLAYER_STATE_PASSENGER)
					return ErrorMsg(playerid, "Player tersebut sudah di dalam kendaraan");
				if(vehicleid == INVALID_VEHICLE_ID)
					return ErrorMsg(playerid, "Tidak ada kendaraan di sekitar anda");
				if(pData[otherid][pCuffed] == 0)
					return ErrorMsg(playerid, "Player tersebut belum di ikat");

				if(GetPlayerVehicleSeat(otherid) == 1) seatid = 2;
				if(GetPlayerVehicleSeat(otherid) == 2) seatid = 3;
				if(GetPlayerVehicleSeat(otherid) == 3 && seatid == 3) seatid = -1;
				SuccesMsg(playerid, "Anda berhasil memasukan player tersebut ke dalam kendaraan secara paksa");
				SyntaxMsg(otherid, "Seseorang telah memasukan anda ke kekendaraan secara paksa");
				SetPlayerChatBubble(playerid, "> Masukan Paksa <", COLOR_PURPLE, 10.0, 4000);

				if(seatid == -1)
					return Error(playerid,"Kursi kendaraan sudah penuh, tidak dapat memasukan paksa!");

				PutPlayerInVehicle(otherid, vehicleid, seatid);
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}			
		}
	}
	if(dialogid == DIALOG_KELUARVEHEMS)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_KELUARVEHEMS, DIALOG_STYLE_INPUT, "Keluar Paksa (Kendaraan) | SAMD", "{FFFFFF}Masukkan Player (ID):", "Masukan", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(GetPlayerState(otherid) == PLAYER_STATE_PASSENGER)
				{
					SuccesMsg(playerid, "Anda berhasil mengeluarkan player tersebut dari kendaraan secara paksa");
					RemovePlayerFromVehicle(otherid);
					InfoMsg(otherid, "Anda telah di keluarkan dari kendaraan secara paksa");
				}
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}			
		}
	}
	if(dialogid == DIALOG_GENDONGEMS)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_GENDONGEMS, DIALOG_STYLE_INPUT, "Gendong Paksa | SAMD", "{FFFFFF}Masukkan Player (ID):", "Gendong", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				new dragby = playerid;
				if(dragby == INVALID_PLAYER_ID || dragby == otherid)
					return ErrorMsg(playerid, "Invalid player id");
				if(pData[otherid][pCuffed] == 0)
					return ErrorMsg(playerid, "Player tersebut belum di Borgol");

				pData[otherid][pDragged] = 1;
				pData[otherid][pDraggedBy] = dragby;
				pData[playerid][pDraggedBy] = otherid;

				pData[otherid][pDragTimer] = SetTimerEx("DragUpdate", 1000, true, "ii", dragby, otherid);
				SetPlayerChatBubble(playerid, "> Menyeret <", COLOR_PURPLE, 5.0, 4000);
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}
		}
	}
	if(dialogid == DIALOG_UNGENDONGEMS)
	{
		if(response)
		{
			new otherid = strval(inputtext);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			if(isnull(inputtext) || !IsNumeric(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_UNGENDONGEMS, DIALOG_STYLE_INPUT, "Lepas Gendong | SAMD", "{FFFFFF}Masukkan Player (ID):", "Lepas", "Tutup");

			if(IsPlayerConnected(otherid) && IsPlayerInRangeOfPoint(otherid, 3.0, x, y, z))
			{
				if(pData[otherid][pDragged] == 0)
					return ErrorMsg(playerid, "Player tersebut belum tergendong");

				DeletePVar(playerid, "DragBy");
				DeletePVar(otherid, "DragBy");
				pData[otherid][pDragged] = 0;
				pData[otherid][pDraggedBy] = INVALID_PLAYER_ID;
				pData[playerid][pDraggedBy] = INVALID_PLAYER_ID;
				KillTimer(pData[otherid][pDragTimer]);					
			}
			else
			{
				ErrorMsg(playerid, "Player ID tidak valid, atau sedang tidak berada di sekitar anda");
			}			
		}
	}
	if(dialogid == DIALOG_RADIAL_GELEDAH)
	{
		if(response)
		{
			if(IsAtEvent[playerid] == 1)
				return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

			new otherid;
			if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
				return Error(playerid, "Player tidak berada didekat mu.");

			if(otherid == playerid)
				return Error(playerid, "Kamu tidak bisa memeriksa dirimu sendiri.");

			Info(otherid, "%s You have been searched by someone", ReturnName(playerid));
			Info(playerid, "You're frisking someone %s.", ReturnName(otherid));
		}
	}
	if(dialogid == DIALOG_KENDARAAN)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					callcmd::engine(playerid, "");
				}
				case 1:
				{
					callcmd::light(playerid, "");
				}
				case 2:
				{
					callcmd::hood(playerid, "");
				}
				case 3:
				{
					callcmd::boot(playerid, "");
				}
				case 4:
				{
					callcmd::lock(playerid, "");
				}
				case 5:
				{
					callcmd::neon(playerid, "");
				}
				case 6:
				{
					/*static Float:x, Float:y, Float:z;
					GetVehicleBoot(vehid, x, y, z);
					if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return InfoMsg(playerid, "Anda harus berada diluar kendaran!");
					if(IsABike(vehid)) return ErrorMsg(playerid, "Kendaraan ini tidak memiliki bagasi!");
					if(!IsPlayerInRangeOfPoint(playerid, 1.8, x, y, z)) return ErrorMsg(playerid, "Anda harus berada didekat bagasi!");
					if(TrunkVehEntered[vehid] != INVALID_PLAYER_ID) return ErrorMsg(playerid, "Bagasi telah dimasuki oleh seseorang! (Max)");

					foreach(new carid : PvtVehicles)
					{
						if(vehid == PlayerVehicle[carid][pVehPhysic])
						{
							if(PlayerVehicle[carid][pVehLocked]) 
								return ErrorMsg(playerid, "Kendaraan ini terkunci!");
						}
					}

					TogglePlayerSpectating(playerid, true);
					PlayerSpectateVehicle(playerid, vehid);
					TrunkVehEntered[vehid] = playerid;
					
					AccountData[playerid][pTempVehID] = vehid;
					Info(playerid, "Anda masuk ke dalam bagasi kendaraan "YELLOW"%s"WHITE" gunakan '"YELLOW"/exittrunk"WHITE"' untuk keluar", GetVehicleName(vehid));
					SetPVarInt(playerid, "PlayerInTrunk", 1);*/
				}
			}
		}
		return 1;
	}
	if(dialogid == DIALOG_EMOTE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT || pData[playerid][pInjured] == 1 || pData[playerid][pCuffed] == 1) 
						return Error(playerid, "You can't do at this moment.");
					ApplyAnimation(playerid, "SHOP", "SHP_HandsUp_Scr", 4.1, 0, 0, 0, 1, 0);
				}
				case 1:
				{
					if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT || pData[playerid][pInjured] == 1 || pData[playerid][pCuffed] == 1) 
						return Error(playerid, "You can't do at this moment.");
					ApplyAnimation(playerid, "ON_LOOKERS", "point_loop", 4.1, 1, 0, 0, 0, 0, 1);
				}
				case 2:
				{
					if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT || pData[playerid][pInjured] == 1 || pData[playerid][pCuffed] == 1) 
						return Error(playerid, "You can't do at this moment.");
					ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.1, 1, 0, 0, 0, 0, 1);
				}
				case 3:
				{
					if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT || pData[playerid][pInjured] == 1 || pData[playerid][pCuffed] == 1) 
						return Error(playerid, "You can't do at this moment.");
					ApplyAnimation(playerid, "GANGS", "prtial_gngtlkD", 4.1, 1, 1, 1, 1, 1, 1);
				}
				case 4:
				{
					if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT || pData[playerid][pInjured] == 1 || pData[playerid][pCuffed] == 1) 
						return Error(playerid, "You can't do at this moment.");
					ApplyAnimation(playerid, "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0, 1);
				}
				case 5:
				{
					callcmd::animhelp(playerid, "");
				}
				case 6:
				{
					clearAnimations(playerid);
				}
			}
		}
	}
	if(dialogid == DIALOG_MENUMASAK)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Potato") < 10) return ErrorMsg(playerid, "Potato yang anda miliki tidak cukup (10)");

					Inventory_Remove(playerid, "Potato", 10);
					Inventory_Add(playerid, "Pizza Stack", 19580, 5);
					TogglePlayerControllable(playerid, 0);
					InfoMsg(playerid, "Anda telah memulai memasak");
					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 0, 0, 0, 0, 0, 1);
					//SetTimerEx("Menumasak", 10000, false, "idd", playerid);
					pData[playerid][pMasak] = SetTimerEx("cookingsacf", 10000, false, "i", playerid);
					ShowProgressbar(playerid, "Cooking...", 10);
					return 1;
				}
				case 1:
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Orange") < 5) return ErrorMsg(playerid, "Orange yang anda miliki tidak cukup (5)");

					Inventory_Remove(playerid, "Orange", 5);
					Inventory_Add(playerid, "Jus Jeruk", 19563, 5);
					TogglePlayerControllable(playerid, 0);
					InfoMsg(playerid, "Anda telah memulai memasak");
					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 0, 0, 0, 0, 0, 1);
					//SetTimerEx("Menumasak", 10000, false, "idd", playerid);
					pData[playerid][pMasak] = SetTimerEx("cookingsacf", 10000, false, "i", playerid);
					ShowProgressbar(playerid, "Cooking...", 10);
					return 1;
				}
				case 2:
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Food") < 5) return ErrorMsg(playerid, "Food yang anda miliki tidak cukup (5)");

					Inventory_Remove(playerid, "Food", 5);
					Inventory_Add(playerid, "Steak", 19882, 5);
					TogglePlayerControllable(playerid, 0);
					InfoMsg(playerid, "Anda telah memulai memasak");
					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 0, 0, 0, 0, 0, 1);
					//SetTimerEx("Menumasak", 10000, false, "idd", playerid);
					pData[playerid][pMasak] = SetTimerEx("cookingsacf", 10000, false, "i", playerid);
					ShowProgressbar(playerid, "Cooking...", 10);
					return 1;
				}
				case 3:
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Wheat") < 5) return ErrorMsg(playerid, "Wheat yang anda miliki tidak cukup (5)");

					Inventory_Remove(playerid, "Wheat", 5);
					Inventory_Add(playerid, "Roti", 19579, 5);
					TogglePlayerControllable(playerid, 0);
					InfoMsg(playerid, "Anda telah memulai memasak");
					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 0, 0, 0, 0, 0, 1);
					//SetTimerEx("Menumasak", 10000, false, "idd", playerid);
					pData[playerid][pMasak] = SetTimerEx("cookingsacf", 10000, false, "i", playerid);
					ShowProgressbar(playerid, "Cooking...", 10);
					return 1;
				}
				case 4:
				{
					if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
					if(Inventory_Count(playerid, "Wheat") < 10) return ErrorMsg(playerid, "Wheat yang anda miliki tidak cukup (5)");
					if(Inventory_Count(playerid, "Food") < 10) return ErrorMsg(playerid, "Wheat yang anda miliki tidak cukup (5)");
				
					Inventory_Remove(playerid, "Wheat", 10);
					Inventory_Remove(playerid, "Food", 10);
					Inventory_Add(playerid, "Nasi Goreng", 2221, 5);
					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 0, 0, 0, 0, 0, 1);
					//SetTimerEx("Menumasak", 10000, false, "idd", playerid);
					pData[playerid][pMasak] = SetTimerEx("cookingsacf", 10000, false, "i", playerid);
					ShowProgressbar(playerid, "Cooking...", 10);
					return 1;
				}
			}
		}
	}
	if(dialogid == DIALOG_DOCUMENT)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					callcmd::idcard(playerid, "");
				}
				case 1:
				{
					callcmd::myinsu(playerid, "");
				}
				case 2:
				{
					callcmd::drivelic(playerid, "");
				}
				case 3:
				{
					callcmd::showdrivelic(playerid, "");
				}
			}
		}
	}
	if(dialogid == DIALOG_SAPDMENU)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					callcmd::buyplate(playerid, "");
				}
				case 1:
				{
					callcmd::newtrucklic(playerid, "");
				}
				case 2:
				{
					callcmd::newlumberlic(playerid, "");
				}
			}
		}
	}
	if(dialogid == DIALOG_SPAWN)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					
				}
				case 1:
				{
					
				}
				case 2:
				{
					pData[playerid][pPosX] = 824.3982;
					pData[playerid][pPosY] = -1361.4440;
					pData[playerid][pPosZ] = -0.5078;
					pData[playerid][pPosA] = 319.3926;
					SetCameraBehindPlayer(playerid);
	      			SetPlayerInterior(playerid, 0);
    				SetPlayerVirtualWorld(playerid, 0);
					TogglePlayerControllable(playerid, 1);
					StopAudioStreamForPlayer(playerid);
					SetPlayerSpawn(playerid);
					SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
	        		SpawnPlayer(playerid);
					SuccesMsg(playerid, "Anda berhasil mendarat di Market Station");

			        Servers(playerid, "Hallo "LB_E"%s"WHITE_E"! Selamat datang di Kampung Indo Roleplay", ReturnName(playerid));
					Servers(playerid, "Berhasil memuat basis data karakter anda dalam "RED_E"%dms", GetPlayerPing(playerid));
					Servers(playerid, "Jangan lupa untuk ikuti aturan server!");
					SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFFFF}Press {FFFF00}[N] {FFFFFF}untuk membuka radial menu");
					SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFF00}/fonline {FFFFFF}untuk melihat anggota fraksi online");
			        SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFF00}/vm {FFFFFF}untuk mengubah mode jarak pada {00FF00}Voice");
					SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFF00}/r {FFFFFF}untuk mengaktifkan Radio");
			        SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFF00}/sid {FFFFFF}untuk menampilkan UCP Tags pada player lain");
				}
				case 3:
				{
					new hid, count = GetOwnedHouses(playerid), string[200], string2[1000];
					string2 = "";
					if(GetOwnedHouses(playerid) == 0)
					{
						ErrorMsg(playerid, "Anda tidak memiliki rumah");
						ShowPlayerDialog(playerid, DIALOG_SPAWN, DIALOG_STYLE_TABLIST_HEADERS, "Caption",
						"NO\t-\tLokasi\n\
						#1\t-\tLos Santos Airport\n\
						#2\t-\tOcean Docks (Pelabuhan)\n\
						#3\t-\tMarket Station\n\
						#4\t-\tRumah Pribadi",
						"Spawn", "");
						return 1;
					}

					Loop(itt, (count + 1), 1)
					{
						if(itt == count)
						{
							format(string, sizeof(string), "{FFFFFF}%d.\t%s\n", itt, hData[hid][hAddress]);
							strcat(string2, string);
						}
					}

					ShowPlayerDialog(playerid, DIALOG_HOUSELIST, DIALOG_STYLE_LIST, "Pilih Rumah", string2, "Spawn", "Cancel");

					/*ErrorMsg(playerid, "Coming soon");
					ShowPlayerDialog(playerid, DIALOG_SPAWN, DIALOG_STYLE_TABLIST_HEADERS, "Caption",
					"NO\t-\tLokasi\n\
					#1\t-\tLos Santos Airport\n\
					#2\t-\tOcean Docks (Pelabuhan)\n\
					#3\t-\tMarket Station\n\
					#4\t-\tRumah Pribadi",
					"Spawn", "");*/
				}
				case 4:
				{
					
					return 1;
				
				}
			}
		
		}
	}
	if(dialogid == DIALOG_HOUSELIST)
	{
		if(!response) return 1;
		SetPVarInt(playerid, "SpawnHouse", ReturnPlayerHousesID(playerid, (listitem + 1)));
		ShowPlayerDialog(playerid, DIALOG_SPAWNHOUSE, DIALOG_STYLE_MSGBOX, "Spawn House", "Apakah kamu yakin ingin mendarat di rumah?", "Spawn", "Tidak");
		return 1;
	}
	if(dialogid == DIALOG_SPAWNHOUSE)
	{
		new hid = GetPVarInt(playerid, "SpawnHouse");

		if(response)
		{
			pData[playerid][pPosX] = hData[hid][hExtposX];
			pData[playerid][pPosY] = hData[hid][hExtposY];
			pData[playerid][pPosZ] = hData[hid][hExtposZ];
			HideSpawnMenu(playerid);
			SetCameraBehindPlayer(playerid);
	      	SetPlayerInterior(playerid, 0);
    		SetPlayerVirtualWorld(playerid, 0);
			TogglePlayerControllable(playerid, 1);
			StopAudioStreamForPlayer(playerid);
			SetPlayerSpawn(playerid);
			SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
	        SpawnPlayer(playerid);
			SuccesMsg(playerid, "Anda berhasil mendarat di Rumah");

			Servers(playerid, "Hallo "LB_E"%s"WHITE_E"! Selamat datang di Kampung Indo Roleplay", ReturnName(playerid));
			Servers(playerid, "Berhasil memuat basis data karakter anda dalam "RED_E"%dms", GetPlayerPing(playerid));
			Servers(playerid, "Jangan lupa untuk ikuti aturan server!");
			SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFFFF}Press {FFFF00}[N] {FFFFFF}untuk membuka radial menu");
			SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFF00}/fonline {FFFFFF}untuk melihat anggota fraksi online");
			SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFF00}/vm {FFFFFF}untuk mengubah mode jarak pada {00FF00}Voice");
			SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFF00}/togr {FFFFFF}untuk mengaktifkan radio lalu {FFFF00}'ALT'");
			SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFF00}/rv {FFFFFF}untuk mengubah Frequensi radio");
			SendClientMessage(playerid, -1, "{FFFF00}GUIDE: {FFFF00}/sid {FFFFFF}untuk menampilkan UCP Tags pada player lain");			
		}
		else
		{
			ErrorMsg(playerid, "anda Tidak Memiliki Rumah!");
		}
	}
	if (dialogid == DIALOG_INVENTORY) {
        if (response) {
            new
            name[48], id; //str[156];

            strunpack(name, InventoryData[playerid][listitem][invItem]);
            pData[playerid][pListitem] = listitem;

            if (InventoryData[playerid][listitem][invQuantity] < 1)
                return ErrorMsg(playerid, "Anda belum memilih item apapun");

            switch (pData[playerid][pStorageSelect]) {
                case 0 :  {
                    format(name, sizeof(name), "%s (%d)", name, InventoryData[playerid][listitem][invQuantity]);
                    ShowPlayerDialog(playerid, DIALOG_INVACTION, DIALOG_STYLE_LIST, name, "Use Item\nGive Item", "Select", "Cancel");
                }
                case 1 :  {
                    if ((id = pData[playerid][pCar]) != -1) {
                        if (InventoryData[playerid][listitem][invQuantity] == 1) {
                            Car_AddItem(id, name, InventoryData[playerid][listitem][invModel], 1);
                            Inventory_Remove(playerid, name);

                            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has stored a \"%s\" into the trunk.", ReturnName(playerid), name);
                            RemovePlayerAttachedObject(playerid, 9);
                            Car_ShowTrunk(playerid, id);
                        } else {
                            new ztr[128];
                            format(ztr, sizeof(ztr), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryData[playerid][pData[playerid][pListitem]][invQuantity]);
                            ShowPlayerDialog(playerid, DIALOG_TRUNKPUT, DIALOG_STYLE_INPUT, "Trunk Deposit", ztr, "Store", "Back");
                        }
                    }
                }
            }
        }
    }
    if (dialogid == DIALOG_TRUNK) {
        new carid = pData[playerid][pCar];
        new string[128];
        if (response) {
            if (CarStorage[carid][listitem][cItemExists]) {
                pData[playerid][pStorageItem] = listitem;
                pData[playerid][pListitem] = listitem;

                strunpack(string, CarStorage[carid][listitem][cItemName]);

                format(string, sizeof(string), "%s (Amount: %d)", string, CarStorage[carid][listitem][cItemQuantity]);
                ShowPlayerDialog(playerid, DIALOG_TRUNKOPTION, DIALOG_STYLE_LIST, string, "Take Item\nStore Item", "Select", "Back");
            } else {
                OpenInventory(playerid);

                pData[playerid][pStorageSelect] = 1;
            }
        }
    }
    if (dialogid == DIALOG_TRUNKTAKE) {
        new carid = pData[playerid][pCar];
        new string[32];
        strunpack(string, CarStorage[carid][pData[playerid][pListitem]][cItemName]);
        if (response) {
            new amount = strval(inputtext);

            if (amount < 1 || amount > CarStorage[carid][pData[playerid][pListitem]][cItemQuantity]) {
                new str[156];
                format(str, sizeof(str), "Item: %s (Amount: %d)\n\nPlease enter the quantity that you wish to take for this item:", string, CarStorage[carid][pData[playerid][pListitem]][cItemQuantity]);
                ShowPlayerDialog(playerid, DIALOG_TRUNKTAKE, DIALOG_STYLE_INPUT, "Trunk Take", str, "Take", "Back");

                return 1;
            }
            new id = Inventory_Add(playerid, string, CarStorage[carid][pData[playerid][pStorageItem]][cItemModel], amount);

            if (id == -1)
                return ErrorMsg(playerid, "Inventory Slot anda sudah penuh");

            Car_RemoveItem(carid, string, amount);

            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has taken a \"%s\" from the trunk.", ReturnName(playerid), string);
            Car_ShowTrunk(playerid, carid);
        } else Car_ShowTrunk(playerid, carid);
    }
    if (dialogid == DIALOG_TRUNKOPTION) {
        new
        carid = pData[playerid][pCar],
            itemid = -1,
            string[32];

        itemid = pData[playerid][pStorageItem];

        strunpack(string, CarStorage[carid][itemid][cItemName]);

        if (response) {
            switch (listitem) {
                case 0 :  {
                    if (CarStorage[carid][itemid][cItemQuantity] == 1) {

                        new id = Inventory_Add(playerid, string, CarStorage[carid][itemid][cItemModel], 1);

                        if (id == -1)
                            return ErrorMsg(playerid, "Inventory Slot anda sudah penuh");

                        Car_RemoveItem(carid, string);

                        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has taken a \"%s\" from the trunk.", ReturnName(playerid), string);
                        Car_ShowTrunk(playerid, carid);
                    } else {
                        new str[156];
                        format(str, sizeof(str), "Item: %s (Amount: %d)\n\nPlease enter the quantity that you wish to take for this item:", string, CarStorage[carid][itemid][cItemQuantity]);
                        ShowPlayerDialog(playerid, DIALOG_TRUNKTAKE, DIALOG_STYLE_INPUT, "Trunk Take", str, "Take", "Back");
                    }
                }
                case 1 :  {
                    new id = Inventory_GetItemID(playerid, string);
                    if (id == -1) {
                        Car_ShowTrunk(playerid, carid);

                        return ErrorMsg(playerid, "Anda sudah tidak memiliki barang yang di masukan");
                    } else if (InventoryData[playerid][id][invQuantity] == 1) {
                        Car_AddItem(carid, string, InventoryData[playerid][id][invModel], 1);
                        Inventory_Remove(playerid, string);

                        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s memasukan barang '%s' kedalam trunk", ReturnName(playerid), string);
                        Car_ShowTrunk(playerid, carid);
                    } else if (InventoryData[playerid][id][invQuantity] > 1) {
                        new str[128];
                        pData[playerid][pListitem] = id;
                        format(str, sizeof(str), "Item: %s (Amount: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryData[playerid][id][invQuantity]);
                        ShowPlayerDialog(playerid, DIALOG_TRUNKPUT, DIALOG_STYLE_INPUT, "Trunk Deposit", str, "Store", "Back");
                    }
                }
            }
        } else {
            Car_ShowTrunk(playerid, carid);
        }
    }
    if (dialogid == DIALOG_TRUNKPUT) {
        new
        carid = pData[playerid][pCar],
            string[32];

        strunpack(string, InventoryData[playerid][pData[playerid][pListitem]][invItem]);

        if (response) {
            new amount = strval(inputtext);

            if (amount < 1 || amount > InventoryData[playerid][pData[playerid][pListitem]][invQuantity]) {
                new str[156];
                format(str, sizeof(str), "Item: %s (Amount: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryData[playerid][pData[playerid][pListitem]][invQuantity]);
                ShowPlayerDialog(playerid, DIALOG_TRUNKPUT, DIALOG_STYLE_INPUT, "Car Deposit", str, "Store", "Back");
                return 1;
            }
            Car_AddItem(carid, string, InventoryData[playerid][pData[playerid][pListitem]][invModel], amount);
            Inventory_Remove(playerid, string, amount);

            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has stored a %s into the trunk.", ReturnName(playerid), string);
            Car_ShowTrunk(playerid, carid);
        } else Car_ShowTrunk(playerid, carid);
    }
    if(dialogid == DIALOG_ORDERTAXI)
    {
    	if(response)
    	{
    		if(pData[playerid][pCallTime] >= gettime())
    			return ErrorMsg(playerid, sprintf("Anda harus menggu %d detik lagi, untuk menggunakan panggilan", pData[playerid][pCallTime] - gettime()));

    		if(isnull(inputtext))
    		{
    			ShowPlayerDialog(playerid, DIALOG_ORDERTAXI, DIALOG_STYLE_INPUT, "Taxi", "{FF0000}Input tidak boleh kosong!\n{FFFFFF}Mau kemana anda hari ini?", "Order", "Batal");
    			return 1;
    		}
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			foreach(new tx : Player)
			{
				if(pData[tx][pJob] == 1 || pData[tx][pJob2] == 1)
				{
					SendClientMessageEx(tx, -1, "{FFFF00}<TAXI> {FFFFFF}seseorang telah memesan taxi | Nomor: [{00FF00}%d{FFFFFF}] | Lokasi: %s", pData[playerid][pPhone], GetLocation(x, y, z));
					SendClientMessageEx(tx, -1, "~> %s", inputtext);
					Info(playerid, "Anda telah memesan taxi, mohon tunggu respon dari supir");
				}
			}

			pData[playerid][pCallTime] = gettime() + 30;
    	}
    }
    if(dialogid == DIALOG_PHONELIST)
    {
    	if(response)
    	{
    		switch(listitem)
    		{
    			case 0:
    			{
    				ShowPlayerDialog(playerid, DIALOG_PHONE_DIALUMBER, DIALOG_STYLE_INPUT, "Phone", "Masukan nomor yang akan anda hubungi", "Kirim", "Kembali");
    			}
    			case 1:
    			{
    				ShowPlayerDialog(playerid, DIALOG_NELPONSAPD, DIALOG_STYLE_INPUT, "SAPD", "Apa keluhan anda?", "Kirim", "Batal");
    			}
    			case 2:
    			{
    				ShowPlayerDialog(playerid, DIALOG_NELPONSAMD, DIALOG_STYLE_INPUT, "SAMD", "Apa keluhan anda?", "Kirim", "Batal");
    			}
    		}
    	}
    }
    if(dialogid == DIALOG_NELPONSAPD)
    {
    	if(response)
    	{
			if(pData[playerid][pCallTime] >= gettime())
				return ErrorMsg(playerid, sprintf("Anda harus menggu %d detik lagi, untuk menggunakan panggilan", pData[playerid][pCallTime] - gettime()));
			if(isnull(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_NELPONSAPD, DIALOG_STYLE_INPUT, "SAPD", "Apa keluhan anda?", "Kirim", "Batal");

			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			SyntaxMsg(playerid, "Nomor ini hanya untuk emergency call, mohon tunggu respon dari SAPD!");
			SendFactionMessage(1, -1, "{0900FF}911: {FFFFFF}seseorang telah menggunakan panggilan darudat! | PH: {00FF00}%d{FFFFFF} | Lokasi: %s", pData[playerid][pPhone], GetLocation(x, y, z));
			SendFactionMessage(1, -1, "{FFFF00}Keluhan {FFFFFF}~> %s", inputtext);
			pData[playerid][pCallTime] = gettime() + 60;
    	}
    }
    if(dialogid == DIALOG_NELPONSAMD)
    {
    	if(response)
    	{
			if(pData[playerid][pCallTime] >= gettime())
				return ErrorMsg(playerid, sprintf("Anda harus menggu %d detik lagi, untuk menggunakan panggilan", pData[playerid][pCallTime] - gettime()));
			if(isnull(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_NELPONSAMD, DIALOG_STYLE_INPUT, "SAMD", "Apa keluhan anda?", "Kirim", "Batal");

			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			SyntaxMsg(playerid, "Nomor ini hanya untuk emergency call, mohon tunggu respon dari SAMD!");
			SendFactionMessage(3, -1, "{FF69D8}933: {FFFFFF}seseorang telah menggunakan panggilan darudat! | PH: {00FF00}%d{FFFFFF} | Lokasi: %s", pData[playerid][pPhone], GetLocation(x, y, z));
			SendFactionMessage(3, -1, "{FFFF00}Keluhan {FFFFFF}~> %s", inputtext);
			pData[playerid][pCallTime] = gettime() + 60;    		
    	}
    }
    if(dialogid == DIALOG_ADS)
    {
    	if(response)
    	{
    		switch(listitem)
    		{
    			case 0:
    			{
    				ShowPlayerDialog(playerid, DIALOG_MAKEADS, DIALOG_STYLE_INPUT, "YellowAds | Membuat Iklan", "Input iklan yang akan anda pasang", "Order", "Batal");
    			}
    			case 1:
    			{
    				ShowAdsLog(playerid);
    			}
    		}
    	}
    }
    if(dialogid == DIALOG_MAKEADS)
    {
    	if(response)
    	{
			if(GetPVarInt(playerid, "delay") > gettime()) 
				return ErrorMsg(playerid, "Anda harus menunggu 10 menit untuk menggunakannya lagi");

			if(Inventory_Count(playerid, "Phone") < 1)
				return ErrorMsg(playerid, "Anda tidak memiliki Ponsel");
			
			if(isnull(inputtext))
				return ShowPlayerDialog(playerid, DIALOG_MAKEADS, DIALOG_STYLE_INPUT, "YellowAds | Membuat Iklan", "Input iklan yang akan anda pasang", "Order", "Batal");

			if(strlen(inputtext) >= 100) return ErrorMsg(playerid, "Anda tidak dapat menuliskan lebih dari 100 kata");

			new payout = strlen(inputtext) * 2;

			if(pData[playerid][pBankMoney] < payout) return ErrorMsg(playerid, "Saldo bank anda tidak cukup untuk membuat iklan");

			pData[playerid][pBankMoney] -= payout;
			Server_AddMoney(payout);
			SetPVarInt(playerid, "delay", gettime() + 600);

			foreach(new ii : Player)
			{
				if(pData[ii][pTogAds] == 0)
				{
					SendClientMessageEx(ii, -1, "{FF6600}IKLAN: {FFFFFF}%s", inputtext);
					SendClientMessageEx(ii, -1, "{FF6600}CONTACT: [{FFFFFF}%s{FF6600}] PH: [{FFFFFF}%d{FF6600}] BANK REK: [{FFFFFF}%d{FF6600}]", pData[playerid][pName], pData[playerid][pPhone], pData[playerid][pBankRek]);
				}
			}
			Add_AdsLog(playerid, inputtext);
    	}
    }
    if (dialogid == VEHICLE_INSURANCEADMIN) 
    {
        if (response) 
        {
            new count;
            new targetid = GetPVarInt(playerid, "forceinsurance");
            foreach(new i : PVehicles) 
            {
                if (pvData[i][cClaim] == 1)
                {
                    if (Vehicle_IsOwner(targetid, i) && count++ == listitem) 
                    {
                        pvData[i][cClaim] = 0;
                        pvData[i][cClaimTime] = 0;
                        new Float:x, Float:y, Float:z, Float:a;
                        GetPlayerPos(targetid, x, y, z);
                        GetPlayerFacingAngle(targetid, a);

                        pvData[i][cPosX] = x;
                        pvData[i][cPosY] = y;
                        pvData[i][cPosZ] = z;
                        pvData[i][cPosA] = a;

                        OnPlayerVehicleRespawn(i);

                        Info(targetid, "Admin {A60000}%s {FFFFFF}telah mengambil kendaraan {FFFF00}%s {FFFFFF}anda dari asuransi", pData[playerid][pAdminname], GetVehicleModelName(pvData[i][cModel]));
                        SendAdminMessage(-1, "{A60000}%s {FFFFFF}telah melakukan claim asuransi kepada %s kendaraan %s.", pData[playerid][pAdminname], GetName(targetid), GetVehicleModelName(pvData[i][cModel]));
                    }
                }
            }
        }
    }
	return 1;
}
