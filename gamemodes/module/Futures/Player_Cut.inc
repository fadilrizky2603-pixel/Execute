//login screen by ahmazuqi

#define Login::    Login_

enum e_Login {
    STREAMER_TAG_OBJECT:objectLogin,
};
new Login::screen[MAX_PLAYERS][e_Login];

function Login_Screen_Show(playerid, value)
{
    switch(value)
    {
        //bandara
        case 1:
        {   
            va_SendClientMessageToAll(-1, " ");
            new wid = 200+pData[playerid][pID];
            TogglePlayerControllable(playerid, false);
            if(IsValidDynamicObject(Login::screen[playerid][objectLogin]))
                DestroyDynamicObject(Login::screen[playerid][objectLogin]);
            Login::screen[playerid][objectLogin] = CreateDynamicObject(1681, 1161.48, -2490.2, 66.7269, 0, 0, -89.8, wid, -1, -1);
            Streamer_Update(playerid, STREAMER_TYPE_OBJECT);
            SetPlayerPos(playerid, 1291.9954,-2382.0916,21.6245);
            SetPlayerVirtualWorld(playerid, wid);
            MoveDynamicObject(Login::screen[playerid][objectLogin], 1362.21, -2489.5, 66.7269, 18.0, 0, 0, -89.8);
            SetPlayerCameraPos(playerid,1287.4884,-2386.6216,21.6686);
            SetPlayerCameraLookAt(playerid, 1161.48, -2490.2, 66.7269, CAMERA_CUT);
            SetTimerEx("MoveSceneLogin", 12000, false, "id", playerid, 1);
            InterpolateCameraLookAt(playerid, 1161.48, -2490.2, 66.7269, 1362.21, -2489.5, 66.7269, 10000, CAMERA_MOVE);
            
        }
        //pelabuhan
        case 2:
        {

        }
    }
    return 1;
}

function MoveSceneLogin(playerid, value)
{
    switch(value)
    {
        case 1:
        {
            new wid = 200+pData[playerid][pID];
            TogglePlayerControllable(playerid, false);
            if(IsValidDynamicObject(Login::screen[playerid][objectLogin]))
                DestroyDynamicObject(Login::screen[playerid][objectLogin]);
            Login::screen[playerid][objectLogin] = CreateDynamicObject(1681, 1487.52, -2494.01, 14.7547, 0 , 0, -90.2, wid, -1, -1);
            Streamer_Update(playerid, STREAMER_TYPE_OBJECT);
            SetPlayerPos(playerid, 1606.1193,-2458.1716,13.5547);
            SetPlayerVirtualWorld(playerid, wid);
            MoveDynamicObject(Login::screen[playerid][objectLogin], 1572.76, -2494.01, 14.7547, 18.0, 0, 0, -90.2);
            SetPlayerCameraPos(playerid,1604.5731,-2460.0952,20.4359);
            SetPlayerCameraLookAt(playerid, 1161.48, -2490.2, 66.7269, CAMERA_CUT);
            SetTimerEx("SpawnEndPlayer", 12000, false, "i", playerid);
            InterpolateCameraLookAt(playerid, 1487.52, -2494.01, 14.7547, 1572.76, -2494.01, 14.7547, 10000, CAMERA_MOVE);
        }
        case 2: 
        {

        }
    }
    return 1;
}

function SpawnEndPlayer(playerid)
{
    if(IsValidDynamicObject(Login::screen[playerid][objectLogin]))
        DestroyDynamicObject(Login::screen[playerid][objectLogin]);

    IsPlayerLanding[playerid] = 0;
    SendClientMessageEx(playerid,COLOR_WHITE,""LB_E"SERVER: "WHITE_E"Registration Successful! Thank you "YELLOW_E"%s"WHITE_E" for joining the server!", pData[playerid][pName]);
    SendClientMessageEx(playerid,COLOR_WHITE,""LB_E"SERVER: "WHITE_E"Date of Birth : "YELLOW_E"%s "WHITE_E"| Gender : "YELLOW_E"Male"WHITE_E"", pData[playerid][pAge]);
    pData[playerid][pPosX] = 1638.170410;
    pData[playerid][pPosY] = -2359.558349;
    pData[playerid][pPosZ] = 1020.330627;
    pData[playerid][pPosA] = 0.925984;
    HideSpawnMenu(playerid);
    SetCameraBehindPlayer(playerid);
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    TogglePlayerControllable(playerid, 1);
    StopAudioStreamForPlayer(playerid);
    SetPlayerSpawn(playerid);
    SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
    SpawnPlayer(playerid);
    
    Servers(playerid, "Hallo "LB_E"%s"WHITE_E"! Selamat datang di Local Prime Roleplay", ReturnName(playerid));
    Servers(playerid, "Berhasil memuat basis data karakter anda dalam "RED_E"%dms", GetPlayerPing(playerid));
    Servers(playerid, "Jangan lupa untuk ikuti aturan server!");
    pData[playerid][pDiPesawat] = true;
    return 1;
}
CMD:testscreen(playerid, params[])
{
    Login::Screen_Show(playerid, 1);
    return 1;
}