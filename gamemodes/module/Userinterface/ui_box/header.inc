enum eItemBox
{
	ItemBoxIcon,
	ItemBoxMessage[320],
	ItemBoxJumlahMessage[200],
	ItemBoxLoading,
	ItemBoxSize
}
new InfoItemBox[MAX_PLAYERS][6][eItemBox];
new MaxPlayerItemBox[MAX_PLAYERS];
new PlayerText:TextDrawItemBox[MAX_PLAYERS][6*10];
new IndexItemBox[MAX_PLAYERS];