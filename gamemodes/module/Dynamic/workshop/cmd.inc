CMD:createws(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
	
	new query[512];
	new wid = Iter_Free(Workshop);

	if(wid == -1) return Error(playerid, "You cant create more door!");
	new price;

	if(sscanf(params, "d", price)) return Usage(playerid, "/createws [price]");

	format(wData[wid][wLeader], 128, "-");
	format(wData[wid][wName], 128, "No Name");

	wData[wid][wPrice] = price;
	GetPlayerPos(playerid, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]);

	GetPlayerFacingAngle(playerid, wData[wid][wExtposA]);

	wData[wid][wMoney] = 0;
	wData[wid][wStatus] = 1;
	wData[wid][wComponent] = 0;
  	
  	Workshop_Refresh(wid);

	Iter_Add(Workshop, wid);
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO workshop SET ID='%d', leader='%s', name='%s', price='%d'", wid, wData[wid][wLeader], wData[wid][wName], wData[wid][wPrice]);
	mysql_tquery(g_SQL, query, "OnWorkshopCreated", "i", wid);
	return 1;
}

function OnWorkshopCreated(wid)
{
	Workshop_Save(wid);
	return 1;
}

CMD:wsdelete(playerid, params[])
{
 	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);

    new wid, query[128];
	if(sscanf(params, "i", wid)) return Usage(playerid, "/wsdelete [wid]");
	if(!Iter_Contains(Workshop, wid)) return Error(playerid, "The you specified ID of doesn't exist.");
	
    format(wData[wid][wName], 50, "None");
	format(wData[wid][wLeader], 50, "None");

	wData[wid][wExtposX] = 0;
	wData[wid][wExtposY] = 0;
	wData[wid][wExtposZ] = 0;
	wData[wid][wExtposA] = 0;

	wData[wid][wComponent] = 0;
	wData[wid][wMoney] = 0;
	
	DestroyDynamic3DTextLabel(wData[wid][wLabel]);
	DestroyDynamicPickup(wData[wid][wPickup]);
	DestroyDynamicMapIcon(wData[wid][wIcon]);
	
	Iter_Remove(Workshop, wid);
	
	mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET workshop=-1,workshoprank=0,duty=0 WHERE workshop=%d", wid);
	mysql_tquery(g_SQL, query);
	
	foreach(new ii : Player)
	{
 		if(pData[ii][pWorkshop] == wid)
   		{
			pData[ii][pWorkshop]= -1;
			pData[ii][pWorkshopRank] = 0;
		}
	}

	mysql_format(g_SQL, query, sizeof(query), "DELETE FROM workshop WHERE ID=%d", wid);
	mysql_tquery(g_SQL, query);
    SendStaffMessage(COLOR_RED, "Admin %s telah menghapus Workshop ID: %d.", pData[playerid][pAdminname], wid);
	return 1;
}

CMD:gotows(playerid, params[])
{
	new wid;
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
		
	if(sscanf(params, "d", wid))
		return Usage(playerid, "/gotows [id]");
	if(!Iter_Contains(Workshop, wid)) return Error(playerid, "The Workshop you specified ID of doesn't exist.");
	SetPlayerPosition(playerid, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ], wData[wid][wExtposA]);
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
	SendClientMessageEx(playerid, COLOR_WHITE, "You has teleport to workshop id %d", wid);
	pData[playerid][pInDoor] = -1;
	pData[playerid][pInHouse] = -1;
	return 1;
}

CMD:wsedit(playerid, params[])
{
    static
        wid,
        type[24],
        string[128],
		otherid;

    if(pData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    if(sscanf(params, "ds[24]S()[128]", wid, type, string))
    {
        Usage(playerid, "/wsedit [id] [name]");
        Names(playerid, "location, name, leader, position, money, component");
        return 1;
    }

    if((wid < 0 || wid >= MAX_WORKSHOP))
        return Error(playerid, "You have specified an invalid ID.");

	if(!Iter_Contains(Workshop, wid)) 
		return Error(playerid, "The you specified ID of doesn't exist.");

    if(!strcmp(type, "name", true))
    {
        new name[50];

        if(sscanf(string, "s[50]", name))
            return Usage(playerid, "/wsedit [id] [name] [Workshop Name]");

        format(wData[wid][wName], 50, name);
		Workshop_Save(wid);
		Workshop_Refresh(wid);

        SendStaffMessage(COLOR_LRED, "Admin %s has changed the Workshop name ID: %d to: %s.", pData[playerid][pAdminname], wid, name);
    }
    else if(!strcmp(type, "leader", true))
    {
        if(sscanf(string, "d", otherid))
            return Usage(playerid, "/wsedit [id] [leader] [playerid]");
		
		if(otherid == INVALID_PLAYER_ID)
			return Error(playerid, "invalid player wid");

        format(wData[wid][wLeader], 50, pData[otherid][pName]);
        pData[otherid][pWorkshop] = wid;
        pData[otherid][pWorkshopRank] = 6;
		Workshop_Save(wid);
		Workshop_Refresh(wid);

        SendStaffMessage(COLOR_LRED, "Admin %s has changed the Workshop leader ID: %d to: %s.", pData[playerid][pAdminname], wid, pData[otherid][pName]);
    }
    else if(!strcmp(type, "location", true))
    {
    	GetPlayerFacingAngle(playerid, wData[wid][wExtposA]);
        GetPlayerPos(playerid, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]);
        Workshop_Save(wid);
		Workshop_Refresh(wid);
		
		SendStaffMessage(COLOR_LRED, "Admin %s has changed the Workshop safepos ID: %d.", pData[playerid][pAdminname], wid);
    }
    else if(!strcmp(type, "money", true))
    {
        new money;

        if(sscanf(string, "d", money))
            return Usage(playerid, "/wsedit [id] [money] [ammount]");

        wData[wid][wMoney] = money;
		
        Workshop_Save(wid);
		Workshop_Refresh(wid);
		
		SendStaffMessage(COLOR_LRED, "Admin %s has changed the Workshop money ID: %d to %s.", pData[playerid][pAdminname], wid, FormatMoney(money));   
	}
	else if(!strcmp(type, "component", true))
    {
        new component;

        if(sscanf(string, "d", component))
            return Usage(playerid, "/wsedit [id] [component] [ammount]");

        wData[wid][wComponent] = component;
		
        Workshop_Save(wid);
		Workshop_Refresh(wid);
		
		SendStaffMessage(COLOR_LRED, "Admin %s has changed the Workshop component ID: %d to %d.", pData[playerid][pAdminname], wid, component);   
	}
    return 1;
}

CMD:wshelp(playerid)
{
	if(pData[playerid][pWorkshop] == -1)
		return Error(playerid, "Kamu bukan anggota workshop");

	new str[3500];
	strcat(str, "Commands\tInformation\n");
	strcat(str, "/wsstorage\tUntuk membuka menu/locker list pada workshop\n"); 
	strcat(str, "/wsinvite\tUntuk menginvite seseorang menjadi anggota workshop\n");
	strcat(str, "/wskick\tUntuk mengeluarkan seseorang dari anggota workshop\n");
	strcat(str, "/wssetrank\tUntuk mengatur rank anggota workshop\n");
	strcat(str, "/wservice\tUntuk membuka menu modif kendaraan\n");
	strcat(str, "/lockws\tUntuk merubah status Open/Closed pada worskhop");
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Workshop Commands", str, "Close","");
	return true;
}

CMD:wsstorage(playerid, const params[])
{
	if(pData[playerid][pWorkshop] == -1)
		return Error(playerid, "Kamu bukan anggota workshop!");

	new wsid = pData[playerid][pWorkshop];

	if(IsPlayerInRangeOfPoint(playerid, 2.5, wData[wsid][wExtposX], wData[wsid][wExtposY], wData[wsid][wExtposZ]))
	{
		new string[254];
		format(string, sizeof(string), "Workshop Info\nToggle Duty\nMoney Storage ({00FF00}$%d)\nComponent Storage(%d)\nCreate Repairkit", wData[wsid][wMoney], wData[wsid][wComponent]);
		ShowPlayerDialog(playerid, WORKSHOP_MENU, DIALOG_STYLE_LIST, "Workshop Menu", string,"Next","Close");
	}
	else return Error(playerid, "Kamu bukan anggota workshop ini!");
	return 1;
}

CMD:setplate(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return Error(playerid, "Kamu bukan anggota workshop!");

	new vehid, platename[5];	
	if(sscanf(params, "us[1028]", vehid, platename))
	{
		Usage(playerid, "/setplate <Vehicle ID> <Plate>");
		return true;
	}

	if(vehid == INVALID_VEHICLE_ID) return Error(playerid, "Invalid id");
	if(!IsValidVehicle(vehid)) return Error(playerid, "Invalid veh id");

	foreach(new ii : PVehicles)
	{
		if(IsValidVehicle(pvData[ii][cVeh]))
		{
			format(pvData[ii][cPlate], 32, platename);
			SetVehicleNumberPlate(pvData[ii][cVeh], pvData[ii][cPlate]);
			Info(playerid, "Plat number kendaraan tersebut, berhasil di ganti menjadi %s", pvData[ii][cPlate]);
		}
	}
	return 1;
}

CMD:lockws(playerid, const params[])
{
	if(pData[playerid][pWorkshopRank] < 5)
		return Error(playerid, "Hanya rank 5 dan 6 yang bisa menutup workshop");

	foreach(new wid : Workshop)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.5, wData[wid][wExtposX], wData[wid][wExtposY], wData[wid][wExtposZ]))
		{
			if(!Player_OwnsWorkshop(playerid, wid)) return Error(playerid, "You don't own this workshop.");
			if(!wData[wid][wStatus])
			{
				wData[wid][wStatus] = 1;
				Workshop_Save(wid);
				Workshop_Refresh(wid);

				InfoTD_MSG(playerid, 4000, "You have ~r~closed~w~ your workshop!");
				PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
			}
			else
			{
				wData[wid][wStatus] = 0;
				Workshop_Save(wid);
				Workshop_Refresh(wid);

				InfoTD_MSG(playerid, 4000, "You have ~g~opened~w~ your workshop!");
				PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
			}
		}
	}
	return 1;
}

CMD:wsinvite(playerid, params[])
{
	if(pData[playerid][pWorkshop] == -1)
		return Error(playerid, "Kamu tidak bergabung workshop manapun");
		
	if(pData[playerid][pWorkshopRank] < 5)
		return Error(playerid, "You must workshop rank 5 - 6!");
	
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/wsinvite [playerid/PartOwName]");
		
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "Invalid ID.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");
		
	if(!NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "You must be near this player.");
	
	if(pData[otherid][pWorkshop] != -1)
		return Error(playerid, "Player tersebut sudah bergabung workshop lain!");
		
	if(pData[otherid][pFaction] != 0)
		return Error(playerid, "Kamu tidak bisa menginvite anggota faction");

	pData[otherid][pWsInvite] = pData[playerid][pWorkshop];
	pData[otherid][pWsOffer] = playerid;
	Servers(playerid, "Anda telah menginvite %s untuk menjadi anggota workshop.", pData[otherid][pName]);
	Servers(otherid, "%s telah menginvite anda untuk menjadi anggota workshop. Type: /accept workshop", pData[playerid][pName]);
	return 1;
}

CMD:wskick(playerid, params[])
{
	if(pData[playerid][pWorkshop] == -1)
		return Error(playerid, "You are not in Workshop!");
		
	if(pData[playerid][pWorkshopRank] < 5)
		return Error(playerid, "You must Workshop level 5 - 6!");
	
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/wskick [playerid/PartOwName]");
		
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "Invalid ID.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");
	
	if(pData[otherid][pWorkshopRank] > pData[playerid][pWorkshopRank])
		return Error(playerid, "You cant kick him.");
		
	pData[otherid][pWorkshopRank] = 0;
	pData[otherid][pWorkshop] = -1;
	Servers(playerid, "Anda telah mengeluarkan %s dari anggota Workshop.", pData[otherid][pName]);
	Servers(otherid, "%s telah mengeluarkan anda dari anggota Workshop.", pData[playerid][pName]);
	return 1;
}

CMD:wssetrank(playerid, params[])
{
	new rank, otherid;
	if(pData[playerid][pWorkshopRank] < 6)
		return Error(playerid, "You must Workshop leader!");
		
	if(sscanf(params, "ud", otherid, rank))
        return Usage(playerid, "/wssetrank [playerid/PartOwName] [rank 1-6]");
	
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "Invalid ID.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");
	
	if(pData[otherid][pWorkshop] != pData[playerid][pWorkshop])
		return Error(playerid, "This player is not in your Workshop!");
	
	if(rank < 1 || rank > 6)
		return Error(playerid, "rank must 1 - 6 only");
	
	pData[otherid][pWorkshopRank] = rank;
	Servers(playerid, "You has set %s Workshop rank to level %d", pData[otherid][pName], rank);
	Servers(otherid, "%s has set your Workshop rank to level %d", pData[playerid][pName], rank);
	return 1;
}

CMD:wsann(playerid, params[])
{
	if(pData[playerid][pWorkshop] == -1)
		return ErrorMsg(playerid, "Anda bukan pekerja workshop");

	new lstr[1024];
	format(lstr, sizeof(lstr), "{8D6D48}[BENGKEL] %s {FFFFFF}: %s", pData[playerid][pName], params);
	va_SendClientMessageToAll(-1, lstr);
	return 1;
}

CMD:wservice(playerid, params[])
{
	if(pData[playerid][pWorkshop] == -1)
		return Error(playerid, "Kamu bukan pekerja workshop");
	{
		if(pData[playerid][pOnDuty] == 0)
			return Error(playerid, "Kamu harus on duty");
		{
			if(pData[playerid][pMechVeh] == INVALID_VEHICLE_ID)
			{
				new vehicleid = GetNearestVehicleToPlayer(playerid, 3.5, false);
				
				if(vehicleid == INVALID_VEHICLE_ID) return Error(playerid, "You not in near any vehicles.");
				if(pData[playerid][pActivityTime] > 5) return Error(playerid, "You already checking vehicle!");
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				Info(playerid, "Don't move from your position or you will failed to checking this vehicle!");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				ShowProgressbar(playerid, "Examining", 10);
				pData[playerid][pMechanic] = SetTimerEx("CheckCar", 10000, false, "dd", playerid, vehicleid);
				return 1;
			}
			
			if(GetNearestVehicleToPlayer(playerid, 3.5, false) == pData[playerid][pMechVeh])
			{
				new Dstring[800], Float:health, engine;
				new panels, doors, light, tires, body;
        		GetVehicleHealth(pData[playerid][pMechVeh], health);
				if(health > 100.0) health = 100.0;
				if(health > 0.0) health *= -1;
				engine = floatround(health, floatround_round) / 10 + 100;
				
				GetVehicleDamageStatus(pData[playerid][pMechVeh], panels, doors, light, tires);
			    new cpanels = panels / 1000000;
			    new lights = light / 2;
			    new pintu;
			    if(doors != 0) pintu = 5;
			    if(doors == 0) pintu = 0;
			    body = cpanels + lights + pintu + 20;
				format(Dstring, sizeof(Dstring), "Service Name\tComponent\n");
				format(Dstring, sizeof(Dstring), "%sEngine Fix\t%d\n", Dstring, engine);
				format(Dstring, sizeof(Dstring), "%sBody Fix\t%d\n", Dstring, body);
				format(Dstring, sizeof(Dstring), "%sEngine Upgrade\t300\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sSpray Car\t12\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sPaint Job Car\t30\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sWheels Car\t25\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sSpoiler Car\t21\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sHood Car\t21\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sVents Car\t21\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sLights Car\t21\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sExhausts\t24\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sFront bumpers\t30\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sRear Bumpers\t30\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sRoofs Car\t21\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sSide skirts\t27\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sBullbars\t15\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sStereo\t45\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sHydraulics\t45\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sNitro 1\t75\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sNitro 2\t112\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sNitro 3\t150\n", Dstring);
				format(Dstring, sizeof(Dstring), "%sNeon\t135", Dstring);
				ShowPlayerDialog(playerid, WORKSHOP_SERVICE, DIALOG_STYLE_TABLIST_HEADERS, "Workshop Service", Dstring, "Service", "Cancel");
			}
			else
			{
				KillTimer(pData[playerid][pMechanic]);
				
				
				pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
				pData[playerid][pActivityTime] = 0;
				Info(playerid, "Kendaraan pelanggan anda yang sebelumnya sudah terlalu jauh.");
				return 1;
			}
		}
	}
	return 1;
}