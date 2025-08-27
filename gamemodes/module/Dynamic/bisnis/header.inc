#include <YSI_Coding\y_hooks>

enum bisinfo
{
	bOwner[MAX_PLAYER_NAME],
	bOwnerID,
	bName[128],
	bPrice,
	bType,
	bLocked,
	bMoney,
	bProd,
	bP[10],
	bInt,
	Float:bExtposX,
	Float:bExtposY,
	Float:bExtposZ,
	Float:bExtposA,
	bVisit,
	bRestock,
	//Not Saved
	bMap,
	Text3D:bLabel,
};

new bData[MAX_BISNIS][bisinfo],
	Iterator: Bisnis<MAX_BISNIS>;