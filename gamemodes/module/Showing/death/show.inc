ShowTDdeath(playerid)
{
	for(new i = 0; i < 8; i++)
	{
		PlayerTextDrawShow(playerid, DeathNTRP[playerid][i]);
	}
}