enum pedaganginfo
{
    pdgType,
    Float:pdgPosX,
    Float:pdgPosY,
    Float:pdgPosZ,
    pdgInt,
    pdgGandum,
    pdgDaging,
    pdgSusuolah,
    pdgBurger,
    pdgRoti,
    pdgSteak,
    pdgMilk,
    pdgKentang,
    pdgOrange,
    pdgFood,
    Text3D:pdgLabel,
    pdgPickup,
    STREAMER_TAG_OBJECT:pdgObject,
    STREAMER_TAG_AREA:pdgAmbilarea
};

new pdgDATA[MAX_PEDAGANG][pedaganginfo],
    Iterator: Pedagang<MAX_PEDAGANG>;
