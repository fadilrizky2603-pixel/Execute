function OnFamilyCreated(id)
{
	Family_Save(id);
	Family_Refresh(id);
	return 1;
}

function LoadFamilys()
{
    new rows = cache_num_rows();
 	if(rows)
  	{
   		new fid, name[50], leader[MAX_PLAYER_NAME], motd[100];
		for(new i; i < rows; i++)
		{
  			cache_get_value_name_int(i, "ID", fid);
	    	cache_get_value_name(i, "name", name);
			format(fData[fid][fName], 50, name);
		    cache_get_value_name(i, "leader", leader);
			format(fData[fid][fLeader], MAX_PLAYER_NAME, leader);
			cache_get_value_name(i, "motd", motd);
			format(fData[fid][fMotd], 100, motd);
		    cache_get_value_name_int(i, "color", fData[fid][fColor]);
		    cache_get_value_name_float(i, "extposx", fData[fid][fExtposX]);
		    cache_get_value_name_float(i, "extposy", fData[fid][fExtposY]);
		    cache_get_value_name_float(i, "extposz", fData[fid][fExtposZ]);
		    cache_get_value_name_float(i, "extposa", fData[fid][fExtposA]);
		    cache_get_value_name_float(i, "intposx", fData[fid][fIntposX]);
		    cache_get_value_name_float(i, "intposy", fData[fid][fIntposY]);
		    cache_get_value_name_float(i, "intposz", fData[fid][fIntposZ]);
		    cache_get_value_name_float(i, "intposa", fData[fid][fIntposA]);
		    cache_get_value_name_int(i, "fint", fData[fid][fInt]);
			cache_get_value_name_float(i, "safex", fData[fid][fSafeposX]);
			cache_get_value_name_float(i, "safey", fData[fid][fSafeposY]);
			cache_get_value_name_float(i, "safez", fData[fid][fSafeposZ]);
			cache_get_value_name_int(i, "money", fData[fid][fMoney]);
			cache_get_value_name_int(i, "marijuana", fData[fid][fMarijuana]);
			cache_get_value_name_int(i, "component", fData[fid][fComponent]);
			cache_get_value_name_int(i, "material", fData[fid][fMaterial]);
			
			cache_get_value_name_int(i, "Weapon1", fData[fid][fGun][0]);
			cache_get_value_name_int(i, "Weapon2", fData[fid][fGun][1]);
			cache_get_value_name_int(i, "Weapon3", fData[fid][fGun][2]);
			cache_get_value_name_int(i, "Weapon4", fData[fid][fGun][3]);
			cache_get_value_name_int(i, "Weapon5", fData[fid][fGun][4]);
			cache_get_value_name_int(i, "Weapon6", fData[fid][fGun][5]);
			cache_get_value_name_int(i, "Weapon7", fData[fid][fGun][6]);
			cache_get_value_name_int(i, "Weapon8", fData[fid][fGun][7]);
			cache_get_value_name_int(i, "Weapon9", fData[fid][fGun][8]);
			cache_get_value_name_int(i, "Weapon10", fData[fid][fGun][9]);
			cache_get_value_name_int(i, "Weapon11", fData[fid][fGun][10]);
			cache_get_value_name_int(i, "Weapon12", fData[fid][fGun][11]);
			cache_get_value_name_int(i, "Weapon13", fData[fid][fGun][12]);
			cache_get_value_name_int(i, "Weapon14", fData[fid][fGun][13]);
			cache_get_value_name_int(i, "Weapon15", fData[fid][fGun][14]);
			
			cache_get_value_name_int(i, "Ammo1", fData[fid][fAmmo][0]);
			cache_get_value_name_int(i, "Ammo2", fData[fid][fAmmo][1]);
			cache_get_value_name_int(i, "Ammo3", fData[fid][fAmmo][2]);
			cache_get_value_name_int(i, "Ammo4", fData[fid][fAmmo][3]);
			cache_get_value_name_int(i, "Ammo5", fData[fid][fAmmo][4]);
			cache_get_value_name_int(i, "Ammo6", fData[fid][fAmmo][5]);
			cache_get_value_name_int(i, "Ammo7", fData[fid][fAmmo][6]);
			cache_get_value_name_int(i, "Ammo8", fData[fid][fAmmo][7]);
			cache_get_value_name_int(i, "Ammo9", fData[fid][fAmmo][8]);
			cache_get_value_name_int(i, "Ammo10", fData[fid][fAmmo][9]);
			cache_get_value_name_int(i, "Ammo11", fData[fid][fAmmo][10]);
			cache_get_value_name_int(i, "Ammo12", fData[fid][fAmmo][11]);
			cache_get_value_name_int(i, "Ammo13", fData[fid][fAmmo][12]);
			cache_get_value_name_int(i, "Ammo14", fData[fid][fAmmo][13]);
			cache_get_value_name_int(i, "Ammo15", fData[fid][fAmmo][14]);
			/*for (new j = 0; j < 10; j ++)
			{
				format(str, 24, "Weapon%d", j + 1);
				cache_get_value_name_int(i, str, fData[fid][fGun][j]);

				format(str, 24, "Ammo%d", j + 1);
				cache_get_value_name_int(i, str, fData[fid][fAmmo][j]);
			}*/
			
			Iter_Add(FAMILYS, fid);
			Family_Refresh(fid);
	    }
	    printf("[DATABASE] Number of Familys loaded: %d.", rows);
		//Profiler_Stop();
	}
}
