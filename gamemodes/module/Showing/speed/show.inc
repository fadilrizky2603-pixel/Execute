ShowSpeed(playerid)
{
	for(new i = 0; i < 17; i++)
	{
		PlayerTextDrawShow(playerid, SpeedoPakCik[playerid][i]);
	}
}