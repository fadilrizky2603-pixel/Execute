Pfarm_Save(id)
{
	new cQuery[2024];
	format(cQuery, sizeof(cQuery), "UPDATE privatefarm SET owner='%s', price='%d', posx='%f', posy='%f', posz='%f', posa='%f', interior='%d', world='%d', seeds='%d', potato='%d', orange='%d', wheat='%d', visit='%d' WHERE id='%d'",
	pfData[id][pfOwner],
	pfData[id][pfPrice],
	pfData[id][pfX],
	pfData[id][pfY],
	pfData[id][pfZ],
	pfData[id][pfA],
	pfData[id][pfInt],
	pfData[id][pfVW],
	pfData[id][pfSeeds],
	pfData[id][pfPotato],
	pfData[id][pfOrange],
	pfData[id][pfWheat],
	pfData[id][pfVisit],
	id);

	return mysql_tquery(g_SQL, cQuery);
}

Pfarm_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamicPickup(pfData[id][pfPickup]))
			DestroyDynamicPickup(pfData[id][pfPickup]);

		if(IsValidDynamic3DTextLabel(pfData[id][pfLabel]))
			DestroyDynamic3DTextLabel(pfData[id][pfLabel]);

		static string[1024];

		if(strcmp(pfData[id][pfOwner], "-"))
		{
			format(string, sizeof(string), "[PRIVATE FARM ID: %d]\n"WHITE_E"Location: "YELLOW_E"%s\n"WHITE_E"Owned by %s\n"WHITE_E"/pfmenu - to open storage", id, GetLocation(pfData[id][pfX], pfData[id][pfY], pfData[id][pfZ]), pfData[id][pfOwner]);
			pfData[id][pfPickup] = CreateDynamicPickup(1239, 23, pfData[id][pfX], pfData[id][pfY], pfData[id][pfZ], pfData[id][pfVW], pfData[id][pfInt], _, 5.0 );
			pfData[id][pfLabel] =  CreateDynamic3DTextLabel(string, COLOR_GREEN, pfData[id][pfX], pfData[id][pfY], pfData[id][pfZ]+0.5, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, pfData[id][pfVW], pfData[id][pfInt]);
		}
		else
		{
			format(string, sizeof(string), "[PRIVATE FARM ID: %d]\n"GREEN_LIGHT"This private farm for sell\n"WHITE_E"Location: "YELLOW_E"%s\n"WHITE_E"Price: "YELLOW_E"%s\n"WHITE_E"/buy - for buy this private farm", id, GetLocation(pfData[id][pfX], pfData[id][pfY], pfData[id][pfZ]), FormatMoney(pfData[id][pfPrice]));
			pfData[id][pfPickup] = CreateDynamicPickup(1239, 23, pfData[id][pfX], pfData[id][pfY], pfData[id][pfZ], pfData[id][pfVW], pfData[id][pfInt], _, 5.0 );
			pfData[id][pfLabel] =  CreateDynamic3DTextLabel(string, COLOR_GREEN, pfData[id][pfX], pfData[id][pfY], pfData[id][pfZ]+0.5, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, pfData[id][pfVW], pfData[id][pfInt]);
		}
	}
	return 1;
}

Player_OwnsPfarm(playerid, id)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(id == -1) return 0;
	if(!strcmp(pfData[id][pfOwner], pData[playerid][pName], true)) return 1;
	return 0;
}

Player_PfarmCount(playerid)
{
	#if LIMIT_PER_PLAYER != 0
    new count;
	foreach(new i : PFarm)
	{
		if(Player_OwnsPfarm(playerid, i)) count++;
	}

	return count;
	#else
	return 0;
	#endif
}

Pfarm_Reset(id)
{
	format(pfData[id][pfOwner], MAX_PLAYER_NAME, "-");
	pfData[id][pfSeeds] = 0;
	pfData[id][pfPotato] = 0;
	pfData[id][pfOrange] = 0;
	pfData[id][pfWheat] = 0;
	pfData[id][pfVisit] = 0;
	Pfarm_Refresh(id);
}

GetOwnedPfarm(playerid)
{
	new tmpcount;
	foreach(new pfid : PFarm)
	{
	    if(!strcmp(pfData[pfid][pfOwner], pData[playerid][pName], true))
	    {
     		tmpcount++;
		}
	}
	return tmpcount;
}

ReturnPlayerPfarmID(playerid, hslot)
{
	new tmpcount;
	if(hslot < 1 && hslot > LIMIT_PER_PLAYER) return -1;
	foreach(new pfid : PFarm)
	{
	    if(!strcmp(pData[playerid][pName], pfData[pfid][pfOwner], true))
	    {
     		tmpcount++;
       		if(tmpcount == hslot)
       		{
        		return pfid;
  			}
	    }
	}
	return -1;
}
