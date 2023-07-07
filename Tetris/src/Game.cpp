#include "Game.h"

Game::Game()
{
	grid = Grid();
	blocks = GetAllBlocks();
	CurrentBlock = GetRandomBlock();
	NextBlock = GetRandomBlock(); 
	GameOver = false;
	int Score = 0;
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
	CurrentBlock.Draw(11, 11);
	switch (NextBlock.id)
	{
	case 3:
		NextBlock.Draw(255, 290);
		break;
	case 4:
		NextBlock.Draw(255, 280);
		break;
	default:
		NextBlock.Draw(270, 270);
	}
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
		UpdateScore(0, 1);
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
	int rowsCleared = grid.ClearFullRows();
	UpdateScore(rowsCleared, 0);
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
	Score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
	switch (linesCleared)
	{
	case 1:
		Score += 100;
		break;
	case 2:
		Score += 300;
		break;
	case 3:
		Score += 500;
		break;
	default:
		break;
	}

	Score += moveDownPoints;
}
