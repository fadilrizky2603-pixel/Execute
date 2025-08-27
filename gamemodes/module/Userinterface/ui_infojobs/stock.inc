stock InfoJob(playerid, const string:text[] = "")
{
	PlayerTextDrawShow(playerid, InfoJobs[playerid][0]);
	PlayerTextDrawShow(playerid, InfoJobs[playerid][1]);
	PlayerTextDrawShow(playerid, InfoJobs[playerid][2]);
	PlayerTextDrawShow(playerid, InfoJobs[playerid][3]);
	PlayerTextDrawSetString(playerid, InfoJobs[playerid][3], text);
	PlayerPlaySound(playerid, 1057 , 0.0, 0.0, 0.0);
    SetTimerEx("HideInfoJobs", 9000, false, "i", playerid);
	return 1;
}

function HideInfoJobs(playerid)
{
	PlayerTextDrawHide(playerid, InfoJobs[playerid][0]);
	PlayerTextDrawHide(playerid, InfoJobs[playerid][1]);
	PlayerTextDrawHide(playerid, InfoJobs[playerid][2]);
	PlayerTextDrawHide(playerid, InfoJobs[playerid][3]);
	return 1;
}