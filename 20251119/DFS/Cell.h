#pragma once

struct Cell
{
    int x,y{0};
public:
    static const Cell UP  ;
    static const Cell DOWN;
    static const Cell RIGHT;
    static const Cell LEFT ;

    static const Cell DIRS[4];

    Cell();
    Cell(int x,int y);
    Cell operator+(const Cell& other);
    bool operator==(const Cell& other);
    bool operator!=(const Cell& other);
};
