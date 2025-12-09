#include <iostream>
#include <stack>
#include <vector>
#include "Cell.h"
#include "Define.h"

bool checkGoal();

int main()
{
    if(checkGoal())
    {
        std::cout << "ゴールできる" << std::endl;
    }
    else
    {
        std::cout << "ゴールできない"<<std::endl;
    }
    return 0;
}

bool checkGoal()
{
    std::stack<Cell> canGoCell; //行けるリスト
    std::vector<Cell> wentCell; //行ったリスト
    Cell nowPos = Define::START;//現在の位置

    while (nowPos != Define::GOAL)
    {
        std::vector<Cell> nowCanGoCell;//今の位置から行けるリスト
        //４方向の行けるところをリストに入れる
        for(int index = 0 ;index < 4 ;index++)
        {
            Cell checkCell = nowPos + Cell::DIRS[index];
            //範囲外ならスキップ
            if(checkCell.x < 0 || checkCell.y < 0 ||
                checkCell.x >= Define::MAP_SIZE_W || checkCell.y >= Define::MAP_SIZE_H)
            {
                continue;
            }
            
            //もう行った場所ならスキップ
             bool alreadyWent = false;
            for (auto& w : wentCell)
            {
                if (w == checkCell)
                {
                    alreadyWent = true;
                    break;
                }
            }
            if (alreadyWent)
            {
                continue;
            } 

            if(Define::MAP[checkCell.x][checkCell.y])
            {
                if(checkCell == Define::GOAL)
                {
                    return true;
                }

                nowCanGoCell.push_back(checkCell);
            }
        }

        //今の位置を行ったリストに追加
        wentCell.push_back(nowPos);

        //行ける場所を全てスタックへ
        for (auto& c : nowCanGoCell)
        {
            canGoCell.push(c);
        }

        //次へ進む
        if(!canGoCell.empty())
        {
            nowPos = canGoCell.top();
            canGoCell.pop();
        }
        else
        {
            break;
        }
    } 

    return false;
}