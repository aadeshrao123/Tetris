#include <iostream>
#include "Grid.h"
#include "Colors.h"

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


bool Grid::IsCellOutside(int row, int column)
{
	if (row >= 0 && row < NumRows && column >= 0 && column < NumCols)
	{
		std::cout << "false" << std::endl;
		return false;
	}
	std::cout << "true" << std::endl;

	return true;
}

void Grid::Draw()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			int CellValue = GridSize[row][column];
			DrawRectangle(column * CellSize + 1, row * CellSize + 1, CellSize - 1, CellSize - 1, Colors[CellValue]);
		}
	}
}