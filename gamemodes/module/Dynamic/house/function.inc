function LoadHouses()
{
    static
        str[128],
		hid;
		
	new rows = cache_num_rows(), owner[128], owner2[128], address[128];
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "ID", hid);
			cache_get_value_name(i, "owner", owner);
			format(hData[hid][hOwner], 128, owner);
			cache_get_value_name(i, "owner2", owner2);
			format(hData[hid][hOwner2], 128, owner2);
			cache_get_value_name(i, "address", address);
			format(hData[hid][hAddress], 128, address);
			cache_get_value_name_int(i, "price", hData[hid][hPrice]);
			cache_get_value_name_int(i, "type", hData[hid][hType]);
			cache_get_value_name_float(i, "extposx", hData[hid][hExtposX]);
			cache_get_value_name_float(i, "extposy", hData[hid][hExtposY]);
			cache_get_value_name_float(i, "extposz", hData[hid][hExtposZ]);
			cache_get_value_name_float(i, "extposa", hData[hid][hExtposA]);
			cache_get_value_name_float(i, "intposx", hData[hid][hIntposX]);
			cache_get_value_name_float(i, "intposy", hData[hid][hIntposY]);
			cache_get_value_name_float(i, "intposz", hData[hid][hIntposZ]);
			cache_get_value_name_float(i, "intposa", hData[hid][hIntposA]);
			cache_get_value_name_int(i, "houseint", hData[hid][hInt]);
			cache_get_value_name_int(i, "money", hData[hid][hMoney]);
			cache_get_value_name_int(i, "component", hData[hid][hComponent]);
			cache_get_value_name_int(i, "material", hData[hid][hMaterial]);
			cache_get_value_name_int(i, "marijuana", hData[hid][hMarijuana]);
			cache_get_value_name_int(i, "ephedrine", hData[hid][hEphedrine]);
			cache_get_value_name_int(i, "cocaine", hData[hid][hCocaine]);
			cache_get_value_name_int(i, "meth", hData[hid][hMeth]);
			cache_get_value_name_int(i, "locked", hData[hid][hLocked]);
			cache_get_value_name_int(i, "visit", hData[hid][hVisit]);

			for (new j = 0; j < 10; j ++)
			{
				format(str, 24, "houseWeapon%d", j + 1);
				cache_get_value_name_int(i, str, hData[hid][hWeapon][j]);

				format(str, 24, "houseAmmo%d", j + 1);
				cache_get_value_name_int(i, str, hData[hid][hAmmo][j]);
			}
			House_Refresh(hid);
			Iter_Add(Houses, hid);
		}
		printf("[DATABASE] Number of House Loaded: %d.", rows);
		//Profiler_Stop();
	}
}