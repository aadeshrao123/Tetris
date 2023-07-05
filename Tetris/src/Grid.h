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
	bool IsCellOutside(int row, int column);
	bool IsCellEmpty(int row, int column);
	void Draw();

private:

private:

	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> Colors;

};