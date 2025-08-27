CMD:sb(playerid, params[])
{
    if(IsPlayerInAnyVehicle(playerid) == 0) 
        return ErrorMsg(playerid, "Anda sedang tidak berada di dalam kendaraan");

    if(IsPlayerInAnyVehicle(playerid) == 1 && pData[playerid][pSeatBelt] == 0)
	{
        if(IsABike(GetPlayerVehicleID(playerid)) && pData[playerid][pHelmetOn] == 0)
		{
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s takes out a helmet and puts it on.", ReturnName(playerid));
            pData[playerid][pHelmetOn] = 1;
			GivePlayerHelmet(playerid);
        }
        else
		{
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s takes out a seatbelt and puts it on.", ReturnName(playerid));
            pData[playerid][pSeatBelt] = 1;
        }
    }
    else if(IsPlayerInAnyVehicle(playerid) == 1 && pData[playerid][pSeatBelt] == 1)
	{
        if(IsABike(GetPlayerVehicleID(playerid)) && pData[playerid][pHelmetOn] == 1)
		{
            pData[playerid][pHelmetOn] = 0;
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s takes their helmet off and puts it away.", ReturnName(playerid));
			RemovePlayerAttachedObject(playerid, 9);
        }
        else
		{
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s takes their seatbelt off and puts it away.", ReturnName(playerid));
            pData[playerid][pSeatBelt] = 0;
        }
    }
    return 1;
}
CMD:seatbelt(playerid, params[])
{
    if(IsPlayerInAnyVehicle(playerid) == 0) return ErrorMsg(playerid, "Anda sedang tidak berada di dalam kendaraan");

    if(IsPlayerInAnyVehicle(playerid) == 1 && pData[playerid][pSeatBelt] == 0)
	{
        if(IsABike(GetPlayerVehicleID(playerid)) && pData[playerid][pHelmetOn] == 0)
		{
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s takes out a helmet and puts it on.", ReturnName(playerid));
            pData[playerid][pHelmetOn] = 1;
			GivePlayerHelmet(playerid);
        }
        else
		{
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s takes out a seatbelt and puts it on.", ReturnName(playerid));
            pData[playerid][pSeatBelt] = 1;
        }
    }
    else if(IsPlayerInAnyVehicle(playerid) == 1 && pData[playerid][pSeatBelt] == 1)
	{
        if(IsABike(GetPlayerVehicleID(playerid)) && pData[playerid][pHelmetOn] == 1)
		{
            pData[playerid][pHelmetOn] = 0;
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s takes their helmet off and puts it away.", ReturnName(playerid));
			RemovePlayerAttachedObject(playerid, 9);
        }
        else
		{
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s takes their seatbelt off and puts it away.", ReturnName(playerid));
            pData[playerid][pSeatBelt] = 0;
        }
    }
    return 1;
}


CMD:helmet(playerid)
{
	if(pData[playerid][pHelmet] <= 0)
		return ErrorMsg(playerid, "Anda tidak memiliki helmet!");
		
	switch(pData[playerid][pHelmetOn])
    {
        case 0:
        {
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s takes out a helmet and puts it on.", ReturnName(playerid));
            pData[playerid][pHelmetOn] = 1;
			GivePlayerHelmet(playerid);
        }
        case 1:
        {
            pData[playerid][pHelmetOn] = 0;
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s takes their helmet off and puts it away.", ReturnName(playerid));
			RemovePlayerAttachedObject(playerid, 9);
        }
    }
	return 1;
}

