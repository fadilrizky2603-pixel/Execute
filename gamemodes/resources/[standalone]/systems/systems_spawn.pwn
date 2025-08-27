#include <YSI\y_hooks>
new PlayerText: SpawnTD[MAX_PLAYERS][22];
new PlayerText: Character_Select[MAX_PLAYERS][18];

CreateSpawnTextdraws(playerid)
{
    Character_Select[playerid][0] = CreatePlayerTextDraw(playerid, 270.000, 185.000, "Gambar teks baru");
    PlayerTextDrawLetterSize(playerid, Character_Select[playerid][0], 0.000, 1.500);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][0], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][0], 150);
    PlayerTextDrawFont(playerid, Character_Select[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][0], 1);

    Character_Select[playerid][1] = CreatePlayerTextDraw(playerid, 173.000, 316.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][1], 280.000, 1.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][1], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][1], -156);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][1], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][1], 1);

    Character_Select[playerid][2] = CreatePlayerTextDraw(playerid, 272.000, 316.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][2], 81.000, 1.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][2], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][2], 502053119);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][2], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][2], 1);

    Character_Select[playerid][3] = CreatePlayerTextDraw(playerid, 217.000, 325.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][3], 96.000, 33.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][3], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][3], -156);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][3], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, Character_Select[playerid][3], 1);

    Character_Select[playerid][4] = CreatePlayerTextDraw(playerid, 217.000, 360.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][4], 96.000, 11.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][4], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][4], 502052964);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][4], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, Character_Select[playerid][4], 1);

    Character_Select[playerid][5] = CreatePlayerTextDraw(playerid, 316.000, 325.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][5], 96.000, 33.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][5], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][5], -156);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][5], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, Character_Select[playerid][5], 1);

    Character_Select[playerid][6] = CreatePlayerTextDraw(playerid, 316.000, 360.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][6], 96.000, 11.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][6], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][6], 502052964);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][6], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, Character_Select[playerid][6], 1);

    Character_Select[playerid][7] = CreatePlayerTextDraw(playerid, 278.000, 320.000, "nopixel:action");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][7], 38.000, 43.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][7], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][7], -141);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][7], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][7], 1);

    Character_Select[playerid][8] = CreatePlayerTextDraw(playerid, 377.000, 320.000, "nopixel:action");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][8], 38.000, 43.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][8], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][8], -141);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][8], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][8], 1);

    Character_Select[playerid][9] = CreatePlayerTextDraw(playerid, 267.000, 294.000, "CHARACTER SELECTOR");
    PlayerTextDrawLetterSize(playerid, Character_Select[playerid][9], 0.200, 1.098);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][9], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][9], 502053119);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][9], 150);
    PlayerTextDrawFont(playerid, Character_Select[playerid][9], 2);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][9], 1);

    Character_Select[playerid][10] = CreatePlayerTextDraw(playerid, 293.000, 304.000, "2/2 charaters");
    PlayerTextDrawLetterSize(playerid, Character_Select[playerid][10], 0.128, 0.699);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][10], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][10], 150);
    PlayerTextDrawFont(playerid, Character_Select[playerid][10], 2);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][10], 1);

    Character_Select[playerid][11] = CreatePlayerTextDraw(playerid, 257.000, 362.000, "Select");
    PlayerTextDrawLetterSize(playerid, Character_Select[playerid][11], 0.108, 0.699);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][11], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][11], 150);
    PlayerTextDrawFont(playerid, Character_Select[playerid][11], 2);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][11], 1);

    Character_Select[playerid][12] = CreatePlayerTextDraw(playerid, 355.000, 362.000, "Select");
    PlayerTextDrawLetterSize(playerid, Character_Select[playerid][12], 0.108, 0.699);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][12], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][12], 150);
    PlayerTextDrawFont(playerid, Character_Select[playerid][12], 2);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][12], 1);

    Character_Select[playerid][13] = CreatePlayerTextDraw(playerid, 320.000, 338.000, "Buat karakter");
    PlayerTextDrawLetterSize(playerid, Character_Select[playerid][13], 0.108, 0.799);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][13], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][13], 150);
    PlayerTextDrawFont(playerid, Character_Select[playerid][13], 2);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][13], 1);

    Character_Select[playerid][14] = CreatePlayerTextDraw(playerid, 221.000, 338.000, "MURO ESCOBAR");
    PlayerTextDrawLetterSize(playerid, Character_Select[playerid][14], 0.108, 0.799);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][14], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][14], 150);
    PlayerTextDrawFont(playerid, Character_Select[playerid][14], 2);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][14], 1);

    Character_Select[playerid][15] = CreatePlayerTextDraw(playerid, 300.000, 277.000, "HUD:radar_gangY");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][15], 15.000, 15.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][15], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][15], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][15], 1);

    Character_Select[playerid][16] = CreatePlayerTextDraw(playerid, 311.000, 277.000, "HUD:radar_gangN");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][16], 15.000, 15.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][16], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][16], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][16], 1);

    Character_Select[playerid][17] = CreatePlayerTextDraw(playerid, 306.000, 279.000, "HUD:radar_gangB");
    PlayerTextDrawTextSize(playerid, Character_Select[playerid][17], 15.000, 15.000);
    PlayerTextDrawAlignment(playerid, Character_Select[playerid][17], 1);
    PlayerTextDrawColor(playerid, Character_Select[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, Character_Select[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, Character_Select[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, Character_Select[playerid][17], 255);
    PlayerTextDrawFont(playerid, Character_Select[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, Character_Select[playerid][17], 1);

    SpawnTD[playerid][0] = CreatePlayerTextDraw(playerid, 270.000, 160.000, "Gambar teks baru");
    PlayerTextDrawLetterSize(playerid, SpawnTD[playerid][0], 0.000, 1.500);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][0], 1);

    SpawnTD[playerid][1] = CreatePlayerTextDraw(playerid, 260.000, 146.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][1], 1.000, 180.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][1], 40369919);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][1], 1);

    SpawnTD[playerid][2] = CreatePlayerTextDraw(playerid, 260.000, 330.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][2], 115.000, 21.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][2], 40369764);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnTD[playerid][2], 1);

    SpawnTD[playerid][3] = CreatePlayerTextDraw(playerid, 261.000, 145.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][3], 114.000, 35.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][3], 175);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnTD[playerid][3], 1);

    SpawnTD[playerid][4] = CreatePlayerTextDraw(playerid, 261.000, 180.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][4], 114.000, 35.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][4], 175);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnTD[playerid][4], 1);

    SpawnTD[playerid][5] = CreatePlayerTextDraw(playerid, 261.000, 215.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][5], 114.000, 37.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][5], 175);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnTD[playerid][5], 1);

    SpawnTD[playerid][6] = CreatePlayerTextDraw(playerid, 261.000, 252.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][6], 114.000, 38.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][6], 175);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnTD[playerid][6], 1);

    SpawnTD[playerid][7] = CreatePlayerTextDraw(playerid, 261.000, 290.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][7], 114.000, 36.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][7], 175);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][7], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, SpawnTD[playerid][7], 1);

    SpawnTD[playerid][8] = CreatePlayerTextDraw(playerid, 331.000, 290.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][8], 43.000, 1.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][8], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][8], 1);

    SpawnTD[playerid][9] = CreatePlayerTextDraw(playerid, 260.000, 215.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][9], 43.000, 1.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][9], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][9], 1);

    SpawnTD[playerid][10] = CreatePlayerTextDraw(playerid, 317.000, 210.000, "Property");
    PlayerTextDrawLetterSize(playerid, SpawnTD[playerid][10], 0.149, 0.999);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][10], 2);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][10], 1);

    SpawnTD[playerid][11] = CreatePlayerTextDraw(playerid, 331.000, 215.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][11], 43.000, 1.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][11], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][11], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][11], 1);

    SpawnTD[playerid][12] = CreatePlayerTextDraw(playerid, 260.000, 290.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][12], 43.000, 1.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][12], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][12], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][12], 1);

    SpawnTD[playerid][13] = CreatePlayerTextDraw(playerid, 317.000, 285.000, "Faction");
    PlayerTextDrawLetterSize(playerid, SpawnTD[playerid][13], 0.149, 0.999);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][13], 2);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][13], 150);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][13], 1);

    SpawnTD[playerid][14] = CreatePlayerTextDraw(playerid, 317.000, 156.000, "Bandara");
    PlayerTextDrawLetterSize(playerid, SpawnTD[playerid][14], 0.179, 1.299);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][14], 2);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][14], 1);

    SpawnTD[playerid][15] = CreatePlayerTextDraw(playerid, 317.000, 185.000, "Terminal");
    PlayerTextDrawLetterSize(playerid, SpawnTD[playerid][15], 0.179, 1.299);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][15], 2);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][15], 1);

    SpawnTD[playerid][16] = CreatePlayerTextDraw(playerid, 317.000, 231.000, "Rusun");
    PlayerTextDrawLetterSize(playerid, SpawnTD[playerid][16], 0.179, 1.299);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][16], 2);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][16], 150);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][16], 1);

    SpawnTD[playerid][17] = CreatePlayerTextDraw(playerid, 317.000, 260.000, "Rumah");
    PlayerTextDrawLetterSize(playerid, SpawnTD[playerid][17], 0.179, 1.299);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][17], 2);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][17], 1);

    SpawnTD[playerid][18] = CreatePlayerTextDraw(playerid, 317.000, 303.000, "Faction");
    PlayerTextDrawLetterSize(playerid, SpawnTD[playerid][18], 0.179, 1.299);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][18], 2);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][18], 150);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][18], 1);

    SpawnTD[playerid][19] = CreatePlayerTextDraw(playerid, 317.000, 334.000, "Last Location");
    PlayerTextDrawLetterSize(playerid, SpawnTD[playerid][19], 0.179, 1.299);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][19], 2);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][19], 1);

    SpawnTD[playerid][20] = CreatePlayerTextDraw(playerid, 302.000, 109.000, "DCRP:logo");
    PlayerTextDrawTextSize(playerid, SpawnTD[playerid][20], 33.000, 35.000);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][20], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][20], 255);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][20], 1);

    SpawnTD[playerid][21] = CreatePlayerTextDraw(playerid, 307.000, 115.000, "_");
    PlayerTextDrawLetterSize(playerid, SpawnTD[playerid][21], 0.388, 1.500);
    PlayerTextDrawAlignment(playerid, SpawnTD[playerid][21], 1);
    PlayerTextDrawColor(playerid, SpawnTD[playerid][21], -260013825);
    PlayerTextDrawSetShadow(playerid, SpawnTD[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, SpawnTD[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, SpawnTD[playerid][21], 150);
    PlayerTextDrawFont(playerid, SpawnTD[playerid][21], 2);
    PlayerTextDrawSetProportional(playerid, SpawnTD[playerid][21], 0);

    
}

hook OnPlayerConnect(playerid)
{
    CreateSpawnTextdraws(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    for(new x = 0; x < 22; x++)
    {
        PlayerTextDrawDestroy(playerid, SpawnTD[playerid][x]);
    }
    return 1;
}

ShowSpawnTextdraws(playerid)
{
    for(new x = 0; x < 22; x++)
    {
        PlayerTextDrawShow(playerid, SpawnTD[playerid][x]);
    }
    SelectTextDraw(playerid, 0xC0C0C0FF);
    return 1;
}

HideSpawnTextdraws(playerid)
{
    for(new x = 0; x < 22; x++)
    {
        PlayerTextDrawHide(playerid, SpawnTD[playerid][x]);
    }
    CancelSelectTextDraw(playerid);
    return 1;
}

hook OnClickDynPlayerTextDraw(playerid, PlayerText:textid)
{
    if(textid == Character_Select[playerid][4]) //SPAWN
    {
        SpawnChar(playerid, 0);
    }
    if(textid == Character_Select[playerid][6]) //SPAWN
    {
        SpawnChar(playerid, 1);
    }
    if(textid == Character_Select[playerid][3]) // KIRI
    {
        if(PlayerChar[playerid][0][0] != EOS) SetPlayerSkin(playerid, CharSkin[playerid][0]);
        else SetPlayerSkin(playerid, RandomEx(1, 255));
        ApplyAnimation(playerid,"SWORD","sword_block",50.0 ,0,1,0,1,1);
    }
    if(textid == Character_Select[playerid][5]) // KANAN
    {
        if(PlayerChar[playerid][1][0] != EOS) SetPlayerSkin(playerid, CharSkin[playerid][1]);
        else SetPlayerSkin(playerid, RandomEx(1, 255));
        ApplyAnimation(playerid,"SWORD","sword_block",50.0 ,0,1,0,1,1);
    }

    if(textid == SpawnTD[playerid][3]) // Bandara
    {
        new rand = random(sizeof(SpawnBandara));
        AccountData[playerid][pPosX] = SpawnBandara[rand][0];
        AccountData[playerid][pPosY] = SpawnBandara[rand][1];
        AccountData[playerid][pPosZ] = SpawnBandara[rand][2];
        AccountData[playerid][pPosA] = SpawnBandara[rand][3];
        SetPlayerInteriorEx(playerid, 0);
        SetPlayerVirtualWorldEx(playerid, 0);

        SetPlayerPositionEx(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ], AccountData[playerid][pPosA], 3000);
        HideSpawnTextdraws(playerid);
        ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda berhasil spawn di Bandara.");
        PlayerPlaySound(playerid, 1054, 0, 0, 0);
    }
    if(textid == SpawnTD[playerid][4]) // pelabuhan - terminal
    {
        new rand = random(sizeof(SpawnPelabuhan));
        AccountData[playerid][pPosX] = SpawnPelabuhan[rand][0];
        AccountData[playerid][pPosY] = SpawnPelabuhan[rand][1];
        AccountData[playerid][pPosZ] = SpawnPelabuhan[rand][2];
        AccountData[playerid][pPosA] = SpawnPelabuhan[rand][3];
        SetPlayerInteriorEx(playerid, 0);
        SetPlayerVirtualWorldEx(playerid, 0);

        SetPlayerPositionEx(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ], AccountData[playerid][pPosA], 3000);
        HideSpawnTextdraws(playerid);
        ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda berhasil spawn di Pelabuhan Merak.");
        PlayerPlaySound(playerid, 1054, 0, 0, 0);
    }
    if(textid == SpawnTD[playerid][5]) //rusun
    {
        if(AccountData[playerid][pOwnedRusun] == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memiliki rusun!");
        foreach(new rsid : Rusun)
        {
            if(RusunData[rsid][rusunOwnerID] == AccountData[playerid][pID])
            {
                AccountData[playerid][pPosX] =  RusunData[rsid][rusunExtPos][0];
                AccountData[playerid][pPosY] =  RusunData[rsid][rusunExtPos][1];
                AccountData[playerid][pPosZ] =  RusunData[rsid][rusunExtPos][2];
                AccountData[playerid][pPosA] =  RusunData[rsid][rusunExtPos][3];
                SetPlayerInteriorEx(playerid, 0);
                SetPlayerVirtualWorldEx(playerid, 0);

                SetPlayerPositionEx(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ], AccountData[playerid][pPosA], 3000);
                HideSpawnTextdraws(playerid);
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda berhasil spawn di Rusun Pribadi.");
            }
        }
    }
    if(textid == SpawnTD[playerid][7]) //FACTION
	{
		if(AccountData[playerid][pFaction] == 0) 
		{
			ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum bergabung di organisasi manapun");
		}
		else
		{
			HideSpawnTextdraws(playerid);
			if(AccountData[playerid][pFaction] == 1)
			{
				SetPlayerPositionEx(playerid, 924.6787,-1728.6313,13.5469+0.2, 98.5410);
				
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0);
			}
			if(AccountData[playerid][pFaction] == 2)
			{
				SetPlayerPositionEx(playerid, 1143.1603,-2035.8755,69.0249+0.2, 93.7807);
				
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0);
			}
			if(AccountData[playerid][pFaction] == 3)
			{
				SetPlayerPositionEx(playerid, 1313.9851,744.4907,10.8784+0.1, 270.2826);
				
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 255);
			}
			if(AccountData[playerid][pFaction] == 4)
			{
				SetPlayerPositionEx(playerid, 1493.6930,-2174.7002,13.5650+0.2, 273.3011);
				
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0);
			}
			if(AccountData[playerid][pFaction] == 5)
			{
				SetPlayerPositionEx(playerid, -58.0587,1008.4011,23.6493+0.2,208.1082);

				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0);
			}
			if(AccountData[playerid][pFaction] == 6)
			{
				SetPlayerPositionEx(playerid, 2863.9470,-1991.5126,11.1016+0.2,97.2547);

				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0);
			}
			if(AccountData[playerid][pFaction] == 7)
			{
				SetPlayerPositionEx(playerid, -1952.1932,296.0997,35.4687+0.2,94.9698);

				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0);
			}
		}
	}
    if(textid == SpawnTD[playerid][6]) // rumah pribadi
    {
		foreach(new hid : House) 
		{
			if(AccountData[playerid][pOwnedHouse] == -1 && AccountData[playerid][pFriendHouseID] == -1)
			{
				ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki rumah!");
                ShowSpawnTextdraws(playerid);
				return 1;
			}
			else if(AccountData[playerid][pOwnedHouse] != -1 && AccountData[playerid][pFriendHouseID] == -1)
			{
				if(HouseData[hid][hsOwnerID] == AccountData[playerid][pID] && !strcmp(HouseData[hid][hsOwner], AccountData[playerid][pName], true))
				{
					AccountData[playerid][pPosX] = HouseData[hid][hsExtPos][0];
					AccountData[playerid][pPosY] = HouseData[hid][hsExtPos][1];
					AccountData[playerid][pPosZ] = HouseData[hid][hsExtPos][2];
					AccountData[playerid][pPosA] = HouseData[hid][hsExtPos][3];
					SetPlayerInteriorEx(playerid, 0);
					SetPlayerVirtualWorldEx(playerid, 0);

					SetPlayerPositionEx(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ], AccountData[playerid][pPosA], 6000);
                    HideSpawnTextdraws(playerid);
                    ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda berhasil spawn di Rumah Pribadi.");
				}
			}
			else if(AccountData[playerid][pOwnedHouse] == -1 && AccountData[playerid][pFriendHouseID] == hid)
			{
				AccountData[playerid][pPosX] = HouseData[AccountData[playerid][pFriendHouseID]][hsExtPos][0];
				AccountData[playerid][pPosY] = HouseData[AccountData[playerid][pFriendHouseID]][hsExtPos][1];
				AccountData[playerid][pPosZ] = HouseData[AccountData[playerid][pFriendHouseID]][hsExtPos][2];
				AccountData[playerid][pPosA] = HouseData[AccountData[playerid][pFriendHouseID]][hsExtPos][3];
				SetPlayerInteriorEx(playerid, 0);
				SetPlayerVirtualWorldEx(playerid, 0);

				SetPlayerPositionEx(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ], AccountData[playerid][pPosA], 6000);
                HideSpawnTextdraws(playerid);
                ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil spawn di Rumah teman anda.");
			}
			else if(AccountData[playerid][pOwnedHouse] != -1 && AccountData[playerid][pFriendHouseID] != -1)
			{
				Dialog_Show(playerid, HouseSpawn_Option, DIALOG_STYLE_TABLIST, ""PINK1"DCRP"WHITE"- House Opsi", "Rumah Pribadi\n"GRAY"Rumah Teman", "Pilih", "Batal");
			}
		}
    }
    if(textid == SpawnTD[playerid][2]) // last spawn
    {
        SetPlayerInteriorEx(playerid, AccountData[playerid][pInt]);
        SetPlayerVirtualWorldEx(playerid, AccountData[playerid][pWorld]);

        SetPlayerPositionEx(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ], AccountData[playerid][pPosA], 3000);
        HideSpawnTextdraws(playerid);
        ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda berhasil spawn di lokasi terakhir.");
    }
    return 1;
}

Dialog:HouseSpawn_Option(playerid, response, listitem, inputtext[])
{
	if(!response)
	{
		ShowSpawnTextdraws(playerid);
		return 1;
	}
	if(response)
	{
		switch(listitem)
		{
			case 0: // Pribadi
			{
				foreach(new i : House)
				{
					if(HouseData[i][hsOwnerID] == AccountData[playerid][pID] && !strcmp(HouseData[i][hsOwner], AccountData[playerid][pName], true))
					{
						AccountData[playerid][pPosX] = HouseData[i][hsExtPos][0];
						AccountData[playerid][pPosY] = HouseData[i][hsExtPos][1];
						AccountData[playerid][pPosZ] = HouseData[i][hsExtPos][2];
						AccountData[playerid][pPosA] = HouseData[i][hsExtPos][3];
						SetPlayerInteriorEx(playerid, 0);
						SetPlayerVirtualWorldEx(playerid, 0);

						SetPlayerPositionEx(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ], AccountData[playerid][pPosA], 6000);
						HideSpawnTextdraws(playerid);
						ShowTDN(playerid, NOTIFICATION_SUKSES, "Anda berhasil spawn di Rumah Pribadi.");
					}
				}
			}
			case 1: // Numpang
			{
				foreach(new i : House)
				{
					if(AccountData[playerid][pFriendHouseID] == i)
					{
						AccountData[playerid][pPosX] = HouseData[i][hsExtPos][0];
						AccountData[playerid][pPosY] = HouseData[i][hsExtPos][1];
						AccountData[playerid][pPosZ] = HouseData[i][hsExtPos][2];
						AccountData[playerid][pPosA] = HouseData[i][hsExtPos][3];
						SetPlayerInteriorEx(playerid, 0);
						SetPlayerVirtualWorldEx(playerid, 0);

						SetPlayerPositionEx(playerid, AccountData[playerid][pPosX], AccountData[playerid][pPosY], AccountData[playerid][pPosZ], AccountData[playerid][pPosA], 6000);
						HideSpawnTextdraws(playerid);
						ShowTDN(playerid, NOTIFICATION_SUKSES, "Berhasil spawn di Ruman teman anda.");
					}
				}
			}
		}
	}
	return 1;
}