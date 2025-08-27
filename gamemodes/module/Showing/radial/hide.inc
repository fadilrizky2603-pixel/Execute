HideRadial(playerid) {
    for(new i = 0; i < 53; i++)
	{
		IsValidDynamicPlayerTextDraw(playerid, RadialMenuHytam[playerid][i]); {
			PlayerTextDrawHide(playerid, RadialMenuHytam[playerid][i]);
		}
	}
	ShowLogo(playerid);
    CancelSelectTextDraw(playerid);
}