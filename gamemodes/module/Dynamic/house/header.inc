#define Loop(%0,%1,%2) for(new %0 = %2; %0 < %1; %0++)

enum houseinfo
{
	hOwner[MAX_PLAYER_NAME],
	hOwner2[MAX_PLAYER_NAME],
	hAddress[128],
	hPrice,
	hType,
	hLocked,
	hMoney,
	hMarijuana,
	hEphedrine,
	hCocaine,
	hMeth,
	hComponent,
	hMaterial,
	hWeapon[10],
	hAmmo[10],
	hInt,
	Float:hExtposX,
	Float:hExtposY,
	Float:hExtposZ,
	Float:hExtposA,
	Float:hIntposX,
	Float:hIntposY,
	Float:hIntposZ,
	Float:hIntposA,
	hVisit,
	//Not Saved
	hPickup,
	hCP,
	hIcon,
	Text3D:hLabel
};

new hData[MAX_HOUSES][houseinfo],
	Iterator: Houses<MAX_HOUSES>;