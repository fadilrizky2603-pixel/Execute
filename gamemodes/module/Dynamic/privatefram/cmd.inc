CMD:createpfarm(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);

	new query[512];
	new pfid = Iter_Free(PFarm);
	if(pfid == -1)
		return Error(playerid, "You cant create more private farm!");

	new price;
	if(sscanf(params, "d", price))
	{
		Usage(playerid, "/createpfarm [price]");
		return 1;
	}

	format(pfData[pfid][pfOwner], 128, "-");
	pfData[pfid][pfPrice] = price;
	GetPlayerPos(playerid, pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]);
	GetPlayerFacingAngle(playerid, pfData[pfid][pfA]);
	pfData[pfid][pfInt] = GetPlayerInterior(playerid);
	pfData[pfid][pfVW] = GetPlayerVirtualWorld(playerid);
	pfData[pfid][pfSeeds] = 0;
	pfData[pfid][pfPotato] = 0;
	pfData[pfid][pfOrange] = 0;
	pfData[pfid][pfWheat] = 0;

	Pfarm_Refresh(pfid);
	Iter_Add(PFarm, pfid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO privatefarm SET id='%d', owner='%s', price='%d'", pfid, pfData[pfid][pfOwner], pfData[pfid][pfPrice]);
	mysql_tquery(g_SQL, query, "OnPfarmCreated", "i", pfid);
	return 1;
}

CMD:editpfarm(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);

	static
     pfid,
      type[24],
       string[128];

    if(sscanf(params, "ds[24]S()[128]", pfid, type, string))
    {
        Usage(playerid, "/editpfarm [id] [name]");
        Names(playerid, "location, owner, price, seeds, potato, orange, wheat, reset, delete");
        return 1;
    }

    if(!Iter_Contains(PFarm, pfid)) 
		return Error(playerid, "Invalid ID.");

	if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]);
		GetPlayerFacingAngle(playerid, pfData[pfid][pfA]);
		pfData[pfid][pfInt] = GetPlayerInterior(playerid);
		pfData[pfid][pfVW] = GetPlayerVirtualWorld(playerid);

		Pfarm_Refresh(pfid);
		Pfarm_Save(pfid);
		SendAdminMessage(COLOR_RED, "%s has adjusted the location of private farm ID: %d.", pData[playerid][pAdminname], pfid);
    }
    else if(!strcmp(type, "owner", true))
    {
    	new owners[MAX_PLAYER_NAME];

        if(sscanf(string, "s[32]", owners))
            return Usage(playerid, "/editpfarm [id] [owner] [player name] (use '-' to no owner)");

        format(pfData[pfid][pfOwner], MAX_PLAYER_NAME, owners);
        if(pfData[pfid][pfVisit] == 0)
        {
        	pfData[pfid][pfVisit] = gettime() + (86400 * 30);
        }
        Pfarm_Refresh(pfid);
        Pfarm_Save(pfid);
        SendAdminMessage(COLOR_RED, "%s has adjusted owner of private farm ID: %d to %s.", pData[playerid][pAdminname], pfid, owners);
    }
    else if(!strcmp(type, "price", true))
    {
    	new price;

        if(sscanf(string, "d", price))
            return Usage(playerid, "/editpfarm [id] [price]");

        pfData[pfid][pfPrice] = price;

        Pfarm_Refresh(pfid);
        Pfarm_Save(pfid);
        SendAdminMessage(COLOR_RED, "%s has adjusted price of private farm ID: %d to %s.", pData[playerid][pAdminname], pfid, FormatMoney(price));
    }
    else if(!strcmp(type, "seeds", true))
    {
    	new price;

        if(sscanf(string, "d", price))
            return Usage(playerid, "/editpfarm [id] [seeds]");

        pfData[pfid][pfSeeds] = price;

        Pfarm_Refresh(pfid);
        Pfarm_Save(pfid);
        SendAdminMessage(COLOR_RED, "%s has adjusted seeds of private farm ID: %d to %d.", pData[playerid][pAdminname], pfid, price);
    }
    else if(!strcmp(type, "potato", true))
    {
    	new price;

        if(sscanf(string, "d", price))
            return Usage(playerid, "/editpfarm [id] [potato]");

        pfData[pfid][pfPotato] = price;

        Pfarm_Refresh(pfid);
        Pfarm_Save(pfid);
        SendAdminMessage(COLOR_RED, "%s has adjusted potato of private farm ID: %d to %d.", pData[playerid][pAdminname], pfid, price);
    }
    else if(!strcmp(type, "orange", true))
    {
    	new price;

        if(sscanf(string, "d", price))
            return Usage(playerid, "/editpfarm [id] [orange]");

        pfData[pfid][pfOrange] = price;

        Pfarm_Refresh(pfid);
        Pfarm_Save(pfid);
        SendAdminMessage(COLOR_RED, "%s has adjusted orange of private farm ID: %d to %d.", pData[playerid][pAdminname], pfid, price);
    }
    else if(!strcmp(type, "wheat", true))
    {
    	new price;

        if(sscanf(string, "d", price))
            return Usage(playerid, "/editpfarm [id] [wheat]");

        pfData[pfid][pfWheat] = price;

        Pfarm_Refresh(pfid);
        Pfarm_Save(pfid);
        SendAdminMessage(COLOR_RED, "%s has adjusted wheat of private farm ID: %d to %d.", pData[playerid][pAdminname], pfid, price);
    }
    else if(!strcmp(type, "reset", true))
    {
        Pfarm_Reset(pfid);
        Pfarm_Save(pfid);
        SendAdminMessage(COLOR_RED, "%s has reset private farm ID: %d.", pData[playerid][pAdminname], pfid);
    }
   	else if(!strcmp(type, "delete", true))
    {
		DestroyDynamic3DTextLabel(pfData[pfid][pfLabel]);
        DestroyDynamicPickup(pfData[pfid][pfPickup]);
		
		pfData[pfid][pfPrice] = 0;
		pfData[pfid][pfX] = 0;
		pfData[pfid][pfY] = 0;
		pfData[pfid][pfZ] = 0;
		pfData[pfid][pfA] = 0;
		pfData[pfid][pfInt] = 0;
		pfData[pfid][pfVW] = 0;

		pfData[pfid][pfLabel] = Text3D: INVALID_3DTEXT_ID;
		pfData[pfid][pfPickup] = -1;
		
		Iter_Remove(PFarm, pfid);

		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM privatefarm WHERE id=%d", pfid);
		mysql_tquery(g_SQL, query);
        SendAdminMessage(COLOR_RED, "%s has delete privatefarm ID: %d.", pData[playerid][pAdminname], pfid);
    }
    return 1;
}

CMD:gotopfarm(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return PermissionError(playerid);

	new pfid;
	if(sscanf(params, "d", pfid))
	{
		Usage(playerid, "/gotopfarm [id]");
		return 1;
	}

	if(!Iter_Contains(PFarm, pfid))
		return Error(playerid, "Invalid ID!");

	SetPlayerPos(playerid, pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]+0.5);
	SetPlayerFacingAngle(playerid, pfData[pfid][pfA]);
	SetPlayerInterior(playerid, pfData[pfid][pfInt]);
	SetPlayerVirtualWorld(playerid, pfData[pfid][pfVW]);
	return 1;
}

CMD:pfmenu(playerid, params[])
{
	foreach(new pfid : PFarm)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]))
		{
			pData[playerid][pGetPFARM] = pfid;
			if(!Player_OwnsPfarm(playerid, pData[playerid][pGetPFARM]))
				return Error(playerid, "Kamu bukan pemilik private farmer ini.");

			new str[128], string[1024];
			format(str, sizeof(str), "Farm Menu (ID : %d)", pfid);
			format(string, sizeof(string), "Seeds Storage ("GREEN_LIGHT"%d/1000kg"WHITE_E")\nPotato Storage ("GREEN_LIGHT"%d/500kg"WHITE_E")\nOrange Storage ("GREEN_LIGHT"%d/500kg"WHITE_E")\nWheat Storage ("GREEN_LIGHT"%d/500kg"WHITE_E")", pfData[pfid][pfSeeds], pfData[pfid][pfPotato], pfData[pfid][pfOrange], pfData[pfid][pfWheat]);
		    ShowPlayerDialog(playerid, PFARM_MENU, DIALOG_STYLE_LIST, str, string,"Next","Close");
		}
	}
    return 1;
}

CMD:mypfarm(playerid)
{
	if(GetOwnedPfarm(playerid) == 0) return Error(playerid, "Anda tidak memiliki private farmer.");
	//if(!Player_OwnsBusiness(playerid, id)) return Error(playerid, "You don't own this business.");
	new pfid, _tmpstring[1204], count = GetOwnedPfarm(playerid), CMDSString[1204];
	CMDSString = "";
	Loop(itt, (count + 1), 1)
	{
	    pfid = ReturnPlayerPfarmID(playerid, itt);
		if(itt == count)
		{
		    format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s   {ffffff}(ID: %d)\n", itt, GetLocation(pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]), pfid);
		}
		else format(_tmpstring, sizeof(_tmpstring), ""LB_E"%d.\t{FFFF2A}%s  {ffffff}(ID: %d)\n", itt, GetLocation(pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]), pfid);
		strcat(CMDSString, _tmpstring);
	}
	ShowPlayerDialog(playerid, DIALOG_MY_PFARM, DIALOG_STYLE_LIST, "{FF0000}Local Prime {0000FF}Private Farm", CMDSString, "Select", "Cancel");
	return 1;
}

CMD:pfarm(playerid, params[])
{
	if(isnull(params)) return Usage(playerid, "/pfarm [plant/harvest/destroy]");
	
	if(!strcmp(params, "plant", true))
	{
		if(pData[playerid][pJob] == 7 || pData[playerid][pJob2] == 7)
		{
			foreach(new pfid : PFarm)
			{
				if(IsPlayerInRangeOfPoint(playerid, 80.0, pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]))
				{
					if(Player_OwnsPfarm(playerid, pfid))
					{
						if(GetPlayerInterior(playerid) > 0) return Error(playerid, "You cant plant at here!");
						if(GetPlayerVirtualWorld(playerid) > 0) return Error(playerid, "You cant plant at here!");
							
						if(!Iter_Contains(PFarm, pfid))
							return Error(playerid, "Invalid ID.");
							
						new mstr[512], tstr[64];
						format(tstr, sizeof(tstr), ""WHITE_E" Farm ID: %d", pfid);
						format(mstr, sizeof(mstr), "Plant\tSeed\n\
						"WHITE_E"Potato\t"GREEN_E"5 Seed\n\
						"WHITE_E"Wheat\t"GREEN_E"18 Seed\n\
						"WHITE_E"Orange\t"GREEN_E"11 Seed");
						ShowPlayerDialog(playerid, PFARM_PLANT, DIALOG_STYLE_TABLIST_HEADERS, tstr, mstr, "Plant", "Close");
					}
				}
			}
		}
		else return Error(playerid, "You are not farmer!");
	}
	else if(!strcmp(params, "harvest", true))
	{
		if(pData[playerid][pJob] == 7 || pData[playerid][pJob2] == 7)
		{
			foreach(new pfid : PFarm)
			{
				if(IsPlayerInRangeOfPoint(playerid, 80.0, pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]))
				{
					if(Player_OwnsPfarm(playerid, pfid))
					{
						new id = GetClosestPlant(playerid);
						if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
						if(id == -1) return Error(playerid, "You must closes on the plant!");
						if(PlantData[id][PlantTime] > 1) return Error(playerid, "This plant is not ready!");
						if(PlantData[id][PlantHarvest] == true) return Error(playerid, "This plant already harvesting by someone!");
						if(GetPlayerWeapon(playerid) != WEAPON_KNIFE) return Error(playerid, "You need holding a knife(pisau)!");
						
						pData[playerid][pHarvestID] = id;
						ShowProgressbar(playerid, "Harvesting...", 10);
						pData[playerid][pHarvest] = SetTimerEx("HarvestPlant", 1000, true, "i", playerid);
						SetPlayerArmedWeapon(playerid, WEAPON_KNIFE);
						ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 1);

						PlantData[id][PlantHarvest] = true;
					}
				}
			}
		}
		else return Error(playerid, "You are not farmer!");
	}
	else if(!strcmp(params, "destroy", true))
	{
		if(pData[playerid][pJob] == 7 || pData[playerid][pJob2] == 7)
		{
			foreach(new pfid : PFarm)
			{
				if(IsPlayerInRangeOfPoint(playerid, 80.0, pfData[pfid][pfX], pfData[pfid][pfY], pfData[pfid][pfZ]))
				{
					if(Player_OwnsPfarm(playerid, pfid))
					{
						new id = GetClosestPlant(playerid);
						if(id == -1) return Error(playerid, "You must closes on the plant!");
						if(PlantData[id][PlantHarvest] == true) return Error(playerid, "This plant already harvesting by someone!");
						
						new query[128];
						PlantData[id][PlantType] = 0;
						PlantData[id][PlantTime] = 0;
						PlantData[id][PlantX] = 0.0;
						PlantData[id][PlantY] = 0.0;
						PlantData[id][PlantZ] = 0.0;
						PlantData[id][PlantHarvest] = false;
						KillTimer(PlantData[id][PlantTimer]);
						PlantData[id][PlantTimer] = -1;
						DestroyDynamicObject(PlantData[id][PlantObjID]);
						DestroyDynamicCP(PlantData[id][PlantCP]);
						DestroyDynamic3DTextLabel(PlantData[id][PlantLabel]);
						mysql_format(g_SQL, query, sizeof(query), "DELETE FROM plants WHERE id='%d'", id);
						mysql_tquery(g_SQL, query);
						Iter_Remove(Plants, id);
						ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 1);
						Info(playerid, "You has destroyed this plant!");
					}
				}
			}
		}
		else return Error(playerid, "You cant destroy a plant!");
	}
	return 1;
}

CMD:givepfarm(playerid, params[])
{
	new pfid, otherid;
	if(sscanf(params, "ud", otherid, pfid)) return Usage(playerid, "/givepfarm [playerid/name] [id] | /givepfarm - for show info");
	if(pfid == -1) return Error(playerid, "Invalid id");
	
	if(!IsPlayerConnected(otherid) || !NearPlayer(playerid, otherid, 4.0))
        return Error(playerid, "Player tersebut telah disconnect/tidak berada didekat dirimu.");
	
	if(!Player_OwnsPfarm(playerid, pfid)) return Error(playerid, "Kamu tidak memiliki Private Farmer ini.");
	if(pData[otherid][pVip] == 1)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_PfarmCount(otherid) + 1 > 2) return Error(playerid, "Target Player tidak dapat memiliki Private Farmer lebih.");
		#endif
	}
	else if(pData[otherid][pVip] == 2)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_PfarmCount(otherid) + 1 > 3) return Error(playerid, "Target Player tidak dapat memiliki Private Farmer lebih.");
		#endif
	}
	else if(pData[otherid][pVip] == 3)
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_PfarmCount(otherid) + 1 > 4) return Error(playerid, "Target Player tidak dapat memiliki Private Farmer lebih.");
		#endif
	}
	else
	{
		#if LIMIT_PER_PLAYER > 0
		if(Player_PfarmCount(otherid) + 1 > 1) return Error(playerid, "Target Player tidak dapat memiliki Private Farmer lebih.");
		#endif
	}
	format(pfData[pfid][pfOwner], MAX_PLAYER_NAME, pData[otherid][pName]);
	
	Pfarm_Refresh(pfid);
	Pfarm_Save(pfid);
	Info(playerid, "Anda memberikan Private Farmer id: %d kepada %s", pfid, ReturnName(otherid));
	Info(otherid, "%s memberikan Private Farmer id: %d kepada anda", ReturnName(playerid), pfid);
	return 1;
}