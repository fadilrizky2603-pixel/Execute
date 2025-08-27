#define BAR_MIN 272 // Posisi minimum bar
#define BAR_MAX 375	// Posisi maksimum bar
#define BAR_SPEED 7 	// kecepatan bar
#define	MAX_CALLBACK 34
#define LebarTarget 5

new bool:BarDirection[MAX_PLAYERS];   // Arah pergerakan bar (true = maju, false = mundur)
new showBarGames[MAX_PLAYERS];
new Float:BarPosition[MAX_PLAYERS];   // Posisi bar saat ini untuk setiap pemain
new Float:BarMove[MAX_PLAYERS];   // Posisi bar saat ini untuk setiap pemain
new BarTimer[MAX_PLAYERS];      // Timer untuk menggerakkan bar

new Float:targetlokasi[MAX_PLAYERS];
new PlayerText:PlayerTD[MAX_PLAYERS][9];

new LoadingCallback[MAX_PLAYERS][MAX_CALLBACK];


