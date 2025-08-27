enum E_SVPOINT
{
	svType,
	Float:svPosX,
	Float:svPosY,
	Float:svPosZ,
	Float:svPosA,
	svVw,
	svInt,
	//Temp
	svPickup,
	Text3D:svLabel
}

new svData[MAX_SVPOINT][E_SVPOINT],
Iterator:SVPoint<MAX_SVPOINT>;

enum E_FACTIONVEH
{
    fvVeh,
    fvFaction,
    Float:fvPosX,
    Float:fvPosY,
    Float:fvPosZ,
    Float:fvPosA,
    fvColor1,
    fvColor2,
    Text3D:fvLabel
}

new fvData[MAX_FACTIONVEH][E_FACTIONVEH],
Iterator:FactionVeh<MAX_FACTIONVEH>;