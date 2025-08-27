enum E_WORKSHOP
{
	wName[50],
	wLeader[MAX_PLAYER_NAME],
	wPrice,
	wStatus,
	wMoney,
	wComponent,
	Float:wExtposX,
	Float:wExtposY,
	Float:wExtposZ,
	Float:wExtposA,
	//Not Save
	Text3D:wLabel,
	wPickup,
	wIcon
};

new wData[MAX_WORKSHOP][E_WORKSHOP],
	Iterator:Workshop<MAX_WORKSHOP>;