CMD:ask(playerid, params[])
{
    new reportid = -1;

    if(isnull(params))
    {
        Usage(playerid, "/ask (text)");
        return 1;
    }
    if(Ask_GetCount(playerid) > 1)
        return Error(playerid, "Anda sudah memiliki pertanyaan, tunggu sampai admin mejawab.");

    if(pData[playerid][pAskTime] >= gettime())
        return Error(playerid, "Anda harus menunggu %d detik lagi untuk mengajukan pertanyaan", pData[playerid][pAskTime] - gettime());

    if((reportid = Ask_Add(playerid, params)) != -1)
    {
        Info(playerid, "Anda berhasil mengirim permintaan {FFFF00}'/ask' {FFFFFF}kepada Administrator");
        if(pData[playerid][pTogAsk] == 0)
        {
            SendStaffMessage(-1, "%s telah mengajukan pertanyaan gunakan {FFFF00}'/asks' {FFFFFF}untuk menjawab | {FFFF00}ASK ID: %d", pData[playerid][pName], reportid);
            SendStaffMessage(-1, "~> %s", params);
        }
        pData[playerid][pAskTime] = gettime() + 180;
    }
    else Error(playerid, "Saat ini permintaan {FFFF00}'/ask' {FFFFFF}sedang penuh, silahkan coba lagi nanti");
    return 1;
}

/*CMD:ans(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return Error(playerid, "Kamu tidak memiliki hak untuk menggunakan ini!");

    new reportid, msg[32];
    if(sscanf(params,"ds[32]", reportid, msg))
        return Usage(playerid, "/ans [ask id] [jawaban] (/asks for a list)");

    if((reportid < 0 || reportid >= MAX_ASKS) || !AskData[reportid][askExists])
        return Error(playerid, "ID Ask tidak valid, Listitem dari 0 sampai %d.", MAX_ASKS);

    SendStaffMessage(COLOR_RED, "%s telah menjawab pertanyaan %s(%d).", pData[playerid][pAdminname], pData[AskData[reportid][askPlayer]][pName], AskData[reportid][askPlayer]);
    Servers(AskData[reportid][askPlayer], "ANSWER: {FF0000}%s {FFFFFF}: %s.", pData[playerid][pAdminname], msg);

    Ask_Remove(reportid);
    return 1;
}*/

CMD:asks(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return PermissionError(playerid);
			
	new gstr[1024], mstr[128], lstr[512];
    strcat(gstr,"ID\tPlayer\tDescription\n",sizeof(gstr));

    for (new i = 0; i != MAX_ASKS; i ++)
    {
        if(!AskData[i][askExists])
            return Error(playerid, "Saat ini belum ada pertanyaan yang aktif");

        strunpack(mstr, AskData[i][askText]);

        if(strlen(mstr) > 32)
            format(lstr,sizeof(lstr), "#%d\t%s (%d)\t%.32s ...\n", i, pData[AskData[i][askPlayer]][pName], AskData[i][askPlayer], mstr);
        else
            format(lstr,sizeof(lstr), "#%d\t%s (%d)\t%s\n", i, pData[AskData[i][askPlayer]][pName], AskData[i][askPlayer], mstr);

        strcat(gstr,lstr,sizeof(gstr));
        ShowPlayerDialog(playerid, DIALOG_ASKS, DIALOG_STYLE_TABLIST_HEADERS,"Ask List",gstr,"Next","Cancel");
    }
    return 1;
}

CMD:clearask(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
            return PermissionError(playerid);
    new
        count;

    for (new i = 0; i != MAX_ASKS; i ++)
    {
        if(AskData[i][askExists]) {
            Ask_Remove(i);
            count++;
        }
    }
    if(!count)
        return Error(playerid, "Tidak ada Pertanyaan yang aktif.");
            
    SendStaffMessage(COLOR_RED, "%s telah menghapus semua permintaan {FFFF00}'/ask' {FFFFFF}yang ada di server", pData[playerid][pAdminname]);
    return 1;
}