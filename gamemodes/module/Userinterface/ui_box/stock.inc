stock ShowItemBox(playerid, const string[], const total[], model, time)
{
    if (MaxPlayerItemBox[playerid] == 5) return 1;

    MaxPlayerItemBox[playerid]++;
    new validtime = time * 1000;

    // Loop untuk menghancurkan TextDraw yang lama
    for (new x = 0; x < IndexItemBox[playerid]; x++)
    {
        for (new i = 0; i < 10; i++)
        {
            new PlayerText:textDrawId = TextDrawItemBox[playerid][(x * 10) + i];
            
            if (textDrawId != PlayerText:INVALID_TEXT_DRAW)
            {
				if(IsValidDynamicPlayerTextDraw(playerid, textDrawId))
				{
					PlayerTextDrawDestroy(playerid, textDrawId);
					TextDrawItemBox[playerid][(x * 10) + i] = PlayerText:INVALID_TEXT_DRAW; // Reset setelah dihancurkan
            	}
			}
        }
        // Penyalinan data (jika perlu)
        InfoItemBox[playerid][IndexItemBox[playerid] - x] = InfoItemBox[playerid][(IndexItemBox[playerid] - x) - 1];
    }

    // Mainkan suara
    PlayerPlaySound(playerid, 1150, 0.0, 0.0, 0.0);

    // Format pesan dan jumlah
    format(InfoItemBox[playerid][0][ItemBoxMessage], 320, "%s", string);
    format(InfoItemBox[playerid][0][ItemBoxJumlahMessage], 200, "%s", total);
    InfoItemBox[playerid][0][ItemBoxIcon] = model;

    // Tambah indeks item box
    ++IndexItemBox[playerid];

    // Membuat TextDraw baru
    new Float:new_x = 0.0;
    for (new x = 0; x < IndexItemBox[playerid]; x++)
    {
        CreateItemBox(playerid, x, x * 10, new_x);
        new_x += (InfoItemBox[playerid][x][ItemBoxSize] * 7.25) + 40.0; // 55
    }

    // Atur timer untuk menyembunyikan item box
    SetTimerEx("HideItemBox", validtime, false, "d", playerid);

    return 1;
}


stock CreateItemBox(const playerid, index, i, const Float:new_x)
{

	new lines = InfoItemBox[playerid][index][ItemBoxSize];
	new Float:x = (lines * 10) + new_x;
	new Float:posisibaru = x-14.0;

	TextDrawItemBox[playerid][i] = CreatePlayerTextDraw(playerid, 1000.000000+posisibaru, 108.500000, "");
	PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 1);
	PlayerTextDrawLetterSize(playerid, TextDrawItemBox[playerid][i], 0.425000, 1.400000);
	PlayerTextDrawTextSize(playerid, TextDrawItemBox[playerid][i], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 1);
	PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], -1);
	PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 255);
	PlayerTextDrawBoxColor(playerid, TextDrawItemBox[playerid][i], 50);
	PlayerTextDrawUseBox(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 1);
	PlayerTextDrawSetSelectable(playerid, TextDrawItemBox[playerid][i], 0);

	if(IsValidDynamicPlayerTextDraw(playerid, TextDrawItemBox[playerid][i])) {
		PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);
	}

	TextDrawItemBox[playerid][++i] = CreatePlayerTextDraw(playerid, 367.000+posisibaru, 312.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, TextDrawItemBox[playerid][i], 37.000, 47.000);
	PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 1);
	PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], 370417079);
	PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 255);
	PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 4);
	PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 1);
	PlayerTextDrawSetSelectable(playerid, TextDrawItemBox[playerid][i], 0);

	if(IsValidDynamicPlayerTextDraw(playerid, TextDrawItemBox[playerid][i])) {
		PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);
	}

	TextDrawItemBox[playerid][++i] = CreatePlayerTextDraw(playerid, 367.000+posisibaru, 357.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, TextDrawItemBox[playerid][i], 37.000, 2.000);
	PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 1);
	PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 255);
	PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 4);
	PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 1);

	if(IsValidDynamicPlayerTextDraw(playerid, TextDrawItemBox[playerid][i])) {
		PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);
	}

	TextDrawItemBox[playerid][++i] = CreatePlayerTextDraw(playerid, 368.000+posisibaru, 315.000, "_");
	PlayerTextDrawTextSize(playerid, TextDrawItemBox[playerid][i], 32.000, 40.000);
	PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 1);
	PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], -1);
	PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 5);
	PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawSetPreviewModel(playerid, TextDrawItemBox[playerid][i], InfoItemBox[playerid][index][ItemBoxIcon]);
	PlayerTextDrawSetPreviewRot(playerid, TextDrawItemBox[playerid][i], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, TextDrawItemBox[playerid][i], 0, 0);

	if(IsValidDynamicPlayerTextDraw(playerid, TextDrawItemBox[playerid][i])) {
		PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);
	}

	TextDrawItemBox[playerid][++i] = CreatePlayerTextDraw(playerid, 369.000+posisibaru, 313.000, InfoItemBox[playerid][index][ItemBoxJumlahMessage]);
	PlayerTextDrawLetterSize(playerid, TextDrawItemBox[playerid][i], 0.119, 0.898);
	PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 1);
	PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], -1);
	PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 150);
	PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 1);
	PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 1);

	if(IsValidDynamicPlayerTextDraw(playerid, TextDrawItemBox[playerid][i])) {
		PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);
	}

	TextDrawItemBox[playerid][++i] = CreatePlayerTextDraw(playerid, 386.000+posisibaru, 347.000, InfoItemBox[playerid][index][ItemBoxMessage]);
	PlayerTextDrawLetterSize(playerid, TextDrawItemBox[playerid][i], 0.119, 0.898);
	PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 2);
	PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], -1);
	PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
	PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 150);
	PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 1);
	PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 1);

	if(IsValidDynamicPlayerTextDraw(playerid, TextDrawItemBox[playerid][i])) {
		PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);
	}
	return 1;
}
