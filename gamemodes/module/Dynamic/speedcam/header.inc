enum E_SPEEDCAM
{
	Float:camX,
	Float:camY,
	Float:camZ,
	Float:camRX,
	Float:camRY,
	Float:camRZ,
	camWorld,
	camInt,
	camSpeed,
	//TEMP
	camObj,
	Text3D:camLabel
};

new camData[MAX_SPEEDCAM][E_SPEEDCAM],
	Iterator:Speedcam<MAX_SPEEDCAM>;