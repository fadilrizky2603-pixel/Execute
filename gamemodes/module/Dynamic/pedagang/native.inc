Pedagang_Refresh(pid)
{
    if(pid != -1)
    {
        if(IsValidDynamic3DTextLabel(pdgDATA[pid][pdgLabel]))
            DestroyDynamic3DTextLabel(pdgDATA[pid][pdgLabel]);

        if(IsValidDynamicPickup(pdgDATA[pid][pdgPickup]))
            DestroyDynamicPickup(pdgDATA[pid][pdgPickup]);

        if(IsValidDynamicArea(pdgDATA[pid][pdgAmbilarea]))
            DestroyDynamicArea(pdgDATA[pid][pdgAmbilarea]);

        static
        string[255];
        
        new type[128];
        if(pdgDATA[pid][pdgType] == 1)
        {
            type= "Gudang Pedagang";
        }
        else
        {
            type= "Unknown";
        }

        format(string, sizeof(string), "[ID: %d]\nType: %s\nPress {FFFF00}[Y] {FFFFFF}atau {FFFF00}'/gudangpedagang'\n", pid, type);
        pdgDATA[pid][pdgLabel] = CreateDynamic3DTextLabel(string, -1, pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ]+0.5, 2.5);
        pdgDATA[pid][pdgPickup] = CreateDynamicPickup(1239, 23, pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ]+0.2, 0, pdgDATA[pid][pdgInt], _, 4);
        pdgDATA[pid][pdgAmbilarea] = CreateDynamicCircle(pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], 1.0, 0, pdgDATA[pid][pdgInt], -1);


        /*if(pData[playerid][pFaction] == 5)
        {
            if(!pData[playerid][pOndutysacf])
            {
                format(string, sizeof(string), "[ID: %d]", pid, type);
                pdgDATA[pid][pdgLabel] = CreateDynamic3DTextLabel(string, COLOR_BLUE, pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ]+0.5, 2.5);
                pdgDATA[pid][pdgObject] = CreateDynamicObject(1316, pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ]-1, 0.0, 0.0, 0.0, 0, pdgDATA[pid][pdgInt], -1, 15.00, 15.00);
                SetDynamicObjectMaterial(pdgDATA[pid][pdgObject], 0, 18646, "matcolours", "white", 0x9900FF00);
                pdgDATA[pid][pdgAmbilarea] = CreateDynamicCircle(pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], 1.0, 0, pdgDATA[pid][pdgInt], -1);
            }
        }*/
    }
    return 1;
}

Pedagang_Save(pid)
{
    new cQuery[512];
    format(cQuery, sizeof(cQuery), "UPDATE pedagang SET type='%d', posx='%f', posy='%f', posz='%f', interior='%d', gandum='%d', daging='%d', susuolah='%d', burger='%d', roti='%d', steak='%d', milk='%d', kentang='%d', orange='%d', food='%d' WHERE id='%d'",
    pdgDATA[pid][pdgType],
    pdgDATA[pid][pdgPosX],
    pdgDATA[pid][pdgPosY],
    pdgDATA[pid][pdgPosZ],
    pdgDATA[pid][pdgInt],
    pdgDATA[pid][pdgGandum],
    pdgDATA[pid][pdgDaging],
    pdgDATA[pid][pdgSusuolah],
    pdgDATA[pid][pdgBurger],
    pdgDATA[pid][pdgRoti],
    pdgDATA[pid][pdgSteak],
    pdgDATA[pid][pdgMilk],
    pdgDATA[pid][pdgKentang],
    pdgDATA[pid][pdgOrange],
    pdgDATA[pid][pdgFood],
    pid
    );
    return mysql_tquery(g_SQL, cQuery);
}