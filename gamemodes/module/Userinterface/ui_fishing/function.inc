function FishTimerStart(playerid)
{
	if(finfo[playerid][f_textsize] > 0.000)
	{
		finfo[playerid][f_textsize] -= 3.000;
		PlayerTextDrawTextSize(playerid, MancingTdBolo[playerid][2], finfo[playerid][f_textsize], 21.000);
		for(new i = 0; i < 8; i++) {
		PlayerTextDrawShow(playerid, MancingTdBolo[playerid][i]);
		}
	}
	else
	{
		finfo[playerid][f_textsize] = 0.000;
		DeleteFishingData(playerid);
		TogglePlayerControllable(playerid, 1);
	    RemovePlayerAttachedObject(playerid, 9);
	}
	return 1;
}


function FishBait(playerid)
{
	if(finfo[playerid][f_baitsecond] > 0)
	{
		finfo[playerid][f_baitsecond]--;
	}
	else
	{
		if(finfo[playerid][f_baittimer] != -1)
		{
			KillTimer(finfo[playerid][f_baittimer]);
			finfo[playerid][f_baittimer] = -1;
		}
		finfo[playerid][f_bite] = true;
		ManagingFishingData(playerid);
	}
	return 1;
}

function FixAnimFish(playerid)
{
	ApplyAnimation(playerid,"SWORD","sword_block",50.0 ,0,1,0,1,1);
	return 1;
}