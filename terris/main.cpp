#include <iostream>
#include <raylib.h>
#include "game.h"
#include "color.h"

using namespace std;

double lastupdatetime=0;

bool event(double interval)
{
    double currenttime = GetTime();
    if (currenttime - lastupdatetime >= interval)
    {
        lastupdatetime=currenttime;
        return true;
    }
    return false;
}

int main () 
{
    InitWindow(660,880,"Raylib Terrist");
    SetTargetFPS(60);
    game Game=game();
    Font font = LoadFontEx("font/monogarm.ttf", 64, 0, 0);

    while(WindowShouldClose() == false )
    {
        Game.handleinput();
        if (event(0.5))
        {
            Game.moveblockdown();
        }
        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawTextEx(font,"Score",{482,22}, 42,4, WHITE);
        DrawTextEx(font,"Next",{488,241}, 42,4, WHITE);
        if ( Game.gameover)
        {
            DrawTextEx(font,"Game Over!",{422,639}, 42,4, WHITE);
        }
        DrawRectangleRounded({422,78,224,85}, 0.4, 6, lightblue);
         char scoretext[10];
        sprintf(scoretext, "%d", Game.score);
        Vector2 textsize = MeasureTextEx(font, scoretext, 42, 4);
        DrawTextEx(font,scoretext ,{482+(224 - textsize.x)/2,92}, 42,4, WHITE);
        DrawRectangleRounded({422,298,224,255}, 0.4, 6, lightblue);
        Game.draw();

        EndDrawing();
    }


    CloseWindow();
}