#pragma once
#include "Grid.h"
#include "Blocks.h"

class Game
{
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	bool GameOver;
	int Score = 0;

	void Draw();
	void HandleInput();
	void MoveBlockDown();

private:
	Grid grid;
	std::vector<Block> blocks;
	Block CurrentBlock;
	Block NextBlock;

	void RotateBlock();
	void MoveBlockLeft();
	void MoveBlockRight();
	bool IsBlockOutside();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
};