CreateCarStealingPoint()
{
    //JOBS
    new strings[500];
    CreateDynamicPickup(1098, 23, 1068.6592,-304.6219, 73.9922, -1, -1, -1, 50);
    format(strings, sizeof(strings), "{FF0000}Dilarang menyalahgunakan fitur ini!\n{FFFFFF}Press {FFFF00}[Y] {FFFFFF}to start Car Steal");
    CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 1068.6592,-304.6219, 73.9922, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); // Kurir
}

function CarStealing(playerid)
{
    new money, materials, str[100];
    new vehid = Vehicle_Nearest2(playerid);
    money = Random(5000, 7000);
    materials = Random(150, 300);

    SuccesMsg(playerid, "Kendaraan berhasil di seludupkan");

    GivePlayerMoneyEx(playerid, money);
    Inventory_Add(playerid, "Material", 17051, materials);

    format(str, sizeof(str), "Anda mendapatkan uang sejumlah %s", FormatMoney(money));
    InfoMsg(playerid, str);
    TogglePlayerControllable(playerid, 1);
    pData[playerid][pRobbingTime] = gettime() + 1800;

    foreach(new ii : PVehicles)
    {
        if(vehid == pvData[ii][cVeh])
        {
            if(pvData[ii][cInsu] > 0)
            {
                pvData[ii][cClaim] = 1;
                pvData[ii][cClaimTime] = gettime() + (1 * 60);
                RemovePlayerFromVehicle(playerid);
                RemoveVehicleToys(pvData[ii][cVeh]);
                if(IsValidVehicle(pvData[ii][cVeh]))
                    DestroyVehicle(pvData[ii][cVeh]); 
                pvData[ii][cVeh] = 0;
                foreach(new pid : Player) 
                {
                    if(pvData[ii][cOwner] == pData[pid][pID])
                    {
                        Info(pid, "Kendaraan anda hancur dan anda masih memiliki insuransi, silahkan ambil di kantor asuransi setelah 5 menit.");
                    }
                }
            }
        }
    }
    return 1;
}

CMD:carsteal(playerid, const params[])
{
    new vehid2 = GetPlayerVehicleID(playerid);
    if(IsPlayerInRangeOfPoint(playerid, 5.0, 1068.6592,-304.6219, 73.9922))
    {
        if(pData[playerid][pRobbingTime] >= gettime()) return ErrorMsg(playerid, "Anda harus menunggu beberapa detik untuk melakukan car steal lagi");
        if(CountFaction(1) < 2) return ErrorMsg(playerid, "SAPD yang ada di kota minimal 2");
        if(CountFaction(3) < 1) return ErrorMsg(playerid, "SAMD yang ada di kota minimal 1");        
        if(pData[playerid][pLevel] < 3) return ErrorMsg(playerid, "Level anda belum mencukupi (3)");
        if(!IsPlayerInAnyVehicle(playerid)) return ErrorMsg(playerid, "Anda harus berada di dalam kendaraan");
        if(IsABusVeh(vehid2) && IsATrashVeh(vehid2) && IsASweeperVeh(vehid2) && IsDRIVESIMCar(vehid2) && pvData[vehid2][cRent] != 0)
            return ErrorMsg(playerid, "Kendaraan ini tidak dapat id curi");
        SetTimerEx("CarStealing", 80000, false, "i", playerid);
        ShowProgressbar(playerid, "Stealing...", 80);
        TogglePlayerControllable(playerid, 0);

        new Float:slx, Float:sly, Float:slz;
        GetPlayerPos(playerid, slx, sly, slz);
        SendFactionMessage(1, -1, "{FF0000}DISPATCH {FFFFFF}: Seseorang telah mencoba melakukan car stealing | Location: %s | ID: %d", GetLocation(slx, sly, slz), playerid);
        SendFactionMessage(1, -1, "Gunakan {FFFF00}'/getlocpd <playerid>'", GetLocation(slx, sly, slz));        
    }    
    return 1;
}