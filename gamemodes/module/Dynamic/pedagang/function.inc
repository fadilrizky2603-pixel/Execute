function LoadPedagang()
{
    static pid;
    
    new rows = cache_num_rows();
    if(rows)
    {
        for(new i; i < rows; i++)
        {
            cache_get_value_name_int(i, "id", pid);
            cache_get_value_name_int(i, "type", pdgDATA[pid][pdgType]);
            cache_get_value_name_float(i, "posx", pdgDATA[pid][pdgPosX]);
            cache_get_value_name_float(i, "posy", pdgDATA[pid][pdgPosY]);
            cache_get_value_name_float(i, "posz", pdgDATA[pid][pdgPosZ]);
            cache_get_value_name_int(i, "interior", pdgDATA[pid][pdgInt]);
            cache_get_value_name_int(i, "gandum", pdgDATA[pid][pdgGandum]);
            cache_get_value_name_int(i, "daging", pdgDATA[pid][pdgDaging]);
            cache_get_value_name_int(i, "susuolah", pdgDATA[pid][pdgSusuolah]);
            cache_get_value_name_int(i, "burger", pdgDATA[pid][pdgBurger]);
            cache_get_value_name_int(i, "roti", pdgDATA[pid][pdgRoti]);
            cache_get_value_name_int(i, "steak", pdgDATA[pid][pdgSteak]);
            cache_get_value_name_int(i, "milk", pdgDATA[pid][pdgMilk]);
            cache_get_value_name_int(i, "kentang", pdgDATA[pid][pdgKentang]);
            cache_get_value_name_int(i, "orange", pdgDATA[pid][pdgOrange]);
            cache_get_value_name_int(i, "food", pdgDATA[pid][pdgFood]);
            Pedagang_Refresh(pid);
            Iter_Add(Pedagang, pid);
        }
        printf("[DATABASE] Number of storage cafe Loaded: %d.", rows);
        //Profiler_Stop();
    }
}

function OnPedagangCreated(pid)
{
    Pedagang_Save(pid);
    return 1;
}