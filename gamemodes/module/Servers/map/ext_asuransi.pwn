/*

	EXTERIOR ASURANSI

*/
removeextasuransi(playerid)
{
	RemoveBuildingForPlayer(playerid, 13060, 360.515, -97.234, 3.351, 0.250);
	RemoveBuildingForPlayer(playerid, 13064, 360.515, -97.234, 3.351, 0.250);
	RemoveBuildingForPlayer(playerid, 1440, 346.234, -103.765, 0.812, 0.250);
	RemoveBuildingForPlayer(playerid, 1440, 344.218, -78.906, 0.890, 0.250);
}
extasuransi()
{
	new object_world = -1, object_int = -1;
	tmpobjid = CreateDynamicObject(18249, 356.476104, -125.614257, 1.297145, 0.000000, 0.000000, 90.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 2, 1574, "dyn_trash", "trash", 0x00000000);
	tmpobjid = CreateDynamicObject(16305, 364.977172, -120.531059, 3.575265, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1574, "dyn_trash", "trash", 0x00000000);
	tmpobjid = CreateDynamicObject(16305, 355.847045, -120.531059, 4.525269, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1574, "dyn_trash", "trash", 0x00000000);
	tmpobjid = CreateDynamicObject(16406, 376.118469, -83.553375, 2.909370, 0.000000, 0.000000, 270.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "stormdrain7", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 3444, "vegashse8", "redstones01_256", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 3, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 4, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 5, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 6, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
	tmpobjid = CreateDynamicObject(3374, 368.399871, -105.114921, 1.527359, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1344, "cj_bins2", "CJ_RUBBISH1", 0x00000000);
	tmpobjid = CreateDynamicObject(3374, 373.949859, -105.114921, 1.527359, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1344, "cj_bins2", "CJ_RUBBISH1", 0x00000000);
	tmpobjid = CreateDynamicObject(3374, 371.359954, -105.114921, 4.557359, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1344, "cj_bins2", "CJ_RUBBISH1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 378.961517, -86.222969, 0.382811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 378.961517, -76.642982, 0.382811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 378.961517, -67.032951, 0.382811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 374.221649, -62.482975, 0.382811, 0.000007, 0.000000, 89.999977, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 364.601287, -62.482975, 0.382811, 0.000007, 0.000000, 89.999977, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 354.991424, -62.482975, 0.382811, 0.000007, 0.000000, 89.999977, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 342.921234, -86.603027, -2.757185, 0.000000, 0.000000, 180.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 342.027008, -77.152023, -2.757185, 0.000000, 0.000000, -169.500045, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(3168, 370.942382, -86.347419, 0.382811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3241, "conhooses", "trail_win2", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 4, 17072, "truckedepotlawn", "GB_truckdepot03", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 384.421356, -102.332931, 0.382811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 343.156799, -72.510101, 6.833851, 0.000000, 0.000000, 270.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "cj_juank_1", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 352.926910, -72.510101, 3.873850, 0.000000, 0.000000, 270.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17504, "eastlstr_lae2", "brokesign1", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 354.536895, -72.510101, 6.833851, 0.000000, 0.000000, 270.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18250, "cw_junkbuildcs_t", "Was_scrpyd_sign_alv", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 342.921234, -106.103065, -2.757185, 0.000000, 0.000000, 180.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 342.921234, -127.103088, -2.757185, 0.000000, 0.000000, 180.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 342.921234, -115.753135, -2.757185, 0.000000, 0.000000, 180.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 342.922241, -121.523124, -2.757185, 0.000000, 0.000000, 180.000000, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17634, "landlae2b", "compfence5b_LAe", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 379.747497, -90.357673, -0.037186, 0.000000, 0.000000, 128.600021, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13654, "drkpoly", "asandockw4", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 388.265380, -94.536399, -0.037186, 0.000000, 0.000000, 128.600021, object_world, object_int, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13654, "drkpoly", "asandockw4", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(18248, 370.245086, -115.795768, 8.226067, 0.000000, 0.000000, -30.600009, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(3576, 345.178558, -120.341606, 1.767470, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(3576, 345.845550, -116.210662, 1.767470, 0.000000, 0.000000, 35.100009, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(3594, 359.651916, -116.450538, 3.311826, -9.299996, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(3594, 366.222015, -116.563674, 2.621028, -9.299996, 0.000000, -33.899997, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(3594, 362.939758, -117.449592, 3.041198, -9.299996, 0.000000, -17.899995, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1637, 344.735443, -105.933898, 1.447325, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(16779, 376.074401, -85.847381, 11.500119, 0.000000, 90.000000, 90.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(3593, 373.185119, -117.846931, 9.844985, 0.000000, 0.000000, 19.100008, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(13591, 361.319702, -105.350212, 0.639374, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(11244, 354.145111, -71.795486, 3.444196, 0.000000, 0.000000, 450.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1407, 363.957519, -89.954483, 0.462016, 0.000000, 0.000000, -54.199996, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1432, 368.348663, -90.133720, 0.472811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1432, 365.508636, -87.923706, 0.472811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1407, 367.565704, -91.853218, 0.462016, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1407, 362.625823, -82.923217, 0.462016, 0.000000, 0.000000, 270.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1432, 364.198638, -82.253723, 0.472811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1712, 368.954620, -84.494865, 0.382811, 0.000000, 0.000000, -90.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19831, 367.534332, -81.429206, 0.322811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2677, 363.173645, -85.323959, 0.622811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2677, 366.803588, -90.963966, 0.682811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2677, 369.823516, -82.043952, 0.682811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2677, 361.063446, -82.043952, 0.682811, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2048, 369.513671, -89.703140, 3.032810, 0.000000, 0.000000, 270.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2048, 369.513671, -85.373146, 3.032810, 0.000000, 0.000000, 270.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1735, 352.446166, -108.436424, 0.684841, 0.000000, 89.400001, 128.300033, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1735, 345.257385, -112.661209, 0.696780, 0.000000, 89.400001, 96.800033, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1369, 355.610565, -105.461853, 0.873973, 0.000000, 0.000000, 0.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(12957, 347.881988, -109.222846, 0.920400, 0.000000, 0.000000, 107.799995, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(12957, 360.536895, -123.056556, 5.180399, 0.000000, 0.000000, 100.500000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(966, 342.869415, -99.742019, 0.506487, 0.000000, 0.000000, 270.000000, object_world, object_int, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(968, 342.859436, -99.684127, 1.374130, 0.000000, 0.000000, 90.000000, object_world, object_int, -1, 300.00, 300.00); 

}