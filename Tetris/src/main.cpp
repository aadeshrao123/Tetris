#include <raylib.h>
#include "Game.h"

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
    Color Orange{ 255, 114, 0, 255 };
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();

        ClearBackground(Orange);
        game.Draw();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}