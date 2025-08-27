#include <YSI\y_hooks>
new pTimerMancing[MAX_PLAYERS] = {-1, ...};
new pTimerSellFish[MAX_PLAYERS] = {-1, ...};
new pTimerJadenFish[MAX_PLAYERS] = {-1, ...};
new pJadenFishState[MAX_PLAYERS] = {0, ...};
new pJadenFishState2[MAX_PLAYERS] = {0, ...};
new pJadenFishDirection[MAX_PLAYERS] = {1, ...};
new pJadenFishDirection2[MAX_PLAYERS] = {1, ...};

new STREAMER_TAG_AREA:FishingArea[8];
new STREAMER_TAG_AREA:SellFishArea;
new STREAMER_TAG_AREA:SellFishIlegalArea;

static Float:FishingPoint[][] = 
{
    {406.5273, -2103.3362, 4.3839},
    {398.5269, -2103.3367, 4.3859},
    {390.5435, -2103.3367, 4.3859},
    {382.5316, -2103.3367, 4.3859},
    {374.4796, -2103.3362, 4.3859},
    {366.5197, -2103.3367, 4.3859},
    {358.5491, -2103.3362, 4.3859},
    {350.5646, -2103.3367, 4.3859}
    //{349.8625, -2052.1484, 7.8359}
};

hook OnPlayerConnect(playerid)
{
    pTimerMancing[playerid] = -1;
    pTimerSellFish[playerid] = -1;
    pTimerJadenFish[playerid] = -1;
    pJadenFishState[playerid] = 0;
    pJadenFishState2[playerid] = 0;
    pJadenFishDirection[playerid] = 1;
    pJadenFishDirection2[playerid] = 1;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(pTimerMancing[playerid]);
    KillTimer(pTimerSellFish[playerid]);
    KillTimer(pTimerJadenFish[playerid]);
    pTimerMancing[playerid] = -1;
    pTimerSellFish[playerid] = -1;
    pTimerJadenFish[playerid] = -1;
    pJadenFishState[playerid] = 0;
    pJadenFishState2[playerid] = 0;
    pJadenFishDirection[playerid] = 1;
    pJadenFishDirection2[playerid] = 1;
    return 1;
}

hook OnGameModeInit()
{
    for(new x = 0; x < 8; x ++)
    {
        FishingArea[x] = CreateDynamicSphere(FishingPoint[x][0], FishingPoint[x][1], FishingPoint[x][2], 2.0, 0, 0, -1), CreateDynamic3DTextLabel(""GREEN"[ALT]"WHITE" Memancing", -1, FishingPoint[x][0], FishingPoint[x][1], FishingPoint[x][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 15.0, -1, 0);
    }
    SellFishArea = CreateDynamicSphere(-2057.3674, -2464.5283, 31.1797, 2.0, 0, 0, -1); 
    SellFishIlegalArea = CreateDynamicSphere(2160.7388, -102.3210, 2.7500, 2.0, 0, 0, -1);
    CreateDynamic3DTextLabel(""GREEN"[ALT]"WHITE" Jual Hiu/Penyu", -1, 2160.7388, -102.3210, 2.7500, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 15.0, -1, 0);
    CreateDynamic3DTextLabel(""GREEN"[ALT]"WHITE" Jual Ikan", -1, -2057.3674, -2464.5283, 31.1797, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 15.0, -1, 0);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_WALK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(IsPlayerInDynamicArea(playerid, SellFishArea))
        {
            if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, tunggu hingga progress selesai!");
            if(!PlayerHasItem(playerid, "Ikan Tawar")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki ikan tawar untuk dijual!");

            AccountData[playerid][ActivityTime] = 1;
            PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MENJUAL IKAN");
            ShowProgressBar(playerid);

            ApplyAnimationEx(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 0, 0, 1);
            pTimerSellFish[playerid] = SetTimerEx("SellingFish", 1000, true, "d", playerid);
        }

        if(IsPlayerInDynamicArea(playerid, SellFishIlegalArea))
        {
            if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, tunggu hingga progress selesai!");
            new count, count2;
            foreach(new i : Player) if (IsPlayerConnected(i)) if (SQL_IsCharacterLogged(i))
            {
                if(AccountData[i][pFaction] == FACTION_POLISI && AccountData[i][pDutyPD]) count++;
                if(AccountData[i][pFaction] == FACTION_EMS && AccountData[i][pDutyEms]) count2++;
            }
            if(count <= 4 && count2 <= 2) return ShowTDN(playerid, NOTIFICATION_ERROR, "Minimal 4 Polisi Duty & 2 EMS Duty");
            
            ShowPlayerDialog(playerid, DIALOG_SELLFISH_ILEGAL, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Sell Ilegal Fish",
            "Ikan Hiu\nPenyu", "Pilih", "Batal");
        }

        for(new x = 0; x < 8; x ++)
        {
            if(IsPlayerInDynamicArea(playerid, FishingArea[x]))
            {
                if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, tunggu sampai progress selesai!");
                if(!PlayerHasItem(playerid, "Pancingan")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki pancingan!");
                if(!PlayerHasItem(playerid, "Umpan")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki umpan!");

                AccountData[playerid][ActivityTime] = 1;
                ApplyAnimationEx(playerid, "SWORD", "sword_block", 50.0, 0, 1, 0, 1, 1, 1);
                SetPlayerAttachedObject(playerid, 9,18632,6,0.079376,0.037070,0.007706,181.482910,0.000000,0.000000,1.000000,1.000000,1.000000);
                
                // Show JadenFish UI
                for(new i = 0; i < 59; i++)
                {
                    PlayerTextDrawShow(playerid, JadenFish[playerid][i]);
                }
                
                pTimerJadenFish[playerid] = SetTimerEx("UpdateJadenFish", 50, true, "i", playerid);
                pTimerMancing[playerid] = SetTimerEx("FishingTime", 1000, true, "dd", playerid, x);
            }
        }
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case DIALOG_SELLFISH_ILEGAL:
        {
            if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, tunggu sampai progress selesai!");
            switch(listitem)
            {
                case 0: //hiu
                {
                    if(!PlayerHasItem(playerid, "Hiu")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki ikan hiu!");
                    
                    AccountData[playerid][ActivityTime] = 1;
                    PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "JUAL HIU");
                    ShowProgressBar(playerid);

                    ApplyAnimationEx(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 0, 0, 1);
                    pTimerSellFish[playerid] = SetTimerEx("SellShark", 1000, true, "i", playerid);
                }
                case 1: //penyu
                {
                    if(!PlayerHasItem(playerid, "Penyu")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki penyu!");
                    
                    AccountData[playerid][ActivityTime] = 1;
                    PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "JUAL PENYU");
                    ShowProgressBar(playerid);

                    ApplyAnimationEx(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 0, 0, 1);
                    pTimerSellFish[playerid] = SetTimerEx("SellPenyu", 1000, true, "i", playerid);
                }
            }
        }
    }
    return 1;
}

/* Other Func */
forward SellPenyu(playerid);
public SellPenyu(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if(!IsPlayerInDynamicArea(playerid, SellFishIlegalArea))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(!IsValidDynamicArea(SellFishIlegalArea))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(!PlayerHasItem(playerid, "Penyu"))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki penyu!");
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang pingsan!");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 15)
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        new count = Inventory_Count(playerid, "Penyu");
        new price = count * 150;

        SendClientMessageEx(playerid, -1, "[i] Anda mendapatkan "RED"%s"WHITE" uang merah dari hasil penjualan penyu sejumlah "YELLOW"%dx", FormatMoney(price), count);
        ItemDelete(playerid, "Penyu", count);
        ShowItemBox(playerid, "Penyu", sprintf("Removed_%dx", count), 2);
        AccountData[playerid][pRedMoney] += price;
    }
    else
    {
        AccountData[playerid][ActivityTime] ++;

        static Float:progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/15;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward SellShark(playerid);
public SellShark(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if(!IsPlayerInDynamicArea(playerid, SellFishIlegalArea))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(!IsValidDynamicArea(SellFishIlegalArea))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(!PlayerHasItem(playerid, "Hiu"))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki ikan hiu!");
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang pingsan!");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 15)
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        new count = Inventory_Count(playerid, "Hiu");
        new price = count * 250;

        SendClientMessageEx(playerid, -1, "[i] Anda mendapatkan "RED"%s"WHITE" uang merah dari hasil penjualan hiu sejumlah "YELLOW"%dx", FormatMoney(price), count);
        ItemDelete(playerid, "Hiu", count);
        ShowItemBox(playerid, "Hiu", sprintf("Removed_%dx", count), 2);
        AccountData[playerid][pRedMoney] += price;
    }
    else
    {
        AccountData[playerid][ActivityTime] ++;

        static Float:progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/15;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward UpdateJadenFish(playerid);
public UpdateJadenFish(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    // Update first bar (index 22)
    if(pJadenFishState[playerid] >= 100) pJadenFishDirection[playerid] = -1;
    else if(pJadenFishState[playerid] <= 0) pJadenFishDirection[playerid] = 1;
    
    pJadenFishState[playerid] += pJadenFishDirection[playerid];
    
    // Update second bar (index 21) - slower movement
    if(pJadenFishState2[playerid] >= 100) pJadenFishDirection2[playerid] = -1;
    else if(pJadenFishState2[playerid] <= 0) pJadenFishDirection2[playerid] = 1;
    
    // Move second bar slower (every 3rd update)
    static updateCount;
    updateCount++;
    if(updateCount >= 3)
    {
        pJadenFishState2[playerid] += pJadenFishDirection2[playerid];
        updateCount = 0;
    }
    
    // Update both bars position vertically
    new Float:progressvalue = pJadenFishState[playerid] * 106.0/100.0; // 106 is the height of the bar
    new Float:progressvalue2 = pJadenFishState2[playerid] * 106.0/100.0;
    
    // Update TextDraw size while maintaining position
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][21], 2.0, progressvalue2);
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][22], 3.0, progressvalue);
    
    // Set alignment to 0 (left) to maintain exact position
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][21], 0);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][22], 0);
    
    PlayerTextDrawShow(playerid, JadenFish[playerid][21]);
    PlayerTextDrawShow(playerid, JadenFish[playerid][22]);
    
    return 1;
}

forward FishingTime(playerid, x);
public FishingTime(playerid, x)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pTimerMancing[playerid]);
        KillTimer(pTimerJadenFish[playerid]);
        pTimerMancing[playerid] = -1;
        pTimerJadenFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        
        // Hide JadenFish UI
        for(new i = 0; i < 59; i++)
        {
            PlayerTextDrawHide(playerid, JadenFish[playerid][i]);
        }
        return 0;
    }

    if(!IsValidDynamicArea(FishingArea[x]))
    {
        KillTimer(pTimerMancing[playerid]);
        pTimerMancing[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        
        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        RemovePlayerAttachedObject(playerid, 9);
        return 0;
    }

    if(!IsPlayerInDynamicArea(playerid, FishingArea[x]))
    {
        KillTimer(pTimerMancing[playerid]);
        pTimerMancing[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        
        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        RemovePlayerAttachedObject(playerid, 9);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang pingsan!");
        KillTimer(pTimerMancing[playerid]);
        pTimerMancing[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        
        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        RemovePlayerAttachedObject(playerid, 9);
        return 0;
    }

    if(GetTotalWeightFloat(playerid) > 50)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda telah penuh!");
        KillTimer(pTimerMancing[playerid]);
        pTimerMancing[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        
        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        RemovePlayerAttachedObject(playerid, 9);
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 20)
    {
        KillTimer(pTimerMancing[playerid]);
        KillTimer(pTimerJadenFish[playerid]);
        pTimerMancing[playerid] = -1;
        pTimerJadenFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        
        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        RemovePlayerAttachedObject(playerid, 9);

        // Hide JadenFish UI
        for(new i = 0; i < 59; i++)
        {
            PlayerTextDrawHide(playerid, JadenFish[playerid][i]);
        }

        ItemDelete(playerid, "Umpan");
        ShowItemBox(playerid, "Umpan", "Removed_1x", 2);

        new rands = RandomEx(1, 58), randikan = RandomEx(3, 10);
        new fishType = 0; // 0 = low, 1 = medium, 2 = high
        
        // Determine fish type based on JadenFish bar position
        if(pJadenFishState[playerid] < 33) fishType = 0;
        else if(pJadenFishState[playerid] < 66) fishType = 1;
        else fishType = 2;
        
        switch(fishType)
        {
            case 0: // Low fish
            {
                switch(rands)
                {
                    case 1..10:
                    {
                        ItemAdd(playerid, "Ikan Tawar", randikan);
                        ShowItemBox(playerid, "Ikan Tawar", sprintf("Received_%dx", randikan), 2);
                    }
                    case 11..21:
                    {
                        SendClientMessageEx(playerid, -1, "[i] Pancingan mu terbawa ikan besar dan jatuh ke dasar laut");
                        ItemDelete(playerid, "Pancingan");
                        ShowItemBox(playerid, "Pancingan", "Removed_1x", 2);
                    }
                    case 22..31:
                    {
                        SendClientMessage(playerid, -1, "[i] Anda zonk mendapatkan sampah makanan");
                        ItemAdd(playerid, "Sampah Makanan");
                        ShowItemBox(playerid, "Sampah Makanan", "Received_1x", 2);
                    }
                    case 32..50:
                    {
                        ItemAdd(playerid, "Ikan Tawar");
                        ShowItemBox(playerid, "Ikan Tawar", "Received_1x", 2);
                    }
                }
            }
            case 1: // Medium fish
            {
                switch(rands)
                {
                    case 1..20:
                    {
                        ItemAdd(playerid, "Ikan Tawar", randikan * 2);
                        ShowItemBox(playerid, "Ikan Tawar", sprintf("Received_%dx", randikan * 2), 2);
                    }
                    case 21..30:
                    {
                        ItemAdd(playerid, "Penyu");
                        ShowItemBox(playerid, "Penyu", "Received_1x", 2);
                    }
                    case 31..50:
                    {
                        ItemAdd(playerid, "Ikan Tawar", 50);
                        ShowItemBox(playerid, "Ikan Tawar", "Received_50x", 2);
                        Info(playerid, "Anda beruntung karena mendapatkan "YELLOW"50"WHITE" ikan hari ini");
                    }
                }
            }
            case 2: // High fish
            {
                switch(rands)
                {
                    case 1..30:
                    {
                        ItemAdd(playerid, "Hiu", 2);
                        ShowItemBox(playerid, "Hiu", "Received_2x", 2);
                    }
                    case 31..50:
                    {
                        ItemAdd(playerid, "Penyu", 2);
                        ShowItemBox(playerid, "Penyu", "Received_2x", 2);
                    }
                }
            }
        }
        GivePlayerXP(playerid, 1);
    }
    else
    {
        AccountData[playerid][ActivityTime] ++;
        return 0;
    }
    return 1;
}

forward SellingFish(playerid);
public SellingFish(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if(!IsValidDynamicArea(SellFishArea))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(!IsPlayerInDynamicArea(playerid, SellFishArea))
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang pingsan!");
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }
    
    if(AccountData[playerid][ActivityTime] >= 15)
    {
        KillTimer(pTimerSellFish[playerid]);
        pTimerSellFish[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    
        new value = Inventory_Count(playerid, "Ikan Tawar");
        ShowItemBox(playerid, "Ikan Tawar", sprintf("Removed_%dx", value), 2);
        ShowItemBox(playerid, "Uang", sprintf("Received_$%s", FormatMoney(value * 3)), 2);
        ItemDelete(playerid, "Ikan Tawar", value);
        GiveMoney(playerid, (value * 3));
    }
    else
    {
        AccountData[playerid][ActivityTime] ++;

        static Float:progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/15;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}