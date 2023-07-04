#pragma once
#include "Grid.h"
#include "Blocks.h"

class Game
{
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	Grid grid;

private:
	bool IsBlockOutside();
	std::vector<Block> blocks;
	Block CurrentBlock;
	Block NextBlock;
};