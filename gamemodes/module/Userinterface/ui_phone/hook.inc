#include <YSI_Coding/y_hooks>

hook OnPlayerConnect(playerid) {
    CreateHomeScreen(playerid);
    CreateTaxiMenu(playerid);
    CreateGwTelpon(playerid);
    CreateDiaTelpon(playerid);
    CreateSettingsMenu(playerid);
    CreatebankMenu(playerid);
    CreateXMenu(playerid);
    CreateXNotif(playerid);
    CreateLockScreen(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnClickDynPlayerTextDraw(playerid, PlayerText:textid) {
    //======================LOCK SCREEN======================//
    if (textid == LockMenu[playerid][36]) { //matikan hp
        for(new i = 0; i < 39; i++) {
			PlayerTextDrawHide(playerid, LockMenu[playerid][i]);
		}
		RemovePlayerAttachedObject(playerid, 9);
		ClearAnimations(playerid);
		CancelSelectTextDraw(playerid);
		ShowLogo(playerid);
		ShowHunger(playerid);
    }
    if (textid == LockMenu[playerid][37]) { //matikan hp
        for(new i = 0; i < 39; i++) {
			PlayerTextDrawHide(playerid, LockMenu[playerid][i]);
		}
		for(new i = 0; i < 95; i++) {
			PlayerTextDrawShow(playerid, HomeScreen[playerid][i]);
		}
    }

    //======================HOME SCREEN=====================//
    if (textid == HomeScreen[playerid][36]) { //matikan hp
        for(new i = 0; i < 95; i++) {
			PlayerTextDrawHide(playerid, HomeScreen[playerid][i]);
		}
		RemovePlayerAttachedObject(playerid, 9);
		ClearAnimations(playerid);
		CancelSelectTextDraw(playerid);
		ShowLogo(playerid);
		ShowHunger(playerid);
    }
    if (textid == HomeScreen[playerid][94]) { //matikan hp
        for(new i = 0; i < 95; i++) {
			PlayerTextDrawHide(playerid, HomeScreen[playerid][i]);
		}
		for(new i = 0; i < 39; i++) {
			PlayerTextDrawShow(playerid, LockMenu[playerid][i]);
		}
    }
    if (textid == HomeScreen[playerid][37]) { //livestream apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");
		InfoMsg(playerid, "No live steram in sanews local prime");
    }
    if (textid == HomeScreen[playerid][38]) { //camera apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");
		callcmd::selfie(playerid, "");
    }
    if (textid == HomeScreen[playerid][38]) { //camera apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");
		callcmd::selfie(playerid, "");
    }
    if (textid == HomeScreen[playerid][39]) { //notes apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");
		callcmd::notes(playerid, "");
    }
    if (textid == HomeScreen[playerid][40]) { //taxi menu apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");
        for(new i = 0; i < 95; i++) {
            PlayerTextDrawHide(playerid, HomeScreen[playerid][i]);
        }
        for(new i = 0; i < 49; i++) {
            PlayerTextDrawShow(playerid, TaxiMenu[playerid][i]);
        }
    }
    if (textid == HomeScreen[playerid][41]) { //x menu apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");
        for(new i = 0; i < 95; i++) {
            PlayerTextDrawHide(playerid, HomeScreen[playerid][i]);
        }
        for(new i = 0; i < 55; i++) {
            PlayerTextDrawShow(playerid, XMenu[playerid][i]);
        }
        PlayerTextDrawSetString(playerid, XMenu[playerid][39], sprintf("%s", pData[playerid][pTwittername]));
		PlayerTextDrawSetString(playerid, XMenu[playerid][40], sprintf("%s", pData[playerid][pTwitterbio]));
    }
    if (textid == HomeScreen[playerid][42]) { //bank menu apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");

        for(new i = 0; i < 95; i++) {
            PlayerTextDrawHide(playerid, HomeScreen[playerid][i]);
        }
        for(new i = 0; i < 50; i++) {
            PlayerTextDrawShow(playerid, BankMenu[playerid][i]);
        }
        PlayerTextDrawSetString(playerid, BankMenu[playerid][40], sprintf("%d", pData[playerid][pBankRek]));
		PlayerTextDrawSetString(playerid, BankMenu[playerid][42], sprintf("$%d", pData[playerid][pBankMoney]));
    }
    if (textid == HomeScreen[playerid][43]) { //yellow menu apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");

		ShowAdsLog(playerid);
    }
    if (textid == HomeScreen[playerid][44]) { //gps menu apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");

		callcmd::gpstest(playerid, "");
    }
    if (textid == HomeScreen[playerid][66]) { //kontak menu apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");

		DisplayContact(playerid);
    }
    if (textid == HomeScreen[playerid][72]) { //call menu apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");

		ShowPlayerDialog(playerid, DIALOG_PHONELIST, DIALOG_STYLE_LIST, "Phone", "Input Nomor\nSAPD\nSAMD", "Pilih", "Batal");
    }
    if (textid == HomeScreen[playerid][76]) { //messages menu apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");

		ShowPlayerDialog(playerid, DIALOG_PHONE_SENDSMS, DIALOG_STYLE_INPUT, "Messages", "Masukan nomor yang akan anda kirimkan pesan:", "Kirim", "Kembali");
    }
    if (textid == HomeScreen[playerid][79]) { //settings menu apk
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");

        for(new i = 0; i < 95; i++) {
            PlayerTextDrawHide(playerid, HomeScreen[playerid][i]);
        }
		for(new i = 0; i < 62; i++) {
            PlayerTextDrawShow(playerid, SettingsMenu[playerid][i]);
        }
    }

    //===============TAXI PHONE===================//

    if (textid == TaxiMenu[playerid][36]) { //matikan hp taxi
        for(new i = 0; i < 49; i++) {
			PlayerTextDrawHide(playerid, TaxiMenu[playerid][i]);
		}
		RemovePlayerAttachedObject(playerid, 9);
		ClearAnimations(playerid);
		CancelSelectTextDraw(playerid);
		ShowLogo(playerid);
		ShowHunger(playerid);
    }
    if (textid == TaxiMenu[playerid][39]) { //order taxi
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
    if (textid == TaxiMenu[playerid][48]) { //back menu taxi
        for(new i = 0; i < 49; i++) {
			PlayerTextDrawHide(playerid, TaxiMenu[playerid][i]);
		}
        for(new i = 0; i < 95; i++) {
			PlayerTextDrawShow(playerid, HomeScreen[playerid][i]);
		}
    }

    //================BANK MENU=================//

    if (textid == BankMenu[playerid][36]) { //close mbanking
        for(new i = 0; i < 50; i++) {
			PlayerTextDrawHide(playerid, BankMenu[playerid][i]);
		}
        RemovePlayerAttachedObject(playerid, 9);
		ClearAnimations(playerid);
		CancelSelectTextDraw(playerid);
		ShowLogo(playerid);
		ShowHunger(playerid);
    }
    if (textid == BankMenu[playerid][44]) { //INVOICE
        callcmd::mybill(playerid);
    }
    if (textid == BankMenu[playerid][45]) { //TRANSFER
        ShowPlayerDialog(playerid, DIALOG_BANKREKENING, DIALOG_STYLE_INPUT, ""LB_E"MBanking", "Masukan jumlah uang:", "Transfer", "Cancel");
    }
    if (textid == BankMenu[playerid][49]) { //BACK MENU BANK
        for(new i = 0; i < 50; i++) {
			PlayerTextDrawHide(playerid, BankMenu[playerid][i]);
		}
        for(new i = 0; i < 95; i++) {
            PlayerTextDrawShow(playerid, HomeScreen[playerid][i]);
        }
    }

    //=============tweet menu===============//
    if (textid == XMenu[playerid][36]) { //Close X Menu
        for(new i = 0; i < 55; i++) {
			PlayerTextDrawHide(playerid, XMenu[playerid][i]);
		}
        RemovePlayerAttachedObject(playerid, 9);
		ClearAnimations(playerid);
		CancelSelectTextDraw(playerid);
		ShowLogo(playerid);
		ShowHunger(playerid);
    }
    if (textid == XMenu[playerid][44]) { //Change Name
        new str[128];
		format(str, sizeof(str), "Username mu sekarang: @%s\nMasukan nama twitter yang kamu inginkan:", pData[playerid][pTwittername]);
		ShowPlayerDialog(playerid, TWITTER_NAME, DIALOG_STYLE_INPUT, "Twitter Name", str, "Yes", "No");
    }
    if (textid == XMenu[playerid][46]) { //Change Bio
        new str[128];
		format(str, sizeof(str), "Bio mu sekarang: %s\nMasukan bio twitter yang kamu inginkan:", pData[playerid][pTwitterbio]);
		ShowPlayerDialog(playerid, TWITTER_BIO, DIALOG_STYLE_INPUT, "Twitter Bio", str, "Yes", "No");
    }
    if (textid == XMenu[playerid][51]) { //Post Tweet
        new str[64];
		format(str, sizeof(str), "Masukan text postingan yang akan dikirim:");
		ShowPlayerDialog(playerid, TWITTER_POST, DIALOG_STYLE_INPUT, "Twitter Post", str, "Yes", "No");
    }
    if (textid == XMenu[playerid][54]) { //back Menu X Menu
        for(new i = 0; i < 55; i++) {
			PlayerTextDrawHide(playerid, XMenu[playerid][i]);
		}
        for(new i = 0; i < 95; i++) {
            PlayerTextDrawShow(playerid, HomeScreen[playerid][i]);
        }
    }

    //===================settings menu==================//
    if (textid == SettingsMenu[playerid][36]) { //Close X Menu
        for(new i = 0; i < 62; i++) {
			PlayerTextDrawHide(playerid, SettingsMenu[playerid][i]);
		}
        RemovePlayerAttachedObject(playerid, 9);
		ClearAnimations(playerid);
		CancelSelectTextDraw(playerid);
		ShowLogo(playerid);
		ShowHunger(playerid);
    }
    if (textid == SettingsMenu[playerid][37]) { //Tog Phone
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
    }
    if (textid == SettingsMenu[playerid][40]) { //Tog Pm
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
    }
    if (textid == SettingsMenu[playerid][43]) { //Tog Ads
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
    }
    if (textid == SettingsMenu[playerid][46]) { //Airdrop
        if(pData[playerid][pUsePhone] == 0)
			return InfoTD_MSG(playerid, 4000, "Nyalakan terlebih dahulu ~y~Handphone ~w~anda");
		ShowPlayerDialog(playerid, DIALOG_AIRDROP, DIALOG_STYLE_INPUT, "Airdrop", "{FFFFFF}Masukkan Player (ID):", "Give", "Tutup");		
    }
    if (textid == SettingsMenu[playerid][49]) { //Tog log
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
    }
    if (textid == SettingsMenu[playerid][52]) { //Tog log
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
    }
    if (textid == SettingsMenu[playerid][61]) { //Back Menu settings
        for(new i = 0; i < 62; i++) {
			PlayerTextDrawHide(playerid, SettingsMenu[playerid][i]);
		}
        for(new i = 0; i < 95; i++) {
            PlayerTextDrawShow(playerid, HomeScreen[playerid][i]);
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

