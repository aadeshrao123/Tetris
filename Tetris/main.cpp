#include "raylib.h"

int main(void)
{
    Color Orange{ 255, 114, 0, 255 };
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(120);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(Orange);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}