stock LoadTombol(playerid)
{
	
    triggernotif[playerid][0] = CreatePlayerTextDraw(playerid, 11.000, 195.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, triggernotif[playerid][0], 78.000, 27.000);
	PlayerTextDrawAlignment(playerid, triggernotif[playerid][0], 1);
	PlayerTextDrawColor(playerid, triggernotif[playerid][0], 538976511);
	PlayerTextDrawSetShadow(playerid, triggernotif[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, triggernotif[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, triggernotif[playerid][0], 255);
	PlayerTextDrawFont(playerid, triggernotif[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, triggernotif[playerid][0], 1);

	triggernotif[playerid][1] = CreatePlayerTextDraw(playerid, 25.000, 201.000, "[ALT]");
	PlayerTextDrawLetterSize(playerid, triggernotif[playerid][1], 0.190, 1.399);
	PlayerTextDrawAlignment(playerid, triggernotif[playerid][1], 2);
	PlayerTextDrawColor(playerid, triggernotif[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, triggernotif[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, triggernotif[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, triggernotif[playerid][1], 150);
	PlayerTextDrawFont(playerid, triggernotif[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, triggernotif[playerid][1], 1);

	triggernotif[playerid][2] = CreatePlayerTextDraw(playerid, 38.000, 203.000, "Costum Your Text");
	PlayerTextDrawLetterSize(playerid, triggernotif[playerid][2], 0.170, 1.199);
	PlayerTextDrawAlignment(playerid, triggernotif[playerid][2], 1);
	PlayerTextDrawColor(playerid, triggernotif[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, triggernotif[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, triggernotif[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, triggernotif[playerid][2], 150);
	PlayerTextDrawFont(playerid, triggernotif[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, triggernotif[playerid][2], 1);

	triggernotif[playerid][3] = CreatePlayerTextDraw(playerid, 35.000, 200.000, ".");
	PlayerTextDrawLetterSize(playerid, triggernotif[playerid][3], 0.190, 1.399);
	PlayerTextDrawAlignment(playerid, triggernotif[playerid][3], 2);
	PlayerTextDrawColor(playerid, triggernotif[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, triggernotif[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, triggernotif[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, triggernotif[playerid][3], 150);
	PlayerTextDrawFont(playerid, triggernotif[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, triggernotif[playerid][3], 1);
	return 1;
}

stock HideInfoTombol(playerid)
{
	PlayerTextDrawHide(playerid, triggernotif[playerid][0]);
	PlayerTextDrawHide(playerid, triggernotif[playerid][1]);
	PlayerTextDrawHide(playerid, triggernotif[playerid][2]);
	PlayerTextDrawHide(playerid, triggernotif[playerid][3]);
	return 1;
}

stock TombolY(playerid, const string:text[] = "")
{
	PlayerTextDrawShow(playerid, triggernotif[playerid][0]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][1]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][2]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][3]);
	PlayerTextDrawSetString(playerid, triggernotif[playerid][1], "[Y]");
	PlayerTextDrawSetString(playerid, triggernotif[playerid][2], text);
	PlayerPlaySound(playerid, 1057 , 0.0, 0.0, 0.0);
	return 1;
}

stock TombolH(playerid, const string:text[] = "")
{
	PlayerTextDrawShow(playerid, triggernotif[playerid][0]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][1]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][2]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][3]);
	PlayerTextDrawSetString(playerid, triggernotif[playerid][1], "[H]");
	PlayerTextDrawSetString(playerid, triggernotif[playerid][2], text);
	PlayerPlaySound(playerid, 1057 , 0.0, 0.0, 0.0);
	return 1;
}

stock TombolEmpty(playerid, const string:text[] = "")
{
	PlayerTextDrawShow(playerid, triggernotif[playerid][0]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][1]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][2]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][3]);
	PlayerTextDrawSetString(playerid, triggernotif[playerid][1], "");
	PlayerTextDrawSetString(playerid, triggernotif[playerid][2], text);
	PlayerPlaySound(playerid, 1057 , 0.0, 0.0, 0.0);
	return 1;
}

stock TombolAlt(playerid, const string:text[] = "")
{
	PlayerTextDrawShow(playerid, triggernotif[playerid][0]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][1]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][2]);
	PlayerTextDrawShow(playerid, triggernotif[playerid][3]);
	PlayerTextDrawSetString(playerid, triggernotif[playerid][1], "[ALT]");
	PlayerTextDrawSetString(playerid, triggernotif[playerid][2], text);
	PlayerPlaySound(playerid, 1057 , 0.0, 0.0, 0.0);
	return 1;
}