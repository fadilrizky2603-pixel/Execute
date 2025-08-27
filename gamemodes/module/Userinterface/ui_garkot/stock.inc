stock ShowGarasiTD(playerid, show)
{
	if(show)
	{
		for(new i = 1; i < 73;i++)
		{
			if(IsValidDynamicPlayerTextDraw(playerid, GarasiTD[playerid][i]))
				PlayerTextDrawShow(playerid, GarasiTD[playerid][i]);

			PlayerTextDrawHide(playerid, GarasiTD[playerid][72]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][71]);

			PlayerTextDrawHide(playerid, GarasiTD[playerid][24]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][28]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][32]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][33]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][40]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][44]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][45]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][46]);

			PlayerTextDrawHide(playerid, GarasiTD[playerid][25]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][29]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][34]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][35]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][41]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][47]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][48]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][49]);

			PlayerTextDrawHide(playerid, GarasiTD[playerid][26]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][30]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][36]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][37]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][42]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][50]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][51]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][52]);

			PlayerTextDrawHide(playerid, GarasiTD[playerid][27]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][31]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][38]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][39]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][43]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][53]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][54]);
			PlayerTextDrawHide(playerid, GarasiTD[playerid][55]);

			for(new b = 56; b < 73; b++)
			{
				PlayerTextDrawHide(playerid, GarasiTD[playerid][b]);
			}
		}	
	}
	else
	{
		for(new i = 1; i < 73;i++)
		{
			if(IsValidDynamicPlayerTextDraw(playerid, GarasiTD[playerid][i]))
				PlayerTextDrawHide(playerid, GarasiTD[playerid][i]);
		}
	}
}