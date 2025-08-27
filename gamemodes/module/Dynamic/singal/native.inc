Signal_Save(id)
{
	new cQuery[2248];
	format(cQuery, sizeof(cQuery), "UPDATE sigenal SET status='%d', posx='%f', posy='%f', posz='%f', posrx='%f', posry='%f', posrz='%f', interior='%d', world='%d' WHERE id='%d'",
	sgData[id][sgStatus],
	sgData[id][sgX],
	sgData[id][sgY],
	sgData[id][sgZ],
	sgData[id][sgRX],
	sgData[id][sgRY],
	sgData[id][sgRZ],
	sgData[id][sgInt],
	sgData[id][sgVW],
	id);

	return mysql_tquery(g_SQL, cQuery);
}

Signal_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamicObject(sgData[id][sgObj]))
			DestroyDynamicObject(sgData[id][sgObj]);

		if(IsValidDynamic3DTextLabel(sgData[id][sgLabel]))
			DestroyDynamic3DTextLabel(sgData[id][sgLabel]);

		static
		 string[1024], 
		  status[128];

		if(sgData[id][sgStatus] == 0)
		{
			status = "{00ff00}Good";
		}
		else if(sgData[id][sgStatus] == 1)
		{
			status = "{ff0000}Troubled";
		}
		else
		{
			status = "{ff0000}Unknown";
		}
		if(sgData[id][sgStatus] == 0)
		{
			sgData[id][sgObj] = CreateDynamicObject(3876, sgData[id][sgX], sgData[id][sgY], sgData[id][sgZ], sgData[id][sgRX], sgData[id][sgRY], sgData[id][sgRZ], sgData[id][sgVW], sgData[id][sgInt], -1, 90.0, 90.0);
			format(string, sizeof(string), "[SIGNAL ID: %d]\n"WHITE_E"Signal Status: %s\n"WHITE_E"Signal Location: "GREEN_LIGHT"%s", id, status, GetLocation(sgData[id][sgX], sgData[id][sgY], sgData[id][sgZ]));
			sgData[id][sgLabel] = CreateDynamic3DTextLabel(string, COLOR_YELLOW, sgData[id][sgX], sgData[id][sgY], sgData[id][sgZ]+3.5, 15.0);
		}
		else
		{
			sgData[id][sgTimer] = SetTimerEx("RespawnSignal", 1000, true, "i", id);

			sgData[id][sgObj] = CreateDynamicObject(3876, sgData[id][sgX], sgData[id][sgY], sgData[id][sgZ], sgData[id][sgRX], sgData[id][sgRY], sgData[id][sgRZ], sgData[id][sgVW], sgData[id][sgInt], -1, 90.0, 90.0);

		    format(string, sizeof(string), "[SIGNAL ID: %d]\n"WHITE_E"Signal Status: %s\n"WHITE_E"Fixxing In: "GREEN_LIGHT"%s", id, status, ConvertToMinutes(sgData[id][sgSeconds]));
			sgData[id][sgLabel] = CreateDynamic3DTextLabel(string, COLOR_YELLOW, sgData[id][sgX], sgData[id][sgY], sgData[id][sgZ]+3.5, 15.0);
			UpdateDynamic3DTextLabelText(sgData[id][sgLabel], COLOR_YELLOW, string);
		}
	}
	return 1;
}


Signal_BeingEdited(sgid)
{
	if(!Iter_Contains(Signal, sgid)) return 0;
	foreach(new i : Player) if(pData[i][pEditing] == sgid) return 1;
	return 0;
}

GetSignalNearest(playerid)
{
    new tmpcount;
    foreach(new id : Signal)
    {
        if(sgData[id][sgStatus] == 0)
        {
            if(GetPlayerDistanceFromPoint(playerid, sgData[id][sgX], sgData[id][sgY], sgData[id][sgZ]) < 10000)
            {
                 tmpcount++;
             }
             else if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
            {
                tmpcount++;
            }
        }
    }
    return tmpcount;
}

GetAdminSignal()
{
	new tmpcount;
	foreach(new id : Signal)
	{
    	tmpcount++;
    }
	return tmpcount;
} 

ReturnAdminSignalID(slot)
{
	new tmpcount;
	if(slot < 1 && slot > MAX_SIGNAL) return -1;
	foreach(new id : Signal)
	{
    	tmpcount++;
       	if(tmpcount == slot)
       	{
        	return id;
  		}
	}
	return -1;
}