#pragma once
#include <vector>
#include "raylib.h"



class Grid
{
public:

	Grid();
	void Initilaize();
	void Print();
	int GridSize[20][10];
	void Draw();

private:
	std::vector<Color> GetCellColors();

private:

	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> Colors;

};