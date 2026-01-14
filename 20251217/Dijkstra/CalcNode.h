#pragma once

#include "Node.h"

/// @brief 計算結果を入れる構造体
struct CalcNode
{
    Node* node;
    int cost;
    Node* calcParent;

    CalcNode(Node* _node)
    {
        node = _node;
        cost = 0;
        calcParent = nullptr;
    }
    CalcNode(Node* _node, int _cost, Node* _parent)
    {
        node = _node;
        cost = _cost;
        calcParent = _parent;
    }
};
