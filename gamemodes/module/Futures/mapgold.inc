#include <YSI_Coding/y_hooks>
new MapGold[MAX_GANG_ZONES];

hook OnPlayerSpawn(playerid) {
    MapGold[0] = GangZoneCreate(-3000, -3000, 3000, 3000);
    GangZoneShowForPlayer(playerid, MapGold[0], COLOR_GOLD);
}