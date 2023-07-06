#include "Game.h"

Game::Game()
{
	grid = Grid();
	blocks = GetAllBlocks();
	CurrentBlock = GetRandomBlock();
	NextBlock = GetRandomBlock(); 
	GameOver = false;
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
	if (GameOver && keyPressed != 0)
	{
		GameOver = false;
		Reset();
	}
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
	if (!GameOver)
	{
		CurrentBlock.Move(0, -1);
		if (IsBlockOutside() || BlockFits() == false)
		{
			CurrentBlock.Move(0 , 1);
		}
	}
}

void Game::MoveBlockRight()
{
	if (!GameOver)
	{
		CurrentBlock.Move(0, 1);
		if (IsBlockOutside() || BlockFits() == false)
		{
			CurrentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown()
{
	if (!GameOver)
	{
		CurrentBlock.Move(1, 0);
		if (IsBlockOutside() || BlockFits() == false)
		{
			CurrentBlock.Move(-1, 0);
			LockBlock();
		}
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
	if (!GameOver)
	{
		CurrentBlock.Rotate();
		if (IsBlockOutside())
		{
			CurrentBlock.UndoRotation();
		}
	}
}

void Game::LockBlock()
{
	std::vector<Position> tiles = CurrentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		grid.GridSize[item.row][item.column] = CurrentBlock.id;
	}
	CurrentBlock = NextBlock;
	if (BlockFits() == false)
	{
		GameOver = true;
	}
	NextBlock = GetRandomBlock();
	grid.ClearFullRows();
}

bool Game::BlockFits()
{
	std::vector<Position> tiles = CurrentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		if (grid.IsCellEmpty(item.row, item.column) == false)
		{
			return false;
		}
	}
	return true;
}

void Game::Reset()
{
	grid.Initilaize();
	blocks = GetAllBlocks();
	CurrentBlock = GetRandomBlock();
	NextBlock = GetRandomBlock();
}
