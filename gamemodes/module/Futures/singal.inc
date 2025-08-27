




//--------------[SIGNAL COMMAND]--------------












/*
DIALOG_ADMIN_SIGNAL






pData[playerid][EditingSIGNAL] = -1;







	mysql_tquery(g_SQL, "SELECT * FROM `sigenal`", "LoadSignal");







	if(dialogid == DIALOG_ADMIN_SIGNAL)
	{
		if(!response)
			return 1;

		new sgid = ReturnAdminSignalID(listitem+1);

		if(sgData[sgid][sgStatus] == 0)
		{
			sgData[sgid][sgSeconds] = 1800;
			sgData[sgid][sgStatus] = 1;
	        Signal_Save(sgid);
			Signal_Refresh(sgid);

			Info(playerid, "Sinyal ID: %d berhasil dimatikan", sgid);
		}
		else
        {
        	KillTimer(sgData[sgid][sgTimer]);
		    sgData[sgid][sgSeconds] = 0;
	    	sgData[sgid][sgTimer] = -1;
			sgData[sgid][sgStatus] = 0;

	        Signal_Save(sgid);
			Signal_Refresh(sgid);

			Info(playerid, "Sinyal ID: %d berhasil diperbaiki", sgid);
		}
	}
	return 1;
}
	
*/