enum E_GARKOT
{
	Float:gkX,
	Float:gkY,
	Float:gkZ,
	Float:gkA,
	Float:sgkX,
	Float:sgkY,
	Float:sgkZ,
	Float:sgkA,
	garkotmap,
	gkInt,
	gkVW,
	//temp
	gkPickup,
	sgkPickup,
	STREAMER_TAG_AREA:gkArea,
	STREAMER_TAG_OBJECT:gkObject,
	Text3D:gkText,
	STREAMER_TAG_AREA:sgkArea,
	STREAMER_TAG_OBJECT:sgkObject,
}

new gkData[MAX_GARKOT][E_GARKOT],
Iterator:Garkot<MAX_GARKOT>;