enum E_FACCALL
{
	fcOwner,
	fcFaction,
	fcMsg[254],
	Float:fcPosX,
	Float:fcPosY,
	Float:fcPosZ
}

new fcData[MAX_FACCALL][E_FACCALL],
Iterator:FactionCall<MAX_FACCALL>;

FactionCall_Delete(fcid)
{
	if(fcid != -1)
	{
		fcData[fcid][fcOwner] = INVALID_PLAYER_ID;
		fcData[fcid][fcFaction] = 0;
		fcData[fcid][fcPosX] = 0;
		fcData[fcid][fcPosY] = 0;
		fcData[fcid][fcPosZ] = 0;

		format(fcData[fcid][fcMsg], 254, "\0");

		Iter_Remove(FactionCall, fcid);
	}
	return 1;
}

FactionCall_Clear(playerid)
{
	for(new i = 0; i < MAX_FACCALL; i++)
	{
		if(Iter_Contains(FactionCall, i))
		{
			if(fcData[i][fcOwner] == playerid)
			{
				FactionCall_Delete(i);
			}
		}
	}
}

//Faction Call List
GetFactionCall(playerid)
{
	new tmpcount;
	foreach(new id : FactionCall)
	{
	    if(fcData[id][fcFaction] == pData[playerid][pFaction])
	    {
     		tmpcount++;
	    }
	}
	return tmpcount;
}

ReturnFactionCallID(playerid, slot)
{
	new tmpcount;
	if(slot < 1 && slot > MAX_FACCALL) return -1;
	foreach(new id : FactionCall)
	{
		if(fcData[id][fcFaction] == pData[playerid][pFaction])
		{
	     	tmpcount++;
	       	if(tmpcount == slot)
	       	{
	        	return id;
	  		}
	    }
	}
	return -1;
}

CMD:emergencylist(playerid, const params[])
{
	if(pData[playerid][pFaction] == 1 || pData[playerid][pFaction] == 3)
	{
		if(GetFactionCall(playerid) <= 0)
			return Error(playerid, "Tidak ada yang melakukan panggilan emergency");

		new hstr[128], lstr[1024], count = GetFactionCall(playerid), id;
		strcat(hstr, "ID\tFrom\tMessage\n", sizeof(hstr));
		Loop(itt, (count + 1), 1)
		{
			id = ReturnFactionCallID(playerid, itt);
			if(itt == count)
			{
				format(lstr, sizeof(lstr), "#%d\t%s\t%s\n", id, ReturnName(fcData[id][fcOwner]), fcData[id][fcMsg]);
			}
			else format(lstr, sizeof(lstr), "#%d\t%s\t%s\n", id, ReturnName(fcData[id][fcOwner]), fcData[id][fcMsg]);	
			strcat(hstr, lstr, sizeof(hstr));
		}
		ShowPlayerDialog(playerid, DIALOG_EMERGENCY_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Emergency Call", hstr, "Track", "Cancel");
	}
	else return Error(playerid, "Kamu bukan anggota SAPD/SAMD!");
	return 1;
}

CMD:call1(playerid, const params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	if(Inventory_Count(playerid, "Phone") < 1)
		return Error(playerid, "Anda tidak memiliki Ponsel!");

	if(pData[playerid][pUsePhone] == 0) 
		return Error(playerid, "Handphone anda sedang dimatikan");
	
	if(pData[playerid][pPhoneCredit] <= 0) 
		return Error(playerid, "Anda tidak memiliki Ponsel credits!");

	if(GetSignalNearest(playerid) == 0)
		return Error(playerid, "Ponsel anda tidak mendapatkan sinyal di wilayah ini.");

	static ph, string[128];
	if(sscanf(params, "dS()[128]", ph, string))
		return Usage(playerid, "/call [phone number] 911 - SAPD Call & SAMD CALL");

	if (ph == 911)
	{
		if(!IsPlayerInAnyVehicle(playerid))
		{
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
		}
		SetPlayerAttachedObject(playerid, 3, 18867, 6, 0.0909, -0.0030, 0.0000, 80.4001, 159.8000, 18.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);

		ServiceIndex[playerid] = 1;
		pData[playerid][pCallTime] = gettime() + 60;
		PlayerPlaySound(playerid, 3600, 0.0, 0.0, 0.0);
		SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s takes out their cellphone and places a call.", ReturnName(playerid));
		SendClientMessage(playerid, COLOR_BLUE, "OPERATOR:{FFFFFF} Which service do you require: \"sapd\" or \"samd\"?");
	}

	if(ph == pData[playerid][pPhone]) 
		return Error(playerid, "Nomor sedang sibuk!");

	foreach(new ii : Player)
	{
		if(pData[ii][pPhone] == ph)
		{
			if(pData[ii][IsLoggedIn] == false || !IsPlayerConnected(ii)) return Error(playerid, "This number is not actived!");
			if(pData[ii][pUsePhone] == 0) return Error(playerid, "Tidak dapat menelepon, Ponsel tersebut yang dituju sedang Offline");
			if(IsPlayerInRangeOfPoint(ii, 20, 2179.9531,-1009.7586,1021.6880))
				return Error(playerid, "Anda tidak dapat melakukan ini, orang yang dituju sedang berada di OOC Zone");

			if(GetSignalNearest(ii) == 0)
				return Error(playerid, "Ponsel tersebut sedang mengalami gangguan sinyal.");

			if(pData[ii][pCall] == INVALID_PLAYER_ID)
			{
				pData[playerid][pCall] = ii;
				
				SendClientMessageEx(playerid, COLOR_YELLOW, "[CELLPHONE to %d] "WHITE_E"phone begins to ring, please wait for answer!", ph);
				SendClientMessageEx(ii, COLOR_YELLOW, "[CELLPHONE form %d] "WHITE_E"Your phonecell is ringing, type '/p' to answer it!", pData[playerid][pPhone]);
				PlayerPlaySound(playerid, 3600, 0,0,0);
				PlayerPlaySound(ii, 6003, 0,0,0);
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
				SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s takes out a cellphone and calling someone.", ReturnName(playerid));
				return 1;
			}
			else
			{
				Error(playerid, "Nomor ini sedang sibuk.");
				return 1;
			}
		}
	}
	return 1;
}