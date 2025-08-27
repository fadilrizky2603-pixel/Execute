Gate_Save(id)
{
	new dquery[2048];
	mysql_format(g_SQL, dquery, sizeof(dquery), "UPDATE gates SET model='%d', password='%s', admin='%d', vip='%d', faction='%d', family='%d', speed='%f', cX='%f', cY='%f', cZ='%f', cRX='%f', cRY='%f', cRZ='%f', oX='%f', oY='%f', oZ='%f', oRX='%f', oRY='%f', oRZ='%f' WHERE ID='%d'",
	gData[id][gModel], gData[id][gPass], gData[id][gAdmin], gData[id][gVip], gData[id][gFaction], gData[id][gFamily], gData[id][gSpeed], gData[id][gCX], gData[id][gCY], gData[id][gCZ], gData[id][gCRX], gData[id][gCRY], gData[id][gCRZ], gData[id][gOX], gData[id][gOY], gData[id][gOZ], gData[id][gORX], gData[id][gORY], gData[id][gORZ], id);
	mysql_tquery(g_SQL, dquery);
	return 1;
}

