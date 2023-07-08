#pragma once
#include "Grid.h"
#include "Blocks.h"

class Game
{
public:
	Game();
	~Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	bool GameOver;
	int Score = 0;
	Music music;

	void Draw();
	void HandleInput();
	void MoveBlockDown();

private:
	Grid grid;
	std::vector<Block> blocks;
	Block CurrentBlock;
	Block NextBlock;
	Sound RoatateSound;
	Sound ClearSound;


	void RotateBlock();
	void MoveBlockLeft();
	void MoveBlockRight();
	bool IsBlockOutside();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
};