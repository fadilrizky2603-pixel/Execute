Vending_Save(id)
{
	new dquery[2048];
	format(dquery, sizeof(dquery), "UPDATE vendingmachine SET owner='%s', price='%d', posx='%f', posy='%f', posz='%f', posrx='%f', posry='%f', posrz='%f', interior='%d', world='%d', money='%d', drinkprice='%d', product='%d', visit='%d' WHERE ID='%d'",
	vmData[id][venOwner],
	vmData[id][venPrice],
	vmData[id][venX],
	vmData[id][venY],
	vmData[id][venZ],
	vmData[id][venRX],
	vmData[id][venRY],
	vmData[id][venRZ],
	vmData[id][venInt],
	vmData[id][venWorld],
	vmData[id][venMoney],
	vmData[id][venDrinkPrice],
	vmData[id][venProduct],
	vmData[id][venVisit],
	id);

	return mysql_tquery(g_SQL, dquery);
}


Vending_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamicObject(vmData[id][venObject]))
			DestroyDynamicObject(vmData[id][venObject]);

		if(IsValidDynamic3DTextLabel(vmData[id][venLabel]))
			DestroyDynamic3DTextLabel(vmData[id][venLabel]);

		new status[128], string[128];
		if(vmData[id][venProduct] == 0)
		{
			status = "{FF0000}OUT OF STOCK{FFFFFF}";
		}
		else
		{	
			format(string, sizeof(string), "{00FF00}%d{FFFFFF}", vmData[id][venProduct]);
			status = string;
		}
		new tstr[1024];
        if(strcmp(vmData[id][venOwner], "-"))
        {
			format(tstr, sizeof(tstr), "[VENDING ID: %d]\n{ffffff}Vending Stock: %s\n{ffffff}Location: "GREEN_LIGHT"%s\n{ffffff}Drink Price: {00ff00}%s\n{ffffff}Owned by %s\n/buydrink - for buy a drink", id, status, GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), FormatMoney(vmData[id][venDrinkPrice]), vmData[id][venOwner]);
            vmData[id][venObject] = CreateDynamicObject(1209, vmData[id][venX], vmData[id][venY], vmData[id][venZ], vmData[id][venRX], vmData[id][venRY], vmData[id][venRZ], vmData[id][venWorld], vmData[id][venInt], -1, 90.0, 300.0);
            vmData[id][venLabel] = CreateDynamic3DTextLabel(tstr, COLOR_YELLOW, vmData[id][venX], vmData[id][venY], vmData[id][venZ]+1.5, 5.0);
        }
		else
		{
			format(tstr, sizeof(tstr), "[VENDING ID: %d]\n{00FF00}This Vending for sell\n{FFFFFF}Location: {00FF00}%s\n{FFFFFF}Price: {00FF00}%s\n"WHITE_E"Type /buy to purchase", id, GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), FormatMoney(vmData[id][venPrice]));
        	vmData[id][venObject] = CreateDynamicObject(1209, vmData[id][venX], vmData[id][venY], vmData[id][venZ], vmData[id][venRX], vmData[id][venRY], vmData[id][venRZ], vmData[id][venWorld], vmData[id][venInt], -1, 90.0, 300.0);
            vmData[id][venLabel] = CreateDynamic3DTextLabel(tstr, COLOR_YELLOW, vmData[id][venX], vmData[id][venY], vmData[id][venZ]+1.5, 5.0);
		}
	}		
	return 1;
}


VendingLabel_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamic3DTextLabel(vmData[id][venLabel]))
			DestroyDynamic3DTextLabel(vmData[id][venLabel]);

		new status[128], string[128];
		if(vmData[id][venProduct] == 0)
		{
			status = "{FF0000}OUT OF STOCK{FFFFFF}";
		}
		else
		{	
			format(string, sizeof(string), "{00FF00}%d{FFFFFF}", vmData[id][venProduct]);
			status = string;
		}
		new tstr[254];
        if(strcmp(vmData[id][venOwner], "-"))
        {
			format(tstr, sizeof(tstr), "[VENDING ID: %d]\n{ffffff}Vending Stock: %s\n{ffffff}Location: "GREEN_LIGHT"%s\n{ffffff}Drink Price: {00ff00}%s\n{ffffff}Owned by %s\n/buydrink - for buy a drink", id, status, GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), FormatMoney(vmData[id][venDrinkPrice]), vmData[id][venOwner]);
            vmData[id][venLabel] = CreateDynamic3DTextLabel(tstr, COLOR_YELLOW, vmData[id][venX], vmData[id][venY], vmData[id][venZ]+1.5, 5.0);
        }
		else
		{
			format(tstr, sizeof(tstr), "[VENDING ID: %d]\n{00FF00}This Vending for sell\n{FFFFFF}Location: {00FF00}%s\n{FFFFFF}Price: {00FF00}%s\n"WHITE_E"Type /buy to purchase", id, GetLocation(vmData[id][venX], vmData[id][venY], vmData[id][venZ]), FormatMoney(vmData[id][venPrice]));
            vmData[id][venLabel] = CreateDynamic3DTextLabel(tstr, COLOR_YELLOW, vmData[id][venX], vmData[id][venY], vmData[id][venZ]+1.5, 5.0);
		}
	}		
	return 1;
}


Player_OwnsVending(playerid, id)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(id == -1) return 0;
	if(!strcmp(vmData[id][venOwner], pData[playerid][pName], true)) return 1;
	return 0;
}

Player_VendingCount(playerid)
{
	#if LIMIT_PER_PLAYER != 0
    new count;
	foreach(new i : Vending)
	{
		if(Player_OwnsVending(playerid, i)) count++;
	}

	return count;
	#else
	return 0;
	#endif
}

Vending_Reset(id)
{
	format(vmData[id][venOwner], MAX_PLAYER_NAME, "-");
	vmData[id][venProduct] = 0;
    vmData[id][venMoney] = 0;
	vmData[id][venDrinkPrice] = 0;
	Vending_Refresh(id);
}

GetRestockVending()
{
	new tmpcount;
	foreach(new id : Vending)
	{
		if(strcmp(vmData[id][venOwner], "-"))
		{
	    	if(vmData[id][venProduct] < 100)
	    	{
     			tmpcount++;
	    	}
		}
	}
	return tmpcount;
}

ReturnRestockVendingID(slot)
{
	new tmpcount;
	if(slot < 1 && slot > MAX_VENDING) return -1;
	foreach(new id : Vending)
	{
		if(strcmp(vmData[id][venOwner], "-"))
		{
		    if(vmData[id][venProduct] < 100)
		    {
	     		tmpcount++;
	       		if(tmpcount == slot)
	       		{
	        		return id;
	  			}
	  		}
		}
	}
	return -1;
}

Vending_BeingEdited(venid)
{
	if(!Iter_Contains(Vending, venid)) return 0;
	foreach(new i : Player) if(pData[i][pEditing] == venid) return 1;
	return 0;
}
