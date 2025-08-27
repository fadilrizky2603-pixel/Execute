CMD:id(playerid, params[])
{	
	new otherid;
	if(sscanf(params, "u", otherid))
        return Usage(playerid, "/id (PlayerID/PartOfName)");
	
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "Player yang di maksud tidak di temukan");
	
	Servers(playerid, "[ID:%d] UCP: %s | Name: %s | Level: %d | Ping: %dms | Device: %d", otherid, pData[otherid][pUcp], pData[otherid][pName], pData[otherid][pLevel], GetPlayerPing(otherid), IsPlayerAndroid(otherid)); 
	return 1;
}