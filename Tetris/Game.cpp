#include "Game.h"

Game::Game()
{
	grid = Grid();
	blocks = GetAllBlocks();
	CurrentBlock = GetRandomBlock();
	NextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
	}
	int RandomIndex = rand() % blocks.size();
	Block block = blocks[RandomIndex];
	blocks.erase(blocks.begin() + RandomIndex);
	return block;
}

std::vector<Block> Game::GetAllBlocks()
{
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::Draw()
{
	grid.Draw();
	CurrentBlock.Draw();
}

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();

	switch (keyPressed)
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		break;
	case KEY_UP:
		RotateBlock();
		break;
	}
}

void Game::MoveBlockLeft()
{
	CurrentBlock.Move(0, -1);
	if (IsBlockOutside())
	{
		CurrentBlock.Move(0, 1);
	}
}

void Game::MoveBlockRight()
{
	CurrentBlock.Move(0, 1);
	if (IsBlockOutside())
	{
		CurrentBlock.Move(0, -1);
	}
}

void Game::MoveBlockDown()
{
	CurrentBlock.Move(1, 0);
	if (IsBlockOutside())
	{
		CurrentBlock.Move(-1, 0);
	}
}

bool Game::IsBlockOutside()
{
	std::vector<Position> tiles = CurrentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		if (grid.IsCellOutside(item.row, item.column))
		{
			return true;
		}
	}
	return false;
}

void Game::RotateBlock()
{
	CurrentBlock.Rotate();
	if (IsBlockOutside())
	{
		CurrentBlock.UndoRotation();
	}
}
