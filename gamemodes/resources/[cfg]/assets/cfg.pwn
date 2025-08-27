//include
#include <a_samp>
#include <memory>
#include <map-zones>
#include <a_mysql>
#include <a_zones>
#include <streamer>
#include <sscanf2> 
#include <gvar>
#include <crashdetect>
#include <YSI_Coding\y_timers>      	
#include <YSI_Server\y_colours\x11def>
#include <YSI_Storage\y_ini>			
#include <EVF2>
#include <easyDialog> 
#include <Pawn.CMD>
#include <FiTimestamp>
#define ENABLE_3D_TRYG_YSI_SUPPORT
#include <nex-ac>                   
#include <nex-ac_id.lang> 
#include <strlib>
#include <sampvoice>
#include <selection>
#include <garageblock>
#include <cb>
#include <textdraw-streamer>
#include <progress2>

// Workshop Dialogs
#define DIALOG_WORKSHOP_MENU 1000
#define DIALOG_WORKSHOP_PAINT 1001
#define DIALOG_WORKSHOP_MODS 1002
#define DIALOG_WORKSHOP_SETTINGS 1003
#define DIALOG_WORKSHOP_EMPLOYEES 1004
#define DIALOG_WORKSHOP_INVENTORY 1005

#include "resources/[standalone]/utils/utils_defines.pwn"
#include "resources/[standalone]/utils/utils_vehiclevars.pwn"
#include "resources/[standalone]/utils/utils_enums.pwn"
#include "resources/[standalone]/utils/utils_variable.pwn"
#include "resources/[standalone]/utils/utils_colours.pwn"
#include "resources/[standalone]/utils/utils_textdraws.pwn"
#include "resources/[standalone]/voucher/voucher_functions.pwn"

#include "resources/[jaden]/BombomCart/bombomcart.pwn"
#include "resources/[standalone]/systems/Pickup.pwn"
#include "resources/[standalone]/systems/JobVehicles.pwn"

#include "resources/[baju]/toys/toys.pwn"
#include "resources/[baju]/toys/toys_helmet.pwn"
#include "resources/[baju]/baju/clothes_functions.pwn"

#include "resources/[jaden]/compas/compass.pwn"
#include "resources/[f-core]/fuel_system/fuel_functions.pwn"
#include "resources/[standalone]/PlayerStuff/player_slot.pwn"
#include "resources/[f-core]/Gym/gym_functions.pwn"

#include "resources/[standalone]/Dynamic/Dynamic_SpeedCam/core.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_SpeedCam/funcs.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_SpeedCam/menu.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_SpeedCam/cmd.pwn"

#include "resources/[standalone]/Dynamic/Dynamic_Button/button_functions.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Actor/ui_dynactor.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Warung/warung_functions.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Pasar/dyn_pasar.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Robbery/robbery_functions.pwn"
#include "resources/[faction]/area/area.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Hunting/hunting_functions.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Ladang/ui_dynkanabis.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Ladang/kanabis_olah.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Object/object_funcs.pwn"

#include "resources/[standalone]/Dynamic/Dynamic_GarasiKota/Header.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_GarasiKota/Function.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_GarasiKota/Commands.pwn"

#include "resources/[standalone]/Dynamic/Dynamic_Atm/ui_atm.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Garbage/dynamic_garbage.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Door/dynamic_doors.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Gate/dynamic_gatev2.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Gudang/gudang_functions.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Label/label_functions.pwn"

#include "resources/[standalone]/Dynamic/Dynamic_IconMap/Header.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_IconMap/Function.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_IconMap/Commands.pwn"

#include "resources/[standalone]/Dynamic/Dynamic_Machine/dynamic_slot.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_ObjectText/objecttext.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Uranium/uranium_funcs.pwn"

#include "resources/[job]/jobs/farmer/petani_functions.pwn"
#include "resources/[inventory]/inventory/inventory_functions.pwn"
#include "resources/[inventory]/inventory/inventory_cmds.pwn"
#include "resources/[inventory]/inventory/inventory_drop.pwn"

#include "resources/[standalone]/voice/radiosystem.pwn"
#include "resources/[standalone]/user-interface/ui_animations.pwn"
#include "resources/[standalone]/user-interface/notifikasi/Header.pwn"
#include "resources/[standalone]/user-interface/notifikasi/Function.pwn"
#include "resources/[standalone]/user-interface/notifikasi/box_func.pwn"
#include "resources/[standalone]/user-interface/ui_shortkeys.pwn"
#include "resources/[standalone]/user-interface/ui_smoking.pwn"

#include "resources/[standalone]/Dynamic/Dynamic_Rusun/rusun_functions.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_House/dyn_house.pwn"

#include "resources/[standalone]/PlayerStuff/PlayerAFK.pwn"
#include "resources/[standalone]/PlayerStuff/IdleAnimation.pwn"
#include "resources/[standalone]/PlayerStuff/NameTag.pwn"
#include "resources/[standalone]/PlayerStuff/player_login.pwn"
#include "resources/[faction]/FractionPlayer/FAMILIES/families_functions.pwn"

#include "resources/[job]/jobs/miner/minerv2_functions.pwn"
#include "resources/[job]/jobs/lumberjack/lumber_functions.pwn"
#include "resources/[job]/jobs/bus/bus_funcs.pwn"
#include "resources/[job]/jobs/chicken factory/butcher_functions.pwn"
#include "resources/[job]/jobs/milker/milker_functions.pwn"
#include "resources/[job]/jobs/oilman/oilman_function.pwn"
#include "resources/[job]/jobs/fisherman/nelayan_funcs.pwn"
#include "resources/[job]/jobs/delivery/deliveryside_functions.pwn"
#include "resources/[job]/jobs/mowingjob/mowerside_functions.pwn"
#include "resources/[job]/jobs/sweeper/sweeper_functions.pwn"
#include "resources/[job]/jobs/forklift/forkliftside_functions.pwn"
#include "resources/[job]/jobs/tailor/tailorv2_functions.pwn"
#include "resources/[job]/jobs/tailor/tailor_forward.pwn"
#include "resources/[job]/jobs/hauling/kargo_func.pwn"
#include "resources/[job]/jobs/RicycleJob/recycler_functions.pwn"
#include "resources/[job]/jobs/trashmaster/trashmaster_functions.pwn"
#include "resources/[job]/jobs/electrican/electric_funcs.pwn"
#include "resources/[job]/jobs/mixer/callback.pwn"

#include "resources/[standalone]/Dynamic/Dynamic_Garbage/rongsokan_functions.pwn"
#include "resources/[standalone]/PlayerStuff/player_gps.pwn"
#include "resources/[phone]/PlayerSmartphone/smartphone_contacts.pwn"
#include "resources/[phone]/PlayerSmartphone/phone_funcs.pwn"

#include "resources/[f-core]/vehiclemod/modshop.pwn"
#include "resources/[f-core]/vehicles/vehicles_functions.pwn"
#include "resources/[f-core]/vehicles/vehicles_cmds.pwn"

#include "resources/[f-core]/weapons/weapons_functions.pwn"
#include "resources/[standalone]/Dynamic/Dynamic_Rental/dyn_rental.pwn"
#include "resources/[faction]/FractionPlayer/stuff_goodside.pwn"
#include "resources/[f-core]/toko-olahraga/business_olahraga.pwn"

#include "resources/[faction]/FractionPlayer/FactionMenu.pwn"
#include "resources/[faction]/FractionPlayer/Pemerintah/pemerintah_functions.pwn"
#include "resources/[faction]/FractionPlayer/Bengkel/bengkel_brankas.pwn"
#include "resources/[faction]/FractionPlayer/Bengkel/bengkel_functions.pwn"
#include "resources/[faction]/FractionPlayer/Bengkel/dynamic_workshop.pwn"
#include "resources/[faction]/FractionPlayer/Pedagang/lounges_brankas.pwn"
#include "resources/[faction]/FractionPlayer/Pedagang/lounges_vars.pwn"
#include "resources/[faction]/FractionPlayer/Pedagang/lounges_functions.pwn"
#include "resources/[faction]/FractionPlayer/EMS/ems_brankas.pwn"
#include "resources/[faction]/FractionPlayer/EMS/ems.pwn"
#include "resources/[faction]/FractionPlayer/Police/sapd_functions.pwn"
#include "resources/[faction]/FractionPlayer/trans/trans_functions.pwn"
#include "resources/[faction]/FractionPlayer/trans/trans_stuffs.pwn"

#include "resources/[f-core]/reports/systems_ask.pwn"
#include "resources/[f-core]/reports/systems_reports.pwn"

#include "resources/[event]/events/admin_events.pwn"
#include "resources/[cmd]/commands/cmds_hooks.pwn"
#include "resources/[standalone]/systems/systems_dialogs.pwn"
#include "resources/[standalone]/systems/systems_spawn.pwn"
#include "resources/[standalone]/systems/systems_functions.pwn"
#include "resources/[standalone]/systems/systems_native.pwn"
#include "resources/[standalone]/systems/systems_character.pwn"
#include "resources/[standalone]/systems/systems_anticheatv2.pwn"

#include "resources/[f-core]/toll/toll_functions.pwn"
#include "resources/[job]/jobs/Disnaker/disnaker_functions.pwn"
#include "resources/[cmd]/commands/management.pwn"
#include "resources/[cmd]/commands/pengurus.pwn"
#include "resources/[cmd]/commands/cmds_faction.pwn"
#include "resources/[cmd]/commands/cmds_player.pwn"
#include "resources/[cmd]/commands/cmds_admin.pwn"
#include "resources/[cmd]/commands/earthquake.pwn"
#include "resources/[cmd]/commands/NoClip.pwn"
#include "resources/[f-core]/carsteal/carsteal_functions.pwn"
#include "resources/[standalone]/PlayerStuff/player_toystd.pwn"
#include "resources/[f-core]/showroom/showroom_functions.pwn"
#include "resources/[standalone]/PlayerStuff/player_actions.pwn"
#include "resources/[standalone]/PlayerStuff/player_asuransi.pwn"
#include "resources/[standalone]/PlayerStuff/player_fishingactivity.pwn"
#include "resources/[f-core]/damages/damagelog_functions.pwn"

#include "resources/[f-core]/tags/core.pwn"
#include "resources/[f-core]/tags/cmd.pwn"
#include "resources/[f-core]/tags/funcs.pwn"
#include "resources/[f-core]/tags/impl.pwn"
#include "resources/[f-core]/PlayerCrafting/crafting_functions.pwn"

#include "resources/[standalone]/streamer/streamer.pwn"
#include "resources/[faction]/invoices/invoices.pwn"
#include "resources/[f-core]/blacklist/blacklist_functions.pwn"
#include "resources/[standalone]/timers/timer_task.pwn"
#include "resources/[standalone]/timers/timer_ptask_jail.pwn"
#include "resources/[standalone]/timers/timer_ptask_update.pwn"
#include "resources/[standalone]/playermarker/playermark.pwn"