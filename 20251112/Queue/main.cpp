#include <iostream>
#include "Queue.h"

int main()
{
    Queue Queue;
    char c = 'a';
    srand(time(nullptr));
    while(c <= 'z')
    {
        int randNum = rand() % 2;
        if(randNum)
        {
            Queue.enqueue(c);
            std::cout << "追加した：" << c << "\n";
            Queue.output();
            std::cout << "\n";
            c++;
        }
        else
        {
            std::cout << "取り出した：" << Queue.dequeue() << "\n";
            Queue.output();
            std::cout << "\n";
        }
    }

    std::cout << std::endl;
    
    return 0;
}