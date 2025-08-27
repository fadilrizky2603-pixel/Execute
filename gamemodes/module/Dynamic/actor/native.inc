Actor_Save(id)
{
	new dquery[2048];
	format(dquery, sizeof(dquery), "UPDATE actors SET name='%s', skinid='%d', bizid='%d', posx='%f', posy='%f', posz='%f', posa='%f', vuln='%d', interior='%d', world='%d', anim='%d' WHERE id='%d'",
	ActData[id][actName],
	ActData[id][actSkin],
	ActData[id][actBizid],
	ActData[id][actX],
	ActData[id][actY],
	ActData[id][actZ],
	ActData[id][actA],
	ActData[id][actVuln],
	ActData[id][actInt],
	ActData[id][actVW],
	ActData[id][actAnim],
	id);

	return mysql_tquery(g_SQL, dquery);
}

Actor_Refresh(id)
{
	if(id != -1)
	{
		if(IsValidDynamicActor(ActData[id][actObj]))
			DestroyDynamicActor(ActData[id][actObj]);

		if(IsValidDynamic3DTextLabel(ActData[id][actLabel]))
			DestroyDynamic3DTextLabel(ActData[id][actLabel]);

		new string[1024];		
		format(string, sizeof(string), "%s (%d)", ActData[id][actName], id);
		ActData[id][actObj] = CreateDynamicActor(ActData[id][actSkin], ActData[id][actX], ActData[id][actY], ActData[id][actZ], 0.0, ActData[id][actVuln], 100.0, ActData[id][actVW], ActData[id][actInt], -1);
		ActData[id][actLabel] = CreateDynamic3DTextLabel(string, COLOR_YELLOW, ActData[id][actX], ActData[id][actY], ActData[id][actZ]+1.5, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, ActData[id][actVW], ActData[id][actInt]);
		SetDynamicActorInvulnerable(ActData[id][actObj], 1);
		SetDynamicActorFacingAngle(ActData[id][actObj], ActData[id][actA]);

		switch(ActData[id][actAnim])
		{
			case 0:
			{
				//Disable Animations
				ClearDynamicActorAnimations(ActData[id][actObj]);
			}
			case 1:
			{
				//Injured
				ApplyDynamicActorAnimation(ActData[id][actObj], "SWEET", "Sweet_injuredloop", 4.1, 1, 0, 0, 0, 0);
			}
			case 2:
			{
				//Handsup
				ApplyDynamicActorAnimation(ActData[id][actObj], "SHOP", "SHP_Rob_HandsUp", 4.1, 1, 0, 0, 0, 0);
			}
			case 3:
			{
				//sit
				ApplyDynamicActorAnimation(ActData[id][actObj], "BEACH", "ParkSit_M_loop", 4.1, 1, 0, 0, 0, 0);
			}
			case 4:
			{
				//lean
				ApplyDynamicActorAnimation(ActData[id][actObj], "GANGS", "leanIDLE", 4.1, 1, 0, 0, 0, 0);
			}
			case 5:
			{
				//dance
				ApplyDynamicActorAnimation(ActData[id][actObj], "DANCING", "dance_loop", 4.1, 1, 0, 0, 0, 0);
			}
			case 6:
			{
				//dealstance
				ApplyDynamicActorAnimation(ActData[id][actObj], "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0);
			}
			case 7:
			{
				//riotchant
				ApplyDynamicActorAnimation(ActData[id][actObj], "RIOT", "RIOT_CHANT", 4.1, 1, 0, 0, 0, 0);
			}
			case 8:
			{
				//wave
				ApplyDynamicActorAnimation(ActData[id][actObj], "ON_LOOKERS", "wave_loop", 4.1, 1, 0, 0, 0, 0);
			}
			case 9:
			{
				//hide
				ApplyDynamicActorAnimation(ActData[id][actObj], "ped", "cower", 4.1, 1, 0, 0, 0, 0);
			}
			case 10:
			{
				//crossarms
				ApplyDynamicActorAnimation(ActData[id][actObj], "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0);
			}
			case 11:
			{
				//laugh
				ApplyDynamicActorAnimation(ActData[id][actObj], "RAPPING", "Laugh_01", 4.1, 1, 0, 0, 0, 0);
			}
			case 12:
			{
				//talk
				ApplyDynamicActorAnimation(ActData[id][actObj], "PED", "IDLE_CHAT", 4.1, 1, 0, 0, 0, 0);
			}
			case 13:
			{
				//fucku
				ApplyDynamicActorAnimation(ActData[id][actObj], "PED", "fucku", 4.1, 1, 0, 0, 0, 0);
			}
			case 14:
			{
				//tired
				ApplyDynamicActorAnimation(ActData[id][actObj], "PED", "IDLE_tired", 4.1, 1, 0, 0, 0, 0);
			}
			case 15:
			{
				//chairsit
				ApplyDynamicActorAnimation(ActData[id][actObj], "PED", "SEAT_idle", 4.1, 1, 0, 0, 0, 0);
			}
		}
	}
	return 1;
}