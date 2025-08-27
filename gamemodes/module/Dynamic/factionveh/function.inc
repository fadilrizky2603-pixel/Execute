function LoadSvpoint(playerid)
{
	static svid;

	new rows = cache_num_rows();
	if(rows)
	{
		for(new i = 0; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", svid);
			cache_get_value_name_int(i, "type", svData[svid][svType]);
			cache_get_value_name_float(i, "posx", svData[svid][svPosX]);
			cache_get_value_name_float(i, "posy", svData[svid][svPosY]);
			cache_get_value_name_float(i, "posz", svData[svid][svPosZ]);
			cache_get_value_name_float(i, "posa", svData[svid][svPosA]);
			cache_get_value_name_int(i, "world", svData[svid][svVw]);
			cache_get_value_name_int(i, "interior", svData[svid][svInt]);

			Svpoint_Refresh(svid);
			Iter_Add(SVPoint, svid);
		}
		printf("[DATABASE] Number of faction vehicle Loaded: %d.", rows);
		//Profiler_Stop();
	}
}

function OnSvpointCreated(svid)
{
	Svpoint_Save(svid);
	return 1;
}