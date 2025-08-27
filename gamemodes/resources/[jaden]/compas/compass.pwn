// Forward declarations
forward Compass_OnPlayerConnect(playerid);
forward Compass_OnPlayerDisconnect(playerid, reason);
forward Compass_OnPlayerUpdate(playerid);
forward Compass_UpdateTimer(playerid);
forward Compass_OnPlayerStateChange(playerid, newstate, oldstate);

#include <a_samp>

//variables
new PlayerText:JADENCOMPAS[MAX_PLAYERS][11];
new bool:CompassVisible[MAX_PLAYERS];
new CompassTimer[MAX_PLAYERS];
new Float:LastAngle[MAX_PLAYERS];

public OnFilterScriptInit()
{
    return 1;
}

public OnFilterScriptExit()
{
    return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
        if(!CompassVisible[playerid])
        {
            CompassVisible[playerid] = true;
            GetPlayerFacingAngle(playerid, LastAngle[playerid]);
            for(new i = 0; i < 11; i++)
            {
                PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
            }
            CompassTimer[playerid] = SetTimerEx("Compass_UpdateTimer", 50, true, "i", playerid);
        }
    }
    else if(oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER)
    {
        if(CompassVisible[playerid])
        {
            CompassVisible[playerid] = false;
            for(new i = 0; i < 11; i++)
            {
                PlayerTextDrawHide(playerid, JADENCOMPAS[playerid][i]);
            }
            if(CompassTimer[playerid])
            {
                KillTimer(CompassTimer[playerid]);
                CompassTimer[playerid] = 0;
            }
        }
    }
    return CallLocalFunction("Compass_OnPlayerStateChange", "iii", playerid, newstate, oldstate);
}

#if defined _ALS_OnPlayerStateChange
    #undef OnPlayerStateChange
#else
    #define _ALS_OnPlayerStateChange
#endif

#define OnPlayerStateChange Compass_OnPlayerStateChange

public Compass_OnPlayerConnect(playerid)
{
    CompassVisible[playerid] = false;
    CompassTimer[playerid] = 0;
    LastAngle[playerid] = 0.0;
    
    //JADEN COMPASS-TD
    JADENCOMPAS[playerid][0] = CreatePlayerTextDraw(playerid, 122.000, 0.000, "I");
    PlayerTextDrawLetterSize(playerid, JADENCOMPAS[playerid][0], 32.240, 2.398);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][0], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][0], 60);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][0], 0);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][0], 1);

    JADENCOMPAS[playerid][1] = CreatePlayerTextDraw(playerid, 320.000, 5.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JADENCOMPAS[playerid][1], 1.000, 2.000);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][1], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][1], 502315826);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][1], 255);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][1], 1);

    JADENCOMPAS[playerid][2] = CreatePlayerTextDraw(playerid, 243.000, 8.000, "NE");
    PlayerTextDrawLetterSize(playerid, JADENCOMPAS[playerid][2], 0.140, 0.699);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][2], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][2], 502316031);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][2], 150);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][2], 1);

    JADENCOMPAS[playerid][3] = CreatePlayerTextDraw(playerid, 268.000, 8.000, "50");
    PlayerTextDrawLetterSize(playerid, JADENCOMPAS[playerid][3], 0.140, 0.699);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][3], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][3], 150);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][3], 1);

    JADENCOMPAS[playerid][4] = CreatePlayerTextDraw(playerid, 293.000, 8.000, "75");
    PlayerTextDrawLetterSize(playerid, JADENCOMPAS[playerid][4], 0.140, 0.699);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][4], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][4], 150);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][4], 1);

    JADENCOMPAS[playerid][5] = CreatePlayerTextDraw(playerid, 318.000, 8.000, "W");
    PlayerTextDrawLetterSize(playerid, JADENCOMPAS[playerid][5], 0.128, 0.699);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][5], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][5], 150);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][5], 1);

    JADENCOMPAS[playerid][6] = CreatePlayerTextDraw(playerid, 341.000, 8.000, "105");
    PlayerTextDrawLetterSize(playerid, JADENCOMPAS[playerid][6], 0.140, 0.699);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][6], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][6], 150);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][6], 1);

    JADENCOMPAS[playerid][7] = CreatePlayerTextDraw(playerid, 366.000, 8.000, "120");
    PlayerTextDrawLetterSize(playerid, JADENCOMPAS[playerid][7], 0.140, 0.699);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][7], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][7], 150);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][7], 1);

    JADENCOMPAS[playerid][8] = CreatePlayerTextDraw(playerid, 391.000, 8.000, "SE");
    PlayerTextDrawLetterSize(playerid, JADENCOMPAS[playerid][8], 0.140, 0.699);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][8], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][8], 502316031);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][8], 150);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][8], 2);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][8], 1);

    JADENCOMPAS[playerid][9] = CreatePlayerTextDraw(playerid, 394.000, 5.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JADENCOMPAS[playerid][9], 1.000, 2.000);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][9], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][9], 502315876);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][9], 255);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][9], 1);

    JADENCOMPAS[playerid][10] = CreatePlayerTextDraw(playerid, 247.000, 5.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JADENCOMPAS[playerid][10], 1.000, 2.000);
    PlayerTextDrawAlignment(playerid, JADENCOMPAS[playerid][10], 1);
    PlayerTextDrawColor(playerid, JADENCOMPAS[playerid][10], 502315876);
    PlayerTextDrawSetShadow(playerid, JADENCOMPAS[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, JADENCOMPAS[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, JADENCOMPAS[playerid][10], 255);
    PlayerTextDrawFont(playerid, JADENCOMPAS[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, JADENCOMPAS[playerid][10], 1);
    return 1;
}

public Compass_OnPlayerDisconnect(playerid, reason)
{
    if(CompassTimer[playerid])
    {
        KillTimer(CompassTimer[playerid]);
        CompassTimer[playerid] = 0;
    }
    
    for(new i = 0; i < 11; i++)
    {
        PlayerTextDrawDestroy(playerid, JADENCOMPAS[playerid][i]);
    }
    return 1;
}

public Compass_OnPlayerUpdate(playerid)
{
    if(CompassVisible[playerid])
    {
        new Float:angle;
        GetPlayerFacingAngle(playerid, angle);
        
        // Update compass direction based on angle
        if(angle >= 337.5 || angle < 22.5)
        {
            PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "N");
            PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][5]);
        }
        else if(angle >= 22.5 && angle < 67.5)
        {
            PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "NE");
            PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][5]);
        }
        else if(angle >= 67.5 && angle < 112.5)
        {
            PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "E");
            PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][5]);
        }
        else if(angle >= 112.5 && angle < 157.5)
        {
            PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "SE");
            PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][5]);
        }
        else if(angle >= 157.5 && angle < 202.5)
        {
            PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "S");
            PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][5]);
        }
        else if(angle >= 202.5 && angle < 247.5)
        {
            PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "SW");
            PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][5]);
        }
        else if(angle >= 247.5 && angle < 292.5)
        {
            PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "W");
            PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][5]);
        }
        else if(angle >= 292.5 && angle < 337.5)
        {
            PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "NW");
            PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][5]);
        }
    }
    return 1;
}

public Compass_UpdateTimer(playerid)
{
    if(CompassVisible[playerid])
    {
        new Float:angle;
        if(IsPlayerInAnyVehicle(playerid))
        {
            new vehicleid = GetPlayerVehicleID(playerid);
            GetVehicleZAngle(vehicleid, angle);
        }
        else
        {
            GetPlayerFacingAngle(playerid, angle);
        }
        
        // Smooth angle transition
        if(angle != LastAngle[playerid])
        {
            new Float:diff = angle - LastAngle[playerid];
            if(diff > 180.0) diff -= 360.0;
            else if(diff < -180.0) diff += 360.0;
            
            // Interpolate angle for smoother transition
            LastAngle[playerid] += diff * 0.2;
            if(LastAngle[playerid] >= 360.0) LastAngle[playerid] -= 360.0;
            else if(LastAngle[playerid] < 0.0) LastAngle[playerid] += 360.0;
            
            // Show all TextDraws first
            for(new i = 0; i < 11; i++)
            {
                PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
            }
            
            // Update compass direction based on interpolated angle
            if(LastAngle[playerid] >= 337.5 || LastAngle[playerid] < 22.5)
            {
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][2], "NW");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][3], "315");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][4], "330");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "N");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][6], "30");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][7], "45");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][8], "NE");
                for(new i = 2; i <= 8; i++) PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
            }
            else if(LastAngle[playerid] >= 22.5 && LastAngle[playerid] < 67.5)
            {
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][2], "N");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][3], "345");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][4], "0");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "NE");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][6], "60");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][7], "75");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][8], "E");
                for(new i = 2; i <= 8; i++) PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
            }
            else if(LastAngle[playerid] >= 67.5 && LastAngle[playerid] < 112.5)
            {
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][2], "NE");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][3], "15");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][4], "30");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "E");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][6], "90");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][7], "105");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][8], "SE");
                for(new i = 2; i <= 8; i++) PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
            }
            else if(LastAngle[playerid] >= 112.5 && LastAngle[playerid] < 157.5)
            {
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][2], "E");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][3], "75");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][4], "90");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "SE");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][6], "120");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][7], "135");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][8], "S");
                for(new i = 2; i <= 8; i++) PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
            }
            else if(LastAngle[playerid] >= 157.5 && LastAngle[playerid] < 202.5)
            {
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][2], "SE");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][3], "105");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][4], "120");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "S");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][6], "150");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][7], "165");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][8], "SW");
                for(new i = 2; i <= 8; i++) PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
            }
            else if(LastAngle[playerid] >= 202.5 && LastAngle[playerid] < 247.5)
            {
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][2], "S");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][3], "135");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][4], "150");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "SW");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][6], "180");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][7], "195");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][8], "W");
                for(new i = 2; i <= 8; i++) PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
            }
            else if(LastAngle[playerid] >= 247.5 && LastAngle[playerid] < 292.5)
            {
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][2], "SW");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][3], "165");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][4], "180");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "W");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][6], "210");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][7], "225");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][8], "NW");
                for(new i = 2; i <= 8; i++) PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
            }
            else if(LastAngle[playerid] >= 292.5 && LastAngle[playerid] < 337.5)
            {
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][2], "W");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][3], "195");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][4], "210");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][5], "NW");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][6], "240");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][7], "255");
                PlayerTextDrawSetString(playerid, JADENCOMPAS[playerid][8], "N");
                for(new i = 2; i <= 8; i++) PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
            }
        }
    }
    return 1;
}

CMD:compass(playerid, params[])
{
    if(CompassVisible[playerid])
    {
        CompassVisible[playerid] = false;
        for(new i = 0; i < 11; i++)
        {
            PlayerTextDrawHide(playerid, JADENCOMPAS[playerid][i]);
        }
        if(CompassTimer[playerid])
        {
            KillTimer(CompassTimer[playerid]);
            CompassTimer[playerid] = 0;
        }
        SendClientMessage(playerid, -1, "Compass: "WHITE"Disabled");
    }
    else
    {
        CompassVisible[playerid] = true;
        GetPlayerFacingAngle(playerid, LastAngle[playerid]);
        for(new i = 0; i < 11; i++)
        {
            PlayerTextDrawShow(playerid, JADENCOMPAS[playerid][i]);
        }
        CompassTimer[playerid] = SetTimerEx("Compass_UpdateTimer", 50, true, "i", playerid);
        SendClientMessage(playerid, -1, "Compass: "WHITE"Enabled");
    }
    return 1;
} 