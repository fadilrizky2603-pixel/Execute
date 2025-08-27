CMD:pmdc(playerid, params[])
{
	if(pData[playerid][pFaction] != 1)
		return ErrorMsg(playerid, "Anda bukan bagian dari SAPD");

	new str[500];
	format(str, sizeof(str), "Vehicle Info\nHouse Info\nPhone Track\nRequest Backup\n 911 Calls");
	ShowPlayerDialog(playerid, PMDC_MENU, DIALOG_STYLE_LIST, "MDC Menu", str, "Select", "Cancel");
	return 1;
}

CMD:emdc(playerid, params[])
{
	if(pData[playerid][pFaction] != 3)
		return ErrorMsg(playerid, "Anda bukan bagian dari SAMD");

	new vehid = GetPlayerVehicleID(playerid), str[254];
	if(IsPlayerInRangeOfPoint(playerid, 3.5, 1161.97, -1325.55, -35.40))
	{
		format(str, sizeof(str), "912 Calls");
		ShowPlayerDialog(playerid, EMDC_MENU, DIALOG_STYLE_LIST, "MDC Menu", str, "Select", "Cancel");
		return 1;
	}
	else if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(IsMDCar(vehid))
		{
			format(str, sizeof(str), "912 Calls");
			ShowPlayerDialog(playerid, EMDC_MENU, DIALOG_STYLE_LIST, "MDC Menu", str, "Select", "Cancel");
			return 1;
		}
	}
	else return ErrorMsg(playerid, "Anda harus berada di dalam kendaraan SAMD");
	return 1;
}

ReturnMdcVehicleID(playerid, hslot)
{
	if(hslot < 1 && hslot > LIMIT_PER_PLAYER) return -1;

	new tmpcount;
	foreach(new i : PVehicles)
	{
		if(IsValidVehicle(pvData[i][cVeh]))
		{
			if(!strcmp(pvData[i][cPlate], pData[playerid][pTargetMDC]))
			{
				tmpcount++;
	       		if(tmpcount == hslot)
	       		{
	        		return i;
	  			}
	  		}
		}
	}
	return -1;
}

ReturnMdcHouseID(playerid, slot)
{
	new tmpcount;
	if(slot < 1 && slot > MAX_HOUSES) return -1;
	foreach(new hid : Houses)
	{
		if(!strcmp(pData[playerid][pName], hData[hid][hOwner], true))
		{
		    tmpcount++;
		    if(tmpcount == slot)
		    {
		    	return hid;
		  	}
		}
	}
	return -1;
}

function trackph(playerid, to_player)
{
	SuccesMsg(playerid, "Searching done!");
	pData[playerid][pLoading] = false;
	ShowPhone(playerid);
	return 1;
}

function ShowPhone(playerid)
{
	new number;
	new str[648];
	new otherid;
	new zone[MAX_ZONE_NAME];
	new sext[40];
	new Float:sX, Float:sY, Float:sZ;
	GetPlayerPos(otherid, sX, sY, sZ);
	SetPlayerCheckpoint(playerid, sX, sY, sZ, 5.0);
	pData[playerid][pSuspectTimer] = 120;
	Info(playerid, "You Has Succesfull Track Ph Number %d", number);
	if(pData[otherid][pGender] == 1) { sext = "Male"; } else { sext = "Female"; }

	GetPlayer3DZone(otherid, zone, sizeof(zone));

	format(str, sizeof(str), "{037bfc}Name: {ffffff}%s\n{037bfc}Gender: {ffffff}%s\n{037bfc}Brithday Date: {ffffff}%s\n\n{ffffff}Last Location At {037bfc}%s", ReturnName(otherid), sext, pData[otherid][pAge], zone);
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "{ffffff}Phone Info", str, "Close","");
	return 1;
}