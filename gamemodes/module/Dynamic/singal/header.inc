enum E_SIGNAL
{	
	sgStatus,
	Float:sgX,
	Float:sgY,
	Float:sgZ,
	Float:sgRX,
	Float:sgRY,
	Float:sgRZ,
	sgInt,
	sgVW,
	//Temp
	sgObj,
	Text3D:sgLabel,
	sgSeconds,
	sgTimer
};

new sgData[MAX_SIGNAL][E_SIGNAL],
	Iterator: Signal<MAX_SIGNAL>;