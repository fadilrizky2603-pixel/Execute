stock OpenInventory(playerid) {
    if (!IsPlayerConnected(playerid))
        return 0;

    new
    amounts[MAX_INVENTORY],
        str[512],
        string[256];

    format(str, sizeof(str), "Name\tAmount\n");
    forex(i, MAX_INVENTORY) {
        if (!InventoryData[playerid][i][invExists])
            format(str, sizeof(str), "%s{AFAFAF}Empty Slot\n", str);

        else {
            amounts[i] = InventoryData[playerid][i][invQuantity];
            strunpack(string, InventoryData[playerid][i][invItem]);
            format(str, sizeof(str), "%s{FFFFFF}%s\t%d\n", str, string, amounts[i]);
        }
    }
    ShowPlayerDialog(playerid, DIALOG_INVENTORY, DIALOG_STYLE_TABLIST_HEADERS, "Inventory Data", str, "Select", "Close");
    return 1;
}

stock Inventory_Clear(playerid)
{
	static
	    string[64];

	for(new i = 0; i < MAX_INVENTORY; i++)
	{
	    if (InventoryData[playerid][i][invExists])
	    {
	        InventoryData[playerid][i][invExists] = false;
	        InventoryData[playerid][i][invModel] = 0;
	        InventoryData[playerid][i][invQuantity] = 0;
	        InventoryData[playerid][i][invAmmo] = 0;
	        InventoryData[playerid][i][invSlot] = -1;
			pData[playerid][pWeight] = 0.00;
		}
	}
	format(string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d'", pData[playerid][pID]);
	return mysql_tquery(g_SQL, string);
}

stock CreatePlayerInventoryTD(playerid)
{
	PlayerPlaySound(playerid, 1039, 0,0,0);
	if(!GetSVarInt("Tem_Move")) SendClientMessageEx(playerid, COLOR_GREEN, "[Info] {FFFFFF}Gunakan {FFFF00}'/cursor' {FFFFFF}jika mouse hilang dari layar/textdraw tidak bisa ditekan!");

	txd_inventory[playerid][0] = CreatePlayerTextDraw(playerid, 178.000, 182.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][0], 1.000, 171.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][0], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][0], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][0], 1);

	txd_inventory[playerid][1] = CreatePlayerTextDraw(playerid, 185.000, 299.000, "HotBar");
	PlayerTextDrawLetterSize(playerid, txd_inventory[playerid][1], 0.209, 0.999);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][1], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][1], 150);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][1], 1);

	txd_inventory[playerid][2] = CreatePlayerTextDraw(playerid, 210.000, 305.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][2], 154.000, 1.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][2], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][2], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][2], 1);

	txd_inventory[playerid][3] = CreatePlayerTextDraw(playerid, 188.000, 160.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][3], 175.000, 6.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][3], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][3], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][3], 1);

	txd_inventory[playerid][4] = CreatePlayerTextDraw(playerid, 188.000, 160.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][4], 175.000, 6.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][4], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][4], SERVER_TEXTDRAW_COLOR);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][4], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][4], 1);

	txd_inventory[playerid][5] = CreatePlayerTextDraw(playerid, 188.000, 135.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][5], 1.000, 16.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][5], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][5], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][5], 1);

	txd_inventory[playerid][6] = CreatePlayerTextDraw(playerid, 195.000, 135.000, "XENO TADASI");
	PlayerTextDrawLetterSize(playerid, txd_inventory[playerid][6], 0.180, 0.898);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][6], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][6], 150);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][6], 1);

	txd_inventory[playerid][7] = CreatePlayerTextDraw(playerid, 195.000, 142.000, "0/100KG");
	PlayerTextDrawLetterSize(playerid, txd_inventory[playerid][7], 0.180, 0.898);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][7], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][7], 150);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][7], 1);

	txd_inventory[playerid][8] = CreatePlayerTextDraw(playerid, 171.000, 140.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][8], 13.000, 9.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][8], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][8], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][8], 1);

	txd_inventory[playerid][9] = CreatePlayerTextDraw(playerid, 173.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][9], 1.000, 9.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][9], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][9], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][9], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][9], 1);

	txd_inventory[playerid][10] = CreatePlayerTextDraw(playerid, 173.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][10], 8.000, 1.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][10], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][10], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][10], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][10], 1);

	txd_inventory[playerid][11] = CreatePlayerTextDraw(playerid, 181.000, 136.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][11], 1.000, 9.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][11], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][11], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][11], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][11], 1);

	txd_inventory[playerid][12] = CreatePlayerTextDraw(playerid, 386.000, 250.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][12], 146.000, 1.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][12], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][12], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][12], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][12], 1);

	txd_inventory[playerid][13] = CreatePlayerTextDraw(playerid, 385.000, 258.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][13], 37.000, 18.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][13], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][13], 150);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][13], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][13], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, txd_inventory[playerid][13], 1);

	txd_inventory[playerid][14] = CreatePlayerTextDraw(playerid, 425.000, 258.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][14], 37.000, 18.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][14], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][14], 150);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][14], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][14], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, txd_inventory[playerid][14], 1);

	txd_inventory[playerid][15] = CreatePlayerTextDraw(playerid, 465.000, 258.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][15], 37.000, 18.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][15], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][15], 150);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][15], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][15], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][15], 1);
	PlayerTextDrawSetSelectable(playerid, txd_inventory[playerid][15], 1);

	txd_inventory[playerid][16] = CreatePlayerTextDraw(playerid, 506.000, 258.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][16], 37.000, 18.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][16], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][16], 150);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][16], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][16], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][16], 1);
	PlayerTextDrawSetSelectable(playerid, txd_inventory[playerid][16], 1);

	txd_inventory[playerid][17] = CreatePlayerTextDraw(playerid, 449.000, 285.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, txd_inventory[playerid][17], 25.000, 29.000);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][17], 1);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][17], 150);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][17], 255);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][17], 4);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][17], 1);
	PlayerTextDrawSetSelectable(playerid, txd_inventory[playerid][17], 1);

	txd_inventory[playerid][18] = CreatePlayerTextDraw(playerid, 403.000, 263.000, "Amount");
	PlayerTextDrawLetterSize(playerid, txd_inventory[playerid][18], 0.180, 0.799);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][18], 2);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][18], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][18], 150);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][18], 1);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][18], 1);

	txd_inventory[playerid][19] = CreatePlayerTextDraw(playerid, 443.000, 263.000, "Use");
	PlayerTextDrawLetterSize(playerid, txd_inventory[playerid][19], 0.180, 0.799);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][19], 2);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][19], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][19], 150);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][19], 1);

	txd_inventory[playerid][20] = CreatePlayerTextDraw(playerid, 483.000, 263.000, "Give");
	PlayerTextDrawLetterSize(playerid, txd_inventory[playerid][20], 0.180, 0.799);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][20], 2);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][20], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][20], 150);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][20], 1);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][20], 1);

	txd_inventory[playerid][21] = CreatePlayerTextDraw(playerid, 525.000, 263.000, "Drop");
	PlayerTextDrawLetterSize(playerid, txd_inventory[playerid][21], 0.180, 0.799);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][21], 2);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][21], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][21], 150);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][21], 1);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][21], 1);

	txd_inventory[playerid][22] = CreatePlayerTextDraw(playerid, 462.000, 296.000, "X");
	PlayerTextDrawLetterSize(playerid, txd_inventory[playerid][22], 0.180, 0.799);
	PlayerTextDrawAlignment(playerid, txd_inventory[playerid][22], 2);
	PlayerTextDrawColor(playerid, txd_inventory[playerid][22], -1);
	PlayerTextDrawSetShadow(playerid, txd_inventory[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, txd_inventory[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, txd_inventory[playerid][22], 150);
	PlayerTextDrawFont(playerid, txd_inventory[playerid][22], 1);
	PlayerTextDrawSetProportional(playerid, txd_inventory[playerid][22], 1);

	indexinv[playerid][0] = CreatePlayerTextDraw(playerid, 184.000, 317.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][0], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][0], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][0], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][0], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][0], 1);

	indexinv[playerid][1] = CreatePlayerTextDraw(playerid, 221.000, 317.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][1], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][1], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][1], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][1], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][1], 1);

	indexinv[playerid][2] = CreatePlayerTextDraw(playerid, 258.000, 317.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][2], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][2], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][2], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][2], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][2], 1);

	indexinv[playerid][3] = CreatePlayerTextDraw(playerid, 295.000, 317.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][3], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][3], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][3], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][3], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][3], 1);

	indexinv[playerid][4] = CreatePlayerTextDraw(playerid, 332.000, 317.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][4], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][4], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][4], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][4], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][4], 1);

	indexinv[playerid][5] = CreatePlayerTextDraw(playerid, 184.000, 254.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][5], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][5], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][5], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][5], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][5], 1);

	indexinv[playerid][6] = CreatePlayerTextDraw(playerid, 221.000, 254.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][6], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][6], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][6], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][6], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][6], 1);

	indexinv[playerid][7] = CreatePlayerTextDraw(playerid, 258.000, 254.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][7], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][7], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][7], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][7], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][7], 1);

	indexinv[playerid][8] = CreatePlayerTextDraw(playerid, 295.000, 254.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][8], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][8], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][8], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][8], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][8], 1);

	indexinv[playerid][9] = CreatePlayerTextDraw(playerid, 332.000, 254.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][9], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][9], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][9], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][9], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][9], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][9], 1);

	indexinv[playerid][10] = CreatePlayerTextDraw(playerid, 184.000, 213.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][10], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][10], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][10], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][10], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][10], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][10], 1);

	indexinv[playerid][11] = CreatePlayerTextDraw(playerid, 221.000, 213.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][11], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][11], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][11], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][11], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][11], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][11], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][11], 1);

	indexinv[playerid][12] = CreatePlayerTextDraw(playerid, 258.000, 213.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][12], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][12], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][12], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][12], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][12], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][12], 1);

	indexinv[playerid][13] = CreatePlayerTextDraw(playerid, 295.000, 213.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][13], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][13], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][13], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][13], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][13], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][13], 1);

	indexinv[playerid][14] = CreatePlayerTextDraw(playerid, 332.000, 213.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][14], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][14], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][14], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][14], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][14], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][14], 1);

	indexinv[playerid][15] = CreatePlayerTextDraw(playerid, 184.000, 172.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][15], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][15], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][15], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][15], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][15], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][15], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][15], 1);

	indexinv[playerid][16] = CreatePlayerTextDraw(playerid, 221.000, 172.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][16], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][16], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][16], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][16], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][16], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][16], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][16], 1);

	indexinv[playerid][17] = CreatePlayerTextDraw(playerid, 258.000, 172.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][17], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][17], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][17], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][17], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][17], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][17], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][17], 1);

	indexinv[playerid][18] = CreatePlayerTextDraw(playerid, 295.000, 172.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][18], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][18], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][18], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][18], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][18], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][18], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][18], 1);

	indexinv[playerid][19] = CreatePlayerTextDraw(playerid, 332.000, 172.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][19], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][19], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][19], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][19], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][19], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][19], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][19], 1);

	indexinv[playerid][20] = CreatePlayerTextDraw(playerid, 386.000, 165.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][20], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][20], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][20], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][20], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][20], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][20], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][20], 1);

	indexinv[playerid][21] = CreatePlayerTextDraw(playerid, 423.000, 165.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][21], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][21], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][21], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][21], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][21], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][21], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][21], 1);

	indexinv[playerid][22] = CreatePlayerTextDraw(playerid, 460.000, 165.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][22], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][22], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][22], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][22], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][22], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][22], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][22], 1);

	indexinv[playerid][23] = CreatePlayerTextDraw(playerid, 497.000, 165.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][23], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][23], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][23], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][23], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][23], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][23], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][23], 1);

	indexinv[playerid][24] = CreatePlayerTextDraw(playerid, 386.000, 206.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][24], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][24], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][24], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][24], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][24], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][24], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][24], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][24], 1);

	indexinv[playerid][25] = CreatePlayerTextDraw(playerid, 423.000, 206.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][25], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][25], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][25], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][25], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][25], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][25], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][25], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][25], 1);

	indexinv[playerid][26] = CreatePlayerTextDraw(playerid, 460.000, 206.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][26], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][26], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][26], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][26], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][26], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][26], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][26], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][26], 1);

	indexinv[playerid][27] = CreatePlayerTextDraw(playerid, 497.000, 206.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, indexinv[playerid][27], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, indexinv[playerid][27], 1);
	PlayerTextDrawColor(playerid, indexinv[playerid][27], 150);
	PlayerTextDrawSetShadow(playerid, indexinv[playerid][27], 0);
	PlayerTextDrawSetOutline(playerid, indexinv[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, indexinv[playerid][27], 255);
	PlayerTextDrawFont(playerid, indexinv[playerid][27], 4);
	PlayerTextDrawSetProportional(playerid, indexinv[playerid][27], 1);
	PlayerTextDrawSetSelectable(playerid, indexinv[playerid][27], 1);

	modelinv[playerid][0] = CreatePlayerTextDraw(playerid, 184.000, 317.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][0], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][0], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][0], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][0], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][0], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][0], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][0], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][0], 0, 0);

	modelinv[playerid][1] = CreatePlayerTextDraw(playerid, 221.000, 317.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][1], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][1], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][1], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][1], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][1], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][1], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][1], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][1], 0, 0);

	modelinv[playerid][2] = CreatePlayerTextDraw(playerid, 258.000, 317.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][2], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][2], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][2], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][2], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][2], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][2], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][2], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][2], 0, 0);

	modelinv[playerid][3] = CreatePlayerTextDraw(playerid, 295.000, 317.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][3], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][3], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][3], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][3], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][3], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][3], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][3], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][3], 0, 0);

	modelinv[playerid][4] = CreatePlayerTextDraw(playerid, 332.000, 317.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][4], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][4], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][4], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][4], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][4], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][4], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][4], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][4], 0, 0);

	modelinv[playerid][5] = CreatePlayerTextDraw(playerid, 184.000, 254.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][5], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][5], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][5], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][5], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][5], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][5], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][5], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][5], 0, 0);

	modelinv[playerid][6] = CreatePlayerTextDraw(playerid, 221.000, 254.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][6], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][6], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][6], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][6], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][6], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][6], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][6], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][6], 0, 0);

	modelinv[playerid][7] = CreatePlayerTextDraw(playerid, 258.000, 254.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][7], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][7], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][7], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][7], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][7], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][7], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][7], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][7], 0, 0);

	modelinv[playerid][8] = CreatePlayerTextDraw(playerid, 295.000, 254.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][8], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][8], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][8], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][8], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][8], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][8], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][8], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][8], 0, 0);

	modelinv[playerid][9] = CreatePlayerTextDraw(playerid, 332.000, 254.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][9], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][9], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][9], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][9], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][9], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][9], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][9], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][9], 0, 0);

	modelinv[playerid][10] = CreatePlayerTextDraw(playerid, 184.000, 213.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][10], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][10], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][10], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][10], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][10], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][10], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][10], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][10], 0, 0);

	modelinv[playerid][11] = CreatePlayerTextDraw(playerid, 221.000, 213.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][11], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][11], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][11], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][11], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][11], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][11], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][11], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][11], 0, 0);

	modelinv[playerid][12] = CreatePlayerTextDraw(playerid, 258.000, 213.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][12], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][12], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][12], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][12], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][12], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][12], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][12], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][12], 0, 0);

	modelinv[playerid][13] = CreatePlayerTextDraw(playerid, 295.000, 213.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][13], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][13], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][13], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][13], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][13], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][13], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][13], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][13], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][13], 0, 0);

	modelinv[playerid][14] = CreatePlayerTextDraw(playerid, 332.000, 213.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][14], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][14], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][14], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][14], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][14], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][14], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][14], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][14], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][14], 0, 0);

	modelinv[playerid][15] = CreatePlayerTextDraw(playerid, 184.000, 172.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][15], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][15], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][15], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][15], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][15], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][15], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][15], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][15], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][15], 0, 0);

	modelinv[playerid][16] = CreatePlayerTextDraw(playerid, 221.000, 172.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][16], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][16], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][16], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][16], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][16], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][16], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][16], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][16], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][16], 0, 0);

	modelinv[playerid][17] = CreatePlayerTextDraw(playerid, 258.000, 172.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][17], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][17], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][17], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][17], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][17], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][17], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][17], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][17], 0, 0);

	modelinv[playerid][18] = CreatePlayerTextDraw(playerid, 295.000, 172.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][18], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][18], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][18], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][18], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][18], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][18], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][18], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][18], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][18], 0, 0);

	modelinv[playerid][19] = CreatePlayerTextDraw(playerid, 332.000, 172.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][19], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][19], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][19], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][19], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][19], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][19], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][19], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][19], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][19], 0, 0);

	modelinv[playerid][20] = CreatePlayerTextDraw(playerid, 386.000, 165.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][20], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][20], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][20], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][20], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][20], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][20], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][20], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][20], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][20], 0, 0);

	modelinv[playerid][21] = CreatePlayerTextDraw(playerid, 423.000, 165.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][21], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][21], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][21], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][21], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][21], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][21], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][21], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][21], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][21], 0, 0);

	modelinv[playerid][22] = CreatePlayerTextDraw(playerid, 460.000, 165.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][22], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][22], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][22], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][22], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][22], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][22], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][22], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][22], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][22], 0, 0);

	modelinv[playerid][23] = CreatePlayerTextDraw(playerid, 497.000, 165.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][23], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][23], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][23], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][23], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][23], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][23], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][23], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][23], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][23], 0, 0);

	modelinv[playerid][24] = CreatePlayerTextDraw(playerid, 386.000, 206.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][24], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][24], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][24], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][24], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][24], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][24], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][24], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][24], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][24], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][24], 0, 0);

	modelinv[playerid][25] = CreatePlayerTextDraw(playerid, 423.000, 206.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][25], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][25], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][25], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][25], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][25], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][25], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][25], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][25], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][25], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][25], 0, 0);

	modelinv[playerid][26] = CreatePlayerTextDraw(playerid, 460.000, 206.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][26], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][26], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][26], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][26], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][26], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][26], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][26], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][26], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][26], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][26], 0, 0);

	modelinv[playerid][27] = CreatePlayerTextDraw(playerid, 497.000, 206.000, "_");
	PlayerTextDrawTextSize(playerid, modelinv[playerid][27], 34.000, 37.000);
	PlayerTextDrawAlignment(playerid, modelinv[playerid][27], 1);
	PlayerTextDrawColor(playerid, modelinv[playerid][27], -1);
	PlayerTextDrawSetShadow(playerid, modelinv[playerid][27], 0);
	PlayerTextDrawSetOutline(playerid, modelinv[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, modelinv[playerid][27], 0);
	PlayerTextDrawFont(playerid, modelinv[playerid][27], 5);
	PlayerTextDrawSetProportional(playerid, modelinv[playerid][27], 0);
	PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][27], 2355);
	PlayerTextDrawSetPreviewRot(playerid, modelinv[playerid][27], 0.000, 0.000, 0.000, 1.000);
	PlayerTextDrawSetPreviewVehCol(playerid, modelinv[playerid][27], 0, 0);

	itemname[playerid][0] = CreatePlayerTextDraw(playerid, 201.000, 349.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][0], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][0], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][0], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][0], 1);

	itemname[playerid][1] = CreatePlayerTextDraw(playerid, 238.000, 349.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][1], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][1], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][1], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][1], 1);

	itemname[playerid][2] = CreatePlayerTextDraw(playerid, 275.000, 349.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][2], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][2], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][2], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][2], 1);

	itemname[playerid][3] = CreatePlayerTextDraw(playerid, 311.000, 349.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][3], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][3], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][3], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][3], 1);

	itemname[playerid][4] = CreatePlayerTextDraw(playerid, 348.000, 349.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][4], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][4], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][4], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][4], 1);

	itemname[playerid][5] = CreatePlayerTextDraw(playerid, 201.000, 286.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][5], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][5], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][5], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][5], 1);

	itemname[playerid][6] = CreatePlayerTextDraw(playerid, 238.000, 286.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][6], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][6], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][6], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][6], 1);

	itemname[playerid][7] = CreatePlayerTextDraw(playerid, 275.000, 286.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][7], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][7], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][7], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][7], 1);

	itemname[playerid][8] = CreatePlayerTextDraw(playerid, 311.000, 286.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][8], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][8], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][8], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][8], 1);

	itemname[playerid][9] = CreatePlayerTextDraw(playerid, 348.000, 286.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][9], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][9], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][9], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][9], 1);

	itemname[playerid][10] = CreatePlayerTextDraw(playerid, 201.000, 245.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][10], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][10], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][10], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][10], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][10], 1);

	itemname[playerid][11] = CreatePlayerTextDraw(playerid, 238.000, 245.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][11], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][11], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][11], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][11], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][11], 1);

	itemname[playerid][12] = CreatePlayerTextDraw(playerid, 275.000, 245.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][12], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][12], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][12], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][12], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][12], 1);

	itemname[playerid][13] = CreatePlayerTextDraw(playerid, 311.000, 245.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][13], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][13], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][13], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][13], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][13], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][13], 1);

	itemname[playerid][14] = CreatePlayerTextDraw(playerid, 348.000, 245.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][14], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][14], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][14], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][14], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][14], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][14], 1);

	itemname[playerid][15] = CreatePlayerTextDraw(playerid, 201.000, 204.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][15], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][15], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][15], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][15], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][15], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][15], 1);

	itemname[playerid][16] = CreatePlayerTextDraw(playerid, 238.000, 204.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][16], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][16], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][16], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][16], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][16], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][16], 1);

	itemname[playerid][17] = CreatePlayerTextDraw(playerid, 275.000, 204.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][17], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][17], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][17], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][17], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][17], 1);

	itemname[playerid][18] = CreatePlayerTextDraw(playerid, 311.000, 204.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][18], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][18], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][18], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][18], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][18], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][18], 1);

	itemname[playerid][19] = CreatePlayerTextDraw(playerid, 348.000, 204.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][19], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][19], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][19], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][19], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][19], 1);

	itemname[playerid][20] = CreatePlayerTextDraw(playerid, 404.000, 198.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][20], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][20], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][20], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][20], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][20], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][20], 1);

	itemname[playerid][21] = CreatePlayerTextDraw(playerid, 441.000, 198.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][21], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][21], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][21], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][21], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][21], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][21], 1);

	itemname[playerid][22] = CreatePlayerTextDraw(playerid, 478.000, 198.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][22], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][22], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][22], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][22], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][22], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][22], 1);

	itemname[playerid][23] = CreatePlayerTextDraw(playerid, 514.000, 198.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][23], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][23], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][23], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][23], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][23], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][23], 1);

	itemname[playerid][24] = CreatePlayerTextDraw(playerid, 404.000, 238.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][24], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][24], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][24], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][24], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][24], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][24], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][24], 1);

	itemname[playerid][25] = CreatePlayerTextDraw(playerid, 441.000, 238.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][25], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][25], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][25], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][25], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][25], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][25], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][25], 1);

	itemname[playerid][26] = CreatePlayerTextDraw(playerid, 478.000, 238.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][26], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][26], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][26], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][26], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][26], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][26], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][26], 1);

	itemname[playerid][27] = CreatePlayerTextDraw(playerid, 514.000, 238.000, "pizza");
	PlayerTextDrawLetterSize(playerid, itemname[playerid][27], 0.150, 0.699);
	PlayerTextDrawAlignment(playerid, itemname[playerid][27], 2);
	PlayerTextDrawColor(playerid, itemname[playerid][27], -1);
	PlayerTextDrawSetShadow(playerid, itemname[playerid][27], 0);
	PlayerTextDrawSetOutline(playerid, itemname[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, itemname[playerid][27], 150);
	PlayerTextDrawFont(playerid, itemname[playerid][27], 1);
	PlayerTextDrawSetProportional(playerid, itemname[playerid][27], 1);

	itemamountname[playerid][0] = CreatePlayerTextDraw(playerid, 185.000, 318.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][0], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][0], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][0], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][0], 1);

	itemamountname[playerid][1] = CreatePlayerTextDraw(playerid, 222.000, 318.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][1], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][1], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][1], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][1], 1);

	itemamountname[playerid][2] = CreatePlayerTextDraw(playerid, 259.000, 318.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][2], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][2], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][2], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][2], 1);

	itemamountname[playerid][3] = CreatePlayerTextDraw(playerid, 296.000, 318.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][3], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][3], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][3], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][3], 1);

	itemamountname[playerid][4] = CreatePlayerTextDraw(playerid, 333.000, 318.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][4], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][4], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][4], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][4], 1);

	itemamountname[playerid][5] = CreatePlayerTextDraw(playerid, 185.000, 255.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][5], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][5], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][5], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][5], 1);

	itemamountname[playerid][6] = CreatePlayerTextDraw(playerid, 222.000, 255.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][6], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][6], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][6], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][6], 1);

	itemamountname[playerid][7] = CreatePlayerTextDraw(playerid, 259.000, 255.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][7], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][7], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][7], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][7], 1);

	itemamountname[playerid][8] = CreatePlayerTextDraw(playerid, 296.000, 255.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][8], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][8], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][8], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][8], 1);

	itemamountname[playerid][9] = CreatePlayerTextDraw(playerid, 333.000, 255.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][9], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][9], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][9], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][9], 1);

	itemamountname[playerid][10] = CreatePlayerTextDraw(playerid, 185.000, 214.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][10], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][10], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][10], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][10], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][10], 1);

	itemamountname[playerid][11] = CreatePlayerTextDraw(playerid, 222.000, 214.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][11], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][11], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][11], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][11], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][11], 1);

	itemamountname[playerid][12] = CreatePlayerTextDraw(playerid, 259.000, 214.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][12], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][12], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][12], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][12], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][12], 1);

	itemamountname[playerid][13] = CreatePlayerTextDraw(playerid, 296.000, 214.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][13], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][13], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][13], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][13], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][13], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][13], 1);

	itemamountname[playerid][14] = CreatePlayerTextDraw(playerid, 333.000, 214.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][14], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][14], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][14], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][14], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][14], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][14], 1);

	itemamountname[playerid][15] = CreatePlayerTextDraw(playerid, 185.000, 174.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][15], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][15], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][15], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][15], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][15], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][15], 1);

	itemamountname[playerid][16] = CreatePlayerTextDraw(playerid, 222.000, 174.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][16], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][16], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][16], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][16], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][16], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][16], 1);

	itemamountname[playerid][17] = CreatePlayerTextDraw(playerid, 259.000, 174.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][17], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][17], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][17], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][17], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][17], 1);

	itemamountname[playerid][18] = CreatePlayerTextDraw(playerid, 296.000, 174.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][18], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][18], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][18], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][18], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][18], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][18], 1);

	itemamountname[playerid][19] = CreatePlayerTextDraw(playerid, 333.000, 174.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][19], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][19], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][19], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][19], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][19], 1);

	itemamountname[playerid][20] = CreatePlayerTextDraw(playerid, 387.000, 167.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][20], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][20], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][20], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][20], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][20], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][20], 1);

	itemamountname[playerid][21] = CreatePlayerTextDraw(playerid, 424.000, 167.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][21], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][21], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][21], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][21], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][21], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][21], 1);

	itemamountname[playerid][22] = CreatePlayerTextDraw(playerid, 461.000, 167.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][22], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][22], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][22], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][22], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][22], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][22], 1);

	itemamountname[playerid][23] = CreatePlayerTextDraw(playerid, 498.000, 167.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][23], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][23], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][23], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][23], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][23], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][23], 1);

	itemamountname[playerid][24] = CreatePlayerTextDraw(playerid, 387.000, 207.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][24], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][24], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][24], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][24], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][24], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][24], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][24], 1);

	itemamountname[playerid][25] = CreatePlayerTextDraw(playerid, 424.000, 207.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][25], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][25], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][25], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][25], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][25], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][25], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][25], 1);

	itemamountname[playerid][26] = CreatePlayerTextDraw(playerid, 461.000, 207.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][26], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][26], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][26], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][26], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][26], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][26], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][26], 1);

	itemamountname[playerid][27] = CreatePlayerTextDraw(playerid, 498.000, 207.000, "1");
	PlayerTextDrawLetterSize(playerid, itemamountname[playerid][27], 0.200, 0.699);
	PlayerTextDrawAlignment(playerid, itemamountname[playerid][27], 1);
	PlayerTextDrawColor(playerid, itemamountname[playerid][27], -1);
	PlayerTextDrawSetShadow(playerid, itemamountname[playerid][27], 0);
	PlayerTextDrawSetOutline(playerid, itemamountname[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, itemamountname[playerid][27], 150);
	PlayerTextDrawFont(playerid, itemamountname[playerid][27], 1);
	PlayerTextDrawSetProportional(playerid, itemamountname[playerid][27], 1);


	static
        str[1080];

	new invStr[300];

	HideLogo(playerid);
	HideHunger(playerid);
	
	AmmountInventory[playerid] = 1;
	BukaInven[playerid] = 1;
	InventoryOpen[playerid] = true;
	format(str, sizeof(str), "%.2f/1000.0", pData[playerid][pWeight]);
	PlayerTextDrawSetString(playerid, txd_inventory[playerid][7], str);
    for(new inv = 0; inv < MAX_INVENTORY; inv++)
	{
		if (!InventoryData[playerid][inv][invExists])
		{
			PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][inv], 11477);
			PlayerTextDrawSetString(playerid, itemname[playerid][inv], "_");
			PlayerTextDrawSetString(playerid, itemamountname[playerid][inv], "_");
			PlayerTextDrawSetString(playerid, indexinv[playerid][inv], "LD_BUM:blkdot");
		}
		else
		{
			format(invStr, 300, "%dx", InventoryData[playerid][inv][invQuantity]);				
			PlayerTextDrawSetPreviewModel(playerid, modelinv[playerid][inv], InventoryData[playerid][inv][invModel]);
			PlayerTextDrawSetString(playerid, itemname[playerid][inv], InventoryData[playerid][inv][invItem]);
			PlayerTextDrawSetString(playerid, indexinv[playerid][inv], "LD_BUM:blkdot");

			PlayerTextDrawSetString(playerid, itemamountname[playerid][inv], invStr);
		}
	}
	PlayerTextDrawSetString(playerid, txd_inventory[playerid][6], sprintf("%s", ReturnName(playerid)));
	for(new a = 0; a < 23; a++)
	{
		PlayerTextDrawShow(playerid, txd_inventory[playerid][a]);
	}
	forex(i, MAX_INVENTORY)//
	{
		PlayerTextDrawShow(playerid, indexinv[playerid][i]);
		PlayerTextDrawShow(playerid, itemname[playerid][i]);
		PlayerTextDrawShow(playerid, modelinv[playerid][i]);
		PlayerTextDrawShow(playerid, itemamountname[playerid][i]);
	}
	SelectTextDraw(playerid, COLOR_RED);
    return 1;
}

stock MenuStore_SelectRow(playerid, row)
{
	SelectInventory[playerid] = row;
    PlayerTextDrawHide(playerid,indexinv[playerid][row]);
	PlayerTextDrawColor(playerid, indexinv[playerid][row], -2686831);
	PlayerTextDrawShow(playerid,indexinv[playerid][row]);
}

stock MenuStore_UnselectRow(playerid)
{
	if(SelectInventory[playerid] != -1)
	{
		new row = SelectInventory[playerid];
		PlayerTextDrawHide(playerid,indexinv[playerid][row]);
		PlayerTextDrawColor(playerid, indexinv[playerid][row], 150);
		PlayerTextDrawShow(playerid,indexinv[playerid][row]);
	}
	SelectInventory[playerid] = -1;
}