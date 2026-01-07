#include <map>
#include "Dijkstra.h"

std::vector<char> Dijkstra::GetShortestPath(Node str,Node goal)
{
    // 計算結果を入れる連想配列
    std::map<Node,int> calcResult; 

    // 計算中心ノード
    Node currentNode = str;

    // 計算済みノードリスト
    std::vector<Node> calculatedNodes;

    // スタートノードの計算
    calcResult[str] = 0;

    // スタート地点を計算済みに追加
    
    while(true)
    {
        // 行けるノードのコスト計算
        for(auto neighbor : currentNode.GetNeighbors())
        {
            // 計算済みノードリストにあるか
            // 計算済みフラグ
            bool isCalculated = false;
            //すべての計算済みノードと比較
            for(auto calculatedNode : calculatedNodes)
            {
                if(neighbor.GetId() == calculatedNode.GetId())
                {
                    // 同じIDのモノがあったらフラグを立てる
                    isCalculated = true;
                }
            }

            //フラグが立っているなら
            if( isCalculated )
            {
                // スキップ
                continue;
            }

            // ノードコスト計算
            int cost = calcResult[currentNode];

            // 計算結果があるかどうか
            if(calcResult.contains(neighbor))
            {
                // 
            }
        }
    }
}