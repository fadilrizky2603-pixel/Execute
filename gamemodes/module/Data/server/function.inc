function LoadServer()
{
	cache_get_value_name_int(0, "servermoney", ServerMoney);
	cache_get_value_name_int(0, "material", Material);
	cache_get_value_name_int(0, "materialprice", MaterialPrice);
	cache_get_value_name_int(0, "lumberprice", LumberPrice);
	cache_get_value_name_int(0, "component", Component);
	cache_get_value_name_int(0, "componentprice", ComponentPrice);
	cache_get_value_name_int(0, "product", Product);
	cache_get_value_name_int(0, "productprice", ProductPrice);
	cache_get_value_name_int(0, "apotek", Apotek);
	cache_get_value_name_int(0, "medicineprice", MedicinePrice);
	cache_get_value_name_int(0, "medkitprice", MedkitPrice);
	cache_get_value_name_int(0, "food", Food);
	cache_get_value_name_int(0, "foodprice", FoodPrice);
	cache_get_value_name_int(0, "seedprice", SeedPrice);
	cache_get_value_name_int(0, "potatoprice", PotatoPrice);
	cache_get_value_name_int(0, "gandum", Gandum);
	cache_get_value_name_int(0, "gandumprice", GandumPrice);
	cache_get_value_name_int(0, "wheatprice", WheatPrice);
	cache_get_value_name_int(0, "orangeprice", OrangePrice);
	cache_get_value_name_int(0, "marijuana", Marijuana);
	cache_get_value_name_int(0, "marijuanaprice", MarijuanaPrice);
	cache_get_value_name_int(0, "ephedrine", Ephedrine);
	cache_get_value_name_int(0, "ephedrineprice", EphedrinePrice);
	cache_get_value_name_int(0, "cocaine", Cocaine);
	cache_get_value_name_int(0, "cocaineprice", CocainePrice);
	cache_get_value_name_int(0, "fishprice", FishPrice);
	cache_get_value_name_int(0, "gstationprice", GStationPrice);
    cache_get_value_name_int(0, "firstspawnprice", FirstSpawnPrice);
    cache_get_value_name_int(0, "daging", Daging);
    cache_get_value_name_int(0, "dagingprice", DagingPrice);
    cache_get_value_name_int(0, "susu", Susu);
    cache_get_value_name_int(0, "susuprice", SusuPrice);
    cache_get_value_name_int(0, "milkprice", MilkPrice);
	printf("[SERVER] Number of Loaded Data Server...");
	printf("[SERVER] ServerMoney: %d", ServerMoney);
	CreateServerPoint();
}