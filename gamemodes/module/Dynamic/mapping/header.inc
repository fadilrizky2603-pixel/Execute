enum    E_MAPO
{
	// loaded from db
	Float: mapoX,
	Float: mapoY,
	Float: mapoZ,
	Float: mapoRX,
	Float: mapoRY,
	Float: mapoRZ,
	mapoObject,
	mapoInt,
	mapoWorld,
	// temp
	mapoObjID,
	Text3D: mapoLabel
}

new MapoData[MAX_MAPO_OBJECT][E_MAPO],
	Iterator:MAPO<MAX_MAPO_OBJECT>;