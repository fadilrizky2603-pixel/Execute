CMD:robbiz(playerid, params[])
{
	if(pData[playerid][pFamily] == -1) return ErrorMsg(playerid, "Anda bukan bagian dari Family");
	if(pData[playerid][pRobbingTime] >= gettime()) return Error(playerid, "Anda harus menunggu %d seconds to robbery biz", pData[playerid][pRobbingTime] - gettime());
    if(pData[playerid][pInBiz] >= 0 && IsPlayerInRangeOfPoint(playerid, 2.5, bData[pData[playerid][pInBiz]][bExtposX], bData[pData[playerid][pInBiz]][bExtposY], bData[pData[playerid][pInBiz]][bExtposZ]))
	if(CountFaction(1) < 2) return ErrorMsg(playerid, "SAPD yang ada di kota minimal 2");
	if(CountFaction(3) < 1) return ErrorMsg(playerid, "SAMD yang ada di kota minimal 1");
		
	if(GetPVarInt(playerid, "Robb") > gettime())
		return ErrorMsg(playerid, "Robbery delay, tunggu sebentar!");

	Info(playerid, "You're in robbery please wait...");
	new Float:slx, Float:sly, Float:slz;
	GetPlayerPos(playerid, slx, sly, slz);
    SendFactionMessage(1, -1, "{FF0000}DISPATCH {FFFFFF}: Seseorang telah mencoba melakukan robbery Warung | Location: %s | Players ID:%d", GetLocation(slx, sly, slz), playerid);
	SendFactionMessage(1, -1, "Gunakan {FFFF00}'/getlocpd <playerid>'", GetLocation(slx, sly, slz));
	pData[playerid][pActivity] = SetTimerEx("Robb", 15000, false, "i", playerid);
	ShowProgressbar(playerid, "Robbing...", 15);
	TogglePlayerControllable(playerid, 0);
	ApplyAnimation(playerid, "BOMBER", "BOM_Plant",	4.0, 1, 0, 0, 0, 0, 1);
	GivePlayerMoneyEx(playerid, 50000);
		return ErrorMsg(playerid, "ANDA BERHASIL MELAKUKAN ROBBIZ");
	InRob[playerid] = 1;
	return 1;
}
