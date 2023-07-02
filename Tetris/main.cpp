#include "raylib.h"
#include "Grid.h"

int main(void)
{
    Color Orange{ 255, 114, 0, 255 };
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(Orange);
        grid.Draw();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}