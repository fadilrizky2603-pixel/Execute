enum    E_ATM
{
	// loaded from db
	Float: atmX,
	Float: atmY,
	Float: atmZ,
	Float: atmRX,
	Float: atmRY,
	Float: atmRZ,
	atmInt,
	atmWorld,
	atmStatus,
	// temp
	atmObjID,
	Text3D: atmLabel,
	STREAMER_TAG_AREA:atmArea
}

new AtmData[MAX_ATM][E_ATM],
	Iterator:ATMS<MAX_ATM>;

new PlayerText: AtmPakCik[MAX_PLAYERS][55];