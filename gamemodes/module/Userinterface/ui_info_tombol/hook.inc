#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
	LoadTombol(playerid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}