new RandomMSG[13][] =
{
    "{FBFF00}Tips:{FFFFFF} Jangan lupa minum, biar stamina karakter kamu nggak drop!",
    "{FBFF00}Tips:{FFFFFF} Jangan lup sholat saat kamu bermain roleplay",
    "{FBFF00}Tips:{FFFFFF} Gunakan roleplay drive saat berkendaraa!",
    "{FBFF00}Tips:{FFFFFF} Pesan hari ini: Jangan royal buat beli mobil mahal, tabung buat bisnis aja!",
    "{FBFF00}Tips:{FFFFFF} Jangan gunakan {FFD700}/ask {FFFFFF}buat laporin sesuatu kerna itu untuk bertanya!",
    "{FBFF00}Tips:{FFFFFF} Gunakan command {FFD700}/admin {FFFFFF}untuk melihat admin duty",
    "{FBFF00}Tips:{FFFFFF} Buat lah roleplay semenarik mungkin!",
    "{FBFF00}Tips:{FFFFFF} Selalu berolahraga agar tubuh kamu menjadi sehat!",
    "{FBFF00}Tips:{FFFFFF} Telpon mechanic jika kendaraanmu rusak!",
    "{FBFF00}Tips:{FFFFFF} Telpon medic jika temanmu sedang koma!",
    "{FBFF00}Tips:{FFFFFF} Telpon taxi jika kamu sedang butuh!",
    "{FBFF00}Tips:{FFFFFF} Jika kamu mengalami pusing silahkan pergi ke cgh, yang berada di dekat skate!",
    "{FBFF00}Tips:{FFFFFF} Jika kalian ingin donasi silahkan cek di discord {E5FF00}Local Prime!"
};

stock RandomSendMSG()
{
    new randMSG = random(sizeof(RandomMSG));
    va_SendClientMessageToAll(X11_TOMATO, RandomMSG[randMSG]);
}

hook OnGameModeInit()
{
    SetTimer("RandomSendMSG", 300000, true);
    return 1;
}