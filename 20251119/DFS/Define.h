#pragma once
#include "Cell.h"

namespace Define
{
    const int MAP_SIZE_W = 8;
    const int MAP_SIZE_H = 8;
    const bool MAP[MAP_SIZE_W][MAP_SIZE_H] = 
    {
        {true, true,false, true, true, true, true, true},
        {true,false,false, true,false, true,false, true},
        {true,false,false, true,false, true,false, true},
        {true, true, true, true,false, true,false, true},
        {true,false, true,false,false,false, true, true},
        {true,false, true,false,false, true, true,false},
        {true, true, true,false,false,false, true,false},
        {true,false, true, true, true,false, true,false}
    };

    const Cell START{2, 3}; 
    const Cell GOAL {6, 6};
};