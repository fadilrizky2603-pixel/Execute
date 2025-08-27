MySQL_LoadPlayerToys(playerid)
{
	new tstr[512];
	mysql_format(g_SQL, tstr, sizeof(tstr), "SELECT * FROM toys WHERE Owner='%s' LIMIT 1", pData[playerid][pName]);
	mysql_tquery(g_SQL, tstr, "LoadPlayerToys", "i", playerid);
}

MySQL_CreatePlayerToy(playerid)
{
	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `toys` (`Owner`) VALUES ('%s');", pData[playerid][pName]);
	mysql_tquery(g_SQL, query);
	pData[playerid][PurchasedToy] = true;

	for(new i = 0; i < 4; i++)
	{
		pToys[playerid][i][toy_model] = 0;
		pToys[playerid][i][toy_bone] = 1;
		pToys[playerid][i][toy_hide] = 0;
		pToys[playerid][i][toy_x] = 0.0;
		pToys[playerid][i][toy_y] = 0.0;
		pToys[playerid][i][toy_z] = 0.0;
		pToys[playerid][i][toy_rx] = 0.0;
		pToys[playerid][i][toy_ry] = 0.0;
		pToys[playerid][i][toy_rz] = 0.0;
		pToys[playerid][i][toy_sx] = 1.0;
		pToys[playerid][i][toy_sy] = 1.0;
		pToys[playerid][i][toy_sz] = 1.0;
	}
}

AttachPlayerToys(playerid)
{
	if(pData[playerid][PurchasedToy] == false) return 1;

	/*for(new i = 0; i < 4; i++)
	{
		if(pToys[playerid][i][toy_model] != 0)
		{
	        SetPlayerAttachedObject(playerid,
	            i,
	            pToys[playerid][i][toy_model],
	            pToys[playerid][i][toy_bone],
	            pToys[playerid][i][toy_x],
	            pToys[playerid][i][toy_y],
	            pToys[playerid][i][toy_z],
	            pToys[playerid][i][toy_rx],
	            pToys[playerid][i][toy_ry],
	            pToys[playerid][i][toy_rz],
	            pToys[playerid][i][toy_sx],
	            pToys[playerid][i][toy_sy],
	            pToys[playerid][i][toy_sz]);
  		}
	}*/
	
	if(pToys[playerid][0][toy_hide] == 0)
	{
		if(pToys[playerid][0][toy_model] != 0)
		{
			SetPlayerAttachedObject(playerid,
			0,
			pToys[playerid][0][toy_model],
			pToys[playerid][0][toy_bone],
			pToys[playerid][0][toy_x],
			pToys[playerid][0][toy_y],
			pToys[playerid][0][toy_z],
			pToys[playerid][0][toy_rx],
			pToys[playerid][0][toy_ry],
			pToys[playerid][0][toy_rz],
			pToys[playerid][0][toy_sx],
			pToys[playerid][0][toy_sy],
			pToys[playerid][0][toy_sz]);
		}
	}

	if(pToys[playerid][1][toy_hide] == 0)
	{
		if(pToys[playerid][1][toy_model] != 0)
		{
			SetPlayerAttachedObject(playerid,
			1,
			pToys[playerid][1][toy_model],
			pToys[playerid][1][toy_bone],
			pToys[playerid][1][toy_x],
			pToys[playerid][1][toy_y],
			pToys[playerid][1][toy_z],
			pToys[playerid][1][toy_rx],
			pToys[playerid][1][toy_ry],
			pToys[playerid][1][toy_rz],
			pToys[playerid][1][toy_sx],
			pToys[playerid][1][toy_sy],
			pToys[playerid][1][toy_sz]);
		}
	}

	if(pToys[playerid][2][toy_hide] == 0)
	{
		if(pToys[playerid][2][toy_model] != 0)
		{
			SetPlayerAttachedObject(playerid,
			2,
			pToys[playerid][2][toy_model],
			pToys[playerid][2][toy_bone],
			pToys[playerid][2][toy_x],
			pToys[playerid][2][toy_y],
			pToys[playerid][2][toy_z],
			pToys[playerid][2][toy_rx],
			pToys[playerid][2][toy_ry],
			pToys[playerid][2][toy_rz],
			pToys[playerid][2][toy_sx],
			pToys[playerid][2][toy_sy],
			pToys[playerid][2][toy_sz]);
		}
	}
	
	if(pToys[playerid][3][toy_hide] == 0)
	{
		if(pToys[playerid][3][toy_model] != 0)
		{
			SetPlayerAttachedObject(playerid,
			3,
			pToys[playerid][3][toy_model],
			pToys[playerid][3][toy_bone],
			pToys[playerid][3][toy_x],
			pToys[playerid][3][toy_y],
			pToys[playerid][3][toy_z],
			pToys[playerid][3][toy_rx],
			pToys[playerid][3][toy_ry],
			pToys[playerid][3][toy_rz],
			pToys[playerid][3][toy_sx],
			pToys[playerid][3][toy_sy],
			pToys[playerid][3][toy_sz]);
		}
	}
	return 1;
}

MySQL_SavePlayerToys(playerid)
{
	if(pData[playerid][PurchasedToy] == false) return true;
	if(!GetPVarInt(playerid, "UpdatedToy")) return true;

	new line4[5054], lstr[5054];

	mysql_format(g_SQL, lstr, sizeof(lstr),
	"UPDATE `toys` SET \
	`Slot0_Model` = %i, `Slot0_Bone` = %i, `Slot0_Hide` = %i, `Slot0_XPos` = %.3f, `Slot0_YPos` = %.3f, `Slot0_ZPos` = %.3f, `Slot0_XRot` = %.3f, `Slot0_YRot` = %.3f, `Slot0_ZRot` = %.3f, `Slot0_XScale` = %.3f, `Slot0_YScale` = %.3f, `Slot0_ZScale` = %.3f,",
		pToys[playerid][0][toy_model],
        pToys[playerid][0][toy_bone],
        pToys[playerid][0][toy_hide],
        pToys[playerid][0][toy_x],
        pToys[playerid][0][toy_y],
        pToys[playerid][0][toy_z],
        pToys[playerid][0][toy_rx],
        pToys[playerid][0][toy_ry],
        pToys[playerid][0][toy_rz],
        pToys[playerid][0][toy_sx],
        pToys[playerid][0][toy_sy],
        pToys[playerid][0][toy_sz]);
	strcat(line4, lstr);

	mysql_format(g_SQL, lstr, sizeof(lstr),
	" `Slot1_Model` = %i, `Slot1_Bone` = %i, `Slot1_Hide` = %i, `Slot1_XPos` = %.3f, `Slot1_YPos` = %.3f, `Slot1_ZPos` = %.3f, `Slot1_XRot` = %.3f, `Slot1_YRot` = %.3f, `Slot1_ZRot` = %.3f, `Slot1_XScale` = %.3f, `Slot1_YScale` = %.3f, `Slot1_ZScale` = %.3f,",
		pToys[playerid][1][toy_model],
        pToys[playerid][1][toy_bone],
        pToys[playerid][1][toy_hide],
        pToys[playerid][1][toy_x],
        pToys[playerid][1][toy_y],
        pToys[playerid][1][toy_z],
        pToys[playerid][1][toy_rx],
        pToys[playerid][1][toy_ry],
        pToys[playerid][1][toy_rz],
        pToys[playerid][1][toy_sx],
        pToys[playerid][1][toy_sy],
        pToys[playerid][1][toy_sz]);
  	strcat(line4, lstr);

    mysql_format(g_SQL, lstr, sizeof(lstr),
	" `Slot2_Model` = %i, `Slot2_Bone` = %i, `Slot2_Hide` = %i, `Slot2_XPos` = %.3f, `Slot2_YPos` = %.3f, `Slot2_ZPos` = %.3f, `Slot2_XRot` = %.3f, `Slot2_YRot` = %.3f, `Slot2_ZRot` = %.3f, `Slot2_XScale` = %.3f, `Slot2_YScale` = %.3f, `Slot2_ZScale` = %.3f,",
		pToys[playerid][2][toy_model],
        pToys[playerid][2][toy_bone],
        pToys[playerid][2][toy_hide],
        pToys[playerid][2][toy_x],
        pToys[playerid][2][toy_y],
        pToys[playerid][2][toy_z],
        pToys[playerid][2][toy_rx],
        pToys[playerid][2][toy_ry],
        pToys[playerid][2][toy_rz],
        pToys[playerid][2][toy_sx],
        pToys[playerid][2][toy_sy],
        pToys[playerid][2][toy_sz]);
  	strcat(line4, lstr);

    mysql_format(g_SQL, lstr, sizeof(lstr),
	" `Slot3_Model` = %i, `Slot3_Bone` = %i, `Slot3_Hide` = %i, `Slot3_XPos` = %.3f, `Slot3_YPos` = %.3f, `Slot3_ZPos` = %.3f, `Slot3_XRot` = %.3f, `Slot3_YRot` = %.3f, `Slot3_ZRot` = %.3f, `Slot3_XScale` = %.3f, `Slot3_YScale` = %.3f, `Slot3_ZScale` = %.3f,",
		pToys[playerid][3][toy_model],
        pToys[playerid][3][toy_bone],
        pToys[playerid][3][toy_hide],
        pToys[playerid][3][toy_x],
        pToys[playerid][3][toy_y],
        pToys[playerid][3][toy_z],
        pToys[playerid][3][toy_rx],
        pToys[playerid][3][toy_ry],
        pToys[playerid][3][toy_rz],
        pToys[playerid][3][toy_sx],
        pToys[playerid][3][toy_sy],
        pToys[playerid][3][toy_sz]);
  	strcat(line4, lstr);

	mysql_format(g_SQL, lstr, sizeof(lstr),
	" `Slot4_Model` = %i, `Slot4_Bone` = %i, `Slot4_Hide` = %i, `Slot4_XPos` = %.3f, `Slot4_YPos` = %.3f, `Slot4_ZPos` = %.3f, `Slot4_XRot` = %.3f, `Slot4_YRot` = %.3f, `Slot4_ZRot` = %.3f, `Slot4_XScale` = %.3f, `Slot4_YScale` = %.3f, `Slot4_ZScale` = %.3f,",
		pToys[playerid][4][toy_model],
        pToys[playerid][4][toy_bone],
        pToys[playerid][4][toy_hide],
        pToys[playerid][4][toy_x],
        pToys[playerid][4][toy_y],
        pToys[playerid][4][toy_z],
        pToys[playerid][4][toy_rx],
        pToys[playerid][4][toy_ry],
        pToys[playerid][4][toy_rz],
        pToys[playerid][4][toy_sx],
        pToys[playerid][4][toy_sy],
        pToys[playerid][4][toy_sz]);
  	strcat(line4, lstr);

	mysql_format(g_SQL, lstr, sizeof(lstr),
	" `Slot5_Model` = %i, `Slot5_Bone` = %i, `Slot5_Hide` = %i, `Slot5_XPos` = %.3f, `Slot5_YPos` = %.3f, `Slot5_ZPos` = %.3f, `Slot5_XRot` = %.3f, `Slot5_YRot` = %.3f, `Slot5_ZRot` = %.3f, `Slot5_XScale` = %.3f, `Slot5_YScale` = %.3f, `Slot5_ZScale` = %.3f WHERE `Owner` = '%s'",
		pToys[playerid][5][toy_model],
        pToys[playerid][5][toy_bone],
        pToys[playerid][5][toy_hide],
        pToys[playerid][5][toy_x],
        pToys[playerid][5][toy_y],
        pToys[playerid][5][toy_z],
        pToys[playerid][5][toy_rx],
        pToys[playerid][5][toy_ry],
        pToys[playerid][5][toy_rz],
        pToys[playerid][5][toy_sx],
        pToys[playerid][5][toy_sy],
        pToys[playerid][5][toy_sz],
		pData[playerid][pName]);
  	strcat(line4, lstr);

    mysql_tquery(g_SQL, line4);
    return 1;
}