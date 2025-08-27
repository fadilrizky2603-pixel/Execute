function LoadNpcfam()
{
	static nfid;
	
	new rows = cache_num_rows();
	if(rows)
	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", nfid);
			cache_get_value_name_int(i, "owner", nfData[nfid][nfOwner]);
			cache_get_value_name_int(i, "type", nfData[nfid][nfType]);

			cache_get_value_name_float(i, "posx", nfData[nfid][nfPosX]);
			cache_get_value_name_float(i, "posy", nfData[nfid][nfPosY]);
			cache_get_value_name_float(i, "posz", nfData[nfid][nfPosZ]);
			cache_get_value_name_float(i, "posa", nfData[nfid][nfPosA]);

			cache_get_value_name_int(i, "world", nfData[nfid][nfVw]);
			cache_get_value_name_int(i, "interior", nfData[nfid][nfInt]);

			cache_get_value_name_int(i, "money", nfData[nfid][nfMoney]);
			cache_get_value_name_int(i, "material", nfData[nfid][nfMaterial]);
			cache_get_value_name_int(i, "marijuana", nfData[nfid][nfMarijuana]);
			cache_get_value_name_int(i, "cocaine", nfData[nfid][nfCocaine]);
			cache_get_value_name_int(i, "meth", nfData[nfid][nfMeth]);

			cache_get_value_name_int(i, "price0", nfData[nfid][nfPrice][0]);
			cache_get_value_name_int(i, "price1", nfData[nfid][nfPrice][1]);
			cache_get_value_name_int(i, "price2", nfData[nfid][nfPrice][2]);
			cache_get_value_name_int(i, "price3", nfData[nfid][nfPrice][3]);
			cache_get_value_name_int(i, "price4", nfData[nfid][nfPrice][4]);
			cache_get_value_name_int(i, "price5", nfData[nfid][nfPrice][5]);
			cache_get_value_name_int(i, "price6", nfData[nfid][nfPrice][6]);
			cache_get_value_name_int(i, "price7", nfData[nfid][nfPrice][7]);
			Npcfam_Refresh(nfid);
			Iter_Add(NPCFam, nfid);
		}
		printf("[DATABASE] Number of npc family Loaded: %d.", rows);
		//Profiler_Stop();
	}
}

function OnNpcfamCreated(id)
{
	Npcfam_Save(id);
	return 1;
}