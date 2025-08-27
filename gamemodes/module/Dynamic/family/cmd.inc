CMD:createfam(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
		
	new fid = Iter_Free(FAMILYS);
	if(fid == -1) 
		return Error(playerid, "You cant create more family slot empty!");

	new name[50], otherid, query[128];
	if(sscanf(params, "s[50]u", name, otherid)) 
		return Usage(playerid, "/fcreate [name] [playerid]");

	if(otherid == INVALID_PLAYER_ID)
		return Error(playerid, "invalid playerid.");
	
	if(pData[otherid][pFamily] != -1)
		return Error(playerid, "Player tersebut sudah bergabung family");
		
	if(pData[otherid][pFaction] != 0)
		return Error(playerid, "Player tersebut sudah bergabung faction");
		
	pData[otherid][pFamily] = fid;
	pData[otherid][pFamilyRank] = 6;
		
	format(fData[fid][fName], 50, name);
	format(fData[fid][fLeader], 50, pData[otherid][pName]);
	format(fData[fid][fMotd], 50, "None");
	fData[fid][fColor] = 0;
	fData[fid][fExtposX] = 0;
	fData[fid][fExtposY] = 0;
	fData[fid][fExtposZ] = 0;
	fData[fid][fExtposA] = 0;
	
	fData[fid][fIntposX] = 0;
	fData[fid][fIntposY] = 0;
	fData[fid][fIntposZ] = 0;
	fData[fid][fIntposA] = 0;
	fData[fid][fInt] = 0;
	
	fData[fid][fMoney] = 0;
	fData[fid][fMarijuana] = 0;
	fData[fid][fComponent] = 0;
	fData[fid][fMaterial] = 0;
	fData[fid][fSafeposX] = 0;
	fData[fid][fSafeposY] = 0;
	fData[fid][fSafeposZ] = 0;

	Iter_Add(FAMILYS, fid);
	Servers(playerid, "Anda telah berhasil membuat family ID: %d dengan leader: %s", fid, pData[otherid][pName]);
	Servers(otherid, "Admin %s telah menset anda sebagai leader dari family ID: %d", pData[playerid][pAdminname], fid);
	SendStaffMessage(COLOR_RED, "Admin %s telah membuat family ID: %d dengan leader: %s", pData[playerid][pAdminname], fid, pData[otherid][pName]);
	
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO familys SET ID=%d, name='%s', leader='%s'", fid, name, pData[otherid][pName]);
	mysql_tquery(g_SQL, query, "OnFamilyCreated", "i", fid);
	return 1;
}


CMD:fedit(playerid, params[])
{
    static
        fid,
        type[24],
        string[128],
		otherid;

    if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);

    if(sscanf(params, "ds[24]S()[128]", fid, type, string))
    {
        Usage(playerid, "/fedit [id] [name]");
        Names(playerid, "location, interior, name, leader, safe, money, marijuana");
        return 1;
    }
    if((fid < 0 || fid >= MAX_FAMILY))
        return Error(playerid, "You have specified an invalid ID.");
	if(!Iter_Contains(FAMILYS, fid)) return Error(playerid, "The you specified ID of doesn't exist.");

    if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, fData[fid][fExtposX], fData[fid][fExtposY], fData[fid][fExtposZ]);
		GetPlayerFacingAngle(playerid, fData[fid][fExtposA]);

        Family_Save(fid);
		Family_Refresh(fid);

        SendStaffMessage(COLOR_RED, "%s has adjusted the location of entrance ID: %d.", pData[playerid][pAdminname], fid);
    }
    else if(!strcmp(type, "interior", true))
    {
        GetPlayerPos(playerid, fData[fid][fIntposX], fData[fid][fIntposY], fData[fid][fIntposZ]);
		GetPlayerFacingAngle(playerid, fData[fid][fIntposA]);

		fData[fid][fInt] = GetPlayerInterior(playerid);
        Family_Save(fid);
		Family_Refresh(fid);

        SendStaffMessage(COLOR_RED, "%s has adjusted the interior spawn of entrance ID: %d.", pData[playerid][pAdminname], fid);
    }
    else if(!strcmp(type, "name", true))
    {
        new name[50];

        if(sscanf(string, "s[50]", name))
            return Usage(playerid, "/fedit [id] [name] [fname]");

        format(fData[fid][fName], 50, name);
		Family_Save(fid);
		Family_Refresh(fid);

        SendStaffMessage(COLOR_LRED, "Admin %s has changed the family name ID: %d to: %s.", pData[playerid][pAdminname], fid, name);
    }
    else if(!strcmp(type, "leader", true))
    {
        if(sscanf(string, "d", otherid))
            return Usage(playerid, "/fedit [id] [leader] [playerid]");
		
		if(otherid == INVALID_PLAYER_ID)
			return Error(playerid, "invalid player fid");

        format(fData[fid][fLeader], 50, pData[otherid][pName]);
        pData[otherid][pFamily] = fid;
        pData[otherid][pFamilyRank] = 6;
		Family_Save(fid);
		Family_Refresh(fid);

        SendStaffMessage(COLOR_LRED, "Admin %s has changed the family leader ID: %d to: %s.", pData[playerid][pAdminname], fid, pData[otherid][pName]);
    }
    else if(!strcmp(type, "safe", true))
    {
        GetPlayerPos(playerid, fData[fid][fSafeposX], fData[fid][fSafeposY], fData[fid][fSafeposZ]);

        Family_Save(fid);
		Family_Refresh(fid);
		
		SendStaffMessage(COLOR_LRED, "Admin %s has changed the family safepos ID: %d.", pData[playerid][pAdminname], fid);
    }
    else if(!strcmp(type, "money", true))
    {
        new money;

        if(sscanf(string, "d", money))
            return Usage(playerid, "/fedit [id] [money] [ammount]");

        fData[fid][fMoney] = money;
		
        Family_Save(fid);
		Family_Refresh(fid);
		
		SendStaffMessage(COLOR_LRED, "Admin %s has changed the family money ID: %d to %s.", pData[playerid][pAdminname], fid, FormatMoney(money));
    }
    else if(!strcmp(type, "marijuana", true))
    {
        new marijuana;

        if(sscanf(string, "d", marijuana))
            return Usage(playerid, "/fedit [id] [marijuana] [ammount]");

        fData[fid][fMarijuana] = marijuana;
		
        Family_Save(fid);
		Family_Refresh(fid);
		
		SendStaffMessage(COLOR_LRED, "Admin %s has changed the family marijuana ID: %d to %s.", pData[playerid][pAdminname], fid, marijuana);
    }
	else if(!strcmp(type, "component", true))
    {
        new comp;

        if(sscanf(string, "d", comp))
            return Usage(playerid, "/fedit [id] [component] [ammount]");

        fData[fid][fComponent] = comp;
		
        Family_Save(fid);
		Family_Refresh(fid);
		
		SendStaffMessage(COLOR_LRED, "Admin %s has changed the family component ID: %d to %s.", pData[playerid][pAdminname], fid, comp);
    }
	else if(!strcmp(type, "material", true))
    {
        new mat;

        if(sscanf(string, "d", mat))
            return Usage(playerid, "/fedit [id] [material] [ammount]");

        fData[fid][fMarijuana] = mat;
		
        Family_Save(fid);
		Family_Refresh(fid);
		
		SendStaffMessage(COLOR_LRED, "Admin %s has changed the family material ID: %d to %s.", pData[playerid][pAdminname], fid, mat);
    }
    return 1;
}

CMD:fgoto(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return PermissionError(playerid);

	new fid;
	if(sscanf(params, "d", fid))
		return Usage(playerid, "/fgoto [family id]");

	if(!Iter_Contains(FAMILYS, fid))
		return Error(playerid, "Invalid family ID!");
	
	SetPlayerPos(playerid, fData[fid][fExtposX], fData[fid][fExtposY], fData[fid][fExtposZ]);
	SetPlayerFacingAngle(playerid, fData[fid][fExtposA]);
	Info(playerid, "Anda telah diteleport menuju family id %d", fid);
	return 1;
}

CMD:fsafe(playerid)
{
	if(pData[playerid][pFamily] == -1)
		return Error(playerid, "Anda bukan anggota family");
		
	new fid = pData[playerid][pFamily];
	if(IsPlayerInRangeOfPoint(playerid, 3.0, fData[fid][fSafeposX], fData[fid][fSafeposY], fData[fid][fSafeposZ]))
    {
     	ShowPlayerDialog(playerid, FAMILY_SAFE, DIALOG_STYLE_LIST, "Family SAFE", "Storage\nMarijuana\nComponent\nMaterial\nMoney", "Select", "Cancel");
    }
 	else
   	{
     	Error(playerid, "You aren't in range in area family safe.");
    }
	return 1;
}

CMD:finvite(playerid, params[])
{
	if(pData[playerid][pFamily] == -1)
		return Error(playerid, "You are not in family!");
		
	if(pData[playerid][pFamilyRank] < 5)
		return Error(playerid, "You must family rank 5 - 6!");
	
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/invite [playerid/PartOfName]");
		
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "Invalid ID.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");
		
	if(!NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "You must be near this player.");
	
	if(pData[otherid][pFamily] != -1)
		return Error(playerid, "Player tersebut sudah bergabung family!");
	
	if(pData[otherid][pFaction] != 0)
		return Error(playerid, "Player tersebut sudah bergabung faction!");
		
	pData[otherid][pFamInvite] = pData[playerid][pFamily];
	pData[otherid][pFamOffer] = playerid;
	Servers(playerid, "Anda telah menginvite %s untuk menjadi anggota family.", pData[otherid][pName]);
	Servers(otherid, "%s telah menginvite anda untuk menjadi anggota family. Type: /accept family or /deny family!", pData[playerid][pName]);
	return 1;
}
CMD:f(playerid, params[])
{
    new text[128];
    
    if(pData[playerid][pFamily] == -1)
        return ErrorMsg(playerid, "You must in family member to use this command");
            
    if(sscanf(params,"s[128]",text))
        return SyntaxMsg(playerid, "/f(family) [text]");

    if(strval(text) > 128)
        return ErrorMsg(playerid,"Text too long.");
	
	SendFamilyMessage(pData[playerid][pFamily], COLOR_FAMILY, ""FAMILY_E"* %s %s: %s *", GetFamilyRank(playerid), pData[playerid][pName], params);
    return 1;
}
CMD:funinvite(playerid, params[])
{
	if(pData[playerid][pFamily] == -1)
		return Error(playerid, "You are not in family!");
		
	if(pData[playerid][pFamilyRank] < 5)
		return Error(playerid, "You must family level 5 - 6!");
	
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/uninvite [playerid/PartOfName]");
		
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "Invalid ID.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");
	
	if(pData[otherid][pFamily] != pData[playerid][pFamily])
		return Error(playerid, "Player tersebut bukan anggota family mu");

	if(pData[otherid][pFamilyRank] > pData[playerid][pFamilyRank])
		return Error(playerid, "You cant kick him.");
		
	pData[otherid][pFamilyRank] = 0;
	pData[otherid][pFamily] = -1;
	Servers(playerid, "Anda telah mengeluarkan %s dari anggota family.", pData[otherid][pName]);
	Servers(otherid, "%s telah mengeluarkan anda dari anggota family.", pData[playerid][pName]);
	return 1;
}

CMD:fsetrank(playerid, params[])
{
	new rank, otherid;
	if(pData[playerid][pFamilyRank] < 6 && pData[playerid][pAdmin] < 5)
		return Error(playerid, "You must family leader!");
		
	if(sscanf(params, "ud", otherid, rank))
        return Usage(playerid, "/fsetrank [playerid/PartOfName] [rank 1-6]");
	
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "Invalid ID.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");
	
	if(pData[otherid][pFamily] != pData[playerid][pFamily])
		return Error(playerid, "This player is not in your family!");
	
	if(rank < 1 || rank > 6)
		return Error(playerid, "rank must 1 - 6 only");
	
	pData[otherid][pFamilyRank] = rank;
	Servers(playerid, "You has set %s family rank to level %d", pData[otherid][pName], rank);
	Servers(otherid, "%s has set your family rank to level %d", pData[playerid][pName], rank);
	return 1;
}

CMD:finfo(playerid, params[])
{
	if(pData[playerid][pFamily] == -1)
        return Error(playerid, "You must in family member to use this command!");
	
	ShowPlayerDialog(playerid, FAMILY_INFO, DIALOG_STYLE_LIST, "Family Info", "Family Info\nFamily Online\nFamily Member", "Select", "Cancel");
	return 1;
}

function ShowFamilyInfo(playerid)
{
	new rows = cache_num_rows();
 	if(rows)
  	{
 		new fname[50],
 			fleader[50],
			fmarijuana,
			fcomponent,
			fmaterial,
			fmoney,
			string[512];
			
		cache_get_value_index(0, 0, fname);
		cache_get_value_index(0, 1, fleader);
		cache_get_value_index_int(0, 2, fmarijuana);
		cache_get_value_index_int(0, 3, fcomponent);
		cache_get_value_index_int(0, 4, fmaterial);
		cache_get_value_index_int(0, 5, fmoney);

		format(string, sizeof(string), "Family ID: %d\nFamily Name: %s\nFamily Leader: %s\nFamily Marijuana: %d\nFamily Component: %d\nFamily Material: %d\nFamily Money: %s",
		pData[playerid][pFamily], fname, fleader, fmarijuana, fcomponent, fmaterial, FormatMoney(fmoney));
		
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Family Info", string, "Okay", "");
	}
}

function ShowFamilyMember(playerid)
{
	new rows = cache_num_rows(), pid, username[50], frank, query[1048];
 	if(rows)
  	{
		for(new i = 0; i != rows; i++)
		{
			cache_get_value_index(i, 0, username);
			pid = GetID(username);
			
			format(query, sizeof(query), "%s"WHITE_E"%d. %s ", query, (i+1), username);
			
			if(IsPlayerConnected(pid))
				strcat(query, ""GREEN_E"(ONLINE) ");
			else
				strcat(query, ""RED_E"(OFFLINE) ");
			
			cache_get_value_index_int(i, 1, frank);
			if(frank == 1)
			{
				strcat(query, ""FAMILY_E"Relasi");
			}
			else if(frank == 2)
			{
				strcat(query, ""FAMILY_E"Outsider");
			}
			else if(frank == 3)
			{
				strcat(query, ""FAMILY_E"Insider");
			}
			else if(frank == 4)
			{
				strcat(query, ""FAMILY_E"Tangan Kanan");
			}
			else if(frank == 5)
			{
				strcat(query, ""FAMILY_E"Wakil Ketua");
			}
			else if(frank == 6)
			{
				strcat(query, ""FAMILY_E"Ketua");
			}
			else
			{
				strcat(query, ""FAMILY_E"None(0)");
			}
			strcat(query, "\n{FFFFFF}");
		}
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Family Member", query, "Okay", "");
	}
}

CMD:fmenu(playerid, params[])
{
	if(pData[playerid][pFamily] == -1)
		return ErrorMsg(playerid, "Anda bukan bagian dari Family");

	ShowPlayerDialog(playerid, DIALOG_FMENU, DIALOG_STYLE_LIST, "Family Menu" , "Menggeledah\nMengikat Seseorang\nMembuka Ikatan\nMemasukan paksa (Kendaraan)\nMengeluarkan Paksa (Kendaraan)\nGendong Paksa\nMelepaskan Gendongan" , "Select" , "Cancel");
	return 1;
}

CMD:families(playerid, params[])
{
	new batandos = 0;
	new sastra = 0;
	new ballas = 0;

	for (new i = 0; i < MAX_PLAYERS; i++)
	{
		if (IsPlayerConnected(i))
		{
			if(pData[i][pFamily] == 2)
			{
				batandos++;
			}
			else if(pData[i][pFamily] == 1)
			{
				sastra++;
			}
			else if(pData[i][pFamily] == 3)
			{
				ballas++;
			}
		}
	}

	new str[500], info[500];
    format(str, sizeof(str), "{FFFFFF}Family\tOnline\nBatandos MC\t%d\nSastra Side\t%d\nThe Ballas Gang\t%d", batandos, sastra, ballas);
    strcat(info, str);
    ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Dark", info, "Tutup", "");
	return 1;
}