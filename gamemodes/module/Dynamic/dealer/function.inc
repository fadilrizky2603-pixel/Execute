function LoadDealer()
{
    static deid;
	
	new rows = cache_num_rows(), owner[128], name[128];
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", deid);
			cache_get_value_name(i, "owner", owner);
			format(drData[deid][dOwner], 128, owner);
			cache_get_value_name(i, "name", name);
			format(drData[deid][dName], 128, name);
			cache_get_value_name_int(i, "price", drData[deid][dPrice]);
			cache_get_value_name_int(i, "type", drData[deid][dType]);
			cache_get_value_name_float(i, "posx", drData[deid][dPosX]);
			cache_get_value_name_float(i, "posy", drData[deid][dPosY]);
			cache_get_value_name_float(i, "posz", drData[deid][dPosZ]);
			cache_get_value_name_float(i, "posa", drData[deid][dPosA]);
			cache_get_value_name_int(i, "posint", drData[deid][dInt]);
			cache_get_value_name_int(i, "posvw", drData[deid][dVW]);

			cache_get_value_name_float(i, "vehx", drData[deid][dVehX]);
			cache_get_value_name_float(i, "vehy", drData[deid][dVehY]);
			cache_get_value_name_float(i, "vehz", drData[deid][dVehZ]);
			cache_get_value_name_float(i, "veha", drData[deid][dVehA]);
			cache_get_value_name_int(i, "vehint", drData[deid][dVehInt]);
			cache_get_value_name_int(i, "vehvw", drData[deid][dVehVW]);

			cache_get_value_name_int(i, "locked", drData[deid][dLock]);
			cache_get_value_name_int(i, "money", drData[deid][dMoney]);
			cache_get_value_name_int(i, "stock", drData[deid][dStock]);
			cache_get_value_name_int(i, "visit", drData[deid][dVisit]);

			cache_get_value_name_int(i, "vehprice0", drData[deid][dP][0]);
			cache_get_value_name_int(i, "vehprice1", drData[deid][dP][1]);
			cache_get_value_name_int(i, "vehprice2", drData[deid][dP][2]);
			cache_get_value_name_int(i, "vehprice3", drData[deid][dP][3]);
			cache_get_value_name_int(i, "vehprice4", drData[deid][dP][4]);
			cache_get_value_name_int(i, "vehprice5", drData[deid][dP][5]);
			cache_get_value_name_int(i, "vehprice6", drData[deid][dP][6]);
			cache_get_value_name_int(i, "vehprice7", drData[deid][dP][7]);
			cache_get_value_name_int(i, "vehprice8", drData[deid][dP][8]);
			cache_get_value_name_int(i, "vehprice9", drData[deid][dP][9]);
			cache_get_value_name_int(i, "vehprice10", drData[deid][dP][10]);
			cache_get_value_name_int(i, "vehprice11", drData[deid][dP][11]);
			cache_get_value_name_int(i, "vehprice12", drData[deid][dP][12]);
			cache_get_value_name_int(i, "vehprice13", drData[deid][dP][13]);
			cache_get_value_name_int(i, "vehprice14", drData[deid][dP][14]);
			cache_get_value_name_int(i, "vehprice15", drData[deid][dP][15]);
			cache_get_value_name_int(i, "vehprice16", drData[deid][dP][16]);
			cache_get_value_name_int(i, "vehprice17", drData[deid][dP][17]);
			cache_get_value_name_int(i, "vehprice18", drData[deid][dP][18]);
			cache_get_value_name_int(i, "vehprice19", drData[deid][dP][19]);
			cache_get_value_name_int(i, "vehprice20", drData[deid][dP][20]);
			cache_get_value_name_int(i, "vehprice21", drData[deid][dP][21]);
			Dealer_Refresh(deid);
			Iter_Add(Dealer, deid);
		}
		printf("[Dealer Business] Number of Loaded: %d.", rows);
		//Profiler_Stop();
	}
}