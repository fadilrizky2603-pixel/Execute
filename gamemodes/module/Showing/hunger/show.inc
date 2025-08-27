ShowHunger(playerid)
{
	for(new i = 0; i < 39; i++)
	{
		PlayerTextDrawShow(playerid, hbeexp[playerid][i]);
	}
}