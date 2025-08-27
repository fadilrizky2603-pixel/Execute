function LoadGates()
{
    new rows = cache_num_rows();
 	if(rows)
  	{
   		new id, password[36];
		for(new i; i < rows; i++)
		{
  			cache_get_value_name_int(i, "ID", id);
	    	cache_get_value_name_int(i, "model", gData[id][gModel]);
		    cache_get_value_name(i, "password", password);
			format(gData[id][gPass], 36, password);
		    cache_get_value_name_int(i, "admin", gData[id][gAdmin]);
		    cache_get_value_name_int(i, "vip", gData[id][gVip]);
		    cache_get_value_name_int(i, "faction", gData[id][gFaction]);
		    cache_get_value_name_int(i, "family", gData[id][gFamily]);
		    cache_get_value_name_float(i, "speed", gData[id][gSpeed]);
		    cache_get_value_name_float(i, "cX", gData[id][gCX]);
			cache_get_value_name_float(i, "cY", gData[id][gCY]);
			cache_get_value_name_float(i, "cZ", gData[id][gCZ]);
			cache_get_value_name_float(i, "cRX", gData[id][gCRX]);
			cache_get_value_name_float(i, "cRY", gData[id][gCRY]);
			cache_get_value_name_float(i, "cRZ", gData[id][gCRZ]);
			cache_get_value_name_float(i, "oX", gData[id][gOX]);
			cache_get_value_name_float(i, "oY", gData[id][gOY]);
			cache_get_value_name_float(i, "oZ", gData[id][gOZ]);
			cache_get_value_name_float(i, "oRX", gData[id][gORX]);
			cache_get_value_name_float(i, "oRY", gData[id][gORY]);
			cache_get_value_name_float(i, "oRZ", gData[id][gORZ]);
			
			Iter_Add(Gates, id);
			new str[128];
			format(str, sizeof(str), "Gate ID: %d", id);
			gData[id][gObjID] = CreateDynamicObject(gData[id][gModel], gData[id][gCX], gData[id][gCY], gData[id][gCZ], gData[id][gCRX], gData[id][gCRY], gData[id][gCRZ], -1, -1, -1, 50.0, 50.0);
			
			gData[id][gText] = CreateDynamic3DTextLabel(str, COLOR_WHITE, gData[id][gCX], gData[id][gCY], gData[id][gCZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 10.0);
			gData[id][gStatus] = 0;
	    }
	    printf("[DATABASE] Number of Gates loaded: %d.", rows);
		//Profiler_Stop();
	}
}

function OnGateCreated(id)
{
	Gate_Save(id);
	return 1;
}