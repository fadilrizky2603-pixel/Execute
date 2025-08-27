function LoadVending()
{
    new rows = cache_num_rows();
 	if(rows)
  	{
   		new venid, owner[MAX_PLAYER_NAME];
		for(new i; i < rows; i++)
		{
  			cache_get_value_name_int(i, "ID", venid);
		    cache_get_value_name(i, "owner", owner);
			format(vmData[venid][venOwner], MAX_PLAYER_NAME, owner);
			cache_get_value_name_int(i, "price", vmData[venid][venPrice]);
		    cache_get_value_name_float(i, "posx", vmData[venid][venX]);
		    cache_get_value_name_float(i, "posy", vmData[venid][venY]);
		    cache_get_value_name_float(i, "posz", vmData[venid][venZ]);
		   	cache_get_value_name_float(i, "posrx", vmData[venid][venRX]);
		    cache_get_value_name_float(i, "posry", vmData[venid][venRY]);
		    cache_get_value_name_float(i, "posrz", vmData[venid][venRZ]);
		    cache_get_value_name_int(i, "interior", vmData[venid][venInt]);
			cache_get_value_name_int(i, "world", vmData[venid][venWorld]);
			cache_get_value_name_int(i, "money", vmData[venid][venMoney]);
			cache_get_value_name_int(i, "drinkprice", vmData[venid][venDrinkPrice]);
			cache_get_value_name_int(i, "product", vmData[venid][venProduct]);
			cache_get_value_name_int(i, "visit", vmData[venid][venVisit]);

			Vending_Refresh(venid);
			Iter_Add(Vending, venid);
	    }
	    printf("[DATABASE] Number of vending loaded: %d.", rows);
		//Profiler_Stop();
	}
}

function OnVendingCreated(venid)
{
	Vending_Save(venid);
	return 1;
}