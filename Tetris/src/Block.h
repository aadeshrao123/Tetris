#pragma once

#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"

class Block
{
public:
	Block();
	void Draw(int offsetX, int offsetY);
	int id;
	std::map<int, std::vector<Position>> Cells;

	void Move(int rows, int columns);
	std::vector<Position> GetCellPosition();

	void Rotate();
	void UndoRotation();

private:
	int CellSize;
	int RotationState;
	std::vector<Color> colors;

	int RowOffset;
	int ColumnOffset;


};