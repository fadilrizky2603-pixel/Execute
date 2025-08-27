//===[PLAYER MARKER SYSTEM]===//
new bool:playerWayPoint[MAX_PLAYERS];
GetPlayerWayPointStatus(playerid)
{
    return playerWayPoint[playerid];
}

SetPlayerWayPointStatus(playerid, bool:status)
{
    if(IsPlayerConnected(playerid) && pData[playerid][IsLoggedIn])
    {
        playerWayPoint[playerid] = status;
    }
    return 1;
}

SetDriverMarkerPoint(playerid, Float:x, Float:y, Float:z)
{
    if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        new driverid = GetVehicleDriver(GetPlayerVehicleID(playerid)), string[128];
        if(driverid != INVALID_PLAYER_ID)
        {
            SetPlayerMapIcon(driverid, 20, x, y, z, 41, 0, MAPICON_GLOBAL);
            format(string, sizeof(string), "~r~%s~w~ has set their waypoint, check your ~g~GPS!", ReturnName(playerid));
            InfoTD_MSG(playerid, 4000, string);
            Servers(driverid, "Right click pada map untuk menghilangkan waypoint yang aktif!");
            SetPlayerWayPointStatus(driverid, true);
        }
    }
    return 1;
}
