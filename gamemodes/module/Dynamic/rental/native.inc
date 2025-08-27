Rental_Save(id)
{
	new cQuery[2248];
	format(cQuery, sizeof(cQuery), "UPDATE rental SET type='%d', price='%d', extposx='%f', extposy='%f', extposz='%f', extposa='%f', vehposx='%f', vehposy='%f', vehposz='%f', vehposa='%f' WHERE id='%d'",
	rnData[id][rType],
	rnData[id][rPrice],
	rnData[id][rExtposX],
	rnData[id][rExtposY],
	rnData[id][rExtposZ],
	rnData[id][rExtposA],
	rnData[id][rVehposX],
	rnData[id][rVehposY],
	rnData[id][rVehposZ],
	rnData[id][rVehposA],
	id);

	return mysql_tquery(g_SQL, cQuery);
}

Rental_BuyMenu(playerid, rentalid)
{
    if(rentalid <= -1 )
        return 0;

    switch(rnData[rentalid][rType])
    {
        case 1:
        {
			if(rnData[rentalid][rVehposX] == 0 && rnData[rentalid][rVehposY] == 0 && rnData[rentalid][rVehposZ] == 0)
				return Error(playerid, "Rental ini belum memiliki spawn point kendaraan.");

			new str[1024];
			format(str, sizeof(str), ""WHITE_E"%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days",
			GetVehicleModelName(509), 
			FormatMoney(rnData[rentalid][rPrice]),
			GetVehicleModelName(481),
			FormatMoney(rnData[rentalid][rPrice]),
			GetVehicleModelName(510),
			FormatMoney(rnData[rentalid][rPrice])
			);

			ShowPlayerDialog(playerid, DIALOG_RENTBIKES, DIALOG_STYLE_LIST, "Rent Bikes", str, "Rent", "Close");
        }
        case 2:
        {
			if(rnData[rentalid][rVehposX] == 0 && rnData[rentalid][rVehposY] == 0 && rnData[rentalid][rVehposZ] == 0)
				return Error(playerid, "Rental ini belum memiliki spawn point kendaraan.");

			new str[1024];
			format(str, sizeof(str), ""WHITE_E"%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days",
			GetVehicleModelName(453), 
			FormatMoney(rnData[rentalid][rPrice]),
			GetVehicleModelName(454),
			FormatMoney(rnData[rentalid][rPrice]),
			GetVehicleModelName(484),
			FormatMoney(rnData[rentalid][rPrice]),
			GetVehicleModelName(595),
			FormatMoney(rnData[rentalid][rPrice])
			);

			ShowPlayerDialog(playerid, DIALOG_RENTBOAT, DIALOG_STYLE_LIST, "Rent Boat", str, "Rent", "Close");
        }
    }
    return 	1;
}

Rental_Refresh(id)
{
    if(id != -1)
    {
    	if(IsValidDynamicPickup(rnData[id][rPickup]))
            DestroyDynamicPickup(rnData[id][rPickup]);

        if(IsValidDynamic3DTextLabel(rnData[id][rLabel]))
            DestroyDynamic3DTextLabel(rnData[id][rLabel]);

        static
        string[255], type[128];

        if(rnData[id][rType] == 1)
        {
        	type = "Bikes";
        }
        else if(rnData[id][rType] == 2)
        {
        	type = "Boat";
        }
        else
        {
        	type = "Unknown";
        }
		format(string, sizeof(string), "ID: %d\nType: %s\n{FFFF00}/rentveh {FFFFFF}untuk menyewa kendaraan", id, type);
		rnData[id][rLabel] = CreateDynamic3DTextLabel(string, -1, rnData[id][rExtposX], rnData[id][rExtposY], rnData[id][rExtposZ]+0.5, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    }
    return 1;
}