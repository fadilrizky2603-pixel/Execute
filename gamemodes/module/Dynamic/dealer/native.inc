Dealer_Save(id)
{
	new cQuery[2248];
	format(cQuery, sizeof(cQuery), "UPDATE dealer SET owner='%s', name='%s', price='%d', type='%d', posx='%f', posy='%f', posz='%f', posa='%f', posint='%d', posvw='%d', vehx='%f', vehy='%f', vehz='%f', veha='%f', vehint='%d', vehvw='%d', locked='%d', money='%d', stock='%d', visit='%d'",
	drData[id][dOwner],
	drData[id][dName],
	drData[id][dPrice],
	drData[id][dType],
	drData[id][dPosX],
	drData[id][dPosY],
	drData[id][dPosZ],
	drData[id][dPosA],
	drData[id][dInt],
	drData[id][dVW],
	drData[id][dVehX],
	drData[id][dVehY],
	drData[id][dVehZ],
	drData[id][dVehA],
	drData[id][dVehInt],
	drData[id][dVehVW],
	drData[id][dLock],
	drData[id][dMoney],
	drData[id][dStock],
	drData[id][dVisit]
	);

	format(cQuery, sizeof(cQuery),"%s, vehprice0='%d', vehprice1='%d', vehprice2='%d', vehprice3='%d', vehprice4='%d', vehprice5='%d', vehprice6='%d', vehprice7='%d', vehprice8='%d', vehprice9='%d', vehprice10='%d', vehprice11='%d', vehprice12='%d', vehprice13='%d', vehprice14='%d', vehprice15='%d', vehprice16='%d', vehprice17='%d', vehprice18='%d', vehprice19='%d', vehprice20='%d', vehprice21='%d' WHERE id='%d'",
	cQuery,
	drData[id][dP][0],
	drData[id][dP][1],
	drData[id][dP][2],
	drData[id][dP][3],
	drData[id][dP][4],
	drData[id][dP][5],
	drData[id][dP][6],
	drData[id][dP][7],
	drData[id][dP][8],
	drData[id][dP][9],
	drData[id][dP][10],
	drData[id][dP][11],
	drData[id][dP][12],
	drData[id][dP][13],
	drData[id][dP][14],
	drData[id][dP][15],
	drData[id][dP][16],
	drData[id][dP][17],
	drData[id][dP][18],
	drData[id][dP][19],
	drData[id][dP][20],
	drData[id][dP][21],
	id);
	return mysql_tquery(g_SQL, cQuery);
}

Dealer_Refresh(id)
{
    if(id != -1)
    {
    	if(IsValidDynamicPickup(drData[id][dPickup]))
    		DestroyDynamicPickup(drData[id][dPickup]);

    	if(IsValidDynamic3DTextLabel(drData[id][dLabel]))
    		DestroyDynamic3DTextLabel(drData[id][dLabel]);
    	
    	if(IsValidDynamicMapIcon(drData[id][dIcon]))
    		DestroyDynamicMapIcon(drData[id][dIcon]);

    	if(IsValidDynamic3DTextLabel(drData[id][dLabelSpawn]))
    		DestroyDynamic3DTextLabel(drData[id][dLabelSpawn]);

    	static
    	string[1024], str[1024];

    	new type[128], statusstock[128], stts[128];
    	if(drData[id][dType] == 1)
    	{
    		type = "Bikes Vehicles";
    	}
    	else if(drData[id][dType] == 2)
    	{
    		type = "Cars";
    	}
    	else if(drData[id][dType] == 3)
    	{
    		type = "Unique Cars";
    	}
    	else if(drData[id][dType] == 4)
    	{
    		type = "Jobs Vehicles";
    	}
    	else if(drData[id][dType] == 5)
    	{
    		type = "Rental Jobs";
    	}
    	else
    	{
    		type = "{FF0000}Unknown{FFFFFF}";
    	}
    	if(drData[id][dStock] <= 0)
    	{
    		statusstock = "{FF0000}OUT OF STOCK{FFFFFF}";
    	}
    	else
    	{
    		format(stts, sizeof(stts), "%d", drData[id][dStock]);
    		statusstock = stts;
    	}
    	if(strcmp(drData[id][dOwner], "-"))
		{
			format(string, sizeof(string), "[DEALER ID: %d]\n"WHITE_E"Dealer Stock: "GREEN_LIGHT"%s\n{FF0000}"WHITE_E"Dealer Name: "GREEN_LIGHT"%s\n"WHITE_E"Dealer Type: "GREEN_LIGHT"%s\n"WHITE_E"Dealer Location: "GREEN_LIGHT"%s\n"WHITE_E"Owned by %s\n"WHITE_E"/buyveh - to buy vehicle", id, statusstock, drData[id][dName], type, GetLocation(drData[id][dPosX], drData[id][dPosY], drData[id][dPosZ]), drData[id][dOwner]);
			drData[id][dPickup] = CreateDynamicPickup(1239, 23, drData[id][dPosX], drData[id][dPosY], drData[id][dPosZ], drData[id][dVW], drData[id][dInt], _, 15.0);
		}
		else
		{
			format(string, sizeof(string), "[DEALER ID: %d]\n"WHITE_E"this dealer for sell\n"WHITE_E"Dealer Stock: "GREEN_LIGHT"%s\n"WHITE_E"Dealer Type: "GREEN_LIGHT"%s\n"WHITE_E"Dealer Location: "GREEN_LIGHT"%s\n"WHITE_E"Dealer Price: "GREEN_LIGHT"%s"WHITE_E"\n/buyveh - to buy vehicle\n"WHITE_E"/buy - to buy this dealer", id, statusstock, type, GetLocation(drData[id][dPosX], drData[id][dPosY], drData[id][dPosZ]), FormatMoney(drData[id][dPrice]));
			drData[id][dPickup] = CreateDynamicPickup(1239, 23, drData[id][dPosX], drData[id][dPosY], drData[id][dPosZ], drData[id][dVW], drData[id][dInt], _, 15.0);
		}
		format(str, sizeof(str), "[SPAWN DEALER: %d]\n"WHITE_E"the place where the dealer's vehicle appears", id);
		drData[id][dLabel] = CreateDynamic3DTextLabel(string, COLOR_YELLOW, drData[id][dPosX], drData[id][dPosY], drData[id][dPosZ]+0.5, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, drData[id][dVW], drData[id][dInt]);
		drData[id][dLabelSpawn] = CreateDynamic3DTextLabel(str, COLOR_YELLOW, drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ]+0.5, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, drData[id][dVehVW], drData[id][dVehInt]);
		drData[id][dIcon] = CreateDynamicMapIcon(drData[id][dVehX], drData[id][dVehY], drData[id][dVehZ], 55, -1, -1, -1, -1, 50.0);
    }
    return 1;
}

Player_DealerCount(playerid)
{
	#if LIMIT_PER_PLAYER != 0
    new count;
	foreach(new i : Dealer)
	{
		if(Player_OwnsDealer(playerid, i)) count++;
	}

	return count;
	#else
	return 0;
	#endif
}

Dealer_SetPrice(id)
{
	if(id != -1)
	{
		if(drData[id][dType] == 1) //Bikes
		{
			drData[id][dP][0] = 450;
			drData[id][dP][1] = 400;
			drData[id][dP][2] = 450;
			drData[id][dP][3] = 550;
			drData[id][dP][4] = 1100;
			drData[id][dP][5] = 1200;
			drData[id][dP][6] = 1275;
			drData[id][dP][7] = 1250;
			drData[id][dP][8] = 1080;
			drData[id][dP][9] = 750;
			drData[id][dP][10] = 0;
			drData[id][dP][11] = 0;
			drData[id][dP][12] = 0;
			drData[id][dP][13] = 0;
			drData[id][dP][14] = 0;
			drData[id][dP][15] = 0;
			drData[id][dP][16] = 0;
			drData[id][dP][17] = 0;
			drData[id][dP][18] = 0;
			drData[id][dP][19] = 0;
			drData[id][dP][20] = 0;
			drData[id][dP][21] = 0;
		}
		else if(drData[id][dType] == 2) //Cars
		{
			drData[id][dP][0] = 1350;
			drData[id][dP][1] =	1300;
			drData[id][dP][2] = 1420;
			drData[id][dP][3] = 1400;
			drData[id][dP][4] = 1380;
			drData[id][dP][5] = 1330;
			drData[id][dP][6] = 2000;
			drData[id][dP][7] = 1320;
			drData[id][dP][8] = 1345;
			drData[id][dP][9] = 2235;
			drData[id][dP][10] = 2250;
			drData[id][dP][11] = 2310;
			drData[id][dP][12] = 2230;
			drData[id][dP][13] = 1350;
			drData[id][dP][14] = 1370;
			drData[id][dP][15] = 2100;
			drData[id][dP][16] = 2700;
			drData[id][dP][17] = 2500;
			drData[id][dP][18] = 2400;
			drData[id][dP][19] = 2000;
			drData[id][dP][20] = 0;
			drData[id][dP][21] = 0;
		}
		else if(drData[id][dType] == 3) //Unique Cars
		{
			drData[id][dP][0] = 2450;
			drData[id][dP][1] = 1450;
			drData[id][dP][2] = 2000;
			drData[id][dP][3] = 4300;
			drData[id][dP][4] = 4500;
			drData[id][dP][5] = 4750;
			drData[id][dP][6] = 3300;
			drData[id][dP][7] = 4650;
			drData[id][dP][8] = 2100;
			drData[id][dP][9] = 2300;
			drData[id][dP][10] = 2350;
			drData[id][dP][11] = 1750;
			drData[id][dP][12] = 0;
			drData[id][dP][13] = 0;
			drData[id][dP][14] = 0;
			drData[id][dP][15] = 0;
			drData[id][dP][16] = 0;
			drData[id][dP][17] = 0;
			drData[id][dP][18] = 0;
			drData[id][dP][19] = 0;
			drData[id][dP][20] = 0;
			drData[id][dP][21] = 0;

		}
		else if(drData[id][dType] == 4) //Job Cars
		{
			drData[id][dP][0] = 1550;
			drData[id][dP][1] = 1500;
			drData[id][dP][2] = 3200;
			drData[id][dP][3] = 1475;
			drData[id][dP][4] = 1456;
			drData[id][dP][5] = 1487;
			drData[id][dP][6] = 1320;
			drData[id][dP][7] = 1980;
			drData[id][dP][8] = 1980;
			drData[id][dP][9] = 1980;
			drData[id][dP][10] = 1476;
			drData[id][dP][11] = 1476;
			drData[id][dP][12] = 1476;
			drData[id][dP][13] = 1476;
			drData[id][dP][14] = 1476;
			drData[id][dP][15] = 1750;
			drData[id][dP][16] = 1476;
			drData[id][dP][17] = 1476;
			drData[id][dP][18] = 1320;
			drData[id][dP][19] = 1320;
			drData[id][dP][20] = 1476;
			drData[id][dP][21] = 0;
		}
		else if(drData[id][dType] == 5) //Rental Jobs
		{
			drData[id][dP][0] = 350;
			drData[id][dP][1] = 350;
			drData[id][dP][2] = 350;
			drData[id][dP][3] = 350;
			drData[id][dP][4] = 350;
			drData[id][dP][5] = 350;
			drData[id][dP][6] = 350;
			drData[id][dP][7] = 350;
			drData[id][dP][8] = 350;
			drData[id][dP][9] = 350;
			drData[id][dP][10] = 350;
			drData[id][dP][11] = 350;
			drData[id][dP][12] = 350;
			drData[id][dP][13] = 350;
			drData[id][dP][14] = 0;
			drData[id][dP][15] = 0;
			drData[id][dP][16] = 0;
			drData[id][dP][17] = 0;
			drData[id][dP][18] = 0;
			drData[id][dP][19] = 0;
			drData[id][dP][20] = 0;
			drData[id][dP][21] = 0;
		}
		else //Invalid Type ID
		{
			drData[id][dP][0] = 0;
			drData[id][dP][1] = 0;
			drData[id][dP][2] = 0;
			drData[id][dP][3] = 0;
			drData[id][dP][4] = 0;
			drData[id][dP][5] = 0;
			drData[id][dP][6] = 0;
			drData[id][dP][7] = 0;
			drData[id][dP][8] = 0;
			drData[id][dP][9] = 0;
			drData[id][dP][10] = 0;
			drData[id][dP][11] = 0;
			drData[id][dP][12] = 0;
			drData[id][dP][13] = 0;
			drData[id][dP][14] = 0;
			drData[id][dP][15] = 0;
			drData[id][dP][16] = 0;
			drData[id][dP][17] = 0;
			drData[id][dP][18] = 0;
			drData[id][dP][19] = 0;
			drData[id][dP][20] = 0;
			drData[id][dP][21] = 0;
		}
	}
	return 1;
}

Dealer_BuyMenu(playerid, deid)
{
    if(deid != -1)
    {
	    switch (drData[deid][dType])
	    {
	        case 1:
	        {
	            if(pData[playerid][pGetDEID] == -1)
					return Error(playerid, "Ada kesalahan penginputan pada data kamu, kamu harus relog.");

				if(drData[deid][dVehX] == 0 && drData[deid][dVehY] == 0 && drData[deid][dVehZ] == 0)
					return Error(playerid, "Dealer ini belum memiliki spawn point kendaraan.");

				if(drData[deid][dStock] <= 0)
					return Error(playerid, "Dealer ini kehabisan stock.");

				//Bikes
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"%s\t\t"LG_E"%s\n%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n", 
				GetVehicleModelName(481), FormatMoney(drData[deid][dP][0]), 
				GetVehicleModelName(509), FormatMoney(drData[deid][dP][1]),
				GetVehicleModelName(510), FormatMoney(drData[deid][dP][2]),
				GetVehicleModelName(462), FormatMoney(drData[deid][dP][3]),
				GetVehicleModelName(586), FormatMoney(drData[deid][dP][4]),
				GetVehicleModelName(581), FormatMoney(drData[deid][dP][5]),
				GetVehicleModelName(461), FormatMoney(drData[deid][dP][6]),
				GetVehicleModelName(521), FormatMoney(drData[deid][dP][7]),
				GetVehicleModelName(463), FormatMoney(drData[deid][dP][8]),
				GetVehicleModelName(468), FormatMoney(drData[deid][dP][9])
				);
						
				ShowPlayerDialog(playerid, DIALOG_BUYPVCP_BIKES, DIALOG_STYLE_LIST, "Bikes", str, "Buy", "Close");
	        }
	        case 2:
	        {
	        	if(pData[playerid][pGetDEID] == -1)
					return Error(playerid, "Ada kesalahan penginputan pada data kamu, kamu harus relog.");

				if(drData[deid][dVehX] == 0 && drData[deid][dVehY] == 0 && drData[deid][dVehZ] == 0)
					return Error(playerid, "Dealer ini belum memiliki spawn point kendaraan.");

				if(drData[deid][dStock] <= 0)
					return Error(playerid, "Dealer ini kehabisan stock.");

	           	//Cars
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n", 
				GetVehicleModelName(400), FormatMoney(drData[deid][dP][0]), 
				GetVehicleModelName(412), FormatMoney(drData[deid][dP][1]),
				GetVehicleModelName(419), FormatMoney(drData[deid][dP][2]),
				GetVehicleModelName(426), FormatMoney(drData[deid][dP][3]),
				GetVehicleModelName(436), FormatMoney(drData[deid][dP][4]),
				GetVehicleModelName(466), FormatMoney(drData[deid][dP][5]),
				GetVehicleModelName(467), FormatMoney(drData[deid][dP][6]),
				GetVehicleModelName(474), FormatMoney(drData[deid][dP][7]),
				GetVehicleModelName(475), FormatMoney(drData[deid][dP][8]),
				GetVehicleModelName(480), FormatMoney(drData[deid][dP][9]),
				GetVehicleModelName(603), FormatMoney(drData[deid][dP][10]),
				GetVehicleModelName(421), FormatMoney(drData[deid][dP][11]),
				GetVehicleModelName(602), FormatMoney(drData[deid][dP][12]),
				GetVehicleModelName(492), FormatMoney(drData[deid][dP][13]),
				GetVehicleModelName(545), FormatMoney(drData[deid][dP][14]),
				GetVehicleModelName(489), FormatMoney(drData[deid][dP][15]),
				GetVehicleModelName(405), FormatMoney(drData[deid][dP][16]),
				GetVehicleModelName(445), FormatMoney(drData[deid][dP][17]),
				GetVehicleModelName(579), FormatMoney(drData[deid][dP][18]),
				GetVehicleModelName(507), FormatMoney(drData[deid][dP][19])
				);
						
				ShowPlayerDialog(playerid, DIALOG_BUYPVCP_CARS, DIALOG_STYLE_LIST, "Cars", str, "Buy", "Close");
	        }
	        case 3:
	        {
	        	if(pData[playerid][pGetDEID] == -1)
					return Error(playerid, "Ada kesalahan penginputan pada data kamu, kamu harus relog.");

				if(drData[deid][dVehX] == 0 && drData[deid][dVehY] == 0 && drData[deid][dVehZ] == 0)
					return Error(playerid, "Dealer ini belum memiliki spawn point kendaraan.");

				if(drData[deid][dStock] <= 0)
					return Error(playerid, "Dealer ini kehabisan stock.");

				//Unique Cars
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n", 
				GetVehicleModelName(483), FormatMoney(drData[deid][dP][0]), 
				GetVehicleModelName(535), FormatMoney(drData[deid][dP][1]),
				GetVehicleModelName(536), FormatMoney(drData[deid][dP][2]),
				GetVehicleModelName(558), FormatMoney(drData[deid][dP][3]),
				GetVehicleModelName(559), FormatMoney(drData[deid][dP][4]),
				GetVehicleModelName(560), FormatMoney(drData[deid][dP][5]),
				GetVehicleModelName(561), FormatMoney(drData[deid][dP][6]),
				GetVehicleModelName(562), FormatMoney(drData[deid][dP][7]),
				GetVehicleModelName(565), FormatMoney(drData[deid][dP][8]),
				GetVehicleModelName(567), FormatMoney(drData[deid][dP][9]),
				GetVehicleModelName(575), FormatMoney(drData[deid][dP][10]),
				GetVehicleModelName(576), FormatMoney(drData[deid][dP][11])
				);
				
				ShowPlayerDialog(playerid, DIALOG_BUYPVCP_UCARS, DIALOG_STYLE_LIST, "Unique Cars", str, "Buy", "Close");
	        }
	        case 4:
	        {
	        	if(pData[playerid][pGetDEID] == -1)
					return Error(playerid, "Ada kesalahan penginputan pada data kamu, kamu harus relog.");

				if(drData[deid][dVehX] == 0 && drData[deid][dVehY] == 0 && drData[deid][dVehZ] == 0)
					return Error(playerid, "Dealer ini belum memiliki spawn point kendaraan.");

				if(drData[deid][dStock] <= 0)
					return Error(playerid, "Dealer ini kehabisan stock.");
				
				//Job Cars
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s", 
				GetVehicleModelName(420), FormatMoney(drData[deid][dP][0]), 
				GetVehicleModelName(438), FormatMoney(drData[deid][dP][1]), 
				GetVehicleModelName(403), FormatMoney(drData[deid][dP][2]), 
				GetVehicleModelName(413), FormatMoney(drData[deid][dP][3]),
				GetVehicleModelName(414), FormatMoney(drData[deid][dP][4]),
				GetVehicleModelName(422), FormatMoney(drData[deid][dP][5]),
				GetVehicleModelName(440), FormatMoney(drData[deid][dP][6]),
				GetVehicleModelName(455), FormatMoney(drData[deid][dP][7]),
				GetVehicleModelName(456), FormatMoney(drData[deid][dP][8]),
				GetVehicleModelName(478), FormatMoney(drData[deid][dP][9]),
				GetVehicleModelName(482), FormatMoney(drData[deid][dP][10]),
				GetVehicleModelName(498), FormatMoney(drData[deid][dP][11]),
				GetVehicleModelName(499), FormatMoney(drData[deid][dP][12]),
				GetVehicleModelName(423), FormatMoney(drData[deid][dP][13]),
				GetVehicleModelName(588), FormatMoney(drData[deid][dP][14]),
				GetVehicleModelName(524), FormatMoney(drData[deid][dP][15]),
				GetVehicleModelName(525), FormatMoney(drData[deid][dP][16]),
				GetVehicleModelName(543), FormatMoney(drData[deid][dP][17]),
				GetVehicleModelName(552), FormatMoney(drData[deid][dP][18]),
				GetVehicleModelName(554), FormatMoney(drData[deid][dP][19]),
				GetVehicleModelName(578), FormatMoney(drData[deid][dP][20]),
				GetVehicleModelName(609), FormatMoney(drData[deid][dP][21])
				//GetVehicleModelName(530), FormatMoney(530)) //fortklift
				);
						
				ShowPlayerDialog(playerid, DIALOG_BUYPVCP_JOBCARS, DIALOG_STYLE_LIST, "Job Cars", str, "Buy", "Close");
	        }
	        case 5:
	        {
	        	if(pData[playerid][pGetDEID] == -1)
					return Error(playerid, "Ada kesalahan penginputan pada data kamu, kamu harus relog.");

				if(drData[deid][dVehX] == 0 && drData[deid][dVehY] == 0 && drData[deid][dVehZ] == 0)
					return Error(playerid, "Dealer ini belum memiliki spawn point kendaraan.");

				if(drData[deid][dStock] <= 0)
					return Error(playerid, "Dealer ini kehabisan stock.");
				
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days",
				GetVehicleModelName(414),
				FormatMoney(drData[deid][dP][0]),
				GetVehicleModelName(455),
				FormatMoney(drData[deid][dP][1]), 
				GetVehicleModelName(456),
				FormatMoney(drData[deid][dP][2]),
				GetVehicleModelName(498),
				FormatMoney(drData[deid][dP][3]),
				GetVehicleModelName(499),
				FormatMoney(drData[deid][dP][4]),
				GetVehicleModelName(609),
				FormatMoney(drData[deid][dP][5]),
				GetVehicleModelName(478),
				FormatMoney(drData[deid][dP][6]),
				GetVehicleModelName(422),
				FormatMoney(drData[deid][dP][7]),
				GetVehicleModelName(543),
				FormatMoney(drData[deid][dP][8]),
				GetVehicleModelName(554),
				FormatMoney(drData[deid][dP][9]),
				GetVehicleModelName(525),
				FormatMoney(drData[deid][dP][10]),
				GetVehicleModelName(438),
				FormatMoney(drData[deid][dP][11]),
				GetVehicleModelName(420),
				FormatMoney(drData[deid][dP][12]),
				GetVehicleModelName(403),
				FormatMoney(drData[deid][dP][13])
				);
						
				ShowPlayerDialog(playerid, DIALOG_RENT_JOBCARS, DIALOG_STYLE_LIST, "Rent Job Cars", str, "Rent", "Close");
			}
	    }
	}
    return 1;
}

Dealer_ProductMenu(playerid, deid)
{
    if(deid != -1)
    {
	    switch (drData[deid][dType])
	    {
	        case 1:
	        {
	            if(pData[playerid][pGetDEID] == -1)
					return Error(playerid, "Ada kesalahan penginputan pada data kamu, kamu harus relog.");

				if(drData[deid][dVehX] == 0 && drData[deid][dVehY] == 0 && drData[deid][dVehZ] == 0)
					return Error(playerid, "Dealer ini belum memiliki spawn point kendaraan.");

				if(drData[deid][dStock] <= 0)
					return Error(playerid, "Dealer ini kehabisan stock.");

				//Bikes
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"%s\t\t"LG_E"%s\n%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n", 
				GetVehicleModelName(481), FormatMoney(drData[deid][dP][0]), 
				GetVehicleModelName(509), FormatMoney(drData[deid][dP][1]),
				GetVehicleModelName(510), FormatMoney(drData[deid][dP][2]),
				GetVehicleModelName(462), FormatMoney(drData[deid][dP][3]),
				GetVehicleModelName(586), FormatMoney(drData[deid][dP][4]),
				GetVehicleModelName(581), FormatMoney(drData[deid][dP][5]),
				GetVehicleModelName(461), FormatMoney(drData[deid][dP][6]),
				GetVehicleModelName(521), FormatMoney(drData[deid][dP][7]),
				GetVehicleModelName(463), FormatMoney(drData[deid][dP][8]),
				GetVehicleModelName(468), FormatMoney(drData[deid][dP][9])
				);
						
				ShowPlayerDialog(playerid, DEALER_EDITPROD, DIALOG_STYLE_LIST, "Bikes", str, "Buy", "Close");
	        }
	        case 2:
	        {
	        	if(pData[playerid][pGetDEID] == -1)
					return Error(playerid, "Ada kesalahan penginputan pada data kamu, kamu harus relog.");

				if(drData[deid][dVehX] == 0 && drData[deid][dVehY] == 0 && drData[deid][dVehZ] == 0)
					return Error(playerid, "Dealer ini belum memiliki spawn point kendaraan.");

				if(drData[deid][dStock] <= 0)
					return Error(playerid, "Dealer ini kehabisan stock.");

	           	//Cars
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n", 
				GetVehicleModelName(400), FormatMoney(drData[deid][dP][0]), 
				GetVehicleModelName(412), FormatMoney(drData[deid][dP][1]),
				GetVehicleModelName(419), FormatMoney(drData[deid][dP][2]),
				GetVehicleModelName(426), FormatMoney(drData[deid][dP][3]),
				GetVehicleModelName(436), FormatMoney(drData[deid][dP][4]),
				GetVehicleModelName(466), FormatMoney(drData[deid][dP][5]),
				GetVehicleModelName(467), FormatMoney(drData[deid][dP][6]),
				GetVehicleModelName(474), FormatMoney(drData[deid][dP][7]),
				GetVehicleModelName(475), FormatMoney(drData[deid][dP][8]),
				GetVehicleModelName(480), FormatMoney(drData[deid][dP][9]),
				GetVehicleModelName(603), FormatMoney(drData[deid][dP][10]),
				GetVehicleModelName(421), FormatMoney(drData[deid][dP][11]),
				GetVehicleModelName(602), FormatMoney(drData[deid][dP][12]),
				GetVehicleModelName(492), FormatMoney(drData[deid][dP][13]),
				GetVehicleModelName(545), FormatMoney(drData[deid][dP][14]),
				GetVehicleModelName(489), FormatMoney(drData[deid][dP][15]),
				GetVehicleModelName(405), FormatMoney(drData[deid][dP][16]),
				GetVehicleModelName(445), FormatMoney(drData[deid][dP][17]),
				GetVehicleModelName(579), FormatMoney(drData[deid][dP][18]),
				GetVehicleModelName(507), FormatMoney(drData[deid][dP][19])
				);
						
				ShowPlayerDialog(playerid, DEALER_EDITPROD, DIALOG_STYLE_LIST, "Cars", str, "Buy", "Close");
	        }
	        case 3:
	        {
	        	if(pData[playerid][pGetDEID] == -1)
					return Error(playerid, "Ada kesalahan penginputan pada data kamu, kamu harus relog.");

				if(drData[deid][dVehX] == 0 && drData[deid][dVehY] == 0 && drData[deid][dVehZ] == 0)
					return Error(playerid, "Dealer ini belum memiliki spawn point kendaraan.");

				if(drData[deid][dStock] <= 0)
					return Error(playerid, "Dealer ini kehabisan stock.");

				//Unique Cars
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"%s\t\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n", 
				GetVehicleModelName(483), FormatMoney(drData[deid][dP][0]), 
				GetVehicleModelName(535), FormatMoney(drData[deid][dP][1]),
				GetVehicleModelName(536), FormatMoney(drData[deid][dP][2]),
				GetVehicleModelName(558), FormatMoney(drData[deid][dP][3]),
				GetVehicleModelName(559), FormatMoney(drData[deid][dP][4]),
				GetVehicleModelName(560), FormatMoney(drData[deid][dP][5]),
				GetVehicleModelName(561), FormatMoney(drData[deid][dP][6]),
				GetVehicleModelName(562), FormatMoney(drData[deid][dP][7]),
				GetVehicleModelName(565), FormatMoney(drData[deid][dP][8]),
				GetVehicleModelName(567), FormatMoney(drData[deid][dP][9]),
				GetVehicleModelName(575), FormatMoney(drData[deid][dP][10]),
				GetVehicleModelName(576), FormatMoney(drData[deid][dP][11])
				);
				
				ShowPlayerDialog(playerid, DEALER_EDITPROD, DIALOG_STYLE_LIST, "Unique Cars", str, "Buy", "Close");
	        }
	        case 4:
	        {
	        	if(pData[playerid][pGetDEID] == -1)
					return Error(playerid, "Ada kesalahan penginputan pada data kamu, kamu harus relog.");

				if(drData[deid][dVehX] == 0 && drData[deid][dVehY] == 0 && drData[deid][dVehZ] == 0)
					return Error(playerid, "Dealer ini belum memiliki spawn point kendaraan.");

				if(drData[deid][dStock] <= 0)
					return Error(playerid, "Dealer ini kehabisan stock.");
				
				//Job Cars
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s\n%s\t"LG_E"%s", 
				GetVehicleModelName(420), FormatMoney(drData[deid][dP][0]), 
				GetVehicleModelName(438), FormatMoney(drData[deid][dP][1]), 
				GetVehicleModelName(403), FormatMoney(drData[deid][dP][2]), 
				GetVehicleModelName(413), FormatMoney(drData[deid][dP][3]),
				GetVehicleModelName(414), FormatMoney(drData[deid][dP][4]),
				GetVehicleModelName(422), FormatMoney(drData[deid][dP][5]),
				GetVehicleModelName(440), FormatMoney(drData[deid][dP][6]),
				GetVehicleModelName(455), FormatMoney(drData[deid][dP][7]),
				GetVehicleModelName(456), FormatMoney(drData[deid][dP][8]),
				GetVehicleModelName(478), FormatMoney(drData[deid][dP][9]),
				GetVehicleModelName(482), FormatMoney(drData[deid][dP][10]),
				GetVehicleModelName(498), FormatMoney(drData[deid][dP][11]),
				GetVehicleModelName(499), FormatMoney(drData[deid][dP][12]),
				GetVehicleModelName(423), FormatMoney(drData[deid][dP][13]),
				GetVehicleModelName(588), FormatMoney(drData[deid][dP][14]),
				GetVehicleModelName(524), FormatMoney(drData[deid][dP][15]),
				GetVehicleModelName(525), FormatMoney(drData[deid][dP][16]),
				GetVehicleModelName(543), FormatMoney(drData[deid][dP][17]),
				GetVehicleModelName(552), FormatMoney(drData[deid][dP][18]),
				GetVehicleModelName(554), FormatMoney(drData[deid][dP][19]),
				GetVehicleModelName(578), FormatMoney(drData[deid][dP][20]),
				GetVehicleModelName(609), FormatMoney(drData[deid][dP][21])
				//GetVehicleModelName(530), FormatMoney(530)) //fortklift
				);
						
				ShowPlayerDialog(playerid, DEALER_EDITPROD, DIALOG_STYLE_LIST, "Job Cars", str, "Buy", "Close");
	        }
	        case 5:
	        {
	        	if(pData[playerid][pGetDEID] == -1)
					return Error(playerid, "Ada kesalahan penginputan pada data kamu, kamu harus relog.");

				if(drData[deid][dVehX] == 0 && drData[deid][dVehY] == 0 && drData[deid][dVehZ] == 0)
					return Error(playerid, "Dealer ini belum memiliki spawn point kendaraan.");

				if(drData[deid][dStock] <= 0)
					return Error(playerid, "Dealer ini kehabisan stock.");
				
				new str[1024];
				format(str, sizeof(str), ""WHITE_E"%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days\n%s\t"LG_E"%s / one days",
				GetVehicleModelName(414),
				FormatMoney(drData[deid][dP][0]),
				GetVehicleModelName(455),
				FormatMoney(drData[deid][dP][1]), 
				GetVehicleModelName(456),
				FormatMoney(drData[deid][dP][2]),
				GetVehicleModelName(498),
				FormatMoney(drData[deid][dP][3]),
				GetVehicleModelName(499),
				FormatMoney(drData[deid][dP][4]),
				GetVehicleModelName(609),
				FormatMoney(drData[deid][dP][5]),
				GetVehicleModelName(478),
				FormatMoney(drData[deid][dP][6]),
				GetVehicleModelName(422),
				FormatMoney(drData[deid][dP][7]),
				GetVehicleModelName(543),
				FormatMoney(drData[deid][dP][8]),
				GetVehicleModelName(554),
				FormatMoney(drData[deid][dP][9]),
				GetVehicleModelName(525),
				FormatMoney(drData[deid][dP][10]),
				GetVehicleModelName(438),
				FormatMoney(drData[deid][dP][11]),
				GetVehicleModelName(420),
				FormatMoney(drData[deid][dP][12]),
				GetVehicleModelName(403),
				FormatMoney(drData[deid][dP][13])
				);
				ShowPlayerDialog(playerid, DEALER_EDITPROD, DIALOG_STYLE_LIST, "Rent Job Cars", str, "Rent", "Close");
			}
	    }
   	}
    return 1;
}

Player_OwnsDealer(playerid, id)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(id == -1) return 0;
	if(!strcmp(drData[id][dOwner], pData[playerid][pName], true)) return 1;
	return 0;
}
