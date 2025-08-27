function LoadGarkot()
{
    new rows = cache_num_rows();
    if (rows == 0) 
    {
        printf("[DATABASE] No Garkot data found.");
        return;
    }

    for (new i = 0; i < rows; i++) 
    {
        new gkid;
        cache_get_value_name_int(i, "id", gkid);

        if (gkid < 0 || gkid >= MAX_GARKOT) // Pastikan ID valid
            continue;

        cache_get_value_name_float(i, "posx", gkData[gkid][gkX]);
        cache_get_value_name_float(i, "posy", gkData[gkid][gkY]);
        cache_get_value_name_float(i, "posz", gkData[gkid][gkZ]);
        cache_get_value_name_float(i, "posa", gkData[gkid][gkA]);
        cache_get_value_name_float(i, "spawnx", gkData[gkid][sgkX]);
        cache_get_value_name_float(i, "spawny", gkData[gkid][sgkY]);
        cache_get_value_name_float(i, "spawnz", gkData[gkid][sgkZ]);
        cache_get_value_name_float(i, "spawna", gkData[gkid][sgkA]);
        cache_get_value_name_int(i, "interior", gkData[gkid][gkInt]);
        cache_get_value_name_int(i, "world", gkData[gkid][gkVW]);

        // Segera refresh data setelah pengambilan
        Garkot_Refresh(gkid);
        Iter_Add(Garkot, gkid);
    }

    printf("[DATABASE] Number of Garkot Loaded: %d.", rows);
}

