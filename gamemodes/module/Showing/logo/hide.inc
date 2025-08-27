HideLogo(playerid) {
	for (new i = 0; i < 6; i++)
	{
		TextDrawHideForPlayer(playerid, HOSTAR[i]);
	}
}
