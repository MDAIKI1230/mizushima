#include "Cell.h"

const Cell Cell:: UP   = { 0,-1};
const Cell Cell:: DOWN = { 0, 1};
const Cell Cell:: RIGHT= { 1,0};
const Cell Cell:: LEFT = { -1,0};

const Cell Cell:: DIRS[4] = 
{
    Cell::UP,Cell::LEFT,Cell::DOWN,Cell::RIGHT
};

Cell::Cell(){};

Cell::Cell(int x, int y):x(x),y(y){};

Cell Cell::operator+(const Cell& other)
{
    int x = this->x + other.x;
    int y = this->y + other.y;
    return Cell(x,y);
}

bool Cell::operator==(const Cell& other)
{
    return ((this->x == other.x) && (this->y == other.y));
}

bool Cell::operator!=(const Cell& other)
{
    return ((this->x != other.x) || (this->y != other.y));
}