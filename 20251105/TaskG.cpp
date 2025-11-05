#include <iostream>

int main()
{
    const int DATA_SIZE = 100;
    int data[DATA_SIZE];

    srand(time(nullptr));

    for(int i = 0;i < DATA_SIZE; ++i)
    {
        data[i] = rand() % 101;
    }

    for(int i = 0 ; i < DATA_SIZE; i++)
    {
        for(int j = i + 1; j < DATA_SIZE ; j++)
        {
            int valueA = data[i];
            int valueB = data[j];
            if(valueA > valueB)
            {
                data[i] = valueB;
                data[j] = valueA;
            }
        }
    }

     for(int i = 0; i < DATA_SIZE ; i++)
    {
        std::cout << data[i] << "\n";
    }

    std::cout << std::endl;

    int target = 50;
    int result = -1;
    int left = 0;
    int right = DATA_SIZE - 1;

    while(left < right)
    {
        int mid = (left + right) / 2;
        if(data[mid] == target)
        {
            result = mid;
            break;
        }

        if(data[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    if( result >= 0)
    {
        std::cout << target << "のインデックスは" << result << "です" << std::endl;
    }
    else
    {
        std::cout << target << "は見つかりませんでした" << std::endl;
    }

    return 0;
}