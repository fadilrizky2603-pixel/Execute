enum E_PFARM
{
	pfOwner[MAX_PLAYER_NAME],
	pfPrice,
	Float:pfX,
	Float:pfY,
	Float:pfZ,
	Float:pfA,
	pfInt,
	pfVW,
	//Storage
	pfSeeds,
	pfPotato,
	pfOrange,
	pfWheat,
	pfVisit,
	//Temp,
	pfPickup,
	Text3D:pfLabel
}

new pfData[MAX_PFARM][E_PFARM],
Iterator: PFarm<MAX_PFARM>;