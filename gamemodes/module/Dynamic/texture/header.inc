

enum E_MATEXT
{
	Float:mtX,
	Float:mtY,
	Float:mtZ,
	Float:mtRX,
	Float:mtRY,
	Float:mtRZ,
	mtInt,
	mtVW,
	//Inti
	mtText[254],
	mtSize,
	mtColor,
	mtBold,
	//Temp
	mtObj,
	Text3D:mtLabel
}

new mtData[MAX_MATEXT][E_MATEXT],
Iterator: Matext<MAX_MATEXT>;