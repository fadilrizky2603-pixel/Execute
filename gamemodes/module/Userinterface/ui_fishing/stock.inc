stock ManagingFishingData(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	finfo[playerid][f_textsize] = 100.000;
	if(finfo[playerid][f_timerstart] != -1)
	{
		KillTimer(finfo[playerid][f_timerstart]);
		finfo[playerid][f_timerstart] = -1;
	}
	for(new i = 0; i < 8; i++) 
	{
		if(MancingTdBolo[playerid][i] != PlayerText:INVALID_TEXT_DRAW)
		{
			if (IsValidDynamicPlayerTextDraw(playerid, MancingTdBolo[playerid][i])) 
			{
				PlayerTextDrawDestroy(playerid, MancingTdBolo[playerid][i]);
			}
		}
	}
	finfo[playerid][f_timerstart] = SetTimerEx("FishTimerStart", 200, true, "i", playerid);
	MancingTdBolo[playerid][0] = CreatePlayerTextDraw(playerid, 263.000, 398.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, MancingTdBolo[playerid][0], 140.000, 22.000);
	PlayerTextDrawAlignment(playerid, MancingTdBolo[playerid][0], 1);
	PlayerTextDrawColor(playerid, MancingTdBolo[playerid][0], 100);
	PlayerTextDrawSetShadow(playerid, MancingTdBolo[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, MancingTdBolo[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, MancingTdBolo[playerid][0], 255);
	PlayerTextDrawFont(playerid, MancingTdBolo[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, MancingTdBolo[playerid][0], 1);

	MancingTdBolo[playerid][1] = CreatePlayerTextDraw(playerid, 396.000, 398.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, MancingTdBolo[playerid][1], 7.000, 21.000);
	PlayerTextDrawAlignment(playerid, MancingTdBolo[playerid][1], 1);
	PlayerTextDrawColor(playerid, MancingTdBolo[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, MancingTdBolo[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, MancingTdBolo[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, MancingTdBolo[playerid][1], 255);
	PlayerTextDrawFont(playerid, MancingTdBolo[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, MancingTdBolo[playerid][1], 1);

	MancingTdBolo[playerid][2] = CreatePlayerTextDraw(playerid, 263.000, 398.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, MancingTdBolo[playerid][2], finfo[playerid][f_textsize], 21.000);
	PlayerTextDrawAlignment(playerid, MancingTdBolo[playerid][2], 1);
	PlayerTextDrawColor(playerid, MancingTdBolo[playerid][2], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, MancingTdBolo[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, MancingTdBolo[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, MancingTdBolo[playerid][2], 255);
	PlayerTextDrawFont(playerid, MancingTdBolo[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, MancingTdBolo[playerid][2], 1);

	MancingTdBolo[playerid][3] = CreatePlayerTextDraw(playerid, 320.000, 384.000, "Spam H");
	PlayerTextDrawLetterSize(playerid, MancingTdBolo[playerid][3], 0.209, 0.999);
	PlayerTextDrawAlignment(playerid, MancingTdBolo[playerid][3], 1);
	PlayerTextDrawColor(playerid, MancingTdBolo[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, MancingTdBolo[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, MancingTdBolo[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, MancingTdBolo[playerid][3], 150);
	PlayerTextDrawFont(playerid, MancingTdBolo[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, MancingTdBolo[playerid][3], 1);

	MancingTdBolo[playerid][4] = CreatePlayerTextDraw(playerid, 360.000, 382.000, "_");
	PlayerTextDrawTextSize(playerid, MancingTdBolo[playerid][4], 42.000, 50.000);
	PlayerTextDrawAlignment(playerid, MancingTdBolo[playerid][4], 1);
	PlayerTextDrawColor(playerid, MancingTdBolo[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, MancingTdBolo[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, MancingTdBolo[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, MancingTdBolo[playerid][4], 0);
	PlayerTextDrawFont(playerid, MancingTdBolo[playerid][4], 5);
	PlayerTextDrawSetProportional(playerid, MancingTdBolo[playerid][4], 0);
	PlayerTextDrawSetPreviewModel(playerid, MancingTdBolo[playerid][4], 19630);
	PlayerTextDrawSetPreviewRot(playerid, MancingTdBolo[playerid][4], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, MancingTdBolo[playerid][4], 0, 0);

	MancingTdBolo[playerid][5] = CreatePlayerTextDraw(playerid, 263.000, 396.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, MancingTdBolo[playerid][5], 140.000, -1.000);
	PlayerTextDrawAlignment(playerid, MancingTdBolo[playerid][5], 1);
	PlayerTextDrawColor(playerid, MancingTdBolo[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, MancingTdBolo[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, MancingTdBolo[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, MancingTdBolo[playerid][5], 255);
	PlayerTextDrawFont(playerid, MancingTdBolo[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, MancingTdBolo[playerid][5], 1);

	MancingTdBolo[playerid][6] = CreatePlayerTextDraw(playerid, 263.000, 421.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, MancingTdBolo[playerid][6], 140.000, 1.000);
	PlayerTextDrawAlignment(playerid, MancingTdBolo[playerid][6], 1);
	PlayerTextDrawColor(playerid, MancingTdBolo[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, MancingTdBolo[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, MancingTdBolo[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, MancingTdBolo[playerid][6], 255);
	PlayerTextDrawFont(playerid, MancingTdBolo[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, MancingTdBolo[playerid][6], 1);

	MancingTdBolo[playerid][7] = CreatePlayerTextDraw(playerid, 396.000, 398.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, MancingTdBolo[playerid][7], 7.000, 21.000);
	PlayerTextDrawAlignment(playerid, MancingTdBolo[playerid][7], 1);
	PlayerTextDrawColor(playerid, MancingTdBolo[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, MancingTdBolo[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, MancingTdBolo[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, MancingTdBolo[playerid][7], 255);
	PlayerTextDrawFont(playerid, MancingTdBolo[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, MancingTdBolo[playerid][7], 1);

	for(new i = 0; i < 8; i++) {
	PlayerTextDrawShow(playerid, MancingTdBolo[playerid][i]);
	}
	return 1;
}

stock DeleteFishingData(playerid)
{
	finfo[playerid][f_bite] = false;
	finfo[playerid][f_player] = false;
	finfo[playerid][f_baitsecond] = 0;
	for(new i = 0; i < 8; i++) 
	{
		if(MancingTdBolo[playerid][i] != PlayerText:INVALID_TEXT_DRAW)
		{
			if (IsValidDynamicPlayerTextDraw(playerid, MancingTdBolo[playerid][i])) 
			{
				PlayerTextDrawDestroy(playerid, MancingTdBolo[playerid][i]);
			}
		}
	}
	if(finfo[playerid][f_baittimer] != 0)
	{
		KillTimer(finfo[playerid][f_baittimer]);
		finfo[playerid][f_baittimer] = -1;
	}
	if(finfo[playerid][f_timerstart] != -1)
	{
		KillTimer(finfo[playerid][f_timerstart]);
		finfo[playerid][f_timerstart] = -1;
	}
	for(new i = 0; i < 8; i++)
	{
		if (IsValidDynamicPlayerTextDraw(playerid, MancingTdBolo[playerid][i])) 
		{
			PlayerTextDrawDestroy(playerid, MancingTdBolo[playerid][i]);
		}
	}
	TogglePlayerControllable(playerid, 1);
	RemovePlayerAttachedObject(playerid, 9);
	return 1;
}