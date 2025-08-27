//3017 Schematic
#define MAX_DROPPED_ITEMS 5000
#define MAX_INVENTORY 28
#define MAX_LISTED_ITEMS 10

new PlayerText: txd_inventory[MAX_PLAYERS][23];
new PlayerText: indexinv[MAX_PLAYERS][MAX_INVENTORY];
new PlayerText: modelinv[MAX_PLAYERS][MAX_INVENTORY];
new PlayerText: itemamountname[MAX_PLAYERS][MAX_INVENTORY];
new PlayerText: itemname[MAX_PLAYERS][MAX_INVENTORY];

new BukaInven[MAX_PLAYERS];

//Inventory
enum inventoryData {
	bool:invExists,
	invID,
	invItem[64],
	invModel,
	invQuantity,
	invAmmo,
	invSlot
};
new InventoryData[MAX_PLAYERS][MAX_INVENTORY][inventoryData];
new bool:InventoryOpen[MAX_PLAYERS], SelectInventory[MAX_PLAYERS], AmmountInventory[MAX_PLAYERS];
new NearestItems[MAX_PLAYERS][MAX_LISTED_ITEMS];
enum e_InventoryItems {
    e_InventoryItem[320],
    e_InventoryModel,
    Float: e_InventoryWeight,
    e_InventoryMax,
    bool:e_InventoryDrop
};

new const g_aInventoryItems[][e_InventoryItems] = {
	{"Phone", 18866, 0.300, 10, false},
	{"Money", 1212, 0.000, 0, false},
	{"Medkit", 1580, 0.300, 20, false},
	{"Portable Radio", 18868, 0.200, 5, false},
	{"Mask", 19036, 0.700, 1, false},
	{"Snack", 2768, 0.200, 20, false},
	{"Red Money", 1212, 0.100, 1, false},
	{"Water", 2958, 0.100, 20, false},
	{"Sprunk", 2958, 0.100, 20, false},
	{"Jus Jeruk", 19563, 0.150, 20, false},
	{"Weed", 1578, 0.200, 500, false},
	{"Component", 19627, 0.100, 500, false},
	{"Material", 17051, 0.100, 500, false},
	{"Repair Kit", 920, 0.100, 500, false},
	{"Wheat", 2247, 0.100, 500, false},
	{"Orange", 19574, 0.100, 500, false},
	{"Food", 19568, 0.100, 500, false},
	{"Potato", 19577, 0.100, 500, false},
	{"Fuel Can", 1650, 1.000, 10, false},
	{"Fish Rod", 18632, 0.300, 20, false},
	{"Bait", 19566, 0.100, 20, false},
	{"Pizza Stack", 19580, 0.100, 20, false},
	{"Fried rice", 2221, 0.100, 20, false},
	{"Rokok", 19897, 0.100, 20, false},
	{"Wine", 1486, 0.300, 20, false},
	{"Whiskey", 19824, 0.300, 20, false},
	{"Vodka", 1544, 0.300, 20, false},
	{"Blue Moon", 1517, 0.300, 20, false},
	{"Skateboard", 19878, 1.000, 20, false},
	{"Boombox", 2226, 0.100, 10, false},
	{"Medicine", 1575, 0.100, 20, false},
	{"Marijuana", 1578, 0.100, 20, false},
	{"Kanabis", 19473, 0.100, 20, false},
	{"Test Drug", 1579, 0.100, 20, false},
	{"Cocaine", 1575, 0.100, 20, false},
	{"Muriatic", 1580, 0.100, 20, false},
	{"Ephedrine", 1580, 0.100, 20, false},
	{"Meth", 1580, 0.100, 20, false},
	{"Daging", 2805, 1.000, 20, false},
	{"Susu", 19570, 0.500, 20, false},
	{"Susu Olah", 19570, 0.300, 20, false},
	{"Ikan", 19630, 1.000, 20, false},
	{"Ayam Hidup", 16776, 1.000, 20, false},
	{"Ayam Potong", 2804, 0.400, 20, false},
	{"Ayam Packing", 2770, 1.000, 20, false},
	{"Kayu Kemas", 1271, 1.000, 20, false},
	{"Steak", 19882, 0.300, 20, false},
	{"Milk", 19570, 0.100, 20, false},
	{"Roti", 19579, 0.100, 20, false},
	{"Bandage", 11747, 0.300, 20, false},
	{"Emas", 19941, 0.700, 50, false},
	{"Tembaga", 3929, 0.800, 50, false},
	{"Berlian", 1559, 0.700, 50, false},
	{"Besi", 19845, 0.900, 50, false},
	{"Batu", 3930, 0.400, 50, false},
	{"Kevlar", 1242, 1.000, 20, false},
	{"Batu Cucian", 2936, 0.500, 50, false},
	{"Benang", 1901, 0.100, 20, false},
	{"Kain", 19873, 0.100, 20, false},
	{"Pakaian", 2705, 0.300, 20, false},
	{"Sampah", 2840, 0.100, 20, true},
	{"Note", 2684, 0.100, 20, true},

	{"Linggis", 18634, 0.700, 10, false},
	{"Kunci T", 18634, 0.700, 10, false},
	{"Clip Pistol", 19995, 0.800, 20, false},
	{"Clip Rifle", 19995, 0.800, 20, false},
	{"Clip Sg", 19995, 0.800, 20, false},
	{"Clip Smg", 19995, 0.800, 20, false},
	{"Bomb", 363, 0.300, 20, false}
};

//Drop Items
enum droppedItems {
	droppedID,
	droppedItem[32],
	droppedPlayer[24],
	droppedModel,
	droppedQuantity,
	Float:droppedPos[3],
	droppedWeapon,
	droppedAmmo,
	droppedInt,
	droppedWorld,
	droppedObject,
	droppedTime,
	Text3D:droppedText3D
};
new DroppedItems[MAX_DROPPED_ITEMS][droppedItems];