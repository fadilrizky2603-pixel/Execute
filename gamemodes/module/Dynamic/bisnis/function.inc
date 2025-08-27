function LoadBisnis()
{
    static bid;
	
	new rows = cache_num_rows(), owner[128], name[128];
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "ID", bid);
			cache_get_value_name(i, "owner", owner);
			format(bData[bid][bOwner], 128, owner);
			cache_get_value_name_int(i, "ownerid", bData[bid][bOwnerID]);
			cache_get_value_name(i, "name", name);
			format(bData[bid][bName], 128, name);
			cache_get_value_name_int(i, "type", bData[bid][bType]);
			cache_get_value_name_int(i, "price", bData[bid][bPrice]);
			cache_get_value_name_float(i, "extposx", bData[bid][bExtposX]);
			cache_get_value_name_float(i, "extposy", bData[bid][bExtposY]);
			cache_get_value_name_float(i, "extposz", bData[bid][bExtposZ]);
			cache_get_value_name_float(i, "extposa", bData[bid][bExtposA]);
			cache_get_value_name_int(i, "money", bData[bid][bMoney]);
			cache_get_value_name_int(i, "locked", bData[bid][bLocked]);
			cache_get_value_name_int(i, "prod", bData[bid][bProd]);
			cache_get_value_name_int(i, "bprice0", bData[bid][bP][0]);
			cache_get_value_name_int(i, "bprice1", bData[bid][bP][1]);
			cache_get_value_name_int(i, "bprice2", bData[bid][bP][2]);
			cache_get_value_name_int(i, "bprice3", bData[bid][bP][3]);
			cache_get_value_name_int(i, "bprice4", bData[bid][bP][4]);
			cache_get_value_name_int(i, "bprice5", bData[bid][bP][5]);
			cache_get_value_name_int(i, "bprice6", bData[bid][bP][6]);
			cache_get_value_name_int(i, "bprice7", bData[bid][bP][7]);
			cache_get_value_name_int(i, "bprice8", bData[bid][bP][8]);
			cache_get_value_name_int(i, "bprice9", bData[bid][bP][9]);
			cache_get_value_name_int(i, "visit", bData[bid][bVisit]);
			cache_get_value_name_int(i, "restock", bData[bid][bRestock]);
			Bisnis_Refresh(bid);
			Iter_Add(Bisnis, bid);
		}
		printf("[DATABASE] Number Of Bisnis Loaded:  %d", rows);
		//Profiler_Dump();
	}
}