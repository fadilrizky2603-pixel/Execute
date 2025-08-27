Family_Save(id)
{
	new dquery[2048];
	format(dquery, sizeof(dquery), "UPDATE familys SET name='%s', leader='%s', motd='%s', color='%d', extposx='%f', extposy='%f', extposz='%f', extposa='%f', intposx='%f', intposy='%f', intposz='%f', intposa='%f', fint='%d'",
	fData[id][fName],
	fData[id][fLeader],
	fData[id][fMotd],
	fData[id][fColor],
	fData[id][fExtposX],
	fData[id][fExtposY],
	fData[id][fExtposZ],
	fData[id][fExtposA],
	fData[id][fIntposX],
	fData[id][fIntposY],
	fData[id][fIntposZ],
	fData[id][fIntposA],
	fData[id][fInt]);
	
	for (new i = 0; i < 15; i ++) 
	{
        format(dquery, sizeof(dquery), "%s, Weapon%d='%d', Ammo%d='%d'", dquery, i + 1, fData[id][fGun][i], i + 1, fData[id][fAmmo][i]);
    }
	
	format(dquery, sizeof(dquery), "%s, safex='%f', safey='%f', safez='%f', money='%d', marijuana='%d', component='%d', material='%d' WHERE ID='%d'",
	dquery,
	fData[id][fSafeposX],
	fData[id][fSafeposY],
	fData[id][fSafeposZ],
	fData[id][fMoney],
	fData[id][fMarijuana],
	fData[id][fComponent],
	fData[id][fMaterial],
	id);
	return mysql_tquery(g_SQL, dquery);
}


Family_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamic3DTextLabel(fData[id][fLabelext]))
            DestroyDynamic3DTextLabel(fData[id][fLabelext]);

        if(IsValidDynamicPickup(fData[id][fPickext]))
            DestroyDynamicPickup(fData[id][fPickext]);

        if(IsValidDynamic3DTextLabel(fData[id][fLabelint]))
            DestroyDynamic3DTextLabel(fData[id][fLabelint]);

        if(IsValidDynamicPickup(fData[id][fPickint]))
            DestroyDynamicPickup(fData[id][fPickint]);
			
		if(IsValidDynamic3DTextLabel(fData[id][fLabelsafe]))
            DestroyDynamic3DTextLabel(fData[id][fLabelsafe]);

        if(IsValidDynamicPickup(fData[id][fPicksafe]))
            DestroyDynamicPickup(fData[id][fPicksafe]);
		
		new mstr[512], tstr[128];
		format(mstr,sizeof(mstr),"[Family ID: %d]\n{FFFFFF}%s\n{FFFFFF}Press {FF0000}ENTER {FFFFFF}to enter", id, fData[id][fName]);
		fData[id][fPickext] = CreateDynamicPickup(19130, 23, fData[id][fExtposX], fData[id][fExtposY], fData[id][fExtposZ], 0, 0);
		fData[id][fLabelext] = CreateDynamic3DTextLabel(mstr, COLOR_YELLOW, fData[id][fExtposX], fData[id][fExtposY], fData[id][fExtposZ]+0.35, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0);

        if(fData[id][fIntposX] != 0.0 && fData[id][fIntposY] != 0.0 && fData[id][fIntposZ] != 0.0)
        {
            format(mstr,sizeof(mstr),"[Family ID: %d]\n{FFFFFF}%s\n{FFFFFF}Press {FF0000}ENTER {FFFFFF}to exit", id, fData[id][fName]);

            fData[id][fLabelint] = CreateDynamic3DTextLabel(mstr, COLOR_YELLOW, fData[id][fIntposX], fData[id][fIntposY], fData[id][fIntposZ]+0.7, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, id, fData[id][fInt]);
            fData[id][fPickint] = CreateDynamicPickup(19130, 23, fData[id][fIntposX], fData[id][fIntposY], fData[id][fIntposZ], id, fData[id][fInt], -1, 7);
        }
		if(fData[id][fSafeposX] != 0.0 && fData[id][fSafeposY] != 0.0 && fData[id][fSafeposZ] != 0.0)
		{
			format(tstr, sizeof(tstr), "[Family ID: %d]\nSafe Point", id);
			fData[id][fLabelsafe] = CreateDynamic3DTextLabel(tstr, COLOR_YELLOW, fData[id][fSafeposX], fData[id][fSafeposY], fData[id][fSafeposZ]+0.7, 5.0);
            fData[id][fPicksafe] = CreateDynamicPickup(1239, 23, fData[id][fSafeposX], fData[id][fSafeposY], fData[id][fSafeposZ], id, fData[id][fInt], -1, 7);
		}
	}
}

/*LoadFamily()
{
	mysql_tquery(g_SQL, "SELECT ID,name,leader,motd,color,extposx,extposy,extposz,extposa,intposx,intposy,intposz,intposa,fint,safex,safey,safez,money,marijuana FROM familys ORDER BY ID", "LoadFamilyData");
}*/

Family_WeaponStorage(playerid, fid)
{
    if(fid == -1)
        return 0;

    static
        string[320];

    string[0] = 0;

    for (new i = 0; i < 15; i ++)
    {
        if(!fData[fid][fGun][i])
            format(string, sizeof(string), "%sSlot Kosong\n", string);

        else
            format(string, sizeof(string), "%s%s (Ammo: %d)\n", string, ReturnWeaponName(fData[fid][fGun][i]), fData[fid][fAmmo][i]);
    }
    ShowPlayerDialog(playerid, FAMILY_WEAPONS, DIALOG_STYLE_LIST, "Weapon Storage", string, "Select", "Cancel");
    return 1;
}

Family_OpenStorage(playerid, fid)
{
    if(fid == -1)
        return 0;

    new
        items[1],
        string[10 * 32];

    for (new i = 0; i < 15; i ++) if(fData[fid][fGun][i]) 
	{
        items[0]++;
    }
    format(string, sizeof(string), "Weapon Storage (%d/15)", items[0]);
    ShowPlayerDialog(playerid, FAMILY_STORAGE, DIALOG_STYLE_LIST, "Family Storage", string, "Select", "Cancel");
    return 1;
}