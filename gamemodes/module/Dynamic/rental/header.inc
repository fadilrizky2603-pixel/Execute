enum E_RENTAL
{
	Float:rExtposX,
	Float:rExtposY,
	Float:rExtposZ,
	Float:rExtposA,
	Float:rVehposX,
	Float:rVehposY,
	Float:rVehposZ,
	Float:rVehposA,
	rPrice,
	//Not Saved
	rPickup,
	Text3D:rLabel,
	rType
};

new rnData[MAX_RENTAL][E_RENTAL],
	Iterator: Rental<MAX_RENTAL>;