#include <YSI_Coding/y_hooks>

public OnPlayerRequestDownload(playerid, type, crc)
{
    return 1;
}

public OnPlayerFinishedDownloading(playerid, virtualworld)
{
    SuccesMsg(playerid, "Install skins succesfully");
	return 1;
}

stock LoadSkin() {
    //skin civilan
    AddCharModel(200, 20001, "maccer.dff", "maccer.txd");
    AddCharModel(201, 20001, "pain.dff", "pain.txd");
}