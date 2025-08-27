function LoadRental()
{
    static rnid;
	
	new rows = cache_num_rows();
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", rnid);
			cache_get_value_name_int(i, "type", rnData[rnid][rType]);
			cache_get_value_name_int(i, "price", rnData[rnid][rPrice]);
			cache_get_value_name_float(i, "extposx", rnData[rnid][rExtposX]);
			cache_get_value_name_float(i, "extposy", rnData[rnid][rExtposY]);
			cache_get_value_name_float(i, "extposz", rnData[rnid][rExtposZ]);
			cache_get_value_name_float(i, "extposa", rnData[rnid][rExtposA]);
			cache_get_value_name_float(i, "vehposx", rnData[rnid][rVehposX]);
			cache_get_value_name_float(i, "vehposy", rnData[rnid][rVehposY]);
			cache_get_value_name_float(i, "vehposz", rnData[rnid][rVehposZ]);
			cache_get_value_name_float(i, "vehposa", rnData[rnid][rVehposA]);
			Rental_Refresh(rnid);
			Iter_Add(Rental, rnid);
		}
		printf("[DATABASE] Number of rental Loaded: %d.", rows);
		//Profiler_Stop();
	}
}

//------------[ Bisnis Command ]------------
CMD:createrent(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
	
	new query[512];
	new rnid = Iter_Free(Rental), address[128];
	if(rnid == -1) return Error(playerid, "You cant create more door!");
	
	new type;
	if(sscanf(params, "dd", type))
	 return Usage(playerid, "/createrental [type 1.Rental Bikes 2.Rental Boat]");

	if(type < 0 || type > 2)
		return Error(playerid, "You have specified an invalid rental type 1 - 2.");

	GetPlayerPos(playerid, rnData[rnid][rExtposX], rnData[rnid][rExtposY], rnData[rnid][rExtposZ]);
	GetPlayerFacingAngle(playerid, rnData[rnid][rExtposA]);
	address = GetLocation(rnData[rnid][rExtposX], rnData[rnid][rExtposY], rnData[rnid][rExtposZ]);
	rnData[rnid][rType] = type;
	rnData[rnid][rPrice] = 25;

    Rental_Refresh(rnid);
	Iter_Add(Rental, rnid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO rental SET id='%d', type='%d', price='%d', extposx='%f', extposy='%f', extposz='%f', extposa='%f'", rnid, rnData[rnid][rType], rnData[rnid][rPrice], rnData[rnid][rExtposX], rnData[rnid][rExtposY], rnData[rnid][rExtposZ], rnData[rnid][rExtposA]);
	mysql_tquery(g_SQL, query, "OnRentalCreated", "i", rnid);
	return 1;
}

function OnRentalCreated(rnid)
{
	Rental_Save(rnid);
	return 1;
}