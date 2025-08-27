// COLOR DEFINE
#define 	WARNA_MERAH		"{FF0000}"
#define 	WARNA_KUNING	"{FFFF00}"
#define 	WARNA_BIRU		"{0099FF}"
#define 	WARNA_PUTIH		"{FFFFFF}"

// RADIO DEFINE
#define 	MAX_FREQUENSI	99999

// MESSAGE DEFINE
#define Servers(%1,%2) SendClientMessage(%1, -1, "{00A2FF}<SV> {FFFFFF}"%2)
#define Info(%1,%2) SendClientMessage(%1, -1, "{FFFF00}<i> {FFFFFF}"%2)
#define Usage(%1,%2) SendClientMessage(%1, -1, "{FFFF77}<?> {FFFFFF}"%2)
#define Error(%1,%2) SendClientMessage(%1, -1, "{FF0000}<!> {FFFFFF}"%2)

// OTHER DEFINE
#define function%0(%1) forward %0(%1); public %0(%1)
#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

new SV_LSTREAM:localStream[MAX_PLAYERS] = SV_NULL;
new SV_GSTREAM:radioStream[MAX_FREQUENSI] = SV_NULL;

// SAVE SYSTEM (MYSQL)
#define     MYSQL_HOST      "db.zeynetwork.xyz"
#define     MYSQL_USER      "u108_ken8W5lxT5"
#define     MYSQL_PASS      "PLbbqz@vH0hnYRZ@^mCYp@lj"
#define     MYSQL_DATA      "s108_aer"
