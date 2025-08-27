#define FISH_ATTACH_IDX 0

enum E_FISH
{
	// fish
	bool:f_bite, // moment fish catch bait
	bool:f_player, // get player fisher
	Float:f_textsize, // float
	f_baittimer, // get fish to bait
	f_baitsecond, // wait fish catch bait
	f_timerstart, // crate progress
	f_fixedanim, // fix anim
	f_fixanimcount
}

new PlayerText: MancingTdBolo[MAX_PLAYERS][8];
new finfo[MAX_PLAYERS][E_FISH];