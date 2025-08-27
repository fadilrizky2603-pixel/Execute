

enum familyss
{
	fName[50],
	fLeader[MAX_PLAYER_NAME],
	fMotd[100],
	fColor,
	Float:fExtposX,
	Float:fExtposY,
	Float:fExtposZ,
	Float:fExtposA,
	Float:fIntposX,
	Float:fIntposY,
	Float:fIntposZ,
	Float:fIntposA,
	fInt,
	Float:fSafeposX,
	Float:fSafeposY,
	Float:fSafeposZ,
	Float:fSafeposA,
	fMoney,
	fMarijuana,
	fComponent,
	fMaterial,
	fGun[15],
	fAmmo[15],
	//Not Save
	Text3D:fLabelext,
	Text3D:fLabelint,
	Text3D:fLabelsafe,
	fPickext,
	fPickint,
	fPicksafe
};

new fData[MAX_FAMILY][familyss],
	Iterator:FAMILYS<MAX_FAMILY>;