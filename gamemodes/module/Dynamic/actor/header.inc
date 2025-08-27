enum E_ACTOR
{
	actName[128],
	actSkin,
	actBizid,
	actVuln,
	Float:actX,
	Float:actY,
	Float:actZ,
	Float:actA,
	actInt,
	actVW,
	actAnim,
	//TEMP
	actObj,
	Text3D:actLabel
}

new ActData[MAX_ACTOR][E_ACTOR],
Iterator:Actors<MAX_ACTOR>;