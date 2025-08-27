#include <YSI\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_WALK && IsPlayerSmoking[playerid])
    {
        if(SmokingDelayTime[playerid] <= gettime())
        {
            ApplyAnimationEx(playerid, "GANGS", "smkcig_prtl", 4.5, 0,1,0,1,1,1);
            SetTimerEx("SmokeCigar", 3500, false, "d", playerid);
            SmokingDelayTime[playerid] = gettime() + 4;
        }
    }
    return 1;
}

forward SmokeCigar(playerid);
public SmokeCigar(playerid)
{
    new randrokok = RandomEx(1, 5);
    SetPlayerAttachedObject(playerid, 7, 18677, 2, -0.028, 0.160, -1.640, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);
    CountSmoking[playerid] --;
    AccountData[playerid][pStress] -= randrokok;
    if(CountSmoking[playerid] == 0)
    {
        IsPlayerSmoking[playerid] = false;
        CountSmoking[playerid] = 0;
        SmokingDelayTime[playerid] = 0;

        Info(playerid, "Rokok anda telah habis sebatang.");
    }
    return 1;
}