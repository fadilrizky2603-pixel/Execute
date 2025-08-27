/*
																						  */																		  																			  
#define CGEN_MEMORY 50000

#define SERVER_TEXTDRAW_COLOR 293063423 //mengatur thema warna server

#define TEXT_GAMEMODE	"v1.0 Relased"
#define TEXT_WEBURL		"discord.gg/kampungindo"
#define TEXT_LANGUAGE	"English/Indonesia"
#define SERVER_BOT      "LP:RP"
#define SERVER_NAME     "Kampung Indo Roleplay | #KamiSayangIndo"

#include <a_samp>
#undef MAX_PLAYERS
#define MAX_PLAYERS	50
#include <a_mysql>
#include <a_zones>

#include <YSI_Coding/y_timers>
#include <YSI_Coding/y_va>
#include <YSI_Coding/y_inline>
#include <YSI_Server/y_colours/y_colours_x11def>

#include <Pawn.CMD>
#include <strlib>
#include <eSelection>
#include <TimestampToDate>
#include <sscanf2>
#include <streamer>
#include <EVF2>
#include <garageblock>
#include <yom_buttons>

#include <LiveCam>

#include <samp_bcrypt>
#include <sampvoice>
#include <textdraw-streamer>
#include <rAntiBuggers>
#include <easyDialog>
#include <discord-connector>
#include <WazeGPS>

//-----[ Modular ]-----
#include "module/enum.inc"
#include "module/mysqlconnect.inc"
#include "module/define.inc"
#include "module/maxdynamic.inc"
#include "module/variabel.inc"

#include "module/Textdraw/header-player.inc"
#include "module/Textdraw/textdraw-player.inc"
#include "module/Textdraw/header-global.inc"
#include "module/Textdraw/textdraw-global.inc"

#include "module/Userinterface/ui_info_tombol.inc"
#include "module/Userinterface/ui_infojobs.inc"
#include "module/Userinterface/ui_notif.inc"
#include "module/Userinterface/ui_loadingbar.inc"
#include "module/Userinterface/ui_atm.inc"
#include "module/Userinterface/ui_box.inc"
#include "module/Userinterface/ui_minigames.inc"
#include "module/Userinterface/ui_menuspawn.inc"
#include "module/Userinterface/ui_anncoument.inc"
#include "module/Userinterface/ui_warning.inc"
#include "module/Userinterface/ui_fishing.inc"
#include "module/Userinterface/ui_phone.inc"
#include "module/Userinterface/ui_garkot.inc"

#include "module/Servers/zone.inc"
#include "module/Servers/map.inc"
#include "module/Servers/gangzone.inc"

#include "module/Data/anim.inc"
#include "module/Data/weaponatt.inc"
#include "module/Data/playertoys.inc"
#include "module/Data/helmet.inc"
#include "module/Data/server.inc"
#include "module/Data/pricejob.inc"
#include "module/Data/voucher.inc"
#include "module/Data/salary.inc"

#include "module/Dynamic/door.inc"
#include "module/Dynamic/family.inc"
#include "module/Dynamic/house.inc"
#include "module/Dynamic/bisnis.inc"
#include "module/Dynamic/robmarket.inc"
#include "module/Dynamic/dealer.inc"
#include "module/Dynamic/rental.inc"
#include "module/Dynamic/locker.inc"
#include "module/Dynamic/atm.inc"
#include "module/Dynamic/gate.inc"
#include "module/Dynamic/actor.inc"
#include "module/Dynamic/pedagang.inc"
#include "module/Dynamic/mapping.inc"
#include "module/Dynamic/texture.inc"
#include "module/Dynamic/vending.inc"
#include "module/Dynamic/singal.inc"
#include "module/Dynamic/npcfam.inc"
#include "module/Dynamic/factionveh.inc"
#include "module/Dynamic/spraytag.inc"

#include "module/Vehicle/vehicle.inc"
#include "module/Vehicle/fuel.inc"
#include "module/Vehicle/modshop.inc"
#include "module/Vehicle/vstorage.inc"

#include "module/Dynamic/workshop.inc"
#include "module/Dynamic/speedcam.inc"
#include "module/Dynamic/garkot.inc"

#include "module/Futures/notes.inc"
#include "module/Userinterface/ui_inventory.inc"

#include "module/Faction/futures/911call.inc"
#include "module/Faction/futures/baricade.inc"
#include "module/Faction/futures/pajak.inc"
#include "module/Faction/futures/factioncall.inc"
#include "module/Faction/futures/mdc.inc"
#include "module/Faction/futures/sirine.inc"

#include "module/Family/futures/carsteal.inc"
#include "module/Family/futures/blackmarket.inc"
#include "module/Family/futures/proseskanabis.inc"
#include "module/Family/futures/robatm.inc"
#include "module/Family/futures/robbank.inc"

#include "module/Futures/waypoint.inc"
#include "module/Futures/streamer.inc"
#include "module/Futures/event.inc"
#include "module/Futures/drivelic.inc"
#include "module/Futures/accent.inc"
#include "module/Futures/bills.inc"
#include "module/Futures/phonebook.inc"
#include "module/Futures/paytoll.inc"
#include "module/Futures/boombox.inc"
#include "module/Futures/payphone.inc"
#include "module/Futures/damagelog.inc"
#include "module/Futures/adslog.inc"
#include "module/Futures/acheat.inc"
#include "module/Futures/Player_Cut.inc"
#include "module/Futures/ucp.inc"
#include "module/Futures/storage.inc"
#include "module/Futures/pasar.inc"
#include "module/Futures/playermarker.inc"
#include "module/Futures/emotemenu.inc"
#include "module/Futures/suit.inc"
#include "module/Futures/roll.inc"

#include "module/native.inc"

#include "module/Showing/death/show.inc"
#include "module/Showing/death/hide.inc"
#include "module/Showing/hunger/show.inc"
#include "module/Showing/hunger/hide.inc"
#include "module/Showing/logo/show.inc"
#include "module/Showing/logo/hide.inc"
#include "module/Showing/radial/show.inc"
#include "module/Showing/radial/hide.inc"
#include "module/Showing/speed/show.inc"
#include "module/Showing/speed/hide.inc"

#include "module/Jobs/bus.inc"

#include "module/Jobs/lumber.inc"
#include "module/Jobs/miner.inc"
#include "module/Jobs/production.inc"
#include "module/Jobs/trucker.inc"
#include "module/Jobs/fish.inc"
#include "module/Jobs/farmer.inc"
#include "module/Jobs/hauling.inc"
#include "module/Jobs/smuggler.inc"
#include "module/Jobs/trashmaster.inc"
#include "module/Jobs/reflenish.inc"
#include "module/Jobs/tukangayam.inc"
#include "module/Jobs/weapdealer.inc"
#include "module/Jobs/susu.inc"
#include "module/Jobs/sweeper.inc"
#include "module/Jobs/penjahit.inc"
//#include "module/Jobs/mixer.inc"

#include "module/Jobs/jualhasil.inc"

#include "module/Dynamic/privatefram.inc"

#include "module/Faction/sapd.inc"
#include "module/Faction/samd.inc"
#include "module/Faction/sags.inc"
#include "module/Faction/mech.inc"
#include "module/Faction/taxi.inc"

#include "module/Cmd/admin.inc"
#include "module/Cmd/Faction.inc"
#include "module/Cmd/Player.inc"

#include "module/Discord/discord.inc"
#include "module/Discord/advertisement.inc"
#include "module/Discord/savepos.inc"
#include "module/Discord/pay.inc"
#include "module/Discord/givepv.inc"

#include "module/Futures/gps.inc"

#include "module/Faction/sacf.inc"

#include "module/Data/report.inc"

#include "module/Data/ask.inc"

#include "module/Faction/futures/tazer.inc"
#include "module/Faction/futures/spiketrap.inc"
#include "module/Faction/futures/livestream.inc"

#include "module/dialog.inc"
#include "module/function.inc"
#include "module/timer.inc"

#include "module/Textdraw/onclick-global.inc"
#include "module/Textdraw/onclick-player.inc"

main() {
}

#include "module/callbacks.inc"
