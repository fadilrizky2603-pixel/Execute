#include <YSI\y_hooks>

CreateTDShortKey(playerid)
{
    PlayerTextdraws[playerid][textdraw_interaksi][0] = CreatePlayerTextDraw(playerid, 271.000, 395.799, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi][0], 21.000, 27.500);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi][0], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][0], 371731455);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][0], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][0], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi][0], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi][0], 1);

    PlayerTextdraws[playerid][textdraw_interaksi][1] = CreatePlayerTextDraw(playerid, 273.000, 398.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi][1], 16.000, 1.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi][1], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][1], 162631167);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][1], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][1], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi][1], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi][1], 1);

    PlayerTextdraws[playerid][textdraw_interaksi][2] = CreatePlayerTextDraw(playerid, 273.000, 420.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi][2], 16.000, -1.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi][2], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][2], 162631167);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][2], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][2], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi][2], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi][2], 1);

    PlayerTextdraws[playerid][textdraw_interaksi][3] = CreatePlayerTextDraw(playerid, 273.000, 420.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi][3], 1.000, -21.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi][3], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][3], 162631167);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][3], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][3], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi][3], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi][3], 1);

    PlayerTextdraws[playerid][textdraw_interaksi][4] = CreatePlayerTextDraw(playerid, 289.000, 420.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi][4], 1.000, -22.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi][4], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][4], 162631167);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][4], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][4], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi][4], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi][4], 1);

    PlayerTextdraws[playerid][textdraw_interaksi][5] = CreatePlayerTextDraw(playerid, 275.500, 403.500, "ALT");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi][5], 0.200, 1.199);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi][5], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][5], 163025407);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][5], 1);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][5], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi][5], 1);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi][5], 1);

    PlayerTextdraws[playerid][textdraw_interaksi][6] = CreatePlayerTextDraw(playerid, 293.500, 395.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi][6], 68.000, 27.500);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi][6], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][6], 371731455);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][6], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][6], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi][6], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi][6], 1);

    PlayerTextdraws[playerid][textdraw_interaksi][7] = CreatePlayerTextDraw(playerid, 296.000, 401.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi][7], 63.000, 18.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi][7], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][7], 1768515940);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][7], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][7], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi][7], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi][7], 1);

    PlayerTextdraws[playerid][textdraw_interaksi][8] = CreatePlayerTextDraw(playerid, 296.000, 398.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi][8], 4.000, 3.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi][8], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][8], 162631167);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][8], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][8], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi][8], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi][8], 1);

    PlayerTextdraws[playerid][textdraw_interaksi][9] = CreatePlayerTextDraw(playerid, 326.500, 404.000, "Garasi Umum");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi][9], 0.140, 1.200);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi][9], 2);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][9], -1448498689);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][9], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi][9], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi][9], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi][9], 1);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi][9], 1);
}

hook OnPlayerConnect(playerid)
{
    CreateTDShortKey(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    for(new x = 0; x < 15; x++)
    {
        PlayerTextDrawDestroy(playerid, PlayerTextdraws[playerid][textdraw_interaksi][x]);
    }
}

ShowKey(playerid, const text[])
{
    PlayerTextDrawSetString(playerid, PlayerTextdraws[playerid][textdraw_interaksi][9], text);
    for(new x = 0; x < 10; x++)
    {
        PlayerTextDrawShow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][x]);
    }
    PlayerPlaySound(playerid, 1058, 0, 0, 0);
    return 1;
}

HideShortKey(playerid)
{
    for(new x = 0; x < 10; x++)
    {
        PlayerTextDrawHide(playerid, PlayerTextdraws[playerid][textdraw_interaksi][x]);
    }
    return 1;
}