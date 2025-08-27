#include <YSI\y_hooks>

CreateTDShortKey(playerid)
{
    PlayerTextdraws[playerid][textdraw_interaksi] [0] = CreatePlayerTextDraw(playerid, 270.000, 841.000, "Gambar teks baru");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [0], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [0], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [0], -1);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [0], 1);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [0], 1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [0], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [0], 1);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [0], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [1] = CreatePlayerTextDraw(playerid, 347.000, 405.000, "l");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [1], 0.300, 2.398);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [1], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [1], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [1], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [1], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [1], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [1], 1);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [1], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [2] = CreatePlayerTextDraw(playerid, 293.000, 412.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [2], 9.000, 9.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [2], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [2], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [2], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [2], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [2], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [2], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [2], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [3] = CreatePlayerTextDraw(playerid, 289.000, 407.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [3], 4.000, 5.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [3], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [3], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [3], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [3], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [3], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [3], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [3], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [4] = CreatePlayerTextDraw(playerid, 289.000, 421.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [4], 4.000, 5.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [4], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [4], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [4], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [4], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [4], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [4], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [4], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [5] = CreatePlayerTextDraw(playerid, 301.000, 421.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [5], 4.000, 5.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [5], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [5], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [5], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [5], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [5], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [5], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [5], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [6] = CreatePlayerTextDraw(playerid, 301.000, 407.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [6], 4.000, 5.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [6], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [6], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [6], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [6], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [6], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [6], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [6], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [7] = CreatePlayerTextDraw(playerid, 292.000, 408.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [7], 11.000, 17.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [7], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [7], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [7], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [7], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [7], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [7], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [7], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [8] = CreatePlayerTextDraw(playerid, 290.000, 410.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [8], 11.000, 13.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [8], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [8], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [8], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [8], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [8], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [8], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [8], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [9] = CreatePlayerTextDraw(playerid, 293.000, 410.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [9], 11.000, 13.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [9], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [9], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [9], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [9], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [9], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [9], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [9], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [10] = CreatePlayerTextDraw(playerid, 303.000, 405.000, "l");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [10], 0.170, 2.398);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [10], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [10], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [10], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [10], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [10], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [10], 1);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [10], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [11] = CreatePlayerTextDraw(playerid, 308.000, 407.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [11], 4.000, 5.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [11], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [11], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [11], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [11], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [11], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [11], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [11], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [12] = CreatePlayerTextDraw(playerid, 308.000, 421.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [12], 4.000, 5.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [12], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [12], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [12], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [12], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [12], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [12], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [12], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [13] = CreatePlayerTextDraw(playerid, 346.000, 421.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [13], 4.000, 5.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [13], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [13], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [13], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [13], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [13], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [13], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [13], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [14] = CreatePlayerTextDraw(playerid, 346.000, 407.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [14], 4.000, 5.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [14], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [14], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [14], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [14], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [14], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [14], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [14], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [15] = CreatePlayerTextDraw(playerid, 310.000, 408.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [15], 38.000, 17.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [15], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [15], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [15], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [15], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [15], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [15], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [15], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [16] = CreatePlayerTextDraw(playerid, 309.000, 409.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [16], 3.000, 15.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [16], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [16], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [16], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [16], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [16], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [16], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [16], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [17] = CreatePlayerTextDraw(playerid, 346.000, 409.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [17], 3.000, 15.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [17], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [17], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [17], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [17], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [17], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [17], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [17], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [18] = CreatePlayerTextDraw(playerid, 311.000, 410.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [18], 2.000, 3.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [18], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [18], 146839807);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [18], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [18], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [18], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [18], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [18], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [19] = CreatePlayerTextDraw(playerid, 292.000, 411.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [19], 10.000, 11.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [19], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [19], 146839807);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [19], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [19], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [19], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [19], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [19], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [20] = CreatePlayerTextDraw(playerid, 288.000, 408.000, "l");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [20], 1.949, 1.799);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [20], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [20], 355545599);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [20], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [20], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [20], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [20], 1);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [20], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [21] = CreatePlayerTextDraw(playerid, 288.000, 406.000, "l");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [21], 2.009, 2.098);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [21], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [21], 355545599);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [21], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [21], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [21], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [21], 1);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [21], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [22] = CreatePlayerTextDraw(playerid, 317.000, 413.000, "Garasi Umum");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [22], 0.079, 0.598);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [22], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [22], -1);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [22], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [22], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [22], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [22], 2);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [22], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [23] = CreatePlayerTextDraw(playerid, 290.000, 410.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [23], 1.000, 13.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [23], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [23], 371205631);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [23], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [23], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [23], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [23], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [23], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [24] = CreatePlayerTextDraw(playerid, 288.000, 405.000, "l");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [24], 2.138, 2.398);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [24], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [24], 355545444);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [24], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [24], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [24], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [24], 1);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [24], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [25] = CreatePlayerTextDraw(playerid, 286.000, 405.000, "l");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [25], 2.138, 2.398);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [25], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [25], 355545444);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [25], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [25], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [25], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [25], 1);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [25], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [26] = CreatePlayerTextDraw(playerid, 294.000, 413.000, "ALT");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [26], 0.079, 0.598);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [26], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [26], -1);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [26], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [26], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [26], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [26], 2);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [26], 1);

    PlayerTextdraws[playerid][textdraw_interaksi] [27] = CreatePlayerTextDraw(playerid, 294.000, 413.000, "ALT");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [27], 0.079, 0.598);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [27], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [27], -1);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [27], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [27], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [27], 150);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [27], 2);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_interaksi] [27], 1);

}

hook OnPlayerConnect(playerid)
{
    CreateTDShortKey(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    for(new x = 0; x < 28; x++)
    {
        PlayerTextDrawDestroy(playerid, PlayerTextdraws[playerid][textdraw_interaksi][x]);
    }
}

ShowKey(playerid, const text[])
{
    PlayerTextDrawSetString(playerid, PlayerTextdraws[playerid][textdraw_interaksi][22], text);
    for(new x = 0; x < 28; x++)
    {
        PlayerTextDrawShow(playerid, PlayerTextdraws[playerid][textdraw_interaksi][x]);
    }
    PlayerPlaySound(playerid, 1058, 0, 0, 0);
    return 1;
}

HideShortKey(playerid)
{
    for(new x = 0; x < 28; x++)
    {
        PlayerTextDrawHide(playerid, PlayerTextdraws[playerid][textdraw_interaksi][x]);
    }
    return 1;
}