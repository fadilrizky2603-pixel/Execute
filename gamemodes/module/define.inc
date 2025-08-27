
#define forex(%0,%1)                    							for(new %0 = 0; %0 < %1; %0++)

// how many seconds until it kicks the player for taking too long to login
#define		SECONDS_TO_LOGIN 120

// default spawn point: Las Venturas (The High Roller)
#define 	DEFAULT_POS_X 		1094.34
#define 	DEFAULT_POS_Y 		-2037.15
#define 	DEFAULT_POS_Z 		82.75
#define 	DEFAULT_POS_A 		0.07

//Penganti 3Tryg
#define GetDistanceBetweenPoints3D(%1,%2,%3,%4,%5,%6)			VectorSize((%1)-(%4),(%2)-(%5),(%3)-(%6))
#define GetDistanceBetweenPoints						GetDistanceBetweenPoints3D

//Android Client Check
#define IsPlayerAndroid(%0)                 GetPVarInt(%0, "NotAndroid") == 0

//
#define forex(%0,%1) for(new %0 = 0; %0 < %1; %0++)

// Message
#define function%0(%1) forward %0(%1); public %0(%1)
#define Servers(%1,%2) SendClientMessageEx(%1, -1, "{00A2FF}(server) {FFFFFF}"%2)
#define Info(%1,%2) SendClientMessageEx(%1, -1, "{FFFF00}(info) {FFFFFF}"%2)
#define Action(%1,%2) SendClientMessageEx(%1, -1, "{C2A3DA}(action) {FFFFFF}"%2)
#define Vehicle(%1,%2) SendClientMessageEx(%1, -1, "{FFA200}(vehicle) {FFFFFF}"%2)
#define Usage(%1,%2) SendClientMessage(%1, -1, "{FFFF77}(usage) {FFFFFF}"%2)
#define Names(%1,%2) SendClientMessage(%1, -1, "{8A8A8A}(names) {FFFFFF}"%2)
#define Error(%1,%2) SendClientMessageEx(%1, -1, "{FF0000}(error) {FFFFFF}"%2)
#define PermissionError(%0) SendClientMessage(%0, -1, "{FF0000}(error) {FFFFFF}Anda tidak memiliki hak akses untuk menggunakan command ini")
#define AdminCMD(%1,%2) SendClientMessageEx(%1, -1, "{FF3939}(AdminLogs) {FFFFFF}"%2)
#define SpeedCheck(%0,%1,%2,%3,%4) floatround(floatsqroot(%4?(%0*%0+%1*%1+%2*%2):(%0*%0+%1*%1) ) *%3*1.6)

#define HOLDING(%0)                     ((newkeys & (%0)) == (%0))

#define SendCustomMessage(%0,%1,%2)     SendClientMessageEx(%0, COLOR_LBLUE, %1": "WHITE""%2)

#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

//Converter
#define minplus(%1) \
        (((%1) < 0) ? (-(%1)) : ((%1)))

// AntiCaps
#define UpperToLower(%1) for( new ToLowerChar; ToLowerChar < strlen( %1 ); ToLowerChar ++ ) if ( %1[ ToLowerChar ]> 64 && %1[ ToLowerChar ] < 91 ) %1[ ToLowerChar ] += 32

// Banneds
const BAN_MASK = (-1 << (32 - (/*this is the CIDR ip detection range [def: 26]*/26)));

#if !defined BCRYPT_HASH_LENGTH
	#define BCRYPT_HASH_LENGTH 250
#endif

#if !defined BCRYPT_COST
	#define BCRYPT_COST 12
#endif

//---------[ Define Faction ]-----
#define SAPD	1		//locker 1573.26, -1652.93, -40.59
#define	SAGS	2		// 1464.10, -1790.31, 2349.68
#define SAMD	3		// -1100.25, 1980.02, -58.91
#define SANEW	4		// 256.14, 1776.99, 701.08
#define SACF    5               // 256.14, 1776.99, 701.08
//---------[ JOB ]---------//
#define BOX_INDEX            9 // Index Box Barang

//mdc
#define MAX_EMERGENCY		(300)
#define MDC_ERROR               (21001)
#define MDC_ERROR               (21001)
#define MDC_SELECT              (21000)
#define MDC_OPEN                (45400)

//img
/*new g_player_listitem[MAX_PLAYERS][96];
#define GetPlayerListitemValue(%0,%1)         g_player_listitem[%0][%1]
#define SetPlayerListitemValue(%0,%1,%2)     g_player_listitem[%0][%1] = %2
*/
new g_ListedItems[MAX_PLAYERS][500];
//-----[ eSelection Define ]-----
#define 	SPAWN_SKIN_MALE 		1
#define 	SPAWN_SKIN_FEMALE 		2
#define 	SHOP_SKIN_MALE 			3
#define 	SHOP_SKIN_FEMALE 		4
#define 	VIP_SKIN_MALE 			5
#define 	VIP_SKIN_FEMALE 		6
#define 	SAPD_SKIN_MALE 			7
#define 	SAPD_SKIN_FEMALE 		8
#define 	SAPD_SKIN_WAR 			9
#define 	SAGS_SKIN_MALE 			10
#define 	SAGS_SKIN_FEMALE 		11
#define 	SAMD_SKIN_MALE 			12
#define 	SAMD_SKIN_FEMALE 		13
#define 	SANA_SKIN_MALE 			14
#define 	SANA_SKIN_FEMALE 		15
#define 	SACF_SKIN_MALE 			16
#define 	SACF_SKIN_FEMALE 		17
#define 	TOYS_MODEL 				18
#define 	VIPTOYS_MODEL 			19
#define     VEHICLE_TOYS            20
#define		BARRICADE_OBJECT		21

//----------[ Lumber Object Vehicle Job ]------------
#define MAX_LUMBERS 100
#define LUMBER_LIFETIME 100
#define LUMBER_LIMIT 10

#define COLOR_WHITE 		0xFFFFFFFF
#define COLOR_WHITEP 		0xFFE4C4FF
#define COLOR_ORANGE   		0xDB881AFF
#define COLOR_ORANGE2		0xFF5000FF
#define COLOR_IVORY 		0xFFFF82FF
#define COLOR_LIME 			0xD2D2ABFF
#define COLOR_BLUE			0x004BFFFF
#define COLOR_SBLUE			0x56A4E4FF
#define COLOR_LBLUE 		0x33CCFFFF
#define COLOR_RCONBLUE      0x0080FF99
#define COLOR_PURPLE2 		0x5A00FFFF
#define COLOR_PURPLE      	0xD0AEEBFF
#define COLOR_RED 			0xFF0000FF
#define COLOR_ADMIN 		0xFF0000FF
#define COLOR_LRED 			0xE65555FF
#define COLOR_LIGHTGREEN 	0x00FF00FF
#define COLOR_YELLOW 		0xFFFF00FF
#define COLOR_YELLOW2 		0xF5DEB3FF
#define COLOR_LB 			0x15D4EDFF
#define COLOR_PINK			0xEE82EEFF
#define COLOR_PINK2		 	0xFF828200
#define COLOR_GOLD			0xFFD700FF
#define COLOR_FIREBRICK 	0xB22222FF
#define COLOR_GREEN 		0x3BBD44FF
#define COLOR_GREY			0xBABABAFF
#define COLOR_GREY2 		0x778899FF
#define COLOR_GREY3			0xC8C8C8FF
#define COLOR_DARK 			0x7A7A7AFF
#define COLOR_BROWN 		0x8B4513FF
#define COLOR_SYSTEM 		0xEFEFF7FF
#define COLOR_RADIO       	0x8D8DFFFF
#define COLOR_FAMILY		0x00F77AFF
#define COLOR_SKY			0xC6E2FFFF
#define	COLOR_AQUA			0x00FFFFFF
#define COLOR_HOSPITAL      0xFF8282FF

#define FAMILY_E	"{F77AFF}"
#define PURPLE_E2	"{7348EB}"
#define RED_E 		"{FF0000}"
#define GOLD_E 		"{FFD700}"
#define BLUE_E 		"{004BFF}"
#define SBLUE_E 	"{56A4E4}"
#define PINK_E 		"{FFB6C1}"
#define YELLOW_E 	"{FFFF00}"
#define LG_E 		"{00FF00}"
#define LB_E 		"{15D4ED}"
#define LB2_E 		"{87CEFA}"
#define GREY_E 		"{BABABA}"
#define GREY2_E 	"{778899}"
#define GREY3_E 	"{C8C8C8}"
#define DARK_E 		"{7A7A7A}"
#define WHITE_E 	"{FFFFFF}"
#define WHITEP_E 	"{FFE4C4}"
#define IVORY_E 	"{FFFF82}"
#define ORANGE_E 	"{DB881A}"
#define ORANGE_E2	"{FF5000}"
#define GREEN_E 	"{3BBD44}"
#define GREEN_LIGHT "{00FF00}"
#define PURPLE_E 	"{5A00FF}"
#define LIME_E 		"{D2D2AB}"
#define LRED_E		"{E65555}"
#define DOOM_		"{F4A460}"
#define MATHS       "{3571FC}"
#define REACTIONS   "{FD4141}"
#define SKY_E		"{C6E2FF}"
#define AQUA_E		"{00FFFF}"
#define BLUEW_E		"{ABC1ED}"

#define dot "{F2F853}> {F0F0F0}"

//=== Color ===
#define COLOR_RGB(%1,%2,%3,%4) (((((%1) & 0xff) << 24) | (((%2) & 0xff) << 16) | (((%3) & 0xff) << 8) | ((%4) & 0xff)))
#define StripAlpha(%0) ((%0) >>> 8)

#define MODE_SKATE (0)        // 0 - medium speed | 1 - fast speed
#define TYPE_SKATE (0)        // 0 - the skate is placed on the right arm | 1 - the skate is placed in the back
#define INDEX_SKATE (0)       //is the slot that used SetPlayerAttachedObject