Garkot_Save(id)
{
	new cQuery[2248];
	format(cQuery, sizeof(cQuery), "UPDATE garkot SET posx='%f', posy='%f', posz='%f', posa='%f', spawnx='%f', spawny='%f', spawnz='%f', spawna='%f', interior='%d', world='%d' WHERE id='%d'",
	gkData[id][gkX],
	gkData[id][gkY],
	gkData[id][gkZ],
	gkData[id][gkA],
	gkData[id][sgkX],
	gkData[id][sgkY],
	gkData[id][sgkZ],
	gkData[id][sgkA],
	gkData[id][gkInt],
	gkData[id][gkVW],
	id);

	return mysql_tquery(g_SQL, cQuery);
}

Garkot_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamic3DTextLabel(gkData[id][gkText]))
			DestroyDynamic3DTextLabel(gkData[id][gkText]);

		if(IsValidDynamicPickup(gkData[id][gkPickup]))
			DestroyDynamicPickup(gkData[id][gkPickup]);

		if(IsValidDynamicArea(gkData[id][gkArea]))
			DestroyDynamicArea(gkData[id][gkArea]);

		if(IsValidDynamicObject(gkData[id][gkObject]))
			DestroyDynamicObject(gkData[id][gkObject]);

		if(IsValidDynamicPickup(gkData[id][sgkPickup]))
			DestroyDynamicPickup(gkData[id][sgkPickup]);

		if(IsValidDynamicArea(gkData[id][sgkArea]))
			DestroyDynamicArea(gkData[id][sgkArea]);

		if(IsValidDynamicObject(gkData[id][sgkObject]))
			DestroyDynamicObject(gkData[id][sgkObject]);

        if(IsValidDynamicMapIcon(gkData[id][garkotmap]))
			DestroyDynamicMapIcon(gkData[id][garkotmap]);
		
		new str[540];
		format(str, sizeof(str), "{FFFFFF}Garasi Kota {FFFF00}[ID:%d]", id);
		gkData[id][gkText] = CreateDynamic3DTextLabel(str, COLOR_WHITE, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]-0.1, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1,  gkData[id][gkVW], gkData[id][gkInt]);
		gkData[id][gkObject] =  CreateDynamicObject(1316, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]-0.8, 0.0, 0.0, 0.0, gkData[id][gkVW], gkData[id][gkInt], -1, 50.00, 50.00);
		SetDynamicObjectMaterial(gkData[id][gkObject], 0, 18646, "matcolours", "white", 0x9900FF00);
		gkData[id][gkArea] = CreateDynamicCircle(gkData[id][gkX], gkData[id][gkY], 2.0, gkData[id][gkVW], gkData[id][gkInt], -1);
		gkData[id][garkotmap] = CreateDynamicMapIcon(gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ], 55, 0, -1, -1, -1, 300.0, MAPICON_GLOBAL);

		gkData[id][sgkObject] = CreateDynamicObject(1316, gkData[id][sgkX], gkData[id][sgkY], gkData[id][sgkZ]-0.8, 0.0, 0.0, 0.0, gkData[id][gkVW], gkData[id][gkInt], -1, 50.00, 50.00); 
		SetDynamicObjectMaterial(gkData[id][sgkObject], 0, 18646, "matcolours", "white", 0xFF990000); 
		gkData[id][sgkArea] = CreateDynamicCircle(gkData[id][sgkX], gkData[id][sgkY], 2.0, gkData[id][gkVW], gkData[id][gkInt], -1);
	}
	return 1;
}

ReturnPVehParkID(playerid, hslot)
{
	new tmpcount;
	if(hslot < 1 && hslot > MAX_PRIVATE_VEHICLE) return -1;
	foreach(new vehid : PVehicles)
	{
		if(pvData[vehid][cOwner] == pData[playerid][pID])
		{
			if(pvData[vehid][cParkid] == pData[playerid][pGetPARKID] && pvData[vehid][cClaim] == 0)
			{
	     		tmpcount++;
	       		if(tmpcount == hslot)
	       		{
	        		return vehid;
		  		}
	  		}
	    }
	}
	return -1;
}  

GetPVehINPARK(playerid)
{
	new tmpcount;
	foreach(new vehid : PVehicles)
	{
		if(pvData[vehid][cOwner] == pData[playerid][pID])
		{
			if(pvData[vehid][cParkid] == pData[playerid][pGetPARKID] && pvData[vehid][cClaim] == 0)
			{
     			tmpcount++;
     		}
	    }
	}
	return tmpcount;
}

ReturnGarkotNearestID(playerid, slot)
{
	new tmpcount;
	if(slot < 1 && slot > MAX_GARKOT) return -1;
	foreach(new id : Garkot)
	{
	    if(GetPlayerDistanceFromPoint(playerid, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]) < 10000)
	    {
     		tmpcount++;
       		if(tmpcount == slot)
       		{
        		return id;
  			}
		}
	}
	return -1;
}

GetGarkotNearest(playerid)
{
	new tmpcount;
	foreach(new id : Garkot)
	{
		if(GetPlayerDistanceFromPoint(playerid, gkData[id][gkX], gkData[id][gkY], gkData[id][gkZ]) < 10000)
	    {
     		tmpcount++;
     	}
	}
	return tmpcount;
}