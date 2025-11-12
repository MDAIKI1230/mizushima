#include <iostream>
#include "./Stack.h"

int main()
{
    Stack stack;
    srand(time(nullptr));
    
    for(char c = 'a'; c <= 'z'; ++c)
    {
        int randNum = rand() % 2;

        stack.push(c);
        std::cout << "追加した" << c << "\n";
        stack.output();
        std::cout << "\n";

        if(randNum)
        {
            std::cout << "取り出した" << stack.pop() << "\n";
        }
    }

    std::cout << std::endl;

    return 0;
}