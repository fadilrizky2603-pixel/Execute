#include <YSI\y_hooks>

new pTakingSusuTimer[MAX_PLAYERS] = {-1, ...};
new pProcessSusuTimer[MAX_PLAYERS] = {-1, ...};

enum E_SUSUSTUFF
{
    STREAMER_TAG_AREA:SusuJobArea,
    STREAMER_TAG_AREA:SusuTakeArea,
    STREAMER_TAG_AREA:SusuProcessArea,

    STREAMER_TAG_PICKUP:SusuJobPickup,

    STREAMER_TAG_OBJECT:CowObject,
    STREAMER_TAG_MAP_ICON:MilkerIcon,

    bool:DuringTakeSusu
};
new PlayerSusuVars[MAX_PLAYERS][E_SUSUSTUFF];

function LoadVarsMilker(playerid)
{
    UnloadVarsMilker(playerid);

    PlayerSusuVars[playerid][SusuJobArea] = CreateDynamicCircle(-1073.1116, -1204.3927, 2.2, 0, 0, playerid);
    PlayerSusuVars[playerid][SusuProcessArea] = CreateDynamicCircle(-1077.3663, -1154.1160, 3.0, 0, 0, playerid);
    PlayerSusuVars[playerid][MilkerIcon] = CreateDynamicMapIcon(-1109.3740, -1197.4646, 129.2259, 38, -1, 0, 0, playerid, 9999.0, MAPICON_GLOBAL, -1, 1);
}

function UnloadVarsMilker(playerid)
{
    if(IsValidDynamicArea(PlayerSusuVars[playerid][SusuJobArea]))
        DestroyDynamicArea(PlayerSusuVars[playerid][SusuJobArea]);
    PlayerSusuVars[playerid][SusuJobArea] = STREAMER_TAG_AREA: -1;
    
    if(IsValidDynamicArea(PlayerSusuVars[playerid][SusuProcessArea]))
        DestroyDynamicArea(PlayerSusuVars[playerid][SusuProcessArea]);
    PlayerSusuVars[playerid][SusuProcessArea] = STREAMER_TAG_AREA: -1;
    
    if(IsValidDynamicMapIcon(PlayerSusuVars[playerid][MilkerIcon]))
        DestroyDynamicMapIcon(PlayerSusuVars[playerid][MilkerIcon]);
    PlayerSusuVars[playerid][MilkerIcon] = STREAMER_TAG_MAP_ICON: -1;
    return 1;
}

new Float: CowSpawn[][6] = {
    {-1108.7729, -1181.9618, 129.2188, 0.000000, 0.000000, 336.035200},
    {-1152.7017, -1200.3629, 129.2188, 0.000000, 0.000000, 15.162900},
    {-1161.0612, -1196.4725, 129.2188, 0.000000, 0.000000, 71.459000},
    {-1176.2808, -1176.0366, 129.2188, 0.000000, 0.000000, 9.877900},
    {-1162.3271, -1162.3107, 129.2188, 0.000000, 0.000000, 351.725500},
    {-1132.8091, -1177.7589, 129.2188, 0.000000, 0.000000, 225.641400}
};

hook OnPlayerConnect(playerid)
{
    pTakingSusuTimer[playerid] = -1;
    pProcessSusuTimer[playerid] = -1;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(pTakingSusuTimer[playerid]);
    KillTimer(pProcessSusuTimer[playerid]);
    pTakingSusuTimer[playerid] = -1;
    pProcessSusuTimer[playerid] = -1;
    return 1;
}

forward TakeSusu(playerid);
public TakeSusu(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pTakingSusuTimer[playerid]);
        pTakingSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);  
        return 0;
    }

    if(!IsValidDynamicArea(PlayerSusuVars[playerid][SusuTakeArea]))
    {
        KillTimer(pTakingSusuTimer[playerid]);
        pTakingSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(!IsPlayerInDynamicArea(playerid, PlayerSusuVars[playerid][SusuTakeArea]))
    {
        HideProgressBar(playerid);
        KillTimer(pTakingSusuTimer[playerid]);
        pTakingSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pBeratItem] >= 50.0)
    {
        HideProgressBar(playerid);
        KillTimer(pTakingSusuTimer[playerid]);
        pTakingSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory Anda Penuh!");
        return 0;
    }

    if(AccountData[playerid][pInjured] == 1)
    {
        HideProgressBar(playerid);
        KillTimer(pTakingSusuTimer[playerid]);
        pTakingSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 105)
    {
        KillTimer(pTakingSusuTimer[playerid]);
        pTakingSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        if(IsValidDynamicObject(PlayerSusuVars[playerid][CowObject]))
            DestroyDynamicObject(PlayerSusuVars[playerid][CowObject]);
        PlayerSusuVars[playerid][CowObject] = STREAMER_TAG_OBJECT: -1;
        if(IsValidDynamicArea(PlayerSusuVars[playerid][SusuTakeArea]))
            DestroyDynamicArea(PlayerSusuVars[playerid][SusuTakeArea]);
        PlayerSusuVars[playerid][SusuTakeArea] = STREAMER_TAG_AREA: -1;

        new rand = Random(sizeof(CowSpawn));
        PlayerSusuVars[playerid][CowObject] = CreateDynamicObject(19833, CowSpawn[rand][0], CowSpawn[rand][1], CowSpawn[rand][2], CowSpawn[rand][3], CowSpawn[rand][4], CowSpawn[rand][5], -1, -1, playerid, 300.00, 300.00);
        PlayerSusuVars[playerid][SusuTakeArea] = CreateDynamicCircle(CowSpawn[rand][0], CowSpawn[rand][1], 2.0, 0, 0, playerid);

        new str[512];
        new randmilk = RandomEx(1, 7);
        ItemAdd(playerid, "Susu Murni", randmilk);
        format(str, sizeof str, "Received_%dx", randmilk);
        ShowItemBox(playerid, "Susu Murni", str, 2);
        GivePlayerXP(playerid, DEFAULT_XP);
    }
    else
    {
        AccountData[playerid][ActivityTime] += 17.5;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/105;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
    }
    return 1;
}

forward ProcessSusu(playerid);
public ProcessSusu(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pProcessSusuTimer[playerid]);
        pProcessSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if(!IsValidDynamicArea(PlayerSusuVars[playerid][SusuProcessArea]))
    {
        KillTimer(pProcessSusuTimer[playerid]);
        pProcessSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(!IsPlayerInDynamicArea(playerid, PlayerSusuVars[playerid][SusuProcessArea]))
    {
        KillTimer(pProcessSusuTimer[playerid]);
        pProcessSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pBeratItem] >= 50.0)
    {
        KillTimer(pProcessSusuTimer[playerid]);
        pProcessSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(Inventory_Count(playerid, "Susu Murni") < 5 && Inventory_Count(playerid, "Botol") < 1)
    {
        KillTimer(pProcessSusuTimer[playerid]);
        pProcessSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Butuh 5x Susu Murni & 1x Botol");
        return 0;
    }

    if(Inventory_Count(playerid, "Susu Murni") < 5)
    {
        KillTimer(pProcessSusuTimer[playerid]);
        pProcessSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Susu Murni Tidak Cukup!");
        return 0;
    }

    if(Inventory_Count(playerid, "Botol") < 1)
    {
        KillTimer(pProcessSusuTimer[playerid]);
        pProcessSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Botol tidak cukup!");
        return 0;
    }

    if(AccountData[playerid][pInjured] == 1)
    {
        KillTimer(pProcessSusuTimer[playerid]);
        pProcessSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 121)
    {
        KillTimer(pProcessSusuTimer[playerid]);
        pProcessSusuTimer[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        ItemDelete(playerid, "Susu Murni", 5);
        ItemDelete(playerid, "Botol");
        ItemAdd(playerid, "Susu Olahan");
        ShowItemBox(playerid, "Susu Olahan", "Received_1x", 2);
        ShowItemBox(playerid, "Susu Murni", "Removed_5x", 2);
        ShowItemBox(playerid, "Botol", "Removed_1x", 2);
        GivePlayerXP(playerid, DEFAULT_XP);
    }
    else
    {
        AccountData[playerid][ActivityTime] += 12.1;

        new Float:progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 67/121;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], progressvalue, 2.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
    }
    return 1;
}

Dialog:SusuMenu(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case DIALOG_SUSU_START:
        {
            if(!response) return 0;
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerSusuVars[playerid][DuringTakeSusu]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memulai pekerjaan ini");
                    
                    // Spawn cow first
                    new rand = random(sizeof(CowSpawn));
                    if(IsValidDynamicObject(PlayerSusuVars[playerid][CowObject]))
                        DestroyDynamicObject(PlayerSusuVars[playerid][CowObject]);
                    PlayerSusuVars[playerid][CowObject] = STREAMER_TAG_OBJECT: -1;
                    if(IsValidDynamicArea(PlayerSusuVars[playerid][SusuTakeArea]))
                        DestroyDynamicArea(PlayerSusuVars[playerid][SusuTakeArea]);
                    PlayerSusuVars[playerid][SusuTakeArea] = STREAMER_TAG_AREA: -1;
                    
                    // Create cow object and area
                    PlayerSusuVars[playerid][CowObject] = CreateDynamicObject(19833, CowSpawn[rand][0], CowSpawn[rand][1], CowSpawn[rand][2], CowSpawn[rand][3], CowSpawn[rand][4], CowSpawn[rand][5], -1, -1, playerid, 300.00, 300.00);
                    PlayerSusuVars[playerid][SusuTakeArea] = CreateDynamicCircle(CowSpawn[rand][0], CowSpawn[rand][1], 2.0, 0, 0, playerid);
                    
                    // Set job state
                    PlayerSusuVars[playerid][DuringTakeSusu] = true;
                    ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda berhasil memulai pekerjaan");
                    
                    // Teleport player to cow if needed
                    SetPlayerPos(playerid, CowSpawn[rand][0], CowSpawn[rand][1], CowSpawn[rand][2]);
                    SetPlayerFacingAngle(playerid, CowSpawn[rand][5]);
                }
                case 1:
                {
                    if(!PlayerSusuVars[playerid][DuringTakeSusu]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memulai pekerjaan ini!");
                    if(IsValidDynamicObject(PlayerSusuVars[playerid][CowObject]))
                        DestroyDynamicObject(PlayerSusuVars[playerid][CowObject]);
                    PlayerSusuVars[playerid][CowObject] = STREAMER_TAG_OBJECT: -1;
                    if(IsValidDynamicArea(PlayerSusuVars[playerid][SusuTakeArea]))
                        DestroyDynamicArea(PlayerSusuVars[playerid][SusuTakeArea]);
                    PlayerSusuVars[playerid][SusuTakeArea] = STREAMER_TAG_AREA: -1;
                    PlayerSusuVars[playerid][DuringTakeSusu] = false;
                    ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda berhasil menyelesaikan pekerjaan");
                }
            }
        }
    }
    return 0;
}

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(GetPlayerJob(playerid) == JOB_MILKER && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(areaid == PlayerSusuVars[playerid][SusuJobArea])
        {
            ShowKey(playerid, "Memulai");
        }
        if(areaid == PlayerSusuVars[playerid][SusuTakeArea])
        {
            ShowKey(playerid, "Perah Susu");
        }
        if(areaid == PlayerSusuVars[playerid][SusuProcessArea])
        {
            ShowKey(playerid, "Olah Susu");
        }
    }
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(areaid == PlayerSusuVars[playerid][SusuJobArea])
    {
        HideShortKey(playerid);
    }
    else if(areaid == PlayerSusuVars[playerid][SusuTakeArea])
    {
        HideShortKey(playerid);
    }
    else if(areaid == PlayerSusuVars[playerid][SusuProcessArea])
    {
        HideShortKey(playerid);
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_WALK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(AccountData[playerid][pJob] == JOB_MILKER)
        {
            if(IsPlayerInDynamicArea(playerid, PlayerSusuVars[playerid][SusuJobArea]))
            {
                ShowSusuJobTD(playerid);
            }

            if(IsPlayerInDynamicArea(playerid, PlayerSusuVars[playerid][SusuTakeArea]))
            {
                if(!PlayerSusuVars[playerid][DuringTakeSusu]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memulai pekerjaan ini!");
                if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, harap tunggu!");
                if(Inventory_Count(playerid, "Susu Murni") >= 250) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat membawa Susu Murni lebih dari 250!");

                AccountData[playerid][ActivityTime] = 1;
                pTakingSusuTimer[playerid] = SetTimerEx("TakeSusu", 1000, true, "i", playerid);
                PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MEMERAH SUSU");
                ShowProgressBar(playerid);
                ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,1,0,0,0,0,1);
            }

            if(IsPlayerInDynamicArea(playerid, PlayerSusuVars[playerid][SusuProcessArea]))
            {
                if(AccountData[playerid][ActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, harap tunggu!");
                if(Inventory_Count(playerid, "Susu Olahan") >= 250) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat membawa Susu Olahan lebih dari 250!");

                AccountData[playerid][ActivityTime] = 1;
                pProcessSusuTimer[playerid] = SetTimerEx("ProcessSusu", 1000, true, "i", playerid);
                PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MENGOLAH SUSU");
                ShowProgressBar(playerid);
                ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 0, 0, 1);
            }
        }   
    }
    return 1;
}

ShowSusuJobTD(playerid)
{

    for(new i = 1; i <= 22; i++)
    {
        PlayerTextDrawShow(playerid, SusuInfo[playerid][i]);
    }
    
    // TD YANG DI PENCET
    PlayerTextDrawSetSelectable(playerid, SusuInfo[playerid][23], true);
    PlayerTextDrawSetSelectable(playerid, SusuInfo[playerid][24], true);
    PlayerTextDrawShow(playerid, SusuInfo[playerid][23]);
    PlayerTextDrawShow(playerid, SusuInfo[playerid][24]);
    
    // MENAMPILKAN SELURUH TD
    for(new i = 25; i <= 30; i++)
    {
        PlayerTextDrawShow(playerid, SusuInfo[playerid][i]);
    }
    
    // WARNA CLICK TD NYA
    SelectTextDraw(playerid, 0x3b4c595e);
}

// FUNCTION HIDE TD NYA
HideSusuJobTD(playerid)
{
    CancelSelectTextDraw(playerid);
    for(new i = 1; i <= 30; i++)
    {
        PlayerTextDrawHide(playerid, SusuInfo[playerid][i]);
    }
}