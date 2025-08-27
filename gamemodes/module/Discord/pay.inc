CMD:pay(playerid, params[])
{
	if(IsAtEvent[playerid] == 1)
		return Error(playerid, "Anda sedang mengikuti event & tidak bisa melakukan ini");

	new money, otherid, mstr[128];
	if(sscanf(params, "ud", otherid, money))
	{
	    Usage(playerid, "/pay <ID/Name> <amount>");
	    return true;
	}

	if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
        return ErrorMsg(playerid, "Player disconnect atau sedang tidak berada didekat anda.");

 	if(otherid == playerid)
		return ErrorMsg(playerid, "Anda tidak dapat mengirim uang pada diri sendiri");
	if(pData[playerid][pMoney] < money)
		return ErrorMsg(playerid, "Uang yang di masukan tidak cukup");
	if(money > 1000000 && pData[playerid][pAdmin] == 0)
		return InfoTD_MSG(playerid, 4000, "Anda tidak dapat memberikan uang, lebih dari ~g~$1.000.000");
	if(money < 1)
		return InfoTD_MSG(playerid, 4000, "Anda tidak dapat memberikan uang kurang dari ~g~$1");
		
	/*GivePlayerMoneyEx(otherid, money);
	GivePlayerMoneyEx(playerid, -money);

	format(mstr, sizeof(mstr), "Server: "YELLOW_E"You have sent %s(%i) "GREEN_E"%s", pName[otherid], otherid, FormatMoney(money));
	SendClientMessage(playerid, COLOR_GREY, mstr);
	format(mstr, sizeof(mstr), "Server: "YELLOW_E"%s(%i) has sent you "GREEN_E"%s", pName[playerid], playerid, FormatMoney(money));
	SendClientMessage(otherid, COLOR_GREY, mstr);
	InfoTD_MSG(playerid, 3500, "~g~~h~Money Sent!");
	InfoMsg(otherid, "~g~~h~Money received!");
	ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
	ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
	
	new OtherIP[16];
	GetPlayerIp(playerid, PlayerIP, sizeof(PlayerIP));
	GetPlayerIp(otherid, OtherIP, sizeof(OtherIP));
	SendStaffMessage(COLOR_RED, "[PAYINFO] "WHITE_E"%s(%d)[IP: %d] pay to %s(%d)[IP: %d] ammount "GREEN_E"%s", pName[playerid], playerid, PlayerIP, pName[otherid], otherid, OtherIP, FormatMoney(money));*/
	format(mstr, sizeof(mstr), ""WHITEP_E"Are you sure you want to send %s(%d) "GREEN_E"%s?", ReturnName(otherid), otherid, FormatMoney(money));
	ShowPlayerDialog(playerid, DIALOG_PAY, DIALOG_STYLE_MSGBOX, ""GREEN_E"Send Money", mstr, "Send", "Cancel");

	SetPVarInt(playerid, "gcAmount", money);
	SetPVarInt(playerid, "gcPlayer", otherid);
	return 1;
}