#include <YSI_Coding/y_hooks>

#define MAX_WARNINGS 5 // Batas peringatan sebelum kick

// Menyimpan jumlah pelanggaran per pemain
new PlayerWarnings[MAX_PLAYERS];

// Inisialisasi Green Zone
hook OnGameModeInit() {
    GangZoneCreate(1348, -2379.5, 1834, -2193.5);
    GangZoneCreate(1100, -2078.5, 1283, -1991.5);
    GangZoneCreate(1385, -1862.5, 1567, -1727.5);
    GangZoneCreate(1046, -1703.5, 1148, -1579.5);
    GangZoneCreate(1047, -1782.5, 1110, -1721.5);
    GangZoneCreate(348, -2089.5, 412, -2010.5);
    GangZoneCreate(541, -1827.5, 599, -1799.5);
    GangZoneCreate(621, -1410.5, 799, -1310.5);
    GangZoneCreate(170, -287.5, 242, -212.5);
    GangZoneCreate(335, -136.5, 385, -56.5);
}

// Fungsi untuk mengecek apakah pemain berada di Green Zone
stock IsPlayerInGreenZone(playerid) {
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    if (x >= 1348 && x <= 1834 && y >= -2379.5 && y <= -2193.5) return 1; // Bandara
    if (x >= 1100 && x <= 1283 && y >= -2078.5 && y <= -1991.5) return 1; // Disnaker
    if (x >= 1385 && x <= 1567 && y >= -1862.5 && y <= -1727.5) return 1; // Balkot
    if (x >= 1046 && x <= 1148 && y >= -1703.5 && y <= -1579.5) return 1; // Kanpol
    if (x >= 1047 && x <= 1110 && y >= -1782.5 && y <= -1721.5) return 1; // Dealer
    if (x >= 348 && x <= 412 && y >= -2089.5 && y <= -2010.5) return 1; // Carnaval
    if (x >= 541 && x <= 599 && y >= -1827.5 && y <= -1799.5) return 1; // Pedagang
    if (x >= 621 && x <= 799 && y >= -1410.5 && y <= -1310.5) return 1; // Sanews
    if (x >= 170 && x <= 242 && y >= -287.5 && y <= -212.5) return 1; // Mecha
    if (x >= 335 && x <= 385 && y >= -136.5 && y <= -56.5) return 1; // Asuransi

    return 0;
}

// Cegah pemain menyerang dalam Green Zone
hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart) {
    if (IsPlayerInGreenZone(playerid)) {
        PlayerWarnings[playerid]++; // Tambahkan jumlah peringatan
        
        // Jika pemain telah melanggar lebih dari batas
        if (PlayerWarnings[playerid] >= MAX_WARNINGS) {
            SendClientMessage(playerid, 0xFF0000FF, "[Green Zone] Anda telah diperingatkan 5 kali! Anda akan dikeluarkan.");
            Kick(playerid);
        } else {
            new string[128];
            format(string, sizeof(string), "[Green Zone] Dilarang menyerang! Peringatan: %d/5", PlayerWarnings[playerid]);
            SendClientMessage(playerid, 0xFFAA00FF, string);
        }
        return 0; // Batalkan serangan
    }
    return 1;
}

// Reset peringatan saat pemain keluar dari server
hook OnPlayerDisconnect(playerid, reason) {
    PlayerWarnings[playerid] = 0;
    return 1;
}
