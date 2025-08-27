CMD:repairatm(playerid, params[])
{
	if(pData[playerid][pJob] == 11 || pData[playerid][pJob2] == 11)
	{
		if(pData[playerid][pJobTime] > 0) 
			return Error(playerid, "Anda harus menunggu "GREY2_E"%d "WHITE_E"detik untuk bisa bekerja kembali.", pData[playerid][pJobTime]);

		if(pData[playerid][pLoading] == true) 
			return ErrorMsg(playerid, "Anda sedang mengisi atm");

		if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
			return ErrorMsg(playerid, "Anda harus turun dari kendaraan terlebih dahulu");

		foreach(new atmid : ATMS)
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.5, AtmData[atmid][atmX], AtmData[atmid][atmY], AtmData[atmid][atmZ]))
			{
				if(IsValidLoadingBar(playerid)) 
					return InfoTD_MSG(playerid, 4000, "Anda masih memiliki ~y~ProgressBar~w~, silahkan tunggu");
				if(AtmData[atmid][atmStatus] == 0)
					return ErrorMsg(playerid, "ATM sedang tidak rusak");

				Info(playerid, "Kamu sedang memperbaiki mesin atm");
				RemovePlayerAttachedObject(playerid, 9);
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
				clearAnimations(playerid);
				pData[playerid][pLoading] = true;

				ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,1,1,1,1,0,1);
				pData[playerid][pRefleBar] = SetTimerEx("RefleRepairATM", 10000, false, "i", playerid);
				ShowProgressbar(playerid, "Repairing...", 10);
				pData[playerid][pRefleATMID] = atmid;
			}
		}
	}
	else return ErrorMsg(playerid, "Anda bukan bagian dari Reflenish");
	return 1;
}

function RefleRepairATM(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pJob] == 11 || pData[playerid][pJob2] == 11)
	{
		{
			if(pData[playerid][pRefleTotalWork] == 3)
			{
				new atmid = pData[playerid][pRefleATMID];
				TogglePlayerControllable(playerid, 1);
				SuccesMsg(playerid, "Repair Succes!");
				pData[playerid][pEnergy] -= 3;
				AtmData[atmid][atmStatus] = 0;
				pData[playerid][pRefleTotalWork] = 0;
				pData[playerid][pJobTime] = 60;
				GivePlayerMoneyEx(playerid, jobreflenishprice);
				ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.1, 0, 0, 0, 0, 0, 1);
				pData[playerid][pLoading] = false;
				clearAnimations(playerid);
				Info(playerid, "Kamu telah memperbaiki ATM dan mendapatkan "GREEN_LIGHT"%s", FormatMoney(jobreflenishprice));
				Info(playerid, "Lanjutkan pekerjaan dengan mencari atm di sekitar kota (/findatm)");
				Atm_Refresh(atmid);
				Atm_Save(atmid);
			}
			else if(pData[playerid][pRefleTotalWork] <= 2)
			{
				new atmid = pData[playerid][pRefleATMID];
				TogglePlayerControllable(playerid, 1);
				SuccesMsg(playerid, "Repair Succes!");
				pData[playerid][pEnergy] -= 3;
				AtmData[atmid][atmStatus] = 0;
				pData[playerid][pRefleTotalWork] += 1;
				GivePlayerMoneyEx(playerid, jobreflenishprice);
				ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.1, 0, 0, 0, 0, 0, 1);
				pData[playerid][pLoading] = false;
				clearAnimations(playerid);
				Info(playerid, "Kamu telah memperbaiki ATM ini dan mendapatkan "GREEN_LIGHT"%s", FormatMoney(jobreflenishprice));
				Info(playerid, "Lanjutkan pekerjaan dengan mencari atm di sekitar kota (/findatm)");
				Atm_Refresh(atmid);
				Atm_Save(atmid);
			}
			else
			{
				pData[playerid][pLoading] = false;
				return 1;
			}
		}
	}
	return 1;
}

GetATMStatus()
{
	new tmpcount;
	foreach(new id : ATMS)
	{
	    if(AtmData[id][atmStatus] != 0)
	    {
     		tmpcount++;
	    }
	}
	return tmpcount;
}

ReturnRestockATMID(slot)
{
	new tmpcount;
	if(slot < 1 && slot > MAX_ATM) return -1;
	foreach(new id : ATMS)
	{
		if(AtmData[id][atmStatus] != 0)
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

/*
	//ENUM PLAYER

    pRefleBar,
    pRefleHaveBox,
    pRefleATMID,
    pRefleTotalWork,

*/

CMD:tsss(playerid, params[])
{
	Info(playerid, "Vehid : %d Stock : %d", GetPVarInt(playerid, "LastVehicleID"), VehRefleMoney[GetPVarInt(playerid, "LastVehicleID")]);
	return 1;
}