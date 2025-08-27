function LoadPfarm()
{
    static pfid;
	
	new rows = cache_num_rows(), owner[128];
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", pfid);
			cache_get_value_name(i, "owner", owner);
			format(pfData[pfid][pfOwner], 128, owner);
			cache_get_value_name_int(i, "price", pfData[pfid][pfPrice]);
			cache_get_value_name_float(i, "posx", pfData[pfid][pfX]);
			cache_get_value_name_float(i, "posy", pfData[pfid][pfY]);
			cache_get_value_name_float(i, "posz", pfData[pfid][pfZ]);
			cache_get_value_name_float(i, "posa", pfData[pfid][pfA]);
			cache_get_value_name_int(i, "interior", pfData[pfid][pfInt]);
			cache_get_value_name_int(i, "world", pfData[pfid][pfVW]);
			cache_get_value_name_int(i, "seeds", pfData[pfid][pfSeeds]);
			cache_get_value_name_int(i, "potato", pfData[pfid][pfPotato]);
			cache_get_value_name_int(i, "orange", pfData[pfid][pfOrange]);
			cache_get_value_name_int(i, "wheat", pfData[pfid][pfWheat]);
			cache_get_value_name_int(i, "visit", pfData[pfid][pfVisit]);

			Pfarm_Refresh(pfid);
			Iter_Add(PFarm, pfid);
		}
		printf("[DATABASE] Number of private fram Loaded: %d.", rows);
		//Profiler_Stop();
	}
}

function OnPfarmCreated(id)
{
	Pfarm_Save(id);
	return 1;
}