//Info textdraw
new Text:StressPurple[1]; 
new Text: RobberyGlobalTD[5];
new Text: gServerTextdraws[1];
new Text: DCRPLOGO[1];
//new PlayerText: DCRPLOGO[MAX_PLAYERS][1];
new Text: ATRP_Warning[10];
new Text: gServerMessage[7];

new PlayerText: RobberyTextTD[MAX_PLAYERS][1];
new PlayerText: KerjaInfo[MAX_PLAYERS][31];
new PlayerText: SusuInfo[MAX_PLAYERS][31];
new PlayerText: ATRP_Injured[MAX_PLAYERS][1];
new PlayerText: DeathTD[MAX_PLAYERS][20];
new PlayerText: ProgressBar[MAX_PLAYERS][5];
new PlayerText: P_MENUCLOTHES[MAX_PLAYERS][14];
new PlayerText: P_CLOTHESSELECT[MAX_PLAYERS][16];

new PlayerText: JadenFish[MAX_PLAYERS][59];

new PlayerText: VR_BANNEDTD[MAX_PLAYERS][21];
new PlayerText: BusWait[MAX_PLAYERS][1];
new PlayerText: VR_KARUNG[MAX_PLAYERS][1];
new PlayerText: ktpTextdraws[MAX_PLAYERS][26];
new PlayerText: KTAtextdraws[MAX_PLAYERS][41];
new PlayerText: ATMTD[MAX_PLAYERS][87];
new PlayerText: SpedoJaden[MAX_PLAYERS][33];
new PlayerText: FPStextdraws[MAX_PLAYERS][1];
new PlayerText: JadenHbe[MAX_PLAYERS][30];
new PlayerText: HbeTengah[MAX_PLAYERS][46];
new PlayerText: ATRP_Gym[MAX_PLAYERS][3];
new PlayerText: Garage_TD[MAX_PLAYERS][31];
new PlayerText: TollTD[MAX_PLAYERS][24];
new PlayerText: PomTD[MAX_PLAYERS][8];
new PlayerText: InsuranceTD[MAX_PLAYERS][9];
//RADIALMENU
new PlayerText: RadialBall[MAX_PLAYERS][8];
new PlayerText: RadialDokumen[MAX_PLAYERS][6];
new PlayerText: RadialVehicle[MAX_PLAYERS][11];
new PlayerText: RadialInven[MAX_PLAYERS][9];
new PlayerText: RadialPhone[MAX_PLAYERS][4];
new PlayerText: RadialPayment[MAX_PLAYERS][6];
new PlayerText: RadialAcc[MAX_PLAYERS][4];
new PlayerText: RadialExit[MAX_PLAYERS][2];
new PlayerText: RadialAction[MAX_PLAYERS][3];

/* San Andreas Hud */
new PlayerText:ATRP_Footer[MAX_PLAYERS];
new PlayerText: SpectatorInfoTD[MAX_PLAYERS][8];

CreatePlayerTextDraws(playerid)
{    
    ATRP_Injured[playerid][0] = CreatePlayerTextDraw(playerid, 323.000, 407.000, "TAK SADARKAN DIRI DALAM: ~r~15~w~ MENIT ~r~30~w~ DETIK");
    PlayerTextDrawLetterSize(playerid, ATRP_Injured[playerid][0], 0.260, 1.399);
    PlayerTextDrawAlignment(playerid, ATRP_Injured[playerid][0], 2);
    PlayerTextDrawColor(playerid, ATRP_Injured[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ATRP_Injured[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, ATRP_Injured[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, ATRP_Injured[playerid][0], 150);
    PlayerTextDrawFont(playerid, ATRP_Injured[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ATRP_Injured[playerid][0], 1);

    KerjaInfo[playerid][0] = CreatePlayerTextDraw(playerid, 264.000, 608.000, "Gambar teks baru");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][0], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][0], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][0], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][0], 1);

    KerjaInfo[playerid][1] = CreatePlayerTextDraw(playerid, 384.000, 275.000, "O");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][1], 0.349, 1.500);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][1], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][1], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][1], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][1], 1);

    KerjaInfo[playerid][2] = CreatePlayerTextDraw(playerid, 250.000, 276.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][2], 10.000, 13.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][2], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][2], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][2], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][2], 1);

    KerjaInfo[playerid][3] = CreatePlayerTextDraw(playerid, 250.000, 326.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][3], 10.000, 13.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][3], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][3], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][3], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][3], 1);

    KerjaInfo[playerid][4] = CreatePlayerTextDraw(playerid, 384.000, 276.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][4], 10.000, 13.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][4], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][4], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][4], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][4], 1);

    KerjaInfo[playerid][5] = CreatePlayerTextDraw(playerid, 384.000, 326.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][5], 10.000, 13.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][5], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][5], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][5], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][5], 1);

    KerjaInfo[playerid][6] = CreatePlayerTextDraw(playerid, 252.000, 281.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][6], 141.000, 53.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][6], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][6], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][6], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][6], 1);

    KerjaInfo[playerid][7] = CreatePlayerTextDraw(playerid, 256.000, 278.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][7], 132.000, 6.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][7], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][7], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][7], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][7], 1);

    KerjaInfo[playerid][8] = CreatePlayerTextDraw(playerid, 256.000, 331.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][8], 132.000, 6.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][8], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][8], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][8], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][8], 1);

    KerjaInfo[playerid][9] = CreatePlayerTextDraw(playerid, 384.000, 325.000, "O");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][9], 0.349, 1.500);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][9], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][9], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][9], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][9], 1);

    KerjaInfo[playerid][10] = CreatePlayerTextDraw(playerid, 252.000, 274.000, "O");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][10], 0.270, 2.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][10], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][10], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][10], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][10], 1);

    KerjaInfo[playerid][11] = CreatePlayerTextDraw(playerid, 252.000, 323.000, "O");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][11], 0.270, 1.799);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][11], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][11], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][11], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][11], 1);

    KerjaInfo[playerid][12] = CreatePlayerTextDraw(playerid, 385.000, 323.000, "O");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][12], 0.270, 1.799);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][12], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][12], 438908159);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][12], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][12], 1);

    KerjaInfo[playerid][13] = CreatePlayerTextDraw(playerid, 259.000, 293.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][13], 127.000, 12.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][13], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][13], 994859519);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][13], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][13], 1);

    KerjaInfo[playerid][14] = CreatePlayerTextDraw(playerid, 261.000, 295.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][14], 3.000, 4.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][14], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][14], 581079551);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][14], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][14], 1);

    KerjaInfo[playerid][15] = CreatePlayerTextDraw(playerid, 260.000, 293.000, "/");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][15], 0.409, 0.799);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][15], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][15], 994859519);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][15], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][15], 1);

    KerjaInfo[playerid][16] = CreatePlayerTextDraw(playerid, 261.000, 293.000, "/");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][16], 0.409, 0.799);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][16], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][16], 994859519);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][16], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][16], 1);

    KerjaInfo[playerid][17] = CreatePlayerTextDraw(playerid, 261.000, 293.000, "/");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][17], 0.409, 0.799);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][17], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][17], 994859519);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][17], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][17], 1);

    KerjaInfo[playerid][18] = CreatePlayerTextDraw(playerid, 260.000, 293.000, "/");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][18], 0.409, 0.799);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][18], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][18], 994859519);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][18], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][18], 1);

    KerjaInfo[playerid][19] = CreatePlayerTextDraw(playerid, 259.000, 281.000, "NPC");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][19], 0.170, 0.799);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][19], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][19], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][19], 2);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][19], 1);

    KerjaInfo[playerid][20] = CreatePlayerTextDraw(playerid, 274.000, 282.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][20], 15.000, 7.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][20], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][20], 581079396);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][20], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][20], 1);

    KerjaInfo[playerid][21] = CreatePlayerTextDraw(playerid, 275.000, 283.000, "JADEN");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][21], 0.108, 0.499);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][21], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][21], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][21], 1);

    KerjaInfo[playerid][22] = CreatePlayerTextDraw(playerid, 265.000, 296.000, "Hai, saya Jaden, Apakah Anda Ingin Bekerja?");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][22], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][22], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][22], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][22], 1);

    KerjaInfo[playerid][23] = CreatePlayerTextDraw(playerid, 259.000, 318.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][23], 38.000, 12.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][23], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][23], 994859519);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][23], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][23], 1);
    PlayerTextDrawSetSelectable(playerid, KerjaInfo[playerid][23], 1);

    KerjaInfo[playerid][24] = CreatePlayerTextDraw(playerid, 348.000, 318.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][24], 38.000, 12.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][24], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][24], 994859519);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][24], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][24], 1);
    PlayerTextDrawSetSelectable(playerid, KerjaInfo[playerid][24], 1);

    KerjaInfo[playerid][25] = CreatePlayerTextDraw(playerid, 260.000, 320.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][25], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][25], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][25], 581079396);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][25], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][25], 1);

    KerjaInfo[playerid][26] = CreatePlayerTextDraw(playerid, 349.000, 320.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KerjaInfo[playerid][26], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][26], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][26], -16777116);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][26], 255);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][26], 1);

    KerjaInfo[playerid][27] = CreatePlayerTextDraw(playerid, 262.000, 320.000, "1");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][27], 0.090, 0.598);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][27], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][27], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][27], 2);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][27], 1);

    KerjaInfo[playerid][28] = CreatePlayerTextDraw(playerid, 351.000, 320.000, "2");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][28], 0.070, 0.598);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][28], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][28], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][28], 2);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][28], 1);

    KerjaInfo[playerid][29] = CreatePlayerTextDraw(playerid, 269.000, 320.000, "Kerja");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][29], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][29], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][29], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][29], 1);

    KerjaInfo[playerid][30] = CreatePlayerTextDraw(playerid, 357.000, 320.000, "Tidak");
    PlayerTextDrawLetterSize(playerid, KerjaInfo[playerid][30], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, KerjaInfo[playerid][30], 1);
    PlayerTextDrawColor(playerid, KerjaInfo[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, KerjaInfo[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, KerjaInfo[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, KerjaInfo[playerid][30], 150);
    PlayerTextDrawFont(playerid, KerjaInfo[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, KerjaInfo[playerid][30], 1);

	DeathTD[playerid][0] = CreatePlayerTextDraw(playerid, 268.000, 400.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DeathTD[playerid][0], 21.000, 29.000);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, DeathTD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][0], 1);

    JadenFish[playerid][0] = CreatePlayerTextDraw(playerid, 270.000, 622.000, "Gambar teks baru");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][0], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][0], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][0], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][0], 1);

    JadenFish[playerid][1] = CreatePlayerTextDraw(playerid, 378.000, 158.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][1], 32.000, 39.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][1], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][1], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][1], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][1], 1);

    JadenFish[playerid][2] = CreatePlayerTextDraw(playerid, 392.000, 292.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][2], 9.000, 10.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][2], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][2], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][2], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][2], 1);

    JadenFish[playerid][3] = CreatePlayerTextDraw(playerid, 387.000, 294.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][3], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][3], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][3], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][3], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][3], 1);

    JadenFish[playerid][4] = CreatePlayerTextDraw(playerid, 394.000, 188.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][4], 5.000, 108.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][4], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][4], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][4], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][4], 1);

    JadenFish[playerid][5] = CreatePlayerTextDraw(playerid, 389.000, 189.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][5], 3.000, 108.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][5], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][5], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][5], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][5], 1);

    JadenFish[playerid][6] = CreatePlayerTextDraw(playerid, 388.000, 184.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][6], 0.109, 14.800);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][6], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][6], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][6], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][6], 1);

    JadenFish[playerid][7] = CreatePlayerTextDraw(playerid, 388.000, 147.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][7], 0.109, 14.800);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][7], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][7], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][7], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][7], 1);

    JadenFish[playerid][8] = CreatePlayerTextDraw(playerid, 393.000, 183.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][8], 0.109, 14.800);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][8], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][8], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][8], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][8], 1);

    JadenFish[playerid][9] = CreatePlayerTextDraw(playerid, 393.000, 152.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][9], 0.109, 14.800);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][9], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][9], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][9], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][9], 1);

    JadenFish[playerid][10] = CreatePlayerTextDraw(playerid, 400.000, 182.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][10], -0.189, 14.900);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][10], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][10], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][10], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][10], 1);

    JadenFish[playerid][11] = CreatePlayerTextDraw(playerid, 400.000, 152.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][11], -0.189, 14.900);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][11], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][11], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][11], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][11], 1);

    JadenFish[playerid][12] = CreatePlayerTextDraw(playerid, 400.000, 195.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][12], -0.189, 13.300);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][12], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][12], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][12], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][12], 1);

    JadenFish[playerid][13] = CreatePlayerTextDraw(playerid, 395.000, 195.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][13], -0.189, 13.300);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][13], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][13], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][13], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][13], 1);

    JadenFish[playerid][14] = CreatePlayerTextDraw(playerid, 389.000, 196.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][14], -0.189, 13.300);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][14], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][14], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][14], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][14], 1);

    JadenFish[playerid][15] = CreatePlayerTextDraw(playerid, 395.000, 190.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][15], 3.000, 106.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][15], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][15], 892613887);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][15], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][15], 1);

    JadenFish[playerid][16] = CreatePlayerTextDraw(playerid, 389.000, 190.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][16], 2.000, 106.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][16], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][16], 892613887);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][16], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][16], 1);

    JadenFish[playerid][17] = CreatePlayerTextDraw(playerid, 389.000, 154.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][17], -0.189, 13.300);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][17], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][17], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][17], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][17], 1);

    JadenFish[playerid][18] = CreatePlayerTextDraw(playerid, 393.000, 197.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][18], -0.189, 13.200);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][18], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][18], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][18], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][18], 1);

    JadenFish[playerid][19] = CreatePlayerTextDraw(playerid, 393.000, 159.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][19], -0.189, 13.300);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][19], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][19], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][19], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][19], 1);

    JadenFish[playerid][20] = CreatePlayerTextDraw(playerid, 390.000, 180.000, ".");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][20], -0.189, 1.200);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][20], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][20], 555819519);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][20], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][20], 1);

    JadenFish[playerid][21] = CreatePlayerTextDraw(playerid, 389.000, 190.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][21], 2.000, 106.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][21], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][21], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][21], 1);

    JadenFish[playerid][22] = CreatePlayerTextDraw(playerid, 395.000, 190.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][22], 3.000, 106.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][22], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][22], 176926463);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][22], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][22], 1);

    JadenFish[playerid][23] = CreatePlayerTextDraw(playerid, 417.000, 187.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][23], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][23], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][23], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][23], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][23], 1);

    JadenFish[playerid][24] = CreatePlayerTextDraw(playerid, 399.000, 189.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][24], 23.000, 10.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][24], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][24], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][24], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][24], 1);

    JadenFish[playerid][25] = CreatePlayerTextDraw(playerid, 417.000, 189.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][25], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][25], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][25], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][25], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][25], 1);

    JadenFish[playerid][26] = CreatePlayerTextDraw(playerid, 401.000, 190.000, ">");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][26], 0.109, 0.799);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][26], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][26], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][26], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][26], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][26], 1);

    JadenFish[playerid][27] = CreatePlayerTextDraw(playerid, 401.000, 191.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][27], 0.109, 0.599);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][27], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][27], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][27], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][27], 1);

    JadenFish[playerid][28] = CreatePlayerTextDraw(playerid, 402.000, 190.000, ".");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][28], 0.109, 0.599);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][28], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][28], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][28], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][28], 1);

    JadenFish[playerid][29] = CreatePlayerTextDraw(playerid, 401.000, 189.000, ".");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][29], 0.150, 0.699);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][29], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][29], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][29], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][29], 1);

    JadenFish[playerid][30] = CreatePlayerTextDraw(playerid, 405.000, 191.000, "Low Fish");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][30], 0.090, 0.499);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][30], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][30], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][30], 1);

    JadenFish[playerid][31] = CreatePlayerTextDraw(playerid, 380.000, 160.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][31], 28.000, 35.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][31], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][31], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][31], 1);

    JadenFish[playerid][32] = CreatePlayerTextDraw(playerid, 380.000, 160.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][32], 28.000, 35.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][32], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][32], 505290239);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][32], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][32], 1);

    JadenFish[playerid][33] = CreatePlayerTextDraw(playerid, 345.000, 172.000, "_");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][33], 90.000, 66.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][33], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][33], 0);
    PlayerTextDrawFont(playerid, JadenFish[playerid][33], 5);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][33], 0);
    PlayerTextDrawSetPreviewModel(playerid, JadenFish[playerid][33], 18632);
    PlayerTextDrawSetPreviewRot(playerid, JadenFish[playerid][33], -349.000, -216.000, -33.000, 0.899);
    PlayerTextDrawSetPreviewVehCol(playerid, JadenFish[playerid][33], 0, 0);

    JadenFish[playerid][34] = CreatePlayerTextDraw(playerid, 417.000, 284.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][34], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][34], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][34], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][34], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][34], 1);

    JadenFish[playerid][35] = CreatePlayerTextDraw(playerid, 399.000, 286.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][35], 23.000, 10.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][35], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][35], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][35], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][35], 1);

    JadenFish[playerid][36] = CreatePlayerTextDraw(playerid, 417.000, 286.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][36], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][36], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][36], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][36], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][36], 1);

    JadenFish[playerid][37] = CreatePlayerTextDraw(playerid, 401.000, 287.000, ">");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][37], 0.109, 0.799);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][37], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][37], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][37], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][37], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][37], 1);

    JadenFish[playerid][38] = CreatePlayerTextDraw(playerid, 401.000, 288.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][38], 0.109, 0.599);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][38], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][38], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][38], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][38], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][38], 1);

    JadenFish[playerid][39] = CreatePlayerTextDraw(playerid, 402.000, 287.000, ".");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][39], 0.109, 0.599);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][39], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][39], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][39], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][39], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][39], 1);

    JadenFish[playerid][40] = CreatePlayerTextDraw(playerid, 401.000, 286.000, ".");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][40], 0.150, 0.699);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][40], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][40], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][40], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][40], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][40], 1);

    JadenFish[playerid][41] = CreatePlayerTextDraw(playerid, 405.000, 288.000, "High Fish");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][41], 0.090, 0.499);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][41], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][41], -1);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][41], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][41], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][41], 1);

    JadenFish[playerid][42] = CreatePlayerTextDraw(playerid, 417.000, 234.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][42], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][42], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][42], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][42], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][42], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][42], 1);

    JadenFish[playerid][43] = CreatePlayerTextDraw(playerid, 399.000, 236.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][43], 23.000, 10.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][43], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][43], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][43], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][43], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][43], 1);

    JadenFish[playerid][44] = CreatePlayerTextDraw(playerid, 417.000, 236.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][44], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][44], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][44], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][44], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][44], 1);

    JadenFish[playerid][45] = CreatePlayerTextDraw(playerid, 401.000, 237.000, ">");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][45], 0.109, 0.799);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][45], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][45], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][45], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][45], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][45], 1);

    JadenFish[playerid][46] = CreatePlayerTextDraw(playerid, 401.000, 238.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][46], 0.109, 0.599);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][46], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][46], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][46], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][46], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][46], 1);

    JadenFish[playerid][47] = CreatePlayerTextDraw(playerid, 402.000, 237.000, ".");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][47], 0.109, 0.599);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][47], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][47], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][47], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][47], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][47], 1);

    JadenFish[playerid][48] = CreatePlayerTextDraw(playerid, 401.000, 236.000, ".");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][48], 0.150, 0.699);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][48], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][48], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][48], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][48], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][48], 1);

    JadenFish[playerid][49] = CreatePlayerTextDraw(playerid, 405.000, 238.000, "Medium Fish");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][49], 0.090, 0.499);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][49], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][49], -1);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][49], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][49], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][49], 1);

    JadenFish[playerid][50] = CreatePlayerTextDraw(playerid, 365.000, 189.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][50], 23.000, 10.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][50], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][50], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][50], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][50], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][50], 1);

    JadenFish[playerid][51] = CreatePlayerTextDraw(playerid, 360.000, 187.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][51], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][51], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][51], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][51], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][51], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][51], 1);

    JadenFish[playerid][52] = CreatePlayerTextDraw(playerid, 360.000, 189.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, JadenFish[playerid][52], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][52], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][52], 522133503);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][52], 255);
    PlayerTextDrawFont(playerid, JadenFish[playerid][52], 4);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][52], 1);

    JadenFish[playerid][53] = CreatePlayerTextDraw(playerid, 364.000, 191.000, "Just Started");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][53], 0.090, 0.499);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][53], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][53], -1);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][53], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][53], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][53], 1);

    JadenFish[playerid][54] = CreatePlayerTextDraw(playerid, 384.000, 190.000, "<");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][54], 0.109, 0.799);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][54], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][54], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][54], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][54], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][54], 1);

    JadenFish[playerid][55] = CreatePlayerTextDraw(playerid, 386.000, 191.000, "l");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][55], 0.090, 0.599);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][55], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][55], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][55], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][55], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][55], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][55], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][55], 1);

    JadenFish[playerid][56] = CreatePlayerTextDraw(playerid, 385.000, 190.000, ".");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][56], 0.090, 0.598);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][56], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][56], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][56], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][56], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][56], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][56], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][56], 1);

    JadenFish[playerid][57] = CreatePlayerTextDraw(playerid, 385.000, 190.000, ".");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][57], 0.128, 0.499);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][57], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][57], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][57], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][57], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][57], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][57], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][57], 1);

    JadenFish[playerid][58] = CreatePlayerTextDraw(playerid, 385.000, 191.000, ".");
    PlayerTextDrawLetterSize(playerid, JadenFish[playerid][58], 0.128, 0.499);
    PlayerTextDrawAlignment(playerid, JadenFish[playerid][58], 1);
    PlayerTextDrawColor(playerid, JadenFish[playerid][58], -1583309057);
    PlayerTextDrawSetShadow(playerid, JadenFish[playerid][58], 0);
    PlayerTextDrawSetOutline(playerid, JadenFish[playerid][58], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenFish[playerid][58], 150);
    PlayerTextDrawFont(playerid, JadenFish[playerid][58], 1);
    PlayerTextDrawSetProportional(playerid, JadenFish[playerid][58], 1);

    SusuInfo[playerid][0] = CreatePlayerTextDraw(playerid, 264.000, 608.000, "Gambar teks baru");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][0], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][0], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][0], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][0], 1);

    SusuInfo[playerid][1] = CreatePlayerTextDraw(playerid, 384.000, 275.000, "O");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][1], 0.349, 1.500);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][1], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][1], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][1], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][1], 1);

    SusuInfo[playerid][2] = CreatePlayerTextDraw(playerid, 250.000, 276.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][2], 10.000, 13.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][2], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][2], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][2], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][2], 1);

    SusuInfo[playerid][3] = CreatePlayerTextDraw(playerid, 250.000, 326.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][3], 10.000, 13.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][3], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][3], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][3], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][3], 1);

    SusuInfo[playerid][4] = CreatePlayerTextDraw(playerid, 384.000, 276.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][4], 10.000, 13.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][4], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][4], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][4], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][4], 1);

    SusuInfo[playerid][5] = CreatePlayerTextDraw(playerid, 384.000, 326.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][5], 10.000, 13.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][5], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][5], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][5], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][5], 1);

    SusuInfo[playerid][6] = CreatePlayerTextDraw(playerid, 252.000, 281.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][6], 141.000, 53.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][6], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][6], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][6], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][6], 1);

    SusuInfo[playerid][7] = CreatePlayerTextDraw(playerid, 256.000, 278.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][7], 132.000, 6.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][7], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][7], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][7], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][7], 1);

    SusuInfo[playerid][8] = CreatePlayerTextDraw(playerid, 256.000, 331.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][8], 132.000, 6.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][8], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][8], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][8], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][8], 1);

    SusuInfo[playerid][9] = CreatePlayerTextDraw(playerid, 384.000, 325.000, "O");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][9], 0.349, 1.500);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][9], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][9], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][9], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][9], 1);

    SusuInfo[playerid][10] = CreatePlayerTextDraw(playerid, 252.000, 274.000, "O");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][10], 0.270, 2.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][10], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][10], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][10], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][10], 1);

    SusuInfo[playerid][11] = CreatePlayerTextDraw(playerid, 252.000, 323.000, "O");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][11], 0.270, 1.799);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][11], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][11], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][11], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][11], 1);

    SusuInfo[playerid][12] = CreatePlayerTextDraw(playerid, 385.000, 323.000, "O");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][12], 0.270, 1.799);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][12], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][12], 438908159);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][12], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][12], 1);

    SusuInfo[playerid][13] = CreatePlayerTextDraw(playerid, 259.000, 293.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][13], 127.000, 12.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][13], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][13], 994859519);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][13], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][13], 1);

    SusuInfo[playerid][14] = CreatePlayerTextDraw(playerid, 261.000, 295.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][14], 3.000, 4.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][14], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][14], 581079551);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][14], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][14], 1);

    SusuInfo[playerid][15] = CreatePlayerTextDraw(playerid, 260.000, 293.000, "/");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][15], 0.409, 0.799);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][15], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][15], 994859519);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][15], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][15], 1);

    SusuInfo[playerid][16] = CreatePlayerTextDraw(playerid, 261.000, 293.000, "/");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][16], 0.409, 0.799);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][16], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][16], 994859519);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][16], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][16], 1);

    SusuInfo[playerid][17] = CreatePlayerTextDraw(playerid, 261.000, 293.000, "/");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][17], 0.409, 0.799);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][17], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][17], 994859519);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][17], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][17], 1);

    SusuInfo[playerid][18] = CreatePlayerTextDraw(playerid, 260.000, 293.000, "/");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][18], 0.409, 0.799);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][18], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][18], 994859519);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][18], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][18], 1);

    SusuInfo[playerid][19] = CreatePlayerTextDraw(playerid, 259.000, 281.000, "NPC");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][19], 0.170, 0.799);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][19], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][19], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][19], 2);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][19], 1);

    SusuInfo[playerid][20] = CreatePlayerTextDraw(playerid, 274.000, 282.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][20], 15.000, 7.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][20], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][20], 581079396);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][20], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][20], 1);

    SusuInfo[playerid][21] = CreatePlayerTextDraw(playerid, 275.000, 283.000, "JADEN");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][21], 0.108, 0.499);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][21], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][21], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][21], 1);

    SusuInfo[playerid][22] = CreatePlayerTextDraw(playerid, 265.000, 296.000, "Hai, saya Jaden, Apakah Anda Ingin Bekerja?");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][22], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][22], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][22], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][22], 1);

    SusuInfo[playerid][23] = CreatePlayerTextDraw(playerid, 259.000, 318.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][23], 38.000, 12.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][23], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][23], 994859519);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][23], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][23], 1);
    PlayerTextDrawSetSelectable(playerid, SusuInfo[playerid][23], 1);

    SusuInfo[playerid][24] = CreatePlayerTextDraw(playerid, 348.000, 318.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][24], 38.000, 12.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][24], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][24], 994859519);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][24], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][24], 1);
    PlayerTextDrawSetSelectable(playerid, SusuInfo[playerid][24], 1);

    SusuInfo[playerid][25] = CreatePlayerTextDraw(playerid, 260.000, 320.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][25], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][25], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][25], 581079396);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][25], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][25], 1);

    SusuInfo[playerid][26] = CreatePlayerTextDraw(playerid, 349.000, 320.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SusuInfo[playerid][26], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][26], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][26], -16777116);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][26], 255);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][26], 1);

    SusuInfo[playerid][27] = CreatePlayerTextDraw(playerid, 262.000, 320.000, "1");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][27], 0.090, 0.598);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][27], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][27], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][27], 2);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][27], 1);

    SusuInfo[playerid][28] = CreatePlayerTextDraw(playerid, 351.000, 320.000, "2");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][28], 0.070, 0.598);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][28], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][28], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][28], 2);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][28], 1);

    SusuInfo[playerid][29] = CreatePlayerTextDraw(playerid, 269.000, 320.000, "Kerja");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][29], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][29], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][29], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][29], 1);

    SusuInfo[playerid][30] = CreatePlayerTextDraw(playerid, 357.000, 320.000, "Tidak");
    PlayerTextDrawLetterSize(playerid, SusuInfo[playerid][30], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, SusuInfo[playerid][30], 1);
    PlayerTextDrawColor(playerid, SusuInfo[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, SusuInfo[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, SusuInfo[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, SusuInfo[playerid][30], 150);
    PlayerTextDrawFont(playerid, SusuInfo[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, SusuInfo[playerid][30], 1);

    DeathTD[playerid][1] = CreatePlayerTextDraw(playerid, 291.000, 400.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DeathTD[playerid][1], 21.000, 29.000);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, DeathTD[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][1], 1);

    DeathTD[playerid][2] = CreatePlayerTextDraw(playerid, 316.000, 406.000, ":");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][2], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][2], 1);

    DeathTD[playerid][3] = CreatePlayerTextDraw(playerid, 324.000, 400.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DeathTD[playerid][3], 21.000, 29.000);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, DeathTD[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][3], 1);

    DeathTD[playerid][4] = CreatePlayerTextDraw(playerid, 347.000, 400.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DeathTD[playerid][4], 21.000, 29.000);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, DeathTD[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][4], 1);

    DeathTD[playerid][5] = CreatePlayerTextDraw(playerid, 276.000, 407.000, "5");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][5], 0.220, 1.499);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][5], 1);

    DeathTD[playerid][6] = CreatePlayerTextDraw(playerid, 298.000, 407.000, "8");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][6], 0.220, 1.499);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][6], 255);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][6], 1);

    DeathTD[playerid][7] = CreatePlayerTextDraw(playerid, 333.000, 407.000, "1");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][7], 0.220, 1.499);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][7], 1);

    DeathTD[playerid][8] = CreatePlayerTextDraw(playerid, 354.000, 407.000, "8");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][8], 0.220, 1.499);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][8], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][8], 2);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][8], 1);

    DeathTD[playerid][9] = CreatePlayerTextDraw(playerid, 245.000, 344.000, "Anda kehabisan darah");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][9], 0.280, 1.299);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][9], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][9], 502316031);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][9], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][9], 2);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][9], 1);

    DeathTD[playerid][10] = CreatePlayerTextDraw(playerid, 208.000, 363.000, "kamu tidak berdaya, tekan");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][10], 0.150, 0.999);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][10], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][10], 1);

    DeathTD[playerid][11] = CreatePlayerTextDraw(playerid, -4.000, -3.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DeathTD[playerid][11], 814.000, 552.000);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][11], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][11], 71);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][11], 255);
    PlayerTextDrawFont(playerid, DeathTD[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][11], 1);

    DeathTD[playerid][12] = CreatePlayerTextDraw(playerid, 276.000, 363.000, "[");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][12], 0.150, 0.999);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][12], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][12], -2686721);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][12], 1);

    DeathTD[playerid][13] = CreatePlayerTextDraw(playerid, 278.000, 363.000, "H");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][13], 0.150, 0.999);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][13], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][13], -2686721);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][13], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][13], 2);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][13], 1);

    DeathTD[playerid][14] = CreatePlayerTextDraw(playerid, 282.000, 363.000, "]");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][14], 0.150, 0.999);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][14], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][14], -2686721);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][14], 1);

    DeathTD[playerid][15] = CreatePlayerTextDraw(playerid, 286.000, 363.000, "untuk respawn");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][15], 0.150, 0.999);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][15], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][15], 1);

    DeathTD[playerid][16] = CreatePlayerTextDraw(playerid, 323.000, 363.000, "/s");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][16], 0.150, 0.999);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][16], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][16], -2686721);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][16], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][16], 1);

    DeathTD[playerid][17] = CreatePlayerTextDraw(playerid, 329.000, 363.000, "untuk mengirim sinyal kepada paramedis");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][17], 0.150, 0.999);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][17], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][17], -2686721);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][17], 1);

    DeathTD[playerid][18] = CreatePlayerTextDraw(playerid, 267.000, 378.000, "Kamu akan kehabisan darah dalam waktu");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][18], 0.150, 0.999);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][18], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][18], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][18], 1);

    DeathTD[playerid][19] = CreatePlayerTextDraw(playerid, 270.000, 606.000, "Gambar teks baru");
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][19], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][19], 1);
    PlayerTextDrawColor(playerid, DeathTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][19], 1);
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][19], 1);
    PlayerTextDrawBackgroundColor(playerid, DeathTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, DeathTD[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, DeathTD[playerid][19], 1);


    ATRP_Gym[playerid][0] = CreatePlayerTextDraw(playerid, 16.000, 208.000, "~r~55");
    PlayerTextDrawLetterSize(playerid, ATRP_Gym[playerid][0], 0.189, 1.198);
    PlayerTextDrawAlignment(playerid, ATRP_Gym[playerid][0], 1);
    PlayerTextDrawColor(playerid, ATRP_Gym[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ATRP_Gym[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, ATRP_Gym[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, ATRP_Gym[playerid][0], 150);
    PlayerTextDrawFont(playerid, ATRP_Gym[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ATRP_Gym[playerid][0], 1);

    ATRP_Gym[playerid][1] = CreatePlayerTextDraw(playerid, 16.000, 221.000, "~g~[ALT]~w~ Untuk Latihan");
    PlayerTextDrawLetterSize(playerid, ATRP_Gym[playerid][1], 0.189, 1.198);
    PlayerTextDrawAlignment(playerid, ATRP_Gym[playerid][1], 1);
    PlayerTextDrawColor(playerid, ATRP_Gym[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ATRP_Gym[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, ATRP_Gym[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, ATRP_Gym[playerid][1], 150);
    PlayerTextDrawFont(playerid, ATRP_Gym[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ATRP_Gym[playerid][1], 1);

    ATRP_Gym[playerid][2] = CreatePlayerTextDraw(playerid, 16.000, 235.000, "~r~[H]~w~ Untuk Berhenti");
    PlayerTextDrawLetterSize(playerid, ATRP_Gym[playerid][2], 0.189, 1.198);
    PlayerTextDrawAlignment(playerid, ATRP_Gym[playerid][2], 1);
    PlayerTextDrawColor(playerid, ATRP_Gym[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ATRP_Gym[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, ATRP_Gym[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, ATRP_Gym[playerid][2], 150);
    PlayerTextDrawFont(playerid, ATRP_Gym[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ATRP_Gym[playerid][2], 1);

    JadenHbe[playerid][0] = CreatePlayerTextDraw(playerid, 5.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][0], 1.000, -14.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][0], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][0], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][0], 1);

    JadenHbe[playerid][1] = CreatePlayerTextDraw(playerid, 38.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][1], 1.000, -14.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][1], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][1], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][1], 1);

    JadenHbe[playerid][2] = CreatePlayerTextDraw(playerid, 39.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][2], -34.000, 1.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][2], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][2], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][2], 1);

    JadenHbe[playerid][3] = CreatePlayerTextDraw(playerid, 39.000, 431.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][3], -34.000, 1.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][3], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][3], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][3], 1);

    JadenHbe[playerid][4] = CreatePlayerTextDraw(playerid, 41.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][4], 1.000, -14.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][4], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][4], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][4], 1);

    JadenHbe[playerid][5] = CreatePlayerTextDraw(playerid, 74.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][5], 1.000, -14.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][5], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][5], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][5], 1);

    JadenHbe[playerid][6] = CreatePlayerTextDraw(playerid, 75.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][6], -34.000, 1.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][6], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][6], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][6], 1);

    JadenHbe[playerid][7] = CreatePlayerTextDraw(playerid, 75.000, 431.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][7], -34.000, 1.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][7], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][7], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][7], 1);

    JadenHbe[playerid][8] = CreatePlayerTextDraw(playerid, 77.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][8], 1.000, -14.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][8], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][8], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][8], 1);

    JadenHbe[playerid][9] = CreatePlayerTextDraw(playerid, 90.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][9], 1.000, -14.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][9], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][9], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][9], 1);

    JadenHbe[playerid][10] = CreatePlayerTextDraw(playerid, 91.000, 446.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][10], -14.000, -1.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][10], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][10], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][10], 1);

    JadenHbe[playerid][11] = CreatePlayerTextDraw(playerid, 91.000, 432.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][11], -14.000, -1.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][11], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][11], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][11], 1);

    JadenHbe[playerid][12] = CreatePlayerTextDraw(playerid, 93.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][12], 1.000, -14.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][12], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][12], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][12], 1);

    JadenHbe[playerid][13] = CreatePlayerTextDraw(playerid, 106.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][13], 1.000, -14.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][13], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][13], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][13], 1);

    JadenHbe[playerid][14] = CreatePlayerTextDraw(playerid, 107.000, 446.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][14], -14.000, -1.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][14], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][14], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][14], 1);

    JadenHbe[playerid][15] = CreatePlayerTextDraw(playerid, 107.000, 432.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][15], -14.000, -1.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][15], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][15], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][15], 1);

    JadenHbe[playerid][16] = CreatePlayerTextDraw(playerid, 109.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][16], 1.000, -14.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][16], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][16], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][16], 1);

    JadenHbe[playerid][17] = CreatePlayerTextDraw(playerid, 122.000, 445.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][17], 1.000, -14.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][17], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][17], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][17], 1);

    JadenHbe[playerid][18] = CreatePlayerTextDraw(playerid, 123.000, 446.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][18], -14.000, -1.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][18], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][18], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][18], 1);

    JadenHbe[playerid][19] = CreatePlayerTextDraw(playerid, 123.000, 432.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][19], -14.000, -1.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][19], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][19], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][19], 1);

    JadenHbe[playerid][20] = CreatePlayerTextDraw(playerid, 7.000, 444.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][20], 30.000, -11.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][20], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][20], 1018393087);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][20], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][20], 1);

    JadenHbe[playerid][21] = CreatePlayerTextDraw(playerid, 43.000, 444.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][21], 30.000, -11.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][21], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][21], 548580095);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][21], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][21], 1);

    JadenHbe[playerid][22] = CreatePlayerTextDraw(playerid, 79.000, 444.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][22], 10.000, -11.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][22], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][22], -626712321);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][22], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][22], 1);

    JadenHbe[playerid][23] = CreatePlayerTextDraw(playerid, 95.000, 444.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][23], 10.000, -11.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][23], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][23], 526626303);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][23], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][23], 1);

    JadenHbe[playerid][24] = CreatePlayerTextDraw(playerid, 111.000, 444.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][24], 10.000, -11.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][24], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][24], -1523963223);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][24], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][24], 1);

    JadenHbe[playerid][25] = CreatePlayerTextDraw(playerid, 10.000, 435.000, "HUD:radar_girlfriend");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][25], 5.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][25], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][25], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][25], 1);

    JadenHbe[playerid][26] = CreatePlayerTextDraw(playerid, 45.000, 435.000, "HUD:radar_tshirt");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][26], 5.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][26], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][26], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][26], 1);

    JadenHbe[playerid][27] = CreatePlayerTextDraw(playerid, 81.000, 435.000, "HUD:radar_burgerShot");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][27], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][27], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][27], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][27], 1);

    JadenHbe[playerid][28] = CreatePlayerTextDraw(playerid, 97.000, 435.000, "HUD:radar_diner");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][28], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][28], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][28], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][28], 1);

    JadenHbe[playerid][29] = CreatePlayerTextDraw(playerid, 113.000, 435.000, "HUD:radar_waypoint");
    PlayerTextDrawTextSize(playerid, JadenHbe[playerid][29], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, JadenHbe[playerid][29], 1);
    PlayerTextDrawColor(playerid, JadenHbe[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, JadenHbe[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, JadenHbe[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, JadenHbe[playerid][29], 255);
    PlayerTextDrawFont(playerid, JadenHbe[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, JadenHbe[playerid][29], 1);

    HbeTengah[playerid][0] = CreatePlayerTextDraw(playerid, 504.000, 867.000, "Gambar teks baru");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][0], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][0], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][0], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][0], 1);

    HbeTengah[playerid][1] = CreatePlayerTextDraw(playerid, 284.000, 432.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][1], 4.000, 7.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][1], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][1], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][1], 1);

    HbeTengah[playerid][2] = CreatePlayerTextDraw(playerid, 322.000, 419.000, "_");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][2], 25.000, 28.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][2], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][2], 315346994);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][2], 0);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][2], 0);
    PlayerTextDrawSetPreviewModel(playerid, HbeTengah[playerid][2], 2751);
    PlayerTextDrawSetPreviewRot(playerid, HbeTengah[playerid][2], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, HbeTengah[playerid][2], 0, 0);

    HbeTengah[playerid][3] = CreatePlayerTextDraw(playerid, 324.000, 422.000, "_");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][3], 21.000, 23.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][3], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][3], 315347044);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][3], 0);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][3], 5);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][3], 0);
    PlayerTextDrawSetPreviewModel(playerid, HbeTengah[playerid][3], 2751);
    PlayerTextDrawSetPreviewRot(playerid, HbeTengah[playerid][3], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, HbeTengah[playerid][3], 0, 0);

    HbeTengah[playerid][4] = CreatePlayerTextDraw(playerid, 338.000, 419.000, "_");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][4], 25.000, 28.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][4], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][4], -16777166);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][4], 0);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, HbeTengah[playerid][4], 2751);
    PlayerTextDrawSetPreviewRot(playerid, HbeTengah[playerid][4], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, HbeTengah[playerid][4], 0, 0);

    HbeTengah[playerid][5] = CreatePlayerTextDraw(playerid, 282.000, 431.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][5], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][5], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][5], 400450178);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][5], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][5], 1);

    HbeTengah[playerid][6] = CreatePlayerTextDraw(playerid, 340.000, 422.000, "_");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][6], 21.000, 23.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][6], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][6], -2147483548);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][6], 0);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][6], 0);
    PlayerTextDrawSetPreviewModel(playerid, HbeTengah[playerid][6], 2751);
    PlayerTextDrawSetPreviewRot(playerid, HbeTengah[playerid][6], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, HbeTengah[playerid][6], 0, 0);

    HbeTengah[playerid][7] = CreatePlayerTextDraw(playerid, 314.000, 431.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][7], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][7], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][7], -91996542);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][7], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][7], 1);

    HbeTengah[playerid][8] = CreatePlayerTextDraw(playerid, 274.000, 419.000, "_");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][8], 25.000, 28.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][8], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][8], 400450098);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][8], 0);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][8], 0);
    PlayerTextDrawSetPreviewModel(playerid, HbeTengah[playerid][8], 2751);
    PlayerTextDrawSetPreviewRot(playerid, HbeTengah[playerid][8], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, HbeTengah[playerid][8], 0, 0);

    HbeTengah[playerid][9] = CreatePlayerTextDraw(playerid, 276.000, 422.000, "_");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][9], 21.000, 23.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][9], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][9], 400450148);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][9], 0);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][9], 5);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][9], 0);
    PlayerTextDrawSetPreviewModel(playerid, HbeTengah[playerid][9], 2751);
    PlayerTextDrawSetPreviewRot(playerid, HbeTengah[playerid][9], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, HbeTengah[playerid][9], 0, 0);

    HbeTengah[playerid][10] = CreatePlayerTextDraw(playerid, 346.000, 431.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][10], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][10], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][10], -2147483518);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][10], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][10], 1);

    HbeTengah[playerid][11] = CreatePlayerTextDraw(playerid, 330.000, 431.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][11], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][11], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][11], 315347074);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][11], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][11], 1);

    HbeTengah[playerid][12] = CreatePlayerTextDraw(playerid, 290.000, 419.000, "_");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][12], 25.000, 28.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][12], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][12], 730265906);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][12], 0);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][12], 5);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][12], 0);
    PlayerTextDrawSetPreviewModel(playerid, HbeTengah[playerid][12], 2751);
    PlayerTextDrawSetPreviewRot(playerid, HbeTengah[playerid][12], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, HbeTengah[playerid][12], 0, 0);

    HbeTengah[playerid][13] = CreatePlayerTextDraw(playerid, 292.000, 422.000, "_");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][13], 21.000, 23.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][13], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][13], 730265956);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][13], 0);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][13], 5);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][13], 0);
    PlayerTextDrawSetPreviewModel(playerid, HbeTengah[playerid][13], 2751);
    PlayerTextDrawSetPreviewRot(playerid, HbeTengah[playerid][13], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, HbeTengah[playerid][13], 0, 0);

    HbeTengah[playerid][14] = CreatePlayerTextDraw(playerid, 306.000, 419.000, "_");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][14], 25.000, 28.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][14], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][14], -91996622);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][14], 0);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][14], 5);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][14], 0);
    PlayerTextDrawSetPreviewModel(playerid, HbeTengah[playerid][14], 2751);
    PlayerTextDrawSetPreviewRot(playerid, HbeTengah[playerid][14], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, HbeTengah[playerid][14], 0, 0);

    HbeTengah[playerid][15] = CreatePlayerTextDraw(playerid, 308.000, 422.000, "_");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][15], 21.000, 23.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][15], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][15], -91996572);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][15], 0);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][15], 5);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][15], 0);
    PlayerTextDrawSetPreviewModel(playerid, HbeTengah[playerid][15], 2751);
    PlayerTextDrawSetPreviewRot(playerid, HbeTengah[playerid][15], -90.000, 0.000, 30.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, HbeTengah[playerid][15], 0, 0);

    HbeTengah[playerid][16] = CreatePlayerTextDraw(playerid, 298.000, 431.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][16], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][16], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][16], 746978434);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][16], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][16], 1);

    HbeTengah[playerid][17] = CreatePlayerTextDraw(playerid, 316.000, 435.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][17], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][17], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][17], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][17], 1);

    HbeTengah[playerid][18] = CreatePlayerTextDraw(playerid, 333.000, 430.000, "v");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][18], 0.209, 0.598);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][18], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][18], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][18], 1);

    HbeTengah[playerid][19] = CreatePlayerTextDraw(playerid, 283.000, 431.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][19], 5.000, 7.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][19], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][19], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][19], 1);

    HbeTengah[playerid][20] = CreatePlayerTextDraw(playerid, 286.000, 431.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][20], 5.000, 7.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][20], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][20], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][20], 1);

    HbeTengah[playerid][21] = CreatePlayerTextDraw(playerid, 286.000, 432.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][21], 4.000, 7.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][21], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][21], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][21], 1);

    HbeTengah[playerid][22] = CreatePlayerTextDraw(playerid, 285.000, 433.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][22], 4.000, 7.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][22], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][22], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][22], 1);

    HbeTengah[playerid][23] = CreatePlayerTextDraw(playerid, 300.000, 431.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][23], 7.000, 9.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][23], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][23], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][23], 1);

    HbeTengah[playerid][24] = CreatePlayerTextDraw(playerid, 301.000, 430.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][24], 5.000, 10.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][24], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][24], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][24], 1);

    HbeTengah[playerid][25] = CreatePlayerTextDraw(playerid, 284.000, 432.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][25], 4.000, 7.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][25], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][25], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][25], 1);

    HbeTengah[playerid][26] = CreatePlayerTextDraw(playerid, 316.000, 432.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][26], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][26], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][26], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][26], 1);

    HbeTengah[playerid][27] = CreatePlayerTextDraw(playerid, 317.000, 432.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][27], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][27], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][27], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][27], 1);

    HbeTengah[playerid][28] = CreatePlayerTextDraw(playerid, 316.000, 432.000, "-");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][28], 0.479, 0.398);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][28], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][28], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][28], 1);

    HbeTengah[playerid][29] = CreatePlayerTextDraw(playerid, 316.000, 432.000, "-");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][29], 0.479, 0.699);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][29], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][29], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][29], 1);

    HbeTengah[playerid][30] = CreatePlayerTextDraw(playerid, 317.000, 435.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HbeTengah[playerid][30], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][30], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][30], 255);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][30], 1);

    HbeTengah[playerid][31] = CreatePlayerTextDraw(playerid, 336.000, 431.000, "2");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][31], 0.070, 0.499);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][31], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][31], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][31], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][31], 1);

    HbeTengah[playerid][32] = CreatePlayerTextDraw(playerid, 333.000, 431.000, "/");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][32], 0.090, 0.499);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][32], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][32], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][32], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][32], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][32], 1);

    HbeTengah[playerid][33] = CreatePlayerTextDraw(playerid, 333.000, 434.000, "l");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][33], 0.090, 0.499);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][33], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][33], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][33], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][33], 1);

    HbeTengah[playerid][34] = CreatePlayerTextDraw(playerid, 337.000, 434.000, "l");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][34], 0.079, 0.499);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][34], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][34], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][34], 1);

    HbeTengah[playerid][35] = CreatePlayerTextDraw(playerid, 333.000, 435.000, "-");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][35], 0.328, 0.499);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][35], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][35], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][35], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][35], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][35], 1);

    HbeTengah[playerid][36] = CreatePlayerTextDraw(playerid, 333.000, 433.000, "-");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][36], 0.328, 0.499);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][36], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][36], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][36], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][36], 1);

    HbeTengah[playerid][37] = CreatePlayerTextDraw(playerid, 333.000, 430.000, "-");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][37], 0.328, 1.199);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][37], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][37], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][37], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][37], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][37], 1);

    HbeTengah[playerid][38] = CreatePlayerTextDraw(playerid, 350.000, 430.000, "l");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][38], 0.090, 0.999);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][38], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][38], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][38], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][38], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][38], 1);

    HbeTengah[playerid][39] = CreatePlayerTextDraw(playerid, 352.000, 430.000, "l");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][39], 0.090, 0.999);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][39], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][39], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][39], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][39], 1);

    HbeTengah[playerid][40] = CreatePlayerTextDraw(playerid, 352.000, 427.000, ".");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][40], 0.159, 0.999);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][40], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][40], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][40], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][40], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][40], 1);

    HbeTengah[playerid][41] = CreatePlayerTextDraw(playerid, 349.000, 427.000, ".");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][41], 0.159, 0.999);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][41], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][41], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][41], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][41], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][41], 1);

    HbeTengah[playerid][42] = CreatePlayerTextDraw(playerid, 349.000, 428.000, ".");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][42], 0.159, 0.999);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][42], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][42], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][42], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][42], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][42], 1);

    HbeTengah[playerid][43] = CreatePlayerTextDraw(playerid, 352.000, 428.000, ".");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][43], 0.159, 0.999);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][43], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][43], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][43], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][43], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][43], 1);

    HbeTengah[playerid][44] = CreatePlayerTextDraw(playerid, 352.000, 429.000, ".");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][44], 0.159, 0.999);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][44], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][44], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][44], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][44], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][44], 1);

    HbeTengah[playerid][45] = CreatePlayerTextDraw(playerid, 349.000, 429.000, ".");
    PlayerTextDrawLetterSize(playerid, HbeTengah[playerid][45], 0.159, 0.999);
    PlayerTextDrawAlignment(playerid, HbeTengah[playerid][45], 1);
    PlayerTextDrawColor(playerid, HbeTengah[playerid][45], -1);
    PlayerTextDrawSetShadow(playerid, HbeTengah[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, HbeTengah[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, HbeTengah[playerid][45], 150);
    PlayerTextDrawFont(playerid, HbeTengah[playerid][45], 1);
    PlayerTextDrawSetProportional(playerid, HbeTengah[playerid][45], 1);

    // Spectator Info
    SpectatorInfoTD[playerid][0] = CreatePlayerTextDraw(playerid, 214.000, 306.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpectatorInfoTD[playerid][0], 209.000, 129.000);
    PlayerTextDrawAlignment(playerid, SpectatorInfoTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, SpectatorInfoTD[playerid][0], 150);
    PlayerTextDrawSetShadow(playerid, SpectatorInfoTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, SpectatorInfoTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, SpectatorInfoTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, SpectatorInfoTD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, SpectatorInfoTD[playerid][0], 1);

    SpectatorInfoTD[playerid][1] = CreatePlayerTextDraw(playerid, 320.000, 310.000, "~g~Cecep_Sugeni_(100)");
    PlayerTextDrawLetterSize(playerid, SpectatorInfoTD[playerid][1], 0.379, 1.399);
    PlayerTextDrawAlignment(playerid, SpectatorInfoTD[playerid][1], 2);
    PlayerTextDrawColor(playerid, SpectatorInfoTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, SpectatorInfoTD[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, SpectatorInfoTD[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, SpectatorInfoTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, SpectatorInfoTD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, SpectatorInfoTD[playerid][1], 1);

    SpectatorInfoTD[playerid][2] = CreatePlayerTextDraw(playerid, 320.000, 333.000, "Cash:~y~_$5,000");
    PlayerTextDrawLetterSize(playerid, SpectatorInfoTD[playerid][2], 0.328, 1.500);
    PlayerTextDrawAlignment(playerid, SpectatorInfoTD[playerid][2], 2);
    PlayerTextDrawColor(playerid, SpectatorInfoTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, SpectatorInfoTD[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, SpectatorInfoTD[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, SpectatorInfoTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, SpectatorInfoTD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, SpectatorInfoTD[playerid][2], 1);

    SpectatorInfoTD[playerid][3] = CreatePlayerTextDraw(playerid, 320.000, 349.000, "HP:~y~_100.0");
    PlayerTextDrawLetterSize(playerid, SpectatorInfoTD[playerid][3], 0.328, 1.500);
    PlayerTextDrawAlignment(playerid, SpectatorInfoTD[playerid][3], 2);
    PlayerTextDrawColor(playerid, SpectatorInfoTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, SpectatorInfoTD[playerid][3], 1);
    PlayerTextDrawSetOutline(playerid, SpectatorInfoTD[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, SpectatorInfoTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, SpectatorInfoTD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, SpectatorInfoTD[playerid][3], 1);

    SpectatorInfoTD[playerid][4] = CreatePlayerTextDraw(playerid, 320.000, 364.000, "AM:~y~_95.0");
    PlayerTextDrawLetterSize(playerid, SpectatorInfoTD[playerid][4], 0.328, 1.500);
    PlayerTextDrawAlignment(playerid, SpectatorInfoTD[playerid][4], 2);
    PlayerTextDrawColor(playerid, SpectatorInfoTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, SpectatorInfoTD[playerid][4], 1);
    PlayerTextDrawSetOutline(playerid, SpectatorInfoTD[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, SpectatorInfoTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, SpectatorInfoTD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, SpectatorInfoTD[playerid][4], 1);

    SpectatorInfoTD[playerid][5] = CreatePlayerTextDraw(playerid, 320.000, 379.000, "Int:~y~7_~w~WID:~y~15");
    PlayerTextDrawLetterSize(playerid, SpectatorInfoTD[playerid][5], 0.328, 1.500);
    PlayerTextDrawAlignment(playerid, SpectatorInfoTD[playerid][5], 2);
    PlayerTextDrawColor(playerid, SpectatorInfoTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, SpectatorInfoTD[playerid][5], 1);
    PlayerTextDrawSetOutline(playerid, SpectatorInfoTD[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, SpectatorInfoTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, SpectatorInfoTD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, SpectatorInfoTD[playerid][5], 1);

    SpectatorInfoTD[playerid][6] = CreatePlayerTextDraw(playerid, 320.000, 394.000, "Keys:~y~_0");
    PlayerTextDrawLetterSize(playerid, SpectatorInfoTD[playerid][6], 0.328, 1.500);
    PlayerTextDrawAlignment(playerid, SpectatorInfoTD[playerid][6], 2);
    PlayerTextDrawColor(playerid, SpectatorInfoTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, SpectatorInfoTD[playerid][6], 1);
    PlayerTextDrawSetOutline(playerid, SpectatorInfoTD[playerid][6], 1);
    PlayerTextDrawBackgroundColor(playerid, SpectatorInfoTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, SpectatorInfoTD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, SpectatorInfoTD[playerid][6], 1);

    SpectatorInfoTD[playerid][7] = CreatePlayerTextDraw(playerid, 320.000, 412.000, "FPS:~y~_52_~w~Ping:~y~_102ms");
    PlayerTextDrawLetterSize(playerid, SpectatorInfoTD[playerid][7], 0.328, 1.500);
    PlayerTextDrawAlignment(playerid, SpectatorInfoTD[playerid][7], 2);
    PlayerTextDrawColor(playerid, SpectatorInfoTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, SpectatorInfoTD[playerid][7], 1);
    PlayerTextDrawSetOutline(playerid, SpectatorInfoTD[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, SpectatorInfoTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, SpectatorInfoTD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, SpectatorInfoTD[playerid][7], 1);
    
    // Footer
    ATRP_Footer[playerid] = CreatePlayerTextDraw(playerid, 231.000, 379.000, "Faggio ~g~Terbuka");
    PlayerTextDrawLetterSize(playerid, ATRP_Footer[playerid], 0.180, 1.299);
    PlayerTextDrawAlignment(playerid, ATRP_Footer[playerid], 1);
    PlayerTextDrawColor(playerid, ATRP_Footer[playerid], -1);
    PlayerTextDrawSetShadow(playerid, ATRP_Footer[playerid], 1);
    PlayerTextDrawSetOutline(playerid, ATRP_Footer[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, ATRP_Footer[playerid], 150);
    PlayerTextDrawFont(playerid, ATRP_Footer[playerid], 1);
    PlayerTextDrawSetProportional(playerid, ATRP_Footer[playerid], 1);

    // FPS
    FPStextdraws[playerid][0] = CreatePlayerTextDraw(playerid, 8.000, 213.000, "~r~FPS:_~w~52~n~~r~PL:_~w~0.15");
    PlayerTextDrawLetterSize(playerid, FPStextdraws[playerid][0], 0.270, 1.399);
    PlayerTextDrawAlignment(playerid, FPStextdraws[playerid][0], 1);
    PlayerTextDrawColor(playerid, FPStextdraws[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, FPStextdraws[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, FPStextdraws[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, FPStextdraws[playerid][0], 150);
    PlayerTextDrawFont(playerid, FPStextdraws[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, FPStextdraws[playerid][0], 1);
    
    // Kartu Tanda Anggota
    KTAtextdraws[playerid][0] = CreatePlayerTextDraw(playerid, 361.000, 210.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][0], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][0], 16.500, 20.500);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][0], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][0], -1061109505);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][0], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][0], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][0], 1);

    KTAtextdraws[playerid][1] = CreatePlayerTextDraw(playerid, 361.000, 322.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][1], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][1], 18.000, 17.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][1], 2);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][1], -1061109505);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][1], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][1], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][1], 1);

    KTAtextdraws[playerid][2] = CreatePlayerTextDraw(playerid, 511.000, 322.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][2], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][2], 17.000, 17.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][2], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][2], -1061109505);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][2], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][2], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][2], 1);

    KTAtextdraws[playerid][3] = CreatePlayerTextDraw(playerid, 511.000, 211.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][3], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][3], 17.000, 17.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][3], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][3], -1061109505);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][3], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][3], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][3], 1);

    KTAtextdraws[playerid][4] = CreatePlayerTextDraw(playerid, 369.000, 293.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][4], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][4], 148.500, 43.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][4], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][4], -1061109505);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][4], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][4], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][4], 1);

    KTAtextdraws[playerid][5] = CreatePlayerTextDraw(playerid, 367.000, 293.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][5], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][5], 151.500, -79.500);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][5], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][5], -1061109505);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][5], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][5], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][5], 1);

    KTAtextdraws[playerid][6] = CreatePlayerTextDraw(playerid, 364.000, 220.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][6], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][6], 161.000, 109.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][6], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][6], -1061109505);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][6], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][6], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][6], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][6], 1);

    KTAtextdraws[playerid][7] = CreatePlayerTextDraw(playerid, 377.000, 234.000, "V");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][7], 0.449, -1.799);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][7], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][7], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][7], 1);

    KTAtextdraws[playerid][8] = CreatePlayerTextDraw(playerid, 361.000, 322.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][8], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][8], 18.000, 17.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][8], 2);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][8], -16776961);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][8], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][8], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][8], 1);

    KTAtextdraws[playerid][9] = CreatePlayerTextDraw(playerid, 364.000, 318.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][9], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][9], 161.000, 14.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][9], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][9], -16776961);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][9], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][9], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][9], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][9], 1);

    KTAtextdraws[playerid][10] = CreatePlayerTextDraw(playerid, 370.000, 322.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][10], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][10], 148.000, 14.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][10], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][10], -16776961);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][10], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][10], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][10], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][10], 1);

    KTAtextdraws[playerid][11] = CreatePlayerTextDraw(playerid, 511.000, 322.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][11], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][11], 17.000, 17.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][11], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][11], -16776961);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][11], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][11], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][11], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][11], 1);

    KTAtextdraws[playerid][12] = CreatePlayerTextDraw(playerid, 377.000, 234.000, "V");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][12], 0.439, -1.799);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][12], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][12], -260013825);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][12], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][12], 1);

    KTAtextdraws[playerid][13] = CreatePlayerTextDraw(playerid, 373.000, 232.000, "/");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][13], 0.330, 0.999);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][13], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][13], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][13], 1);

    KTAtextdraws[playerid][14] = CreatePlayerTextDraw(playerid, 373.200, 232.000, "/");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][14], 0.330, 0.999);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][14], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][14], -260013825);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][14], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][14], 1);

    KTAtextdraws[playerid][15] = CreatePlayerTextDraw(playerid, 374.000, 233.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][15], 8.000, -2.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][15], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][15], 255);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][15], 1);

    KTAtextdraws[playerid][16] = CreatePlayerTextDraw(playerid, 374.299, 233.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][16], 8.199, -1.700);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][16], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][16], -260013825);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][16], 255);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][16], 1);

    KTAtextdraws[playerid][17] = CreatePlayerTextDraw(playerid, 377.000, 232.000, "/");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][17], 0.330, 0.999);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][17], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][17], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][17], 1);

    KTAtextdraws[playerid][18] = CreatePlayerTextDraw(playerid, 377.200, 232.000, "/");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][18], 0.330, 0.999);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][18], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][18], -260013825);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][18], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][18], 1);

    KTAtextdraws[playerid][19] = CreatePlayerTextDraw(playerid, 382.000, 238.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][19], 2.000, -2.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][19], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][19], 255);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][19], 1);

    KTAtextdraws[playerid][20] = CreatePlayerTextDraw(playerid, 382.299, 238.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][20], 3.197, -1.700);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][20], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][20], -260013825);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][20], 255);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][20], 1);

    KTAtextdraws[playerid][21] = CreatePlayerTextDraw(playerid, 384.000, 231.000, "/");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][21], 0.270, 0.698);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][21], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][21], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][21], 1);

    KTAtextdraws[playerid][22] = CreatePlayerTextDraw(playerid, 384.000, 231.000, "/");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][22], 0.270, 0.698);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][22], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][22], -260013825);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][22], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][22], 1);

    KTAtextdraws[playerid][23] = CreatePlayerTextDraw(playerid, 391.000, 231.000, "/");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][23], -0.349, 0.796);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][23], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][23], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][23], 1);

    KTAtextdraws[playerid][24] = CreatePlayerTextDraw(playerid, 391.000, 231.000, "/");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][24], -0.349, 0.796);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][24], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][24], -260013825);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][24], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][24], 1);

    KTAtextdraws[playerid][25] = CreatePlayerTextDraw(playerid, 443.000, 217.000, "Kepolisian Kota DCRP");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][25], 0.189, 1.098);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][25], 2);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][25], 255);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][25], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][25], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][25], 1);

    KTAtextdraws[playerid][26] = CreatePlayerTextDraw(playerid, 387.000, 228.000, "/");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][26], -0.349, 0.796);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][26], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][26], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][26], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][26], 1);

    KTAtextdraws[playerid][27] = CreatePlayerTextDraw(playerid, 387.000, 228.000, "/");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][27], -0.349, 0.796);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][27], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][27], -260013825);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][27], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][27], 1);

    KTAtextdraws[playerid][28] = CreatePlayerTextDraw(playerid, 443.000, 227.000, "KARTU TANDA ANGGOTA");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][28], 0.209, 1.399);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][28], 2);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][28], 255);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][28], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][28], 1);

    KTAtextdraws[playerid][29] = CreatePlayerTextDraw(playerid, 372.000, 264.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][29], 20.000, 6.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][29], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][29], -626712321);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][29], 255);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][29], 1);

    KTAtextdraws[playerid][30] = CreatePlayerTextDraw(playerid, 372.000, 271.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][30], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][30], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][30], -626712321);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][30], 255);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][30], 1);

    KTAtextdraws[playerid][31] = CreatePlayerTextDraw(playerid, 379.000, 271.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][31], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][31], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][31], -626712321);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][31], 255);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][31], 1);

    KTAtextdraws[playerid][32] = CreatePlayerTextDraw(playerid, 386.000, 271.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][32], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][32], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][32], -626712321);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][32], 255);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][32], 1);

    KTAtextdraws[playerid][33] = CreatePlayerTextDraw(playerid, 372.000, 278.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][33], 20.000, 6.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][33], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][33], -626712321);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][33], 255);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][33], 1);

    KTAtextdraws[playerid][34] = CreatePlayerTextDraw(playerid, 396.000, 261.000, "Cecep_Sugeni");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][34], 0.189, 1.299);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][34], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][34], 255);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][34], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][34], 1);

    KTAtextdraws[playerid][35] = CreatePlayerTextDraw(playerid, 396.000, 274.000, "Wadir Umum");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][35], 0.200, 1.299);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][35], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][35], 255);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][35], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][35], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][35], 1);

    KTAtextdraws[playerid][36] = CreatePlayerTextDraw(playerid, 443.000, 238.000, "_");
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][36], 94.000, 94.000);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][36], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][36], 0);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][36], 5);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][36], 0);
    PlayerTextDrawSetPreviewModel(playerid, KTAtextdraws[playerid][36], 281);
    PlayerTextDrawSetPreviewRot(playerid, KTAtextdraws[playerid][36], -7.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, KTAtextdraws[playerid][36], 0, 0);

    KTAtextdraws[playerid][37] = CreatePlayerTextDraw(playerid, 470.000, 294.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][37], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][37], 39.500, 24.500);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][37], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][37], -1061109505);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][37], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][37], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][37], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][37], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][37], 1);

    KTAtextdraws[playerid][38] = CreatePlayerTextDraw(playerid, 475.000, 318.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][38], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, KTAtextdraws[playerid][38], 39.500, 14.500);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][38], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][38], -16776961);
    PlayerTextDrawUseBox(playerid, KTAtextdraws[playerid][38], 1);
    PlayerTextDrawBoxColor(playerid, KTAtextdraws[playerid][38], 50);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][38], 1);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][38], -789973249);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][38], 1);

    KTAtextdraws[playerid][39] = CreatePlayerTextDraw(playerid, 369.000, 307.000, "7263 1231 0082 2321");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][39], 0.129, 0.898);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][39], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][39], 255);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][39], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][39], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][39], 1);

    KTAtextdraws[playerid][40] = CreatePlayerTextDraw(playerid, 369.000, 322.000, "INI ADALAH KARTU TANDA ANGGOTA, KEASLIAN KEANGGOTAAN SESEORANG");
    PlayerTextDrawLetterSize(playerid, KTAtextdraws[playerid][40], 0.119, 0.898);
    PlayerTextDrawAlignment(playerid, KTAtextdraws[playerid][40], 1);
    PlayerTextDrawColor(playerid, KTAtextdraws[playerid][40], 255);
    PlayerTextDrawSetShadow(playerid, KTAtextdraws[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, KTAtextdraws[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, KTAtextdraws[playerid][40], 150);
    PlayerTextDrawFont(playerid, KTAtextdraws[playerid][40], 1);
    PlayerTextDrawSetProportional(playerid, KTAtextdraws[playerid][40], 1);

    /* Watermark
    Watermarktextdraws[playerid][0] = CreatePlayerTextDraw(playerid, 324.000, 19.000, "V");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][0], 0.449, -1.799);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][0], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][0], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][0], 1);

    Watermarktextdraws[playerid][1] = CreatePlayerTextDraw(playerid, 324.000, 19.000, "V");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][1], 0.439, -1.799);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][1], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][1], -260013825);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][1], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][1], 1);

    Watermarktextdraws[playerid][2] = CreatePlayerTextDraw(playerid, 320.000, 17.000, "/");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][2], 0.330, 0.999);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][2], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][2], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][2], 1);

    Watermarktextdraws[playerid][3] = CreatePlayerTextDraw(playerid, 320.200, 17.000, "/");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][3], 0.330, 0.999);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][3], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][3], -260013825);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][3], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][3], 1);

    Watermarktextdraws[playerid][4] = CreatePlayerTextDraw(playerid, 321.000, 18.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Watermarktextdraws[playerid][4], 8.000, -2.000);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][4], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][4], 255);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][4], 1);

    Watermarktextdraws[playerid][5] = CreatePlayerTextDraw(playerid, 321.299, 18.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Watermarktextdraws[playerid][5], 8.199, -1.700);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][5], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][5], -260013825);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][5], 255);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][5], 1);

    Watermarktextdraws[playerid][6] = CreatePlayerTextDraw(playerid, 324.000, 17.000, "/");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][6], 0.330, 0.999);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][6], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][6], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][6], 1);

    Watermarktextdraws[playerid][7] = CreatePlayerTextDraw(playerid, 324.200, 17.000, "/");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][7], 0.330, 0.999);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][7], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][7], -260013825);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][7], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][7], 1);

    Watermarktextdraws[playerid][8] = CreatePlayerTextDraw(playerid, 329.000, 23.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Watermarktextdraws[playerid][8], 2.000, -2.000);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][8], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][8], 255);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][8], 1);

    Watermarktextdraws[playerid][9] = CreatePlayerTextDraw(playerid, 329.299, 23.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Watermarktextdraws[playerid][9], 3.198, -1.700);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][9], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][9], -260013825);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][9], 255);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][9], 1);

    Watermarktextdraws[playerid][10] = CreatePlayerTextDraw(playerid, 331.000, 16.000, "/");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][10], 0.270, 0.698);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][10], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][10], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][10], 1);

    Watermarktextdraws[playerid][11] = CreatePlayerTextDraw(playerid, 331.000, 16.000, "/");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][11], 0.270, 0.698);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][11], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][11], -260013825);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][11], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][11], 1);

    Watermarktextdraws[playerid][12] = CreatePlayerTextDraw(playerid, 338.000, 16.000, "/");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][12], -0.349, 0.797);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][12], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][12], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][12], 1);

    Watermarktextdraws[playerid][13] = CreatePlayerTextDraw(playerid, 338.000, 16.000, "/");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][13], -0.349, 0.797);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][13], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][13], -260013825);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][13], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][13], 1);

    Watermarktextdraws[playerid][14] = CreatePlayerTextDraw(playerid, 328.799, 25.798, "DCRP");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][14], 0.270, 1.098);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][14], 2);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][14], -260013825);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][14], -92245249);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][14], 1);

    Watermarktextdraws[playerid][15] = CreatePlayerTextDraw(playerid, 334.000, 13.000, "/");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][15], -0.349, 0.797);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][15], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][15], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][15], 1);

    Watermarktextdraws[playerid][16] = CreatePlayerTextDraw(playerid, 334.000, 13.000, "/");
    PlayerTextDrawLetterSize(playerid, Watermarktextdraws[playerid][16], -0.349, 0.797);
    PlayerTextDrawAlignment(playerid, Watermarktextdraws[playerid][16], 1);
    PlayerTextDrawColor(playerid, Watermarktextdraws[playerid][16], -260013825);
    PlayerTextDrawSetShadow(playerid, Watermarktextdraws[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, Watermarktextdraws[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, Watermarktextdraws[playerid][16], 150);
    PlayerTextDrawFont(playerid, Watermarktextdraws[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, Watermarktextdraws[playerid][16], 1);*/

    // Taxi Argo
    PlayerTextdraws[playerid][textdraw_taxi][0] = CreatePlayerTextDraw(playerid, 67.000, 176.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PlayerTextdraws[playerid][textdraw_taxi][0], 81.000, 38.000);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_taxi][0], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_taxi][0], 150);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_taxi][0], 0);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_taxi][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_taxi][0], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_taxi][0], 4);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_taxi][0], 1);

    PlayerTextdraws[playerid][textdraw_taxi][1] = CreatePlayerTextDraw(playerid, 86.000, 179.000, "Taxi Argo");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_taxi][1], 0.240, 0.999);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_taxi][1], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_taxi][1], -1);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_taxi][1], 1);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_taxi][1], 1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_taxi][1], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_taxi][1], 3);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_taxi][1], 1);

    PlayerTextdraws[playerid][textdraw_taxi][2] = CreatePlayerTextDraw(playerid, 73.000, 194.000, "$55");
    PlayerTextDrawLetterSize(playerid, PlayerTextdraws[playerid][textdraw_taxi][2], 0.240, 0.999);
    PlayerTextDrawAlignment(playerid, PlayerTextdraws[playerid][textdraw_taxi][2], 1);
    PlayerTextDrawColor(playerid, PlayerTextdraws[playerid][textdraw_taxi][2], -1);
    PlayerTextDrawSetShadow(playerid, PlayerTextdraws[playerid][textdraw_taxi][2], 1);
    PlayerTextDrawSetOutline(playerid, PlayerTextdraws[playerid][textdraw_taxi][2], 1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTextdraws[playerid][textdraw_taxi][2], 255);
    PlayerTextDrawFont(playerid, PlayerTextdraws[playerid][textdraw_taxi][2], 1);
    PlayerTextDrawSetProportional(playerid, PlayerTextdraws[playerid][textdraw_taxi][2], 1);

    SpedoJaden[playerid][0] = CreatePlayerTextDraw(playerid, 290.000, 695.000, "Gambar teks baru");
    PlayerTextDrawLetterSize(playerid, SpedoJaden[playerid][0], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][0], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][0], 150);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][0], 1);

    SpedoJaden[playerid][1] = CreatePlayerTextDraw(playerid, 147.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][1], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][1], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][1], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][1], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][1], 1);

    SpedoJaden[playerid][2] = CreatePlayerTextDraw(playerid, 150.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][2], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][2], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][2], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][2], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][2], 1);

    SpedoJaden[playerid][3] = CreatePlayerTextDraw(playerid, 153.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][3], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][3], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][3], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][3], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][3], 1);

    SpedoJaden[playerid][4] = CreatePlayerTextDraw(playerid, 156.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][4], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][4], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][4], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][4], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][4], 1);

    SpedoJaden[playerid][5] = CreatePlayerTextDraw(playerid, 159.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][5], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][5], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][5], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][5], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][5], 1);

    SpedoJaden[playerid][6] = CreatePlayerTextDraw(playerid, 162.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][6], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][6], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][6], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][6], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][6], 1);

    SpedoJaden[playerid][7] = CreatePlayerTextDraw(playerid, 165.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][7], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][7], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][7], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][7], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][7], 1);

    SpedoJaden[playerid][8] = CreatePlayerTextDraw(playerid, 168.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][8], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][8], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][8], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][8], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][8], 1);

    SpedoJaden[playerid][9] = CreatePlayerTextDraw(playerid, 171.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][9], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][9], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][9], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][9], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][9], 1);

    SpedoJaden[playerid][10] = CreatePlayerTextDraw(playerid, 174.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][10], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][10], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][10], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][10], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][10], 1);

    SpedoJaden[playerid][11] = CreatePlayerTextDraw(playerid, 177.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][11], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][11], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][11], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][11], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][11], 1);

    SpedoJaden[playerid][12] = CreatePlayerTextDraw(playerid, 180.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][12], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][12], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][12], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][12], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][12], 1);

    SpedoJaden[playerid][13] = CreatePlayerTextDraw(playerid, 183.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][13], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][13], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][13], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][13], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][13], 1);

    SpedoJaden[playerid][14] = CreatePlayerTextDraw(playerid, 186.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][14], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][14], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][14], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][14], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][14], 1);

    SpedoJaden[playerid][15] = CreatePlayerTextDraw(playerid, 189.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][15], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][15], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][15], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][15], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][15], 1);

    SpedoJaden[playerid][16] = CreatePlayerTextDraw(playerid, 192.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][16], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][16], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][16], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][16], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][16], 1);

    SpedoJaden[playerid][17] = CreatePlayerTextDraw(playerid, 195.000, 417.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][17], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][17], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][17], 100);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][17], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][17], 1);

    SpedoJaden[playerid][18] = CreatePlayerTextDraw(playerid, 199.000, 399.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][18], 3.000, 38.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][18], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][18], 572729343);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][18], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][18], 1);

    SpedoJaden[playerid][19] = CreatePlayerTextDraw(playerid, 200.000, 436.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][19], 1.000, -36.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][19], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][19], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][19], 1);

    SpedoJaden[playerid][20] = CreatePlayerTextDraw(playerid, 147.000, 398.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][20], 11.000, 16.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][20], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][20], 502316031);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][20], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][20], 1);

    SpedoJaden[playerid][21] = CreatePlayerTextDraw(playerid, 151.000, 399.000, "D");
    PlayerTextDrawLetterSize(playerid, SpedoJaden[playerid][21], 0.140, 0.699);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][21], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][21], 572729343);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][21], 150);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][21], 1);

    SpedoJaden[playerid][22] = CreatePlayerTextDraw(playerid, 152.000, 404.000, "l");
    PlayerTextDrawLetterSize(playerid, SpedoJaden[playerid][22], 0.140, 0.999);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][22], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][22], 572729343);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][22], 150);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][22], 1);

    SpedoJaden[playerid][23] = CreatePlayerTextDraw(playerid, 152.000, 404.000, "-");
    PlayerTextDrawLetterSize(playerid, SpedoJaden[playerid][23], 0.200, 0.799);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][23], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][23], 572729343);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][23], 150);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][23], 1);

    SpedoJaden[playerid][24] = CreatePlayerTextDraw(playerid, 166.000, 398.000, "024");
    PlayerTextDrawLetterSize(playerid, SpedoJaden[playerid][24], 0.238, 1.500);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][24], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][24], 150);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][24], 2);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][24], 1);

    SpedoJaden[playerid][25] = CreatePlayerTextDraw(playerid, 183.000, 393.000, "MPH");
    PlayerTextDrawLetterSize(playerid, SpedoJaden[playerid][25], 0.119, 0.799);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][25], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][25], 150);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][25], 2);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][25], 1);

    SpedoJaden[playerid][26] = CreatePlayerTextDraw(playerid, 199.000, 394.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][26], 4.000, 4.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][26], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][26], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][26], 1);

    SpedoJaden[playerid][27] = CreatePlayerTextDraw(playerid, 199.000, 391.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][27], 1.000, 3.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][27], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][27], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][27], 1);

    SpedoJaden[playerid][28] = CreatePlayerTextDraw(playerid, 199.000, 390.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][28], 1.000, 4.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][28], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][28], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][28], 1);

    SpedoJaden[playerid][29] = CreatePlayerTextDraw(playerid, 202.000, 390.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][29], 1.000, 4.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][29], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][29], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][29], 1);

    SpedoJaden[playerid][30] = CreatePlayerTextDraw(playerid, 200.000, 390.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][30], 3.000, 1.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][30], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][30], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][30], 1);

    SpedoJaden[playerid][31] = CreatePlayerTextDraw(playerid, 202.000, 389.000, "2");
    PlayerTextDrawLetterSize(playerid, SpedoJaden[playerid][31], 0.128, 0.799);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][31], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][31], 150);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][31], 1);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][31], 1);

    SpedoJaden[playerid][32] = CreatePlayerTextDraw(playerid, 200.000, 397.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpedoJaden[playerid][32], 4.000, 1.000);
    PlayerTextDrawAlignment(playerid, SpedoJaden[playerid][32], 1);
    PlayerTextDrawColor(playerid, SpedoJaden[playerid][32], -1);
    PlayerTextDrawSetShadow(playerid, SpedoJaden[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, SpedoJaden[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, SpedoJaden[playerid][32], 255);
    PlayerTextDrawFont(playerid, SpedoJaden[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, SpedoJaden[playerid][32], 1);

    // Katepeh
    ktpTextdraws[playerid][0] = CreatePlayerTextDraw(playerid, 352.000, 223.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][0], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][0], 16.500, 20.500);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][0], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][0], 1671806975);
    PlayerTextDrawUseBox(playerid, ktpTextdraws[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, ktpTextdraws[playerid][0], 50);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][0], -789973249);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][0], 1);

    ktpTextdraws[playerid][1] = CreatePlayerTextDraw(playerid, 352.000, 335.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][1], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][1], 18.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][1], 2);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][1], 1671806975);
    PlayerTextDrawUseBox(playerid, ktpTextdraws[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, ktpTextdraws[playerid][1], 50);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][1], -789973249);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][1], 1);

    ktpTextdraws[playerid][2] = CreatePlayerTextDraw(playerid, 502.000, 335.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][2], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][2], 17.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][2], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][2], 1671806975);
    PlayerTextDrawUseBox(playerid, ktpTextdraws[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, ktpTextdraws[playerid][2], 50);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][2], -789973249);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][2], 1);

    ktpTextdraws[playerid][3] = CreatePlayerTextDraw(playerid, 502.000, 224.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][3], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][3], 17.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][3], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][3], 1671806975);
    PlayerTextDrawUseBox(playerid, ktpTextdraws[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, ktpTextdraws[playerid][3], 50);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][3], -789973249);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][3], 1);

    ktpTextdraws[playerid][4] = CreatePlayerTextDraw(playerid, 360.000, 306.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][4], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][4], 148.500, 43.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][4], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][4], 1671806975);
    PlayerTextDrawUseBox(playerid, ktpTextdraws[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, ktpTextdraws[playerid][4], 50);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][4], -789973249);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][4], 1);

    ktpTextdraws[playerid][5] = CreatePlayerTextDraw(playerid, 358.000, 306.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][5], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][5], 151.500, -79.500);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][5], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][5], 1671806975);
    PlayerTextDrawUseBox(playerid, ktpTextdraws[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, ktpTextdraws[playerid][5], 50);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][5], -789973249);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][5], 1);

    ktpTextdraws[playerid][6] = CreatePlayerTextDraw(playerid, 355.000, 233.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][6], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][6], 161.000, 109.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][6], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][6], 1671806975);
    PlayerTextDrawUseBox(playerid, ktpTextdraws[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, ktpTextdraws[playerid][6], 50);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][6], 1);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][6], -789973249);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][6], 1);

    ktpTextdraws[playerid][7] = CreatePlayerTextDraw(playerid, 400.000, 276.000, "TANGGAL_LAHIR");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][7], 0.136, 1.049);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][7], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][7], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][7], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][7], 1);

    ktpTextdraws[playerid][8] = CreatePlayerTextDraw(playerid, 372.000, 255.000, "/");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][8], 0.554, 2.697);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][8], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][8], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][8], -261923073);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][8], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][8], 1);

    ktpTextdraws[playerid][9] = CreatePlayerTextDraw(playerid, 379.000, 255.000, "\\");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][9], 0.554, 2.697);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][9], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][9], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][9], -261923073);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][9], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][9], 1);

    ktpTextdraws[playerid][10] = CreatePlayerTextDraw(playerid, 398.000, 250.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][10], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][10], 118.000, 14.500);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][10], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][10], -16776961);
    PlayerTextDrawUseBox(playerid, ktpTextdraws[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, ktpTextdraws[playerid][10], 50);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][10], 1);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][10], -789973249);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][10], 1);

    ktpTextdraws[playerid][11] = CreatePlayerTextDraw(playerid, 398.000, 264.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][11], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][11], 118.000, 13.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][11], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, ktpTextdraws[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, ktpTextdraws[playerid][11], 50);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][11], 1);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][11], -789973249);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][11], 1);

    ktpTextdraws[playerid][12] = CreatePlayerTextDraw(playerid, 407.000, 226.000, "KARTU_TANDA_PENDUDUK");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][12], 0.143, 1.149);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][12], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][12], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][12], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][12], 1);

    ktpTextdraws[playerid][13] = CreatePlayerTextDraw(playerid, 404.000, 234.000, "PEMERINTAH_KOTA_DCRP");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][13], 0.150, 1.299);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][13], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][13], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][13], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][13], 1);

    ktpTextdraws[playerid][14] = CreatePlayerTextDraw(playerid, 402.000, 255.000, "Christian_Snouck");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][14], 0.143, 1.649);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][14], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][14], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][14], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][14], 2);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][14], 1);

    ktpTextdraws[playerid][15] = CreatePlayerTextDraw(playerid, 453.000, 276.000, "KELAMIN");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][15], 0.133, 0.999);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][15], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][15], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][15], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][15], 1);

    ktpTextdraws[playerid][16] = CreatePlayerTextDraw(playerid, 490.000, 276.000, "TINGGI");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][16], 0.143, 1.049);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][16], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][16], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][16], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][16], 1);

    ktpTextdraws[playerid][17] = CreatePlayerTextDraw(playerid, 400.000, 294.000, "TANDA_TANGAN");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][17], 0.115, 1.049);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][17], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][17], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][17], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][17], 1);

    ktpTextdraws[playerid][18] = CreatePlayerTextDraw(playerid, 405.000, 283.000, "19-10-2001");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][18], 0.123, 0.898);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][18], 465.500, 10.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][18], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][18], -667137);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][18], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][18], 1);

    ktpTextdraws[playerid][19] = CreatePlayerTextDraw(playerid, 456.000, 283.000, "MALE");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][19], 0.143, 0.949);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][19], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][19], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][19], -667137);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][19], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][19], 1);

    ktpTextdraws[playerid][20] = CreatePlayerTextDraw(playerid, 494.000, 283.000, "165");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][20], 0.143, 0.949);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][20], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][20], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][20], -667137);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][20], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][20], 1);

    ktpTextdraws[playerid][21] = CreatePlayerTextDraw(playerid, 405.000, 303.000, "CHRIS");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][21], 0.189, 1.149);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][21], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][21], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][21], -667137);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][21], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][21], 0);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][21], 1);

    ktpTextdraws[playerid][22] = CreatePlayerTextDraw(playerid, 365.000, 314.000, "BERLAKU_SEUMUR_HIDUP");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][22], 0.158, 1.098);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][22], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][22], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][22], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][22], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][22], 1);

    ktpTextdraws[playerid][23] = CreatePlayerTextDraw(playerid, 365.000, 322.000, "KARTU_TANDA_PENDUDUK_INI_RESMI_DIKELUARKAN_PEMERINTAH_DCRP");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][23], 0.112, 0.898);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][23], 620.000, 20.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][23], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][23], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][23], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][23], 1);

    ktpTextdraws[playerid][24] = CreatePlayerTextDraw(playerid, 365.000, 329.000, "MENJADI_BUKTI_BAHWA_YANG_BERSANGKUTAN_MEMILIKI_HAK_DAN_KEWAJIBAN");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][24], 0.112, 0.898);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][24], 620.000, 20.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][24], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][24], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][24], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][24], 1);

    ktpTextdraws[playerid][25] = CreatePlayerTextDraw(playerid, 365.000, 336.000, "SEBAGAI_WARGA_DCRP");
    PlayerTextDrawLetterSize(playerid, ktpTextdraws[playerid][25], 0.112, 0.898);
    PlayerTextDrawTextSize(playerid, ktpTextdraws[playerid][25], 620.000, 20.000);
    PlayerTextDrawAlignment(playerid, ktpTextdraws[playerid][25], 1);
    PlayerTextDrawColor(playerid, ktpTextdraws[playerid][25], 255);
    PlayerTextDrawSetShadow(playerid, ktpTextdraws[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, ktpTextdraws[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, ktpTextdraws[playerid][25], 255);
    PlayerTextDrawFont(playerid, ktpTextdraws[playerid][25], 1);
    PlayerTextDrawSetProportional(playerid, ktpTextdraws[playerid][25], 1);

    // ATM Textdraw
    ATMTD[playerid][0] = CreatePlayerTextDraw(playerid, 291.000, 718.000, "Gambar teks baru");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][0], 0.300, 1.500);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][0], 1);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][0], 1);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][0], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][0], 1);

	ATMTD[playerid][1] = CreatePlayerTextDraw(playerid, -1.000, 0.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][1], 675.000, 453.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][1], 150);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][1], 1);

	ATMTD[playerid][2] = CreatePlayerTextDraw(playerid, 201.000, 93.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][2], 11.000, 13.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][2], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][2], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][2], 1);

	ATMTD[playerid][3] = CreatePlayerTextDraw(playerid, 201.000, 157.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][3], 11.000, 13.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][3], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][3], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][3], 1);

	ATMTD[playerid][4] = CreatePlayerTextDraw(playerid, 290.000, 93.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][4], 11.000, 13.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][4], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][4], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][4], 1);

	ATMTD[playerid][5] = CreatePlayerTextDraw(playerid, 290.000, 157.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][5], 11.000, 13.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][5], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][5], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][5], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][5], 1);

	ATMTD[playerid][6] = CreatePlayerTextDraw(playerid, 203.000, 100.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][6], 96.000, 63.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][6], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][6], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][6], 1);

	ATMTD[playerid][7] = CreatePlayerTextDraw(playerid, 207.000, 95.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][7], 88.000, 63.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][7], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][7], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][7], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][7], 1);

	ATMTD[playerid][8] = CreatePlayerTextDraw(playerid, 207.000, 105.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][8], 88.000, 63.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][8], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][8], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][8], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][8], 1);

	ATMTD[playerid][9] = CreatePlayerTextDraw(playerid, 298.000, 76.000, "l");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][9], 0.189, 11.500);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][9], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][9], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][9], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][9], 1);

	ATMTD[playerid][10] = CreatePlayerTextDraw(playerid, 298.000, 76.000, "l");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][10], 0.189, 11.500);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][10], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][10], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][10], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][10], 1);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][10], 1);

	ATMTD[playerid][11] = CreatePlayerTextDraw(playerid, 333.000, 93.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][11], 11.000, 13.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][11], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][11], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][11], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][11], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][11], 1);

	ATMTD[playerid][12] = CreatePlayerTextDraw(playerid, 333.000, 130.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][12], 11.000, 13.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][12], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][12], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][12], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][12], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][12], 1);

	ATMTD[playerid][13] = CreatePlayerTextDraw(playerid, 434.000, 93.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][13], 11.000, 13.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][13], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][13], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][13], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][13], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][13], 1);

	ATMTD[playerid][14] = CreatePlayerTextDraw(playerid, 411.000, 102.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][14], 39.000, 47.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][14], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][14], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][14], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][14], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][14], 1);

	ATMTD[playerid][15] = CreatePlayerTextDraw(playerid, 335.000, 100.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][15], 96.000, 36.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][15], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][15], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][15], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][15], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][15], 1);

	ATMTD[playerid][16] = CreatePlayerTextDraw(playerid, 338.000, 105.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][16], 90.000, 36.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][16], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][16], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][16], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][16], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][16], 1);

	ATMTD[playerid][17] = CreatePlayerTextDraw(playerid, 339.000, 95.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][17], 100.000, 36.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][17], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][17], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][17], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][17], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][17], 1);

	ATMTD[playerid][18] = CreatePlayerTextDraw(playerid, 343.000, 99.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][18], 100.000, 24.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][18], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][18], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][18], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][18], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][18], 1);

	ATMTD[playerid][19] = CreatePlayerTextDraw(playerid, 424.000, 133.000, ".");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][19], 0.778, 1.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][19], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][19], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][19], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][19], 1);

	ATMTD[playerid][20] = CreatePlayerTextDraw(playerid, 442.000, 89.000, "l");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][20], 0.189, 4.598);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][20], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][20], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][20], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][20], 1);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][20], 1);

	ATMTD[playerid][21] = CreatePlayerTextDraw(playerid, 426.000, 133.000, ".");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][21], 0.778, 1.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][21], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][21], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][21], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][21], 1);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][21], 1);

	ATMTD[playerid][22] = CreatePlayerTextDraw(playerid, 425.000, 133.000, ".");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][22], 0.778, 1.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][22], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][22], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][22], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][22], 1);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][22], 1);

	ATMTD[playerid][23] = CreatePlayerTextDraw(playerid, 202.000, 200.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][23], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][23], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][23], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][23], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][23], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][23], 1);

	ATMTD[playerid][24] = CreatePlayerTextDraw(playerid, 202.000, 213.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][24], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][24], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][24], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][24], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][24], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][24], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][24], 1);

	ATMTD[playerid][25] = CreatePlayerTextDraw(playerid, 212.000, 213.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][25], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][25], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][25], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][25], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][25], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][25], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][25], 1);

	ATMTD[playerid][26] = CreatePlayerTextDraw(playerid, 212.000, 200.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][26], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][26], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][26], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][26], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][26], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][26], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][26], 1);

	ATMTD[playerid][27] = CreatePlayerTextDraw(playerid, 203.000, 203.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][27], 14.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][27], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][27], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][27], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][27], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][27], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][27], 1);

	ATMTD[playerid][28] = CreatePlayerTextDraw(playerid, 205.000, 201.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][28], 10.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][28], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][28], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][28], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][28], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][28], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][28], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][28], 1);

	ATMTD[playerid][29] = CreatePlayerTextDraw(playerid, 205.000, 205.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][29], 10.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][29], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][29], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][29], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][29], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][29], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][29], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][29], 1);

	ATMTD[playerid][30] = CreatePlayerTextDraw(playerid, 202.000, 175.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][30], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][30], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][30], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][30], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][30], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][30], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][30], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][30], 1);

	ATMTD[playerid][31] = CreatePlayerTextDraw(playerid, 202.000, 188.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][31], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][31], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][31], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][31], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][31], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][31], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][31], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][31], 1);

	ATMTD[playerid][32] = CreatePlayerTextDraw(playerid, 212.000, 188.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][32], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][32], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][32], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][32], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][32], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][32], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][32], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][32], 1);

	ATMTD[playerid][33] = CreatePlayerTextDraw(playerid, 212.000, 175.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][33], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][33], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][33], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][33], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][33], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][33], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][33], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][33], 1);

	ATMTD[playerid][34] = CreatePlayerTextDraw(playerid, 203.000, 178.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][34], 14.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][34], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][34], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][34], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][34], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][34], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][34], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][34], 1);

	ATMTD[playerid][35] = CreatePlayerTextDraw(playerid, 205.000, 176.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][35], 10.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][35], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][35], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][35], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][35], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][35], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][35], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][35], 1);

	ATMTD[playerid][36] = CreatePlayerTextDraw(playerid, 205.000, 180.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][36], 10.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][36], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][36], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][36], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][36], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][36], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][36], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][36], 1);

	ATMTD[playerid][37] = CreatePlayerTextDraw(playerid, 202.000, 225.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][37], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][37], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][37], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][37], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][37], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][37], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][37], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][37], 1);

	ATMTD[playerid][38] = CreatePlayerTextDraw(playerid, 202.000, 238.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][38], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][38], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][38], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][38], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][38], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][38], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][38], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][38], 1);

	ATMTD[playerid][39] = CreatePlayerTextDraw(playerid, 212.000, 238.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][39], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][39], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][39], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][39], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][39], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][39], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][39], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][39], 1);

	ATMTD[playerid][40] = CreatePlayerTextDraw(playerid, 212.000, 225.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][40], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][40], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][40], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][40], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][40], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][40], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][40], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][40], 1);

	ATMTD[playerid][41] = CreatePlayerTextDraw(playerid, 203.000, 228.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][41], 14.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][41], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][41], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][41], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][41], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][41], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][41], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][41], 1);

	ATMTD[playerid][42] = CreatePlayerTextDraw(playerid, 205.000, 226.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][42], 10.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][42], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][42], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][42], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][42], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][42], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][42], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][42], 1);

	ATMTD[playerid][43] = CreatePlayerTextDraw(playerid, 205.000, 230.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][43], 10.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][43], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][43], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][43], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][43], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][43], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][43], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][43], 1);

	ATMTD[playerid][44] = CreatePlayerTextDraw(playerid, 202.000, 250.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][44], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][44], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][44], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][44], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][44], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][44], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][44], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][44], 1);

	ATMTD[playerid][45] = CreatePlayerTextDraw(playerid, 202.000, 263.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][45], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][45], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][45], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][45], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][45], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][45], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][45], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][45], 1);

	ATMTD[playerid][46] = CreatePlayerTextDraw(playerid, 212.000, 263.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][46], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][46], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][46], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][46], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][46], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][46], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][46], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][46], 1);

	ATMTD[playerid][47] = CreatePlayerTextDraw(playerid, 212.000, 250.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][47], 6.000, 7.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][47], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][47], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][47], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][47], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][47], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][47], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][47], 1);

	ATMTD[playerid][48] = CreatePlayerTextDraw(playerid, 203.000, 253.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][48], 14.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][48], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][48], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][48], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][48], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][48], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][48], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][48], 1);

	ATMTD[playerid][49] = CreatePlayerTextDraw(playerid, 205.000, 251.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][49], 10.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][49], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][49], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][49], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][49], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][49], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][49], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][49], 1);

	ATMTD[playerid][50] = CreatePlayerTextDraw(playerid, 205.000, 255.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][50], 10.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][50], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][50], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][50], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][50], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][50], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][50], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][50], 1);

	ATMTD[playerid][51] = CreatePlayerTextDraw(playerid, 318.000, 55.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][51], 1.000, 335.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][51], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][51], -206);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][51], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][51], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][51], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][51], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][51], 1);

	ATMTD[playerid][52] = CreatePlayerTextDraw(playerid, 339.000, 110.000, "BALANCE");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][52], 0.079, 0.499);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][52], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][52], 1920566271);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][52], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][52], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][52], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][52], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][52], 1);

	ATMTD[playerid][53] = CreatePlayerTextDraw(playerid, 208.000, 233.000, "V");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][53], 0.140, 0.599);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][53], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][53], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][53], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][53], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][53], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][53], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][53], 1);

	ATMTD[playerid][54] = CreatePlayerTextDraw(playerid, 285.000, 151.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][54], 12.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][54], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][54], -1031399425);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][54], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][54], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][54], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][54], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][54], 1);

	ATMTD[playerid][55] = CreatePlayerTextDraw(playerid, 280.000, 151.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][55], 12.000, 14.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][55], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][55], -1289153281);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][55], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][55], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][55], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][55], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][55], 1);

	ATMTD[playerid][56] = CreatePlayerTextDraw(playerid, 206.000, 106.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][56], 4.000, 4.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][56], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][56], -692962817);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][56], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][56], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][56], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][56], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][56], 1);

	ATMTD[playerid][57] = CreatePlayerTextDraw(playerid, 205.000, 101.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][57], 4.000, 5.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][57], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][57], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][57], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][57], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][57], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][57], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][57], 1);

	ATMTD[playerid][58] = CreatePlayerTextDraw(playerid, 208.000, 101.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][58], 4.000, 5.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][58], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][58], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][58], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][58], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][58], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][58], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][58], 1);

	ATMTD[playerid][59] = CreatePlayerTextDraw(playerid, 205.000, 101.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][59], 6.000, 5.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][59], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][59], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][59], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][59], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][59], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][59], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][59], 1);

	ATMTD[playerid][60] = CreatePlayerTextDraw(playerid, 206.000, 101.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][60], 6.000, 5.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][60], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][60], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][60], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][60], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][60], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][60], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][60], 1);

	ATMTD[playerid][61] = CreatePlayerTextDraw(playerid, 214.000, 100.000, "FLEECA");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][61], 0.180, 0.999);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][61], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][61], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][61], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][61], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][61], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][61], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][61], 1);

	ATMTD[playerid][62] = CreatePlayerTextDraw(playerid, 229.000, 126.000, "9310 7500 0000 0000");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][62], 0.100, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][62], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][62], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][62], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][62], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][62], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][62], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][62], 1);

	ATMTD[playerid][63] = CreatePlayerTextDraw(playerid, 339.000, 99.000, "PERSONAL ACCOUNT");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][63], 0.108, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][63], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][63], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][63], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][63], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][63], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][63], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][63], 1);

	ATMTD[playerid][64] = CreatePlayerTextDraw(playerid, 339.000, 115.000, "$5,499");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][64], 0.108, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][64], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][64], 6553855);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][64], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][64], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][64], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][64], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][64], 1);

	ATMTD[playerid][65] = CreatePlayerTextDraw(playerid, 221.000, 181.000, "DEPOSIT");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][65], 0.108, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][65], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][65], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][65], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][65], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][65], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][65], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][65], 1);

	ATMTD[playerid][66] = CreatePlayerTextDraw(playerid, 221.000, 206.000, "WITHDRAW");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][66], 0.108, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][66], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][66], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][66], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][66], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][66], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][66], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][66], 1);

	ATMTD[playerid][67] = CreatePlayerTextDraw(playerid, 203.000, 229.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][67], 14.000, 12.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][67], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][67], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][67], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][67], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][67], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][67], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][67], 1);
	PlayerTextDrawSetSelectable(playerid, ATMTD[playerid][67], 1);

	ATMTD[playerid][68] = CreatePlayerTextDraw(playerid, 221.000, 231.000, "TRANSFER");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][68], 0.108, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][68], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][68], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][68], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][68], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][68], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][68], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][68], 1);

	ATMTD[playerid][69] = CreatePlayerTextDraw(playerid, 221.000, 256.000, "LOG OUT");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][69], 0.108, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][69], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][69], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][69], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][69], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][69], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][69], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][69], 1);

	ATMTD[playerid][70] = CreatePlayerTextDraw(playerid, 207.000, 156.000, "JADEN_BAKTERIA");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][70], 0.100, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][70], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][70], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][70], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][70], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][70], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][70], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][70], 1);

	ATMTD[playerid][71] = CreatePlayerTextDraw(playerid, 207.000, 151.000, "CARD HOLDER");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][71], 0.079, 0.499);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][71], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][71], 1920566271);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][71], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][71], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][71], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][71], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][71], 1);

	ATMTD[playerid][72] = CreatePlayerTextDraw(playerid, 209.000, 228.000, "I");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][72], 0.160, 1.199);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][72], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][72], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][72], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][72], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][72], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][72], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][72], 1);

	ATMTD[playerid][73] = CreatePlayerTextDraw(playerid, 207.000, 235.000, "-");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][73], 0.459, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][73], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][73], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][73], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][73], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][73], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][73], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][73], 1);

	ATMTD[playerid][74] = CreatePlayerTextDraw(playerid, 208.000, 212.000, "V");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][74], 0.140, -0.600);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][74], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][74], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][74], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][74], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][74], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][74], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][74], 1);

	ATMTD[playerid][75] = CreatePlayerTextDraw(playerid, 209.000, 205.000, "I");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][75], 0.160, 1.199);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][75], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][75], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][75], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][75], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][75], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][75], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][75], 1);

	ATMTD[playerid][76] = CreatePlayerTextDraw(playerid, 207.000, 203.000, "-");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][76], 0.519, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][76], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][76], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][76], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][76], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][76], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][76], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][76], 1);

	ATMTD[playerid][77] = CreatePlayerTextDraw(playerid, 203.000, 204.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][77], 14.000, 12.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][77], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][77], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][77], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][77], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][77], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][77], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][77], 1);
	PlayerTextDrawSetSelectable(playerid, ATMTD[playerid][77], 1);

	ATMTD[playerid][78] = CreatePlayerTextDraw(playerid, 208.000, 180.000, "$");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][78], 0.128, 0.899);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][78], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][78], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][78], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][78], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][78], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][78], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][78], 1);

	ATMTD[playerid][79] = CreatePlayerTextDraw(playerid, 210.000, 256.000, ">");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][79], 0.129, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][79], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][79], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][79], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][79], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][79], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][79], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][79], 1);

	ATMTD[playerid][80] = CreatePlayerTextDraw(playerid, 203.000, 179.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][80], 14.000, 12.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][80], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][80], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][80], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][80], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][80], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][80], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][80], 1);
	PlayerTextDrawSetSelectable(playerid, ATMTD[playerid][80], 1);

	ATMTD[playerid][81] = CreatePlayerTextDraw(playerid, 203.000, 254.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, ATMTD[playerid][81], 14.000, 12.000);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][81], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][81], 555952127);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][81], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][81], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][81], 255);
	PlayerTextDrawFont(playerid, ATMTD[playerid][81], 4);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][81], 1);
	PlayerTextDrawSetSelectable(playerid, ATMTD[playerid][81], 1);

	ATMTD[playerid][82] = CreatePlayerTextDraw(playerid, 207.000, 255.000, "[");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][82], 0.140, 0.799);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][82], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][82], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][82], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][82], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][82], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][82], 3);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][82], 1);

	ATMTD[playerid][83] = CreatePlayerTextDraw(playerid, 365.000, 110.000, "WALLET");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][83], 0.079, 0.499);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][83], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][83], 1920566271);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][83], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][83], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][83], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][83], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][83], 1);

	ATMTD[playerid][84] = CreatePlayerTextDraw(playerid, 365.000, 115.000, "$5,499");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][84], 0.108, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][84], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][84], 6553855);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][84], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][84], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][84], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][84], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][84], 1);

	ATMTD[playerid][85] = CreatePlayerTextDraw(playerid, 362.000, 126.000, "350444");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][85], 0.100, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][85], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][85], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][85], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][85], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][85], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][85], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][85], 1);

	ATMTD[playerid][86] = CreatePlayerTextDraw(playerid, 339.000, 126.000, "REKENING");
	PlayerTextDrawLetterSize(playerid, ATMTD[playerid][86], 0.100, 0.699);
	PlayerTextDrawAlignment(playerid, ATMTD[playerid][86], 1);
	PlayerTextDrawColor(playerid, ATMTD[playerid][86], -1);
	PlayerTextDrawSetShadow(playerid, ATMTD[playerid][86], 0);
	PlayerTextDrawSetOutline(playerid, ATMTD[playerid][86], 0);
	PlayerTextDrawBackgroundColor(playerid, ATMTD[playerid][86], 150);
	PlayerTextDrawFont(playerid, ATMTD[playerid][86], 2);
	PlayerTextDrawSetProportional(playerid, ATMTD[playerid][86], 1);

    //RADIAL TEDEH
    RadialDokumen[playerid][0] = CreatePlayerTextDraw(playerid, 252.000, 176.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialDokumen[playerid][0], 15.000, 18.000);
    PlayerTextDrawAlignment(playerid, RadialDokumen[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadialDokumen[playerid][0], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialDokumen[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadialDokumen[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialDokumen[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadialDokumen[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, RadialDokumen[playerid][0], 1);

    RadialDokumen[playerid][1] = CreatePlayerTextDraw(playerid, 254.000, 178.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialDokumen[playerid][1], 15.000, 18.000);
    PlayerTextDrawAlignment(playerid, RadialDokumen[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadialDokumen[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, RadialDokumen[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadialDokumen[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialDokumen[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadialDokumen[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, RadialDokumen[playerid][1], 1);

    RadialDokumen[playerid][2] = CreatePlayerTextDraw(playerid, 256.000, 190.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialDokumen[playerid][2], 11.000, 1.000);
    PlayerTextDrawAlignment(playerid, RadialDokumen[playerid][2], 1);
    PlayerTextDrawColor(playerid, RadialDokumen[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, RadialDokumen[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RadialDokumen[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialDokumen[playerid][2], 255);
    PlayerTextDrawFont(playerid, RadialDokumen[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, RadialDokumen[playerid][2], 1);

    RadialDokumen[playerid][3] = CreatePlayerTextDraw(playerid, 256.000, 187.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialDokumen[playerid][3], 11.000, 1.000);
    PlayerTextDrawAlignment(playerid, RadialDokumen[playerid][3], 1);
    PlayerTextDrawColor(playerid, RadialDokumen[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, RadialDokumen[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RadialDokumen[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialDokumen[playerid][3], 255);
    PlayerTextDrawFont(playerid, RadialDokumen[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, RadialDokumen[playerid][3], 1);

    RadialDokumen[playerid][4] = CreatePlayerTextDraw(playerid, 256.000, 185.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialDokumen[playerid][4], 11.000, 1.000);
    PlayerTextDrawAlignment(playerid, RadialDokumen[playerid][4], 1);
    PlayerTextDrawColor(playerid, RadialDokumen[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, RadialDokumen[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, RadialDokumen[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialDokumen[playerid][4], 255);
    PlayerTextDrawFont(playerid, RadialDokumen[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, RadialDokumen[playerid][4], 1);

    RadialDokumen[playerid][5] = CreatePlayerTextDraw(playerid, 260.000, 198.000, "Document");
    PlayerTextDrawLetterSize(playerid, RadialDokumen[playerid][5], 0.128, 0.799);
    PlayerTextDrawTextSize(playerid, RadialDokumen[playerid][5], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialDokumen[playerid][5], 2);
    PlayerTextDrawColor(playerid, RadialDokumen[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, RadialDokumen[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, RadialDokumen[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialDokumen[playerid][5], 255);
    PlayerTextDrawFont(playerid, RadialDokumen[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, RadialDokumen[playerid][5], 1);

    RadialInven[playerid][0] = CreatePlayerTextDraw(playerid, 331.000, 172.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RadialInven[playerid][0], 25.000, 18.000);
    PlayerTextDrawAlignment(playerid, RadialInven[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadialInven[playerid][0], -106);
    PlayerTextDrawSetShadow(playerid, RadialInven[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadialInven[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialInven[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadialInven[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, RadialInven[playerid][0], 1);

    RadialInven[playerid][1] = CreatePlayerTextDraw(playerid, 335.000, 182.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialInven[playerid][1], 17.000, 15.000);
    PlayerTextDrawAlignment(playerid, RadialInven[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadialInven[playerid][1], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialInven[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadialInven[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialInven[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadialInven[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, RadialInven[playerid][1], 1);

    RadialInven[playerid][2] = CreatePlayerTextDraw(playerid, 333.000, 187.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialInven[playerid][2], 21.000, 7.000);
    PlayerTextDrawAlignment(playerid, RadialInven[playerid][2], 1);
    PlayerTextDrawColor(playerid, RadialInven[playerid][2], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialInven[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RadialInven[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialInven[playerid][2], 255);
    PlayerTextDrawFont(playerid, RadialInven[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, RadialInven[playerid][2], 1);

    RadialInven[playerid][3] = CreatePlayerTextDraw(playerid, 338.000, 188.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialInven[playerid][3], 11.000, 2.000);
    PlayerTextDrawAlignment(playerid, RadialInven[playerid][3], 1);
    PlayerTextDrawColor(playerid, RadialInven[playerid][3], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialInven[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RadialInven[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialInven[playerid][3], 255);
    PlayerTextDrawFont(playerid, RadialInven[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, RadialInven[playerid][3], 1);

    RadialInven[playerid][4] = CreatePlayerTextDraw(playerid, 338.000, 192.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialInven[playerid][4], 11.000, 2.000);
    PlayerTextDrawAlignment(playerid, RadialInven[playerid][4], 1);
    PlayerTextDrawColor(playerid, RadialInven[playerid][4], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialInven[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, RadialInven[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialInven[playerid][4], 255);
    PlayerTextDrawFont(playerid, RadialInven[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, RadialInven[playerid][4], 1);

    RadialInven[playerid][5] = CreatePlayerTextDraw(playerid, 341.000, 173.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialInven[playerid][5], 1.000, 5.000);
    PlayerTextDrawAlignment(playerid, RadialInven[playerid][5], 1);
    PlayerTextDrawColor(playerid, RadialInven[playerid][5], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialInven[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, RadialInven[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialInven[playerid][5], 255);
    PlayerTextDrawFont(playerid, RadialInven[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, RadialInven[playerid][5], 1);

    RadialInven[playerid][6] = CreatePlayerTextDraw(playerid, 346.000, 173.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialInven[playerid][6], 1.000, 5.000);
    PlayerTextDrawAlignment(playerid, RadialInven[playerid][6], 1);
    PlayerTextDrawColor(playerid, RadialInven[playerid][6], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialInven[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, RadialInven[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialInven[playerid][6], 255);
    PlayerTextDrawFont(playerid, RadialInven[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, RadialInven[playerid][6], 1);

    RadialInven[playerid][7] = CreatePlayerTextDraw(playerid, 341.000, 173.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialInven[playerid][7], 6.000, 1.000);
    PlayerTextDrawAlignment(playerid, RadialInven[playerid][7], 1);
    PlayerTextDrawColor(playerid, RadialInven[playerid][7], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialInven[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, RadialInven[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialInven[playerid][7], 255);
    PlayerTextDrawFont(playerid, RadialInven[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, RadialInven[playerid][7], 1);

    RadialInven[playerid][8] = CreatePlayerTextDraw(playerid, 344.000, 198.000, "Inventory");
    PlayerTextDrawLetterSize(playerid, RadialInven[playerid][8], 0.128, 0.799);
    PlayerTextDrawTextSize(playerid, RadialInven[playerid][8], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialInven[playerid][8], 2);
    PlayerTextDrawColor(playerid, RadialInven[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, RadialInven[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, RadialInven[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialInven[playerid][8], 255);
    PlayerTextDrawFont(playerid, RadialInven[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, RadialInven[playerid][8], 1);

    RadialExit[playerid][0] = CreatePlayerTextDraw(playerid, 316.000, 284.000, "X");
    PlayerTextDrawLetterSize(playerid, RadialExit[playerid][0], 0.391, 1.799);
    PlayerTextDrawTextSize(playerid, RadialExit[playerid][0], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialExit[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadialExit[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, RadialExit[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadialExit[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialExit[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadialExit[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, RadialExit[playerid][0], 1);

    RadialExit[playerid][1] = CreatePlayerTextDraw(playerid, 320.500, 301.000, "Exit");
    PlayerTextDrawLetterSize(playerid, RadialExit[playerid][1], 0.150, 0.898);
    PlayerTextDrawTextSize(playerid, RadialExit[playerid][1], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialExit[playerid][1], 2);
    PlayerTextDrawColor(playerid, RadialExit[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, RadialExit[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadialExit[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialExit[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadialExit[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, RadialExit[playerid][1], 1);

    RadialBall[playerid][0] = CreatePlayerTextDraw(playerid, 300.000, 274.000, "LD_POOL:ball");
    PlayerTextDrawTextSize(playerid, RadialBall[playerid][0], 41.000, 48.000);
    PlayerTextDrawAlignment(playerid, RadialBall[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadialBall[playerid][0], -1523963137);
    PlayerTextDrawSetShadow(playerid, RadialBall[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadialBall[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialBall[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadialBall[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, RadialBall[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, RadialBall[playerid][0], 1);

    RadialBall[playerid][1] = CreatePlayerTextDraw(playerid, 342.000, 210.000, "LD_POOL:ball");
    PlayerTextDrawTextSize(playerid, RadialBall[playerid][1], 41.000, 48.000);
    PlayerTextDrawAlignment(playerid, RadialBall[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadialBall[playerid][1], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialBall[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadialBall[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialBall[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadialBall[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, RadialBall[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, RadialBall[playerid][1], 1);

    RadialBall[playerid][2] = CreatePlayerTextDraw(playerid, 301.000, 210.000, "LD_POOL:ball");
    PlayerTextDrawTextSize(playerid, RadialBall[playerid][2], 41.000, 48.000);
    PlayerTextDrawAlignment(playerid, RadialBall[playerid][2], 1);
    PlayerTextDrawColor(playerid, RadialBall[playerid][2], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialBall[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RadialBall[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialBall[playerid][2], 255);
    PlayerTextDrawFont(playerid, RadialBall[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, RadialBall[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, RadialBall[playerid][2], 1);

    RadialBall[playerid][3] = CreatePlayerTextDraw(playerid, 260.000, 210.000, "LD_POOL:ball");
    PlayerTextDrawTextSize(playerid, RadialBall[playerid][3], 41.000, 48.000);
    PlayerTextDrawAlignment(playerid, RadialBall[playerid][3], 1);
    PlayerTextDrawColor(playerid, RadialBall[playerid][3], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialBall[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RadialBall[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialBall[playerid][3], 255);
    PlayerTextDrawFont(playerid, RadialBall[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, RadialBall[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, RadialBall[playerid][3], 1);

    RadialBall[playerid][4] = CreatePlayerTextDraw(playerid, 364.000, 166.000, "LD_POOL:ball");
    PlayerTextDrawTextSize(playerid, RadialBall[playerid][4], 41.000, 48.000);
    PlayerTextDrawAlignment(playerid, RadialBall[playerid][4], 1);
    PlayerTextDrawColor(playerid, RadialBall[playerid][4], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialBall[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, RadialBall[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialBall[playerid][4], 255);
    PlayerTextDrawFont(playerid, RadialBall[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, RadialBall[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, RadialBall[playerid][4], 1);

    RadialBall[playerid][5] = CreatePlayerTextDraw(playerid, 323.000, 165.000, "LD_POOL:ball");
    PlayerTextDrawTextSize(playerid, RadialBall[playerid][5], 41.000, 48.000);
    PlayerTextDrawAlignment(playerid, RadialBall[playerid][5], 1);
    PlayerTextDrawColor(playerid, RadialBall[playerid][5], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialBall[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, RadialBall[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialBall[playerid][5], 255);
    PlayerTextDrawFont(playerid, RadialBall[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, RadialBall[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, RadialBall[playerid][5], 1);

    RadialBall[playerid][6] = CreatePlayerTextDraw(playerid, 281.000, 165.000, "LD_POOL:ball");
    PlayerTextDrawTextSize(playerid, RadialBall[playerid][6], 41.000, 48.000);
    PlayerTextDrawAlignment(playerid, RadialBall[playerid][6], 1);
    PlayerTextDrawColor(playerid, RadialBall[playerid][6], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialBall[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, RadialBall[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialBall[playerid][6], 255);
    PlayerTextDrawFont(playerid, RadialBall[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, RadialBall[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, RadialBall[playerid][6], 1);

    RadialBall[playerid][7] = CreatePlayerTextDraw(playerid, 239.000, 166.000, "LD_POOL:ball");
    PlayerTextDrawTextSize(playerid, RadialBall[playerid][7], 41.000, 48.000);
    PlayerTextDrawAlignment(playerid, RadialBall[playerid][7], 1);
    PlayerTextDrawColor(playerid, RadialBall[playerid][7], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialBall[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, RadialBall[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialBall[playerid][7], 255);
    PlayerTextDrawFont(playerid, RadialBall[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, RadialBall[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, RadialBall[playerid][7], 1);

    RadialAction[playerid][0] = CreatePlayerTextDraw(playerid, 315.500, 218.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RadialAction[playerid][0], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, RadialAction[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadialAction[playerid][0], -101);
    PlayerTextDrawSetShadow(playerid, RadialAction[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadialAction[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialAction[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadialAction[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, RadialAction[playerid][0], 1);

    RadialAction[playerid][1] = CreatePlayerTextDraw(playerid, 311.500, 229.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RadialAction[playerid][1], 20.000, 12.000);
    PlayerTextDrawAlignment(playerid, RadialAction[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadialAction[playerid][1], -101);
    PlayerTextDrawSetShadow(playerid, RadialAction[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadialAction[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialAction[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadialAction[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, RadialAction[playerid][1], 1);

    RadialAction[playerid][2] = CreatePlayerTextDraw(playerid, 321.000, 241.000, "Action");
    PlayerTextDrawLetterSize(playerid, RadialAction[playerid][2], 0.129, 0.799);
    PlayerTextDrawTextSize(playerid, RadialAction[playerid][2], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialAction[playerid][2], 2);
    PlayerTextDrawColor(playerid, RadialAction[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, RadialAction[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RadialAction[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialAction[playerid][2], 255);
    PlayerTextDrawFont(playerid, RadialAction[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, RadialAction[playerid][2], 1);

    RadialAcc[playerid][0] = CreatePlayerTextDraw(playerid, 356.000, 221.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialAcc[playerid][0], 14.000, 18.000);
    PlayerTextDrawAlignment(playerid, RadialAcc[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadialAcc[playerid][0], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialAcc[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadialAcc[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialAcc[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadialAcc[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, RadialAcc[playerid][0], 1);

    RadialAcc[playerid][1] = CreatePlayerTextDraw(playerid, 352.000, 221.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialAcc[playerid][1], 22.000, 6.000);
    PlayerTextDrawAlignment(playerid, RadialAcc[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadialAcc[playerid][1], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialAcc[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadialAcc[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialAcc[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadialAcc[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, RadialAcc[playerid][1], 1);

    RadialAcc[playerid][2] = CreatePlayerTextDraw(playerid, 363.000, 219.000, "V");
    PlayerTextDrawLetterSize(playerid, RadialAcc[playerid][2], 0.261, 1.100);
    PlayerTextDrawTextSize(playerid, RadialAcc[playerid][2], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialAcc[playerid][2], 2);
    PlayerTextDrawColor(playerid, RadialAcc[playerid][2], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialAcc[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RadialAcc[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialAcc[playerid][2], 255);
    PlayerTextDrawFont(playerid, RadialAcc[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, RadialAcc[playerid][2], 1);

    RadialAcc[playerid][3] = CreatePlayerTextDraw(playerid, 363.000, 241.000, "Aksesoris");
    PlayerTextDrawLetterSize(playerid, RadialAcc[playerid][3], 0.128, 0.799);
    PlayerTextDrawTextSize(playerid, RadialAcc[playerid][3], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialAcc[playerid][3], 2);
    PlayerTextDrawColor(playerid, RadialAcc[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, RadialAcc[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RadialAcc[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialAcc[playerid][3], 255);
    PlayerTextDrawFont(playerid, RadialAcc[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, RadialAcc[playerid][3], 1);

    RadialPayment[playerid][0] = CreatePlayerTextDraw(playerid, 269.000, 236.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialPayment[playerid][0], 21.000, 3.000);
    PlayerTextDrawAlignment(playerid, RadialPayment[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadialPayment[playerid][0], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialPayment[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadialPayment[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialPayment[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadialPayment[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, RadialPayment[playerid][0], 1);

    RadialPayment[playerid][1] = CreatePlayerTextDraw(playerid, 276.000, 230.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialPayment[playerid][1], 8.000, 2.000);
    PlayerTextDrawAlignment(playerid, RadialPayment[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadialPayment[playerid][1], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialPayment[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadialPayment[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialPayment[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadialPayment[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, RadialPayment[playerid][1], 1);

    RadialPayment[playerid][2] = CreatePlayerTextDraw(playerid, 275.000, 229.000, "/");
    PlayerTextDrawLetterSize(playerid, RadialPayment[playerid][2], 0.409, 0.799);
    PlayerTextDrawTextSize(playerid, RadialPayment[playerid][2], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialPayment[playerid][2], 2);
    PlayerTextDrawColor(playerid, RadialPayment[playerid][2], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialPayment[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RadialPayment[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialPayment[playerid][2], 255);
    PlayerTextDrawFont(playerid, RadialPayment[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, RadialPayment[playerid][2], 1);

    RadialPayment[playerid][3] = CreatePlayerTextDraw(playerid, 291.000, 227.000, "/");
    PlayerTextDrawLetterSize(playerid, RadialPayment[playerid][3], 0.370, 1.200);
    PlayerTextDrawTextSize(playerid, RadialPayment[playerid][3], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialPayment[playerid][3], 2);
    PlayerTextDrawColor(playerid, RadialPayment[playerid][3], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialPayment[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RadialPayment[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialPayment[playerid][3], 255);
    PlayerTextDrawFont(playerid, RadialPayment[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, RadialPayment[playerid][3], 1);

    RadialPayment[playerid][4] = CreatePlayerTextDraw(playerid, 281.000, 217.000, "$");
    PlayerTextDrawLetterSize(playerid, RadialPayment[playerid][4], 0.270, 1.200);
    PlayerTextDrawTextSize(playerid, RadialPayment[playerid][4], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialPayment[playerid][4], 2);
    PlayerTextDrawColor(playerid, RadialPayment[playerid][4], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialPayment[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, RadialPayment[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialPayment[playerid][4], 255);
    PlayerTextDrawFont(playerid, RadialPayment[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, RadialPayment[playerid][4], 1);

    RadialPayment[playerid][5] = CreatePlayerTextDraw(playerid, 280.000, 241.000, "Payment");
    PlayerTextDrawLetterSize(playerid, RadialPayment[playerid][5], 0.128, 0.799);
    PlayerTextDrawTextSize(playerid, RadialPayment[playerid][5], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialPayment[playerid][5], 2);
    PlayerTextDrawColor(playerid, RadialPayment[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, RadialPayment[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, RadialPayment[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialPayment[playerid][5], 255);
    PlayerTextDrawFont(playerid, RadialPayment[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, RadialPayment[playerid][5], 1);

    RadialPhone[playerid][0] = CreatePlayerTextDraw(playerid, 378.000, 176.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialPhone[playerid][0], 14.000, 20.000);
    PlayerTextDrawAlignment(playerid, RadialPhone[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadialPhone[playerid][0], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialPhone[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadialPhone[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialPhone[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadialPhone[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, RadialPhone[playerid][0], 1);

    RadialPhone[playerid][1] = CreatePlayerTextDraw(playerid, 379.000, 176.699, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialPhone[playerid][1], 12.000, 19.000);
    PlayerTextDrawAlignment(playerid, RadialPhone[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadialPhone[playerid][1], 572732671);
    PlayerTextDrawSetShadow(playerid, RadialPhone[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadialPhone[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialPhone[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadialPhone[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, RadialPhone[playerid][1], 1);

    RadialPhone[playerid][2] = CreatePlayerTextDraw(playerid, 384.000, 192.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RadialPhone[playerid][2], 3.000, 3.000);
    PlayerTextDrawAlignment(playerid, RadialPhone[playerid][2], 1);
    PlayerTextDrawColor(playerid, RadialPhone[playerid][2], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialPhone[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RadialPhone[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialPhone[playerid][2], 255);
    PlayerTextDrawFont(playerid, RadialPhone[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, RadialPhone[playerid][2], 1);

    RadialPhone[playerid][3] = CreatePlayerTextDraw(playerid, 384.000, 198.000, "Phone");
    PlayerTextDrawLetterSize(playerid, RadialPhone[playerid][3], 0.128, 0.799);
    PlayerTextDrawTextSize(playerid, RadialPhone[playerid][3], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialPhone[playerid][3], 2);
    PlayerTextDrawColor(playerid, RadialPhone[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, RadialPhone[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RadialPhone[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialPhone[playerid][3], 255);
    PlayerTextDrawFont(playerid, RadialPhone[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, RadialPhone[playerid][3], 1);

    RadialVehicle[playerid][0] = CreatePlayerTextDraw(playerid, 293.000, 187.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][0], 17.000, 6.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][0], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][0], 1);

    RadialVehicle[playerid][1] = CreatePlayerTextDraw(playerid, 293.000, 194.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][1], 3.000, 3.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][1], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][1], 1);

    RadialVehicle[playerid][2] = CreatePlayerTextDraw(playerid, 307.000, 194.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][2], 3.000, 3.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][2], 1);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][2], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][2], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][2], 1);

    RadialVehicle[playerid][3] = CreatePlayerTextDraw(playerid, 310.000, 185.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][3], 3.000, 4.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][3], 1);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][3], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][3], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][3], 1);

    RadialVehicle[playerid][4] = CreatePlayerTextDraw(playerid, 291.000, 185.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][4], 3.000, 4.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][4], 1);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][4], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][4], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][4], 1);

    RadialVehicle[playerid][5] = CreatePlayerTextDraw(playerid, 293.000, 190.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][5], 2.000, 3.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][5], 1);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][5], 1768516095);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][5], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][5], 1);

    RadialVehicle[playerid][6] = CreatePlayerTextDraw(playerid, 308.000, 190.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][6], 2.000, 3.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][6], 1);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][6], 1768516095);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][6], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][6], 1);

    RadialVehicle[playerid][7] = CreatePlayerTextDraw(playerid, 293.000, 178.000, "/");
    PlayerTextDrawLetterSize(playerid, RadialVehicle[playerid][7], 0.250, 0.998);
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][7], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][7], 1);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][7], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][7], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][7], 1);

    RadialVehicle[playerid][8] = CreatePlayerTextDraw(playerid, 310.000, 178.000, "/");
    PlayerTextDrawLetterSize(playerid, RadialVehicle[playerid][8], -0.250, 0.998);
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][8], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][8], 1);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][8], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][8], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][8], 1);

    RadialVehicle[playerid][9] = CreatePlayerTextDraw(playerid, 296.000, 179.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][9], 12.000, 1.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][9], 1);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][9], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][9], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][9], 1);

    RadialVehicle[playerid][10] = CreatePlayerTextDraw(playerid, 301.000, 198.000, "Vehicles");
    PlayerTextDrawLetterSize(playerid, RadialVehicle[playerid][10], 0.128, 0.799);
    PlayerTextDrawTextSize(playerid, RadialVehicle[playerid][10], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, RadialVehicle[playerid][10], 2);
    PlayerTextDrawColor(playerid, RadialVehicle[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, RadialVehicle[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, RadialVehicle[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, RadialVehicle[playerid][10], 255);
    PlayerTextDrawFont(playerid, RadialVehicle[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, RadialVehicle[playerid][10], 1);

    // Karung
    VR_KARUNG[playerid][0] = CreatePlayerTextDraw(playerid, -29.000, -13.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VR_KARUNG[playerid][0], 781.000, 582.000);
    PlayerTextDrawAlignment(playerid, VR_KARUNG[playerid][0], 1);
    PlayerTextDrawColor(playerid, VR_KARUNG[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, VR_KARUNG[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, VR_KARUNG[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_KARUNG[playerid][0], 255);
    PlayerTextDrawFont(playerid, VR_KARUNG[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, VR_KARUNG[playerid][0], 1);

    // Banned TD
    VR_BANNEDTD[playerid][0] = CreatePlayerTextDraw(playerid, 0.000, -6.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, VR_BANNEDTD[playerid][0], 651.000, 470.000);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][0], 943210495);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][0], 1);

    VR_BANNEDTD[playerid][1] = CreatePlayerTextDraw(playerid, 89.000, 88.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, VR_BANNEDTD[playerid][1], 458.000, 284.000);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][1], -2139062017);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][1], 1);

    VR_BANNEDTD[playerid][2] = CreatePlayerTextDraw(playerid, 116.000, 104.000, "DCRP");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][2], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][2], 1);

    VR_BANNEDTD[playerid][3] = CreatePlayerTextDraw(playerid, 102.000, 94.000, "/");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][3], 0.539, 3.700);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][3], -65281);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][3], 1);

    VR_BANNEDTD[playerid][4] = CreatePlayerTextDraw(playerid, 106.000, 96.000, "/");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][4], 0.539, 3.700);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][4], 1);

    VR_BANNEDTD[playerid][5] = CreatePlayerTextDraw(playerid, 117.000, 116.000, "Indonesia");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][5], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][5], 1);

    VR_BANNEDTD[playerid][6] = CreatePlayerTextDraw(playerid, 310.000, 144.000, "You Have Been Banned By Adm Mings");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][6], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][6], 2);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][6], 1);

    VR_BANNEDTD[playerid][7] = CreatePlayerTextDraw(playerid, 209.000, 174.000, "UCP:_Kims");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][7], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][7], 1);

    VR_BANNEDTD[playerid][8] = CreatePlayerTextDraw(playerid, 209.000, 191.000, "Name: Kim_Jong");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][8], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][8], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][8], 1);

    VR_BANNEDTD[playerid][9] = CreatePlayerTextDraw(playerid, 201.000, 167.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, VR_BANNEDTD[playerid][9], 233.000, 104.000);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][9], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][9], 943210495);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][9], 1);

    VR_BANNEDTD[playerid][10] = CreatePlayerTextDraw(playerid, 209.000, 207.000, "Level: 51");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][10], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][10], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][10], 1);

    VR_BANNEDTD[playerid][11] = CreatePlayerTextDraw(playerid, 209.000, 223.000, "Reason:");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][11], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][11], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][11], 1);

    VR_BANNEDTD[playerid][12] = CreatePlayerTextDraw(playerid, 318.000, 245.000, "Anda Mencoba Menggunakan Teleportasi");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][12], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][12], 2);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][12], 1);

    VR_BANNEDTD[playerid][13] = CreatePlayerTextDraw(playerid, 376.000, 167.000, "/");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][13], 0.439, 2.000);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][13], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][13], -65281);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][13], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][13], 1);

    VR_BANNEDTD[playerid][14] = CreatePlayerTextDraw(playerid, 379.000, 168.000, "/");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][14], 0.439, 2.000);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][14], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][14], 1);

    VR_BANNEDTD[playerid][15] = CreatePlayerTextDraw(playerid, 387.000, 172.000, "DCRP");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][15], 0.150, 1.100);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][15], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][15], 1);

    VR_BANNEDTD[playerid][16] = CreatePlayerTextDraw(playerid, 388.000, 181.000, "Indonesia");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][16], 0.150, 1.100);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][16], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][16], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][16], 1);

    VR_BANNEDTD[playerid][17] = CreatePlayerTextDraw(playerid, 321.000, 282.000, "TIDAK MERASA BERSALAH ATAUPUN TIDAK MERASA APA YANG DIBILANG OLEH ADMIN?");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][17], 0.220, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][17], 2);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][17], 1);

    VR_BANNEDTD[playerid][18] = CreatePlayerTextDraw(playerid, 319.000, 297.000, "Report Misunderstandings On Discord: ~p~http://discord.gg/DCRPTheater");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][18], 0.220, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][18], 2);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][18], 255);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][18], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][18], 1);

    VR_BANNEDTD[playerid][19] = CreatePlayerTextDraw(playerid, 324.000, 314.000, "In Channel: #create-ticket");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][19], 0.220, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][19], 2);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][19], 255);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][19], 1);

    VR_BANNEDTD[playerid][20] = CreatePlayerTextDraw(playerid, 94.000, 352.000, "Tanggal Terbanned: 25-02-2003");
    PlayerTextDrawLetterSize(playerid, VR_BANNEDTD[playerid][20], 0.220, 1.500);
    PlayerTextDrawAlignment(playerid, VR_BANNEDTD[playerid][20], 1);
    PlayerTextDrawColor(playerid, VR_BANNEDTD[playerid][20], 255);
    PlayerTextDrawSetShadow(playerid, VR_BANNEDTD[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, VR_BANNEDTD[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, VR_BANNEDTD[playerid][20], 150);
    PlayerTextDrawFont(playerid, VR_BANNEDTD[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, VR_BANNEDTD[playerid][20], 1);

    // LoadBarTD
/*    ProgressBar[playerid][0] = CreatePlayerTextDraw(playerid, 212.000, 362.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, ProgressBar[playerid][0], 103.000, 21.000);
    PlayerTextDrawAlignment(playerid, ProgressBar[playerid][0], 1);
    PlayerTextDrawColor(playerid, ProgressBar[playerid][0], 140);
    PlayerTextDrawSetShadow(playerid, ProgressBar[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ProgressBar[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressBar[playerid][0], 255);
    PlayerTextDrawFont(playerid, ProgressBar[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ProgressBar[playerid][0], 1);

    ProgressBar[playerid][1] = CreatePlayerTextDraw(playerid, 212.000, 362.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, ProgressBar[playerid][1], 103.000, 21.000);
    PlayerTextDrawAlignment(playerid, ProgressBar[playerid][1], 1);
    PlayerTextDrawColor(playerid, ProgressBar[playerid][1], -6710800);
    PlayerTextDrawSetShadow(playerid, ProgressBar[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ProgressBar[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressBar[playerid][1], 255);
    PlayerTextDrawFont(playerid, ProgressBar[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, ProgressBar[playerid][1], 1);

    ProgressBar[playerid][2] = CreatePlayerTextDraw(playerid, 265.000, 365.000, "MAKAN");
    PlayerTextDrawLetterSize(playerid, ProgressBar[playerid][2], 0.216, 1.500);
    PlayerTextDrawAlignment(playerid, ProgressBar[playerid][2], 2);
    PlayerTextDrawColor(playerid, ProgressBar[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ProgressBar[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ProgressBar[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressBar[playerid][2], 150);
    PlayerTextDrawFont(playerid, ProgressBar[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ProgressBar[playerid][2], 1);*/

    ProgressBar[playerid][0] = CreatePlayerTextDraw(playerid, 208.000, 356.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ProgressBar[playerid][0], 67.000, 2.000);
    PlayerTextDrawAlignment(playerid, ProgressBar[playerid][0], 1);
    PlayerTextDrawColor(playerid, ProgressBar[playerid][0], -421070146);
    PlayerTextDrawSetShadow(playerid, ProgressBar[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ProgressBar[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressBar[playerid][0], 255);
    PlayerTextDrawFont(playerid, ProgressBar[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ProgressBar[playerid][0], 1);

    ProgressBar[playerid][1] = CreatePlayerTextDraw(playerid, 243.000, 346.000, "Otw Ngecrot..");
    PlayerTextDrawLetterSize(playerid, ProgressBar[playerid][1], 0.149, 0.799);
    PlayerTextDrawAlignment(playerid, ProgressBar[playerid][1], 2);
    PlayerTextDrawColor(playerid, ProgressBar[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ProgressBar[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ProgressBar[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressBar[playerid][1], 150);
    PlayerTextDrawFont(playerid, ProgressBar[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ProgressBar[playerid][1], 1);

    ProgressBar[playerid][2] = CreatePlayerTextDraw(playerid, 208.000, 356.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ProgressBar[playerid][2], 67.000, 2.000);
    PlayerTextDrawAlignment(playerid, ProgressBar[playerid][2], 1);
    PlayerTextDrawColor(playerid, ProgressBar[playerid][2], -260013880);
    PlayerTextDrawSetShadow(playerid, ProgressBar[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ProgressBar[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressBar[playerid][2], 255);
    PlayerTextDrawFont(playerid, ProgressBar[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, ProgressBar[playerid][2], 1);

    ProgressBar[playerid][3] = CreatePlayerTextDraw(playerid, 252.000, 356.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ProgressBar[playerid][3], 2.000, 2.000);
    PlayerTextDrawAlignment(playerid, ProgressBar[playerid][3], 1);
    PlayerTextDrawColor(playerid, ProgressBar[playerid][3], 1887473919);
    PlayerTextDrawSetShadow(playerid, ProgressBar[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ProgressBar[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressBar[playerid][3], 255);
    PlayerTextDrawFont(playerid, ProgressBar[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, ProgressBar[playerid][3], 1);

    ProgressBar[playerid][4] = CreatePlayerTextDraw(playerid, 229.000, 356.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ProgressBar[playerid][4], 2.000, 2.000);
    PlayerTextDrawAlignment(playerid, ProgressBar[playerid][4], 1);
    PlayerTextDrawColor(playerid, ProgressBar[playerid][4], 1887473919);
    PlayerTextDrawSetShadow(playerid, ProgressBar[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ProgressBar[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressBar[playerid][4], 255);
    PlayerTextDrawFont(playerid, ProgressBar[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, ProgressBar[playerid][4], 1);
    
    // Robbery
    RobberyTextTD[playerid][0] = CreatePlayerTextDraw(playerid, 18.000, 195.000, "  Mohon tetap diwarung~n~selama 14 menit 59 detik");
    PlayerTextDrawLetterSize(playerid, RobberyTextTD[playerid][0], 0.249, 1.399);
    PlayerTextDrawAlignment(playerid, RobberyTextTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, RobberyTextTD[playerid][0], 1926329087);
    PlayerTextDrawSetShadow(playerid, RobberyTextTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RobberyTextTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RobberyTextTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, RobberyTextTD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, RobberyTextTD[playerid][0], 1);

    // Clothes New
    P_MENUCLOTHES[playerid][0] = CreatePlayerTextDraw(playerid, 145.000, 183.000, "LD_DUAL:white"); //baju
    PlayerTextDrawTextSize(playerid, P_MENUCLOTHES[playerid][0], 90.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][0], 1);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][0], -260013880);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][0], 255);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, P_MENUCLOTHES[playerid][0], 1);

    P_MENUCLOTHES[playerid][1] = CreatePlayerTextDraw(playerid, 237.000, 186.000, "LD_DUAL:white"); //kembali
    PlayerTextDrawTextSize(playerid, P_MENUCLOTHES[playerid][1], 20.000, 22.000);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][1], 1);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][1], -2147483393);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][1], 255);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, P_MENUCLOTHES[playerid][1], 1);

    P_MENUCLOTHES[playerid][2] = CreatePlayerTextDraw(playerid, 145.000, 209.000, "LD_DUAL:white"); //topi/helm
    PlayerTextDrawTextSize(playerid, P_MENUCLOTHES[playerid][2], 90.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][2], 1);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][2], -260013880);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][2], 255);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, P_MENUCLOTHES[playerid][2], 1);

    P_MENUCLOTHES[playerid][3] = CreatePlayerTextDraw(playerid, 145.000, 235.000, "LD_DUAL:white"); //kacamata
    PlayerTextDrawTextSize(playerid, P_MENUCLOTHES[playerid][3], 90.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][3], 1);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][3], -260013880);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][3], 255);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, P_MENUCLOTHES[playerid][3], 1);

    P_MENUCLOTHES[playerid][4] = CreatePlayerTextDraw(playerid, 145.000, 262.000, "LD_DUAL:white"); //aksesoris 
    PlayerTextDrawTextSize(playerid, P_MENUCLOTHES[playerid][4], 90.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][4], 1);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][4], -260013880);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][4], 255);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, P_MENUCLOTHES[playerid][4], 1);

    P_MENUCLOTHES[playerid][5] = CreatePlayerTextDraw(playerid, 145.000, 288.000, "LD_DUAL:white"); //tas/koper
    PlayerTextDrawTextSize(playerid, P_MENUCLOTHES[playerid][5], 90.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][5], 1);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][5], -260013880);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][5], 255);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, P_MENUCLOTHES[playerid][5], 1);

    P_MENUCLOTHES[playerid][6] = CreatePlayerTextDraw(playerid, 145.000, 185.000, "LD_DUAL:white");
    PlayerTextDrawTextSize(playerid, P_MENUCLOTHES[playerid][6], 90.000, -1.000);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][6], 1);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][6], -260013880);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][6], 255);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][6], 1);

    P_MENUCLOTHES[playerid][7] = CreatePlayerTextDraw(playerid, 145.000, 186.000, "LD_DUAL:white");
    PlayerTextDrawTextSize(playerid, P_MENUCLOTHES[playerid][7], 90.000, -1.000);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][7], 1);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][7], 255);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][7], 1);

    P_MENUCLOTHES[playerid][8] = CreatePlayerTextDraw(playerid, 190.000, 190.000, "Pakaian");
    PlayerTextDrawLetterSize(playerid, P_MENUCLOTHES[playerid][8], 0.209, 1.299);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][8], 2);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][8], 150);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][8], 1);

    P_MENUCLOTHES[playerid][9] = CreatePlayerTextDraw(playerid, 190.000, 215.000, "Topi/Helm");
    PlayerTextDrawLetterSize(playerid, P_MENUCLOTHES[playerid][9], 0.209, 1.299);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][9], 2);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][9], 150);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][9], 1);

    P_MENUCLOTHES[playerid][10] = CreatePlayerTextDraw(playerid, 247.000, 190.000, "X");
    PlayerTextDrawLetterSize(playerid, P_MENUCLOTHES[playerid][10], 0.289, 1.500);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][10], 2);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][10], 150);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][10], 1);

    P_MENUCLOTHES[playerid][11] = CreatePlayerTextDraw(playerid, 190.000, 240.000, "Kacamata");
    PlayerTextDrawLetterSize(playerid, P_MENUCLOTHES[playerid][11], 0.209, 1.299);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][11], 2);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][11], 150);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][11], 1);

    P_MENUCLOTHES[playerid][12] = CreatePlayerTextDraw(playerid, 190.000, 268.000, "Aksesoris");
    PlayerTextDrawLetterSize(playerid, P_MENUCLOTHES[playerid][12], 0.209, 1.299);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][12], 2);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][12], 150);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][12], 1);

    P_MENUCLOTHES[playerid][13] = CreatePlayerTextDraw(playerid, 190.000, 294.000, "Tas/Koper");
    PlayerTextDrawLetterSize(playerid, P_MENUCLOTHES[playerid][13], 0.209, 1.299);
    PlayerTextDrawAlignment(playerid, P_MENUCLOTHES[playerid][13], 2);
    PlayerTextDrawColor(playerid, P_MENUCLOTHES[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, P_MENUCLOTHES[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, P_MENUCLOTHES[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, P_MENUCLOTHES[playerid][13], 150);
    PlayerTextDrawFont(playerid, P_MENUCLOTHES[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, P_MENUCLOTHES[playerid][13], 1);

    P_CLOTHESSELECT[playerid][0] = CreatePlayerTextDraw(playerid, 145.000, 180.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][0], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][0], 90.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][0], 1);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][0], -260013880);
    PlayerTextDrawUseBox(playerid, P_CLOTHESSELECT[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, P_CLOTHESSELECT[playerid][0], 50);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][0], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][0], 1);

    P_CLOTHESSELECT[playerid][1] = CreatePlayerTextDraw(playerid, 190.000, 186.000, "KACAMATA");
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][1], 0.232, 1.399);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][1], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][1], 2);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][1], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][1], 1);

    P_CLOTHESSELECT[playerid][2] = CreatePlayerTextDraw(playerid, 145.000, 275.000, "ld_bum:blkdot");   //beli
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][2], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][2], 90.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][2], 1);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][2], -260013880);
    PlayerTextDrawUseBox(playerid, P_CLOTHESSELECT[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, P_CLOTHESSELECT[playerid][2], 50);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][2], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, P_CLOTHESSELECT[playerid][2], 1);

    P_CLOTHESSELECT[playerid][3] = CreatePlayerTextDraw(playerid, 189.000, 281.000, "BELI");
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][3], 0.232, 1.450);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][3], 16.500, 57.500);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][3], 2);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][3], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][3], 1);

    P_CLOTHESSELECT[playerid][4] = CreatePlayerTextDraw(playerid, 112.000, 275.000, "ld_bum:blkdot");   //kiri
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][4], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][4], 30.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][4], 1);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][4], -260013880);
    PlayerTextDrawUseBox(playerid, P_CLOTHESSELECT[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, P_CLOTHESSELECT[playerid][4], 50);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][4], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, P_CLOTHESSELECT[playerid][4], 1);

    P_CLOTHESSELECT[playerid][5] = CreatePlayerTextDraw(playerid, 238.000, 275.000, "ld_bum:blkdot");   //kanan
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][5], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][5], 30.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][5], 1);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][5], -260013880);
    PlayerTextDrawUseBox(playerid, P_CLOTHESSELECT[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, P_CLOTHESSELECT[playerid][5], 50);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][5], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, P_CLOTHESSELECT[playerid][5], 1);

    P_CLOTHESSELECT[playerid][6] = CreatePlayerTextDraw(playerid, 127.000, 281.000, "<<");
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][6], 0.232, 1.450);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][6], 16.500, 16.500);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][6], 2);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][6], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][6], 1);

    P_CLOTHESSELECT[playerid][7] = CreatePlayerTextDraw(playerid, 253.000, 281.000, ">>");
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][7], 0.232, 1.450);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][7], 16.500, 16.000);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][7], 2);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][7], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][7], 1);

    P_CLOTHESSELECT[playerid][8] = CreatePlayerTextDraw(playerid, 112.000, 247.000, "ld_bum:blkdot");   //rot kiri
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][8], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][8], 30.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][8], 1);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][8], -260013880);
    PlayerTextDrawUseBox(playerid, P_CLOTHESSELECT[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, P_CLOTHESSELECT[playerid][8], 50);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][8], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, P_CLOTHESSELECT[playerid][8], 1);

    P_CLOTHESSELECT[playerid][9] = CreatePlayerTextDraw(playerid, 238.000, 247.000, "ld_bum:blkdot");   //rot kanan
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][9], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][9], 30.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][9], 1);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][9], -260013880);
    PlayerTextDrawUseBox(playerid, P_CLOTHESSELECT[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, P_CLOTHESSELECT[playerid][9], 50);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][9], 1);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][9], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, P_CLOTHESSELECT[playerid][9], 1);

    P_CLOTHESSELECT[playerid][10] = CreatePlayerTextDraw(playerid, 255.000, 253.000, "ROT >");
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][10], 0.158, 1.399);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][10], 16.500, 40.500);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][10], 2);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][10], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][10], 1);

    P_CLOTHESSELECT[playerid][11] = CreatePlayerTextDraw(playerid, 126.000, 253.000, "< ROT");
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][11], 0.158, 1.399);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][11], 16.500, 40.500);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][11], 2);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][11], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][11], 1);

    P_CLOTHESSELECT[playerid][12] = CreatePlayerTextDraw(playerid, 250.000, 398.000, "ld_bum:blkdot");  //kembali
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][12], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][12], 60.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][12], 1);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][12], -260013880);
    PlayerTextDrawUseBox(playerid, P_CLOTHESSELECT[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, P_CLOTHESSELECT[playerid][12], 50);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][12], 1);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][12], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][12], 1);
    PlayerTextDrawSetSelectable(playerid, P_CLOTHESSELECT[playerid][12], 1);

    P_CLOTHESSELECT[playerid][13] = CreatePlayerTextDraw(playerid, 317.000, 398.000, "ld_bum:blkdot");  //dialog pilih custom
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][13], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][13], 40.000, 25.000);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][13], 1);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][13], -260013880);
    PlayerTextDrawUseBox(playerid, P_CLOTHESSELECT[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, P_CLOTHESSELECT[playerid][13], 50);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][13], 1);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][13], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][13], 1);
    //PlayerTextDrawSetSelectable(playerid, P_CLOTHESSELECT[playerid][13], 1);

    P_CLOTHESSELECT[playerid][14] = CreatePlayerTextDraw(playerid, 337.000, 404.000, "15/130");
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][14], 0.232, 1.399);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][14], 400.000, 24.500);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][14], 2);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][14], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][14], 1);

    P_CLOTHESSELECT[playerid][15] = CreatePlayerTextDraw(playerid, 280.000, 404.000, "KEMBALI");
    PlayerTextDrawLetterSize(playerid, P_CLOTHESSELECT[playerid][15], 0.232, 1.450);
    PlayerTextDrawTextSize(playerid, P_CLOTHESSELECT[playerid][15], 16.500, 57.500);
    PlayerTextDrawAlignment(playerid, P_CLOTHESSELECT[playerid][15], 2);
    PlayerTextDrawColor(playerid, P_CLOTHESSELECT[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, P_CLOTHESSELECT[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, P_CLOTHESSELECT[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, P_CLOTHESSELECT[playerid][15], 255);
    PlayerTextDrawFont(playerid, P_CLOTHESSELECT[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, P_CLOTHESSELECT[playerid][15], 1);

    // Bus Waiting
    BusWait[playerid][0] = CreatePlayerTextDraw(playerid, 320.000, 351.000, "~w~Waiting_Time:_10~n~~r~NOTE~w~: Tunggu untuk lanjut ke rute berikutnya");
    PlayerTextDrawLetterSize(playerid, BusWait[playerid][0], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, BusWait[playerid][0], 2);
    PlayerTextDrawColor(playerid, BusWait[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, BusWait[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, BusWait[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, BusWait[playerid][0], 150);
    PlayerTextDrawFont(playerid, BusWait[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, BusWait[playerid][0], 1);

    //garkot
    Garage_TD[playerid][0] = CreatePlayerTextDraw(playerid, 408.000, 1266.000, "PARTICLE:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][0], 1092.000, -1267.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][0], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][0], 817731839);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][0], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][0], 1);

    Garage_TD[playerid][1] = CreatePlayerTextDraw(playerid, 466.000, 120.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][1], 140.000, 270.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][1], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][1], 572732671);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][1], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][1], 1);

    Garage_TD[playerid][2] = CreatePlayerTextDraw(playerid, 475.000, 127.000, "Garasi Bandara");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][2], 0.127, 0.998);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][2], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][2], 817731839);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][2], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][2], 1);

    Garage_TD[playerid][3] = CreatePlayerTextDraw(playerid, 475.000, 136.000, "Garasi");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][3], 0.197, 1.398);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][3], 344.000, 52.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][3], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][3], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][3], 1);

    Garage_TD[playerid][4] = CreatePlayerTextDraw(playerid, 475.000, 148.000, "Ambil kendaraan dari garasi");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][4], 0.116, 0.898);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][4], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][4], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][4], 1);

    Garage_TD[playerid][5] = CreatePlayerTextDraw(playerid, 588.000, 137.000, "Exit");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][5], 0.108, 0.998);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][5], 31.000, 19.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][5], 2);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, Garage_TD[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, Garage_TD[playerid][5], 16423459);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][5], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, Garage_TD[playerid][5], 1);

    Garage_TD[playerid][6] = CreatePlayerTextDraw(playerid, 474.000, 167.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][6], 125.000, 215.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][6], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][6], 1651536895);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][6], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][6], 1);

    Garage_TD[playerid][7] = CreatePlayerTextDraw(playerid, 475.000, 168.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][7], 123.000, 213.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][7], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][7], 572732671);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][7], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][7], 1);

    Garage_TD[playerid][8] = CreatePlayerTextDraw(playerid, 479.000, 171.000, "_");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][8], 55.000, 65.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][8], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][8], 1651536790);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][8], 0);
    PlayerTextDrawSetPreviewModel(playerid, Garage_TD[playerid][8], 560);
    PlayerTextDrawSetPreviewRot(playerid, Garage_TD[playerid][8], -15.000, 0.000, -40.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, Garage_TD[playerid][8], 6, 0);
    PlayerTextDrawSetSelectable(playerid, Garage_TD[playerid][8], 1);

    Garage_TD[playerid][9] = CreatePlayerTextDraw(playerid, 480.000, 237.000, "Sultan");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][9], 0.136, 0.998);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][9], 344.000, 52.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][9], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][9], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][9], 1);

    Garage_TD[playerid][10] = CreatePlayerTextDraw(playerid, 480.000, 245.000, "B-1248");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][10], 0.136, 0.998);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][10], 344.000, 52.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][10], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][10], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][10], 1);

    Garage_TD[playerid][11] = CreatePlayerTextDraw(playerid, 479.000, 255.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][11], 55.000, 1.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][11], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][11], 817731839);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][11], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][11], 1);

    Garage_TD[playerid][12] = CreatePlayerTextDraw(playerid, 539.000, 171.000, "_");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][12], 55.000, 65.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][12], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][12], 1651536790);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][12], 5);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][12], 0);
    PlayerTextDrawSetPreviewModel(playerid, Garage_TD[playerid][12], 411);
    PlayerTextDrawSetPreviewRot(playerid, Garage_TD[playerid][12], -15.000, 0.000, -40.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, Garage_TD[playerid][12], -3, 0);
    PlayerTextDrawSetSelectable(playerid, Garage_TD[playerid][12], 1);

    Garage_TD[playerid][13] = CreatePlayerTextDraw(playerid, 540.000, 237.000, "Infernus");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][13], 0.136, 0.998);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][13], 344.000, 52.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][13], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][13], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][13], 1);

    Garage_TD[playerid][14] = CreatePlayerTextDraw(playerid, 540.000, 245.000, "T-1245");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][14], 0.136, 0.998);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][14], 344.000, 52.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][14], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][14], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][14], 1);

    Garage_TD[playerid][15] = CreatePlayerTextDraw(playerid, 539.000, 255.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][15], 55.000, 1.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][15], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][15], 817731839);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][15], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][15], 1);

    Garage_TD[playerid][16] = CreatePlayerTextDraw(playerid, 479.000, 261.000, "_");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][16], 55.000, 65.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][16], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][16], 1651536790);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][16], 5);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][16], 0);
    PlayerTextDrawSetPreviewModel(playerid, Garage_TD[playerid][16], 468);
    PlayerTextDrawSetPreviewRot(playerid, Garage_TD[playerid][16], -15.000, 0.000, -40.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, Garage_TD[playerid][16], 5, 0);
    PlayerTextDrawSetSelectable(playerid, Garage_TD[playerid][16], 1);

    Garage_TD[playerid][17] = CreatePlayerTextDraw(playerid, 480.000, 327.000, "Sanchez");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][17], 0.136, 0.998);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][17], 344.000, 52.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][17], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][17], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][17], 1);

    Garage_TD[playerid][18] = CreatePlayerTextDraw(playerid, 480.000, 335.000, "S-2145");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][18], 0.136, 0.998);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][18], 344.000, 52.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][18], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][18], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][18], 1);

    Garage_TD[playerid][19] = CreatePlayerTextDraw(playerid, 479.000, 345.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][19], 55.000, 1.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][19], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][19], 817731839);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][19], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][19], 1);

    Garage_TD[playerid][20] = CreatePlayerTextDraw(playerid, 539.000, 261.000, "_");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][20], 55.000, 65.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][20], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][20], 1651536790);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][20], 5);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][20], 0);
    PlayerTextDrawSetPreviewModel(playerid, Garage_TD[playerid][20], 470);
    PlayerTextDrawSetPreviewRot(playerid, Garage_TD[playerid][20], -15.000, 0.000, -40.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, Garage_TD[playerid][20], 0, 0);
    PlayerTextDrawSetSelectable(playerid, Garage_TD[playerid][20], 1);

    Garage_TD[playerid][21] = CreatePlayerTextDraw(playerid, 540.000, 327.000, "Patriot");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][21], 0.136, 0.998);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][21], 344.000, 52.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][21], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][21], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][21], 1);

    Garage_TD[playerid][22] = CreatePlayerTextDraw(playerid, 540.000, 335.000, "P-8592");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][22], 0.136, 0.998);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][22], 344.000, 52.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][22], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][22], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][22], 1);

    Garage_TD[playerid][23] = CreatePlayerTextDraw(playerid, 539.000, 345.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][23], 55.000, 1.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][23], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][23], 817731839);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][23], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][23], 1);

    Garage_TD[playerid][24] = CreatePlayerTextDraw(playerid, 364.000, 120.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][24], 100.000, 270.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][24], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][24], 572732671);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][24], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][24], 1);

    Garage_TD[playerid][25] = CreatePlayerTextDraw(playerid, 371.000, 167.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][25], 86.000, 215.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][25], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][25], 1651536895);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][25], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][25], 1);

    Garage_TD[playerid][26] = CreatePlayerTextDraw(playerid, 372.000, 168.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][26], 84.000, 213.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][26], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][26], 572732671);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][26], 255);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][26], 1);

    Garage_TD[playerid][27] = CreatePlayerTextDraw(playerid, 374.000, 138.000, "Pilih Kendaraan");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][27], 0.148, 0.998);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][27], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][27], 817731839);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][27], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][27], 1);

    Garage_TD[playerid][28] = CreatePlayerTextDraw(playerid, 374.000, 149.000, "Details");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][28], 0.197, 1.398);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][28], 344.000, 52.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][28], 1);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][28], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][28], 1);

    Garage_TD[playerid][29] = CreatePlayerTextDraw(playerid, 413.000, 190.000, "Keluarkan Kendaraan");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][29], 0.108, 0.998);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][29], 31.000, 71.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][29], 2);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][29], 817731839);
    PlayerTextDrawUseBox(playerid, Garage_TD[playerid][29], 1);
    PlayerTextDrawBoxColor(playerid, Garage_TD[playerid][29], 16423459);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][29], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][29], 2);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][29], 1);
    PlayerTextDrawSetSelectable(playerid, Garage_TD[playerid][29], 1);

    Garage_TD[playerid][30] = CreatePlayerTextDraw(playerid, 413.000, 206.000, "Kendaraan: Sultan ~n~Plate: B-1245 ~n~Fuel: 100 ~n~Body:1000");
    PlayerTextDrawLetterSize(playerid, Garage_TD[playerid][30], 0.150, 1.098);
    PlayerTextDrawTextSize(playerid, Garage_TD[playerid][30], 60.000, 71.000);
    PlayerTextDrawAlignment(playerid, Garage_TD[playerid][30], 2);
    PlayerTextDrawColor(playerid, Garage_TD[playerid][30], -1);
    PlayerTextDrawUseBox(playerid, Garage_TD[playerid][30], 1);
    PlayerTextDrawBoxColor(playerid, Garage_TD[playerid][30], 1768515910);
    PlayerTextDrawSetShadow(playerid, Garage_TD[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, Garage_TD[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, Garage_TD[playerid][30], -2147483393);
    PlayerTextDrawFont(playerid, Garage_TD[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, Garage_TD[playerid][30], 1);

    TollTD[playerid][0] = CreatePlayerTextDraw(playerid, 377.000, 152.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][0], 107.000, 206.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][0], -2139062017);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][0], 1);

    TollTD[playerid][1] = CreatePlayerTextDraw(playerid, 380.000, 156.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][1], 101.000, 197.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][1], 421097727);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][1], 1);

    TollTD[playerid][2] = CreatePlayerTextDraw(playerid, 432.000, 156.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][2], 49.000, 75.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][2], 16777215);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][2], 1);

    TollTD[playerid][3] = CreatePlayerTextDraw(playerid, 384.000, 159.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][3], 92.000, 3.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][3], 1);

    TollTD[playerid][4] = CreatePlayerTextDraw(playerid, 384.000, 159.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][4], 3.000, 189.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][4], 1);

    TollTD[playerid][5] = CreatePlayerTextDraw(playerid, 475.000, 159.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][5], 3.000, 189.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][5], 1);

    TollTD[playerid][6] = CreatePlayerTextDraw(playerid, 384.000, 346.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][6], 94.000, 3.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][6], 1);

    TollTD[playerid][7] = CreatePlayerTextDraw(playerid, 384.000, 236.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][7], 50.000, 113.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][7], -65281);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][7], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][7], 1);

    TollTD[playerid][8] = CreatePlayerTextDraw(playerid, 437.000, 236.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][8], 35.000, 63.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][8], -65281);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][8], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][8], 1);

    TollTD[playerid][9] = CreatePlayerTextDraw(playerid, 395.000, 170.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][9], 74.000, 41.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][9], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][9], 1768516095);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][9], 1);

    TollTD[playerid][10] = CreatePlayerTextDraw(playerid, 407.000, 177.000, "GERBANG TOLL");
    PlayerTextDrawLetterSize(playerid, TollTD[playerid][10], 0.217, 1.098);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][10], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][10], -5963521);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, TollTD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][10], 1);

    TollTD[playerid][11] = CreatePlayerTextDraw(playerid, 432.000, 188.000, "DCRP ~w~Theater");
    PlayerTextDrawLetterSize(playerid, TollTD[playerid][11], 0.238, 1.399);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][11], 2);
    PlayerTextDrawColor(playerid, TollTD[playerid][11], -260013825);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, TollTD[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][11], 1);

    TollTD[playerid][12] = CreatePlayerTextDraw(playerid, 392.500, 240.000, "Tanda Terima");
    PlayerTextDrawLetterSize(playerid, TollTD[playerid][12], 0.170, 0.999);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][12], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, TollTD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][12], 1);

    TollTD[playerid][13] = CreatePlayerTextDraw(playerid, 387.000, 252.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][13], 44.000, 55.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][13], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][13], 421097727);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][13], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][13], 1);

    TollTD[playerid][14] = CreatePlayerTextDraw(playerid, 396.000, 268.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][14], 27.000, 5.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][14], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][14], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][14], 1);

    TollTD[playerid][15] = CreatePlayerTextDraw(playerid, 399.000, 271.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][15], 21.000, 7.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][15], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][15], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][15], 1);

    TollTD[playerid][16] = CreatePlayerTextDraw(playerid, 400.000, 273.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][16], 19.000, 1.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][16], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][16], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][16], 1);

    TollTD[playerid][17] = CreatePlayerTextDraw(playerid, 435.000, 260.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][17], 39.000, 41.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][17], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][17], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][17], 1);

    TollTD[playerid][18] = CreatePlayerTextDraw(playerid, 437.000, 262.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][18], 35.000, 37.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][18], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][18], -65281);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][18], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][18], 1);

    TollTD[playerid][19] = CreatePlayerTextDraw(playerid, 439.000, 264.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][19], 31.000, 33.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][19], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][19], 255);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][19], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][19], 1);
    PlayerTextDrawSetSelectable(playerid, TollTD[playerid][19], 1);

    TollTD[playerid][20] = CreatePlayerTextDraw(playerid, 450.000, 276.000, "TAP");
    PlayerTextDrawLetterSize(playerid, TollTD[playerid][20], 0.170, 0.998);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][20], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][20], -2686721);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][20], 150);
    PlayerTextDrawFont(playerid, TollTD[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][20], 1);

    TollTD[playerid][21] = CreatePlayerTextDraw(playerid, 439.000, 239.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][21], 31.000, 21.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][21], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][21], 255);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][21], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][21], 1);

    TollTD[playerid][22] = CreatePlayerTextDraw(playerid, 441.000, 241.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, TollTD[playerid][22], 27.000, 17.000);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][22], 1);
    PlayerTextDrawColor(playerid, TollTD[playerid][22], 1768516095);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][22], 255);
    PlayerTextDrawFont(playerid, TollTD[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][22], 1);

    TollTD[playerid][23] = CreatePlayerTextDraw(playerid, 455.000, 245.000, "$50");
    PlayerTextDrawLetterSize(playerid, TollTD[playerid][23], 0.158, 0.998);
    PlayerTextDrawAlignment(playerid, TollTD[playerid][23], 2);
    PlayerTextDrawColor(playerid, TollTD[playerid][23], 16711935);
    PlayerTextDrawSetShadow(playerid, TollTD[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, TollTD[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, TollTD[playerid][23], 150);
    PlayerTextDrawFont(playerid, TollTD[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, TollTD[playerid][23], 1);

    PomTD[playerid][0] = CreatePlayerTextDraw(playerid, 588.000, 150.000, "LD_DUAL:white");
    PlayerTextDrawTextSize(playerid, PomTD[playerid][0], 0.500, 223.000);
    PlayerTextDrawAlignment(playerid, PomTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, PomTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, PomTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PomTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PomTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, PomTD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, PomTD[playerid][0], 1);

    PomTD[playerid][1] = CreatePlayerTextDraw(playerid, 628.000, 150.000, "LD_DUAL:white");
    PlayerTextDrawTextSize(playerid, PomTD[playerid][1], 0.500, 223.000);
    PlayerTextDrawAlignment(playerid, PomTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, PomTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, PomTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PomTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PomTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, PomTD[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, PomTD[playerid][1], 1);

    PomTD[playerid][2] = CreatePlayerTextDraw(playerid, 628.000, 150.000, "LD_DUAL:white");
    PlayerTextDrawTextSize(playerid, PomTD[playerid][2], -39.500, 0.500);
    PlayerTextDrawAlignment(playerid, PomTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, PomTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, PomTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PomTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PomTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, PomTD[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, PomTD[playerid][2], 1);

    PomTD[playerid][3] = CreatePlayerTextDraw(playerid, 628.000, 373.000, "LD_DUAL:white");
    PlayerTextDrawTextSize(playerid, PomTD[playerid][3], -39.500, 0.500);
    PlayerTextDrawAlignment(playerid, PomTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, PomTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, PomTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PomTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PomTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, PomTD[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, PomTD[playerid][3], 1);

    PomTD[playerid][4] = CreatePlayerTextDraw(playerid, 628.000, 372.000, "LD_DUAL:white");
    PlayerTextDrawTextSize(playerid, PomTD[playerid][4], -39.500, -221.500);
    PlayerTextDrawAlignment(playerid, PomTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, PomTD[playerid][4], 6553855);
    PlayerTextDrawSetShadow(playerid, PomTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PomTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PomTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, PomTD[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, PomTD[playerid][4], 1);

    PomTD[playerid][5] = CreatePlayerTextDraw(playerid, 563.000, 308.000, "_");
    PlayerTextDrawTextSize(playerid, PomTD[playerid][5], 90.000, 90.000);
    PlayerTextDrawAlignment(playerid, PomTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, PomTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, PomTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PomTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PomTD[playerid][5], 0);
    PlayerTextDrawFont(playerid, PomTD[playerid][5], 5);
    PlayerTextDrawSetProportional(playerid, PomTD[playerid][5], 0);
    PlayerTextDrawSetPreviewModel(playerid, PomTD[playerid][5], 1650);
    PlayerTextDrawSetPreviewRot(playerid, PomTD[playerid][5], 0.000, 0.000, 0.000, 2.500);
    PlayerTextDrawSetPreviewVehCol(playerid, PomTD[playerid][5], 0, 0);

    PomTD[playerid][6] = CreatePlayerTextDraw(playerid, 608.000, 158.000, "100");
    PlayerTextDrawLetterSize(playerid, PomTD[playerid][6], 0.200, 1.099);
    PlayerTextDrawAlignment(playerid, PomTD[playerid][6], 2);
    PlayerTextDrawColor(playerid, PomTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, PomTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PomTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PomTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, PomTD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, PomTD[playerid][6], 1);

    PomTD[playerid][7] = CreatePlayerTextDraw(playerid, 608.000, 168.000, "LITER");
    PlayerTextDrawLetterSize(playerid, PomTD[playerid][7], 0.200, 1.099);
    PlayerTextDrawAlignment(playerid, PomTD[playerid][7], 2);
    PlayerTextDrawColor(playerid, PomTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, PomTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PomTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PomTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, PomTD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, PomTD[playerid][7], 1);

    InsuranceTD[playerid][0] = CreatePlayerTextDraw(playerid, 10.000, 220.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, InsuranceTD[playerid][0], 95.000, 60.000);
    PlayerTextDrawAlignment(playerid, InsuranceTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, InsuranceTD[playerid][0], 572732671);
    PlayerTextDrawSetShadow(playerid, InsuranceTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InsuranceTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, InsuranceTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, InsuranceTD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, InsuranceTD[playerid][0], 1);

    InsuranceTD[playerid][1] = CreatePlayerTextDraw(playerid, 10.000, 226.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, InsuranceTD[playerid][1], 1.000, 49.000);
    PlayerTextDrawAlignment(playerid, InsuranceTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, InsuranceTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, InsuranceTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InsuranceTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, InsuranceTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, InsuranceTD[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, InsuranceTD[playerid][1], 1);

    InsuranceTD[playerid][2] = CreatePlayerTextDraw(playerid, 9.000, 220.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, InsuranceTD[playerid][2], 1.000, 60.000);
    PlayerTextDrawAlignment(playerid, InsuranceTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, InsuranceTD[playerid][2], -602653441);
    PlayerTextDrawSetShadow(playerid, InsuranceTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InsuranceTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, InsuranceTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, InsuranceTD[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, InsuranceTD[playerid][2], 1);

    InsuranceTD[playerid][3] = CreatePlayerTextDraw(playerid, 59.000, 223.000, "Insurance Keliling");
    PlayerTextDrawLetterSize(playerid, InsuranceTD[playerid][3], 0.179, 1.199);
    PlayerTextDrawAlignment(playerid, InsuranceTD[playerid][3], 2);
    PlayerTextDrawColor(playerid, InsuranceTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, InsuranceTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InsuranceTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, InsuranceTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, InsuranceTD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, InsuranceTD[playerid][3], 1);

    InsuranceTD[playerid][4] = CreatePlayerTextDraw(playerid, 51.000, 201.000, "HUD:radar_impound");
    PlayerTextDrawTextSize(playerid, InsuranceTD[playerid][4], 15.000, 20.000);
    PlayerTextDrawAlignment(playerid, InsuranceTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, InsuranceTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, InsuranceTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, InsuranceTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, InsuranceTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, InsuranceTD[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, InsuranceTD[playerid][4], 1);

    InsuranceTD[playerid][5] = CreatePlayerTextDraw(playerid, 58.000, 235.000, "Sistem akan mengirim semua~n~kendaraan pribadi yang tidak~n~ dinaiki oleh pemain dalam");
    PlayerTextDrawLetterSize(playerid, InsuranceTD[playerid][5], 0.170, 1.098);
    PlayerTextDrawAlignment(playerid, InsuranceTD[playerid][5], 2);
    PlayerTextDrawColor(playerid, InsuranceTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, InsuranceTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, InsuranceTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, InsuranceTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, InsuranceTD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, InsuranceTD[playerid][5], 1);

    InsuranceTD[playerid][6] = CreatePlayerTextDraw(playerid, 58.000, 267.000, "01 Menit 20 Detik");
    PlayerTextDrawLetterSize(playerid, InsuranceTD[playerid][6], 0.149, 1.199);
    PlayerTextDrawAlignment(playerid, InsuranceTD[playerid][6], 2);
    PlayerTextDrawColor(playerid, InsuranceTD[playerid][6], -7601921);
    PlayerTextDrawSetShadow(playerid, InsuranceTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, InsuranceTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, InsuranceTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, InsuranceTD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, InsuranceTD[playerid][6], 1);
}

CreateTextDraw()
{
    gServerMessage[0] = TextDrawCreate(211.000, 41.000, "LD_SPAC:white");
    TextDrawTextSize(gServerMessage[0], 218.000, 62.000);
    TextDrawAlignment(gServerMessage[0], 1);
    TextDrawColor(gServerMessage[0], -6710840);
    TextDrawSetShadow(gServerMessage[0], 0);
    TextDrawSetOutline(gServerMessage[0], 0);
    TextDrawBackgroundColor(gServerMessage[0], 255);
    TextDrawFont(gServerMessage[0], 4);
    TextDrawSetProportional(gServerMessage[0], 1);

    gServerMessage[1] = TextDrawCreate(213.000, 44.000, "LD_SPAC:white");
    TextDrawTextSize(gServerMessage[1], 214.000, 57.000);
    TextDrawAlignment(gServerMessage[1], 1);
    TextDrawColor(gServerMessage[1], 200);
    TextDrawSetShadow(gServerMessage[1], 0);
    TextDrawSetOutline(gServerMessage[1], 0);
    TextDrawBackgroundColor(gServerMessage[1], 255);
    TextDrawFont(gServerMessage[1], 4);
    TextDrawSetProportional(gServerMessage[1], 1);

    gServerMessage[2] = TextDrawCreate(220.000, 50.000, "LD_CHAT:badchat");
    TextDrawTextSize(gServerMessage[2], 10.000, 10.000);
    TextDrawAlignment(gServerMessage[2], 1);
    TextDrawColor(gServerMessage[2], -1);
    TextDrawSetShadow(gServerMessage[2], 0);
    TextDrawSetOutline(gServerMessage[2], 0);
    TextDrawBackgroundColor(gServerMessage[2], 255);
    TextDrawFont(gServerMessage[2], 4);
    TextDrawSetProportional(gServerMessage[2], 1);

    gServerMessage[3] = TextDrawCreate(232.000, 50.000, "ANNOUNCEMENT");
    TextDrawLetterSize(gServerMessage[3], 0.200, 0.999);
    TextDrawAlignment(gServerMessage[3], 1);
    TextDrawColor(gServerMessage[3], -1);
    TextDrawSetShadow(gServerMessage[3], 1);
    TextDrawSetOutline(gServerMessage[3], 1);
    TextDrawBackgroundColor(gServerMessage[3], 150);
    TextDrawFont(gServerMessage[3], 1);
    TextDrawSetProportional(gServerMessage[3], 1);

    gServerMessage[4] = TextDrawCreate(219.000, 71.000, "SERVER AKAN MAINTANCE PADA PUKUL 12.00 WIB, DIHARAPKAN UNTUK KALIAN MEMASUKKAN KENDARAAN KE GARASI TERDEKAT");
    TextDrawLetterSize(gServerMessage[4], 0.209, 0.898);
    TextDrawTextSize(gServerMessage[4], 416.000, 61.000);
    TextDrawAlignment(gServerMessage[4], 1);
    TextDrawColor(gServerMessage[4], -1);
    TextDrawSetShadow(gServerMessage[4], 1);
    TextDrawSetOutline(gServerMessage[4], 1);
    TextDrawBackgroundColor(gServerMessage[4], 150);
    TextDrawFont(gServerMessage[4], 1);
    TextDrawSetProportional(gServerMessage[4], 1);

    gServerMessage[5] = TextDrawCreate(379.000, 106.000, "Admin By: DCRP - YellowKitty");
    TextDrawLetterSize(gServerMessage[5], 0.159, 0.898);
    TextDrawAlignment(gServerMessage[5], 2);
    TextDrawColor(gServerMessage[5], -1);
    TextDrawSetShadow(gServerMessage[5], 1);
    TextDrawSetOutline(gServerMessage[5], 1);
    TextDrawBackgroundColor(gServerMessage[5], 150);
    TextDrawFont(gServerMessage[5], 1);
    TextDrawSetProportional(gServerMessage[5], 1);

    gServerMessage[6] = TextDrawCreate(328.000, 104.000, "LD_SPAC:white");
    TextDrawTextSize(gServerMessage[6], 101.000, 14.000);
    TextDrawAlignment(gServerMessage[6], 1);
    TextDrawColor(gServerMessage[6], 200);
    TextDrawSetShadow(gServerMessage[6], 0);
    TextDrawSetOutline(gServerMessage[6], 0);
    TextDrawBackgroundColor(gServerMessage[6], 255);
    TextDrawFont(gServerMessage[6], 4);
    TextDrawSetProportional(gServerMessage[6], 1);
    
    ATRP_Warning[0] = TextDrawCreate(-2.000, -2.000, "LD_BUM:blkdot");
    TextDrawTextSize(ATRP_Warning[0], 657.000, 460.000);
    TextDrawAlignment(ATRP_Warning[0], 1);
    TextDrawColor(ATRP_Warning[0], -16777126);
    TextDrawSetShadow(ATRP_Warning[0], 0);
    TextDrawSetOutline(ATRP_Warning[0], 0);
    TextDrawBackgroundColor(ATRP_Warning[0], 255);
    TextDrawFont(ATRP_Warning[0], 4);
    TextDrawSetProportional(ATRP_Warning[0], 1);

    ATRP_Warning[1] = TextDrawCreate(238.000, 153.000, "LD_BUM:blkdot");
    TextDrawTextSize(ATRP_Warning[1], 165.000, 2.000);
    TextDrawAlignment(ATRP_Warning[1], 1);
    TextDrawColor(ATRP_Warning[1], -1);
    TextDrawSetShadow(ATRP_Warning[1], 0);
    TextDrawSetOutline(ATRP_Warning[1], 0);
    TextDrawBackgroundColor(ATRP_Warning[1], 255);
    TextDrawFont(ATRP_Warning[1], 4);
    TextDrawSetProportional(ATRP_Warning[1], 1);

    ATRP_Warning[2] = TextDrawCreate(238.000, 260.000, "LD_BUM:blkdot");
    TextDrawTextSize(ATRP_Warning[2], 165.000, 2.000);
    TextDrawAlignment(ATRP_Warning[2], 1);
    TextDrawColor(ATRP_Warning[2], -1);
    TextDrawSetShadow(ATRP_Warning[2], 0);
    TextDrawSetOutline(ATRP_Warning[2], 0);
    TextDrawBackgroundColor(ATRP_Warning[2], 255);
    TextDrawFont(ATRP_Warning[2], 4);
    TextDrawSetProportional(ATRP_Warning[2], 1);

    ATRP_Warning[3] = TextDrawCreate(238.000, 154.000, "LD_BUM:blkdot");
    TextDrawTextSize(ATRP_Warning[3], 2.000, 107.000);
    TextDrawAlignment(ATRP_Warning[3], 1);
    TextDrawColor(ATRP_Warning[3], -1);
    TextDrawSetShadow(ATRP_Warning[3], 0);
    TextDrawSetOutline(ATRP_Warning[3], 0);
    TextDrawBackgroundColor(ATRP_Warning[3], 255);
    TextDrawFont(ATRP_Warning[3], 4);
    TextDrawSetProportional(ATRP_Warning[3], 1);

    ATRP_Warning[4] = TextDrawCreate(401.000, 154.000, "LD_BUM:blkdot");
    TextDrawTextSize(ATRP_Warning[4], 2.000, 107.000);
    TextDrawAlignment(ATRP_Warning[4], 1);
    TextDrawColor(ATRP_Warning[4], -1);
    TextDrawSetShadow(ATRP_Warning[4], 0);
    TextDrawSetOutline(ATRP_Warning[4], 0);
    TextDrawBackgroundColor(ATRP_Warning[4], 255);
    TextDrawFont(ATRP_Warning[4], 4);
    TextDrawSetProportional(ATRP_Warning[4], 1);

    ATRP_Warning[5] = TextDrawCreate(243.000, 181.000, "LD_BUM:blkdot");
    TextDrawTextSize(ATRP_Warning[5], 156.000, -1.000);
    TextDrawAlignment(ATRP_Warning[5], 1);
    TextDrawColor(ATRP_Warning[5], -1);
    TextDrawSetShadow(ATRP_Warning[5], 0);
    TextDrawSetOutline(ATRP_Warning[5], 0);
    TextDrawBackgroundColor(ATRP_Warning[5], 255);
    TextDrawFont(ATRP_Warning[5], 4);
    TextDrawSetProportional(ATRP_Warning[5], 1);

    ATRP_Warning[6] = TextDrawCreate(268.000, 157.000, "WARNING!");
    TextDrawLetterSize(ATRP_Warning[6], 0.458, 2.198);
    TextDrawAlignment(ATRP_Warning[6], 1);
    TextDrawColor(ATRP_Warning[6], -1);
    TextDrawSetShadow(ATRP_Warning[6], 0);
    TextDrawSetOutline(ATRP_Warning[6], 0);
    TextDrawBackgroundColor(ATRP_Warning[6], 150);
    TextDrawFont(ATRP_Warning[6], 1);
    TextDrawSetProportional(ATRP_Warning[6], 1);

    ATRP_Warning[7] = TextDrawCreate(347.000, 158.000, "LD_CHAT:badchat");
    TextDrawTextSize(ATRP_Warning[7], 17.000, 17.000);
    TextDrawAlignment(ATRP_Warning[7], 1);
    TextDrawColor(ATRP_Warning[7], -1);
    TextDrawSetShadow(ATRP_Warning[7], 0);
    TextDrawSetOutline(ATRP_Warning[7], 0);
    TextDrawBackgroundColor(ATRP_Warning[7], 255);
    TextDrawFont(ATRP_Warning[7], 4);
    TextDrawSetProportional(ATRP_Warning[7], 1);

    ATRP_Warning[8] = TextDrawCreate(256.000, 193.000, "ANAK BUAH WAHYU DILARANG MAIN DI DCRPTOD");
    TextDrawLetterSize(ATRP_Warning[8], 0.250, 1.299);
    TextDrawTextSize(ATRP_Warning[8], 381.000, 7.000);
    TextDrawAlignment(ATRP_Warning[8], 1);
    TextDrawColor(ATRP_Warning[8], -1);
    TextDrawSetShadow(ATRP_Warning[8], 0);
    TextDrawSetOutline(ATRP_Warning[8], 0);
    TextDrawBackgroundColor(ATRP_Warning[8], 150);
    TextDrawFont(ATRP_Warning[8], 1);
    TextDrawSetProportional(ATRP_Warning[8], 1);

    ATRP_Warning[9] = TextDrawCreate(397.000, 242.000, "Warned by: DCRP - Azpsss.");
    TextDrawLetterSize(ATRP_Warning[9], 0.159, 1.098);
    TextDrawTextSize(ATRP_Warning[9], 462.000, -5.000);
    TextDrawAlignment(ATRP_Warning[9], 3);
    TextDrawColor(ATRP_Warning[9], -1);
    TextDrawSetShadow(ATRP_Warning[9], 0);
    TextDrawSetOutline(ATRP_Warning[9], 0);
    TextDrawBackgroundColor(ATRP_Warning[9], 150);
    TextDrawFont(ATRP_Warning[9], 1);
    TextDrawSetProportional(ATRP_Warning[9], 1);
    
    DCRPLOGO[0] = TextDrawCreate(545.000, 5.000, "DEVINE CITY ROLEPLAY");
    TextDrawLetterSize(DCRPLOGO[0], 0.150, 0.699);
    TextDrawAlignment(DCRPLOGO[0], 1);
    TextDrawColor(DCRPLOGO[0], -1);
    TextDrawSetShadow(DCRPLOGO[0], 0);
    TextDrawSetOutline(DCRPLOGO[0], 0);
    TextDrawBackgroundColor(DCRPLOGO[0], 150);
    TextDrawFont(DCRPLOGO[0], 1);
    TextDrawSetProportional(DCRPLOGO[0], 1);
    
    // Restart Server
    gServerTextdraws[0] = TextDrawCreate(22.005966, 209.766693, "_");
    TextDrawLetterSize(gServerTextdraws[0], 0.263191, 1.156665);
    TextDrawAlignment(gServerTextdraws[0], 1);
    TextDrawColor(gServerTextdraws[0], -1);
    TextDrawSetShadow(gServerTextdraws[0], 0);
    TextDrawSetOutline(gServerTextdraws[0], 1);
    TextDrawBackgroundColor(gServerTextdraws[0], 255);
    TextDrawFont(gServerTextdraws[0], 3);
    TextDrawSetProportional(gServerTextdraws[0], 1);
    TextDrawSetShadow(gServerTextdraws[0], 0);

    // Robbery
    RobberyGlobalTD[0] = TextDrawCreate(18.000, 294.000, "LD_DUAL:white");
    TextDrawTextSize(RobberyGlobalTD[0], 104.000, 38.000);
    TextDrawAlignment(RobberyGlobalTD[0], 1);
    TextDrawColor(RobberyGlobalTD[0], 1926328957);
    TextDrawSetShadow(RobberyGlobalTD[0], 0);
    TextDrawSetOutline(RobberyGlobalTD[0], 0);
    TextDrawBackgroundColor(RobberyGlobalTD[0], 255);
    TextDrawFont(RobberyGlobalTD[0], 4);
    TextDrawSetProportional(RobberyGlobalTD[0], 1);

    RobberyGlobalTD[1] = TextDrawCreate(18.000, 294.000, "LD_DUAL:white");
    TextDrawTextSize(RobberyGlobalTD[1], 24.000, 19.000);
    TextDrawAlignment(RobberyGlobalTD[1], 1);
    TextDrawColor(RobberyGlobalTD[1], 1926329087);
    TextDrawSetShadow(RobberyGlobalTD[1], 0);
    TextDrawSetOutline(RobberyGlobalTD[1], 0);
    TextDrawBackgroundColor(RobberyGlobalTD[1], 255);
    TextDrawFont(RobberyGlobalTD[1], 4);
    TextDrawSetProportional(RobberyGlobalTD[1], 1);

    RobberyGlobalTD[2] = TextDrawCreate(25.000, 297.000, "HUD:radar_ammugun");
    TextDrawTextSize(RobberyGlobalTD[2], 12.000, 12.000);
    TextDrawAlignment(RobberyGlobalTD[2], 1);
    TextDrawColor(RobberyGlobalTD[2], -1);
    TextDrawSetShadow(RobberyGlobalTD[2], 0);
    TextDrawSetOutline(RobberyGlobalTD[2], 0);
    TextDrawBackgroundColor(RobberyGlobalTD[2], 255);
    TextDrawFont(RobberyGlobalTD[2], 4);
    TextDrawSetProportional(RobberyGlobalTD[2], 1);

    RobberyGlobalTD[3] = TextDrawCreate(44.000, 293.000, "DCRP~n~Perampokan Warung");
    TextDrawLetterSize(RobberyGlobalTD[3], 0.129, 0.999);
    TextDrawAlignment(RobberyGlobalTD[3], 1);
    TextDrawColor(RobberyGlobalTD[3], -1);
    TextDrawSetShadow(RobberyGlobalTD[3], 0);
    TextDrawSetOutline(RobberyGlobalTD[3], 0);
    TextDrawBackgroundColor(RobberyGlobalTD[3], 150);
    TextDrawFont(RobberyGlobalTD[3], 2);
    TextDrawSetProportional(RobberyGlobalTD[3], 1);

    RobberyGlobalTD[4] = TextDrawCreate(20.000, 312.000, "Perampokan Warung gagal, anda terlalu~n~jauh dari Warung!");
    TextDrawLetterSize(RobberyGlobalTD[4], 0.129, 0.999);
    TextDrawAlignment(RobberyGlobalTD[4], 1);
    TextDrawColor(RobberyGlobalTD[4], -1);
    TextDrawSetShadow(RobberyGlobalTD[4], 0);
    TextDrawSetOutline(RobberyGlobalTD[4], 0);
    TextDrawBackgroundColor(RobberyGlobalTD[4], 150);
    TextDrawFont(RobberyGlobalTD[4], 1);
    TextDrawSetProportional(RobberyGlobalTD[4], 1);
        
    //Stress Purple
    StressPurple[0] = TextDrawCreate(314.000000, 1.000000, "_");
	TextDrawFont(StressPurple[0], 1);
	TextDrawLetterSize(StressPurple[0], 0.600000, 51.049999);
	TextDrawTextSize(StressPurple[0], 298.500000, 676.500000);
	TextDrawSetOutline(StressPurple[0], 1);
	TextDrawSetShadow(StressPurple[0], 0);
	TextDrawAlignment(StressPurple[0], 2);
	TextDrawColor(StressPurple[0], -1);
	TextDrawBackgroundColor(StressPurple[0], 255);
	TextDrawBoxColor(StressPurple[0], -2147450812);
	TextDrawUseBox(StressPurple[0], 1);
	TextDrawSetProportional(StressPurple[0], 1);
	TextDrawSetSelectable(StressPurple[0], 0);
}
