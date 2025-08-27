CMD:h(playerid, const params[]) //Phone on-foot
{
	if(pData[playerid][pProgress] == 1) 
		return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");

	if(Inventory_Count(playerid, "Phone") < 1)
	{
		ErrorMsg(playerid, "Anda tidak memiliki ponsel");
		CancelSelectTextDraw(playerid);
		return 1;
	}
	
	if(pData[playerid][pPhone] == 0) return ErrorMsg(playerid, "Anda tidak memiliki ponsel");
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER || GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
	{
		HideHunger(playerid);
		HideLogo(playerid);
		for(new i = 0; i < 39; i++) {
			PlayerTextDrawShow(playerid, LockMenu[playerid][i]);
		}
		SelectTextDraw(playerid, COLOR_WHITE);
		PlayerPlaySound(playerid, 3600, 0,0,0);
		SetPlayerChatBubble(playerid, "> Membuka Handphone <", COLOR_PURPLE, 15.0, 5000);
		return 1;
	}
	HideHunger(playerid);
	HideLogo(playerid);
	for(new i = 0; i < 39; i++) {
		PlayerTextDrawShow(playerid, LockMenu[playerid][i]);
	}
	SelectTextDraw(playerid, COLOR_RED);
	PlayerPlaySound(playerid, 3600, 0,0,0);
	ApplyAnimation(playerid, "ped", "Jetpack_Idle", 4.1, 1, 0, 0, 1, 0, 1);
	SetPlayerAttachedObject(playerid, 9, 18866, 5, 0.135999, 0.017999, -0.053999, -91.299995, -88.799972, -2.199998, 1.000000, 1.000000, 1.000000);
	SetPlayerChatBubble(playerid, "> Membuka Handphone <", COLOR_PURPLE, 15.0, 5000);
	return 1;
}

CMD:selfie(playerid, const params[])
{
	if(Inventory_Count(playerid, "Phone") < 1) return ErrorMsg(playerid, "Anda tidak memiliki ponsel");

	if(takingselfie[playerid] == 0)
	{
	    GetPlayerPos(playerid,lX[playerid],lY[playerid],lZ[playerid]);
		static Float: n1X, Float: n1Y;
		if(Degree[playerid] >= 360) Degree[playerid] = 0;
		Degree[playerid] += Speed;
		n1X = lX[playerid] + Radius * floatcos(Degree[playerid], degrees);
		n1Y = lY[playerid] + Radius * floatsin(Degree[playerid], degrees);
		SetPlayerCameraPos(playerid, n1X, n1Y, lZ[playerid] + Height);
		SetPlayerCameraLookAt(playerid, lX[playerid], lY[playerid], lZ[playerid]+1);
		SetPlayerFacingAngle(playerid, Degree[playerid] - 90.0);
		takingselfie[playerid] = 1;
		ApplyAnimation(playerid, "PED", "gang_gunstand", 4.1, 1, 1, 1, 1, 1, 1);
		return 1;
	}
    if(takingselfie[playerid] == 1)
	{
	    TogglePlayerControllable(playerid,1);
		SetCameraBehindPlayer(playerid);
	    takingselfie[playerid] = 0;
	    ApplyAnimation(playerid, "PED", "ATM", 4.1, 0, 1, 1, 0, 1, 1);
	    return 1;
	}
    return 1;
}