#include <iostream>

int main()
{
    const int ARR_NUM = 10;//配列数
    int randArr[ARR_NUM] = {};//ランダムように配列
    int sortArr[ARR_NUM] = {};//ソート用の配列
    //ランダム準備
    srand(time(nullptr));
    //ランダムな整数を10個生成
    for(int index = 0; index<ARR_NUM;index++)
    {
        randArr[index] = rand();
        //出力準備
        std::cout << randArr[index];
        //改行
        std::cout << "\n";
    }

    //ソート用配列にランダム配列の最初を入れておく
    sortArr[0] = randArr[0];

    //出力
    std::cout << std::endl;

    //挿入ソート
    for(int sortIndex = 1;sortIndex < ARR_NUM; sortIndex++)
    {
        int val = randArr[sortIndex];//ソートする値
        
        //すでにソート済みの要素数になる
        int setIndex = sortIndex - 1;//ソート用配列の挿入インデックス
        //挿入するところを探しつつ挿入するところから先の要素をずらす
        //インデックスが０より小さくなるか、値を入れる場所が見つかったらループを抜ける
        while(setIndex >= 0 && sortArr[setIndex] > val)
        {
            //要素のインデックスを一つずらす
            sortArr[setIndex + 1] = sortArr[setIndex];
            
            setIndex --;
        }
        //ずらしたインデックスとずらしてないインデックスの間に入れる
        sortArr[setIndex+1] = val;
    }

    //出力用
    for(int index = 0; index < ARR_NUM; index++)
    {
        std::cout << sortArr[index];
        std::cout << "\n";
    }

    //出力
    std::cout << std::endl;
}