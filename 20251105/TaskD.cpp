#include <iostream>

int main()
{
    for(int i = 1;i <= 100; ++i)
    {
        std::cout << i << ":";
        bool isMultipleThree = i % 3 == 0;
        bool isMultipleFive = i % 5 == 0;
        if(isMultipleThree && isMultipleFive)
        {
            std::cout << "fizz buzz";
        }
        else if(isMultipleThree)
        {
            std::cout << "fizz";
        }
        else if(isMultipleFive)
        {
            std::cout << "buzz";
        }
        std::cout << "\n";
    }

    std::cout << std::endl;

    return 0;
}