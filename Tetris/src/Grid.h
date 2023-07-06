#pragma once
#include <vector>
#include "raylib.h"



class Grid
{
public:

	Grid();
	int GridSize[20][10];

	void Initilaize();
	void Print();
	bool IsCellOutside(int row, int column);
	bool IsCellEmpty(int row, int column);
	void Draw();
	int ClearFullRows();

private:
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int numRows);

private:

	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> Colors;

};