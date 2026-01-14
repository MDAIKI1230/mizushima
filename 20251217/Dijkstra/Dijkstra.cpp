#include <map>
#include "Dijkstra.h"
#include "CalcNode.h"

std::vector<char> Dijkstra::getShortestPath(Node str,Node goal)
{
    // 計算結果を入れる連想配列
    std::map<Node,CalcNode*> calcResult; 

    // 計算済みノードリスト
    std::vector<Node*> calculatedNodes;

    // 現在の計算ノード
    Node* currentNode = &str;

    CalcNode strNode{&str};
    // スタート地点の計算
    calcResult[str] = &strNode;

    // スタート地点を計算済みに追加
    
    while(currentNode->getId() == goal.getId())
    {
        // 行けるノードのコスト計算
        for(auto neighbor : currentNode->getNeighbors())
        {
            // 計算済みノードリストにあるか
            // 計算済みフラグ
            bool isCalculated = false;
            //すべての計算済みノードと比較
            for(auto calculatedNode : calculatedNodes)
            {
                if(neighbor.getId() == calculatedNode->getId())
                {
                    // 同じIDのモノがあったらフラグを立てる
                    isCalculated = true;
                    // for文を抜ける
                    break;
                }
            }

            //フラグが立っているなら
            if( isCalculated )
            {
                // スキップ
                continue;
            }

            // ノードコスト計算
            // コスト取得関数が来る
            int cost = calcResult[*currentNode]->cost;

            // 計算結果があるかどうか
            if(calcResult.contains(neighbor))
            {
                // あってコストがもとより低いなら
                if(calcResult[neighbor]->cost > cost)
                {
                    // 変更
                    CalcNode calcNeighbor{&neighbor, cost, currentNode};
                    calcResult[neighbor] = &calcNeighbor;
                }
            }
            // ないなら
            else
            {
                // 追加
                CalcNode calcNeighbor{&neighbor, cost, currentNode};
                calcResult[neighbor] = &calcNeighbor;
            }

            // 計算済みノードの追加
            calculatedNodes.push_back(currentNode);

            // 次の計算ノードの決定
            // 最小コストのノードが入る
            CalcNode* minCostNode = nullptr;

            // 最小コスト探す
            for(auto ite = calcResult.begin(); ite != calcResult.end(); ite++)
            {
                // Nullチェック
                if( minCostNode == nullptr)
                {
                    // 代入
                    minCostNode = ite->second;
                }

                // 暫定一位よりコストが低いなら
                if(minCostNode->cost > ite->second->cost)
                {
                    // 変更
                    minCostNode = ite->second;
                }
            }

            // 最小コストノードのノードを次の計算に代入
            currentNode = minCostNode->node;
        }
    }
}