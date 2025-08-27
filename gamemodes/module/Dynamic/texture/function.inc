function LoadMatext()
{
    static mtid;
	
	new rows = cache_num_rows(), string[254];
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", mtid);
			cache_get_value_name(i, "text", string);
			format(mtData[mtid][mtText], 254, string);
			cache_get_value_name_int(i, "size", mtData[mtid][mtSize]);
			cache_get_value_name_int(i, "color", mtData[mtid][mtColor]);
			cache_get_value_name_int(i, "bold", mtData[mtid][mtBold]);
			cache_get_value_name_float(i, "x", mtData[mtid][mtX]);
			cache_get_value_name_float(i, "y", mtData[mtid][mtY]);
			cache_get_value_name_float(i, "z", mtData[mtid][mtZ]);
			cache_get_value_name_float(i, "rx", mtData[mtid][mtRX]);
			cache_get_value_name_float(i, "ry", mtData[mtid][mtRY]);
			cache_get_value_name_float(i, "rz", mtData[mtid][mtRZ]);
			cache_get_value_name_int(i, "interior", mtData[mtid][mtInt]);
			cache_get_value_name_int(i, "world", mtData[mtid][mtVW]);
			Matext_Refresh(mtid);
			Iter_Add(Matext, mtid);
		}
		printf("[DATABASE] Number of matrial text Loaded: %d.", rows);
		//Profiler_Stop();
	}
}

function OnMatextCreated(id)
{
	Matext_Save(id);
	return 1;
}