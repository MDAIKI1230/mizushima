#pragma once
#include <vector>

/// @brief ノード
class Node
{
public:
    /// @brief 隣接ノードのリストのゲッター
    /// @return 隣接ノードのリスト
    const std::vector<Node>& getNeighbors()
    {
        return neighbors;
    }

    /// @brief ノードIDのゲッター
    /// @return ノードのID
    const char& getId()
    {
        return id;
    }

private:
    char id;
    std::vector<Node> neighbors;
};