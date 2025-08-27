stock LoadAnnouncementTD(playerid)
{
    ANNOUNCEMENT[playerid][0] = CreatePlayerTextDraw(playerid, 222.000, 7.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][0], 197.000, 48.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][0], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][0], -191362561);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][0], 255);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][0], 1);

    ANNOUNCEMENT[playerid][1] = CreatePlayerTextDraw(playerid, 249.000, 15.000, "Server Announcement by %s:");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][1], 0.230, 1.098);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][1], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][1], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][1], 1);

    ANNOUNCEMENT[playerid][2] = CreatePlayerTextDraw(playerid, 249.000, 27.000, "Server Akan segera badai");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][2], 0.209, 1.098);
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][2], 399.000, 0.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][2], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, ANNOUNCEMENT[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, ANNOUNCEMENT[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][2], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][2], 1);

    ANNOUNCEMENT[playerid][3] = CreatePlayerTextDraw(playerid, 228.000, 11.000, "/");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][3], 0.657, 3.197);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][3], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][3], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][3], 1);

    ANNOUNCEMENT[playerid][4] = CreatePlayerTextDraw(playerid, 235.000, 11.000, "\\");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][4], 0.657, 3.197);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][4], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][4], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][4], 1);

    ANNOUNCEMENT[playerid][5] = CreatePlayerTextDraw(playerid, 228.000, 27.000, "-");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][5], 1.610, 1.598);
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][5], 0.000, -62.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][5], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][5], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][5], 1);

    ANNOUNCEMENT[playerid][6] = CreatePlayerTextDraw(playerid, 236.000, 22.000, "!");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][6], 0.219, 1.299);
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][6], 0.000, -62.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][6], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][6], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][6], 1);

    ANNOUNCEMENT[playerid][7] = CreatePlayerTextDraw(playerid, 219.000, 6.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][7], 6.000, 5.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][7], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][7], -191362561);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][7], 255);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][7], 1);

    ANNOUNCEMENT[playerid][8] = CreatePlayerTextDraw(playerid, 219.000, 51.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][8], 6.000, 5.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][8], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][8], -191362561);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][8], 255);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][8], 1);

    ANNOUNCEMENT[playerid][9] = CreatePlayerTextDraw(playerid, 417.000, 5.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][9], 6.000, 9.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][9], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][9], -191362561);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][9], 255);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][9], 1);

    ANNOUNCEMENT[playerid][10] = CreatePlayerTextDraw(playerid, 417.000, 50.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][10], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][10], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][10], -191362561);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][10], 255);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][10], 1);

    ANNOUNCEMENT[playerid][11] = CreatePlayerTextDraw(playerid, 222.000, 9.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][11], -2.000, 45.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][11], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][11], -191362561);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][11], 255);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][11], 1);

    ANNOUNCEMENT[playerid][12] = CreatePlayerTextDraw(playerid, 418.000, 11.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][12], 4.000, 41.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][12], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][12], -191362561);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][12], 255);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][12], 1); 
}