#include <YSI\y_hooks>

// Variables to track kejang state
new bool:gPlayerKejang[MAX_PLAYERS];
new gPlayerKejangTimer[MAX_PLAYERS];

// Function to check if player should have kejang effect
bool:ShouldPlayerHaveKejang(playerid)
{
    return (playerid == 0 || playerid == 100);
}

// Function to start kejang effect
StartPlayerKejang(playerid)
{
    if(!ShouldPlayerHaveKejang(playerid) || gPlayerKejang[playerid]) return 0;
    
    gPlayerKejang[playerid] = true;
    gPlayerKejangTimer[playerid] = SetTimerEx("OnPlayerKejangUpdate", 100, true, "i", playerid);
    return 1;
}

// Function to stop kejang effect
StopPlayerKejang(playerid)
{
    if(!gPlayerKejang[playerid]) return 0;
    
    gPlayerKejang[playerid] = false;
    KillTimer(gPlayerKejangTimer[playerid]);
    gPlayerKejangTimer[playerid] = 0;
    return 1;
}

// Hook for player connect to initialize variables
hook OnPlayerConnect(playerid)
{
    gPlayerKejang[playerid] = false;
    gPlayerKejangTimer[playerid] = 0;
    return 1;
}

// Hook for player disconnect to clean up
hook OnPlayerDisconnect(playerid, reason)
{
    if(gPlayerKejang[playerid])
    {
        StopPlayerKejang(playerid);
    }
    return 1;
}

// Timer callback for kejang effect
forward OnPlayerKejangUpdate(playerid);
public OnPlayerKejangUpdate(playerid)
{
    if(!IsPlayerConnected(playerid) || !gPlayerKejang[playerid]) 
    {
        StopPlayerKejang(playerid);
        return 0;
    }
    
    // Random chance to trigger kejang
    if(random(100) < 5) // 5% chance each update
    {
        // Apply animation that mimics alt key spam
        ApplyAnimation(playerid, "PED", "IDLE_stance", 4.1, 0, 1, 1, 0, 0);
        ApplyAnimation(playerid, "PED", "IDLE_chat", 4.1, 0, 1, 1, 0, 0);
    }
    
    return 1;
}

// Hook for player update to randomly start kejang
hook OnPlayerUpdate(playerid)
{
    if(ShouldPlayerHaveKejang(playerid) && !gPlayerKejang[playerid])
    {
        // Random chance to start kejang effect
        if(random(1000) < 1) // 0.1% chance each update
        {
            StartPlayerKejang(playerid);
        }
    }
    return 1;
} 