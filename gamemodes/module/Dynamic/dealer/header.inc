enum E_DEALER
{
	dOwner[MAX_PLAYER_NAME],
	dName[128],
	//Pickup Stats
	Float:dPosX,
	Float:dPosY,
	Float:dPosZ,
	Float:dPosA,
	dInt,
	dVW,
	dPrice,
	//Pos Vehicle Stats
	Float:dVehX,
	Float:dVehY,
	Float:dVehZ,
	Float:dVehA,
	dVehInt,
	dVehVW,
	//Dealer Menu
	dLock,
	dType,
	dMoney,
	dStock,
	dP[22],
	dVisit,
	//Temp 
	dPickup,
	dIcon,
	Text3D:dLabel,
	Text3D:dLabelSpawn
}

new drData[MAX_DEALER][E_DEALER],
Iterator:Dealer<MAX_DEALER>;