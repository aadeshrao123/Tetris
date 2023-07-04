#include "Block.h"

Block::Block()
{
	CellSize = 30;
	RotationState = 0;
	colors = GetCellColors();

	RowOffset = 0;
	ColumnOffset = 0;
}

void Block::Draw()
{
	std::vector<Position> tiles = GetCellPosition();
	for (Position item : tiles)
	{
		DrawRectangle(item.column * CellSize + 1, item.row * CellSize + 1, CellSize - 1, CellSize - 1, colors[id]);
	}
}

void Block::Move(int rows, int columns)
{
	RowOffset += rows;
	ColumnOffset += columns;
}

std::vector<Position> Block::GetCellPosition()
{
	std::vector<Position> tiles = Cells[RotationState];
	std::vector<Position> movedTiles;
	for (Position item : tiles)
	{
		Position newPos = Position(item.row + RowOffset, item.column + ColumnOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}