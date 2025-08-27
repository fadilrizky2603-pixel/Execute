LoadArea(playerid)
{
	//==========================[ DYANAMIC CP ]==============================
	//CENTRAL BALKOT
	//CreateDynamic3DTextLabel("Press "GREEN_E"[Y]"WHITE_E" Untuk Menu Pemerintah", COLOR_WHITE, 1488.1105, -1783.8051, -34.8809, 5.0);
	//CENTER JOB
	//CreateDynamic3DTextLabel("Press "GREEN_E"[Y]"WHITE_E" Untuk Menu Job", COLOR_WHITE, 1488.3700, -1791.3699, -34.8809, 5.0);

	eaData[playerid][Buysusu] = CreateDynamicCP(2779.750244, -1623.891723, 10.921875, 2.0, -1, -1, playerid, 30.0);
	eaData[playerid][jobfarmer] = CreateDynamicCP(-382.97, -1426.43, 26.31, 2.0, -1, -1, playerid, 50.0);
	eaData[playerid][Crafting] = CreateDynamicCP(2650.8174, -2407.7600, 3001.0859, 2.0, -1, -1, playerid, 50.0);
	eaData[playerid][Showroom] = CreateDynamicCP(1097.9308, -1765.0497, 13.3841, 2.0, -1, 11, playerid, 50.0);

	//================================[ DYNAMIC CIRCLE ]============================================

	eaData[playerid][balkot] = CreateDynamicCircle(1488.1105, -1783.8051, 2.0, -1, -1, playerid);
	eaData[playerid][centraljob] = CreateDynamicCircle(1488.3700, -1791.3699, 2.0, -1, -1, playerid);
	eaData[playerid][farmer] = CreateDynamicCircle(-382.97, -1426.43, 4.0, -1, -1, playerid);
	return 1;
}