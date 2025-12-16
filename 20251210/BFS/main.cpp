#include <iostream>
#include <queue>
#include <vector>
#include "Define.h"
#include "Cell.h"

bool CheckGoalBFS();
void logCell(Cell cell);

int main()
{
    if(CheckGoalBFS())
    {
        std::cout << "ゴールできる" << std::endl;
    }
    else
    {
        std::cout << "ゴールできない" << std::endl;
    }

    return 0;
}

bool CheckGoalBFS()
{
    Cell nowCheckCell { Define::START};//チェックセル
    std::vector<Cell> checkedCells {};//すでにチェックしたセル
    std::vector<Cell> checkWaitList{};//チェック待ちセルを確認するためのリスト
    std::queue<Cell> checkWaitCells {};//チェック待ちセル

    // 最初に START を queue に入れる
    checkWaitCells.push(nowCheckCell);
    checkWaitList.push_back(nowCheckCell);


    //チェック位置がゴールになるまで
    while(!checkWaitCells.empty())
    {
        //次にチェックするセルを決める
        nowCheckCell = checkWaitCells.front();
        //チェック待ちから除外
        if (!checkWaitList.empty())
        {
            checkWaitList.erase(checkWaitList.begin());
        }
        checkWaitCells.pop();

        //ゴールセルだったらtrueを返して終了
        if(nowCheckCell == Define::GOAL)
        {
            return true;
        }

        //チェックしたセルをチェック済みセルに追加
        checkedCells.push_back(nowCheckCell);

        std::cout << "メインセル\n";
        std::cout << nowCheckCell.x << "," << nowCheckCell.y << "\n";
        //４方向のセルをチェック待ちに追加するかどうかのチェック
        for(int i = 0; i < 4; i++)
        {
            //実際に確認するセル
            Cell checkCell = nowCheckCell + Cell::DIRS[i];
            logCell(checkCell);
            //セルがマップ外ならスキップ
            if(checkCell.x < 0 || checkCell.y < 0 || 
                checkCell.x >= Define::MAP_SIZE_W || checkCell.y >= Define::MAP_SIZE_H)
            {
                std::cout << "マップ外\n";
                continue;
            }

            //すでにチェックしたセルならスキップ
            bool alreadyCheckCell { false };//すでにチェック済みフラグ
            //チェック済みセルすべてと比較
            for(int i = 0; i < checkedCells.size(); i++)
            {
                //同じのがあったらすでにチェック済みフラグを立て、ループを抜ける。
                if(checkedCells[i] == checkCell)
                {
                    alreadyCheckCell = true;
                    break;
                }
            }

            //すでにチェック済みフラグが立っているならスキップ
            if(alreadyCheckCell == true)
            {
                std::cout << "チェック済み\n";
                continue;
            }

            bool isCheckWait = false;
            //チェック待ちにあるならスキップ
            //チェック待ちすべてと比較
            for(int i= 0;i<checkWaitList.size();i++)
            {
                if(checkWaitList[i] == checkCell)
                {
                    //同じのがあったらすでにチェック済みフラグを立て、ループを抜ける。
                    isCheckWait = true;
                    break;
                }
            }

            //チェック待ちフラグが立っているならスキップ
            if(isCheckWait)
            {
                continue;
            }

            //マップが移動可能マスならチェック待ちに追加
            if(Define::MAP[checkCell.y][checkCell.x] == true)
            {
                std::cout << "チェック待ちに追加\n";
                checkWaitCells.push(checkCell);
                checkWaitList.push_back(checkCell);
            }
            else
            {
                std::cout << "移動不可セル\n";
            }
        }

        std::cout << std::endl;
    }

    return false;
}

void logCell(Cell cell)
{
    std::cout << cell.x << "," << cell.y << "\n";
}