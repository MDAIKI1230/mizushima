#pragma once
#include <vector>
#include "Node.h"

class Dijkstra
{
public:
    /// @brief 最短経路の計算
    /// @param str スタート地点
    /// @param goal ゴール地点
    /// @return 最短経路の道順のノードID
    std::vector<char> getShortestPath(Node str,Node goal);
};