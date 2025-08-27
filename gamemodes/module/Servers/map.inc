

#include <YSI_Coding/y_hooks>
new tmpobjid;
#include "./module/Servers/map/ext_balkot.pwn"
#include "./module/Servers/map/int_balkot.pwn"
//FAMILY
//#include "./module/Servers/map/family/ext_cartel.pwn"
//#include "./module/Servers/map/family/ext_bikers.pwn"
//#include "./module/Servers/map/family/ext_gangs.pwn"
//#include "./module/Servers/map/family/ext_mafia.pwn"

//GARKOT
//#include "./module/Servers/map/garkot/gk_conference.pwn"


//#include "./module/Servers/map/family/int_cartel.pwn"
#include "./module/Servers/map/family/int_gangs.pwn"
//#include "./module/Servers/map/family/int_mafia.pwn"
#include "./module/Servers/map/family/int_bikers.pwn"
#include "./module/Servers/map/openint_flecca.pwn"

//EXTERIOR
#include "./module/Servers/map/ext_penjahit.pwn"
#include "./module/Servers/map/ext_district.pwn"
#include "./module/Servers/map/ext_baju.pwn"
#include "./module/Servers/map/ext_market.pwn"
#include "./module/Servers/map/ext_ayam.pwn"
#include "./module/Servers/map/ext_bus.pwn"
#include "./module/Servers/map/ext_gasstation.pwn"
#include "./module/Servers/map/ext_mechanic.pwn"
#include "./module/Servers/map/ext_production.pwn"
#include "./module/Servers/map/ext_rentboat.pwn"
#include "./module/Servers/map/ext_sags.pwn"
#include "./module/Servers/map/ext_sana.pwn"
#include "./module/Servers/map/ext_toll.pwn"
#include "./module/Servers/map/ext_wedding.pwn"
#include "./module/Servers/map/ext_rehabilitation.pwn"
#include "./module/Servers/map/ext_dealer.pwn"
#include "./module/Servers/map/ext_fisherman.pwn"
#include "./module/Servers/map/ext_firstspawn.pwn"
#include "./module/Servers/map/ext_miner.pwn"
#include "./module/Servers/map/ext_adminjail.pwn"
//#include "./module/Servers/map/ext_worskhop.pwn"
//#include "./module/Servers/map/ext_pawnoinforu.pwn"
#include "./module/Servers/map/ext_sweeper.pwn"
#include "./module/Servers/map/ext_yellowstreet.pwn"
//#include "./module/Servers/map/ext_sapd.pwn"
#include "./module/Servers/map/ext_pasar.pwn"
#include "./module/Servers/map/ext_samd.pwn"
#include "./module/Servers/map/ext_kayu.pwn"

//INTERIOR
#include "./module/Servers/map/int_apartement.pwn"
#include "./module/Servers/map/int_bank.pwn"
#include "./module/Servers/map/int_sags.pwn"
#include "./module/Servers/map/int_sagsalpin.pwn"
#include "./module/Servers/map/int_samd.pwn"
#include "./module/Servers/map/int_sapd.pwn"
#include "./module/Servers/map/int_rehabilitation.pwn"
#include "./module/Servers/map/int_blackmarket.pwn"
#include "./module/Servers/map/int_pawnoinforu.pwn"
#include "./module/Servers/map/int_samd_baru.pwn"
#include "./module/Servers/map/int_bandara.pwn"
#include "./module/Servers/map/int_jail.pwn"

//OPEN INT
#include "./module/Servers/map/openint_pedagang.pwn"

//OPEN INT
#include "./module/Servers/map/openint_sapd.pwn"

//PRAGMA CONSTANT
#include "./module/Servers/map/int_sana.pwn"

//ASURANSI
#include "./module/Servers/map/ext_asuransi.pwn"

//SACF
//#include "./module/Servers/map/ext_sacf.pwn"

//JOB 
#include "./module/Servers/map/ext_jobsapi.pwn"
#include "./module/Servers/map/ext_haltebus.pwn"

//BLACK MARKET
#include "./module/Servers/map/ext_blackmarket.pwn"


//MAPPINGA WARGA
#include "./module/Servers/map/wargamapping/bedul/bedul.pwn"


//INT SHOWROOM
#include "./module/Servers/map/int_showroom.pwn"

#include "./module/Servers/map/ext_boxlv.pwn"

#include "./module/Servers/map/ext_mansion.pwn"

//#include "./module/Servers/map/intext_sapd.pwn"

#include "./module/Servers/map/ext_bankls.pwn"

#include "./module/Servers/map/name_server.pwn"
#include "./module/Servers/map/ext_bandara.pwn"

#include "./module/Servers/map/openint_mecha.pwn"
#include "./module/Servers/map/openint_dilerkapal.pwn"
#include "./module/Servers/map/openint_motel.pwn"

#include "./module/Servers/map/ext_jobfair.pwn"

#include "./module/Servers/map/paidads/pa_welcomesign.pwn"
#include "./module/Servers/map/paidads/pa_veronamall.pwn"
#include "./module/Servers/map/paidads/pa_roadsign.pwn"
#include "./module/Servers/map/paidads/la_swapmeet.pwn"
#include "./module/Servers/map/paidads/la_vagosmcbar.pwn"
#include "./module/Servers/map/paidads/pa_mcarthurpark.pwn"
#include "./module/Servers/map/paidads/pa_ghettopark.pwn"
//#include "./module/Servers/map/paidads/pa_roadblock.pwn"
#include "./module/Servers/map/paidads/pa_chinatown.pwn"
#include "./module/Servers/map/paidads/pa_idlestpark.pwn"
RemoveVendingMachines(playerid)
{
	RemoveBuildingForPlayer(playerid, 956, 1634.1487,-2238.2810,13.5077, 20.0); //Snack vender @ LS Airport
	RemoveBuildingForPlayer(playerid, 956, 2480.9885,-1958.5117,13.5831, 20.0); //Snack vender @ Sushi Shop in Willowfield
	RemoveBuildingForPlayer(playerid, 955, 1729.7935,-1944.0087,13.5682, 20.0); //Sprunk machine @ Unity Station
	RemoveBuildingForPlayer(playerid, 955, 2060.1099,-1898.4543,13.5538, 20.0); //Sprunk machine opposite Tony's Liqour in Willowfield
	RemoveBuildingForPlayer(playerid, 955, 2325.8708,-1645.9584,14.8270, 20.0); //Sprunk machine @ Ten Green Bottles
	RemoveBuildingForPlayer(playerid, 955, 1153.9130,-1460.8893,15.7969, 20.0); //Sprunk machine @ Market
	RemoveBuildingForPlayer(playerid, 955,1788.3965,-1369.2336,15.7578, 20.0); //Sprunk machine in Downtown Los Santos
	RemoveBuildingForPlayer(playerid, 955, 2352.9939,-1357.1105,24.3984, 20.0); //Sprunk machine @ Liquour shop in East Los Santos
	RemoveBuildingForPlayer(playerid, 1775, 2224.3235,-1153.0692,1025.7969, 20.0); //Sprunk machine @ Jefferson Motel
	RemoveBuildingForPlayer(playerid, 956, 2140.2566,-1161.7568,23.9922, 20.0); //Snack machine @ pick'n'go market in Jefferson
	RemoveBuildingForPlayer(playerid, 956, 2154.1199,-1015.7635,62.8840, 20.0); //Snach machine @ Carniceria El Pueblo in Las Colinas
	RemoveBuildingForPlayer(playerid, 956, 662.5665,-551.4142,16.3359, 20.0); //Snack vender at Dillimore Gas Station
	RemoveBuildingForPlayer(playerid, 955, 200.2010,-107.6401,1.5513, 20.0); //Sprunk machine @ Blueberry Safe House
	RemoveBuildingForPlayer(playerid, 956, 2271.4666,-77.2104,26.5824, 20.0); //Snack machine @ Palomino Creek Library
	RemoveBuildingForPlayer(playerid, 955, 1278.5421,372.1057,19.5547, 20.0); //Sprunk machine @ Papercuts in Montgomery
	RemoveBuildingForPlayer(playerid, 955, 1929.5527,-1772.3136,13.5469, 20.0); //Sprunk machine @ Idlewood Gas Station
	//purzfood
	RemoveBuildingForPlayer(playerid, 10394, -2336.929, -105.289, 37.000, 0.250);
	RemoveBuildingForPlayer(playerid, 10553, -2336.929, -105.289, 37.000, 0.250);
	RemoveBuildingForPlayer(playerid, 781, -2359.840, -123.344, 34.593, 0.250);
	RemoveBuildingForPlayer(playerid, 765, -2359.840, -127.633, 34.625, 0.250);
	RemoveBuildingForPlayer(playerid, 692, -2359.840, -123.969, 34.671, 0.250);
	RemoveBuildingForPlayer(playerid, 692, -2359.840, -126.805, 34.671, 0.250);

	//San Fierro
	RemoveBuildingForPlayer(playerid, 1302, -2419.5835,984.4185,45.2969, 20.0); //Soda machine 1 @ Juniper Hollow Gas Station
	RemoveBuildingForPlayer(playerid, 1209, -2419.5835,984.4185,45.2969, 20.0); //Soda machine 2 @ Juniper Hollow Gas Station
	RemoveBuildingForPlayer(playerid, 956, -2229.2075,287.2937,35.3203, 20.0); //Snack vender @ King's Car Park
	RemoveBuildingForPlayer(playerid, 955, -1349.3947,493.1277,11.1953, 20.0); //Sprunk machine @ SF Aircraft Carrier
	RemoveBuildingForPlayer(playerid, 956, -1349.3947,493.1277,11.1953, 20.0); //Snack vender @ SF Aircraft Carrier
	RemoveBuildingForPlayer(playerid, 955, -1981.6029,142.7232,27.6875, 20.0); //Sprunk machine @ Cranberry Station
	RemoveBuildingForPlayer(playerid, 955, -2119.6245,-422.9411,35.5313, 20.0); //Sprunk machine 1/2 @ SF Stadium
	RemoveBuildingForPlayer(playerid, 955, -2097.3696,-397.5220,35.5313, 20.0); //Sprunk machine 3 @ SF Stadium
	RemoveBuildingForPlayer(playerid, 955, -2068.5593,-397.5223,35.5313, 20.0); //Sprunk machine 3 @ SF Stadium
	RemoveBuildingForPlayer(playerid, 955, -2039.8802,-397.5214,35.5313, 20.0); //Sprunk machine 3 @ SF Stadium
	RemoveBuildingForPlayer(playerid, 955, -2011.1403,-397.5225,35.5313, 20.0); //Sprunk machine 3 @ SF Stadium
	RemoveBuildingForPlayer(playerid, 955, -2005.7861,-490.8688,35.5313, 20.0); //Sprunk machine 3 @ SF Stadium
	RemoveBuildingForPlayer(playerid, 955, -2034.5267,-490.8681,35.5313, 20.0); //Sprunk machine 3 @ SF Stadium
	RemoveBuildingForPlayer(playerid, 955, -2063.1875,-490.8687,35.5313, 20.0); //Sprunk machine 3 @ SF Stadium
	RemoveBuildingForPlayer(playerid, 955, -2091.9780,-490.8684,35.5313, 20.0); //Sprunk machine 3 @ SF Stadium

	//Las Venturas
	RemoveBuildingForPlayer(playerid, 956, -1455.1298,2592.4138,55.8359, 20.0); //Snack vender @ El Quebrados GONE
	RemoveBuildingForPlayer(playerid, 955, -252.9574,2598.9048,62.8582, 20.0); //Sprunk machine @ Las Payasadas GONE
	RemoveBuildingForPlayer(playerid, 956, -252.9574,2598.9048,62.8582, 20.0); //Snack vender @ Las Payasadas GONE
	RemoveBuildingForPlayer(playerid, 956, 1398.7617,2223.3606,11.0234, 20.0); //Snack vender @ Redsands West GONE
	RemoveBuildingForPlayer(playerid, 955, -862.9229,1537.4246,22.5870, 20.0); //Sprunk machine @ The Smokin' Beef Grill in Las Barrancas GONE
	RemoveBuildingForPlayer(playerid, 955, -14.6146,1176.1738,19.5634, 20.0); //Sprunk machine @ Fort Carson GONE
	RemoveBuildingForPlayer(playerid, 956, -75.2839,1227.5978,19.7360, 20.0); //Snack vender @ Fort Carson GONE
	RemoveBuildingForPlayer(playerid, 955, 1519.3328,1055.2075,10.8203, 20.0); //Sprunk machine @ LVA Freight Department GONE
	RemoveBuildingForPlayer(playerid, 956, 1659.5096,1722.1096,10.8281, 20.0); //Snack vender near Binco @ LV Airport GONE
	RemoveBuildingForPlayer(playerid, 955, 2086.5872,2071.4958,11.0579, 20.0); //Sprunk machine @ Sex Shop on The Strip
	RemoveBuildingForPlayer(playerid, 955, 2319.9001,2532.0376,10.8203, 20.0); //Sprunk machine @ Pizza co by Julius Thruway (North)
	RemoveBuildingForPlayer(playerid, 955, 2503.2061,1244.5095,10.8203, 20.0); //Sprunk machine @ Club in the Camels Toe
	RemoveBuildingForPlayer(playerid, 956, 2845.9919,1294.2975,11.3906, 20.0); //Snack vender @ Linden Station

	//Interiors: 24/7 and Clubs
	RemoveBuildingForPlayer(playerid, 1775, 496.0843,-23.5310,1000.6797, 20.0); //Sprunk machine 1 @ Club in Camels Toe
	RemoveBuildingForPlayer(playerid, 1775, 501.1219,-2.1968,1000.6797, 20.0); //Sprunk machine 2 @ Club in Camels Toe
	RemoveBuildingForPlayer(playerid, 1776, 501.1219,-2.1968,1000.6797, 20.0); //Snack vender @ Club in Camels Toe
	RemoveBuildingForPlayer(playerid, 1775, -19.2299,-57.0460,1003.5469, 20.0); //Sprunk machine @ Roboi's type 24/7 stores
	RemoveBuildingForPlayer(playerid, 1776, -35.9012,-57.1345,1003.5469, 20.0); //Snack vender @ Roboi's type 24/7 stores
	RemoveBuildingForPlayer(playerid, 1775, -17.0036,-90.9709,1003.5469, 20.0); //Sprunk machine @ Other 24/7 stores
	RemoveBuildingForPlayer(playerid, 1776, -17.0036,-90.9709,1003.5469, 20.0); //Snach vender @ Others 24/7 stores
	
	//garkot gk conference
	RemoveBuildingForPlayer(playerid, 647, 1133.588989, -1764.550049, 13.976000, 0.250000);
	RemoveBuildingForPlayer(playerid, 647, 1117.800049, -1765.260010, 13.976000, 0.250000);
}


RemoveMap(playerid)
{
	RemoveMapIdleStPark(playerid);
	RemoveMapVagosMcBar(playerid);
	RemoveMapChinaTown(playerid);
//	RemoveMapRoadBlock(playerid);
	RemoveMapMcArthurPark(playerid);
	RemoveMapSwapMeet(playerid);
	RemoveMapPaVeronaMall(playerid);
	RemoveMapPaWelcomeSign(playerid);

	RemoveMapMecha(playerid);
	RemoveVendingMachines(playerid);
	RemoveExtSana(playerid);
	//removesacf(playerid);
	RemoveMapBaju(playerid);
	RemoveMapDistrict(playerid);
	RemoveMapMarket(playerid);
	RemoveMapExtBandara(playerid);
	removeextasuransi(playerid);
	removemappedagang(playerid);

	//FAMILY
	//RemoveExtCartel(playerid);
	//RemoveExtBikers(playerid);
	//RemoveExtGangs(playerid);

	//=========FACTION========
	//RemoveExtSapd(playerid);
	//RemoveExtSamd(playerid);

	//======JOB=======
	RemoveExtMechanic(playerid);
	RemoveExtProduction(playerid);
	RemoveExtMiner(playerid);
	RemoveMapAyam(playerid);
	removemapnameserver(playerid);

	//===========MORE=========
	RemoveExtGasStation(playerid);
	RemoveExtToll(playerid);
	RemoveExtWedding(playerid);
	RemoveExtRehabilitation(playerid);
	RemoveExtFirstSpawn(playerid);
	//RemoveExtWorkshop(playerid);
	RemoveExtBoxLv(playerid);
	RemoveExtYellowStreet(playerid);
	//RemoveExtSapd(playerid);
	RemoveExtDealer(playerid);
	//RemoveIntExtSAPD(playerid);
	RemoveExtSamd(playerid);
	RemoveExtBank(playerid);
	RemoveExtKayu(playerid);
	removeopenintsapd(playerid);
	RemoveMapBalkot(playerid);
	RemoveMapDilerKapal(playerid);
	RemoveMapJobFair(playerid);
	RemovePenjahitMap(playerid);
	return 1;
}

LoadMap()
{
	LoadMapIdleStPark();
	LoadMapVagosMcBar();
	LoadMapChinaTown();
//	LoadMapRoadBlock();
	LoadMapGhettoPark();
	LoadMapMcArthurPark();
	LoadMapSwapMeet();
	LoadMapPaRoadSign();
	LoadMapPaVeronaMall();
	LoadMapPaWelcomeSign();
	/*Streamer_MaxItems(STREAMER_TYPE_OBJECT, 990000);
	Streamer_MaxItems(STREAMER_TYPE_CP, 200);
	Streamer_MaxItems(STREAMER_TYPE_MAP_ICON, 2000);
	Streamer_MaxItems(STREAMER_TYPE_PICKUP, 2000);
	Streamer_VisibleItems(STREAMER_TYPE_OBJECT, 1000);*/
	LoadMapJobFair();
	CreateMotelSantaMarina();
	LoadMapDilerKapal();
	LoadMapMecha();
	LoadMapIntBalkot();
	LoadMapBalkot();
	LoadMapExtBandara();
	//======= FAMILY ========
	CreateIntJail();
	loadmappedagang();
	loadmapopenintflecca();
	//CreateExtCartel();
	//CreateExtGangs();
	//CreateExtBikers();
	CreateIntBikers();
	CreateIntGangs();
	LoadMapMarket();
	
	//======= GARKOT ========
	//CreateGkConference();

	//EXT BAJU
	LoadMapBaju();

	//EXT DISTRICT
	LoadMapDistrict();

	//====== FACTION ========
	CreateExtSags();
	//CreateExtSapd();
	//CreateExtSamd();
	CreateExtSana();

	CreateIntSags();
	CreateIntSapd();
	CreateIntSamd();
	CreateIntSAGSAlpin();

	//====== JOBS & SIDEJOBS =======
	CreateExtMechanic();
	CreateExtProduction();
	CreateJobAyam();

	CreateExtFisherman();
	CreateExtBus();
	CreateExtMiner();

	//====== MORE MAPPING EXT =====
	CreateExtToll();
	CreateExtRentBoat();
	CreateExtWedding();
	CreateExtDealer();
	CreateExtGasStation();
	LoadPenjahitMap();
	CreateExtRehabilitation();
	CreateExtFirstSpawn();
	CreateExtAdminJail();
	//CreateExtWorkshop();
	CreateExtBoxLv();
	CreateExtYellowStreet();

	//====== MORE INTERIOR INT ====
	CreateIntApartement();
	CreateIntBank();
	CreateIntRehabilitation();
	CreateIntBlackMarket();
	CreateIntPawnoInfoRu();

	//======== PRAGMA CONSTANT
	CreateIntSana();

	//======= ASURANSI =======
	extasuransi();
	
	//========= SACF ========
	//extsacf();

	//======= JOB SAPI =====
	Createolahsusu();

	//====== JOB AYAM =====
	CreateMapAyam();

	//===== HALTE BUS =====
	CreateHalteBus();

	//===== BLACK MARKET ====
	Createbm();

	//==== RUMAH SAKIT TERBARU ====
	Createsamdterbaru();


	//===[ MAPINGAN WARGA ]====
	//BEDUL
	CreateInteriorBaseBedul();
	CreateHalamanBedul();
	CreateKantorBedul();


	//====[ INT SHOWROOM ]==
	CreateShowRoom();

	//EXT Mansion
	CreateExtMansion();
	//ext sweeper
	CreateExtSweeper();
	//CreateExtSapd();
	CreateIntbandara();
	CreateExtPasar();
	//CreateIntExtSAPD();
	CreateExtSamd();
	CreateExtBank();
	CreateExtAyam();
	loadmapopenintsapd();
	loadmapnameserver();
	return 1;
}
