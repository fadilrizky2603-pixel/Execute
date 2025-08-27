//#include <YSI_Coding\y_hooks>
#define MAX_REMEMBERS	45
#define KEIZI:%0(%1) forward %0(%1); public %0(%1)
enum Remember_Data
{
	bool:remindersMustClicked,
	bool:remindersClicked,
}
new RememberData[MAX_PLAYERS][MAX_REMEMBERS][Remember_Data];
new PlayerText: RememberTD[MAX_PLAYERS][3];
new PlayerText: RobTD[MAX_PLAYERS][45];
new RobWave[MAX_PLAYERS],Float:RobValue[MAX_PLAYERS], RobTimers[MAX_PLAYERS], bool:IsPlayerRobbing[MAX_PLAYERS];
new Float:RobTimersDecrease[MAX_PLAYERS], RobCount[MAX_PLAYERS];
new CooldownRobWarung;
RobWarung_CreateTextDraw(playerid)
{
	RememberTD[playerid][0] = CreatePlayerTextDraw(playerid, -10.000, -12.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RememberTD[playerid][0], 658.000, 465.000);
	PlayerTextDrawAlignment(playerid, RememberTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, RememberTD[playerid][0], 100);
	PlayerTextDrawSetShadow(playerid, RememberTD[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, RememberTD[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, RememberTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, RememberTD[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, RememberTD[playerid][0], 1);

	RememberTD[playerid][1] = CreatePlayerTextDraw(playerid, 168.000, 123.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RememberTD[playerid][1], 296.000, 240.000);
	PlayerTextDrawAlignment(playerid, RememberTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, RememberTD[playerid][1], 538976511);
	PlayerTextDrawSetShadow(playerid, RememberTD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, RememberTD[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, RememberTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, RememberTD[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, RememberTD[playerid][1], 1);

	RememberTD[playerid][2] = CreatePlayerTextDraw(playerid, 173.000, 325.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, RememberTD[playerid][2], 286.000, 32.000);
	PlayerTextDrawAlignment(playerid, RememberTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, RememberTD[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, RememberTD[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, RememberTD[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, RememberTD[playerid][2], 255);
	PlayerTextDrawFont(playerid, RememberTD[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, RememberTD[playerid][2], 1);

	RobTD[playerid][0] = CreatePlayerTextDraw(playerid, 205.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][0], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][0], 1);

	RobTD[playerid][1] = CreatePlayerTextDraw(playerid, 237.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][1], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][1], 1);

	RobTD[playerid][2] = CreatePlayerTextDraw(playerid, 269.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][2], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][2], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][2], 1);

	RobTD[playerid][3] = CreatePlayerTextDraw(playerid, 301.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][3], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][3], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][3], 1);

	RobTD[playerid][4] = CreatePlayerTextDraw(playerid, 333.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][4], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][4], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][4], 1);

	RobTD[playerid][5] = CreatePlayerTextDraw(playerid, 365.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][5], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][5], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][5], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][5], 1);

	RobTD[playerid][6] = CreatePlayerTextDraw(playerid, 397.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][6], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][6], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][6], 1);

	RobTD[playerid][7] = CreatePlayerTextDraw(playerid, 429.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][7], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][7], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][7], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][7], 1);

	RobTD[playerid][8] = CreatePlayerTextDraw(playerid, 173.000, 173.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][8], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][8], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][8], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][8], 1);

	RobTD[playerid][9] = CreatePlayerTextDraw(playerid, 205.000, 173.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][9], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][9], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][9], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][9], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][9], 1);

	RobTD[playerid][10] = CreatePlayerTextDraw(playerid, 237.000, 173.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][10], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][10], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][10], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][10], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][10], 1);

	RobTD[playerid][11] = CreatePlayerTextDraw(playerid, 269.000, 173.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][11], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][11], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][11], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][11], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][11], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][11], 1);

	RobTD[playerid][12] = CreatePlayerTextDraw(playerid, 301.000, 173.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][12], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][12], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][12], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][12], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][12], 1);

	RobTD[playerid][13] = CreatePlayerTextDraw(playerid, 333.000, 173.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][13], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][13], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][13], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][13], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][13], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][13], 1);

	RobTD[playerid][14] = CreatePlayerTextDraw(playerid, 365.000, 173.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][14], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][14], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][14], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][14], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][14], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][14], 1);

	RobTD[playerid][15] = CreatePlayerTextDraw(playerid, 397.000, 173.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][15], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][15], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][15], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][15], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][15], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][15], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][15], 1);

	RobTD[playerid][16] = CreatePlayerTextDraw(playerid, 429.000, 173.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][16], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][16], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][16], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][16], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][16], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][16], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][16], 1);

	RobTD[playerid][17] = CreatePlayerTextDraw(playerid, 173.000, 210.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][17], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][17], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][17], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][17], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][17], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][17], 1);

	RobTD[playerid][18] = CreatePlayerTextDraw(playerid, 205.000, 210.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][18], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][18], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][18], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][18], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][18], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][18], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][18], 1);

	RobTD[playerid][19] = CreatePlayerTextDraw(playerid, 237.000, 210.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][19], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][19], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][19], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][19], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][19], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][19], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][19], 1);

	RobTD[playerid][20] = CreatePlayerTextDraw(playerid, 269.000, 210.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][20], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][20], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][20], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][20], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][20], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][20], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][20], 1);

	RobTD[playerid][21] = CreatePlayerTextDraw(playerid, 301.000, 210.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][21], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][21], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][21], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][21], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][21], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][21], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][21], 1);

	RobTD[playerid][22] = CreatePlayerTextDraw(playerid, 333.000, 210.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][22], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][22], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][22], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][22], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][22], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][22], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][22], 1);

	RobTD[playerid][23] = CreatePlayerTextDraw(playerid, 365.000, 210.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][23], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][23], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][23], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][23], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][23], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][23], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][23], 1);

	RobTD[playerid][24] = CreatePlayerTextDraw(playerid, 397.000, 210.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][24], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][24], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][24], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][24], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][24], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][24], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][24], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][24], 1);

	RobTD[playerid][25] = CreatePlayerTextDraw(playerid, 429.000, 210.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][25], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][25], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][25], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][25], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][25], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][25], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][25], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][25], 1);

	RobTD[playerid][26] = CreatePlayerTextDraw(playerid, 173.000, 247.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][26], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][26], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][26], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][26], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][26], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][26], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][26], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][26], 1);

	RobTD[playerid][27] = CreatePlayerTextDraw(playerid, 205.000, 247.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][27], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][27], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][27], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][27], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][27], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][27], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][27], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][27], 1);

	RobTD[playerid][28] = CreatePlayerTextDraw(playerid, 237.000, 247.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][28], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][28], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][28], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][28], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][28], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][28], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][28], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][28], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][28], 1);

	RobTD[playerid][29] = CreatePlayerTextDraw(playerid, 269.000, 247.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][29], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][29], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][29], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][29], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][29], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][29], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][29], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][29], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][29], 1);

	RobTD[playerid][30] = CreatePlayerTextDraw(playerid, 301.000, 247.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][30], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][30], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][30], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][30], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][30], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][30], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][30], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][30], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][30], 1);

	RobTD[playerid][31] = CreatePlayerTextDraw(playerid, 333.000, 247.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][31], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][31], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][31], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][31], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][31], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][31], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][31], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][31], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][31], 1);

	RobTD[playerid][32] = CreatePlayerTextDraw(playerid, 365.000, 247.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][32], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][32], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][32], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][32], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][32], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][32], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][32], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][32], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][32], 1);

	RobTD[playerid][33] = CreatePlayerTextDraw(playerid, 397.000, 247.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][33], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][33], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][33], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][33], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][33], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][33], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][33], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][33], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][33], 1);

	RobTD[playerid][34] = CreatePlayerTextDraw(playerid, 429.000, 247.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][34], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][34], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][34], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][34], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][34], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][34], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][34], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][34], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][34], 1);

	RobTD[playerid][35] = CreatePlayerTextDraw(playerid, 173.000, 284.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][35], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][35], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][35], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][35], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][35], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][35], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][35], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][35], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][35], 1);

	RobTD[playerid][36] = CreatePlayerTextDraw(playerid, 205.000, 284.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][36], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][36], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][36], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][36], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][36], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][36], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][36], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][36], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][36], 1);

	RobTD[playerid][37] = CreatePlayerTextDraw(playerid, 237.000, 284.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][37], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][37], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][37], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][37], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][37], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][37], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][37], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][37], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][37], 1);

	RobTD[playerid][38] = CreatePlayerTextDraw(playerid, 269.000, 284.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][38], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][38], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][38], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][38], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][38], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][38], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][38], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][38], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][38], 1);

	RobTD[playerid][39] = CreatePlayerTextDraw(playerid, 301.000, 284.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][39], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][39], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][39], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][39], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][39], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][39], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][39], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][39], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][39], 1);

	RobTD[playerid][40] = CreatePlayerTextDraw(playerid, 333.000, 284.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][40], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][40], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][40], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][40], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][40], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][40], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][40], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][40], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][40], 1);

	RobTD[playerid][41] = CreatePlayerTextDraw(playerid, 365.000, 284.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][41], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][41], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][41], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][41], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][41], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][41], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][41], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][41], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][41], 1);

	RobTD[playerid][42] = CreatePlayerTextDraw(playerid, 397.000, 284.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][42], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][42], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][42], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][42], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][42], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][42], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][42], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][42], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][42], 1);

	RobTD[playerid][43] = CreatePlayerTextDraw(playerid, 429.000, 284.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][43], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][43], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][43], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][43], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][43], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][43], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][43], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][43], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][43], 1);

	RobTD[playerid][44] = CreatePlayerTextDraw(playerid, 173.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, RobTD[playerid][44], 30.000, 35.000);
	PlayerTextDrawAlignment(playerid, RobTD[playerid][44], 1);
	PlayerTextDrawColor(playerid, RobTD[playerid][44], -1);
	PlayerTextDrawSetShadow(playerid, RobTD[playerid][44], 0);
	PlayerTextDrawSetOutline(playerid, RobTD[playerid][44], 0);
	PlayerTextDrawBackgroundColor(playerid, RobTD[playerid][44], 255);
	PlayerTextDrawFont(playerid, RobTD[playerid][44], 4);
	PlayerTextDrawSetProportional(playerid, RobTD[playerid][44], 1);
	PlayerTextDrawSetSelectable(playerid, RobTD[playerid][44], 1);
	return 1;
}

RobWarung_TextDrawReset(playerid)
{
	//Loop TextDraw
	for(new i = 0; i<MAX_REMEMBERS; i++)
	{
		RememberData[playerid][i][remindersMustClicked] = false;
		RememberData[playerid][i][remindersClicked] = false;
		PlayerTextDrawColor(playerid, RobTD[playerid][i], -1);
	}
	//Reset Player Data

	IsPlayerRobbing[playerid] = false;
	RobWave[playerid] = 0;
	RobValue[playerid] = 100.0;
	RobTimersDecrease[playerid] = 1.0;
	RobCount[playerid] = 0;
	KillTimer(RobTimers[playerid]);
	return 1;
}
RobWarung_RandomTextDraw(playerid)
{
	//SUBSCIBE KEIIZI
	new counts = 0, rand;
	//Loop textdraw
	for(new i = 0; i<MAX_REMEMBERS; i++)
	{
		//random textdraw yang harus di ingat
		rand = random(MAX_REMEMBERS);

		//Check jika textdraw sudah harus di ingat, maka random lagi
		if(RememberData[playerid][rand][remindersMustClicked]) rand = random(MAX_REMEMBERS);

		//Double Check
		if(RememberData[playerid][rand][remindersMustClicked]) rand = random(MAX_REMEMBERS);

		//Set agar TextDraw ini wajib di klik
		RememberData[playerid][rand][remindersMustClicked] = true;

		//Set Warna TextDraw
		PlayerTextDrawColor(playerid, RobTD[playerid][rand], SERVER_TEXTDRAW_COLOR);

		//Hitung Textdraw yang harus di ingat
		counts++;

		//Maksimal 5 textdraw yang harus di ingat
		if(counts == 5) break;
	}
	return 1;
}

RobWarung_ShowTextDraw(playerid)
{
	//Reset Dulu TextDrawnya
	RobWarung_TextDrawReset(playerid);

	//Random TextDraw Yang Harus Di Klik
	RobWarung_RandomTextDraw(playerid);

	//Player sekarang sedang rob
	IsPlayerRobbing[playerid] = true;

	//Player Wave
	RobWave[playerid] = 1;

	//Show All TextDraw
	for(new i = 0; i<3; i++) PlayerTextDrawShow(playerid, RememberTD[playerid][i]);
	for(new i = 0; i<MAX_REMEMBERS; i++) PlayerTextDrawShow(playerid, RobTD[playerid][i]);

	//Loop Timer
	RobTimers[playerid] = SetTimerEx("RobTimersEx", 20, true, "d", playerid);
	return 1;
}
RobWarung_StartMission(playerid)
{
	//Biar bisa klik textdraw (warna ubah sesuka kalian)
	SelectTextDraw(playerid, COLOR_GOLD);

	//Set ulang player data
	RobWave[playerid] = 2;
	RobValue[playerid] = 100.0;
	RobTimersDecrease[playerid] = 0.5;

	//Set Warna ke putih dan show kembali
	for(new i = 0; i<MAX_REMEMBERS; i++) PlayerTextDrawColor(playerid, RobTD[playerid][i], -1), PlayerTextDrawShow(playerid, RobTD[playerid][i]);
	return 1;
}
//SUBSCIBE KEIIZI
RobWarung_HideTextDraw(playerid)
{
	//Reset Lagi TextDrawnya 
	RobWarung_TextDrawReset(playerid);

	for(new i = 0; i<3; i++) PlayerTextDrawHide(playerid, RememberTD[playerid][i]);
	for(new i = 0; i<MAX_REMEMBERS; i++) PlayerTextDrawHide(playerid, RobTD[playerid][i]);

	CancelSelectTextDraw(playerid);
	return 1;
}
RobWarung_Succes(playerid)
{
	new rand = RandomEx(1000, 10000);
	IsPlayerRobbing[playerid] = false;
	RobWarung_HideTextDraw(playerid);
	GivePlayerMoneyEx(playerid, rand);
	CooldownRobWarung = gettime()+50;
	InfoMsg(playerid, "Merampok bisnis berhasil dan mendapatkan uang sebanyak banyaknya");
	return 1;
}
RobWarung_Failed(playerid)
{
	IsPlayerRobbing[playerid] = false;
	RobWarung_HideTextDraw(playerid);
	ErrorMsg(playerid, "Kamu gagal pada saat merampok");
	return 1; 
}
CMD:resetwarung(playerid, params[]) 
{
	CooldownRobWarung = 0;
	InfoMsg(playerid, "Cooldown telah di reset");
	return 1;
}

CMD:robatm(playerid, params[])
{
	if(pData[playerid][pLevel] < 7)
		return ErrorMsg(playerid, "Kamu harus level 7 untuk melakukan ini");

	if(pData[playerid][pRobbing] != 0)
		return ErrorMsg(playerid, "Kamu baru baru ini sudah melakukan perampokan, tunggu 1 hari untuk melakukannya kembali.");

	if(pData[playerid][pRobMember] < 2)
		return ErrorMsg(playerid, "Kamu harus menginvite 2 orang untuk melakukan ini");

	if(pData[playerid][pRobLeader] < 1)
		return ErrorMsg(playerid, "Hanya pemimpin rob yang bisa melakukan ini");

	if(pData[playerid][pFaction] != 0)
		return ErrorMsg(playerid, "Anggota faction tidak bisa melakukan ini");

	if(FactionMember_GetCount(1, true) < 2)
		return ErrorMsg(playerid, "SAPD yang anda di kota minimal 2");

	if(FactionMember_GetCount(3, true) < 1)
		return ErrorMsg(playerid, "SAMD yang anda di kota minimal 1");

	if(pData[playerid][pActivityTime] > 5)
		return ErrorMsg(playerid, "Kamu masih memiliki activity progress");

	new id = -1;
	id = GetClosestATM(playerid);

	if(id > -1)
	{
		if(AtmData[id][atmStatus] == 1)
			return ErrorMsg(playerid, "Atm rusak tidak bisa di rob");
		if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");	
		if(pData[playerid][pRobAtmProgres] == -1)
		{
			foreach(new i : Player)
			{
				if(pData[i][pFaction] == 1)
				{
					DisablePlayerRaceCheckpoint(i);
					SendFactionMessage(1, COLOR_RADIO, "[ATM INFO] there is an atm robbery in the area %s!", GetLocation(AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ]));
					SetPlayerRaceCheckpoint(i, 1, AtmData[id][atmX], AtmData[id][atmY], AtmData[id][atmZ], 0.0, 0.0, 0.0, 3.5);
					Info(i, "Lokasi perampokan ATM telah ditandai!");
				}
			}
		}
		TogglePlayerControllable(playerid, 0);
		if(gettime() > CooldownRobWarung)
		{
			RobWarung_ShowTextDraw(playerid);
		}
		else return InfoMsg(playerid, "You must wait coldown");
	}
	return 1;
}
KEIZI:RobTimersEx(playerid)
{
	if(IsPlayerRobbing[playerid])
	{
		switch(RobWave[playerid])
		{
			case 1:
			{
				RobValue[playerid] -= RobTimersDecrease[playerid];
				new Float:indicatorvalue = RobValue[playerid]*279/100;
				PlayerTextDrawTextSize(playerid, RememberTD[playerid][2], indicatorvalue, 32.000);
				PlayerTextDrawShow(playerid, RememberTD[playerid][2]);
				if(RobValue[playerid] <= 0) RobWarung_StartMission(playerid);
			}
			case 2:
			{
				RobValue[playerid] -= RobTimersDecrease[playerid];
				new Float:indicatorvalue = RobValue[playerid]*286/100;
				PlayerTextDrawTextSize(playerid, RememberTD[playerid][2], indicatorvalue, 32.000);
				PlayerTextDrawShow(playerid, RememberTD[playerid][2]);
				va_SendClientMessageToAll(0xFFFFFFAA, "Telah Terjadi perampokan warga harap siap siaga 1");
				if(RobValue[playerid] <= 0) RobWarung_Failed(playerid);
			}
		}
	}
	return 1;
}

CMD:robtest(playerid){
	if(gettime() > CooldownRobWarung)
	{
		RobWarung_ShowTextDraw(playerid);
	}
	else return InfoMsg(playerid, "You must wait coldown");
	return 1;
}