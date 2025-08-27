CMD:fish1(playerid, const params[])
{
	if(finfo[playerid][f_player] == true) return SendClientMessage(playerid, COLOR_GREY, "Wait for it, you have time fishing /refishing (to {FF0000}cancel{FFFFFF} fishing)");
	finfo[playerid][f_player] = true;

    if(finfo[playerid][f_baittimer] != -1)
    {
    	KillTimer(finfo[playerid][f_baittimer]);
    	finfo[playerid][f_baittimer] = -1;
    }

    SetCameraBehindPlayer(playerid);
    finfo[playerid][f_baitsecond] = RandomEx(5,10);
    finfo[playerid][f_baittimer] = SetTimerEx("FishBait", 1000, true, "i", playerid);

    TogglePlayerControllable(playerid,0);
    ApplyAnimation(playerid,"SWORD","sword_block",50.0 ,0,1,0,1,1);
    SetPlayerAttachedObject(playerid, 0, 18632 ,6,0.079376,0.037070,0.007706,181.482910,0.000000,0.000000,1.000000,1.000000,1.000000);

    if(finfo[playerid][f_fixedanim] != -1)
    {
    	KillTimer(finfo[playerid][f_fixedanim]);
    	finfo[playerid][f_fixedanim] = -1;
    }

    finfo[playerid][f_fixedanim] = SetTimerEx("FixAnimFish", 500, false, "i", playerid);
    return 1;
}