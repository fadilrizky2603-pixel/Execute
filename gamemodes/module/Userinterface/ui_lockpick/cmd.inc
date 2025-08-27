CMD:lockpick(playerid, params[]) {

    new time;
    if(sscanf(params, "d", time))
        return true;

    CreateLockPick(playerid, "lockpick", time);
    return true;
}
