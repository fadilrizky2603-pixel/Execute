#include <YSI_Coding\y_hooks>

enum    E_TREE
{
	// loaded from db
	Float: treeX,
	Float: treeY,
	Float: treeZ,
	Float: treeRX,
	Float: treeRY,
	Float: treeRZ,
	// temp
	treeLumber,
	treeSeconds,
	bool: treeGettingCut,
	treeObjID,
	Text3D: treeLabel,
	treeTimer
}

new TreeData[MAX_TREES][E_TREE],
	Iterator:Trees<MAX_TREES>;
	
SetPlayerLookAt(playerid, Float:x, Float:y)
{
	// somewhere on samp forums, couldn't find the source
	new Float:Px, Float:Py, Float: Pa;
	GetPlayerPos(playerid, Px, Py, Pa);
	Pa = floatabs(atan((y-Py)/(x-Px)));
	if (x <= Px && y >= Py) Pa = floatsub(180, Pa);
	else if (x < Px && y < Py) Pa = floatadd(Pa, 180);
	else if (x >= Px && y <= Py) Pa = floatsub(360.0, Pa);
	Pa = floatsub(Pa, 90.0);
	if (Pa >= 360.0) Pa = floatsub(Pa, 360.0);
	SetPlayerFacingAngle(playerid, Pa);
}

GetClosestTree(playerid, Float: range = 3.0)
{
	new id = -1, Float: dist = range, Float: tempdist;
	foreach(new i : Trees)
	{
	    tempdist = GetPlayerDistanceFromPoint(playerid, TreeData[i][treeX], TreeData[i][treeY], TreeData[i][treeZ]);

	    if(tempdist > range) continue;
		if(tempdist <= dist)
		{
			dist = tempdist;
			id = i;
		}
	}
	return id;
}

Player_ResetCutting(playerid)
{
	if(!IsPlayerConnected(playerid) || pData[playerid][CuttingTreeID] == -1) return 0;
	new id = pData[playerid][CuttingTreeID];
	TreeData[id][treeGettingCut] = false;
	if(TreeData[id][treeSeconds] < 1) Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, TreeData[id][treeLabel], E_STREAMER_COLOR, 0x2ECC71FF);
	
	clearAnimations(playerid);
    TogglePlayerControllable(playerid, 1);
    pData[playerid][CuttingTreeID] = -1;
    
    if(pData[playerid][pActivity] != -1)
	{
	    KillTimer(pData[playerid][pActivity]);
		pData[playerid][pActivity] = -1;
		pData[playerid][pActivityTime] = 0;
	}
	
	
	return 1;
}

Player_DropLumber(playerid, death_drop = 0)
{
    if(!IsPlayerConnected(playerid) || !pData[playerid][CarryingLumber]) return 0;
    new id = Iter_Free(Lumbers);
    if(id != -1)
    {
        new Float: x, Float: y, Float: z, Float: a, label[128];
        GetPlayerPos(playerid, x, y, z);
        GetPlayerFacingAngle(playerid, a);
        GetPlayerName(playerid, LumberData[id][lumberDroppedBy], MAX_PLAYER_NAME);

		if(!death_drop)
		{
		    x += (1.0 * floatsin(-a, degrees));
			y += (1.0 * floatcos(-a, degrees));
			
			ApplyAnimation(playerid, "CARRY", "putdwn05", 4.1, 0, 1, 1, 0, 0, 1);
		}

		LumberData[id][lumberSeconds] = LUMBER_LIFETIME;
		LumberData[id][lumberObjID] = CreateDynamicObject(19793, x, y, z - 0.9, 0.0, 0.0, a);
		
		//format(label, sizeof(label), "Lumber (%d)\n"WHITE_E"Dropped By "GREEN_E"%s\n"WHITE_E"%s\nUse /lumber pickup.", id, LumberData[id][lumberDroppedBy], ConvertToMinutes(LUMBER_LIFETIME));
		format(label, sizeof(label), "Batang Pohon\n{FFFF00}%s\n{FFFFFF}Gunakan {FFFF00}'/lum pickup' {FFFFFF}untuk membawa batang", ConvertToMinutes(LUMBER_LIFETIME));
		LumberData[id][lumberLabel] = CreateDynamic3DTextLabel(label, -1, x, y, z - 0.7, 5.0, .testlos = 1);
		
		LumberData[id][lumberTimer] = SetTimerEx("RemoveLumber", 1000, true, "i", id);
		Iter_Add(Lumbers, id);
    }
    
    Player_RemoveLumber(playerid);
	return 1;
}

Player_RemoveLumber(playerid)
{
	//if(!IsPlayerConnected(playerid) || !pData[playerid][CarryingLumber]) return 0;
	RemovePlayerAttachedObject(playerid, 9);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	pData[playerid][CarryingLumber] = false;
	return 1;
}

function RespawnTree(id)
{
	new label[300];
	if(TreeData[id][treeSeconds] > 1) 
	{
	    TreeData[id][treeSeconds]--;
	    //format(label, sizeof(label), "ID: %d\n{FF0000}Pohon Tumbang!\n%s\n{FFFFFF}Jumlah: %d\n{FFFF00}'/lum take' {FFFFFF}untuk mengambil", id, ConvertToMinutes(TreeData[id][treeSeconds]), TreeData[id][treeLumber]);
	    format(label, sizeof(label), "{FF0000}Pohon Tumbang!\n{FFFFFF}ID: %d\n{FFFF00}%s", id, ConvertToMinutes(TreeData[id][treeSeconds]));
		UpdateDynamic3DTextLabelText(TreeData[id][treeLabel], -1, label);
	}
	else if(TreeData[id][treeSeconds] == 1) 
	{
	    KillTimer(TreeData[id][treeTimer]);

	    TreeData[id][treeLumber] = 0;
	    TreeData[id][treeSeconds] = 0;
	    TreeData[id][treeTimer] = -1;
	    
	    SetDynamicObjectPos(TreeData[id][treeObjID], TreeData[id][treeX], TreeData[id][treeY], TreeData[id][treeZ]);
     	SetDynamicObjectRot(TreeData[id][treeObjID], TreeData[id][treeRX], TreeData[id][treeRY], TreeData[id][treeRZ]);
     	
     	format(label, sizeof(label), "ID: %d\n{FFFF00}[Y] {FFFFFF}untuk menebang pohon", id);
     	UpdateDynamic3DTextLabelText(TreeData[id][treeLabel], COLOR_GREEN, label);
	}
	return 1;
}
	
function LoadTrees()
{
    new rows = cache_num_rows();
    if (rows == 0) 
    {
        printf("[DATABASE] No trees found in database.");
        return;
    }

    for (new i = 0; i < rows; i++) 
    {
        new tid;
        cache_get_value_name_int(i, "id", tid);

        if (tid < 0 || tid >= MAX_TREES) // Pastikan ID dalam batas yang benar
            continue;

        cache_get_value_name_float(i, "posx", TreeData[tid][treeX]);
        cache_get_value_name_float(i, "posy", TreeData[tid][treeY]);
        cache_get_value_name_float(i, "posz", TreeData[tid][treeZ]);
        cache_get_value_name_float(i, "posrx", TreeData[tid][treeRX]);
        cache_get_value_name_float(i, "posry", TreeData[tid][treeRY]);
        cache_get_value_name_float(i, "posrz", TreeData[tid][treeRZ]);

        // Buat label pohon
        new label[64];
        format(label, sizeof(label), "ID: %d\n{FFFF00}[Y] {FFFFFF}untuk menebang pohon", tid);
        TreeData[tid][treeLabel] = CreateDynamic3DTextLabel(label, -1, 
            TreeData[tid][treeX], TreeData[tid][treeY], TreeData[tid][treeZ] + 1.5, 
            5.0
        );

        // Buat objek pohon
        TreeData[tid][treeObjID] = CreateDynamicObject(657, 
            TreeData[tid][treeX], TreeData[tid][treeY], TreeData[tid][treeZ], 
            TreeData[tid][treeRX], TreeData[tid][treeRY], TreeData[tid][treeRZ], 
            -1, -1, -1, 100.00, 100.00
        );

        Iter_Add(Trees, tid);
        TreeData[tid][treeGettingCut] = false;
        TreeData[tid][treeSeconds] = 0;
    }

    printf("[DATABASE] Number of trees loaded: %d.", rows);
}

Tree_Save(tid)
{
	new cQuery[512];
	format(cQuery, sizeof(cQuery), "UPDATE trees SET posx='%f', posy='%f', posz='%f', posrx='%f', posry='%f', posrz='%f' WHERE id='%d'",
	TreeData[tid][treeX],
	TreeData[tid][treeY],
	TreeData[tid][treeZ],
	TreeData[tid][treeRX],
	TreeData[tid][treeRY],
	TreeData[tid][treeRZ],
	tid
	);
	return mysql_tquery(g_SQL, cQuery);
}

Tree_Refresh(tid)
{
    if(!Iter_Contains(Trees, tid)) return 0;
    new label[96];
    
    if(TreeData[tid][treeLumber] > 0) {
	    //format(label, sizeof(label), "Tree (%d)\n"WHITE_E"Lumber: "GREEN_E"%d\n"WHITE_E"Use /lumber take.", tid, TreeData[tid][treeLumber]);
		format(label, sizeof(label), "ID: %d\nJumlah: %d\n{FFFF00}'/lum take' {FFFFFF}untuk membawa batang pohon", tid, TreeData[tid][treeLumber]);
		UpdateDynamic3DTextLabelText(TreeData[tid][treeLabel], -1, label);
	}else{
	    TreeData[tid][treeTimer] = SetTimerEx("RespawnTree", 1000, true, "i", tid);
	    
	    format(label, sizeof(label), "ID: %d\n{FFFF00}[Y] {FFFFFF}untuk menebang pohon", tid);
		UpdateDynamic3DTextLabelText(TreeData[tid][treeLabel], -1, label);
	}
	
	return 1;
}

Tree_BeingEdited(tid)
{
	if(!Iter_Contains(Trees, tid)) return 0;
	foreach(new i : Player) if(pData[i][pEditing] == tid) return 1;
	return 0;
}

ConvertToMinutes(time)
{
    // http://forum.sa-mp.com/showpost.php?p=3223897&postcount=11
    new string[15];//-2000000000:00 could happen, so make the string 15 chars to avoid any errors
    format(string, sizeof(string), "%02d:%02d", time / 60, time % 60);
    return string;
}

//-------[ commands ]----------

CMD:createtree(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
	new tid = Iter_Free(Trees), query[512];
	if(tid == -1) return Error(playerid, "Can't add any more trees.");
 	new Float: x, Float: y, Float: z, Float: a;
 	GetPlayerPos(playerid, x, y, z);
 	GetPlayerFacingAngle(playerid, a);
 	x += (3.0 * floatsin(-a, degrees));
	y += (3.0 * floatcos(-a, degrees));
	z -= 1.0;
	
	TreeData[tid][treeX] = x;
	TreeData[tid][treeY] = y;
	TreeData[tid][treeZ] = z;
	TreeData[tid][treeRX] = TreeData[tid][treeRY] = TreeData[tid][treeRZ] = 0.0;
	
	new label[96];
	format(label, sizeof(label), "ID: %d\n{FFFF00}[Y] {FFFFFF}untuk menebang pohon", tid);
	TreeData[tid][treeLabel] = CreateDynamic3DTextLabel(label, -1, TreeData[tid][treeX], TreeData[tid][treeY], TreeData[tid][treeZ] + 1.5, 5.0);
	TreeData[tid][treeObjID] = CreateDynamicObject(657, TreeData[tid][treeX], TreeData[tid][treeY], TreeData[tid][treeZ], TreeData[tid][treeRX], TreeData[tid][treeRY], TreeData[tid][treeRZ]);
	Iter_Add(Trees, tid);
	
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO trees SET id='%d', posx='%f', posy='%f', posz='%f', posrx='%f', posry='%f', posrz='%f'", tid, TreeData[tid][treeX], TreeData[tid][treeY], TreeData[tid][treeZ], TreeData[tid][treeRX], TreeData[tid][treeRY], TreeData[tid][treeRZ]);
	mysql_tquery(g_SQL, query, "OnTreeCreated", "di", playerid, tid);
	return 1;
}

function OnTreeCreated(playerid, tid)
{
	Tree_Save(tid);
	
	pData[playerid][pEditing] = tid;
	pData[playerid][pEditType] = EDIT_TREE;
	EditDynamicObject(playerid, TreeData[tid][treeObjID]);
	Servers(playerid, "Tree created.");
	Servers(playerid, "You can edit it right now, or cancel editing and edit it some other time.");
	return 1;
}

CMD:edittree(playerid, params[])
{
    if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
    if(pData[playerid][pEditing] != -1) return Error(playerid, "You're already editing a tree.");
	new tid;
	if(sscanf(params, "i", tid)) return Usage(playerid, "/edittree [tree id]");
	if(!Iter_Contains(Trees, tid)) return Error(playerid, "Invalid ID.");
	if(TreeData[tid][treeGettingCut]) return Error(playerid, "Can't edit specified tree because its getting cut down.");
	if(!IsPlayerInRangeOfPoint(playerid, 30.0, TreeData[tid][treeX], TreeData[tid][treeY], TreeData[tid][treeZ])) return SendClientMessage(playerid, 0xE74C3CFF, "ERROR: {FFFFFF}You're not near the tree you want to edit.");
	pData[playerid][pEditing] = tid;
	pData[playerid][pEditType] = EDIT_TREE;
	EditDynamicObject(playerid, TreeData[tid][treeObjID]);
	return 1;
}

CMD:removetree(playerid, params[])
{
    if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
		
	new tid, query[512];
	if(sscanf(params, "i", tid)) return Usage(playerid, "/removetree [tree id]");
	if(!Iter_Contains(Trees, tid)) return Error(playerid, "Invalid ID.");
	if(TreeData[tid][treeGettingCut]) return Error(playerid, "Can't remove specified tree because its getting cut down.");
	if(Tree_BeingEdited(tid)) return Error(playerid, "Can't remove specified tree because its being edited.");
	DestroyDynamicObject(TreeData[tid][treeObjID]);
	DestroyDynamic3DTextLabel(TreeData[tid][treeLabel]);
	if(TreeData[tid][treeTimer] != -1) KillTimer(TreeData[tid][treeTimer]);
	
	TreeData[tid][treeLumber] = TreeData[tid][treeSeconds] = 0;
	TreeData[tid][treeObjID] = TreeData[tid][treeTimer] = -1;
	TreeData[tid][treeLabel] = Text3D: -1;
	Iter_Remove(Trees, tid);
	
	mysql_format(g_SQL, query, sizeof(query), "DELETE FROM trees WHERE id=%d", tid);
	mysql_tquery(g_SQL, query);
	Servers(playerid, "Tree removed.");
	return 1;
}

CMD:gototree(playerid, params[])
{
	new tid;
	if(pData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
		
	if(sscanf(params, "d", tid))
		return Usage(playerid, "/gototree [id]");
	if(!Iter_Contains(Trees, tid)) return Error(playerid, "The tree you specified ID of doesn't exist.");
	SetPlayerPosition(playerid, TreeData[tid][treeX], TreeData[tid][treeY], TreeData[tid][treeZ], 2.0);
	
	pData[playerid][pInHouse] = -1;
	pData[playerid][pInDoor] = -1;
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
	Servers(playerid, "You has teleport to house id %d", tid);
	return 1;
}

CMD:lumber(playerid, params[])
{
	if(pData[playerid][pJob] == 3 || pData[playerid][pJob2] == 3)
	{
		//JamKerja(playerid, 5, 20);
		if(IsPlayerInAnyVehicle(playerid)) return ErrorMsg(playerid, "Anda harus keluar dari kendaraan.");
		if(isnull(params)) return Usage(playerid, "/lum [take/load/unload/pickup/sell]");
		
		/*if(!strcmp(params, "cut", true))
		{
			if(pData[playerid][CarryingLumber]) return Player_DropLumber(playerid);
				
			if(GetPlayerWeapon(playerid) == WEAPON_CHAINSAW && pData[playerid][CuttingTreeID] == -1 && !pData[playerid][CarryingLumber])
			{
				if(pData[playerid][pJobTime] > 0) return Error(playerid, "Anda harus menunggu "GREY2_E"%d "WHITE_E"detik untuk bisa bekerja kembali.", pData[playerid][pJobTime]);
				new tid = GetClosestTree(playerid);
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(tid != -1)
				{
					if(!Tree_BeingEdited(tid) && !TreeData[tid][treeGettingCut] && TreeData[tid][treeSeconds] < 1)
					{
						SetPlayerLookAt(playerid, TreeData[tid][treeX], TreeData[tid][treeY]);

						Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, TreeData[tid][treeLabel], E_STREAMER_COLOR, 0xE74C3CFF);
						SetTimerEx("CutTree", 10000, false, "i", playerid);
						ShowProgressbar(playerid, "Cutting...", 10);
						pData[playerid][CuttingTreeID] = tid;
						TogglePlayerControllable(playerid, 0);
						SetPlayerArmedWeapon(playerid, WEAPON_CHAINSAW);
						ApplyAnimation(playerid, "CHAINSAW", "WEAPON_csaw", 4.1, 1, 0, 0, 1, 0, 1);

						TreeData[tid][treeGettingCut] = true;
	
					}
					else return Error(playerid, "This tree is not ready.");
				}
				else return ErrorMsg(playerid, "Invalid tree id");
			}
			else return ErrorMsg(playerid, "You need to pickup the chainsaw.");
		}*/
		if(!strcmp(params, "take", true))
		{
			// taking from a cut tree
			if(pData[playerid][CarryingLumber]) return ErrorMsg(playerid, "Anda sedang membawa batang pohon");
			new tid = GetClosestTree(playerid);
			if(tid == -1) return Error(playerid, "Anda sedang tidak berada di dekat pohon");
			if(TreeData[tid][treeSeconds] < 1) return ErrorMsg(playerid, "Pohon ini belum di tebang");
			if(TreeData[tid][treeLumber] < 1) return ErrorMsg(playerid, "Pohon ini tidak memiliki batang pohon");
			TreeData[tid][treeLumber]--;
			Tree_Refresh(tid);
			
			Player_GiveLumber(playerid);
			Info(playerid, "Masukan ke dalam kendaraan pickup anda dengan {FFFF00}/lum load");
		}
		else if(!strcmp(params, "load", true))
		{
			// loading to a bobcat
			new carid = -1;
			if(!pData[playerid][CarryingLumber]) return ErrorMsg(playerid, "Anda sedang tidak membawa batang pohon");
			new vehicleid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			if(vehicleid == INVALID_VEHICLE_ID) return ErrorMsg(playerid, "Anda sedang tidak berada di dekat kendaraan");
			if(!IsAPickup(vehicleid)) return ErrorMsg(playerid, "Hanya dapat memasukan batang pohon di kendaraan pickup");

			if(Vehicle_LumberCount(vehicleid) >= LUMBER_LIMIT) return Error(playerid, "You can't load any more logs to this vehicle.");
			if((carid = Vehicle_Nearest(playerid)) != -1)
			{
				if(IsValidVehicle(pvData[carid][cVeh]))
				{
					pvData[carid][cLumber] += 1;
				}
			}
			if(IsValidVehicle(vehicleid))
			{
				for(new i; i < LUMBER_LIMIT; i++)
				{
					if(!IsValidDynamicObject(LumberObjects[vehicleid][i]))
					{
						LumberObjects[vehicleid][i] = CreateDynamicObject(19793, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
						AttachDynamicObjectToVehicle(LumberObjects[vehicleid][i], vehicleid, LumberAttachOffsets[i][0], LumberAttachOffsets[i][1], LumberAttachOffsets[i][2], 0.0, 0.0, LumberAttachOffsets[i][3]);
						break;
					}
				}
			}
			Streamer_Update(playerid);
			Player_RemoveLumber(playerid);
			Info(playerid, "Gunakan {FFFF00}'/lum unload' {FFFFFF}untuk mengambil kembali batang pohon");
		}
		else if(!strcmp(params, "unload")) 
		{
			// taking from a bobcat
			new carid = -1;
			if(pData[playerid][CarryingLumber]) return ErrorMsg(playerid, "Anda sedang membawa batang pohon");
			new vehicleid = GetNearestVehicleToPlayer(playerid, 3.5, false);
			if(vehicleid == INVALID_VEHICLE_ID) return ErrorMsg(playerid, "Anda sedang tidak berada di dekat kendaraan");
			if(!IsAPickup(vehicleid)) return ErrorMsg(playerid, "Hanya dapat mengeluarkan batang pohon di kendaraan pickup");

			if(Vehicle_LumberCount(vehicleid) < 1) return ErrorMsg(playerid, "Kendaraan ini tidak memiliki batang pohon");
			if((carid = Vehicle_Nearest(playerid)) != -1)
			{
				if(IsValidVehicle(pvData[carid][cVeh]))
				{
					pvData[carid][cLumber] -= 1;
				}
			}
			if(IsValidVehicle(vehicleid))
			{
				for(new i = (LUMBER_LIMIT - 1); i >= 0; i--)
				{
					if(IsValidDynamicObject(LumberObjects[vehicleid][i]))
					{
						DestroyDynamicObject(LumberObjects[vehicleid][i]);
						LumberObjects[vehicleid][i] = -1;
						break;
					}
				}
			}
			Streamer_Update(playerid);
			Player_GiveLumber(playerid);
		}
		else if(!strcmp(params, "pickup")) 
		{
			// taking from ground
			if(pData[playerid][CarryingLumber]) return ErrorMsg(playerid, "Anda sedang membawa batang pohon");
			new tid = GetClosestLumber(playerid);
			if(tid == -1) return ErrorMsg(playerid, "Anda sedang tidak berada di dekat batang pohon");
			LumberData[tid][lumberSeconds] = 1;
			RemoveLumber(tid);
			
			Player_GiveLumber(playerid);
		}
		else if(!strcmp(params, "sell"))
		{
			
		}
	}
	else return Error(playerid, "anda bukan pekerja lumber!");
	return 1;
}

#include <YSI_Coding\y_hooks>

CreateLumberPoint()
{
	new strings[128];
	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk packing kayu");
	CreateDynamic3DTextLabel(strings, -1, -437.0533,-86.2299,58.8833, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);		

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk packing kayu");
	CreateDynamic3DTextLabel(strings, -1, -437.0782,-82.6669,58.9089, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk packing kayu");
	CreateDynamic3DTextLabel(strings, -1, -437.1782,-77.6128,58.9478, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk mengolah kayu kemas menjadi Material");
	CreateDynamic3DTextLabel(strings, -1, -433.6643,-66.1523,58.9850, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk mengolah kayu kemas menjadi Material");
	CreateDynamic3DTextLabel(strings, -1, -433.6947,-62.9528,58.9850, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk mengolah kayu kemas menjadi Material");
	CreateDynamic3DTextLabel(strings, -1, -458.8548,-46.9672,60.0193, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk mengolah kayu kemas menjadi Material");
	CreateDynamic3DTextLabel(strings, -1, -462.4451,-46.8993,60.0448, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk mengolah kayu kemas menjadi Material");
	CreateDynamic3DTextLabel(strings, -1, -472.8553,-46.7882,60.1223, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

	format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk mengolah kayu kemas menjadi Material");
	CreateDynamic3DTextLabel(strings, -1, -476.5958,-47.0435,60.1710, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
}

function proseskayu(playerid)
{
	clearAnimations(playerid);
	Inventory_Add(playerid, "Kayu Kemas", 1271, 1);
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(pData[playerid][pJob] == 3 || pData[playerid][pJob2] == 3)
	{
		if(newkeys & KEY_YES)
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.0, -437.0533,-86.2299,58.8833))
			{
				if(!pData[playerid][CarryingLumber]) return ErrorMsg(playerid, "Anda sedang tidak membawa batang pohon");
				Player_RemoveLumber(playerid);
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Proses", "proseskayu");			
			}
			if(IsPlayerInRangeOfPoint(playerid, 3.0, -437.0782,-82.6669,58.9089))
			{
				if(!pData[playerid][CarryingLumber]) return ErrorMsg(playerid, "Anda sedang tidak membawa batang pohon");
				Player_RemoveLumber(playerid);
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Proses", "proseskayu");			
			}
			if(IsPlayerInRangeOfPoint(playerid, 3.0, -437.1782,-77.6128,58.9478))
			{
				if(!pData[playerid][CarryingLumber]) return ErrorMsg(playerid, "Anda sedang tidak membawa batang pohon");
				Player_RemoveLumber(playerid);
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Proses", "proseskayu");			
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -433.6643,-66.1523,58.9850))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Kayu Kemas") < 1) return ErrorMsg(playerid, "Anda tidak memiliki kayu kemas");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Proses", "proseskayu2");			
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -433.6947,-62.9528,58.9850))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Kayu Kemas") < 1) return ErrorMsg(playerid, "Anda tidak memiliki kayu kemas");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Proses", "proseskayu2");
			}	
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -458.8548,-46.9672,60.0193))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Kayu Kemas") < 1) return ErrorMsg(playerid, "Anda tidak memiliki kayu kemas");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Proses", "proseskayu2");
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -462.4451,-46.8993,60.0448))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Kayu Kemas") < 1) return ErrorMsg(playerid, "Anda tidak memiliki kayu kemas");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Proses", "proseskayu2");
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -472.8553,-46.7882,60.1223))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Kayu Kemas") < 1) return ErrorMsg(playerid, "Anda tidak memiliki kayu kemas");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Proses", "proseskayu2");
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -476.5958,-47.0435,60.1710))
			{
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(Inventory_Count(playerid, "Kayu Kemas") < 1) return ErrorMsg(playerid, "Anda tidak memiliki kayu kemas");
				ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);
				BarQTE(playerid, "Proses", "proseskayu2");
			}
		}
		if(newkeys & KEY_YES)
		{	
			if(GetPlayerWeapon(playerid) == WEAPON_CHAINSAW && pData[playerid][CuttingTreeID] == -1 && !pData[playerid][CarryingLumber])
			{
				if(pData[playerid][pJobTime] > 0) return Error(playerid, "Anda harus menunggu "GREY2_E"%d "WHITE_E"detik untuk bisa bekerja kembali.", pData[playerid][pJobTime]);
				new tid = GetClosestTree(playerid);
				if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
				if(tid != -1)
				{
					if(!Tree_BeingEdited(tid) && !TreeData[tid][treeGettingCut] && TreeData[tid][treeSeconds] < 1)
					{
						if(pData[playerid][CarryingLumber]) return Player_DropLumber(playerid);

						SetPlayerLookAt(playerid, TreeData[tid][treeX], TreeData[tid][treeY]);
						Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, TreeData[tid][treeLabel], E_STREAMER_COLOR, 0xE74C3CFF);	
						BarQTE(playerid, "Cutting", "CutTree");
						pData[playerid][CuttingTreeID] = tid;
						TogglePlayerControllable(playerid, 0);
						SetPlayerArmedWeapon(playerid, WEAPON_CHAINSAW);
						ApplyAnimation(playerid, "CHAINSAW", "WEAPON_csaw", 4.1, 1, 0, 0, 1, 0, 1);

						TreeData[tid][treeGettingCut] = true;
	
					}
					else return ErrorMsg(playerid, "Pohon yang akan anda tebang belum tumbuh");
				}
				else return Y_HOOKS_CONTINUE_RETURN_1;
			}
			else return Y_HOOKS_CONTINUE_RETURN_1;
		}		
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && (newkeys & KEY_NO))
		{
		    if(pData[playerid][CarryingLumber])
			{
				Player_DropLumber(playerid);
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

function proseskayu2(playerid)
{
	switch(random(2))
	{
		case 0:
		{
			clearAnimations(playerid);
			Inventory_Remove(playerid, "Kayu Kemas");
			Inventory_Add(playerid, "Material", 17051, 5);
		}
		case 1:
		{
			clearAnimations(playerid);
			Inventory_Remove(playerid, "Kayu Kemas");
			Inventory_Add(playerid, "Material", 17051, 10);
		}
	}
	return 1;
}

Vehicle_LumberCount(vehicleid)
{
	if(GetVehicleModel(vehicleid) == 0) return 0;
	new count;
	for(new i; i < LUMBER_LIMIT; i++) if(IsValidDynamicObject(LumberObjects[vehicleid][i])) count++;
	return count;
}

GetClosestLumber(playerid, Float: range = 2.0)
{
	new tid = -1, Float: dist = range, Float: tempdist, Float: pos[3];
	foreach(new i : Lumbers)
	{
		GetDynamicObjectPos(LumberData[i][lumberObjID], pos[0], pos[1], pos[2]);
	    tempdist = GetPlayerDistanceFromPoint(playerid, pos[0], pos[1], pos[2]);

	    if(tempdist > range) continue;
		if(tempdist <= dist)
		{
			dist = tempdist;
			tid = i;
		}
	}
	return tid;
}

Player_GiveLumber(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
	pData[playerid][CarryingLumber] = true;
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
	SetPlayerAttachedObject(playerid, 9, 19793, 6, 0.077999, 0.043999, -0.170999, -13.799953, 79.70, 0.0);
	Info(playerid, "Gunakan {FFFF00}[N] {FFFFFF}untuk menjatuhkan batang pohon");
	return 1;
}

function CutTree(playerid)
{
    if(pData[playerid][CuttingTreeID] != -1)
	{
		new tid = pData[playerid][CuttingTreeID];
		TreeData[tid][treeLumber] = 5;
		TreeData[tid][treeSeconds] = TREE_RESPAWN;
		Player_ResetCutting(playerid);
		Tree_Refresh(tid);
			
		SuccesMsg(playerid, "Cutting tree done!");
		KillTimer(pData[playerid][pActivity]);
		pData[playerid][pActivityTime] = 0;
			
		pData[playerid][pEnergy] -= 3;
		clearAnimations(playerid);
		StopLoopingAnim(playerid);
		SetPlayerSpecialAction(playerid, 0);

		MoveDynamicObject(TreeData[tid][treeObjID], TreeData[tid][treeX], TreeData[tid][treeY], TreeData[tid][treeZ] + 0.03, 0.025, TreeData[tid][treeRX], TreeData[tid][treeRY] - 80.0, TreeData[tid][treeRZ]);
		Streamer_Update(playerid);
		return 1;
	}
	return 1;
}

function RemoveLumber(tid)
{
	if(!Iter_Count(Lumbers, tid)) return 1;
	
	if(LumberData[tid][lumberSeconds] > 1) 
	{
	    LumberData[tid][lumberSeconds]--;

        new label[128];
	    //format(label, sizeof(label), "Lumber (%d)\n"WHITE_E"Dropped By "GREEN_E"%s\n"WHITE_E"%s\nUse /lumber pickup.", tid, LumberData[tid][lumberDroppedBy], ConvertToMinutes(LumberData[tid][lumberSeconds]));
		format(label, sizeof(label), "Batang Pohon\n{FFFF00}%s\n{FFFFFF}Gunakan {FFFF00}'/lum pickup' {FFFFFF}untuk membawa batang", ConvertToMinutes(LumberData[tid][lumberSeconds]));
		UpdateDynamic3DTextLabelText(LumberData[tid][lumberLabel], -1, label);
	}
	else if(LumberData[tid][lumberSeconds] == 1) 
	{
	    KillTimer(LumberData[tid][lumberTimer]);
	    DestroyDynamicObject(LumberData[tid][lumberObjID]);
		DestroyDynamic3DTextLabel(LumberData[tid][lumberLabel]);
		
	    LumberData[tid][lumberTimer] = -1;
        LumberData[tid][lumberObjID] = -1;
        LumberData[tid][lumberLabel] = Text3D: -1;

		Iter_Remove(Lumbers, tid);
	}
	
	return 1;
}
