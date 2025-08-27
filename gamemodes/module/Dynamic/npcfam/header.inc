enum E_NPCFAM
{
	nfOwner,
	nfType,

	Float:nfPosX,
	Float:nfPosY,
	Float:nfPosZ,
	Float:nfPosA,
	nfVw,
	nfInt,
	nfMoney,
	nfMaterial,
	nfMarijuana,
	nfCocaine,
	nfMeth,
	nfPrice[10],
	//Temp
	nfPickup,
	Text3D:nfLabel
}

new nfData[MAX_NPCFAM][E_NPCFAM],
Iterator:NPCFam<MAX_NPCFAM>;