//Weapon Attach System
function OnWeaponsLoaded(playerid)
{
    new rows, weaponid, index;
   
    cache_get_row_count(rows);
   
    for (new i; i < rows; i++)
    {
        cache_get_value_name_int(i, "WeaponID", weaponid);
        index = weaponid - 22;
       
        cache_get_value_name_float(i, "PosX", WeaponSettings[playerid][index][Position][0]);
        cache_get_value_name_float(i, "PosY", WeaponSettings[playerid][index][Position][1]);
        cache_get_value_name_float(i, "PosZ", WeaponSettings[playerid][index][Position][2]);
       
        cache_get_value_name_float(i, "RotX", WeaponSettings[playerid][index][Position][3]);
        cache_get_value_name_float(i, "RotY", WeaponSettings[playerid][index][Position][4]);
        cache_get_value_name_float(i, "RotZ", WeaponSettings[playerid][index][Position][5]);
       
        cache_get_value_name_int(i, "Bone", WeaponSettings[playerid][index][Bone]);
        cache_get_value_name_int(i, "Hidden", WeaponSettings[playerid][index][Hidden]);
    }
}