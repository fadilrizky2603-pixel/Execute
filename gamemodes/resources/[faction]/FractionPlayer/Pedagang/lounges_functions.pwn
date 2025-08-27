#include <YSI\y_hooks>

forward ProcessEsTeh(playerid);
public ProcessEsTeh(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if((!IsValidDynamicArea(Pedagang_Stuff[PdgCooking]) && !IsValidDynamicArea(Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if((!IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCooking]) && !IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(Inventory_Count(playerid, "Gula") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Gula tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Air Mineral") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Air Mineral tidak cukup, (Min: 10)");
        return 0;
    }

    if(GetTotalWeightFloat(playerid) > 50)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 3)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        ItemDelete(playerid, "Gula", 10);
        ItemDelete(playerid, "Air Mineral", 10);
        ItemAdd(playerid, "Es Teh", 10);
        ShowItemBox(playerid, "Es Teh", "Received_10x", 2);
        ShowItemBox(playerid, "Gula", "Removed_10x", 2);
        ShowItemBox(playerid, "Air Mineral", "Removed_10x", 2);
    }
    else 
    {
        AccountData[playerid][ActivityTime]  ++;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/3;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward ProcessNasiGoreng(playerid);
public ProcessNasiGoreng(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if((!IsValidDynamicArea(Pedagang_Stuff[PdgCooking]) && !IsValidDynamicArea(Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if((!IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCooking]) && !IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(Inventory_Count(playerid, "Beras") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Beras tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Sambal") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Sambal tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Garam") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Garam tidak cukup, (Min: 10)");
        return 0;
    }

    if(GetTotalWeightFloat(playerid) > 50)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 3)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        ItemDelete(playerid, "Beras", 10);
        ItemDelete(playerid, "Garam", 10);
        ItemDelete(playerid, "Sambal", 10);
        ItemAdd(playerid, "Nasi Goreng", 10);
        ShowItemBox(playerid, "Nasi Goreng", "Received_10x", 2);
        ShowItemBox(playerid, "Beras", "Removed_10x", 2);
        ShowItemBox(playerid, "Garam", "Removed_10x", 2);
        ShowItemBox(playerid, "Sambal", "Removed_10x", 2);
    }
    else 
    {
        AccountData[playerid][ActivityTime]  ++;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/3;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward ProcessBakso(playerid);
public ProcessBakso(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if((!IsValidDynamicArea(Pedagang_Stuff[PdgCooking]) && !IsValidDynamicArea(Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if((!IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCooking]) && !IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(Inventory_Count(playerid, "Ikan") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Ikan tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Sambal") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Sambal tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Garam") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Garam tidak cukup, (Min: 10)");
        return 0;
    }

    if(GetTotalWeightFloat(playerid) > 50)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 3)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        ItemDelete(playerid, "Ikan", 10);
        ItemDelete(playerid, "Garam", 10);
        ItemDelete(playerid, "Sambal", 10);
        ItemAdd(playerid, "Bakso", 10);
        ShowItemBox(playerid, "Bakso", "Received_10x", 2);
        ShowItemBox(playerid, "Ikan", "Removed_10x", 2);
        ShowItemBox(playerid, "Garam", "Removed_10x", 2);
        ShowItemBox(playerid, "Sambal", "Removed_10x", 2);
    }
    else 
    {
        AccountData[playerid][ActivityTime]  ++;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/3;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward ProcessNasiPecel(playerid);
public ProcessNasiPecel(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if((!IsValidDynamicArea(Pedagang_Stuff[PdgCooking]) && !IsValidDynamicArea(Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if((!IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCooking]) && !IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(Inventory_Count(playerid, "Ikan") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Ikan tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Beras") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Beras tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Sambal") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Sambal tidak cukup, (Min: 10)");
        return 0;
    }

    if(GetTotalWeightFloat(playerid) > 50)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 3)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        ItemDelete(playerid, "Beras", 10);
        ItemDelete(playerid, "Ikan", 10);
        ItemDelete(playerid, "Sambal", 10);
        ItemAdd(playerid, "Nasi Pecel", 10);
        ShowItemBox(playerid, "Nasi Pecel", "Received_10x", 2);
        ShowItemBox(playerid, "Beras", "Removed_10x", 2);
        ShowItemBox(playerid, "Ikan", "Removed_10x", 2);
        ShowItemBox(playerid, "Sambal", "Removed_10x", 2);
    }
    else 
    {
        AccountData[playerid][ActivityTime]  ++;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/3;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward ProcessSusuFresh(playerid);
public ProcessSusuFresh(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if((!IsValidDynamicArea(Pedagang_Stuff[PdgCooking]) && !IsValidDynamicArea(Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if((!IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCooking]) && !IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(Inventory_Count(playerid, "Gula") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Gula tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Susu Olahan") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Susu Olahan tidak cukup, (Min: 10)");
        return 0;
    }

    if(GetTotalWeightFloat(playerid) > 50)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 3)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        ItemDelete(playerid, "Gula", 10);
        ItemDelete(playerid, "Susu Olahan", 10);
        ItemAdd(playerid, "Susu Fresh", 10);
        ShowItemBox(playerid, "Susu Fresh", "Received_10x", 2);
        ShowItemBox(playerid, "Gula", "Removed_10x", 2);
        ShowItemBox(playerid, "Susu Olahan", "Removed_10x", 2);
    }
    else 
    {
        AccountData[playerid][ActivityTime]  ++;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/3;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward ProcessBurdas(playerid);
public ProcessBurdas(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if((!IsValidDynamicArea(Pedagang_Stuff[PdgCooking]) && !IsValidDynamicArea(Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if((!IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCooking]) && !IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(Inventory_Count(playerid, "Sambal") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Sambal tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Ayam Kemas") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Ayam Kemas tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Beras") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Beras tidak cukup, (Min: 10)");
        return 0;
    }

    if(GetTotalWeightFloat(playerid) > 50)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 3)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        ItemDelete(playerid, "Beras", 10);
        ItemDelete(playerid, "Sambal", 10);
        ItemDelete(playerid, "Ayam Kemas", 10);
        ItemAdd(playerid, "Bubur Pedas", 10);
        ShowItemBox(playerid, "Bubur Pedas", "Received_10x", 2);
        ShowItemBox(playerid, "Beras", "Removed_10x", 2);
        ShowItemBox(playerid, "Sambal", "Removed_10x", 2);
        ShowItemBox(playerid, "Ayam Kemas", "Removed_10x", 2);
    }
    else 
    {
        AccountData[playerid][ActivityTime]  ++;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/3;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward ProcessKopiKenangan(playerid);
public ProcessKopiKenangan(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if((!IsValidDynamicArea(Pedagang_Stuff[PdgCooking]) && !IsValidDynamicArea(Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if((!IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCooking]) && !IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(Inventory_Count(playerid, "Gula") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Gula tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Air Mineral") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Air Mineral tidak cukup, (Min: 10)");
        return 0;
    }

    if(GetTotalWeightFloat(playerid) > 50)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 3)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        ItemDelete(playerid, "Air Mineral", 10);
        ItemDelete(playerid, "Gula", 10);
        ItemAdd(playerid, "Kopi Kenangan", 10);
        ShowItemBox(playerid, "Kopi Kenangan", "Received_10x", 2);
        ShowItemBox(playerid, "Air Mineral", "Removed_10x", 2);
        ShowItemBox(playerid, "Gula", "Removed_10x", 2);
    }
    else 
    {
        AccountData[playerid][ActivityTime]  ++;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/3;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}

forward ProcessMatcha(playerid);
public ProcessMatcha(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if((!IsValidDynamicArea(Pedagang_Stuff[PdgCooking]) && !IsValidDynamicArea(Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if((!IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCooking]) && !IsPlayerInDynamicArea(playerid, Pedagang_Stuff[PdgCookingEms])))
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(Inventory_Count(playerid, "Gula") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Gula tidak cukup, (Min: 10)");
        return 0;
    }

    if(Inventory_Count(playerid, "Air Mineral") < 10)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Air Mineral tidak cukup, (Min: 10)");
        return 0;
    }

    if(GetTotalWeightFloat(playerid) > 50)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 3)
    {
        KillTimer(pMasakTimer[playerid]);
        pMasakTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        ItemDelete(playerid, "Air Mineral", 10);
        ItemDelete(playerid, "Gula", 10);
        ItemAdd(playerid, "Choco Matcha", 10);
        ShowItemBox(playerid, "Choco Matcha", "Received_10x", 2);
        ShowItemBox(playerid, "Air Mineral", "Removed_10x", 2);
        ShowItemBox(playerid, "Gula", "Removed_10x", 2);
    }
    else 
    {
        AccountData[playerid][ActivityTime]  ++;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/3;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}