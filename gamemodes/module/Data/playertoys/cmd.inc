CMD:toys(playerid, const params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return Error(playerid, "This command can only be used on foot, exit your vehicle!");
	if(pData[playerid][IsLoggedIn] == false) return Error(playerid, "You must be logged in to attach objects to your character!");
	new string[350], status[128];

	format(string, sizeof(string), "Slot\tShow/Hide\n");

	// ========= Toys Slot 1 ======= 
	if(pToys[playerid][0][toy_hide] != 0)
	{
		status = ""RED_E"Hidden";
	}
	else
	{
		status = ""GREEN_LIGHT"Showed";
	}
	if(pToys[playerid][0][toy_model] == 0)
	{
		format(string, sizeof(string), "%sSlot 1\n", string);
	}
	else format(string, sizeof(string), "%sSlot 1\t%s\n", string, status);

	// ========= Toys Slot 2 ======= 
	if(pToys[playerid][1][toy_hide] != 0)
	{
		status = ""RED_E"Hidden";
	}
	else
	{
		status = ""GREEN_LIGHT"Showed";
	}

	// ========= Toys Slot 3 ======= 
	if(pToys[playerid][1][toy_model] == 0)
	{
		format(string, sizeof(string), "%sSlot 2\n", string);
	}
	else format(string, sizeof(string), "%sSlot 2\t%s\n", string, status);

	// ========= Toys Slot 4 ======= 
	if(pToys[playerid][2][toy_hide] != 0)
	{
		status = ""RED_E"Hidden";
	}
	else
	{
		status = ""GREEN_LIGHT"Showed";
	}
	if(pToys[playerid][2][toy_model] == 0)
	{
		format(string, sizeof(string), "%sSlot 3\n", string);
	}
	else format(string, sizeof(string), "%sSlot 3\t%s\n", string, status);

	// ========= Toys Slot 5 ======= 
	if(pToys[playerid][3][toy_hide] != 0)
	{
		status = ""RED_E"Hidden";
	}
	else
	{
		status = ""GREEN_LIGHT"Showed";
	}
	if(pToys[playerid][3][toy_model] == 0)
	{
		format(string, sizeof(string), "%sSlot 4\n", string);
	}
	else format(string, sizeof(string), "%sSlot 4\t%s\n", string, status);

	strcat(string, ""dot">"RED_E"Reset Toys");

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

	ShowPlayerDialog(playerid, DIALOG_TOY, DIALOG_STYLE_TABLIST_HEADERS, ""RED_E"Local Prime Roleplay: "WHITE_E"Player Toys", string, "Select", "Cancel");
	return 1;
}
