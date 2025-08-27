#include <YSI_Coding/y_hooks>

new SmokeObject[MAX_PLAYERS];

CMD:asap(playerid, const params[])
{
    if (!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF0000FF, "Anda harus berada di dalam kendaraan!");
    
    new vehicleid = GetPlayerVehicleID(playerid);
    
    if (strcmp(params, "on", true) == 0)
    {
        if (SmokeObject[playerid] != INVALID_OBJECT_ID)
            return SendClientMessage(playerid, 0xFFFF00FF, "Asap knalpot sudah aktif!");

        CreateBlackSmoke(playerid, vehicleid);
        SendClientMessage(playerid, 0x00FF00FF, "Asap knalpot telah AKTIF!");
    }
    else if (strcmp(params, "off", true) == 0)
    {
        if (SmokeObject[playerid] == INVALID_OBJECT_ID)
            return SendClientMessage(playerid, 0xFFFF00FF, "Asap knalpot sudah mati!");

        DestroyBlackSmoke(playerid);
        SendClientMessage(playerid, 0xFF0000FF, "Asap knalpot telah DIMATIKAN!");
    }
    else
    {
        SendClientMessage(playerid, 0xFFFFFF00, "Gunakan: /asap [on/off]");
    }
    return 1;
}

CreateBlackSmoke(playerid, vehicleid)
{
    if (SmokeObject[playerid] != INVALID_OBJECT_ID) return;

    new Float:x, Float:y, Float:z;
    GetVehiclePos(vehicleid, x, y, z);

    // Sesuaikan posisi agar efek berada di knalpot
    x -= 1.2;  // Geser ke belakang
    y += 0.3;  // Sedikit ke samping
    z -= 0.5;  // Geser ke bawah sedikit

    // Membuat objek asap hitam pekat (18723)
    SmokeObject[playerid] = CreateDynamicObject(18723, x, y, z, 0.000000, 0.000000, 0.000000, 0, 0, -1, 300.00, 300.00);
    
    // Menghubungkan ke kendaraan
    AttachDynamicObjectToVehicle(SmokeObject[playerid], vehicleid, -1.2, 0.3, -0.5, 0.0, 0.0, 0.0);
    
    // Timer untuk memperbarui efek
    SetTimerEx("UpdateBlackSmoke", 2000, true, "d", playerid);
}

DestroyBlackSmoke(playerid)
{
    if (SmokeObject[playerid] != INVALID_OBJECT_ID)
    {
        DestroyDynamicObject(SmokeObject[playerid]);
        SmokeObject[playerid] = INVALID_OBJECT_ID;
    }
}

function UpdateBlackSmoke(playerid)
{
    if (!IsPlayerInAnyVehicle(playerid))
    {
        DestroyBlackSmoke(playerid);
        return 0;
    }

    new vehicleid = GetPlayerVehicleID(playerid);
    new Float:x, Float:y, Float:z;
    GetVehiclePos(vehicleid, x, y, z);

    // Perbarui posisi efek asap agar tetap berada di knalpot
    x -= 1.2;
    y += 0.3;
    z -= 0.5;

    SetDynamicObjectPos(SmokeObject[playerid], x, y, z);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyBlackSmoke(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}
