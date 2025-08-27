function HideItemBox(playerid)
{
    if (!IndexItemBox[playerid]) return 1;
    --IndexItemBox[playerid];
    MaxPlayerItemBox[playerid]--;

    for (new i = 0; i < 10; i++)
    {
        new PlayerText:textDrawId = TextDrawItemBox[playerid][(IndexItemBox[playerid] * 10) + i];
        
        if (textDrawId != PlayerText:INVALID_TEXT_DRAW) // Pastikan ID valid
        {
			if(IsValidDynamicPlayerTextDraw(playerid, textDrawId))
			{	
				PlayerTextDrawDestroy(playerid, textDrawId);
				TextDrawItemBox[playerid][(IndexItemBox[playerid] * 10) + i] = PlayerText:INVALID_TEXT_DRAW; // Reset ID setelah dihancurkan
			}
        }
    }
    return 1;
}