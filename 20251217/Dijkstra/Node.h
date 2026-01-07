#pragma once
#include <vector>

class Node
{
public:
    /// @brief 隣接ノードのリストのゲッター
    /// @return 隣接ノードのリスト
    const std::vector<Node>& GetNeighbors()
    {
        return neighbors;
    }

    /// @brief ノードIDのゲッター
    /// @return ノードのID
    const char& GetId()
    {
        return id;
    }

private:
    char id;
    std::vector<Node> neighbors;
};