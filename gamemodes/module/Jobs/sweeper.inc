#define sweperpoint1 781.1893,-1136.6997, 23.5533
#define sweperpoint2 795.4310, -1233.1376, 14.2794
#define sweperpoint3 863.2161, -1327.5327, 13.5294
#define sweperpoint4 1003.9434, -1329.0822, 13.3828
#define sweperpoint5 1056.8229, -1402.7941, 13.4338
#define sweperpoint6 1207.9458, -1403.2822, 13.2808
#define sweperpoint7 1206.3276, -1306.7577, 13.3912
#define sweperpoint8 1218.0497,-1141.5039, 23.5633
#define sweperpoint9 968.3759, -1140.7751, 24.1460
#define sweperpoint10 786.1747,-1137.3812, 23.8281

#define sweper1 779.3620, -1137.0579, 23.8281
#define sweper2 797.6353, -1061.3221, 24.6964
#define sweper3 947.5177, -972.6575, 38.5392
#define sweper4 1194.4229,-945.7073, 42.6887
#define sweper5 1260.5281,-988.5601, 36.2375
#define sweper6 1383.5503,-1037.9486, 26.0025
#define sweper7 1482.8932,-1157.5695, 23.8984
#define sweper8 1233.9427,-1141.0167, 23.5629
#define sweper9 865.5140,-1142.1689, 23.7346
#define sweper10 795.4321,-1136.3503, 23.8993


new SweepVeh[5];
new SweeperCP[MAX_PLAYERS];

AddSweeperVehicle()
{
	SweepVeh[0] = AddStaticVehicleEx(574, 775.503, -1121.813, 23.426, 90.694, 1, 1, VEHICLE_RESPAWN);
	vCore[SweepVeh[0]][vFuel] = 100;
	SweepVeh[1] = AddStaticVehicleEx(574, 775.480, -1124.296, 23.426, 92.137, 1, 1, VEHICLE_RESPAWN);
	vCore[SweepVeh[1]][vFuel] = 100;
	SweepVeh[2] = AddStaticVehicleEx(574, 775.554, -1126.844, 23.428, 96.045, 1, 1, VEHICLE_RESPAWN);
	vCore[SweepVeh[2]][vFuel] = 100;
}

IsASweeperVeh(carid)
{
	for(new v = 0; v < sizeof(SweepVeh); v++) {
	    if(carid == SweepVeh[v]) return 1;
	}
	return 0;
}