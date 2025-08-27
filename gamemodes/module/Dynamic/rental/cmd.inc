CMD:gotorent(playerid, params[])
{
	static
        rnid,
        type[24];

	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
		
    if(sscanf(params, "ds[24]S()[128]", rnid, type))
    {
        Usage(playerid, "/gotorental [id] [name]");
        Names(playerid, "pickup, spawnveh");
        return 1;
    }
	if(!Iter_Contains(Rental, rnid))
		return Error(playerid, "The Rental you specified ID of doesn't exist.");

	if(!strcmp(type, "pickup", true))
	{
		SetPlayerPosition(playerid, rnData[rnid][rExtposX], rnData[rnid][rExtposY], rnData[rnid][rExtposZ], rnData[rnid][rExtposA]);
	    SetPlayerInterior(playerid, 0);
	    SetPlayerVirtualWorld(playerid, 0);
		SendClientMessageEx(playerid, COLOR_WHITE, "You has teleport to rental pickup id %d", rnid);
		pData[playerid][pInDoor] = -1;
		pData[playerid][pInHouse] = -1;
	}
	else if(!strcmp(type, "spawnveh", true))
	{
		SetPlayerPosition(playerid, rnData[rnid][rVehposX], rnData[rnid][rVehposY], rnData[rnid][rVehposZ], rnData[rnid][rVehposA]);
	    SetPlayerInterior(playerid, 0);
	    SetPlayerVirtualWorld(playerid, 0);
		SendClientMessageEx(playerid, COLOR_WHITE, "You has teleport to rental spawn vehice point id %d", rnid);
		pData[playerid][pInDoor] = -1;
		pData[playerid][pInHouse] = -1;
	}
	return 1;
}

CMD:editrent(playerid, params[])
{
    static
        rnid,
        type[24],
        string[128];

    if(pData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    if(sscanf(params, "ds[24]S()[128]", rnid, type, string))
    {
        Usage(playerid, "/editrental [id] [name]");
        Names(playerid, "location, spawnpoint, type, price, delete");
        return 1;
    }
    if((rnid < 0 || rnid >= MAX_RENTAL))
        return Error(playerid, "You have specified an invalid ID.");

	if(!Iter_Contains(Rental, rnid)) 
		return Error(playerid, "The rental you specified ID of doesn't exist.");

	if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, rnData[rnid][rExtposX], rnData[rnid][rExtposY], rnData[rnid][rExtposZ]);
		GetPlayerFacingAngle(playerid, rnData[rnid][rExtposA]);
        Rental_Save(rnid);
		Rental_Refresh(rnid);

        SendAdminMessage(COLOR_RED, "%s has adjusted the location of rental ID: %d.", pData[playerid][pAdminname], rnid);
    }
    else if(!strcmp(type, "spawnpoint", true))
    {
		GetPlayerPos(playerid, rnData[rnid][rVehposX], rnData[rnid][rVehposY], rnData[rnid][rVehposZ]);
		GetPlayerFacingAngle(playerid, rnData[rnid][rVehposA]);
        Rental_Save(rnid);
		Rental_Refresh(rnid);

        SendAdminMessage(COLOR_RED, "%s has adjusted the spawn vehicle point of rental ID: %d.", pData[playerid][pAdminname], rnid);
    }
    else if(!strcmp(type, "type", true))
    {
        new types;

        if(sscanf(string, "d", types))
            return Usage(playerid, "/editrental [id] [Type] [1.Rental Bikes 2.Rental Boat]");

        if(0 < types || types > 2)
        	return Error(playerid, "Rental type only 1-2");

        rnData[rnid][rType] = types;
        Rental_Save(rnid);
		Rental_Refresh(rnid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the type of rental ID: %d to %d.", pData[playerid][pAdminname], rnid, types);
    }
    else if(!strcmp(type, "price", true))
    {
        new ammount;

        if(sscanf(string, "d", ammount))
            return Usage(playerid, "/editrental [id] [price] [ammount]");

        if(ammount < 0)
        	return Error(playerid, "Rental price tidak boleh dibawah $0");

        rnData[rnid][rPrice] = ammount;
        Rental_Save(rnid);
		Rental_Refresh(rnid);
        SendAdminMessage(COLOR_RED, "%s has adjusted the price of rental ID: %d to %s.", pData[playerid][pAdminname], rnid, FormatMoney(ammount));
    }
	else if(!strcmp(type, "delete", true))
    {
		DestroyDynamic3DTextLabel(rnData[rnid][rLabel]);
        DestroyDynamicPickup(rnData[rnid][rPickup]);
		rnData[rnid][rType] = 0;
		rnData[rnid][rPrice] = 0;
		rnData[rnid][rExtposX] = 0;
		rnData[rnid][rExtposY] = 0;
		rnData[rnid][rExtposZ] = 0;
		rnData[rnid][rExtposA] = 0;
		rnData[rnid][rVehposX] = 0;
		rnData[rnid][rVehposY] = 0;
		rnData[rnid][rVehposZ] = 0;
		rnData[rnid][rVehposA] = 0;
		rnData[rnid][rLabel] = Text3D: INVALID_3DTEXT_ID;
		rnData[rnid][rPickup] = -1;
		
		Iter_Remove(Rental, rnid);

		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM rental WHERE id=%d", rnid);
		mysql_tquery(g_SQL, query);
        SendAdminMessage(COLOR_RED, "%s has delete rental ID: %d.", pData[playerid][pAdminname], rnid);
	}
    return 1;
}

CMD:rentveh(playerid, params[])
{
	foreach(new rnid : Rental)
	{
		if(IsPlayerInRangeOfPoint(playerid, 5.0, rnData[rnid][rExtposX], rnData[rnid][rExtposY], rnData[rnid][rExtposZ]))
		{
			pData[playerid][pGetRENID] = rnid;
			Rental_BuyMenu(playerid, rnid);
		}
	}
	return 1;
}