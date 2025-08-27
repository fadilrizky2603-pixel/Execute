#define sapdloc 1542.34, -1675.75, 13.55
#define samdloc 2002.21, -1443.84, 13.56
#define rehabsamd 2215.11, -63.34, 26.48
#define sanaloc 645.63, -1356.65, 13.56
#define sacfloc 566.9679, -1816.0094, 6.0625
#define mancing 370.15, -2038.16, 7.67
#define materialloc -258.23, -2189.83, 28.97
#define componentloc 601.71, 867.77, -42.96
#define Casino 1022.49, -1125.98, 23.87
#define PigPen 2420.26, -1224.75, 25.12
#define Asuransi 345.52, -77.80, 1.41
#define showroomloc 1285.23, -1308.43, 13.54

//{"Dinasker", }

enum GPSDATA
{
	Float:LocX,
	Float:LocY,
	Float:LocZ,
	LocName[120],
    LocType[70]
};

new GPSLocations[][GPSDATA] =
{
    {1483.154785, -1756.937744, 13.736878, "Cityhall", "Pershing Square"},
    {1130.339477, -2037.112426, 69.023292, "Disnaker", "Verdent Bluff"},
    {1462.056274, -1031.137207, 23.656250, "Bank", "Downtown Los Santos"},
    {1255.668090, -1827.728149, 13.397333, "Driver School Newbie", "Confreance Center"},
    {1139.669189, -1695.843750, 14.014966, "San Andreas Police Department", "Verona Beach"},
    {2003.723754, -1443.117919, 13.562394,"County General Hospital", "Jefferson"},
    {208.145614, -254.009185, 1.597932, "Mechanic Basement", "Blueberry"},
    {342.543365, -96.290649, 1.369909,"Asuransi", "Blueberry"},
    {559.372314, -1815.664916, 6.075510, "Food Vendor", "Santa Maria Beach"},
    {2420.7288,-1233.5121,24.5077, "Bahamas", "East Los Santos"},
    {2862.896728, -1961.174438, 10.937087, "Market Job", "Playa Del Sellvie"},
    {1070.605224, -1765.693847, 13.369536,"Showroom Kampung Indo", "Santa Maria Beach"},
    {2078.491943, -2033.320556, 13.546875, "Gudang Warlok", "Willowfield"},
    {1129.356689, -1426.836425, 15.797985, "Mall Los Santos", "Market"}
};

new GPSHobi[][GPSDATA] =
{
    {369.8456,-2039.3762,7.3772, "Spot Memancing #1", "Santa Maria Bech"}
};


new GPSJOB[][GPSDATA] =
{
    {1530.788696, 25.285085, 24.135414, "Tukang Ayam #1", "Kadang Ayam"},
    {-1032.406860, -1025.620239, 129.218750, "Tukang Ayam #2", "Kantor Ayam"},
    {-382.653808, -1426.560424, 26.237884,"Petani #1", "Pembelian Bibit"},
    {-405.899139, -1385.407226, 23.651691, "Petani #2", "Ladang Tanaman"},
    {-598.167602, -2359.218261, 28.138463, "Tukang Kayu #1", "Hutan Kayu"},
    {-449.5992, -75.2461, 59.4415, "Tukang Kayu #2", "Proses Kayu"},
    {1982.407104, -2066.835205, 13.535199, "Penjahit", "Kantor Penjahit"},
    {307.279388, 1138.384887, 8.585937, "Pemerah Sapi", "Lokasi Pemerah"},
    {-847.501464, -2251.178710, 22.739616,"Penambang #1", "Pertambangan"},
    {-761.376037, -2239.026367, 26.530178, "Penambang #2 ", "Pencucian Batu"},
    {-797.836608, -2275.932128, 43.296417, "Penambang #3 ", "Peleburan Batu"},
    {-265.907257, -2158.017822, 28.857172, "Production", "Kantor Production"},
    {-82.211425, -1133.094726, 1.078125, "Trucker", "Tempat Trucker"}
};

new SidejobLocation[][GPSDATA] = {
    {1698.79, -1545.35, 13.38, "Driver Bus"},
    {370.15, -2038.16, 7.67, "Fishing Area"},
    {781.1893, -1136.6997, 23.5533, "Sweeper"},
    {2423.56, -2089.59, 13.53, "Trashmaster"},
    {2750.03, -2450.83, 13.64, "Trucker Hauling"}
};

new JobWhouseLocation[][GPSDATA] = {
    {2798.756103, -1593.548583, 10.931569, "Ikea", "Jual Hasil Kerja"},
    {-382.86, -1438.84, 26.33, "Jual Hasil Petani", "Petani"}
};

stock ShowBusinessLocation(playerid)
{
	new pelernen[3000], str[500];
    format(pelernen, sizeof(pelernen), "Nama\tLokasi\tJarak\n");
	forex(i, MAX_BISNIS)
	{
        {
            format(str, sizeof(str), "%s\t %s\t"YELLOW_E"%.2f Meter\n", bData[i][bName], GetLocation(bData[i][bExtposX], bData[i][bExtposY], bData[i][bExtposZ]),GetPlayerDistanceFromPoint(playerid, bData[i][bExtposX], bData[i][bExtposY], bData[i][bExtposZ]));
            strcat(pelernen, str);
        } 
	}
	Dialog_Show(playerid, DIALOG_GPS_BUSINESS, DIALOG_STYLE_TABLIST_HEADERS, "Kampung Indo - Lokasi Toko", pelernen, "Select", "Close");
	return 1;
}

stock ShowATMLocation(playerid)
{
    new str[2556];
    format(str, sizeof(str), "Lokasi\tJarak\n");
    forex(i, MAX_ATM)
	{
        {
            format(str, sizeof(str), "%s\t%s\t"YELLOW_E"%.2f Meter\n", str, GetLocation(AtmData[i][atmX], AtmData[i][atmY], AtmData[i][atmZ]), GetPlayerDistanceFromPoint(playerid, AtmData[i][atmX], AtmData[i][atmY], AtmData[i][atmZ]));
        }
	}
	Dialog_Show(playerid, DIALOG_GPS_ATM, DIALOG_STYLE_TABLIST_HEADERS, "Kampung Indo - Lokasi ATM", str, "Select", "Close");
}

stock ShowParkLocation(playerid)
{
    new str[2556];
    format(str, sizeof(str), "Lokasi\tJarak\n");
    forex(i, MAX_GARKOT)
    format(str, sizeof(str), "%s\t%s\t"YELLOW_E"%.2f Meter\n", str, GetLocation(gkData[i][gkX], gkData[i][gkY], gkData[i][gkZ]), GetPlayerDistanceFromPoint(playerid, gkData[i][gkX], gkData[i][gkY], gkData[i][gkZ]));
	Dialog_Show(playerid, DIALOG_GPS_PARK, DIALOG_STYLE_TABLIST_HEADERS, "Kampung Indo - Lokasi Garasi Kota", str, "Select", "Close");
}

Dialog:DIALOG_GPS_PARK(playerid, response, listitem, inputtext[])
{
    if(response)
	{
	    new id = listitem;

        SetPlayerWaypoint(playerid, "Garasi Kota",gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]);
        InfoMsg(playerid, sprintf("Rute ke garasi kota %s, lanjutkan ke waypoint", GetLocation(gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ])));
	}
    return 1;
}

stock ShowTreeLocation(playerid)
{
    new str[2556];
    format(str, sizeof(str), "Lokasi\tJarak\n");
    forex(i, MAX_TREES)
	{
        if(i % 2 == 0) format(str, sizeof(str), "%s\t%s\t"YELLOW"%.2f Meter\n", str, GetLocation(TreeData[i][treeX], TreeData[i][treeY], TreeData[i][treeZ]), GetPlayerDistanceFromPoint(playerid,TreeData[i][treeX], TreeData[i][treeY], TreeData[i][treeZ]));
	}
	Dialog_Show(playerid, DIALOG_GPS_TREE, DIALOG_STYLE_TABLIST_HEADERS, "Kampung Indo - Lokasi Pohon", str, "Select", "Close");
}



Dialog:DIALOG_GPS(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new bigstr[3000], str[500];
            format(bigstr, sizeof(bigstr), "Nama\tLokasi\tJarak\n");
			for(new x = 0; x < sizeof(GPSLocations); x++)
			{
                if(x % 2 == 0)
                {
                    format(str, sizeof(str), "%s\t%s\t"YELLOW_E"%0.2f Meter\n", GPSLocations[x][LocName],GPSLocations[x][LocType], GetPlayerDistanceFromPoint(playerid, GPSLocations[x][LocX], GPSLocations[x][LocY], GPSLocations[x][LocZ]));
                    strcat(bigstr, str);
                }
                else
                {
                    format(str, sizeof(str), "%s\t%s\t"YELLOW_E"%0.2f Meter\n", GPSLocations[x][LocName], GPSLocations[x][LocType], GetPlayerDistanceFromPoint(playerid, GPSLocations[x][LocX], GPSLocations[x][LocY], GPSLocations[x][LocZ]));
                    strcat(bigstr, str);
                }
			}
			Dialog_Show(playerid, GPSDestinations, DIALOG_STYLE_TABLIST_HEADERS, "Kampung Indo - GPS", bigstr, "Pilih", "Keluar");
        }
        case 1:
        {
            new peler1[3000], str[500];
            format(peler1, sizeof(peler1), "Nama\tLokasi\tJarak\n");
			for(new x = 0; x < sizeof(GPSJOB); x++)
			{
                if(x % 2 == 0)
                {
                    format(str, sizeof(str), "%s\t%s\t"YELLOW_E"%0.2f Meter\n", GPSJOB[x][LocName],GPSJOB[x][LocType], GetPlayerDistanceFromPoint(playerid, GPSJOB[x][LocX], GPSJOB[x][LocY], GPSJOB[x][LocZ]));
                    strcat(peler1, str);
                }
                else
                {
                    format(str, sizeof(str), ""GREY_E"%s\t%s\t"YELLOW_E"%0.2f Meter\n", GPSJOB[x][LocName], GPSJOB[x][LocType], GetPlayerDistanceFromPoint(playerid, GPSJOB[x][LocX], GPSJOB[x][LocY], GPSJOB[x][LocZ]));
                    strcat(peler1, str);
                }
			}
			Dialog_Show(playerid, JobDestinations, DIALOG_STYLE_TABLIST_HEADERS, "Kampung Indo - GPS", peler1, "Pilih", "Keluar");
        }
        case 2:
        {
            new peler[3000], str[500];
            format(peler, sizeof(peler), "Nama\tLokasi\tJarak\n");
			for(new x = 0; x < sizeof(GPSHobi); x++)
			{
                if(x % 2 == 0)
                {
                    format(str, sizeof(str), "%s\t%s\t"YELLOW_E"%0.2f Meter\n", GPSHobi[x][LocName],GPSHobi[x][LocType], GetPlayerDistanceFromPoint(playerid, GPSHobi[x][LocX], GPSHobi[x][LocY], GPSHobi[x][LocZ]));
                    strcat(peler, str);
                }
                else
                {
                    format(str, sizeof(str), "%s\t%s\t"YELLOW_E"%0.2f Meter\n", GPSHobi[x][LocName], GPSHobi[x][LocType], GetPlayerDistanceFromPoint(playerid, GPSHobi[x][LocX], GPSHobi[x][LocY], GPSHobi[x][LocZ]));
                    strcat(peler, str);
                }
			}
			Dialog_Show(playerid, HobiDestinations, DIALOG_STYLE_TABLIST_HEADERS, "Kampung Indo - GPS", peler, "Pilih", "Keluar");
        }
        case 3:
        {
            if(GetAnyBusiness() <= 0) return ErrorMsg(playerid, "Tidak ada bisnis di kota ini");
            new id, count = GetAnyBusiness(), location[4096], lstr[596];
            strcat(location,"No\tNama Bisnis\tType Bisnis\tDistance\n",sizeof(location));
            Loop(itt, (count + 1), 1)
            {
                id = ReturnBusinessID(itt);

                new type[128];
                if(bData[id][bType] == 1)
                {
                    type= "Fast Food";
                }
                else if(bData[id][bType] == 2)
                {
                    type= "24/7";
                }
                else if(bData[id][bType] == 3)
                {
                    type= "Clothes";
                }
                else if(bData[id][bType] == 4)
                {
                    type= "Equipments";
                }
                else if(bData[id][bType] == 5)
                {
                    type= "Electronics";
                }
                else
                {
                    type= "N/A";
                }
                if(itt == count)
                {
                    format(lstr,sizeof(lstr), "%d\t%s\t%s\t"YELLOW_E"%0.2fm\n", itt, bData[id][bName], type, GetPlayerDistanceFromPoint(playerid, bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ]));
                }
                else format(lstr,sizeof(lstr), "%d\t%s\t%s\t"YELLOW_E"%0.2fm\n", itt, bData[id][bName], type, GetPlayerDistanceFromPoint(playerid, bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ]));
                strcat(location,lstr,sizeof(location));
            }
            ShowPlayerDialog(playerid, DIALOG_TRACKBUSINESS, DIALOG_STYLE_TABLIST_HEADERS,"List Bisnis",location,"Tandai","Batal");
        }
        case 4:
        {
            if(GetATMStatus() <= 0)
                return ErrorMsg(playerid, "Tidak ada ATM yang kekurangan Stock/Rusak");

            new id, count = GetATMStatus(), mission[2024], lstr[3024], status[128];

            strcat(mission,"No\tLokasi\tStatus\tJarak\n",sizeof(mission));
            Loop(itt, (count + 1), 1)
            {
                id = ReturnRestockATMID(itt);

                if(AtmData[id][atmStatus] == 0)
                {
                    status = ""GREEN_LIGHT"Good";
                }
                else
                {
                    status = ""RED_E"Damaged";
                }
                if(itt == count)
                {
                    format(lstr,sizeof(lstr), "%d\t%s\t%s\t"YELLOW_E"%0.2f Meter\n", itt, GetLocation(AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]), status, GetPlayerDistanceFromPoint(playerid, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]));
                }
                else format(lstr,sizeof(lstr), "%d\t%s\t%s\t"YELLOW_E"%0.2f Meter\n", itt, GetLocation(AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]), status, GetPlayerDistanceFromPoint(playerid, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]));	
                strcat(mission,lstr,sizeof(mission));
            }
            ShowPlayerDialog(playerid, DIALOG_FIND_ATM, DIALOG_STYLE_TABLIST_HEADERS,"ATM Checker",mission,"Start","Cancel");
        }
        case 5:
        {
            if(GetWorkshopNearest() <= 0)
                return Error(playerid, "Tidak dapat menemukan workshop dikota.");

            new id, count = GetWorkshopNearest(), mission[2024], lstr[3024], wsstatus[128];

            strcat(mission,"No\tName\tStatus\tDistance\n",sizeof(mission));
            Loop(itt, (count + 1), 1)
            {
                id = ReturnWorkshopNearestID(itt);
                if(wData[id][wStatus] == 1)
                {
                    wsstatus = "{FF0000}Closed{FFFFFF}";
                }
                else
                {
                    wsstatus = "{00FF00}Opened{FFFFFF}";
                }
                if(itt == count)
                {
                    format(lstr,sizeof(lstr), "%d\t%s\t%s\t"YELLOW_E"%0.2fm\n", itt, wData[id][wName], wsstatus, GetPlayerDistanceFromPoint(playerid, wData[id][wExtposX], wData[id][wExtposY], wData[id][wExtposZ]));
                }
                else format(lstr,sizeof(lstr), "%d\t%s\t%s\t"YELLOW_E"%0.2fm\n", itt, wData[id][wName], wsstatus, GetPlayerDistanceFromPoint(playerid, wData[id][wExtposX], wData[id][wExtposY], wData[id][wExtposZ]));
                strcat(mission,lstr,sizeof(mission));
            }
            ShowPlayerDialog(playerid, GPS_NEAREST_WORKSHOP, DIALOG_STYLE_TABLIST_HEADERS,"Nearest Workshop",mission,"Select","Cancel");
        }
        case 6:
        {
            if(GetGarkotNearest(playerid) <= 0)
                return Error(playerid, "Tidak ada Public Garage yang berjarak 10km (10000 meter) darimu.");

            new id, count = GetGarkotNearest(playerid), mission[2024], lstr[3024];

            strcat(mission,"No\tLokasi\tJarak\n",sizeof(mission));
            Loop(itt, (count + 1), 1)
            {
                id = ReturnGarkotNearestID(playerid, itt);
                if(itt == count)
                {
                    format(lstr,sizeof(lstr), "%d\t%s\t"YELLOW_E"%0.2f Meter\n", itt, GetLocation(gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]),GetPlayerDistanceFromPoint(playerid, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]));
                }
                else format(lstr,sizeof(lstr), "%d\t%s\t"YELLOW_E"%0.2f Meter\n", itt, GetLocation(gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]), GetPlayerDistanceFromPoint(playerid, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]));
                strcat(mission,lstr,sizeof(mission));
            }
            ShowPlayerDialog(playerid, GPS_NEAREST_GARKOT, DIALOG_STYLE_TABLIST_HEADERS,"Nearest Public Garage",mission,"Select","Cancel");
        }
        case 7:
        {
            if(GetGStationNearest(playerid) <= 0)
                return ErrorMsg(playerid, "Tidak ada Pom Bensin di dekat anda");

            new id, count = GetGStationNearest(playerid), mission[2024], lstr[3024];

            strcat(mission,"No\tLokasi\tDistance\n",sizeof(mission));
            Loop(itt, (count + 1), 1)
            {
                id = ReturnGStationNearestID(playerid, itt);
                if(itt == count)
                {
                    format(lstr,sizeof(lstr), "%d\t%s\t"YELLOW_E"%0.2fm\n", itt, GetLocation(gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]), GetPlayerDistanceFromPoint(playerid, gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]));
                }
                else format(lstr,sizeof(lstr), "%d\t%s\t"YELLOW_E"%0.2fm\n", itt, GetLocation(gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]), GetPlayerDistanceFromPoint(playerid, gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]));
                strcat(mission,lstr,sizeof(mission));
            }
            ShowPlayerDialog(playerid, GPS_NEAREST_GSTATION, DIALOG_STYLE_TABLIST_HEADERS,"Nearest Gas Station",mission,"Select","Cancel");
        }
    }
    return 1;
}

stock ShowGarbageLocation(playerid)
{
    new str[1155];
    format(str, sizeof(str), "Lokasi\tJarak\n");
    forex(i, MAX_TRASH)
	{
        if(i % 2 == 0) format(str, sizeof(str), "%s\t%s\t"YELLOW_E"%.2f Meter\n", str, GetLocation(tmData[i][tmX], tmData[i][tmY], tmData[i][tmZ]), GetPlayerDistanceFromPoint(playerid,tmData[i][tmX], tmData[i][tmY], tmData[i][tmZ]));
	}
	Dialog_Show(playerid, DIALOG_GPS_GARBAGE, DIALOG_STYLE_TABLIST_HEADERS, "Kampung Indo - Lokasi Tempat Sampah", str, "Select", "Close");
}

Dialog:DIALOG_GPS_GARBAGE(playerid, response, listitem, inputtext[])
{
    if(response)
	{
	    new id = listitem;
 
        SetPlayerWaypoint(playerid, "Garbage", tmData[id][tmX], tmData[id][tmY], tmData[id][tmZ]);
        InfoMsg(playerid, sprintf("Rute ke garbage %s, lanjutkan ke waypoint", GetLocation(tmData[id][tmX], tmData[id][tmY], tmData[id][tmZ])));
	}
    return 1;
}

Dialog:DIALOG_GPS_ATM(playerid, response, listitem, inputtext[])
{
    if(response)
	{
	    new id = listitem;
    
        SetPlayerWaypoint(playerid, "ATM", AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]);
        InfoMsg(playerid, sprintf("Rute ke atm %s, lanjutkan ke waypoint", GetLocation(AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ])));
	}
    return 1;
}

Dialog:DIALOG_GPS_TREE(playerid, response, listitem, inputtext[])
{
    if(response)
	{
	    new id = listitem;
  
        SetPlayerWaypoint(playerid, "Tree", TreeData[id][treeX], TreeData[id][treeY], TreeData[id][treeZ]);
        InfoMsg(playerid, sprintf("Rute ke tree %s, lanjutkan ke waypoint", GetLocation(TreeData[id][treeX], TreeData[id][treeY], TreeData[id][treeZ])));
	}
    return 1;
}

Dialog:DIALOG_GPS_BUSINESS(playerid, response, listitem, inputtext[])
{
    if(response)
	{
		new id = listitem;
	
		SetPlayerWaypoint(playerid, "Business", bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ]);
		InfoMsg(playerid, sprintf("Rute ke business %s, lanjutkan ke waypoint", GetLocation(bData[id][bExtposX], bData[id][bExtposY], bData[id][bExtposZ])));		
	}
    return 1;
}

Dialog:SidejobDestinations(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        DisablePlayerRaceCheckpoint(playerid);
  
		SetPlayerWaypoint(playerid, SidejobLocation[listitem][LocName], SidejobLocation[listitem][LocX], SidejobLocation[listitem][LocY], SidejobLocation[listitem][LocZ]);
        InfoMsg(playerid, sprintf("Rute gps ditetapkan ke lokasi %s", SidejobLocation[listitem][LocName]));
    }
    return 1;
}

Dialog:JobWarehouseDestinations(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        DisablePlayerRaceCheckpoint(playerid);
  
		SetPlayerWaypoint(playerid, JobWhouseLocation[listitem][LocName], JobWhouseLocation[listitem][LocX], JobWhouseLocation[listitem][LocY], JobWhouseLocation[listitem][LocZ]);
        InfoMsg(playerid, sprintf("Rute gps ditetapkan ke lokasi %s", JobWhouseLocation[listitem][LocName]));
    }
    return 1;
}
Dialog:GPSDestinations(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		DisablePlayerRaceCheckpoint(playerid);
        SetPlayerWaze(playerid, Float:GPSLocations[listitem][LocX], Float:GPSLocations[listitem][LocY], Float:GPSLocations[listitem][LocZ], 0x8A44E4FF);
		SetPlayerWaypoint(playerid, GPSLocations[listitem][LocName], GPSLocations[listitem][LocX], GPSLocations[listitem][LocY], GPSLocations[listitem][LocZ]);
        InfoMsg(playerid, sprintf("Rute gps ditetapkan ke lokasi %s", GPSLocations[listitem][LocName]));
	}
	return true;
}

Dialog:HobiDestinations(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		DisablePlayerRaceCheckpoint(playerid);
        SetPlayerWaze(playerid, Float:GPSHobi[listitem][LocX], Float:GPSHobi[listitem][LocY], Float:GPSHobi[listitem][LocZ], 0x8A44E4FF);
		SetPlayerWaypoint(playerid, GPSHobi[listitem][LocName], GPSHobi[listitem][LocX], GPSHobi[listitem][LocY], GPSHobi[listitem][LocZ]);
        InfoMsg(playerid, sprintf("Rute gps ditetapkan ke lokasi %s", GPSHobi[listitem][LocName]));
	}
	return true;
}

Dialog:JobDestinations(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		DisablePlayerRaceCheckpoint(playerid);
  
        SetPlayerWaze(playerid, Float:GPSJOB[listitem][LocX], Float:GPSJOB[listitem][LocY], Float:GPSJOB[listitem][LocZ], 0x8A44E4FF);
		SetPlayerWaypoint(playerid, GPSJOB[listitem][LocName], GPSJOB[listitem][LocX], GPSJOB[listitem][LocY], GPSJOB[listitem][LocZ]);
        //InfoMsg(playerid, sprintf("Rute gps ditetapkan ke lokasi %s", GPSJOB[listitem][LocName]));
        SendClientMessageEx(playerid, COLOR_GREEN, "[Info]:"WHITE_E" Lokasi di tetapkan ke %s", GPSJOB[listitem][LocName]);
	}
	return true;
}

Dialog:DIALOG_GPS_JOB(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    
    if(pData[playerid][pJob] == 5)
    {
        if(listitem == 0)
        {
            SetPlayerWaypoint(playerid, "Penambang",  -459.5641,1596.1566,36.6520);
        }
        else if(listitem == 1)
        {
            SetPlayerWaypoint(playerid, "Penambang",  1393.1852,-296.7876,2.3329);
        }
        else if(listitem == 2)
        {
            SetPlayerWaypoint(playerid, "Penambang",  1030.0902,-340.7472,73.9922);
        }
    }
    if(pData[playerid][pJob] == 15)
    {
        if(listitem == 0)
        {
            SetPlayerWaypoint(playerid, "Penjahit",  2350.0000,-87.5007,26.4844);
        }
    }
    if(pData[playerid][pJob] == 7)
    {
        if(listitem == 0)
        {
            SetPlayerWaypoint(playerid, "Petani",  -1087.4374,-1648.2863,76.3739);
        }
        if(listitem == 1)
        {
            SetPlayerWaypoint(playerid, "Petani",  -283.7930,-2165.1985,28.5973);
        }
    }
    if(pData[playerid][pJob] == 14)
    {
        if(listitem == 0)
        {
            SetPlayerWaypoint(playerid, "Pemerah Susu",  300.255584, 1141.295288, 9.137485);
        }
    }
    if(pData[playerid][pJob] == 10)
    {
        if(listitem == 0)
        {
            SetPlayerWaypoint(playerid, "Pengambilan Ayam",  1550.9177,47.0601,24.8426);
        }
        else if(listitem == 1)
        {
            SetPlayerWaypoint(playerid, "Pemotong Ayam",  1902.7578,160.7851,37.1406);
        }
    }
    if(pData[playerid][pJob] == 3)
    {
        if(listitem == 0)
        {
            SetPlayerWaypoint(playerid, "Penebang Kayu",  -469.9032,-60.9384,60.1619);      
        }
    }
    if(pData[playerid][pJob] == 9)
    {
        if(listitem == 0)
        {
            SetPlayerWaypoint(playerid, "Penambang Minyak", 471.6167,1279.0704,9.5779);
        }
        else if(listitem == 1)
        {
            SetPlayerWaypoint(playerid, "Penambang Minyak", -1519.1105,2289.7993,47.4717);
        }
        else if(listitem == 2)
        {
            SetPlayerWaypoint(playerid, "Penambang Minyak", 285.1230,1408.3357,10.4018);
        }
    }
    if(pData[playerid][pJob] == 4)
    {
        
        if(listitem == 0)
        {
            //ShowCargoList(playerid);
        }
        if(listitem == 1)
        {
            SetPlayerWaypoint(playerid, "Cargo",  2837.6621,891.4214,10.7578);
        }
    }

    


    InfoMsg(playerid, "Rute telah di tandai di peta");
    return 1;
}

CMD:gpstest(playerid, const params[]) {
    Dialog_Show(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "Kampung Indo - Lokasi", "Lokasi Umum\nLokasi Pekerjaan\nLokasi Hobi\nLokasi Pertokoan\nATM Terdekat\nWorkshop\nGarasi Umum Terdekat\nPom Bensin\n"RED_E"(Disable Checkpoint)", "Pilih", "Keluar");
    return 1;
}
