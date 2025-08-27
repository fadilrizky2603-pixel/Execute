function LoadActor()
{
	new rows = cache_num_rows();
 	if(rows)
  	{
   		new actid, actname[128];
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", actid);
			cache_get_value_name(i, "name", actname);
			format(ActData[actid][actName], 128, actname);
			cache_get_value_name_int(i, "bizid", ActData[actid][actBizid]);
			cache_get_value_name_int(i, "skinid", ActData[actid][actSkin]);
			cache_get_value_name_float(i, "posx", ActData[actid][actX]);
			cache_get_value_name_float(i, "posy", ActData[actid][actY]);
			cache_get_value_name_float(i, "posz", ActData[actid][actZ]);
			cache_get_value_name_float(i, "posa", ActData[actid][actA]);
			cache_get_value_name_int(i, "vuln", ActData[actid][actVuln]);
			cache_get_value_name_int(i, "interior", ActData[actid][actInt]);
			cache_get_value_name_int(i, "world", ActData[actid][actVW]);
			cache_get_value_name_int(i, "anim", ActData[actid][actAnim]);
			Actor_Refresh(actid);
			Iter_Add(Actors, actid);
		}
		printf("[DATABASE] Number of Actor loaded: %d.", rows);
		//Profiler_Dump();
	}
}

function OnActorCreated(actid)
{
	Actor_Save(actid);
	return 1;
}