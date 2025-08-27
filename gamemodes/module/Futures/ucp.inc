

enum E_UCP
{
	//Ucp Character
	ucpCharacter[128],
	ucpLastLogin[126],
	ucpLevel
};

new UcpData[MAX_PLAYERS][MAX_UCP][E_UCP];

MySQL_LoadUcpCharacter(playerid)
{
	new query[524];
	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM players WHERE ucp_name = '%s' LIMIT 3", pData[playerid][pName]);
	mysql_tquery(g_SQL, query, "LoadUcpCharacter", "d", playerid);
	return 1;
}

/*function LoadUcpCharacter(playerid)
{

	new rows = cache_num_rows(), charname[128], lastlog[128];

	for(new i = 0; i < 40; i++)
	{
		PlayerTextDrawShow(playerid, CharSelect[playerid][i]);
	}
	SetPlayerSkin(playerid, 4);
	SetPlayerPos(playerid, 1094.925415, -2237.837158, 49.359375);
	SelectTextDraw(playerid, SERVER_TEXTDRAW_COLOR);
	//SpawnPlayer(playerid);
	//SetPlayerVirtualWorld(playerid, (playerid + 1000));
	TogglePlayerControllable(playerid, true);
	ApplyAnimation(playerid, "PED", "SEAT_idle", 4.1, 1, 0, 0, 0, 0);
	InterpolateCameraPos(playerid, 1100.701049, -2237.768554, 50.827800, 1100.701049, -2237.768554, 50.827800, 3000, 1);
	InterpolateCameraLookAt(playerid, 1099.716674, -2237.805175, 50.655693, 1096.729614, -2237.927490, 50.377506, 3000, 1);
	if(rows)
	{
		for(new i = 0; i < rows; i++)
		{
			cache_get_value_name(i, "username", charname);
			format(UcpData[playerid][i][ucpCharacter], 126, charname);
			cache_get_value_name(i, "last_login", lastlog);
			format(UcpData[playerid][i][ucpLastLogin], 126, lastlog);
			cache_get_value_name_int(i, "level" , UcpData[playerid][i][ucpLevel]);

			if(UcpData[playerid][0][ucpCharacter])
			{
				PlayerTextDrawSetString(playerid, CharSelect[playerid][12], UcpData[playerid][0][ucpCharacter]);
				PlayerTextDrawSetString(playerid, CharSelect[playerid][13], UcpData[playerid][0][ucpLastLogin]);
			}
			else
			{
				PlayerTextDrawSetString(playerid, CharSelect[playerid][12], "Create Character");
				PlayerTextDrawSetString(playerid, CharSelect[playerid][13], "No Date Create Yet");
			}
			if(UcpData[playerid][1][ucpCharacter])
			{
				PlayerTextDrawSetString(playerid, CharSelect[playerid][25], UcpData[playerid][1][ucpCharacter]);
				PlayerTextDrawSetString(playerid, CharSelect[playerid][26], UcpData[playerid][1][ucpLastLogin]);
			}
			else
			{
				PlayerTextDrawSetString(playerid, CharSelect[playerid][25], "Create Character");
				PlayerTextDrawSetString(playerid, CharSelect[playerid][26], "No Date Create Yet");
			}
			if(UcpData[playerid][2][ucpCharacter])
			{
				PlayerTextDrawSetString(playerid, CharSelect[playerid][38], UcpData[playerid][2][ucpCharacter]);
				PlayerTextDrawSetString(playerid, CharSelect[playerid][39], UcpData[playerid][2][ucpLastLogin]);
			}
			else
			{
				PlayerTextDrawSetString(playerid, CharSelect[playerid][38], "Create Character");
				PlayerTextDrawSetString(playerid, CharSelect[playerid][39], "No Date Create Yet");
			}
		}
	}
	else
	{
		for(new i = 0; i < 40; i++)
		{
			PlayerTextDrawHide(playerid, CharSelect[playerid][i]);
		}
		ShowCreateChar(playerid);
	}
	return 1;
}*/

function LoadUcpCharacter(playerid)
{

	new rows = cache_num_rows(), charname[128], lastlog[128], str[524], count = 0;

	format(str, sizeof(str), "Character Name\tLevel\tLast Login\n");
	for(new slot = 0; slot < MAX_UCP; slot++)
	{
		UcpData[playerid][slot][ucpCharacter] = EOS;
	}
	if(rows)
	{
		for(new i = 0; i < rows; i++)
		{
			count++;
			cache_get_value_name(i, "username", charname);
			format(UcpData[playerid][i][ucpCharacter], 126, charname);
			cache_get_value_name(i, "last_login", lastlog);
			format(UcpData[playerid][i][ucpLastLogin], 126, lastlog);
			cache_get_value_name_int(i, "level" , UcpData[playerid][i][ucpLevel]);

			format(str, sizeof(str), "%s%s\t"YELLOW_E"%d\t"WHITE_E"%s\n", str, UcpData[playerid][i][ucpCharacter], UcpData[playerid][i][ucpLevel], UcpData[playerid][i][ucpLastLogin]);
		}
		if(count < 3)
		{
			format(str, sizeof(str), "%s"GREEN_E"+ Create Character", str);
		}
		ShowPlayerDialog(playerid, UCP_CHARACTER, DIALOG_STYLE_TABLIST_HEADERS, "Load Character", str, "Select", "");
	}
	else
	{
		format(str, sizeof(str), "%s"GREEN_E"+ Create Character", str);
		ShowPlayerDialog(playerid, UCP_CHARACTER, DIALOG_STYLE_TABLIST_HEADERS, "Load Character", str, "Select", "");
	}
	return 1;
}

MySQL_SpawnUcpCharacter(playerid)
{
	new query[524];
	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM players WHERE username = '%s' LIMIT 1", pData[playerid][pName]);
	mysql_tquery(g_SQL, query, "SpawnUcpCharacter", "d", playerid);
	return 1;
}

function SpawnUcpCharacter(playerid)
{
	if(cache_num_rows() > 0)
	{
		cache_get_value_name_int(0, "reg_id", pData[playerid][pID]);

		foreach(new ii : Player)
		{
			if(pData[ii][pTogLog] == 0)
			{
				SendClientMessageEx(ii, -1, "~ {00FF00}%s [%d] {FFFFFF}Telah bergabung kedalam server.", pData[playerid][pName], playerid);
				SendDiscordMessage(2, sprintf("**%s** player joinned to server", pData[playerid][pName]));
			}
		}
		mysql_tquery(g_SQL, sprintf("SELECT * FROM `players` WHERE `username` = '%s' LIMIT 1;", pData[playerid][pName]), "AssignPlayerData", "d", playerid); 
	}
	new query[524], PlayerIP[16];
	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `banneds` WHERE `name` = '%s' OR `ip` = '%s' OR (`longip` != 0 AND (`longip` & %i) = %i) LIMIT 1", pData[playerid][pName], pData[playerid][pIP], BAN_MASK, (Ban_GetLongIP(PlayerIP) & BAN_MASK));
	mysql_tquery(g_SQL, query, "CheckBan", "i", playerid);
	return 1;
}

MySQL_CheckCharacterCreate(playerid, const charname[])
{
	new query[524];
	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM players WHERE username = '%s'", charname);
	mysql_tquery(g_SQL, query, "CheckCharacterCreate", "ds", playerid, charname);
	return 1;
}

function CheckCharacterCreate(playerid, charname[])
{
	if(cache_num_rows())
	{
		new lstring[128];
		format(lstring, sizeof(lstring), "{FFFFFF}%d\n{FF0000}Nama yang anda masukan sudah di pakai!\n\n{00FF00}(Input nama In-Character yang ingin anda buat Contoh : Xeno_Tadasi, Albert_Linghart, etc)", charname);
		ShowPlayerDialog(playerid, UCP_CHARACTER_CREATE, DIALOG_STYLE_INPUT, "Create Character", lstring, "Create", "Cancel");
	}
	else
	{
		new query[842], PlayerIP[16];
		GetPlayerName(playerid, pData[playerid][pUcp], MAX_PLAYER_NAME);

		SetPlayerName(playerid, charname);
		GetPlayerName(playerid, pData[playerid][pName], MAX_PLAYER_NAME);
		GetPlayerIp(playerid, PlayerIP, sizeof(PlayerIP));
		foreach(new ii : Player)
		{
			if(pData[ii][pTogLog] == 0)
			{
				SendClientMessageEx(ii, -1, "~> {00FF00}%s [%d] {FFFFFF}Telah bergabung kedalam server.", pData[playerid][pName], playerid);
				SendDiscordMessage(2, sprintf("**%s** player joinned to server", pData[playerid][pName]));
			}
		}
		mysql_format(g_SQL, query, sizeof query, "INSERT INTO `players` (`username`, `ip`, `reg_date`, `last_login`) VALUES ('%e', '%s', CURRENT_TIMESTAMP(), CURRENT_TIMESTAMP())", pData[playerid][pName], PlayerIP);
		mysql_tquery(g_SQL, query, "OnPlayerRegister", "i", playerid);
	}
	return 1;
}