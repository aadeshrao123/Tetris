#include <iostream>
#include "Grid.h"

Grid::Grid()
{
	NumRows = 20;
	NumCols = 10;
	CellSize = 30;
	Initilaize();
	Colors = GetCellColors();
}

void Grid::Initilaize()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			GridSize[row][column] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			std::cout << GridSize[row][column] << " ";
		}

		std::cout << std::endl;
	}
}



std::vector<Color> Grid::GetCellColors()
{
	Color darkGrey = { 26, 31, 40, 255 }; 
	Color green = { 47, 230, 23, 255 }; 
	Color red = { 232, 18, 18, 255 }; 
	Color orange = { 226, 116, 17, 255 }; 
	Color yellow = { 237, 234, 4, 255 }; 
	Color purple = { 166, 0, 247, 255 }; 
	Color cyan = { 21, 204, 209, 255 }; 
	Color blue = { 13, 64, 216, 255 };
	return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}

void Grid::Draw()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			int CellValue = GridSize[row][column];
			DrawRectangle(column * CellSize + 1, row * CellSize + 1, CellSize - 1, CellSize - 1, Colors[GetRandomValue(0, 7)]);
		}
	}
}