
new
	eventJoin[MAX_PLAYERS] = {0, ...},
	eventTeams[MAX_PLAYERS] = {0, ...},
	eventWaitingSpawn[MAX_PLAYERS] = {0, ...},
	eventCheckpoint[MAX_PLAYERS] = {0, ...},
	Text:eventTextdraws[8],
	eventMessageText[4][128],
  	eventScore_DM[MAX_PLAYERS] = {0, ...}
;

#include "resources/[event]/events/enumerations.pwn"
#include "resources/[event]/events/function.pwn"
#include "resources/[event]/events/callback.pwn"
#include "resources/[event]/events/command.pwn"
#include "resources/[event]/events/dialog.pwn"