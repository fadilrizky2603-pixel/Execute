Doors_Save(id)
{
	new dquery[2048];
	mysql_format(g_SQL, dquery, sizeof(dquery), "UPDATE doors SET name='%s', password='%s', icon='%d', locked='%d', admin='%d', vip='%d', faction='%d', family='%d', garage='%d', custom='%d', extvw='%d', extint='%d', extposx='%f', extposy='%f', extposz='%f', extposa='%f', intvw='%d', intint='%d', intposx='%f', intposy='%f', intposz='%f', intposa='%f' WHERE ID='%d'",
	dData[id][dName], dData[id][dPass], dData[id][dIcon], dData[id][dLocked], dData[id][dAdmin], dData[id][dVip], dData[id][dFaction], dData[id][dFamily], dData[id][dGarage], dData[id][dCustom], dData[id][dExtvw], dData[id][dExtint], dData[id][dExtposX], dData[id][dExtposY], dData[id][dExtposZ], dData[id][dExtposA], dData[id][dIntvw], dData[id][dIntint],
	dData[id][dIntposX], dData[id][dIntposY], dData[id][dIntposZ], dData[id][dIntposA], id);
	mysql_tquery(g_SQL, dquery);
	return 1;
}

Doors_Updatelabel(id)
{
	if(id != -1)
	{
		if(IsValidDynamic3DTextLabel(dData[id][dLabelext]))
            DestroyDynamic3DTextLabel(dData[id][dLabelext]);

        if(IsValidDynamicPickup(dData[id][dPickupext]))
            DestroyDynamicPickup(dData[id][dPickupext]);

        if(IsValidDynamic3DTextLabel(dData[id][dLabelint]))
            DestroyDynamic3DTextLabel(dData[id][dLabelint]);

        if(IsValidDynamicPickup(dData[id][dPickupint]))
            DestroyDynamicPickup(dData[id][dPickupint]);
		
		if(dData[id][dGarage] == 1)
		{
			new mstr[512];
			format(mstr,sizeof(mstr),"[ID: %d]\n{FFFFFF}%s\n{FFFFFF}Press {FF0000}ALT {FFFFFF}to enter", id, dData[id][dName]);
			dData[id][dPickupext] = CreateDynamicPickup(19130, 23, dData[id][dExtposX], dData[id][dExtposY], dData[id][dExtposZ], dData[id][dExtvw], dData[id][dExtint]);
			dData[id][dLabelext] = CreateDynamic3DTextLabel(mstr, COLOR_YELLOW, dData[id][dExtposX], dData[id][dExtposY], dData[id][dExtposZ]+0.35, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, dData[id][dExtvw], dData[id][dExtint]);
		}
		else
		{
			new mstr[512];
			format(mstr, sizeof(mstr), "ID: %d\n%s\n{FFFF00}[ENTER] {FFFFFF}untuk masuk", id, dData[id][dName]);
			dData[id][dPickupext] = CreateDynamicPickup(19606, 23, dData[id][dExtposX], dData[id][dExtposY], dData[id][dExtposZ], dData[id][dExtvw], dData[id][dExtint]);
			dData[id][dLabelext] = CreateDynamic3DTextLabel(mstr, -1, dData[id][dExtposX], dData[id][dExtposY], dData[id][dExtposZ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, dData[id][dExtvw], dData[id][dExtint]);
		}
		
        if(dData[id][dIntposX] != 0.0 && dData[id][dIntposY] != 0.0 && dData[id][dIntposZ] != 0.0)
        {
			if(dData[id][dGarage] == 1)
			{
				new mstr[512];
				format(mstr,sizeof(mstr),"[ID: %d]\n{FFFFFF}%s\n{FFFFFF}Press {FF0000}ALT {FFFFFF}to exit", id, dData[id][dName]);

				dData[id][dLabelint] = CreateDynamic3DTextLabel(mstr, COLOR_YELLOW, dData[id][dIntposX], dData[id][dIntposY], dData[id][dIntposZ]+0.7, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, dData[id][dIntvw], dData[id][dIntint]);
				dData[id][dPickupint] = CreateDynamicPickup(19130, 23, dData[id][dIntposX], dData[id][dIntposY], dData[id][dIntposZ], dData[id][dIntvw], dData[id][dIntint], -1, 7);
			}
			else
			{
				new mstr[512];
				format(mstr, sizeof(mstr), "ID: %d\n%s\n{FFFF00}[ENTER] {FFFFFF}untuk keluar", id, dData[id][dName]);
				dData[id][dLabelint] = CreateDynamic3DTextLabel(mstr, -1, dData[id][dIntposX], dData[id][dIntposY], dData[id][dIntposZ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, dData[id][dIntvw], dData[id][dIntint]);
				dData[id][dPickupint] = CreateDynamicPickup(19605, 23, dData[id][dIntposX], dData[id][dIntposY], dData[id][dIntposZ], dData[id][dIntvw], dData[id][dIntint], -1, 7);
			}
		}
	}
}