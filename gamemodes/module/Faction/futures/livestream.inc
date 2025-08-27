#include <YSI_Coding/y_hooks>

new WatchingStream[MAX_PLAYERS] = -1;
new Stream = -1;
new Streamer[MAX_PLAYERS] = 0;
new PlayerText: Stream_TD[MAX_PLAYERS][7];

CMD:startstream(playerid, params[])
{
	if(pData[playerid][pFaction] != 4) return Error(playerid, "You must be part of a news faction.");
	if (Streamer[playerid] == 0) return SendClientMessage(playerid, -1, "You are not a streamer.");
	if (Stream != -1) return SendClientMessage(playerid, -1, "There is already an active live stream.");
	Stream = playerid;
    GivePlayerCamera(playerid);
	return 1;
}

CMD:stopstream(playerid)
{
	if(pData[playerid][pFaction] != 4) return Error(playerid, "You must be part of a news faction.");
    Stream = -1;
    RemovePlayerCamera(playerid);
    foreach (new i:Player) if (WatchingStream[i] != 0)
    {
        SendClientMessage(i, -1, "The streamer ended the live stream and it was automatically switched off.");
        PlayerTextDrawHide(i, Stream_TD[i][0]);
        PlayerTextDrawHide(i, Stream_TD[i][1]);
 	    PlayerTextDrawHide(i, Stream_TD[i][2]);
        PlayerTextDrawHide(i, Stream_TD[i][3]);
   	    PlayerTextDrawHide(i, Stream_TD[i][4]);
   	    PlayerTextDrawHide(i, Stream_TD[i][5]);
   	    PlayerTextDrawHide(i, Stream_TD[i][6]);
        CancelSelectTextDraw(i);
  		WatchingStream[playerid] = 0;
    }
    return 1;
}

CMD:watchstream(playerid)
{
    if(Streamer[playerid] == -1) return SendClientMessage(playerid, -1, "There are no active live streams.");
	StartPlayerWatchingCamera(playerid, Streamer[playerid]);

    SelectTextDraw(playerid, -1);

    PlayerTextDrawShow(playerid, Stream_TD[playerid][0]);
    PlayerTextDrawShow(playerid, Stream_TD[playerid][1]);
    PlayerTextDrawShow(playerid, Stream_TD[playerid][2]);
	PlayerTextDrawShow(playerid, Stream_TD[playerid][3]);
	PlayerTextDrawShow(playerid, Stream_TD[playerid][4]);
	PlayerTextDrawShow(playerid, Stream_TD[playerid][5]);
	PlayerTextDrawShow(playerid, Stream_TD[playerid][6]);

    new str[256];

    format(str, sizeof(str), "%s", ReturnPlayerName(Streamer[playerid]));
    PlayerTextDrawSetString(playerid, Stream_TD[playerid][3], str);

	format(str, sizeof(str), "%s - %s", getdate(), gettime());
    PlayerTextDrawSetString(playerid, Stream_TD[playerid][5], str);
    WatchingStream[playerid] = 1;	
	return 1;
}

hook OnPlayerConnect(playerid)
{
    Stream_TD[playerid][0] = CreatePlayerTextDraw(playerid, 242.000, 347.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, Stream_TD[playerid][0], 141.000, 57.000);
	PlayerTextDrawAlignment(playerid, Stream_TD[playerid][0], 1);
	PlayerTextDrawColor(playerid, Stream_TD[playerid][0], -2139062017);
	PlayerTextDrawSetShadow(playerid, Stream_TD[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, Stream_TD[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, Stream_TD[playerid][0], 255);
	PlayerTextDrawFont(playerid, Stream_TD[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, Stream_TD[playerid][0], 1);

	Stream_TD[playerid][1] = CreatePlayerTextDraw(playerid, 279.000, 348.000, "LIVE STREAM");
	PlayerTextDrawLetterSize(playerid, Stream_TD[playerid][1], 0.310, 1.700);
	PlayerTextDrawAlignment(playerid, Stream_TD[playerid][1], 1);
	PlayerTextDrawColor(playerid, Stream_TD[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, Stream_TD[playerid][1], 1);
	PlayerTextDrawSetOutline(playerid, Stream_TD[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, Stream_TD[playerid][1], 150);
	PlayerTextDrawFont(playerid, Stream_TD[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, Stream_TD[playerid][1], 1);

	Stream_TD[playerid][2] = CreatePlayerTextDraw(playerid, 244.000, 367.000, "Streamer:");
	PlayerTextDrawLetterSize(playerid, Stream_TD[playerid][2], 0.200, 1.199);
	PlayerTextDrawAlignment(playerid, Stream_TD[playerid][2], 1);
	PlayerTextDrawColor(playerid, Stream_TD[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, Stream_TD[playerid][2], 1);
	PlayerTextDrawSetOutline(playerid, Stream_TD[playerid][2], 1);
	PlayerTextDrawBackgroundColor(playerid, Stream_TD[playerid][2], 150);
	PlayerTextDrawFont(playerid, Stream_TD[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, Stream_TD[playerid][2], 1);

	Stream_TD[playerid][3] = CreatePlayerTextDraw(playerid, 279.000, 368.000, "Deks_Michealson");
	PlayerTextDrawLetterSize(playerid, Stream_TD[playerid][3], 0.129, 1.099);
	PlayerTextDrawAlignment(playerid, Stream_TD[playerid][3], 1);
	PlayerTextDrawColor(playerid, Stream_TD[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, Stream_TD[playerid][3], 1);
	PlayerTextDrawSetOutline(playerid, Stream_TD[playerid][3], 1);
	PlayerTextDrawBackgroundColor(playerid, Stream_TD[playerid][3], 150);
	PlayerTextDrawFont(playerid, Stream_TD[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, Stream_TD[playerid][3], 1);

	Stream_TD[playerid][4] = CreatePlayerTextDraw(playerid, 244.000, 379.000, "Date:");
	PlayerTextDrawLetterSize(playerid, Stream_TD[playerid][4], 0.200, 1.199);
	PlayerTextDrawAlignment(playerid, Stream_TD[playerid][4], 1);
	PlayerTextDrawColor(playerid, Stream_TD[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, Stream_TD[playerid][4], 1);
	PlayerTextDrawSetOutline(playerid, Stream_TD[playerid][4], 1);
	PlayerTextDrawBackgroundColor(playerid, Stream_TD[playerid][4], 150);
	PlayerTextDrawFont(playerid, Stream_TD[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, Stream_TD[playerid][4], 1);

	Stream_TD[playerid][5] = CreatePlayerTextDraw(playerid, 267.000, 380.000, "10/10/2000 - 19:50");
	PlayerTextDrawLetterSize(playerid, Stream_TD[playerid][5], 0.129, 1.099);
	PlayerTextDrawAlignment(playerid, Stream_TD[playerid][5], 1);
	PlayerTextDrawColor(playerid, Stream_TD[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, Stream_TD[playerid][5], 1);
	PlayerTextDrawSetOutline(playerid, Stream_TD[playerid][5], 1);
	PlayerTextDrawBackgroundColor(playerid, Stream_TD[playerid][5], 150);
	PlayerTextDrawFont(playerid, Stream_TD[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, Stream_TD[playerid][5], 1);

	Stream_TD[playerid][6] = CreatePlayerTextDraw(playerid, 361.000, 382.000, "LD_BEAT:cross");
	PlayerTextDrawTextSize(playerid, Stream_TD[playerid][6], 18.000, 20.000);
	PlayerTextDrawAlignment(playerid, Stream_TD[playerid][6], 1);
	PlayerTextDrawColor(playerid, Stream_TD[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, Stream_TD[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, Stream_TD[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, Stream_TD[playerid][6], 255);
	PlayerTextDrawFont(playerid, Stream_TD[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, Stream_TD[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, Stream_TD[playerid][6], 1);
	return Y_HOOKS_CONTINUE_RETURN_1;
}