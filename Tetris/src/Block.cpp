#include "Block.h"

Block::Block()
{
	CellSize = 30;
	RotationState = 0;
	colors = GetCellColors();

	RowOffset = 0;
	ColumnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
	std::vector<Position> tiles = GetCellPosition();
	for (Position item : tiles)
	{
		DrawRectangle(item.column * CellSize + offsetX, item.row * CellSize + offsetY, CellSize - 1, CellSize - 1, colors[id]);
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

void Block::Rotate()
{
	RotationState++;
	if (RotationState == (int)Cells.size())
	{
		RotationState = 0;
	}
}

void Block::UndoRotation()
{
	RotationState --;
	if (RotationState == -1)
	{
		RotationState = Cells.size() - 1;
	}
}
