#include <YSI_Coding\y_hooks>

stock AnimationCheck(playerid)
{
	return (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && !pData[playerid][pCuffed] && !pData[playerid][pTazer] && !IsValidLoadingBar(playerid));
}

stock ApplyAnimationEx(playerid, const animlib[], const animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0)
{
	ApplyAnimation(playerid, animlib, animname, fDelta, loop, lockx, locky, freeze, time, forcesync);
	return 1;
}

stock PlayAnimation(playerid, const animlib[], const animname[])
{
	ApplyAnimation(playerid, animlib, animname, 4.0, 1, 0, 0, 0, 0);
	return 1;
}

#define Anim:: anim_
enum Anim::e_AnimStuff
{
    Anim::e_AnimationName[32],
    Anim::e_AnimLib[32],
    Anim::e_AnimName[32],
    Float:Anim::e_AnimDelta,
    bool:Anim::e_AnimLoop,
    bool:Anim::e_AnimLX,
    bool:Anim::e_AnimLY,
    bool:Anim::e_AnimFreeze,
    Anim::e_AnimTime
};
new PlayerText: emoteList[MAX_PLAYERS][35];
new animPage[MAX_PLAYERS] = {1, ...};

new Anim::g_AnimDetails[][Anim::e_AnimStuff] =
{
    {"Baseball 1", "BASEBALL", "Bat_1", 4.1, false, true, true, false, 0},
    {"Baseball 2", "BASEBALL", "Bat_2", 4.1, false, true, true, false, 0},
    {"Baseball 3", "BASEBALL", "Bat_3", 4.1, false, true, true, false, 0},
    {"Baseball 4", "BASEBALL", "Bat_4", 4.1, false, true, true, false, 0},
    {"Baseball Idle", "BASEBALL", "Bat_IDLE", 4.1, true, false, false, false, 0},

    {"Bar 1", "BAR", "Barserve_bottle", 4.1, false, false, false, false, 0},
	{"Bar 2", "BAR", "Barserve_give", 4.1, false, false, false, false, 0},
	{"Bar 3", "BAR", "Barserve_glass", 4.1, false, false, false, false, 0},
	{"Bar 4", "BAR", "Barserve_in", 4.1, false, false, false, false, 0},
	{"Bar 5", "BAR", "Barserve_order", 4.1, false, false, false, false, 0},
	{"Bar 6", "BAR", "BARman_idle", 4.1, true, false, false, false, 0},
	{"Bar 7", "BAR", "dnk_stndM_loop", 4.1, false, false, false, false, 0},
	{"Bar 8", "BAR", "dnk_stndF_loop", 4.1, false, false, false, false, 0},

    {"Berbaring 1", "BEACH", "bather", 4.1, true, false, false, false, 0},
	{"Berbaring 2", "BEACH", "Lay_Bac_Loop", 4.1, true, false, false, false, 0},
	{"Berbaring 3", "BEACH", "ParkSit_M_loop", 4.1, true, false, false, false, 0},
	{"Berbaring 4", "BEACH", "ParkSit_W_loop", 4.1, true, false, false, false, 0},
	{"Berbaring 5", "BEACH", "SitnWait_loop_W", 4.1, true, false, false, false, 0},

    {"Cuci Tangan", "BD_FIRE", "wash_up", 4.1, true, true, true, true, 0},

    {"Car 1", "CAR", "Fixn_Car_Out", 4.1, false, true, true, true, 1},
    {"Car 2", "CAR", "Fixn_Car_Loop", 4.0, true, false, false, false, 0},
    {"Car 3", "CAR", "flag_drop", 4.1, false, true, true, true, 1},

    {"Cop 1", "POLICE","CopTraf_Come", 4.0, true, false, false, false, 0},
	{"Cop 2", "POLICE","CopTraf_Away", 4.0, true, false, false, false, 0},
	{"Cop 3", "POLICE","CopTraf_Stop", 4.0, true, false, false, false, 0},
	{"Cop 4", "POLICE","CopTraf_Left", 4.0, true, false, false, false, 0},

    {"Crossarms 1", "COP_AMBIENT", "Coplook_loop", 4.1, false, true, true, true, 0},
	{"Crossarms 2", "GRAVEYARD", "prst_loopa", 4.1, true, false, false, false, 0},
	{"Crossarms 3", "GRAVEYARD", "mrnM_loop", 4.1, true, false, false, false, 0},
	{"Crossarms 4", "DEALER", "DEALER_IDLE", 4.1, false, true, true, true, 0},

    {"Cium 1", "KISSING", "Grlfrd_Kiss_01", 4.1, false, false, false, false, 0},
	{"Cium 2", "KISSING", "Grlfrd_Kiss_02", 4.1, false, false, false, false, 0},
	{"Cium 3", "KISSING", "Grlfrd_Kiss_03", 4.1, false, false, false, false, 0},
	{"Cium 4", "KISSING", "Playa_Kiss_01", 4.1, false, false, false, false, 0},
	{"Cium 5", "KISSING", "Playa_Kiss_02", 4.1, false, false, false, false, 0},
	{"Cium 6", "KISSING", "Playa_Kiss_03", 4.1, false, false, false, false, 0},

    {"Bom", "BOMBER", "BOM_Plant", 4.1, false, false, false, false, 0},

    {"Crack", "CRACK", "crckdeth1", 4.1, false, false, false, true, 0},
	{"Crack", "CRACK", "crckdeth2", 4.1, true, false, false, false, 0},
	{"Crack", "CRACK", "crckdeth3", 4.1, false, false, false, true, 0},
	{"Crack", "CRACK", "crckidle1", 4.1, false, false, false, true, 0},
	{"Crack", "CRACK", "crckidle2", 4.1, false, false, false, true, 0},
	{"Crack", "CRACK", "crckidle3", 4.1, false, false, false, true, 0},

    {"Deal 1", "DEALER", "DEALER_DEAL", 4.1, false, false, false, false, 0},
	{"Deal 2", "DEALER", "DRUGS_BUY", 4.1, false, false, false, false, 0},
	{"Deal 3", "DEALER", "shop_pay", 4.1, false, false, false, false, 0},
	{"Deal 4", "DEALER", "DEALER_IDLE_01", 4.1, true, false, false, false, 0},
	{"Deal 5", "DEALER", "DEALER_IDLE_02", 4.1, true, false, false, false, 0},
	{"Deal 6", "DEALER", "DEALER_IDLE_03", 4.1, true, false, false, false, 0},

    {"Duduk 1", "CRIB", "PED_Console_Loop", 4.1, true, false, false, false, 0},
	{"Duduk 2", "INT_HOUSE", "LOU_In", 4.1, false, false, false, true, 1},
	{"Duduk 3", "MISC", "SEAT_LR", 4.1, true, false, false, false, 0},
	{"Duduk 4", "MISC", "Seat_talk_01", 4.1, true, false, false, false, 0},
	{"Duduk 5", "MISC", "Seat_talk_02", 4.1, true, false, false, false, 0},
	{"Duduk 6", "ped", "SEAT_down", 4.1, false, false, false, true, 1},

    {"Mabuk", "PED", "WALK_drunk", 4.1, true, true, true, true, 1},
    {"Makan Burger", "FOOD", "EAT_Burger", 4.1, false, false, false, false, 0},
	{"Makan Ayam", "FOOD", "EAT_Chicken", 4.1, false, false, false, false, 0},
	{"Makan Pizza", "FOOD", "EAT_Pizza", 4.1, false, false, false, false, 0},

    {"Menangis", "GRAVEYARD", "mrnF_loop", 4.1, true, false, false, false, 0},
    {"Lelah 1", "PED", "IDLE_tired", 4.1, true, false, false, false, 0},
    {"Lelah 2", "FAT", "IDLE_tired", 4.1, true, false, false, false, 0},

    {"Melambai 1", "PED", "endchat_03", 4.1, false, false, false, false, 0},
	{"Melambai 2", "KISSING", "gfwave2", 4.1, false, false, false, false, 0},
	{"Melambai 3", "ON_LOOKERS", "wave_loop", 4.1, true, false, false, false, 0},

    {"Merokok 1", "SMOKING", "M_smk_drag", 4.1, false, false, false, false, 0},
	{"Merokok 2", "SMOKING", "M_smklean_loop", 4.1, true, false, false, false, 0},
	{"Merokok 3", "SMOKING", "M_smkstnd_loop", 4.1, false, false, false, false, 0},

    {"Menggores 1", "SCRATCHING", "scdldlp", 4.1, true, false, false, false, 0},
	{"Menggores 2", "SCRATCHING", "scdlulp", 4.1, true, false, false, false, 0},
	{"Menggores 3", "SCRATCHING", "scdrdlp", 4.1, true, false, false, false, 0},
	{"Menggores 4", "SCRATCHING", "scdrulp", 4.1, true, false, false, false, 0},

    {"Menari 1", "DANCING", "dance_loop", 4.1, true, false, false, false, 0},
	{"Menari 2", "DANCING", "DAN_Left_A", 4.1, true, false, false, false, 0},
	{"Menari 3", "DANCING", "DAN_Right_A", 4.1, true, false, false, false, 0},
	{"Menari 4", "DANCING", "DAN_Loop_A", 4.1, true, false, false, false, 0},
	{"Menari 5", "DANCING", "DAN_Up_A", 4.1, true, false, false, false, 0},
	{"Menari 6", "DANCING", "DAN_Down_A", 4.1, true, false, false, false, 0},
	{"Menari 7", "DANCING", "dnce_M_a", 4.1, true, false, false, false, 0},
	{"Menari 8", "DANCING", "dnce_M_e", 4.1, true, false, false, false, 0},
	{"Menari 9", "DANCING", "dnce_M_b", 4.1, true, false, false, false, 0},
	{"Menari 0", "DANCING", "dnce_M_c", 4.1, true, false, false, false, 0},

    {"Membawa 1", "CARRY", "liftup", 4.1, false, false, false, false, 0},
	{"Membawa 2", "CARRY", "liftup05", 4.1, false, false, false, false, 0},
	{"Membawa 3", "CARRY", "liftup105", 4.1, false, false, false, false, 0},
	{"Membawa 4", "CARRY", "putdwn", 4.1, false, false, false, false, 0},
	{"Membawa 5", "CARRY", "putdwn05", 4.1, false, false, false, false, 0},
	{"Membawa 6", "CARRY", "putdwn105", 4.1, false, false, false, false, 0},

    {"Mengobrol 1", "GANGS", "prtial_gngtlkA", 4.1, false, false, false, false, 0},
	{"Mengobrol 2", "GANGS", "prtial_gngtlkB", 4.1, false, false, false, false, 0},
	{"Mengobrol 3", "GANGS", "prtial_gngtlkE", 4.1, false, false, false, false, 0},
	{"Mengobrol 4", "GANGS", "prtial_gngtlkF", 4.1, false, false, false, false, 0},
	{"Mengobrol 5", "GANGS", "prtial_gngtlkG", 4.1, false, false, false, false, 0},
	{"Mengobrol 6", "GANGS", "prtial_gngtlkH", 4.1, false, false, false, false, 0},

    {"Medis", "MEDIC", "CPR", 4.1, false, false, false, false, 0},
    {"Ketakutan", "PED", "cower", 4.1, false, false, false, true, 0},
    {"Jari Tengah", "PED", "fucku", 4.1, false, false, false, false, 0},

    {"Muntah", "FOOD", "EAT_Vomit_P", 4.1, false, false, false, false, 0},
    {"Salut", "GHANDS", "gsign5LH", 4.1, false, false, false, false, 0},

    {"Olahraga 1", "benchpress", "gym_bp_celebrate", 4.1, false, false, false, false, 0},
	{"Olahraga 2", "benchpress", "gym_bp_down", 4.1, false, false, false, true, 0},
	{"Olahraga 3", "benchpress", "gym_bp_getoff", 4.1, false, false, false, false, 0},
	{"Olahraga 4", "benchpress", "gym_bp_geton", 4.1, false, false, false, true, 0},
	{"Olahraga 5", "benchpress", "gym_bp_up_A", 4.1, false, false, false, true, 0},
	{"Olahraga 6", "benchpress", "gym_bp_up_B", 4.1, false, false, false, true, 0},
	{"Olahraga 7", "benchpress", "gym_bp_up_smooth", 4.1, false, false, false, true, 0},

    {"Point 1", "PED", "ARRESTgun", 4.1, false, false, false, true, 0},
	{"Point 2", "SHOP", "ROB_Loop_Threat", 4.1, true, false, false, false, 0},
    {"Point 3", "ON_LOOKERS", "point_loop", 4.1, true, false, false, false, 0},
	{"Point 4", "ON_LOOKERS", "Pointup_loop", 4.1, true, false, false, false, 0},

    {"Kacamata", "goggles", "goggles_put_on", 4.1, false, false, false, false, 0},
    {"Semprot", "GRAFFITI", "spraycan_fire", 4.1, true, false, false, false, 0},
    {"Melemparkan", "GRENADE", "WEAPON_throw", 4.1, false, false, false, false, 0},

    {"Teriak 1", "ON_LOOKERS", "shout_01", 4.1, false, false, false, false, 0},
	{"Teriak 2", "ON_LOOKERS", "shout_02", 4.1, false, false, false, false, 0},

    {"Taichi", "PARK", "Tai_Chi_Loop", 4.1, true, false, false, false, 0},

    {"Wank 1", "PAULNMAC", "wank_loop", 4.1, true, false, false, false, 0},
	{"Wank 2", "PAULNMAC", "wank_in", 4.1, false, false, false, false, 0},
	{"Wank 3", "PAULNMAC", "wank_out", 4.1, false, false, false, false, 0},

    {"Tidur 1", "CRACK", "crckdeth4", 4.1, false, false, false, true, 0},
	{"Tidur 2", "CRACK", "crckidle4", 4.1, false, false, false, true, 0},
    {"Tamparan", "BASEBALL", "Bat_M", 4.1, false, false, false, false, 0},

    {"Lompat", "DODGE", "Crush_Jump", 4.1, false, true, true, false, 0},

    {"Seks Oral 1", "BLOWJOBZ", "BJ_COUCH_LOOP_W", 4.1, true, false, false, false, 0},
	{"Seks Oral 2", "BLOWJOBZ", "BJ_COUCH_LOOP_P", 4.1, true, false, false, false, 0},
	{"Seks Oral 3", "BLOWJOBZ", "BJ_STAND_LOOP_W", 4.1, true, false, false, false, 0},
	{"Seks Oral 4", "BLOWJOBZ", "BJ_STAND_LOOP_P", 4.1, true, false, false, false, 0},

    {"Strips 1", "STRIP", "strip_A", 4.1, true, false, false, false, 0},
	{"Strips 1", "STRIP", "strip_B", 4.1, true, false, false, false, 0},
	{"Strips 1", "STRIP", "strip_C", 4.1, true, false, false, false, 0},
	{"Strips 1", "STRIP", "strip_D", 4.1, true, false, false, false, 0},
	{"Strips 1", "STRIP", "strip_E", 4.1, true, false, false, false, 0},
	{"Strips 1", "STRIP", "strip_F", 4.1, true, false, false, false, 0},
	{"Strips 1", "STRIP", "strip_G", 4.1, true, false, false, false, 0},

    {"Gsign 1", "GHANDS", "gsign1", 4.1, false, false, false, false, 0},
	{"Gsign 2", "GHANDS", "gsign1LH", 4.1, false, false, false, false, 0},
	{"Gsign 3", "GHANDS", "gsign2", 4.1, false, false, false, false, 0},
	{"Gsign 4", "GHANDS", "gsign2LH", 4.1, false, false, false, false, 0},
	{"Gsign 5", "GHANDS", "gsign3", 4.1, false, false, false, false, 0},
	{"Gsign 6", "GHANDS", "gsign3LH", 4.1, false, false, false, false, 0},
	{"Gsign 7", "GHANDS", "gsign4", 4.1, false, false, false, false, 0},
	{"Gsign 8", "GHANDS", "gsign4LH", 4.1, false, false, false, false, 0},
	{"Gsign 9", "GHANDS", "gsign5", 4.1, false, false, false, false, 0},
	{"Gsign 10", "GHANDS", "gsign5", 4.1, false, false, false, false, 0},
	{"Gsign 11", "GHANDS", "gsign5LH", 4.1, false, false, false, false, 0},
	{"Gsign 12", "GANGS", "Invite_No", 4.1, false, false, false, false, 0},
	{"Gsign 13", "GANGS", "Invite_Yes", 4.1, false, false, false, false, 0},
	{"Gsign 14", "GANGS", "prtial_gngtlkD", 4.1, false, false, false, false, 0},
	{"Gsign 15", "GANGS", "smkcig_prtl", 4.1, false, false, false, false, 0},

    {"Pisau 1", "KNIFE", "knife_1", 4.1, false, true, true, false, 0},
	{"Pisau 2", "KNIFE", "knife_2", 4.1, false, true, true, false, 0},
	{"Pisau 3", "KNIFE", "knife_3", 4.1, false, true, true, false, 0},
	{"Pisau 4", "KNIFE", "knife_4", 4.1, false, true, true, false, 0},
	{"Pisau 5", "KNIFE", "WEAPON_knifeidle", 4.1, true, false, false, false, 0},
	{"Pisau 6", "KNIFE", "KILL_Knife_Player", 4.1, false, false, false, false, 0},
	{"Pisau 7", "KNIFE", "KILL_Knife_Ped_Damage", 4.1, false, false, false, false, 0},
	{"Pisau 8", "KNIFE", "KILL_Knife_Ped_Die", 4.1, false, false, false, false, 0},

    {"Kantor 1", "INT_OFFICE", "OFF_Sit_Bored_Loop", 4.1, true, false, false, false, 0},
    {"Kantor 2", "INT_OFFICE", "OFF_Sit_Crash", 4.1, true, false, false, false, 0},
    {"Kantor 3", "INT_OFFICE", "OFF_Sit_Drink", 4.1, true, false, false, false, 0},
    {"Kantor 4", "INT_OFFICE", "OFF_Sit_Read", 4.1, true, false, false, false, 0},
    {"Kantor 5", "INT_OFFICE", "OFF_Sit_Type_Loop", 4.1, true, false, false, false, 0},
    {"Kantor 6", "INT_OFFICE", "OFF_Sit_Watch", 4.1, true, false, false, false, 0},

    {"Jalan Fat", "FAT", "FatWalk", 4.1, true, true, true, true, 1},
	{"Jalan Muscle", "MUSCULAR", "MuscleWalk", 4.1, true, true, true, true, 1},
	{"Jalan Armed", "PED", "WALK_armed", 4.1, true, true, true, true, 1},
	{"Jalan Civil", "PED", "WALK_civi", 4.1, true, true, true, true, 1},
	{"Jalan Gang 1", "PED", "WALK_gang1", 4.1, true, true, true, true, 1},
	{"Jalan Gang 2", "PED", "WALK_gang2", 4.1, true, true, true, true, 1},
	{"Jalan Player", "PED", "WALK_player", 4.1, true, true, true, true, 1},
	{"Jalan Old", "PED", "WALK_old", 4.1, true, true, true, true, 1},
	{"Jalan Wuzi", "PED", "WALK_wuzi", 4.1, true, true, true, true, 1},
	{"Jalan Busy", "PED", "WOMAN_walkbusy", 4.1, true, true, true, true, 1},
	{"Jalan Fat Old", "PED", "WOMAN_walkfatold", 4.1, true, true, true, true, 1},
	{"Jalan Normal", "PED", "WOMAN_walknorm", 4.1, true, true, true, true, 1},
	{"Jalan Sexy", "PED", "WOMAN_walksexy", 4.1, true, true, true, true, 1},
	{"Jalan Shop", "PED", "WOMAN_walkshop", 4.1, true, true, true, true, 1}
};

enum e_AnimPropStuff
{
    e_AnimationPropName[32],
    e_AnimPropLib[32],
    e_AnimPropName[32],
    Float:e_AnimPropDelta,
    bool:e_AnimPropLoop,
    bool:e_AnimPropLX,
    bool:e_AnimPropLY,
    bool:e_AnimPropFreeze,
    e_AnimPropTime,

    //prop object
    e_AnimPropIndex,
    e_AnimPropModel,
    e_AnimPropBone,
    Float:e_AnimPropoffX,
    Float:e_AnimPropoffy,
    Float:e_AnimPropoffz,
    Float:e_AnimPropRotX,
    Float:e_AnimPropRotY,
    Float:e_AnimPropRotz,
    Float:e_AnimPropScaX,
    Float:e_AnimPropScaY,
    Float:e_AnimPropScaz,
    e_AnimPropMatCole,
    e_AnimPropMatCol1
};

new g_AnimPropDetails[][e_AnimPropStuff] =
{
    {"Bunga", "KISSING", "gift_give", 5.33, false, false, false, false, 0, 9, 325, 6, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Dildo", "PAULNMAC", "WANK_LOOP", 4.0, true, false, false, true, 0, 9, 321, 5, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Dildo2", "PAULNMAC", "WANK_LOOP", 4.0, true, false, false, true, 0, 9, 322, 5, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Bat", "CRACK", "Bbalbat_Idle_01", 6.67, true, false, false, true, 0, 9, 336, 6, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Bat2", "CRACK", "Bbalbat_Idle_02", 10.00, true, false, false, true, 0, 9, 336, 6, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Baton", "CRACK", "Bbalbat_Idle_01", 6.67, true, false, false, true, 0, 9, 334, 6, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Baton2", "CRACK", "Bbalbat_Idle_02", 10.00, true, false, false, true, 0, 9, 334, 6, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Skate", "ped","Jetpack_Idle", 4.1, false, false, false, true, 0, 9, 19878, 5, 0.016000, 0.028000, 0.456000, 0.400000, 91.400108, -1.100000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Mic", "ped","Jetpack_Idle", 4.1, false, false, false, true, 0, 9, 19610, 5, 0.051999, 0.028999, -0.020000, -84.299865, -0.799999, 10.899998, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Bendera", "ped","Jetpack_Idle", 4.1, false, false, false, true, 0, 9, 11245, 5, -0.097999, 0.039000, 0.091999, 1.500000, 103.000022, -2.900001, 0.384999, 0.204000, 0.276000, 0, 0},
    {"Gitar", "CRACK", "Bbalbat_Idle_01", 6.67, true, false, false, true, 0, 9, 19317, 1, -0.145000, 0.356999, 0.211999, -9.399999, 25.299961, 154.199905, 1.000000, 1.051999, 1.000000, 0, 0},

    {"Kursi", "ped", "SEAT_down", 4.1, false, false, false, true, 0, 9, 1369, 1, -0.207000, 0.101999, -0.010000, -88.599967, 100.600143, -94.200103, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Kursi2",  "ped", "SEAT_down", 4.1, false, false, false, true, 0, 9, 2121, 1, -0.324999, 0.050000, -0.015000, -128.700027, 94.600151, -55.500225, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Camera", "CAMERA", "piccrch_take", 1.0, true, false, false, false, 0, 9, 19623, 6, 0.074999, 0.112999, 0.079999, 0.000000, 0.000000, 96.599990, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Camera2", "CAMERA", "picstnd_take", 1.0, true, false, false, false, 0, 9, 19623, 6, 0.152000, 0.068999, 0.037999, 3.899933, -0.499996, 91.399879, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Payung", "ped","Jetpack_Idle", 4.1, false, false, false, true, 0, 9, 642, 5, -0.279000, 0.126000, -0.356999, 19.699987, -134.099990, 1.599998, 0.368000, 0.371000, 0.470999, 0xFF3A3B3C, 0xFF3A3B3C},
    {"Basket", "BSKTBALL","BBALL_idleloop", 0.67, true, false, false, true, 0, 9, 2114, 6, 0.300000, 0.000000, 0.039999, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Basket2", "BSKTBALL","BBALL_run", 0.90, true, true, true, true, 0, 9, 2114, 6, 0.300000, 0.000000, 0.039999, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Basket3", "BSKTBALL","BBALL_walk", 1.07, true, true, true, true, 0, 9, 2114, 6, 0.300000, 0.000000, 0.039999, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000, 0, 0},
    {"Medbox", "CAMERA", "camcrch_idleloop", 2.0, true, false, false, false, 0, 9, 11738, 1, -0.522999, 0.668999, 0.550999, 74.799995, 76.100028, -21.699998, 1.473999, 1.431999, 1.212000, 0, 0}
};

new g_animPropIndex[MAX_PLAYERS];

hook OnPlayerConnect(playerid) {
    emoteList[playerid][0] = CreatePlayerTextDraw(playerid, 480.500, 100.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][0], 156.000, 17.000);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][0], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][0], SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][0], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][0], true);

    emoteList[playerid][1] = CreatePlayerTextDraw(playerid, 480.500, 52.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][1], 156.000, 47.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][1], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][1], SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][1], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][1], true);

    emoteList[playerid][2] = CreatePlayerTextDraw(playerid, 557.000, 64.000, "EMOTE LIST");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][2], 0.469, 2.299);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][2], 2);
    PlayerTextDrawColor(playerid, emoteList[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][2], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][2], 3);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][2], true);

    emoteList[playerid][3] = CreatePlayerTextDraw(playerid, 494.000, 105.000, "Shared Emotes");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][3], 0.189, 0.999);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][3], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][3], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][3], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][3], true);

    emoteList[playerid][4] = CreatePlayerTextDraw(playerid, 485.000, 103.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][4], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][4], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][4], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][4], true);

    emoteList[playerid][5] = CreatePlayerTextDraw(playerid, 483.000, 108.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][5], 10.000, 7.000);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][5], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][5], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][5], true);

    emoteList[playerid][6] = CreatePlayerTextDraw(playerid, 633.000, 105.000, "200 / 200");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][6], 0.189, 0.999);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][6], 3);
    PlayerTextDrawColor(playerid, emoteList[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][6], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][6], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][6], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][6], true);

    emoteList[playerid][7] = CreatePlayerTextDraw(playerid, 480.500, 117.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][7], 156.000, 178.000);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][7], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][7], 148);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][7], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][7], true);

    emoteList[playerid][8] = CreatePlayerTextDraw(playerid, 480.500, 117.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][8], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][8], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][8], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][8], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][8], true);

    emoteList[playerid][17] = CreatePlayerTextDraw(playerid, 480.500, 262.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][17], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][17], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][17], 0);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][17], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][17], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][17], true);

    emoteList[playerid][16] = CreatePlayerTextDraw(playerid, 480.500, 246.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][16], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][16], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][16], 0);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][16], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][16], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][16], true);

    emoteList[playerid][15] = CreatePlayerTextDraw(playerid, 480.500, 230.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][15], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][15], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][15], 0);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][15], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][15], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][15], true);

    emoteList[playerid][14] = CreatePlayerTextDraw(playerid, 480.500, 214.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][14], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][14], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][14], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][14], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][14], true);

    emoteList[playerid][13] = CreatePlayerTextDraw(playerid, 480.500, 198.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][13], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][13], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][13], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][13], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][13], true);

    emoteList[playerid][12] = CreatePlayerTextDraw(playerid, 480.500, 182.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][12], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][12], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][12], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][12], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][12], true);

    emoteList[playerid][11] = CreatePlayerTextDraw(playerid, 480.500, 166.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][11], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][11], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][11], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][11], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][11], true);

    emoteList[playerid][10] = CreatePlayerTextDraw(playerid, 480.500, 150.199, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][10], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][10], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][10], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][10], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][10], true);

    emoteList[playerid][9] = CreatePlayerTextDraw(playerid, 480.500, 133.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][9], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][9], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][9], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][9], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][9], true);

    emoteList[playerid][18] = CreatePlayerTextDraw(playerid, 480.500, 278.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][18], 156.000, 16.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][18], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][18], 148);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][18], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][18], true);

    emoteList[playerid][19] = CreatePlayerTextDraw(playerid, 483.500, 120.000, "Emote 1");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][19], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][19], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][19], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][19], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][19], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][19], true);

    emoteList[playerid][20] = CreatePlayerTextDraw(playerid, 483.500, 136.000, "Emote 2");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][20], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][20], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][20], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][20], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][20], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][20], true);

    emoteList[playerid][21] = CreatePlayerTextDraw(playerid, 483.500, 152.000, "Emote 3");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][21], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][21], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][21], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][21], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][21], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][21], true);

    emoteList[playerid][22] = CreatePlayerTextDraw(playerid, 483.500, 168.000, "Emote 4");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][22], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][22], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][22], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][22], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][22], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][22], true);

    emoteList[playerid][23] = CreatePlayerTextDraw(playerid, 483.500, 184.000, "Emote 5");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][23], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][23], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][23], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][23], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][23], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][23], true);

    emoteList[playerid][24] = CreatePlayerTextDraw(playerid, 483.500, 200.000, "Emote 6");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][24], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][24], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][24], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][24], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][24], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][24], true);

    emoteList[playerid][25] = CreatePlayerTextDraw(playerid, 483.500, 216.000, "Emote 7");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][25], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][25], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][25], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][25], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][25], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][25], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][25], true);

    emoteList[playerid][26] = CreatePlayerTextDraw(playerid, 483.500, 232.000, "Emote 8");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][26], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][26], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][26], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][26], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][26], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][26], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][26], true);

    emoteList[playerid][27] = CreatePlayerTextDraw(playerid, 483.500, 248.000, "Emote 9");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][27], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][27], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][27], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][27], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][27], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][27], true);

    emoteList[playerid][28] = CreatePlayerTextDraw(playerid, 483.500, 264.000, "Emote 10");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][28], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][28], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][28], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][28], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][28], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][28], true);

    emoteList[playerid][29] = CreatePlayerTextDraw(playerid, 599.000, 280.600, "NEXT >");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][29], 0.219, 1.199);
    PlayerTextDrawTextSize(playerid, emoteList[playerid][29], 628.000, 12.000);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][29], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][29], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][29], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][29], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][29], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][29], true);

    emoteList[playerid][30] = CreatePlayerTextDraw(playerid, 490.000, 280.600, "< PREV");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][30], 0.219, 1.199);
    PlayerTextDrawTextSize(playerid, emoteList[playerid][30], 519.000, 12.000);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][30], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][30], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][30], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][30], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][30], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][30], true);

    emoteList[playerid][31] = CreatePlayerTextDraw(playerid, 480.500, 297.500, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][31], 156.000, 30.500);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][31], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][31], 148);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][31], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][31], true);

    emoteList[playerid][32] = CreatePlayerTextDraw(playerid, 484.000, 302.000, "/e (~g~emote~w~) untuk memainkannya atau klik langsung di atas");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][32], 0.179, 0.999);
    PlayerTextDrawTextSize(playerid, emoteList[playerid][32], 620.000, 0.000);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][32], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][32], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][32], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][32], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][32], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][32], 1);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][32], true);

    emoteList[playerid][33] = CreatePlayerTextDraw(playerid, 557.000, 80.000, "Kampung Indo Roleplay");
    PlayerTextDrawLetterSize(playerid, emoteList[playerid][33], 0.349, 1.498);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][33], 2);
    PlayerTextDrawColor(playerid, emoteList[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][33], 1);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][33], 1);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][33], 0);
    PlayerTextDrawFont(playerid, emoteList[playerid][33], 0);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][33], true);

    emoteList[playerid][34] = CreatePlayerTextDraw(playerid, 552.000, 279.500, "LD_BEAT:cross");
    PlayerTextDrawTextSize(playerid, emoteList[playerid][34], 12.000, 15.000);
    PlayerTextDrawAlignment(playerid, emoteList[playerid][34], 1);
    PlayerTextDrawColor(playerid, emoteList[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, emoteList[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, emoteList[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, emoteList[playerid][34], 255);
    PlayerTextDrawFont(playerid, emoteList[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, emoteList[playerid][34], true);
    PlayerTextDrawSetSelectable(playerid, emoteList[playerid][34], true);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

SyncAnimPage(playerid) {
    new ePage = animPage[playerid];
    new totalAnimDetails = sizeof(Anim::g_AnimDetails);
    new maxVisibleEmotes = 10;
    for(new i = 19; i < 29; i++) { 
        if(i < maxVisibleEmotes && i < totalAnimDetails) {
            PlayerTextDrawShow(playerid, emoteList[playerid][i]);
        } else {
            PlayerTextDrawHide(playerid, emoteList[playerid][i]);
        }
    }
    PlayerTextDrawShow(playerid, emoteList[playerid][6]);
    PlayerTextDrawSetString(playerid, emoteList[playerid][6], va_return("%d / %d", ePage, totalAnimDetails));
    return 1;
}

CMD:elist(playerid, const params[])
{
    Dialog_Show(playerid, ListEmotes, DIALOG_STYLE_LIST, "Daftar Emote", ""SBLUE_E"Emotes\n"GREY_E"Emotes Property\n"SBLUE_E"", "Pilih", "Batal");
    return 1;
}

Dialog:ListEmotes(playerid, response, listitem, inputext[])
{
    if(!response) return 1;

    switch(listitem)
    {
        case 0:
        {
            new str[1500];
            for(new index = 0; index < sizeof(Anim::g_AnimDetails); index ++)
            {
                strcat(str, va_return("%s\n", Anim::g_AnimDetails[index][Anim::e_AnimationName]));
            }
            Dialog_Show(playerid, DIALOG_NONE, DIALOG_STYLE_LIST, "Emotes", str, "Pilih", "Batal");
        }
        case 1:
        {
            new str[1500];
            for(new index = 0; index < sizeof(g_AnimPropDetails); index ++)
            {
                strcat(str, va_return("%s\n", g_AnimPropDetails[index][e_AnimationPropName]));
            }
            Dialog_Show(playerid, DIALOG_NONE, DIALOG_STYLE_LIST, "Emotes Property", str, "Pilih", "Batal");
        }
    }
    return 1;
}

CMD:emotemenu(playerid, const params[])
{
    new i;
    if (isnull(params)) {
        for(i = 0; i < 35; i++) {
            if(i < 19 || i > 28) {
                new totalAnimDetails = sizeof(Anim::g_AnimDetails);
                PlayerTextDrawShow(playerid, emoteList[playerid][i]);
                PlayerTextDrawSetString(playerid, emoteList[playerid][6], va_return("%d / %d", animPage[playerid], totalAnimDetails));
            } else {
                if(i - 19 < 10) { 
                    PlayerTextDrawSetString(playerid, emoteList[playerid][i], Anim::g_AnimDetails[i - 19][Anim::e_AnimationName]);
                    PlayerTextDrawShow(playerid, emoteList[playerid][i]);
                }
            }
        }
        animPage[playerid] = 1;
        SelectTextDraw(playerid, -1);
    } else {
        if(!strcmp("x", params, true))
        {
            if(AnimationCheck(playerid))
            {
                if(IsPlayerAttachedObjectSlotUsed(playerid, g_animPropIndex[playerid])) RemovePlayerAttachedObject(playerid, g_animPropIndex[playerid]);
                ClearAnimations(playerid);
                SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
            }
        } else {
            for(new index = 0; index < sizeof(Anim::g_AnimDetails); index ++)
            {
                if(!strcmp(Anim::g_AnimDetails[index][Anim::e_AnimationName], params, true))
                {
                    ApplyAnimationEx(playerid, Anim::g_AnimDetails[index][Anim::e_AnimLib], Anim::g_AnimDetails[index][Anim::e_AnimName], Anim::g_AnimDetails[index][Anim::e_AnimDelta], Anim::g_AnimDetails[index][Anim::e_AnimLoop], Anim::g_AnimDetails[index][Anim::e_AnimLX], Anim::g_AnimDetails[index][Anim::e_AnimLY], Anim::g_AnimDetails[index][Anim::e_AnimFreeze], Anim::g_AnimDetails[index][Anim::e_AnimTime]);
                    return 1;
                }
            }
        }
    }
    return 1;
}

CMD:eprop(playerid, params[])
{
    new name[32];
    if(sscanf(params, "s[32]", name))
	    return SyntaxMsg(playerid, "/eprop [nama animasi]");

    if(!strcmp("x", name, true))
    {
        if(AnimationCheck(playerid))
        {
            if(IsPlayerAttachedObjectSlotUsed(playerid, g_animPropIndex[playerid])) RemovePlayerAttachedObject(playerid, g_animPropIndex[playerid]);

            ClearAnimations(playerid, true);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
            Servers(playerid, "You have stopped any animations.");
        }
        return 1;
    }
    else
    {
        for(new index = 0; index < sizeof(g_AnimPropDetails); index ++)
        {
            if(!strcmp(g_AnimPropDetails[index][e_AnimationPropName], name, true))
            {
                ApplyAnimationEx(playerid, g_AnimPropDetails[index][e_AnimPropLib], g_AnimPropDetails[index][e_AnimPropName], g_AnimPropDetails[index][e_AnimPropDelta], g_AnimPropDetails[index][e_AnimPropLoop], g_AnimPropDetails[index][e_AnimPropLX], g_AnimPropDetails[index][e_AnimPropLY], g_AnimPropDetails[index][e_AnimPropFreeze], g_AnimPropDetails[index][e_AnimPropTime]);
                SetPlayerAttachedObject(playerid, g_AnimPropDetails[index][e_AnimPropIndex], g_AnimPropDetails[index][e_AnimPropModel], g_AnimPropDetails[index][e_AnimPropBone], g_AnimPropDetails[index][e_AnimPropoffX], g_AnimPropDetails[index][e_AnimPropoffy], g_AnimPropDetails[index][e_AnimPropoffz], g_AnimPropDetails[index][e_AnimPropRotX], g_AnimPropDetails[index][e_AnimPropRotY], g_AnimPropDetails[index][e_AnimPropRotz], g_AnimPropDetails[index][e_AnimPropScaX], g_AnimPropDetails[index][e_AnimPropScaY], g_AnimPropDetails[index][e_AnimPropScaz], g_AnimPropDetails[index][e_AnimPropMatCole], g_AnimPropDetails[index][e_AnimPropMatCol1]);
                g_animPropIndex[playerid] = g_AnimPropDetails[index][e_AnimPropIndex];
                return 1;
            }
        }
    }
    Error(playerid, "Eprop tidak tersedia!");
    return 1;
}

CMD:mic(playerid, params[]) {
    for(new index = 0; index < sizeof(g_AnimPropDetails); index ++) {
        ApplyAnimationEx(playerid, g_AnimPropDetails[index][e_AnimPropLib], g_AnimPropDetails[index][e_AnimPropName], g_AnimPropDetails[index][e_AnimPropDelta], g_AnimPropDetails[index][e_AnimPropLoop], g_AnimPropDetails[index][e_AnimPropLX], g_AnimPropDetails[index][e_AnimPropLY], g_AnimPropDetails[index][e_AnimPropFreeze], g_AnimPropDetails[index][e_AnimPropTime]);
        SetPlayerAttachedObject(playerid, g_AnimPropDetails[index][e_AnimPropIndex], g_AnimPropDetails[index][e_AnimPropModel], g_AnimPropDetails[index][e_AnimPropBone], g_AnimPropDetails[index][e_AnimPropoffX], g_AnimPropDetails[index][e_AnimPropoffy], g_AnimPropDetails[index][e_AnimPropoffz], g_AnimPropDetails[index][e_AnimPropRotX], g_AnimPropDetails[index][e_AnimPropRotY], g_AnimPropDetails[index][e_AnimPropRotz], g_AnimPropDetails[index][e_AnimPropScaX], g_AnimPropDetails[index][e_AnimPropScaY], g_AnimPropDetails[index][e_AnimPropScaz], g_AnimPropDetails[index][e_AnimPropMatCole], g_AnimPropDetails[index][e_AnimPropMatCol1]);
        g_animPropIndex[playerid] = g_AnimPropDetails[index][e_AnimPropIndex];
    }
    return 1;
}
