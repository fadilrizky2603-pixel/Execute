ptask PlayerJail_Update[1000](playerid)
{
    if(!AccountData[playerid][pSpawned])
        return 0;
    
    if(AccountData[playerid][pArrest])
    {
        if(AccountData[playerid][pArrestTime] != 0)
        {
            AccountData[playerid][pArrestTime] --;
            ShowPlayerFooter(playerid, sprintf("~y~Arrest ~n~~w~Anda harus menunggu selama ~r~%d detik ~w~untuk bebas dari penjara kepolisian", AccountData[playerid][pArrestTime]), 1000);
            if(!AccountData[playerid][pArrestTime])
            {
                AccountData[playerid][pArrest] = 0;
                AccountData[playerid][pArrestTime] = 0;
                SetPlayerPositionEx(playerid, 135.0716, 1943.8336, 19.3363, 356.8318, 6000);
                ClearAnimations(playerid, 1);
                SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
                SendClientMessage(playerid, X11_GRAY, "[Federal] Kamu telah dibebaskan dari penjara federal");

                new query[255];
                mysql_format(dcrp_query, query, sizeof(query), "UPDATE `player_characters` SET `Char_Jail`=0, `Char_JailTime`=0 WHERE `pID`=%d", AccountData[playerid][pID]);
                mysql_tquery(dcrp_query, query);
            }
        }
    }

    if(AccountData[playerid][pJail])
    {
        if(AccountData[playerid][pJailTime] != 0)
        {
            AccountData[playerid][pJailTime] --;
            ShowPlayerFooter(playerid, sprintf("~y~Admin jail ~n~~w~Anda harus menunggu selama ~r~%d detik ~w~untuk bebas dari penjara admin", AccountData[playerid][pJailTime]), 1000);
            if(!AccountData[playerid][pJailTime])
            {
                AccountData[playerid][pJail] = 0;
                AccountData[playerid][pJailTime] = 0;
                AccountData[playerid][pJailReason][0] = EOS;
                AccountData[playerid][pJailBy][0] = EOS;
                SetPlayerPositionEx(playerid, 1482.0356,-1724.5726,13.5469,750, 2000);
                SetPlayerInteriorEx(playerid, 0);
                SetPlayerVirtualWorldEx(playerid, 0);
                ClearAnimations(playerid, 1);
                SendClientMessage(playerid, X11_ARWIN, "[AdmCmd] Anda telah terbebas dari hukuman jail admin!");

                new cQuery[178];
                mysql_format(dcrp_query, cQuery, sizeof(cQuery), "DELETE FROM `warninglogs` WHERE `WarnType` = 2 AND `pID` = '%d'", AccountData[playerid][pID]);
                mysql_query(dcrp_query, cQuery, false);
            }
        }
    }
    return 1;
}