#include <YSI_Coding\y_hooks.inc>

new Text3D:LabelFuel[MAX_PLAYERS];

enum gsinfo
{
	gsStock,
	Float:gsPosX,
	Float:gsPosY,
	Float:gsPosZ,
	Text3D:gsLabel,
};

new gsData[MAX_GSTATION][gsinfo],
	Iterator: GStation<MAX_GSTATION>;
	
GStation_Refresh(gsid)
{
	if(gsid != -1)
    {
        if(IsValidDynamic3DTextLabel(gsData[gsid][gsLabel]))
            DestroyDynamic3DTextLabel(gsData[gsid][gsLabel]);

        static
        string[255];

		format(string, sizeof(string), ""WHITE_E"ID: %d\n"WHITE_E"Press "GREEN_E"Y "WHITE_E"to fill up petrol\n"WHITE_E"Harga; "GREEN_E"$10",gsid);
		gsData[gsid][gsLabel] = CreateDynamic3DTextLabel(string, COLOR_GREEN, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]-0.3, 4.5);
	}
    return 1;
}

function LoadGStations()
{
    static gsid;
	
	new rows = cache_num_rows();
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", gsid);
			cache_get_value_name_int(i, "stock", gsData[gsid][gsStock]);
			cache_get_value_name_float(i, "posx", gsData[gsid][gsPosX]);
			cache_get_value_name_float(i, "posy", gsData[gsid][gsPosY]);
			cache_get_value_name_float(i, "posz", gsData[gsid][gsPosZ]);
			GStation_Refresh(gsid);
			Iter_Add(GStation, gsid);
		}
		printf("[DATABASE] Number of Loaded: %d.", rows);
	}
}

GStation_Save(gsid)
{
	new cQuery[512];
	format(cQuery, sizeof(cQuery), "UPDATE gstations SET stock='%d', posx='%f', posy='%f', posz='%f' WHERE id='%d'",
	gsData[gsid][gsStock],
	gsData[gsid][gsPosX],
	gsData[gsid][gsPosY],
	gsData[gsid][gsPosZ],
	gsid
	);
	return mysql_tquery(g_SQL, cQuery);
}

CMD:creategs(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
	
	new gsid = Iter_Free(GStation), query[128];
	if(gsid == -1) return Error(playerid, "You cant create more gs!");
	new stok;
	if(sscanf(params, "d", stok)) return Usage(playerid, "/creategs [stock - max: 10000/liters]");
	
	if(stok < 1 || stok > 10000) return Error(playerid, "Invagsid stok.");
	
	GetPlayerPos(playerid, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]);
	gsData[gsid][gsStock] = stok;
    GStation_Refresh(gsid);
	Iter_Add(GStation, gsid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO gstations SET id='%d', stock='%d', posx='%f', posy='%f', posz='%f'", gsid, gsData[gsid][gsStock], gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]);
	mysql_tquery(g_SQL, query, "OnGstationCreated", "i", gsid);
	return 1;
}

function OnGstationCreated(gsid)
{
	GStation_Save(gsid);
	return 1;
}

CMD:gotogs(playerid, params[])
{
	new gsid;
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
		
	if(sscanf(params, "d", gsid))
		return Usage(playerid, "/gotogs [id]");
		
	if(!Iter_Contains(GStation, gsid)) return Error(playerid, "The gs you specified ID of doesn't exist.");
	SetPlayerPosition(playerid, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ], 2.0);
    SetPlayerVirtualWorld(playerid, 0);
	SetPlayerInterior(playerid, 0);
	pData[playerid][pInDoor] = -1;
	pData[playerid][pInHouse] = -1;
	Servers(playerid, "You has teleport to gs id %d", gsid);
	return 1;
}

CMD:editgs(playerid, params[])
{
    static
        gsid,
        type[24],
        string[128];

    if(pData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    if(sscanf(params, "ds[24]S()[128]", gsid, type, string))
    {
        Usage(playerid, "/editgs [id] [name]");
        Names(playerid, "location, stock, delete");
        return 1;
    }
    if((gsid < 0 || gsid >= MAX_GSTATION))
        return Error(playerid, "You have specified an invagsid ID.");
	if(!Iter_Contains(GStation, gsid)) return Error(playerid, "The doors you specified ID of doesn't exist.");

    if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]);
        GStation_Save(gsid);
		GStation_Refresh(gsid);

        SendAdminMessage(COLOR_RED, "%s has adjusted the location of gs ID: %d.", pData[playerid][pAdminname], gsid);
    }
    else if(!strcmp(type, "stock", true))
    {
        new stok;

        if(sscanf(string, "d", stok))
            return Usage(playerid, "/editgs [id] [type] [stock - 10000]");

        if(stok < 1 || stok > 10000)
            return Error(playerid, "You must specify at least 1 - 5.");

        gsData[gsid][gsStock] = stok;
        GStation_Save(gsid);
		GStation_Refresh(gsid);

        SendAdminMessage(COLOR_RED, "%s has set gs ID: %d stock to %d.", pData[playerid][pAdminname], gsid, stok);
    }
    else if(!strcmp(type, "delete", true))
    {
		new query[128];
		DestroyDynamic3DTextLabel(gsData[gsid][gsLabel]);
		gsData[gsid][gsPosX] = 0;
		gsData[gsid][gsPosY] = 0;
		gsData[gsid][gsPosY] = 0;
		gsData[gsid][gsStock] = 0;
		gsData[gsid][gsLabel] = Text3D: INVALID_3DTEXT_ID;
		Iter_Remove(GStation, gsid);
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM gstations WHERE id=%d", gsid);
		mysql_tquery(g_SQL, query);
        SendAdminMessage(COLOR_RED, "%s has delete gs ID: %d.", pData[playerid][pAdminname], gsid);
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if((newkeys & KEY_YES) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		foreach(new gsid : GStation)
		{
			if(IsPlayerInRangeOfPoint(playerid, 1.5, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]))
			{
				if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
					return ErrorMsg(playerid, "Anda harus turun dari kendaraan.");
				
				new vehicleid = GetNearestVehicleToPlayer(playerid, 3.0, false);
				if(IsValidVehicle(vehicleid))
				{
					if(pData[playerid][pIsiBBM] == 0)
					{
						if(GetEngineStatus(vehicleid))
							return ErrorMsg(playerid, "Matikan terlebih dahulu kendaraan anda");
								
						if(vCore[vehicleid][vFuel] >= 100)
							return ErrorMsg(playerid, "Kendaraan bensin ini sudah penuh");
						
						if(pData[playerid][pIsValid] != 0)
							return SyntaxMsg(playerid, "Anda sedang mengisi bensin, tunggu sebentar");

						pData[playerid][pFill] = 0;
						pData[playerid][pIsValid] = 1;
						pData[playerid][pIsiBBM] = 1;
						DestroyDynamic3DTextLabel(LabelFuel[playerid]);
						new Float:x, Float:y, Float:z;
						GetVehiclePos(vehicleid, x, y, z);
						LabelFuel[playerid] = CreateDynamic3DTextLabel("0%", COLOR_WHITE, x, y, z+2, 10.0, INVALID_PLAYER_ID, vehicleid);
						pData[playerid][pActivity] = SetTimerEx("Filling", 500, true, "id", playerid, vehicleid);
					}
					else
					{
						Error(playerid, "Refulling fail! Anda telah membatalkan mengisi BBM!");
						DestroyDynamic3DTextLabel(LabelFuel[playerid]);
						GivePlayerMoneyEx(playerid, pData[playerid][pFill]*10);
						KillTimer(pData[playerid][pActivity]);
						pData[playerid][pIsValid] = 0;
						pData[playerid][pActivityTime] = 0;
						pData[playerid][pFill] = 0;
						pData[playerid][pIsiBBM] = 0;
					}
				}
				else
				{
					GivePlayerMoneyEx(playerid, -200);
					Inventory_Add(playerid, "Fuel Can", 1650, 1);
					InfoTD_MSG(playerid, 4000, "Anda telah membeli Fuel Can seharga ~g~$2.00");
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

ptask ReloadGas[1000](playerid)
{
	foreach(new gsid : GStation)
	{
		if(IsPlayerInRangeOfPoint(playerid, 1.5, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]))
		{
			new vehicleid = GetNearestVehicleToPlayer(playerid, 3.0, false);
			if(IsValidVehicle(vehicleid))
			{
				if(!pData[playerid][pIsiBBM])
				{
					UpdateDynamic3DTextLabelText(gsData[gsid][gsLabel], COLOR_GREY, sprintf(""WHITE_E"ID: %d\n"WHITE_E"Tekan "GREEN_E"Y "WHITE_E"Untuk mengisi BBM\n"WHITE_E"Harga; "GREEN_E"$10", gsid));
				}
				else
				{
					UpdateDynamic3DTextLabelText(gsData[gsid][gsLabel], COLOR_GREY, sprintf(""WHITE_E"ID: %d\n"WHITE_E"Tekan "GREEN_E"Y "WHITE_E"Untuk membatalkan mengisi BBM\n"WHITE_E"Harga: "GREEN_E"$10", gsid));
				}
			}
			else
			{
				UpdateDynamic3DTextLabelText(gsData[gsid][gsLabel], COLOR_GREY, sprintf(""WHITE_E"ID: %d\n"WHITE_E"Tekan"GREEN_E"Y "WHITE_E"Untuk membeli dirigen\n"WHITE_E"Harga: "GREEN_E"$2.00", gsid));	
			}
		}
	}
	return 1;
}

function Filling(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(!pData[playerid][pIsValid]) return 0;
	if(!pData[playerid][pIsiBBM]) return 0;
	if(GetNearestVehicleToPlayer(playerid, 3.0, false) == vehicleid || GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
		if(vCore[vehicleid][vFuel] >= 100)
		{
			if(IsValidVehicle(vehicleid))
			{
				DestroyDynamic3DTextLabel(LabelFuel[playerid]);
				SuccesMsg(playerid, "Refulling done!");
				pData[playerid][pFill] += GStationPrice;
				GivePlayerMoneyEx(playerid, -pData[playerid][pFill]*10);
				KillTimer(pData[playerid][pActivity]);
				pData[playerid][pIsValid] = 0;
				pData[playerid][pFill] = 0;
				pData[playerid][pIsiBBM] = 0;
			}
		}
		else if(vCore[vehicleid][vFuel] < 100)
		{
			vCore[vehicleid][vFuel]++;
			pData[playerid][pFill]++;
			ApplyAnimation(playerid, "CAMERA", "camstnd_idleloop", 4.1, 0, 0, 0, 0, 0, 1);
			UpdateDynamic3DTextLabelText(LabelFuel[playerid], COLOR_WHITE, sprintf("%d%", vCore[vehicleid][vFuel]));
		}
		else
		{
			ErrorMsg(playerid, "Anda gagal mengisi bensin anda");
			DestroyDynamic3DTextLabel(LabelFuel[playerid]);
			GivePlayerMoneyEx(playerid, pData[playerid][pFill]*10);
			KillTimer(pData[playerid][pActivity]);
			pData[playerid][pIsValid] = 0;
			pData[playerid][pFill] = 0;
			pData[playerid][pIsiBBM] = 0;
		}
	}
	else
	{
		ErrorMsg(playerid, "Anda gagal mengisi bahan bakar kendaraan");
		DestroyDynamic3DTextLabel(LabelFuel[playerid]);
		GivePlayerMoneyEx(playerid, pData[playerid][pFill]*10);
		KillTimer(pData[playerid][pActivity]);
		pData[playerid][pIsValid] = 0;
		pData[playerid][pFill] = 0;
	}
	return 1;
}

//GPS
GetGStationNearest(playerid)
{
	new tmpcount;
	foreach(new id : GStation)
	{
	    if(gsData[id][gsStock] > 0)
	    {
	    	if(GetPlayerDistanceFromPoint(playerid, gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]) < 10000)
	    	{
     			tmpcount++;
	    	}
		}
	}
	return tmpcount;
}

ReturnGStationNearestID(playerid, slot)
{
	new tmpcount;
	if(slot < 1 && slot > MAX_GSTATION) return -1;
	foreach(new id : GStation)
	{
	    if(gsData[id][gsStock] > 0)
	    {
	    	if(GetPlayerDistanceFromPoint(playerid, gsData[id][gsPosX], gsData[id][gsPosY], gsData[id][gsPosZ]) < 10000)
	    	{
	     		tmpcount++;
	       		if(tmpcount == slot)
	       		{
	        		return id;
	  			}
			}
		}
	}
	return -1;
}