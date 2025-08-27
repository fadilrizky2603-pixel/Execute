GivePlayerHelmet(playerid)
{
	// Don't continue unless player wants a helmet
	//if(GetPVarInt(playerid, "HelmetDisabled") == 1)
	//	return true;

	// Check if this skin even has a helmet preset and store the player's skin in a variable for performance
	new skin = GetPlayerSkin(playerid);
	if(HelmetPos[skin][0] == 0.0)
		return 0;

	// Modify the helmet scale
	static Float:HelmetScaleX = 1.0, Float:HelmetScaleY = 1.0, Float:HelmetScaleZ = 1.0;
	if(HelmetPos[skin][6] > 0.0) HelmetScaleX = HelmetPos[skin][6];
	if(HelmetPos[skin][7] > 0.0) HelmetScaleY = HelmetPos[skin][7];
	if(HelmetPos[skin][8] > 0.0) HelmetScaleZ = HelmetPos[skin][8];

	// Attach the helmet to the player
	SetPlayerAttachedObject(playerid, 9, 18645, 2, HelmetPos[skin][0], HelmetPos[skin][1], HelmetPos[skin][2], HelmetPos[skin][3], HelmetPos[skin][4], HelmetPos[skin][5], HelmetScaleX, HelmetScaleY, HelmetScaleZ);
	return 1;
}