Svpoint_Save(svid)
{
	new cQuery[1024];
	format(cQuery, sizeof(cQuery), "UPDATE faction_vehpoint SET type = '%d', posx = '%f', posy = '%f', posz = '%f', posa = '%f', world = '%d', interior = '%d' WHERE id = '%d'",
	svData[svid][svType],
	svData[svid][svPosX],
	svData[svid][svPosY],
	svData[svid][svPosZ],
	svData[svid][svPosA],
	svData[svid][svVw],
	svData[svid][svInt],
	svid
	);
	return mysql_tquery(g_SQL, cQuery);
}

Svpoint_Refresh(svid)
{
	if(svid != -1)
	{
		if(IsValidDynamicPickup(svData[svid][svPickup]))
			DestroyDynamicPickup(svData[svid][svPickup]);

		if(IsValidDynamic3DTextLabel(svData[svid][svLabel]))
			DestroyDynamic3DTextLabel(svData[svid][svLabel]);

		new str[512], type[128];
		if(svData[svid][svType] == 1)
		{
			type = "Police Departement";
		}
		else if(svData[svid][svType] == 2)
		{
			type = "Goverment Services";
		}
		else if(svData[svid][svType] == 3)
		{
			type = "Medical Departement";
		}
		else if(svData[svid][svType] == 4)
		{
			type = "News Agency";
		}
		else if(svData[svid][svType] == 5)
		{
			type = "Cafe Food";
		}
		else 
		{
			type = "Unknown";
		}

		svData[svid][svPickup] = CreateDynamicPickup(1239, 23, svData[svid][svPosX], svData[svid][svPosY], svData[svid][svPosZ], svData[svid][svVw], svData[svid][svInt], _, 30.0);
		format(str, sizeof(str), "[FACTION VEHICLE ID: %d]\n"WHITE_E"Faction: "GREEN_LIGHT"%s\n"WHITE_E"Location: "GREEN_LIGHT"%s\n"WHITE_E"/fspawnveh - to spawn faction vehicle\n"WHITE_E"/fdespawnveh - to despawn faction vehicle", svid, type, GetLocation(svData[svid][svPosX], svData[svid][svPosY], svData[svid][svPosZ]));
		svData[svid][svLabel] = CreateDynamic3DTextLabel(str, COLOR_YELLOW, svData[svid][svPosX], svData[svid][svPosY], svData[svid][svPosZ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, svData[svid][svVw], svData[svid][svInt]);
	}
	return 1;
}

Svpoint_Listmenu(playerid, svid)
{
	if(svid <= -1)
        return 0;

    static
    	str[512];

   	switch(svData[svid][svType])
    {
    	case 1: //SAPD
    	{
    		format(str, sizeof(str), "Model\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
    			GetVehicleModelName(596),
    			GetVehicleModelName(407),
    			GetVehicleModelName(544),
    			GetVehicleModelName(599),
    			GetVehicleModelName(601),
    			GetVehicleModelName(528),
    			GetVehicleModelName(560),
    			GetVehicleModelName(523),
    			GetVehicleModelName(525),
    			GetVehicleModelName(497),
    			GetVehicleModelName(411)
    			);
    		ShowPlayerDialog(playerid, SVPOINT_SAPD, DIALOG_STYLE_TABLIST_HEADERS, "Vehicle Point (SAPD)", str, "Select", "Cancel");
    	}
    	case 2: //SAGS
    	{
    		format(str, sizeof(str), "Model\n%s\n%s\n%s\n%s\n%s\n%s\n",
    			GetVehicleModelName(405),
    			GetVehicleModelName(409),
    			GetVehicleModelName(411),
    			GetVehicleModelName(521),
    			GetVehicleModelName(437),
    			GetVehicleModelName(487)
    			);
    		ShowPlayerDialog(playerid, SVPOINT_SAGS, DIALOG_STYLE_TABLIST_HEADERS, "Vehicle Point (SAGS)", str, "Select", "Cancel");
	    }
	    case 3: //SAMD
	    {
	    	format(str, sizeof(str), "Model\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
	    		GetVehicleModelName(407),
    			GetVehicleModelName(544),
    			GetVehicleModelName(416),
    			GetVehicleModelName(442),
    			GetVehicleModelName(426),
    			GetVehicleModelName(586),
    			GetVehicleModelName(563),
    			GetVehicleModelName(487)
    			);
	    	ShowPlayerDialog(playerid, SVPOINT_SAMD, DIALOG_STYLE_TABLIST_HEADERS, "Vehicle Point (SAMD)", str, "Select", "Cancel");
	    }
	    case 4: //SANEW
	    {
	    	format(str, sizeof(str), "Model\n%s\n%s\n%s\n%s\n%s\n%s",
    			GetVehicleModelName(582),
    			GetVehicleModelName(418),
    			GetVehicleModelName(413),
    			GetVehicleModelName(405),
    			GetVehicleModelName(461),
    			GetVehicleModelName(488)
    			);
	    	ShowPlayerDialog(playerid, SVPOINT_SANEWS, DIALOG_STYLE_TABLIST_HEADERS, "Vehicle Point (SANA)", str, "Select", "Cancel");
	    }
	    case 5: //SACF
	    {
	    	format(str, sizeof(str), "Model\n%s\n%s\n%s\n%s\n%s\n%s",
    			GetVehicleModelName(588),
    			GetVehicleModelName(448),
    			GetVehicleModelName(423)
    			);
	    	ShowPlayerDialog(playerid, SVPOINT_SACF, DIALOG_STYLE_TABLIST_HEADERS, "Vehicle Point (SACF)", str, "Select", "Cancel");
	    }
    }
	return 1;
}

IsGSCar(carid)
{
	for(new v = 0; v < sizeof(SAGSVeh); v++)
	{
		if(carid == SAGSVeh[v]) return  1;
	}
	return 0;
}

IsCFCar(carid)
{
	for(new v = 0; v < sizeof(SAPDVeh); v++)
	{
		if(carid == SACFVeh[v]) return 1;
	}
	return 0;
}

IsPDCar(carid)
{
	for(new v = 0; v < sizeof(SAPDVeh); v++)
	{
	    if(carid == SAPDVeh[v]) return 1;
	}
	return 0;
}

IsMDCar(carid)
{
	for(new v = 0; v < sizeof(SAMDVeh); v++)
	{
	    if(carid == SAMDVeh[v]) return 1;
	}
	return 0;
}