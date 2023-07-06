#pragma once
#include "Grid.h"
#include "Blocks.h"

class Game
{
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	Grid grid;
	bool GameOver;
	int Score = 0;

	void Draw();
	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();

private:
	std::vector<Block> blocks;
	Block CurrentBlock;
	Block NextBlock;

	void RotateBlock();
	bool IsBlockOutside();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
};