#define live:: l_
#define MAX_LIVESTREAM (100)

enum e_live
{
    bool:l_exists,
    l_plat,
    l_players,
    l_platcust[64],
    l_title[128],
    l_username[64],
};
new live::data[MAX_LIVESTREAM][e_live],
    Iterator:LiveStream<MAX_LIVESTREAM>;

stock const PlatformName[3][] = {
    ""WHITE"No Platform",
    ""RED"YouTube",
    ""GREY"TikTok"
};

GetCountStream()
{
    foreach(new s:LiveStream)
    {
        if(live::data[s][live::exists])
        {
            return s;
        }
    }
    return -1;
}

GetPlatformStream(id)
{
    if(live::data[id][live::plat] != 3)
    {
        return PlatformName[live::data[id][live::plat]];
    }
    else
    {
        return live::data[id][live::platcust];
    }
    return PlatformName[0];
}

CMD:livestream(playerid, params[])
{
    if(GetCountStream() == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada streamer di kota!");
    new strlive[1000], strfrmt[160];
    strcat(strlive, "Player\tPlatform\tUsername\tTitle\n");
    foreach(new liveid:LiveStream)
    {
        if(live::data[liveid][live::exists])
            format(strfrmt, sizeof(strfrmt), "%s\t%s\t%s\t%s\n", ReturnName(live::data[playerid][live::players]), GetPlatformStream(liveid), live::data[liveid][live::username],live::data[liveid][live::title]);
    }
    ShowPlayerDialog(playerid, DIALOG_STREAMLIST, DIALOG_STYLE_TABLIST_HEADERS, "{FFB6C1}DCRP{FFFFFF} - List Streamer", strlive, "Close", "");
    return 1;
}