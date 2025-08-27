#include <YSI\y_hooks>

new PlayerText: INVINFO[MAX_PLAYERS][37];
new PlayerText: NAMETD[MAX_PLAYERS][16];
new PlayerText: INDEXTD[MAX_PLAYERS][16];
new PlayerText: MODELTD[MAX_PLAYERS][16];
new PlayerText: AMOUNTTD[MAX_PLAYERS][16];
new PlayerText: GARISBAWAH[MAX_PLAYERS][16];

CreateInventoryTextdraw(playerid)
{
    INVINFO[playerid][0] = CreatePlayerTextDraw(playerid, 270.000, 628.000, "Gambar teks baru");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][0], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][0], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][0], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][0], 1);

    INVINFO[playerid][1] = CreatePlayerTextDraw(playerid, 314.000, 296.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][1], 47.000, 18.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][1], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][1], 502315876);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][1], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, INVINFO[playerid][1], 1);

    INVINFO[playerid][2] = CreatePlayerTextDraw(playerid, 115.000, 129.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][2], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][2], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][2], 502315876);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][2], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][2], 1);

    INVINFO[playerid][3] = CreatePlayerTextDraw(playerid, 160.000, 129.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][3], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][3], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][3], 502315876);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][3], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][3], 1);

    INVINFO[playerid][4] = CreatePlayerTextDraw(playerid, 205.000, 129.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][4], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][4], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][4], 502315876);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][4], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][4], 1);

    INVINFO[playerid][5] = CreatePlayerTextDraw(playerid, 250.000, 129.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][5], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][5], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][5], 502315876);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][5], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][5], 1);

    INVINFO[playerid][6] = CreatePlayerTextDraw(playerid, 117.000, 129.000, "1");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][6], 0.070, 0.597);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][6], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][6], 502316031);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][6], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][6], 1);

    INVINFO[playerid][7] = CreatePlayerTextDraw(playerid, 162.000, 129.000, "2");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][7], 0.070, 0.597);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][7], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][7], 502316031);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][7], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][7], 1);

    INVINFO[playerid][8] = CreatePlayerTextDraw(playerid, 207.000, 129.000, "3");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][8], 0.070, 0.597);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][8], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][8], 502316031);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][8], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][8], 2);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][8], 1);

    INVINFO[playerid][9] = CreatePlayerTextDraw(playerid, 252.000, 129.000, "4");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][9], 0.070, 0.597);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][9], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][9], 502316031);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][9], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][9], 2);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][9], 1);

    INVINFO[playerid][10] = CreatePlayerTextDraw(playerid, 314.000, 194.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][10], 47.000, 43.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][10], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][10], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, INVINFO[playerid][10], 1);

    INVINFO[playerid][11] = CreatePlayerTextDraw(playerid, 305.000, 156.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][11], 66.000, 163.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][11], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][11], 1684300900);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][11], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][11], 1);

    INVINFO[playerid][12] = CreatePlayerTextDraw(playerid, 314.000, 272.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][12], 47.000, 18.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][12], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][12], 502315876);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][12], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][12], 1);
    PlayerTextDrawSetSelectable(playerid, INVINFO[playerid][12], 1);

    INVINFO[playerid][13] = CreatePlayerTextDraw(playerid, 314.000, 248.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][13], 47.000, 18.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][13], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][13], 502315876);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][13], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][13], 1);
    PlayerTextDrawSetSelectable(playerid, INVINFO[playerid][13], 1);

    INVINFO[playerid][14] = CreatePlayerTextDraw(playerid, 314.000, 161.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][14], 47.000, 18.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][14], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][14], 502315876);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][14], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, INVINFO[playerid][14], 1);

    INVINFO[playerid][15] = CreatePlayerTextDraw(playerid, 326.000, 215.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][15], 13.000, 7.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][15], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][15], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][15], 1);

    INVINFO[playerid][16] = CreatePlayerTextDraw(playerid, 339.000, 217.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][16], 7.000, 5.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][16], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][16], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][16], 1);

    INVINFO[playerid][17] = CreatePlayerTextDraw(playerid, 342.000, 210.000, "/");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][17], 0.759, 1.299);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][17], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][17], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][17], 1);

    INVINFO[playerid][18] = CreatePlayerTextDraw(playerid, 327.000, 210.000, "/");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][18], 0.619, 0.898);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][18], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][18], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][18], 1);

    INVINFO[playerid][19] = CreatePlayerTextDraw(playerid, 333.000, 212.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][19], 9.000, 3.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][19], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][19], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][19], 1);

    INVINFO[playerid][20] = CreatePlayerTextDraw(playerid, 340.000, 211.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][20], 5.000, 5.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][20], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][20], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][20], 1);

    INVINFO[playerid][21] = CreatePlayerTextDraw(playerid, 348.000, 210.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][21], 5.000, 5.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][21], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][21], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][21], 1);

    INVINFO[playerid][22] = CreatePlayerTextDraw(playerid, 328.000, 165.000, "Jumlah");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][22], 0.150, 0.999);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][22], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][22], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][22], 1);

    INVINFO[playerid][23] = CreatePlayerTextDraw(playerid, 328.000, 252.000, "Berikan");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][23], 0.158, 0.999);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][23], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][23], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][23], 1);

    INVINFO[playerid][24] = CreatePlayerTextDraw(playerid, 329.000, 275.000, "Buang");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][24], 0.158, 0.999);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][24], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][24], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][24], 1);

    INVINFO[playerid][25] = CreatePlayerTextDraw(playerid, 326.000, 199.000, "Gunakan");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][25], 0.158, 0.999);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][25], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][25], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][25], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][25], 1);

    INVINFO[playerid][26] = CreatePlayerTextDraw(playerid, 296.000, 129.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][26], 6.000, 215.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][26], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][26], 1684300900);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][26], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][26], 1);

    INVINFO[playerid][27] = CreatePlayerTextDraw(playerid, 297.000, 130.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][27], 4.000, 110.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][27], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][27], 1684300900);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][27], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][27], 1);
    PlayerTextDrawSetSelectable(playerid, INVINFO[playerid][27], 1);

    INVINFO[playerid][28] = CreatePlayerTextDraw(playerid, 297.000, 240.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][28], 4.000, 103.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][28], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][28], 1684300900);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][28], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][28], 1);
    PlayerTextDrawSetSelectable(playerid, INVINFO[playerid][28], 1);

    INVINFO[playerid][29] = CreatePlayerTextDraw(playerid, 250.000, 111.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][29], 43.000, 12.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][29], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][29], 1684300900);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][29], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][29], 1);

    INVINFO[playerid][30] = CreatePlayerTextDraw(playerid, 132.000, 107.000, "Player");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][30], 0.158, 0.999);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][30], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][30], 502316031);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][30], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][30], 1);

    INVINFO[playerid][31] = CreatePlayerTextDraw(playerid, 131.000, 117.000, "16.00/50.00kg");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][31], 0.108, 0.699);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][31], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][31], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][31], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][31], 1);

    INVINFO[playerid][32] = CreatePlayerTextDraw(playerid, 257.000, 113.000, "Jaden_Bakteria");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][32], 0.119, 0.799);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][32], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][32], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][32], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][32], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][32], 1);

    INVINFO[playerid][33] = CreatePlayerTextDraw(playerid, 109.000, 101.000, "_");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][33], 24.000, 26.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][33], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][33], 502315876);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][33], 0);
    PlayerTextDrawFont(playerid, INVINFO[playerid][33], 5);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][33], 0);
    PlayerTextDrawSetPreviewModel(playerid, INVINFO[playerid][33], 2751);
    PlayerTextDrawSetPreviewRot(playerid, INVINFO[playerid][33], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, INVINFO[playerid][33], 0, 0);

    INVINFO[playerid][34] = CreatePlayerTextDraw(playerid, 329.000, 300.000, "Tutup");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][34], 0.158, 0.999);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][34], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][34], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][34], 1);

    INVINFO[playerid][35] = CreatePlayerTextDraw(playerid, 119.000, 118.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INVINFO[playerid][35], 6.000, -4.000);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][35], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][35], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][35], 255);
    PlayerTextDrawFont(playerid, INVINFO[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][35], 1);

    INVINFO[playerid][36] = CreatePlayerTextDraw(playerid, 120.000, 109.000, "o");
    PlayerTextDrawLetterSize(playerid, INVINFO[playerid][36], 0.200, 0.899);
    PlayerTextDrawAlignment(playerid, INVINFO[playerid][36], 1);
    PlayerTextDrawColor(playerid, INVINFO[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, INVINFO[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, INVINFO[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, INVINFO[playerid][36], 150);
    PlayerTextDrawFont(playerid, INVINFO[playerid][36], 1);
    PlayerTextDrawSetProportional(playerid, INVINFO[playerid][36], 1);

    NAMETD[playerid][0] = CreatePlayerTextDraw(playerid, 117.000, 172.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][0], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][0], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][0], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][0], 1);

    NAMETD[playerid][1] = CreatePlayerTextDraw(playerid, 162.000, 172.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][1], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][1], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][1], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][1], 1);

    NAMETD[playerid][2] = CreatePlayerTextDraw(playerid, 207.000, 172.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][2], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][2], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][2], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][2], 1);

    NAMETD[playerid][3] = CreatePlayerTextDraw(playerid, 252.000, 172.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][3], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][3], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][3], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][3], 1);

    NAMETD[playerid][4] = CreatePlayerTextDraw(playerid, 117.000, 226.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][4], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][4], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][4], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][4], 1);

    NAMETD[playerid][5] = CreatePlayerTextDraw(playerid, 162.000, 226.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][5], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][5], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][5], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][5], 1);

    NAMETD[playerid][6] = CreatePlayerTextDraw(playerid, 207.000, 226.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][6], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][6], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][6], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][6], 1);

    NAMETD[playerid][7] = CreatePlayerTextDraw(playerid, 252.000, 226.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][7], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][7], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][7], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][7], 1);

    NAMETD[playerid][8] = CreatePlayerTextDraw(playerid, 117.000, 280.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][8], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][8], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][8], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][8], 1);

    NAMETD[playerid][9] = CreatePlayerTextDraw(playerid, 162.000, 280.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][9], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][9], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][9], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][9], 1);

    NAMETD[playerid][10] = CreatePlayerTextDraw(playerid, 207.000, 280.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][10], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][10], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][10], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][10], 1);

    NAMETD[playerid][11] = CreatePlayerTextDraw(playerid, 252.000, 280.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][11], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][11], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][11], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][11], 1);

    NAMETD[playerid][12] = CreatePlayerTextDraw(playerid, 117.000, 335.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][12], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][12], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][12], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][12], 1);

    NAMETD[playerid][13] = CreatePlayerTextDraw(playerid, 162.000, 335.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][13], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][13], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][13], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][13], 1);

    NAMETD[playerid][14] = CreatePlayerTextDraw(playerid, 207.000, 335.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][14], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][14], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][14], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][14], 1);

    NAMETD[playerid][15] = CreatePlayerTextDraw(playerid, 252.000, 335.000, "Water");
    PlayerTextDrawLetterSize(playerid, NAMETD[playerid][15], 0.100, 0.598);
    PlayerTextDrawAlignment(playerid, NAMETD[playerid][15], 1);
    PlayerTextDrawColor(playerid, NAMETD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, NAMETD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, NAMETD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, NAMETD[playerid][15], 150);
    PlayerTextDrawFont(playerid, NAMETD[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, NAMETD[playerid][15], 1);

    INDEXTD[playerid][0] = CreatePlayerTextDraw(playerid, 115.000, 129.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][0], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][0], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][0], 1);

    INDEXTD[playerid][1] = CreatePlayerTextDraw(playerid, 160.000, 129.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][1], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][1], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][1], 1);

    INDEXTD[playerid][2] = CreatePlayerTextDraw(playerid, 205.000, 129.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][2], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][2], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][2], 1);

    INDEXTD[playerid][3] = CreatePlayerTextDraw(playerid, 250.000, 129.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][3], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][3], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][3], 1);

    INDEXTD[playerid][4] = CreatePlayerTextDraw(playerid, 115.000, 183.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][4], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][4], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][4], 1);

    INDEXTD[playerid][5] = CreatePlayerTextDraw(playerid, 160.000, 183.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][5], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][5], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][5], 1);

    INDEXTD[playerid][6] = CreatePlayerTextDraw(playerid, 205.000, 183.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][6], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][6], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][6], 1);

    INDEXTD[playerid][7] = CreatePlayerTextDraw(playerid, 250.000, 183.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][7], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][7], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][7], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][7], 1);

    INDEXTD[playerid][8] = CreatePlayerTextDraw(playerid, 115.000, 237.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][8], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][8], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][8], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][8], 1);

    INDEXTD[playerid][9] = CreatePlayerTextDraw(playerid, 160.000, 237.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][9], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][9], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][9], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][9], 1);

    INDEXTD[playerid][10] = CreatePlayerTextDraw(playerid, 205.000, 237.000, "LD_BUM:blkdot"); //GUNAKAN
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][10], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][10], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][10], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][10], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][10], 1);

    INDEXTD[playerid][11] = CreatePlayerTextDraw(playerid, 250.000, 237.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][11], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][11], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][11], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][11], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][11], 1);

    INDEXTD[playerid][12] = CreatePlayerTextDraw(playerid, 115.000, 291.000, "LD_BUM:blkdot"); //MENUTUP
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][12], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][12], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][12], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][12], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][12], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][12], 1);

    INDEXTD[playerid][13] = CreatePlayerTextDraw(playerid, 160.000, 291.000, "LD_BUM:blkdot"); //MEMBERIKAN     
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][13], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][13], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][13], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][13], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][13], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][13], 1);

    INDEXTD[playerid][14] = CreatePlayerTextDraw(playerid, 205.000, 291.000, "LD_BUM:blkdot"); //JUMLAH
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][14], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][14], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][14], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][14], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][14], 1);

    INDEXTD[playerid][15] = CreatePlayerTextDraw(playerid, 250.000, 291.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, INDEXTD[playerid][15], 43.000, 52.000);
    PlayerTextDrawAlignment(playerid, INDEXTD[playerid][15], 1);
    PlayerTextDrawColor(playerid, INDEXTD[playerid][15], 100);
    PlayerTextDrawSetShadow(playerid, INDEXTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, INDEXTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, INDEXTD[playerid][15], 255);
    PlayerTextDrawFont(playerid, INDEXTD[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, INDEXTD[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, INDEXTD[playerid][15], 1);

    MODELTD[playerid][0] = CreatePlayerTextDraw(playerid, 119.000, 134.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][0], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][0], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][0], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][0], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][0], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][0], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][0], 0, 0);

    MODELTD[playerid][1] = CreatePlayerTextDraw(playerid, 164.000, 134.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][1], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][1], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][1], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][1], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][1], 0, 0);

    MODELTD[playerid][2] = CreatePlayerTextDraw(playerid, 208.000, 134.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][2], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][2], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][2], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][2], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][2], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][2], 0, 0);

    MODELTD[playerid][3] = CreatePlayerTextDraw(playerid, 254.000, 134.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][3], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][3], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][3], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][3], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][3], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][3], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][3], 0, 0);

    MODELTD[playerid][4] = CreatePlayerTextDraw(playerid, 119.000, 189.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][4], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][4], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][4], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][4], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][4], 0, 0);

    MODELTD[playerid][5] = CreatePlayerTextDraw(playerid, 164.000, 189.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][5], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][5], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][5], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][5], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][5], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][5], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][5], 0, 0);

    MODELTD[playerid][6] = CreatePlayerTextDraw(playerid, 208.000, 189.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][6], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][6], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][6], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][6], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][6], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][6], 0, 0);

    MODELTD[playerid][7] = CreatePlayerTextDraw(playerid, 254.000, 189.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][7], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][7], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][7], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][7], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][7], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][7], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][7], 0, 0);

    MODELTD[playerid][8] = CreatePlayerTextDraw(playerid, 119.000, 242.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][8], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][8], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][8], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][8], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][8], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][8], 0, 0);

    MODELTD[playerid][9] = CreatePlayerTextDraw(playerid, 164.000, 242.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][9], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][9], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][9], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][9], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][9], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][9], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][9], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][9], 0, 0);

    MODELTD[playerid][10] = CreatePlayerTextDraw(playerid, 208.000, 242.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][10], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][10], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][10], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][10], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][10], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][10], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][10], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][10], 0, 0);

    MODELTD[playerid][11] = CreatePlayerTextDraw(playerid, 254.000, 242.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][11], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][11], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][11], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][11], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][11], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][11], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][11], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][11], 0, 0);

    MODELTD[playerid][12] = CreatePlayerTextDraw(playerid, 119.000, 296.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][12], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][12], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][12], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][12], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][12], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][12], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][12], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][12], 0, 0);

    MODELTD[playerid][13] = CreatePlayerTextDraw(playerid, 164.000, 296.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][13], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][13], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][13], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][13], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][13], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][13], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][13], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][13], 0, 0);

    MODELTD[playerid][14] = CreatePlayerTextDraw(playerid, 208.000, 296.000, "_");
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][14], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][14], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][14], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][14], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][14], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][14], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][14], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][14], 0, 0);

    MODELTD[playerid][15] = CreatePlayerTextDraw(playerid, 254.000, 296.000, "_"); 
    PlayerTextDrawTextSize(playerid, MODELTD[playerid][15], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, MODELTD[playerid][15], 1);
    PlayerTextDrawColor(playerid, MODELTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, MODELTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, MODELTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, MODELTD[playerid][15], 0);
    PlayerTextDrawFont(playerid, MODELTD[playerid][15], 5);
    PlayerTextDrawSetProportional(playerid, MODELTD[playerid][15], 0);
    PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][15], 3026);
    PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][15], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MODELTD[playerid][15], 0, 0);

    AMOUNTTD[playerid][0] = CreatePlayerTextDraw(playerid, 143.000, 131.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][0], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][0], 1);

    AMOUNTTD[playerid][1] = CreatePlayerTextDraw(playerid, 189.000, 131.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][1], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][1], 1);

    AMOUNTTD[playerid][2] = CreatePlayerTextDraw(playerid, 234.000, 131.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][2], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][2], 1);

    AMOUNTTD[playerid][3] = CreatePlayerTextDraw(playerid, 279.000, 131.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][3], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][3], 1);

    AMOUNTTD[playerid][4] = CreatePlayerTextDraw(playerid, 143.000, 185.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][4], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][4], 1);

    AMOUNTTD[playerid][5] = CreatePlayerTextDraw(playerid, 189.000, 185.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][5], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][5], 1);

    AMOUNTTD[playerid][6] = CreatePlayerTextDraw(playerid, 234.000, 185.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][6], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][6], 1);

    AMOUNTTD[playerid][7] = CreatePlayerTextDraw(playerid, 279.000, 185.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][7], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][7], 1);

    AMOUNTTD[playerid][8] = CreatePlayerTextDraw(playerid, 143.000, 239.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][8], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][8], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][8], 1);

    AMOUNTTD[playerid][9] = CreatePlayerTextDraw(playerid, 189.000, 239.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][9], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][9], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][9], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][9], 1);

    AMOUNTTD[playerid][10] = CreatePlayerTextDraw(playerid, 234.000, 239.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][10], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][10], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][10], 1);

    AMOUNTTD[playerid][11] = CreatePlayerTextDraw(playerid, 279.000, 239.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][11], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][11], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][11], 1);

    AMOUNTTD[playerid][12] = CreatePlayerTextDraw(playerid, 143.000, 293.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][12], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][12], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][12], 1);

    AMOUNTTD[playerid][13] = CreatePlayerTextDraw(playerid, 189.000, 293.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][13], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][13], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][13], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][13], 1);

    AMOUNTTD[playerid][14] = CreatePlayerTextDraw(playerid, 234.000, 293.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][14], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][14], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][14], 1);

    AMOUNTTD[playerid][15] = CreatePlayerTextDraw(playerid, 279.000, 293.000, "1 (1.00)");
    PlayerTextDrawLetterSize(playerid, AMOUNTTD[playerid][15], 0.100, 0.499);
    PlayerTextDrawAlignment(playerid, AMOUNTTD[playerid][15], 1);
    PlayerTextDrawColor(playerid, AMOUNTTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, AMOUNTTD[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTTD[playerid][15], 1);

    GARISBAWAH[playerid][0] = CreatePlayerTextDraw(playerid, 115.000, 179.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][0], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][0], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][0], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][0], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][0], 1);

    GARISBAWAH[playerid][1] = CreatePlayerTextDraw(playerid, 160.000, 179.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][1], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][1], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][1], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][1], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][1], 1);

    GARISBAWAH[playerid][2] = CreatePlayerTextDraw(playerid, 205.000, 179.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][2], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][2], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][2], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][2], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][2], 1);

    GARISBAWAH[playerid][3] = CreatePlayerTextDraw(playerid, 250.000, 179.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][3], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][3], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][3], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][3], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][3], 1);

    GARISBAWAH[playerid][4] = CreatePlayerTextDraw(playerid, 115.000, 233.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][4], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][4], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][4], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][4], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][4], 1);

    GARISBAWAH[playerid][5] = CreatePlayerTextDraw(playerid, 160.000, 233.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][5], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][5], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][5], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][5], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][5], 1);

    GARISBAWAH[playerid][6] = CreatePlayerTextDraw(playerid, 205.000, 233.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][6], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][6], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][6], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][6], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][6], 1);

    GARISBAWAH[playerid][7] = CreatePlayerTextDraw(playerid, 250.000, 233.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][7], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][7], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][7], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][7], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][7], 1);

    GARISBAWAH[playerid][8] = CreatePlayerTextDraw(playerid, 115.000, 287.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][8], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][8], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][8], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][8], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][8], 1);

    GARISBAWAH[playerid][9] = CreatePlayerTextDraw(playerid, 160.000, 287.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][9], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][9], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][9], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][9], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][9], 1);

    GARISBAWAH[playerid][10] = CreatePlayerTextDraw(playerid, 205.000, 287.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][10], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][10], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][10], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][10], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][10], 1);

    GARISBAWAH[playerid][11] = CreatePlayerTextDraw(playerid, 250.000, 287.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][11], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][11], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][11], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][11], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][11], 1);

    GARISBAWAH[playerid][12] = CreatePlayerTextDraw(playerid, 115.000, 342.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][12], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][12], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][12], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][12], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][12], 1);

    GARISBAWAH[playerid][13] = CreatePlayerTextDraw(playerid, 160.000, 342.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][13], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][13], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][13], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][13], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][13], 1);

    GARISBAWAH[playerid][14] = CreatePlayerTextDraw(playerid, 205.000, 342.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][14], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][14], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][14], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][14], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][14], 1);

    GARISBAWAH[playerid][15] = CreatePlayerTextDraw(playerid, 250.000, 342.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GARISBAWAH[playerid][15], 43.000, 2.000);
    PlayerTextDrawAlignment(playerid, GARISBAWAH[playerid][15], 1);
    PlayerTextDrawColor(playerid, GARISBAWAH[playerid][15], 502316031);
    PlayerTextDrawSetShadow(playerid, GARISBAWAH[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, GARISBAWAH[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, GARISBAWAH[playerid][15], 255);
    PlayerTextDrawFont(playerid, GARISBAWAH[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, GARISBAWAH[playerid][15], 1);

}

hook OnPlayerConnect(playerid)
{
    CreateInventoryTextdraw(playerid);
    return 1;
}

function Inventory_Show(playerid, p2, slotid)
{
	if(!IsPlayerConnected(playerid))
		return 0;

    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
	//if(IsValidProgressBarTextdraw(playerid)) 
	//	return ErrorMsg(playerid, "Anda sedang melakukan sesuatu, harap tunggu!");

	if(AccountData[playerid][pSpawned] == 1 && AccountData[playerid][pUseTextdraw] == 0)
	{
		AccountData[playerid][pUseTextdraw] = 1;
		
		new item[128], str[128];

		if(InventoryWeightFull(p2))
		{
			format(str, sizeof(str), "%.3f/%.3fkg", GetPlayerMaxInventory(p2), GetPlayerMaxInventory(p2));
			PlayerTextDrawSetString(playerid, INVINFO[p2][31], str);
		}
		else
		{
			format(str, sizeof(str), "%.3f/%.3fkg", GetItemAllKG(p2), GetPlayerMaxInventory(p2));
			PlayerTextDrawSetString(playerid, INVINFO[p2][31], str);
		}

		format(str, sizeof(str), "%s", AccountData[p2][pName]);
		PlayerTextDrawSetString(playerid, INVINFO[p2][32], str);
		
		forex(u, 37)
		{
            if(IsValidDynamicPlayerTextDraw(playerid, INVINFO[p2][u]))
			    PlayerTextDrawShow(playerid, INVINFO[p2][u]);
		} 
		SelectTextDraw(playerid, COLOR_SYNTAX);
		
        invenIndex[playerid] = slotid;
		invenNumber[playerid] = (invenIndex[playerid] - 1) * 16;
		if(invenIndex[playerid] == 1)
		{
			PlayerTextDrawHide(playerid, INVINFO[playerid][27]);
			PlayerTextDrawShow(playerid, INVINFO[playerid][28]);
		}
		else
		{
			PlayerTextDrawHide(playerid, INVINFO[playerid][28]);
			PlayerTextDrawShow(playerid, INVINFO[playerid][27]);
		}
		
		for (new i = 0; i < 16; i ++) 
		{
			PlayerTextDrawShow(playerid, INDEXTD[p2][i]);
			PlayerTextDrawShow(playerid, GARISBAWAH[p2][i]);
			
			if(InventoryData[p2][i + invenNumber[playerid]][invExists])
			{
				//PENYESUAIAN ROTATE ITEMS
				switch(InventoryData[p2][i + invenNumber[playerid]][invModel])
				{
					case 18867: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], -254.000000, 0.000000, 0.000000, 2.500);
					case 16776: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], 0.000000, 0.000000, -85.000000, 2.500);
					case 1581: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], 0.000000, 0.000000, -180.000000, 2.500);
					case 19580: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], -95.000000, 0.000000, 1.000000, 2.500);
					case 2703: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], -80.000, 0.000, 0.000, 2.500);
					case 19896: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], -50.000, 0.000, -10.000, 2.500);
					case 18875: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], 95.000, 180.000, 0.000, 2.500);
					case 19878: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], 163.000, 210.000, -50.000, 2.500);
					case 19883: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], 163.000, 210.000, -50.000, 2.500);
					case 11736: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], 120.000, -30.000, 0.000, 2.500);
					default: PlayerTextDrawSetPreviewRot(playerid, MODELTD[p2][i], 0.000, 0.000, 0.000, 2.500);
				}
				
				PlayerTextDrawSetPreviewModel(playerid, MODELTD[p2][i], InventoryData[p2][i + invenNumber[playerid]][invModel]);
				PlayerTextDrawShow(playerid, MODELTD[p2][i]);

				strunpack(item, InventoryData[p2][i + invenNumber[playerid]][invItem]);

				format(str, sizeof(str), "%s", item);
				PlayerTextDrawSetString(playerid, NAMETD[p2][i], str);
				PlayerTextDrawShow(playerid, NAMETD[p2][i]);

				format(str, sizeof(str), "%d(%.3f)", InventoryData[p2][i + invenNumber[playerid]][invQuantity], GetItemKG(item, InventoryData[p2][i + invenNumber[playerid]][invQuantity]));
                PlayerTextDrawSetString(playerid, AMOUNTTD[p2][i], str);
                PlayerTextDrawShow(playerid, AMOUNTTD[p2][i]);
			}
		}
	}
	return 1;
}

Inventory_Close(playerid)
{
	forex(i, 37)
	{
        if(IsValidDynamicPlayerTextDraw(playerid, INVINFO[playerid][i]))
	        PlayerTextDrawHide(playerid, INVINFO[playerid][i]);
	}
	for (new u = 0; u < 16; u ++) 
	{
	    PlayerTextDrawHide(playerid, MODELTD[playerid][u]);
	    PlayerTextDrawHide(playerid, NAMETD[playerid][u]);
	    PlayerTextDrawHide(playerid, AMOUNTTD[playerid][u]);
	    PlayerTextDrawHide(playerid, INDEXTD[playerid][u]);
		PlayerTextDrawHide(playerid, GARISBAWAH[playerid][u]);
		PlayerTextDrawColor(playerid, INDEXTD[playerid][u], 1667457892);
	}
	CancelSelectTextDraw(playerid);

	AccountData[playerid][pUseTextdraw] = 0;
	AccountData[playerid][pSelectItem] = -1;
	return 1;
}

stock ItemSwitch(playerid, itemid, slot, old_slot)
{
	//ITEM BARU
	InventoryData[playerid][slot][invExists] = true;
	InventoryData[playerid][slot][invQuantity] = InventoryData[playerid][itemid][invQuantity];
	strpack(InventoryData[playerid][slot][invItem], InventoryData[playerid][itemid][invItem], 32 char);
	InventoryData[playerid][slot][invModel] = InventoryData[playerid][itemid][invModel];
	InventoryData[playerid][slot][invID] = InventoryData[playerid][itemid][invID];

	//ITEM LAMA
	InventoryData[playerid][itemid][invExists] = false;
	InventoryData[playerid][itemid][invModel] = 0;
	InventoryData[playerid][itemid][invQuantity] = 0;
	InventoryData[playerid][itemid][invID] = -1;

	//HIDE OLD ITEM BOX
	PlayerTextDrawHide(playerid, INDEXTD[playerid][old_slot]);
	PlayerTextDrawColor(playerid, INDEXTD[playerid][old_slot], 1667457892);
	PlayerTextDrawShow(playerid, INDEXTD[playerid][old_slot]);

	PlayerTextDrawHide(playerid, MODELTD[playerid][old_slot]);
	PlayerTextDrawHide(playerid, NAMETD[playerid][old_slot]);
	PlayerTextDrawHide(playerid, AMOUNTTD[playerid][old_slot]);

	//SHOW THE NEW ITEMBOX
	new 
		str[32],
		string[64];

	PlayerTextDrawHide(playerid, INDEXTD[playerid][slot - invenPlayed[playerid]]);
	PlayerTextDrawShow(playerid, INDEXTD[playerid][slot - invenPlayed[playerid]]);

	PlayerTextDrawHide(playerid, GARISBAWAH[playerid][slot - invenPlayed[playerid]]);
	PlayerTextDrawShow(playerid, GARISBAWAH[playerid][slot - invenPlayed[playerid]]);

	ItemIcon(playerid, slot);
	
	PlayerTextDrawShow(playerid, MODELTD[playerid][slot - invenPlayed[playerid]]);
	strunpack(string, InventoryData[playerid][slot][invItem]);

	format(str, sizeof(str), "%s", string);
	PlayerTextDrawSetString(playerid, NAMETD[playerid][slot - invenPlayed[playerid]], str);
	PlayerTextDrawShow(playerid, NAMETD[playerid][slot - invenPlayed[playerid]]);

	for (new ai = 0; ai < sizeof(g_aInventoryItems); ai ++) if (!strcmp(g_aInventoryItems[ai][e_InventoryItem], string, true))
	{
		format(str, sizeof(str), "%d(%.3f)", InventoryData[playerid][slot][invQuantity], float(InventoryData[playerid][slot][invQuantity])*g_aInventoryItems[ai][e_InventoryWeight] / 1000);
		PlayerTextDrawSetString(playerid, AMOUNTTD[playerid][slot - invenPlayed[playerid]], str);
		PlayerTextDrawShow(playerid, AMOUNTTD[playerid][slot - invenPlayed[playerid]]);
	}

	AccountData[playerid][pSelectItem] = -1;
	return 1;
}

ItemIcon(playerid, slot)
{
	switch(InventoryData[playerid][slot][invModel])
	{
		case 18867: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], -254.000000, 0.000000, 0.000000, 2.500);
		case 16776: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], 0.000000, 0.000000, -85.000000, 2.500);
		case 1581: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], 0.000000, 0.000000, -180.000000, 2.500);
		case 19580: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], -95.000000, 0.000000, 1.000000, 2.500);
		case 2703: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], -80.000, 0.000, 0.000, 2.500);
		case 19896: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], -50.000, 0.000, -10.000, 2.500);
		case 18875: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], 95.000, 180.000, 0.000, 2.500);
		case 19878: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], 163.000, 210.000, -50.000, 2.500);
		case 19883: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], 163.000, 210.000, -50.000, 2.500);
		case 11736: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], 120.000, -30.000, 0.000, 2.500);
		default: PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], 0.000, 0.000, 0.000, 2.500);
	}
	PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][slot - invenPlayed[playerid]], InventoryData[playerid][slot][invModel]);
	return 1;
}

InventorySelect(playerid, row)
{
    PlayerTextDrawHide(playerid,INDEXTD[playerid][row]);
	PlayerTextDrawColor(playerid, INDEXTD[playerid][row], 1733302984);
	PlayerTextDrawShow(playerid,INDEXTD[playerid][row]);
}

InventoryUnSelect(playerid)
{	
	if(AccountData[playerid][pSelectInv] != -1)
	{
		new row = AccountData[playerid][pSelectInv];
		PlayerTextDrawHide(playerid, INDEXTD[playerid][row]);
		PlayerTextDrawColor(playerid, INDEXTD[playerid][row], 1667457892);
		PlayerTextDrawShow(playerid, INDEXTD[playerid][row]);
	}
	AccountData[playerid][pSelectInv] = -1;
	AccountData[playerid][pSelectItem] = -1;
}
/*CreateInventoryGTextdraw()
{
    i_textdraw[0] = TextDrawCreate(352.000, 166.000, "LD_SPAC:white");
    TextDrawTextSize(i_textdraw[0], 55.000, 21.000);
    TextDrawAlignment(i_textdraw[0], 1);
    TextDrawColor(i_textdraw[0], 135);
    TextDrawSetShadow(i_textdraw[0], 0);
    TextDrawSetOutline(i_textdraw[0], 0);
    TextDrawBackgroundColor(i_textdraw[0], 255);
    TextDrawFont(i_textdraw[0], 4);
    TextDrawSetProportional(i_textdraw[0], 1);
    TextDrawSetSelectable(i_textdraw[0], 1);

    i_textdraw[1] = TextDrawCreate(352.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(i_textdraw[1], 55.000, 29.000);
    TextDrawAlignment(i_textdraw[1], 1);
    TextDrawColor(i_textdraw[1], 135);
    TextDrawSetShadow(i_textdraw[1], 0);
    TextDrawSetOutline(i_textdraw[1], 0);
    TextDrawBackgroundColor(i_textdraw[1], 255);
    TextDrawFont(i_textdraw[1], 4);
    TextDrawSetProportional(i_textdraw[1], 1);
    TextDrawSetSelectable(i_textdraw[1], 1);

    i_textdraw[2] = TextDrawCreate(352.000, 222.000, "LD_SPAC:white");
    TextDrawTextSize(i_textdraw[2], 55.000, 21.000);
    TextDrawAlignment(i_textdraw[2], 1);
    TextDrawColor(i_textdraw[2], 135);
    TextDrawSetShadow(i_textdraw[2], 0);
    TextDrawSetOutline(i_textdraw[2], 0);
    TextDrawBackgroundColor(i_textdraw[2], 255);
    TextDrawFont(i_textdraw[2], 4);
    TextDrawSetProportional(i_textdraw[2], 1);
    TextDrawSetSelectable(i_textdraw[2], 1);

    i_textdraw[3] = TextDrawCreate(352.000, 246.000, "LD_SPAC:white");
    TextDrawTextSize(i_textdraw[3], 55.000, 21.000);
    TextDrawAlignment(i_textdraw[3], 1);
    TextDrawColor(i_textdraw[3], 135);
    TextDrawSetShadow(i_textdraw[3], 0);
    TextDrawSetOutline(i_textdraw[3], 0);
    TextDrawBackgroundColor(i_textdraw[3], 255);
    TextDrawFont(i_textdraw[3], 4);
    TextDrawSetProportional(i_textdraw[3], 1);
    TextDrawSetSelectable(i_textdraw[3], 1);

    i_textdraw[4] = TextDrawCreate(383.000, 194.000, "-");
    TextDrawLetterSize(i_textdraw[4], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[4], 2);
    TextDrawColor(i_textdraw[4], -1);
    TextDrawSetShadow(i_textdraw[4], 0);
    TextDrawSetOutline(i_textdraw[4], 0);
    TextDrawBackgroundColor(i_textdraw[4], 150);
    TextDrawFont(i_textdraw[4], 1);
    TextDrawSetProportional(i_textdraw[4], 1);

    i_textdraw[5] = TextDrawCreate(389.000, 193.000, "/");
    TextDrawLetterSize(i_textdraw[5], 0.759, 1.699);
    TextDrawAlignment(i_textdraw[5], 2);
    TextDrawColor(i_textdraw[5], -1);
    TextDrawSetShadow(i_textdraw[5], 0);
    TextDrawSetOutline(i_textdraw[5], 0);
    TextDrawBackgroundColor(i_textdraw[5], 150);
    TextDrawFont(i_textdraw[5], 1);
    TextDrawSetProportional(i_textdraw[5], 1);

    i_textdraw[6] = TextDrawCreate(389.000, 193.000, "/");
    TextDrawLetterSize(i_textdraw[6], 0.759, 1.699);
    TextDrawAlignment(i_textdraw[6], 2);
    TextDrawColor(i_textdraw[6], -1);
    TextDrawSetShadow(i_textdraw[6], 0);
    TextDrawSetOutline(i_textdraw[6], 0);
    TextDrawBackgroundColor(i_textdraw[6], 150);
    TextDrawFont(i_textdraw[6], 1);
    TextDrawSetProportional(i_textdraw[6], 1);

    i_textdraw[7] = TextDrawCreate(376.000, 197.000, "/");
    TextDrawLetterSize(i_textdraw[7], 0.749, 1.099);
    TextDrawAlignment(i_textdraw[7], 2);
    TextDrawColor(i_textdraw[7], -1);
    TextDrawSetShadow(i_textdraw[7], 0);
    TextDrawSetOutline(i_textdraw[7], 0);
    TextDrawBackgroundColor(i_textdraw[7], 150);
    TextDrawFont(i_textdraw[7], 1);
    TextDrawSetProportional(i_textdraw[7], 1);

    i_textdraw[8] = TextDrawCreate(376.000, 197.000, "/");
    TextDrawLetterSize(i_textdraw[8], 0.749, 1.099);
    TextDrawAlignment(i_textdraw[8], 2);
    TextDrawColor(i_textdraw[8], -1);
    TextDrawSetShadow(i_textdraw[8], 0);
    TextDrawSetOutline(i_textdraw[8], 0);
    TextDrawBackgroundColor(i_textdraw[8], 150);
    TextDrawFont(i_textdraw[8], 1);
    TextDrawSetProportional(i_textdraw[8], 1);

    i_textdraw[9] = TextDrawCreate(377.000, 197.000, "/");
    TextDrawLetterSize(i_textdraw[9], 0.749, 1.099);
    TextDrawAlignment(i_textdraw[9], 2);
    TextDrawColor(i_textdraw[9], -1);
    TextDrawSetShadow(i_textdraw[9], 0);
    TextDrawSetOutline(i_textdraw[9], 0);
    TextDrawBackgroundColor(i_textdraw[9], 150);
    TextDrawFont(i_textdraw[9], 1);
    TextDrawSetProportional(i_textdraw[9], 1);

    i_textdraw[10] = TextDrawCreate(383.000, 194.000, "-");
    TextDrawLetterSize(i_textdraw[10], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[10], 2);
    TextDrawColor(i_textdraw[10], -1);
    TextDrawSetShadow(i_textdraw[10], 0);
    TextDrawSetOutline(i_textdraw[10], 0);
    TextDrawBackgroundColor(i_textdraw[10], 150);
    TextDrawFont(i_textdraw[10], 1);
    TextDrawSetProportional(i_textdraw[10], 1);

    i_textdraw[11] = TextDrawCreate(375.000, 194.000, "-");
    TextDrawLetterSize(i_textdraw[11], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[11], 2);
    TextDrawColor(i_textdraw[11], -1);
    TextDrawSetShadow(i_textdraw[11], 0);
    TextDrawSetOutline(i_textdraw[11], 0);
    TextDrawBackgroundColor(i_textdraw[11], 150);
    TextDrawFont(i_textdraw[11], 1);
    TextDrawSetProportional(i_textdraw[11], 1);

    i_textdraw[12] = TextDrawCreate(375.000, 194.000, "-");
    TextDrawLetterSize(i_textdraw[12], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[12], 2);
    TextDrawColor(i_textdraw[12], -1);
    TextDrawSetShadow(i_textdraw[12], 0);
    TextDrawSetOutline(i_textdraw[12], 0);
    TextDrawBackgroundColor(i_textdraw[12], 150);
    TextDrawFont(i_textdraw[12], 1);
    TextDrawSetProportional(i_textdraw[12], 1);

    i_textdraw[13] = TextDrawCreate(370.000, 194.000, "-");
    TextDrawLetterSize(i_textdraw[13], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[13], 2);
    TextDrawColor(i_textdraw[13], -1);
    TextDrawSetShadow(i_textdraw[13], 0);
    TextDrawSetOutline(i_textdraw[13], 0);
    TextDrawBackgroundColor(i_textdraw[13], 150);
    TextDrawFont(i_textdraw[13], 1);
    TextDrawSetProportional(i_textdraw[13], 1);

    i_textdraw[14] = TextDrawCreate(370.000, 194.000, "-");
    TextDrawLetterSize(i_textdraw[14], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[14], 2);
    TextDrawColor(i_textdraw[14], -1);
    TextDrawSetShadow(i_textdraw[14], 0);
    TextDrawSetOutline(i_textdraw[14], 0);
    TextDrawBackgroundColor(i_textdraw[14], 150);
    TextDrawFont(i_textdraw[14], 1);
    TextDrawSetProportional(i_textdraw[14], 1);

    i_textdraw[15] = TextDrawCreate(381.000, 186.000, "-");
    TextDrawLetterSize(i_textdraw[15], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[15], 2);
    TextDrawColor(i_textdraw[15], -1);
    TextDrawSetShadow(i_textdraw[15], 0);
    TextDrawSetOutline(i_textdraw[15], 0);
    TextDrawBackgroundColor(i_textdraw[15], 150);
    TextDrawFont(i_textdraw[15], 1);
    TextDrawSetProportional(i_textdraw[15], 1);

    i_textdraw[16] = TextDrawCreate(381.000, 186.000, "-");
    TextDrawLetterSize(i_textdraw[16], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[16], 2);
    TextDrawColor(i_textdraw[16], -1);
    TextDrawSetShadow(i_textdraw[16], 0);
    TextDrawSetOutline(i_textdraw[16], 0);
    TextDrawBackgroundColor(i_textdraw[16], 150);
    TextDrawFont(i_textdraw[16], 1);
    TextDrawSetProportional(i_textdraw[16], 1);

    i_textdraw[17] = TextDrawCreate(370.000, 191.000, "-");
    TextDrawLetterSize(i_textdraw[17], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[17], 2);
    TextDrawColor(i_textdraw[17], -1);
    TextDrawSetShadow(i_textdraw[17], 0);
    TextDrawSetOutline(i_textdraw[17], 0);
    TextDrawBackgroundColor(i_textdraw[17], 150);
    TextDrawFont(i_textdraw[17], 1);
    TextDrawSetProportional(i_textdraw[17], 1);

    i_textdraw[18] = TextDrawCreate(370.000, 191.000, "-");
    TextDrawLetterSize(i_textdraw[18], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[18], 2);
    TextDrawColor(i_textdraw[18], -1);
    TextDrawSetShadow(i_textdraw[18], 0);
    TextDrawSetOutline(i_textdraw[18], 0);
    TextDrawBackgroundColor(i_textdraw[18], 150);
    TextDrawFont(i_textdraw[18], 1);
    TextDrawSetProportional(i_textdraw[18], 1);

    i_textdraw[19] = TextDrawCreate(375.000, 203.000, "/");
    TextDrawLetterSize(i_textdraw[19], -1.310, 0.399);
    TextDrawAlignment(i_textdraw[19], 2);
    TextDrawColor(i_textdraw[19], -1);
    TextDrawSetShadow(i_textdraw[19], 0);
    TextDrawSetOutline(i_textdraw[19], 0);
    TextDrawBackgroundColor(i_textdraw[19], 150);
    TextDrawFont(i_textdraw[19], 1);
    TextDrawSetProportional(i_textdraw[19], 1);

    i_textdraw[20] = TextDrawCreate(375.000, 203.000, "/");
    TextDrawLetterSize(i_textdraw[20], -1.310, 0.399);
    TextDrawAlignment(i_textdraw[20], 2);
    TextDrawColor(i_textdraw[20], -1);
    TextDrawSetShadow(i_textdraw[20], 0);
    TextDrawSetOutline(i_textdraw[20], 0);
    TextDrawBackgroundColor(i_textdraw[20], 150);
    TextDrawFont(i_textdraw[20], 1);
    TextDrawSetProportional(i_textdraw[20], 1);

    i_textdraw[21] = TextDrawCreate(373.000, 197.000, "/");
    TextDrawLetterSize(i_textdraw[21], 0.749, 1.099);
    TextDrawAlignment(i_textdraw[21], 2);
    TextDrawColor(i_textdraw[21], -1);
    TextDrawSetShadow(i_textdraw[21], 0);
    TextDrawSetOutline(i_textdraw[21], 0);
    TextDrawBackgroundColor(i_textdraw[21], 150);
    TextDrawFont(i_textdraw[21], 1);
    TextDrawSetProportional(i_textdraw[21], 1);

    i_textdraw[22] = TextDrawCreate(373.000, 197.000, "/");
    TextDrawLetterSize(i_textdraw[22], 0.749, 1.099);
    TextDrawAlignment(i_textdraw[22], 2);
    TextDrawColor(i_textdraw[22], -1);
    TextDrawSetShadow(i_textdraw[22], 0);
    TextDrawSetOutline(i_textdraw[22], 0);
    TextDrawBackgroundColor(i_textdraw[22], 150);
    TextDrawFont(i_textdraw[22], 1);
    TextDrawSetProportional(i_textdraw[22], 1);

    i_textdraw[23] = TextDrawCreate(378.000, 186.000, "-");
    TextDrawLetterSize(i_textdraw[23], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[23], 2);
    TextDrawColor(i_textdraw[23], -1);
    TextDrawSetShadow(i_textdraw[23], 0);
    TextDrawSetOutline(i_textdraw[23], 0);
    TextDrawBackgroundColor(i_textdraw[23], 150);
    TextDrawFont(i_textdraw[23], 1);
    TextDrawSetProportional(i_textdraw[23], 1);

    i_textdraw[24] = TextDrawCreate(378.000, 186.000, "-");
    TextDrawLetterSize(i_textdraw[24], 0.819, 2.499);
    TextDrawAlignment(i_textdraw[24], 2);
    TextDrawColor(i_textdraw[24], -1);
    TextDrawSetShadow(i_textdraw[24], 0);
    TextDrawSetOutline(i_textdraw[24], 0);
    TextDrawBackgroundColor(i_textdraw[24], 150);
    TextDrawFont(i_textdraw[24], 1);
    TextDrawSetProportional(i_textdraw[24], 1);

    i_textdraw[25] = TextDrawCreate(379.000, 269.000, "X");
    TextDrawLetterSize(i_textdraw[25], 0.549, 2.399);
    TextDrawTextSize(i_textdraw[25], 24.000, 19.000);
    TextDrawAlignment(i_textdraw[25], 2);
    TextDrawColor(i_textdraw[25], -16776961);
    TextDrawSetShadow(i_textdraw[25], 0);
    TextDrawSetOutline(i_textdraw[25], 0);
    TextDrawBackgroundColor(i_textdraw[25], 150);
    TextDrawFont(i_textdraw[25], 2);
    TextDrawSetProportional(i_textdraw[25], 1);
    TextDrawSetSelectable(i_textdraw[25], 1);
}

hook OnGameModeInit()
{
    CreateInventoryGTextdraw();
    return 1;
}*/

/*ShowInventoryTD(playerid)
{
    forex(i, 26)
    {
        TextDrawShowForPlayer(playerid, inv::textdraw[i]);
    }
    forex(i,6)
    {
        PlayerTextDrawShow(playerid, inv::string[playerid][i]);
    }
    AccountData[playerid][pAmountInv] = 0;
    PlayerTextDrawSetString(playerid, inv::string[playerid][0], "Amount");
}

Inventory_Show(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;

    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");
    SendClientMessage(playerid, -1, " ");

    ShowInventoryTD(playerid);
    new str[120];
    for(new index; index < MAX_INVENTORY; index ++) 
    {
        PlayerTextDrawShow(playerid, inv::box[playerid][index]);
        if(InventoryData[playerid][index][invExists])
        {
            for (new i; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], InventoryData[playerid][index][invItem], true))
            {
                
                PlayerTextDrawSetPreviewModel(playerid, inv::model[playerid][index], InventoryData[playerid][index][invModel]);
                PlayerTextDrawShow(playerid, inv::model[playerid][index]);

                format(str, sizeof(str), "%s", g_aInventoryItems[i][e_InventoryItem], InventoryData[playerid][index][invQuantity]);
                PlayerTextDrawSetString(playerid, inv::item[playerid][index], str);
                PlayerTextDrawShow(playerid, inv::item[playerid][index]);

                format(str, sizeof(str), "%dx (%.1f)", InventoryData[playerid][index][invQuantity], Float:GetInventoryWeight(g_aInventoryItems[i][e_InventoryItem], InventoryData[playerid][index][invQuantity]));
                PlayerTextDrawSetString(playerid, inv::qwt[playerid][index], str);
                PlayerTextDrawShow(playerid, inv::qwt[playerid][index]);

                PlayerTextDrawShow(playerid, inv::bar[playerid][index]);
            }
        }
    }
    
    format(str, sizeof(str), "%.1f/50", AccountData[playerid][pBeratItem]);
    PlayerTextDrawSetString(playerid, inv::string[playerid][5], str);

    format(str, sizeof(str), "%s", AccountData[playerid][pName]);
    PlayerTextDrawSetString(playerid, inv::string[playerid][4], str);
    
    SelectTextDraw(playerid, X11_PINK);
    return 1;
}

Inventory_Close(playerid)
{
    forex(i,6)
    {
        PlayerTextDrawHide(playerid, inv::string[playerid][i]);
    }
    forex(i, 26)
    {
        TextDrawHideForPlayer(playerid, inv::textdraw[i]);
    }
    forex(i, MAX_INVENTORY)
    {
        PlayerTextDrawHide(playerid, inv::box[playerid][i]);
        PlayerTextDrawHide(playerid, inv::model[playerid][i]);
        PlayerTextDrawHide(playerid, inv::item[playerid][i]);
        PlayerTextDrawHide(playerid, inv::qwt[playerid][i]);
        PlayerTextDrawHide(playerid, inv::bar[playerid][i]);
    }
    CancelSelectTextDraw(playerid);
    AccountData[playerid][pSelectItem] = -1;
    AccountData[playerid][pAmountInv] = 0;
    return 1;
}


stock SelectItem(playerid, i)
{
    AccountData[playerid][pSelectItem] = i;
    PlayerTextDrawColor(playerid, inv::box[playerid][i], -190554032);
    PlayerTextDrawShow(playerid, inv::box[playerid][i]);
    PlayerPlaySound(playerid, 1052, 0, 0, 0);
    return 1;
}

stock UnselectItem(playerid)
{
    if(AccountData[playerid][pSelectItem] != -1)
    {
        PlayerTextDrawHide(playerid, inv::box[playerid][AccountData[playerid][pSelectItem]]);
        PlayerTextDrawColor(playerid, inv::box[playerid][AccountData[playerid][pSelectItem]], 135);
		PlayerTextDrawShow(playerid, inv::box[playerid][AccountData[playerid][pSelectItem]]);
    }
    AccountData[playerid][pSelectItem] = -1;
    return 1;
}

stock MoveItemToNewSlot(playerid, b, a)
{
    //textdraw slot before moving
	PlayerTextDrawSetPreviewModel(playerid, inv::model[playerid][b], 11477);
	PlayerTextDrawSetString(playerid, inv::item[playerid][b], "_");
	PlayerTextDrawSetString(playerid, inv::qwt[playerid][b], "_");
    //var inv item
	InventoryData[playerid][a][invExists] = true;
	InventoryData[playerid][a][invModel] = InventoryData[playerid][b][invModel];
	InventoryData[playerid][a][invQuantity] = InventoryData[playerid][b][invQuantity];
	strpack(InventoryData[playerid][a][invItem], InventoryData[playerid][b][invItem], 32 char);
    //var after inv item
	InventoryData[playerid][b][invExists] = false;
	InventoryData[playerid][b][invModel] = 0;
	InventoryData[playerid][b][invQuantity] = 0;
	strpack(InventoryData[playerid][b][invItem], "", 32 char);
    //textdrawslot after moving
	new invStr[64];
	format(invStr, 64, "%dx (%.1f)", InventoryData[playerid][a][invQuantity], Float:GetInventoryWeight(InventoryData[playerid][a][invItem], InventoryData[playerid][a][invQuantity]));
	PlayerTextDrawSetPreviewModel(playerid, inv::model[playerid][a], InventoryData[playerid][a][invModel]);
	PlayerTextDrawSetString(playerid, inv::item[playerid][a], InventoryData[playerid][a][invItem]);
	PlayerTextDrawSetString(playerid, inv::qwt[playerid][a], invStr);
	//all show and hide slot textdraw
	PlayerTextDrawHide(playerid, inv::box[playerid][b]);
	PlayerTextDrawHide(playerid, inv::model[playerid][b]);
	PlayerTextDrawHide(playerid, inv::qwt[playerid][b]);
	PlayerTextDrawHide(playerid, inv::item[playerid][b]);
	PlayerTextDrawHide(playerid, inv::bar[playerid][b]);
	PlayerTextDrawShow(playerid, inv::box[playerid][a]);
	PlayerTextDrawShow(playerid, inv::model[playerid][a]);
	PlayerTextDrawShow(playerid, inv::qwt[playerid][a]);
	PlayerTextDrawShow(playerid, inv::item[playerid][a]);
	PlayerTextDrawShow(playerid, inv::bar[playerid][a]);
    return 1;
}*/