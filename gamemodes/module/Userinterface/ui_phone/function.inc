function HideNotifX(playerid) {
	for(new x = 0; x < 26; x++) {
		PlayerTextDrawHide(playerid, NotifX[playerid][x]);
	}
}

function HideAllPhone(playerid) {
	for(new x = 0; x < 26; x++) {
		PlayerTextDrawHide(playerid, NotifX[playerid][x]);
	}
	for(new x = 0; x < 94; x++) {
		PlayerTextDrawHide(playerid, HomeScreen[playerid][x]);
	}
	for(new x = 0; x < 31; x++) {
		PlayerTextDrawHide(playerid, TaxiMenu[playerid][x]);
	}
	for(new x = 0; x < 54; x++) {
		PlayerTextDrawHide(playerid, BankMenu[playerid][x]);
	}
	for(new x = 0; x < 34; x++) {
		PlayerTextDrawHide(playerid, SettingsMenu[playerid][x]);
	}
	for(new x = 0; x < 44; x++) {
		PlayerTextDrawHide(playerid, XMenu[playerid][x]);
	}
}