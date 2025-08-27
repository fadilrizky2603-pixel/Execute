// DYNAMIC BILLIARDS by HydraX

// INCLUDES SHITS
#include <physics>
#include <bfx_objects>

#define MAX_POOL 99

// ENUMS
enum POOL_ENUM
{
    bID,
    bBalls[16],
    bTable,
    bInterior,
    bWorld,
    bUsed,
    bPlayer1,
    bPlayer2,
    bCurrentShooter,
    bLastShooter,
    Float:bPosX,
    Float:bPosY,
    Float:bPosZ,
};
new PoolInfo[MAX_POOL][POOL_ENUM];
new CueTimer[MAX_PLAYERS] = {-1, ...};
new Float:CuePower[MAX_PLAYERS];
new Float:CueAimAngle[MAX_PLAYERS][2];
new PoolDir[MAX_PLAYERS];
new AimObject[MAX_PLAYERS];
new Text:PoolTD[4];

forward Float:GetPointDistanceToPoint(Float:x1,Float:y1,Float:x2,Float:y2);

// YOU CAN PUT THIS ANYWHERE!!!
forward Pool_Timer(playerid, poolid);
public Pool_Timer(playerid, poolid)
{
    if (PoolInfo[poolid][bCurrentShooter] == playerid)
    {
        if (AccountData[playerid][pAiming] != 0)
        {
            new keys, ud, lr;
            GetPlayerKeys(playerid, keys, ud, lr);
            if (!(keys & KEY_FIRE))
            {
                if (lr)
                {
                    new Float:X,
                    Float:Y,
                    Float:Z,
                    Float:Xa,
                    Float:Ya,
                    Float:Za,
                    Float:x,
                    Float:y,
                    Float:newrot,
                    Float:dist1;
                    GetPlayerPos(playerid, X, Y, Z);
                    GetObjectPos(PoolInfo[poolid][bBalls][0], Xa, Ya, Za);
                    newrot = CueAimAngle[playerid][0] + (lr > 0 ? 0.9 : -0.9);
                    dist1 = GetPointDistanceToPoint(X, Y, Xa, Ya);
                    if (AngleInRangeOfAngle(CueAimAngle[playerid][1], newrot, 30.0))
                    {
                        CueAimAngle[playerid][0] = newrot;
                        GetXYBehindObjectInAngle(PoolInfo[poolid][bBalls][0], newrot, x, y, 0.675);
                        SetPlayerCameraPos(playerid, x, y, Za + 0.28);
                        SetPlayerCameraLookAt(playerid, Xa, Ya, Za + 0.170);
                        GetXYInFrontOfPos(Xa, Ya, newrot + 180, x, y, 0.085);
                        SetObjectPos(AimObject[playerid], x, y, Za);
                        SetObjectRot(AimObject[playerid], 7.0, 0, CueAimAngle[playerid][0] + 180);
                        GetXYInFrontOfPos(Xa, Ya, newrot + 180, X, Y, dist1);
                        SetPlayerPos(playerid, X, Y, Z);
                        SetPlayerFacingAngle(playerid, newrot);
                    }
                }
            }
            else
            {
                if (PoolDir[playerid])
                    CuePower[playerid] -= 2.0;
                else
                    CuePower[playerid] += 2.0;
                if (CuePower[playerid] <= 0)
                {
                    PoolDir[playerid] = 0;
                    CuePower[playerid] = 2.0;
                }
                else if (CuePower[playerid] > 100.0)
                {
                    PoolDir[playerid] = 1;
                    CuePower[playerid] = 98.0;
                }
                TextDrawTextSize(PoolTD[2], 501.0 + ((67.0 * CuePower[playerid]) / 100.0), 0.0);
                TextDrawShowForPlayer(playerid, PoolTD[2]);
            }
        }
    }
    return 1;
}



// COMMANDS
CMD:apool(playerid, params[])
{
    new Float:x, Float:y, Float:z, option[16], secoption[128], poolid = -1;

    if (AccountData[playerid][pAdmin] < 7)
    {
        return SendClientMessage(playerid, X11_ORANGE, "You are not authorized to use this command.");
    }
    if (sscanf(params, "s[16] S[128]", option, secoption))
    {
        return SendClientMessage(playerid, X11_ORANGE, "Usage: /apool [create / remove / goto]");
    }
    if(!strcmp(option, "create", true))
    {
        if ((poolid = GetNextPoolTableID()) == -1) return SM(playerid, "Maximum number of pooltable reached.");

		GetPlayerPos(playerid, x, y, z);
		//PoolInfo[poolid][bID] = poolid + 1;
		PoolInfo[poolid][bPosX] = x;
		PoolInfo[poolid][bPosY] = y;
		PoolInfo[poolid][bPosZ] = z;
		PoolInfo[poolid][bUsed] = 0;
		PoolInfo[poolid][bPlayer1] = -1;
		PoolInfo[poolid][bPlayer2] = -1;
		PoolInfo[poolid][bLastShooter] = -1;
		PoolInfo[poolid][bCurrentShooter] = -1;
		PoolInfo[poolid][bInterior] = GetPlayerInterior(playerid);
		PoolInfo[poolid][bWorld] = GetPlayerVirtualWorld(playerid);
		PoolInfo[poolid][bBalls][0] = CreateObject(3003, x + 0.5,  y,         z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][1] = CreateObject(3002, x - 0.3,   y,         z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][2] = CreateObject(3100, x - 0.525, y - 0.040, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][3] = CreateObject(3101, x - 0.375, y + 0.044, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][4] = CreateObject(3102, x - 0.600, y + 0.079, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][5] = CreateObject(3103, x - 0.525, y + 0.118, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][6] = CreateObject(3104, x - 0.600, y - 0.157, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][7] = CreateObject(3105, x - 0.450, y - 0.079, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][8] = CreateObject(3106, x - 0.450, y,         z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][9] = CreateObject(2995, x - 0.375, y - 0.044, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][10] = CreateObject(2996, x - 0.450, y + 0.079, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][11] = CreateObject(2997, x - 0.525, y - 0.118, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][12] = CreateObject(2998, x - 0.600, y - 0.079, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][13] = CreateObject(2999, x - 0.600, y,         z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][14] = CreateObject(3000, x - 0.600, y + 0.157, z -0.045 , 0, 0, 0);
		PoolInfo[poolid][bBalls][15] = CreateObject(3001, x - 0.525, y + 0.040, z -0.045 , 0, 0, 0);

		PoolInfo[poolid][bTable] = CreateDynamicObject(2964, x, y, z -1 , 0, 0, 0, PoolInfo[poolid][bWorld], PoolInfo[poolid][bInterior]);

		PHY_CreateArea(x - 1.000, y - 0.500, x + 1.000, y + 0.500,0.6, FLOAT_NEG_INFINITY);
		AddPoolTableToFile(poolid, x, y, z, PoolInfo[poolid][bInterior], PoolInfo[poolid][bWorld]);

        SendAdminMessage(X11_TOMATO, "%s created a pool table [ID: %i].", AccountData[playerid][pAdminname], poolid);
    }
    else if(!strcmp(option, "remove", true))
    {
        new query[128];
        if ((poolid = GetNearestPoolTable(playerid)) == -1)
        {
            return SendClientMessage(playerid, X11_TOMATO, "There is no pool table near you.");
        }

        if (PoolInfo[poolid][bUsed])
        {
            if (PoolInfo[poolid][bPlayer1] != -1)
            {
                AccountData[PoolInfo[poolid][bPlayer1]][pPoolTable] = -1;
                AccountData[PoolInfo[poolid][bPlayer1]][pPlayingPool] = 0;
                SendClientMessage(playerid, PoolInfo[poolid][bPlayer1], "An admin removed the pool table that you were playing on.");
            }
            if (PoolInfo[poolid][bPlayer2] != -1)
            {
                AccountData[PoolInfo[poolid][bPlayer2]][pPoolTable] = -1;
                AccountData[PoolInfo[poolid][bPlayer2]][pPlayingPool] = 0;
                SendClientMessage(playerid, PoolInfo[poolid][bPlayer2], "An admin removed the pool table that you were playing on.");
            }
        }

        for (new i = 0; i < 16; i++)
        DestroyObject(PoolInfo[poolid][bBalls][i]);
        DestroyDynamicObject(PoolInfo[poolid][bTable]);

		format(query, sizeof(query), "DELETE FROM `poll` WHERE `id` = '%d'", PoolInfo[poolid][bID]);
		mysql_tquery(dcrp_query, query);

        SM(playerid, "You have deleted the pool table [ID: %i].", poolid);
    }
    else if(!strcmp(option, "goto", true))
    {
        new id;
        if (sscanf(secoption, "i", id))
        {
            return SendClientMessage(playerid, X11_ORANGE, "Usage: /apool goto [Pool Table ID]");
        }
        if (id < 0 || id > MAX_POOL)
        {
            return SendClientMessage(playerid, X11_TOMATO, "Pool Table not found.");
        }

        SetPlayerPos(playerid, PoolInfo[id][bPosX], PoolInfo[id][bPosY], PoolInfo[id][bPosZ]);
        SetPlayerVirtualWorld(playerid, PoolInfo[id][bWorld]);
        SetPlayerInterior(playerid, PoolInfo[id][bInterior]);
    }
    else
    {
        return SendClientMessage(playerid, X11_ORANGE, "Invalid option. Usage: /apool [create / remove / goto]");
    }
    return 1;
}

CMD:leavepooltable(playerid, params[])
{
	new poolid = AccountData[playerid][pPoolTable];
	if (AccountData[playerid][pPlayingPool] == 0)
	{
		return SendClientMessage(playerid, X11_TOMATO, "You are not playing a pool game.");
	}
	if(PoolInfo[poolid][bPlayer1] == playerid)
	{
		PoolInfo[poolid][bPlayer1] = -1;
		AccountData[playerid][pPoolTable] = -1;
		AccountData[playerid][pPlayingPool] = 0;
		PoolInfo[poolid][bUsed] = 0;
		SendClientMessage(playerid, X11_GOLD, "You have left the pool game.");
		SetPlayerArmedWeapon(playerid, 0);
		RespawnPoolBalls(poolid);
	}
	if(PoolInfo[poolid][bPlayer2] == playerid)
	{
		PoolInfo[poolid][bPlayer2] = -1;
		AccountData[playerid][pPoolTable] = -1;
		AccountData[playerid][pPlayingPool] = 0;
		PoolInfo[poolid][bUsed] = 0;
		SendClientMessage(playerid, X11_GOLD, "You have left the pool game.");
		SetPlayerArmedWeapon(playerid, 0);
		RespawnPoolBalls(poolid);
	}
	return 1;
}

CMD:playpool(playerid, params[])
{
	new poolid, option[128], secoption[128];
	if (sscanf(params, "s[16]S()[128]", option, secoption))
	{
		return SendClientMessage(playerid, X11_TOMATO, "/playpool [solo / multiplayer]");
	}
	if (!strcmp(option, "solo", true))
	{
		if ((poolid = GetNearestPoolTable(playerid)) == -1)
		{
			return SendClientMessage(playerid, X11_TOMATO, "There is no pool table near you.");
		}
		if (AccountData[playerid][pPlayingPool] != 0)
		{
			return SendClientMessage(playerid, X11_TOMATO, "You are already playing on this pool table or in another pool table.");
		}
		if(PoolInfo[poolid][bUsed] == 1)
		{
			return SendClientMessage(playerid, X11_TOMATO, "This pool table is used by someone.");
		} 
		if (GetPlayerWeapon(playerid) > 7)
		{
			return SendClientMessage(playerid, X11_TOMATO, "You don't have a pool cue in your hand.");
		}


		AccountData[playerid][pPoolTable] = poolid;
		AccountData[playerid][pPlayingPool] = 1;
		PoolInfo[poolid][bPlayer1] = playerid;
		PoolInfo[poolid][bUsed] = 1;
		PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        

		for(new i; i < 16; i++)
		{
			PHY_InitObject(PoolInfo[poolid][bBalls][i], 3003, _, _, PHY_MODE_2D);
			PHY_SetObjectFriction(PoolInfo[poolid][bBalls][i], 0.08);
			PHY_RollObject(PoolInfo[poolid][bBalls][i]);
		}
		return 1;
	}
	if (!strcmp(option, "multiplayer", true))
	{
		new userid , targetid;
		if (sscanf(secoption, "i", userid))
		{
			return SendClientMessage(playerid, X11_TOMATO, "/playpool multiplayer [Player 2 ID]");
		}
		if ((poolid = GetNearestPoolTable(playerid)) == -1)
		{
			return SendClientMessage(playerid, X11_TOMATO, "There is no pool table near you.");
		}
		if (AccountData[playerid][pPlayingPool] != 0)
		{
			return SendClientMessage(playerid, X11_TOMATO, "You are already playing on this pool table or in another pool table.");
		}
		if (AccountData[playerid][pPlayingPool] != 0)
		{
			return SendClientMessage(playerid, X11_TOMATO, "You are already playing on this pool table or in another pool table.");
		}
		if (!IsPlayerConnected(userid)) 
		{
			return SendClientMessage(playerid, X11_TOMATO, "The player is offline."); 
		}           	 
		if (!IsPlayerNearPlayer(playerid, targetid, 5.0))
		{
			return SendClientMessage(playerid, X11_ORANGE, "The player specified is disconnected or out of range.");
		}
		if(PoolInfo[poolid][bUsed] == 1)
		{
			return SendClientMessage(playerid, X11_TOMATO, "This pool table is used by someone.");
		}
		if (GetPlayerWeapon(playerid) > 7)
		{
			return SendClientMessage(playerid, X11_TOMATO, "You don't have a pool cue in your hand.");
		}
		if (GetPlayerWeapon(playerid) > 7)
		{
			return SendClientMessage(playerid, X11_TOMATO, "That player doesn't have a pool cue in their hand.");
		}

		PoolInfo[poolid][bPlayer1] = playerid;
		PoolInfo[poolid][bPlayer2] = userid;

		AccountData[playerid][pPoolTable] = poolid;
		AccountData[playerid][pPlayingPool] = 1;

		AccountData[userid][pPoolTable] = poolid;
		AccountData[userid][pPlayingPool] = 1;

		PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		PlayerPlaySound(userid, 1085, 0.0, 0.0, 0.0);

		SM(playerid, "You have invited %s to play a pool game with you.", GetRPName(userid));
		SM(userid, "You have been invited by %s to play a pool game with him/her.", GetRPName(playerid));

		for(new i; i < 16; i++)
		{
			PHY_InitObject(PoolInfo[poolid][bBalls][i], 3003, _, _, PHY_MODE_2D); // Notice that I typed modelid 3003 because all the balls are equal.
			PHY_SetObjectFriction(PoolInfo[poolid][bBalls][i], 0.08);
			PHY_RollObject(PoolInfo[poolid][bBalls][i]);
		}
		return 1;
	}
	return 1;
}


// YOU CAN PUT THIS ANYWHERE!
stock BILLIARDS()
{
    mysql_tquery(dcrp_query, "SELECT * FROM `poll`", "LoadPoolTables");
    
    PoolTD[0] = TextDrawCreate(505.000000, 260.000000, "~n~~n~");
	TextDrawBackgroundColor(PoolTD[0], 255);
	TextDrawFont(PoolTD[0], 1);
	TextDrawLetterSize(PoolTD[0], 0.500000, 0.439999);
	TextDrawColor(PoolTD[0], -1);
	TextDrawSetOutline(PoolTD[0], 0);
	TextDrawSetProportional(PoolTD[0], 1);
	TextDrawSetShadow(PoolTD[0], 1);
	TextDrawUseBox(PoolTD[0], 1);
	TextDrawBoxColor(PoolTD[0], 255);
	TextDrawTextSize(PoolTD[0], 569.000000, -10.000000);

	PoolTD[1] = TextDrawCreate(506.000000, 261.000000, "~n~~n~");
	TextDrawBackgroundColor(PoolTD[1], 255);
	TextDrawFont(PoolTD[1], 1);
	TextDrawLetterSize(PoolTD[1], 0.500000, 0.300000);
	TextDrawColor(PoolTD[1], -1);
	TextDrawSetOutline(PoolTD[1], 0);
	TextDrawSetProportional(PoolTD[1], 1);
	TextDrawSetShadow(PoolTD[1], 1);
	TextDrawUseBox(PoolTD[1], 1);
	TextDrawBoxColor(PoolTD[1], 911303167);
	TextDrawTextSize(PoolTD[1], 568.000000, 0.000000);

	PoolTD[2] = TextDrawCreate(506.000000, 261.000000, "~n~~n~");
	TextDrawBackgroundColor(PoolTD[2], 255);
	TextDrawFont(PoolTD[2], 1);
	TextDrawLetterSize(PoolTD[2], 0.500000, 0.300000);
	TextDrawColor(PoolTD[2], -1);
	TextDrawSetOutline(PoolTD[2], 0);
	TextDrawSetProportional(PoolTD[2], 1);
	TextDrawSetShadow(PoolTD[2], 1);
	TextDrawUseBox(PoolTD[2], 1);
	TextDrawBoxColor(PoolTD[2], -1949699841);
	TextDrawTextSize(PoolTD[2], 501.000000, 0.000000);

	PoolTD[3] = TextDrawCreate(503.000000, 240.000000, "Power");
	TextDrawBackgroundColor(PoolTD[3], 255);
	TextDrawFont(PoolTD[3], 2);
	TextDrawLetterSize(PoolTD[3], 0.280000, 1.699999);
	TextDrawColor(PoolTD[3], -1);
	TextDrawSetOutline(PoolTD[3], 1);
	TextDrawSetProportional(PoolTD[3], 1);
    return 1;
}


public PHY_OnObjectCollideWithPlayer(objectid, playerid)
{
    if(AccountData[playerid][pPlayingPool] != 0)
    {
        for(new i; i < MAX_POOL; i++)
        {
            for(new j; j < 16; j++)
            {
                if(objectid == PoolInfo[i][bBalls][j]) return 0;
            }
        }
    }
    return 1;
}

public PHY_OnObjectUpdate(objectid, playerid)
{
    if(AccountData[playerid][pPlayingPool] != 0)
    {
        new poolid = AccountData[playerid][pPoolTable];
        if( IsInBall(objectid , PoolInfo[poolid][bPosX] + 0.955, PoolInfo[poolid][bPosY] + 0.510, PoolInfo[poolid][bPosZ] -0.045,0.10) ||
            IsInBall(objectid , PoolInfo[poolid][bPosX] + 0.955, PoolInfo[poolid][bPosY] - 0.510, PoolInfo[poolid][bPosZ] -0.045,0.10) ||
            IsInBall(objectid , PoolInfo[poolid][bPosX] + 0.000, PoolInfo[poolid][bPosY] + 0.550, PoolInfo[poolid][bPosZ] -0.045,0.10) ||
            IsInBall(objectid , PoolInfo[poolid][bPosX] + 0.000, PoolInfo[poolid][bPosY] - 0.550, PoolInfo[poolid][bPosZ] -0.045,0.10) ||
            IsInBall(objectid , PoolInfo[poolid][bPosX] - 0.955, PoolInfo[poolid][bPosY] + 0.510, PoolInfo[poolid][bPosZ] -0.045,0.10) ||
            IsInBall(objectid , PoolInfo[poolid][bPosX] - 0.955, PoolInfo[poolid][bPosY] - 0.510, PoolInfo[poolid][bPosZ] -0.045,0.10))
        { 
            if(objectid == PoolInfo[poolid][bBalls][0])
            {
                DestroyObject(PoolInfo[poolid][bBalls][0]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][0]);
                PoolInfo[poolid][bBalls][0] = CreateObject(3003, PoolInfo[poolid][bPosX] + 0.5,  PoolInfo[poolid][bPosY], PoolInfo[poolid][bPosZ] -0.045 , 0, 0, 0);
                //SetObjectPos(PoolInfo[poolid][bBalls][0], PoolInfo[poolid][bPosX] + 0.5, PoolInfo[poolid][bPosY], PoolInfo[poolid][bPosZ] -0.045);
                PHY_InitObject(PoolInfo[poolid][bBalls][0], 3003, _, _, PHY_MODE_2D); // Notice that I typed modelid 3003 because all the balls are equal.
                PHY_SetObjectFriction(PoolInfo[poolid][bBalls][0], 0.08);
                PHY_RollObject(PoolInfo[poolid][bBalls][0]);
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} Bad shot! %s have potted the cue ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
            }
            if(objectid == PoolInfo[poolid][bBalls][1])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 1 Solid Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][1]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][1]);
            }
            if(objectid == PoolInfo[poolid][bBalls][2])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 2 Solid Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][2]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][2]);
            }
            if(objectid == PoolInfo[poolid][bBalls][3])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 3 Solid Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][3]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][3]);
            }
            if(objectid == PoolInfo[poolid][bBalls][4])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 4 Solid Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][4]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][4]);
            }
            if(objectid == PoolInfo[poolid][bBalls][5])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 5 Solid Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][5]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][5]);
            }
            if(objectid == PoolInfo[poolid][bBalls][6])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 6 Solid Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][6]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][6]);
            }
            if(objectid == PoolInfo[poolid][bBalls][7])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 7 Solid Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][7]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][7]);
            }
            if(objectid == PoolInfo[poolid][bBalls][8])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 8 Solid Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][8]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][8]);
            }
            if(objectid == PoolInfo[poolid][bBalls][9])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 9 Stripe Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][9]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][9]);
            }
            if(objectid == PoolInfo[poolid][bBalls][10])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 10 Stripe Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][10]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][10]);
            }
            if(objectid == PoolInfo[poolid][bBalls][11])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 11 Stripe Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][11]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][11]);
            }
            if(objectid == PoolInfo[poolid][bBalls][12])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 12 Stripe Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][12]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][12]);
            }
            if(objectid == PoolInfo[poolid][bBalls][13])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 13 Stripe Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][13]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][13]);
            }
            if(objectid == PoolInfo[poolid][bBalls][14])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 14 Stripe Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][14]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][14]);
            }
            if(objectid == PoolInfo[poolid][bBalls][15])
            {
                SendClientMessage(playerid, X11_GOLD, "INFO:{FFFFFF} %s have pocketed number 15 Stripe Ball.", GetRPName(PoolInfo[poolid][bLastShooter]));
                DestroyObject(PoolInfo[poolid][bBalls][15]);
                PHY_DeleteObject(PoolInfo[poolid][bBalls][15]);
            }                  
        }
        return 1;
    }
    return 1;
}

GetNextPoolTableID()
{
	for(new i; i < MAX_POOL; i++)
	{
	    if (!PoolInfo[i][bID]) return i;
	}
	return -1;
}

GetNearestPoolTable(playerid, Float: radius = 2.0)
{
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
	
    for(new i = 0; i != MAX_POOL; i++)
    {
        if (IsPlayerInRangeOfPoint(playerid, radius, PoolInfo[i][bPosX], PoolInfo[i][bPosY], PoolInfo[i][bPosZ]))
        {
			return i;
        }
    }
    return -1;
}

stock Float:GetPointDistanceToPoint(Float:x1,Float:y1,Float:x2,Float:y2)
{
    new Float:x, Float:y;
    x = x1-x2;
    y = y1-y2;
    return floatsqroot(x*x+y*y);
}

stock IsInBall(objectid,Float:x,Float:y,Float:z,Float:radius){

    new
        Float:pos[3],
        Float:dis;
        
    GetObjectPos(objectid, pos[0], pos[1], pos[2]);
    
    dis = floatsqroot(floatpower(floatabs(floatsub(x, pos[0] )), 2)+ floatpower(floatabs(floatsub(y, pos[1] )), 2)+ floatpower(floatabs(floatsub(z, pos[2] )), 2));
    
    if(dis < radius) return 1;
    return 0;
}


stock IsKeyJustDown(key, newkeys, oldkeys)
{
    if((newkeys & key) && !(oldkeys & key)) return 1;
    return 0;
}

stock IsKeyJustUp(key, newkeys, oldkeys)
{
    if(!(newkeys & key) && (oldkeys & key)) return 1;
    return 0;
}

stock Is2DPointInRangeOfPoint(Float:x, Float:y, Float:x2, Float:y2, Float:range)
{
    x2 -= x;
    y2 -= y;
    return ((x2 * x2) + (y2 * y2)) < (range * range);
}

stock GetAngleToXY(Float:X, Float:Y, Float:CurrX, Float:CurrY, &Float:angle)
{
    angle = atan2(Y-CurrY, X-CurrX);
    angle = floatsub(angle, 90.0);
    if(angle < 0.0) angle = floatadd(angle, 360.0);
}

stock GetXYInFrontOfPos(Float:xx,Float:yy,Float:a, &Float:x2, &Float:y2, Float:distance)
{
    if(a>360)
	{
        a=a-360;
    }
    xx += (distance * floatsin(-a, degrees));
    yy += (distance * floatcos(-a, degrees));
    x2=xx;
    y2=yy;
}

stock GetXYBehindObjectInAngle(objectid, Float:a, &Float:x2, &Float:y2, Float:distance)
{
    new Float:z;
    GetObjectPos(objectid, x2, y2, z);

    x2 += (distance * floatsin(-a+180, degrees));
    y2 += (distance * floatcos(-a+180, degrees));
}

stock AngleInRangeOfAngle(Float:a1, Float:a2, Float:range)
{
	a1 -= a2;
	if((a1 < range) && (a1 > -range)) return true;

	return false;
}

stock RespawnPoolBalls(poolid)
{
    new Float:x, Float:y, Float:z;
    for(new i; i < 16; i++)
	{
        DestroyObject(PoolInfo[poolid][bBalls][i]);
        PHY_DeleteObject(PoolInfo[poolid][bBalls][i]);
    }
    x = PoolInfo[poolid][bPosX];
    y = PoolInfo[poolid][bPosY];
    z = PoolInfo[poolid][bPosZ];
    PoolInfo[poolid][bBalls][0] = CreateObject(3003, x + 0.5,  y,         z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][1] = CreateObject(3002, x - 0.3,   y,         z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][2] = CreateObject(3100, x - 0.525, y - 0.040, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][3] = CreateObject(3101, x - 0.375, y + 0.044, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][4] = CreateObject(3102, x - 0.600, y + 0.079, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][5] = CreateObject(3103, x - 0.525, y + 0.118, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][6] = CreateObject(3104, x - 0.600, y - 0.157, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][7] = CreateObject(3105, x - 0.450, y - 0.079, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][8] = CreateObject(3106, x - 0.450, y,         z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][9] = CreateObject(2995, x - 0.375, y - 0.044, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][10] = CreateObject(2996, x - 0.450, y + 0.079, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][11] = CreateObject(2997, x - 0.525, y - 0.118, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][12] = CreateObject(2998, x - 0.600, y - 0.079, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][13] = CreateObject(2999, x - 0.600, y,         z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][14] = CreateObject(3000, x - 0.600, y + 0.157, z -0.045 , 0, 0, 0);
    PoolInfo[poolid][bBalls][15] = CreateObject(3001, x - 0.525, y + 0.040, z -0.045 , 0, 0, 0);
    return 1;
}


AddPoolTableToFile(poolid, Float:PosX, Float:PosY, Float:PosZ, interior, world)
{
    new query[300];
	mysql_format(dcrp_query, query, sizeof(query), "INSERT INTO `poll` (posx, posy, posz, interior, world) VALUES (%f, %f, %f, %i, %i)",
	PosX, PosY, PosZ, interior, world);
	mysql_tquery(dcrp_query, query, "OnPoolTableInsert", "d", poolid);
 	return 1;
}

forward OnPoolTableInsert(poolid);
public OnPoolTableInsert(poolid)
{
	return PoolInfo[poolid][bID] = cache_insert_id();	
}

stock GetPoolBalls(poolid)
{
	new count;
	for(new i; i < 16; i++)
	{
		if(PoolInfo[poolid][bBalls][i] || i == 0) count++;
	}
	return count;
}

forward LoadPoolTables();
public LoadPoolTables()
{
	new rows = cache_num_rows(), time = GetTickCount(), total;

	if (!rows) return print("[Pool Table] No records found.");
	    

	for(new i; i < rows; i++)
	{
		cache_get_value_name_int(i, "id", PoolInfo[i][bID]);
		cache_get_value_name_float(i, "posx", PoolInfo[i][bPosX]);
		cache_get_value_name_float(i, "posy", PoolInfo[i][bPosY]);
	    cache_get_value_name_float(i, "posz", PoolInfo[i][bPosZ]);
		cache_get_value_name_int(i, "interior", PoolInfo[i][bInterior]);
		cache_get_value_name_int(i, "world", PoolInfo[i][bWorld]);
        PoolInfo[i][bUsed] = 0;
		PoolInfo[i][bPlayer1] = -1;
		PoolInfo[i][bPlayer2] = -1;
		PoolInfo[i][bLastShooter] = -1;
		PoolInfo[i][bCurrentShooter] = -1;

        PoolInfo[i][bBalls][0] = CreateObject(3003, PoolInfo[i][bPosX] + 0.5,  PoolInfo[i][bPosY],         PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][1] = CreateObject(3002, PoolInfo[i][bPosX] - 0.3,   PoolInfo[i][bPosY],         PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][2] = CreateObject(3100, PoolInfo[i][bPosX] - 0.525, PoolInfo[i][bPosY] - 0.040, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][3] = CreateObject(3101, PoolInfo[i][bPosX] - 0.375, PoolInfo[i][bPosY] + 0.044, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][4] = CreateObject(3102, PoolInfo[i][bPosX] - 0.600, PoolInfo[i][bPosY] + 0.079, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][5] = CreateObject(3103, PoolInfo[i][bPosX] - 0.525, PoolInfo[i][bPosY] + 0.118, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][6] = CreateObject(3104, PoolInfo[i][bPosX] - 0.600, PoolInfo[i][bPosY] - 0.157, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][7] = CreateObject(3105, PoolInfo[i][bPosX] - 0.450, PoolInfo[i][bPosY] - 0.079, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][8] = CreateObject(3106, PoolInfo[i][bPosX] - 0.450, PoolInfo[i][bPosY],         PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][9] = CreateObject(2995, PoolInfo[i][bPosX] - 0.375, PoolInfo[i][bPosY] - 0.044, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][10] = CreateObject(2996, PoolInfo[i][bPosX] - 0.450, PoolInfo[i][bPosY] + 0.079, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][11] = CreateObject(2997, PoolInfo[i][bPosX] - 0.525, PoolInfo[i][bPosY] - 0.118, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][12] = CreateObject(2998, PoolInfo[i][bPosX] - 0.600, PoolInfo[i][bPosY] - 0.079, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][13] = CreateObject(2999, PoolInfo[i][bPosX] - 0.600, PoolInfo[i][bPosY],         PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][14] = CreateObject(3000, PoolInfo[i][bPosX] - 0.600, PoolInfo[i][bPosY] + 0.157, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);
		PoolInfo[i][bBalls][15] = CreateObject(3001, PoolInfo[i][bPosX] - 0.525, PoolInfo[i][bPosY] + 0.040, PoolInfo[i][bPosZ] -0.045 , 0, 0, 0);

        PoolInfo[i][bTable] = CreateDynamicObject(2964, PoolInfo[i][bPosX], PoolInfo[i][bPosY], PoolInfo[i][bPosZ] -1, 0, 0, 0, PoolInfo[i][bWorld], PoolInfo[i][bInterior]);
        PHY_CreateArea(PoolInfo[i][bPosX] - 1.000, PoolInfo[i][bPosY] - 0.500, PoolInfo[i][bPosX] + 1.000, PoolInfo[i][bPosY] + 0.500,0.6, FLOAT_NEG_INFINITY);
		total++;
	}

	printf("[Pool Tables] Rows - %i. Load - %i. Time: %i ms.", rows, total, GetTickCount()-time);
	return 1;
}
