function hideann()
{
	foreach(new i : Player)
	{
		for(new  ii = 0; ii < 13; ii ++)
		{
			PlayerTextDrawHide(i, ANNOUNCEMENT[i][ii]);
		}
	}
	return 1;
}
