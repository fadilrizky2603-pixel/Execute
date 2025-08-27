ShowRadial(playerid) {
    for(new i = 0; i < 53; i++)
	{
		IsValidDynamicPlayerTextDraw(playerid, RadialMenuHytam[playerid][i]); {
			PlayerTextDrawShow(playerid, RadialMenuHytam[playerid][i]);
		}
	}
	HideLogo(playerid);
    SelectTextDraw(playerid, COLOR_RED);
}