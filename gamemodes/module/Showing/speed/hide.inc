HideSpeed(playerid)
{
	for(new i = 0; i < 17; i++)
	{
		PlayerTextDrawHide(playerid, SpeedoPakCik[playerid][i]);
	}
}