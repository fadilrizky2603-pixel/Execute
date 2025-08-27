#include <YSI_Coding/y_hooks>

hook OnPlayerConnect(playerid) {
    SpawnMenu[playerid][0] = CreatePlayerTextDraw(playerid, 135.000, 141.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][0], 145.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][0], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][0], 150);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][0], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnMenu[playerid][0], 1);

    SpawnMenu[playerid][1] = CreatePlayerTextDraw(playerid, 135.000, 205.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][1], 145.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][1], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][1], 150);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][1], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnMenu[playerid][1], 1);

    SpawnMenu[playerid][2] = CreatePlayerTextDraw(playerid, 135.000, 270.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][2], 145.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][2], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][2], 150);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][2], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnMenu[playerid][2], 1);

    SpawnMenu[playerid][3] = CreatePlayerTextDraw(playerid, 285.000, 166.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][3], 145.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][3], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][3], 150);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][3], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnMenu[playerid][3], 1);

    SpawnMenu[playerid][4] = CreatePlayerTextDraw(playerid, 285.000, 232.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][4], 145.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][4], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][4], 150);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][4], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnMenu[playerid][4], 1);

    SpawnMenu[playerid][5] = CreatePlayerTextDraw(playerid, 435.000, 195.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][5], 145.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][5], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][5], 150);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][5], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnMenu[playerid][5], 1);

    SpawnMenu[playerid][6] = CreatePlayerTextDraw(playerid, 134.000, 141.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][6], 1.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][6], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][6], SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][6], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][6], 1);

    SpawnMenu[playerid][7] = CreatePlayerTextDraw(playerid, 134.000, 205.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][7], 1.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][7], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][7], SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][7], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][7], 1);

    SpawnMenu[playerid][8] = CreatePlayerTextDraw(playerid, 134.000, 270.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][8], 1.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][8], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][8], SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][8], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][8], 1);

    SpawnMenu[playerid][9] = CreatePlayerTextDraw(playerid, 285.000, 232.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][9], 1.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][9], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][9], SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][9], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][9], 1);

    SpawnMenu[playerid][10] = CreatePlayerTextDraw(playerid, 285.000, 165.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][10], 1.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][10], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][10], SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][10], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][10], 1);

    SpawnMenu[playerid][11] = CreatePlayerTextDraw(playerid, 435.000, 195.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][11], 1.000, 60.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][11], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][11], SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][11], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][11], 1);

    SpawnMenu[playerid][12] = CreatePlayerTextDraw(playerid, 138.000, 142.000, "Airport");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][12], 0.219, 1.400);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][12], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][12], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][12], 1);

    SpawnMenu[playerid][13] = CreatePlayerTextDraw(playerid, 138.000, 153.000, "anda akan spawn di airport kampung indo");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][13], 0.139, 1.100);
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][13], 334.000, 0.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][13], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][13], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][13], 1);

    SpawnMenu[playerid][14] = CreatePlayerTextDraw(playerid, 138.000, 218.000, "anda akan spawn di motal kampung indo");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][14], 0.139, 1.100);
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][14], 334.000, 0.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][14], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][14], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][14], 1);

    SpawnMenu[playerid][15] = CreatePlayerTextDraw(playerid, 138.000, 206.000, "Motel");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][15], 0.219, 1.400);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][15], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][15], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][15], 1);

    SpawnMenu[playerid][16] = CreatePlayerTextDraw(playerid, 138.000, 269.000, "Carnaval");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][16], 0.219, 1.400);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][16], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][16], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][16], 1);

    SpawnMenu[playerid][17] = CreatePlayerTextDraw(playerid, 138.000, 280.000, "anda akan spawn di carnaval kampung indo");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][17], 0.139, 1.100);
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][17], 334.000, 0.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][17], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][17], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][17], 1);

    SpawnMenu[playerid][18] = CreatePlayerTextDraw(playerid, 289.000, 165.000, "House");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][18], 0.219, 1.400);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][18], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][18], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][18], 1);

    SpawnMenu[playerid][19] = CreatePlayerTextDraw(playerid, 289.000, 178.000, "anda akan spawn di house property");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][19], 0.139, 1.100);
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][19], 485.000, 0.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][19], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][19], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][19], 1);

    SpawnMenu[playerid][20] = CreatePlayerTextDraw(playerid, 289.000, 245.000, "anda akan spawn di faction anda");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][20], 0.139, 1.100);
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][20], 485.000, 0.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][20], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][20], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][20], 1);

    SpawnMenu[playerid][21] = CreatePlayerTextDraw(playerid, 289.000, 233.000, "Faction");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][21], 0.219, 1.400);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][21], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][21], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][21], 1);

    SpawnMenu[playerid][22] = CreatePlayerTextDraw(playerid, 438.000, 197.000, "Last Location");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][22], 0.219, 1.400);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][22], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][22], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][22], 1);

    SpawnMenu[playerid][23] = CreatePlayerTextDraw(playerid, 439.000, 210.000, "amda akan spawn terakhir anda spawn");
    PlayerTextDrawLetterSize(playerid, SpawnMenu[playerid][23], 0.139, 1.100);
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][23], 531.000, 0.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][23], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][23], 150);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][23], 1);

    SpawnMenu[playerid][24] = CreatePlayerTextDraw(playerid, 263.000, 174.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][24], 11.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][24], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][24], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][24], 1);

    SpawnMenu[playerid][25] = CreatePlayerTextDraw(playerid, 259.000, 183.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][25], 19.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][25], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][25], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][25], 1);

    SpawnMenu[playerid][26] = CreatePlayerTextDraw(playerid, 263.000, 241.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][26], 11.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][26], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][26], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][26], 1);

    SpawnMenu[playerid][27] = CreatePlayerTextDraw(playerid, 259.000, 250.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][27], 19.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][27], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][27], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][27], 1);

    SpawnMenu[playerid][28] = CreatePlayerTextDraw(playerid, 263.000, 306.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][28], 11.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][28], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][28], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][28], 1);

    SpawnMenu[playerid][29] = CreatePlayerTextDraw(playerid, 259.000, 315.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][29], 19.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][29], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][29], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][29], 1);

    SpawnMenu[playerid][30] = CreatePlayerTextDraw(playerid, 413.000, 202.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][30], 11.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][30], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][30], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][30], 1);

    SpawnMenu[playerid][31] = CreatePlayerTextDraw(playerid, 409.000, 211.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][31], 19.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][31], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][31], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][31], 1);

    SpawnMenu[playerid][32] = CreatePlayerTextDraw(playerid, 413.000, 268.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][32], 11.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][32], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][32], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][32], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][32], 1);

    SpawnMenu[playerid][33] = CreatePlayerTextDraw(playerid, 409.000, 277.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][33], 19.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][33], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][33], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][33], 1);

    SpawnMenu[playerid][34] = CreatePlayerTextDraw(playerid, 563.000, 230.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][34], 11.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][34], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][34], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][34], 1);

    SpawnMenu[playerid][35] = CreatePlayerTextDraw(playerid, 559.000, 239.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SpawnMenu[playerid][35], 19.000, 14.000);
    PlayerTextDrawAlignment(playerid, SpawnMenu[playerid][35], 1);
    PlayerTextDrawColor(playerid, SpawnMenu[playerid][35], -1);
    PlayerTextDrawSetShadow(playerid, SpawnMenu[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, SpawnMenu[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnMenu[playerid][35], 255);
    PlayerTextDrawFont(playerid, SpawnMenu[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, SpawnMenu[playerid][35], 1);
    return Y_HOOKS_CONTINUE_RETURN_1;
}
