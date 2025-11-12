#include <iostream>

int main()
{
    const int ARR_SIZE = 10;
    int data[ARR_SIZE] = {};

    srand(time(nullptr));
    for(int index = 0; index < ARR_SIZE; index++)
    {
        data[index] = rand();
    }

    for(int i = 0; i < ARR_SIZE; i++)
    {
        std::cout << data[i];
        std::cout << "\n";
    }

    std::cout << std::endl;
}