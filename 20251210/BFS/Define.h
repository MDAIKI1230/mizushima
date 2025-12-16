#pragma once
#include "Cell.h"

namespace Define
{
    const int MAP_SIZE_W = 8;
    const int MAP_SIZE_H = 8;
    const bool MAP[MAP_SIZE_W][MAP_SIZE_H] = 
    {
//       0     1      2      3      4      5      6      7
        {true, true,  false, true,  true,  true,  true,  true},  // 0
        {true, false, false, true,  false, true,  false, true},  // 1
        {true, false, false, true,  false, true,  false, true},  // 2
        {true, true,  true,  true,  false, true,  false, true},  // 3
        {true, false, true,  false, false, false, true,  true},  // 4
        {true, false, true,  false, false, true,  true,  false}, // 5
        {true, true,  true,  false, false, false, true,  false}, // 6
        {true, false, true,  true,  true,  false, true,  false}  // 7
    };

    const Cell START{2, 3}; 
    const Cell GOAL {6, 6};
};