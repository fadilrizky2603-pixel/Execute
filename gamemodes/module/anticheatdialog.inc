// Nama opsi Anti-Cheat (agar lebih mudah dalam dialog)
new const AntiCheatOptions[][64] =
{
    "Anti-AirBreak (onfoot)",
    "Anti-AirBreak (in vehicle)",
    "Anti-Teleport Hack (onfoot)",
    "Anti-Teleport Hack (in vehicle)",
    "Anti-FlyHack (onfoot)",
    "Anti-SpeedHack (onfoot)",
    "Anti-Health Hack (in vehicle)",
    "Anti-Health Hack (onfoot)",
    "Anti-Armour Hack",
    "Anti-Money Hack"
};

// Menampilkan dialog utama
stock ShowAntiCheatDialog(playerid)
{
    new dialogText[1024];
    
    for (new i = 0; i < sizeof(AntiCheatOptions); i++)
    {
        format(dialogText, sizeof(dialogText), "%s%s%s\n", 
            dialogText,
            ac_ACAllow[i] ? ("{00FF00}") : ("{FF0000}"), // Warna hijau jika aktif, merah jika nonaktif
            AntiCheatOptions[i]
        );
    }

    EasyDialog_ShowList(playerid, AntiCheatDialogResponse, DIALOG_STYLE_LIST, "Pengaturan Anti-Cheat", dialogText, "Ubah", "Tutup");
}

// Callback ketika admin memilih opsi
EasyDialog_Callback(AntiCheatDialogResponse(playerid, response, listitem, inputtext[]))
{
    if (!response) return 1; // Jika admin memilih "Tutup", keluar dari dialog

    ac_ACAllow[listitem] = !ac_ACAllow[listitem]; // Toggle nilai true/false

    new msg[64];
    format(msg, sizeof(msg), "%s sekarang %s", AntiCheatOptions[listitem], ac_ACAllow[listitem] ? "Aktif" : "Nonaktif");
    SendClientMessage(playerid, 0x00FF00FF, msg);

    ShowAntiCheatDialog(playerid); // Tampilkan kembali dialog setelah perubahan
    return 1;
}

CMD:acsettings(playerid, params[])
{
    ShowAntiCheatDialog(playerid);
    return 1;
}