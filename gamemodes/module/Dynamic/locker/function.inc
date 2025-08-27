function LoadLockers()
{
    static lid;
	
	new rows = cache_num_rows();
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", lid);
			cache_get_value_name_int(i, "type", lData[lid][lType]);
			cache_get_value_name_float(i, "posx", lData[lid][lPosX]);
			cache_get_value_name_float(i, "posy", lData[lid][lPosY]);
			cache_get_value_name_float(i, "posz", lData[lid][lPosZ]);
			cache_get_value_name_int(i, "interior", lData[lid][lInt]);
			cache_get_value_name_int(i, "money", lData[lid][lMoney]);
			Locker_Refresh(lid);
			Iter_Add(Lockers, lid);
		}
		printf("[DATABASE] Number of locker Loaded: %d.", rows);
		//Profiler_Stop();
	}
}

function OnLockerCreated(lid)
{
	Locker_Save(lid);
	return 1;
}