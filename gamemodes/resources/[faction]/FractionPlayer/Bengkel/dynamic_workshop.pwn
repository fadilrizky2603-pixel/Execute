#include <YSI\y_hooks>
#include <streamer>

#define MAX_DYNAMIC_WORKSHOPS 50
#define DIALOG_WORKSHOP_MENU 1000
#define DIALOG_WORKSHOP_PAINT 1001
#define DIALOG_WORKSHOP_MODS 1002
#define DIALOG_WORKSHOP_SETTINGS 1003
#define DIALOG_WORKSHOP_EMPLOYEES 1004
#define DIALOG_WORKSHOP_INVENTORY 1005
#define DIALOG_WORKSHOP_EXHAUST 1006
#define DIALOG_WORKSHOP_FBUMPER 1007
#define DIALOG_WORKSHOP_RBUMPER 1008
#define DIALOG_WORKSHOP_ROOF 1009
#define DIALOG_WORKSHOP_SKIRTS 1010
#define DIALOG_WORKSHOP_WHEELS 1011
#define DIALOG_WORKSHOP_LIGHTS 1012
#define DIALOG_WORKSHOP_PAINT_COLOR1 1013
#define DIALOG_WORKSHOP_PAINT_COLOR2 1014
#define DIALOG_WORKSHOP_PAINT_BOTH 1015
#define DIALOG_WORKSHOP_SPOILER 1016
#define DIALOG_WORKSHOP_HOOD 1017
#define DIALOG_WORKSHOP_VENT 1018
#define DIALOG_WORKSHOP_BULLBARS 1019
#define DIALOG_WORKSHOP_HYDRAULICS 1020
#define DIALOG_WORKSHOP_PAINTJOB 1021
#define DIALOG_WORKSHOP_COLOR 1022
#define DIALOG_WORKSHOP_NEON 1023
#define DIALOG_WORKSHOP_NITRO 1024

// Car modification types
#define CARMODTYPE_SPOILER 0
#define CARMODTYPE_HOOD 1
#define CARMODTYPE_ROOF 2
#define CARMODTYPE_SIDE_SKIRT 3
#define CARMODTYPE_LAMPS 4
#define CARMODTYPE_NITRO 5
#define CARMODTYPE_EXHAUST 6
#define CARMODTYPE_WHEELS 7
#define CARMODTYPE_STEREO 8
#define CARMODTYPE_HYDRAULICS 9
#define CARMODTYPE_FRONT_BUMPER 10
#define CARMODTYPE_REAR_BUMPER 11
#define CARMODTYPE_VENT 12
#define CARMODTYPE_BULLBARS 13
#define CARMODTYPE_LIGHT 14
#define CARMODTYPE_NEON 15

enum E_WORKSHOP_DATA {
    workshop_id,
    workshop_name[128],
    workshop_owner,
    Float:workshop_x,
    Float:workshop_y,
    Float:workshop_z,
    workshop_interior,
    workshop_vw,
    workshop_price,
    workshop_reputation,
    workshop_income,
    workshop_employees,
    workshop_max_employees,
    workshop_status,
    workshop_pickup,
    workshop_mapicon,
    Text3D:workshop_label
}

new WorkshopData[MAX_DYNAMIC_WORKSHOPS][E_WORKSHOP_DATA];
new WorkshopCount = 0;

// Workshop types and their prices
enum {
    WORKSHOP_TYPE_BASIC = 1,
    WORKSHOP_TYPE_STANDARD,
    WORKSHOP_TYPE_PREMIUM
}

new const WorkshopPrices[] = {
    0, // WORKSHOP_TYPE_BASIC (unused)
    500000, // WORKSHOP_TYPE_STANDARD
    1000000 // WORKSHOP_TYPE_PREMIUM
};

// Load all workshops from database
function LoadDynamicWorkshops()
{
    new query[256];
    mysql_format(dcrp_query, query, sizeof(query), "SELECT * FROM dynamic_workshops");
    mysql_tquery(dcrp_query, query, "OnWorkshopsLoaded", "");
    printf("[Workshop] Attempting to load workshops from database...");
    return 1;
}

// Callback when workshops are loaded
function OnWorkshopsLoaded()
{
    new rows = cache_num_rows();
    printf("[Workshop] Found %d workshops in database", rows);
    
    if(rows > 0)
    {
        for(new i = 0; i < rows && i < MAX_DYNAMIC_WORKSHOPS; i++)
        {
            cache_get_value_name_int(i, "id", WorkshopData[i][workshop_id]);
            cache_get_value_name(i, "name", WorkshopData[i][workshop_name], 128);
            cache_get_value_name_int(i, "owner", WorkshopData[i][workshop_owner]);
            cache_get_value_name_float(i, "x", WorkshopData[i][workshop_x]);
            cache_get_value_name_float(i, "y", WorkshopData[i][workshop_y]);
            cache_get_value_name_float(i, "z", WorkshopData[i][workshop_z]);
            cache_get_value_name_int(i, "interior", WorkshopData[i][workshop_interior]);
            cache_get_value_name_int(i, "virtual_world", WorkshopData[i][workshop_vw]);
            cache_get_value_name_int(i, "price", WorkshopData[i][workshop_price]);
            cache_get_value_name_int(i, "reputation", WorkshopData[i][workshop_reputation]);
            cache_get_value_name_int(i, "income", WorkshopData[i][workshop_income]);
            cache_get_value_name_int(i, "employees", WorkshopData[i][workshop_employees]);
            cache_get_value_name_int(i, "max_employees", WorkshopData[i][workshop_max_employees]);
            cache_get_value_name_int(i, "status", WorkshopData[i][workshop_status]);

            // Create pickup and map icon
            WorkshopData[i][workshop_pickup] = CreateDynamicPickup(1239, 1, WorkshopData[i][workshop_x], WorkshopData[i][workshop_y], WorkshopData[i][workshop_z], WorkshopData[i][workshop_vw], WorkshopData[i][workshop_interior]);
            WorkshopData[i][workshop_mapicon] = CreateDynamicMapIcon(WorkshopData[i][workshop_x], WorkshopData[i][workshop_y], WorkshopData[i][workshop_z], 55, COLOR_YELLOW, WorkshopData[i][workshop_vw], WorkshopData[i][workshop_interior]);
            
            // Create 3D text label
            new label[256];
            format(label, sizeof(label), "Workshop: %s\nOwner: %s\nStatus: %s\nPress Y to enter", 
                WorkshopData[i][workshop_name],
                WorkshopData[i][workshop_owner] ? ReturnName(WorkshopData[i][workshop_owner]) : "None",
                WorkshopData[i][workshop_status] ? "Open" : "Closed"
            );
            WorkshopData[i][workshop_label] = CreateDynamic3DTextLabel(label, COLOR_YELLOW, WorkshopData[i][workshop_x], WorkshopData[i][workshop_y], WorkshopData[i][workshop_z], 10.0);
            
            printf("[Workshop] Loaded workshop ID: %d, Name: %s", WorkshopData[i][workshop_id], WorkshopData[i][workshop_name]);
        }
        WorkshopCount = rows;
        printf("[Workshop] Successfully loaded %d dynamic workshops", WorkshopCount);
    }
    return 1;
}

// Create a new workshop
CMD:createworkshop(playerid, params[])
{
    if(CheckAdmin(playerid, 6))
        return PermissionError(playerid);
        
    new type, price;
    if(sscanf(params, "dd", type, price))
        return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/createworkshop [type] [price]\nTypes: 1-Basic, 2-Standard, 3-Premium");
        
    if(type < 1 || type > 3)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid workshop type!");
        
    if(WorkshopCount >= MAX_DYNAMIC_WORKSHOPS)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Maximum number of workshops reached!");
        
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    
    new query[512];
    mysql_format(dcrp_query, query, sizeof(query), "INSERT INTO dynamic_workshops (name, x, y, z, interior, virtual_world, price) VALUES ('Workshop %d', %f, %f, %f, %d, %d, %d)",
        WorkshopCount + 1, x, y, z, GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid), WorkshopPrices[type]);
    mysql_tquery(dcrp_query, query, "OnWorkshopCreated", "ii", playerid, type);
    return 1;
}

// Callback when workshop is created
function OnWorkshopCreated(playerid, type)
{
    new id = cache_insert_id();
    if(id)
    {
        WorkshopData[WorkshopCount][workshop_id] = id;
        format(WorkshopData[WorkshopCount][workshop_name], 128, "Workshop %d", WorkshopCount + 1);
        GetPlayerPos(playerid, WorkshopData[WorkshopCount][workshop_x], WorkshopData[WorkshopCount][workshop_y], WorkshopData[WorkshopCount][workshop_z]);
        WorkshopData[WorkshopCount][workshop_interior] = GetPlayerInterior(playerid);
        WorkshopData[WorkshopCount][workshop_vw] = GetPlayerVirtualWorld(playerid);
        WorkshopData[WorkshopCount][workshop_price] = WorkshopPrices[type];
        WorkshopData[WorkshopCount][workshop_status] = 1;
        
        // Create pickup and map icon
        WorkshopData[WorkshopCount][workshop_pickup] = CreateDynamicPickup(1239, 1, WorkshopData[WorkshopCount][workshop_x], WorkshopData[WorkshopCount][workshop_y], WorkshopData[WorkshopCount][workshop_z], WorkshopData[WorkshopCount][workshop_vw], WorkshopData[WorkshopCount][workshop_interior]);
        WorkshopData[WorkshopCount][workshop_mapicon] = CreateDynamicMapIcon(WorkshopData[WorkshopCount][workshop_x], WorkshopData[WorkshopCount][workshop_y], WorkshopData[WorkshopCount][workshop_z], 55, COLOR_YELLOW, WorkshopData[WorkshopCount][workshop_vw], WorkshopData[WorkshopCount][workshop_interior]);
        
        // Create 3D text label
        new label[256];
        format(label, sizeof(label), "Workshop: %s\nOwner: None\nStatus: Open\nPress Y to enter", WorkshopData[WorkshopCount][workshop_name]);
        WorkshopData[WorkshopCount][workshop_label] = CreateDynamic3DTextLabel(label, COLOR_YELLOW, WorkshopData[WorkshopCount][workshop_x], WorkshopData[WorkshopCount][workshop_y], WorkshopData[WorkshopCount][workshop_z], 10.0);
        
        WorkshopCount++;
        ShowTDN(playerid, NOTIFICATION_SUKSES, "Workshop created successfully!");
    }
    return 1;
}

// Buy a workshop
CMD:buyworkshop(playerid, params[])
{
    new workshopid;
    if(sscanf(params, "d", workshopid))
        return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/buyworkshop [id]");
        
    if(workshopid < 0 || workshopid >= WorkshopCount)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid workshop ID!");
        
    if(WorkshopData[workshopid][workshop_owner] != 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "This workshop is already owned!");
        
    if(AccountData[playerid][pMoney] < WorkshopData[workshopid][workshop_price])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "You don't have enough money!");
        
    new query[256];
    mysql_format(dcrp_query, query, sizeof(query), "UPDATE dynamic_workshops SET owner = %d WHERE id = %d", AccountData[playerid][pID], WorkshopData[workshopid][workshop_id]);
    mysql_tquery(dcrp_query, query, "OnWorkshopBought", "ii", playerid, workshopid);
    return 1;
}

// Callback when workshop is bought
function OnWorkshopBought(playerid, workshopid)
{
    WorkshopData[workshopid][workshop_owner] = AccountData[playerid][pID];
    AccountData[playerid][pMoney] -= WorkshopData[workshopid][workshop_price];
    
    // Update 3D text label
    new label[256];
    format(label, sizeof(label), "Workshop: %s\nOwner: %s\nStatus: %s\nPress Y to enter", 
        WorkshopData[workshopid][workshop_name],
        ReturnName(playerid),
        WorkshopData[workshopid][workshop_status] ? "Open" : "Closed"
    );
    UpdateDynamic3DTextLabelText(WorkshopData[workshopid][workshop_label], COLOR_YELLOW, label);
    
    ShowTDN(playerid, NOTIFICATION_SUKSES, "You have successfully bought this workshop!");
    return 1;
}

// Workshop menu
CMD:workshop(playerid, params[])
{
    new workshopid = GetPlayerWorkshop(playerid);
    if(workshopid == -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada di dalam workshop!");
        
    if(WorkshopData[workshopid][workshop_owner] != AccountData[playerid][pID])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan pemilik workshop ini!");
        
    new string[512];
    format(string, sizeof(string), "Spoiler\n\n\
                                    Velg\n\
                                    Hood\n\
                                    Vent\n\
                                    Roof\n\
                                    Bumper Depan\n\
                                    Bumper Belakang\n\
                                    Exhaulis\n\
                                    Sideskirt\n\
                                    Bullbars\n\
                                    Stereo\n\
                                    Light\n\
                                    Hydrolik\n\
                                    Paint job\n\
                                    Repair\n\
                                    Ganti Warna\n\
                                    Neon\n\
                                    Pilih Nitro");
    ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
    return 1;
}

// Get player's current workshop
stock GetPlayerWorkshop(playerid)
{
    for(new i = 0; i < WorkshopCount; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, WorkshopData[i][workshop_x], WorkshopData[i][workshop_y], WorkshopData[i][workshop_z]))
        {
            return i;
        }
    }
    return -1;
}

// Hook for dialog response
hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    new string[512];
    new workshopid = GetPlayerWorkshop(playerid);
    new vehicleid = GetPlayerVehicleID(playerid);
    new price;

    if(dialogid == DIALOG_WORKSHOP_MENU)
    {
        if(!response) return 1;
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
            
        if(!IsValidVehicle(vehicleid))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan tidak valid!");
        
        switch(listitem)
        {
            case 0: // Spoiler
            {
                format(string, sizeof(string), "Pilih Spoiler\n\n\
                Spoiler 1\n\
                Spoiler 2\n\
                Spoiler 3\n\
                Spoiler 4\n\
                Hapus");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_SPOILER, DIALOG_STYLE_LIST, "Pilih Spoiler", string, "Pilih", "Kembali");
            }
            case 1: // Velg
            {
                format(string, sizeof(string), "Normal\n\n\
                Velg 1\n\
                Velg 2\n\
                Velg 3\n\
                Velg 4\n\
                Hapus");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_WHEELS, DIALOG_STYLE_LIST, "Pilih Velg", string, "Pilih", "Kembali");
            }
            case 2: // Hood
            {
                format(string, sizeof(string), "Pilih Hood\n\n\
                Hood Sport 1\n\
                Hood Sport 2\n\
                Hood Sport 3\n\
                Hapus");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_HOOD, DIALOG_STYLE_LIST, "Pilih Hood", string, "Pilih", "Kembali");
            }
            case 3: // Vent
            {
                format(string, sizeof(string), "Pilih Vent\n\n\
                Vent Sport 1\n\
                Vent Sport 2\n\
                Vent Sport 3\n\
                Hapus");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_VENT, DIALOG_STYLE_LIST, "Pilih Vent", string, "Pilih", "Kembali");
            }
            case 4: // Roof
            {
                format(string, sizeof(string), "Pilih Roof\n\n\
                Roof Sport 1\n\
                Roof Sport 2\n\
                Roof Sport 3\n\
                Roof Sport 4\n\
                Hapus Roof - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_ROOF, DIALOG_STYLE_LIST, "Pilih Roof", string, "Pilih", "Kembali");
            }
            case 5: // Bumper Depan
            {
                format(string, sizeof(string), "Pilih Bumper Depan\n\n\
                Bumper Sport 1\n\
                Bumper Sport 2\n\
                Bumper Sport 3\n\
                Bumper Sport 4\n\
                Hapus Bumper - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_FBUMPER, DIALOG_STYLE_LIST, "Pilih Bumper Depan", string, "Pilih", "Kembali");
            }
            case 6: // Bumper Belakang
            {
                format(string, sizeof(string), "Pilih Bumper Belakang\n\n\
                Bumper Sport 1\n\
                Bumper Sport 2\n\
                Bumper Sport 3\n\
                Bumper Sport 4\n\
                Hapus Bumper - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_RBUMPER, DIALOG_STYLE_LIST, "Pilih Bumper Belakang", string, "Pilih", "Kembali");
            }
            case 7: // Exhaulis
            {
                format(string, sizeof(string), "Pilih Exhaulis\n\n\
                Exhaulis Sport 1\n\
                Exhaulis Sport 2\n\
                Exhaulis Sport 3\n\
                Exhaulis Sport 4\n\
                Hapus Exhaulis - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_EXHAUST, DIALOG_STYLE_LIST, "Pilih Exhaulis", string, "Pilih", "Kembali");
            }
            case 8: // Sideskirt
            {
                format(string, sizeof(string), "Pilih Sideskirt\n\n\
                Sideskirt Sport 1\n\
                Sideskirt Sport 2\n\
                Sideskirt Sport 3\n\
                Sideskirt Sport 4\n\
                Hapus Sideskirt - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_SKIRTS, DIALOG_STYLE_LIST, "Pilih Sideskirt", string, "Pilih", "Kembali");
            }
            case 9: // Bullbars
            {
                format(string, sizeof(string), "Pilih Bullbars\n\n\
                Bullbars 1\n\
                Bullbars 2\n\
                Bullbars 3\n\
                Bullbars 4\n\
                Hapus Bullbars - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_BULLBARS, DIALOG_STYLE_LIST, "Pilih Bullbars", string, "Pilih", "Kembali");
            }
            case 10: // Stereo
            {
                format(string, sizeof(string), "Pilih Stereo\n\n\
                Stereo Bass\n\
                Hapus Stereo - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_LIGHTS, DIALOG_STYLE_LIST, "Pilih Stereo", string, "Pilih", "Kembali");
            }
            case 11: // Light
            {
                format(string, sizeof(string), "Pilih Light\n\n\
                Light Sport 1\n\
                Light Sport 2\n\
                Light Sport 3\n\
                Hapus Light - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_LIGHTS, DIALOG_STYLE_LIST, "Pilih Light", string, "Pilih", "Kembali");
            }
            case 12: // Hydrolik
            {
                format(string, sizeof(string), "Pilih Hydrolik\n\n\
                Hydrolik Sport\n\
                Hapus Hydrolik - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_HYDRAULICS, DIALOG_STYLE_LIST, "Pilih Hydrolik", string, "Pilih", "Kembali");
            }
            case 13: // Paint job
            {
                format(string, sizeof(string), "Pilih Paint Job\n\n\
                Paint Job 1\n\
                Paint Job 2\n\
                Paint Job 3\n\
                Hapus Paint Job - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_PAINTJOB, DIALOG_STYLE_LIST, "Pilih Paint Job", string, "Pilih", "Kembali");
            }
            case 14: // Repair
            {
                price = 400;
                if(AccountData[playerid][pMoney] < price)
                    return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
                    
                RepairVehicle(vehicleid);
                AccountData[playerid][pMoney] -= price;
                WorkshopData[workshopid][workshop_income] += price;
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Kendaraan berhasil diperbaiki!");
            }
            case 15: // Ganti Warna
            {
                format(string, sizeof(string), "Pilih Warna\n\n\
                Hitam\n\
                Putih\n\
                Merah\n\
                Biru\n\
                Hijau\n\
                Kuning\n\
                Ungu\n\
                Oranye");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_COLOR, DIALOG_STYLE_LIST, "Pilih Warna", string, "Pilih", "Kembali");
            }
            case 16: // Neon
            {
                format(string, sizeof(string), "Pilih Neon\n\n\
                Neon Merah\n\
                Neon Biru\n\
                Neon Hijau\n\
                Neon Kuning\n\
                Neon Pink\n\
                Neon Putih\n\
                Hapus Neon - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_NEON, DIALOG_STYLE_LIST, "Pilih Neon", string, "Pilih", "Kembali");
            }
            case 17: // Nitro
            {
                format(string, sizeof(string), "Pilih Nitro\n\n\
                Nitro Level 1\n\
                Nitro Level 2\n\
                Nitro Level 3\n\
                Hapus Nitro - $0");
                ShowPlayerDialog(playerid, DIALOG_WORKSHOP_NITRO, DIALOG_STYLE_LIST, "Pilih Nitro", string, "Pilih", "Kembali");
            }
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_SPOILER)
    {
        if(!response) 
        {
            format(string, sizeof(string), "Bengkel Menu\n\n\
                                                Velg\n\
                                                Hood\n\
                                                Vent\n\
                                                Roof\n\
                                                Bumper Depan\n\
                                                Bumper Belakang\n\
                                                Exhaulis\n\
                                                Sideskirt\n\
                                                Bullbars\n\
                                                Stereo\n\
                                                Light\n\
                                                Hydrolik\n\
                                                Paint job\n\
                                                Repair\n\
                                                Ganti Warna\n\
                                                Neon\n\
                                                Pilih Nitro");
            return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        }
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
            
        price = 1700;
        if(listitem == 5) // Hapus Spoiler
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_SPOILER));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Spoiler berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        new spoiler_components[] = {1000, 1001, 1002, 1003, 1014};
        if(listitem < sizeof(spoiler_components))
        {
            AddVehicleComponent(vehicleid, spoiler_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Spoiler berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_WHEELS)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
        
        price = 900;
        if(listitem == 5) // Hapus Velg
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_WHEELS));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Velg berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        new wheels_components[] = {1025, 1073, 1074, 1075, 1076};
        if(listitem < sizeof(wheels_components))
        {
            AddVehicleComponent(vehicleid, wheels_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Velg berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_HOOD)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
        
        price = 700;
        if(listitem == 4) // Hapus Hood
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_HOOD));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Hood berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        new hood_components[] = {1004, 1005, 1011, 1012};
        if(listitem < sizeof(hood_components))
        {
            AddVehicleComponent(vehicleid, hood_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Hood berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_VENT)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
        
        price = 700;
        if(listitem == 4) // Hapus Vent
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_VENT));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Vent berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        new vent_components[] = {1142, 1143, 1144, 1145};
        if(listitem < sizeof(vent_components))
        {
            AddVehicleComponent(vehicleid, vent_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Vent berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_ROOF)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
        
        price = 700;
        if(listitem == 4) // Hapus Roof
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_ROOF));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Roof berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        new roof_components[] = {1006, 1032, 1033, 1035, 1038};
        if(listitem < sizeof(roof_components))
        {
            AddVehicleComponent(vehicleid, roof_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Roof berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_FBUMPER)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
        
        price = 1700;
        if(listitem == 4) // Hapus Bumper Depan
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_FRONT_BUMPER));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Bumper Depan berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
        
        new fbumper_components[] = {1115, 1116, 1117, 1118, 1119};
        if(listitem < sizeof(fbumper_components))
        {
            AddVehicleComponent(vehicleid, fbumper_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Bumper Depan berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_RBUMPER)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
        
        price = 1700;
        if(listitem == 4) // Hapus Bumper Belakang
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_REAR_BUMPER));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Bumper Belakang berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
        
        new rbumper_components[] = {1140, 1141, 1142, 1143, 1144};
        if(listitem < sizeof(rbumper_components))
        {
            AddVehicleComponent(vehicleid, rbumper_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Bumper Belakang berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_EXHAUST)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "You must be in a vehicle!");
        
        price = 700;
        if(listitem == 4) // Hapus Exhaust
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_EXHAUST));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Exhaust system berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        new exhaust_components[] = {1020, 1021, 1022, 1023, 1024};
        if(listitem < sizeof(exhaust_components))
        {
            AddVehicleComponent(vehicleid, exhaust_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Exhaust system berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_SKIRTS)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "You must be in a vehicle!");
        
        price = 700;
        if(listitem == 4) // Hapus Sideskirt
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_SIDE_SKIRT));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Sideskirt berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
        
        new skirts_components[] = {1007, 1026, 1031, 1036, 1039};
        if(listitem < sizeof(skirts_components))
        {
            AddVehicleComponent(vehicleid, skirts_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Sideskirt berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_BULLBARS)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "You must be in a vehicle!");
        
        price = 700;
        if(listitem == 4) // Hapus Bullbars
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_BULLBARS));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Bullbars berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        new bullbar_components[] = {1100, 1101, 1102, 1103, 1104, 1105};
        if(listitem < sizeof(bullbar_components))
        {
            AddVehicleComponent(vehicleid, bullbar_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Bullbars berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_LIGHTS)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "You must be in a vehicle!");
        
        price = 500;
        if(listitem == 2) // Hapus Light
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_LIGHT));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Light berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        new light_components[] = {1013, 1024};
        if(listitem < sizeof(light_components))
        {
            AddVehicleComponent(vehicleid, light_components[listitem]);
            AccountData[playerid][pMoney] -= price;
            WorkshopData[workshopid][workshop_income] += price;
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Light berhasil dipasang!");
        }
    }
    else if(dialogid == DIALOG_WORKSHOP_HYDRAULICS)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "You must be in a vehicle!");
        
        price = 1200;
        if(listitem == 1) // Hapus Hydrolik
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_HYDRAULICS));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Hydrolik berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        AddVehicleComponent(vehicleid, 1087);
        AccountData[playerid][pMoney] -= price;
        WorkshopData[workshopid][workshop_income] += price;
        ShowTDN(playerid, NOTIFICATION_SUKSES, "Hydrolik berhasil dipasang!");
    }
    else if(dialogid == DIALOG_WORKSHOP_PAINTJOB)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
        
        price = 2100;
        if(listitem == 2) // Hapus Paint Job
        {
            ChangeVehiclePaintjob(vehicleid, 0);
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Paint job berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        new paintjob = random(3);
        ChangeVehiclePaintjob(vehicleid, paintjob);
        AccountData[playerid][pMoney] -= price;
        WorkshopData[workshopid][workshop_income] += price;
        ShowTDN(playerid, NOTIFICATION_SUKSES, "Paint job berhasil dipasang!");
    }
    else if(dialogid == DIALOG_WORKSHOP_COLOR)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
        
        price = 700;
        new color1 = random(255);
        new color2 = random(255);
        ChangeVehicleColor(vehicleid, color1, color2);
        AccountData[playerid][pMoney] -= price;
        WorkshopData[workshopid][workshop_income] += price;
        ShowTDN(playerid, NOTIFICATION_SUKSES, "Warna kendaraan berhasil diubah!");
    }
    else if(dialogid == DIALOG_WORKSHOP_NEON)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");
        
        price = 11000;
        if(listitem == 6) // Hapus Neon
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_NEON));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Neon berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        AddVehicleComponent(vehicleid, 1010);
        AccountData[playerid][pMoney] -= price;
        WorkshopData[workshopid][workshop_income] += price;
        ShowTDN(playerid, NOTIFICATION_SUKSES, "Neon berhasil dipasang!");
    }
    else if(dialogid == DIALOG_WORKSHOP_NITRO)
    {
        if(!response) return ShowPlayerDialog(playerid, DIALOG_WORKSHOP_MENU, DIALOG_STYLE_LIST, "Bengkel Menu", string, "Pilih", "Batal");
        
        if(workshopid == -1) return 1;
        
        if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "You must be in a vehicle!");
        
        price = 3800;
        if(listitem == 3) // Hapus Nitro
        {
            RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, CARMODTYPE_NITRO));
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Nitro berhasil dihapus!");
            return 1;
        }
        
        if(AccountData[playerid][pMoney] < price)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang Anda tidak cukup!");
            
        AddVehicleComponent(vehicleid, 1008);
        AccountData[playerid][pMoney] -= price;
        WorkshopData[workshopid][workshop_income] += price;
        ShowTDN(playerid, NOTIFICATION_SUKSES, "Nitro berhasil dipasang!");
    }
    return 1;
}

// Initialize
hook OnGameModeInit()
{
    SetTimer("LoadDynamicWorkshops", 1000, false); // Delay loading by 1 second to ensure database connection is ready
    return 1;
}

// Cleanup
hook OnGameModeExit()
{
    for(new i = 0; i < WorkshopCount; i++)
    {
        if(WorkshopData[i][workshop_pickup] != -1)
            DestroyDynamicPickup(WorkshopData[i][workshop_pickup]);
            
        if(WorkshopData[i][workshop_mapicon] != -1)
            DestroyDynamicMapIcon(WorkshopData[i][workshop_mapicon]);
            
        if(WorkshopData[i][workshop_label] != Text3D:0)
            DestroyDynamic3DTextLabel(WorkshopData[i][workshop_label]);
    }
    return 1;
} 