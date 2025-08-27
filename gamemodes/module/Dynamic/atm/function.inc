function LoadATM()
{
	new rows;
	cache_get_row_count(rows);
	if(rows)
  	{
 		new id, i = 0;
		while(i < rows)
		{
		    cache_get_value_name_int(i, "id", id);
			cache_get_value_name_float(i, "posx", AtmData[id][atmX]);
			cache_get_value_name_float(i, "posy", AtmData[id][atmY]);
			cache_get_value_name_float(i, "posz", AtmData[id][atmZ]);
			cache_get_value_name_float(i, "posrx", AtmData[id][atmRX]);
			cache_get_value_name_float(i, "posry", AtmData[id][atmRY]);
			cache_get_value_name_float(i, "posrz", AtmData[id][atmRZ]);
			cache_get_value_name_int(i, "interior", AtmData[id][atmInt]);
			cache_get_value_name_int(i, "world", AtmData[id][atmWorld]);
			cache_get_value_name_int(i, "status", AtmData[id][atmStatus]);
			Atm_Refresh(id);
			Iter_Add(ATMS, id);
	    	i++;
		}
		printf("[DATABASE] Number of Loaded: %d.", i);
		//Profiler_Dump();
	}
}

function OnAtmCreated(playerid, id)
{
	Atm_Save(id);
	Servers(playerid, "You has created ATM id: %d.", id);
	return 1;
}

function RobbingAtm(playerid, atmid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	{
		{
			if(IsPlayerInRangeOfPoint(playerid, 4.5, AtmData[atmid][atmX], AtmData[atmid][atmY], AtmData[atmid][atmZ]))
			{
				if(pData[playerid][pRobAtmProgres] == -1)
				{
					TogglePlayerControllable(playerid, 1);
					Info(playerid, "Kamu berhasil membobol mesin ATM!");
					Info(playerid, "Gunakan /robatm sekali lagi untuk mengambil uang di mesin atm!");
					pData[playerid][pRobAtmProgres] = 0;
				}
				else
				{
					new stok = RandomEx(1000, 10000);
					TogglePlayerControllable(playerid, 1);
					GivePlayerMoneyEx(playerid, stok);
					Info(playerid, "Kamu berhasil mendapatkan uang "GREEN_E"%s"WHITE_E" dari mesin ATM", FormatMoney(stok));
					AtmData[atmid][atmStatus] = 1;
					Atm_Refresh(atmid);
					Atm_Save(atmid);

					if(pData[playerid][pRobLeader] == 1)
					{
						foreach(new ii : Player) 
						{
							if(pData[ii][pMemberRob] == playerid)
							{
								Servers(ii, "* Pemimpin Perampokan anda telah berhasil mengambil uang dari mesin atm!");
								pData[ii][pMemberRob] = -1;
								pData[ii][pRobLeader] = -1;
								pData[ii][pRobMember] = 0;

								pData[ii][pRobbing] = 1;
								pData[ii][pRobbingTime] = gettime() + (120 * 1);
							}
						}
					}
					pData[playerid][pMemberRob] = -1;
					pData[playerid][pRobLeader] = -1;
					pData[playerid][pRobMember] = 0;
					pData[playerid][pRobbing] = 1;
					pData[playerid][pRobbingTime] = gettime() + (120 * 1);
				}
			}
		}
	}
	return 1;
}