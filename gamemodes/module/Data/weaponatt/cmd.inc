//Weapon Attach System
CMD:weapon(playerid, params[])
{
	new weaponid = GetPlayerWeaponEx(playerid);
	new ammo = GetPlayerAmmoEx(playerid);
	
	new name[20], give[128];
	if(sscanf(params, "s[20]S()[128]", name, give))
		return Usage(playerid, "/weapon [give/drop/pickup/pos/bone/hide]");

	if(!strcmp(name, "pos", true))
	{
		if (!weaponid)
			return Error(playerid, "You are not holding a weapon.");

		if (!IsWeaponWearable(weaponid))
			return Error(playerid, "This weapon cannot be edited.");
		
		if (EditingWeapon[playerid])
			return Error(playerid, "You are already editing a weapon.");

		if (WeaponSettings[playerid][weaponid - 22][Hidden])
			return Error(playerid, "You cannot adjust a hidden weapon.");

		new index = weaponid - 22;
		   
		SetPlayerArmedWeapon(playerid, 0);
	   
		SetPlayerAttachedObject(playerid, GetWeaponObjectSlot(weaponid), GetWeaponModel(weaponid), WeaponSettings[playerid][index][Bone], WeaponSettings[playerid][index][Position][0], WeaponSettings[playerid][index][Position][1], WeaponSettings[playerid][index][Position][2], WeaponSettings[playerid][index][Position][3], WeaponSettings[playerid][index][Position][4], WeaponSettings[playerid][index][Position][5], 1.0, 1.0, 1.0);
		EditAttachedObject(playerid, GetWeaponObjectSlot(weaponid));
	   
		EditingWeapon[playerid] = weaponid;
	}
	else if (!strcmp(name, "bone", true))
	{
		if (!weaponid)
			return Error(playerid, "You are not holding a weapon.");

		if (!IsWeaponWearable(weaponid))
			return Error(playerid, "This weapon cannot be edited.");
			
		if (EditingWeapon[playerid])
			return Error(playerid, "You are already editing a weapon.");

		ShowPlayerDialog(playerid, DIALOG_EDITBONE, DIALOG_STYLE_LIST, "Bone", "Spine\nHead\nLeft upper arm\nRight upper arm\nLeft hand\nRight hand\nLeft thigh\nRight thigh\nLeft foot\nRight foot\nRight calf\nLeft calf\nLeft forearm\nRight forearm\nLeft shoulder\nRight shoulder\nNeck\nJaw", "Choose", "Cancel");
		EditingWeapon[playerid] = weaponid;
	}
	else if (!strcmp(name, "hide", true))
	{
		if (!weaponid)
			return Error(playerid, "You are not holding a weapon.");

		if (!IsWeaponWearable(weaponid))
			return Error(playerid, "This weapon cannot be edited.");
			
		if (EditingWeapon[playerid])
			return Error(playerid, "You cannot hide a weapon while you are editing it.");

		if (!IsWeaponHideable(weaponid))
			return Error(playerid, "This weapon cannot be hidden.");

		new index = weaponid - 22, weaponname[18], string[150];

		GetWeaponName(weaponid, weaponname, sizeof(weaponname));
	   
		if (WeaponSettings[playerid][index][Hidden])
		{
			format(string, sizeof(string), "You have set your %s to show.", weaponname);
			WeaponSettings[playerid][index][Hidden] = false;
		}
		else
		{
			if (IsPlayerAttachedObjectSlotUsed(playerid, GetWeaponObjectSlot(weaponid)))
				RemovePlayerAttachedObject(playerid, GetWeaponObjectSlot(weaponid));

			format(string, sizeof(string), "You have set your %s not to show.", weaponname);
			WeaponSettings[playerid][index][Hidden] = true;
		}
		SendClientMessage(playerid, -1, string);
	   
		mysql_format(g_SQL, string, sizeof(string), "INSERT INTO weaponsettings (Owner, WeaponID, Hidden) VALUES ('%d', %d, %d) ON DUPLICATE KEY UPDATE Hidden = VALUES(Hidden)", pData[playerid][pID], weaponid, WeaponSettings[playerid][index][Hidden]);
		mysql_tquery(g_SQL, string);
	}
	else if(!strcmp(name, "give", true))
	{
		if (!weaponid)
			return Error(playerid, "You are not holding a weapon.");

		new otherid;	
		if(sscanf(give, "u", otherid))
			return Usage(playerid, "/weapon [give] [playerid]");
			
		if(otherid == INVALID_PLAYER_ID || otherid == playerid || !NearPlayer(playerid, otherid, 5.0))
			return Error(playerid, "You must in near target player.");
		
		if(PlayerHasWeapon(otherid, weaponid))
			return Error(playerid, "Player yang dituju sudah memiliki senjata tersebut");

		if(pData[otherid][pLevel] < 3)
			return Error(playerid, "Player tersebut masih dibawah level 3");

		ResetWeapon(playerid, weaponid);
		Info(playerid, "Anda telah memberikan weapon %s kepada %s.", ReturnWeaponName(weaponid) , ReturnName(otherid));
		Info(otherid, "%s telah memberikan weapon %s kepada anda.", ReturnName(playerid), ReturnWeaponName(weaponid));
		GivePlayerWeaponEx(otherid, weaponid, ammo);
	}
	else if(!strcmp(name, "drop", true))
	{
		if (!weaponid)
			return Error(playerid, "You are not holding a weapon.");
			
		static
			Float:x,
			Float:y,
			Float:z,
			Float:angle;

		GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, angle);

		x += 1 * floatsin(-angle, degrees);
		y += 1 * floatcos(-angle, degrees);

		DropWeapon(pData[playerid][pName], GetWeaponModel(weaponid), weaponid, GetPlayerAmmoEx(playerid), x, y, z - 1, GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
		ResetWeapon(playerid, weaponid);

		ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 1);
		SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s takes out a %s and drops it on the floor.", ReturnName(playerid), ReturnWeaponName(weaponid));
	}
	else if(!strcmp(name, "pickup", true))
	{
		new wid = NearWeapon(playerid);
		if(wid != -1)
        {
			PickupWeapon(playerid, wid);
			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has picked up a %s.", ReturnName(playerid), ReturnWeaponName(DropWeap[wid][WeaponID]));
			ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 1);
		}
	}
	else Error(playerid, "You have specified an invalid option.");
	return 1;
}

CMD:reloadweap(playerid, params[])
{
	if(GetPlayerWeapon(playerid) == 0)
		return Error(playerid, "Kamu harus memegang senjata api");

	new weaponid = GetPlayerWeaponEx(playerid), ammo = GetPlayerAmmoEx(playerid);

	if(weaponid < 22 || weaponid > 32)
		return Error(playerid, "this weapon does not support to use clip");

	if(weaponid >= 22 && weaponid <= 24) //PISTOL
	{
		if(Inventory_Count(playerid, "Clip Pistol") <= 0)
			return Error(playerid, "Kamu tidak memiliki Pistol Clip");

		if(weaponid == 22 || weaponid == 23)
		{
			GivePlayerWeaponEx(playerid, weaponid, ammo+20);
		}
		else
		{
			GivePlayerWeaponEx(playerid, weaponid, ammo+15);
		}
		Inventory_Remove(playerid, "Clip Pistol", 1);
		Info(playerid, "Succes reloaded ammo weapon %s with Pistol Clip", ReturnWeaponName(weaponid));
		ApplyAnimation(playerid, "PYTHON", "python_reload", 4.1, 0, 0, 0, 0, 0);
	}
	if(weaponid >= 25 && weaponid <= 27) //SHOTGUN
	{
		if(Inventory_Count(playerid, "Clip Sg") <= 0)
			return Error(playerid, "Kamu tidak memiliki Shotgun Clip");

		Inventory_Remove(playerid, "Clip Sg", 1);
		GivePlayerWeaponEx(playerid, weaponid, ammo+20);
		Info(playerid, "Succes reloaded ammo weapon %s with Shotgun Clip", ReturnWeaponName(weaponid));
		ApplyAnimation(playerid, "BUDDY", "buddy_reload", 4.1, 0, 0, 0, 0, 0);
	}
	if(weaponid >= 28 && weaponid <= 32) //SMG
	{
		if(Inventory_Count(playerid, "Smg") <= 0)
			return Error(playerid, "Kamu tidak memiliki SMG Clip");

		Inventory_Remove(playerid, "Clip Smg", 1);
		GivePlayerWeaponEx(playerid, weaponid, ammo+100);
		Info(playerid, "Succes reloaded ammo weapon %s with SMG Clip", ReturnWeaponName(weaponid));
		ApplyAnimation(playerid, "RIFLE", "RIFLE_load", 4.1, 0, 0, 0, 0, 0);
	}
	return 1;
}