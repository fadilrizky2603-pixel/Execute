#include <YSI_Coding/y_hooks>

hook OnPlayerConnect(playerid) {
    GarasiTD[playerid][0] = CreatePlayerTextDraw(playerid, 181.000, -209.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][0], 711.000, 876.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][0], 728983746);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][0], 1);

	GarasiTD[playerid][1] = CreatePlayerTextDraw(playerid, 450.000, 102.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][1], 164.000, 260.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][1], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][1], 1);

	GarasiTD[playerid][2] = CreatePlayerTextDraw(playerid, 444.000, 111.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][2], 176.000, 241.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][2], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][2], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][2], 1);

	GarasiTD[playerid][3] = CreatePlayerTextDraw(playerid, 440.000, 97.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][3], 23.000, 30.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][3], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][3], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][3], 1);

	GarasiTD[playerid][4] = CreatePlayerTextDraw(playerid, 601.000, 97.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][4], 23.000, 30.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][4], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][4], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][4], 1);

	GarasiTD[playerid][5] = CreatePlayerTextDraw(playerid, 601.000, 336.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][5], 23.000, 31.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][5], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][5], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][5], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][5], 1);

	GarasiTD[playerid][6] = CreatePlayerTextDraw(playerid, 440.000, 336.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][6], 23.000, 31.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][6], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][6], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][6], 1);

	GarasiTD[playerid][7] = CreatePlayerTextDraw(playerid, 457.000, 185.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][7], 1.000, 155.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][7], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][7], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][7], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][7], 1);

	GarasiTD[playerid][8] = CreatePlayerTextDraw(playerid, 457.000, 184.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][8], 6.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][8], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][8], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][8], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][8], 1);

	GarasiTD[playerid][9] = CreatePlayerTextDraw(playerid, 464.000, 185.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][9], -1.000, -9.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][9], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][9], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][9], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][9], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][9], 1);

	GarasiTD[playerid][10] = CreatePlayerTextDraw(playerid, 464.000, 176.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][10], 137.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][10], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][10], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][10], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][10], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][10], 1);

	GarasiTD[playerid][11] = CreatePlayerTextDraw(playerid, 602.000, 185.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][11], -1.000, -9.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][11], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][11], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][11], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][11], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][11], 1);

	GarasiTD[playerid][12] = CreatePlayerTextDraw(playerid, 601.000, 184.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][12], 6.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][12], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][12], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][12], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][12], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][12], 1);

	GarasiTD[playerid][13] = CreatePlayerTextDraw(playerid, 606.000, 185.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][13], 1.000, 155.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][13], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][13], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][13], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][13], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][13], 1);

	GarasiTD[playerid][14] = CreatePlayerTextDraw(playerid, 457.000, 340.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][14], 6.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][14], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][14], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][14], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][14], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][14], 1);

	GarasiTD[playerid][15] = CreatePlayerTextDraw(playerid, 602.000, 349.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][15], -1.000, -9.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][15], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][15], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][15], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][15], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][15], 1);

	GarasiTD[playerid][16] = CreatePlayerTextDraw(playerid, 464.000, 348.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][16], 137.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][16], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][16], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][16], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][16], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][16], 1);

	GarasiTD[playerid][17] = CreatePlayerTextDraw(playerid, 601.000, 340.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][17], 6.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][17], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][17], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][17], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][17], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][17], 1);

	GarasiTD[playerid][18] = CreatePlayerTextDraw(playerid, 464.000, 349.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][18], -1.000, -9.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][18], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][18], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][18], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][18], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][18], 1);

	GarasiTD[playerid][19] = CreatePlayerTextDraw(playerid, 454.000, 109.000, "Garasi Local Prime....");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][19], 0.150, 0.898);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][19], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][19], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][19], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][19], 1);

	GarasiTD[playerid][20] = CreatePlayerTextDraw(playerid, 454.000, 120.000, "Garasi");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][20], 0.289, 2.198);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][20], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][20], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][20], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][20], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][20], 1);

	GarasiTD[playerid][21] = CreatePlayerTextDraw(playerid, 455.000, 141.000, "Ambil Kendaran anda di garasi ini.");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][21], 0.119, 0.799);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][21], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][21], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][21], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][21], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][21], 1);

	GarasiTD[playerid][22] = CreatePlayerTextDraw(playerid, 574.000, 126.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][22], 30.000, 13.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][22], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][22], 341791743);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][22], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][22], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][22], 1);
	PlayerTextDrawSetSelectable(playerid, GarasiTD[playerid][22], 1);

	GarasiTD[playerid][23] = CreatePlayerTextDraw(playerid, 589.000, 129.000, "Exit");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][23], 0.119, 0.799);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][23], 2);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][23], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][23], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][23], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][23], 1);

	GarasiTD[playerid][24] = CreatePlayerTextDraw(playerid, 467.000, 186.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][24], 56.000, 53.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][24], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][24], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][24], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][24], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][24], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][24], 1);
	PlayerTextDrawSetSelectable(playerid, GarasiTD[playerid][24], 1);

	GarasiTD[playerid][25] = CreatePlayerTextDraw(playerid, 541.000, 186.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][25], 56.000, 53.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][25], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][25], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][25], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][25], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][25], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][25], 1);
	PlayerTextDrawSetSelectable(playerid, GarasiTD[playerid][25], 1);

	GarasiTD[playerid][26] = CreatePlayerTextDraw(playerid, 468.000, 266.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][26], 56.000, 53.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][26], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][26], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][26], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][26], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][26], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][26], 1);
	PlayerTextDrawSetSelectable(playerid, GarasiTD[playerid][26], 1);

	GarasiTD[playerid][27] = CreatePlayerTextDraw(playerid, 541.000, 266.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][27], 56.000, 53.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][27], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][27], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][27], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][27], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][27], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][27], 1);
	PlayerTextDrawSetSelectable(playerid, GarasiTD[playerid][27], 1);

	GarasiTD[playerid][28] = CreatePlayerTextDraw(playerid, 468.000, 261.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][28], 56.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][28], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][28], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][28], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][28], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][28], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][28], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][28], 1);

	GarasiTD[playerid][29] = CreatePlayerTextDraw(playerid, 541.000, 261.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][29], 56.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][29], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][29], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][29], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][29], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][29], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][29], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][29], 1);

	GarasiTD[playerid][30] = CreatePlayerTextDraw(playerid, 469.000, 342.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][30], 56.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][30], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][30], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][30], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][30], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][30], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][30], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][30], 1);

	GarasiTD[playerid][31] = CreatePlayerTextDraw(playerid, 541.000, 342.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][31], 56.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][31], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][31], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][31], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][31], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][31], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][31], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][31], 1);

	GarasiTD[playerid][32] = CreatePlayerTextDraw(playerid, 467.000, 241.000, "Supra MK4");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][32], 0.189, 1.199);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][32], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][32], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][32], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][32], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][32], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][32], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][32], 1);

	GarasiTD[playerid][33] = CreatePlayerTextDraw(playerid, 467.000, 252.000, "Stored");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][33], 0.150, 0.898);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][33], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][33], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][33], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][33], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][33], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][33], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][33], 1);

	GarasiTD[playerid][34] = CreatePlayerTextDraw(playerid, 541.000, 241.000, "RX7");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][34], 0.189, 1.199);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][34], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][34], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][34], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][34], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][34], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][34], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][34], 1);

	GarasiTD[playerid][35] = CreatePlayerTextDraw(playerid, 541.000, 252.000, "Stored");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][35], 0.150, 0.898);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][35], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][35], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][35], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][35], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][35], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][35], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][35], 1);

	GarasiTD[playerid][36] = CreatePlayerTextDraw(playerid, 468.000, 320.000, "BMW E46");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][36], 0.189, 1.199);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][36], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][36], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][36], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][36], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][36], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][36], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][36], 1);

	GarasiTD[playerid][37] = CreatePlayerTextDraw(playerid, 468.000, 331.000, "Stored");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][37], 0.150, 0.898);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][37], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][37], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][37], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][37], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][37], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][37], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][37], 1);

	GarasiTD[playerid][38] = CreatePlayerTextDraw(playerid, 541.000, 320.000, "GTR 34");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][38], 0.189, 1.199);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][38], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][38], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][38], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][38], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][38], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][38], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][38], 1);

	GarasiTD[playerid][39] = CreatePlayerTextDraw(playerid, 541.000, 331.000, "Stored");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][39], 0.150, 0.898);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][39], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][39], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][39], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][39], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][39], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][39], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][39], 1);

	GarasiTD[playerid][40] = CreatePlayerTextDraw(playerid, 456.000, 221.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][40], 79.000, 19.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][40], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][40], 728983746);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][40], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][40], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][40], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][40], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][40], 1);

	GarasiTD[playerid][41] = CreatePlayerTextDraw(playerid, 530.000, 221.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][41], 79.000, 19.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][41], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][41], 728983746);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][41], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][41], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][41], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][41], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][41], 1);

	GarasiTD[playerid][42] = CreatePlayerTextDraw(playerid, 456.000, 301.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][42], 79.000, 19.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][42], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][42], 728983746);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][42], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][42], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][42], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][42], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][42], 1);

	GarasiTD[playerid][43] = CreatePlayerTextDraw(playerid, 530.000, 301.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][43], 79.000, 19.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][43], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][43], 728983746);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][43], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][43], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][43], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][43], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][43], 1);

	GarasiTD[playerid][44] = CreatePlayerTextDraw(playerid, 461.000, 184.000, "_");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][44], 71.000, 76.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][44], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][44], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][44], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][44], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][44], 0);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][44], 5);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][44], 0);
	PlayerTextDrawSetPreviewModel(playerid, GarasiTD[playerid][44], 558);
	PlayerTextDrawSetPreviewRot(playerid, GarasiTD[playerid][44], -7.000, -2.000, -43.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, GarasiTD[playerid][44], 0, 0);

	GarasiTD[playerid][45] = CreatePlayerTextDraw(playerid, 470.000, 191.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][45], 9.000, 2.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][45], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][45], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][45], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][45], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][45], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][45], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][45], 1);

	GarasiTD[playerid][46] = CreatePlayerTextDraw(playerid, 469.000, 191.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][46], 2.000, 10.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][46], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][46], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][46], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][46], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][46], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][46], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][46], 1);

	GarasiTD[playerid][47] = CreatePlayerTextDraw(playerid, 536.000, 184.000, "_");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][47], 71.000, 76.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][47], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][47], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][47], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][47], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][47], 0);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][47], 5);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][47], 0);
	PlayerTextDrawSetPreviewModel(playerid, GarasiTD[playerid][47], 451);
	PlayerTextDrawSetPreviewRot(playerid, GarasiTD[playerid][47], -7.000, -2.000, -43.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, GarasiTD[playerid][47], 0, 0);

	GarasiTD[playerid][48] = CreatePlayerTextDraw(playerid, 545.000, 191.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][48], 9.000, 2.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][48], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][48], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][48], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][48], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][48], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][48], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][48], 1);

	GarasiTD[playerid][49] = CreatePlayerTextDraw(playerid, 544.000, 191.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][49], 2.000, 10.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][49], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][49], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][49], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][49], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][49], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][49], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][49], 1);

	GarasiTD[playerid][50] = CreatePlayerTextDraw(playerid, 462.000, 264.000, "_");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][50], 71.000, 76.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][50], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][50], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][50], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][50], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][50], 0);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][50], 5);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][50], 0);
	PlayerTextDrawSetPreviewModel(playerid, GarasiTD[playerid][50], 560);
	PlayerTextDrawSetPreviewRot(playerid, GarasiTD[playerid][50], -7.000, -2.000, -43.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, GarasiTD[playerid][50], 0, 0);

	GarasiTD[playerid][51] = CreatePlayerTextDraw(playerid, 471.000, 271.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][51], 9.000, 2.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][51], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][51], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][51], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][51], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][51], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][51], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][51], 1);

	GarasiTD[playerid][52] = CreatePlayerTextDraw(playerid, 470.000, 271.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][52], 2.000, 10.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][52], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][52], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][52], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][52], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][52], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][52], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][52], 1);

	GarasiTD[playerid][53] = CreatePlayerTextDraw(playerid, 536.000, 264.000, "_");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][53], 71.000, 76.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][53], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][53], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][53], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][53], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][53], 0);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][53], 5);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][53], 0);
	PlayerTextDrawSetPreviewModel(playerid, GarasiTD[playerid][53], 562);
	PlayerTextDrawSetPreviewRot(playerid, GarasiTD[playerid][53], -7.000, -2.000, -43.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, GarasiTD[playerid][53], 0, 0);

	GarasiTD[playerid][54] = CreatePlayerTextDraw(playerid, 545.000, 271.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][54], 9.000, 2.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][54], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][54], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][54], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][54], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][54], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][54], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][54], 1);

	GarasiTD[playerid][55] = CreatePlayerTextDraw(playerid, 545.000, 271.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][55], 2.000, 10.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][55], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][55], 341791693);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][55], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][55], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][55], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][55], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][55], 1);

	GarasiTD[playerid][56] = CreatePlayerTextDraw(playerid, 300.000, 102.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][56], 118.000, 260.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][56], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][56], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][56], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][56], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][56], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][56], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][56], 1);

	GarasiTD[playerid][57] = CreatePlayerTextDraw(playerid, 293.000, 111.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][57], 132.000, 241.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][57], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][57], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][57], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][57], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][57], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][57], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][57], 1);

	GarasiTD[playerid][58] = CreatePlayerTextDraw(playerid, 289.000, 97.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][58], 23.000, 30.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][58], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][58], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][58], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][58], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][58], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][58], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][58], 1);

	GarasiTD[playerid][59] = CreatePlayerTextDraw(playerid, 406.000, 97.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][59], 23.000, 30.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][59], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][59], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][59], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][59], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][59], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][59], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][59], 1);

	GarasiTD[playerid][60] = CreatePlayerTextDraw(playerid, 406.000, 337.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][60], 23.000, 30.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][60], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][60], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][60], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][60], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][60], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][60], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][60], 1);

	GarasiTD[playerid][61] = CreatePlayerTextDraw(playerid, 289.000, 337.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][61], 23.000, 30.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][61], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][61], 471869439);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][61], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][61], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][61], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][61], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][61], 1);

	GarasiTD[playerid][62] = CreatePlayerTextDraw(playerid, 305.000, 153.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][62], -1.000, 196.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][62], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][62], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][62], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][62], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][62], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][62], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][62], 1);

	GarasiTD[playerid][63] = CreatePlayerTextDraw(playerid, 305.000, 153.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][63], 108.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][63], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][63], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][63], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][63], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][63], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][63], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][63], 1);

	GarasiTD[playerid][64] = CreatePlayerTextDraw(playerid, 414.000, 153.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][64], -1.000, 196.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][64], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][64], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][64], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][64], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][64], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][64], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][64], 1);

	GarasiTD[playerid][65] = CreatePlayerTextDraw(playerid, 305.000, 348.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][65], 108.000, 1.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][65], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][65], 1195986943);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][65], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][65], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][65], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][65], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][65], 1);

	GarasiTD[playerid][66] = CreatePlayerTextDraw(playerid, 303.000, 109.000, "Pilih Kendaran");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][66], 0.150, 0.898);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][66], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][66], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][66], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][66], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][66], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][66], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][66], 1);

	GarasiTD[playerid][67] = CreatePlayerTextDraw(playerid, 303.000, 120.000, "Details");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][67], 0.289, 2.198);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][67], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][67], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][67], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][67], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][67], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][67], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][67], 1);

	GarasiTD[playerid][68] = CreatePlayerTextDraw(playerid, 307.000, 157.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][68], 104.000, 18.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][68], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][68], 341791661);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][68], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][68], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][68], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][68], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][68], 1);
	PlayerTextDrawSetSelectable(playerid, GarasiTD[playerid][68], 1);

	GarasiTD[playerid][69] = CreatePlayerTextDraw(playerid, 360.000, 161.000, "TAKE OUT");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][69], 0.150, 0.898);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][69], 2);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][69], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][69], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][69], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][69], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][69], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][69], 1);

	GarasiTD[playerid][70] = CreatePlayerTextDraw(playerid, 307.000, 179.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, GarasiTD[playerid][70], 104.000, 22.000);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][70], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][70], 1970765055);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][70], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][70], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][70], 255);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][70], 4);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][70], 1);

	GarasiTD[playerid][71] = CreatePlayerTextDraw(playerid, 309.000, 180.000, "STATUS VEHICLE");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][71], 0.169, 0.899);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][71], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][71], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][71], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][71], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][71], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][71], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][71], 1);

	GarasiTD[playerid][72] = CreatePlayerTextDraw(playerid, 309.000, 190.000, "Stored - Fuel : 100 - Body : 1000");
	PlayerTextDrawLetterSize(playerid, GarasiTD[playerid][72], 0.139, 0.799);
	PlayerTextDrawAlignment(playerid, GarasiTD[playerid][72], 1);
	PlayerTextDrawColor(playerid, GarasiTD[playerid][72], -1);
	PlayerTextDrawSetShadow(playerid, GarasiTD[playerid][72], 0);
	PlayerTextDrawSetOutline(playerid, GarasiTD[playerid][72], 0);
	PlayerTextDrawBackgroundColor(playerid, GarasiTD[playerid][72], 150);
	PlayerTextDrawFont(playerid, GarasiTD[playerid][72], 1);
	PlayerTextDrawSetProportional(playerid, GarasiTD[playerid][72], 1);
	return Y_HOOKS_CONTINUE_RETURN_1;
}