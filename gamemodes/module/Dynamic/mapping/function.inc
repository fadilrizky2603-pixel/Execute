function LoadMAPO()
{
	new rows;
	cache_get_row_count(rows);
	if(rows)
  	{
 		new id, i = 0;
		while(i < rows)
		{
		    cache_get_value_name_int(i, "id", id);
		    cache_get_value_name_int(i, "objectmodel", MapoData[id][mapoObject]);
			cache_get_value_name_float(i, "posx", MapoData[id][mapoX]);
			cache_get_value_name_float(i, "posy", MapoData[id][mapoY]);
			cache_get_value_name_float(i, "posz", MapoData[id][mapoZ]);
			cache_get_value_name_float(i, "posrx", MapoData[id][mapoRX]);
			cache_get_value_name_float(i, "posry", MapoData[id][mapoRY]);
			cache_get_value_name_float(i, "posrz", MapoData[id][mapoRZ]);
			cache_get_value_name_int(i, "interior", MapoData[id][mapoInt]);
			cache_get_value_name_int(i, "world", MapoData[id][mapoWorld]);
			MapoData[id][mapoObjID] = CreateDynamicObject(MapoData[id][mapoObject], MapoData[id][mapoX], MapoData[id][mapoY], MapoData[id][mapoZ], MapoData[id][mapoRX], MapoData[id][mapoRY], MapoData[id][mapoRZ], MapoData[id][mapoWorld], MapoData[id][mapoInt], -1, 90.0, 90.0);
			MapoData[id][mapoLabel] = Text3D: -1;
			Iter_Add(MAPO, id);
	    	i++;
		}
		printf("[DATABASE] Number of creator mapping Loaded: %d.", i);
		//Profiler_Stop();
	}
}

function OnMapoCreated(playerid, id)
{
	Mapo_Save(id);
	Servers(playerid, "You has created Mapping Object id: %d.", id);
	return 1;
}