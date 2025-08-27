CMD:announcement(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
		return ErrorMsg(playerid, "Only Administrator Local Prime");

    new teks[250], str[128];
    if(sscanf(params, "s[250]", teks))
    {
        Usage(playerid, "/announcement [teks]");
        return 1;
    }		
	format(str, 128, "%s", teks);
	for(new ii = 0; ii < 13; ii ++)
	{
		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			PlayerTextDrawShow(i, ANNOUNCEMENT[i][ii]);
			PlayerTextDrawSetString(i, ANNOUNCEMENT[i][2], str);	
			SetTimer("hideann", 5000, 0);	
		}
	}	
    SendClientMessageToAllEx(COLOR_IVORY, "AdmCmd | %s telah memunculkan announcement kepada warga di kota", pData[playerid][pName]);	
	return 1;
}