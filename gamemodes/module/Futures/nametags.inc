#define NT_DISTANCE 30.0 // Nametag render distance
new Text3D:cNametag[MAX_PLAYERS];

#define DEFAULT_COLOR 0xFFFFFFAA  // Putih dengan transparansi
#define DAMAGED_COLOR 0xFF0000AA  // Merah dengan transparansi

#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    SetTimer("UpdateNametag", 1000, true);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    cNametag[playerid] = CreateDynamic3DTextLabel("Loading nametag...", 0xFFFFFFFF, 0.0, 0.0, 0.1, NT_DISTANCE, .attachedplayer = playerid, .testlos = 1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(IsValidDynamic3DTextLabel(cNametag[playerid]))
              DestroyDynamic3DTextLabel(cNametag[playerid]);
    return 1;
}

ReturnNameTags(i)
{
    static
        name[MAX_PLAYER_NAME + 1];

    GetPlayerName(i, name, sizeof(name));
	for (new r = 0, len = strlen(name); r < len; r ++) {
			if(name[r] == '_') name[r] = ' ';
	}
    return name;
}

function UpdateNametag()
{
    for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
    {
        if(IsPlayerConnected(i))
        {
            new nametag[64], playername[MAX_PLAYER_NAME];

            GetPlayerName(i, playername, sizeof(playername));
            {
                format(nametag, sizeof(nametag), "{%06x}%s [%i]{FFFFFF}", GetPlayerColor(i) >>> 8, ReturnNameTags(i), i);
            }
            UpdateDynamic3DTextLabelText(cNametag[i], 0xFFFFFFFF, nametag);
        }
    }
}

stock ResetPlayerColor(playerid)
{
    // Mengembalikan warna nametag pemain ke warna default
    SetPlayerColor(playerid, DEFAULT_COLOR);
    return 1;
}