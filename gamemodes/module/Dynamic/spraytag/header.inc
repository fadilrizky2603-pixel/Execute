enum e_tag_data
{
	tagID,
	Float:tagPos[6],
	tagInterior,
	tagWorld,
	tagOwner,
	tagFont[24],
	tagSize,
	tagBold,
	tagColor,
	tagText[64],
	STREAMER_TAG_OBJECT:tagObject
}
new TagData[MAX_TAGS][e_tag_data],
	Iterator:SprayTag<MAX_TAGS>;

new TagText[MAX_PLAYERS][64],
	TagFont[MAX_PLAYERS][24],
	TagSize[MAX_PLAYERS],
	TagBold[MAX_PLAYERS],
	TagColor[MAX_PLAYERS];