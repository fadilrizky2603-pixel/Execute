HideHunger(playerid)
{
	for(new i = 0; i < 39; i++)
	{
		PlayerTextDrawHide(playerid, hbeexp[playerid][i]);
	}
}