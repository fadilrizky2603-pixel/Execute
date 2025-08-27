StreamerConfig()
{
	Streamer_MaxItems(STREAMER_TYPE_OBJECT, 990000);
	Streamer_MaxItems(STREAMER_TYPE_MAP_ICON, 2000);
	Streamer_MaxItems(STREAMER_TYPE_PICKUP, 2000);
	for(new playerid = (GetMaxPlayers() - 1); playerid != -1; playerid--)
	{
		Streamer_DestroyAllVisibleItems(playerid, 0);
	}
	return 1;
}

CMD:render(playerid, params[])
{
	ShowPlayerDialog(playerid, DIALOG_STREAMER_CONFIG, DIALOG_STYLE_LIST, "Maximum object Configuration", "High level Configuration\nMedium level Configuration\nLow level Configuration\nPotato level Configuration", "Set", "Close");
	return 1;
}