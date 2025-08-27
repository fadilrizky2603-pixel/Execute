forward CheckCharacters(playerid);
public CheckCharacters(playerid)
{
    new query[256];
    mysql_format(dcrp_query, query, sizeof(query), "SELECT Char_Name, Char_Skin FROM player_characters WHERE Char_UCP= '%s'LIMIT %d;", AccountData[playerid][pUCP], MAX_CHARS + AccountData[playerid][pExtraChar]);
    mysql_tquery(dcrp_query, query, "LoadCharacter", "d", playerid);
    return 1;
}

forward LoadCharacter(playerid);
public LoadCharacter(playerid)
{
	for(new i = 0; i < MAX_CHARS; i ++)
	{
		PlayerChar[playerid][i][0] = EOS;
	}
	for(new i = 0; i < cache_num_rows(); i ++)
	{
		cache_get_value_name(i, "Char_Name", PlayerChar[playerid][i]);
		cache_get_value_name_int(i, "Char_Skin", CharSkin[playerid][i]);
	}
	ShowCharacterList(playerid);
	return 1;
}

stock SpawnChar(playerid, char_id)
{
	if(AccountData[playerid][IsLoggedIn] == true)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah login!");

	forex(i, 18)
	{
		PlayerTextDrawHide(playerid, Character_Select[playerid][i]);
	}
	CancelSelectTextDraw(playerid);
	PlayerSpawn[playerid] = 1;

	if(PlayerChar[playerid][char_id][0] == EOS) return ShowPlayerDialog(playerid, DIALOG_MAKE_CHAR, DIALOG_STYLE_INPUT, ""PINK1"DCRP"WHITE"- Pembuatan Karakter",
		""WHITE"Selamat Datang di "PINK1"DCRP\n"WHITE"Sebelum bermain anda harus membuat karakter terlebih dahulu\
		\nMasukkan nama karakter hanya dengan nama orang Indonesia\nCth: Dudung_Sutarman, Aldy_Firmansyah", "Input", "");

	SetPlayerName(playerid, PlayerChar[playerid][char_id]);
	StopStream(playerid);
	
	if(!Blacklist_Check(playerid, "name", PlayerChar[playerid][char_id])) {
		mysql_tquery(dcrp_query, sprintf("SELECT * FROM `player_characters` WHERE `Char_Name` = '%s' LIMIT 1;", PlayerChar[playerid][char_id]), "LoadPlayerData", "d", playerid);
	}
	return 1;
}

stock ShowCharacterList(playerid)
{
	/*SetSpawnInfo(playerid, NO_TEAM, CharSkin[playerid][0], 1158.4897,-1644.3599,-30.4449+0.1,272.5841, 0, 0, 0, 0, 0, 0);
	SpawnPlayer(playerid);*/
	SetSpawnInfo(playerid, NO_TEAM, CharSkin[playerid][0], 349.8621,-2052.0586,7.8359+0.1,90.4918, 0, 0, 0, 0, 0, 0);
	SpawnPlayer(playerid);
	
	new str[18];
	if(PlayerChar[playerid][0][0] != EOS)
	{
		format(str, sizeof(str), "%s", PlayerChar[playerid][0]);
		PlayerTextDrawSetString(playerid, Character_Select[playerid][14], str);
		PlayerTextDrawSetString(playerid, Character_Select[playerid][11], "Spawn");
	}
	else
	{
		PlayerTextDrawSetString(playerid, Character_Select[playerid][14], "Buat Karakter");
		PlayerTextDrawSetString(playerid, Character_Select[playerid][11], "Create");
	}
	
	if(PlayerChar[playerid][1][0] != EOS)
	{
		format(str, sizeof(str), "%s", PlayerChar[playerid][1]);
		PlayerTextDrawSetString(playerid, Character_Select[playerid][13], str);
		PlayerTextDrawSetString(playerid, Character_Select[playerid][12], "Spawn");
	}
	else
	{
		PlayerTextDrawSetString(playerid, Character_Select[playerid][13], "Buat Karakter");
		PlayerTextDrawSetString(playerid, Character_Select[playerid][12], "Create");
	}

	forex(i, 18)
	{
		PlayerTextDrawShow(playerid, Character_Select[playerid][i]);
	}
	SelectTextDraw(playerid, COLOR_SYNTAX);
	return 1;
}