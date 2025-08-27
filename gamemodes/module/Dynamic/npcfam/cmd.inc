CMD:npcfam(playerid, const params[])
{
	if(pData[playerid][pFamily] != -1)
	{
		if(pData[playerid][pFamilyRank] > 4)
		{
			new nfid, names[128];
			if(sscanf(params, "ds[128]", nfid, names))
			{
				Usage(playerid, "/npcfam [nfid] [names]");
				Names(playerid, "location, menu");
				return 1;
			}

			if(!Iter_Contains(NPCFam, nfid))
				return Error(playerid, "Invalid NPC Family id!");

			if(pData[playerid][pFamily] != nfData[nfid][nfOwner])
				return Error(playerid, "NPC tersebut bukan miliki family mu!");

			if(!strcmp(names, "location", true))
			{
				new Float:x, Float:y, Float:z, Float:a;
				GetPlayerPos(playerid, x, y, z);
				GetPlayerFacingAngle(playerid, a);

				nfData[nfid][nfPosX] = x;
				nfData[nfid][nfPosY] = y;
				nfData[nfid][nfPosZ] = z;
				nfData[nfid][nfPosA] = a;

				nfData[nfid][nfVw] = GetPlayerVirtualWorld(playerid);
				nfData[nfid][nfInt] = GetPlayerInterior(playerid);

				Npcfam_Refresh(nfid);
				Npcfam_Save(nfid);

				Info(playerid, "Lokasi NPC Family %s (NPCID: %d) berhasil dipindahkan", fData[pData[playerid][pFamily]][fName], nfid);
			}
			else if(!strcmp(names, "menu", true))
			{
				if(!IsPlayerInRangeOfPoint(playerid, 3.5, nfData[nfid][nfPosX], nfData[nfid][nfPosY], nfData[nfid][nfPosZ]))
					return Error(playerid, "Kamu harus berada dekat denga NPC Family mu!");

				pData[playerid][pGetNPCFAMID] = nfid;
				
				new str[254];
				if(nfData[nfid][nfType] == 1)
				{
					format(str, sizeof(str), "Money (%s)\nMarijuana (%d gram)\nCocaine (%d gram)\nMeth (%d gram)\nProduct Menu", FormatMoney(nfData[nfid][nfMoney]), nfData[nfid][nfMaterial], nfData[nfid][nfMarijuana], nfData[nfid][nfCocaine], nfData[nfid][nfMeth]);
					ShowPlayerDialog(playerid, NPCFAM_MENU, DIALOG_STYLE_LIST, "NPC FAMILY (Drugs)", str, "Select", "Cancel");
				}
				else if(nfData[nfid][nfType] == 2)
				{
					format(str, sizeof(str), "Money (%s)\nMaterial (%d)\nProduct Menu", FormatMoney(nfData[nfid][nfMoney]), nfData[nfid][nfMaterial], nfData[nfid][nfMarijuana], nfData[nfid][nfCocaine], nfData[nfid][nfMeth]);
					ShowPlayerDialog(playerid, NPCFAM_MENU, DIALOG_STYLE_LIST, "NPC FAMILY (Weapon)", str, "Select", "Cancel");
				}	
			}
		}
		else return Error(playerid, "Hanya rank 5-6 yang bisa melakukan ini");
	}
	else return Error(playerid, "Kamu tidak bergabung family manapun");
	return 1;
}

CMD:deletenpcfam(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
	
	new nfid;
	if(sscanf(params, "d", nfid))
		return Usage(playerid, "/deletenpfam [nfid]");

	if(!Iter_Contains(NPCFam, nfid))
		return Error(playerid, "Invalid NPC Family id");

	Npcfam_Reset(nfid);

	Iter_Remove(NPCFam, nfid);
	
	new query[1024];
	mysql_format(g_SQL, query, sizeof(query), "DELETE FROM npcfamily WHERE id = '%d'", nfid);
	mysql_tquery(g_SQL, query);
    SendAdminMessage(COLOR_RED, "%s has delete NPC Family ID: %d.", pData[playerid][pAdminname], nfid);
    return 1;
}

CMD:fdelete(playerid, params[])
{
 	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

    new fid, query[128];
	if(sscanf(params, "i", fid)) return Usage(playerid, "/fdelete [fid]");
	if(!Iter_Contains(FAMILYS, fid)) return Error(playerid, "The you specified ID of doesn't exist.");
	
    format(fData[fid][fName], 50, "None");
	format(fData[fid][fLeader], 50, "None");
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
	
	DestroyDynamic3DTextLabel(fData[fid][fLabelext]);
	DestroyDynamicPickup(fData[fid][fPickext]);
	DestroyDynamic3DTextLabel(fData[fid][fLabelint]);
	DestroyDynamicPickup(fData[fid][fPickint]);
	DestroyDynamic3DTextLabel(fData[fid][fLabelsafe]);
	DestroyDynamicPickup(fData[fid][fPicksafe]);
	Iter_Remove(FAMILYS, fid);
	
	mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET family=-1,familyrank=0 WHERE family=%d", fid);
	mysql_tquery(g_SQL, query);
	
	foreach(new ii : Player)
	{
 		if(pData[ii][pFamily] == fid)
   		{
			pData[ii][pFamily]= -1;
			pData[ii][pFamilyRank] = 0;
		}
	}

	mysql_format(g_SQL, query, sizeof(query), "DELETE FROM familys WHERE ID=%d", fid);
	mysql_tquery(g_SQL, query);
    SendStaffMessage(COLOR_RED, "Admin %s telah menghapus family ID: %d.", pData[playerid][pAdminname], fid);

    for(new nfid = 0; nfid < MAX_NPCFAM; nfid++)
	{
		if(Iter_Contains(NPCFam, nfid))
		{
			if(nfData[nfid][nfOwner] == fid)
			{
				Npcfam_Reset(nfid);

				Iter_Remove(NPCFam, nfid);
				
				mysql_format(g_SQL, query, sizeof(query), "DELETE FROM npcfamily WHERE id = '%d'", nfid);
				mysql_tquery(g_SQL, query);
			    SendAdminMessage(COLOR_RED, "%s has delete NPC Family ID: %d.", pData[playerid][pAdminname], nfid);
			}
		}
	}
	return 1;
}

CMD:gotonpcfam(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);

    new nfid;
    if(sscanf(params, "d", nfid))
        return Usage(playerid, "/gotonpfam [nfid]");

    if(!Iter_Contains(NPCFam, nfid))
        return Error(playerid, "Invalid NPCFAM ID!");

    SetPlayerPos(playerid, nfData[nfid][nfPosX], nfData[nfid][nfPosY], nfData[nfid][nfPosZ]);
    SetPlayerVirtualWorld(playerid, nfData[nfid][nfVw]);
    SetPlayerInterior(playerid, nfData[nfid][nfInt]);

    Info(playerid, "Berhasil diteleport menuju NPCFAM ID: %d", nfid);
    return 1;
}