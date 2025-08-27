HideTDdeath(playerid)
{
	for(new i = 0; i < 8; i++)
	{
		PlayerTextDrawHide(playerid, DeathNTRP[playerid][i]);
	}
}