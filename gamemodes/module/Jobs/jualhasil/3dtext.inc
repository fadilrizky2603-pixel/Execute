CreatePasarPoint()
{
	new strings[258];
	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}to sell Clothes"); //jual pakaian
	CreateDynamic3DTextLabel(strings, -1, 2785.728759, -1604.146362, 10.921875, 5.0);

	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}to sell Packed Chicken"); //jual ayam
	CreateDynamic3DTextLabel(strings, -1, 2781.684326, -1604.076904, 10.921875, 5.0);

	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}to sell mines"); //Jual Tambang
	CreateDynamic3DTextLabel(strings, -1, 2771.944580, -1625.254150, 11.126003, 5.0);

	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}to sell material"); //lum sell
	CreateDynamic3DTextLabel(strings, -1, 2775.390869, -1604.076416, 10.921875, 5.0);

    format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}to sell milk"); //lum sell
	CreateDynamic3DTextLabel(strings, -1, 2779.750244, -1623.891723, 10.921875, 5.0);

	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}to sell menu farmer"); //lum sell
	CreateDynamic3DTextLabel(strings, -1, 2770.871582, -1604.076538, 10.921875, 5.0);

	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}to buy material"); //lum sell
	CreateDynamic3DTextLabel(strings, -1, 2769.373779, -1609.820434, 10.921875, 5.0);

	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}to buy component"); //lum sell
	CreateDynamic3DTextLabel(strings, -1, 2772.005615, -1617.289794, 10.921875, 5.0);

	format(strings, sizeof(strings), "Press {FFFF00}[Y] {FFFFFF}to sell fish"); //lum sell
	CreateDynamic3DTextLabel(strings, -1, 2784.399169, -1623.892944, 10.921875, 5.0);
}