#include <iostream>

int main()
{
    const int DATA_SIZE = 11;
    int data[DATA_SIZE] = {0,1,2,3,4,5,6,7,8,9,10};
    int shuffleNum = 10;
    srand(time(nullptr));
    for(int i = 0; i < shuffleNum; ++i)
    {
        int randIndex01 = rand() % DATA_SIZE;
        int randIndex02 = rand() % DATA_SIZE;

        int temp = data[randIndex01];
        data[randIndex01] = data[randIndex02];
        data[randIndex02] = temp;
    }
    
    for(int i = 0 ;i < DATA_SIZE; ++i)
    {
        std::cout << data[i] << "\n";
    }

    std::cout << std::endl;

    int result = -1;
    int target = 5;
    for(int i = 0; i <= DATA_SIZE; i++)
    {
        if( data[i] == target)
        {
            result = i;
            break;
        }
    }

    std::cout << target << "のインデックスは" << result << "です" << std::endl;
    return 0;
}