#include <YSI_Coding\y_hooks>

enum E_STORAGE_DATA {
    bool:storageExists,
    storageID,
    Float:storagePos[3],
    storageInterior,
    storageWorld,
    Text3D:storageLabel,
    storageType,
    storageExtraID
};

new StorageData[MAX_STORAGE][E_STORAGE_DATA];

enum {
    STORAGE_TYPE_NONE = 0,
    STORAGE_TYPE_PUBLIC,
    STORAGE_TYPE_FACTION,
    STORAGE_TYPE_HOUSE,
    STORAGE_TYPE_FAMILY
};

GetFreeStorageID() {
    new index = -1;

    for(new i = 0; i < MAX_STORAGE; i++) if(!StorageData[i][storageExists]) {
        index = i;
        break;
    }
    return index;
}

CreateStorage(type, Float:x, Float:y, Float:z, interior, world) {
    new index = -1;

    if((index = GetFreeStorageID()) != -1) {
        StorageData[index][storageExists] = true;
        StorageData[index][storageID] = 0;
        StorageData[index][storagePos][0] = x;
        StorageData[index][storagePos][1] = y;
        StorageData[index][storagePos][2] = z;
        StorageData[index][storageInterior] = interior;
        StorageData[index][storageWorld] = world;
        StorageData[index][storageType] = type;
        StorageData[index][storageExtraID] = -1;

        mysql_tquery(g_SQL, "INSERT INTO `storage` (`Interior`) VALUES('0')", "OnStorageCreated", "d", index);
    }
    return index;
}

SaveStorage(id) {
    if(StorageData[id][storageExists]) {
        new query[512];

        mysql_format(g_SQL, query, sizeof(query), "UPDATE `storage` SET `PosX` = '%f', `PosY` = '%f', `PosZ` = '%f', `Interior` = '%d', `World` = '%d'",
            StorageData[id][storagePos][0],
            StorageData[id][storagePos][1],
            StorageData[id][storagePos][2],
            StorageData[id][storageInterior],
            StorageData[id][storageWorld]
        );
        mysql_format(g_SQL, query, sizeof(query), "%s, `Type` = '%d', `ExtraID` = '%d'",
            query,
            StorageData[id][storageType],
            StorageData[id][storageExtraID]
        );
        mysql_format(g_SQL, query, sizeof(query), "%s WHERE `ID` = '%d'",
            query,
            StorageData[id][storageID]
        );
        mysql_tquery(g_SQL, query);
    }
    return 1;
}

GetStorageName(storagetype) {
    new type[24];

    switch(storagetype) {
        case 0: type = "None";
        case 1: type = "Public";
        case 2: type = "Faction";
        case 3: type = "House";
        case 4: type = "Family";
    }
    return type;
}

function LoadStorage() 
{
    new rows = cache_num_rows();
    if(rows == 0) 
    {
        printf("[DATABASE] No storage found in database.");
        return 0;
    }

    for (new i = 0; i < rows; i++) 
    {
        StorageData[i][storageExists] = true;

        cache_get_value_name_int(i, "ID", StorageData[i][storageID]);
        cache_get_value_name_int(i, "Type", StorageData[i][storageType]);
        cache_get_value_name_int(i, "Interior", StorageData[i][storageInterior]);
        cache_get_value_name_int(i, "World", StorageData[i][storageWorld]);
        cache_get_value_name_int(i, "ExtraID", StorageData[i][storageExtraID]);
        cache_get_value_name_float(i, "PosX", StorageData[i][storagePos][0]);
        cache_get_value_name_float(i, "PosY", StorageData[i][storagePos][1]);
        cache_get_value_name_float(i, "PosZ", StorageData[i][storagePos][2]);

        SyncStorage(i);
    }

    printf("[DATABASE] Loaded %d storage from database", rows);
    return 1;
}

SyncStorage(id) 
{
    if (!StorageData[id][storageExists])
        return 0;

    if (IsValidDynamic3DTextLabel(StorageData[id][storageLabel]))
        DestroyDynamic3DTextLabel(StorageData[id][storageLabel]);

    new string[96];
    format(string, sizeof(string), "{EEFF00}[Y] {FFFFFF}%s storage (ID: %d)", 
        GetStorageName(StorageData[id][storageType]), id);

    StorageData[id][storageLabel] = CreateDynamic3DTextLabel(
        string, -1, 
        StorageData[id][storagePos][0], StorageData[id][storagePos][1], StorageData[id][storagePos][2], 
        10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 
        StorageData[id][storageWorld], StorageData[id][storageInterior]
    );

    return 1;
}

GetNearestStorage(playerid) {

    new idx = -1;
    for(new i = 0; i < MAX_STORAGE; i++) if(IsPlayerInRangeOfPoint(playerid, 3.5, StorageData[i][storagePos][0], StorageData[i][storagePos][1], StorageData[i][storagePos][2]) && GetPlayerInterior(playerid) == StorageData[i][storageInterior] && GetPlayerVirtualWorld(playerid) == StorageData[i][storageWorld]) {
        idx = i;
        break;
    }
    return idx;
}

function OnStorageCreated(id) 
{
    if(StorageData[id][storageExists]) 
    {
        StorageData[id][storageID] = cache_insert_id();
        SaveStorage(id);
        SyncStorage(id);
    }
    return 1;
}

CMD:createstorage(playerid, params[]) {
    if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);

    new type, Float:pos[3];

    if(sscanf(params, "d", type))
        return Usage(playerid, "/createstorage [1. public | 2. faction | 3. house | 4.family]");

    if(type < 1 || type > 4)
        return Error(playerid, "Tipe tidak tersedia.");

    new index = -1;

    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
    if((index = CreateStorage(type, pos[0], pos[1], pos[2], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid))) != -1) {
        Info(playerid, "Anda telah membuat storage ID: %d (gunakan /editstorage untuk mengatur)", index);
    }
    return 1;
}

CMD:editstorage(playerid, params[]) {

    if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);

    new id, type[24], string[128], idx;

    if(sscanf(params, "ds[24]S()[128]", id, type, string))
        return Usage(playerid, "/edistorage [id] [house/faction/family/location/delete]");

    if(!StorageData[id][storageExists]) 
        return Error(playerid, "Storage ID %d tidak terdaftar.", id);

    if(!strcmp(type, "location", true)) {

        GetPlayerPos(playerid, StorageData[id][storagePos][0], StorageData[id][storagePos][1], StorageData[id][storagePos][2]);
        StorageData[id][storageInterior] = GetPlayerInterior(playerid);
        StorageData[id][storageWorld] = GetPlayerVirtualWorld(playerid);

        SaveStorage(id);
        SyncStorage(id);

        Info(playerid, "Anda telah mengatur posisi Storage ID: %d", id);
    }
    else if(!strcmp(type, "delete", true)) {


        mysql_tquery(g_SQL, sprintf("DELETE FROM `storage` WHERE `ID` = '%d'", StorageData[id][storageID]));
        mysql_tquery(g_SQL, sprintf("DELETE FROM `itemstorage` WHERE `StorageID` = '%d'", StorageData[id][storageID]));
        if(IsValidDynamic3DTextLabel(StorageData[id][storageLabel]))
            DestroyDynamic3DTextLabel(StorageData[id][storageLabel]);

        StorageData[id][storageInterior] = 0;
        StorageData[id][storageWorld] = 0;
        StorageData[id][storageID] = 0;
        StorageData[id][storageType] = 0;

    }
    else if(!strcmp(type, "faction", true)) {
        if(sscanf(string, "d", idx))
            return Usage(playerid, "/editstorage [id] [faction] [factionid]");

        if(StorageData[id][storageType] != STORAGE_TYPE_FACTION)
            return Error(playerid, "Storage tersebut bukan tipe faction!");

        StorageData[id][storageExtraID] = idx;
        Info(playerid, "Berhasil mengubah faction Storage ID: %d menjadi %d.", id, idx);
 
        SaveStorage(id);
    }
    else if(!strcmp(type, "house", true)) {
        if(sscanf(string, "d", idx))
            return Usage(playerid, "/editstorage [id] [house] [houseid]");

        if(StorageData[id][storageType] != STORAGE_TYPE_HOUSE)
            return Error(playerid, "Storage tersebut bukan tipe house!");

        if(!Iter_Contains(Houses, idx))
            return Error(playerid, "House ID: %d tidak terdaftar.", idx);

        StorageData[id][storageExtraID] = hData[idx][hOwner];
        Info(playerid, "Berhasil mengubah house Storage ID: %d House ID %d.", id, idx); \
        SaveStorage(id);    
    }
    else if(!strcmp(type, "family", true)) {
        if(sscanf(string, "d", idx))
            return Usage(playerid, "/editstorage [id] [family] [familyid]");

        if(StorageData[id][storageType] != STORAGE_TYPE_FAMILY)
            return Error(playerid, "Storage tersebut bukan tipe family!");

        StorageData[id][storageExtraID] = idx;
        Info(playerid, "Berhasil mengubah family Storage ID: %d menjadi %d.", id, idx);
        SaveStorage(id);
    }
    return 1;
}

ShowStorage(playerid, id, type) {

    if(StorageData[id][storageExists]) {
        SetPVarInt(playerid, "StorageType", type);
        SetPVarInt(playerid, "StorageID", id);

        ShowPlayerDialog(playerid, DIALOG_STORAGE, DIALOG_STYLE_LIST, sprintf("Storage #%d (%s)", id, GetStorageName(StorageData[id][storageType])), "Simpan barang\nAmbil barang", "Select", "Close");
    }
    return 1;
}

ShowStoredItem(playerid) {

    new type = GetPVarInt(playerid, "StorageType"),
        id = GetPVarInt(playerid, "StorageID"),
        Cache:result,
        string[1012],
        count = 0;

    if(type == STORAGE_TYPE_FACTION) {
        result = mysql_query(g_SQL, sprintf("SELECT * FROM `itemstorage` WHERE `StorageID` = '%d' AND `Type` = '%d'", StorageData[id][storageID], type));

        if(cache_num_rows()) {

            
            for(new i = 0; i < cache_num_rows(); i++) {

                new itemname1[24], quantity, sqlid;

                cache_get_value_name(i, "Name", itemname1, sizeof(itemname1));
                cache_get_value_name_int(i, "Quantity", quantity);
                cache_get_value_name_int(i, "ID", sqlid);

                strcat(string, sprintf("%s (Jumlah: %d)\n", itemname1, quantity));

                g_ListedItems[playerid][count++] = sqlid;
            }
            ShowPlayerDialog(playerid, DIALOG_STORAGE_TAKE, DIALOG_STYLE_LIST, "Ambil Barang", string, "Select", "Close");
        }
        else {
            Error(playerid, "Tidak ada barang yang tersimpan.");
        }

        cache_delete(result);
    }
    else if(type == STORAGE_TYPE_FAMILY) {
        result = mysql_query(g_SQL, sprintf("SELECT * FROM `itemstorage` WHERE `StorageID` = '%d' AND `Type` = '%d'",StorageData[id][storageID], type));

        if(cache_num_rows()) {


            for(new i = 0; i < cache_num_rows(); i++) {

                new itemname1[24], quantity, sqlid;

                cache_get_value_name(i, "Name", itemname1, sizeof(itemname1));
                cache_get_value_name_int(i, "Quantity", quantity);
                cache_get_value_name_int(i, "ID", sqlid);

                strcat(string, sprintf("%s (Jumlah: %d)\n", itemname1, quantity));

                g_ListedItems[playerid][count++] = sqlid;
            }
            ShowPlayerDialog(playerid, DIALOG_STORAGE_TAKE, DIALOG_STYLE_LIST, "Ambil Barang", string, "Select", "Close");
        }
        else {
            Error(playerid, "Tidak ada barang yang tersimpan.");
        }

        cache_delete(result);
    }
    else if(type == STORAGE_TYPE_HOUSE) {
        result = mysql_query(g_SQL, sprintf("SELECT * FROM `itemstorage` WHERE `StorageID` = '%d' AND `Type` = '%d' AND `ExtraID` = '%d'", StorageData[id][storageID], type, StorageData[id][storageExtraID]));

        if(cache_num_rows()) {

            
            for(new i = 0; i < cache_num_rows(); i++) {

                new itemname1[24], quantity, sqlid;

                cache_get_value_name(i, "Name", itemname1, sizeof(itemname1));
                cache_get_value_name_int(i, "Quantity", quantity);
                cache_get_value_name_int(i, "ID", sqlid);

                strcat(string, sprintf("%s (Jumlah: %d)\n", itemname1, quantity));

                g_ListedItems[playerid][count++] = sqlid;
            }
            ShowPlayerDialog(playerid, DIALOG_STORAGE_TAKE, DIALOG_STYLE_LIST, "Ambil Barang", string, "Select", "Close");
        }
        else {
            Error(playerid, "Tidak ada barang yang tersimpan.");
        }

        cache_delete(result);
    }
    else if(type == STORAGE_TYPE_PUBLIC) {
        result = mysql_query(g_SQL, sprintf("SELECT * FROM `itemstorage` WHERE `StorageID` = '%d' AND `Type` = '%d' AND `ExtraID` = '%d'", StorageData[id][storageID], type, pData[playerid][pID]));

        if(cache_num_rows()) {

            
            for(new i = 0; i < cache_num_rows(); i++) {

                new itemname1[24], quantity, sqlid;

                cache_get_value_name(i, "Name", itemname1, sizeof(itemname1));
                cache_get_value_name_int(i, "Quantity", quantity);
                cache_get_value_name_int(i, "ID", sqlid);

                strcat(string, sprintf("%s (Jumlah: %d)\n", itemname1, quantity));

                g_ListedItems[playerid][count++] = sqlid;
            }
            ShowPlayerDialog(playerid, DIALOG_STORAGE_TAKE, DIALOG_STYLE_LIST, "Gudang Umum", string, "Select", "Close");
            //ShowPlayerDialog(playerid, DIALOG_STORAGE_TAKE, DIALOG_STYLE_TABLIST_HEADERS, "Gudang Umum", string, "Select", "Close");
        }
        else {
            Error(playerid, "Tidak ada barang yang tersimpan.");
        }

        cache_delete(result);
    }
    return 1;
}

ShowPutItem(playerid) {
    new string[712], count = 0;

    for(new i = 0; i < MAX_INVENTORY; i++) if(InventoryData[playerid][i][invExists]) {

        new itemname1[128];
        strunpack(itemname1, InventoryData[playerid][i][invItem]);
        strcat(string, sprintf("%s (Qty: %d)\n", itemname1, InventoryData[playerid][i][invQuantity]));
        g_ListedItems[playerid][count++] = i;
    }

    return ShowPlayerDialog(playerid, DIALOG_STORAGE_MYITEMS, DIALOG_STYLE_LIST, "Select Item", string, "Select", "Close");
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {

    if(dialogid == DIALOG_STORAGE_TAKE_INPUT) {
        if(response) {

            new amount = strval(inputtext);
            new Cache:result = mysql_query(g_SQL, sprintf("SELECT * FROM `itemstorage` WHERE `ID` = '%d'", GetPVarInt(playerid, "TakeItemID")));
        
            if(amount < 1)
                return ShowPlayerDialog(playerid, DIALOG_STORAGE_TAKE_INPUT, DIALOG_STYLE_INPUT, "Ambil Barang", "Masukkan jumlah barang yang akan kamu ambil", "Ambil", "Tutup");

            if(cache_num_rows()) {
                
                new item_amount, item_name[24], item_model;

                cache_get_value_name_int(0, "Quantity", item_amount);
                cache_get_value_name_int(0, "Model", item_model);
                cache_get_value_name(0, "Name", item_name);

                if(amount > item_amount) {
                    ErrorMsg(playerid, "Jumlah pada storage tidak sesuai!");
                }
                else {

                    if(Inventory_Add(playerid, item_name, item_model, amount) != -1) {
                        item_amount -= amount;


                        if(item_amount < 1) {
                            mysql_tquery(g_SQL, sprintf("DELETE FROM `itemstorage` WHERE `ID` = '%d'", GetPVarInt(playerid, "TakeItemID")));
                        }
                        else {
                            mysql_tquery(g_SQL, sprintf("UPDATE `itemstorage` SET `Quantity` = `Quantity` - '%d' WHERE `ID` = '%d'", amount, GetPVarInt(playerid, "TakeItemID")));
                        }

                        Info(playerid, "Berhasil mengambil %s dari storage.", item_name);
                    }
                }
            }  
            else {
                ErrorMsg(playerid, "Item tidak lagi tersedia.");
            }

            cache_delete(result);
        }
    }
    if(dialogid == DIALOG_STORAGE_TAKE) {
        if(response) {
            new sql_id = g_ListedItems[playerid][listitem];

            SetPVarInt(playerid, "TakeItemID", sql_id);
            ShowPlayerDialog(playerid, DIALOG_STORAGE_TAKE_INPUT, DIALOG_STYLE_INPUT, "Ambil Barang", "Masukkan jumlah barang yang akan kamu ambil", "Ambil", "Tutup");
        }
    }
    if(dialogid == DIALOG_STORAGE_PUT_INPUT) {
        if(response) {
            new amount = strval(inputtext),
                itemid = GetPVarInt(playerid, "SelectItem"),
                type = GetPVarInt(playerid, "StorageType"),
                id = GetPVarInt(playerid, "StorageID");

            if(amount < 1)
                return ShowPlayerDialog(playerid, DIALOG_STORAGE_PUT_INPUT, DIALOG_STYLE_INPUT, "Simpan Barang", sprintf("{FFFFFF}Masukkan jumlah yang ingin kamu simpan (dimiliki: %d)", InventoryData[playerid][itemid][invQuantity]), "Simpan", "Tutup");
        

            new itemname1[128];
            strunpack(itemname1, InventoryData[playerid][itemid][invItem]);

            if(Inventory_Count(playerid, itemname1) < amount)
                return Error(playerid, "Kamu tidak memiliki jumlah sebanyak itu");

            new Cache:result, query[256], sql_id;

            if(type == STORAGE_TYPE_FACTION) {
                mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `itemstorage` WHERE `Model` = '%d' AND `Type` = '%d' AND `StorageID` = '%d' LIMIT 1;", InventoryData[playerid][itemid][invModel], STORAGE_TYPE_FACTION, StorageData[id][storageID]);
                result = mysql_query(g_SQL, query);

                if(cache_num_rows()) {

                    cache_get_value_name_int(0, "ID", sql_id);
                    mysql_format(g_SQL, query, sizeof(query), "UPDATE `itemstorage` SET `Quantity` = `Quantity` + '%d' WHERE `ID` = '%d'", amount, sql_id);
                    mysql_tquery(g_SQL, query);

                    Info(playerid, "Berhasil memasukkan item %s berjumlah %d pada storage faction.", itemname1, amount);
                    Inventory_Remove(playerid, itemname1, amount);
                }
                else {
                    mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `itemstorage` (`Model`, `Quantity`, `StorageID`, `ExtraID`, `Type`, `Name`) VALUES('%d','%d','%d','%d','%d','%e')", 
                    InventoryData[playerid][itemid][invModel], amount, StorageData[id][storageID], StorageData[id][storageExtraID], STORAGE_TYPE_FACTION, itemname1);
                    mysql_tquery(g_SQL, query);
                    Info(playerid, "Berhasil memasukkan item %s berjumlah %d pada storage faction.", itemname1, amount);
                    Inventory_Remove(playerid, itemname1, amount);
                }

                cache_delete(result);
            }
            else if(type == STORAGE_TYPE_FAMILY) {
                mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `itemstorage` WHERE `Model` = '%d' AND `Type` = '%d' AND `StorageID` = '%d' LIMIT 1;", InventoryData[playerid][itemid][invModel], STORAGE_TYPE_FAMILY, StorageData[id][storageID]);
                result = mysql_query(g_SQL, query);

                if(cache_num_rows()) {

                    cache_get_value_name_int(0, "ID", sql_id);
                    mysql_format(g_SQL, query, sizeof(query), "UPDATE `itemstorage` SET `Quantity` = `Quantity` + '%d' WHERE `ID` = '%d'", amount, sql_id);
                    mysql_tquery(g_SQL, query);

                    Info(playerid, "Berhasil memasukkan item %s berjumlah %d pada storage family.", itemname1, amount);
                    Inventory_Remove(playerid, itemname1, amount);
                }
                else {
                    mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `itemstorage` (`Model`, `Quantity`, `StorageID`, `ExtraID`, `Type`, `Name`) VALUES('%d','%d','%d','%d','%d','%e')", 
                    InventoryData[playerid][itemid][invModel], amount, StorageData[id][storageID], StorageData[id][storageExtraID], STORAGE_TYPE_FAMILY, itemname1);
                    mysql_tquery(g_SQL, query);
                    Info(playerid, "Berhasil memasukkan item %s berjumlah %d pada storage family.", itemname1, amount);
                    Inventory_Remove(playerid, itemname1, amount);
                }

                cache_delete(result);                
            }
            else if(type == STORAGE_TYPE_HOUSE) {
                mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `itemstorage` WHERE `Model` = '%d' AND `Type` = '%d' AND `StorageID` = '%d' AND `ExtraID` = '%d' LIMIT 1;", InventoryData[playerid][itemid][invModel], STORAGE_TYPE_HOUSE, StorageData[id][storageID], StorageData[id][storageExtraID]);
                result = mysql_query(g_SQL, query);

                if(cache_num_rows()) {

                    cache_get_value_name_int(0, "ID", sql_id);
                    mysql_format(g_SQL, query, sizeof(query), "UPDATE `itemstorage` SET `Quantity` = `Quantity` + '%d' WHERE `ID` = '%d'", amount, sql_id);
                    mysql_tquery(g_SQL, query);

                    Info(playerid, "Berhasil memasukkan item %s berjumlah %d pada storage rumah.", itemname1, amount);
                    Inventory_Remove(playerid, itemname1, amount);
                }
                else {
                    mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `itemstorage` (`Model`, `Quantity`, `StorageID`, `ExtraID`, `Type`, `Name`) VALUES('%d','%d','%d','%d','%d','%e')", 
                        InventoryData[playerid][itemid][invModel], amount, StorageData[id][storageID], StorageData[id][storageExtraID], STORAGE_TYPE_HOUSE, itemname1);
                    
                    mysql_tquery(g_SQL, query);
                    Info(playerid, "Berhasil memasukkan item %s berjumlah %d pada storage rumah.", itemname1, amount);
                    Inventory_Remove(playerid, itemname1, amount);
                }

                cache_delete(result);
            }
            else if(type == STORAGE_TYPE_PUBLIC) {
                mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `itemstorage` WHERE `Model` = '%d' AND `Type` = '%d' AND `StorageID` = '%d' AND `ExtraID` = '%d' LIMIT 1;", InventoryData[playerid][itemid][invModel], STORAGE_TYPE_PUBLIC, StorageData[id][storageID], pData[playerid][pID]);
                result = mysql_query(g_SQL, query);

                if(cache_num_rows()) {

                    cache_get_value_name_int(0, "ID", sql_id);
                    mysql_format(g_SQL, query, sizeof(query), "UPDATE `itemstorage` SET `Quantity` = `Quantity` + '%d' WHERE `ID` = '%d'", amount, sql_id);
                    mysql_tquery(g_SQL, query);

                    Info(playerid, "Berhasil memasukkan item %s berjumlah %d pada storage public.", itemname1, amount);
                    Inventory_Remove(playerid, itemname1, amount);
                }
                else {
                    mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `itemstorage` (`Model`, `Quantity`, `StorageID`, `ExtraID`, `Type`, `Name`) VALUES('%d','%d','%d','%d','%d','%e')", 
                        InventoryData[playerid][itemid][invModel], amount, StorageData[id][storageID], pData[playerid][pID], STORAGE_TYPE_PUBLIC, itemname1);
                    
                    mysql_tquery(g_SQL, query);
                    Info(playerid, "Berhasil memasukkan item %s berjumlah %d pada storage public.", itemname1, amount);
                    Inventory_Remove(playerid, itemname1, amount);
                }

                cache_delete(result); 
            }
        }
    }
    if(dialogid == DIALOG_STORAGE_MYITEMS) {
        if(response) {
            SetPVarInt(playerid, "SelectItem", g_ListedItems[playerid][listitem]);

            ShowPlayerDialog(playerid, DIALOG_STORAGE_PUT_INPUT, DIALOG_STYLE_INPUT, "Simpan Barang", sprintf("{FFFFFF}Masukkan jumlah yang ingin kamu simpan (dimiliki: %d)", InventoryData[playerid][g_ListedItems[playerid][listitem]][invQuantity]), "Simpan", "Tutup");
        }
    }
    if(dialogid == DIALOG_STORAGE) {
        if(response) {
            if(listitem == 0) {
                ShowPutItem(playerid);
            }
            if(listitem == 1) {
                ShowStoredItem(playerid);
            }
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if((newkeys & KEY_YES)) {
        new id, index;

        if((id = GetNearestStorage(playerid)) != -1) {

            if(StorageData[id][storageType] == STORAGE_TYPE_FACTION && StorageData[id][storageExtraID] == -1) {
                return Error(playerid, "Faction ID belum diatur!");
            }
            if(StorageData[id][storageType] == STORAGE_TYPE_FAMILY && StorageData[id][storageExtraID] == -1) {
                return Error(playerid, "Family ID belum di atur!");
            }
            if(StorageData[id][storageType] == STORAGE_TYPE_HOUSE && StorageData[id][storageExtraID] == -1) {
                return Error(playerid, "House ID belum diatur!");
            }

            if(StorageData[id][storageType] == STORAGE_TYPE_FACTION) {
                
                //index = GetFactionByID(StorageData[id][storageExtraID]);
                index = StorageData[id][storageExtraID];

                if(index == -1) {
                    return Error(playerid, "Tidak dapat mengakses storage! (001)");
                }

                if(pData[playerid][pFaction] != index)
                    return Error(playerid, "Anda tidak memiliki akses!");

                ShowStorage(playerid, id, STORAGE_TYPE_FACTION);
            }
            else if(StorageData[id][storageType] == STORAGE_TYPE_FAMILY)
            {
                index = StorageData[id][storageExtraID];

                if(index == -1) {
                    return Error(playerid, "Tidak dapat mengakses storage! (001)");
                }

                if(pData[playerid][pFamily] != index)
                    return Error(playerid, "Anda tidak memiliki akses!");

                if(pData[playerid][pFamilyRank] < 3)
                    return Error(playerid, "Anda harus menjadi bagian dari Insider (3)");

                ShowStorage(playerid, id, STORAGE_TYPE_FAMILY);
            }
            else if(StorageData[id][storageType] == STORAGE_TYPE_HOUSE) 
            {      
                ShowStorage(playerid, id, STORAGE_TYPE_HOUSE);
            }
            else if(StorageData[id][storageType] == STORAGE_TYPE_PUBLIC) {

                ShowStorage(playerid, id, STORAGE_TYPE_PUBLIC);
            }
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}