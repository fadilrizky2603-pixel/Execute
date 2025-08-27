Speedcam_Save(id)
{
	new dquery[2048];
	format(dquery, sizeof(dquery), "UPDATE speedcam SET camx='%f', camy='%f', camz='%f', camrx='%f', camry='%f', camrz='%f', camworld='%d', camint='%d', camspeed='%d' WHERE ID='%d'",
	camData[id][camX],
	camData[id][camY],
	camData[id][camZ],
	camData[id][camRX],
	camData[id][camRY],
	camData[id][camRZ],
	camData[id][camWorld],
	camData[id][camInt],
	camData[id][camSpeed],
	id);

	return mysql_tquery(g_SQL, dquery);
}

Speedcam_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamicObject(camData[id][camObj]))
			DestroyDynamicObject(camData[id][camObj]);

		if(IsValidDynamic3DTextLabel(camData[id][camLabel]))
			DestroyDynamic3DTextLabel(camData[id][camLabel]);

		new tstr[1024];
		format(tstr, sizeof(tstr), "[SPEEDCAM ID: %d]\n{ffffff}Speedcam Location: {00ff00}%s\n{ffffff}Max Speed: {00ff00}%d/Mph", id, GetLocation(camData[id][camX], camData[id][camY], camData[id][camZ]), camData[id][camSpeed]);
        camData[id][camObj] = CreateDynamicObject(18880, camData[id][camX], camData[id][camY], camData[id][camZ], camData[id][camRX], camData[id][camRY], camData[id][camRZ], camData[id][camWorld], camData[id][camInt], -1, 90.0, 90.0);
       	camData[id][camLabel] = CreateDynamic3DTextLabel(tstr, COLOR_YELLOW, camData[id][camX], camData[id][camY], camData[id][camZ]+3.5, 5.0);
	}		
	return 1;
}

Speedcam_BeingEdited(camid)
{
	if(!Iter_Contains(Speedcam, camid)) return 0;
	foreach(new i : Player) if(pData[i][pEditing] == camid) return 1;
	return 0;
}