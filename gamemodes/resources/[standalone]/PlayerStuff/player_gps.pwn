#if defined GPS_SYSTEM
    
     GPS SYSTEM BY AHMAZUQI

#endif
#include <YSI_Coding\y_hooks>
#define GPS:: g_
enum e_gps
{
    Float:g_X,
    Float:g_Y,
    Float:g_Z,
    g_Location[120],
    g_Type[70]
};

new g_Public[][e_gps] =
{ 
    {1133.9788, -2036.3195, 69.0078, "Balai Kota", "DCRP"},
    {931.0251, -1728.4634, 13.5485, "Kantor Kepolisian", "DCRP"},
    {382.9032, -1921.0918, 7.8359, "Bombom Cart", "DCRP"},
    {1323.7080,741.4053,10.8784, "Rumah Sakit", "DCRP"},
    {-75.1937, 1035.4578, 19.7411, "Bengkel Kota", "DCRP"},
    {424.6763, -1322.2543, 15.0031, "Asuransi", "DCRP"},
    {51.3536, 1222.1011, 18.9170, "Asuransi LV", "DCRP"},
    {2858.4968, -1986.9226, 10.9361, "Restaurant", "DCRP"},
    {2767.8762, -2435.3850, 13.6850, "Pelabuhan", "DCRP"},
    {2422.3745, -1234.7301, 24.5338, "Bahamas", "DCRP"},
    {2224.1106, -1152.6976, 25.7977, "Rusun Abah Iwan", "DCRP"},
    {88.39, -280.85, 1.57, "Terminal Desa", "DCRP"},
    {833.0068,-1197.2810,16.9935, "Pasar Modern", "DCRP"},
    {555.3796, -1292.9777, 17.2482, "Showroom DCRP", "DCRP"},
    {2076.8, -2033.33, 13.5469, "Gudang Warbun", "DCRP"},
    {-136.0707, 1116.6332, 20.1966, "Gudang Fort Carson", "DCRP"},
    //{2223.5115, -1143.1807, 25.7969, "OYO Hotels", "DCRP"},
    {221.2156, -117.9283, 1.5781, "Rusun Suroh", "DCRP"},
    {2183.3953, -1794.7335, 13.3606, "Rusun Jamal", "DCRP"},
    {1386.4347, 293.3129, 19.5469, "Toko Olahraga", "DCRP"},
    {-3.3894, 1212.4326, 19.3527, "Motel Romo", "DCRP"},
    {836.0340, -2008.6443, 12.8672, "Venue DCRP", "DCRP"},
    {2222.4739, 1837.4940, 10.8203, "Bahamas LV", "DCRP"},
    {-2442.7500, 755.2680, 35.2719, "Bahamas SF", "DCRP"},
    {2613.9070, 732.6111, 10.8203, "Rusun Bluedoorz", "DCRP"},
    {2819.3628, -1086.1926, 30.7333, "Universitas", "DCRP"},
    //{-2882.8586, 464.0963, 4.9141, "Panggung San Fiero", "DCRP"},
    {2832.8967, 1903.7570, 10.8203, "Drag Race Las Venturas", "DCRP"}
};

new g_Job[][e_gps] =
{
    {-2521.1821, -621.8853, 132.7418, "Electrician Job", "(Multiplayer Job)"},
    {96.0680, -272.6256, 1.5781, "Supir Bus", "Terminal FCODE"},
    {1546.5872, 28.7098, 24.1406, "Tukang Ayam #1", "Kandang Ayam"},
    {1911.8618, 164.4111, 37.1539, "Tukang Ayam #2", "Kantor Ayam"},
    {-547.7806, -185.1288, 78.4063, "Petani #1", "Pembelian Bibit"},
    {-376.1269, -1439.9231, 25.7266, "Petani #2", "Ladang Tanaman"},
    {3.9224, 66.8390, 3.1172, "Petani #3", "Olah Tanaman"},
    {-439.7503, -62.3335, 58.9720, "Tukang Kayu", "Hutan Kayu"},
    {-1704.2260, 49.6503, 3.5495, "Kargo", "Pegambilan Truck Kargo"},
    {-1072.7213,-1206.1061,129.2188, "Pemerah Sapi", "Lokasi Pemerahan"},
    {686.9853, 895.7302, -39.5328, "Penambang #1", "Pertambangan FCODE"},
    {-412.7031, 1197.8976, 2.2932, "Penambang #2", "Pencucian Batu"},
    {2182.6780, -2259.5010, 13.3878, "Penambang #3", "Peleburan Batu"},
    {2348.7112, -82.1600, 26.3359, "Penjahit #1", "Kantor Penjahit"},
    {676.1796, -619.9467, 16.3359, "Penjahit #2", "Penjualan Pakaian"},
    {2297.9268, 2764.1992, 10.8203, "Recycler #1", "Tempat Penyortiran"},
    {-31.6359, 1386.9554, 9.1719, "Recycler #2", "Tempat Daur Ulang"},
    {471.9127, 1299.1512, 9.7176, "Tukang Minyak #1", "Ambil Minyak"},
    {497.5595, 1518.7350, 1.0000, "Tukang Minyak #2", "Refined Minyak"},
    {279.6849, 1348.9515, 10.5859, "Tukang Minyak #3", "Mixxing Minyak"},
    {1929.94, -1776.33, 13.5469, "Tukang Minyak #4", "Penjualan Gas"},
    {111.3999, -1895.6553, 2.9408, "Nelayan #1", "Rental Perahu"},
    {352.4596, -2669.7722, -0.0401, "Nelayan #2", "Penangkapan Ikan"},
    {641.2187, 1238.3390, 11.6796, "Driver Mixer", "Memulai Pekerjaan"},
    {1037.3827, -305.1682, 74.0922, "Trashmaster", "Sidejob"},
    {2118.1814, -1188.9286, 23.9358, "Mower", "Sidejob"},
    {604.9979, -1508.6365, 14.9549, "Sweeper", "Sidejob"},
    {1001.3441, -1445.8391, 13.5469, "Delivery", "Sidejob"},
    {-1723.7289, -63.5671, 3.5547, "Forklift", "Sidejob"}
};

new g_Hoby[][e_gps] =
{
    {383.1566, -2075.2007, 7.8359, "Memancing #1", "Spot Pemancingan"},
    {-2057.3674, -2464.5283, 31.1797, "Memancing #2", "Penjualan Ikan"},
    {-387.3126, -2259.8279, 45.5646, "Berburu #1", "Spot Perburuan"},
    {-1693.3431, -88.9088, 3.5654, "Berburu #2", "Penjualan Hasil Buruan"}
};

stock g_Display(playerid)
{
    ShowPlayerDialog(playerid, GPS::LokasiGps, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Lokasi",
    "Lokasi Umum\
    \n"GRAY"Lokasi Pekerjaan\
    \nLokasi Hobi\
    \n"GRAY"Lokasi Pertokoan\
    \nATM Terdekat\
    \n"GRAY"Garasi Umum Terdekat\
    \nTong Sampah Terdekat\
    \n"GRAY"Warung Terdekat\
    \nPom Bensin Terdekat\
    \n"GRAY"Bengkel Modshop\
    \nRumah Saya\
    \n"RED"(Disable Checkpoint)\
    \n"RED"(Disable Shareloc)", "Pilih", "Batal");
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    //============================[GPS DIALOG]===========================================//
	if(dialogid == GPS::PublicMark)
	{
		if(response)
		{
	    	DisablePlayerRaceCheckpoint(playerid);
            SetPlayerRaceCheckpoint(playerid, 1, GPS::Public[listitem][GPS::X], GPS::Public[listitem][GPS::Y], GPS::Public[listitem][GPS::Z], GPS::Public[listitem][GPS::X], GPS::Public[listitem][GPS::Y], GPS::Public[listitem][GPS::Z], 5.0);
		    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
		    pMapCP[playerid] = true;
		}
	}
	if(dialogid == GPS::JobMark)
	{
		if(response)
		{
	    	DisablePlayerRaceCheckpoint(playerid);
            SetPlayerRaceCheckpoint(playerid, 1, GPS::Job[listitem][GPS::X], GPS::Job[listitem][GPS::Y], GPS::Job[listitem][GPS::Z], GPS::Job[listitem][GPS::X], GPS::Job[listitem][GPS::Y], GPS::Job[listitem][GPS::Z], 5.0);
		    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
		    pMapCP[playerid] = true;
		}
	}
	if(dialogid == GPS::HobyMark)
	{
		if(response)
		{
	    	DisablePlayerRaceCheckpoint(playerid);
            SetPlayerRaceCheckpoint(playerid, 1, GPS::Hoby[listitem][GPS::X], GPS::Hoby[listitem][GPS::Y], GPS::Hoby[listitem][GPS::Z], GPS::Hoby[listitem][GPS::X], GPS::Hoby[listitem][GPS::Y], GPS::Hoby[listitem][GPS::Z], 5.0);
		    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
		    pMapCP[playerid] = true;
		}
	}
    if(dialogid ==GPS::LokasiPertokoan)
    {
        if(!response)
        {
            GPS::Display(playerid);
        }
        else
        {
            switch(listitem)
            {
                case 0: // pakaian
                {
                    new id = ClothesStoreNearby(playerid);
                    if(id == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada Toko Pakaian terdekat dari posisi anda!");
                    DisablePlayerRaceCheckpoint(playerid);
                    SetPlayerRaceCheckpoint(playerid, 1, WarungData[id][warungPOS][0], WarungData[id][warungPOS][1], WarungData[id][warungPOS][2], WarungData[id][warungPOS][0], WarungData[id][warungPOS][1], WarungData[id][warungPOS][2], 5.0);
                    pMapCP[playerid] = true;
                    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
                }
                case 1: // elektronik
                {
                    new id = ElectronicStoreNearby(playerid);
                    if(id == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada Toko Elektronik terdekat dari posisi anda!");
                    DisablePlayerRaceCheckpoint(playerid);
                    SetPlayerRaceCheckpoint(playerid, 1, WarungData[id][warungPOS][0], WarungData[id][warungPOS][1], WarungData[id][warungPOS][2], WarungData[id][warungPOS][0], WarungData[id][warungPOS][1], WarungData[id][warungPOS][2], 5.0);
                    pMapCP[playerid] = true;
                    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
                }
            }
        }
    }
    if(dialogid == GPS::LokasiGps)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    new gpsStr[3000], gpsFormat[500];
                    strcat(gpsStr, "Nama\tLokasi\tJarak\n");
                    jv_loop(g, sizeof(GPS::Public))
                    {
                        if(g % 2 == 0)
                        {
                            format(gpsFormat, sizeof(gpsFormat), ""WHITE"%s\t"WHITE"%s\t"YELLOW"%.2f m\n", GPS::Public[g][GPS::Location], GetLocation(GPS::Public[g][GPS::X], GPS::Public[g][GPS::Y], GPS::Public[g][GPS::Z]), GetPlayerDistanceFromPoint(playerid, GPS::Public[g][GPS::X], GPS::Public[g][GPS::Y], GPS::Public[g][GPS::Z]));
                            strcat(gpsStr, gpsFormat);
                        }
                        else
                        {
                            format(gpsFormat, sizeof(gpsFormat), ""GREY"%s\t"GREY"%s\t"YELLOW"%.2f m\n", GPS::Public[g][GPS::Location], GetLocation(GPS::Public[g][GPS::X], GPS::Public[g][GPS::Y], GPS::Public[g][GPS::Z]), GetPlayerDistanceFromPoint(playerid, GPS::Public[g][GPS::X], GPS::Public[g][GPS::Y], GPS::Public[g][GPS::Z]));
                            strcat(gpsStr, gpsFormat);
                        }
                    }
                    ShowPlayerDialog(playerid, GPS::PublicMark, DIALOG_STYLE_TABLIST_HEADERS, ""PINK1"DCRP"WHITE"- GPS", gpsStr, "Pilih", "Batal");
                }
                case 1: 
                {
                    new gpsStr[3000], gpsFormat[500];
                    strcat(gpsStr, "Pekerjaan\tNama\tLokasi\tJarak\n");
                    jv_loop(g, sizeof(GPS::Job))
                    {
                        if(g % 2 == 0)
                        {
                            format(gpsFormat, sizeof(gpsFormat), ""WHITE"%s\t"WHITE"%s\t"WHITE"%s\t"YELLOW"%.2f m\n", GPS::Job[g][GPS::Location], GPS::Job[g][GPS::Type], GetLocation(GPS::Job[g][GPS::X], GPS::Job[g][GPS::Y], GPS::Job[g][GPS::Z]), GetPlayerDistanceFromPoint(playerid, GPS::Job[g][GPS::X], GPS::Job[g][GPS::Y], GPS::Job[g][GPS::Z]));
                            strcat(gpsStr, gpsFormat);
                        }
                        else
                        {
                            format(gpsFormat, sizeof(gpsFormat), ""GREY"%s\t"GREY"%s\t"GREY"%s\t"YELLOW"%.2f m\n", GPS::Job[g][GPS::Location], GPS::Job[g][GPS::Type], GetLocation(GPS::Job[g][GPS::X], GPS::Job[g][GPS::Y], GPS::Job[g][GPS::Z]), GetPlayerDistanceFromPoint(playerid, GPS::Job[g][GPS::X], GPS::Job[g][GPS::Y], GPS::Job[g][GPS::Z]));
                            strcat(gpsStr, gpsFormat);
                        }
                    }
                    ShowPlayerDialog(playerid, GPS::JobMark, DIALOG_STYLE_TABLIST_HEADERS, ""PINK1"DCRP"WHITE"- GPS", gpsStr, "Pilih", "Batal");
                }
                case 2:
                {
                    new gpsStr[3000], gpsFormat[500];
                    strcat(gpsStr, "Hobi\tNama\tLokasi\tJarak\n");
                    jv_loop(g, sizeof(GPS::Hoby))
                    {
                        if(g % 2 == 0)
                        {
                            format(gpsFormat, sizeof(gpsFormat), ""WHITE"%s\t"WHITE"%s\t"WHITE"%s\t"YELLOW"%.2f m\n", GPS::Hoby[g][GPS::Location], GPS::Hoby[g][GPS::Type], GetLocation(GPS::Hoby[g][GPS::X], GPS::Hoby[g][GPS::Y], GPS::Hoby[g][GPS::Z]), GetPlayerDistanceFromPoint(playerid, GPS::Hoby[g][GPS::X], GPS::Hoby[g][GPS::Y], GPS::Hoby[g][GPS::Z]));
                            strcat(gpsStr, gpsFormat);
                        }
                        else
                        {
                            format(gpsFormat, sizeof(gpsFormat), ""GREY"%s\t"GREY"%s\t"GREY"%s\t"YELLOW"%.2f m\n", GPS::Hoby[g][GPS::Location], GPS::Hoby[g][GPS::Type], GetLocation(GPS::Hoby[g][GPS::X], GPS::Hoby[g][GPS::Y], GPS::Hoby[g][GPS::Z]), GetPlayerDistanceFromPoint(playerid, GPS::Hoby[g][GPS::X], GPS::Hoby[g][GPS::Y], GPS::Hoby[g][GPS::Z]));
                            strcat(gpsStr, gpsFormat);
                        }
                    }
                    ShowPlayerDialog(playerid, GPS::HobyMark, DIALOG_STYLE_TABLIST_HEADERS, ""PINK1"DCRP"WHITE"- GPS", gpsStr, "Pilih", "Batal");
                }
                case 3:
                {
                    ShowPlayerDialog(playerid, GPS::LokasiPertokoan, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- GPS", 
                    "Toko Pakaian Terdekat\
                    \n"GRAY"Toko Elektronik Terdekat", "Pilih", "Batal");
                }
                case 4:
                {
                    new id = NearestAtm(playerid);
                    if(id == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada ATM terdekat dari posisi anda!");
                    DisablePlayerRaceCheckpoint(playerid);
                    SetPlayerRaceCheckpoint(playerid, 1, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ], AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ], 5.0);
                    pMapCP[playerid] = true;
                    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
                }
                case 5:
                {
                    new id = GarkotNearby(playerid);
                    if(id == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada Garasi Umum terdekat dari posisi anda!");
                    DisablePlayerRaceCheckpoint(playerid);
                    SetPlayerRaceCheckpoint(playerid, 1, PublicGarage[id][pgPOS][0], PublicGarage[id][pgPOS][1], PublicGarage[id][pgPOS][2], PublicGarage[id][pgPOS][0], PublicGarage[id][pgPOS][1], PublicGarage[id][pgPOS][2], 5.0);
                    pMapCP[playerid] = true;
                    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
                }
                case 6:
                {
                    new id = NearbyTrash(playerid);
                    if(id == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada Tong Sampah terdekat dari posisi anda!");
                    DisablePlayerRaceCheckpoint(playerid);
                    SetPlayerRaceCheckpoint(playerid, 1, TrashData[id][trashPos][0], TrashData[id][trashPos][1], TrashData[id][trashPos][2], 0.0, 0.0, 0.0 ,5.0);
                    pMapCP[playerid] = true;
                    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
                }
                case 7:
                {
                    new id = WarungNearby(playerid);
                    if(id == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada Warung terdekat dari posisi anda!");
                    DisablePlayerRaceCheckpoint(playerid);
                    SetPlayerRaceCheckpoint(playerid, 1, WarungData[id][warungPOS][0], WarungData[id][warungPOS][1], WarungData[id][warungPOS][2], WarungData[id][warungPOS][0], WarungData[id][warungPOS][1], WarungData[id][warungPOS][2], 5.0);
                    pMapCP[playerid] = true;
                    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
                }
                case 8: // Pom bensin
                {
                    new id = GasFuelNearby(playerid);
                    if(id == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada Pom Bensin terdekat dari posisi anda!");
                    DisablePlayerRaceCheckpoint(playerid);
                    SetPlayerRaceCheckpoint(playerid, 1, PomNearest[id][0], PomNearest[id][1], PomNearest[id][2], PomNearest[id][0], PomNearest[id][1], PomNearest[id][2], 5.0);
                    pMapCP[playerid] = true;
                    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
                }
                case 9: // Bengkel Modshop
                {
                    DisablePlayerRaceCheckpoint(playerid);
                    SetPlayerRaceCheckpoint(playerid, 1, 1101.4049, -1233.4498, 15.8203, 1101.4049, -1233.4498, 15.8203, 5.0);
                    pMapCP[playerid] = true;
                    Info(playerid, "Silahkan ikuti tanda blip yang sudah ditandai pada map anda");
                }
                case 10:// Rumah saya
                {
                    new bool: found = false;
                    foreach(new id : House)
                    {
                        if(House_HaveAccess(playerid, id))
                        {
                            AccountData[playerid][pTrackHoused] = true;
                            DisablePlayerRaceCheckpoint(playerid);
                            SetPlayerRaceCheckpoint(playerid, 1, HouseData[id][hsExtPos][0], HouseData[id][hsExtPos][1], HouseData[id][hsExtPos][2], HouseData[id][hsExtPos][0], HouseData[id][hsExtPos][1], HouseData[id][hsExtPos][2], 4.0);
                            ShowTDN(playerid, NOTIFICATION_INFO, "Lokasi telah ditandai di map!");
                            found = true;
                        }
                    }
                    if(!found) ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki/memegang kunci Rumah!");
                }
                case 11:
                {
                    DisablePlayerRaceCheckpoint(playerid);
                    ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil menghapus Checkpoint");
                    pMapCP[playerid] = false;
                }
                case 12:
                {
                    if(!IsValidDynamicMapIcon(SharelocSender[playerid]))
                    {
                        return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada yang mengirimkan anda share lokasi!");
                    }
                    else
                    {
                        ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil menghapus Shareloc!");

                        DestroyDynamicMapIcon(SharelocSender[playerid]);
                        SharelocSender[playerid] = INVALID_STREAMER_ID;
                        SharelocTimer[playerid] = 0;
                    }
                }
            }
        }
    }
    return 1;
}