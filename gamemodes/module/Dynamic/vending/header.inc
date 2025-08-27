enum E_VENDING
{
	venOwner[MAX_PLAYER_NAME],
	venPrice,
	Float:venX,
	Float:venY,
	Float:venZ,
	Float:venRX,
	Float:venRY,
	Float:venRZ,
	venWorld,
	venInt,
	venMoney,
	venDrinkPrice,
	venProduct,
	venVisit,
	//Not Save
	venObject,
	Text3D:venLabel,
};

new vmData[MAX_VENDING][E_VENDING],
	Iterator:Vending<MAX_VENDING>;