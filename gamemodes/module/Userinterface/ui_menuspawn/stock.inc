stock ShowSpawnMenu(playerid) {
    for(new i = 0; i < 36; i++)
	{
		PlayerTextDrawShow(playerid, SpawnMenu[playerid][i]);
	}
	SelectTextDraw(playerid, SERVER_TEXTDRAW_COLOR);
}

stock HideSpawnMenu(playerid) {
    for(new i = 0; i < 36; i++)
	{
		PlayerTextDrawHide(playerid, SpawnMenu[playerid][i]);
	}
	CancelSelectTextDraw(playerid);
}