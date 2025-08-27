#include <YSI_Coding\y_hooks>
#define Note:: note_

enum Note::GlobalStuff {
	ID,
    From[50],
    Text[100],
    Float:Note::Pos[3],
    bool:Exists,
    Int,
   	World,
   	Object,
    TimeNote,
    STREAMER_TAG_3D_TEXT_LABEL:TextLabel
};

enum Note::PlayerStuff {
    bool:Created,
    Text[100],
    Exists,
    PlayerText:Note::p_td[18],
    bool:ReadMode
}

new NoteData[MAX_NOTES][Note::GlobalStuff];
new CharacterNote[MAX_PLAYERS][Note::PlayerStuff];

hook OnPlayerConnect(playerid) {
    CharacterNote[playerid][Note::p_td][0] = CreatePlayerTextDraw(playerid, 378.000, 150.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][0], 218.000, 191.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][0], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][0], -1);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][0], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][0], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][0], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][0], 1);

    CharacterNote[playerid][Note::p_td][1] = CreatePlayerTextDraw(playerid, 378.000, 152.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][1], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][1], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][1], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][1], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][1], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][1], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][1], 1);

    CharacterNote[playerid][Note::p_td][2] = CreatePlayerTextDraw(playerid, 378.000, 170.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][2], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][2], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][2], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][2], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][2], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][2], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][2], 1);

    CharacterNote[playerid][Note::p_td][3] = CreatePlayerTextDraw(playerid, 378.000, 188.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][3], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][3], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][3], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][3], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][3], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][3], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][3], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][3], 1);

    CharacterNote[playerid][Note::p_td][4] = CreatePlayerTextDraw(playerid, 378.000, 204.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][4], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][4], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][4], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][4], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][4], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][4], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][4], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][4], 1);

    CharacterNote[playerid][Note::p_td][5] = CreatePlayerTextDraw(playerid, 378.000, 222.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][5], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][5], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][5], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][5], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][5], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][5], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][5], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][5], 1);

    CharacterNote[playerid][Note::p_td][6] = CreatePlayerTextDraw(playerid, 378.000, 240.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][6], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][6], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][6], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][6], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][6], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][6], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][6], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][6], 1);

    CharacterNote[playerid][Note::p_td][7] = CreatePlayerTextDraw(playerid, 378.000, 259.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][7], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][7], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][7], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][7], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][7], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][7], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][7], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][7], 1);

    CharacterNote[playerid][Note::p_td][8] = CreatePlayerTextDraw(playerid, 378.000, 277.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][8], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][8], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][8], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][8], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][8], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][8], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][8], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][8], 1);

    CharacterNote[playerid][Note::p_td][9] = CreatePlayerTextDraw(playerid, 378.000, 295.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][9], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][9], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][9], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][9], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][9], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][9], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][9], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][9], 1);

    CharacterNote[playerid][Note::p_td][10] = CreatePlayerTextDraw(playerid, 378.000, 313.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][10], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][10], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][10], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][10], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][10], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][10], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][10], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][10], 1);

    CharacterNote[playerid][Note::p_td][11] = CreatePlayerTextDraw(playerid, 378.000, 329.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][11], 218.000, 1.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][11], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][11], 1768516095);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][11], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][11], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][11], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][11], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][11], 1);

    CharacterNote[playerid][Note::p_td][12] = CreatePlayerTextDraw(playerid, 390.000, 341.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][12], 1.000, -191.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][12], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][12], -190002177);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][12], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][12], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][12], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][12], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][12], 1);

    CharacterNote[playerid][Note::p_td][13] = CreatePlayerTextDraw(playerid, 391.549, 341.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][13], 1.000, -191.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][13], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][13], -190002177);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][13], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][13], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][13], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][13], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][13], 1);

    CharacterNote[playerid][Note::p_td][14] = CreatePlayerTextDraw(playerid, 398.000, 319.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][14], 31.000, 16.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][14], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][14], -8433409);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][14], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][14], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][14], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][14], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][14], 1);
    PlayerTextDrawSetSelectable(playerid, CharacterNote[playerid][Note::p_td][14], 1);

    CharacterNote[playerid][Note::p_td][15] = CreatePlayerTextDraw(playerid, 405.000, 321.000, "Drop");
    PlayerTextDrawLetterSize(playerid, CharacterNote[playerid][Note::p_td][15], 0.200, 1.299);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][15], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][15], -1);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][15], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][15], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][15], 150);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][15], 1);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][15], 1);

    CharacterNote[playerid][Note::p_td][16] = CreatePlayerTextDraw(playerid, 400.000, 157.000, "Notes");
    PlayerTextDrawLetterSize(playerid, CharacterNote[playerid][Note::p_td][16], 0.160, 1.099);
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][16], 593.000, 0.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][16], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][16], -1448498689);
    PlayerTextDrawUseBox(playerid, CharacterNote[playerid][Note::p_td][16], 1);
    PlayerTextDrawBoxColor(playerid, CharacterNote[playerid][Note::p_td][16], 0);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][16], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][16], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][16], 150);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][16], 1);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][16], 1);

    CharacterNote[playerid][Note::p_td][17] = CreatePlayerTextDraw(playerid, 393.549, 155.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, CharacterNote[playerid][Note::p_td][17], 198.000, 14.000);
    PlayerTextDrawAlignment(playerid, CharacterNote[playerid][Note::p_td][17], 1);
    PlayerTextDrawColor(playerid, CharacterNote[playerid][Note::p_td][17], -1);
    PlayerTextDrawSetShadow(playerid, CharacterNote[playerid][Note::p_td][17], 0);
    PlayerTextDrawSetOutline(playerid, CharacterNote[playerid][Note::p_td][17], 0);
    PlayerTextDrawBackgroundColor(playerid, CharacterNote[playerid][Note::p_td][17], 255);
    PlayerTextDrawFont(playerid, CharacterNote[playerid][Note::p_td][17], 4);
    PlayerTextDrawSetProportional(playerid, CharacterNote[playerid][Note::p_td][17], 1);
    PlayerTextDrawSetSelectable(playerid, CharacterNote[playerid][Note::p_td][17], 1);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

ShowPlayerNote(playerid, bool:type) {
    if(type) {
        forex(i, 18) {
            PlayerTextDrawShow(playerid, CharacterNote[playerid][Note::p_td][i]);
        }
        CharacterNote[playerid][Exists] = true;
        SelectTextDraw(playerid, COLOR_RED);
    } else {
        forex(i, 18) {
            PlayerTextDrawHide(playerid, CharacterNote[playerid][Note::p_td][i]);
        }
        PlayerTextDrawSetString(playerid, CharacterNote[playerid][Note::p_td][15], "Drop");
        PlayerTextDrawSetString(playerid, CharacterNote[playerid][Note::p_td][16], "Notes");
        PlayerTextDrawSetSelectable(playerid, CharacterNote[playerid][Note::p_td][17], 1);
        CharacterNote[playerid][Exists] = false;
        CancelSelectTextDraw(playerid);
    }
    return 1;
}

PlayerTakeNote(playerid, noteid)
{
    new noteText[100];
    strcpy(noteText, NoteData[noteid][Text]);

    // Add the note to the player's inventory
    Inventory_Add(playerid, "Note", 2684, 1);

    // Destroy the note from the world
    PlayerNoteDestroy(noteid);
    return 1;
}

CMD:notes(playerid, const params[]) {
    if(CharacterNote[playerid][Exists]) {
        ShowPlayerNote(playerid, false);
    } else {
        ShowPlayerNote(playerid, true);
    }
    return 1;
}

CMD:deleteallnotes(playerid, params[]) {
    for (new i = 0; i != MAX_NOTES; i ++) {
		if(NoteData[i][Exists]) {
			if(NoteData[i][TimeNote] <= gettime())
			{
				PlayerNoteDestroy(i);
			}
		}	
	}
}

Dialog:DialogNoteCreate(playerid, response, listitem, inputtext[]) {
    if(response) {
        new inputLength = strlen(inputtext);
        if(inputLength >= 1 && inputLength <= 100) {
            CharacterNote[playerid][Created] = true;
            strcpy(CharacterNote[playerid][Text], inputtext);
            // Success(playerid, "Your note has been created successfully.");
            PlayerTextDrawSetString(playerid, CharacterNote[playerid][Note::p_td][16], inputtext);
        } else {
            InfoMsg(playerid, "Note text must be between 1 and 100 characters.");
        }
    }
    return 1;
}

/*Function:Notes_Load()
{
	new rows = cache_num_rows();
 	if(rows) {
        for (new i = 0; i < rows; i ++) {
		    cache_get_value_name_int(i, "ID", NoteData[i][ID]);

			cache_get_value_name(i, "from", NoteData[i][From]);
			cache_get_value_name(i, "text", NoteData[i][Text]);

			cache_get_value_name_float(i, "x", NoteData[i][Note::Pos][0]);
			cache_get_value_name_float(i, "y", NoteData[i][Note::Pos][1]);
			cache_get_value_name_float(i, "z", NoteData[i][Note::Pos][2]);
			cache_get_value_name_int(i, "int", NoteData[i][Int]);
			cache_get_value_name_int(i, "world", NoteData[i][World]);
            NoteData[i][TimeNote] = (gettime() + 300);
            NoteData[i][Exists] = true;
			NoteData[i][TextLabel] = CreateDynamic3DTextLabel(""GREEN"Y{FFFFFF} to take, "RED"F {FFFFFF}to destroy", -1, NoteData[i][Note::Pos][0], NoteData[i][Note::Pos][1], NoteData[i][Note::Pos][2] - 0.9, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, NoteData[i][World], NoteData[i][Int]);
		}
        printf("[Dynamic Notes]: Jumblah total Notes yang dimuat %d.", rows);
	}
    return 1;
}*/

/*Function:Notes_Load() {
	new rows = cache_num_rows();
 	if(rows) {
    	forex(i, rows) {
		    cache_get_value_name_int(i, "ID", NoteData[i][ID]);

			cache_get_value_name(i, "from", NoteData[i][From]);
			cache_get_value_name(i, "text", NoteData[i][Text]);

			cache_get_value_name_float(i, "x", NoteData[i][Note::Pos][0]);
			cache_get_value_name_float(i, "y", NoteData[i][Note::Pos][1]);
			cache_get_value_name_float(i, "z", NoteData[i][Note::Pos][2]);
			cache_get_value_name_int(i, "int", NoteData[i][Int]);
			cache_get_value_name_int(i, "world", NoteData[i][World]);
            NoteData[i][TimeNote] = (gettime() + 300);
            NoteData[i][Exists] = true;
			NoteData[i][TextLabel] = CreateDynamic3DTextLabel(""GREEN"Y{FFFFFF} to take, "RED"F {FFFFFF}to destroy", -1, NoteData[i][Note::Pos][0], NoteData[i][Note::Pos][1], NoteData[i][Note::Pos][2] - 0.9, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, NoteData[i][World], NoteData[i][Int]);
		}
        printf("===========================");
	    printf("Dynamic Notes Loaded : %d", rows);
	    printf("===========================");
	    printf(" ");
	}
    return 1;
}*/

forward Notes_Load();
public Notes_Load() 
{
	new rows = cache_num_rows();
	if(rows)
	{
        for(new i = 0; i < rows; ++i) if(i < MAX_NOTES)
        {
            NoteData[i][Exists] = true;

            cache_get_value_name_int(i, "ID", NoteData[i][ID]);

            cache_get_value_name(i, "from", NoteData[i][From]);
            cache_get_value_name(i, "text", NoteData[i][Text]);

            cache_get_value_name_float(i, "x", NoteData[i][Note::Pos][0]);
            cache_get_value_name_float(i, "y", NoteData[i][Note::Pos][1]);
            cache_get_value_name_float(i, "z", NoteData[i][Note::Pos][2]);
            cache_get_value_name_int(i, "int", NoteData[i][Int]);
            cache_get_value_name_int(i, "world", NoteData[i][World]);
            NoteData[i][TimeNote] = (gettime() + 300);
            NoteData[i][Exists] = true;
            NoteData[i][TextLabel] = CreateDynamic3DTextLabel(""GOLD_E"Y{FFFFFF} to take, "RED_E"F {FFFFFF}to destroy", -1, NoteData[i][Note::Pos][0], NoteData[i][Note::Pos][1], NoteData[i][Note::Pos][2] - 0.9, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, NoteData[i][World], NoteData[i][Int]);
        }
    }
    printf("[Dynamic Notes]: Jumblah total Notes yang dimuat %d.", rows);
    return 1;
}

PlayerDropNote(const from[], const note[], Float: x, Float: y, Float:z, interior, world) {
	new
	    query[300];

	forex(i, MAX_NOTES) if (!NoteData[i][Int])
	{
	    format(NoteData[i][From], 50, from);
	    format(NoteData[i][Text], 100, note);

		NoteData[i][Note::Pos][0] = x;
		NoteData[i][Note::Pos][1] = y;
		NoteData[i][Note::Pos][2] = z;

		NoteData[i][Int] = interior;
		NoteData[i][World] = world;
        NoteData[i][TimeNote] = (gettime() + 300);

 		NoteData[i][TextLabel] = CreateDynamic3DTextLabel(""GOLD_E"Y{FFFFFF} to take, "GOLD_E"F {FFFFFF}to destroy", -1, x, y, z - 0.9, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, world, interior);
        NoteData[i][Exists] = true;

 		format(query, sizeof(query), "INSERT INTO `notes` (`from`, `text`, `x`, `y`, `z`, `int`, `world`) VALUES('%s', '%s', '%.4f', '%.4f', '%.4f', '%d', '%d')", from, note, x, y, z, interior, world);
		mysql_tquery(g_SQL, query, "OnCreatedNotes", "d", i);
		return i;
	}
	return -1;
}

PlayerNoteDestroy(id) {
    new query[450];
    if (id != -1 && NoteData[id][Exists]) {
	    NoteData[id][Note::Pos][0] = 0.0;
	    NoteData[id][Note::Pos][1] = 0.0;
	    NoteData[id][Note::Pos][2] = 0.0;
	    NoteData[id][Int] = 0;
	    NoteData[id][World] = 0;

		if(IsValidDynamic3DTextLabel(NoteData[id][TextLabel])) DestroyDynamic3DTextLabel(NoteData[id][TextLabel]);
		NoteData[id][TextLabel] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_STREAMER_ID;

	    mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `notes` WHERE `ID` = '%d'", NoteData[id][ID]);
	    mysql_tquery(g_SQL, query);
    }
	return 1;
}

function OnCreatedNotes(id)
{
	if (id == -1 || !NoteData[id][Int])
	    return 0;

	NoteData[id][ID] = cache_insert_id();
	return 1;
}

NoteNearest(playerid)
{
    for (new i = 0; i != MAX_NOTES; i ++) if (IsPlayerInRangeOfPoint(playerid, 1.5, NoteData[i][Note::Pos][0], NoteData[i][Note::Pos][1], NoteData[i][Note::Pos][2]))
	{
	    if (GetPlayerInterior(playerid) == NoteData[i][Int] && GetPlayerVirtualWorld(playerid) == NoteData[i][World])
	        return i;
	}
	return -1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        new id = NoteNearest(playerid);
        if(id != -1) {
            if(pData[playerid][pName] == NoteData[id][From]) {
                PlayerNoteDestroy(id);
            } else if(pData[playerid][pAdmin] < 5) {
                PlayerNoteDestroy(id);
            }
        }
    }
    if (newkeys & KEY_YES) {
        new id = NoteNearest(playerid);
        if (id != -1)
        {
            PlayerTakeNote(playerid, id);
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}