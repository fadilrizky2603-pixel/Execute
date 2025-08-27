#include <pawn-easing-functions>
#include <YSI_Coding/y_hooks>

new g_iAnimator = -1;

new
    PlayerText:NameLocalPrime0,
    PlayerText:NameLocalPrime1,
    PlayerText:NameLocalPrime2,
    PlayerText:NameLocalPrime3,
    PlayerText:NameLocalPrime4,
    PlayerText:NameLocalPrime5,
    PlayerText:NameLocalPrime6,
    PlayerText:NameLocalPrime7,
    PlayerText:NameLocalPrime8,
    PlayerText:NameLocalPrime9,
    PlayerText:NameLocalPrime10,
    PlayerText:NameLocalPrime11,
    PlayerText:NameLocalPrime12,
    PlayerText:NameLocalPrime13,
    PlayerText:NameLocalPrime14,
    PlayerText:NameLocalPrime15
;

hook OnPlayerConnect(playerid) {
    NameLocalPrime0 = CreatePlayerTextDraw(playerid, 317.000, 6.500, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime0, 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, NameLocalPrime0, 5.500, 4.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime0, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime0, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawUseBox(playerid, NameLocalPrime0, 1);
    PlayerTextDrawBoxColor(playerid, NameLocalPrime0, 50);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime0, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime0, 1);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime0, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime0, 4);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime0, 1);

    NameLocalPrime1 = CreatePlayerTextDraw(playerid, 316.000, 8.500, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime1, 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, NameLocalPrime1, 5.500, 2.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime1, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime1, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawUseBox(playerid, NameLocalPrime1, 1);
    PlayerTextDrawBoxColor(playerid, NameLocalPrime1, 50);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime1, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime1, 1);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime1, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime1, 4);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime1, 1);

    NameLocalPrime2 = CreatePlayerTextDraw(playerid, 312.000, 6.000, "/");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime2, 0.416, 1.750);
    PlayerTextDrawTextSize(playerid, NameLocalPrime2, 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime2, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime2, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime2, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime2, 0);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime2, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime2, 1);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime2, 1);

    NameLocalPrime3 = CreatePlayerTextDraw(playerid, 319.500, 15.500, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime3, 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, NameLocalPrime3, 3.000, 1.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime3, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime3, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawUseBox(playerid, NameLocalPrime3, 1);
    PlayerTextDrawBoxColor(playerid, NameLocalPrime3, 50);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime3, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime3, 1);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime3, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime3, 4);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime3, 1);

    NameLocalPrime4 = CreatePlayerTextDraw(playerid, 315.000, 9.500, "/");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime4, 0.416, 1.950);
    PlayerTextDrawTextSize(playerid, NameLocalPrime4, 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime4, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime4, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime4, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime4, 0);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime4, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime4, 1);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime4, 1);

    NameLocalPrime5 = CreatePlayerTextDraw(playerid, 321.500, 10.000, "/");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime5, 0.404, 1.449);
    PlayerTextDrawTextSize(playerid, NameLocalPrime5, 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime5, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime5, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime5, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime5, 0);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime5, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime5, 1);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime5, 1);

    NameLocalPrime6 = CreatePlayerTextDraw(playerid, 319.500, 22.500, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime6, 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, NameLocalPrime6, 4.000, 1.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime6, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime6, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawUseBox(playerid, NameLocalPrime6, 1);
    PlayerTextDrawBoxColor(playerid, NameLocalPrime6, 50);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime6, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime6, 1);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime6, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime6, 4);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime6, 1);

    NameLocalPrime7 = CreatePlayerTextDraw(playerid, 314.500, 27.000, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime7, 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, NameLocalPrime7, 3.000, 1.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime7, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime7, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawUseBox(playerid, NameLocalPrime7, 1);
    PlayerTextDrawBoxColor(playerid, NameLocalPrime7, 50);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime7, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime7, 1);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime7, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime7, 4);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime7, 1);

    NameLocalPrime8 = CreatePlayerTextDraw(playerid, 311.000, 3.000, "/");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime8, 0.416, 1.950);
    PlayerTextDrawTextSize(playerid, NameLocalPrime8, 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime8, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime8, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime8, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime8, 0);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime8, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime8, 1);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime8, 1);

    NameLocalPrime9 = CreatePlayerTextDraw(playerid, 311.500, 19.000, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime9, 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, NameLocalPrime9, 4.500, 3.500);
    PlayerTextDrawAlignment(playerid, NameLocalPrime9, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime9, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawUseBox(playerid, NameLocalPrime9, 1);
    PlayerTextDrawBoxColor(playerid, NameLocalPrime9, 50);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime9, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime9, 1);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime9, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime9, 4);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime9, 1);

    NameLocalPrime10 = CreatePlayerTextDraw(playerid, 313.000, 17.500, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime10, 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, NameLocalPrime10, 3.500, 3.500);
    PlayerTextDrawAlignment(playerid, NameLocalPrime10, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime10, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawUseBox(playerid, NameLocalPrime10, 1);
    PlayerTextDrawBoxColor(playerid, NameLocalPrime10, 50);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime10, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime10, 1);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime10, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime10, 4);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime10, 1);

    NameLocalPrime11 = CreatePlayerTextDraw(playerid, 314.000, 9.000, "/");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime11, 0.416, 1.950);
    PlayerTextDrawTextSize(playerid, NameLocalPrime11, 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime11, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime11, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime11, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime11, 0);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime11, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime11, 1);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime11, 1);

    NameLocalPrime12 = CreatePlayerTextDraw(playerid, 319.000, 12.500, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime12, 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, NameLocalPrime12, 5.000, 3.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime12, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime12, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawUseBox(playerid, NameLocalPrime12, 1);
    PlayerTextDrawBoxColor(playerid, NameLocalPrime12, 50);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime12, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime12, 1);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime12, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime12, 4);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime12, 1);

    NameLocalPrime13 = CreatePlayerTextDraw(playerid, 320.000, 10.000, "/");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime13, 0.404, 1.350);
    PlayerTextDrawTextSize(playerid, NameLocalPrime13, 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime13, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime13, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime13, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime13, 0);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime13, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime13, 1);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime13, 1);

    NameLocalPrime14 = CreatePlayerTextDraw(playerid, 316.000, 6.500, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime14, 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, NameLocalPrime14, 5.500, 2.500);
    PlayerTextDrawAlignment(playerid, NameLocalPrime14, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime14, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawUseBox(playerid, NameLocalPrime14, 1);
    PlayerTextDrawBoxColor(playerid, NameLocalPrime14, 50);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime14, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime14, 1);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime14, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime14, 4);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime14, 1);

    NameLocalPrime15 = CreatePlayerTextDraw(playerid, 319.500, 18.500, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, NameLocalPrime15, 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, NameLocalPrime15, 2.000, 4.000);
    PlayerTextDrawAlignment(playerid, NameLocalPrime15, 1);
    PlayerTextDrawColor(playerid, NameLocalPrime15, SERVER_TEXTDRAW_COLOR);
    PlayerTextDrawUseBox(playerid, NameLocalPrime15, 1);
    PlayerTextDrawBoxColor(playerid, NameLocalPrime15, 50);
    PlayerTextDrawSetShadow(playerid, NameLocalPrime15, 0);
    PlayerTextDrawSetOutline(playerid, NameLocalPrime15, 1);
    PlayerTextDrawBackgroundColor(playerid, NameLocalPrime15, 255);
    PlayerTextDrawFont(playerid, NameLocalPrime15, 4);
    PlayerTextDrawSetProportional(playerid, NameLocalPrime15, 1);
}

CMD:move1(playerid, const params[])
{
    new Float:x, Float:y;
    if (sscanf(params, "ff", x, y))
    {
        return SendClientMessage(playerid, 0xDADADAFF, "Usage: /move <x> <y>");
    }

    if (g_iAnimator != -1)
        PlayerText_StopMove(g_iAnimator);

    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime0, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime1, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime2, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime3, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime4, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime5, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime6, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime7, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime8, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime9, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime10, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime11, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime12, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime13, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime14, x, y, 1000, EASE_OUT_CUBIC);
    g_iAnimator = PlayerText_MoveTo(playerid, NameLocalPrime15, x, y, 1000, EASE_OUT_CUBIC);
    return 1;
}