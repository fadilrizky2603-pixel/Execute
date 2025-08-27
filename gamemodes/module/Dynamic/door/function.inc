function OnDoorsCreated(id)
{
	Doors_Save(id);
	Doors_Updatelabel(id);
	return 1;
}

function LoadDoors()
{
    new rows = cache_num_rows();
 	if(rows)
  	{
   		new did, name[128], password[128];
		for(new i; i < rows; i++)
		{
  			cache_get_value_name_int(i, "ID", did);
	    	cache_get_value_name(i, "name", name);
			format(dData[did][dName], 128, name);
		    cache_get_value_name(i, "password", password);
			format(dData[did][dPass], 128, password);
		    cache_get_value_name_int(i, "icon", dData[did][dIcon]);
		    cache_get_value_name_int(i, "locked", dData[did][dLocked]);
		    cache_get_value_name_int(i, "admin", dData[did][dAdmin]);
		    cache_get_value_name_int(i, "vip", dData[did][dVip]);
		    cache_get_value_name_int(i, "faction", dData[did][dFaction]);
		    cache_get_value_name_int(i, "family", dData[did][dFamily]);
			cache_get_value_name_int(i, "garage", dData[did][dGarage]);
		    cache_get_value_name_int(i, "custom", dData[did][dCustom]);
		    cache_get_value_name_int(i, "extvw", dData[did][dExtvw]);
		    cache_get_value_name_int(i, "extint", dData[did][dExtint]);
		    cache_get_value_name_float(i, "extposx", dData[did][dExtposX]);
			cache_get_value_name_float(i, "extposy", dData[did][dExtposY]);
			cache_get_value_name_float(i, "extposz", dData[did][dExtposZ]);
			cache_get_value_name_float(i, "extposa", dData[did][dExtposA]);
			cache_get_value_name_int(i, "intvw", dData[did][dIntvw]);
			cache_get_value_name_int(i, "intint", dData[did][dIntint]);
			cache_get_value_name_float(i, "intposx", dData[did][dIntposX]);
			cache_get_value_name_float(i, "intposy", dData[did][dIntposY]);
			cache_get_value_name_float(i, "intposz", dData[did][dIntposZ]);
			cache_get_value_name_float(i, "intposa", dData[did][dIntposA]);
			
			Iter_Add(Doors, did);
			Doors_Updatelabel(did);
	    }
	    printf("[DATABASE] Number of Doors loaded: %d.", rows);
		//Profiler_Stop();
	}
}