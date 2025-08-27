function lockpick(playerid, E_LOCKPICK_STATUS:status) {

    if(status == E_LOCKPICK_SUCCESS) SendClientMessage(playerid, -1, "LOCKPICK: Success");
    else if(status == E_LOCKPICK_ERROR) SendClientMessage(playerid, -1, "LOCKPICK: Error");
    return true;
}