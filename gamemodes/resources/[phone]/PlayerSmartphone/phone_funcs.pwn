#include <YSI\y_hooks>
new PlayerText: JadenDcrpPhone[MAX_PLAYERS][82];
new PlayerText: JadenDCRPTelponan[MAX_PLAYERS][45];
new PlayerText: JadenDCRPBankHP[MAX_PLAYERS][55];
new PlayerText: JadenDCRPSpotify[MAX_PLAYERS][47];
new PlayerText: JadenDCRPXLogin[MAX_PLAYERS][40];
new PlayerText: JadenDCRPXHome[MAX_PLAYERS][42];

ATRPhoneTwitterHomepageLoad(playerid)
{
    JadenDCRPXHome[playerid][0] = CreatePlayerTextDraw(playerid, 485.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][0], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][0], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][0], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][0], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][0], 1);

    JadenDCRPXHome[playerid][1] = CreatePlayerTextDraw(playerid, 569.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][1], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][1], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][1], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][1], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][1], 1);

    JadenDCRPXHome[playerid][2] = CreatePlayerTextDraw(playerid, 508.000, 122.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][2], 86.000, 287.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][2], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][2], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][2], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][2], 1);

    JadenDCRPXHome[playerid][3] = CreatePlayerTextDraw(playerid, 492.500, 140.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][3], 116.500, 251.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][3], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][3], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][3], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][3], 1);

    JadenDCRPXHome[playerid][4] = CreatePlayerTextDraw(playerid, 485.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][4], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][4], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][4], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][4], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][4], 1);

    JadenDCRPXHome[playerid][5] = CreatePlayerTextDraw(playerid, 486.500, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][5], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][5], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][5], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][5], 1);

    JadenDCRPXHome[playerid][6] = CreatePlayerTextDraw(playerid, 569.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][6], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][6], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][6], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][6], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][6], 1);

    JadenDCRPXHome[playerid][7] = CreatePlayerTextDraw(playerid, 509.000, 124.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][7], 82.000, 283.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][7], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][7], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][7], 1);

    JadenDCRPXHome[playerid][8] = CreatePlayerTextDraw(playerid, 494.000, 143.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][8], 113.500, 248.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][8], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][8], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][8], 1);

    JadenDCRPXHome[playerid][9] = CreatePlayerTextDraw(playerid, 568.299, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][9], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][9], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][9], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][9], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][9], 1);

    JadenDCRPXHome[playerid][10] = CreatePlayerTextDraw(playerid, 486.500, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][10], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][10], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][10], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][10], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][10], 1);

    JadenDCRPXHome[playerid][11] = CreatePlayerTextDraw(playerid, 568.299, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][11], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][11], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][11], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][11], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][11], 1);

    JadenDCRPXHome[playerid][12] = CreatePlayerTextDraw(playerid, 490.500, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][12], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][12], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][12], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][12], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][12], 1);

    JadenDCRPXHome[playerid][13] = CreatePlayerTextDraw(playerid, 497.299, 145.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][13], 107.000, 240.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][13], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][13], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][13], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][13], 1);

    JadenDCRPXHome[playerid][14] = CreatePlayerTextDraw(playerid, 510.299, 128.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][14], 82.000, 275.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][14], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][14], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][14], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][14], 1);

    JadenDCRPXHome[playerid][15] = CreatePlayerTextDraw(playerid, 570.000, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][15], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][15], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][15], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][15], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][15], 1);

    JadenDCRPXHome[playerid][16] = CreatePlayerTextDraw(playerid, 490.500, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][16], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][16], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][16], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][16], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][16], 1);

    JadenDCRPXHome[playerid][17] = CreatePlayerTextDraw(playerid, 570.000, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][17], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][17], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][17], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][17], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][17], 1);

    JadenDCRPXHome[playerid][18] = CreatePlayerTextDraw(playerid, 527.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][18], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][18], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][18], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][18], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][18], 1);

    JadenDCRPXHome[playerid][19] = CreatePlayerTextDraw(playerid, 560.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][19], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][19], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][19], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][19], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][19], 1);

    JadenDCRPXHome[playerid][20] = CreatePlayerTextDraw(playerid, 534.500, 131.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][20], 32.000, 10.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][20], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][20], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][20], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][20], 1);

    JadenDCRPXHome[playerid][21] = CreatePlayerTextDraw(playerid, 564.500, 134.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][21], 4.000, 4.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][21], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][21], 1768516095);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][21], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][21], 1);

    JadenDCRPXHome[playerid][22] = CreatePlayerTextDraw(playerid, 565.500, 135.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][22], 2.000, 2.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][22], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][22], 32842);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][22], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][22], 1);

    JadenDCRPXHome[playerid][23] = CreatePlayerTextDraw(playerid, 608.000, 186.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][23], 3.500, 39.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][23], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][23], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][23], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][23], 1);

    JadenDCRPXHome[playerid][24] = CreatePlayerTextDraw(playerid, 491.500, 155.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][24], 2.000, 14.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][24], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][24], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][24], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][24], 1);

    JadenDCRPXHome[playerid][25] = CreatePlayerTextDraw(playerid, 491.500, 178.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][25], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][25], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][25], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][25], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][25], 1);

    JadenDCRPXHome[playerid][26] = CreatePlayerTextDraw(playerid, 491.500, 206.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][26], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][26], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][26], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][26], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][26], 1);

    JadenDCRPXHome[playerid][27] = CreatePlayerTextDraw(playerid, 514.000, 131.000, "12 : 00");
    PlayerTextDrawLetterSize(playerid, JadenDCRPXHome[playerid][27], 0.140, 1.098);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][27], 2);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][27], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][27], 150);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][27], 1);

    JadenDCRPXHome[playerid][28] = CreatePlayerTextDraw(playerid, 586.000, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][28], 10.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][28], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][28], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][28], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][28], 1);

    JadenDCRPXHome[playerid][29] = CreatePlayerTextDraw(playerid, 594.500, 134.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][29], 3.000, 3.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][29], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][29], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][29], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][29], 1);

    JadenDCRPXHome[playerid][30] = CreatePlayerTextDraw(playerid, 582.000, 132.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][30], 0.898, 7.697);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][30], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][30], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][30], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][30], 1);

    JadenDCRPXHome[playerid][31] = CreatePlayerTextDraw(playerid, 580.000, 132.600, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][31], 0.898, 6.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][31], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][31], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][31], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][31], 1);

    JadenDCRPXHome[playerid][32] = CreatePlayerTextDraw(playerid, 577.700, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][32], 0.898, 6.400);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][32], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][32], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][32], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][32], 1);

    JadenDCRPXHome[playerid][33] = CreatePlayerTextDraw(playerid, 575.700, 134.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][33], 0.898, 5.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][33], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][33], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][33], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][33], 1);

    JadenDCRPXHome[playerid][34] = CreatePlayerTextDraw(playerid, 551.000, 205.000, "NeroSuki.");
    PlayerTextDrawLetterSize(playerid, JadenDCRPXHome[playerid][34], 0.218, 1.299);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][34], 2);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][34], 150);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][34], 1);

    JadenDCRPXHome[playerid][35] = CreatePlayerTextDraw(playerid, 534.000, 186.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][35], 32.000, 20.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][35], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][35], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][35], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][35], 1);

    JadenDCRPXHome[playerid][36] = CreatePlayerTextDraw(playerid, 542.000, 169.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][36], 16.000, 21.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][36], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][36], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][36], 1);

    JadenDCRPXHome[playerid][37] = CreatePlayerTextDraw(playerid, 525.500, 260.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][37], 51.000, 15.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][37], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][37], 512819199);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][37], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][37], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPXHome[playerid][37], 1);

    JadenDCRPXHome[playerid][38] = CreatePlayerTextDraw(playerid, 525.500, 285.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][38], 51.000, 15.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][38], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][38], 512819199);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][38], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][38], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPXHome[playerid][38], 1);

    JadenDCRPXHome[playerid][39] = CreatePlayerTextDraw(playerid, 551.000, 261.000, "Tweet");
    PlayerTextDrawLetterSize(playerid, JadenDCRPXHome[playerid][39], 0.218, 1.299);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][39], 2);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][39], 150);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][39], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][39], 1);

    JadenDCRPXHome[playerid][40] = CreatePlayerTextDraw(playerid, 551.000, 285.000, "Logout");
    PlayerTextDrawLetterSize(playerid, JadenDCRPXHome[playerid][40], 0.218, 1.299);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][40], 2);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][40], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][40], 150);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][40], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][40], 1);

    JadenDCRPXHome[playerid][41] = CreatePlayerTextDraw(playerid, 525.500, 391.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXHome[playerid][41], 51.000, 5.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXHome[playerid][41], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXHome[playerid][41], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXHome[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXHome[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXHome[playerid][41], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXHome[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXHome[playerid][41], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPXHome[playerid][41], 1);
    return 1;
}

ATRPhoneTwitterHomepageUnload(playerid)
{
    for(new i; i < 42; i++) PlayerTextDrawDestroy(playerid, JadenDCRPXHome[playerid][i]);
    return 1;
}

ATRPhoneTwitterHomeLoad(playerid)
{
    JadenDCRPXLogin[playerid][0] = CreatePlayerTextDraw(playerid, 485.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][0], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][0], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][0], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][0], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][0], 1);

    JadenDCRPXLogin[playerid][1] = CreatePlayerTextDraw(playerid, 569.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][1], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][1], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][1], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][1], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][1], 1);

    JadenDCRPXLogin[playerid][2] = CreatePlayerTextDraw(playerid, 508.000, 122.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][2], 86.000, 287.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][2], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][2], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][2], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][2], 1);

    JadenDCRPXLogin[playerid][3] = CreatePlayerTextDraw(playerid, 492.500, 140.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][3], 116.500, 251.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][3], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][3], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][3], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][3], 1);

    JadenDCRPXLogin[playerid][4] = CreatePlayerTextDraw(playerid, 485.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][4], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][4], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][4], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][4], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][4], 1);

    JadenDCRPXLogin[playerid][5] = CreatePlayerTextDraw(playerid, 486.500, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][5], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][5], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][5], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][5], 1);

    JadenDCRPXLogin[playerid][6] = CreatePlayerTextDraw(playerid, 569.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][6], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][6], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][6], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][6], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][6], 1);

    JadenDCRPXLogin[playerid][7] = CreatePlayerTextDraw(playerid, 509.000, 124.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][7], 82.000, 283.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][7], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][7], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][7], 1);

    JadenDCRPXLogin[playerid][8] = CreatePlayerTextDraw(playerid, 494.000, 143.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][8], 113.500, 248.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][8], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][8], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][8], 1);

    JadenDCRPXLogin[playerid][9] = CreatePlayerTextDraw(playerid, 568.299, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][9], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][9], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][9], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][9], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][9], 1);

    JadenDCRPXLogin[playerid][10] = CreatePlayerTextDraw(playerid, 486.500, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][10], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][10], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][10], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][10], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][10], 1);

    JadenDCRPXLogin[playerid][11] = CreatePlayerTextDraw(playerid, 568.299, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][11], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][11], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][11], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][11], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][11], 1);

    JadenDCRPXLogin[playerid][12] = CreatePlayerTextDraw(playerid, 490.500, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][12], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][12], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][12], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][12], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][12], 1);

    JadenDCRPXLogin[playerid][13] = CreatePlayerTextDraw(playerid, 497.299, 145.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][13], 107.000, 240.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][13], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][13], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][13], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][13], 1);

    JadenDCRPXLogin[playerid][14] = CreatePlayerTextDraw(playerid, 510.299, 128.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][14], 82.000, 275.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][14], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][14], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][14], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][14], 1);

    JadenDCRPXLogin[playerid][15] = CreatePlayerTextDraw(playerid, 570.000, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][15], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][15], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][15], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][15], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][15], 1);

    JadenDCRPXLogin[playerid][16] = CreatePlayerTextDraw(playerid, 490.500, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][16], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][16], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][16], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][16], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][16], 1);

    JadenDCRPXLogin[playerid][17] = CreatePlayerTextDraw(playerid, 570.000, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][17], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][17], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][17], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][17], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][17], 1);

    JadenDCRPXLogin[playerid][18] = CreatePlayerTextDraw(playerid, 527.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][18], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][18], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][18], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][18], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][18], 1);

    JadenDCRPXLogin[playerid][19] = CreatePlayerTextDraw(playerid, 560.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][19], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][19], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][19], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][19], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][19], 1);

    JadenDCRPXLogin[playerid][20] = CreatePlayerTextDraw(playerid, 534.500, 131.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][20], 32.000, 10.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][20], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][20], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][20], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][20], 1);

    JadenDCRPXLogin[playerid][21] = CreatePlayerTextDraw(playerid, 564.500, 134.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][21], 4.000, 4.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][21], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][21], 1768516095);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][21], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][21], 1);

    JadenDCRPXLogin[playerid][22] = CreatePlayerTextDraw(playerid, 565.500, 135.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][22], 2.000, 2.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][22], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][22], 32842);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][22], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][22], 1);

    JadenDCRPXLogin[playerid][23] = CreatePlayerTextDraw(playerid, 608.000, 186.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][23], 3.500, 39.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][23], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][23], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][23], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][23], 1);

    JadenDCRPXLogin[playerid][24] = CreatePlayerTextDraw(playerid, 491.500, 155.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][24], 2.000, 14.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][24], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][24], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][24], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][24], 1);

    JadenDCRPXLogin[playerid][25] = CreatePlayerTextDraw(playerid, 491.500, 178.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][25], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][25], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][25], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][25], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][25], 1);

    JadenDCRPXLogin[playerid][26] = CreatePlayerTextDraw(playerid, 491.500, 206.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][26], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][26], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][26], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][26], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][26], 1);

    JadenDCRPXLogin[playerid][27] = CreatePlayerTextDraw(playerid, 514.000, 131.000, "12 : 00");
    PlayerTextDrawLetterSize(playerid, JadenDCRPXLogin[playerid][27], 0.140, 1.098);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][27], 2);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][27], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][27], 150);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][27], 1);

    JadenDCRPXLogin[playerid][28] = CreatePlayerTextDraw(playerid, 586.000, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][28], 10.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][28], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][28], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][28], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][28], 1);

    JadenDCRPXLogin[playerid][29] = CreatePlayerTextDraw(playerid, 594.500, 134.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][29], 3.000, 3.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][29], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][29], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][29], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][29], 1);

    JadenDCRPXLogin[playerid][30] = CreatePlayerTextDraw(playerid, 582.000, 132.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][30], 0.898, 7.697);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][30], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][30], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][30], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][30], 1);

    JadenDCRPXLogin[playerid][31] = CreatePlayerTextDraw(playerid, 580.000, 132.600, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][31], 0.898, 6.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][31], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][31], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][31], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][31], 1);

    JadenDCRPXLogin[playerid][32] = CreatePlayerTextDraw(playerid, 577.700, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][32], 0.898, 6.400);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][32], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][32], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][32], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][32], 1);

    JadenDCRPXLogin[playerid][33] = CreatePlayerTextDraw(playerid, 575.700, 134.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][33], 0.898, 5.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][33], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][33], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][33], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][33], 1);

    JadenDCRPXLogin[playerid][34] = CreatePlayerTextDraw(playerid, 541.000, 180.000, "Hai, Selamat datang di Twitter, Silahkan login!");
    PlayerTextDrawLetterSize(playerid, JadenDCRPXLogin[playerid][34], 0.167, 1.098);
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][34], 158.000, 77.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][34], 2);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][34], 150);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][34], 1);

    JadenDCRPXLogin[playerid][35] = CreatePlayerTextDraw(playerid, 525.500, 220.000, "LD_BUM:blkdot");    //login
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][35], 51.000, 17.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][35], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][35], 12582911);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][35], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][35], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPXLogin[playerid][35], 1);

    JadenDCRPXLogin[playerid][36] = CreatePlayerTextDraw(playerid, 550.500, 222.500, "Login");
    PlayerTextDrawLetterSize(playerid, JadenDCRPXLogin[playerid][36], 0.167, 1.098);
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][36], 158.000, 77.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][36], 2);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][36], 150);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][36], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][36], 1);

    JadenDCRPXLogin[playerid][37] = CreatePlayerTextDraw(playerid, 527.000, 276.000, "Belum punya akun?");
    PlayerTextDrawLetterSize(playerid, JadenDCRPXLogin[playerid][37], 0.167, 1.098);
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][37], 158.000, 77.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][37], 2);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][37], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][37], 150);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][37], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][37], 1);

    JadenDCRPXLogin[playerid][38] = CreatePlayerTextDraw(playerid, 579.000, 276.500, "Sign In");
    PlayerTextDrawLetterSize(playerid, JadenDCRPXLogin[playerid][38], 0.167, 1.098);
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][38], 158.000, 77.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][38], 2);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][38], 512819199);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][38], 150);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][38], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][38], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPXLogin[playerid][38], 1);

    JadenDCRPXLogin[playerid][39] = CreatePlayerTextDraw(playerid, 525.500, 391.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPXLogin[playerid][39], 51.000, 5.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPXLogin[playerid][39], 1);
    PlayerTextDrawColor(playerid, JadenDCRPXLogin[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPXLogin[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPXLogin[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPXLogin[playerid][39], 255);
    PlayerTextDrawFont(playerid, JadenDCRPXLogin[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPXLogin[playerid][39], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPXLogin[playerid][39], 1);
    return 1;
}

ATRPhoneTwitterHomeUnload(playerid)
{
    for(new i; i < 40; i++) PlayerTextDrawDestroy(playerid, JadenDCRPXLogin[playerid][i]);
    return 1;
}

ATRPhoneLoad(playerid)
{
    JadenDcrpPhone[playerid][0] = CreatePlayerTextDraw(playerid, 485.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][0], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][0], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][0], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][0], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][0], 1);

    JadenDcrpPhone[playerid][1] = CreatePlayerTextDraw(playerid, 569.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][1], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][1], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][1], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][1], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][1], 1);

    JadenDcrpPhone[playerid][2] = CreatePlayerTextDraw(playerid, 508.000, 122.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][2], 86.000, 287.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][2], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][2], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][2], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][2], 1);

    JadenDcrpPhone[playerid][3] = CreatePlayerTextDraw(playerid, 492.500, 140.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][3], 116.500, 251.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][3], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][3], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][3], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][3], 1);

    JadenDcrpPhone[playerid][4] = CreatePlayerTextDraw(playerid, 485.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][4], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][4], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][4], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][4], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][4], 1);

    JadenDcrpPhone[playerid][5] = CreatePlayerTextDraw(playerid, 486.500, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][5], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][5], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][5], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][5], 1);

    JadenDcrpPhone[playerid][6] = CreatePlayerTextDraw(playerid, 569.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][6], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][6], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][6], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][6], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][6], 1);

    JadenDcrpPhone[playerid][7] = CreatePlayerTextDraw(playerid, 509.000, 124.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][7], 82.000, 283.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][7], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][7], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][7], 1);

    JadenDcrpPhone[playerid][8] = CreatePlayerTextDraw(playerid, 494.000, 143.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][8], 113.500, 248.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][8], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][8], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][8], 1);

    JadenDcrpPhone[playerid][9] = CreatePlayerTextDraw(playerid, 568.299, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][9], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][9], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][9], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][9], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][9], 1);

    JadenDcrpPhone[playerid][10] = CreatePlayerTextDraw(playerid, 486.500, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][10], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][10], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][10], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][10], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][10], 1);

    JadenDcrpPhone[playerid][11] = CreatePlayerTextDraw(playerid, 568.299, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][11], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][11], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][11], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][11], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][11], 1);

    JadenDcrpPhone[playerid][12] = CreatePlayerTextDraw(playerid, 490.500, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][12], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][12], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][12], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][12], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][12], 1);

    JadenDcrpPhone[playerid][13] = CreatePlayerTextDraw(playerid, 497.299, 145.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][13], 107.000, 240.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][13], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][13], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][13], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][13], 1);

    JadenDcrpPhone[playerid][14] = CreatePlayerTextDraw(playerid, 510.299, 128.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][14], 82.000, 275.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][14], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][14], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][14], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][14], 1);

    JadenDcrpPhone[playerid][15] = CreatePlayerTextDraw(playerid, 570.000, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][15], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][15], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][15], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][15], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][15], 1);

    JadenDcrpPhone[playerid][16] = CreatePlayerTextDraw(playerid, 490.500, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][16], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][16], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][16], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][16], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][16], 1);

    JadenDcrpPhone[playerid][17] = CreatePlayerTextDraw(playerid, 570.000, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][17], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][17], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][17], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][17], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][17], 1);

    JadenDcrpPhone[playerid][18] = CreatePlayerTextDraw(playerid, 527.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][18], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][18], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][18], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][18], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][18], 1);

    JadenDcrpPhone[playerid][19] = CreatePlayerTextDraw(playerid, 560.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][19], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][19], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][19], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][19], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][19], 1);

    JadenDcrpPhone[playerid][20] = CreatePlayerTextDraw(playerid, 534.500, 131.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][20], 32.000, 10.800);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][20], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][20], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][20], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][20], 1);

    JadenDcrpPhone[playerid][21] = CreatePlayerTextDraw(playerid, 564.500, 134.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][21], 4.000, 4.800);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][21], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][21], 1768516095);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][21], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][21], 1);

    JadenDcrpPhone[playerid][22] = CreatePlayerTextDraw(playerid, 565.500, 135.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][22], 2.000, 2.500);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][22], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][22], 32842);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][22], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][22], 1);

    JadenDcrpPhone[playerid][23] = CreatePlayerTextDraw(playerid, 608.000, 186.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][23], 3.500, 39.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][23], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][23], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][23], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][23], 1);

    JadenDcrpPhone[playerid][24] = CreatePlayerTextDraw(playerid, 491.500, 155.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][24], 2.000, 14.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][24], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][24], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][24], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][24], 1);

    JadenDcrpPhone[playerid][25] = CreatePlayerTextDraw(playerid, 491.500, 178.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][25], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][25], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][25], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][25], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][25], 1);

    JadenDcrpPhone[playerid][26] = CreatePlayerTextDraw(playerid, 491.500, 206.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][26], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][26], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][26], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][26], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][26], 1);

    JadenDcrpPhone[playerid][27] = CreatePlayerTextDraw(playerid, 497.000, 352.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][27], 28.000, 33.500);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][27], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][27], -1734894081);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][27], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][27], 1);

    JadenDcrpPhone[playerid][28] = CreatePlayerTextDraw(playerid, 497.000, 362.200, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][28], 28.000, 33.500);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][28], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][28], -1734894081);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][28], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][28], 1);

    JadenDcrpPhone[playerid][29] = CreatePlayerTextDraw(playerid, 501.500, 368.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][29], 99.000, 10.500);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][29], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][29], -1734894081);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][29], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][29], 1);

    JadenDcrpPhone[playerid][30] = CreatePlayerTextDraw(playerid, 577.000, 352.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][30], 28.000, 33.500);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][30], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][30], -1734894081);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][30], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][30], 1);

    JadenDcrpPhone[playerid][31] = CreatePlayerTextDraw(playerid, 577.000, 362.200, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][31], 28.000, 33.500);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][31], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][31], -1734894081);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][31], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][31], 1);

    JadenDcrpPhone[playerid][32] = CreatePlayerTextDraw(playerid, 511.500, 357.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][32], 80.000, 32.500);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][32], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][32], -1734894081);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][32], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][32], 1);

    JadenDcrpPhone[playerid][33] = CreatePlayerTextDraw(playerid, 551.000, 143.000, "12 : 00");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][33], 0.289, 2.089);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][33], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][33], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][33], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][33], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][33], 1);

    JadenDcrpPhone[playerid][34] = CreatePlayerTextDraw(playerid, 551.000, 163.000, "13 Oktober 2005");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][34], 0.187, 1.297);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][34], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][34], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][34], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][34], 1);

    JadenDcrpPhone[playerid][35] = CreatePlayerTextDraw(playerid, 586.000, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][35], 10.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][35], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][35], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][35], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][35], 1);

    JadenDcrpPhone[playerid][36] = CreatePlayerTextDraw(playerid, 594.500, 134.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][36], 3.000, 3.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][36], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][36], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][36], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][36], 1);

    JadenDcrpPhone[playerid][37] = CreatePlayerTextDraw(playerid, 507.500, 362.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][37], 20.000, 24.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][37], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][37], 852308735);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][37], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][37], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][37], 1);

    JadenDcrpPhone[playerid][38] = CreatePlayerTextDraw(playerid, 530.000, 362.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][38], 20.000, 24.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][38], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][38], 1887473919);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][38], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][38], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][38], 1);

    JadenDcrpPhone[playerid][39] = CreatePlayerTextDraw(playerid, 552.500, 362.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][39], 20.000, 24.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][39], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][39], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][39], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][39], 1);

    JadenDcrpPhone[playerid][40] = CreatePlayerTextDraw(playerid, 575.000, 362.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][40], 20.000, 24.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][40], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][40], 8388863);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][40], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][40], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][40], 1);

    JadenDcrpPhone[playerid][41] = CreatePlayerTextDraw(playerid, 500.500, 264.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][41], 23.000, 27.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][41], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][41], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][41], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][41], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][41], 1);

    JadenDcrpPhone[playerid][42] = CreatePlayerTextDraw(playerid, 526.500, 264.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][42], 23.000, 27.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][42], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][42], 579543807);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][42], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][42], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][42], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][42], 1);

    JadenDcrpPhone[playerid][43] = CreatePlayerTextDraw(playerid, 552.500, 264.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][43], 23.000, 27.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][43], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][43], 1182971135);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][43], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][43], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][43], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][43], 1);

    JadenDcrpPhone[playerid][44] = CreatePlayerTextDraw(playerid, 578.500, 264.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][44], 23.000, 27.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][44], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][44], 512819199);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][44], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][44], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][44], 1);

    JadenDcrpPhone[playerid][45] = CreatePlayerTextDraw(playerid, 500.500, 294.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][45], 23.000, 27.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][45], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][45], 2005441023);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][45], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][45], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][45], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][45], 1);

    JadenDcrpPhone[playerid][46] = CreatePlayerTextDraw(playerid, 526.500, 294.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][46], 23.000, 27.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][46], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][46], -2686721);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][46], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][46], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][46], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][46], 1);

    JadenDcrpPhone[playerid][47] = CreatePlayerTextDraw(playerid, 552.500, 294.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][47], 23.000, 27.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][47], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][47], -5963521);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][47], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][47], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][47], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][47], 1);

    JadenDcrpPhone[playerid][48] = CreatePlayerTextDraw(playerid, 578.500, 294.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][48], 23.000, 27.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][48], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][48], 8388863);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][48], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][48], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][48], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][48], 1);

    JadenDcrpPhone[playerid][49] = CreatePlayerTextDraw(playerid, 608.500, 186.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][49], 17.000, 42.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][49], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][49], 0);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][49], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][49], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][49], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDcrpPhone[playerid][49], 1);

    JadenDcrpPhone[playerid][50] = CreatePlayerTextDraw(playerid, 513.000, 365.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][50], 9.000, 8.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][50], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][50], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][50], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][50], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][50], 1);

    JadenDcrpPhone[playerid][51] = CreatePlayerTextDraw(playerid, 513.000, 374.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][51], 9.000, 8.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][51], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][51], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][51], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][51], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][51], 1);

    JadenDcrpPhone[playerid][52] = CreatePlayerTextDraw(playerid, 514.500, 364.000, "(");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][52], 0.550, 1.700);
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][52], -1.000, 7.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][52], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][52], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][52], -1);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][52], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][52], 1);

    JadenDcrpPhone[playerid][53] = CreatePlayerTextDraw(playerid, 535.000, 364.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][53], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][53], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][53], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][53], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][53], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][53], 1);

    JadenDcrpPhone[playerid][54] = CreatePlayerTextDraw(playerid, 533.200, 373.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][54], 14.000, 11.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][54], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][54], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][54], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][54], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][54], 1);

    JadenDcrpPhone[playerid][55] = CreatePlayerTextDraw(playerid, 551.000, 359.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][55], 23.000, 30.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][55], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][55], 12582911);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][55], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][55], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][55], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][55], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][55], 1);

    JadenDcrpPhone[playerid][56] = CreatePlayerTextDraw(playerid, 552.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][56], 21.000, 28.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][56], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][56], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][56], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][56], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][56], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][56], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][56], 1);

    JadenDcrpPhone[playerid][57] = CreatePlayerTextDraw(playerid, 553.000, 361.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][57], 19.000, 26.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][57], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][57], 12582911);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][57], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][57], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][57], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][57], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][57], 1);

    JadenDcrpPhone[playerid][58] = CreatePlayerTextDraw(playerid, 561.500, 370.000, "/");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][58], 0.349, 1.299);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][58], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][58], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][58], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][58], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][58], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][58], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][58], 1);

    JadenDcrpPhone[playerid][59] = CreatePlayerTextDraw(playerid, 563.098, 364.000, "/");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][59], 0.349, 1.250);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][59], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][59], -16776961);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][59], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][59], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][59], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][59], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][59], 1);

    JadenDcrpPhone[playerid][60] = CreatePlayerTextDraw(playerid, 573.500, 362.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][60], 23.000, 20.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][60], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][60], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][60], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][60], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][60], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][60], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][60], 1);

    JadenDcrpPhone[playerid][61] = CreatePlayerTextDraw(playerid, 581.500, 369.500, "/");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][61], 0.400, 1.299);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][61], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][61], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][61], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][61], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][61], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][61], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][61], 1);

    JadenDcrpPhone[playerid][62] = CreatePlayerTextDraw(playerid, 580.500, 369.500, "/");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][62], 0.400, 1.299);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][62], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][62], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][62], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][62], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][62], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][62], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][62], 1);

    JadenDcrpPhone[playerid][63] = CreatePlayerTextDraw(playerid, 511.500, 266.000, "X");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][63], 0.418, 2.398);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][63], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][63], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][63], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][63], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][63], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][63], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][63], 1);

    JadenDcrpPhone[playerid][64] = CreatePlayerTextDraw(playerid, 524.000, 262.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][64], 28.000, 32.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][64], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][64], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][64], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][64], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][64], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][64], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][64], 1);

    JadenDcrpPhone[playerid][65] = CreatePlayerTextDraw(playerid, 538.000, 268.000, "$");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][65], 0.379, 1.998);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][65], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][65], 6553855);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][65], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][65], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][65], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][65], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][65], 1);

    JadenDcrpPhone[playerid][66] = CreatePlayerTextDraw(playerid, 553.000, 271.000, "HUD:radar_gangB");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][66], 14.000, 14.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][66], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][66], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][66], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][66], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][66], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][66], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][66], 1);

    JadenDcrpPhone[playerid][67] = CreatePlayerTextDraw(playerid, 560.000, 271.000, "HUD:radar_impound");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][67], 14.000, 14.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][67], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][67], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][67], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][67], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][67], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][67], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][67], 1);

    JadenDcrpPhone[playerid][68] = CreatePlayerTextDraw(playerid, 584.000, 267.000, "HUD:radar_gangG");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][68], 12.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][68], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][68], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][68], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][68], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][68], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][68], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][68], 1);

    JadenDcrpPhone[playerid][69] = CreatePlayerTextDraw(playerid, 580.000, 275.000, "HUD:radar_gangP");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][69], 12.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][69], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][69], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][69], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][69], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][69], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][69], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][69], 1);

    JadenDcrpPhone[playerid][70] = CreatePlayerTextDraw(playerid, 588.000, 275.000, "HUD:radar_gangY");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][70], 12.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][70], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][70], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][70], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][70], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][70], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][70], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][70], 1);

    JadenDcrpPhone[playerid][71] = CreatePlayerTextDraw(playerid, 505.000, 301.000, "HUD:radar_airYard");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][71], 14.000, 14.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][71], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][71], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][71], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][71], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][71], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][71], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][71], 1);

    JadenDcrpPhone[playerid][72] = CreatePlayerTextDraw(playerid, 524.500, 294.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][72], 27.000, 28.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][72], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][72], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][72], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][72], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][72], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][72], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][72], 1);

    JadenDcrpPhone[playerid][73] = CreatePlayerTextDraw(playerid, 543.000, 291.000, "/");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][73], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][73], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][73], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][73], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][73], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][73], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][73], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][73], 1);

    JadenDcrpPhone[playerid][74] = CreatePlayerTextDraw(playerid, 532.000, 309.000, "/");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][74], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][74], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][74], 255);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][74], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][74], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][74], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][74], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][74], 1);

    JadenDcrpPhone[playerid][75] = CreatePlayerTextDraw(playerid, 537.299, 304.000, "Maxim");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][75], 0.158, 0.699);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][75], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][75], -5963521);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][75], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][75], 1);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][75], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][75], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][75], 1);

    JadenDcrpPhone[playerid][76] = CreatePlayerTextDraw(playerid, 563.000, 296.000, "Y");
    PlayerTextDrawLetterSize(playerid, JadenDcrpPhone[playerid][76], 0.418, 2.398);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][76], 2);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][76], -2686721);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][76], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][76], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][76], 150);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][76], 1);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][76], 1);

    JadenDcrpPhone[playerid][77] = CreatePlayerTextDraw(playerid, 580.500, 297.000, "HUD:radar_dateDisco");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][77], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][77], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][77], -1);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][77], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][77], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][77], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][77], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][77], 1);

    JadenDcrpPhone[playerid][78] = CreatePlayerTextDraw(playerid, 582.000, 132.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][78], 0.898, 7.697);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][78], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][78], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][78], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][78], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][78], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][78], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][78], 1);

    JadenDcrpPhone[playerid][79] = CreatePlayerTextDraw(playerid, 580.000, 132.600, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][79], 0.898, 6.800);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][79], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][79], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][79], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][79], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][79], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][79], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][79], 1);

    JadenDcrpPhone[playerid][80] = CreatePlayerTextDraw(playerid, 577.700, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][80], 0.898, 6.400);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][80], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][80], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][80], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][80], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][80], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][80], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][80], 1);

    JadenDcrpPhone[playerid][81] = CreatePlayerTextDraw(playerid, 575.700, 134.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDcrpPhone[playerid][81], 0.898, 5.500);
    PlayerTextDrawAlignment(playerid, JadenDcrpPhone[playerid][81], 1);
    PlayerTextDrawColor(playerid, JadenDcrpPhone[playerid][81], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDcrpPhone[playerid][81], 0);
    PlayerTextDrawSetOutline(playerid, JadenDcrpPhone[playerid][81], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDcrpPhone[playerid][81], 255);
    PlayerTextDrawFont(playerid, JadenDcrpPhone[playerid][81], 4);
    PlayerTextDrawSetProportional(playerid, JadenDcrpPhone[playerid][81], 1);
}

ATRPhoneUnload(playerid)
{
    for(new i; i < 82; i++) PlayerTextDrawDestroy(playerid, JadenDcrpPhone[playerid][i]);
    return 1;
}

ATRPhoneCallLoad(playerid)
{
    JadenDCRPTelponan[playerid][0] = CreatePlayerTextDraw(playerid, 485.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][0], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][0], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][0], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][0], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][0], 1);

    JadenDCRPTelponan[playerid][1] = CreatePlayerTextDraw(playerid, 569.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][1], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][1], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][1], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][1], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][1], 1);

    JadenDCRPTelponan[playerid][2] = CreatePlayerTextDraw(playerid, 508.000, 122.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][2], 86.000, 287.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][2], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][2], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][2], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][2], 1);

    JadenDCRPTelponan[playerid][3] = CreatePlayerTextDraw(playerid, 492.500, 140.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][3], 116.500, 251.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][3], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][3], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][3], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][3], 1);

    JadenDCRPTelponan[playerid][4] = CreatePlayerTextDraw(playerid, 485.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][4], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][4], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][4], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][4], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][4], 1);

    JadenDCRPTelponan[playerid][5] = CreatePlayerTextDraw(playerid, 486.500, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][5], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][5], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][5], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][5], 1);

    JadenDCRPTelponan[playerid][6] = CreatePlayerTextDraw(playerid, 569.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][6], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][6], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][6], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][6], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][6], 1);

    JadenDCRPTelponan[playerid][7] = CreatePlayerTextDraw(playerid, 509.000, 124.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][7], 82.000, 283.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][7], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][7], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][7], 1);

    JadenDCRPTelponan[playerid][8] = CreatePlayerTextDraw(playerid, 494.000, 143.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][8], 113.500, 248.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][8], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][8], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][8], 1);

    JadenDCRPTelponan[playerid][9] = CreatePlayerTextDraw(playerid, 568.299, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][9], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][9], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][9], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][9], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][9], 1);

    JadenDCRPTelponan[playerid][10] = CreatePlayerTextDraw(playerid, 486.500, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][10], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][10], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][10], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][10], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][10], 1);

    JadenDCRPTelponan[playerid][11] = CreatePlayerTextDraw(playerid, 568.299, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][11], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][11], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][11], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][11], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][11], 1);

    JadenDCRPTelponan[playerid][12] = CreatePlayerTextDraw(playerid, 490.500, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][12], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][12], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][12], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][12], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][12], 1);

    JadenDCRPTelponan[playerid][13] = CreatePlayerTextDraw(playerid, 497.299, 145.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][13], 107.000, 240.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][13], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][13], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][13], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][13], 1);

    JadenDCRPTelponan[playerid][14] = CreatePlayerTextDraw(playerid, 510.299, 128.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][14], 82.000, 275.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][14], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][14], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][14], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][14], 1);

    JadenDCRPTelponan[playerid][15] = CreatePlayerTextDraw(playerid, 570.000, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][15], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][15], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][15], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][15], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][15], 1);

    JadenDCRPTelponan[playerid][16] = CreatePlayerTextDraw(playerid, 490.500, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][16], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][16], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][16], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][16], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][16], 1);

    JadenDCRPTelponan[playerid][17] = CreatePlayerTextDraw(playerid, 570.000, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][17], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][17], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][17], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][17], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][17], 1);

    JadenDCRPTelponan[playerid][18] = CreatePlayerTextDraw(playerid, 527.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][18], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][18], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][18], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][18], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][18], 1);

    JadenDCRPTelponan[playerid][19] = CreatePlayerTextDraw(playerid, 560.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][19], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][19], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][19], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][19], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][19], 1);

    JadenDCRPTelponan[playerid][20] = CreatePlayerTextDraw(playerid, 534.500, 131.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][20], 32.000, 10.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][20], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][20], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][20], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][20], 1);

    JadenDCRPTelponan[playerid][21] = CreatePlayerTextDraw(playerid, 564.500, 134.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][21], 4.000, 4.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][21], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][21], 1768516095);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][21], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][21], 1);

    JadenDCRPTelponan[playerid][22] = CreatePlayerTextDraw(playerid, 565.500, 135.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][22], 2.000, 2.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][22], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][22], 32842);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][22], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][22], 1);

    JadenDCRPTelponan[playerid][23] = CreatePlayerTextDraw(playerid, 608.000, 186.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][23], 3.500, 39.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][23], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][23], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][23], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][23], 1);

    JadenDCRPTelponan[playerid][24] = CreatePlayerTextDraw(playerid, 491.500, 155.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][24], 2.000, 14.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][24], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][24], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][24], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][24], 1);

    JadenDCRPTelponan[playerid][25] = CreatePlayerTextDraw(playerid, 491.500, 178.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][25], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][25], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][25], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][25], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][25], 1);

    JadenDCRPTelponan[playerid][26] = CreatePlayerTextDraw(playerid, 491.500, 206.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][26], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][26], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][26], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][26], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][26], 1);

    JadenDCRPTelponan[playerid][27] = CreatePlayerTextDraw(playerid, 514.000, 131.000, "12 : 00");
    PlayerTextDrawLetterSize(playerid, JadenDCRPTelponan[playerid][27], 0.140, 1.098);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][27], 2);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][27], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][27], 150);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][27], 1);

    JadenDCRPTelponan[playerid][28] = CreatePlayerTextDraw(playerid, 586.000, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][28], 10.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][28], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][28], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][28], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][28], 1);

    JadenDCRPTelponan[playerid][29] = CreatePlayerTextDraw(playerid, 594.500, 134.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][29], 3.000, 3.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][29], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][29], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][29], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][29], 1);

    JadenDCRPTelponan[playerid][30] = CreatePlayerTextDraw(playerid, 582.000, 132.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][30], 0.898, 7.697);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][30], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][30], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][30], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][30], 1);

    JadenDCRPTelponan[playerid][31] = CreatePlayerTextDraw(playerid, 580.000, 132.600, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][31], 0.898, 6.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][31], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][31], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][31], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][31], 1);

    JadenDCRPTelponan[playerid][32] = CreatePlayerTextDraw(playerid, 577.700, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][32], 0.898, 6.400);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][32], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][32], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][32], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][32], 1);

    JadenDCRPTelponan[playerid][33] = CreatePlayerTextDraw(playerid, 575.700, 134.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][33], 0.898, 5.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][33], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][33], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][33], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][33], 1);

    JadenDCRPTelponan[playerid][34] = CreatePlayerTextDraw(playerid, 551.000, 205.000, "Nero Mevousa");    //nama kontak
    PlayerTextDrawLetterSize(playerid, JadenDCRPTelponan[playerid][34], 0.218, 1.299);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][34], 2);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][34], 150);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][34], 1);

    JadenDCRPTelponan[playerid][35] = CreatePlayerTextDraw(playerid, 534.000, 186.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][35], 32.000, 20.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][35], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][35], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][35], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][35], 1);

    JadenDCRPTelponan[playerid][36] = CreatePlayerTextDraw(playerid, 542.000, 169.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][36], 16.000, 21.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][36], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][36], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][36], 1);

    JadenDCRPTelponan[playerid][37] = CreatePlayerTextDraw(playerid, 550.000, 220.000, "Panggilan Masuk...");  //status dialling
    PlayerTextDrawLetterSize(playerid, JadenDCRPTelponan[playerid][37], 0.218, 1.299);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][37], 2);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][37], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][37], 150);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][37], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][37], 1);

    JadenDCRPTelponan[playerid][38] = CreatePlayerTextDraw(playerid, 512.500, 321.000, "LD_BEAT:chit"); //tolak telpon
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][38], 35.000, 40.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][38], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][38], -16776961);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][38], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][38], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPTelponan[playerid][38], 1);

    JadenDCRPTelponan[playerid][39] = CreatePlayerTextDraw(playerid, 552.500, 321.000, "LD_BEAT:chit");  //angkat telpon
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][39], 35.000, 40.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][39], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][39], 579543807);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][39], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][39], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPTelponan[playerid][39], 1);

    JadenDCRPTelponan[playerid][40] = CreatePlayerTextDraw(playerid, 529.299, 331.000, "X");
    PlayerTextDrawLetterSize(playerid, JadenDCRPTelponan[playerid][40], 0.468, 1.999);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][40], 2);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][40], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][40], 150);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][40], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][40], 1);

    JadenDCRPTelponan[playerid][41] = CreatePlayerTextDraw(playerid, 572.299, 329.000, "/");
    PlayerTextDrawLetterSize(playerid, JadenDCRPTelponan[playerid][41], 0.518, 2.099);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][41], 2);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][41], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][41], 150);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][41], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][41], 1);

    JadenDCRPTelponan[playerid][42] = CreatePlayerTextDraw(playerid, 567.299, 350.000, "/");
    PlayerTextDrawLetterSize(playerid, JadenDCRPTelponan[playerid][42], 0.668, -1.101);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][42], 2);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][42], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][42], 150);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][42], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][42], 1);

    JadenDCRPTelponan[playerid][43] = CreatePlayerTextDraw(playerid, 512.500, 321.000, "LD_BEAT:chit");    //matikan telpon
    PlayerTextDrawTextSize(playerid, JadenDCRPTelponan[playerid][43], 35.000, 40.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPTelponan[playerid][43], 1);
    PlayerTextDrawColor(playerid, JadenDCRPTelponan[playerid][43], -16776961);
    PlayerTextDrawSetShadow(playerid, JadenDCRPTelponan[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPTelponan[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPTelponan[playerid][43], 255);
    PlayerTextDrawFont(playerid, JadenDCRPTelponan[playerid][43], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPTelponan[playerid][43], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPTelponan[playerid][43], 1);

    return 1;
}

ATRPhoneCallUnload(playerid)
{
    for(new i; i < 45; i++) PlayerTextDrawDestroy(playerid, JadenDCRPTelponan[playerid][i]);
    return 1;
}

ATRPhoneBankLoad(playerid)
{
    JadenDCRPBankHP[playerid][0] = CreatePlayerTextDraw(playerid, 485.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][0], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][0], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][0], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][0], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][0], 1);

    JadenDCRPBankHP[playerid][1] = CreatePlayerTextDraw(playerid, 569.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][1], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][1], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][1], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][1], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][1], 1);

    JadenDCRPBankHP[playerid][2] = CreatePlayerTextDraw(playerid, 508.000, 122.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][2], 86.000, 287.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][2], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][2], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][2], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][2], 1);

    JadenDCRPBankHP[playerid][3] = CreatePlayerTextDraw(playerid, 492.500, 140.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][3], 116.500, 251.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][3], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][3], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][3], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][3], 1);

    JadenDCRPBankHP[playerid][4] = CreatePlayerTextDraw(playerid, 485.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][4], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][4], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][4], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][4], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][4], 1);

    JadenDCRPBankHP[playerid][5] = CreatePlayerTextDraw(playerid, 486.500, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][5], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][5], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][5], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][5], 1);

    JadenDCRPBankHP[playerid][6] = CreatePlayerTextDraw(playerid, 569.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][6], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][6], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][6], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][6], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][6], 1);

    JadenDCRPBankHP[playerid][7] = CreatePlayerTextDraw(playerid, 509.000, 124.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][7], 82.000, 283.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][7], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][7], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][7], 1);

    JadenDCRPBankHP[playerid][8] = CreatePlayerTextDraw(playerid, 494.000, 143.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][8], 113.500, 248.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][8], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][8], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][8], 1);

    JadenDCRPBankHP[playerid][9] = CreatePlayerTextDraw(playerid, 568.299, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][9], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][9], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][9], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][9], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][9], 1);

    JadenDCRPBankHP[playerid][10] = CreatePlayerTextDraw(playerid, 486.500, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][10], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][10], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][10], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][10], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][10], 1);

    JadenDCRPBankHP[playerid][11] = CreatePlayerTextDraw(playerid, 568.299, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][11], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][11], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][11], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][11], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][11], 1);

    JadenDCRPBankHP[playerid][12] = CreatePlayerTextDraw(playerid, 490.500, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][12], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][12], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][12], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][12], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][12], 1);

    JadenDCRPBankHP[playerid][13] = CreatePlayerTextDraw(playerid, 497.299, 145.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][13], 107.000, 240.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][13], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][13], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][13], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][13], 1);

    JadenDCRPBankHP[playerid][14] = CreatePlayerTextDraw(playerid, 510.299, 128.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][14], 82.000, 275.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][14], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][14], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][14], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][14], 1);

    JadenDCRPBankHP[playerid][15] = CreatePlayerTextDraw(playerid, 570.000, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][15], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][15], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][15], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][15], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][15], 1);

    JadenDCRPBankHP[playerid][16] = CreatePlayerTextDraw(playerid, 490.500, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][16], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][16], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][16], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][16], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][16], 1);

    JadenDCRPBankHP[playerid][17] = CreatePlayerTextDraw(playerid, 570.000, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][17], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][17], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][17], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][17], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][17], 1);

    JadenDCRPBankHP[playerid][18] = CreatePlayerTextDraw(playerid, 527.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][18], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][18], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][18], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][18], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][18], 1);

    JadenDCRPBankHP[playerid][19] = CreatePlayerTextDraw(playerid, 560.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][19], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][19], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][19], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][19], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][19], 1);

    JadenDCRPBankHP[playerid][20] = CreatePlayerTextDraw(playerid, 534.500, 131.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][20], 32.000, 10.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][20], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][20], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][20], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][20], 1);

    JadenDCRPBankHP[playerid][21] = CreatePlayerTextDraw(playerid, 564.500, 134.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][21], 4.000, 4.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][21], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][21], 1768516095);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][21], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][21], 1);

    JadenDCRPBankHP[playerid][23] = CreatePlayerTextDraw(playerid, 608.000, 186.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][23], 3.500, 39.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][23], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][23], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][23], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][23], 1);

    JadenDCRPBankHP[playerid][24] = CreatePlayerTextDraw(playerid, 491.500, 155.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][24], 2.000, 14.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][24], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][24], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][24], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][24], 1);

    JadenDCRPBankHP[playerid][25] = CreatePlayerTextDraw(playerid, 491.500, 178.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][25], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][25], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][25], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][25], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][25], 1);

    JadenDCRPBankHP[playerid][26] = CreatePlayerTextDraw(playerid, 491.500, 206.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][26], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][26], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][26], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][26], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][26], 1);

    JadenDCRPBankHP[playerid][27] = CreatePlayerTextDraw(playerid, 514.000, 131.000, "12 : 00");
    PlayerTextDrawLetterSize(playerid, JadenDCRPBankHP[playerid][27], 0.140, 1.098);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][27], 2);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][27], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][27], 150);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][27], 1);

    JadenDCRPBankHP[playerid][28] = CreatePlayerTextDraw(playerid, 586.000, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][28], 10.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][28], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][28], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][28], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][28], 1);

    JadenDCRPBankHP[playerid][29] = CreatePlayerTextDraw(playerid, 594.500, 134.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][29], 3.000, 3.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][29], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][29], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][29], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][29], 1);

    JadenDCRPBankHP[playerid][30] = CreatePlayerTextDraw(playerid, 582.000, 132.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][30], 0.898, 7.697);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][30], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][30], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][30], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][30], 1);

    JadenDCRPBankHP[playerid][31] = CreatePlayerTextDraw(playerid, 580.000, 132.600, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][31], 0.898, 6.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][31], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][31], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][31], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][31], 1);

    JadenDCRPBankHP[playerid][32] = CreatePlayerTextDraw(playerid, 577.700, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][32], 0.898, 6.400);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][32], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][32], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][32], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][32], 1);

    JadenDCRPBankHP[playerid][33] = CreatePlayerTextDraw(playerid, 575.700, 134.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][33], 0.898, 5.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][33], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][33], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][33], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][33], 1);

    JadenDCRPBankHP[playerid][34] = CreatePlayerTextDraw(playerid, 503.000, 218.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][34], 16.000, 23.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][34], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][34], 52735);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][34], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][34], 1);

    JadenDCRPBankHP[playerid][35] = CreatePlayerTextDraw(playerid, 503.000, 275.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][35], 16.000, 23.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][35], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][35], 52735);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][35], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][35], 1);

    JadenDCRPBankHP[playerid][36] = CreatePlayerTextDraw(playerid, 583.299, 218.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][36], 16.000, 23.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][36], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][36], 52735);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][36], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][36], 1);

    JadenDCRPBankHP[playerid][37] = CreatePlayerTextDraw(playerid, 583.299, 275.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][37], 16.000, 23.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][37], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][37], 52735);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][37], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][37], 1);

    JadenDCRPBankHP[playerid][38] = CreatePlayerTextDraw(playerid, 505.799, 226.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][38], 90.500, 63.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][38], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][38], 52735);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][38], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][38], 1);

    JadenDCRPBankHP[playerid][39] = CreatePlayerTextDraw(playerid, 512.500, 222.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][39], 77.000, 72.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][39], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][39], 52735);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][39], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][39], 1);

    JadenDCRPBankHP[playerid][40] = CreatePlayerTextDraw(playerid, 551.000, 205.000, "Nero Mevousa");
    PlayerTextDrawLetterSize(playerid, JadenDCRPBankHP[playerid][40], 0.219, 1.299);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][40], 2);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][40], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][40], 150);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][40], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][40], 1);

    JadenDCRPBankHP[playerid][41] = CreatePlayerTextDraw(playerid, 534.000, 186.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][41], 32.000, 20.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][41], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][41], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][41], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][41], 1);

    JadenDCRPBankHP[playerid][42] = CreatePlayerTextDraw(playerid, 542.000, 169.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][42], 16.000, 21.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][42], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][42], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][42], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][42], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][42], 1);

    JadenDCRPBankHP[playerid][43] = CreatePlayerTextDraw(playerid, 522.000, 222.000, "JVBANKING");
    PlayerTextDrawLetterSize(playerid, JadenDCRPBankHP[playerid][43], 0.150, 1.100);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][43], 2);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][43], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][43], 150);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][43], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][43], 1);

    JadenDCRPBankHP[playerid][44] = CreatePlayerTextDraw(playerid, 512.000, 244.000, "$");
    PlayerTextDrawLetterSize(playerid, JadenDCRPBankHP[playerid][44], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][44], 2);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][44], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][44], 150);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][44], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][44], 1);

    JadenDCRPBankHP[playerid][45] = CreatePlayerTextDraw(playerid, 512.000, 244.000, "131005");
    PlayerTextDrawLetterSize(playerid, JadenDCRPBankHP[playerid][45], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][45], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][45], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][45], 150);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][45], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][45], 1);

    JadenDCRPBankHP[playerid][46] = CreatePlayerTextDraw(playerid, 521.000, 260.000, "Total Uang");
    PlayerTextDrawLetterSize(playerid, JadenDCRPBankHP[playerid][46], 0.150, 1.100);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][46], 2);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][46], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][46], 150);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][46], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][46], 1);

    JadenDCRPBankHP[playerid][47] = CreatePlayerTextDraw(playerid, 510.000, 283.000, "13102005");
    PlayerTextDrawLetterSize(playerid, JadenDCRPBankHP[playerid][47], 0.159, 0.898);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][47], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][47], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][47], 150);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][47], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][47], 1);

    JadenDCRPBankHP[playerid][48] = CreatePlayerTextDraw(playerid, 563.000, 244.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][48], 22.000, 26.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][48], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][48], -16776961);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][48], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][48], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][48], 1);

    JadenDCRPBankHP[playerid][49] = CreatePlayerTextDraw(playerid, 572.000, 244.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][49], 22.000, 26.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][49], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][49], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][49], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][49], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][49], 1);

    JadenDCRPBankHP[playerid][50] = CreatePlayerTextDraw(playerid, 512.500, 315.000, "LD_BUM:blkdot");    //transfer
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][50], 77.000, 20.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][50], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][50], 8192200);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][50], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][50], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][50], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPBankHP[playerid][50], 1);

    JadenDCRPBankHP[playerid][51] = CreatePlayerTextDraw(playerid, 512.500, 340.000, "LD_BUM:blkdot");    //invoice
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][51], 77.000, 20.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][51], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][51], 8192200);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][51], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][51], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][51], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPBankHP[playerid][51], 1);

    JadenDCRPBankHP[playerid][52] = CreatePlayerTextDraw(playerid, 550.000, 317.500, "Transfer");
    PlayerTextDrawLetterSize(playerid, JadenDCRPBankHP[playerid][52], 0.180, 1.400);
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][52], 40.000, 39.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][52], 2);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][52], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][52], 150);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][52], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][52], 1);

    JadenDCRPBankHP[playerid][53] = CreatePlayerTextDraw(playerid, 550.000, 342.000, "Invoice");
    PlayerTextDrawLetterSize(playerid, JadenDCRPBankHP[playerid][53], 0.180, 1.400);
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][53], 40.000, 39.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][53], 2);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][53], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][53], 150);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][53], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][53], 1);

    JadenDCRPBankHP[playerid][54] = CreatePlayerTextDraw(playerid, 525.500, 391.000, "LD_BUM:blkdot");    //close bank
    PlayerTextDrawTextSize(playerid, JadenDCRPBankHP[playerid][54], 51.000, 5.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPBankHP[playerid][54], 1);
    PlayerTextDrawColor(playerid, JadenDCRPBankHP[playerid][54], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPBankHP[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPBankHP[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPBankHP[playerid][54], 255);
    PlayerTextDrawFont(playerid, JadenDCRPBankHP[playerid][54], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPBankHP[playerid][54], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPBankHP[playerid][54], 1);
    return 1;
}

ATRPhoneBankUnload(playerid)
{
    for(new i; i < 55; i++) PlayerTextDrawDestroy(playerid, JadenDCRPBankHP[playerid][i]);
    return 1;
}

ATRPhoneSpotifyLoad(playerid)
{
    JadenDCRPSpotify[playerid][0] = CreatePlayerTextDraw(playerid, 485.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][0], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][0], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][0], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][0], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][0], 1);

    JadenDCRPSpotify[playerid][1] = CreatePlayerTextDraw(playerid, 569.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][1], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][1], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][1], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][1], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][1], 1);

    JadenDCRPSpotify[playerid][2] = CreatePlayerTextDraw(playerid, 508.000, 122.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][2], 86.000, 287.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][2], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][2], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][2], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][2], 1);

    JadenDCRPSpotify[playerid][3] = CreatePlayerTextDraw(playerid, 492.500, 140.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][3], 116.500, 251.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][3], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][3], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][3], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][3], 1);

    JadenDCRPSpotify[playerid][4] = CreatePlayerTextDraw(playerid, 485.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][4], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][4], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][4], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][4], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][4], 1);

    JadenDCRPSpotify[playerid][5] = CreatePlayerTextDraw(playerid, 486.500, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][5], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][5], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][5], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][5], 1);

    JadenDCRPSpotify[playerid][6] = CreatePlayerTextDraw(playerid, 569.000, 112.597, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][6], 48.000, 59.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][6], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][6], 1600086015);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][6], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][6], 1);

    JadenDCRPSpotify[playerid][7] = CreatePlayerTextDraw(playerid, 509.000, 124.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][7], 82.000, 283.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][7], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][7], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][7], 1);

    JadenDCRPSpotify[playerid][8] = CreatePlayerTextDraw(playerid, 494.000, 143.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][8], 113.500, 248.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][8], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][8], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][8], 1);

    JadenDCRPSpotify[playerid][9] = CreatePlayerTextDraw(playerid, 568.299, 115.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][9], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][9], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][9], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][9], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][9], 1);

    JadenDCRPSpotify[playerid][10] = CreatePlayerTextDraw(playerid, 486.500, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][10], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][10], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][10], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][10], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][10], 1);

    JadenDCRPSpotify[playerid][11] = CreatePlayerTextDraw(playerid, 568.299, 362.299, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][11], 47.000, 54.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][11], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][11], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][11], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][11], 1);

    JadenDCRPSpotify[playerid][12] = CreatePlayerTextDraw(playerid, 490.500, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][12], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][12], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][12], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][12], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][12], 1);

    JadenDCRPSpotify[playerid][13] = CreatePlayerTextDraw(playerid, 497.299, 145.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][13], 107.000, 240.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][13], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][13], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][13], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][13], 1);

    JadenDCRPSpotify[playerid][14] = CreatePlayerTextDraw(playerid, 510.299, 128.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][14], 82.000, 275.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][14], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][14], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][14], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][14], 1);

    JadenDCRPSpotify[playerid][15] = CreatePlayerTextDraw(playerid, 570.000, 120.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][15], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][15], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][15], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][15], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][15], 1);

    JadenDCRPSpotify[playerid][16] = CreatePlayerTextDraw(playerid, 490.500, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][16], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][16], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][16], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][16], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][16], 1);

    JadenDCRPSpotify[playerid][17] = CreatePlayerTextDraw(playerid, 570.000, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][17], 41.000, 46.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][17], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][17], 471539967);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][17], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][17], 1);

    JadenDCRPSpotify[playerid][18] = CreatePlayerTextDraw(playerid, 527.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][18], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][18], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][18], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][18], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][18], 1);

    JadenDCRPSpotify[playerid][19] = CreatePlayerTextDraw(playerid, 560.500, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][19], 13.000, 15.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][19], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][19], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][19], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][19], 1);

    JadenDCRPSpotify[playerid][20] = CreatePlayerTextDraw(playerid, 534.500, 131.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][20], 32.000, 10.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][20], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][20], 255);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][20], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][20], 1);

    JadenDCRPSpotify[playerid][21] = CreatePlayerTextDraw(playerid, 564.500, 134.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][21], 4.000, 4.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][21], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][21], 1768516095);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][21], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][21], 1);

    JadenDCRPSpotify[playerid][22] = CreatePlayerTextDraw(playerid, 565.500, 135.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][22], 2.000, 2.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][22], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][22], 32842);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][22], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][22], 1);

    JadenDCRPSpotify[playerid][23] = CreatePlayerTextDraw(playerid, 608.000, 186.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][23], 3.500, 39.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][23], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][23], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][23], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][23], 1);

    JadenDCRPSpotify[playerid][24] = CreatePlayerTextDraw(playerid, 491.500, 155.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][24], 2.000, 14.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][24], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][24], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][24], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][24], 1);

    JadenDCRPSpotify[playerid][25] = CreatePlayerTextDraw(playerid, 491.500, 178.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][25], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][25], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][25], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][25], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][25], 1);

    JadenDCRPSpotify[playerid][26] = CreatePlayerTextDraw(playerid, 491.500, 206.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][26], 2.000, 22.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][26], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][26], 1179010815);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][26], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][26], 1);

    JadenDCRPSpotify[playerid][27] = CreatePlayerTextDraw(playerid, 514.000, 131.000, "12 : 00");
    PlayerTextDrawLetterSize(playerid, JadenDCRPSpotify[playerid][27], 0.140, 1.098);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][27], 2);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][27], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][27], 150);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][27], 1);

    JadenDCRPSpotify[playerid][28] = CreatePlayerTextDraw(playerid, 586.000, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][28], 10.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][28], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][28], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][28], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][28], 1);

    JadenDCRPSpotify[playerid][29] = CreatePlayerTextDraw(playerid, 594.500, 134.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][29], 3.000, 3.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][29], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][29], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][29], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][29], 1);

    JadenDCRPSpotify[playerid][30] = CreatePlayerTextDraw(playerid, 582.000, 132.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][30], 0.898, 7.698);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][30], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][30], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][30], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][30], 1);

    JadenDCRPSpotify[playerid][31] = CreatePlayerTextDraw(playerid, 580.000, 132.600, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][31], 0.898, 6.800);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][31], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][31], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][31], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][31], 1);

    JadenDCRPSpotify[playerid][32] = CreatePlayerTextDraw(playerid, 577.700, 133.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][32], 0.898, 6.400);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][32], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][32], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][32], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][32], 1);

    JadenDCRPSpotify[playerid][33] = CreatePlayerTextDraw(playerid, 575.700, 134.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][33], 0.898, 5.500);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][33], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][33], -1061109505);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][33], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][33], 1);

    JadenDCRPSpotify[playerid][35] = CreatePlayerTextDraw(playerid, 498.000, 195.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][35], 106.000, 30.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][35], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][35], 1768516020);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][35], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][35], 1);

    JadenDCRPSpotify[playerid][36] = CreatePlayerTextDraw(playerid, 552.000, 166.000, "Putar Di Earphone");
    PlayerTextDrawLetterSize(playerid, JadenDCRPSpotify[playerid][36], 0.230, 1.598);
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][36], -92.000, 72.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][36], 2);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][36], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][36], 150);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][36], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][36], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPSpotify[playerid][36], 1);

    JadenDCRPSpotify[playerid][37] = CreatePlayerTextDraw(playerid, 552.000, 202.000, "Putar Di Boombox");
    PlayerTextDrawLetterSize(playerid, JadenDCRPSpotify[playerid][37], 0.230, 1.598);
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][37], -54.000, 72.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][37], 2);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][37], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][37], 150);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][37], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][37], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPSpotify[playerid][37], 1);

    JadenDCRPSpotify[playerid][38] = CreatePlayerTextDraw(playerid, 532.000, 236.000, "Hai, bagaimana kabarmu?");
    PlayerTextDrawLetterSize(playerid, JadenDCRPSpotify[playerid][38], 0.158, 1.098);
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][38], -61.000, 90.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][38], 2);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][38], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][38], 150);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][38], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][38], 1);

    JadenDCRPSpotify[playerid][39] = CreatePlayerTextDraw(playerid, 503.500, 290.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][39], 95.000, 40.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][39], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][39], 1768516020);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][39], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][39], 1);

    JadenDCRPSpotify[playerid][40] = CreatePlayerTextDraw(playerid, 506.000, 293.000, "LD_SPAC:backgnd");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][40], 26.000, 34.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][40], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][40], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][40], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][40], 1);

    JadenDCRPSpotify[playerid][41] = CreatePlayerTextDraw(playerid, 522.000, 275.000, "Lagu favoritmu :");
    PlayerTextDrawLetterSize(playerid, JadenDCRPSpotify[playerid][41], 0.158, 1.098);
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][41], -61.000, 90.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][41], 2);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][41], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][41], 150);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][41], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][41], 1);

    JadenDCRPSpotify[playerid][42] = CreatePlayerTextDraw(playerid, 545.000, 292.000, "Album :");
    PlayerTextDrawLetterSize(playerid, JadenDCRPSpotify[playerid][42], 0.158, 1.098);
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][42], -61.000, 90.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][42], 2);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][42], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][42], 150);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][42], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][42], 1);

    JadenDCRPSpotify[playerid][43] = CreatePlayerTextDraw(playerid, 555.000, 303.000, "Garam dan Madu");
    PlayerTextDrawLetterSize(playerid, JadenDCRPSpotify[playerid][43], 0.158, 1.098);
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][43], -61.000, 90.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][43], 2);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][43], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][43], 150);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][43], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][43], 1);

    JadenDCRPSpotify[playerid][44] = CreatePlayerTextDraw(playerid, 566.000, 315.000, "Song by Tenxi, Jemsii & Naykilla");
    PlayerTextDrawLetterSize(playerid, JadenDCRPSpotify[playerid][44], 0.128, 1.098);
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][44], -61.000, 90.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][44], 2);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][44], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][44], 150);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][44], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][44], 1);

    JadenDCRPSpotify[playerid][45] = CreatePlayerTextDraw(playerid, 551.000, 336.000, "Semoga harimu menyenangkan dengan mendengarkan lagu di spotify");
    PlayerTextDrawLetterSize(playerid, JadenDCRPSpotify[playerid][45], 0.158, 1.098);
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][45], -61.000, 90.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][45], 2);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][45], -1448498689);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][45], 150);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][45], 1);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][45], 1);

    JadenDCRPSpotify[playerid][46] = CreatePlayerTextDraw(playerid, 525.500, 391.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenDCRPSpotify[playerid][46], 51.000, 5.000);
    PlayerTextDrawAlignment(playerid, JadenDCRPSpotify[playerid][46], 1);
    PlayerTextDrawColor(playerid, JadenDCRPSpotify[playerid][46], -1);
    PlayerTextDrawSetShadow(playerid, JadenDCRPSpotify[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, JadenDCRPSpotify[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenDCRPSpotify[playerid][46], 255);
    PlayerTextDrawFont(playerid, JadenDCRPSpotify[playerid][46], 4);
    PlayerTextDrawSetProportional(playerid, JadenDCRPSpotify[playerid][46], 1);
    PlayerTextDrawSetSelectable(playerid, JadenDCRPSpotify[playerid][46], 1);
    return 1;
}

ATRPhoneSpotifyUnload(playerid)
{
    for(new i; i < 47; i++) PlayerTextDrawDestroy(playerid, JadenDCRPSpotify[playerid][i]);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    if (IsValidDynamicMapIcon(SharelocSender[playerid]))
    {
        DestroyDynamicMapIcon(SharelocSender[playerid]);
        SharelocSender[playerid] = INVALID_STREAMER_ID;
    }

    ATRPhoneLoad(playerid);
    ATRPhoneCallLoad(playerid);
    ATRPhoneBankLoad(playerid);
    ATRPhoneSpotifyLoad(playerid);
    ATRPhoneTwitterHomepageLoad(playerid);
    ATRPhoneTwitterHomeLoad(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    // If player was in a call, terminate it properly
    if(AccountData[playerid][phoneDurringConversation] || AccountData[playerid][phoneIncomingCall])
    {
        // Get the other player in the call
        new otherPlayerID = AccountData[playerid][phoneCallingWithPlayerID];
        
        // First disconnect the voice call
        CallRemoteFunction("DisconnectPlayerCalling", "dd", playerid, otherPlayerID);
        
        // Reset player state variables
        AccountData[playerid][phoneIncomingCall] = false;
        AccountData[playerid][phoneDurringConversation] = false;
        AccountData[playerid][phoneCallingTime] = 0;
        AccountData[playerid][phoneCallingWithPlayerID] = INVALID_PLAYER_ID;
        
        // Clean up the other player if they're connected
        if(IsPlayerConnected(otherPlayerID))
        {
            // Reset their call variables
            AccountData[otherPlayerID][phoneCallingWithPlayerID] = INVALID_PLAYER_ID;
            AccountData[otherPlayerID][phoneIncomingCall] = false;
            AccountData[otherPlayerID][phoneDurringConversation] = false;
            AccountData[otherPlayerID][phoneCallingTime] = 0;
            StopAudioStreamForPlayer(otherPlayerID);
            
            // Clean up their UI
            if(!IsPlayerInAnyVehicle(otherPlayerID) && GetPlayerState(otherPlayerID) == PLAYER_STATE_ONFOOT)
            {
                ClearAnimations(otherPlayerID, 1);
                StopLoopingAnim(otherPlayerID);
                ApplyAnimation(otherPlayerID, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
            }
            RemovePlayerAttachedObject(otherPlayerID, 9);
            HideAllSmartphone(otherPlayerID);
            Toggle_CallTD(otherPlayerID, false);
            PlayerTextDrawHide(otherPlayerID, JadenDCRPTelponan[otherPlayerID][39]);
            PlayerTextDrawHide(otherPlayerID, JadenDCRPTelponan[otherPlayerID][38]);
            PlayerTextDrawHide(otherPlayerID, JadenDCRPTelponan[otherPlayerID][43]);
            if(AccountData[otherPlayerID][phoneShown]) 
            {
                AccountData[otherPlayerID][phoneShown] = false;
            }
            
            // Let them know the call was disconnected
            Info(otherPlayerID, "Telepon terputus, player yang lain telah terputus dari server.");
        }
        
        // Call DisconnectPlayerCalling again to ensure voice disconnection is complete
        CallRemoteFunction("DisconnectPlayerCalling", "dd", playerid, otherPlayerID);
    }

    if (IsValidDynamicMapIcon(SharelocSender[playerid]))
    {
        DestroyDynamicMapIcon(SharelocSender[playerid]);
        SharelocSender[playerid] = INVALID_STREAMER_ID;
        SharelocTimer[playerid] = 0;
    }

    ATRPhoneUnload(playerid);
    ATRPhoneCallUnload(playerid);
    ATRPhoneBankUnload(playerid);
    ATRPhoneSpotifyUnload(playerid);
    ATRPhoneTwitterHomepageUnload(playerid);
    ATRPhoneTwitterHomeUnload(playerid);
    return 1;
}

Toggle_PhoneTD(playerid, bool:toggle)
{
    if(!toggle)
    {
        for(new i; i < 82; i++) PlayerTextDrawHide(playerid, JadenDcrpPhone[playerid][i]);
    }
    else
    {
        for(new i; i < 82; i++) PlayerTextDrawShow(playerid, JadenDcrpPhone[playerid][i]);
    }
    return 1;
}

Toggle_CallTD(playerid, bool:toggle)
{
    if(!toggle)
    {
        for(new i; i < 45; i++) PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][i]);
    }
    else
    {
        for(new i; i < 45; i++) PlayerTextDrawShow(playerid, JadenDCRPTelponan[playerid][i]);
    }
    return 1;
}

Toggle_BankTD(playerid, bool:toggle)
{
    if(!toggle)
    {
        for(new i; i < 55; i++) PlayerTextDrawHide(playerid, JadenDCRPBankHP[playerid][i]);
    }
    else
    {
        PlayerTextDrawSetString(playerid, JadenDCRPBankHP[playerid][40], sprintf("%s", ReturnName(playerid)));
        PlayerTextDrawSetString(playerid, JadenDCRPBankHP[playerid][47], sprintf("%d", AccountData[playerid][pBankRek]));
        PlayerTextDrawSetString(playerid, JadenDCRPBankHP[playerid][45], sprintf("%s", FormatMoney(AccountData[playerid][pBankMoney])));
        for(new i; i < 55; i++) PlayerTextDrawShow(playerid, JadenDCRPBankHP[playerid][i]);
        PlayerTextDrawHide(playerid, JadenDCRPBankHP[playerid][44]);
    }
    return 1;
}

Toggle_SpotifyTD(playerid, bool:toggle)
{
    if(!toggle)
    {
        for(new i; i < 47; i++) PlayerTextDrawHide(playerid, JadenDCRPSpotify[playerid][i]);
    }
    else
    {
        for(new i; i < 47; i++) PlayerTextDrawShow(playerid, JadenDCRPSpotify[playerid][i]);
    }
    return 1;
}

Toggle_TwitterHome(playerid, bool:toggle)
{
    if(!toggle)
    {
        for(new i; i < 40; i++) PlayerTextDrawHide(playerid, JadenDCRPXLogin[playerid][i]);
    }
    else
    {
        for(new i; i < 40; i++) PlayerTextDrawShow(playerid, JadenDCRPXLogin[playerid][i]);
    }
    return 1;
}

Toggle_TwitterHomepage(playerid, bool:toggle)
{
    if(!toggle)
    {
        for(new i; i < 42; i++) PlayerTextDrawHide(playerid, JadenDCRPXHome[playerid][i]);
    }
    else
    {
        PlayerTextDrawSetString(playerid, JadenDCRPXHome[playerid][34], "%s", AccountData[playerid][TwitterName]);
        for(new i; i < 42; i++) PlayerTextDrawShow(playerid, JadenDCRPXHome[playerid][i]);
    }
    return 1;
}

HideAllSmartphone(playerid)
{
    Toggle_PhoneTD(playerid, false);
    Toggle_BankTD(playerid, false);
    Toggle_SpotifyTD(playerid, false);
    Toggle_TwitterHome(playerid, false);
    Toggle_TwitterHomepage(playerid, false);
    return 1;
}

ShowingSmartphone(playerid)
{
    if (IsPlayerInWater(playerid))
    {
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat membuka Smartphone di dalam air!");
    }

    if(!PlayerHasItem(playerid, "Smartphone"))
    {
        CancelSelectTextDraw(playerid);
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Smartphone!");
    }
    
    if(AccountData[playerid][pInjured])   
    {
        CancelSelectTextDraw(playerid);
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak bisa melakukannya saat ini!");
    }

    if(!AccountData[playerid][phoneShown])
    {
        SendRPMeAboveHead(playerid, "Membuka HP Miliknya", X11_PLUM1);
        if(AccountData[playerid][phoneDurringConversation] && AccountData[playerid][phoneCallingWithPlayerID] != INVALID_PLAYER_ID)
        {
            new otherid = AccountData[playerid][phoneCallingWithPlayerID];
            PlayerTextDrawSetString(playerid, JadenDCRPTelponan[playerid][34], sprintf("%s", GetMySavedContactName(playerid, AccountData[otherid][pPhone])));
            Toggle_CallTD(playerid, true);
            PlayerTextDrawShow(playerid, JadenDCRPTelponan[playerid][43]);
            AccountData[playerid][phoneShown] = true;
            return 1;
        }

        if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
        {
            ApplyAnimation(playerid, "CASINO", "cards_loop", 4.1, 0, 0, 0, 1, 0, 1);
            SetPlayerAttachedObject(playerid, 9, 18870, 6,  0.110000, 0.014999, 0.044999,  93.000000, 200.000000, -13.000000,  1.000000, 1.000000, 1.000000);
        }
        Toggle_PhoneTD(playerid, true);
        AccountData[playerid][phoneShown] = true;
        SelectTextDraw(playerid, COLOR_SYNTAX);
    }
    else 
    {
        AccountData[playerid][phoneShown] = false;
        Inventory_Close(playerid);
        CancelSelectTextDraw(playerid);
    }

    return 1;
}

CutCallingLine(playerid)
{
    new inlinewithplayerID = AccountData[playerid][phoneCallingWithPlayerID];
    AccountData[playerid][phoneIncomingCall] = false;
    AccountData[playerid][phoneDurringConversation] = false;
    AccountData[playerid][phoneCallingTime] = 0;
    
    if(IsPlayerConnected(inlinewithplayerID))
    {
        AccountData[inlinewithplayerID][phoneCallingWithPlayerID] = INVALID_PLAYER_ID;
        AccountData[inlinewithplayerID][phoneIncomingCall] = false;
        AccountData[inlinewithplayerID][phoneDurringConversation] = false;
        AccountData[inlinewithplayerID][phoneCallingTime] = 0;

        SendRPMeAboveHead(inlinewithplayerID, "Menutup HP miliknya.", X11_PLUM);

        if(!IsPlayerInAnyVehicle(inlinewithplayerID) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
        {
            ClearAnimations(inlinewithplayerID, 1);
            StopLoopingAnim(inlinewithplayerID);
            ApplyAnimation(inlinewithplayerID, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        }
        RemovePlayerAttachedObject(inlinewithplayerID, 9);
        HideAllSmartphone(inlinewithplayerID);
        Toggle_CallTD(inlinewithplayerID, false);
        PlayerTextDrawHide(inlinewithplayerID, JadenDCRPTelponan[inlinewithplayerID][39]);
        PlayerTextDrawHide(inlinewithplayerID, JadenDCRPTelponan[inlinewithplayerID][38]);
        PlayerTextDrawHide(inlinewithplayerID, JadenDCRPTelponan[inlinewithplayerID][43]);
        if(AccountData[inlinewithplayerID][phoneShown]) 
        {
            AccountData[inlinewithplayerID][phoneShown] = false;
        }
        CallRemoteFunction("DisconnectPlayerCalling", "dd", playerid, inlinewithplayerID);
        Info(inlinewithplayerID, "Telepon terputus...");
    }
    return 1;
}

forward OnOutcomingCall(playerid, const targetnumber[]);
public OnOutcomingCall(playerid, const targetnumber[])
{
    HideAllSmartphone(playerid);

    new contnstr[25];
    format(contnstr, sizeof(contnstr), "%s", targetnumber);
    for(new cid; cid < MAX_CONTACTS; ++cid)
    {
        if(ContactData[playerid][cid][contactExists])
        {
            if(!strcmp(ContactData[playerid][cid][contactNumber], targetnumber, false))
            {
                format(contnstr, sizeof(contnstr), "%s", ContactData[playerid][cid][contactName]);
            }
        }
    }
    PlayerTextDrawSetString(playerid, JadenDCRPTelponan[playerid][34], contnstr);
    PlayerTextDrawSetString(playerid, JadenDCRPTelponan[playerid][37], "Berdering...");

    new targetnumberownerid = GetNumberOwner(targetnumber);
    if(IsPlayerConnected(targetnumberownerid) && targetnumberownerid != INVALID_PLAYER_ID)
    {
        if(AccountData[targetnumberownerid][phoneAirplaneMode])
        {
            PlayerTextDrawSetString(playerid, JadenDCRPTelponan[playerid][37], "Nomor tidak aktif...");
            AccountData[playerid][phoneIncomingCall] = true;
        }
        else if(AccountData[targetnumberownerid][phoneIncomingCall] || AccountData[targetnumberownerid][phoneDurringConversation])
        {
            PlayerTextDrawSetString(playerid, JadenDCRPTelponan[playerid][37], "Panggilan sedang sibuk...");
            AccountData[playerid][phoneIncomingCall] = true;
        }
        else
        {
            AccountData[playerid][phoneCallingWithPlayerID] = targetnumberownerid;
            AccountData[playerid][phoneIncomingCall] = false;
            OnIncomingCall(targetnumberownerid, AccountData[playerid][pPhone]);
        }
    }
    ApplyAnimation(playerid, "ped", "phone_talk", 3.1, 0, 1, 0, 1, 1, 1);
    RemovePlayerAttachedObject(playerid, 9);
    SetPlayerAttachedObject(playerid, 9, 18870, 6,  0.099000, 0.009999, 0.000000,  78.200027, 179.000061, -1.500000,  1.000000, 1.000000, 1.000000); // 276
    Toggle_CallTD(playerid, true);
    PlayerTextDrawShow(playerid, JadenDCRPTelponan[playerid][43]);
    return 1;
}

forward OnIncomingCall(playerid, const fromnumber[]);
public OnIncomingCall(playerid, const fromnumber[])
{
    HideAllSmartphone(playerid);

    new contnstr[25];
    format(contnstr, sizeof(contnstr), "%s", fromnumber);
    for(new cid; cid < MAX_CONTACTS; ++cid)
    {
        if(ContactData[playerid][cid][contactExists])
        {
            if(!strcmp(ContactData[playerid][cid][contactNumber], fromnumber, false))
            {
                format(contnstr, sizeof(contnstr), "%s", ContactData[playerid][cid][contactName]);
            }
        }
    }
    if(!AccountData[playerid][phoneShown]) 
        AccountData[playerid][phoneShown] = true;

    PlayerTextDrawSetString(playerid, JadenDCRPTelponan[playerid][34], contnstr);
    PlayerTextDrawSetString(playerid, JadenDCRPTelponan[playerid][37], "Panggilan masuk...");
    PlayAudioStreamForPlayer(playerid, AccountData[playerid][phoneCallRingtone], 0.0, 0.0, 0.0, 30.0, 0); // Memulai Nada Dering Sendiri

    for(new i; i < 45; i++) PlayerTextDrawShow(playerid, JadenDCRPTelponan[playerid][i]);
    SelectTextDraw(playerid, COLOR_SYNTAX);
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case DIALOG_TWITTER_LOGIN:
        {
            if(!response) return 1;
            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DIALOG_TWITTER_LOGIN, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Login Twitter", 
            "Error: Tidak dapat diisi kosong!\nHai, selamat datang di Twitter!\nSilahkan masukkan username Twitter kamu yang telah terdaftar:", "Input", "Batal");

            if(strcmp(inputtext, AccountData[playerid][TwitterName])) return ShowTDN(playerid, NOTIFICATION_WARNING, sprintf("Akum Twitter %s tidak ditemukan!", inputtext));

            ShowPlayerDialog(playerid, DIALOG_TWITTER_LOGINPASSWORD, DIALOG_STYLE_PASSWORD, ""PINK1"DCRP"WHITE"- Login Twitter", 
            sprintf("Hai, %s!\nSilahkan masukkan kata sandi akun Twitter kamu untuk masuk:", inputtext), "Input", "Batal");
        }
        case DIALOG_TWITTER_LOGINPASSWORD:
        {
            if(!response) return 1;
            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DIALOG_TWITTER_LOGINPASSWORD, DIALOG_STYLE_PASSWORD, ""PINK1"DCRP"WHITE"- Login Twitter", 
            sprintf("Error: Anda harus memasukkan kata sandi!\nHai, %s!\nSilahkan masukkan kata sandi akun Twitter kamu untuk masuk:", AccountData[playerid][TwitterName]), "Input", "Batal");

            if(strcmp(inputtext, AccountData[playerid][TwitterPassword])) return ShowPlayerDialog(playerid, DIALOG_TWITTER_LOGINPASSWORD, DIALOG_STYLE_PASSWORD, ""PINK1"DCRP"WHITE"- Login Twitter", 
            sprintf("Error: Kata sandi yang anda masukkan salah!\nHai, %s!\nSilahkan masukkan kata sandi akun Twitter kamu untuk masuk:", AccountData[playerid][TwitterName]), "Input", "Batal");

            AccountData[playerid][Twitter] = true;
            Toggle_TwitterHome(playerid, false);
            Toggle_TwitterHomepage(playerid, true);
        }
        case DIALOG_TWITTER_SIGN:
        {
            if(!response) return 1;
            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DIALOG_TWITTER_SIGN, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Daftar Twitter", "Error: Tidak dapat diisi kosong!\nHai, selamat datang di Twitter!\
            \nSilahkan masukkan username Twitter kamu, ini akan ditampilkan pada setiap post tweet yang kamu buat:\
            \nIngat: Username hanya dapat berupa huruf dan angka, tidak menggunakan simbol!\
            \nPanjang username 7 - 24 karakter!", "Set", "Batal");

            if(strlen(inputtext) < 7 || strlen(inputtext) > 24) return ShowPlayerDialog(playerid, DIALOG_TWITTER_SIGN, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Daftar Twitter", "Error: Nama tidak dapat kurang dari 7 huruf atau lebih dari 24!\nHai, selamat datang di Twitter!\
            \nSilahkan masukkan username Twitter kamu, ini akan ditampilkan pada setiap post tweet yang kamu buat:\
            \nIngat: Username hanya dapat berupa huruf dan angka, tidak menggunakan simbol!\
            \nPanjang username 7 - 24 karakter!", "Set", "Batal");

            format(AccountData[playerid][pTempText], 24, inputtext);
            ShowPlayerDialog(playerid, DIALOG_TWITTER_SIGNPASSWORD, DIALOG_STYLE_PASSWORD, ""PINK1"DCRP"WHITE"- Daftar Twitter", 
            sprintf("Hai %s!\nSilahkan massukan kata sandi untuk akun Twitter kamu:\nIngat: Panjang kata sandi 7 - 32 Karakter!\nTahap ini tidak dapat dibatalkan!", inputtext), "Set", "");
        }
        case DIALOG_TWITTER_SIGNPASSWORD:
        {
            if(!response) return 1;
            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DIALOG_TWITTER_SIGNPASSWORD, DIALOG_STYLE_PASSWORD, ""PINK1"DCRP"WHITE"- Daftar Twitter", 
            sprintf("Error: Tidak dapat diisi kosong!\nHai, %s!\nSilahkan masukkan kata sandi untuk akun Twitter kamu:\nIngat: Panjang kata sandi 7 - 32 Karakter!\nTahap ini tidak dapat dibatalkan!", AccountData[playerid][pTempText]), "Set", "");

            if(strlen(inputtext) < 7 || strlen(inputtext) > 32) return ShowPlayerDialog(playerid, DIALOG_TWITTER_SIGNPASSWORD, DIALOG_STYLE_PASSWORD, ""PINK1"DCRP"WHITE"- Daftar Twitter", 
            sprintf("Error: Password tidak dapat kurang dari 7 atau 32 huruf!\nHai, %s!\nSilahkan masukkan kata sandi untuk akun Twitter kamu:\nIngat: Panjang kata sandi 7 - 32 Karakter!\nTahap ini tidak dapat dibatalkan!", AccountData[playerid][pTempText]), "Set", "");

            format(AccountData[playerid][TwitterName], 128, AccountData[playerid][pTempText]);
            format(AccountData[playerid][TwitterPassword], 64, inputtext);
            ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil membuat akun twitter, silahkan login!");
        }
        case DialogOpenContact:
        {
            if(!response) return 1;
            switch(listitem)
            {
                case 0: // 
                {
                    ShowPlayerDialog(playerid, DIALOG_ADD_CONTACT, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Tambah Kontak", 
                    "Mohon masukkan nama kontak yang akan disimpan dibawah ini:", "Set", "Batal");
                }
                case 1: //
                {
                    ShowContactList(playerid);
                }
            }
        }
        case DIALOG_AIRDROPDISPLAY:
        {
            if(!response) return 1;
            switch(listitem)
            {
                case 0: // izin airdrop
                {
                    switch(AccountData[playerid][AirdropPermission])
                    {
                        case false: AccountData[playerid][AirdropPermission] = true;
                        case true: AccountData[playerid][AirdropPermission] = false;
                    }

                    new strings[255];
                    format(strings, sizeof(strings), "Status: %s\
                    \nShare Contacts", AccountData[playerid][AirdropPermission] ? ""LIGHTGREEN"Share Contact diizinkan" : ""RED"Share Contact tidak diizinkan");
                    
                    ShowPlayerDialog(playerid, DIALOG_AIRDROPDISPLAY, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Airdrop", strings, "Pilih", "Batal");
                }
                case 1: // share
                {
                    if(!AccountData[playerid][AirdropPermission]) 
                        return ShowTDN(playerid, NOTIFICATION_WARNING, "Izinkan terlebih dahulu Permission Share Contact!");

                    new frmxt[255], count = 0;

                    foreach(new i : Player) if (i != playerid) if (IsPlayerNearPlayer(playerid, i, 2.0) && AccountData[i][AirdropPermission])
                    {
                        format(frmxt, sizeof(frmxt), "%sPlayer ID: %d\n", frmxt, i);
                        NearestPlayer[playerid][count++] = i;
                    }

                    if(count == 0)
                    {
                        PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
                        return ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""PINK1"DCRP"WHITE"- Airdrop",
                        "Tidak ada player yang dekat dengan anda!", "Tutup", "");
                    }

                    ShowPlayerDialog(playerid, DIALOG_AIRDROP, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Airdrop", frmxt, "Pilih", "Batal");
                }
            }
        }
        case DIALOG_AIRDROP:
        {
            if(!response) return 1;
            new targetid = NearestPlayer[playerid][listitem];
            if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
            if(!IsPlayerNearPlayer(playerid, targetid, 2.5)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak dekat dengan anda!");
            if(listitem == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih orang yang ingin anda bagikan kontak!");

            SetPVarString(targetid, "NumberPhone", AccountData[playerid][pPhone]);
            strpack(AccountData[targetid][pNamaAirdrop], ReturnName(playerid), MAX_PLAYER_NAME);

            new shstr[522];
            format(shstr, sizeof(shstr), "Anda menerima permintaan penyimpanan kotak dari:\nNama: %s\nNomor HP: %s\nApakah anda yakin ingin menyimpan kontak tersebut?", AccountData[playerid][pName], AccountData[playerid][pPhone]);
            ShowPlayerDialog(targetid, DIALOG_AIRDROP_CONF, DIALOG_STYLE_MSGBOX, ""PINK1"DCRP"WHITE"- Airdrop", shstr, "Iya", "Tidak");
        }
        case DIALOG_AIRDROP_CONF:
        {
            if(!response) return 1;

            new frmtname[64], frmtnumber[64], tss[255];            

            GetPVarString(playerid, "NumberPhone", frmtnumber, sizeof(frmtnumber));
            strunpack(frmtname, AccountData[playerid][pNamaAirdrop]);

            if(IsNumberAlreadySaved(playerid, frmtnumber)) return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Nomor tersebut sudah terdaftar di kontak atas nama %s", GetMySavedContactName(playerid, frmtnumber)));
            if(CountPlayerContact(playerid) >= MAX_CONTACTS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Penyimpanan kontak anda penuh!");

            for(new cid = 0; cid < MAX_CONTACTS; cid ++)
            {
                if(!ContactData[playerid][cid][contactExists])
                {
                    ContactData[playerid][cid][contactExists] = true;
                    ContactData[playerid][cid][contactOwnerID] = GetUCPSQLID(playerid);
                    format(ContactData[playerid][cid][contactNumber], sizeof(frmtnumber), "%s", frmtnumber);
                    format(ContactData[playerid][cid][contactName], sizeof(frmtname), "%s", frmtname);

                    mysql_format(dcrp_query, tss, sizeof(tss), "INSERT INTO `contacts` SET `ID`=%d, `contactName`='%s', `contactNumber`='%s', `contactOwner`=%d, `contactUnread`=0", GetUCPSQLID(playerid), ContactData[playerid][cid][contactName], ContactData[playerid][cid][contactNumber], ContactData[playerid][cid][contactOwnerID]);
                    mysql_tquery(dcrp_query, tss, "OnContactAdded", "dd", playerid, cid);
                    return 1;
                }
            }
        }
        case DANN_BOOMBOX:
        {
            if(!response)
            {
                SendClientMessageEx(playerid, COLOR_WHITE, ""VERONADOT"Kamu Membatalkan Music");
                return 1;
            }
            switch(listitem)
            {
                case 0:
                {
                    if(GetPVarType(playerid, "BBArea"))
                    {
                        SendRPMeAboveHead(playerid, "Mematikan musik", X11_PLUM1);
                        foreach(new i : Player)
                        {
                            if(IsPlayerInDynamicArea(i, GetPVarInt(playerid, "BBArea")))
                            {
                                StopStream(i);
                            }
                        }
                        DeletePVar(playerid, "BBStation");
                    }
                    SendClientMessageEx(playerid, COLOR_WHITE, "{00ff00}[!]{ffffff}: Kamu Telah Mematikan Boomboxnya");
                }
                case 1:
                {
                    static jskc[512];
                    format(jskc, sizeof(jskc), ""VERONA_ARWIN"Boombox Music - Cerahi Hidupmu Secerah Matahari Di Pagi Hari\n\n"VERONA_ARWIN"Kami sarankan anda untuk upload file mp3 ke discord terlebih dahulu.\n"RED_E"Note: Fitur ini tidak support link Youtube secara langsung!\n\n"YELLOW"(Apabila file mp3 telah di upload ke discord, silahkan copy linknya dan paste dibawah ini):");
                    ShowPlayerDialog(playerid,DANN_BOOMBOX1,DIALOG_STYLE_INPUT, "Boombox Play Music", jskc, "Play", "Cancel");
                }
            }
        }
        case DANN_BOOMBOX1:
        {
            if(response == 1)
            {
                if(isnull(inputtext))
                {
                    ShowTDN(playerid, NOTIFICATION_WARNING, "Kamu belum memasukan URL!");
                    // SendClientMessageEx(playerid, COLOR_WHITE, "{00ff00}[!]{ffffff}: Kamu Tidak Menulis Apapun");
                    return 1;
                }
                if(strlen(inputtext))
                {
                    if(GetPVarType(playerid, "PlacedBB"))
                    {
                        foreach(new i : Player)
                        {
                            if(IsPlayerInDynamicArea(i, GetPVarInt(playerid, "BBArea")))
                            {
                                PlayStream(i, inputtext, GetPVarFloat(playerid, "BBX"), GetPVarFloat(playerid, "BBY"), GetPVarFloat(playerid, "BBZ"), 30.0, 1);
                            }
                        }
                        SetPVarString(playerid, "BBStation", inputtext);
                    }
                }
            }
        }
        case DIALOG_ADD_CONTACT:
        {
            if(!response) return 1;

            if(isnull(inputtext))
            {
                ShowPlayerDialog(playerid, DIALOG_ADD_CONTACT, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Tambah Kontak", 
                "Error: Tidak dapat diisi kosong!\nMohon masukkan nama kontak yang akan disimpan dibawah ini:", "Set", "Batal");
                return 1;
            }

            if(strlen(inputtext) < 1 || strlen(inputtext) > 64)
            {
                ShowPlayerDialog(playerid, DIALOG_ADD_CONTACT, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Tambah Kontak", 
                "Error: Tidak dapat kurang dari 1 huruf atau lebih dari 64!\nMohon masukkan nama kontak yang akan disimpan dibawah ini:", "Set", "Batal");
                return 1;
            }
            
            strpack(AccountData[playerid][pTempText], inputtext, 64);
            ShowPlayerDialog(playerid, DIALOG_ADD_CONTACTNUMB, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Tambah Kontak",
            sprintf("Mohon masukkan nomor HP dari %s:", inputtext), "Input", "Kembali");
        }
        case DIALOG_ADD_CONTACTNUMB:
        {
            if(!response)
            {
                ShowPlayerDialog(playerid, DIALOG_ADD_CONTACT, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Tambah Kontak", 
                "Mohon masukkan nama kontak yang akan disimpan dibawah ini:", "Set", "Batal");
                return 1;
            }

            if(isnull(inputtext))
            {
                ShowPlayerDialog(playerid, DIALOG_ADD_CONTACTNUMB, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Tambah Kontak",
                "Error: Tidak dapat diisi kosong!\nMohon masukkan nomor HP kontak yang akan disimpan dibawah ini:", "Input", "Kembali");
                return 1;
            }

            if(!IsNumeric(inputtext))
            {
                ShowPlayerDialog(playerid, DIALOG_ADD_CONTACTNUMB, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Tambah Kontak",
                "Error: Masukkan nomor HP kontak hanya berisi angka!\nMohon masukkan nomor HP kontak yang akan disimpan dibawah ini:", "Input", "Kembali");
                return 1;
            }

            if(IsNumberAlreadySaved(playerid, inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Nomor tersebut sudah terdaftar di kontak atas nama %s", GetMySavedContactName(playerid, inputtext)));
            if(CountPlayerContact(playerid) >= MAX_CONTACTS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Penyimpanan kontak anda telah penuh!");

            new tss[255], frmtname[64];

            strunpack(frmtname, AccountData[playerid][pTempText]);
            for(new cid = 0; cid < MAX_CONTACTS; cid++)
            {
                if(!ContactData[playerid][cid][contactExists])
                {
                    ContactData[playerid][cid][contactExists] = true;
                    ContactData[playerid][cid][contactOwnerID] = GetUCPSQLID(playerid);
                    format(ContactData[playerid][cid][contactNumber], 64, inputtext);
                    format(ContactData[playerid][cid][contactName], 64, frmtname);
                
                    mysql_format(dcrp_query, tss, sizeof(tss), "INSERT INTO `contacts` SET `ID`=%d, `contactName`='%s', `contactNumber`='%s', `contactOwner`=%d, `contactUnread`=0", GetUCPSQLID(playerid), ContactData[playerid][cid][contactName], ContactData[playerid][cid][contactNumber], ContactData[playerid][cid][contactOwnerID]);
                    mysql_tquery(dcrp_query, tss, "OnContactAdded", "dd", playerid, cid);    
                    return 1;
                }
            }
        }
        case DialogTelepon:
        {
            if(!response) return 1;

            if(AccountData[playerid][phoneAirplaneMode])
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Smartphone sedang dalam Mode Pesawat!");

            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DialogTelepon, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Telepon", 
            "Error: Tidak dapat diisi kosong!\nMohon masukan nomor telepon yang ingin anda hubungi:", "Input", "Batal");
               
            if(!IsNumeric(inputtext)) return ShowPlayerDialog(playerid, DialogTelepon, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Telepon", 
            "Error: Hanya dapat diisi angka!\nMohon masukan nomor telepon yang ingin anda hubungi:", "Input", "Batal");

            if(!strcmp(inputtext, "110", true)) // Polisi
            {
                Dialog_Show(playerid, CALLCENTER_POLISI, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Panggilan Darurat Polisi",
                "Masukkan kendala anda yang ingin dilaporkan kepada pihak kepolisian dibawah ini\
                \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke kepolisian:", "Kirim", "Batal");
            }
            else if(!strcmp(inputtext, "118", true)) // Ems
            {
                Dialog_Show(playerid, CALLCENTER_EMS, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Panggilan Darurat Rumah Sakit",
                "Masukkan kendala anda yang ingin dilaporkan kepada pihak Rumah Sakit dibawah ini\
                \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke Rumah Sakit:", "Kirim", "Batal");
            }
            else if(!strcmp(inputtext, "117", true)) // Pemerintah
            {
                Dialog_Show(playerid, CALLCENTER_PEMDA, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Call Center Pemerintah",
                "Masukkan kendala anda yang ingin dilaporkan kepada pihak Pemerintah dibawah ini\
                \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke Pemerintah:", "Kirim", "Batal");
            }
            else
            {
                new targetnumberownerid = GetNumberOwner(inputtext);
                if(!IsPlayerConnected(targetnumberownerid) || targetnumberownerid == INVALID_PLAYER_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon maaf nomor tersebut sedang tidak aktif!");
                if(!strcmp(AccountData[playerid][pPhone], inputtext, false)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat menghubungi diri sendiri!");
                OnOutcomingCall(playerid, inputtext);
            }

    
        }
        case DialogContact:
        {
            new index = ListedContacts[playerid][listitem];

            if(!response)
            {
                ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan");

                PlayerContactPage[playerid] = 0;
                return true;
            }

            if(strfind(inputtext, "<< Halaman Sebelumnya") != -1)
            {
                PlayerContactPage[playerid] --;
                ShowContactList(playerid);
                return true;
            }

            if(strfind(inputtext, ">> Halaman Selanjutnya") != -1)
            {
                new next_page = PlayerContactPage[playerid] + 1;
                new start_index = next_page * 15;
                if(ContactData[playerid][start_index][contactExists])
                {
                    PlayerContactPage[playerid] ++;
                    ShowContactList(playerid);
                }
                else
                {
                    PlayerContactPage[playerid] = PlayerContactPage[playerid];
                    ShowContactList(playerid);
                    Error(playerid, "Anda tidak memiliki kontak lagi di halaman selanjutnya!");
                }
                return true;
            }

            /*if(!strcmp(inputtext, ">> Halaman Selanjutnya", true))
            {
                mysql_format(dcrp_query, query, sizeof(query), "SELECT * FROM `contacts` WHERE `ID` = %d ORDER BY ID ASC LIMIT %d, 15", AccountData[playerid][pID], (PlayerContactPage[playerid] + 1) * 15);
                result = mysql_query(dcrp_query, query, true);
                if(cache_num_rows())
                {
                    cache_delete(result);
                    PlayerContactPage[playerid] ++;
                    ShowContactList(playerid);
                }
                else
                {
                    cache_delete(result);
                    PlayerContactPage[playerid] = PlayerContactPage[playerid];
                    ShowContactList(playerid);
                }
                return true;
            }*/

            if(ContactData[playerid][index][contactExists])
            {
                AccountData[playerid][pContact] = index;
                
                ShowPlayerDialog(playerid, DialogContactMenu, DIALOG_STYLE_LIST, sprintf(""PINK1"DCRP"WHITE" - %s", ContactData[playerid][AccountData[playerid][pContact]][contactName]), 
                "Panggil\
                \n"GRAY"Whatsapp\
                \nShareloc\
                \n"GRAY"Edit Nama Kontak\
                \nEdit Nomor Kontak\
                \n"GRAY"Blokir/Buka Blokir Kontak\
                \nHapus Kontak", "Pilih", "Batal");
            }
            
            for(new i = 0; i < MAX_CONTACTS; i++) {
                ListedContacts[playerid][i] = -1;
            }
        }
        case DIALOG_YELLOW_PAGE_EMPTY:
        {
            if(!response)
            {
                return AccountData[playerid][CurrentlyReadYellow] = false;
            }

            ShowPlayerDialog(playerid, DIALOG_YELLOW_PAGE_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Buat Iklan", "Masukkan iklan yang ingin anda buat dibawah sini:", "Kirim", "Kembali");
        }
        case DIALOG_YELLOW_PAGE:
        {
            if(!response)
            {
                return AccountData[playerid][CurrentlyReadYellow] = false;
            }
            
            new cQuery[333];
            mysql_format(dcrp_query, cQuery, sizeof(cQuery), "SELECT * FROM `yellowpages` WHERE ID=1");
            mysql_query(dcrp_query, cQuery);
            if(cache_num_rows())
            {
                new YellowSender[64], YellowNumber[64], YellowMessage[128], frmxt[598];
                if(listitem >= 0 && listitem < cache_num_rows())
                {
                    cache_get_value_name(listitem, "YellowFrom", YellowSender);
                    cache_get_value_name(listitem, "YellowPhone", YellowNumber);
                    cache_get_value_name(listitem, "YellowText", YellowMessage);
                
                    SetPVarString(playerid, "YellowNumber", YellowNumber);
                    format(frmxt, sizeof(frmxt), ""WHITE"Pengirim: "YELLOW"%s\n"BLUEJEGE"%s", YellowSender, YellowMessage);
                    ShowPlayerDialog(playerid, DIALOG_YELLOW_CALL, DIALOG_STYLE_MSGBOX, ""PINK1"DCRP"WHITE"- Iklan",
                    frmxt, "Hubungi", "Batal");
                }
            }
        }
        case DIALOG_YELLOW_PAGE_MENU:
        {
            if(!response)
            {
                AccountData[playerid][CurrentlyReadYellow] = false;
                return 1;
            }
            
            switch(listitem)
            {
                case 0: // Lihat Iklan
                {
                    ShowPlayerYellowsPage(playerid);
                }
                case 1: //Buat Iklan
                {
                    ShowPlayerDialog(playerid, DIALOG_YELLOW_PAGE_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Buat Iklan", 
                    "Masukkan iklan yang ingin anda buat dibawah sini:", "Kirim", "Kembali");
                }
            }
        }
        case DIALOG_YELLOW_CALL:
        {
            if(!response)
            {
                SetPVarString(playerid, "YellowNumber", "");
                ShowPlayerYellowsPage(playerid);
                return 1;
            }

            new YellowPhoneNumber[64];
            GetPVarString(playerid, "YellowNumber", YellowPhoneNumber, sizeof(YellowPhoneNumber));
            
            new ownernumberID = GetNumberOwner(YellowPhoneNumber);
            if(!strcmp(YellowPhoneNumber, AccountData[playerid][pPhone], false)) 
            {
                AccountData[playerid][CurrentlyReadYellow] = false;
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Nomor tersebut sedang sibuk!");
            }

            if(!IsPlayerConnected(ownernumberID)) 
            {
                AccountData[playerid][CurrentlyReadYellow] = false;
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
            }

            OnOutcomingCall(playerid, sprintf("%s", YellowPhoneNumber));
            AccountData[playerid][CurrentlyReadYellow] = false;
        }
        case DIALOG_YELLOW_PAGE_SEND:
        {
            if(!response) 
            {
                AccountData[playerid][CurrentlyReadYellow] = false;
                return 1;
            }

            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DIALOG_YELLOW_PAGE_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Buat Iklan",
                "Error: Iklan tidak dapat kosong!\nMasukkan iklan yang ingin anda buat dibawah sini:", "Kirim", "Kembali");
            
            if(strlen(inputtext) < 1 || strlen(inputtext) > 128) return ShowPlayerDialog(playerid, DIALOG_YELLOW_PAGE_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Buat Iklan",
                "Error: Iklan tidak boleh kurang dari 1 atau lebih dari 128 huruf!\nMasukkan iklan yang ingin anda buat dibawah sini:", "Kirim", "Kembali");
            
            if(!IsValidFormatText(inputtext)) return ShowPlayerDialog(playerid, DIALOG_TWITTER_POST_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Kirim Tweet",
                "Error: Dilarang menggunakan tanda '\'' atau apapun itu!\nMasukkan Tweet yang ingin anda buat dibawah sini:", "Kirim", "Kembali");

            new frmttime[255], query[600];
            new hours, minutes, seconds, years, months, days;
            gettime(hours, minutes, seconds);
            getdate(years, months, days);
            format(frmttime, sizeof(frmttime), "%02d/%02d/%02d %02d:%02d:%02d", years, months, days, hours, minutes, seconds);

            mysql_format(dcrp_query, query, sizeof(query), "INSERT INTO `yellowpages` (`ID`, `YellowFrom`, `YellowPhone`, `YellowDate`, `YellowText`) VALUES ('1', '%s', '%s', '%s', '%s')", ReturnName(playerid), AccountData[playerid][pPhone], frmttime, inputtext);
            mysql_tquery(dcrp_query, query, "OnPlayerAdvert", "d", playerid);
            foreach(new i : Player) if (IsPlayerConnected(i) && AccountData[i][IsLoggedIn]) if (i != playerid)
            {
                if(AccountData[i][CurrentlyReadYellow]) return ShowPlayerYellowsPage(i);
            }
        }
        case DIALOG_WHATSAPP_CHAT:
        {
            new cidt = AccountData[playerid][pContact];
            if(!response) 
            {
                ShowContactList(playerid);
                AccountData[playerid][CurrentlyReadWA] = false;
            }
            else
            {
                new title[100];
                format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cidt][contactName]);
                ShowPlayerDialog(playerid, DIALOG_WHATSAPP_SEND, DIALOG_STYLE_INPUT, title, "Masukkan pesan WhatsApp yang ingin anda kirim dibawah ini:", "Kirim", "Kembali");
            }
            return 1;
        }
        case DIALOG_WHATSAPP_CHAT_EMPTY:
        {
            new cidt = AccountData[playerid][pContact];
            if(!response) 
            {
                ShowContactList(playerid);
                AccountData[playerid][CurrentlyReadWA] = false;
            }
            else
            {
                new title[100];
                format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cidt][contactName]);
                ShowPlayerDialog(playerid, DIALOG_WHATSAPP_SEND, DIALOG_STYLE_INPUT, title, "Masukkan pesan WhatsApp yang ingin anda kirim dibawah ini:", "Kirim", "Kembali");
            }
            return 1;
        }
        case DIALOG_WHATSAPP_SEND:
        {
            if(!response) 
            {
                AccountData[playerid][CurrentlyReadWA] = false;
                return 1;
            }
            
            new cidt = AccountData[playerid][pContact];
            new targetid = GetNumberOwner(ContactData[playerid][cidt][contactNumber]);
            if(targetid == INVALID_PLAYER_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon maaf nomor telepon itu sedang tidak aktif!");
            new ChatID = (AccountData[playerid][pMaskID]+AccountData[targetid][pMaskID]);

            new title[100];
            format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cidt][contactName]);

            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DIALOG_WHATSAPP_SEND, DIALOG_STYLE_INPUT, title, 
            "Error: Pesan tidak boleh kosong!\nMasukkan pesan WhatsApp yang ingin anda kirim dibawah ini:", "Kirim", "Kembali");

            if(strlen(inputtext) < 1 || strlen(inputtext) > 128) return ShowPlayerDialog(playerid, DIALOG_WHATSAPP_SEND, DIALOG_STYLE_INPUT, title, 
            "Error: Pesan tidak dapat kurang dari 1 atau lebih dari 128 huruf!\nMasukkan pesan WhatsApp yang ingin anda kirim dibawah ini:", "Kirim", "Kembali");

            if(!IsValidFormatText(inputtext)) return ShowPlayerDialog(playerid, DIALOG_TWITTER_POST_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Kirim Tweet",
            "Error: Dilarang menggunakan tanda '\'' atau apapun itu!\nMasukkan Tweet yang ingin anda buat dibawah sini:", "Kirim", "Kembali");

            if(CheckNumberBlocked(targetid, AccountData[playerid][pPhone])) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda tidak dapat mengirim pesan, nomor anda di Blokir!");

            for(new i; i < MAX_CONTACTS; i ++) {
                if(ContactData[targetid][i][contactExists]) {
                    if(!strcmp(ContactData[targetid][i][contactNumber], AccountData[playerid][pPhone], false)) {
                        ContactData[targetid][i][contactUnread] += 1;
                    }
                }
                new dbstr[151];
                mysql_format(dcrp_query, dbstr, sizeof(dbstr), "UPDATE `contacts` SET `contactUnread` = %d WHERE `contactID` = %d", ContactData[targetid][i][contactUnread], ContactData[targetid][i][contactID]);
                mysql_tquery(dcrp_query, dbstr);
            }
            new frmttime[255];
            new hours, minutes, seconds, years, months, days;
            gettime(hours, minutes, seconds);
            getdate(years, months, days);
            format(frmttime, sizeof(frmttime), "%02d-%02d-%02d %02d:%02d:%02d", years, months, days, hours, minutes, seconds);

            new query[1048];
            mysql_format(dcrp_query, query, sizeof(query), "INSERT INTO `whatsapp_chats` (`ID`, `chatTimestamp`, `chatSender`, `chatMessage`) VALUES ('%d', '%s', '%s', '%s')", ChatID, frmttime, GetMySavedContactName(targetid, AccountData[playerid][pPhone]), inputtext);
            mysql_tquery(dcrp_query, query, "OnWhatsappSent", "iiii", playerid, targetid, cidt, (AccountData[playerid][pMaskID]+AccountData[targetid][pMaskID]));
        }
        case DIALOG_TWITTER_POST_EMPTY:
        {
            if(!response)
            {
                AccountData[playerid][CurrentlyReadTwitter] = false;
                return 1;
            }

            ShowPlayerDialog(playerid, DIALOG_TWITTER_POST_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Kirim Tweet", "Masukkan Tweet yang ingin anda buat dibawah sini:", "Kirim", "Kembali");
        }
        case DIALOG_TWITTER_POST:
        {
            if(!response)
            {
                AccountData[playerid][CurrentlyReadTwitter] = false;
                return 1;
            }

            ShowPlayerDialog(playerid, DIALOG_TWITTER_POST_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Kirim Tweet", "Masukkan Tweet yang ingin anda buat dibawah sini:", "Kirim", "Kembali");
        }
        case DIALOG_TWITTER_POST_SEND:
        {
            if(!response) 
            {
                AccountData[playerid][CurrentlyReadTwitter] = false;
                return 1;
            }

            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DIALOG_TWITTER_POST_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Kirim Tweet",
                "Error: Tweet tidak dapat kosong!\nMasukkan Tweet yang ingin anda buat dibawah sini:", "Kirim", "Kembali");
            
            if(strlen(inputtext) < 1 || strlen(inputtext) > 128) return ShowPlayerDialog(playerid, DIALOG_TWITTER_POST_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Kirim Tweet",
                "Error: Tweet tidak boleh kurang dari 1 atau lebih dari 128 huruf!\nMasukkan Tweet yang ingin anda buat dibawah sini:", "Kirim", "Kembali");

            if(!IsValidFormatText(inputtext)) return ShowPlayerDialog(playerid, DIALOG_TWITTER_POST_SEND, DIALOG_STYLE_INPUT, ""PINK1"DCRP"GRAY"- Kirim Tweet",
            "Error: Dilarang menggunakan tanda '\'' atau apapun itu!\nMasukkan Tweet yang ingin anda buat dibawah sini:", "Kirim", "Kembali");

            new frmttime[255], query[522];
            new hours, minutes, seconds, years, months, days;
            gettime(hours, minutes, seconds);
            getdate(years, months, days);
            format(frmttime, sizeof(frmttime), "%02d/%02d/%02d %02d:%02d:%02d", years, months, days, hours, minutes, seconds);

            mysql_format(dcrp_query, query, sizeof(query), "INSERT INTO `tweets` (`ID`, `TwitterFrom`, `TwitterDate`, `TwitterText`) VALUES ('1', '%s', '%s', '%s')", AccountData[playerid][TwitterName], frmttime, inputtext);
            mysql_tquery(dcrp_query, query, "OnPlayerTweet", "d", playerid);
            AddTweetLog(AccountData[playerid][pName], AccountData[playerid][pUCP], inputtext);

            foreach(new i : Player) if (AccountData[i][pSpawned] && AccountData[i][CurrentlyReadTwitter]) {
                ShowPlayerTwitterPage(i);
            }
        }
        case DialogContactMenu:
        {
            if(!response)
            {
                ShowContactList(playerid);
                return 1;
            }

            new cidt = AccountData[playerid][pContact];
            new ownernumber = GetNumberOwner(ContactData[playerid][cidt][contactNumber]);
            switch(listitem)
            {
                case 0:// Panggil
                {
                    if(AccountData[playerid][phoneAirplaneMode]) 
                        return ShowTDN(playerid, NOTIFICATION_ERROR, "Smartphone sedang dalam Mode Pesawat!");
                        
                    new targetnumber[25];
                    format(targetnumber, sizeof(targetnumber), "%s", ContactData[playerid][cidt][contactNumber]);
                    if(!strcmp(AccountData[playerid][pPhone], targetnumber, false)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat menghubungi diri sendiri!");
                    if(!IsPlayerConnected(ownernumber)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon maaf nomor tersebut sedang tidak aktif!");
                    if(CheckNumberBlocked(playerid, AccountData[ownernumber][pPhone])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Nomor tersebut anda blokir, buka terlebih dahulu!");
                    if(CheckNumberBlocked(ownernumber, AccountData[playerid][pPhone])) return ShowTDN(playerid, NOTIFICATION_WARNING, "Tidak dapat melakukan panggilan ini, nomor anda diblokir!");
                    OnOutcomingCall(playerid, targetnumber);
                }
                case 1:// Whatsapp
                {
                    if(AccountData[playerid][phoneAirplaneMode]) 
                        return ShowTDN(playerid, NOTIFICATION_ERROR, "Smartphone sedang dalam Mode Pesawat!");

                    if(!IsPlayerConnected(ownernumber)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon maaf nomor tersebut tidak aktif di kota!");
                    if(CheckNumberBlocked(playerid, AccountData[ownernumber][pPhone])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Nomor tersebut anda blokir, buka terlebih dahulu!");

                    new query[525], harlem[128];
                    mysql_format(dcrp_query, query, sizeof(query), "SELECT * FROM `whatsapp_chats` WHERE `ID`=%d ORDER BY `chatTimestamp` ASC LIMIT 30", AccountData[playerid][pMaskID]+AccountData[ownernumber][pMaskID]);
                    mysql_query(dcrp_query, query);
                    if(cache_num_rows())
                    {
                        if(cache_num_rows() >= 30)
                        {
                            mysql_format(dcrp_query, harlem, sizeof(harlem), "DELETE FROM `whatsapp_chats` WHERE `ID`=%d", AccountData[playerid][pMaskID]+AccountData[ownernumber][pMaskID]);
                            mysql_tquery(dcrp_query, harlem);
                        }

                        new list[2500], date[64], issuer[24], watext[128];

                        ContactData[playerid][cidt][contactUnread] = 0;
                        mysql_format(dcrp_query, query, sizeof(query), "UPDATE `contacts` SET `contactUnread`= 0 WHERE `contactID`=%d", ContactData[playerid][cidt][contactID]);
                        mysql_tquery(dcrp_query, query);

                        format(list, sizeof(list), "Tanggal\tPengirim\tPesan\n");
                        for(new i; i < cache_num_rows(); ++i)
                        {
                            cache_get_value_name(i, "chatTimestamp", date);
                            cache_get_value_name(i, "chatSender", issuer);
                            cache_get_value_name(i, "chatMessage", watext);
                        
                            format(list, sizeof(list), "%s%s\t%s\t%s\n", list, date, issuer, watext);
                        }
                        new title[100];
                        format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cidt][contactName]);
                        ShowPlayerDialog(playerid, DIALOG_WHATSAPP_CHAT, DIALOG_STYLE_TABLIST_HEADERS, title, list, "Kirim", "Kembali");
                    }
                    else 
                    {
                        new list[208], title[102];
                        format(list, sizeof(list), "Tanggal\tPengirim\tPesan\n");
                        format(list, sizeof(list), "%sPesan dan panggilan terenkripsi secara end-to-end.", list);
                        format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cidt][contactName]);
                        ShowPlayerDialog(playerid, DIALOG_WHATSAPP_CHAT_EMPTY, DIALOG_STYLE_TABLIST_HEADERS, title, list, "Kirim", "Kembali");
                    }
                    AccountData[playerid][CurrentlyReadWA] = true;
                }
                case 2:// Shareloc
                {
                    if(AccountData[playerid][phoneAirplaneMode]) 
                        return ShowTDN(playerid, NOTIFICATION_ERROR, "Smartphone sedang dalam Mode Pesawat!");

                    if(!IsPlayerConnected(ownernumber)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon maaf nomor tersebut tidak aktif di kota!");
                    if(CheckNumberBlocked(playerid, AccountData[ownernumber][pPhone])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Nomor tersebut anda blokir, buka terlebih dahulu!");
                    if(CheckNumberBlocked(ownernumber, AccountData[playerid][pPhone])) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda tidak dapat mengirim shareloc, nomor anda di Blokir!");

                    static Float:x, Float:y, Float:z;
                    GetPlayerPos(playerid, x, y, z);

                    if (SharelocSender[ownernumber] != INVALID_STREAMER_ID) 
                        DestroyDynamicMapIcon(SharelocSender[ownernumber]);

                    SharelocSender[ownernumber] = CreateDynamicMapIcon(x, y, z, 0, COLOR_CLIENT, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), ownernumber, 5000.0, MAPICON_GLOBAL, -1, 0);
                    SharelocTimer[ownernumber] = 120;
                    ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil mengirim lokasi kepada %s", ReturnName(ownernumber)));
                    Syntax(ownernumber, "%s mengirimkan shareloc kepada anda", GetMySavedContactName(ownernumber, AccountData[playerid][pPhone]));
                }
                case 3: // Edit Nama Kontak
                {
                    ShowPlayerDialog(playerid, DIALOG_EDIT_CONTACTNAME, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Edit Nama Kontak", 
                    sprintf("Mohon masukkan nama baru untuk diterapkan pada kontak %s", ContactData[playerid][cidt][contactName]), "Save", "Batal");
                }
                case 4: // Edit Number
                {
                    ShowPlayerDialog(playerid, DIALOG_EDIT_CONTACTNUMBER, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Edit Nomor Kontak",
                    sprintf("Mohon masukkan nomor baru untuk diterapkan pada kontak %s", ContactData[playerid][cidt][contactName]), "Save", "Batal");
                }
                case 5: // Blokir Kontak
                {
                    switch(ContactData[playerid][cidt][contactBlocked])
                    {
                        case 0:
                        {
                            ContactData[playerid][cidt][contactBlocked] = 1;
                            mysql_query(dcrp_query, sprintf("UPDATE `contacts` SET `contactBlocked` = %d WHERE `ID` = '%d' AND `contactID` = '%d'", ContactData[playerid][cidt][contactBlocked], AccountData[playerid][pID], ContactData[playerid][cidt][contactID]), false);
                            ShowContactList(playerid);
                            
                            Info(playerid, "Anda memblokir kontak %s (%s)", ContactData[playerid][cidt][contactName], ContactData[playerid][cidt][contactNumber]);
                        }
                        case 1:
                        {
                            ContactData[playerid][cidt][contactBlocked] = 0;
                            mysql_query(dcrp_query, sprintf("UPDATE `contacts` SET `contactBlocked` = %d WHERE `ID` = '%d' AND `contactID` = '%d'", ContactData[playerid][cidt][contactBlocked], AccountData[playerid][pID], ContactData[playerid][cidt][contactID]), false);
                            ShowContactList(playerid);
                            
                            Info(playerid, "Anda membuka memblokir kontak %s (%s)", ContactData[playerid][cidt][contactName], ContactData[playerid][cidt][contactNumber]);
                        }
                    }
                }
                case 6:// Hapus Kontak
                {
                    ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Anda telah menghapus %s dari daftar kontak!", ContactData[playerid][cidt][contactName]));
                    
                    static frmtx[188];
                    mysql_format(dcrp_query, frmtx, sizeof(frmtx), "DELETE FROM `contacts` WHERE `ID` = '%d' AND `contactID` = '%d'", AccountData[playerid][pID], ContactData[playerid][cidt][contactID]);
                    mysql_query(dcrp_query, frmtx);
                    
                    ContactData[playerid][cidt][contactExists] = false;
                    ContactData[playerid][cidt][contactNumber] = 0;
                    ContactData[playerid][cidt][contactID] = 0;
                    PlayerContactPage[playerid] = 0;
                    
                    for (new i = 0; i < MAX_CONTACTS; i ++) {
                        ContactData[playerid][i][contactExists] = false;
                    }
                    
                    static cQuery[200];
                    mysql_format(dcrp_query, cQuery, sizeof(cQuery), "SELECT * FROM `contacts` WHERE `ID`=%d AND `contactOwner`=%d", AccountData[playerid][pID], AccountData[playerid][pID]);
	                mysql_tquery(dcrp_query, cQuery, "LoadPlayerContact", "d", playerid);
                    // ShowContactList(playerid);
                }
            }
        }
        case DIALOG_EDIT_CONTACTNUMBER:
        {
            if(response)
            {
                if(isnull(inputtext)) return ShowPlayerDialog(playerid, DIALOG_EDIT_CONTACTNUMBER, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Edit Nomor Kontak", 
                sprintf("Error: Tidak dapat diisi kosong!\nMohon masukkan nomor baru untuk diterapkan pada kontak %s", ContactData[playerid][AccountData[playerid][pContact]][contactName]), "Save", "Batal");

                if(!IsNumeric(inputtext)) return ShowPlayerDialog(playerid, DIALOG_EDIT_CONTACTNUMBER, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Edit Nomor Kontak", 
                sprintf("Error: Hanya dapat diisi angka!\nMohon masukkan nomor baru untuk diterapkan pada kontak %s", ContactData[playerid][AccountData[playerid][pContact]][contactName]), "Save", "Batal");

                CallLocalFunction("OnContactEditNumber", "dds", playerid, AccountData[playerid][pContact], inputtext);
            }
            else ShowContactList(playerid);
        }
        case DIALOG_EDIT_CONTACTNAME:
        {
            if(response)
            {
                if(isnull(inputtext)) return ShowPlayerDialog(playerid, DIALOG_EDIT_CONTACTNAME, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Edit Nama Kontak", 
                sprintf("Error: Tidak dapat diisi kosong!\nMohon masukkan nama baru untuk diterapkan pada kontak %s", ContactData[playerid][AccountData[playerid][pContact]][contactName]), "Save", "Batal");

                if(IsNumeric(inputtext)) return ShowPlayerDialog(playerid, DIALOG_EDIT_CONTACTNAME, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Edit Nama Kontak", 
                sprintf("Error: Tidak dapat memasukkan angka semua!\nMohon masukkan nama baru untuk diterapkan pada kontak %s", ContactData[playerid][AccountData[playerid][pContact]][contactName]), "Save", "Batal");

                if(strlen(inputtext) < 1 || strlen(inputtext) > 32) return ShowPlayerDialog(playerid, DIALOG_EDIT_CONTACTNAME, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Edit Nama Kontak", 
                sprintf("Error: Nama tidak dapat kurang dari 1 huruf atau lebih dari 32!\nMohon masukkan nama baru untuk diterapkan pada kontak %s", ContactData[playerid][AccountData[playerid][pContact]][contactName]), "Save", "Batal");

                CallLocalFunction("OnContactEditName", "dds", playerid, AccountData[playerid][pContact], inputtext);
            }
            else ShowContactList(playerid);
        }
        case DialogTransfer:
        {
            if(!response) return false;
            
            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DialogTransfer, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Transfer", 
            "Error: Harus diisi tidak dapat kosong!\nMohon masukkan nomor rekening yang ingin anda transfer:", "Submit", "Batal");

            if(!IsNumeric(inputtext)) return ShowPlayerDialog(playerid, DialogTransfer, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Transfer", 
            "Error: Hanya dapat diisi angka!\nMohon masukkan nomor rekening yang ingin anda transfer:", "Submit", "Batal");

            if(strval(inputtext) == AccountData[playerid][pBankRek]) return ShowPlayerDialog(playerid, DialogTransfer, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Transfer", 
            "Error: Tidak dapat mengirim ke rekening diri sendiri!\nMohon masukkan nomor rekening yang ingin anda transfer:", "Submit", "Batal");

            new query[128];
            mysql_format(dcrp_query, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `Char_BankRek`=%d", strval(inputtext));
            mysql_tquery(dcrp_query, query, "SearchBankRek", "dd", playerid, strval(inputtext));
        }
        case DialogTransfer1:
        {
            if(!response) return 1;

            new targetid = GetRekeningOwner(AccountData[playerid][pTransferRek]);

            if(isnull(inputtext)) return ShowPlayerDialog(playerid, DialogTransfer1, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Transfer",
            "Error: Harus diisi tidak dapat kosong!\nMohon masukkan jumlah nominal yang ingin anda kirim ke rekening tersebut:", "Kirim", "Batal"); 
        
            if(!IsNumeric(inputtext)) return ShowPlayerDialog(playerid, DialogTransfer1, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Transfer",
            "Error: Hanya dapat diisi angka!\nMohon masukkan jumlah nominal yang ingin anda kirim ke rekening tersebut:", "Kirim", "Batal");
        
            if(strval(inputtext) < 1 || strval(inputtext) > AccountData[playerid][pBankMoney]) return ShowPlayerDialog(playerid, DialogTransfer1, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Transfer",
            "Error: Jumlah tidak vaid!\nMohon masukkan jumlah nominal yang ingin anda kirim ke rekening tersebut:", "Kirim", "Batal");
        
            if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemilik rekening tersebut tidak terkoneksi ke server!");
            AccountData[targetid][pBankMoney] += strval(inputtext);
            AccountData[playerid][pBankMoney] -= strval(inputtext);
            SendClientMessageEx(targetid, -1, "[i] Anda mendapatkan transfer dari // Nama Rek: %s // Jumlah Transfer: "GREEN"%s", AccountData[playerid][pName], FormatMoney(strval(inputtext)));
            ShowTDN(playerid, NOTIFICATION_SUKSES, sprintf("Berhasil mengirim %s ke rekening %d", FormatMoney(strval(inputtext)), AccountData[playerid][pTransferRek]));
            
            foreach(new i : Player) if (AccountData[i][pAdmin] >= 1 && IsPlayerConnected(i))
			{
				SendClientMessageEx(i, -1, ""YELLOW"[Transfer Logs]: %s(%d) Mentransfer uang sebesar %s kepada %s(%d)", AccountData[playerid][pName], playerid, FormatMoney(strval(inputtext)), AccountData[targetid][pName], targetid);
			}
            new frmxt[255];
			format(frmxt, sizeof(frmxt), "Menstransfer uang kepada rekening %d sebesar $%d", AccountData[playerid][pTransferRek], strval(inputtext));
			AddPMoneyLog(AccountData[playerid][pName], AccountData[playerid][pUCP], frmxt, strval(inputtext));
            AccountData[playerid][pTransferRek] = 0;
        }
        case DialogSpotify:
        {
            if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda membatalkan musik");
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        SendRPMeAboveHead(playerid, "Mematikan musik di Spotifynya", X11_PLUM1);
                        StopStream(playerid);
                    }
                    case 1:
                    {
                        static jskc[512];
                        format(jskc, sizeof(jskc), ""VERONA_ARWIN"Spotify Music - Cerahi Hidupmu Secerah Matahari Di Pagi Hari\n\n"VERONA_ARWIN"Kami sarankan anda untuk upload file mp3 ke discord terlebih dahulu.\n"RED_E"Note: Fitur ini tidak support link Youtube secara langsung!\n\n"YELLOW"(Apabila file mp3 telah di upload ke discord, silahkan copy linknya dan paste dibawah ini):");
                        ShowPlayerDialog(playerid, DialogSpotify1, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Spotify", jskc, "Input", "Cancel");
                    }
                }
            }
        }
        case DialogSpotify1:
        {
            if(response == 1)
            {
                if(isnull(inputtext))
                {
                    ShowTDN(playerid, NOTIFICATION_WARNING, "Anda belum memasukan URL musik!");
                    return 1;
                }
                if(strlen(inputtext))
                {
                    PlayStream(playerid, inputtext, 0.0, 0.0, 0.0, 1, 0);
                }
            }
        }
    }
    return 1;
}


ShowPlayerTwitterPage(playerid)
{
    mysql_query(dcrp_query, "SELECT * FROM `tweets` WHERE `ID`=1 ORDER BY `TwitterDate` ASC LIMIT 30");
    new rows = cache_num_rows(), list[4500], tempTweetFrom[24], tempTweetDate[64], tempTweetText[128];
    if(rows)
    {
        if(rows >= 30)
        {
            mysql_tquery(dcrp_query, "DELETE FROM `tweets` WHERE `ID`=1");
        }

        format(list, sizeof(list), "Username\tTanggal\tPostingan\n");
        for(new i; i < rows; ++i)
        {
            cache_get_value_name(i, "TwitterFrom", tempTweetFrom);
            cache_get_value_name(i, "TwitterDate", tempTweetDate);
            cache_get_value_name(i, "TwitterText", tempTweetText);

            format(list, sizeof(list), "%s"VTWITTER"@%s\t"GRAY"%s\t"WHITE"%s\n", list, tempTweetFrom, tempTweetDate, tempTweetText);
        }
        ShowPlayerDialog(playerid, DIALOG_TWITTER_POST, DIALOG_STYLE_TABLIST_HEADERS, ""PINK1"DCRP"WHITE"- Tweets", list, "Tweet", "Kembali");
    }
    else 
    {
        format(list, sizeof(list), "Username\tTanggal\tPostingan\n");
        format(list, sizeof(list), "%sJadilah orang pertama yang membagikan Tweet", list);
        ShowPlayerDialog(playerid, DIALOG_TWITTER_POST_EMPTY, DIALOG_STYLE_TABLIST_HEADERS, ""PINK1"DCRP"WHITE"- Tweets", list, "Tweet", "Kembali");
    }
	return 1;
}

ShowPlayerYellowsPage(playerid)
{
    AccountData[playerid][CurrentlyReadYellow] = true;
    mysql_query(dcrp_query, "SELECT * FROM `yellowpages` WHERE `ID`=1 ORDER BY `YellowDate` ASC LIMIT 30");
    new rowcount = cache_num_rows(), list[4500], tempYellowFrom[24], tempYellowDate[64], tempYellowText[128], tempYellowPhone[24];
    if(rowcount)
    {
        if(rowcount >= 30)
        {
            mysql_tquery(dcrp_query, "DELETE FROM `yellowpages` WHERE `ID`=1");
        }

        format(list, sizeof(list), "Nama\tTanggal\tIklan\n");
        for(new i; i < rowcount; ++i)
        {
            cache_get_value_name(i, "YellowFrom", tempYellowFrom);
            cache_get_value_name(i, "YellowPhone", tempYellowPhone);
            cache_get_value_name(i, "YellowDate", tempYellowDate);
            cache_get_value_name(i, "YellowText", tempYellowText);
            
            if(strlen(tempYellowText) > 24) {
                format(list, sizeof(list), "%s"YELLOW"%s - %s\t"GRAY"%s\t"WHITE"%.24s...\n", list, tempYellowFrom, tempYellowPhone, tempYellowDate, tempYellowText);
            } else format(list, sizeof(list), "%s"YELLOW"%s - %s\t"GRAY"%s\t"WHITE"%s\n", list, tempYellowFrom, tempYellowPhone, tempYellowDate, tempYellowText);
        }
        ShowPlayerDialog(playerid, DIALOG_YELLOW_PAGE, DIALOG_STYLE_TABLIST_HEADERS, ""PINK1"DCRP"WHITE"- Yellow Pages", list, "Iklan", "Kembali");
    }
    else
    {
        format(list, sizeof(list), "Nama\tTanggal\tIklan\n");
        format(list, sizeof(list), "%sJadilah orang pertama yang membuat iklan!", list);
        ShowPlayerDialog(playerid, DIALOG_YELLOW_PAGE_EMPTY, DIALOG_STYLE_TABLIST_HEADERS, ""PINK1"DCRP"WHITE"- Yellow Pages", list, "Iklan", "Kembali");
    }
    return 1;
}

forward SearchBankRek(playerid, norekening);
public SearchBankRek(playerid, norekening)
{
    if(!cache_num_rows())
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Nomor rekening tidak terdaftar!");
        return 1;
    }
    else 
    {
        new ownerRek = GetRekeningOwner(norekening);
        if(!IsPlayerConnected(ownerRek)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
        AccountData[playerid][pTransferRek] = norekening;
        ShowPlayerDialog(playerid, DialogTransfer1, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Transfer",
        "Mohon masukkan jumlah nominal yang ingin anda kirim ke rekening tersebut:", "Kirim", "Batal");
    }
    return 1;
}

Dialog:SettingPhone(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0: //ttg ponsel
            {
                static minsty[200];
                format(minsty, sizeof(minsty), "Aevhone X25 Milik: %s\
                \nNomor Telepon: %s\
                \nNama Series Model: X25\
                \nNomor Serial: VR81AXS23S33\nIMEI (slot 1): 7182991211\nIMEI (slot 2): 9928192882", ReturnName(playerid), AccountData[playerid][pPhone]);
                ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""PINK1"DCRP"WHITE"- Tentang Ponsel", minsty, "Tutup", "");
            }
            case 1: // Ubah Nada Dering
            {
                Dialog_Show(playerid, PhoneRingtone, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Ubah Nada Dering",
                "Mohon masukkan link mp3 yang sudah anda upload dimanapun itu untuk dijadikan sebagai nada dering saat ada panggilan masuk\
                \nNOTE: Tidak dapat memasukkan link langsung dari YouTube!", "Submit", "Batal");
            }
            case 2: // Hapus Nada Dering
            {
                AccountData[playerid][phoneCallRingtone][0] = EOS;
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil menghapus nada dering!");
            }
            case 3: // Mode Pesawat
            {
                switch(AccountData[playerid][phoneAirplaneMode])
                {
                    case false:
                    {
                        AccountData[playerid][phoneAirplaneMode] = true;
                        ShowTDN(playerid, NOTIFICATION_INFO, "Anda mengaktifkan Mode Pesawat");
                    }
                    case true:
                    {
                        AccountData[playerid][phoneAirplaneMode] = false;
                        ShowTDN(playerid, NOTIFICATION_INFO, "Anda menonaktifkan Mode Pesawat");
                    }
                }
            }
        }
    }
    else ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    return 1;
}

Dialog:PhoneRingtone(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        return Dialog_Show(playerid, SettingPhone, DIALOG_STYLE_LIST, ""PINK1"DCRP"WHITE"- Pengaturan",
        "Tentang Ponsel\
        \nUbah Nada Dering Telepon", "Pilih", "Batal");
    }

    if(isnull(inputtext)) return Dialog_Show(playerid, PhoneRingtone, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Ubah Nada Dering",
    "Error: Tidak dapat diisi kosong!\nMohon masukkan link mp3 yang sudah anda upload dimanapun itu untuk dijadikan sebagai nada dering saat ada panggilan masuk\
    \nNOTE: Tidak dapat memasukkan link langsung dari YouTube!", "Submit", "Batal");
    
    if(IsNumeric(inputtext)) return Dialog_Show(playerid, PhoneRingtone, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Ubah Nada Dering",
    "Error: Tidak dapat diisi angka!\nMohon masukkan link mp3 yang sudah anda upload dimanapun itu untuk dijadikan sebagai nada dering saat ada panggilan masuk\
    \nNOTE: Tidak dapat memasukkan link langsung dari YouTube!", "Submit", "Batal");

    format(AccountData[playerid][phoneCallRingtone], 128, inputtext);
    ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil mengubah nada dering panggilan!");
    return 1;
}

Dialog:GpsMenu(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0: //Lokasi GPS
            {
                GPS::Display(playerid);
            }
            case 1: // Emergency Signal
            {
                if(AccountData[playerid][pFaction] != FACTION_EMS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota Mitra EMS DCRP!");
                if(!AccountData[playerid][pDutyEms]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak sedang duty EMS!");

                new list[525], count = 0;
                format(list, sizeof(list), "#No\tKorban\tLokasi\n");
                foreach(new i : Player) if (AccountData[i][pSpawned] && SignalExists[i])
                {
                    format(list, sizeof(list), "%s%d\t%s(%d)\t%s\n", list, count, ReturnName(i), i, GetLocation(SignalPos[i][0], SignalPos[i][1], SignalPos[i][2]));
                    ListSignal[playerid][count ++] = i;
                }

                if(count == 0)
                {
                    return Dialog_Show(playerid, ShowOnly, DIALOG_STYLE_MSGBOX, ""PINK1"DCRP"WHITE"- Emergency Signal",
                    "Tidak ada seseorang manapun yang mengirim Emergency Signal!", "Tutup", "");
                }

                Dialog_Show(playerid, EmergencySignal, DIALOG_STYLE_TABLIST_HEADERS, ""PINK1"DCRP"WHITE"- Emergency Signal", list, "Pilih", "Batal");
            }
        }
    }
    return 1;
}

Dialog:EmergencySignal(playerid, response, listitem, inputtext[])
{
    if(response)
    {   
        if(AccountData[playerid][pFaction] != FACTION_EMS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota Mitra EMS DCRP!");
        if(!AccountData[playerid][pDutyEms]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak sedang duty EMS!");

        new id = ListSignal[playerid][listitem];
        if(!IsPlayerConnected(id)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
        if(!SignalExists[id]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Emergency signal sudah tidak ada/dihandle anggota lain!"); 
        // if(!AccountData[id][pInjured]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Orang yang mengirim signal sudah terbangun dari pingsannya!");
        
        SetPlayerRaceCheckpoint(playerid, 1, SignalPos[id][0], SignalPos[id][1], SignalPos[id][2], 0.0, 0.0, 0.0, 4.0);
        Info(playerid, "Anda telah menerima signal emergency di daerah "YELLOW"%s", GetLocation(SignalPos[id][0], SignalPos[id][1], SignalPos[id][2]));
        Info(id, "Anggota Mitra EMS telah merespon signal emergency yang anda kirim. Harap tunggu di lokasi hingga petugas datang!");
        static str[218];
        format(str, sizeof(str), ""RED"EMS %s | telah menerima Emergency Signal di daerah "YELLOW"%s", AccountData[playerid][pName], GetLocation(SignalPos[id][0], SignalPos[id][1], SignalPos[id][2]));
        SendClientMessageToAll(COLOR_RED, str);
        SignalExists[id] = false;
        SignalPos[id][0] = SignalPos[id][1] = SignalPos[id][2] = 0.0;
        pMapCP[playerid] = true;
    }
    else ShowTDN(playerid, NOTIFICATION_ERROR, "Anda telah membatalkan pilihan!");
    return 1;
}

Dialog:CALLCENTER_POLISI(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    new Float:X, Float:Y, Float:Z;
    GetPlayerPos(playerid, X, Y, Z);

    if(isnull(inputtext)) return Dialog_Show(playerid, CALLCENTER_POLISI, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Panggilan Darurat Polisi",
    "Error: Tidak dapat diisi kosong!\nMasukkan kendala anda yang ingin dilaporkan kepada pihak kepolisian dibawah ini\
    \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke kepolisian:", "Kirim", "Batal");

    if(IsNumeric(inputtext)) return Dialog_Show(playerid, CALLCENTER_POLISI, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Panggilan Darurat Polisi",
    "Error: Tidak dapat diisi angka!\nMasukkan kendala anda yang ingin dilaporkan kepada pihak kepolisian dibawah ini\
    \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke kepolisian:", "Kirim", "Batal");
    
    if(strlen(inputtext) > 128) return Dialog_Show(playerid, CALLCENTER_POLISI, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Panggilan Darurat Polisi",
    "Error: Tidak dapat lebih dari 128 characters!\nMasukkan kendala anda yang ingin dilaporkan kepada pihak kepolisian dibawah ini\
    \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke kepolisian:", "Kirim", "Batal");
    
    if(AccountData[playerid][pHotlineTime] >= gettime()){
		ShowTDN(playerid, NOTIFICATION_WARNING, sprintf("Mohon menunggu %d detik untuk mengirim hotline ke factions kembali", AccountData[playerid][pHotlineTime] - gettime()));
		return 1;
	}
	foreach(new i : Player) {
		if(AccountData[i][pFaction] == 1 && AccountData[i][pDutyPD]) {
			SendClientMessageEx(i, -1, ""GRAY"[Pesan Darurat] "WHITE"Laporan Dari %s (%d) // Lokasi: %s // No Telpon: %s", GetRPName(playerid), playerid, GetLocation(X, Y, Z), AccountData[playerid][pPhone]);
			SendClientMessageEx(i, -1, ""WHITE"-> %s", inputtext);
		}
	}
	AccountData[playerid][pHotlineTime] = gettime() + 180;
	SendClientMessageEx(playerid, -1, ""GRAY"[Pesan Darurat] "WHITE"Laporan Dari %s (%d) // Lokasi: %s // No Telpon: %s", GetRPName(playerid), playerid, GetLocation(X, Y, Z), AccountData[playerid][pPhone]);
	SendClientMessageEx(playerid, -1, ""WHITE"-> %s", inputtext);
	ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil mengirim pesan darurat kepolisian!");
    return 1;
}

Dialog:CALLCENTER_EMS(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    new Float:X, Float:Y, Float:Z;
    GetPlayerPos(playerid, X, Y, Z);

    if(isnull(inputtext)) return Dialog_Show(playerid, CALLCENTER_EMS, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Panggilan Darurat Rumah Sakit",
    "Error: Tidak dapat diisi kosong!\nMasukkan kendala anda yang ingin dilaporkan kepada pihak Rumah Sakit dibawah ini\
    \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke Rumah Sakit:", "Kirim", "Batal");

    if(IsNumeric(inputtext)) return Dialog_Show(playerid, CALLCENTER_EMS, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Panggilan Darurat Rumah Sakit",
    "Error: Tidak dapat diisi angka!\nMasukkan kendala anda yang ingin dilaporkan kepada pihak Rumah Sakit dibawah ini\
    \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke Rumah Sakit:", "Kirim", "Batal");
    
    if(strlen(inputtext) > 128) return Dialog_Show(playerid, CALLCENTER_EMS, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Panggilan Darurat Rumah Sakit",
    "Error: Tidak dapat lebih dari 128 characters!\nMasukkan kendala anda yang ingin dilaporkan kepada pihak Rumah Sakit dibawah ini\
    \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke Rumah Sakit:", "Kirim", "Batal");
    
    if(AccountData[playerid][pHotlineTime] >= gettime())
	{
		ShowTDN(playerid, NOTIFICATION_WARNING, sprintf("Mohon menunggu %d detik untuk mengirim hotline factions kembali!", AccountData[playerid][pHotlineTime] - gettime()));
		return 1;
	}

	foreach(new i : Player) {
		if(AccountData[i][pFaction] == 3 && AccountData[i][pDutyEms]) {
			SendClientMessageEx(i, -1, ""C_DOKTER"[EMS CALL CENTER]"WHITE" Laporan Dari %s (%d) // Lokasi: %s // No Telpon: %s", GetRPName(playerid), playerid, GetLocation(X, Y, Z), AccountData[playerid][pPhone]);
			SendClientMessageEx(i, -1, ""WHITE"-> %s", inputtext);
		}
	}
	AccountData[playerid][pHotlineTime] = gettime() + 180;
	SendClientMessageEx(playerid, -1, ""C_DOKTER"[EMS CALL CENTER]"WHITE" Laporan Dari %s (%d) // Lokasi: %s // No Telpon: %s", GetRPName(playerid), playerid, GetLocation(X, Y, Z), AccountData[playerid][pPhone]);
	SendClientMessageEx(playerid, -1, ""WHITE"-> %s", inputtext);
	ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil mengirim pesan darurat Rumah Sakit!");
    return 1;
}

Dialog:CALLCENTER_PEMDA(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    new Float:X, Float:Y, Float:Z;
    GetPlayerPos(playerid, X, Y, Z);

    if(isnull(inputtext)) return Dialog_Show(playerid, CALLCENTER_PEMDA, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Call Center Pemerintah",
    "Error: Tidak dapat diisi kosong!\nMasukkan kendala anda yang ingin dilaporkan kepada pihak Pemerintah dibawah ini\
    \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke Pemerintah:", "Kirim", "Batal");

    if(IsNumeric(inputtext)) return Dialog_Show(playerid, CALLCENTER_PEMDA, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Call Center Pemerintah",
    "Error: Tidak dapat diisi angka!\nMasukkan kendala anda yang ingin dilaporkan kepada pihak Pemerintah dibawah ini\
    \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke Pemerintah:", "Kirim", "Batal");
    
    if(strlen(inputtext) > 128) return Dialog_Show(playerid, CALLCENTER_PEMDA, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Call Center Pemerintah",
    "Error: Tidak dapat lebih dari 128 characters!\nMasukkan kendala anda yang ingin dilaporkan kepada pihak Pemerintah dibawah ini\
    \nJelaskan detail dan kendala yang sedang kamu alami dan ingin lapor ke Pemerintah:", "Kirim", "Batal");
    
    if(AccountData[playerid][pHotlineTime] >= gettime())
	{
		ShowTDN(playerid, NOTIFICATION_WARNING, sprintf("Mohon menunggu %d detik untuk mengirim hotline factions kembali!", AccountData[playerid][pHotlineTime] - gettime()));
		return 1;
	}

	foreach(new i : Player) {
		if(AccountData[i][pFaction] == FACTION_PEMERINTAH && AccountData[i][pDutyPemerintah]) {
			SendClientMessageEx(i, -1, ""SKYBLUE"[PEMDA CALL CENTER]"WHITE" Laporan Dari %s (%d) // Lokasi: %s // No Telpon: %s", GetRPName(playerid), playerid, GetLocation(X, Y, Z), AccountData[playerid][pPhone]);
			SendClientMessageEx(i, -1, ""WHITE"-> %s", inputtext);
		}
	}
	AccountData[playerid][pHotlineTime] = gettime() + 180;
	SendClientMessageEx(playerid, -1, ""SKYBLUE"[PEMDA CALL CENTER]"WHITE" Laporan Dari %s (%d) // Lokasi: %s // No Telpon: %s", GetRPName(playerid), playerid, GetLocation(X, Y, Z), AccountData[playerid][pPhone]);
	SendClientMessageEx(playerid, -1, ""WHITE"-> %s", inputtext);
	ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil mengirim pesan ke Call Center Pemerintah!");
    return 1;
}

// ------------------------------------------------------------------------------- //
ptask CallTimer_Update[1000](playerid)
{
    if(AccountData[playerid][phoneDurringConversation] && AccountData[playerid][phoneCallingWithPlayerID] != INVALID_PLAYER_ID)
    {
        new times[3];
        GetElapsedTime(AccountData[playerid][phoneCallingTime]++, times[0], times[1], times[2]);
        PlayerTextDrawSetString(playerid, JadenDCRPTelponan[playerid][37], sprintf("%02d:%02d:%02d", times[0], times[1], times[2]));
        PlayerTextDrawShow(playerid, JadenDCRPTelponan[playerid][37]);
        if(!AccountData[playerid][phoneShown]){
            PlayerTextDrawHide(playerid, JadenDCRPTelponan[playerid][37]);
        }
    }
    return 1;
}

ptask SharelocRemove[1000](playerid)
{
    if(SharelocTimer[playerid] > 0)
    {
        SharelocTimer[playerid] --;
        if(!SharelocTimer[playerid])
        {
            if(SharelocSender[playerid] != INVALID_STREAMER_ID)
                DestroyDynamicMapIcon(SharelocSender[playerid]), SharelocSender[playerid] = INVALID_STREAMER_ID;
            
            SharelocTimer[playerid] = 0;
        }
    }
    return 1;
}

ptask PhoneClockTD[1000](playerid)
{
    if(AccountData[playerid][phoneShown])
    {
        static const MonthName[12][] =
        {
            "Januari", "Februar", "Maret", "April", "Mei", "Juni",
            "Juli", "Agustus", "September", "Oktober", "November", "Desember"
        };

        new datestring[32], timestring[16];
        new hours, minutes, seconds, days, months, years;
        
        getdate(years, months, days);
        gettime(hours, minutes, seconds);

        // Format tanggal
        format(datestring, sizeof datestring, "%02d_%s_%02d", days, MonthName[months - 1], years % 100);

        // Format waktu
        format(timestring, sizeof timestring, "%02d:%02d", hours, minutes);

        // Update TextDraw
        PlayerTextDrawSetString(playerid, JadenDcrpPhone[playerid][34], datestring);
        PlayerTextDrawSetString(playerid, JadenDcrpPhone[playerid][33], timestring);
        PlayerTextDrawSetString(playerid, JadenDCRPBankHP[playerid][27], timestring);
        PlayerTextDrawSetString(playerid, JadenDCRPSpotify[playerid][27], timestring);
        PlayerTextDrawSetString(playerid, JadenDCRPXLogin[playerid][27], timestring);
        PlayerTextDrawSetString(playerid, JadenDCRPXHome[playerid][27], timestring);
        PlayerTextDrawSetString(playerid, JadenDCRPTelponan[playerid][27], timestring);
    }
    return 1;
}

// DialogPages:ContactListDialog(playerid, response, listitem, inputtext[])
// {
//     if(response)
//     {
//         if(listitem == INVALID_LISTITEM) return 0;

//         new index =  ListedContacts[playerid][listitem];

//         AccountData[playerid][pContact] = index;

//         ShowPlayerDialog(playerid, DialogContactMenu, DIALOG_STYLE_LIST, sprintf(""PINK1"DCRP"WHITE" - %s", ContactData[playerid][AccountData[playerid][pContact]][contactName]), 
//         "Panggil\
//         \n"GRAY"Whatsapp\
//         \nShareloc\
//         \n"GRAY"Edit Nama Kontak\
//         \nEdit Nomor Kontak\
//         \n"GRAY"Blokir/Buka Blokir Kontak\
//         \nHapus Kontak", "Pilih", "Batal");
//     }
//     else
//     {
//         ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan");
//     }

//     for(new i = 0; i < MAX_CONTACTS; i++) {
//         ListedContacts[playerid][i] = -1;
//     }
//     return 1;
// }