
#include <YSI_Coding/y_hooks>
// Fungsi untuk menghapus radar map

#define PACKET_REMOVE_RADAR 186

// Fungsi untuk menghapus radar map
stock HidePlayerRadar(playerid) {
    new BitStream:bs = BS_New();
    BS_WriteValue(bs, PACKET_REMOVE_RADAR);
    PR_SendPacket(playerid, bs);  
    BS_Delete(bs);
}

hook OnPlayerConnect(playerid) {
    HidePlayerRadar(playerid); // Menyembunyikan radar saat pemain masuk
    return 1;
}

CMD:hideradar(playerid, params[]) {
    HidePlayerRadar(playerid);
    SendClientMessage(playerid, -1, "Radar telah disembunyikan.");
    return 1;
}

hook OnGameModeInit() {
    print("Sistem tutup radar map dengan Pawn.RakNet telah diinisialisasi.");
    return 1;
}

