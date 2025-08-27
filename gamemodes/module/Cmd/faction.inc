#include <YSI_Coding\y_hooks>
//-----------[ Faction Commands ]------------
CMD:factionhelp(playerid, const params[])
{
	new str[3500];
	if(pData[playerid][pFaction] == 1)
	{
		strcat(str, ""BLUE_E"SAPD: /locker /or (/rf)adio /od /d(epartement) (/gov)ernment (/m)egaphone /invite /uninvite /setrank\n");
		strcat(str, ""WHITE_E"SAPD: /(un)cuff /tazer /detain /arrest /release /flare /destroyflare /checkveh /takedl\n");
		strcat(str, ""BLUE_E"SAPD: /takemarijuana /spike /destroyspike /destroyallspike /findphone /createplate /giveweaplic /takeweaplic /friskpd\n");
		strcat(str, ""BLUE_E"SAPD: /impoundpv /unimpoundpv /pmdc /getlocpd /giveinvoice /invoiceinfo /togspeedcam /takeweapon /roadblock\n");
		strcat(str, ""WHITE_E"NOTE: Lama waktu duty anda akan menjadi gaji anda pada saat paycheck!\n");
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"SAPD", str, "Close", "");
	}
	else if(pData[playerid][pFaction] == 2)
	{
		strcat(str, ""LB_E"SAGS: /locker /or (/rf)adio /od /d(epartement) (/gov)ernment (/m)egaphone /invite /uninvite /setrank\n");
		strcat(str, ""WHITE_E"SAGS: /(un)cuff /sealhouse /giveinvoice /invoiceinfo\n");
		strcat(str, ""WHITE_E"NOTE: Lama waktu duty anda akan menjadi gaji anda pada saat paycheck!\n");
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"SAGS", str, "Close", "");
	}
	else if(pData[playerid][pFaction] == 3)
	{
		strcat(str, ""PINK_E"SAMD: /locker /or (/rf)adio /od /d(epartement) (/gov)ernment (/m)egaphone /invite /uninvite /setrank /detainmd\n");
		strcat(str, ""WHITE_E"SAMD: /loadinjured /dropinjured /ems /healbone /revive /salve /rehab /emdc /getlocmd /treatment /giveinvoice /invoiceinfo\n");
		strcat(str, ""WHITE_E"NOTE: Lama waktu duty anda akan menjadi gaji anda pada saat paycheck!\n");
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"SAMD", str, "Close", "");
	}
	else if(pData[playerid][pFaction] == 4)
	{
		strcat(str, ""ORANGE_E"SANA: /locker /or (/rf)adio /od /d(epartement) (/gov)ernment (/m)egaphone /invite /uninvite /setrank\n");
		strcat(str, ""WHITE_E"SANA: /broadcast /bc /live /inviteguest /removeguest /giveinvoice /invoiceinfo\n");
		strcat(str, ""WHITE_E"NOTE: Lama waktu duty anda akan menjadi gaji anda pada saat paycheck!\n");
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"SANEWS", str, "Close", "");
	}
	else if(pData[playerid][pFaction] == 5)
	{
		strcat(str, ""ORANGE_E"FOOD: /locker /or (/rf)adio /od /d(epartement) (/gov)ernment (/m)egaphone /invite /uninvite /setrank\n");
		strcat(str, ""WHITE_E"FOOD: /menumasak /menuminum /masak /minum /gudangpedagang /giveinvoice /invoiceinfo\n");
		strcat(str, ""WHITE_E"NOTE: Lama waktu duty anda akan menjadi gaji anda pada saat paycheck!\n");
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"SANEWS", str, "Close", "");
	}
	else if(pData[playerid][pFamily] != -1)
	{
		strcat(str, ""WHITE_E"Family: /fsafe /f(amily) /finvite /funinvite /fsetrank /npcfam\n");
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Family", str, "Close", "");
	}
	else
	{
		Error(playerid, "Anda tidak bergabung dalam faction/family manapun!");
	}
	return 1;
}

CMD:friskpd(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
		return ErrorMsg(playerid, "Anda bukan bagian dari SAPD");

	new otherid;
	if(sscanf(params, "u", otherid))
        return SyntaxMsg(playerid, "/friskpd [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
        return ErrorMsg(playerid, "Player sedang tidak berada didekat mu.");

    if(otherid == playerid)
        return Error(playerid, "Kamu tidak bisa memeriksa dirimu sendiri.");

    ShowInventoryFrisk(playerid, otherid);
	return 1;
}

CMD:menumasak(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.5, 586.45, -1820.44, 6.08) && !IsPlayerInRangeOfPoint(playerid, 3.5, 1290.3080, 709.8832, 10.8462)) return ErrorMsg(playerid, "Anda harus berada di dapur SACF");
	if(pData[playerid][pFaction] != 5)
        return ErrorMsg(playerid, "Anda bukan bagian dari Pedagang");

	new Dstring[512];
	format(Dstring, sizeof(Dstring), "Jenis (Jumlah)\tBahan\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sPizza (5)\tPotato 10\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sJus Jeruk (5)\tOrange 5\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sSteak(5)\tFood (5)\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sRoti(5)\tWheat (5)\n", Dstring);
	format(Dstring, sizeof(Dstring), "{FFFFFF}%sNasi Goreng(5)\tWheat + Food (10)", Dstring);
	ShowPlayerDialog(playerid, DIALOG_MENUMASAK, DIALOG_STYLE_TABLIST_HEADERS, "Pedagang - Menu Masak", Dstring, "Pilih", "Batal");
	return 1;
}

function Menumasak(playerid, gunid, ammo)
{
    clearAnimations(playerid);
    TogglePlayerControllable(playerid, 0);
    return 1;
}

CMD:sealhouse(playerid, params[])
{
	if(pData[playerid][pFaction] != 2)
		return Error(playerid, "Kamu bukan anggota SAGS!");

	if(pData[playerid][pFactionRank] < 3)
		return Error(playerid, "Hanya SAGS level 2 keatas yang bisa melakukan ini!");
	
	static hid, type[128];
	if(sscanf(params, "ds[128]", hid, type))
		return Usage(playerid, "/sealhouse [hid] [seal | unseal]");

	if(!strcmp(type, "seal", true))
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]))
		{
			if(!strcmp(hData[hid][hOwner], "-"))
				return Error(playerid,"Kamu tidak dapat menyegel rumah yang tidak memiliki owner");
			
			if(hData[hid][hLocked] >= 2)
				return Error(playerid, "Rumah ini sudah disegel!");

			hData[hid][hLocked] = 2;
			House_Refresh(hid);
			House_Save(hid);

			Info(playerid, "Kamu telah menyegel rumah miliki %s (ID: %d) yang berlokasi di %s", hData[hid][hOwner], hid, GetLocation(hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]));
		}
		else return Error(playerid, "Kamu tidak berada dekat dengan point point tersebut"); 
	}
	if(!strcmp(type, "unseal", true))
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]))
		{
			if(hData[hid][hLocked] != 2)
				return Error(playerid, "Rumah ini tidak disegel!");

			hData[hid][hLocked] = 0;
			House_Refresh(hid);
			House_Save(hid);

			Info(playerid, "Kamu telah membuka segel rumah miliki %s (ID: %d) yang berlokasi di %s", hData[hid][hOwner], hid, GetLocation(hData[hid][hExtposX], hData[hid][hExtposY], hData[hid][hExtposZ]));
		}
		else return Error(playerid, "Kamu tidak berada dekat dengan point rumah tersebut"); 
	}
	return 1;
}

CMD:sealdealer(playerid, params[])
{
	if(pData[playerid][pFaction] != 2)
		return Error(playerid, "Kamu bukan anggota SAGS!");

	if(pData[playerid][pFactionRank] < 3)
		return Error(playerid, "Hanya SAGS level 2 keatas yang bisa melakukan ini!");
	
	static id, type[128];
	if(sscanf(params, "ds[128]", id, type))
		return Usage(playerid, "/sealdealer [id] [seal | unseal]");

	if(!strcmp(type, "seal", true))
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, drData[id][dPosX], drData[id][dPosY], drData[id][dPosZ]))
		{
			if(!strcmp(drData[id][dOwner], "-"))
				return Error(playerid,"Kamu tidak dapat menyegel dealer yang tidak memiliki owner");
			
			if(drData[id][dLock] >= 1)
				return Error(playerid, "dealer ini sudah disegel!");

			drData[id][dLock] = 1;
			Dealer_Refresh(id);
			Dealer_Save(id);

			Info(playerid, "Kamu telah menyegel dealer miliki %s (ID: %d) yang berlokasi di %s", drData[id][dOwner], id, GetLocation(drData[id][dPosX], drData[id][dPosY], drData[id][dPosZ]));
		}
		else return Error(playerid, "Kamu tidak berada dekat dengan point point tersebut"); 
	}
	if(!strcmp(type, "unseal", true))
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, drData[id][dPosX], drData[id][dPosY], drData[id][dPosZ]))
		{
			if(drData[id][dLock] != 1)
				return Error(playerid, "Dealer ini tidak disegel!");

			drData[id][dLock] = 0;
			Dealer_Refresh(id);
			Dealer_Save(id);

			Info(playerid, "Kamu telah membuka segel dealer miliki %s (ID: %d) yang berlokasi di %s", drData[id][dOwner], id, GetLocation(drData[id][dPosX], drData[id][dPosY], drData[id][dPosZ]));
		}
		else return Error(playerid, "Kamu tidak berada dekat dengan point dealer tersebut");
	}
	return 1;
}

CMD:impoundpv(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
    	return Error(playerid, "Kamu harus menjadi police officer.");

    if(pData[playerid][pFactionRank] < 2)
    	return Error(playerid,"Hanya rank 2-5 yang bisa menggunakan ini");

    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
    	return Error(playerid, "Kamu harus turun dari kendaraan");

	new vehicleid = GetNearestVehicleToPlayer(playerid, 5.0, false);

	if(vehicleid == INVALID_VEHICLE_ID)
		return Error(playerid, "Kamu tidak berada didekat Kendaraan apapun");

	new string[1024];
	format(string, sizeof(string), "Anda yakin ingin memberi tilang pada kendaraan %s (ID: %d)", GetVehicleName(vehicleid), vehicleid);
	ShowPlayerDialog(playerid, DIALOG_TICKET, DIALOG_STYLE_MSGBOX, "Dialog Ticket", string, "Yes", "No");

	SetPVarInt(playerid, "GiveTicketVehicle", vehicleid);
	return 1;
}

CMD:unimpoundpv(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
    	return Error(playerid, "Kamu harus menjadi police officer.");

    if(pData[playerid][pFactionRank] < 2)
    	return Error(playerid,"Hanya rank 2-5 yang bisa menggunakan ini");

    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
    	return Error(playerid, "Kamu harus turun dari kendaraan");

	new vehicleid = GetNearestVehicleToPlayer(playerid, 5.0, false);

	if(vehicleid == INVALID_VEHICLE_ID)
		return Error(playerid, "Kamu tidak berada didekat Kendaraan apapun");

	new string[1024];
	format(string, sizeof(string), "Anda yakin ingin menghapus tilang pada kendaraan %s (ID: %d)", GetVehicleName(vehicleid), vehicleid);
	ShowPlayerDialog(playerid, DIALOG_CLEARTICKET, DIALOG_STYLE_MSGBOX, "Clear Ticket", string, "Yes", "No");

	SetPVarInt(playerid, "ClearVehTicket", vehicleid);
	return 1;
}

CMD:giveweaplic(playerid, params[])
{
	if(!pData[playerid][pOnDuty])
		return Error(playerid, "You must on duty to give weapon license.");

	if(pData[playerid][pFaction] != 1)
    	return Error(playerid, "Kamu harus menjadi police officer.");

    if(pData[playerid][pFactionRank] < 2)
    	return Error(playerid,"Hanya rank 2-5 yang bisa menggunakan ini");

    new otherid;
    if(sscanf(params, "d", otherid))
    	return Usage(playerid, "/giveweaplic [playerid]");

    if(otherid == playerid)
    	return Error(playerid, "You cannot use for yourself.");

    if(otherid == INVALID_PLAYER_ID)
    	return Error(playerid, "That player is disconnected.");

    if(!NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "You must be near this player.");

    if(pData[otherid][pWeapLic] == 1)
    	return Error(playerid, "Player tersebut sudah memiliki weapon license");

    pData[otherid][pWeapLic] = 1;
    pData[otherid][pWeapLicTime] = gettime() + (86400 * 8);
    Info(playerid, "Kamu berhasil memberikan %s weapon license dengan masa berlaku 1 minggu", ReturnName(otherid));
    Info(otherid, "%s telah memberikanmu weapon license dengan masa berlaku 1 minggu", ReturnName(playerid));
    return 1;
}

CMD:takeweaplic(playerid, params[])
{
	if(!pData[playerid][pOnDuty])
		return Error(playerid, "You must on duty to take weapon license.");

	if(pData[playerid][pFaction] != 1)
    	return Error(playerid, "Kamu harus menjadi police officer.");

    if(pData[playerid][pFactionRank] < 3)
    	return Error(playerid,"Hanya rank 3-5 yang bisa menggunakan ini");

    new otherid;
    if(sscanf(params, "d", otherid))
    	return Usage(playerid, "/giveweaplic [playerid]");

    if(otherid == playerid)
    	return Error(playerid, "You cannot use for yourself.");

    if(otherid == INVALID_PLAYER_ID)
    	return Error(playerid, "That player is disconnected.");

    if(!NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "You must be near this player.");

    if(pData[otherid][pWeapLic] == 0)
    	return Error(playerid, "Player tersebut tidak memiliki weapon license");

    pData[otherid][pWeapLic] = 0;
    pData[otherid][pWeapLicTime] = 0;
    Info(playerid, "Kamu berhasil menarik weapon license milik %s", ReturnName(otherid));
    Info(otherid, "%s telah menarik weapon license milikmu", ReturnName(playerid));
    return 1;
}

CMD:createplate(playerid, params[])
{
	new vehid = GetPlayerVehicleID(playerid);
	foreach(new i :PVehicles)
	{
		if(vehid == pvData[i][cVeh])
		{
			new rand = RandomEx(1111, 9999);
			format(pvData[i][cPlate], 32, "R %d RP", rand);
			pvData[i][cPlateTime] = gettime() + (15 * 86400);
			
			Vehicle_GetStatus(i);
			RemoveVehicleToys(pvData[i][cVeh]);
			if(IsValidVehicle(pvData[i][cVeh]))
				DestroyVehicle(pvData[i][cVeh]);

			pvData[i][cVeh] = 0;

			OnPlayerVehicleRespawn(i);
			PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
			PutPlayerInVehicle(playerid, pvData[i][cVeh], 0);

			GivePlayerMoneyEx(playerid, -150);
			Server_AddMoney(150);
			Info(playerid, "Kamu telah memasang plat %s pada kendaraan %s(ID: %d)", pvData[i][cPlate], GetVehicleModelName(pvData[i][cModel]), pvData[i][cVeh]);
		}
	}
	return 1;
}

CMD:or(playerid, params[])
{
    new text[128];
    
    if(pData[playerid][pFaction] == 0)
        return Error(playerid, "You must in faction member to use this command");
            
    if(sscanf(params,"s[128]",text))
        return Usage(playerid, "/or(OOC radio) [text]");

    if(strval(text) > 128)
        return Error(playerid,"Text too long.");

    if(pData[playerid][pFaction] == 1) {
        SendFactionMessage(1, COLOR_RADIO, "* (( %s: %s ))", pData[playerid][pName], text);
		//format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
		//SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
    }
    else if(pData[playerid][pFaction] == 2) {
        SendFactionMessage(2, COLOR_RADIO, "* (( %s: %s ))", pData[playerid][pName], text);
		//format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
		//SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
    }
    else if(pData[playerid][pFaction] == 3) {
        SendFactionMessage(3, COLOR_RADIO, "* (( %s: %s ))", pData[playerid][pName], text);
		//format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
		//SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
    }
    else if(pData[playerid][pFaction] == 4) {
        SendFactionMessage(4, COLOR_RADIO, "* (( %s: %s ))", pData[playerid][pName], text);
		//format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
		//SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
    }
    else if(pData[playerid][pFaction] == 5) {
        SendFactionMessage(4, COLOR_RADIO, "* (( %s: %s ))", pData[playerid][pName], text);
		//format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
		//SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
    }
	else if(pData[playerid][pFaction] == 6) {
        SendFactionMessage(4, COLOR_RADIO, "* (( %s: %s ))", pData[playerid][pName], text);
		//format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
		//SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
    }
    else
            return Error(playerid, "You are'nt in any faction");
    return 1;
}

CMD:rf(playerid, params[])
{
    new text[128], mstr[512];
    
    if(pData[playerid][pFaction] == 0)
        return Error(playerid, "You must in faction member to use this command");
    
    if(pData[playerid][pInjured] != 0)
	 	return Error(playerid, "Kamu tidak bisa melakukan ini ketika sedang injured");

	if(GetSignalNearest(playerid) == 0)
		return Error(playerid, "Perangkat anda tidak mendapatkan sinyal di wilayah ini.");
	
    if(sscanf(params,"s[128]",text))
        return Usage(playerid, "/rf(adio) [text]");

    if(strval(text) > 128)
        return Error(playerid,"Text too long.");

    if(pData[playerid][pFaction] == 1) 
    {
    	if(GetSignalNearest(playerid) > 0)
    	{
	        SendFactionMessage(1, COLOR_RADIO, "** [SAPD Radio] %s(%d) %s: %s", GetFactionRank(playerid), pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
		}
    }
    else if(pData[playerid][pFaction] == 2) 
    {
    	if(GetSignalNearest(playerid) > 0)
    	{
	        SendFactionMessage(2, COLOR_RADIO, "** [SAGS Radio] %s(%d) %s: %s", GetFactionRank(playerid),  pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
		}
    }
    else if(pData[playerid][pFaction] == 3) 
    {
    	if(GetSignalNearest(playerid) > 0)
    	{
	        SendFactionMessage(3, COLOR_RADIO, "** [SAMD Radio] %s(%d) %s: %s", GetFactionRank(playerid),  pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
		}
    }
    else if(pData[playerid][pFaction] == 4) 
    {
    	if(GetSignalNearest(playerid) > 0)
    	{
	        SendFactionMessage(4, COLOR_RADIO, "** [SANA Radio] %s(%d) %s: %s", GetFactionRank(playerid),  pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
		}
    }
    else if(pData[playerid][pFaction] == 5) 
    {
    	if(GetSignalNearest(playerid) > 0)
    	{
	        SendFactionMessage(4, COLOR_RADIO, "** [SACF Radio] %s(%d) %s: %s", GetFactionRank(playerid),  pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
		}
    }
	else if(pData[playerid][pFaction] == 6) 
    {
    	if(GetSignalNearest(playerid) > 0)
    	{
	        SendFactionMessage(4, COLOR_RADIO, "** [SACF Radio] %s(%d) %s: %s", GetFactionRank(playerid),  pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<RADIO>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, COLOR_RADIO, 10.0, 3000);
		}
    }
    else
            return Error(playerid, "You are'nt in any faction");
    return 1;
}

CMD:od(playerid, params[])
{
    new text[128];
    
    if(pData[playerid][pFaction] == 0)
        return Error(playerid, "You must in faction member to use this command");
            
    if(sscanf(params,"s[128]",text))
        return Usage(playerid, "/od(OOC departement) [text]");

    if(strval(text) > 128)
        return Error(playerid,"Text too long.");
	
	for(new fid = 1; fid < 5; fid++)
	{
		if(pData[playerid][pFaction] == 1) {
			SendFactionMessage(fid, 0xFFD7004A, "** (( %s: %s ))", pData[playerid][pName], text);
			//format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			//SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else if(pData[playerid][pFaction] == 2) {
			SendFactionMessage(fid, 0xFFD7004A, "** (( %s: %s ))", pData[playerid][pName], text);
			//format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			//SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else if(pData[playerid][pFaction] == 3) {
			SendFactionMessage(fid, 0xFFD7004A, "** (( %s: %s ))", pData[playerid][pName], text);
			//format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			//SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else if(pData[playerid][pFaction] == 4) {
			SendFactionMessage(fid, 0xFFD7004A, "** (( %s: %s ))", pData[playerid][pName], text);
			//format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			//SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else if(pData[playerid][pFaction] == 5) {
			SendFactionMessage(fid, 0xFFD7004A, "** (( %s: %s ))", pData[playerid][pName], text);
			//format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			//SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else if(pData[playerid][pFaction] == 6) {
			SendFactionMessage(fid, 0xFFD7004A, "** (( %s: %s ))", pData[playerid][pName], text);
			//format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			//SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else
				return Error(playerid, "You are'nt in any faction");
	}
    return 1;
}

CMD:d(playerid, params[])
{
    new text[128], mstr[512];
    
    if(pData[playerid][pFaction] == 0)
        return Error(playerid, "You must in faction member to use this command");
    
    if(pData[playerid][pInjured] != 0)
	 	return Error(playerid, "Kamu tidak bisa melakukan ini ketika sedang injured");

    if(sscanf(params,"s[128]",text))
        return Usage(playerid, "/d(epartement) [text]");

    if(strval(text) > 128)
        return Error(playerid,"Text too long.");
	
	for(new fid = 1; fid < 5; fid++)
	{
		if(pData[playerid][pFaction] == 1) 
		{
			SendFactionMessage(fid, 0xFFD7004A, "** [SAPD Departement] %s(%d) %s: %s", GetFactionRank(playerid), pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else if(pData[playerid][pFaction] == 2) 
		{
			SendFactionMessage(fid, 0xFFD7004A, "** [SAGS Departement] %s(%d) %s: %s", GetFactionRank(playerid),  pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else if(pData[playerid][pFaction] == 3) 
		{
			SendFactionMessage(fid, 0xFFD7004A, "** [SAMD Departement] %s(%d) %s: %s", GetFactionRank(playerid),  pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else if(pData[playerid][pFaction] == 4) 
		{
			SendFactionMessage(fid, 0xFFD7004A, "** [SANA Departement] %s(%d) %s: %s", GetFactionRank(playerid),  pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else if(pData[playerid][pFaction] == 5) 
		{
			SendFactionMessage(fid, 0xFFD7004A, "** [SACF Departement] %s(%d) %s: %s", GetFactionRank(playerid),  pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else if(pData[playerid][pFaction] == 6) 
		{
			SendFactionMessage(fid, 0xFFD7004A, "** [SACF Departement] %s(%d) %s: %s", GetFactionRank(playerid),  pData[playerid][pFactionRank], pData[playerid][pName], text);
			format(mstr, sizeof(mstr), "[<DEPARTEMENT>]\n* %s *", text);
			SetPlayerChatBubble(playerid, mstr, 0xFFD7004A, 10.0, 3000);
		}
		else
				return Error(playerid, "You are'nt in any faction");
	}
    return 1;
}

CMD:m(playerid, params[])
{
	new facname[16];
	if(pData[playerid][pFaction] <= 0)
		return Error(playerid, "You are not faction!");
		
	if(isnull(params)) return Usage(playerid, "/m(egaphone) [text]");
	
	if(pData[playerid][pFaction] == 1)
	{
		facname = "SAPD";
	}
	else if(pData[playerid][pFaction] == 2)
	{
		facname = "SAGS";
	}
	else if(pData[playerid][pFaction] == 3)
	{
		facname = "SAMD";
	}
	else if(pData[playerid][pFaction] == 4)
	{
		facname = "SANA";
	}
	else
	{
		facname ="Unknown";
	}
	
	if(strlen(params) > 64) {
        SendNearbyMessage(playerid, 60.0, COLOR_YELLOW, "[%s Megaphone] %s says: %.64s", facname, ReturnName(playerid), params);
        SendNearbyMessage(playerid, 60.0, COLOR_YELLOW, "...%s", params[64]);
    }
    else {
        SendNearbyMessage(playerid, 60.0, COLOR_YELLOW, "[%s Megaphone] %s says: %s", facname, ReturnName(playerid), params);
    }
	return 1;
}

CMD:gov(playerid, params[])
{
	if(pData[playerid][pFaction] <= 0)
		return Error(playerid, "You are not faction!");
		
	if(pData[playerid][pFaction] == 1)
	{
		new lstr[1024];
		format(lstr, sizeof(lstr), "{0066FF}[SAPD] %s {FFFFFF}: %s", pData[playerid][pName], params);
		va_SendClientMessageToAll(-1, lstr);
	}
	else if(pData[playerid][pFaction] == 2)
	{
		new lstr[1024];
		format(lstr, sizeof(lstr), "{5C8459}[SAGS] %s  {FFFFFF}: %s", pData[playerid][pName], params);
		va_SendClientMessageToAll(-1, lstr);
	}
	else if(pData[playerid][pFaction] == 3)
	{
		new lstr[1024];
		format(lstr, sizeof(lstr), "{FF8686}[SAMD] %s {FFFFFF}: %s", pData[playerid][pName], params);
		va_SendClientMessageToAll(-1, lstr);
	}
	else if(pData[playerid][pFaction] == 4)
	{
		new lstr[1024];
		format(lstr, sizeof(lstr), "{FFFF00}[SA-NEWS] %s {FFFFFF}: %s", pData[playerid][pName], params);
		va_SendClientMessageToAll(-1, lstr);
	}
	else if(pData[playerid][pFaction] == 5)
	{
		new lstr[1024];
		format(lstr, sizeof(lstr), "{FF8900}[SACF] %s {FFFFFF}: %s", pData[playerid][pName], params);
		va_SendClientMessageToAll(-1, lstr);
	}
	else if(pData[playerid][pFaction] == 6)
	{
		new lstr[1024];
		format(lstr, sizeof(lstr), "{FF8900}[SACF] %s {FFFFFF}: %s", pData[playerid][pName], params);
		va_SendClientMessageToAll(-1, lstr);
	}
	return 1;
}

CMD:setranksapd(playerid, params[])
{
	new rank, otherid;
	if(pData[playerid][pFactionLead] != 1)
		return Error(playerid, "Kamu bukan leader SAPD");

	if(sscanf(params, "ud", otherid, rank))
        return Usage(playerid, "/setrank [playerid/PartOfName] [rank 1-6]");

	if(otherid == INVALID_PLAYER_ID)
		return Error(playerid, "Invalid ID.");

	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");

	if(pData[otherid][pFaction] != pData[playerid][pFaction])
		return Error(playerid, "This player is not in your devision!");

	if(rank < 1 || rank > 8)
		return Error(playerid, "Rank must be between 1 and 8");

	pData[otherid][pFactionRank] = rank;
	Servers(playerid, "You has set %s faction rank to level %d", pData[otherid][pName], rank);
	Servers(otherid, "%s has set your faction rank to level %d", pData[playerid][pName], rank);
	return 1;
}

CMD:setrank(playerid, params[])
{
	new rank, otherid;
	if(pData[playerid][pFactionLead] == 0 && pData[playerid][pFactionRank] < 5)
		return Error(playerid, "You must faction leader!");
		
	if(sscanf(params, "ud", otherid, rank))
        return Usage(playerid, "/setrank [playerid/PartOfName] [rank 1-6]");
		
	if(otherid == INVALID_PLAYER_ID)
		return Error(playerid, "Invalid ID.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");
	
	if(pData[otherid][pFaction] != pData[playerid][pFaction])
		return Error(playerid, "This player is not in your devision!");

	if(rank < 1 || rank > 6)
		return Error(playerid, "Rank must be between 1 and 6");
	
	pData[otherid][pFactionRank] = rank;
	Servers(playerid, "You has set %s faction rank to level %d", pData[otherid][pName], rank);
	Servers(otherid, "%s has set your faction rank to level %d", pData[playerid][pName], rank);
	return 1;
}

CMD:uninvite(playerid, params[])
{
	if(pData[playerid][pFaction] <= 0)
		return Error(playerid, "You are not faction!");
		
	if(pData[playerid][pFactionRank] < 5)
		return Error(playerid, "You must faction level 5 - 6!");
	
	if(!pData[playerid][pOnDuty])
        return Error(playerid, "You must on duty!.");
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/uninvite [playerid/PartOfName]");
		
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "Invalid ID.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");
	
	if(pData[otherid][pFactionRank] > pData[playerid][pFactionRank])
		return Error(playerid, "You cant kick him.");
		
	pData[otherid][pFactionRank] = 0;
	pData[otherid][pFaction] = 0;
	Servers(playerid, "Anda telah mengeluarkan %s dari faction.", pData[otherid][pName]);
	Servers(otherid, "%s telah mengkick anda dari faction.", pData[playerid][pName]);
	return 1;
}

CMD:invite(playerid, params[])
{
	if(pData[playerid][pFaction] <= 0)
		return Error(playerid, "You are not faction!");
		
	if(pData[playerid][pFactionRank] < 5)
		return Error(playerid, "You must faction level 5 - 6!");
	
	if(!pData[playerid][pOnDuty])
        return Error(playerid, "You must on duty!.");
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/invite [playerid/PartOfName]");
		
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "Invalid ID.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");
	
	if(!NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "You must be near this player.");
	
	if(pData[otherid][pFamily] != -1)
		return Error(playerid, "Player tersebut sudah bergabung family");
		
	if(pData[otherid][pFaction] != 0)
		return Error(playerid, "Player tersebut sudah bergabung faction!");
		
	pData[otherid][pFacInvite] = pData[playerid][pFaction];
	pData[otherid][pFacOffer] = playerid;
	Servers(playerid, "Anda telah menginvite %s untuk menjadi faction.", pData[otherid][pName]);
	Servers(otherid, "%s telah menginvite anda untuk menjadi faction. Type: /accept faction or /deny faction!", pData[playerid][pName]);
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		foreach(new lid : Lockers)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, lData[lid][lPosX], lData[lid][lPosY], lData[lid][lPosZ]))
			{
				if(pData[playerid][pVip] > 0 && lData[lid][lType] == 8)
				{
					ShowPlayerDialog(playerid, DIALOG_LOCKERVIP, DIALOG_STYLE_LIST, "VIP Locker", "Health\nWeapons\nClothing\nVip Toys", "Okay", "Cancel");
				}
				else if(pData[playerid][pFaction] == 1 && pData[playerid][pFaction] == lData[lid][lType])
				{
					ShowPlayerDialog(playerid, DIALOG_LOCKERSAPD, DIALOG_STYLE_LIST, "SAPD Lockers", "Toggle Duty\nHealth\nArmour\nWeapons/Items\nClothing\nClothing War\nMoney", "Proceed", "Cancel");
				}
				else if(pData[playerid][pFaction] == 2 && pData[playerid][pFaction] == lData[lid][lType])
				{
					ShowPlayerDialog(playerid, DIALOG_LOCKERSAGS, DIALOG_STYLE_LIST, "SAGS Lockers", "Toggle Duty\nHealth\nArmour\nWeapons\nClothing\nMoney", "Proceed", "Cancel");
				}
				else if(pData[playerid][pFaction] == 3 && pData[playerid][pFaction] == lData[lid][lType])
				{
					ShowPlayerDialog(playerid, DIALOG_LOCKERSAMD, DIALOG_STYLE_LIST, "SAMD Lockers", "Toggle Duty\nHealth\nArmour\nWeapons/Items\nClothing\nMoney", "Proceed", "Cancel");
				}
				else if(pData[playerid][pFaction] == 4 && pData[playerid][pFaction] == lData[lid][lType])
				{
					ShowPlayerDialog(playerid, DIALOG_LOCKERSANEW, DIALOG_STYLE_LIST, "SANA Lockers", "Toggle Duty\nHealth\nArmour\nWeapons\nClothing\nMoney", "Proceed", "Cancel");
				}
				else if(pData[playerid][pFaction] == 5 && pData[playerid][pFaction] == lData[lid][lType])
				{
					ShowPlayerDialog(playerid, DIALOG_LOCKERSACF, DIALOG_STYLE_LIST, "SACF Lockers", "Toggle Duty\nHealth\nArmour\nWeapons\nClothing\nMoney", "Proceed", "Cancel");
				}
				else if(pData[playerid][pFaction] == 6 && pData[playerid][pFaction] == lData[lid][lType])
				{
					ShowPlayerDialog(playerid, DIALOG_LOCKERMECH, DIALOG_STYLE_LIST, "MECH Lockers", "Toggle Duty", "Proceed", "Cancel");
				}
				else if(pData[playerid][pFaction] == 7 && pData[playerid][pFaction] == lData[lid][lType])
				{
					ShowPlayerDialog(playerid, DIALOG_LOCKERMECH, DIALOG_STYLE_LIST, "TAXI Lockers", "comming soon", "Proceed", "Cancel");
				}
				else return Error(playerid, "You are not in this faction type!");
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

//SAPD Commands
CMD:fonline(playerid, params[])
{
    new sapdOnDuty = 0;
    new govOnline = 0;
    new samdOnDuty = 0;
    new sanaOnline = 0;
    new pdgOnline = 0;

    for (new i = 0; i < MAX_PLAYERS; i++)
    {
        if (IsPlayerConnected(i))
        {
            if (pData[i][pFaction] == 1 && pData[i][pOnDuty]) // Faction ID untuk SAPD
            {
                sapdOnDuty++;
            }
            else if (pData[i][pFaction] == 2 && pData[i][pOnDuty])
            {
            	govOnline++;
            }
            else if (pData[i][pFaction] == 3 && pData[i][pOnDuty]) // Faction ID untuk SAMD
            {
                samdOnDuty++;
            }
            else if (pData[i][pFaction] == 4 && pData[i][pOnDuty])
            {
            	sanaOnline++;
            }
            else if (pData[i][pFaction] == 5 && pData[i][pOnDuty])
            {
            	pdgOnline++;
            }
        }
    }

    new str[500], info[500];
    format(str, sizeof(str), "{FFFFFF}Faction\t{00FF00}Online & Duty\n{0033FF}San Andreas Police Department\t{FFFFFF}%d\n{FF72F2}San Andreas Medic Department\t{FFFFFF}%d\n{5E8060}San Andreas Goverments\t{FFFFFF}%d\n{FFAB00}San Andreas News\t{FFFFFF}%d\n{FFFF00}San Andreas Cafe Food\t{FFFFFF}%d", sapdOnDuty, samdOnDuty, govOnline, sanaOnline, pdgOnline);
    strcat(info, str);
    ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Faction Online", info, "Tutup", "");
    return 1;
}

CMD:flist(playerid, params[])
{
	if(pData[playerid][pFaction] == 0)
		return ErrorMsg(playerid, "Anda belum bergabung ke Faction manapun");

	new duty[16], lstr[1024];
	format(lstr, sizeof(lstr), "Name\tRank\tStatus\tFaction\n");
	foreach(new i: Player)
	{
		if(pData[i][pFaction] == 1)
		{
			switch(pData[i][pOnDuty])
			{
				case 0:
				{
					duty = "Off Duty";
				}
				case 1:
				{
					duty = ""BLUE_E"On Duty";
				}
			}
			format(lstr, sizeof(lstr), "%s%s(%d)\t%s(%d)\t%s\t%s", lstr, pData[i][pName], i, GetFactionRank(i), pData[i][pFactionRank], duty, GetFactionName(i));
			format(lstr, sizeof(lstr), "%s\n", lstr);
		}
		else if(pData[i][pFaction] == 2)
		{
			switch(pData[i][pOnDuty])
			{
				case 0:
				{
					duty = "Off Duty";
				}
				case 1:
				{
					duty = ""BLUE_E"On Duty";
				}
			}
			format(lstr, sizeof(lstr), "%s%s(%d)\t%s(%d)\t%s\t%s", lstr, pData[i][pName], i, GetFactionRank(i), pData[i][pFactionRank], duty, GetFactionName(i));
			format(lstr, sizeof(lstr), "%s\n", lstr);
		}
		else if(pData[i][pFaction] == 3)
		{
			switch(pData[i][pOnDuty])
			{
				case 0:
				{
					duty = "Off Duty";
				}
				case 1:
				{
					duty = ""BLUE_E"On Duty";
				}
			}
			format(lstr, sizeof(lstr), "%s%s(%d)\t%s(%d)\t%s\t%s", lstr, pData[i][pName], i, GetFactionRank(i), pData[i][pFactionRank], duty, GetFactionName(i));
			format(lstr, sizeof(lstr), "%s\n", lstr);
		}
		else if(pData[i][pFaction] == 4)
		{
			switch(pData[i][pOnDuty])
			{
				case 0:
				{
					duty = "Off Duty";
				}
				case 1:
				{
					duty = ""BLUE_E"On Duty";
				}
			}
			format(lstr, sizeof(lstr), "%s%s(%d)\t%s(%d)\t%s\t%s", lstr, pData[i][pName], i, GetFactionRank(i), pData[i][pFactionRank], duty, GetFactionName(i));
			format(lstr, sizeof(lstr), "%s\n", lstr);
		}
		else if(pData[i][pFaction] == 5)
		{
			switch(pData[i][pOnDuty])
			{
				case 0:
				{
					duty = "Off Duty";
				}
				case 1:
				{
					duty = ""BLUE_E"On Duty";
				}
			}
			format(lstr, sizeof(lstr), "%s%s(%d)\t%s(%d)\t%s\t%s", lstr, pData[i][pName], i, GetFactionRank(i), pData[i][pFactionRank], duty, GetFactionName(i));
			format(lstr, sizeof(lstr), "%s\n", lstr);
		}
	}
	format(lstr, sizeof(lstr), "%s\n", lstr);
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Faction Online", lstr, "Close", "");
	return 1;
}

CMD:getlocmd(playerid, params[])
{
	if(pData[playerid][pFaction] != 3)
		return Error(playerid, "Kamu harus menjadi Medic.");

	new otherid;
	if(sscanf(params, "u", otherid))
	{
	    SyntaxMsg(playerid, "/getlocmd <ID/Name>");
	    return true;
	}

	if(pData[playerid][pSuspectTimer] > 1)
		return Error(playerid, "Anad harus menunggu %d detik untuk melanjutkan GetLoc",pData[playerid][pSuspectTimer]);

    if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "Player tersebut belum masuk!");
	
	if(otherid == playerid)
		return Error(playerid, "You cant getloc yourself!");

    new zone[MAX_ZONE_NAME];
	GetPlayer3DZone(otherid, zone, sizeof(zone));
	new Float:sX, Float:sY, Float:sZ;
	GetPlayerPos(otherid, sX, sY, sZ);
	SetPlayerCheckpoint(playerid, sX, sY, sZ, 5.0);
	pData[playerid][pSuspectTimer] = 120;
	Info(playerid, "Target Nama : %s", pData[otherid][pName]);
	Info(playerid, "Target Akun Twitter : %s", pData[otherid][pTwittername]);
	Info(playerid, "Target Akun Twitter Bio : %s", pData[otherid][pTwitterbio]);
	Info(playerid, "Lokasi : %s", zone);
	Info(playerid, "Nomer Telepon : %d", pData[otherid][pPhone]);
	return 1;
}

CMD:getlocpd(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
		return Error(playerid, "Anda harus menjadi SAPD.");

	new otherid;
	if(sscanf(params, "u", otherid))
	{
	    SyntaxMsg(playerid, "/getlocpd <ID/Name>");
	    return true;
	}

	if(pData[playerid][pSuspectTimer] > 1)
		return Error(playerid, "Anad harus menunggu %d detik untuk melanjutkan GetLoc",pData[playerid][pSuspectTimer]);

    if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "Player tersebut belum masuk!");
	
	if(otherid == playerid)
		return Error(playerid, "You cant getloc yourself!");

    new zone[MAX_ZONE_NAME];
	GetPlayer3DZone(otherid, zone, sizeof(zone));
	new Float:sX, Float:sY, Float:sZ;
	GetPlayerPos(otherid, sX, sY, sZ);
	SetPlayerCheckpoint(playerid, sX, sY, sZ, 5.0);
	pData[playerid][pSuspectTimer] = 120;
	Info(playerid, "Target Nama : %s", pData[otherid][pName]);
	Info(playerid, "Target Akun Twitter : %s", pData[otherid][pTwittername]);
	Info(playerid, "Target Akun Twitter Bio : %s", pData[otherid][pTwitterbio]);
	Info(playerid, "Lokasi : %s", zone);
	Info(playerid, "Nomer Telepon : %d", pData[otherid][pPhone]);
	return 1;
}

CMD:flare(playerid, const params[])
{
	if(pData[playerid][pFaction] != 1)
        return Error(playerid, "Kamu harus menjadi police officer.");
		
    new Float:x, Float:y, Float:z, Float:a;
    GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);
	
	if(IsValidDynamicObject(pData[playerid][pFlare]))
		DestroyDynamicObject(pData[playerid][pFlare]);
		
	pData[playerid][pFlare] = CreateDynamicObject(18728, x, y, z-2.8, 0, 0, a-90);
	Info(playerid, "Flare: request backup is actived! /destroyflare to delete flare.");
	SendFactionMessage(1, COLOR_RADIO, "[FLARE] "WHITE_E"Officer %s has request a backup in near (%s).", ReturnName(playerid), GetLocation(x, y, z));
	SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s deployed a flare on the ground.", ReturnName(playerid));
    return 1;
}

CMD:destroyflare(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
        return Error(playerid, "Kamu harus menjadi police officer.");
		
	if(IsValidDynamicObject(pData[playerid][pFlare]))
		DestroyDynamicObject(pData[playerid][pFlare]);
	Info(playerid, "Your flare is deleted.");
	return 1;
}

CMD:detain(playerid, params[])
{
    new vehicleid = GetNearestVehicleToPlayer(playerid, 3.0, false), otherid;

    if(pData[playerid][pFaction] != 1)
        return Error(playerid, "Kamu harus menjadi police officer.");
	
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/detain [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "That player is disconnected.");

    if(otherid == playerid)
        return Error(playerid, "You cannot detained yourself.");

    if(!NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "You must be near this player.");

    if(!pData[otherid][pCuffed])
        return Error(playerid, "The player is not cuffed at the moment.");

    if(vehicleid == INVALID_VEHICLE_ID)
        return Error(playerid, "You are not near any vehicle.");

    if(GetVehicleMaxSeats(vehicleid) < 2)
        return Error(playerid, "You can't detain that player in this vehicle.");

    if(IsPlayerInVehicle(otherid, vehicleid))
    {
        TogglePlayerControllable(otherid, 1);

        RemoveFromVehicle(otherid);
        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s opens the door and pulls %s out the vehicle.", ReturnName(playerid), ReturnName(otherid));
    }
    else
    {
        new seatid = GetAvailableSeat(vehicleid, 2);

        if(seatid == -1)
            return Error(playerid, "There are no more seats remaining.");

        new
            string[64];

        format(string, sizeof(string), "You've been ~r~detained~w~ by %s.", ReturnName(playerid));
        TogglePlayerControllable(otherid, 0);

        //StopDragging(otherid);
        PutPlayerInVehicle(otherid, vehicleid, seatid);

        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s opens the door and places %s into the vehicle.", ReturnName(playerid), ReturnName(otherid));
        InfoTD_MSG(otherid, 4000, string);
    }
    return 1;
}

CMD:detainmd(playerid, params[])
{
    new vehicleid = GetNearestVehicleToPlayer(playerid, 3.0, false), otherid;

    if(pData[playerid][pFaction] != 3)
        return Error(playerid, "Anda bukan bagian dari SAMD");
	
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/detain [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "That player is disconnected.");

    if(otherid == playerid)
        return Error(playerid, "You cannot detained yourself.");

    if(!NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "You must be near this player.");

    if(!pData[otherid][pCuffed])
        return Error(playerid, "The player is not cuffed at the moment.");

    if(vehicleid == INVALID_VEHICLE_ID)
        return Error(playerid, "You are not near any vehicle.");

    if(GetVehicleMaxSeats(vehicleid) < 2)
        return Error(playerid, "You can't detain that player in this vehicle.");

    if(IsPlayerInVehicle(otherid, vehicleid))
    {
        TogglePlayerControllable(otherid, 1);

        RemoveFromVehicle(otherid);
        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s opens the door and pulls %s out the vehicle.", ReturnName(playerid), ReturnName(otherid));
    }
    else
    {
        new seatid = GetAvailableSeat(vehicleid, 2);

        if(seatid == -1)
            return Error(playerid, "There are no more seats remaining.");

        new
            string[64];

        format(string, sizeof(string), "You've been ~r~detained~w~ by %s.", ReturnName(playerid));
        TogglePlayerControllable(otherid, 0);

        //StopDragging(otherid);
        PutPlayerInVehicle(otherid, vehicleid, seatid);

        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s opens the door and places %s into the vehicle.", ReturnName(playerid), ReturnName(otherid));
        InfoMsg(otherid, string);
    }
    return 1;
}

CMD:cuff(playerid, params[])
{
	if(pData[playerid][pFaction] == 1 || pData[playerid][pFaction] == 2)
	{
		if(!pData[playerid][pOnDuty])
			return Error(playerid, "You must on duty to use cuff.");
		
		new otherid;
		if(sscanf(params, "u", otherid))
			return Usage(playerid, "/cuff [playerid/PartOfName]");

		if(otherid == INVALID_PLAYER_ID)
			return Error(playerid, "That player is disconnected.");

		if(otherid == playerid)
			return Error(playerid, "You cannot handcuff yourself.");

		if(!NearPlayer(playerid, otherid, 5.0))
			return Error(playerid, "You must be near this player.");

		if(GetPlayerState(otherid) != PLAYER_STATE_ONFOOT)
			return Error(playerid, "The player must be onfoot before you can cuff them.");

		if(pData[otherid][pCuffed])
			return Error(playerid, "The player is already cuffed at the moment.");

		pData[otherid][pCuffed] = 1;
		SetPlayerSpecialAction(otherid, SPECIAL_ACTION_CUFFED);
		
		new mstr[128];
		format(mstr, sizeof(mstr), "You've been ~r~cuffed~w~ by %s.", ReturnName(playerid));
		InfoTD_MSG(otherid, 4000, mstr);

		SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s tightens a pair of handcuffs on %s's wrists.", ReturnName(playerid), ReturnName(otherid));
	}
	else
	{
		return Error(playerid, "You not police/gov.");
	}
    return 1;
}

/*CMD:createlic(playerid, params[])
{
	if(pData[playerid][pFaction] == 1 || pData[playerid][pFaction] == 2)
	{
		if(!pData[playerid][pOnDuty])
			return Error(playerid, "You must on duty to use create license.");
			
		new String[512], giveplayerid, type;
		if(sscanf(params, "ud", giveplayerid, type))
		{
			SendClientMessageEx(playerid, COLOR_WHITE, "KEGUNAAN: /createlic [playerid] [type]");
			SendClientMessageEx(playerid, COLOR_ORANGE, "Types: 1 = Trucker, 2 = Lumberjack");
			return 1;
		}

		if(!IsPlayerConnected(giveplayerid))
		{
			SendClientMessageEx(playerid, COLOR_ORANGE, "Invalid player specified.");
			return 1;
		}
		switch(type)
		{
		case 1:
			{
				if(pData[giveplayerid][pTruckLic] == 1)
				{
					SendClientMessageEx(playerid, COLOR_RED, "This player already has a Trucking license.");
					return 1;
				}
				format(String, sizeof(String), "You have given a Trucking license to %s.",GetPlayerName(giveplayerid));
				SendClientMessageEx(playerid, COLOR_WHITE, String);
				format(String, sizeof(String), "%s has given you a Trucking license.",ReturnName(playerid));
				SendClientMessageEx(giveplayerid, COLOR_WHITE, String);
				pData[playerid][pTruckLic] = 1;
				pData[playerid][pTruckLicTime] = gettime() + (15 * 86400);
				return 1;
			}
		case 2:
			{
				if(pData[giveplayerid][pLumberLic] == 1)
				{
					SendClientMessageEx(playerid, COLOR_RED, "This player already has a Lumberjack license.");
					return 1;
				}
				format(String, sizeof(String), "You have given a Lumberjack license to %s.",GetPlayerName(giveplayerid));
				SendClientMessageEx(playerid, COLOR_WHITE, String);
				format(String, sizeof(String), "%s has given you a Lumberjack license.",ReturnName(playerid));
				pData[playerid][pLumberLic] = 1;
				pData[playerid][pLumberLicTime] = gettime() + (15 * 86400);
				return 1;
			}
		default:
			{
				SendClientMessageEx(playerid, COLOR_WHITE, "Invalid license type! /givelicense [playerid] [type]");
				SendClientMessageEx(playerid, COLOR_ORANGE, "Types: 1 = Trucker, 2 = Lumberjack");
			}
		}
	}
	return 1;
}*/

CMD:takeweapon(playerid, params[])
{
	if(pData[playerid][pFaction] == 1)
        return Error(playerid, "Kamu harus menjadi police officer.");
	{
		new otherid;
		if(sscanf(params, "u", playerid)) return Usage(playerid, "USAGE: /takeweapon [playerid/partofname]");

		if(IsPlayerConnected(playerid))
		{
			ResetPlayerWeaponsEx(playerid);
			Info(playerid, "You has taken gun from %s", pData[otherid][pName]);
			Info(otherid, "Officer %s has taken your gun.", pData[playerid][pName]);
		}
	}
	return 1;
}

CMD:uncuff(playerid, params[])
{
	if(pData[playerid][pFaction] == 1 || pData[playerid][pFaction] == 2)
	{
	
		if(!pData[playerid][pOnDuty])
			return Error(playerid, "You must on duty to use cuff.");
		
		new otherid;
		if(sscanf(params, "u", otherid))
			return Usage(playerid, "/uncuff [playerid/PartOfName]");

		if(otherid == INVALID_PLAYER_ID)
			return Error(playerid, "That player is disconnected.");

		if(otherid == playerid)
			return Error(playerid, "You cannot uncuff yourself.");

		if(!NearPlayer(playerid, otherid, 5.0))
			return Error(playerid, "You must be near this player.");

		if(!pData[otherid][pCuffed])
			return Error(playerid, "The player is not cuffed at the moment.");

		static
			string[64];

		pData[otherid][pCuffed] = 0;
		SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);

		format(string, sizeof(string), "You've been ~g~uncuffed~w~ by %s.", ReturnName(playerid));
		InfoTD_MSG(otherid, 4000, string);

		SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s loosens the pair of handcuffs on %s's wrists.", ReturnName(playerid), ReturnName(otherid));
	}
	else
	{
		return Error(playerid, "You not police/gov.");
	}
    return 1;
}

CMD:release(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
        return Error(playerid, "Kamu harus menjadi police officer.");
	
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 1097.26, -1665.73, 15.03))
		return Error(playerid, "You must be near an arrest point.");

	new otherid;
	if(sscanf(params, "u", otherid))
	{
	    Usage(playerid, "/release <ID/Name>");
	    return true;
	}

    if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "Player tersebut belum masuk!");
	
	if(otherid == playerid)
		return Error(playerid, "You cant release yourself!");

	if(pData[otherid][pArrest] == 0)
	    return Error(playerid, "The player isn't in arrest!");

	pData[otherid][pArrest] = 0;
	pData[otherid][pArrestTime] = 0;
	PlayerTextDrawHide(otherid, Time[playerid][0]);
	SetPlayerInterior(otherid, 0);
	SetPlayerVirtualWorld(otherid, 0);
	SetPlayerPositionEx(otherid,  1097.26, -1665.73, 15.03, 2000);
	SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);

	SendClientMessageToAllEx(COLOR_BLUE, "[PRISON]"WHITE_E"Officer %s telah membebaskan %s dari penjara.", ReturnName(playerid), ReturnName(otherid));
	return true;
}


CMD:arrest(playerid, params[])
{
    static
        denda,
		cellid,
        times,
		otherid;

    if(pData[playerid][pFaction] != 1)
        return Error(playerid, "Kamu harus menjadi police officer.");
		
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 1097.26, -1665.73, 15.03))
		return Error(playerid, "You must be near an arrest point.");

    if(sscanf(params, "uddd", otherid, cellid, times, denda))
        return Usage(playerid, "/arrest [playerid/PartOfName] [cell id] [minutes] [denda]");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "The player is disconnected or not near you.");
		
	/*if(otherid == playerid)
		return Error(playerid, "You cant arrest yourself!");*/

    if(times < 1 || times > 120)
        return Error(playerid, "The specified time can't be below 1 or above 120.");
		
	if(cellid < 1 || cellid > 4)
        return Error(playerid, "The specified cell id can't be below 1 or above 4.");
		
	if(denda < 100 || denda > 20000)
        return Error(playerid, "The specified denda can't be below 100 or above 20,000.");

    /*if(!IsPlayerNearArrest(playerid))
        return Error(playerid, "You must be near an arrest point.");*/

	GivePlayerMoneyEx(otherid, -denda);
    pData[otherid][pArrest] = cellid;
    pData[otherid][pArrestTime] = times * 60;
	
	SetPlayerArrest(otherid, cellid);

    
    SendClientMessageToAllEx(COLOR_BLUE, "PRISON:"WHITE_E" %s telah ditangkap dan dipenjarakan oleh polisi selama %d bulan dengan denda "GREEN_E"%s.", ReturnName(otherid), times, FormatMoney(denda));
    return 1;
}

CMD:findphone(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
		return Error(playerid, "Kamu harus menjadi police officer.");

	new otherid;
	if(sscanf(params, "u", otherid))
	{
	    Usage(playerid, "/findphone <ID/Name>");
	    return true;
	}

	if(pData[playerid][pSuspectTimer] > 1)
		return Error(playerid, "Anad harus menunggu %d detik untuk melanjutkan GetLoc",pData[playerid][pSuspectTimer]);

    if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "Player tersebut belum masuk!");
	
	if(otherid == playerid)
		return Error(playerid, "You cant getloc yourself!");

	if(Inventory_Count(otherid, "Phone") < 1)
		return Error(playerid, "Player tersebut tidak memiliki Ponsel!");
	if(pData[otherid][pUsePhone] == 0) return Error(playerid, "Tidak dapat mendeteksi lokasi, Ponsel tersebut yang dituju sedang Offline");

    new zone[MAX_ZONE_NAME];
	GetPlayer3DZone(otherid, zone, sizeof(zone));
	new Float:sX, Float:sY, Float:sZ;
	GetPlayerPos(otherid, sX, sY, sZ);
	SetPlayerCheckpoint(playerid, sX, sY, sZ, 5.0);
	Info(playerid, "Target Nama : %s", pData[otherid][pName]);
	Info(playerid, "Target Akun Twitter : %s", pData[otherid][pTwittername]);
	Info(playerid, "Target Akun Twitter Bio : %s", pData[otherid][pTwitterbio]);
	Info(playerid, "Lokasi : %s", zone);
	Info(playerid, "Nomer Telepon : %d", pData[otherid][pPhone]);
	return 1;
}

CMD:su(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
		return ErrorMsg(playerid, "Kamu harus menjadi police officer.");

	new crime[64], otherid;
	if(sscanf(params, "us[64]", otherid, crime)) return SyntaxMsg(playerid, "(/su)spect [playerid] [crime discription]");

	if (pData[playerid][pFaction] == 1 || pData[playerid][pFaction] == 2)
	{
		if(IsPlayerConnected(otherid))
		{
			if(otherid != INVALID_PLAYER_ID)
			{
				if(otherid == playerid)
				{
					ErrorMsg(playerid, "Anda tidak dapat mensuspek dirimu");
					return 1;
				}
				pData[otherid][pSuspect] = 1;
				new string[250];
				format(string, sizeof(string), "{FFFF00}[SUSPECT] {FFFFFF}Officer: %s has suspected %s [ID:%d] | Crime Description : %s", pData[playerid][pName], pData[otherid][pName], otherid, crime);
				SendFactionMessage(1, -1, string);
				return 1;
			}
		}
		else
		{
			ErrorMsg(playerid, "Invalid player specified.");
			return 1;
		}
	}
	else
	{
		ErrorMsg(playerid, "Anda bukan bagian dari SAPD");
	}
	return 1;
}

CMD:ticket(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
			return Error(playerid, "Kamu harus menjadi sapd officer.");
	
	new vehid, ticket;
	if(sscanf(params, "dd", vehid, ticket))
		return Usage(playerid, "/ticket [vehid] [ammount] | /checkveh - for find vehid");
	
	if(vehid == INVALID_VEHICLE_ID || !IsValidVehicle(vehid))
		return Error(playerid, "Invalid id");
	
	if(ticket < 0 || ticket > 500)
		return Error(playerid, "Ammount max of ticket is $1 - $500!");
	
	new nearid = GetNearestVehicleToPlayer(playerid, 5.0, false);
	
	foreach(new ii : PVehicles)
	{
		if(vehid == pvData[ii][cVeh])
		{
			if(vehid == nearid)
			{
				if(pvData[ii][cTicket] >= 2000)
					return Error(playerid, "Kendaraan ini sudah mempunyai terlalu banyak ticket!");
					
				pvData[ii][cTicket] += ticket;
				Info(playerid, "Anda telah menilang kendaraan %s(id: %d) dengan denda sejumlah "RED_E"%s", GetVehicleName(vehid), vehid, FormatMoney(ticket));
				return 1;
			}
			else return Error(playerid, "Anda harus berada dekat dengan kendaraan tersebut!");
		}
	}
	return 1;
}

CMD:checkveh(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
		if(pData[playerid][pAdmin] < 1)
			return Error(playerid, "Kamu harus menjadi sapd officer.");
		
	static carid = -1;
	new vehicleid = GetNearestVehicleToPlayer(playerid, 3.0, false);

	if(vehicleid == INVALID_VEHICLE_ID || !IsValidVehicle(vehicleid))
		return Error(playerid, "You not in near any vehicles.");
	
	if((carid = Vehicle_Nearest(playerid)) != -1)
	{
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "SELECT username FROM players WHERE reg_id='%d'", pvData[carid][cOwner]);
		new Cache:result = mysql_query(g_SQL, query);
		new rows = cache_num_rows();
		if(rows) 
		{
			new owner[32];
			cache_get_value_index(0, 0, owner);
			cache_delete(result);
			
			if(strcmp(pvData[carid][cPlate], "None"))
			{
				Info(playerid, "ID: %d | Model: %s | Owner: %s | Plate: %s | Plate Time: %s", vehicleid, GetVehicleName(vehicleid), owner, pvData[carid][cPlate], ReturnTimelapse(gettime(), pvData[carid][cPlateTime]));
			}
			else
			{
				Info(playerid, "ID: %d | Model: %s | Owner: %s | Plate: None | Plate Time: None", vehicleid, GetVehicleName(vehicleid), owner);
			}
		}
		else
		{
			Error(playerid, "This vehicle no owned found!");
			return 1;
		}
	}
	else
	{
		Error(playerid, "You are not in near owned private vehicle.");
		return 1;
	}
	return 1;
}


CMD:takemarijuana(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
        return Error(playerid, "Kamu harus menjadi sapd officer.");
	if(pData[playerid][pFactionRank] < 1)
		return Error(playerid, "You must be 1 rank level!");

	new otherid;
	if(sscanf(params, "u", otherid))
	{
	    Usage(playerid, "/takemarijuana <ID/Name> | Melenyapkan Marijuana");
	    return true;
	}

	if(!IsPlayerConnected(otherid) || otherid == INVALID_PLAYER_ID)
        return Error(playerid, "Player tersebut belum masuk!");

 	if(!NearPlayer(playerid, otherid, 4.0))
        return Error(playerid, "The specified player is disconnected or not near you.");
		
	Inventory_Set(playerid, "Marijuana", 1578, 0);
	Info(playerid, "Anda telah mengambil semua marijuana milik %s.", ReturnName(otherid));
	Info(otherid, "Officer %s telah mengambil semua marijuana milik anda", ReturnName(playerid));
	return 1;
}

CMD:takedl(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
        return Error(playerid, "Kamu harus menjadi sapd officer.");
	if(pData[playerid][pFactionRank] < 2)
		return Error(playerid, "You must be 2 rank level!");

	new otherid;
	if(sscanf(params, "u", otherid))
	{
	    Usage(playerid, "/takedl <ID/Name> | Tilang Driving License(SIM)");
	    return true;
	}

	if(!IsPlayerConnected(otherid) || otherid == INVALID_PLAYER_ID)
        return Error(playerid, "Player tersebut belum masuk!");

 	if(!NearPlayer(playerid, otherid, 4.0))
        return Error(playerid, "The specified player is disconnected or not near you.");
		
	pData[otherid][pDriveLic] = 0;
	pData[otherid][pDriveLicTime] = 0;
	Info(playerid, "Anda telah menilang Driving License milik %s.", ReturnName(otherid));
	Info(otherid, "Officer %s telah menilang Driving License milik anda", ReturnName(playerid));
	return 1;
}

//SAMD Commands
CMD:loadinjured(playerid, params[])
{
    static
        seatid,
		otherid;

    if(pData[playerid][pFaction] != 3)
        return Error(playerid, "You must be part of a medical faction.");

    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/loadinjured [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 10.0))
        return Error(playerid, "Player tersebut tidak berada didekat mu.");

    if(otherid == playerid)
        return Error(playerid, "You can't load yourself into an ambulance.");

    if(!pData[otherid][pInjured])
        return Error(playerid, "That player is not injured.");
	
	if(!IsPlayerInAnyVehicle(playerid))
	{
	    Error(playerid, "You must be in a Ambulance to load patient!");
	    return true;
	}
		
	new i = GetPlayerVehicleID(playerid);
    if(GetVehicleModel(i) == 416)
    {
        seatid = GetAvailableSeat(i, 2);

        if(seatid == -1)
            return Error(playerid, "There is no room for the patient.");

        clearAnimations(otherid);
        pData[otherid][pInjured] = 2;

        PutPlayerInVehicle(otherid, i, seatid);
        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s opens up the ambulance and loads %s on the stretcher.", ReturnName(playerid), ReturnName(otherid));

        TogglePlayerControllable(otherid, 0);
        SetPlayerHealthEx(otherid, 100.0);
        InfoTD_MSG(otherid, 4000, "You're injured ~r~now you're on ambulance.");
        return 1;
    }
    else Error(playerid, "You must be in an ambulance.");
    return 1;
}

CMD:dropinjured(playerid, params[])
{

    if(pData[playerid][pFaction] != 3)
        return Error(playerid, "You must be part of a medical faction.");
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/dropinjured [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID || !IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
        return Error(playerid, "Player tersebut tidak berada didekat mu.");

    if(otherid == playerid)
        return Error(playerid, "You can't deliver yourself to the hospital.");

    if(pData[otherid][pInjured] != 2)
        return Error(playerid, "That player is not injured.");

    if(IsPlayerInRangeOfPoint(playerid, 5.0, 2025.09, -1404.14, 17.20))
    {
		RemovePlayerFromVehicle(otherid);
		pData[otherid][pHospital] = 1;
		pData[otherid][pHospitalTime] = 0;
		pData[otherid][pInjured] = 1;
		ResetPlayerWeaponsEx(otherid);
        Info(playerid, "You have delivered %s to the hospital.", ReturnName(otherid));
        Info(otherid, "You have recovered at the nearest hospital by officer %s.", ReturnName(playerid));
    }
    else Error(playerid, "You must be near a hospital deliver location.");
    return 1;
}

CMD:ems(playerid, params[])
{
	if(pData[playerid][pFaction] != 3)
        return Error(playerid, "Kamu harus menjadi samd officer.");
	
	foreach(new ii : Player)
	{
		if(pData[ii][pInjured])
		{
			SendClientMessageEx(playerid, COLOR_PINK2, "EMS Player: "WHITE_E"%s(id: %d)", ReturnName(ii), ii);
		}
	}
	Info(playerid, "/findems [id] to search injured player!");
	return 1;
}

CMD:revive(playerid, params[])
{
	if(pData[playerid][pFaction] != 3)
        return ErrorMsg(playerid, "Anda bukan bagian dari SAMD");

	new otherid;
    if(sscanf(params, "u", otherid))
        return SyntaxMsg(playerid, "/revive [playerid/PartOfName]");

    if(IsValidLoadingBar(playerid)) 
    	return InfoTD_MSG(playerid, 4000, "Anda masih memiliki ~y~ProgressBar~w~, silahkan tunggu");

    if(!IsPlayerConnected(otherid))
        return ErrorMsg(playerid, "Player belum terkoneksi ke server");

    if(!pData[otherid][pInjured])
        return ErrorMsg(playerid, "Tidak dapat melakukan revive, player tersebut tidak Injured");

    if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
        return ErrorMsg(playerid, "Anda sedang tidak berada di dekat player tersebut");

    if(Inventory_Count(playerid, "Medkit") < 1)
		return ErrorMsg(playerid, "Anda tidak memiliki Medkit untuk melakukan revive");

    ApplyAnimation(playerid, "MEDIC", "CPR", 4.1, 0, 0, 0, 0, 0, 1);
    ShowProgressbar(playerid, "Reviving...", 10);
    SetTimerEx("revive", 10000, false, "i", otherid);
    Inventory_Remove(playerid, "Medkit", 1);

    //SetPlayerHealthEx(otherid, 100.0);
    SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s menyembuhkan segala luka %s.", ReturnName(playerid), ReturnName(otherid));
    Info(otherid, "%s has revived you.", ReturnName(playerid));
    return 1;
}

function revive(playerid)
{
	pData[playerid][pInjured] = 0;
    pData[playerid][pHospital] = 0;
    pData[playerid][pSick] = 0;
    pData[playerid][pHead] = 100;
    pData[playerid][pPerut] = 100;
    pData[playerid][pRHand] = 100;
    pData[playerid][pLHand] = 100;
    pData[playerid][pRFoot] = 100;
    pData[playerid][pLFoot] = 100;
	SetPlayerHealthEx(playerid, 100.0);
	HideTDdeath(playerid);
    Toggleaccdeath[playerid] = 0;
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	clearAnimations(playerid);
	StopLoopingAnim(playerid);
	TogglePlayerControllable(playerid, 1);
}

CMD:salve(playerid, params[])
{
	new Float:health;
	health = GetPlayerHealth(playerid, health);
	if(pData[playerid][pFaction] != 3)
        return ErrorMsg(playerid, "Anda bukan bagian dari SAMD");
	
	if(Inventory_Count(playerid, "Medicine") < 1)
		return ErrorMsg(playerid, "Anda tidak memiliki Medkit untuk melakukan revive");

	new otherid;
	if(sscanf(params, "u", otherid))
        return SyntaxMsg(playerid, "/salve [playerid/PartOfName]");

    if(IsValidLoadingBar(playerid)) 
    	return InfoTD_MSG(playerid, 4000, "Anda masih memiliki ~y~ProgressBar~w~, silahkan tunggu");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
        return ErrorMsg(playerid, "Anda sedang tidak berada di dekat player tersebut");

    if(otherid == playerid)
        return ErrorMsg(playerid, "Anda tidak dapat melakukan selve pada diri sendiri");

    if(pData[otherid][pStress] == 10)
        return ErrorMsg(playerid, "Player tersebut sedang tidak sakit");
    
    if (health >= 100.0)
     	return ErrorMsg(playerid, "Player tersebut masih sehat");

	ApplyAnimation(playerid, "MEDIC", "CPR", 4.1, 0, 0, 0, 0, 0, 1);
	ShowProgressbar(playerid, "Salving...", 10);
    SetTimerEx("salve", 10000, false, "i", otherid);
	Inventory_Remove(playerid, "Medicine", 1);
	SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has given medicine to %s with the right hand.", ReturnName(playerid), ReturnName(otherid));
    Info(otherid, "Officer %s has resalve your sick character.", ReturnName(playerid));
	return 1;
}

function salve(playerid)
{
	new Float:health;
	health = GetPlayerHealth(playerid, health);
	SetPlayerHealthEx(playerid, health+100);
	pData[playerid][pHunger] += 20;
	pData[playerid][pEnergy] += 20;
	pData[playerid][pStress] = 0;
	pData[playerid][pSick] = 0;
	pData[playerid][pSickTime] = 0;
	HideTDdeath(playerid);
	Toggleaccdeath[playerid] = 0;
    clearAnimations(playerid);
	SetPlayerDrunkLevel(playerid, 0);
}

CMD:rehab(playerid, params[])
{
	if(pData[playerid][pFaction] != 3)
		return ErrorMsg(playerid, "Anda bukan bagian dari SAMD");

	if(!IsPlayerInRangeOfPoint(playerid, 4.5, 2206.36, -63.64, 26.48))
		return ErrorMsg(playerid, "Anda harus berada di point rehabilitation");
	
	new otherid;
	if(sscanf(params, "d", otherid))
		return Usage(playerid, "/usage [otherid/playerid]");

	if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
        return ErrorMsg(playerid, "Anda sedang tidak berada di dekat player tersebut");

 	if(otherid == playerid)
		return ErrorMsg(playerid, "Anda tidak dapat melakukan rehab pada diri sendiri");

	if(pData[otherid][pRehabTime] != 0)
		return ErrorMsg(playerid, "Player tersebut sedang dalam masa rehabilitas");

	if(pData[otherid][pUseDrug] <= 0)
		return ErrorMsg(playerid, "Player tersebut bukan pengguna drugs");

	if(pData[otherid][pUseDrug] >= 1 && pData[otherid][pUseDrug] <= 10)
	{
		pData[otherid][pRehab] = 1;
		pData[otherid][pRehabTime] = 10 * 60;
		Info(playerid, "Anda telah memberi waktu rehab "GREEN_E"(Low User) "WHITE_E"kepada %s selama 10menit", pData[otherid][pName]);
		Info(otherid, "%s telah memberi waktu rehab "GREEN_E"(Low User) "WHITE_E"kepadamu selama 10menit", pData[playerid][pName]);
		SetPlayerPos(otherid, 1153.74, -1330.82, -44.28+0.2);
		SetPlayerFacingAngle(otherid, 359.26);
		SetPlayerInterior(otherid, 3);
		SetPlayerVirtualWorld(otherid, 0);
		TogglePlayerControllable(otherid, 0);
		SetTimerEx("TimerUntogglePlayer", 3000, 0, "d", otherid);
	}
	else if(pData[otherid][pUseDrug] >= 11 && pData[otherid][pUseDrug] <= 20)
	{
		pData[otherid][pRehab] = 1;
		pData[otherid][pRehabTime] = 20 * 60;
		Info(playerid, "Anda telah memberi waktu rehab "YELLOW_E"(Medium User) "WHITE_E"kepada %s selama 20menit", pData[otherid][pName]);
		Info(otherid, "%s telah memberi waktu rehab "YELLOW_E"(Medium User) "WHITE_E"kepadamu selama 20menit", pData[playerid][pName]);
		SetPlayerPos(otherid, 1153.74, -1330.82, -44.28+0.2);
		SetPlayerFacingAngle(otherid, 359.26);
		SetPlayerInterior(otherid, 3);
		SetPlayerVirtualWorld(otherid, 0);
		TogglePlayerControllable(otherid, 0);
		SetTimerEx("TimerUntogglePlayer", 3000, 0, "d", otherid);
	}
	else if(pData[otherid][pUseDrug] >= 21)
	{
		pData[otherid][pRehab] = 1;
		pData[otherid][pRehabTime] = 30 * 60;
		Info(playerid, "Kamu telah memberi waktu rehab "RED_E"(Hard User) "WHITE_E"kepada %s selama 30menit", pData[otherid][pName]);
		Info(otherid, "%s telah memberi waktu rehab "RED_E"(Hard User) "WHITE_E"kepadamu selama 30menit", pData[playerid][pName]);
		SetPlayerPos(otherid, 1153.74, -1330.82, -44.28+0.2);
		SetPlayerFacingAngle(otherid, 359.26);
		SetPlayerInterior(otherid, 3);
		SetPlayerVirtualWorld(otherid, 0);
		TogglePlayerControllable(otherid, 0);
		SetTimerEx("TimerUntogglePlayer", 3000, 0, "d", otherid);
	}
	return 1;
}

CMD:healbone(playerid, params[])
{
	new Float:health;
	health = GetPlayerHealth(playerid, health);

	if(pData[playerid][pFaction] != 3)
        return ErrorMsg(playerid, "Anda harus menjadi bagian dari SAMD");

	if(Inventory_Count(playerid, "Medicine") < 1)
		return ErrorMsg(playerid, "Anda tidak memiliki Medkit untuk melakukan Heal Bone");

	new otherid;
	if(sscanf(params, "u", otherid))
        return SyntaxMsg(playerid, "/healbone [playerid/PartOfName]");

    if(IsValidLoadingBar(playerid)) 
    	return InfoTD_MSG(playerid, 4000, "Anda masih memiliki ~y~ProgressBar~w~, silahkan tunggu");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
        return ErrorMsg(playerid, "Player tersebut tidak berada didekat mu.");

    if(otherid == playerid)
        return ErrorMsg(playerid, "Anda tidak dapat memperbaiki kesehatan tulang dirimu sendiri.");
	
	ApplyAnimation(playerid, "MEDIC", "CPR", 4.1, 0, 0, 0, 0, 0, 1);
	ShowProgressbar(playerid, "Operating...", 10);
    SetTimerEx("healbone", 10000, false, "i", otherid);
	Inventory_Remove(playerid, "Medicine", 1);

	SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has given medicine to %s with the right hand.", ReturnName(playerid), ReturnName(otherid));
    Info(otherid, "Officer %s has resalve your sick character.", ReturnName(playerid));
	return 1;
}

function healbone(playerid)
{
	SetPlayerHealthEx(playerid, 100.0);
	pData[playerid][pHead] += 60;
	pData[playerid][pPerut] += 60;
	pData[playerid][pRHand] += 60;
	pData[playerid][pLHand] += 60;
	pData[playerid][pRFoot] += 60;
	pData[playerid][pLFoot] += 60;
	pData[playerid][pSickTime] = 0;
    clearAnimations(playerid);
	SetPlayerDrunkLevel(playerid, 0);
	HideTDdeath(playerid);
	Toggleaccdeath[playerid] = 0;
}

CMD:treatment(playerid, params[])
{
	new Float:health;
	health = GetPlayerHealth(playerid, health);

	if(pData[playerid][pFaction] != 3)
		return ErrorMsg(playerid, "Anda harus menjadi SAMD Officer");

	if(Inventory_Count(playerid, "Medicine") < 1)
		return ErrorMsg(playerid, "Anda tidak memiliki Medkit untuk melakukan treatment");

	new otherid;
	if(sscanf(params, "u", otherid))
		return Usage(playerid, "/treatment [playerid/PartOfName]");

	if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
    	return ErrorMsg(playerid, "Anda sedang tidak berada di dekat player tersebut");

    if(otherid == playerid)
        return ErrorMsg(playerid, "Anda tidak dapat melakukan treatment pada diri sendiri.");

    if (health >= 100.0)
     	return ErrorMsg(playerid, "Player tersebut masih sehat");

    ApplyAnimation(playerid, "MEDIC", "CPR", 4.1, 0, 0, 0, 0, 0, 1);
    ShowProgressbar(playerid, "Healing...", 10);
    SetTimerEx("treatment", 10000, false, "i", otherid);
    Inventory_Remove(playerid, "Medicine", 1);
    Info(otherid, "Officer %s has treatment your character.", ReturnName(playerid));
    return 1;    
}

function treatment(playerid)
{
	new Float:health;
	health = GetPlayerHealth(playerid, health);
	SetPlayerHealthEx(playerid, health+100);
	HideTDdeath(playerid);
	Toggleaccdeath[playerid] = 0;
}

//SANEW Commands
CMD:broadcast(playerid, params[])
{
    if(pData[playerid][pFaction] != 4)
        return Error(playerid, "You must be part of a news faction.");

    //if(!IsSANEWCar(GetPlayerVehicleID(playerid)) || !IsPlayerInRangeOfPoint(playerid, 5, 255.63, 1757.39, 701.09))
    //    return Error(playerid, "You must be inside a news van or chopper or in sanew studio.");

    if(!pData[playerid][pBroadcast])
    {
        pData[playerid][pBroadcast] = true;

        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has started a news broadcast.", ReturnName(playerid));
        Servers(playerid, "You have started a news broadcast (use \"/bc [broadcast text]\" to broadcast).");
    }
    else
    {
        pData[playerid][pBroadcast] = false;

        foreach (new i : Player) if(pData[i][pNewsGuest] == playerid) 
		{
            pData[i][pNewsGuest] = INVALID_PLAYER_ID;
        }
        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has stopped a news broadcast.", ReturnName(playerid));
        Servers(playerid, "You have stopped the news broadcast.");
    }
    return 1;
}


CMD:bc(playerid, params[])
{
    if(pData[playerid][pFaction] != 4)
        return Error(playerid, "You must be part of a news faction.");

    if(isnull(params))
        return Usage(playerid, "/bc [broadcast text]");

    //if(!IsSANEWCar(GetPlayerVehicleID(playerid)) || !IsPlayerInRangeOfPoint(playerid, 5, 255.63, 1757.39, 701.09))
    //    return Error(playerid, "You must be inside a news van or chopper or in sanew studio.");

    if(!pData[playerid][pBroadcast])
        return Error(playerid, "You must be broadcasting to use this command.");

    if(strlen(params) > 64) {
        foreach (new i : Player) /*if(!pData[i][pDisableBC])*/ {
            SendClientMessageEx(i, COLOR_ORANGE, "[SANA] Reporter %s: %.64s", ReturnName(playerid), params);
            SendClientMessageEx(i, COLOR_ORANGE, "...%s", params[64]);
        }
    }
    else {
        foreach (new i : Player) /*if(!pData[i][pDisableBC])*/ {
            SendClientMessageEx(i, COLOR_ORANGE, "[SANA] Reporter %s: %s", ReturnName(playerid), params);
        }
    }
    return 1;
}

CMD:live(playerid, params[])
{
    static
        livechat[128];
        
    if(sscanf(params, "s[128]", livechat))
        return Usage(playerid, "/live [live chat]");

    if(pData[playerid][pNewsGuest] == INVALID_PLAYER_ID)
        return Error(playerid, "You're now invite by sanew member to live!");

    /*if(!IsNewsVehicle(GetPlayerVehicleID(playerid)) || !IsPlayerInRangeOfPoint(playerid, 5, 255.63, 1757.39, 701.09))
        return Error(playerid, "You must in news chopper or in studio to live.");*/

    if(pData[pData[playerid][pNewsGuest]][pFaction] == 4)
    {
        foreach (new i : Player) /*if(!pData[i][pDisableBC])*/ {
            SendClientMessageEx(i, COLOR_LIGHTGREEN, "[SANA] Guest %s: %s", ReturnName(playerid), livechat);
        }
    }
    return 1;
}

CMD:inviteguest(playerid, params[])
{
    if(pData[playerid][pFaction] != 4)
        return Error(playerid, "You must be part of a news faction.");
		
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/inviteguest [playerid/PartOfName]");

    if(!pData[playerid][pBroadcast])
        return Error(playerid, "You must be broadcasting to use this command.");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "Player tersebut tidak berada didekat mu.");

    if(otherid == playerid)
        return Error(playerid, "You can't add yourself as a guest.");

    if(pData[otherid][pNewsGuest] == playerid)
        return Error(playerid, "That player is already a guest of your broadcast.");

    if(pData[otherid][pNewsGuest] != INVALID_PLAYER_ID)
        return Error(playerid, "That player is already a guest of another broadcast.");

    pData[otherid][pNewsGuest] = playerid;

    Info(playerid, "You have added %s as a broadcast guest.", ReturnName(otherid));
    Info(otherid, "%s has added you as a broadcast guest ((/live to start broadcast)).", ReturnName(otherid));
    return 1;
}

CMD:removeguest(playerid, params[])
{

    if(pData[playerid][pFaction] != 4)
        return Error(playerid, "You must be part of a news faction.");
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/removeguest [playerid/PartOfName]");

    if(!pData[playerid][pBroadcast])
        return Error(playerid, "You must be broadcasting to use this command.");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "Player tersebut tidak berada didekat mu.");

    if(otherid == playerid)
        return Error(playerid, "You can't remove yourself as a guest.");

    if(pData[otherid][pNewsGuest] != playerid)
        return Error(playerid, "That player is not a guest of your broadcast.");

    pData[otherid][pNewsGuest] = INVALID_PLAYER_ID;

    Info(playerid, "You have removed %s from your broadcast.", ReturnName(otherid));
    Info(otherid, "%s has removed you from their broadcast.", ReturnName(otherid));
    return 1;
}

forward DutyHour(playerid);
public DutyHour(playerid)
{
	if(pData[playerid][pOnDuty] < 1)
		return KillTimer(DutyTimer);

	pData[playerid][pDutyHour] += 1;
	if(pData[playerid][pDutyHour] == 3600)
	{
		if(pData[playerid][pFaction] == 1)
		{
			AddPlayerSalary(playerid, "Duty(SAPD)", factionprice);
			pData[playerid][pDutyHour] = 0;
			Servers(playerid, "Anda telah Duty selama 1 Jam dan Anda mendapatkan Pending Salary anda");
		}
		else if(pData[playerid][pFaction] == 2)
		{
			AddPlayerSalary(playerid, "Duty(SAGS)", factionprice);
			pData[playerid][pDutyHour] = 0;
			Servers(playerid, "Anda telah Duty selama 1 Jam dan Anda mendapatkan Pending Salary anda");
		}
		else if(pData[playerid][pFaction] == 3)
		{
			AddPlayerSalary(playerid, "Duty(SAMD)", factionprice);
			pData[playerid][pDutyHour] = 0;
			Servers(playerid, "Anda telah Duty selama 1 Jam dan Anda mendapatkan Pending Salary anda");
		}
		else if(pData[playerid][pFaction] == 4)
		{
			AddPlayerSalary(playerid, "Duty(SANEWS)", factionprice);
			pData[playerid][pDutyHour] = 0;
			Servers(playerid, "Anda telah Duty selama 1 Jam dan Anda mendapatkan Pending Salary anda");
		}
	}
	return 1;
}

//=============[ CMD SACF ]==========================//
CMD:sacfonline(playerid, params[])
{
	if(pData[playerid][pFaction] != 5)
        return Error(playerid, "Kamu harus menjadi sacf officer.");
	if(pData[playerid][pFactionRank] < 1)
		return Error(playerid, "Kamu harus memiliki peringkat tertinggi!");
		
	new duty[16], lstr[1024];
	format(lstr, sizeof(lstr), "Name\tRank\tStatus\tDuty Time\n");
	foreach(new i: Player)
	{
		if(pData[i][pFaction] == 5)
		{
			switch(pData[i][pOnDuty])
			{
				case 0:
				{
					duty = "Off Duty";
				}
				case 1:
				{
					duty = ""BLUE_E"On Duty";
				}
			}
			format(lstr, sizeof(lstr), "%s%s(%d)\t%s(%d)\t%s\t%d detik", lstr, pData[i][pName], i, GetFactionRank(i), pData[i][pFactionRank], duty, pData[i][pOnDutyTime]);
			format(lstr, sizeof(lstr), "%s\n", lstr);
		}
	}
	format(lstr, sizeof(lstr), "%s\n", lstr);
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "SACF Online", lstr, "Close", "");
	return 1;
}

CMD:gudangpedagang(playerid, const params[])
{
	if(pData[playerid][pFaction] != 5)
       return ErrorMsg(playerid, "Anda harus menjadi bagian dari SACF");

    foreach(new pid : Pedagang)
	{
        if(IsPlayerInRangeOfPoint(playerid, 4.0, pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ]))
        {
            ShowPedagangMenu(playerid, pid);
        }
    }
    return 1;
}

/*ShowPedagangMenu(playerid, pid)
{
    pData[playerid][pdgMenuType] = 0;
    pData[playerid][pInPdg] = pid;

    new Dstring[1280];
	format(Dstring, sizeof(Dstring), "Gudang Pedagang\tPC\n\
	gandum\t(%d)\n", pdgDATA[pid][pdgGandum]);
	format(Dstring, sizeof(Dstring), "%sPizza\t(%d)\n", Dstring, pdgDATA[pid][pdgDaging]);
	format(Dstring, sizeof(Dstring), "%sJus Jeruk\t(%d)\n", Dstring, pdgDATA[pid][pdgSusuolah]);
	format(Dstring, sizeof(Dstring), "%sBurger\t(%d)\n", Dstring, pdgDATA[pid][pdgBurger]);
	format(Dstring, sizeof(Dstring), "%sRoti\t(%d)\n", Dstring, pdgDATA[pid][pdgRoti]);
	format(Dstring, sizeof(Dstring), "%sSteak\t(%d)\n", Dstring, pdgDATA[pid][pdgSteak]);
	format(Dstring, sizeof(Dstring), "%sMilk\t(%d)\n", Dstring, pdgDATA[pid][pdgMilk]);
	format(Dstring, sizeof(Dstring), "%sKentang\t(%d)\n", Dstring, pdgDATA[pid][pdgKentang]);
	format(Dstring, sizeof(Dstring), "%sOrange\t(%d)\n", Dstring, pdgDATA[pid][pdgOrange]);
	format(Dstring, sizeof(Dstring), "%sFood\t(%d)\n", Dstring, pdgDATA[pid][pdgFood]);
    ShowPlayerDialog(playerid, GUDANG_SACF, DIALOG_STYLE_TABLIST_HEADERS, "LIST GUDANG", Dstring, "Select", "Cancel");
    return 1;
}*/

ShowPedagangMenu(playerid, pid)
{
    pData[playerid][pdgMenuType] = 0;
    pData[playerid][pInPdg] = pid;

    new Dstring[1280];
	format(Dstring, sizeof(Dstring), "Gudang Pedagang\tJumlah\n\
	gandum\t(%d)\n", pdgDATA[pid][pdgGandum]);
	format(Dstring, sizeof(Dstring), "%sPizza\t(%d)\n", Dstring, pdgDATA[pid][pdgDaging]);
	format(Dstring, sizeof(Dstring), "%sJus Jeruk\t(%d)\n", Dstring, pdgDATA[pid][pdgSusuolah]);
	format(Dstring, sizeof(Dstring), "%sNasi Goreng\t(%d)\n", Dstring, pdgDATA[pid][pdgBurger]);
	format(Dstring, sizeof(Dstring), "%sRoti\t(%d)\n", Dstring, pdgDATA[pid][pdgRoti]);
	format(Dstring, sizeof(Dstring), "%sSteak\t(%d)\n", Dstring, pdgDATA[pid][pdgSteak]);
	format(Dstring, sizeof(Dstring), "%sFood\t(%d)\n", Dstring, pdgDATA[pid][pdgFood]);
	format(Dstring, sizeof(Dstring), "%sKentang\t(%d)\n", Dstring, pdgDATA[pid][pdgKentang]);
	format(Dstring, sizeof(Dstring), "%sOrange\t(%d)\n", Dstring, pdgDATA[pid][pdgOrange]);
	format(Dstring, sizeof(Dstring), "%sMoney\t(%d)\n", Dstring, pdgDATA[pid][pdgMilk]);
    ShowPlayerDialog(playerid, GUDANG_SACF, DIALOG_STYLE_TABLIST_HEADERS, "LIST GUDANG", Dstring, "Select", "Cancel");
    return 1;
}

CMD:cooking(playerid, const params[])
{
	if(pData[playerid][pFaction] != 5)
		return ErrorMsg(playerid, "Anda Bukan Faction SACF");
	{
		if(IsPlayerInRangeOfPoint(playerid, 1.5, 1315.1160, -861.6995, 39.7260))
		{
			if(pData[playerid][pLoading] == true) return ErrorMsg(playerid, "Anda Masih Proses");
			{
				new Dstring[1280];
				format(Dstring, sizeof(Dstring), "MENU MASAK\tBahan #1\tBahan #2\tBahan #3\n\
				Burger\tDaging\tRoti\t-\n");
				format(Dstring, sizeof(Dstring), "%sRoti\tGandum\t-\t-\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sSteak\tDaging\t-\t-\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sSusu\tSusu Olahan\t-\t-\n", Dstring);
				ShowPlayerDialog(playerid, DIALOG_COOKING_SACF, DIALOG_STYLE_TABLIST_HEADERS, "Dapur Pedagang", Dstring, "Pilih", "Batal");
			}
		}
		else return ErrorMsg(playerid, "Anda Tidak Ditempat Masak");
	}
	return 1;
}

CMD:invoiceinfo(playerid, params[])
{
	if(pData[playerid][pFaction] <= 0)
		return Error(playerid, "You are not faction!");
	ShowInvoiceInfo(playerid);
	return 1;
}

CMD:togspeedcam(playerid, params[])
{
	if(!pData[playerid][pTogSpeedcam])
	{
		pData[playerid][pTogSpeedcam] = 1;
		Info(playerid, "Anda telah menonaktifkan Info Speedcam");
	}
	else
	{
		pData[playerid][pTogSpeedcam] = 0;
		Info(playerid, "Anda telah mengaktifkan Info Speedcam");
	}
	return 1;
}