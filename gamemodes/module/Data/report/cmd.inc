CMD:report(playerid, params[])
{
    new reportid = -1;

    if(isnull(params))
    {
        Usage(playerid, "/report (text)");
        return 1;
    }
    if(Report_GetCount(playerid) > 1)
        return Error(playerid, "Anda sudah memiliki laporan, tunggu sampai admin mejawab.");

    if(pData[playerid][pReportTime] >= gettime())
        return Error(playerid, "Anda harus menunggu %d detik untuk mengajukan laporan.", pData[playerid][pReportTime] - gettime());

    if((reportid = Report_Add(playerid, params)) != -1)
    {
        Info(playerid, "Anda berhasil mengirim permintaan {FF0000}'/report' {FFFFFF}kepada Administrator");
        if(pData[playerid][pTogReport] == 0)
        {
            SendStaffMessage(-1, "%s telah mengajukan laporan gunakan {FF0000}'/reports' {FFFFFF}untuk menjawab | {FF0000}REPORT ID: %d", pData[playerid][pName], reportid);
            SendStaffMessage(-1, "~> %s", params);
        }
        pData[playerid][pReportTime] = gettime() + 180;
    }
    else Error(playerid, "Saat ini permintaan {FF0000}'/report' {FFFFFF}sedang penuh, silahkan coba lagi nanti");
    return 1;
}

/*CMD:ar(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return PermissionError(playerid);

    if(isnull(params))
        return Usage(playerid, "/ar [report id] (/reports for a list)");

    new
        reportid = strval(params);
        
    if((reportid < 0 || reportid >= MAX_REPORTS) || !ReportData[reportid][rExists])
        return Error(playerid, "Invalid report ID. Reports list from 0 to %d.", MAX_REPORTS);

    SendStaffMessage(COLOR_RED, "%s has accepted %s(%d) report.", pData[playerid][pAdminname], pData[ReportData[reportid][rPlayer]][pName], ReportData[reportid][rPlayer]);
    Servers(ReportData[reportid][rPlayer], "ACCEPT REPORT: {FF0000}%s {FFFFFF}accept your report.", pData[playerid][pAdminname]);
    Report_Remove(reportid);
    return 1;
}*/

/*CMD:dr(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return Error(playerid, "Kamu tidak memiliki izin!");

    new reportid, msg[32];
    if(sscanf(params,"ds[32]", reportid, msg))
        return Usage(playerid, "/dr [report id] [reason] (/reports for a list)");

    if((reportid < 0 || reportid >= MAX_REPORTS) || !ReportData[reportid][rExists])
        return Error(playerid, "ID Report tidak valid, listitem 0 sampai %d.", MAX_REPORTS);

    SendStaffMessage(COLOR_RED, "%s has denied %s(%d) report.", pData[playerid][pAdminname], pData[ReportData[reportid][rPlayer]][pName], ReportData[reportid][rPlayer]);
    Servers(ReportData[reportid][rPlayer], "DENY REPORT: {FF0000}%s {FFFFFF}denied your report: %s.", pData[playerid][pAdminname], msg);

    Report_Remove(reportid);
    return 1;
}*/

CMD:reports(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return PermissionError(playerid);
			
	new gstr[1024], mstr[128], lstr[512];
    strcat(gstr,"ID\tPlayer\tDescription\n",sizeof(gstr));

    for (new i = 0; i != MAX_REPORTS; i ++)
    {
        if(!ReportData[i][rExists])
           return Error(playerid, "Saat ini belum ada laporan yang aktif");

        strunpack(mstr, ReportData[i][rText]);

        if(strlen(mstr) > 32)
            format(lstr,sizeof(lstr), "#%d\t%s (%d)\t%.32s ...\n", i, pData[ReportData[i][rPlayer]][pName], ReportData[i][rPlayer], mstr);
        else
            format(lstr,sizeof(lstr), "#%d\t%s (%d)\t%s\n", i, pData[ReportData[i][rPlayer]][pName], ReportData[i][rPlayer], mstr);

        strcat(gstr,lstr,sizeof(gstr));
        ShowPlayerDialog(playerid, DIALOG_REPORTS, DIALOG_STYLE_TABLIST_HEADERS,"Report List",gstr,"Next","Cancel");
    }
    return 1;
}

CMD:clearreports(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
            return PermissionError(playerid);
    new
        count;

    for (new i = 0; i != MAX_REPORTS; i ++)
    {
        if(ReportData[i][rExists]) {
            Report_Remove(i);
            count++;
        }
    }
    if(!count)
        return Error(playerid, "Tidak ada Laporan yang aktif.");
            
    SendStaffMessage(COLOR_RED, "%s telah menghapus semua permintaan {FF0000}'/report' {FFFFFF}yang ada di server", pData[playerid][pAdminname]);
    return 1;
}