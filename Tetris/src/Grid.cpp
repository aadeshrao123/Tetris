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
		//std::cout << "false" << std::endl;
		return false;
	}
	//std::cout << "true" << std::endl;

	return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
	if (GridSize[row][column] == 0)
	{
		return true;
	}
	return false;
}

void Grid::Draw()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			int CellValue = GridSize[row][column];
			DrawRectangle(column * CellSize + 11, row * CellSize + 11, CellSize - 1, CellSize - 1, Colors[CellValue]);
		}
	}
}

bool Grid::IsRowFull(int row)
{
	for (int column = 0; column < NumCols; column++)
	{
		if (GridSize[row][column] == 0)
		{
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row)
{
	for (int column = 0; column < NumCols; column++)
	{
		GridSize[row][column] = 0;
	}
}

void Grid::MoveRowDown(int row, int numRows)
{
	for (int column = 0; column < NumCols; column++)
	{
		GridSize[row + numRows][column] = GridSize[row][column];
		GridSize[row][column] = 0;
	}
}

int Grid::ClearFullRows()
{
	int completed = 0;
	for (int row = NumRows - 1; row >= 0; row--)
	{
		if (IsRowFull(row))
		{
			ClearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			MoveRowDown(row, completed);
		}
	}
	return completed;
}