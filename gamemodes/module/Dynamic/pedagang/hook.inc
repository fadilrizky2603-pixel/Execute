#include <YSI_Coding\y_hooks>

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && pData[playerid][pFaction] == 5 && pData[playerid][pOndutysacf] == true)
    {
        foreach(new pid : Pedagang)
        {
            if(IsPlayerInDynamicArea(playerid, pdgDATA[pid][pdgAmbilarea]))
            {
                if(areaid == pdgDATA[pid][pdgAmbilarea])
                {
                    TombolY(playerid, "Gudang Pedagang");
                }
            }
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    foreach(new pid : Pedagang)
    {
        if(areaid == pdgDATA[pid][pdgAmbilarea])
        {
            HideInfoTombol(playerid);
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && pData[playerid][pFaction] == 5 && pData[playerid][pOndutysacf] == true)
    {
        foreach(new pid : Pedagang)
        {
            if(IsPlayerInRangeOfPoint(playerid, 1.0, pdgDATA[pid][pdgPosX], pdgDATA[pid][pdgPosY], pdgDATA[pid][pdgPosZ]))
            {
                return callcmd::gudangpedagang(playerid, "");
            }
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}