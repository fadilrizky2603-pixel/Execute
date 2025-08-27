CreateServerPoint()
{
	if(IsValidDynamic3DTextLabel(MoneyText))
            DestroyDynamic3DTextLabel(MoneyText);

	if(IsValidDynamicPickup(MoneyPickup))
		DestroyDynamicPickup(MoneyPickup);
			
	//Server Money
	new strings[1024];
	MoneyPickup = CreateDynamicPickup(1239, 23, -984.91, 1468.59, 1332.02, -1, -1, -1, 5.0);
	format(strings, sizeof(strings), "[Server Money]\n"WHITE_E"Goverment Money: "LG_E"%s\n"WHITE_E"/robvault - untuk merampok vault", FormatMoney(ServerMoney));
	MoneyText = CreateDynamic3DTextLabel(strings, COLOR_LBLUE, -984.91, 1468.59, 1332.02, 5.0);

	//SagsVault
	MoneyPickup = CreateDynamicPickup(1239, 23, -995.0111 ,1456.7094 ,1340.6270 , -1, -1, -1, 5.0);
	format(strings, sizeof(strings), "[Server Money]\n"WHITE_E"Goverment Money: "LG_E"%s\n"WHITE_E"/gsvault - untuk akses vault", FormatMoney(ServerMoney));
	MoneyText = CreateDynamic3DTextLabel(strings, COLOR_LBLUE, -995.0111, 1456.7094, 1340.6270, 5.0);
	
	if(IsValidDynamic3DTextLabel(MatText))
            DestroyDynamic3DTextLabel(MatText);

	if(IsValidDynamicPickup(MatPickup))
		DestroyDynamicPickup(MatPickup);
	
	if(IsValidDynamic3DTextLabel(CompText))
            DestroyDynamic3DTextLabel(CompText);

	if(IsValidDynamicPickup(CompPickup))
		DestroyDynamicPickup(CompPickup);
		
	if(IsValidDynamic3DTextLabel(ProductText[0]))
        DestroyDynamic3DTextLabel(ProductText[0]);
	
    if(IsValidDynamic3DTextLabel(ProductText[1]))
        DestroyDynamic3DTextLabel(ProductText[1]);

	if(IsValidDynamicPickup(ProductPickup[0]))
		DestroyDynamicPickup(ProductPickup[0]);

    if(IsValidDynamicPickup(ProductPickup[1]))
        DestroyDynamicPickup(ProductPickup[1]);

	if(IsValidDynamic3DTextLabel(ApotekText))
        DestroyDynamic3DTextLabel(ApotekText);
		
	if(IsValidDynamicPickup(ApotekPickup))
		DestroyDynamicPickup(ApotekPickup);
	
	if(IsValidDynamic3DTextLabel(FoodText))
            DestroyDynamic3DTextLabel(FoodText);
		
	if(IsValidDynamicPickup(FoodPickup))
		DestroyDynamicPickup(FoodPickup);
		
	if(IsValidDynamic3DTextLabel(MarijuanaText))
            DestroyDynamic3DTextLabel(MarijuanaText);
		
	if(IsValidDynamicPickup(MarijuanaPickup))
		DestroyDynamicPickup(MarijuanaPickup);

	if(IsValidDynamic3DTextLabel(EphedrineText))
           DestroyDynamic3DTextLabel(EphedrineText);
		
	if(IsValidDynamicPickup(EphedrinePickup))
		DestroyDynamicPickup(EphedrinePickup);

	if(IsValidDynamic3DTextLabel(CocaineText))
           DestroyDynamic3DTextLabel(CocaineText);
		
	if(IsValidDynamicPickup(CocainePickup))
		DestroyDynamicPickup(CocainePickup);

	if(IsValidDynamic3DTextLabel(DagingText))
           DestroyDynamic3DTextLabel(DagingText);

    if(IsValidDynamic3DTextLabel(SusuText))
           DestroyDynamic3DTextLabel(SusuText);

	//JOBS
	MatPickup = CreateDynamicPickup(1239, 23, 2801.2979, -2362.8828, 13.7167, -1, -1, -1, 10.0);
	format(strings, sizeof(strings), ""WHITE_E"Material Stock: "LG_E"%d\n"WHITE_E"Material Price: "LG_E"%s /item\n\n"LB_E"/buy", Material, FormatMoney(MaterialPrice));
	MatText = CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2801.2979, -2362.8828, 13.7167, 10.0); // lumber
	
	CompPickup = CreateDynamicPickup(1239, 23, 2789.1106, -2363.0295, 13.7167, -1, -1, -1, 5.0);
	format(strings, sizeof(strings), ""WHITE_E"Component Stock: "LG_E"%d\n"WHITE_E"Component Price: "LG_E"%s /item\n\n"LB_E"/buy", Component, FormatMoney(ComponentPrice));
	CompText = CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2789.1106, -2363.0295, 13.7167, 5.0); // comp
	
	ProductPickup[0] = CreateDynamicPickup(1239, 23, 2765.2415, -2363.1838, 13.7167, -1, -1, -1, 10.0);
	format(strings, sizeof(strings), ""WHITE_E"Product Stock: "LG_E"%d\n"WHITE_E"/sellproduct - sell product", Product);
	ProductText[0] = CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2765.2415, -2363.1838, 13.7167, 10.0); // product original
	
    ProductPickup[1] = CreateDynamicPickup(1239, 23, -62.03, -1121.26, 1.29, -1, -1, -1, 10.0);
    format(strings, sizeof(strings), "[TRUCKER BOX]\n"WHITE_E"/loadbox - load vending product to vehicle");
    ProductText[1] = CreateDynamic3DTextLabel(strings, COLOR_YELLOW, -62.03, -1121.26, 1.29+0.3, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0); // product trucker

	ApotekPickup = CreateDynamicPickup(1241, 23, -2012.4336, 122.6201, 10027.6240, -1, -1, -1, 5.0);
	format(strings, sizeof(strings), "San Andreas Medic Department\n"WHITE_E"Pharmacy Stock: "LG_E"%d\n"LB_E"/buy", Apotek);
	ApotekText = CreateDynamic3DTextLabel(strings, COLOR_PINK, -2012.4336, 122.6201, 10027.6240, 5.0); // Apotek hospital
	
	//FoodPickup = CreateDynamicPickup(1239, 23, -382.97, -1426.43, 26.31, -1, -1, -1, 10.0);
	format(strings, sizeof(strings), "[Food]\n"WHITE_E"Food Stock: "LG_E"%d\n"WHITE_E"Food Price: "LG_E"%s /item\n"WHITE_E"Gandum Stock: "LG_E"%d\n"WHITE_E"Gandum Price: "LG_E"%s /item\n\n"WHITE_E"Seed Price: "LG_E"%s /item\n"WHITE_E"Potato Price: "LG_E"%s /kg\n"WHITE_E"Wheat Price: "LG_E"%s /kg\n"WHITE_E"Orange Price: "LG_E"%s /kg",
	Food, FormatMoney(FoodPrice), Gandum, FormatMoney(GandumPrice), FormatMoney(SeedPrice), FormatMoney(PotatoPrice), FormatMoney(WheatPrice), FormatMoney(OrangePrice));
	FoodText = CreateDynamic3DTextLabel(strings, COLOR_YELLOW, -382.97, -1426.43, 26.31+1, 10.0); // food*/

	/*//SEEDS MARIJUANA
	MarijuanaPickup = CreateDynamicPickup(1578, 23, 321.86, 1117.14, 1083.88, -1);
	format(strings, sizeof(strings), "Marijuana\n"WHITE_E"Stock: %d\nPrice: %s/Item\n/buy [ammount]", Marijuana, FormatMoney(MarijuanaPrice));
	MarijuanaText = CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 321.86, 1117.14, 1083.88+0.3, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); */

	//RAW EPHEDRINE
	EphedrinePickup = CreateDynamicPickup(1577, 23, 323.99, 1117.11, 1083.88, -1);
	format(strings, sizeof(strings), "Raw Ephedrine\n"WHITE_E"Stock: %d\nPrice: %s/Item\n/buydrugs [ephedrine] [ammount]", Ephedrine, FormatMoney(EphedrinePrice));
	EphedrineText = CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 323.99, 1117.11, 1083.88+0.3, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); 

	//COCAINE
	CocainePickup = CreateDynamicPickup(1575, 23, 870.3434,-25.2242,63.9634, -1);
	format(strings, sizeof(strings), "Cocaine\n"WHITE_E"Stock: %d\nPrice: %s/Item\n/buycocaine [ammount]", Cocaine, FormatMoney(CocainePrice));
	CocaineText = CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 870.3434, -25.2242, 63.9634, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1); 

	//STOCK DAGING
	format(strings, sizeof(strings), "[SELL DAGING]\n"WHITE_E"Stock: %d\nPrice: %s/Item\n/buy", Daging, FormatMoney(DagingPrice));
	DagingText = CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 1996.39, -2065.53, 13.54+0.3, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);


}

Server_Percent(price)
{
    return floatround((float(price) / 100) * 85);
}

Server_AddPercent(price)
{
    new money = (price - Server_Percent(price));
    ServerMoney = ServerMoney + money;
    Server_Save();
}

Server_AddMoney(amount)
{
    ServerMoney = ServerMoney + amount;
    Server_Save();
}

Server_MinMoney(amount)
{
    ServerMoney -= amount;
    Server_Save();
}

Server_Save()
{
    new str[2024];

	CreateServerPoint();
    format(str, sizeof(str), "UPDATE server SET servermoney='%d', material='%d', materialprice='%d', lumberprice='%d', component='%d', componentprice='%d', product='%d', productprice='%d', medicineprice='%d', medkitprice='%d', food='%d', foodprice='%d', seedprice='%d', potatoprice='%d', gandum='%d', gandumprice='%d', wheatprice='%d', orangeprice='%d', marijuana='%d', marijuanaprice='%d', ephedrine='%d', ephedrineprice='%d', cocaine='%d', cocaineprice='%d', fishprice='%d', gstationprice='%d', firstspawnprice='%d', daging='%d', dagingprice='%d', susu='%d', susuprice='%d', milkprice='%d' WHERE id=0",
	ServerMoney, Material, MaterialPrice, LumberPrice, Component, ComponentPrice, Product, ProductPrice, MedicinePrice, MedkitPrice, 
	Food, FoodPrice, SeedPrice, PotatoPrice, Gandum, GandumPrice, WheatPrice, OrangePrice, Marijuana, MarijuanaPrice, Ephedrine, EphedrinePrice, Cocaine, CocainePrice, FishPrice, GStationPrice, FirstSpawnPrice, Daging, DagingPrice, Susu, SusuPrice, MilkPrice);
    return mysql_tquery(g_SQL, str);
}