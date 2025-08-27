CreateCraftingPoint()
{
    //JOBS
    new strings[500];
    format(strings, sizeof(strings), "{FFFF00}[Y] {FFFFFF}untuk membuat Senjata");
    CreateDynamic3DTextLabel(strings, COLOR_YELLOW, 2650.8174, -2407.7600, 3001.0859, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
}

#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.5, 2650.8174, -2407.7600, 3001.0859))
        {
        	return callcmd::crafting(playerid, "");
        }
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

/*CMD:crafting(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.5, 2650.8174,-2407.7600, 3001.0859)) return ErrorMsg(playerid, "Anda sedang tidak berada di BlackMarket");
	if(pData[playerid][pLevel] < 5) return ErrorMsg(playerid, "Level anda tidak mencukupi (~y~5~w~)");
	if(pData[playerid][pFamily] == -1) return ErrorMsg(playerid, "Anda bukan bagian dari Family");
	if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan crafting");
	
	new Dstring[512];
	format(Dstring, sizeof(Dstring), "Weapon\tMats\tComps\n\
	{ffffff}%sAK-47(ammo 200)\t700\t300\n");
	format(Dstring, sizeof(Dstring), "{ffffff}%sDesert Eagle\t300\t65\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sMicro UZI\t500\t250\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sShotgun\t200\t70\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sSilenced 9mm\t100\t45\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sSniper Rifle\t1000\t1000\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sPatched Bomb\t355\t90\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sClip Pistol\t55\t20\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sClip Rifle\t60\t25\n", Dstring);
	ShowPlayerDialog(playerid, DIALOG_BLACKMARKET, DIALOG_STYLE_TABLIST_HEADERS, "Craffting", Dstring, "Create", "Cancel");
	return 1;
}*/

/*CMD:crafting(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.5, 2650.8174,-2407.7600, 3001.0859)) return ErrorMsg(playerid, "Anda sedang tidak berada di BlackMarket");
	if(pData[playerid][pLevel] < 3) return ErrorMsg(playerid, "Level anda tidak mencukupi (~y~5~w~)");
	if(pData[playerid][pFamily] == -1) return ErrorMsg(playerid, "Anda bukan bagian dari Family");
	if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan crafting");
	
	new Dstring[512];
	format(Dstring, sizeof(Dstring), "Weapon\tMaterial\tTembaga\tBesi\n\
	{ffffff}%sAK-47\t700\t300\t300\n");
	format(Dstring, sizeof(Dstring), "{ffffff}%sDesert Eagle\t300\t80\t100\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sMicro UZI\t500\t250\t250\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sShotgun\t200\t60\t80\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sSilenced 9mm\t100\t45\t50\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sSniper Rifle\t1000\t800\t800\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sPatched Bomb\t300\t100\t120\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sClip Pistol\t50\t20\t40\n", Dstring);
	format(Dstring, sizeof(Dstring), "{ffffff}%sClip Rifle\t70\t40\t60\n", Dstring);
	ShowPlayerDialog(playerid, DIALOG_BLACKMARKET, DIALOG_STYLE_TABLIST_HEADERS, "Craffting", Dstring, "Create", "Cancel");
	return 1;
}*/

CMD:crafting(playerid, const params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.5, 2650.8174,-2407.7600, 3001.0859)) return 1;
	if(pData[playerid][pLevel] < 3) return InfoTD_MSG(playerid, 4000, "Level anda tidak mencukupi (~y~5~w~)");
	if(pData[playerid][pFamily] == -1) return ErrorMsg(playerid, "Anda bukan bagian dari Family");
	if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan crafting");

	ShowPlayerDialog(playerid, DIALOG_BLACKMARKET, DIALOG_STYLE_LIST, "Crafting", "Colt 45\nDeasert Eagle\nShotgun\nMicro UZI\nAK-47\nSniper Rifle\nKevlar (Armor)\nPatched Bom", "Crafting", "Cancel");
	return 1;
}


function crafting(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(pData[playerid][pActivityTime] >= 100)
	{
		TogglePlayerControllable(playerid, 1);
		clearAnimations(playerid);
		pData[playerid][pLoading] = false;
	}
	else if(pData[playerid][pActivityTime] < 100)
	{
		pData[playerid][pActivityTime] += 10;
		ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
	}
	return 1;
}

function CreateGun(playerid, gunid, ammo)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(gunid == 0 || ammo == 0) return 0;
	{		
		GivePlayerWeaponEx(playerid, gunid, ammo);
		SuccesMsg(playerid, "Anda berhasil membuat senjata");
		TogglePlayerControllable(playerid, 1);
		clearAnimations(playerid);
		pData[playerid][pLoading] = false;
	}
	return 1;
}

function CreateBomb(playerid)
{
	SuccesMsg(playerid, "Anda berhasil membuat Bomb");
	TogglePlayerControllable(playerid, 1);
	clearAnimations(playerid);
	Inventory_Add(playerid, "Bomb", 363, 1);
	pData[playerid][pLoading] = false;
	return 1;
}

function CreateKevlar(playerid)
{
	SuccesMsg(playerid, "Anda berhasil membuat Kevlar");
	TogglePlayerControllable(playerid, 1);
	clearAnimations(playerid);
	Inventory_Add(playerid, "Kevlar", 1242, 1);
	pData[playerid][pLoading] = false;
	return 1;
}

function CreateClipPistol(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	{
		Info(playerid, "Anda telah berhasil membuat clip pistol.");
		TogglePlayerControllable(playerid, 1);
		SuccesMsg(playerid, "Clip Pistol Created!");
		clearAnimations(playerid);
		Inventory_Add(playerid, "Clip Pistol", 19995, 1);
		pData[playerid][pLoading] = false;
	}
	return 1;
}

function CreateClipRifle(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	{
		Info(playerid, "Anda telah berhasil membuat clip Rifle.");
		TogglePlayerControllable(playerid, 1);
		SuccesMsg(playerid, "Clip Rifle Created!");
		clearAnimations(playerid);
		Inventory_Add(playerid, "Clip Rifle", 19995, 1);
		pData[playerid][pLoading] = false;
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == DIALOG_BLACKMARKET)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					ShowPlayerDialog(playerid, DIALOG_CRAFTCOLT45, DIALOG_STYLE_MSGBOX, "Crafting | Colt-45", "{FFFFFF}Bahan-Bahan:\n\nMaterial: 300\nComponent: 150", "Crafting", "Cancel");
				}
				case 1:
				{
					ShowPlayerDialog(playerid, DIALOG_CRAFTDE, DIALOG_STYLE_MSGBOX, "Crafting | Deasert Eagle", "{FFFFFF}Bahan-Bahan:\n\nMaterial: 500\nComponent: 250", "Crafting", "Cancel");
				}
				case 2:
				{
					ShowPlayerDialog(playerid, DIALOG_CRAFTSHOTGUN, DIALOG_STYLE_MSGBOX, "Crafting | Shotgun", "{FFFFFF}Bahan-Bahan:\n\nMaterial: 400\nComponent: 200", "Crafting", "Cancel");
				}
				case 3:
				{
					ShowPlayerDialog(playerid, DIALOG_CRAFTUZI, DIALOG_STYLE_MSGBOX, "Crafting | Micro UZI", "{FFFFFF}Bahan-Bahan:\n\nMaterial: 400\nComponent: 250", "Crafting", "Cancel");
				}
				case 4:
				{
					ShowPlayerDialog(playerid, DIALOG_CRAFTAK47, DIALOG_STYLE_MSGBOX, "Crafting | AK-47", "{FFFFFF}Bahan-Bahan:\n\nMaterial: 700\nComponent: 500", "Crafting", "Cancel");
				}
				case 5:
				{
					ShowPlayerDialog(playerid, DIALOG_CRAFTSNIPER, DIALOG_STYLE_MSGBOX, "Crafting | Sniper Rifle", "{FFFFFF}Bahan-Bahan:\n\nMaterial: 800\nComponent: 600", "Crafting", "Cancel");
				}
				case 6:
				{
					ShowPlayerDialog(playerid, DIALOG_CRAFTKEVLAR, DIALOG_STYLE_MSGBOX, "Crafting | Kevlar", "{FFFFFF}Bahan-Bahan:\n\nMaterial: 250\nComponent: 100\nPakaian: 100", "Crafting", "Cancel");
				}
				case 7:
				{
					ShowPlayerDialog(playerid, DIALOG_CRAFTBOMB, DIALOG_STYLE_MSGBOX, "Crafting | Patched Bomb", "{FFFFFF}Bahan-Bahan:\n\nMaterial: 200\nComponent: 200", "Crafting", "Cancel");
				}
			}
		}
	}
	if(dialogid == DIALOG_CRAFTKEVLAR)
	{
		if(response)
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan Crafting");
			if(Inventory_Count(playerid, "Material") < 250)
				return ErrorMsg(playerid, "Material anda tidak mencukupi (250)");
			if(Inventory_Count(playerid, "Component") < 100)
				return ErrorMsg(playerid, "Component anda tidak mencukupi (100)");
			if(Inventory_Count(playerid, "Pakaian") < 100)
				return ErrorMsg(playerid, "Component anda tidak mencukupi (100)");


			Inventory_Remove(playerid, "Material", 250);
			Inventory_Remove(playerid, "Component", 100);
			Inventory_Remove(playerid, "Pakaian", 100);
			pData[playerid][pLoading] = true;
			TogglePlayerControllable(playerid, 0);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
			ShowProgressbar(playerid, "Crafting...", 15);
			SetTimerEx("CreateKevlar", 15000, false, "i", playerid);	
		}
	}
	if(dialogid == DIALOG_CRAFTBOMB)
	{
		if(response)
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan Crafting");
			
			if(Inventory_Count(playerid, "Material") < 200)
				return ErrorMsg(playerid, "Material anda tidak mencukupi (200)");
			if(Inventory_Count(playerid, "Component") < 200)
				return ErrorMsg(playerid, "Component anda tidak mencukupi (200)");

			Inventory_Remove(playerid, "Material", 200);
			Inventory_Remove(playerid, "Component", 200);
			pData[playerid][pLoading] = true;
			TogglePlayerControllable(playerid, 0);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
			ShowProgressbar(playerid, "Crafting...", 15);
			SetTimerEx("CreateBomb", 15000, false, "i", playerid);		
		}
	}
	if(dialogid == DIALOG_CRAFTSNIPER)
	{
		if(response)
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan Crafting");
			
			if(Inventory_Count(playerid, "Material") < 800)
				return ErrorMsg(playerid, "Material anda tidak mencukupi (800)");
			if(Inventory_Count(playerid, "Component") < 600)
				return ErrorMsg(playerid, "Component anda tidak mencukupi (600)");

			Inventory_Remove(playerid, "Material", 800);
			Inventory_Remove(playerid, "Component", 600);
			pData[playerid][pLoading] = true;
			TogglePlayerControllable(playerid, 0);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
			ShowProgressbar(playerid, "Crafting...", 15);
			pData[playerid][pCraftingtime] = SetTimerEx("CreateGun", 15000, false, "idd", playerid, WEAPON_SNIPER, 50);			
		}
	}
	if(dialogid == DIALOG_CRAFTAK47)
	{
		if(response)
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan Crafting");
			
			if(Inventory_Count(playerid, "Material") < 700)
				return ErrorMsg(playerid, "Material anda tidak mencukupi (700)");
			if(Inventory_Count(playerid, "Component") < 500)
				return ErrorMsg(playerid, "Component anda tidak mencukupi (500)");

			Inventory_Remove(playerid, "Material", 700);
			Inventory_Remove(playerid, "Component", 500);
			pData[playerid][pLoading] = true;
			TogglePlayerControllable(playerid, 0);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
			ShowProgressbar(playerid, "Crafting...", 15);
			pData[playerid][pCraftingtime] = SetTimerEx("CreateGun", 15000, false, "idd", playerid, WEAPON_AK47, 150);			
		}
	}
	if(dialogid == DIALOG_CRAFTUZI)
	{
		if(response)
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan Crafting");
			
			if(Inventory_Count(playerid, "Material") < 400)
				return ErrorMsg(playerid, "Material anda tidak mencukupi (400)");
			if(Inventory_Count(playerid, "Component") < 250)
				return ErrorMsg(playerid, "Component anda tidak mencukupi (250)");

			Inventory_Remove(playerid, "Material", 400);
			Inventory_Remove(playerid, "Component", 250);
			pData[playerid][pLoading] = true;
			TogglePlayerControllable(playerid, 0);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
			ShowProgressbar(playerid, "Crafting...", 15);
			pData[playerid][pCraftingtime] = SetTimerEx("CreateGun", 15000, false, "idd", playerid, WEAPON_UZI, 200);			
		}
	}
	if(dialogid == DIALOG_CRAFTSHOTGUN)
	{
		if(response)
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan Crafting");
			
			if(Inventory_Count(playerid, "Material") < 400)
				return ErrorMsg(playerid, "Material anda tidak mencukupi (400)");
			if(Inventory_Count(playerid, "Component") < 200)
				return ErrorMsg(playerid, "Component anda tidak mencukupi (200)");

			Inventory_Remove(playerid, "Material", 400);
			Inventory_Remove(playerid, "Component", 200);
			pData[playerid][pLoading] = true;
			TogglePlayerControllable(playerid, 0);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
			ShowProgressbar(playerid, "Crafting...", 15);
			pData[playerid][pCraftingtime] = SetTimerEx("CreateGun", 15000, false, "idd", playerid, WEAPON_SHOTGUN, 100);			
		}
	}
	if(dialogid == DIALOG_CRAFTDE)
	{
		if(response)
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan Crafting");
			
			if(Inventory_Count(playerid, "Material") < 500)
				return ErrorMsg(playerid, "Material anda tidak mencukupi (500)");
			if(Inventory_Count(playerid, "Component") < 250)
				return ErrorMsg(playerid, "Component anda tidak mencukupi (250)");



			Inventory_Remove(playerid, "Material", 500);
			Inventory_Remove(playerid, "Component", 250);
			pData[playerid][pLoading] = true;
			TogglePlayerControllable(playerid, 0);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
			ShowProgressbar(playerid, "Crafting...", 15);
			pData[playerid][pCraftingtime] = SetTimerEx("CreateGun", 15000, false, "idd", playerid, WEAPON_DEAGLE, 100);			
		}
	}
	if(dialogid == DIALOG_CRAFTCOLT45)
	{
		if(response)
		{
			if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity Progress, silahkan tunggu");
			if(pData[playerid][pLoading] == true) return SyntaxMsg(playerid, "Anda sedang melakukan Crafting");
			
			if(Inventory_Count(playerid, "Material") < 300)
				return ErrorMsg(playerid, "Material anda tidak mencukupi (300)");
			if(Inventory_Count(playerid, "Component") < 150)
				return ErrorMsg(playerid, "Component anda tidak mencukupi (150)");

			Inventory_Remove(playerid, "Material", 300);
			Inventory_Remove(playerid, "Component", 150);
			pData[playerid][pLoading] = true;
			TogglePlayerControllable(playerid, 0);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 0, 0, 1, 0, 1);
			ShowProgressbar(playerid, "Crafting...", 15);
			pData[playerid][pCraftingtime] = SetTimerEx("CreateGun", 15000, false, "idd", playerid, WEAPON_COLT45, 150);			
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}