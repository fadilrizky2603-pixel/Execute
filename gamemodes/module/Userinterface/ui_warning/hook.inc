#include <YSI_Coding/y_hooks>

hook OnPlayerConnect(playerid)
{
    LoadAlertTD(playerid);    
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES)
    {
		if(IsValidDynamicPlayerTextDraw(playerid, ALERTTD[playerid][0]))
		{
			forex(i, 16)
			{
				PlayerTextDrawHide(playerid, ALERTTD[playerid][i]);
			}	
			ShowLogo(playerid);
			ShowHunger(playerid);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}