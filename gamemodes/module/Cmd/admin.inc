CMD:acmds(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		return PermissionError(playerid);

	new line3[2480];
	strcat(line3, ""WHITE_E"Moderator/Admin Commands:"LB2_E"\n\
 	/aduty /a /hel /asay /togooc /o /goto /gethere /freeze /unfreeze /arevive /areviveall /spec /slap\n\
 	/caps /peject /astats /ostats /acuff /auncuff /jetpack /getip /aka /akaip /jail /unjail\n\
	/kick /ban /unban /respawnjobs /setbooster /asettings\n\
	/reports /asks /ans /ar /dr /vmodels /vehname /apv /aveh /gotoveh /getveh /aject /setvw /adamagelogs");

	strcat(line3, "\n\n"WHITE_E"Admin Junior Commands:"LB2_E"\n\
 	/sethp /setbone /afuel /agl /clearreports /afix /setskin /akill /ann /cd /settime /setweather /gotows\n\
    /ojail /owarn /setam /gotoco /gotohouse /gotodoor /gotolocker /gotogs /banip /unbanip /asalve\n\
    /gotorent /gotows /sendto /frespawnveh /respawnsamd /respawnsana /respawnsapd /respawnsacf /respawnsags");

	strcat(line3, "\n\n"WHITE_E"Admin Commands:"LB2_E"\n\
	/oban /banucp /areloadweap /resetweap /sethbe /gotodealer /gotopark /gotoobj /gotopfarm /gotosignal\n\
 	/asignal /gotospeedcam /gotoven/createdoor /editdoor /gotoven /askel /gotosvpoint");

	strcat(line3, ""WHITE_E"\n\nHead Admin Commands:"LB2_E"\n\
	/setname /setvip /setfaction /setleader /takemoney /takegold /giveweap\n\
	/veh /destroysveh");

	strcat(line3, "\n\n"WHITE_E"Executive Admin Commands:"LB2_E"\n\
	/sethelperlevel /setadminname /setmoney /givemoney /setbankmoney /givebankmoney /setjob1 /setjob2 /setjobtime\n\
	/setmaterial /setcomponent /createpv /destroypv /explode /makequiz /agive /mappinghelp /setlevel /setgender\n\
	/mappinghelp /resetrobbank /createsignal /editsignal /editspeedcam /createspeedcam /editven /fcreate /ainv\n\
	/fedit /fdelete /afkick /awskick /setstock /createnpcfam /deletenpcfam /createsvpoint /deletesvpoint /createpayphone /editpayphone");

	strcat(line3,"\n\n"WHITE_E"Developer/CEO:"LB2_E"\n\
	/setadminlevel /setgold /givegold /setstock /setprice /createven /editven\n\
	/createhouse /edithouse /createdealer /editdealer /setitem(inventory) /itemlist(inventory)\n\
	/restockalldealer /createpfarm /editpfarm /createrent /editrent /createws /wsdelete /wsedit\n\
	/spdealerall /sphouseall /restockalldealer /setjobprice /setarmorall /sethpall /sipdealerall");

	strcat(line3, "\n"BLUE_E"LOCALPRIME:RP "WHITE_E"- Anti-Cheat is actived.\n\
	"PINK_E"NOTE: All admin commands log is saved in database! | Abuse Commands? Kick And Demote Premanent!.");
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""ORANGE_E"LOCALPRIME:RP"YELLOW_E"Staff Commands", line3, "OK","");
	return true;
}

CMD:afkick(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/afkick [playerid/PartOfName]");
		
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "Invalid ID.");
	
	if(otherid == playerid)
		return Error(playerid, "Invalid ID.");

	pData[otherid][pFamily] = -1;
	pData[otherid][pFamilyRank] = 0;
	Servers(playerid, "You have removed %s from Family.", pData[otherid][pName]);
	Servers(otherid, "Administrator {A60000}%s {FFFFFF}has removed you from the Family.", pData[playerid][pAdminname]);
	return 1;
}

CMD:awskick(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/awskick (PlayerID/PartOfName)");
		
	if(!IsPlayerConnected(otherid))
		return Error(playerid, "The player in question was not found");

	pData[otherid][pWorkshop] = -1;
	pData[otherid][pWorkshopRank] = 0;
	Servers(playerid, "You have removed %s from the workshop.", pData[otherid][pName]);
	Servers(otherid, "Administrator {A60000}%s has removed you from the workshop.", pData[playerid][pAdminname]);
	return 1;
}

CMD:asalve(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
	if(pData[playerid][pHelper] < 1)
        return PermissionError(playerid);
	
	new otherid;
	if(sscanf(params, "u", otherid))
        return Usage(playerid, "/salve (PlayerID/PartOfName)");

    if(pData[otherid][pSick] == 0)
        return Error(playerid, "The player has not experienced {FF0000}'Sick'");
        
	pData[otherid][pHunger] += 50;
	pData[otherid][pEnergy] += 50;
	pData[otherid][pSick] = 0;
	pData[otherid][pSickTime] = 0;
    clearAnimations(otherid);
    ApplyAnimation(otherid, "CARRY", "crry_prtial", 4.1, 0, 0, 0, 0, 0, 1);
	SetPlayerDrunkLevel(otherid, 0);
	new str[200];
	format(str, sizeof(str), "Administrator %s has cured your illness", pData[playerid][pAdminname]);
	InfoMsg(otherid, str);
	SendStaffMessage(-1, "{A60000}%s {FFFFFF}has used {FFFF00}'/asalve' {FFFFFF}on %s", pData[playerid][pAdminname], ReturnName(otherid));
	return 1;
}

CMD:arelease(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);

	new otherid;
	if(sscanf(params, "u", otherid))
	{
	    Usage(playerid, "/arelease (PlayerID/PartOfName)");
	    return true;
	}

    if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "The player in question was not found");

	if(pData[otherid][pArrest] == 0)
	    return Error(playerid, "The player is not in prison");

	pData[otherid][pArrest] = 0;
	pData[otherid][pArrestTime] = 0;
	SetPlayerInterior(otherid, 0);
	SetPlayerVirtualWorld(otherid, 0);
	SetPlayerPositionEx(otherid, 1097.26, -1665.73, 15.03, 278.5868, 2000);
	SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);
	return true;
}

CMD:helpquiz(playerid,params[])
{
	if(pData[playerid][pAdmin] < 2) return PermissionError(playerid);

	Usage(playerid, "1./quizans | 2./quizprize | .3.quizquest | /quizend");

	return 1;
}

CMD:quizquest(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) return PermissionError(playerid);

	new string[200], str[256];
	if(sscanf(params, "s[256]", str)) return SyntaxMsg(playerid, "/quizquest [caption]");
	if(quiz == 1) return InfoTD_MSG(playerid, 4000, "The quiz is starting, use ~y~/quizend ~w~ to end");
	if(answermade == 0) return InfoTD_MSG(playerid, 4000, "You must create an Answer first, ~y~/quizanswer");
	if(qprs == 0) return InfoTD_MSG(playerid, 4000, "You haven't added a Prize, ~y~/quizprize");
	format(string, sizeof(string), "{FCF77B}QUIZ: {FFFFFF}%s | Prize: {00FF00}$%d.", str, qprs);
	va_SendClientMessageToAll(-1, string);
	va_SendClientMessageToAll(-1,"Use {FFFF00}'/answer' {FFFFFF}to answer");
	quiz = 1;

	return 1;
}

CMD:quizans(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) return PermissionError(playerid);

	new string[500], str[256];
	if(sscanf(params, "s[256]", str)) return SyntaxMsg(playerid, "/quizans [caption]");
	if(quiz == 1) return InfoTD_MSG(playerid, 4000, "The quiz is starting, use ~y~/quizend ~w~ to end");
	answers = str;
	answermade = 1;
	format(string, sizeof(string), "{FCF77B}QUIZ: {FFFFFF}Answer successfully created | {00FF00}%s.", str);
	SendClientMessage(playerid, -1, string);
	return 1;
}

CMD:quizprize(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) return PermissionError(playerid);

	new string[500], pr;
	if(sscanf(params, "d", pr)) return Usage(playerid, "/makequiz price [amount]");
	if(quiz == 1) return InfoTD_MSG(playerid, 4000, "The quiz is starting, use ~y~/quizend ~w~ to end");
	if(answermade == 0) return InfoTD_MSG(playerid, 4000, "You must create an Answer first, ~y~/quizanswer");
	if(pr <= 0) return InfoTD_MSG(playerid, 4000, "Cannot enter empty amount");
	qprs = pr;
	format(string, sizeof(string), "{FCF77B}QUIZ: {FFFFFF}You have awarded a Quiz prize of {00FF00}$%d", pr);
	SendClientMessage(playerid, -1, string);
	return 1;
}

CMD:quizend(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) return PermissionError(playerid);
	if(quiz == 0) return ErrorMsg(playerid, "There are no quizzes whatsoever");
		
	va_SendClientMessageToAll(-1, "{FF0000}Administrator {FFFFFF}has ended the Quiz");
	answermade = 0;
	quiz = 0;
	qprs = 0;
	return 1;
}

CMD:answer(playerid, params[])
{
	new tmp[256], string[256];
	if (quiz == 0) return ErrorMsg(playerid, "Currently there are no quizzes created");
	if (sscanf(params, "s[256]", tmp)) return Usage(playerid, "/answer [caption]");
	if(strcmp(tmp, answers, true)==0)
	{
		GivePlayerMoneyEx(playerid, qprs);
		format(string, sizeof(string), "{FCF77B}QUIZ: {FFFFFF}%s has given the correct answer {FFFF00}'%s' {FFFFFF}of the Quiz and won the prize {00FF00}$%d.", ReturnName(playerid), answers, qprs);
		va_SendClientMessageToAll(0xFFFF00FF, string);
		answermade = 0;
		quiz = 0;
		qprs = 0;
		answers = "";
	}
	else
	{
		ErrorMsg(playerid,"Your answer is wrong, please try again");
	}
	return 1;
}

CMD:hcmds(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] == 0)
		return PermissionError(playerid);

	new line3[2480];
	strcat(line3, ""WHITE_E"Junior Helper Commands:"LB2_E"\n\
 	/aduty /hel /asay /o /goto /sendto /gethere /freeze /unfreeze\n\
	/kick /slap /caps /acuff /auncuff /reports /ar /dr");

	strcat(line3, "\n\n"WHITE_E"Senior Helper Commands:"LB2_E"\n\
 	/spec /peject /astats /ostats /jetpack\n\
    /jail /unjail");

	strcat(line3, "\n\n"WHITE_E"Head Helper Commands:"LB2_E"\n\
	/respawnsapd /respawnsags /respawnsamd /respawnsana /respawnjobs\n");
 	
	strcat(line3, "\n"BLUE_E"LOCALPRIME:RP "WHITE_E"- Anti-Cheat is actived.\n\
	"PINK_E"NOTE: All admin commands log is saved in database! | Abuse Commands? Kick And Demote Premanent!.");
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""ORANGE_E"LOCALPRIME:RP"YELLOW_E"Staff Commands", line3, "OK","");
	return true;
}

/*CMD:admins(playerid, params[])
{
    new count = 0;
	new str[1280];
	foreach(new i:Player)
	{
		if(pData[i][pAdmin] > 0 || pData[i][pHelper] > 0)
		{
			if(pData[i][pAdminDuty] == 0)
			{
			  	format(str, sizeof(str), ""WHITE_E"[%s"WHITE_E"] %s (%s) (ID: %i) ["GREEN_E"Roleplaying"WHITE_E"]\n", GetStaffRank(i), pData[i][pAdminname], pData[i][pName], i);
			    count++;
			}
			if(pData[i][pAdminDuty] == 1)
			{
			  	format(str, sizeof(str), ""WHITE_E"[%s"WHITE_E"] %s (%s) (ID: %i) ["RED_E"On Duty"WHITE_E"]\n", GetStaffRank(i), pData[i][pAdminname], pData[i][pName], i);
			    count++;
			}
		}
	}
	if(count > 0)
	{
		SendClientMessageEx(playerid, COLOR_WHITE, "Anda bisa {ffff00}'/report' {ffffff}Melaporkan sesuatu saat admin sedang online");
		SendClientMessageEx(playerid, COLOR_WHITE, "Anda bisa {ffff00}'/ask' {ffffff}Untuk bertanya saat admin sedang online");
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Staff Online", str, "Close", "");
	}
	else return SendClientMessageEx(playerid, COLOR_WHITE, "Tidak ada admin yang online saat ini");
	return 1;
}*/

CMD:admins(playerid, params[])
{
	new duty[16], astr[1024];
	format(astr, sizeof(astr), "ID\tName\tRank\tStatus\n");
	foreach(new i : Player)
	{
		if(pData[i][pAdmin] > 0 || pData[i][pHelper] > 0)
		{
			switch(pData[i][pAdminDuty])
			{
				case 0:
				{
					duty = "OFF Duty";
				}
				case 1:
				{
					duty = "ON Duty";
				}
			}
			format(astr, sizeof(astr), "%s#%d\t{A60000}%s{FFFFFF}\t%s\t%s", astr, i, pData[i][pAdminname], GetStaffRank(i), duty);
			format(astr, sizeof(astr), "%s\n", astr);			
		}
	}
	format(astr, sizeof(astr), "%s\n", astr);
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Admin Online", astr, "Close", "");
	return 1;
}

CMD:adminjail(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] == 0)
			return PermissionError(playerid);
			
	new count = 0, line3[512];
	foreach(new i:Player)
	{
		if(pData[i][pJail] > 0)
		{
			format(line3, sizeof(line3), "%s\n"WHITE_E"%s(ID: %d) [Jail Time: %d seconds]", line3, pData[i][pName], i, pData[i][pJailTime]);
			count++;
		}
	}
	if(count > 0)
	{
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Jail Player", line3, "Close", "");
	}
	else
	{
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"Jail Player", "There are no player in jail!", "Close", "");
	}
	return 1;
}

//---------------------------[ Admin Level 1 ]--------------------
CMD:aduty(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] == 0)
			return PermissionError(playerid);
			
	if(!strcmp(pData[playerid][pAdminname], "None"))
		return ErrorMsg(playerid, "You have not set the Admin name");
	
	if(!pData[playerid][pAdminDuty])
    {
		if(pData[playerid][pAdmin] > 0)
		{
			SetPlayerColor(playerid, COLOR_ADMIN);
			pData[playerid][pAdminDuty] = 1;
			SetPlayerName(playerid, pData[playerid][pAdminname]);
			SendStaffMessage(COLOR_YELLOW, "{FF0000}%s {FFFFFF}has been {00FF00}ON {FFFFFF}Administrator duty as {A60000}%s", pData[playerid][pName], pData[playerid][pAdminname]);
			SetTimerEx("LabelAdmin", 1000, false, "d", playerid);
		}
		else
		{
			SetPlayerColor(playerid, COLOR_ADMIN);
			pData[playerid][pAdminDuty] = 1;
			SetPlayerName(playerid, pData[playerid][pAdminname]);
			SendStaffMessage(COLOR_YELLOW, "{FF0000}%s {FFFFFF}has been {00FF00}ON {FFFFFF}Helper duty as {A60000}%s", pData[playerid][pName], pData[playerid][pAdminname]);
			SetTimerEx("LabelAdmin", 1000, false, "d", playerid);
		}
    }
    else
    {
        if(pData[playerid][pFaction] != -1 && pData[playerid][pOnDuty]) 
            SetFactionColor(playerid);
        else 
            SetPlayerColor(playerid, COLOR_WHITE);
                
        SetPlayerName(playerid, pData[playerid][pName]);
        pData[playerid][pAdminDuty] = 0;
        SendStaffMessage(COLOR_RED, "{FF0000}%s {FFFFFF}has been {FF0000}OFF {FFFFFF}Administrator duty.", pData[playerid][pAdminname]);
    }
	return 1;
}

function LabelAdmin(playerid)
{
    if(IsPlayerConnected(playerid))
    {
        new nametag[128], playername[MAX_PLAYER_NAME];
        GetPlayerName(playerid, playername, sizeof(playername));
        format(nametag, sizeof(nametag), "{FF0000}%s {FFFFFF}[%d]", pData[playerid][pAdminname], playerid);
        UpdateDynamic3DTextLabelText(pData[playerid][AdminTag], COLOR_YELLOW, nametag);
    }
}

CMD:hel(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] == 0)
			return PermissionError(playerid);

	if(isnull(params))
	{
	    Usage(playerid, "/hel (text)");
	    return true;
	}

    // Decide about multi-line msgs
	new i = -1;
	new line[512];
	if(strlen(params) > 70)
	{
		i = strfind(params, " ", false, 60);
		if(i > 80 || i == -1) i = 70;

		// store the second line text
		line = " ";
		strcat(line, params[i]);

		// delete the rest from msg
		params[i] = EOS;
	}
	new mstr[512];
	format(mstr, sizeof(mstr), "{FF3939}Helper Chat > {FFFFFF}%s | {A60000}%s {FFFFFF}[%i]: %s", GetStaffRank(playerid), pData[playerid][pAdminname], playerid, params);
	foreach(new ii : Player) 
	{
		if(pData[ii][pAdmin] > 0 || pData[ii][pHelper] == 1)
		{
			SendClientMessage(ii, COLOR_LB, mstr);	
		}
	}
	if(i != -1)
	{
		foreach(new ii : Player)
		{
			if(pData[ii][pAdmin] > 0 || pData[ii][pHelper] == 1)
			{
				SendClientMessage(ii, COLOR_LB, line);
			}
		}
	}
	return 1;
}

CMD:a(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
			return PermissionError(playerid);

	if(isnull(params))
	{
	    Usage(playerid, "/a (text)");
	    return true;
	}

    // Decide about multi-line msgs
	new i = -1;
	new line[512];
	if(strlen(params) > 70)
	{
		i = strfind(params, " ", false, 60);
		if(i > 80 || i == -1) i = 70;

		// store the second line text
		line = " ";
		strcat(line, params[i]);

		// delete the rest from msg
		params[i] = EOS;
	}
	new mstr[512];
	format(mstr, sizeof(mstr), "{FF3939}Admin Chat > {FFFFFF}%s | {A60000}%s {ffffff}[%i]: %s", GetStaffRank(playerid), pData[playerid][pAdminname], playerid, params);
	foreach(new ii : Player) 
	{
		if(pData[ii][pAdmin] > 0)
		{
			if(pData[playerid][pTogAdminchat] == 0)
			{
				SendClientMessage(ii, COLOR_WHITE, mstr);	
			}
		}
	}
	if(i != -1)
	{
		foreach(new ii : Player)
		{
			if(pData[ii][pAdmin] > 0)
			{
				if(pData[playerid][pTogAdminchat] == 0)
				{
					SendClientMessage(ii, COLOR_WHITE, line);
				}
			}
		}
	}
	return true;
}

CMD:togooc(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    if(TogOOC == 0)
    {
        SendClientMessageToAllEx(COLOR_RED, "{9A00FF}GLOBAL: {FFFFFF}Administrator {A60000}%s {FFFFFF}has disabled Global-OOC chat.", pData[playerid][pAdminname]);
        TogOOC = 1;
    }
    else
    {
        SendClientMessageToAllEx(COLOR_RED, "{9A00FF}GLOBAL: {FFFFFF}Administrator {A60000}%s {FFFFFF}has enabled Global-OOC chat.", pData[playerid][pAdminname]);
        SendClientMessageToAllEx(-1, "Use {FFFF00}'/o' {FFFFFF}to start chat");
        TogOOC = 0;
    }
    return 1;
}

CMD:o(playerid, params[])
{
    if(TogOOC == 1 && pData[playerid][pAdmin] < 1 && pData[playerid][pHelper] < 1) 
            return PermissionError(playerid);

    if(isnull(params))
        return Usage(playerid, "/o (text)");

    /*if(pData[playerid][pDisableOOC])
        return Error(playerid, "You must enable OOC chat first.");*/

    if(strlen(params) < 90)
    {
        foreach (new i : Player) if(pData[i][IsLoggedIn] == true && pData[i][pSpawned] == 1)
        {
            if(pData[playerid][pAdmin] == 1) SendClientMessageEx(i, COLOR_WHITE, "(( {FFFFFF}Trial Admin | {A60000}%s {FFFFFF}[%d]: %s {FFFFFF}))", pData[playerid][pAdminname], playerid, ColouredText(params));
            else if(pData[playerid][pAdmin] == 2) SendClientMessageEx(i, COLOR_WHITE, "(( {FFFFFF}Junior Admin | {A60000}%s {FFFFFF}[%d]: %s {FFFFFF}))", pData[playerid][pAdminname], playerid, ColouredText(params));
            else if(pData[playerid][pAdmin] == 3) SendClientMessageEx(i, COLOR_WHITE, "(( {FFFFFF}Senior Admin | {A60000}%s {FFFFFF}[%d]: %s {FFFFFF}))", pData[playerid][pAdminname], playerid, ColouredText(params));
            else if(pData[playerid][pAdmin] == 4) SendClientMessageEx(i, COLOR_WHITE, "(( {FFFFFF}Admin Management | {A60000}%s {FFFFFF}[%d]: %s {FFFFFF}))", pData[playerid][pAdminname], playerid, ColouredText(params));
            else if(pData[playerid][pAdmin] == 5) SendClientMessageEx(i, COLOR_WHITE, "(( {FFFFFF}Moderator | {A60000}%s {FFFFFF}[%d]: %s {FFFFFF}))", pData[playerid][pAdminname], playerid, ColouredText(params));
            else if(pData[playerid][pAdmin] == 6) SendClientMessageEx(i, COLOR_WHITE, "(( {FFFFFF}Founder | {A60000}%s {FFFFFF}[%d]: %s {FFFFFF}))", pData[playerid][pAdminname], playerid, ColouredText(params));
			else if(pData[playerid][pHelper] > 0 && pData[playerid][pAdmin] == 0)
			{
				SendClientMessageEx(i, COLOR_WHITE, "(( {FFFFFF}Helper | {A60000}%s {FFFFFF}[%d]: %s {FFFFFF}))", pData[playerid][pAdminname], playerid, ColouredText(params));
			}
            else
            {
                SendClientMessageEx(i, -1, "(( %s | %s [%d]: %s ))", GetLevelRank(playerid), pData[playerid][pName], playerid, params);
            }
        }
    }
    else
        return Error(playerid, "The text you entered is too long, a maximum of 90 characters.");

    return 1;
}

CMD:goto(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return PermissionError(playerid);
			
	new otherid;
	if(sscanf(params, "u", otherid))
        return Usage(playerid, "/id (PlayerID/PartOfName)");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "The player in question was not found");
		
	SendPlayerToPlayer(playerid, otherid);
	Servers(otherid, "Administrator {A60000}%s {FFFFFF}has used Teleportation {FFFFFF}on you", pData[playerid][pAdminname]);
	Servers(playerid, "You have Teleported to {FFFF00}%s", pData[otherid][pName]);
	return 1;
}

CMD:sendto(playerid, params[])
{
    static
        type[24],
		otherid;

    if(pData[playerid][pAdmin] < 2)
   		if(pData[playerid][pHelper] == 0)
     		return PermissionError(playerid);

    if(sscanf(params, "us[32]", otherid, type))
    {
        Usage(playerid, "/send [player] [name]");
        Names(playerid, "pelabuhan, stasiun, bandara, sapd, rs, balkot, bank");
        return 1;
    }
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player not connected!");

	if(!strcmp(type,"pelabuhan")) 
	{
        if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER) 
		{
            SetVehiclePos(GetPlayerVehicleID(otherid), 2770.2573, -2429.3826, 13.6947);
        }
        else 
		{
            SetPlayerPosition(otherid, 2770.2573, -2429.3826, 13.6947, 1.6703);
        }
        SetPlayerFacingAngle(otherid, 1.6703);
        SetPlayerInterior(otherid, 0);
        SetPlayerVirtualWorld(otherid, 0);
		Servers(playerid, "Anda telah mengirim %s ke {FFFF00}'Pelabuhan'", pData[otherid][pName]);
		Servers(otherid, "Administrator {A60000}%s {FFFF00}telah mengirim anda ke {FFFF00}Pelabuhan", pData[playerid][pAdminname]);
		pData[otherid][pInDoor] = -1;
		pData[otherid][pInHouse] = -1;
    }
    else if(!strcmp(type,"stasiun")) 
	{
        if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER) 
		{
            SetVehiclePos(GetPlayerVehicleID(otherid), 1744.2001, -1855.1138, 13.4141);
        }
        else 
		{
            SetPlayerPosition(otherid, 1744.2001, -1855.1138, 13.4141, 267.0034);
        }
        SetPlayerFacingAngle(otherid, 267.0034);
        SetPlayerInterior(otherid, 0);
        SetPlayerVirtualWorld(otherid, 0);
		Servers(playerid, "Anda telah mengirim %s ke {FFFF00}Stasiun", pData[otherid][pName]);
		Servers(otherid, "Administrator {A60000}%s {FFFF00}telah mengirim anda ke {FFFF00}Stasiun", pData[playerid][pAdminname]);
		pData[otherid][pInDoor] = -1;
		pData[otherid][pInHouse] = -1;
    }
    else if(!strcmp(type,"bandara")) 
	{
        if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER) 
		{
            SetVehiclePos(GetPlayerVehicleID(otherid), 1682.8878, -2319.7080, 13.3828);
        }
        else 
		{
            SetPlayerPosition(otherid, 1682.8878, -2319.7080, 13.3828, 88.5977);
        }
        SetPlayerFacingAngle(otherid, 88.5977);
        SetPlayerInterior(otherid, 0);
        SetPlayerVirtualWorld(otherid, 0);
		Servers(playerid, "Anda telah mengirim %s ke {FFFF00}Bandara", pData[otherid][pName]);
		Servers(otherid, "Administrator {A60000}%s {FFFF00}telah mengirim anda ke {FFFF00}Bandara", pData[playerid][pAdminname]);
		pData[otherid][pInDoor] = -1;
		pData[otherid][pInHouse] = -1;
		
    }
    else if(!strcmp(type,"sapd"))
	{
        if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER)
		{
            SetVehiclePos(GetPlayerVehicleID(otherid), 1546.55, -1669.18, 13.56);
        }
        else
		{
            SetPlayerPosition(otherid, 1546.55, -1669.18, 13.56, 750);
        }
        SetPlayerFacingAngle(otherid, 89.69);
        SetPlayerInterior(otherid, 0);
        SetPlayerVirtualWorld(otherid, 0);
		Servers(playerid, "Anda telah mengirim %s ke {FFFF00}Department Kepolisian", pData[otherid][pName]);
		Servers(otherid, "Administrator {A60000}%s {FFFF00}telah mengirim anda ke {FFFF00}Department Kepolisian", pData[playerid][pAdminname]);
		pData[otherid][pInDoor] = -1;
		pData[otherid][pInHouse] = -1;
		
    }
    else if(!strcmp(type,"rs"))
	{
        if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER)
		{
            SetVehiclePos(GetPlayerVehicleID(otherid), 1183.89, -1333.06, 13.58);
        }
        else
		{
            SetPlayerPosition(otherid, 1183.89, -1333.06, 13.58, 750);
        }
        SetPlayerFacingAngle(otherid, 272.36);
        SetPlayerInterior(otherid, 0);
        SetPlayerVirtualWorld(otherid, 0);
		Servers(playerid, "Anda telah mengirim %s ke {FFFF00}Rumah Sakit", pData[otherid][pName]);
		Servers(otherid, "Administrator {A60000}%s {FFFF00}telah mengirim anda ke {FFFF00}Rumah Sakit", pData[playerid][pAdminname]);
		pData[otherid][pInDoor] = -1;
		pData[otherid][pInHouse] = -1;
		
    }
    else if(!strcmp(type,"balkot"))
	{
        if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER)
		{
            SetVehiclePos(GetPlayerVehicleID(otherid), 1476.68, -1738.55, 13.54);
        }
        else
		{
            SetPlayerPosition(otherid, 1476.68, -1738.55, 13.54, 750);
        }
        SetPlayerFacingAngle(otherid, 1.29);
        SetPlayerInterior(otherid, 0);
        SetPlayerVirtualWorld(otherid, 0);
		Servers(playerid, "Anda telah mengirim %s ke {FFFF00}Balai Kota", pData[otherid][pName]);
		Servers(otherid, "Administrator {A60000}%s {FFFF00}telah mengirim anda ke {FFFF00}Balai Kota", pData[playerid][pAdminname]);
		pData[otherid][pInDoor] = -1;
		pData[otherid][pInHouse] = -1;
		
    }
    else if(!strcmp(type,"bank"))
	{
        if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER)
		{
            SetVehiclePos(GetPlayerVehicleID(otherid), 1451.57, -1026.37, 23.82);
        }
        else
		{
            SetPlayerPosition(otherid, 1451.57, -1026.37, 23.82, 750);
        }
        SetPlayerFacingAngle(otherid, 170.87);
        SetPlayerInterior(otherid, 0);
        SetPlayerVirtualWorld(otherid, 0);
		Servers(playerid, "Anda telah mengirim %s ke {FFFF00}Bank", pData[otherid][pName]);
		Servers(otherid, "Administrator {A60000}%s {FFFF00}telah mengirim anda ke {FFFF00}Bank", pData[playerid][pAdminname]);
		pData[otherid][pInDoor] = -1;
		pData[otherid][pInHouse] = -1;
		
	}
    return 1;
}

CMD:gethere(playerid, params[])
{
    new otherid;

	if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return PermissionError(playerid);
			
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/gethere (PlayerID/PartOfName)");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");
	
	if(pData[playerid][pSpawned] == 0 || pData[otherid][pSpawned] == 0)
		return Error(playerid, "Player yang di maksud belum melakukan Spawn");
		
	if(pData[playerid][pJail] > 0 || pData[otherid][pJail] > 0)
		return Error(playerid, "Player yang di maksud sedang di Jail");
		
	if(pData[playerid][pArrest] > 0 || pData[otherid][pArrest] > 0)
		return Error(playerid, "Player yang di maksud sedang dalam status Arrested");

	if(pData[playerid][pAdmin] < pData[otherid][pAdmin] > 0)
		return Error(playerid, "Anda tidak dapat menarik Administrator dengan Rank di atas anda");

    SendPlayerToPlayer(otherid, playerid);

    Servers(playerid, "Anda telah menarik %s", pData[otherid][pName]);
    Servers(otherid, "Administrator {A60000}%s {FFFFFF}telah menarik anda.", pData[playerid][pName]);
    return 1;
}

CMD:freeze(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return PermissionError(playerid);
			
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/freeze (PlayerID/PartOfName)");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

    pData[playerid][pFreeze] = 1;

    TogglePlayerControllable(otherid, 0);
    Servers(playerid, "Anda telah menggunakan {FFFF00}'/freeze' {FFFFFF}kepada %s", ReturnName(otherid));
	Servers(otherid, "Administrator {A60000}%s {FFFFFF}telah menggunakan {FFFF00}'/freeze' {FFFFFF}kepada anda", pData[playerid][pAdminname]);
    return 1;
}

CMD:unfreeze(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return PermissionError(playerid);
			
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/freeze (PlayerID/PartOfName)");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

    pData[playerid][pFreeze] = 0;

    TogglePlayerControllable(otherid, 1);
    Servers(playerid, "Anda telah menggunakan {FFFF00}'/unfreeze' {FFFFFF}kepada %s", ReturnName(otherid));
	Servers(otherid, "Administrator {A60000}%s {FFFFFF}telah menggunakan {FFFF00}'/unfreeze' {FFFFFF}kepada anda", pData[playerid][pAdminname]);
    return 1;
}

CMD:arevive(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
        if(pData[playerid][pHelper] < 2)
            return PermissionError(playerid);
    
    new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/revive (PlayerID/PartOfName)");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");

    if(!pData[otherid][pInjured])
        return Error(playerid, "Tidak bisa revive karena tidak injured.");

    pData[otherid][pInjured] = 0;
    pData[otherid][pHospital] = 0;
    pData[otherid][pSick] = 0;
    pData[otherid][pHead] = 100;
    pData[otherid][pPerut] = 100;
    pData[otherid][pRHand] = 100;
    pData[otherid][pLHand] = 100;
    pData[otherid][pRFoot] = 100;
    pData[otherid][pLFoot] = 100;

    SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);
    clearAnimations(otherid);
    StopLoopingAnim(otherid);
    TogglePlayerControllable(otherid, 1);
    HideTDdeath(otherid);
    Toggleaccdeath[otherid] = 0;

    SetPlayerHealthEx(otherid, 100.0);
    SendStaffMessage(COLOR_RED, "{A60000}%s {FFFFFF}telah menggunakan {FFFF00}'/arevive' {FFFFFF}kepada %s.", pData[playerid][pAdminname], ReturnName(otherid));
    Info(otherid, "Administrator {A60000}%s {FFFFFF}telah menghidupkan kembali karakter anda.", pData[playerid][pAdminname]);
    return 1;
}

CMD:areviveall(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);

	foreach(new pid : Player)
	{
		if(pid != INVALID_PLAYER_ID)
		{
			if(pData[pid][pInjured])
			{
				SetPlayerHealthEx(pid, 100);
			    pData[pid][pInjured] = 0;
				pData[pid][pHospital] = 0;
				pData[pid][pSick] = 0;
			    clearAnimations(pid);
				StopLoopingAnim(pid);
				SetPlayerSpecialAction(pid, SPECIAL_ACTION_NONE);
				HideTDdeath(pid);
			    Servers(pid, "[%s] Revive all player", pData[playerid][pAdminname]);
        		SendAdminMessage(COLOR_RED, "%s revive all for player", pData[playerid][pAdminname]);
			}
		}
	}
	return 1;
}


CMD:sethbeall(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
	new string[500];
	foreach(new pid : Player)
	{
		if(pid != INVALID_PLAYER_ID)
		{
			if(IsPlayerConnected(pid))
			{
				pData[pid][pHunger] = 100;
				pData[pid][pEnergy] = 100;
				pData[pid][pStress] = 0;
			}
		}
	}
	format(string, sizeof(string), "Administrator {A60000}%s {FFFFFF}telah melakukan reset {FFFF00}'HBE' {FFFFFF}kepada semua player.", pData[playerid][pAdminname]);
	va_SendClientMessageToAll(-1, string);
	return 1;
}

CMD:spec(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] < 2)
			return PermissionError(playerid);

    if(!isnull(params) && !strcmp(params, "off", true))
    {
        if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING)
            return Error(playerid, "Anda tidak melakukan Spectating kepada player manapun.");

		pData[pData[playerid][pSpec]][playerSpectated]--;
        PlayerSpectatePlayer(playerid, INVALID_PLAYER_ID);
        PlayerSpectateVehicle(playerid, INVALID_VEHICLE_ID);

        SetSpawnInfo(playerid, 0, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
        TogglePlayerSpectating(playerid, false);
		pData[playerid][pSpec] = -1;

        return Info(playerid, "Anda keluar dari mode Spectator.");
    }
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/spec (playerid/PartOfName) | Gunakan {FFFF00}'/spec off' {FFFFFF}untuk menonaktifkan Spectator Mode.");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan.");
		
	if(otherid == playerid)
		return Error(playerid, "Anda tidak dapat melakukan Spectating pada diri sendiri.");

    if(pData[playerid][pAdmin] < pData[otherid][pAdmin])
        return Error(playerid, "Anda tidak dapat melakukan Spectating pada admin dengan Rank di atas anda.");
		
	if(pData[otherid][pSpawned] == 0)
	{
	    Error(playerid, "%s [%i] | Belum melakukan Spawn", pData[otherid][pName], otherid);
	    return true;
	}

    if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING)
    {
        GetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
        GetPlayerFacingAngle(playerid, pData[playerid][pPosA]);

        pData[playerid][pInt] = GetPlayerInterior(playerid);
        pData[playerid][pWorld] = GetPlayerVirtualWorld(playerid);
    }
    SetPlayerInterior(playerid, GetPlayerInterior(otherid));
    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(otherid));

    TogglePlayerSpectating(playerid, true);

    if(IsPlayerInAnyVehicle(otherid))
	{
		new vID = GetPlayerVehicleID(otherid);
        PlayerSpectateVehicle(playerid, GetPlayerVehicleID(otherid));
		if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER)
	    {
	    	Servers(playerid, "Posisi Spectator pada player %s(%i) anda di ubah ke mode Driving pada %s(%d).", pData[otherid][pName], otherid, GetVehicleModelName(GetVehicleModel(vID)), vID);
		}
		else
		{
		    Servers(playerid, "Posisi Spectator pada player %s(%i) anda di ubah ke mode Pessagger pada %s(%d).", pData[otherid][pName], otherid, GetVehicleModelName(GetVehicleModel(vID)), vID);
		}
	}
    else
	{
        PlayerSpectatePlayer(playerid, otherid);
	}
	pData[otherid][playerSpectated]++;
    SendStaffMessage(COLOR_RED, "{A60000}%s {FFFFFF}telah menggunakan {FFFF00}'/spec' {FFFFFF}kepada %s [ID:%d].", pData[playerid][pAdminname], pData[otherid][pName], otherid);
    Servers(playerid, "Anda telah melakukan Spectating kepada %s [ID: %d]", pData[otherid][pName], otherid);
    pData[playerid][pSpec] = otherid;
    return 1;
}

CMD:overdosespec(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] < 2)
			return PermissionError(playerid);

    if(!isnull(params) && !strcmp(params, "off", true))
    {
        if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING)
            return Error(playerid, "Anda tidak melakukan Spectating kepada player manapun.");

		pData[pData[playerid][pSpec]][playerSpectated]--;
        PlayerSpectatePlayer(playerid, INVALID_PLAYER_ID);
        PlayerSpectateVehicle(playerid, INVALID_VEHICLE_ID);

        SetSpawnInfo(playerid, 0, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
        TogglePlayerSpectating(playerid, false);
		pData[playerid][pSpec] = -1;

        return Info(playerid, "Anda keluar dari mode Spectator.");
    }
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/overdosespec (playerid/PartOfName) | Gunakan {FFFF00}'/spec off' {FFFFFF}untuk menonaktifkan Spectator Mode.");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");
		
	if(otherid == playerid)
		return Error(playerid, "Anda tidak dapat mengunakan Spectator pada diri sendiri");
		
	if(pData[otherid][pSpawned] == 0)
	{
	    Error(playerid, "%s [%i] | Belum melakukan Spawn", pData[otherid][pName], otherid);
	    return true;
	}

    if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING)
    {
        GetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
        GetPlayerFacingAngle(playerid, pData[playerid][pPosA]);

        pData[playerid][pInt] = GetPlayerInterior(playerid);
        pData[playerid][pWorld] = GetPlayerVirtualWorld(playerid);
    }
    SetPlayerInterior(playerid, GetPlayerInterior(otherid));
    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(otherid));

    TogglePlayerSpectating(playerid, true);

    if(IsPlayerInAnyVehicle(otherid))
	{
		new vID = GetPlayerVehicleID(otherid);
        PlayerSpectateVehicle(playerid, GetPlayerVehicleID(otherid));
		if(GetPlayerState(otherid) == PLAYER_STATE_DRIVER)
	    {
	    	Servers(playerid, "Posisi Spectator pada player %s(%i) anda di ubah ke mode Driving pada %s(%d).", pData[otherid][pName], otherid, GetVehicleModelName(GetVehicleModel(vID)), vID);
		}
		else
		{
		    Servers(playerid, "Posisi Spectator pada player %s(%i) anda di ubah ke mode Pessagger pada %s(%d).", pData[otherid][pName], otherid, GetVehicleModelName(GetVehicleModel(vID)), vID);
		}
	}
    else
	{
        PlayerSpectatePlayer(playerid, otherid);
	}
	pData[otherid][playerSpectated]++;
    pData[playerid][pSpec] = otherid;
    return 1;
}

CMD:slap(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] == 0)
			return PermissionError(playerid);
			
	new Float:POS[3], otherid;
	if(sscanf(params, "u", otherid))
	{
	    Usage(playerid, "/slap (PlayerID)");
	    return true;
	}

	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

	GetPlayerPos(otherid, POS[0], POS[1], POS[2]);
	SetPlayerPos(otherid, POS[0], POS[1], POS[2] + 9.0);
	if(IsPlayerInAnyVehicle(otherid)) 
	{
		RemovePlayerFromVehicle(otherid);
		//OnPlayerExitVehicle(otherid, GetPlayerVehicleID(otherid));
	}
	SendStaffMessage(COLOR_RED, "{A60000}%s {FFFFFF}telah menggunakan {FFFF00}'/slap' {FFFFFF}kepada %s", pData[playerid][pAdminname], pData[otherid][pName]);

	PlayerPlaySound(otherid, 1130, 0.0, 0.0, 0.0);
	return 1;
}

CMD:peject(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] < 2)
			return PermissionError(playerid);
	new otherid;
	if(sscanf(params, "u", otherid))
	{
	    Usage(playerid, "/peject (PlayerID)");
	    return 1;
	}

	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

	if(!IsPlayerInAnyVehicle(otherid))
	{
		Error(playerid, "Player tersebut sedang tidak di dalam kendaraan");
		return 1;
	}

	new vv = GetVehicleModel(GetPlayerVehicleID(otherid));
	Servers(playerid, "Anda telah melakukan {FFFF00}'/peject' {FFFFFF}kepada %s(%i) dari kendaraan %s.", pData[otherid][pName], otherid, GetVehicleModelName(vv - 400));
	Servers(otherid, "Administrator {A60000}%s {FFFFFF}telah mengeluarkan anda dari kendaraan %s.", pData[playerid][pAdminname], GetVehicleModelName(vv));
	RemovePlayerFromVehicle(otherid);
	return 1;
}

CMD:aitems(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] < 2)
			return PermissionError(playerid);
			
	new otherid;
	if(sscanf(params, "u", otherid))
        return Usage(playerid, "/aitems [playerid/PartOfName]");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");

	if(pData[otherid][IsLoggedIn] == false)
        return Error(playerid, "That player is not logged in yet.");
		
	//DisplayItems(playerid, otherid);
	ShowInventoryFrisk(playerid, otherid);
	return 1;
}

CMD:astats(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] < 2)
			return PermissionError(playerid);
	new otherid;
	if(sscanf(params, "u", otherid))
        return Usage(playerid, "/check (PlayerID/PartOfName)");
		
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

	if(pData[otherid][IsLoggedIn] == false)
        return Error(playerid, "Player tersebut belum melakukan Login");

	DisplayStats(playerid, otherid);
	return 1;
}

CMD:ostats(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] < 2)
			return PermissionError(playerid);
			
	new name[24], PlayerName[24];
	if(sscanf(params, "s[24]", name))
	{
	    Usage(playerid, "/ostats (player name)");
 		return 1;
 	}

 	foreach(new ii : Player)
	{
		GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

		if(!strcmp(PlayerName, name, true))
		{
			Error(playerid, "Player tersebut sedang online, anda bisa menggunakan {FFFF00}'/astats'");
	  		return 1;
	  	}
	}

	// Load User Data
    new cVar[500];
    new cQuery[600];

	strcat(cVar, "email,admin,helper,level,levelup,vip,vip_time,gold,reg_date,last_login,money,bmoney,brek,hours,minutes,seconds,");
	strcat(cVar, "gender,age,faction,family,warn,job,job2,interior,world");

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "SELECT %s FROM players WHERE username='%e' LIMIT 1", cVar, name);
	mysql_tquery(g_SQL, cQuery, "LoadStats", "is", playerid, name);
	return true;
}

CMD:acuff(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return PermissionError(playerid);
			
	new otherid;		
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/acuff (PlayerID/PartOfName)");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

    if(GetPlayerState(otherid) != PLAYER_STATE_ONFOOT)
        return Error(playerid, "Player tersebut harus dalam mode {FFFF00}'ON-FOOT' {FFFFFF}sebelum di Cuff");

    if(pData[otherid][pCuffed])
        return Error(playerid, "Player tersebut sedang dalam keadaan Cuffed");

    pData[otherid][pCuffed] = 1;
	SetPlayerSpecialAction(otherid, SPECIAL_ACTION_CUFFED);

    Servers(playerid, "Anda telah menggunakan {FFFF00}'/acuff' {FFFFFF}kepada %s", pData[otherid][pName]);
    Servers(otherid, "Administrator {A60000}%s {FFFFFF}telah menggunakan {FFFF00}'/acuff' {FFFFFF}kepada anda.", pData[playerid][pName]);
    return 1;
}

CMD:auncuff(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] == 0)
     		return PermissionError(playerid);
			
	new otherid;		
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/auncuff [PlayerID/PartOfName]");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang anda maksud tidak di temukan");

    if(!pData[otherid][pCuffed])
        return Error(playerid, "Player tersebut tidak dalam mode Cuffed");

    pData[otherid][pCuffed] = 0;
    SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);

	Servers(playerid, "Anda telah menggunakan {FFFF00}'/auncuff' {FFFFFF}kepada %s", pData[otherid][pName]);
    Servers(otherid, "Administrator {A60000}%s {FFFFFF}telah menggunakan {FFFF00}'/auncuff' {FFFFFF}kepada anda.", pData[playerid][pName]);
    return 1;
}

CMD:jetpack(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] < 2)
     		return PermissionError(playerid);
			
	new otherid;		
    if(sscanf(params, "u", otherid))
    {
        //pData[playerid][pJetpack] = 1;
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USEJETPACK);
    }
    else
    {
        //pData[playerid][pJetpack] = 1;
        SetPlayerSpecialAction(otherid, SPECIAL_ACTION_USEJETPACK);
        Servers(playerid, "You have spawned a jetpack for %s.", pData[otherid][pName]);
    }
    return 1;
}

CMD:getip(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
     	return PermissionError(playerid);
		
	new otherid, PlayerIP[16], giveplayer[24];
	if(sscanf(params, "u", otherid))
 	{
  		Usage(playerid, "/getip (PlayerID)");
		return 1;
	}
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");
		
	if(pData[otherid][pAdmin] == 5)
 	{
  		Error(playerid, "Anda tidak dapat menggunakan {FFFF00}'/getip' {FFFFFF}pada Owner");
  		Servers(otherid, "Administrator {A60000}%s {FFFFFF}mencoba mendapatkan IP anda", pData[playerid][pAdminname]);
  		return 1;
    }
	GetPlayerName(otherid, giveplayer, sizeof(giveplayer));
	GetPlayerIp(otherid, PlayerIP, sizeof(PlayerIP));

	Servers(playerid, "%s(%i)'s IP: %s", giveplayer, otherid, PlayerIP);
	return 1;
}

CMD:aka(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
     	return PermissionError(playerid);
	new otherid, PlayerIP[16], query[128];
	if(sscanf(params, "u", otherid))
	{
	    Usage(playerid, "/aka <ID/Name>");
	    return true;
	}
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
		
	if(pData[otherid][pAdmin] == 5)
 	{
  		Error(playerid, "You can't AKA the server owner!");
  		Servers(otherid, "%s(%i) tried to AKA you!", pData[playerid][pName], playerid);
  		return 1;
    }
	GetPlayerIp(otherid, PlayerIP, sizeof(PlayerIP));
	mysql_format(g_SQL, query, sizeof(query), "SELECT username FROM players WHERE IP='%s'", PlayerIP);
	mysql_tquery(g_SQL, query, "CheckPlayerIP", "is", playerid, PlayerIP);
	return true;
}

CMD:akaip(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
     	return PermissionError(playerid);
	new query[128];
	if(isnull(params))
	{
	    Usage(playerid, "/akaip <IP>");
		return true;
	}

	mysql_format(g_SQL, query, sizeof(query), "SELECT username FROM players WHERE IP='%s'", params);
	mysql_tquery(g_SQL, query, "CheckPlayerIP2", "is", playerid, params);
	return true;
}

CMD:vmodels(playerid, params[])
{
    new string[3500];

    if(pData[playerid][pAdmin] < 1)
     	return PermissionError(playerid);

    for (new i = 0; i < sizeof(g_arrVehicleNames); i ++)
    {
        format(string,sizeof(string), "%s%d - %s\n", string, i+400, g_arrVehicleNames[i]);
    }
    ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_LIST, "Vehicle Models", string, "Close", "");
    return 1;
}

CMD:vehname(playerid, params[]) {

	if(pData[playerid][pAdmin] >= 1) 
	{
		SendClientMessageEx(playerid, COLOR_YELLOW, "--------------------------------------------------------------------------------------------------------------------------------");
		SendClientMessageEx(playerid, COLOR_WHITE, "Vehicle Search:");

		new
			string[128];

		if(isnull(params)) return Error(playerid, "No keyword specified.");
		if(!params[2]) return Error(playerid, "Search keyword too short.");

		for(new v; v < sizeof(g_arrVehicleNames); v++) 
		{
			if(strfind(g_arrVehicleNames[v], params, true) != -1) {

				if(isnull(string)) format(string, sizeof(string), "%s (ID %d)", g_arrVehicleNames[v], v+400);
				else format(string, sizeof(string), "%s | %s (ID %d)", string, g_arrVehicleNames[v], v+400);
			}
		}

		if(!string[0]) Error(playerid, "No results found.");
		else if(string[127]) Error(playerid, "Too many results found.");
		else SendClientMessageEx(playerid, COLOR_WHITE, string);

		SendClientMessageEx(playerid, COLOR_YELLOW, "--------------------------------------------------------------------------------------------------------------------------------");
	}
	else
	{
		PermissionError(playerid);
	}
	return 1;
}

CMD:owarn(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
	    return PermissionError(playerid);
	
	new player[24], tmp[50], PlayerName[MAX_PLAYER_NAME];
	if(sscanf(params, "s[24]s[50]", player, tmp))
		return Usage(playerid, "/owarn <name> <reason>");

	if(strlen(tmp) > 50) return Error(playerid, "Tidak dapat menginput lebih dari 50 kata");

	foreach(new ii : Player)
	{
		GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

	    if(strfind(PlayerName, player, true) != -1)
		{
			Error(playerid, "Player tersebut sedang online, anda bisa menggunakan {FFFF00}'/warn'");
	  		return 1;
	  	}
	}
	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "SELECT reg_id,warn FROM players WHERE username='%e'", player);
	mysql_tquery(g_SQL, query, "OWarnPlayer", "iss", playerid, player, tmp);
	return 1;
}

function OWarnPlayer(adminid, NameToWarn[], warnReason[])
{
	if(cache_num_rows() < 1)
	{
		return Error(adminid, "Account {ffff00}'%s' "WHITE_E"does not exist.", NameToWarn);
	}
	else
	{
	    new RegID, warn;
		cache_get_value_index_int(0, 0, RegID);
		cache_get_value_index_int(0, 1, warn);
		SendClientMessageToAllEx(-1, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah memberi warning {9C9C9C}'Offline' {FFFFFF}kepada player %s.", pData[adminid][pAdminname], NameToWarn);
		SendClientMessageToAllEx(-1, "~> {FF0000}%s", warnReason);
		new query[512];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET warn=%d WHERE reg_id=%d", warn+1, RegID);
		mysql_tquery(g_SQL, query);
	}
	return 1;
}

CMD:ojail(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
	    return PermissionError(playerid);

	new player[24], datez, tmp[50], PlayerName[MAX_PLAYER_NAME];
	if(sscanf(params, "s[24]ds[50]", player, datez, tmp))
		return Usage(playerid, "/ojail (name) (time in minutes) (reason)");

	if(strlen(tmp) > 50) return Error(playerid, "Reason yang anda masukan tidak boleh lebih dari 50 karakter");
	if(datez < 1 || datez > 60)
	{
 		if(pData[playerid][pAdmin] < 5)
   		{
			Error(playerid, "Waktu Jail yang di masukan minimal 1 sampai 60 menit");
  			return 1;
   		}
	}
	foreach(new ii : Player)
	{
		GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

	    if(strfind(PlayerName, player, true) != -1)
		{
			Error(playerid, "Player tersebut sedang online, gunakan {FFFF00}'/jail'");
	  		return 1;
	  	}
	}
	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "SELECT reg_id FROM players WHERE username='%e'", player);
	mysql_tquery(g_SQL, query, "OJailPlayer", "issi", playerid, player, tmp, datez);
	return 1;
}

function OJailPlayer(adminid, NameToJail[], jailReason[], jailTime)
{
	if(cache_num_rows() < 1)
	{
		return Error(adminid, "Account {ffff00}'%s' "WHITE_E"tidak di temukan", NameToJail);
	}
	else
	{
	    new RegID, JailMinutes = jailTime * 60;
		cache_get_value_index_int(0, 0, RegID);

		SendClientMessageToAllEx(-1, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah menjail {9C9C9C}'Offline' {FFFFFF}kepada player %s selama %d menit.", pData[adminid][pAdminname], NameToJail, jailTime);
		SendClientMessageToAllEx(-1, "~> {FFFF00}%s", jailReason);
		new query[512];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET jail=%d WHERE reg_id=%d", JailMinutes, RegID);
		mysql_tquery(g_SQL, query);
	}
	return 1;
}

CMD:jail(playerid, params[])
{
   	if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] < 2)
     		return PermissionError(playerid);

	new reason[60], timeSec, otherid;
	if(sscanf(params, "uD(15)S(*)[60]", otherid, timeSec, reason))
	{
	    Usage(playerid, "/jail (PlayerID/Name) (time in minutes) (reason)");
	    return true;
	}

	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

	if(pData[otherid][pJail] > 0)
	{
	    Servers(playerid, "%s(%i) sedang dalam mode Jailed (%d Menit)", pData[otherid][pName], otherid, pData[otherid][pJailTime]);
	    Usage(playerid, "/unjail (PlayerID/Name) | untuk mengeluarkan player dari penjara");
	    return true;
	}
	if(pData[otherid][pSpawned] == 0)
	{
	    Error(playerid, "%s [%i] | Belum melakukan Spawn", pData[otherid][pName], otherid);
	    return true;
	}
	if(reason[0] != '*' && strlen(reason) > 60)
	{
	 	Error(playerid, "Reason yang anda masukan tidak boleh lebih dari 60 karakter");
	   	return true;
	}
	if(timeSec < 1 || timeSec > 60)
	{
	    if(pData[playerid][pAdmin] < 5)
	 	{
			Error(playerid, "Waktu Jail yang di masukan minimal 1 sampai 60 menit");
	    	return 1;
	  	}
	}
	pData[otherid][pJail] = 1;
	pData[otherid][pJailTime] = timeSec * 60;
	JailPlayer(otherid);
	if(reason[0] == '*')
	{
		SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah memasukan player %s kedalam penjara selama %d menit.", pData[playerid][pAdminname], pData[otherid][pName], timeSec);
	}
	else
	{
		SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah memasukan player %s kedalam penjara selama %d menit.", pData[playerid][pAdminname], pData[otherid][pName], timeSec);
		SendClientMessageToAllEx(-1, "~> {FFFF00}%s", reason);
	}
	return 1;
}


CMD:unjail(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
   		if(pData[playerid][pHelper] < 2)
     		return PermissionError(playerid);

	new otherid;
	if(sscanf(params, "u", otherid))
	{
	    Usage(playerid, "/unjail (ID/Name)");
	    return true;
	}

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

	if(pData[otherid][pJail] == 0)
	    return Error(playerid, "Player tersebut sedang tidak dalam keadaan Jailed");

	pData[otherid][pJail] = 0;
	pData[otherid][pJailTime] = 0;
	PlayerTextDrawHide(otherid, Time[playerid][0]);
	SetPlayerInterior(otherid, 0);
	SetPlayerVirtualWorld(otherid, 0);
	SetPlayerPos(otherid, 1546.55, -1669.18, 13.56);
	SetPlayerFacingAngle(otherid, 89.69);
	SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);
	SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah mengeluarkan %s dari penjara", pData[playerid][pAdminname], pData[otherid][pName]);
	return true;
}

CMD:kick(playerid, params[])
{
    static
        reason[128];

	if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] == 0)
			return PermissionError(playerid);
			
	new otherid;
    if(sscanf(params, "us[128]", otherid, reason))
        return Usage(playerid, "/kick (playerid/PartOfName) (reason)");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

    if(pData[otherid][pAdmin] > pData[playerid][pAdmin])
        return Error(playerid, "Anda tidak dapat melakukan Kick pada admin dengan Rank di atas anda.");

    SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {FFFF00}%s {FFFFFF}telah di kick oleh {A60000}%s", pData[otherid][pName], pData[playerid][pAdminname]);
    SendClientMessageToAllEx(-1, "~> {FFFF00}%s", reason);
    //Log_Write("logs/kick_log.txt", "[%s] %s has kicked %s for: %s.", ReturnTime(), ReturnName(otherid, 0), ReturnName(otherid, 0), reason);
	//SetPlayerPosition(otherid, 227.46, 110.0, 999.02, 360.0000, 10);
    KickEx(otherid);
    return 1;
}

CMD:ban(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
			return PermissionError(playerid);

	new ban_time, datez, tmp[60], otherid;
	if(sscanf(params, "uds[60]", otherid, datez, tmp))
	{
	    Usage(playerid, "/ban (ID/Name) <waktu (hari), 0 untuk permanent> (reason) ");
	    return true;
	}
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");
	
 	if(datez < 0) Error(playerid, "Masukan waktu Banned dengan benar");
	if(pData[playerid][pAdmin] < 2)
	{
		if(datez > 30 || datez <= 0) return Error(playerid, "Anda hanya dapat Banned selama 1-30 hari");
	}
	/*if(otherid == playerid)
	    return Error(playerid, "You are not able to ban yourself!");*/
	if(pData[otherid][pAdmin] > pData[playerid][pAdmin])
	{
		Servers(otherid, "Administrator {A60000}%s {FFFFFF}mencoba melakukan Banned kepada anda", pData[playerid][pAdminname]);
 		Error(playerid, "Anda tidak dapat melakukan Banned kepada admin dengan Rank di atas anda.");
 		return true;
   	}
	new PlayerIP[16], giveplayer[24];
	
   	//SetPlayerPosition(otherid, 405.1100,2474.0784,35.7369,360.0000);
	GetPlayerName(otherid, giveplayer, sizeof(giveplayer));
	GetPlayerIp(otherid, PlayerIP, sizeof(PlayerIP));

	if(!strcmp(tmp, "ab", true)) tmp = "Airbreak";
	else if(!strcmp(tmp, "ad", true)) tmp = "Advertising";
	else if(!strcmp(tmp, "ads", true)) tmp = "Advertising";
	else if(!strcmp(tmp, "hh", true)) tmp = "Health Hacks";
	else if(!strcmp(tmp, "wh", true)) tmp = "Weapon Hacks";
	else if(!strcmp(tmp, "sh", true)) tmp = "Speed Hacks";
	else if(!strcmp(tmp, "mh", true)) tmp = "Money Hacks";
	else if(!strcmp(tmp, "rh", true)) tmp = "Ram Hacks";
	else if(!strcmp(tmp, "ah", true)) tmp = "Ammo Hacks";
	if(datez != 0)
	{
		SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah menggunakan '/ban' kepada player %s selama %d hari.", pData[playerid][pAdminname], giveplayer, datez);
		SendClientMessageToAllEx(-1, "~> {FFFF00}%s", tmp);
	}
	else
	{
		SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah menggunakan '/ban' kepada player %s (Permanent).", pData[playerid][pAdminname], giveplayer);
		SendClientMessageToAllEx(-1, "~> {FFFF00}%s", tmp);
	}
	//SetPlayerPosition(otherid, 227.46, 110.0, 999.02, 360.0000, 10);
	BanPlayerMSG(otherid, playerid, tmp);
 	if(datez != 0)
    {
		Servers(otherid, "Ini adalah Temporary Banned yang akan kadaluarsa dalam %d hari", datez);
		ban_time = gettime() + (datez * 86400);
	}
	else
	{
		Servers(otherid, "Administrator telah melakukan banned selama %d kepada anda, kontak Administrator untuk info lebih lanjut.", datez);
		ban_time = datez;
	}
	new query[248];
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO banneds(name, ip, admin, reason, ban_date, ban_expire) VALUES ('%s', '%s', '%s', '%s', %i, %d)", giveplayer, PlayerIP, pData[playerid][pAdminname], tmp, gettime(), ban_time);
	mysql_tquery(g_SQL, query);
	KickEx(otherid);
	return true;
}

CMD:unban(playerid, params[])
{
   	if(pData[playerid][pAdmin] < 1)
			return PermissionError(playerid);
	
	new tmp[24];
	if(sscanf(params, "s[24]", tmp))
	{
	    Usage(playerid, "/unban (Player Name)");
	    return true;
	}

	SendStaffMessage(-1, "{A60000}%s {FFFFFF}telah menggunakan {FFFF00}'/unban' {FFFFFF}kepada player %s", tmp);
	
	new query[128];
	mysql_format(g_SQL, query, sizeof(query), "SELECT name,ip FROM banneds WHERE name = '%e'", tmp);
	mysql_tquery(g_SQL, query, "OnUnbanQueryData", "is", playerid, tmp);
	return 1;
}

function OnUnbanQueryData(adminid, BannedName[])
{
	if(cache_num_rows() > 0)
	{
		new banIP[16], query[128];
		cache_get_value_name(0, "ip", banIP);
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM banneds WHERE ip = '%s'", banIP);
		mysql_tquery(g_SQL, query);

		SendClientMessageToAllEx(-1, "{00A2FF}SERVER: {FFFF00}%s {FFFFFF}telah di unbanned oleh {A60000}%s dari server", BannedName, pData[adminid][pAdminname]);
	}
	else
	{
		Error(adminid, "Tidak ada nama %s di temukan di list", BannedName);
	}
	return 1;
}

CMD:warn(playerid, params[])
{
    static
        reason[32];

    if(pData[playerid][pAdmin] < 1)
        if(pData[playerid][pHelper] < 3)
			return PermissionError(playerid);
	new otherid;
    if(sscanf(params, "us[32]", otherid, reason))
        return Usage(playerid, "/warn (playerid/PartOfName) (reason)");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

    if(pData[otherid][pAdmin] > pData[playerid][pAdmin])
        return Error(playerid, "Anda tidak dapat menggunakan warn pada Admin dengan rank di atas anda");

	pData[otherid][pWarn]++;
	SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah memberikan Warning kepada player %s.", pData[playerid][pAdminname], pData[otherid][pName]);
    SendClientMessageToAllEx(-1, "~> {FFFF00}%s {FFFFFF}| {FFFF00}Total Warning {FFFFFF}[%d/20]", reason, pData[otherid][pWarn]);
    return 1;
}

CMD:unwarn(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] < 3)
			return PermissionError(playerid);
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/unwarn (playerid/PartOfName)");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak di temukan");

    pData[otherid][pWarn] -= 1;
    Servers(playerid, "Anda telah mengurangi Warns pada player %s", pData[otherid][pName]);
	Servers(otherid, "Administrator {A60000}%s {FFFFFF}telah mengurangi Warns anda", pData[playerid][pAdminname]);
    SendStaffMessage(COLOR_RED, "{A60000}%s {FFFFFF}telah mengurangi Warning pada player %s", pData[playerid][pAdminname], pData[otherid][pName]);
    return 1;
}

/*CMD:respawnfveh(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
		return PermissionError(playerid);
	
	new facname[128];
	if(sscanf(params, "s[128]", facname))
	{
		Usage(playerid, "/respawnfveh [names]");
		Names(playerid, "sapd, sags, samd, sana");
		return 1;
	}

	if(!strcmp(facname, "sapd", true))
	{
		for(new i = 0; i < MAX_FACTIONVEH; i++)
		{
			if(Iter_Contains(FactionVeh, i))
			{
				if(fvData[i][fvFaction] == 1)
				{
					if(IsVehicleEmpty(fvData[i][fvVeh]))
					{
						Delete3DTextLabel(fvData[i][fvLabel]);
						fvData[i][fvLabel] = Text3D: -1;
						
						if(IsValidVehicle(fvData[i][fvVeh]))
							DestroyVehicle(fvData[i][fvVeh]);

						fvData[i][fvVeh] = 0;
						fvData[i][fvFaction] = 0;
						
						Iter_SafeRemove(FactionVeh, i, i);
					}
				}
			}
		}
		SendClientMessageToAllEx(COLOR_RED, "AdmCMD: %s telah merespawn kendaraan faction SAPD", pData[playerid][pAdminname]);
	}
	else if(!strcmp(facname, "sags", true))
	{
		for(new i = 0; i < MAX_FACTIONVEH; i++)
		{
			if(Iter_Contains(FactionVeh, i))
			{
				if(fvData[i][fvFaction] == 2)
				{
					if(IsVehicleEmpty(fvData[i][fvVeh]))
					{
						Delete3DTextLabel(fvData[i][fvLabel]);
						fvData[i][fvLabel] = Text3D: -1;

						if(IsValidVehicle(fvData[i][fvVeh]))
							DestroyVehicle(fvData[i][fvVeh]);

						fvData[i][fvVeh] = 0;
						fvData[i][fvFaction] = 0;

						Iter_SafeRemove(FactionVeh, i, i);
					}
				}
			}
		}
		SendClientMessageToAllEx(COLOR_RED, "AdmCMD: %s telah merespawn kendaraan faction SAGS", pData[playerid][pAdminname]);
	}
	else if(!strcmp(facname, "samd", true))
	{
		for(new i = 0; i < MAX_FACTIONVEH; i++)
		{
			if(Iter_Contains(FactionVeh, i))
			{
				if(fvData[i][fvFaction] == 3)
				{
					if(IsVehicleEmpty(fvData[i][fvVeh]))
					{
						Delete3DTextLabel(fvData[i][fvLabel]);
						fvData[i][fvLabel] = Text3D: -1;

						if(IsValidVehicle(fvData[i][fvVeh]))
							DestroyVehicle(fvData[i][fvVeh]);

						fvData[i][fvVeh] = 0;
						fvData[i][fvFaction] = 0;

						Iter_SafeRemove(FactionVeh, i, i);
					}
				}
			}
		}
		SendClientMessageToAllEx(COLOR_RED, "AdmCMD: %s telah merespawn kendaraan faction SAMD", pData[playerid][pAdminname]);
	}
	else if(!strcmp(facname, "sana", true))
	{
		for(new i = 0; i < MAX_FACTIONVEH; i++)
		{
			if(Iter_Contains(FactionVeh, i))
			{
				if(fvData[i][fvFaction] == 4)
				{
					if(IsVehicleEmpty(fvData[i][fvVeh]))
					{
						Delete3DTextLabel(fvData[i][fvLabel]);
						fvData[i][fvLabel] = Text3D: -1;

						if(IsValidVehicle(fvData[i][fvVeh]))
							DestroyVehicle(fvData[i][fvVeh]);

						fvData[i][fvVeh] = 0;
						fvData[i][fvFaction] = 0;

						Iter_SafeRemove(FactionVeh, i, i);
					}
				}
			}
		}
		SendClientMessageToAllEx(COLOR_RED, "AdmCMD: %s telah merespawn kendaraan faction SANA", pData[playerid][pAdminname]);
	}
	return 1;
}*/

CMD:frespawnveh(playerid, params[])
{
	for(new i = 0; i < MAX_FACTIONVEH; i++)
	{
		if(Iter_Contains(FactionVeh, i))
		{
			if(fvData[i][fvFaction] == 1)
			{
				if(IsVehicleEmpty(fvData[i][fvVeh]))
				{
					Delete3DTextLabel(fvData[i][fvLabel]);
					fvData[i][fvLabel] = Text3D: -1;

					if(IsValidVehicle(fvData[i][fvVeh]))
						DestroyVehicle(fvData[i][fvVeh]);

					fvData[i][fvVeh] = 0;
					fvData[i][fvFaction] = 0;

					Iter_Remove(FactionVeh, i);
				}
			}
		}
		if(Iter_Contains(FactionVeh, i))
		{
			if(fvData[i][fvFaction] == 2)
			{
				if(IsVehicleEmpty(fvData[i][fvVeh]))
				{
					Delete3DTextLabel(fvData[i][fvLabel]);
					fvData[i][fvLabel] = Text3D: -1;

					if(IsValidVehicle(fvData[i][fvVeh]))
						DestroyVehicle(fvData[i][fvVeh]);

					fvData[i][fvVeh] = 0;
					fvData[i][fvFaction] = 0;

					Iter_Remove(FactionVeh, i);
				}
			}
		}
		if(Iter_Contains(FactionVeh, i))
		{
			if(fvData[i][fvFaction] == 3)
			{
				if(IsVehicleEmpty(fvData[i][fvVeh]))
				{
					Delete3DTextLabel(fvData[i][fvLabel]);
					fvData[i][fvLabel] = Text3D: -1;

					if(IsValidVehicle(fvData[i][fvVeh]))
						DestroyVehicle(fvData[i][fvVeh]);

					fvData[i][fvVeh] = 0;
					fvData[i][fvFaction] = 0;

					Iter_Remove(FactionVeh, i);
				}
			}
		}
		if(Iter_Contains(FactionVeh, i))
		{
			if(fvData[i][fvFaction] == 4)
			{
				if(IsVehicleEmpty(fvData[i][fvVeh]))
				{
					Delete3DTextLabel(fvData[i][fvLabel]);
					fvData[i][fvLabel] = Text3D: -1;

					if(IsValidVehicle(fvData[i][fvVeh]))
						DestroyVehicle(fvData[i][fvVeh]);

					fvData[i][fvVeh] = 0;
					fvData[i][fvFaction] = 0;

					Iter_Remove(FactionVeh, i);
				}
			}
		}
	}
	SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah merespawn all kendaraan faction", pData[playerid][pAdminname]);
	return 1;
}

CMD:respawnsags(playerid, params[])
{
	for(new i = 0; i < MAX_FACTIONVEH; i++)
	{
		if(Iter_Contains(FactionVeh, i))
		{
			if(fvData[i][fvFaction] == 2)
			{
				if(IsVehicleEmpty(fvData[i][fvVeh]))
				{
					Delete3DTextLabel(fvData[i][fvLabel]);
					fvData[i][fvLabel] = Text3D: -1;

					if(IsValidVehicle(fvData[i][fvVeh]))
						DestroyVehicle(fvData[i][fvVeh]);

					fvData[i][fvVeh] = 0;
					fvData[i][fvFaction] = 0;

					Iter_Remove(FactionVeh, i);
				}
			}
		}
	}
	SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah merespawn kendaraan faction SAGS", pData[playerid][pAdminname]);

	return 1;
}

CMD:respawnsapd(playerid, params[])
{
	for(new i = 0; i < MAX_FACTIONVEH; i++)
	{
		if(Iter_Contains(FactionVeh, i))
		{
			if(fvData[i][fvFaction] == 1)
			{
				if(IsVehicleEmpty(fvData[i][fvVeh]))
				{
					Delete3DTextLabel(fvData[i][fvLabel]);
					fvData[i][fvLabel] = Text3D: -1;

					if(IsValidVehicle(fvData[i][fvVeh]))
						DestroyVehicle(fvData[i][fvVeh]);

					fvData[i][fvVeh] = 0;
					fvData[i][fvFaction] = 0;

					Iter_Remove(FactionVeh, i);
				}
			}
		}
	}
	SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah merespawn kendaraan faction SAPD", pData[playerid][pAdminname]);
	return 1;
}

CMD:respawnsamd(playerid, params[])
{
	for(new i = 0; i < MAX_FACTIONVEH; i++)
	{
		if(Iter_Contains(FactionVeh, i))
		{
			if(fvData[i][fvFaction] == 3)
			{
				if(IsVehicleEmpty(fvData[i][fvVeh]))
				{
					Delete3DTextLabel(fvData[i][fvLabel]);
					fvData[i][fvLabel] = Text3D: -1;

					if(IsValidVehicle(fvData[i][fvVeh]))
						DestroyVehicle(fvData[i][fvVeh]);

					fvData[i][fvVeh] = 0;
					fvData[i][fvFaction] = 0;

					Iter_Remove(FactionVeh, i);
				}
			}
		}
	}
	SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah merespawn kendaraan faction SAMD", pData[playerid][pAdminname]);
	return 1;
}

CMD:respawnsacf(playerid, params[])
{
	for(new i = 0; i < MAX_FACTIONVEH; i++)
	{
		if(Iter_Contains(FactionVeh, i))
		{
			if(fvData[i][fvFaction] == 5)
			{
				if(IsVehicleEmpty(fvData[i][fvVeh]))
				{
					Delete3DTextLabel(fvData[i][fvLabel]);
					fvData[i][fvLabel] = Text3D: -1;

					if(IsValidVehicle(fvData[i][fvVeh]))
						DestroyVehicle(fvData[i][fvVeh]);

					fvData[i][fvVeh] = 0;
					fvData[i][fvFaction] = 0;

					Iter_Remove(FactionVeh, i);
				}
			}
		}
	}
	SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah merespawn kendaraan faction SACF", pData[playerid][pAdminname]);

	return 1;
}

CMD:respawnsana(playerid, params[])
{
	for(new i = 0; i < MAX_FACTIONVEH; i++)
	{
		if(Iter_Contains(FactionVeh, i))
		{
			if(fvData[i][fvFaction] == 4)
			{
				if(IsVehicleEmpty(fvData[i][fvVeh]))
				{
					Delete3DTextLabel(fvData[i][fvLabel]);
					fvData[i][fvLabel] = Text3D: -1;

					if(IsValidVehicle(fvData[i][fvVeh]))
						DestroyVehicle(fvData[i][fvVeh]);

					fvData[i][fvVeh] = 0;
					fvData[i][fvFaction] = 0;

					Iter_Remove(FactionVeh, i);
				}
			}
		}
	}
	SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah merespawn kendaraan faction SANA", pData[playerid][pAdminname]);

	return 1;
}


CMD:respawnjobs(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		if(pData[playerid][pHelper] < 3)
			return PermissionError(playerid);
			
	for(new xx;xx<sizeof(BusVeh);xx++)
	{
		if(IsVehicleEmpty(BusVeh[xx]))
		{
			SetVehicleToRespawn(BusVeh[xx]);
			SetValidVehicleHealth(BusVeh[xx], 2000);
			vCore[BusVeh[xx]][vFuel] = 100;
			SwitchVehicleDoors(BusVeh[xx], false);
		}
	}
	for(new xx;xx<sizeof(DRIVESIMVehicles);xx++)
	{
		if(IsVehicleEmpty(DRIVESIMVehicles[xx]))
		{
			SetVehicleToRespawn(DRIVESIMVehicles[xx]);
			SetValidVehicleHealth(DRIVESIMVehicles[xx], 2000);
			vCore[DRIVESIMVehicles[xx]][vFuel] = 100;
			SwitchVehicleDoors(DRIVESIMVehicles[xx], false);
		}
	}
	for(new xx;xx<sizeof(TruckerVeh);xx++)
	{
		if(IsVehicleEmpty(TruckerVeh[xx]))
		{
			if(IsValidDynamicObject(TruckerVehObject[TruckerVeh[xx]]))
				DestroyDynamicObject(TruckerVehObject[TruckerVeh[xx]]);

			TruckerVehObject[TruckerVeh[xx]] = 0;
			SetVehicleToRespawn(TruckerVeh[xx]);
			SetValidVehicleHealth(TruckerVeh[xx], 2000);
			vCore[TruckerVeh[xx]][vFuel] = 100;
			SwitchVehicleDoors(TruckerVeh[xx], false);
		}
	}
	for(new xx;xx<sizeof(TrashVeh);xx++)
	{
		if(IsVehicleEmpty(TrashVeh[xx]))
		{
			SetVehicleToRespawn(TrashVeh[xx]);
			SetValidVehicleHealth(TrashVeh[xx], 2000);
			vCore[TrashVeh[xx]][vFuel] = 100;
			SwitchVehicleDoors(TrashVeh[xx], false);
		}
	}
	SendClientMessageToAllEx(COLOR_RED, "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah merespawn kendaraan Jobs & Side Jobs", pData[playerid][pAdminname]);
	return 1;
}

//----------------------------[ Admin Level 2 ]-----------------------
CMD:sethp(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
	
	new jumlah, otherid;
	if(sscanf(params, "ud", otherid, jumlah))
        return Usage(playerid, "/sethp [playerid id/name] <jumlah>");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
		
	SetPlayerHealthEx(otherid, jumlah);
	SendStaffMessage(-1, "{A60000}%s {FFFFFF}telah mengubah jumlah {FF0000}'HP' {FFFFFF}pada player %s.", pData[playerid][pAdminname], pData[otherid][pName]);
	Servers(otherid, "Administrator {A60000}%s {FFFFFF}telah mengubah jumlah {FF0000}'HP' {FFFFFF}anda.", pData[playerid][pAdminname]);
	return 1;
}

CMD:setbone(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
	
	new jumlah, otherid;
	if(sscanf(params, "ud", otherid, jumlah))
        return Usage(playerid, "/setbone [playerid id/name] <jumlah>");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
		
	pData[otherid][pHead] = jumlah;
	pData[otherid][pPerut] = jumlah;
	pData[otherid][pLFoot] = jumlah;
	pData[otherid][pRFoot] = jumlah;
	pData[otherid][pLHand] = jumlah;
	pData[otherid][pRHand] = jumlah;
	SendStaffMessage(COLOR_RED, "%s telah men set jumlah Kondisi tulang player %s", pData[playerid][pAdminname], pData[otherid][pName]);
	Servers(otherid, "Admin %s telah men set Kondisi tulang anda", pData[playerid][pAdminname]);
	return 1;
}

CMD:setam(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
	
	new jumlah, otherid;
	if(sscanf(params, "ud", otherid, jumlah))
        return Usage(playerid, "/setam [playerid id/name] <jumlah>");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	if(jumlah > 95)
	{
		SetPlayerArmourEx(otherid, 98);
	}
	else
	{
		SetPlayerArmourEx(otherid, jumlah);
	}
	SendStaffMessage(-1, "{A60000}%s {FFFFFF}telah mengubah jumlah {CAC9C9}'ARMOR' {FFFFFF}kepada player %s", pData[playerid][pAdminname], pData[otherid][pName]);
	Servers(otherid, "Administrator {A60000}%s {FFFFFF}telah mengubah jumlah {CAC9C9}'ARMOR' {FFFFFF}anda.", pData[playerid][pAdminname]);
	return 1;
}

CMD:afuel(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
     		return PermissionError(playerid);

	if(IsPlayerInAnyVehicle(playerid)) 
	{
		vCore[GetPlayerVehicleID(playerid)][vFuel] = 100;
		SuccesMsg(playerid, "Bensin kendaraan berhasil terisi penuh");
	}
	else
	{
		ErrorMsg(playerid, "Anda sedang tidak berada di dalam kendaraan apapun");
	}
	return 1;
}

CMD:afix(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
     		return PermissionError(playerid);
	
    if(IsPlayerInAnyVehicle(playerid)) 
	{
        SetValidVehicleHealth(GetPlayerVehicleID(playerid), 2000);
		ValidRepairVehicle(GetPlayerVehicleID(playerid));
		vCore[GetPlayerVehicleID(playerid)][vFuel] = 100;
        SuccesMsg(playerid, "Kendaraan berhasil di perbaiki");
    }
	else
	{
		ErrorMsg(playerid, "Anda sedang tidak berada di dalam kendaraan apapun");
	}
	return 1;
}

CMD:setjob1(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
	
	new
        jobid,
		otherid;
	
	if(sscanf(params, "ud", otherid, jobid))
        return Usage(playerid, "/setjob1 [playerid/PartOfName] [jobid]");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	if(jobid < 0 || jobid > 14)
        return Error(playerid, "Invalid ID. 0 - 14.");
		
	pData[otherid][pJob] = jobid;
	pData[otherid][pExitJob] = 0;
	
	Servers(playerid, "Anda telah menset job1 player %s(%d) menjadi %s(%d).", pData[otherid][pName], otherid, GetJobName(jobid), jobid);
	Servers(otherid, "Admin %s telah menset job1 anda menjadi %s(%d)", pData[playerid][pAdminname], GetJobName(jobid), jobid);
	return 1;
}

CMD:setjob2(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
	
	new
        jobid,
		otherid;
	
	if(sscanf(params, "ud", otherid, jobid))
        return Usage(playerid, "/setjob2 [playerid/PartOfName] [jobid]");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	if(jobid < 0 || jobid > 14)
        return Error(playerid, "Invalid ID. 0 - 14.");
		
	pData[otherid][pJob2] = jobid;
	pData[otherid][pExitJob] = 0;
	
	Servers(playerid, "Anda telah menset job2 player %s(%d) menjadi %s(%d).", pData[otherid][pName], otherid, GetJobName(jobid), jobid);
	Servers(otherid, "Admin %s telah menset job2 anda menjadi %s(%d)", pData[playerid][pAdminname], GetJobName(jobid), jobid);
	return 1;
}

CMD:setjobtime(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
	
	new
        timer,
		otherid;
	
	if(sscanf(params, "ud", otherid, timer))
        return Usage(playerid, "/setjobtime [playerid/PartOfName] [time]");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
		
	pData[otherid][pJobTime] = timer;
	
	Servers(playerid, "Anda telah menset job time player %s(%d) menjadi %s(%d).", pData[otherid][pName], otherid, pData[otherid][pJobTime]);
	Servers(otherid, "Admin %s telah menset jobtime anda menjadi %s(%d)", pData[playerid][pAdminname], pData[otherid][pJobTime]);
	return 1;
}

CMD:setstat(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);

	if(IsPlayerConnected(playerid))
	{
		new name[24], query[248], param[32], ammount, otherid;
        if(sscanf(params, "us[24]S()[32]", otherid, name, param))
		{
			Usage(playerid, "/setstat [playerid] [names]");
			Info(playerid, "Names: Level, LevelUp, Money, Bank, Health, Armour, Hunger, Energy");
			Info(playerid, "Names: Phonecr, Job1, Job2, Fam");
			return 1;
		}

		if(!strcmp(name, "level", true))
		{
			if(sscanf(param, "i", ammount))
			{
				return Usage(playerid, "/setstat [playerid] [level] [ammount]");
			}

			pData[otherid][pLevel] = ammount;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Level {FFFF00}%s {ffffff}ke level %d.", pData[playerid][pAdminname], pData[otherid][pName], ammount);
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Level{ffffff} kamu ke %d.", pData[playerid][pAdminname], ammount);

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET level = %i WHERE reg_id = %i", pData[otherid][pLevel], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else if(!strcmp(name, "levelup", true))
		{
			if(sscanf(param, "i", ammount))
			{
				return Usage(playerid, "/setstat [playerid] [levelup] [ammount]");
			}

			pData[otherid][pLevelUp] = ammount;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Poin Level {FFFF00}%s {ffffff}menjadi %d.", pData[playerid][pAdminname], pData[otherid][pName], ammount);
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Poin Level{ffffff} kamu menjadi %d.", pData[playerid][pAdminname], ammount);

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET levelup = %i WHERE reg_id = %i", pData[otherid][pLevelUp], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else if(!strcmp(name, "money", true))
		{
			if(sscanf(param, "i", ammount))
			{
				return Usage(playerid, "/setstat [playerid] [money] [ammount]");
			}

			GivePlayerMoneyEx(playerid, ammount);
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Money {FFFF00}%s {ffffff}menjadi %s.", pData[playerid][pAdminname], pData[otherid][pName], FormatMoney(ammount));
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Money{ffffff} kamu menjadi %d.", pData[playerid][pAdminname], ammount);
		}
		else if(!strcmp(name, "bank", true))
		{
			if(sscanf(param, "i", ammount))
			{
				return Usage(playerid, "/setstat [playerid] [bank] [ammount]");
			}

			pData[otherid][pBankMoney] = ammount;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Bank Money {FFFF00}%s {ffffff}menjadi %s.", pData[playerid][pAdminname], pData[otherid][pName], FormatMoney(ammount));
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Bank Money{ffffff} kamu menjadi %d.", pData[playerid][pAdminname], ammount);

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET bmoney = %i WHERE reg_id = %i", pData[otherid][pBankMoney], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else if(!strcmp(name, "phonecr", true))
		{
			if(sscanf(param, "i", ammount))
			{
				return Usage(playerid, "/setstat [playerid] [phonecr] [ammount]");
			}

			pData[otherid][pPhoneCredit] = ammount;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Phone Credit {FFFF00}%s {ffffff}menjadi %d.", pData[playerid][pAdminname], pData[otherid][pName], ammount);
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Phone Credit{ffffff} kamu menjadi %d.", pData[playerid][pAdminname], ammount);

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET phonecredit = %i WHERE reg_id = %i", pData[otherid][pPhoneCredit], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else if(!strcmp(name, "health", true))
		{
			if(sscanf(param, "i", ammount))
			{
				return Usage(playerid, "/setstat [playerid] [health] [ammount]");
			}

			pData[otherid][pHealth] = ammount;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Health {FFFF00}%s {ffffff}menjadi %d.", pData[playerid][pAdminname], pData[otherid][pName], ammount);
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Health{ffffff} kamu menjadi %d.", pData[playerid][pAdminname], ammount);

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET health = %i WHERE reg_id = %i", pData[otherid][pHealth], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else if(!strcmp(name, "armour", true))
		{
			if(sscanf(param, "i", ammount))
			{
				return Usage(playerid, "/setstat [playerid] [armour] [ammount]");
			}

			pData[otherid][pArmour] = ammount;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Armour {FFFF00}%s {ffffff}menjadi %d.", pData[playerid][pAdminname], pData[otherid][pName], ammount);
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Armour{ffffff} kamu menjadi %d.", pData[playerid][pAdminname], ammount);

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET armour = %i WHERE reg_id = %i", pData[otherid][pArmour], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else if(!strcmp(name, "hunger", true))
		{
			if(sscanf(param, "i", ammount))
			{
				return Usage(playerid, "/setstat [playerid] [hunger] [ammount]");
			}

			pData[otherid][pHunger] = ammount;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Hunger {FFFF00}%s {ffffff}menjadi %d.", pData[playerid][pAdminname], pData[otherid][pName], ammount);
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Hunger{ffffff} kamu menjadi %d.", pData[playerid][pAdminname], ammount);

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET hunger = %i WHERE reg_id = %i", pData[otherid][pHunger], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else if(!strcmp(name, "energy", true))
		{
			if(sscanf(param, "i", ammount))
			{
				return Usage(playerid, "/setstat [playerid] [energy] [ammount]");
			}

			pData[otherid][pEnergy] = ammount;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Energy {FFFF00}%s {ffffff}menjadi %d.", pData[playerid][pAdminname], pData[otherid][pName], ammount);
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Energy{ffffff} kamu menjadi %d.", pData[playerid][pAdminname], ammount);

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET energy = %i WHERE reg_id = %i", pData[otherid][pEnergy], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else if(!strcmp(name, "job1", true))
		{
			if(sscanf(param, "i", ammount))
			{
				Usage(playerid, "/setstat [playerid] [job1] [ammount]");
				Info(playerid, "Names: <1> LumberJack, <2> Trucker, <3> Miner");
				Info(playerid, "Names: <4> Production, <5> Farmer, <6> Hauling, <7> Pizzaman");
				Info(playerid, "Names: <8> Butcher, <9> Reflenish, <10> Drug Dealer, <11> Weapon Dealer, <12> Cow milker");
				return 1;
			}
			if(!(0 <= ammount <= 9))
			{
				return Error(playerid, "Invalid job.");
			}

			pData[otherid][pJob] = ammount;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Job {FFFF00}%s {ffffff}menjadi %s.", pData[playerid][pAdminname], pData[otherid][pName], GetJobName(ammount));
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Job{ffffff} kamu menjadi %s.", pData[playerid][pAdminname], GetJobName(ammount));

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET job = %i WHERE reg_id = %i", pData[otherid][pJob], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else if(!strcmp(name, "job2", true))
		{
			if(sscanf(param, "i", ammount))
			{
				Usage(playerid, "/setstat [playerid] [job2] [ammount]");
				Info(playerid, "Names: <1> LumberJack, <2> Trucker, <3> Miner");
				Info(playerid, "Names: <4> Production, <5> Farmer, <6> Hauling, <7> Pizzaman");
				Info(playerid, "Names: <8> Butcher, <9> Reflenish, <10> Drug Dealer, <11> Weapon Dealer, <12> Cow milker");
				return 1;
			}
			if(!(0 <= ammount <= 9))
			{
				return Error(playerid, "Invalid job.");
			}

			pData[otherid][pJob2] = ammount;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Second Job {FFFF00}%s {ffffff}menjadi %s.", pData[playerid][pAdminname], pData[otherid][pName], GetJobName(ammount));
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Second Job{ffffff} kamu menjadi %s.", pData[playerid][pAdminname], GetJobName(ammount));

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET job2 = %i WHERE reg_id = %i", pData[otherid][pJob2], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else if(!strcmp(name, "fam", true))
		{
			if(sscanf(param, "i", ammount))
			{
				return Usage(playerid, "/setstat [playerid] [fam] [ammount]");
			}

			pData[otherid][pFamily] = ammount;
			pData[otherid][pFamilyRank] = 1;
			AdminCMD(playerid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Family {FFFF00}%s {ffffff}menjadi %d.", pData[playerid][pAdminname], pData[otherid][pName], ammount);
			AdminCMD(otherid, "{FFFF00}%s {ffffff}telah menyetel {15D4ED}Family{ffffff} kamu menjadi %d.", pData[playerid][pAdminname], ammount);

			mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET family = %i, familyrank = %i WHERE reg_id = %i", pData[otherid][pFamily], pData[otherid][pFamilyRank], pData[otherid][pID]);
	    	mysql_tquery(g_SQL, query);
		}
		else
		{
			return 1;
		}
	}
	return 1;
}

CMD:setskin(playerid, params[])
{
    new
        skinid,
		otherid;

    if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);

    if(sscanf(params, "ud", otherid, skinid))
        return Usage(playerid, "/skin [playerid/PartOfName] [skin id]");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");

    if(skinid < 0 || skinid > 299)
        return Error(playerid, "Invalid skin ID. Skins range from 0 to 299.");

    SetPlayerSkin(otherid, skinid);
	pData[otherid][pSkin] = skinid;

    Servers(playerid, "Anda telah mengganti skin %s dengan skin ID %d.", ReturnName(otherid), skinid);
    Servers(otherid, "Admin {A60000}%s {FFFFFF}telah mengganti skin anda dengan ID %d.", pData[playerid][pAdminname], skinid);
    return 1;
}

CMD:akill(playerid, params[])
{
    if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
	new reason[60], otherid;
	if(sscanf(params, "uS(*)[60]", otherid, reason))
	{
	    Usage(playerid, "/akill <ID/Name> <optional: reason>");
	    return 1;
	}

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");

	SetPlayerHealth(otherid, 0.0);

	if(reason[0] != '*')
	{
		SendClientMessageToAllEx(COLOR_RED, "Servers: {ffff00}Admin %s has killed %s. "GREY_E"[Reason: %s]", pData[playerid][pAdminname], pData[otherid][pName], reason);
	}
	else
	{
		SendClientMessageToAllEx(COLOR_RED, "Servers: {ffff00}Admin %s has killed %s.", pData[playerid][pAdminname], pData[otherid][pName]);
	}
	return 1;
}

CMD:ann(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);

 	if(isnull(params))
    {
	    Usage(playerid, "/announce <msg>");
	    return 1;
	}
	// Check for special trouble-making input
   	if(strfind(params, "~x~", true) != -1)
		return Error(playerid, "~x~ is not allowed in announce.");
	if(strfind(params, "#k~", true) != -1)
		return Error(playerid, "The constant key is not allowed in announce.");
	if(strfind(params, "/q", true) != -1)
		return Error(playerid, "You are not allowed to type /q in announcement!");

	// Count tildes (uneven number = faulty input)
	new iTemp = 0;
	for(new i = (strlen(params)-1); i != -1; i--)
	{
		if(params[i] == '~')
			iTemp ++;
	}
	if(iTemp % 2 == 1)
		return Error(playerid, "You either have an extra ~ or one is missing in the announcement!");
	
	new str[512];
	format(str, sizeof(str), "~w~%s", params);
	GameTextForAll(str, 6500, 3);
	return true;
}

/*CMD:settime(playerid, params[])
{
    if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);

	new time, mstr[128];
	if(sscanf(params, "d", time))
	{
		Usage(playerid, "/time <time ID>");
		return true;
	}

	SendClientMessageToAllEx(-1, "{0AD7FF}WEATHER: {FFFFFF}Administrator {A60000}%s {FFFFFF}telah mengubah waktu server", pData[playerid][pAdminname]);

	format(mstr, sizeof(mstr), "~r~Time changed: ~b~%d", time);
	GameTextForAll(mstr, 3000, 5);

	SetWorldTime(time);
	foreach(new ii : Player)
	{
		SetPlayerTime(ii, time, 0);
	}
	return 1;
}*/

CMD:setweather(playerid, params[])
{
    new weatherid;

    if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);

    if(sscanf(params, "d", weatherid))
        return Usage(playerid, "/setweather [weather ID]");

    SetWeather(weatherid);
	WorldWeather = weatherid;
	foreach(new ii : Player)
	{
		SetPlayerWeather(ii, weatherid);
	}
    SendClientMessageToAllEx(COLOR_RED,"{0AD7FF}WEATHER: {FFFFFF}Administrator {A60000}%s {FFFFFF}telah mengubah cuaca server", pData[playerid][pAdminname]);
    Servers(playerid, "Anda telah mengubah cuaca server ke ID %d.", weatherid);
    return 1;
}

CMD:gotoco(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
		return PermissionError(playerid);
		
	new Float: pos[3], int;
	if(sscanf(params, "fffd", pos[0], pos[1], pos[2], int)) return Usage(playerid, "/gotoco [x coordinate] [y coordinate] [z coordinate] [interior]");

	Servers(playerid, "Anda telah terteleportasi ke kordinat tersebut.");
	SetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	SetPlayerInterior(playerid, int);
	return 1;
}

CMD:cd(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
		
	if(Count != -1) return Error(playerid, "There is already a countdown in progress, wait for it to end!");

	Count = 6;
	countTimer = SetTimer("pCountDown", 1000, 1);

	foreach(new ii : Player)
	{
		showCD[ii] = 1;
	}
	SendClientMessageToAllEx(COLOR_RED, "[SERVER] "LB_E"Admin %s has started a global countdown!", pData[playerid][pAdminname]);
	return 1;
}

//---------------[ Admin Level 3 ]------------
CMD:oban(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
	    return PermissionError(playerid);

	new player[24], datez, reason[50];
	if(sscanf(params, "s[24]D(0)s[50]", player, datez, reason))
	{
	    Usage(playerid, "/oban <ban name> <time in days (0 for permanent ban)> <reason>");
	    Info(playerid, "Will ban a player while he is offline. If time isn't specified it will be a perm ban.");
	    return true;
	}
	if(strlen(reason) > 50) return Error(playerid, "Reason must be shorter than 50 characters.");

	foreach(new ii : Player)
	{
		new PlayerName[24];
		GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

	    if(strfind(PlayerName, player, true) != -1)
		{
			Error(playerid, "Player is online, you can use /ban on him.");
	  		return true;
	  	}
	}

	new query[128];

	mysql_format(g_SQL, query, sizeof(query), "SELECT ip FROM players WHERE username='%e'", player);
	mysql_tquery(g_SQL, query, "OnOBanQueryData", "issi", playerid, player, reason, datez);
	return true;
}

CMD:banucp(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
	    return PermissionError(playerid);

	new player[24], datez, reason[50];
	if(sscanf(params, "s[24]D(0)s[50]", player, datez, reason))
	{
	    Usage(playerid, "/ucpban <ucpname> <time in days (0 for permanent ban)> <reason>");
	    return true;
	}
	if(strlen(reason) > 50) 
		return Error(playerid, "Reason must be shorter than 50 characters.");

	new query[128];
	mysql_format(g_SQL, query, sizeof(query), "SELECT ip FROM ucp WHERE ucp_name = '%e'", player);
	mysql_tquery(g_SQL, query, "OnOBanUcpQueryData", "issi", playerid, player, reason, datez);
	return true;
}


CMD:banip(playerid, params[])
{
    if(pData[playerid][pAdmin] < 2)
     	return PermissionError(playerid);

	if(isnull(params))
	{
	    Usage(playerid, "/banip <IP Address>");
		return true;
	}
	if(strfind(params, "*", true) != -1 && pData[playerid][pAdmin] != 5)
	{
		Error(playerid, "You are not authorized to ban ranges.");
  		return true;
  	}

	SendClientMessageToAllEx(COLOR_RED, "Server: {ffff00}Admin %s(%d) IP banned address %s.", pData[playerid][pAdminname], playerid, params);
	
	new tstr[128];
	format(tstr, sizeof(tstr), "banip %s", params);
	SendRconCommand(tstr);
	return 1;
}

CMD:unbanip(playerid, params[])
{
    if(pData[playerid][pAdmin] < 2)
     	return PermissionError(playerid);

	if(isnull(params))
	{
	    Usage(playerid, "/unbanip <IP Address>");
		return true;
	}
	new mstr[128];
	format(mstr, sizeof(mstr), "unbanip %s", params);
	SendRconCommand(mstr);
	format(mstr, sizeof(mstr), "reloadbans");
	SendRconCommand(mstr);
	Servers(playerid, "You have unbanned IP address %s.", params);
	return 1;
}

CMD:areloadweap(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/areloadweap [playerid/PartOfName]");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");

    SetWeapons(otherid);
    Servers(playerid, "You have reload %s's weapons.", pData[otherid][pName]);
    Servers(otherid, "Admin %s have reload your weapons.", pData[playerid][pAdminname]);
    return 1;
}

CMD:resetweap(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/resetweps [playerid/PartOfName]");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");

    ResetPlayerWeaponsEx(otherid);
    Servers(playerid, "You have reset %s's weapons.", pData[otherid][pName]);
    Servers(otherid, "Admin %s have reset your weapons.", pData[playerid][pAdminname]);
    return 1;
}

CMD:setlevel(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
	
	new jumlah, otherid;
	if(sscanf(params, "ud", otherid, jumlah))
        return Usage(playerid, "/setlevel [playerid id/name] <jumlah>");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
		
	pData[otherid][pLevel] = jumlah;
	SetPlayerScore(otherid, jumlah);
	SendStaffMessage(COLOR_RED, "%s telah men set jumlah level player %s", pData[playerid][pAdminname], pData[otherid][pName]);
	Servers(otherid, "Admin %s telah men set level anda", pData[playerid][pAdminname]);
	return 1;
}

CMD:setgender(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
	
	new jumlah, otherid, string[128];
	if(sscanf(params, "ud", otherid, jumlah))
        return Usage(playerid, "/setgender [playerid id/name] [gender] (1.Pria 2.Wanita)");
	
	if(jumlah < 1 || jumlah > 2)
		return Error(playerid, "Gender only type 1 or 2");

	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
    {
		if(jumlah == 1)
	    {
	    	string = "Pria";
	    }
	    else
	    {
	    	string = "Wanita";
	    }
	    pData[otherid][pGender] = jumlah;
		SendStaffMessage(COLOR_RED, "%s telah men set gender player %s menjadi %s", pData[playerid][pAdminname], pData[otherid][pName], string);
		Servers(otherid, "Admin %s telah men set gender anda menjadi %s", pData[playerid][pAdminname], string);
	}
    return 1;
}

CMD:sethbe(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
	
	new jumlah, otherid;
	if(sscanf(params, "ud", otherid, jumlah))
        return Usage(playerid, "/sethbe [playerid id/name] <jumlah>");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
		
	pData[otherid][pHunger] = jumlah;
	pData[otherid][pEnergy] = jumlah;
	pData[otherid][pSick] = 0;
	SetPlayerDrunkLevel(playerid, 0);
	SendStaffMessage(COLOR_RED, "%s telah men set jumlah hbe player %s", pData[playerid][pAdminname], pData[otherid][pName]);
	Servers(otherid, "Admin %s telah men set HBE anda", pData[playerid][pAdminname]);
	return 1;
}

CMD:setstress(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
	
	new jumlah, otherid;
	if(sscanf(params, "ud", otherid, jumlah))
        return Usage(playerid, "/setstress [playerid id/name] <jumlah>");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
		
	pData[otherid][pStress] = jumlah;
	pData[otherid][pSick] = 0;
	SendStaffMessage(COLOR_RED, "%s telah men set jumlah stress player %s", pData[playerid][pAdminname], pData[otherid][pName]);
	Servers(otherid, "Admin %s telah men set stress anda", pData[playerid][pAdminname]);
	return 1;
}

//----------------------------[ Admin Level 4 ]---------------
CMD:setname(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
	new otherid, tmp[20];
	if(sscanf(params, "is[20]", otherid, tmp))
	{
	   	Usage(playerid, "/setname <ID/Name> <newname>");
	    return 1;
	}
	if(!IsPlayerConnected(otherid)) return Error(playerid, "Player belum masuk!");
	if(pData[otherid][IsLoggedIn] == false)	return Error(playerid, "That player is not logged in.");
	
	if(strlen(tmp) < 4) return Error(playerid, "New name can't be shorter than 4 characters!");
	if(strlen(tmp) > 20) return Error(playerid, "New name can't be longer than 20 characters!");

	if(!IsValidName(tmp)) return Error(playerid, "Name contains invalid characters, please doublecheck!");
	new query[248];
	mysql_format(g_SQL, query, sizeof(query), "SELECT username FROM players WHERE username='%s'", tmp);
	mysql_tquery(g_SQL, query, "SetName", "iis", otherid, playerid, tmp);
	return 1;
}


// SetName Callback
function SetName(otherplayer, playerid, nname[])
{
	if(!cache_num_rows())
	{
		new oldname[24], newname[24], query[248];
		GetPlayerName(otherplayer, oldname, sizeof(oldname));
		
		mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET username='%s' WHERE reg_id=%d", nname, pData[otherplayer][pID]);
		mysql_tquery(g_SQL, query);
		
		Servers(otherplayer, "Admin %s telah mengganti nickname anda menjadi (%s)", pData[playerid][pAdminname], nname);
		Info(otherplayer, "Pastikan anda mengingat dan mengganti nickname anda pada saat login kembali!");
		SendStaffMessage(COLOR_RED, "Admin %s telah mengganti nickname player %s(%d) menjadi %s", pData[playerid][pAdminname], oldname, otherplayer, nname);
		
		SetPlayerName(otherplayer, nname);
		GetPlayerName(otherplayer, newname, sizeof(newname));
		pData[otherplayer][pName] = newname;
		// House
		foreach(new h : Houses)
		{
			if(!strcmp(hData[h][hOwner], oldname, true))
   			{
   			    // Has House
   			    format(hData[h][hOwner], 24, "%s", newname);
          		mysql_format(g_SQL, query, sizeof(query), "UPDATE houses SET owner='%s' WHERE ID=%d", newname, h);
				mysql_tquery(g_SQL, query);
				House_Refresh(h);
				House_Save(h);
			}
		}
		// Dealer
		foreach(new deid : Dealer)
		{
			if(!strcmp(drData[deid][dOwner], oldname, true))
   			{
   			    // Has Dealer
   			    format(drData[deid][dOwner], 24, "%s", newname);
          		mysql_format(g_SQL, query, sizeof(query), "UPDATE dealer SET owner='%s' WHERE ID=%d", newname, deid);
				mysql_tquery(g_SQL, query);
				Dealer_Refresh(deid);
				Dealer_Save(deid);
			}
		}
		// Venid
		foreach(new venid : Vending)
		{
			if(!strcmp(vmData[venid][venOwner], oldname, true))
   			{
   			    // Has Vending
   			    format(vmData[venid][venOwner], 24, "%s", newname);
          		mysql_format(g_SQL, query, sizeof(query), "UPDATE vendingmachine SET owner='%s' WHERE ID=%d", newname, venid);
				mysql_tquery(g_SQL, query);
				Vending_Refresh(venid);
				Vending_Save(venid);
			}
		}
		if(pData[otherplayer][PurchasedToy] == true)
		{
			mysql_format(g_SQL, query, sizeof(query), "UPDATE toys SET Owner='%s' WHERE Owner='%s'", newname, oldname);
			mysql_tquery(g_SQL, query);
		}
		/*// Update Family
		if(pGroupRank[otherplayer] == 6)
		{
			format(query, sizeof(query), "UPDATE groups SET gFounder='%s' WHERE gFounder='%s'", newname, oldname);
			MySQL_updateQuery(query);
		}*/
	}
	else
	{
	    // Name Exists
		Error(playerid, "The name "DARK_E"'%s' "WHITE_E"already exists in the database, please use a different name!", nname);
	}
    return 1;
}

function ChangeName(playerid, nname[])
{
	if(!cache_num_rows())
	{
		if(pData[playerid][pGold] < 500) return Error(playerid, "Not enough gold!");
		pData[playerid][pGold] -= 500;
		
		new oldname[24], newname[24], query[248];
		GetPlayerName(playerid, oldname, sizeof(oldname));
		
		mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET username='%s' WHERE reg_id=%d", nname, pData[playerid][pID]);
		mysql_tquery(g_SQL, query);
		
		Servers(playerid, "Anda telah mengganti nickname anda menjadi (%s)", nname);
		Info(playerid, "Pastikan anda mengingat dan mengganti nickname anda pada saat login kembali!");
		SendStaffMessage(COLOR_RED, "Player %s(%d) telah mengganti nickname menjadi %s(%d)", oldname, playerid, nname, playerid);
		
		SetPlayerName(playerid, nname);
		GetPlayerName(playerid, newname, sizeof(newname));
		pData[playerid][pName] = newname;
		// House
		foreach(new h : Houses)
		{
			if(!strcmp(hData[h][hOwner], oldname, true))
   			{
   			    // Has House
   			    format(hData[h][hOwner], 24, "%s", newname);
          		mysql_format(g_SQL, query, sizeof(query), "UPDATE houses SET owner='%s' WHERE ID=%d", newname, h);
				mysql_tquery(g_SQL, query);
				House_Refresh(h);
				House_Save(h);
			}
		}
		if(pData[playerid][PurchasedToy] == true)
		{
			mysql_format(g_SQL, query, sizeof(query), "UPDATE toys SET Owner='%s' WHERE Owner='%s'", newname, oldname);
			mysql_tquery(g_SQL, query);
		}
		/*// Update Family
		if(pGroupRank[otherplayer] == 6)
		{
			format(query, sizeof(query), "UPDATE groups SET gFounder='%s' WHERE gFounder='%s'", newname, oldname);
			MySQL_updateQuery(query);
		}*/
	}
	else
	{
	    // Name Exists
		Error(playerid, "The name "DARK_E"'%s' "WHITE_E"already exists in the database, please use a different name!", nname);
		return 1;
	}
    return 1;
}

CMD:setboostall(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
	
	new dayz;
	if(sscanf(params, "d", dayz))
	{
	    Usage(playerid, "/setboostall <time (in days) 0 for permanent>");
	    return true;
	}
	if(dayz < 0)
		return Error(playerid, "Time can't be lower than 0!");
		
	
	if(pData[playerid][pAdmin] < 5 && dayz > 7)
		return Error(playerid, "Anda hanya bisa menset 1 - 7 hari!");
	
	foreach(new otherid : Player)
	{
		pData[otherid][pBooster] = 1;
		if(dayz == 0)
		{
			pData[otherid][pBoostTime] = 0;
			SendClientMessageToAllEx(COLOR_RED, "Server: {ffff00}Admin %s(%d) telah menset Roleplay Booster kepada seluruh player ke level permanent time!", pData[playerid][pAdminname], playerid);
		}
		else
		{
			pData[otherid][pBoostTime] = gettime() + (dayz * 86400);
			SendClientMessageToAllEx(COLOR_RED, "Server: {ffff00}Admin %s(%d) telah menset Roleplay Booster kepada seluruh player selama %d hari!", pData[playerid][pAdminname], playerid, dayz);
		}
	}
	return 1;
}

CMD:setbooster(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
	
	new dayz, otherid, tmp[64];
	if(sscanf(params, "ud", otherid, dayz))
	{
	    Usage(playerid, "/setbooster <ID/Name> <time (in days) 0 for permanent>");
	    return true;
	}
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	if(dayz < 0)
		return Error(playerid, "Time can't be lower than 0!");
		
	if(pData[otherid][IsLoggedIn] == false)
	{
		Error(playerid, "Player %s(%i) isn't logged in!", pData[otherid][pName], otherid);
		return true;
	}
	
	if(pData[playerid][pAdmin] < 5 && dayz > 7)
		return Error(playerid, "Anda hanya bisa menset 1 - 7 hari!");
	
	pData[otherid][pBooster] = 1;
	if(dayz == 0)
	{
		pData[otherid][pBoostTime] = 0;
		SendClientMessageToAllEx(COLOR_RED, "Server: {ffff00}Admin %s(%d) telah menset Roleplay Booster kepada %s(%d) ke level permanent time!", pData[playerid][pAdminname], playerid, pData[otherid][pName], otherid);
	}
	else
	{
		pData[otherid][pBoostTime] = gettime() + (dayz * 86400);
		SendClientMessageToAllEx(COLOR_RED, "Server: {ffff00}Admin %s(%d) telah menset Roleplay Booster kepada %s(%d) selama %d hari!", pData[playerid][pAdminname], playerid, pData[otherid][pName], otherid, dayz);
	}
	
	format(tmp, sizeof(tmp), "(%d days)", dayz);
	StaffCommandLog("SETBOOSTER", playerid, otherid, tmp);
	return 1;
}

CMD:setamall(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return Error(playerid, "Only admin level 6");

	new Float:amount, string[1024];
	if(sscanf(params, "f", amount))
	    return Usage(playerid, "/setamall [amount]");

	if(amount < 1 || amount > 97)
		return Error(playerid, "tidak bisa kurang dari 1 dan lebih dari 97");
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i))
		{
			SetPlayerArmourEx(i, amount);
		}
	}
	format(string, sizeof(string), "[SERVER]"YELLOW_E"Admin %s telah memberikan armor sejumlah %0.0f kepada seluruh player yang online", pData[playerid][pAdminname], amount);
	va_SendClientMessageToAll(COLOR_RED, string);
	return 1;
}

CMD:sethpall(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return Error(playerid, "Only admin level 6");

	new Float:amount, string[1024];
	if(sscanf(params, "f", amount))
	    return Usage(playerid, "/sethpall [amount]");

	if(amount < 1 || amount > 97)
		return Error(playerid, "tidak bisa kurang dari 1 dan lebih dari 97");
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i))
		{
			SetPlayerHealthEx(i, amount);
		}
	}
	format(string, sizeof(string), "[SERVER]"YELLOW_E"Admin %s telah memberikan hp sejumlah %0.0f kepada seluruh player yang online", pData[playerid][pAdminname], amount);
	va_SendClientMessageToAll(COLOR_RED, string);
	return 1;
}

CMD:overdosemoneyall(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return Error(playerid, "Only admin level 6");

	new amount, string[1024];
	if(sscanf(params, "d", amount))
	    return Usage(playerid, "/overdosemoneyall [amount]");

	if(amount < 1 || amount > 100000)
		return Error(playerid, "tidak bisa kurang dari $1 dan lebih dari $100.000");

	foreach(new i : Player)
	{
		if(IsPlayerConnected(i))
		{
			GivePlayerMoneyEx(i, amount);
		}
	}
	format(string, sizeof(string), "{FF3939}AdmCMD: {A60000}%s {FFFFFF}telah memberikan uang sejumlah {00FF00}%s {FFFFFF}kepada seluruh player yang online", pData[playerid][pAdminname], FormatMoney(amount));
	va_SendClientMessageToAll(-1, string);
	return 1;
}

CMD:setvip(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
	
	new alevel, dayz, otherid, tmp[64];
	if(sscanf(params, "udd", otherid, alevel, dayz))
	{
	    Usage(playerid, "/setvip <ID/Name> <level 0 - 3> <time (in days) 0 for permanent>");
	    return true;
	}
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	if(alevel > 3)
		return Error(playerid, "Level can't be higher than 3!");
	if(alevel < 0)
		return Error(playerid, "Level can't be lower than 0!");
	if(dayz < 0)
		return Error(playerid, "Time can't be lower than 0!");
		
	if(pData[otherid][IsLoggedIn] == false)
	{
		Error(playerid, "Player %s(%i) isn't logged in!", pData[otherid][pName], otherid);
		return true;
	}
	
	if(pData[playerid][pAdmin] < 5 && dayz > 7)
		return Error(playerid, "Anda hanya bisa menset 1 - 7 hari!");
	
	pData[otherid][pVip] = alevel;
	if(dayz == 0)
	{
		pData[otherid][pVipTime] = 0;
		Info(otherid, "Admin %s(%d) telah menset VIP kepada %s(%d) ke level %s permanent time!", pData[playerid][pAdminname], playerid, pData[otherid][pName], otherid, GetVipRank(otherid));
		Info(playerid, "Admin %s(%d) telah menset VIP kepada %s(%d) ke level %s permanent time!", pData[playerid][pAdminname], playerid, pData[otherid][pName], otherid, GetVipRank(otherid));
	}
	else
	{
		pData[otherid][pVipTime] = gettime() + (dayz * 86400);
		Info(otherid, "Admin %s(%d) telah menset VIP kepada %s(%d) selama %d hari ke level %s!", pData[playerid][pAdminname], playerid, pData[otherid][pName], otherid, dayz, GetVipRank(otherid));
		Info(playerid, "Admin %s(%d) telah menset VIP kepada %s(%d) selama %d hari ke level %s!", pData[playerid][pAdminname], playerid, pData[otherid][pName], otherid, dayz, GetVipRank(otherid));
	}
	
	format(tmp, sizeof(tmp), "%d(%d days)", alevel, dayz);
	StaffCommandLog("SETVIP", playerid, otherid, tmp);
	return 1;
}

CMD:giveweap(playerid, params[])
{
    static
        weaponid,
        ammo;
		
	new otherid;
    if(pData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    if(sscanf(params, "udI(250)", otherid, weaponid, ammo))
        return Usage(playerid, "/givewep [playerid/PartOfName] [weaponid] [ammo]");

    if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "You cannot give weapons to disconnected players.");


    if(weaponid <= 0 || weaponid > 46 || (weaponid >= 19 && weaponid <= 21))
        return Error(playerid, "You have specified an invalid weapon.");

    if(ammo < 1 || ammo > 500)
        return Error(playerid, "You have specified an invalid weapon ammo, 1 - 500");

    if(PlayerHasWeapon(otherid, weaponid))
		return Error(playerid, "Player yang dituju sudah memiliki senjata tersebut");

    GivePlayerWeaponEx(otherid, weaponid, ammo);
    Servers(playerid, "You have give %s a %s with %d ammo.", pData[otherid][pName], ReturnWeaponName(weaponid), ammo);
    return 1;
}

CMD:setfaction(playerid, params[])
{
	new fid, rank, otherid, tmp[64];
    if(pData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    if(sscanf(params, "udd", otherid, fid, rank))
        return Usage(playerid, "/setfaction [playerid/PartOfName] [1.SAPD, 2.SAGS, 3.SAMD, 4.SANEW, 5.SACF, 6.MECH, 7.TAXI] [rank 1-7]");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	if(pData[otherid][pFamily] != -1)
		return Error(playerid, "Player tersebut sudah bergabung family");

    if(fid < 0 || fid > 7)
        return Error(playerid, "You have specified an invalid faction ID 0 - 7.");
		
	if(rank < 1 || rank > 6)
        return Error(playerid, "You have specified an invalid rank 1 - 6.");

	if(fid == 0)
	{
		pData[otherid][pFaction] = 0;
		pData[otherid][pFactionRank] = 0;
		Servers(playerid, "You have removed %s's from faction.", pData[otherid][pName]);
		Servers(otherid, "%s has removed your faction.", pData[playerid][pName]);
	}
	else
	{
		pData[otherid][pFaction] = fid;
		pData[otherid][pFactionRank] = rank;
		Servers(playerid, "You have set %s's faction ID %d with rank %d.", pData[otherid][pName], fid, rank);
		Servers(otherid, "%s has set your faction ID to %d with rank %d.", pData[playerid][pName], fid, rank);
	}
	
	format(tmp, sizeof(tmp), "%d(%d rank)", fid, rank);
	StaffCommandLog("SETFACTION", playerid, otherid, tmp);
    return 1;
}

CMD:setleader(playerid, params[])
{
	new fid, otherid, tmp[64];
    if(pData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    if(sscanf(params, "ud", otherid, fid))
        return Usage(playerid, "/setleader [playerid/PartOfName] [0.None, 1.SAPD, 2.SAGS, 3.SAMD, 4.SANEW, 5.SACF, 6.MECH, 7.TAXI]");

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	if(pData[otherid][pFamily] != -1)
		return Error(playerid, "Player tersebut sudah bergabung family");

    if(fid < 0 || fid > 7)
        return Error(playerid, "You have specified an invalid faction ID 0 - 7.");

	if(fid == 0)
	{
		pData[otherid][pFaction] = 0;
		pData[otherid][pFactionLead] = 0;
		pData[otherid][pFactionRank] = 0;
		Servers(playerid, "You have removed %s's from faction leader.", pData[otherid][pName]);
		Servers(otherid, "%s has removed your faction leader.", pData[playerid][pName]);
	}
	else if(fid == 1)
	{
		pData[otherid][pFaction] = 1;
		pData[otherid][pFactionLead] = 1;
		pData[otherid][pFactionRank] = 8;
		Servers(playerid, "You have set %s's faction ID %d with leader.", pData[otherid][pName], fid);
		Servers(otherid, "%s has set your faction ID to %d with leader.", pData[playerid][pName], fid);
	}
	else
	{
		pData[otherid][pFaction] = fid;
		pData[otherid][pFactionLead] = fid;
		pData[otherid][pFactionRank] = 6;
		Servers(playerid, "You have set %s's faction ID %d with leader.", pData[otherid][pName], fid);
		Servers(otherid, "%s has set your faction ID to %d with leader.", pData[playerid][pName], fid);
	}
	
	format(tmp, sizeof(tmp), "%d", fid);
	StaffCommandLog("SETLEADER", playerid, otherid, tmp);
    return 1;
}

CMD:takemoney(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
		
	new money, otherid;
	if(sscanf(params, "ud", otherid, money))
	{
	    Usage(playerid, "/takemoney <ID/Name> <amount>");
	    return true;
	}

	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");

 	if(money > pData[playerid][pMoney])
		return Error(playerid, "Player doesn't have enough money to deduct from!");

	GivePlayerMoneyEx(otherid, -money);
	SendClientMessageToAllEx(COLOR_RED, "SERVER: {ffff00}Admin %s(%i) has taken away money "RED_E"%s {ffff00}from %s", pData[playerid][pAdminname], FormatMoney(money), pData[otherid][pName]);
	return true;
}

CMD:takegold(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
		
	new gold, otherid;
	if(sscanf(params, "ud", otherid, gold))
	{
	    Usage(playerid, "/takegold <ID/Name> <amount>");
	    return true;
	}

	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");

 	if(gold > pData[otherid][pGold])
		return Error(playerid, "Player doesn't have enough gold to deduct from!");

	pData[otherid][pGold] -= gold;
	Info(playerid, "Admin %s has taken away gold "RED_E"%d "WHITE_E"from %s", pData[playerid][pAdminname], gold, pData[otherid][pName]);
	Info(otherid, "Admin %s has taken away gold "RED_E"%d "WHITE_E"from %s", pData[playerid][pAdminname], gold, pData[otherid][pName]);
	return 1;
}

CMD:veh(playerid, params[])
{
    static
        model[32],
        color1,
        color2;

    if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);

    if(sscanf(params, "s[32]I(0)I(0)", model, color1, color2))
        return Usage(playerid, "/veh [model id/name] <color 1> <color 2>");

    if((model[0] = GetVehicleModelByName(model)) == 0)
        return Error(playerid, "Invalid model ID.");

    static
        Float:x,
        Float:y,
        Float:z,
        Float:a,
        vehicleid;

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);

    vehicleid = AddStaticVehicleEx(model[0], x, y, z, a, color1, color2, -1);
	vCore[vehicleid][vFuel] = 100;
    adminVehicle{vehicleid} = true;

    if(GetPlayerInterior(playerid) != 0)
        LinkVehicleToInterior(vehicleid, GetPlayerInterior(playerid));

    if(GetPlayerVirtualWorld(playerid) != 0)
        SetVehicleVirtualWorld(vehicleid, GetPlayerVirtualWorld(playerid));

    if(IsABoat(vehicleid) || IsAPlane(vehicleid) || IsAHelicopter(vehicleid))
        PutPlayerInVehicle(playerid, vehicleid, 0);

    SetVehicleNumberPlate(vehicleid, "ADMIN");
    Servers(playerid, "Anda memunculkan %s (%d, %d).", GetVehicleModelName(model[0]), color1, color2);
    return 1;
}

CMD:dveh(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
		return PermissionError(playerid);

	new count = 0;
	for(new i = 0; i < MAX_VEHICLES; i++)
	{
	    if(adminVehicle{i})
	    {
	    	if(IsVehicleEmpty(i))
	    	{
	    		count++;
	    		if(IsValidVehicle(i))
		        	DestroyVehicle(i);
		        
		        adminVehicle{i} = false;
			}
		}
	}
	SendStaffMessage(-1, "{A60000}%s {FFFFFF}merespawn {FFFF00}'%d' {FFFFFF}kendaraan admin static", pData[playerid][pAdminname], count);
	return 1;
}

CMD:agl(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
	
	new otherid;
	if(sscanf(params, "u", otherid))
        return Usage(playerid, "/agl [playerid id/name]");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
		
	SendStaffMessage(COLOR_RED, "%s telah memberi sim kepada player %s", pData[playerid][pAdminname], pData[otherid][pName]);
	Servers(otherid, "Admin %s telah memberi sim anda", pData[playerid][pAdminname]);
	return 1;
}
//-----------------------------[ Admin Level 5 ]------------------
CMD:sethelperlevel(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
	
	new alevel, otherid, tmp[64];
	if(sscanf(params, "ud", otherid, alevel))
	{
	    Usage(playerid, "/sethelperlevel <ID/Name> <level 0 - 3>");
	    return true;
	}
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	if(alevel > 3)
		return Error(playerid, "Level can't be higher than 3!");
	if(alevel < 0)
		return Error(playerid, "Level can't be lower than 0!");
	
	if(pData[otherid][IsLoggedIn] == false)
	{
		Error(playerid, "Player %s(%i) isn't logged in!", pData[otherid][pName], otherid);
		return true;
	}
	pData[otherid][pHelper] = alevel;
	Servers(playerid, "You has set helper level %s(%d) to level %d", pData[otherid][pName], otherid, alevel);
	Servers(otherid, "%s(%d) has set your helper level to %d", pData[otherid][pName], playerid, alevel);
	SendStaffMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}telah menset %s(%d) sebagai staff helper level %s(%d)",  pData[playerid][pAdminname], pData[otherid][pName], otherid, GetStaffRank(playerid), alevel);
	
	format(tmp, sizeof(tmp), "%d", alevel);
	StaffCommandLog("SETHELPERLEVEL", playerid, otherid, tmp);
	return 1;
}

CMD:setadminname(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
	
	new aname[1028], otherid, query[1028];
	if(sscanf(params, "us[1028]", otherid, aname))
	{
	    Usage(playerid, "/setadminname <ID/Name> <admin name>");
	    return true;
	}
	
	mysql_format(g_SQL, query, sizeof(query), "SELECT adminname FROM players WHERE adminname='%s'", aname);
	mysql_tquery(g_SQL, query, "a_ChangeAdminName", "iis", otherid, playerid, aname);
	return 1;
}

CMD:setmoney(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
		
	new money, otherid, tmp[64];
	if(sscanf(params, "ud", otherid, money))
	{
	    Usage(playerid, "/setmoney <ID/Name> <money>");
	    return true;
	}

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	ResetPlayerMoneyEx(otherid);
	GivePlayerMoneyEx(otherid, money);
	
	Servers(playerid, "Anda telah mengubah uang %s(%d) menjadi %s", pData[otherid][pName], otherid, FormatMoney(money));
	Servers(otherid, "Admin {A60000}%s {FFFFFF}telah mengubah uang anda menjadi %s",pData[playerid][pAdminname], FormatMoney(money));
	
	format(tmp, sizeof(tmp), "%d", money);
	StaffCommandLog("SETMONEY", playerid, otherid, tmp);
	return 1;
}

CMD:givemoney(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
		
	new money, otherid, tmp[64];
	if(sscanf(params, "ud", otherid, money))
	{
	    Usage(playerid, "/givemoney <ID/Name> <money>");
	    return true;
	}

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	GivePlayerMoneyEx(otherid, money);
	
	Servers(playerid, "Anda telah memberikan uang kepada %s(%d) dengan jumlah %s", pData[otherid][pName], otherid, FormatMoney(money));
	Servers(otherid, "Admin {A60000}%s {FFFFFF}telah memberikan uang kepada anda dengan jumlah %s", pData[playerid][pAdminname], FormatMoney(money));
	
	format(tmp, sizeof(tmp), "%d", money);
	StaffCommandLog("GIVEMONEY", playerid, otherid, tmp);
	return 1;
}

CMD:setbankmoney(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
		
	new money, otherid, tmp[64];
	if(sscanf(params, "ud", otherid, money))
	{
	    Usage(playerid, "/setbankmoney <ID/Name> <money>");
	    return true;
	}

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	pData[otherid][pBankMoney] = money;
	
	Servers(playerid, "Anda telah mengubah uang rekening bank %s(%d) menjadi %s", pData[otherid][pName], otherid, FormatMoney(money));
	Servers(otherid, "Admin {A60000}%s {FFFFFF}telah mengubah uang rekening bank anda menjadi %s",pData[playerid][pAdminname], FormatMoney(money));
	
	format(tmp, sizeof(tmp), "%d", money);
	StaffCommandLog("SETBANKMONEY", playerid, otherid, tmp);
	return 1;
}

CMD:givebankmoney(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
		
	new money, otherid, tmp[64];
	if(sscanf(params, "ud", otherid, money))
	{
	    Usage(playerid, "/givebankmoney <ID/Name> <money>");
	    return true;
	}

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	pData[otherid][pBankMoney] += money;
	
	Servers(playerid, "Anda telah memberikan uang rekening bank kepada %s(%d) sebesar %s!", pData[otherid][pName], otherid, FormatMoney(money));
	Servers(otherid, "Admin {A60000}%s {FFFFFF}telah memberikan uang rekening bank kepada anda sebesar %s!", pData[playerid][pAdminname], FormatMoney(money));
	
	format(tmp, sizeof(tmp), "%d", money);
	StaffCommandLog("GIVEBANKMONEY", playerid, otherid, tmp);
	return 1;
}

CMD:setvw(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
        return PermissionError(playerid);
	
	new jumlah, otherid;
	if(sscanf(params, "ud", otherid, jumlah))
        return Usage(playerid, "/setvw [playerid id/name] <virtual world>");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak ada");
		
	SetPlayerVirtualWorld(otherid, jumlah);
	Servers(otherid, "Admin {A60000}%s {FFFFFF}telah mengubah Virtual World anda", pData[playerid][pAdminname]);
	return 1;
}

CMD:setint(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
        return PermissionError(playerid);
	
	new jumlah, otherid;
	if(sscanf(params, "ud", otherid, jumlah))
        return SyntaxMsg(playerid, "/setint [playerid id/name] <interior>");
	
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player yang di maksud tidak ada");
		
	SetPlayerInterior(otherid, jumlah);
	Servers(otherid, "Admin {A60000}%s {FFFFFF}telah mengubah Interior anda", pData[playerid][pAdminname]);
	return 1;
}

CMD:explode(playerid, params[])
{
    if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
	new Float:POS[3], otherid, giveplayer[24];
	if(sscanf(params, "u", otherid))
	{
		Usage(playerid, "/explode <ID/Name>");
		return true;
	}

	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");

	GetPlayerName(otherid, giveplayer, sizeof(giveplayer));

	Servers(playerid, "Anda telah meledakan %s(%i).", giveplayer, otherid);
	GetPlayerPos(otherid, POS[0], POS[1], POS[2]);
	CreateExplosion(POS[0], POS[1], POS[2], 7, 5.0);
	return true;
}

//--------------------------[ Admin Level 6 ]-------------------
CMD:setadminlevel(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
	
	new alevel, otherid, tmp[64];
	if(sscanf(params, "ud", otherid, alevel))
	{
	    Usage(playerid, "/setadminlevel <ID/Name> <level 0 - 4>");
	    return true;
	}
	if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player tersebut belum terkoneksi");
	if(alevel > 6)
		return Error(playerid, "Level tidak boleh di atas 6");
	if(alevel < 0)
		return Error(playerid, "Level tidak boleh di bawah 0");
	
	if(pData[otherid][IsLoggedIn] == false)
	{
		Error(playerid, "Player %s (%i) isn't logged in!", pData[otherid][pName], otherid);
		return true;
	}
	pData[otherid][pAdmin] = alevel;
	Servers(playerid, "Anda telah mengubah level pada Admin {A60000}%s {FFFFFF}menjadi %d", pData[otherid][pAdminname], alevel);
	Servers(otherid, "Admin {A60000}%s {FFFFFF}telah mengubah level admin anda menjadi (%d)", pData[otherid][pAdminname], alevel);
	
	format(tmp, sizeof(tmp), "%d", alevel);
	StaffCommandLog("SETADMINLEVEL", playerid, otherid, tmp);
	return 1;
}

CMD:setgold(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
		
	new gold, otherid, tmp[64];
	if(sscanf(params, "ud", otherid, gold))
	{
	    Usage(playerid, "/setgold <ID/Name> <gold>");
	    return true;
	}

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	pData[otherid][pGold] = gold;
	
	Servers(playerid, "Anda telah menset gold %s(%d) dengan jumlah %d!", pData[otherid][pName], otherid, gold);
	Servers(otherid, "Admin {A60000}%s {FFFFFF}telah menset gold kepada anda dengan jumlah %d!", pData[playerid][pAdminname], gold);
	
	format(tmp, sizeof(tmp), "%d", gold);
	StaffCommandLog("SETGOLD", playerid, otherid, tmp);
	return 1;
}

CMD:givegold(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
		
	new gold, otherid, tmp[64];
	if(sscanf(params, "ud", otherid, gold))
	{
	    Usage(playerid, "/givegold <ID/Name> <gold>");
	    return true;
	}

    if(!IsPlayerConnected(otherid))
        return Error(playerid, "Player belum masuk!");
	
	pData[otherid][pGold] += gold;
	
	Servers(playerid, "Anda telah memberikan gold %s(%d) dengan jumlah %d!", pData[otherid][pName], otherid, gold);
	Servers(otherid, "Admin {A60000}%s {FFFFFF}telah memberikan gold kepada anda dengan jumlah %d!", pData[playerid][pAdminname], gold);
	
	format(tmp, sizeof(tmp), "%d", gold);
	StaffCommandLog("GIVEGOLD", playerid, otherid, tmp);
	return 1;
}

CMD:agive(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	if(IsPlayerConnected(playerid)) 
	{
		new name[24], ammount, otherid;
        if(sscanf(params, "us[24]d", otherid, name, ammount))
		{
			Usage(playerid, "/agive [playerid] [name] [ammount]");
			Names(playerid, "bandage, medicine, snack, sprunk, material, component, repairkit, bomb, marijuana, gps");
			Names(playerid, "weaponlic, gasfuel, clippistol, clipsg, clipsmg, cocaine, meth, ephedrine, medkit, kevlar");
			return 1;
		}
			
		if(strcmp(name,"bandage",true) == 0) 
		{		
			Inventory_Add(otherid, "Bandage", 11745, ammount);
			Info(playerid, "Anda telah berhasil memberikan perban kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan perban kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"medkit",true) == 0) 
		{		
			Inventory_Add(otherid, "Medkit", 1580, ammount);
			Info(playerid, "Anda telah berhasil memberikan medkit kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan medkit kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"medicine",true) == 0) 
		{
			Inventory_Add(otherid, "Medicine", 1575, ammount);
			Info(playerid, "Anda telah berhasil memberikan medicine kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan medicine kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"snack",true) == 0) 
		{
			Inventory_Add(otherid, "Snack", 2768, ammount);
			Info(playerid, "Anda telah berhasil memberikan snack kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan snack kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"sprunk",true) == 0) 
		{
			Inventory_Add(otherid, "Sprunk", 2958, ammount);
			Info(playerid, "Anda telah berhasil memberikan Sprunk kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Sprunk kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"material",true) == 0) 
		{			
			Inventory_Add(otherid, "Material", 17051, ammount);
			Info(playerid, "Anda telah berhasil memberikan Material kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Material kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"component",true) == 0) 
		{
			Inventory_Add(otherid, "Component", 19627, ammount);
			Info(playerid, "Anda telah berhasil memberikan Component kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Component kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"repairkit",true) == 0) 
		{
			Inventory_Add(otherid, "Repair Kit", 920, ammount);
			Info(playerid, "Anda telah berhasil memberikan Repairkit kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Repairkit kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"bomb",true) == 0) 
		{
			Inventory_Add(otherid, "Bomb", 363, ammount);
			Info(playerid, "Anda telah berhasil memberikan Bomb kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Bomb kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"marijuana",true) == 0) 
		{
			Inventory_Add(otherid, "Marijuana", 1578, ammount);
			Info(playerid, "Anda telah berhasil memberikan Marijuana kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Marijuana kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"cocaine",true) == 0) 
		{
			Inventory_Add(otherid, "Cocaine", 1575, ammount);
			Info(playerid, "Anda telah berhasil memberikan Cocaine kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Cocaine kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"meth",true) == 0) 
		{
			Inventory_Add(otherid, "Meth", 1580, ammount);
			Info(playerid, "Anda telah berhasil memberikan Meth kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Meth kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"ephedrine",true) == 0) 
		{
			Inventory_Add(otherid, "Ephedrine", 1580, ammount);
			Info(playerid, "Anda telah berhasil memberikan Ephedrine kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Ephedrine kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"clippistol",true) == 0) 
		{
			Inventory_Add(otherid, "Clip Pistol", 19995, ammount);
			Info(playerid, "Anda telah berhasil memberikan Clip Pistol kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Clip Pistol kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"clipsg",true) == 0) 
		{
			Inventory_Add(otherid, "Clip Sg", 19995, ammount);
			Info(playerid, "Anda telah berhasil memberikan Clip SG kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Clip SG kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"clipsmg",true) == 0) 
		{
			Inventory_Add(otherid, "Clip Smg", 19995, ammount);
			Info(playerid, "Anda telah berhasil memberikan Clip SMG kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan Clip SMG kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
		else if(strcmp(name,"kevlar",true) == 0)
		{
			Inventory_Add(otherid, "kevlar", 19515, ammount);
			Info(playerid, "Anda telah berhasil memberikan kevlar kepada %s sejumlah %d.", ReturnName(otherid), ammount);
			Info(otherid, "Admin {A60000}%s {FFFFFF}telah berhasil memberikan kevlar kepada anda sejumlah %d.", pData[playerid][pAdminname], ammount);
			ApplyAnimation(playerid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
			ApplyAnimation(otherid, "DEALER", "shop_pay", 4.0, 0, 0, 0, 0, 0);
		}
	}
	return 1;
}

CMD:setprice(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
		
	new name[64], string[128];
	if(sscanf(params, "s[64]S()[128]", name, string))
    {
        Usage(playerid, "/setprice [name] [price]");
        Names(playerid, "[MaterialPrice], [LumberPrice], [ComponentPrice], [ProductPrice], [FoodPrice], [FishPrice], [GsPrice]");
		Names(playerid, "[MarijuanaPrice], [EphedrinePrice], [CocainePrice] [MedkitPrice], [MedicinePrice], [Bandage]");
		Names(playerid, "[PotatoPrice], [WheatPrice], [OrangePrice], [FirstSpawnPrice], [GandumPrice], [DagingPrice], [SusuPrice], [MilkPrice]");
        return 1;
    }
    if(!strcmp(name, "materialprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [materialprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        MaterialPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Material to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
	else if(!strcmp(name, "lumberprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [lumberprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        LumberPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Lumber to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "bandage", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [bandage] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        LumberPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Bandage to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
	else if(!strcmp(name, "componentprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [componentprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        ComponentPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Component to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
	else if(!strcmp(name, "productprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [productprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        ProductPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Production to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
	else if(!strcmp(name, "medicineprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [medicineprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        MedicinePrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Medicine to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
	else if(!strcmp(name, "medkitprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [medkitprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        MedkitPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Medkit to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
	else if(!strcmp(name, "foodprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [foodprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        FoodPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Food to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
	else if(!strcmp(name, "fishprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [fishprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        FishPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price ikan to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
	else if(!strcmp(name, "gsprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [gsprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        GStationPrice = price;
		foreach(new gsid : GStation)
		{
			if(Iter_Contains(GStation, gsid))
			{
				GStation_Save(gsid);
				GStation_Refresh(gsid);
			}
		}
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price pom bensin to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "marijuanaprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [marijuanaprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        MarijuanaPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Marijuana to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "ephedrineprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [ephedrineprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        EphedrinePrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Ephedrine to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "cocaineprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [cocaineprice] [price]");

        if(price < 0 || price > 5000)
            return Error(playerid, "You can only change from 0 to 5000");

        CocainePrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price cocaine to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "firstspawnprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [firstspawnprice] [price]");

        if(price < 0 || price > 500000)
            return Error(playerid, "You can only change from 0 to 500000");

        FirstSpawnPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}mengubah uang player baru to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "potatoprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [potatoprice] [price]");

        if(price < 0 || price > 500000)
            return Error(playerid, "You can only change from 0 to 500000");

        PotatoPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price potato to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "orangeprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [orangeprice] [price]");

        if(price < 0 || price > 500000)
            return Error(playerid, "You can only change from 0 to 500000");

        OrangePrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price orange to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "wheatprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [wheatprice] [price]");

        if(price < 0 || price > 500000)
            return Error(playerid, "You can only change from 0 to 500000");

        WheatPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price Wheat to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "gandumprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [gandumprice] [price]");

        if(price < 0 || price > 500000)
            return Error(playerid, "You can only change from 0 to 500000");

        GandumPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price gandum to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "dagingprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [dagingprice] [price]");

        if(price < 0 || price > 500000)
            return Error(playerid, "You can only change from 0 to 500000");

        DagingPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price daging to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "susuprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [susuprice] [price]");

        if(price < 0 || price > 500000)
            return Error(playerid, "You can only change from 0 to 500000");

        SusuPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price susu to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
    else if(!strcmp(name, "milkprice", true))
    {
		new price;
        if(sscanf(string, "d", price))
            return Usage(playerid, "/setprice [milkprice] [price]");

        if(price < 0 || price > 500000)
            return Error(playerid, "You can only change from 0 to 500000");

        MilkPrice = price;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}changed price susu to {00FF00}%s", pData[playerid][pAdminname], FormatMoney(price));
    }
	return 1;
}

CMD:setstock(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
		
	new name[64], string[128];
	if(sscanf(params, "s[64]S()[128]", name, string))
    {
        Usage(playerid, "/setstock <name> <stock>");
        Names(playerid, "[material], [component], [product], [food], [marijuana], [ephedrine], [cocaine], [gandum], [daging], [susu]");
        return 1;
    }
	if(!strcmp(name, "material", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock (material) (stok)");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Material = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'MATERIAL' {FFFFFF}ti %d", pData[playerid][pAdminname], stok);
    }
	else if(!strcmp(name, "component", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <component> <stok>");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Component = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'COMPONENT' {FFFFFF}ti %d", pData[playerid][pAdminname], stok);
    }
	else if(!strcmp(name, "product", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <product> <stok>");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Product = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'PRODUCT' {FFFFFF}ti %d", pData[playerid][pAdminname], stok);
    }
	else if(!strcmp(name, "apotek", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <apotek> <stok>");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Apotek = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'APOTEK' {FFFFFF}ti %d", pData[playerid][pAdminname], stok);
    }
	else if(!strcmp(name, "food", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <food> <stok>");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Food = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'FOOD' {FFFFFF}ti %d", pData[playerid][pAdminname], stok);
    }
    else if(!strcmp(name, "gandum", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <gandum> <stok>");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Gandum = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'GANDUM' {FFFFFF}ti %d", pData[playerid][pAdminname], stok);
    }
    else if(!strcmp(name, "daging", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <daging> <stok>");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Daging = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'DAGING' {FFFFFF}ti %d", pData[playerid][pAdminname], stok);
    }
    else if(!strcmp(name, "marijuana", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <marijuana> <stok>");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Marijuana = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'MARIJUANA' {FFFFFF}ti %d", pData[playerid][pAdminname], stok);
    }
    else if(!strcmp(name, "ephedrine", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <ephedrine> <stok>");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Ephedrine = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'EPHEDRINE' {FFFFFF}ti %d", pData[playerid][pAdminname], stok);
    }
    else if(!strcmp(name, "cocaine", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <cocaine> <stok>");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Cocaine = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'COCAINE' {FFFFFF}ti %d.", pData[playerid][pAdminname], stok);
    }
    else if(!strcmp(name, "susu", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <susu> <stok>");

        if(stok < 0 || stok > 50000)
            return Error(playerid, "You can only change from 0 to 50000.");

        Susu = stok;
		Server_Save();
        SendAdminMessage(COLOR_RED, "Admin {A60000}%s {FFFFFF}change stock {FFFF00}'SUSU' {FFFFFF}ti %d.", pData[playerid][pAdminname], stok);
    }
	else if(!strcmp(name, "server", true))
    {
		new stok;
        if(sscanf(string, "d", stok))
            return Usage(playerid, "/setstock <server> <stok>");

        if(stok < 0 || stok > 5000000000)
            return Error(playerid, "You can only change from 0 to 5000000000");

        ServerMoney = stok;
		Server_Save();
        SendAdminMessage(-1, "Admin {A60000}%s {FFFFFF}changed stock {FFFF00}'SERVER MONEY' {FFFFFF}to %d.", pData[playerid][pAdminname], stok);
    }
	return 1;
}

CMD:kickall(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
		
	foreach(new pid : Player)
	{
		if(pid != playerid)
		{
			UpdateWeapons(playerid);
			UpdatePlayerData(playerid);
			Servers(pid, "Sorry, the server is currently experiencing a storm");
			Servers(pid, "{FFFF00}Your {FFFFFF}database information has been successfully saved");
			KickEx(pid);
		}
	}
	return 1;
}

CMD:playsong(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new songname[1024], Float:x, Float:y, Float:z;
	if(sscanf(params, "s[1024]", songname))
		return Usage(playerid, "/playsong <link>");

	
	GetPlayerPos(playerid, x, y, z);
	foreach(new ii : Player)
	{
		if(IsPlayerInRangeOfPoint(ii, 35.0, x, y, z))
		{
			PlayAudioStreamForPlayer(ii, songname);
			Servers(ii, "%s", songname);
			Servers(ii, "/stopsong");
		}
	}
	return 1;
}

CMD:playnearsong(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new songname[1024], Float:x, Float:y, Float:z;
	if(sscanf(params, "s[1024]", songname))
		return Usage(playerid, "/playnearsong <link>");
	
	GetPlayerPos(playerid, x, y, z);
	foreach(new ii : Player)
	{
		if(IsPlayerInRangeOfPoint(ii, 35.0, x, y, z))
		{
			PlayAudioStreamForPlayer(ii, songname, x, y, z, 35.0, 1);
			Servers(ii, "%s", songname);
			Servers(ii, "/stopsong");
		}
	}
	return 1;
}

CMD:stopsong(playerid, params[])
{
	StopAudioStreamForPlayer(playerid);
	Servers(playerid, "Song stop!");
	return 1;
}

CMD:majucik(playerid, params[])
{
	new Float:x, Float:y, Float:z;
	
	// Dapatkan posisi pemain saat ini
	GetPlayerPos(playerid, x, y, z);
	
	// Variabel mengatur arah berdasarkan orientasi pemain
	new Float:angle;
	GetPlayerFacingAngle(playerid, angle);
	
	// Hitung posisi baru (dalam arah hadap pemain)
	x += 2.0 * floatsin(-angle, degrees);
	y += 2.0 * floatcos(-angle, degrees);
	
	// Pindahkan pemain ke posisi baru
	SetPlayerPos(playerid, x, y, z);
	
	// Pesan konfirmasi
	SendClientMessage(playerid, 0x00FF00FF, "You've broken through the wall!");
	return 1;
}


CMD:mypos(playerid, params[])
{
	new int, Float:px,Float:py,Float:pz, Float:a;
	GetPlayerPos(playerid, px, py, pz);
	GetPlayerFacingAngle(playerid, a);
	int = GetPlayerInterior(playerid);
	new zone[MAX_ZONE_NAME];
	GetPlayer3DZone(playerid, zone, sizeof(zone));
	SendClientMessageEx(playerid, COLOR_WHITE, "Your Current Location: %s (%0.2f, %0.2f, %0.2f, %0.2f) Int = %d", zone, px, py, pz, a, int);
	printf("Your Current Location: %s (%0.2f, %0.2f, %0.2f, %0.2f) Int = %d", zone, px, py, pz, a, int);
	return 1;
}

CMD:ainv(playerid, params[])
{
	if (pData[playerid][pAdmin] < 4)
	    return PermissionError(playerid);
	    
	new targetid;
	if(sscanf(params, "u", targetid))
	    return SyntaxMsg(playerid, "/ainv <PlayerID/PartOfName>");
	    
	if(targetid == INVALID_PLAYER_ID)
	    return ErrorMsg(playerid, "The player you entered is invalid");
	    
	CreatePlayerInventoryTD(targetid);
	return 1;
}

CMD:togadminchat(playerid, const params[])
{
	if (pData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);
	if(!pData[playerid][pTogAdminchat])
	{
		pData[playerid][pTogAdminchat] = 1;
		Info(playerid, "You have disabled Admin Chat");
	}
	else
	{
		pData[playerid][pTogAdminchat] = 0;
		Info(playerid, "You have activated Admin Chat");
	}
	return 1;
}

CMD:togreport(playerid, const params[])
{
	if (pData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);
	if(!pData[playerid][pTogReport])
	{
		pData[playerid][pTogReport] = 1;
		Info(playerid, "You have disabled Report logs");
	}
	else
	{
		pData[playerid][pTogReport] = 0;
		Info(playerid, "You have enabled Report logs");
	}
	return 1;
}

CMD:togask(playerid, const params[])
{
	if (pData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);
	if(!pData[playerid][pTogAsk])
	{
		pData[playerid][pTogAsk] = 1;
		Info(playerid, "You have disabled Ask logs");
	}
	else
	{
		pData[playerid][pTogAsk] = 0;
		Info(playerid, "You have enabled Ask logs");
	}
	return 1;
}

CMD:asettings(playerid, params[])
{
	if (pData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);

	if(pData[playerid][IsLoggedIn] == false)
	{
	    Error(playerid, "You must be logged in!");
	    return 1;
	}
	
	new str[1024], togreport[64], togask[64], togachat[64];
	if(pData[playerid][pTogReport] == 0)
	{
		togreport = ""RED_E"Disable";
	}
	else
	{
		togreport = ""LG_E"Enable";
	}
	
	if(pData[playerid][pTogAsk] == 0)
	{
		togask = ""RED_E"Disable";
	}
	else
	{
		togask = ""LG_E"Enable";
	}
	
	if(pData[playerid][pTogAdminchat] == 0)
	{
		togachat = ""RED_E"Disable";
	}
	else
	{
		togachat = ""LG_E"Enable";
	}
	
	format(str, sizeof(str), "Name\tStatus\n"WHITEP_E"Report Logs:\t%s\n"WHITEP_E"Ask Logs:\t%s\n"WHITEP_E"Admin Chat:\t%s",
	togreport,
	togask,
	togachat
	);
	
	ShowPlayerDialog(playerid, DIALOG_ASETTINGS, DIALOG_STYLE_TABLIST_HEADERS, "Admin Settings", str, "Set", "Close");
	return 1;
}

CMD:setnomor(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
	    return PermissionError(playerid);

	new number, otherid;
	if(sscanf(params, "ud", otherid, number))
		return Usage(playerid, "/setnomor <playerid> <number>");

	if(otherid == playerid)
		return Error(playerid, "The player you entered is invalid");

	if(number < 1 || number > 99999999999)
		return Error(playerid, "You can only get 3 to 6 numbers");

	new cQuery[254];
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "SELECT phone FROM players WHERE phone = '%d'", number);
	mysql_tquery(g_SQL, cQuery, "AdminSetNumber", "id", playerid, number);
	return 1;
}

CMD:aclaimpv(playerid, params[]) 
{
    new bool:found = false, msg2[512], targetid;
    if (pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);

    if (sscanf(params, "u", targetid))
        return Usage(playerid, "/aclaimpv [playerid/PartOfName]");

    if (targetid == INVALID_PLAYER_ID)
        return Error(playerid, "Player ID tidak valid");

    SetPVarInt(playerid, "forceinsurance", targetid);
    new pelir[128];
    format(pelir, sizeof(pelir), "%s Insurance's", GetName(targetid));
    format(msg2, sizeof(msg2), "Model\tPlate\n");
    foreach(new vehid : PVehicles)
    {
        if (pvData[vehid][cClaim] == 1) 
        {
            if (Vehicle_IsOwner(targetid, vehid)) 
            {
                format(msg2, sizeof(msg2), "%s%s\t%s\n", msg2, GetVehicleModelName(pvData[vehid][cModel]), pvData[vehid][cPlate]);
                found = true;
            }
        }
    }
    if (found)
        ShowPlayerDialog(playerid, VEHICLE_INSURANCEADMIN, DIALOG_STYLE_TABLIST_HEADERS, pelir, msg2, "Force", "Close");
    else
        ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, pelir, "No vehicle insurance", "Close", "");
    return 1;
}
new AskelTime;
CMD:askel(playerid, params[])
{
	if (pData[playerid][pAdmin] < 3)
        return PermissionError(playerid);

	new seconds;
	if (sscanf(params, "i", seconds))
		return Usage(playerid, "/askel [detik]");

	AskelTime = seconds;
	SendStaffMessage(COLOR_LRED, "%s memulai ansuransi keliling dengan waktu %d detik", pData[playerid][pAdminname], seconds);
	return 1;
}

stock AskelCheck(playerid)
{
	if (AskelTime > 0)
	{
		AskelTime--;
		new string[256];
		for (new i; i < 11; i ++)
		{
			TextDrawShowForPlayer(playerid, Askel@Global[i]);
		}
		format(string, sizeof(string), "Seluruh kendaraan kosong akan dimasukkan ke asuransi dalam y%d detik", AskelTime);
		TextDrawSetString(Askel@Global[4], string);
	}
	else if (AskelTime == 0)
	{
		AskelTime = -1;
		for (new i; i < 11; i ++)
		{
			TextDrawHideForPlayer(playerid, Askel@Global[i]);
		}
		foreach(new ii : PVehicles) if(IsValidVehicle(pvData[ii][cVeh]))
		{
			if (!IsVehicleEmpty(pvData[ii][cVeh])) continue;

			pvData[ii][cClaim] = 1;
			pvData[ii][cClaimTime] = gettime() + (1 * 60);
			foreach(new pid : Player)
			{
				if(pvData[ii][cOwner] == pData[pid][pID])
				{
					Info(pid, "Kendaraan anda di ansuransikan, pergi ke kantor asuransi untuk mengembalikan kendaraan {00FF00}'/myinsu'");
				}
				RemoveVehicleToys(pvData[ii][cVeh]);
				if(IsValidVehicle(pvData[ii][cVeh])) DestroyVehicle(pvData[ii][cVeh]);

				pvData[ii][cVeh] = INVALID_VEHICLE_ID;
			}
		}
	}
}
