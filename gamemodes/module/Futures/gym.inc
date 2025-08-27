#include <YSI_Coding\y_hooks>

#define Gym:: gym_
#define Buff:: buff_
#define MAX_BUFF_SLOT 5

enum Gym::DataStuff {
    STREAMER_TAG_AREA:Gym::MenuGym,
    STREAMER_TAG_AREA:Gym::Yoga[2],
    STREAMER_TAG_AREA:Gym::Barbel,
    STREAMER_TAG_AREA:Gym::BarbelPrison[2]
}
new GymData[Gym::DataStuff];

enum Gym::PlayerStuff {
    bool:Gym::Barbel,
    Float:Gym::Persen
}

enum Buff::param {
    bool:Buff::isActive,
    Buff::type,
    Buff::duration,
    Buff::value
}

enum Buff::buff_type_enum {
    Buff::type_none,
    Buff::type_food,
    Buff::type_thirst,
    Buff::type_stress,
    Buff::type_stamina
}

new GymPlayerData[MAX_PLAYERS][Gym::PlayerStuff];

new PlayerText: GUI_GYM[MAX_PLAYERS][5];

hook OnGameModeInit() {
    CreateDynamic3DTextLabel("Tekan "COLOR_GOLD"Y"WHITE" untuk memulai Yoga", -1, 659.9156, -1869.5369, 5.5537, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
    //CreateDynamic3DTextLabel("Tekan "COLOR_DV20K"Y"WHITE" untuk memulai angkat Barbel", -1, 654.2678, -1869.5612, 5.5537, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
    CreateDynamic3DTextLabel("Tekan "COLOR_GOLD"Y"WHITE" untuk memulai angkat Barbel", -1, 651.7175, -1864.0197, 5.5537, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
    //CreateDynamic3DTextLabel("Tekan "COLOR_DV20K"Y"WHITE" untuk memulai angkat Barbel", -1, 324.2272,1937.5671,17.6706, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
    //CreateDynamic3DTextLabel("Tekan "COLOR_DV20K"Y"WHITE" untuk memulai angkat Barbel", -1, 323.0472,1951.5145,17.6706, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);

    GymData[Gym::MenuGym] = CreateDynamicSphere(670.761474, -1861.124511, 5.46094, 1.0);
    GymData[Gym::Yoga][0] = CreateDynamicSphere(659.9156, -1869.5369, 5.5537, 2.0);
    GymData[Gym::Yoga][1] = CreateDynamicSphere(654.2678, -1869.5612, 5.5537, 2.0);
    GymData[Gym::Barbel] = CreateDynamicSphere(651.7175, -1864.0197, 5.5537, 1.5);
    GymData[Gym::BarbelPrison][0] = CreateDynamicSphere(324.2272,1937.5671,17.6706, 1.5);
    GymData[Gym::BarbelPrison][1] = CreateDynamicSphere(323.0472,1951.5145,17.6706, 1.5);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {
    GUI_GYM[playerid][0] = CreatePlayerTextDraw(playerid, 270.000, -51.000, "New textdraw");
    PlayerTextDrawLetterSize(playerid, GUI_GYM[playerid][0], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, GUI_GYM[playerid][0], 1);
    PlayerTextDrawColor(playerid, GUI_GYM[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, GUI_GYM[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, GUI_GYM[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, GUI_GYM[playerid][0], 150);
    PlayerTextDrawFont(playerid, GUI_GYM[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, GUI_GYM[playerid][0], 1);

    GUI_GYM[playerid][1] = CreatePlayerTextDraw(playerid, 347.000, 181.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GUI_GYM[playerid][1], 22.000, 172.000);
    PlayerTextDrawAlignment(playerid, GUI_GYM[playerid][1], 1);
    PlayerTextDrawColor(playerid, GUI_GYM[playerid][1], 153);
    PlayerTextDrawSetShadow(playerid, GUI_GYM[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, GUI_GYM[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, GUI_GYM[playerid][1], 255);
    PlayerTextDrawFont(playerid, GUI_GYM[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, GUI_GYM[playerid][1], 1);

    GUI_GYM[playerid][2] = CreatePlayerTextDraw(playerid, 350.000, 350.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GUI_GYM[playerid][2], 17.000, -165.000);
    PlayerTextDrawAlignment(playerid, GUI_GYM[playerid][2], 1);
    PlayerTextDrawColor(playerid, GUI_GYM[playerid][2], -1306385665);
    PlayerTextDrawSetShadow(playerid, GUI_GYM[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, GUI_GYM[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, GUI_GYM[playerid][2], 255);
    PlayerTextDrawFont(playerid, GUI_GYM[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, GUI_GYM[playerid][2], 1);

    GUI_GYM[playerid][3] = CreatePlayerTextDraw(playerid, 372.000, 312.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, GUI_GYM[playerid][3], 41.000, 48.000);
    PlayerTextDrawAlignment(playerid, GUI_GYM[playerid][3], 1);
    PlayerTextDrawColor(playerid, GUI_GYM[playerid][3], 153);
    PlayerTextDrawSetShadow(playerid, GUI_GYM[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, GUI_GYM[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, GUI_GYM[playerid][3], 255);
    PlayerTextDrawFont(playerid, GUI_GYM[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, GUI_GYM[playerid][3], 1);

    GUI_GYM[playerid][4] = CreatePlayerTextDraw(playerid, 374.000, 315.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, GUI_GYM[playerid][4], 37.000, 42.000);
    PlayerTextDrawAlignment(playerid, GUI_GYM[playerid][4], 1);
    PlayerTextDrawColor(playerid, GUI_GYM[playerid][4], -5963521);
    PlayerTextDrawSetShadow(playerid, GUI_GYM[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, GUI_GYM[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, GUI_GYM[playerid][4], 255);
    PlayerTextDrawFont(playerid, GUI_GYM[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, GUI_GYM[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, GUI_GYM[playerid][4], 1);
    return Y_HOOKS_CONTINUE_RETURN_1;
}
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if(newkeys == KEY_YES) {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 673.0744,-1860.4080,5.4609))
        {
            new str[250];
            if(!PlayerData[playerid][pPriority]) {
                strcat(str, ""WHITE"Gym Membership\t"COLOR_DV20K"$10,000 / week\n");
                //strcat(str, ""GREY"Gym Suppliements\t - \n");
            } else {
                strcat(str, ""WHITE"Gym Membership\t"COLOR_DV20K"Free / week\n");
                //strcat(str, ""GREY"Gym Suppliements\t - \n");
            }
            Dialog_Show(playerid, DialogGymMenu, DIALOG_STYLE_TABLIST, ""GREY"Gym Menu", str, "Select", "Cancel"); 
        }
        forex(i, 2) {
            if(IsPlayerInDynamicArea(playerid, GymData[Gym::Yoga][i])) {
                if(!PlayerData[playerid][GymMembership]) return Error2(playerid, "Kamu tidak memiliki gym membership.");

                SetTimerEx("TimerAnimationYoga", 12000, false, "i", playerid);
                TogglePlayerControllable(playerid, 0);
                ApplyAnimation(playerid,"PARK","Tai_Chi_Loop", 4.1, 1, 1, 1, 1, 0, 1);                
            }
        }    
        forex(i, 2) {
            if(IsPlayerInDynamicArea(playerid, GymData[Gym::BarbelPrison][i])) {
                if(!PlayerData[playerid][pArrest] && !PlayerData[playerid][pJailTime]) return Error2(playerid, "Kamu tidak sedang di Penjara.");
                
                forex(j, 5) {
                    PlayerTextDrawShow(playerid, GUI_GYM[playerid][j]);
                }

                SendCustomMessage(playerid, "GYM", "Tekan tombol bulat kuning di samping untuk mengangkat barbel");
                GymPlayerData[playerid][Gym::Barbel] = true;
                SelectTextDraw(playerid, COLOR_RED);
                SetPlayerAttachedObject(playerid, 2, 2916, 6, 0.0, 0.0, 0.0, 0.0, 80.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
                SetPlayerAttachedObject(playerid, 9, 2916, 5, 0.0, 0.0, 0.0, 0.0, 80.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
                ApplyAnimation(playerid, "Freeweights", "gym_free_A", 4.1, 0, 1, 1, 0, 0, 1);
                UpdateGymProgress(playerid);              
            }
        }
        if(IsPlayerInDynamicArea(playerid, GymData[Gym::Barbel])) {
            if(!PlayerData[playerid][GymMembership]) return Error2(playerid, "Kamu tidak memiliki gym membership.");
            forex(i, 5) {
                PlayerTextDrawShow(playerid, GUI_GYM[playerid][i]);
            }

            SendCustomMessage(playerid, "GYM", "Tekan tombol bulat kuning di samping untuk mengangkat barbel");
            GymPlayerData[playerid][Gym::Barbel] = true;
            SelectTextDraw(playerid, COLOR_RED);
            SetPlayerAttachedObject(playerid, 2, 2916, 6, 0.0, 0.0, 0.0, 0.0, 80.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            SetPlayerAttachedObject(playerid, 9, 2916, 5, 0.0, 0.0, 0.0, 0.0, 80.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            ApplyAnimation(playerid, "Freeweights", "gym_free_A", 4.1, 0, 1, 1, 0, 0, 1);
            UpdateGymProgress(playerid);
        }    
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

Dialog:DialogGymMenu(playerid, response, listitem, inputtext[]) {
    if(response) {
        switch(listitem) {
            case 0: {
                if(PlayerData[playerid][GymMembership]) return Error2(playerid, "You already have a gym membership.");

                if(!PlayerData[playerid][pPriority]) {
                    if(GetMoney(playerid) < 10000) return Error2(playerid, "You don't have enough money.");
                    PlayerData[playerid][GymMembership] = 1;
                    PlayerData[playerid][GymMembershipTime] = gettime() + (7 * 24 * 60 * 60);
                    GiveMoney(playerid, -10000);
                    Success2(playerid, "You have Success2fully purchased a gym membership.");
                } else {
                    PlayerData[playerid][GymMembership] = 1;
                    PlayerData[playerid][GymMembershipTime] = gettime() + (7 * 24 * 60 * 60);
                    Success2(playerid, "You have Success2fully purchased a gym membership."); 
                }
            }
            case 1: {
                new str[250];
                strcat(str, ""WHITE"Creatine\t"COLOR_DV20K"$100\tCreatine dapat digunakan sebanyak 5x, kegunaan untuk mengurangi penurunan stamina\n");
                strcat(str, ""GREY"Protein Powder\t"COLOR_DV20K"$50\tProtein Powder dapat digunakan sebanyak 2x, kegunaan untuk mengurangi penurunan stamina\n");
                Dialog_Show(playerid, DialogGymSuppliements, DIALOG_STYLE_TABLIST, ""GREY"Gym Suppliements", str, "Select", "Cancel");
            }
        }
    }
    return 1;
}

Dialog:DialogGymSuppliements(playerid, response, listitem, inputtext[]) {
    if(response) {
        switch(listitem) {
            case 0: {
                if(!PlayerData[playerid][GymMembership]) return Error2(playerid, "You don't have a gym membership.");
                if(GetMoney(playerid) < 100) return Error2(playerid, "You don't have enough money.");
                GiveMoney(playerid, -100);
                Inventory_Add(playerid, "Creatine", 1950, 1);
            }
            case 1: {
                if(!PlayerData[playerid][GymMembership]) return Error2(playerid, "You don't have a gym membership.");
                if(GetMoney(playerid) < 50) return Error2(playerid, "You don't have enough money.");
                GiveMoney(playerid, -50);
                Inventory_Add(playerid, "Protein Powder", 1951, 1);
            }
        }
    }
    return 1;
}

Function:TimerAnimationYoga(playerid)
{
    if(PlayerData[playerid][GymSuppliements][0]) { // Creatine
        PlayerData[playerid][GymSuppliements][0] -= 1;
        switch(random(2)) {
            case 0: {
                PlayerData[playerid][pLegs] += RandomEx(2, 3);    
                PlayerData[playerid][pHand] += RandomEx(2, 3);    
            }
            case 1: {
                PlayerData[playerid][pLegs] += RandomEx(2, 3);    
                PlayerData[playerid][pTorso] += RandomEx(2, 3);    
            }
            case 2: {
                PlayerData[playerid][pHand] += RandomEx(2, 3);    
                PlayerData[playerid][pTorso] += RandomEx(2, 3);    
            }
        }
        SetPlayerStress(playerid, PlayerData[playerid][pStress] - 5);
        TogglePlayerControllable(playerid, 1);
        ClearAnimations(playerid, 1);
        //Buff::GivePlayerBuff(playerid, Buff::type_stamina, 20, 0);
    } else if(PlayerData[playerid][GymSuppliements][1]) { // Protein Powder
        PlayerData[playerid][GymSuppliements][1] -= 1;
        switch(random(2)) {
            case 0: {
                PlayerData[playerid][pLegs] += RandomEx(2, 3);    
                PlayerData[playerid][pHand] += RandomEx(2, 3);    
            }
            case 1: {
                PlayerData[playerid][pLegs] += RandomEx(2, 3);    
                PlayerData[playerid][pTorso] += RandomEx(2, 3);    
            }
            case 2: {
                PlayerData[playerid][pHand] += RandomEx(2, 3);    
                PlayerData[playerid][pTorso] += RandomEx(2, 3);    
            }
        }
        SetPlayerStress(playerid, PlayerData[playerid][pStress] - 5);
        TogglePlayerControllable(playerid, 1);
        ClearAnimations(playerid, 1);
        //Buff::GivePlayerBuff(playerid, Buff::type_stamina, 20, 0);
    } else {
        switch(random(2)) {
            case 0: {
                PlayerData[playerid][pLegs] += 1;    
                PlayerData[playerid][pHand] += 1;    
            }
            case 1: {
                PlayerData[playerid][pLegs] += 1;    
                PlayerData[playerid][pTorso] += 1;    
            }
            case 2: {
                PlayerData[playerid][pHand] += 1;    
                PlayerData[playerid][pTorso] += 1;    
            }
        }
        SetPlayerStress(playerid, PlayerData[playerid][pStress] - 5);
        TogglePlayerControllable(playerid, 1);
        ClearAnimations(playerid, 1);        
        //Buff::GivePlayerBuff(playerid, Buff::type_stamina, 20, 0);
    }
    return 1;
}

stock UpdateGymProgress(playerid) {
    if(!GymPlayerData[playerid][Gym::Barbel]) return 1;
    new Float: divided, Float:value;
    divided = floatdiv(-165.000,100);
    value = floatmul(GymPlayerData[playerid][Gym::Persen], divided);
    
    PlayerTextDrawTextSize(playerid, GUI_GYM[playerid][2], 17.000, value);
    PlayerTextDrawShow(playerid, GUI_GYM[playerid][2]);	            
    return 1;
}