#include "Block.h"

Block::Block()
{
	CellSize = 30;
	RotationState = 0;
	colors = GetCellColors();
}

void Block::Draw()
{
	std::vector<Position> tiles = Cells[RotationState];
	for (Position item : tiles)
	{
		DrawRectangle(item.column * CellSize + 1, item.row * CellSize + 1, CellSize - 1, CellSize - 1, colors[id]);
	}
}