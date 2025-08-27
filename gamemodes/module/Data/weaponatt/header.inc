//Weapon Attach
enum weaponSettings
{
    Float:Position[6],
    Bone,
    Hidden
}
new WeaponSettings[MAX_PLAYERS][17][weaponSettings], WeaponTick[MAX_PLAYERS], EditingWeapon[MAX_PLAYERS];

enum droppedweapons {
    WeapID,
    WeapPlayer[24],
	WeapModel,
	WeaponID,
	WeapAmmo,
    Float:WeapPos[3],
	WeapInt,
	WeapWorld,
    WeapObject,
	Text3D:WeapLabel
};
new DropWeap[MAX_DROP_WEAPON][droppedweapons];