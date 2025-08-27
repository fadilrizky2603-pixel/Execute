#include <YSI\y_hooks>

hook OnPlayerConnect(playerid)
{
    pTakeKanabis[playerid] = -1;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(pTakeKanabis[playerid]);
    pTakeKanabis[playerid] = -1;
    return 1;
}

forward TakeKanabis(playerid);
public TakeKanabis(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pTakeKanabis[playerid]);
        pTakeKanabis[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);
        return 0;
    }

    if(AccountData[playerid][pInjured])
    {
        KillTimer(pTakeKanabis[playerid]);
        pTakeKanabis[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 0;
    }

    if(AccountData[playerid][pBeratItem] >= 50.0)
    {
        KillTimer(pTakeKanabis[playerid]);
        pTakeKanabis[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda penuh!");
        return 0;
    }

    if(AccountData[playerid][ActivityTime] >= 6)
    {
        new id = Kanabis_Nearest(playerid);
        if(id == -1) return 0;

        KillTimer(pTakeKanabis[playerid]);
        pTakeKanabis[playerid] = -1;
        AccountData[playerid][ActivityTime] = 0;
        HideProgressBar(playerid);

        ClearAnimations(playerid, 1);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        ItemAdd(playerid, "Kanabis", 1);
        ShowItemBox(playerid, "Kanabis", "Received_1x", 2);
        HideShortKey(playerid);

        if(IsValidDynamicObject(LadangData[id][kanabisObjID]))
            DestroyDynamicObject(LadangData[id][kanabisObjID]);

        if(IsValidDynamicArea(LadangData[id][kanabisArea]))
            DestroyDynamicArea(LadangData[id][kanabisArea]);
        LadangData[id][kanabisArea] = STREAMER_TAG_AREA: -1;
    }
    else 
    {
        AccountData[playerid][ActivityTime] ++;

        new Float: progressvalue;
        progressvalue = AccountData[playerid][ActivityTime] * 99/6;
        PlayerTextDrawTextSize(playerid, ProgressBar[playerid][1], progressvalue, 19.0);
        PlayerTextDrawShow(playerid, ProgressBar[playerid][2]);
        return 0;
    }
    return 1;
}