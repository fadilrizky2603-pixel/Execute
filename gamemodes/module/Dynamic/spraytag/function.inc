function OnSprayTagCreated(id)
{
	TagData[id][tagID] = cache_insert_id();
	Tag_Save(id);
}

function Tag_Load()
{
	if(cache_num_rows())
	{
		forex(i, cache_num_rows())
		{
			cache_get_value_name_int(i, "ID", TagData[i][tagID]);
			cache_get_value_name_float(i, "PosX", TagData[i][tagPos][0]);
			cache_get_value_name_float(i, "PosY", TagData[i][tagPos][1]);
			cache_get_value_name_float(i, "PosZ", TagData[i][tagPos][2]);
			cache_get_value_name_float(i, "RotX", TagData[i][tagPos][3]);
			cache_get_value_name_float(i, "RotY", TagData[i][tagPos][4]);
			cache_get_value_name_float(i, "RotZ", TagData[i][tagPos][5]);
			cache_get_value_name(i, "Text", TagData[i][tagText], 64);
			cache_get_value_name(i, "Font", TagData[i][tagFont], 24);
			cache_get_value_name_int(i, "Interior", TagData[i][tagInterior]);
			cache_get_value_name_int(i, "World", TagData[i][tagWorld]);
			cache_get_value_name_int(i, "Color", TagData[i][tagColor]);
			cache_get_value_name_int(i, "Bold", TagData[i][tagBold]);
			cache_get_value_name_int(i, "Size", TagData[i][tagSize]);
			cache_get_value_name_int(i, "Owner", TagData[i][tagOwner]);
			Iter_Add(SprayTag, i);
			Tag_Spawn(i);
		}
		printf("[DATABASE] Loaded %d spraytags from database", cache_num_rows());
		//Profiler_Stop();
	}
	return 1;
}