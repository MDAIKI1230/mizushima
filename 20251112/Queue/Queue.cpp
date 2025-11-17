#include <iostream>
#include "Queue.h"

void Queue::enqueue(char val)
{
    Arr[enqueueIndex] = val;
    enqueueIndex++;
    enqueueIndex %= ARR_NUM;
}

char Queue::dequeue()
{
    if(dequeueIndex == enqueueIndex)
    {
        return 0;
    }
    char val = Arr[dequeueIndex];
    Arr[dequeueIndex] = 0;
    dequeueIndex++;
    dequeueIndex %= ARR_NUM;

    return val;
}

void Queue::output()
{
    int index = dequeueIndex;
    while(index != enqueueIndex)
    {
        std::cout << Arr[index];
        index++;
        index %= ARR_NUM;
    }
}