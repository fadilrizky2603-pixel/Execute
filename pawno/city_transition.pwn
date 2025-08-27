#include <a_samp>
#include "city_transition.inc"

// Callback when player transitions between cities
public OnPlayerCityTransition(playerid, bool:entering)
{
    // Prevent disconnection by handling the transition smoothly
    if(entering)
    {
        // Player is entering a city
        // Save their current state
        new
            Float:health,
            Float:armour,
            Float:x,
            Float:y,
            Float:z,
            Float:angle,
            interior,
            virtualworld;
            
        GetPlayerHealth(playerid, health);
        GetPlayerArmour(playerid, armour);
        GetPlayerPos(playerid, x, y, z);
        GetPlayerFacingAngle(playerid, angle);
        interior = GetPlayerInterior(playerid);
        virtualworld = GetPlayerVirtualWorld(playerid);
        
        // Small delay to ensure smooth transition
        SetTimerEx("RestorePlayerState", 100, false, "ifffffii", 
            playerid, health, armour, x, y, z, angle, interior, virtualworld);
    }
    return 1;
}

// Restore player state after transition
forward RestorePlayerState(playerid, Float:health, Float:armour, Float:x, Float:y, Float:z, Float:angle, interior, virtualworld);
public RestorePlayerState(playerid, Float:health, Float:armour, Float:x, Float:y, Float:z, Float:angle, interior, virtualworld)
{
    if(IsPlayerConnected(playerid))
    {
        SetPlayerHealth(playerid, health);
        SetPlayerArmour(playerid, armour);
        SetPlayerPos(playerid, x, y, z);
        SetPlayerFacingAngle(playerid, angle);
        SetPlayerInterior(playerid, interior);
        SetPlayerVirtualWorld(playerid, virtualworld);
    }
    return 1;
}

// Main function
main()
{
    print("\n----------------------------------");
    print(" City Transition Handler Loaded");
    print("----------------------------------\n");
}

// Initialize when script starts
public OnFilterScriptInit()
{
    print("\n----------------------------------");
    print(" City Transition Handler Started");
    print("----------------------------------\n");
    return 1;
}

// Clean up when script ends
public OnFilterScriptExit()
{
    print("\n----------------------------------");
    print(" City Transition Handler Stopped");
    print("----------------------------------\n");
    return 1;
} 