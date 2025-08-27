enum E_SUITSUTFF
{
	Text3D:TimeRolled
}
new PlayerSuitVars[MAX_PLAYERS][E_SUITSUTFF];
new timesuit[MAX_PLAYERS];
CMD:rps(playerid, params[])
{
	if(timesuit[playerid])
		return Error(playerid, "Harap tunggu sebentar");

    Dialog_Show(playerid, DIALOG_SUIT, DIALOG_STYLE_LIST, ""GREY_E"Suit Menu",
    "Gunting\nBatu\nKertas", "Select", "Cancel");
	return 1;
}

Dialog:DIALOG_SUIT(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(listitem == 0)
        {
            new str[200];
            new Float: x, Float: y, Float: z;
            GetPlayerPos(playerid, x, y, z);

            ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
            format(str, 200, "Suit : "LG_E"Gunting");
            PlayerSuitVars[playerid][TimeRolled] = Create3DTextLabel(str, -1,  x, y, z, 15.0, 0, 1);
            timesuit[playerid] = 500;
            SetTimerEx("hapussuit", 5000, 0, "i", playerid);            
        }
        if(listitem == 1)
        {
            new str[200];
            new Float: x, Float: y, Float: z;
            GetPlayerPos(playerid, x, y, z);

            ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
            format(str, 200, "Suit : "LG_E"Batu");
            PlayerSuitVars[playerid][TimeRolled] = Create3DTextLabel(str, -1,  x, y, z, 15.0, 0, 1);
            timesuit[playerid] = 500;
            SetTimerEx("hapussuit", 5000, 0, "i", playerid);            
        }        
        if(listitem == 2)
        {
            new str[200];
            new Float: x, Float: y, Float: z;
            GetPlayerPos(playerid, x, y, z);

            ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
            format(str, 200, "Suit : "LG_E"Kertas");
            PlayerSuitVars[playerid][TimeRolled] = Create3DTextLabel(str, -1,  x, y, z, 15.0, 0, 1);
            timesuit[playerid] = 500;
            SetTimerEx("hapussuit", 5000, 0, "i", playerid);            
        }        
    }
    return 1;
}

function hapussuit(playerid)
{
	timesuit[playerid] = 0;
	Delete3DTextLabel(PlayerSuitVars[playerid][TimeRolled]);
	return 1;
}