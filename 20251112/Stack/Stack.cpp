#include <iostream>
#include "./Stack.h"

void Stack::push(char val)
{
    arr[index] = val;
    index++;
}

char Stack::pop()
{
    if(index > 0)
    {
        index--;
    }
    char val = arr[index];
    arr[index] = 0;
    return val;
}

void Stack::output()
{
    for(int i = 0; i < index; ++i)
    {
        std::cout << arr[i];
    }
}