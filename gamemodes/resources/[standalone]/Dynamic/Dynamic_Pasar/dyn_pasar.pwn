#include <YSI\y_hooks>
#define MAX_PASAR   20

enum e_pasar
{
    Float:paDCRPos[3],
    pasarType,
    pasarInt,
    pasarWorld,
    Text3D:pasarLabel,
    STREAMER_TAG_AREA:pasarArea,
}
new PasarData[MAX_PASAR][e_pasar],
    Iterator:PASAR<MAX_PASAR>;

forward LoadPasar();
public LoadPasar()
{
    new id, rows = cache_num_rows();
    if(rows)
    {
        for(new i = 0; i < rows; i ++)
        {
            id = cache_get_field_int(i, "id");
            PasarData[id][paDCRPos][0] = cache_get_field_float(i, "posx");
			PasarData[id][paDCRPos][1] = cache_get_field_float(i, "posy");
			PasarData[id][paDCRPos][2] = cache_get_field_float(i, "posz");
			PasarData[id][pasarType] = cache_get_field_int(i, "type");
			PasarData[id][pasarInt] = cache_get_field_int(i, "interior");
			PasarData[id][pasarWorld] = cache_get_field_int(i, "world");
            
            Iter_Add(PASAR, id);
            Pasar_Refresh(id);
        }
        printf("[Dynamic PASAR]: Jumlah total Pasar yang dimuat %d", rows);
    }
    return 1;
}

Pasar_Refresh(id)
{
    if(id != -1)
    {
        if(PasarData[id][pasarType] == 1)
        {
            PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Susu Olahan", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
        }
        else if(PasarData[id][pasarType] == 2)
        {
            PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Hasil Tambang", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
        }
        else if(PasarData[id][pasarType] == 3)
        {
            PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Kayu Kemas", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
        }
        else if(PasarData[id][pasarType] == 4)
        {
            PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Ayam Kemas", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
        }
        else if(PasarData[id][pasarType] == 5)
        {
            PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Hasil Daur", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
        }
        else if(PasarData[id][pasarType] == 6)
        {
            PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual/membeli Hasil Tani", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
        }
        else if(PasarData[id][pasarType] == 7)
        {
            PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Pakaian", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
        }
        else if(PasarData[id][pasarType] == 8)
        {
            PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual GAS", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
        }
        else if(PasarData[id][pasarType] == 9)
        {
            PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Ikan Nelayan", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
        }
    }
    return 1;
}

Pasar_Save(id)
{
    new cQuery[1056];
    format(cQuery, sizeof(cQuery), "UPDATE pasar SET posx='%f', posy='%f', posz='%f', type='%d', interior='%d', world='%d' WHERE id='%d'",
    PasarData[id][paDCRPos][0],
    PasarData[id][paDCRPos][1],
    PasarData[id][paDCRPos][2],
    PasarData[id][pasarType],
    PasarData[id][pasarInt],
    PasarData[id][pasarWorld],
    id
    );
    return mysql_tquery(dcrp_query, cQuery);
}

CMD:addpasar(playerid, params[])
{
    if(CheckAdmin(playerid, 6))
        return PermissionError(playerid);
    
    new id = Iter_Free(PASAR), query[512];
    new type;

    if(id == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menambah pasar lagi!");
    if(sscanf(params, "d", type))
        return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/addpasar [type] [1 - 9]");
    
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    PasarData[id][paDCRPos][0] = x;
    PasarData[id][paDCRPos][1] = y;
    PasarData[id][paDCRPos][2] = z;
    PasarData[id][pasarType] = type;
    PasarData[id][pasarInt] = GetPlayerInterior(playerid);
    PasarData[id][pasarWorld] = GetPlayerVirtualWorld(playerid);
    if(type == 1)
    {
        PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Susu Olahan", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    }
    else if(type == 2)
    {
        PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Hasil Tambang", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    }
    else if(type == 3)
    {
        PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Kayu Kemas", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    }
    else if(type == 4)
    {
        PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Ayam Kemas", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    }
    else if(type == 5)
    {
        PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Hasil Daur", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    }
    else if(type == 6)
    {
        PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual/membeli Hasil Tani", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    }
    else if(type == 7)
    {
        PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Pakaian", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    }
    else if(type == 8)
    {
        PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Gas", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    }
    else if(type == 9)
    {
        PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf(""LIGHTGREY"[PID: %d]\n"WHITE"Tekan"VERONA_GREEN" [ALT]"WHITE" untuk menjual Ikan Nelayan", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    }
    else
    {
        PasarData[id][pasarLabel] = CreateDynamic3DTextLabel(sprintf("Unknows", id), -1, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2] + 0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    }
    Iter_Add(PASAR, id);

    SendStaffMessage(X11_ARWIN, ""RED"%s"ARWIN1" telah membuat Dynamic Pasar ID: %d.", GetAdminName(playerid), id);
    mysql_format(dcrp_query, query, sizeof(query), "INSERT INTO pasar SET id=%d, posx='%f', posy='%f', posz='%f', type='%d', interior=%d, world=%d", id, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2], PasarData[id][pasarType], PasarData[id][pasarInt], PasarData[id][pasarWorld]);
	mysql_tquery(dcrp_query, query, "OnPasarCreated", "ii", playerid, id);
	return 1;
}

NERO::OnPasarCreated(playerid, id)
{
    Pasar_Save(id);
    SendClientMessageEx(playerid, -1, "[!]: Kamu membuat Dynamic pasar ID %d", id);
    return 1;
}

CMD:removepasar(playerid, params[])
{
    if(CheckAdmin(playerid, 6))
        return PermissionError(playerid);
    
    new id;
    if(sscanf(params, "d", id)) return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/removepasar [id]");
    if(!Iter_Contains(PASAR, id)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Pasar tidak ditemukan");

    DestroyDynamic3DTextLabel(PasarData[id][pasarLabel]);
    Iter_Remove(PASAR, id);

    SendStaffMessage(X11_ARWIN, ""RED"%s"ARWIN1" Menghapus Dynamic Pasar ID: %d.", GetAdminName(playerid), id);
    mysql_tquery(dcrp_query, sprintf("DELETE FROM pasar WHERE id='%d'", id));
    return 1;
}

CMD:gotopasar(playerid, params[])
{
    new id;
    if (CheckAdmin(playerid, 5))
        return PermissionError(playerid);
    
    if(sscanf(params, "d", id)) return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/gotopasar [id]");
    if(!Iter_Contains(PASAR, id)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Pasar tersebut tidak ada!");

    SetPlayerPos(playerid, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2]);
    SendStaffMessage(X11_ARWIN, ""RED"%s"ARWIN1" Teleportasi ke Dynamic Pasar ID: %d", GetAdminName(playerid), id);
    AccountData[playerid][pInDoor] = -1;
    AccountData[playerid][pInHouse] = -1;
    AccountData[playerid][pInBiz] = -1;
    AccountData[playerid][pInFamily] = -1;
    AccountData[playerid][pInRusun] = -1;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_WALK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(!IsPlayerConnected(playerid)) return false;
        foreach(new id : PASAR)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, PasarData[id][paDCRPos][0], PasarData[id][paDCRPos][1], PasarData[id][paDCRPos][2]))
            {
                if(PasarData[id][pasarType] == 1)
                {
                    new total = Inventory_Count(playerid, "Susu Olahan");
                    new valuepay = total*SusuOlahPrice;
                    if(!PlayerHasItem(playerid, "Susu Olahan")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Susu Olahan!");

                    ItemDelete(playerid, "Susu Olahan", total);
                    GiveMoney(playerid, valuepay);
                    ShowItemBox(playerid, "Susu Olahan", sprintf("Removed_%dx", total), 2);
                    ShowItemBox(playerid, "Uang", sprintf("Received_$%d", valuepay), 2);
                }
                else if(PasarData[id][pasarType] == 2)
                {
                    Dialog_Show(playerid, Pasar_HasilTambang, DIALOG_STYLE_TABLIST, ""PINK1"DCRP"WHITE"- Jual Hasil Tambang",
                    "Besi\t"GREEN"%s"ARWIN1"/pcs\
                    \n"GRAY"Tembaga\t"GREEN"%s"ARWIN1"/pcs\
                    \nEmas\t"GREEN"%s"ARWIN1"/pcs\
                    \n"GRAY"Berlian\t"GREEN"%s"ARWIN1"/pcs\
                    \nMaterial\t"GREEN"%s"ARWIN1"/pcs", "Pilih", "Batal", FormatMoney(BesiPrice), FormatMoney(TembagaPrice), FormatMoney(EmasPrice), FormatMoney(BerlianPrice), FormatMoney(MaterialPrice));
                }
                else if(PasarData[id][pasarType] == 3)
                {
                    new total = Inventory_Count(playerid, "Kayu Kemas");
                    new valuepay = total*KayuKemasPrice;
                    if(!PlayerHasItem(playerid, "Kayu Kemas")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Kayu Kemasan!");

                    ItemDelete(playerid, "Kayu Kemas", total);
                    GiveMoney(playerid, valuepay);
                    ShowItemBox(playerid, "Kayu Kemas", sprintf("Removed_%dx", total), 2);
                    ShowItemBox(playerid, "Uang", sprintf("Received_$%d", valuepay), 2);
                }
                else if(PasarData[id][pasarType] == 4)
                {
                    new total = Inventory_Count(playerid, "Ayam Kemas");
                    new valuepay = total*AyamKemasPrice;
                    if(!PlayerHasItem(playerid, "Ayam Kemas")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Ayam Kemas!");

                    ItemDelete(playerid, "Ayam Kemas", total);
                    GiveMoney(playerid, valuepay);
                    ShowItemBox(playerid, "Ayam Kemas", sprintf("Removed_%dx", total), 2);
                    ShowItemBox(playerid, "Uang", sprintf("Received_$%d", valuepay), 2);
                }
                else if(PasarData[id][pasarType] == 5)
                {
                    Dialog_Show(playerid, Pasar_HasilDaur, DIALOG_STYLE_TABLIST, ""PINK1"DCRP"WHITE"- Jual Hasil Recycler",
                    "Baja\t"GREEN"%s"ARWIN1"/pcs\
                    \n"GRAY"Kaca\t"GREEN"%s"ARWIN1"/pcs\
                    \nKaret\t"GREEN"%s"ARWIN1"/pcs\
                    \n"GRAY"Alumunium\t"GREEN"%s"ARWIN1"/pcs", "Pilih", "Batal", FormatMoney(BajaPrice), FormatMoney(KacaPrice), FormatMoney(KaretPrice), FormatMoney(AlumuniumPrice));
                }
                else if(PasarData[id][pasarType] == 7)
                {
                    new total = Inventory_Count(playerid, "Pakaian");
                    new valuepay = total*PakaianPrice;
                    if(!PlayerHasItem(playerid, "Pakaian")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Pakaian!");

                    ItemDelete(playerid, "Pakaian", total);
                    GiveMoney(playerid, valuepay);
                    ShowItemBox(playerid, "Pakaian", sprintf("Removed_%dx", total), 2);
                    ShowItemBox(playerid, "Uang", sprintf("Received_$%d", valuepay), 2);
                }
                else if(PasarData[id][pasarType] == 8)
                {
                    new total = Inventory_Count(playerid, "GAS");
                    new hasil = total*GasPrice;
                    if(!PlayerHasItem(playerid, "GAS")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki GAS!");

                    ItemDelete(playerid, "GAS", total);
                    GiveMoney(playerid, hasil);
                    ShowItemBox(playerid, "GAS", sprintf("Removed_%dx", total), 2);
                    ShowItemBox(playerid, "Uang", sprintf("Received_$%d", hasil), 2);
                }
                else if(PasarData[id][pasarType] == 9)
                {
                    new total = Inventory_Count(playerid, "Ikan");
                    new hasil = total*8;
                    if(!PlayerHasItem(playerid, "Ikan")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Ikan!");

                    ItemDelete(playerid, "Ikan", total);
                    GiveMoney(playerid, hasil);
                    ShowItemBox(playerid, "Ikan", sprintf("Removed_%dx", total), 2);
                    ShowItemBox(playerid, "Uang", sprintf("Received_$%s", FormatMoney(hasil)), 2);
                }
            }
        }
    }
    return 1;
}

Dialog:Pasar_HasilDaur(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0://Baja
        {
            new total = Inventory_Count(playerid, "Baja");
            new value = total*BajaPrice;
            if(!PlayerHasItem(playerid, "Baja")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Baja!");

            ItemDelete(playerid, "Baja", total);
            GiveMoney(playerid, value);
            ShowItemBox(playerid, "Baja", sprintf("Removed_%dx", total), 2);
            ShowItemBox(playerid, "Uang", sprintf("Received_$%d", value), 2);
        }
        case 1://Kaca
        {
            new total = Inventory_Count(playerid, "Kaca");
            new value = total*KacaPrice;
            if(!PlayerHasItem(playerid, "Kaca")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Kaca!");

            ItemDelete(playerid, "Kaca", total);
            GiveMoney(playerid, value);
            ShowItemBox(playerid, "Kaca", sprintf("Removed_%dx", total), 2);
            ShowItemBox(playerid, "Uang", sprintf("Received_$%d", value), 2);
        }
        case 2://Karet
        {
            new total = Inventory_Count(playerid, "Karet");
            new value = total*KaretPrice;
            if(!PlayerHasItem(playerid, "Karet")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Karet!");

            ItemDelete(playerid, "Karet", total);
            GiveMoney(playerid, value);
            ShowItemBox(playerid, "Karet", sprintf("Removed_%dx", total), 2);
            ShowItemBox(playerid, "Uang", sprintf("Received_$%d", value), 2);
        }
        case 3://alumunium
        {
            new total = Inventory_Count(playerid, "Alumunium");
            new valuepay = total*AlumuniumPrice;
            if(!PlayerHasItem(playerid, "Alumunium")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Alumunium!");

            ItemDelete(playerid, "Alumunium", total);
            GiveMoney(playerid, valuepay);
            ShowItemBox(playerid, "Aluminium", sprintf("Removed_%dx", total), 2);
            ShowItemBox(playerid, "Uang", sprintf("Received_$%d", valuepay), 2);
        }
    }
    return 1;
}

Dialog:Pasar_HasilTambang(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0://Besi
        {
            new total = Inventory_Count(playerid, "Besi");
            new valuepay = total*BesiPrice;
            if(!PlayerHasItem(playerid, "Besi")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Besi!");

            ItemDelete(playerid, "Besi", total);
            GiveMoney(playerid, valuepay);
            ShowItemBox(playerid, "Besi", sprintf("Removed_%dx", total), 2);
            ShowItemBox(playerid, "Uang", sprintf("Received_$%d", valuepay), 2); 
        }
        case 1://Tembaga
        {
            new total = Inventory_Count(playerid, "Tembaga");
            new valuepay = total*TembagaPrice;
            if(!PlayerHasItem(playerid, "Tembaga")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Tembaga!");

            ItemDelete(playerid, "Tembaga", total);
            GiveMoney(playerid, valuepay);
            ShowItemBox(playerid, "Tembaga", sprintf("Removed_%dx", total), 2);
            ShowItemBox(playerid, "Uang", sprintf("Received_$%d", valuepay), 2); 
        }
        case 2://Emas
        {
            new total = Inventory_Count(playerid, "Emas");
            new valuepay = total*EmasPrice;
            if(!PlayerHasItem(playerid, "Emas")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Emas!");

            ItemDelete(playerid, "Emas", total);
            GiveMoney(playerid, valuepay);
            ShowItemBox(playerid, "Emas", sprintf("Removed_%dx", total), 2);
            ShowItemBox(playerid, "Uang", sprintf("Received_$%d", valuepay), 2); 
        }
        case 3://Berlian
        {
            new total = Inventory_Count(playerid, "Berlian");
            new valuepay = total*BerlianPrice;
            if(!PlayerHasItem(playerid, "Berlian")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Berlian!");

            ItemDelete(playerid, "Berlian", total);
            GiveMoney(playerid, valuepay);
            ShowItemBox(playerid, "Berlian", sprintf("Removed_%dx", total), 2);
            ShowItemBox(playerid, "Uang", sprintf("Received_$%d", valuepay), 2); 
        }
        case 4://Material
        {
            new total = Inventory_Count(playerid, "Material");
            new valuepay = total*MaterialPrice;
            if(!PlayerHasItem(playerid, "Material")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Material!");

            ItemDelete(playerid, "Material", total);
            GiveMoney(playerid, valuepay);
            ShowItemBox(playerid, "Material", sprintf("Removed_%dx", total), 2);
            ShowItemBox(playerid, "Uang", sprintf("Received_$%d", valuepay), 2);
        }
    }
    return 1;
}