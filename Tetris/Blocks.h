#include "Block.h"
#include "Position.h"

class LBlock : public Block
{
public:
    LBlock()
    {
        id = 1;
        Cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
        Cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
        Cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
        Cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
    }
};

class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2;
        Cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
        Cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
        Cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
        Cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
    }
};

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3;
        Cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
        Cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
        Cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
        Cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
    }
};

class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4;
        Cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
    }
};

class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;
        Cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
        Cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
        Cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
        Cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
    }
};

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;
        Cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
        Cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
        Cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
        Cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
    }
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;
        Cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
        Cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
        Cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
        Cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
    }
};