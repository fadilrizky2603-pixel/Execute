CMD:pedagangcreate(playerid, params[])
{
    if(pData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    
    new pid = Iter_Free(Pedagang), query[128];
    if(pid == -1) return Error(playerid, "You cant create more locker!");
    new type;
    if(sscanf(params, "d", type)) return Usage(playerid, "/pedagangcreate [type, 1.SA PEDAGANG]");
    
    if(type < 1 || type > 1) return Error(playerid, "Invapid type.");
    
    GetPlayerPos(playerid, pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ]);
    pdgDATA[pid][pdgInt] = GetPlayerInterior(playerid);
    pdgDATA[pid][pdgType] = type;
    Pedagang_Refresh(pid);
    Iter_Add(Pedagang, pid);

    mysql_format(g_SQL, query, sizeof(query), "INSERT INTO pedagang SET id='%d', type='%d', posx='%f', posy='%f', posz='%f'", pid, pdgDATA[pid][pdgType], pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ]);
    mysql_tquery(g_SQL, query, "OnLockerCreated", "i", pid);
    return 1;
}

CMD:gotogudang(playerid, params[])
{
    new pid;
    if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
        
    if(sscanf(params, "d", pid))
        return Usage(playerid, "/gotogudang [id]");
    if(!Iter_Contains(Pedagang, pid)) return Error(playerid, "The locker you specified ID of doesn't exist.");
    SetPlayerPosition(playerid, pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ], 2.0);
    SetPlayerInterior(playerid, pdgDATA[pid][pdgInt]);
    SetPlayerVirtualWorld(playerid, 0);
    Servers(playerid, "You has teleport to locker id %d", pid);
    return 1;
}

CMD:editpedagang(playerid, params[])
{
    static
        pid,
        type[24],
        string[128];

    if(pData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    if(sscanf(params, "ds[24]S()[128]", pid, type, string))
    {
        Usage(playerid, "/editlocker [id] [name]");
        SendClientMessage(playerid, COLOR_YELLOW, "[NAMES]:{FFFFFF} location, type, delete");
        return 1;
    }
    if((pid < 0 || pid >= MAX_PEDAGANG))
        return Error(playerid, "You have specified an invapid ID.");
    if(!Iter_Contains(Pedagang, pid)) return Error(playerid, "The doors you specified ID of doesn't exist.");

    if(!strcmp(type, "location", true))
    {
        GetPlayerPos(playerid, pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ]);
        pdgDATA[pid][pdgInt] = GetPlayerInterior(playerid);
        Locker_Save(pid);
        Pedagang_Refresh(pid);

        SendAdminMessage(COLOR_RED, "%s has adjusted the location of locker ID: %d.", pData[playerid][pAdminname], pid);
    }
    else if(!strcmp(type, "type", true))
    {
        new tipe;

        if(sscanf(string, "d", tipe))
            return Usage(playerid, "/editlocker [id] [type] [type, 1.SAPEDAGANG]");

        if(tipe < 1 || tipe > 1)
            return Error(playerid, "You must specify at least 1 - 5.");

        pdgDATA[pid][pdgType] = tipe;
        Locker_Save(pid);
        Pedagang_Refresh(pid);

        SendAdminMessage(COLOR_RED, "%s has set locker ID: %d to type id faction %d.", pData[playerid][pAdminname], pid, tipe);
    }
    else if(!strcmp(type, "delete", true))
    {
        new query[128];
        DestroyDynamic3DTextLabel(pdgDATA[pid][pdgLabel]);
        DestroyDynamicPickup(pdgDATA[pid][pdgPickup]);
        DestroyDynamicArea(pdgDATA[pid][pdgAmbilarea]);
        pdgDATA[pid][pdgPosX] = 0;
        pdgDATA[pid][pdgPosY] = 0;
        pdgDATA[pid][pdgPosZ] = 0;
        pdgDATA[pid][pdgInt] = 0;
        pdgDATA[pid][pdgLabel] = Text3D: INVALID_3DTEXT_ID;
        pdgDATA[pid][pdgPickup] = -1;
        pdgDATA[pid][pdgAmbilarea] = STREAMER_TAG_AREA: INVALID_STREAMER_ID;
        Iter_Remove(Pedagang, pid);
        mysql_format(g_SQL, query, sizeof(query), "DELETE FROM pedagang WHERE id=%d", pid);
        mysql_tquery(g_SQL, query);
        SendAdminMessage(COLOR_RED, "%s has delete locker ID: %d.", pData[playerid][pAdminname], pid);
    }
    return 1;
}