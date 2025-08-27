function RespawnSignal(id)
{
	new string[96];
	if(sgData[id][sgSeconds] > 1) 
	{
	    sgData[id][sgSeconds]--;
	    
		format(string, sizeof(string), "[SIGNAL ID: %d]\n"WHITE_E"Signal Status: {ff0000}Troubled\n"WHITE_E"Fixxing In: "GREEN_LIGHT"%s", id, ConvertToMinutes(sgData[id][sgSeconds]));
		UpdateDynamic3DTextLabelText(sgData[id][sgLabel], COLOR_YELLOW, string);
	}
	else if(sgData[id][sgSeconds] == 1) 
	{
	    KillTimer(sgData[id][sgTimer]);

	    sgData[id][sgSeconds] = 0;
	    sgData[id][sgTimer] = -1;
	    sgData[id][sgStatus] = 0;

	    Signal_Refresh(id);
	    Signal_Save(id);
	}
	return 1;
}

function LoadSignal()
{
    static sgid;
	
	new rows = cache_num_rows();
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", sgid);
			cache_get_value_name_int(i, "status", sgData[sgid][sgStatus]);
			cache_get_value_name_float(i, "posx", sgData[sgid][sgX]);
			cache_get_value_name_float(i, "posy", sgData[sgid][sgY]);
			cache_get_value_name_float(i, "posz", sgData[sgid][sgZ]);

			cache_get_value_name_float(i, "posrx", sgData[sgid][sgRX]);
			cache_get_value_name_float(i, "posry", sgData[sgid][sgRY]);
			cache_get_value_name_float(i, "posrz", sgData[sgid][sgRZ]);

			cache_get_value_name_int(i, "interior", sgData[sgid][sgInt]);
			cache_get_value_name_int(i, "world", sgData[sgid][sgVW]);
			if(sgData[sgid][sgStatus] == 1)
			{
				sgData[sgid][sgSeconds] = 60 * 20;
			}
			Signal_Refresh(sgid);
			Iter_Add(Signal, sgid);
		}
		printf("[DATABASE] Number of tower Loaded: %d.", rows);
		//Profiler_Stop();
	}
}

function OnSignalCreated(sgid)
{
	Signal_Save(sgid);
	return 1;
}