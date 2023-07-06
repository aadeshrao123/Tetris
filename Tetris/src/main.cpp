#include <raylib.h>
#include "Game.h"
#include "Colors.h"

double LastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double CurrentTime = GetTime();
    if (CurrentTime - LastUpdateTime >= interval)
    {
        LastUpdateTime = CurrentTime;
        return true;
    }
    return false;
}


int main(void)
{
    InitWindow(570, 620, "Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Tetris/Font/Lobster-Regular.ttf", 50, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();

        ClearBackground(darkblue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
        if (game.GameOver)
        {
            DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
        }


        DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightblue);
        DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightblue);

        game.Draw();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}