#include <YSI_Coding/y_hooks>

hook OnPlayerConnect(playerid) {
    InfoJobs[playerid][0] = CreatePlayerTextDraw(playerid, 5.000, 274.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InfoJobs[playerid][0], 124.000, 1.000);
    PlayerTextDrawAlignment(playerid, InfoJobs[playerid][0], 1);
    PlayerTextDrawColor(playerid, InfoJobs[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, InfoJobs[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InfoJobs[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, InfoJobs[playerid][0], 255);
    PlayerTextDrawFont(playerid, InfoJobs[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, InfoJobs[playerid][0], 1);

    InfoJobs[playerid][1] = CreatePlayerTextDraw(playerid, 25.000, 272.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InfoJobs[playerid][1], 83.000, 4.000);
    PlayerTextDrawAlignment(playerid, InfoJobs[playerid][1], 1);
    PlayerTextDrawColor(playerid, InfoJobs[playerid][1], SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, InfoJobs[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InfoJobs[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, InfoJobs[playerid][1], 255);
    PlayerTextDrawFont(playerid, InfoJobs[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, InfoJobs[playerid][1], 1);

    InfoJobs[playerid][2] = CreatePlayerTextDraw(playerid, 5.000, 286.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InfoJobs[playerid][2], 127.000, 26.000);
    PlayerTextDrawAlignment(playerid, InfoJobs[playerid][2], 1);
    PlayerTextDrawColor(playerid, InfoJobs[playerid][2], 150);
    PlayerTextDrawSetShadow(playerid, InfoJobs[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InfoJobs[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, InfoJobs[playerid][2], 255);
    PlayerTextDrawFont(playerid, InfoJobs[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, InfoJobs[playerid][2], 1);

    InfoJobs[playerid][3] = CreatePlayerTextDraw(playerid, 20.000, 294.000, "You Have Joinned Jobs Penambang");
    PlayerTextDrawLetterSize(playerid, InfoJobs[playerid][3], 0.170, 0.900);
    PlayerTextDrawAlignment(playerid, InfoJobs[playerid][3], 1);
    PlayerTextDrawColor(playerid, InfoJobs[playerid][3], SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, InfoJobs[playerid][3], 1);
    PlayerTextDrawSetOutline(playerid, InfoJobs[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, InfoJobs[playerid][3], 150);
    PlayerTextDrawFont(playerid, InfoJobs[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, InfoJobs[playerid][3], 1);
    return Y_HOOKS_CONTINUE_RETURN_1;
}