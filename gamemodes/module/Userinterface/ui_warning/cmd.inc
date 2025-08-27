CMD:alert(playerid, const params[])
{
	new
	    userid, teks[100];

    if (pData[playerid][pAdmin] < 2)
	    return Error(playerid, "You don't have permission to use this command.");

	if (sscanf(params, "us[100]", userid, teks))
	    return Usage(playerid, "/alert [playerid/PartOfName] [teks]");

	forex(i, 16)
	{
		PlayerTextDrawShow(userid, ALERTTD[userid][i]);
		PlayerTextDrawSetString(userid, ALERTTD[userid][13], teks);
		PlayerTextDrawSetString(userid, ALERTTD[userid][14], sprintf("Warned by: %s", pData[playerid][pName]));
	}
	HideLogo(playerid);
	HideHunger(playerid);
	SendClientMessageToAllEx(COLOR_IVORY, "AdmCmd | %s telah memunculkan alert kepada %s", pData[playerid][pName], ReturnName(userid));
	return 1;
}
