#include "raylib.h"
#include "Game.h"


int main(void)
{
    Color Orange{ 255, 114, 0, 255 };
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        BeginDrawing();

        ClearBackground(Orange);
        game.Draw();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}