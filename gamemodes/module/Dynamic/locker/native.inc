Locker_Refresh(lid)
{
    if(lid != -1)
    {
        if(IsValidDynamic3DTextLabel(lData[lid][lLabel]))
            DestroyDynamic3DTextLabel(lData[lid][lLabel]);

		if(IsValidDynamicObject(lData[lid][lPickup]))
			DestroyDynamicObject(lData[lid][lPickup]);

        static
        string[255];
		
		new type[128];
		if(lData[lid][lType] == 1)
		{
			type= "San Andrease Police Departement";
		}
		else if(lData[lid][lType] == 2)
		{
			type= "San Andreas Goverment Service";
		}
		else if(lData[lid][lType] == 3)
		{
			type= "San Andreas Medical Departement";
		}
		else if(lData[lid][lType] == 4)
		{
			type= "San Andreas News Agency";
		}
		else if(lData[lid][lType] == 5)
		{
			type= "San Andreas Cafe Food";
		}
		else if(lData[lid][lType] == 6)
		{
			type= "VIP";
		}
		else
		{
			type= "Unknown";
		}

		format(string, sizeof(string), "ID: %d\n%s\nMoney: {00FF00}$%d\n{FFFF00}[Y] {FFFFFF}untuk membuka Locker", lid, type, lData[lid][lMoney]);
		lData[lid][lPickup] =  CreateDynamicObject(1316, lData[lid][lPosX], lData[lid][lPosY], lData[lid][lPosZ]-0.8, 0.0, 0.0, 0.0, 0, lData[lid][lInt], -1, 50.00, 50.00);
		SetDynamicObjectMaterial(lData[lid][lPickup], 0, 18646, "matcolours", "white", 0x9900FF00);
		//lData[lid][lPickup] = CreateDynamicPickup(1316, 23, lData[lid][lPosX], lData[lid][lPosY], lData[lid][lPosZ], 0, lData[lid][lInt], _, 4);
		lData[lid][lLabel] = CreateDynamic3DTextLabel(string, -1, lData[lid][lPosX], lData[lid][lPosY], lData[lid][lPosZ]+0.5, 2.5);
	}
    return 1;
}

Locker_Save(lid)
{
	new cQuery[512];
	format(cQuery, sizeof(cQuery), "UPDATE lockers SET type='%d', posx='%f', posy='%f', posz='%f', interior='%d', money='%d' WHERE id='%d'",
	lData[lid][lType],
	lData[lid][lPosX],
	lData[lid][lPosY],
	lData[lid][lPosZ],
	lData[lid][lInt],
	lData[lid][lMoney],
	lid
	);
	return mysql_tquery(g_SQL, cQuery);
}

Fac_AddMoney(lockerid, amount)
{
	lData[lockerid][lMoney] += amount;
	Locker_Save(lockerid);
	Locker_Refresh(lockerid);
}