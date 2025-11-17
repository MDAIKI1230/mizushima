#pragma once

class Queue
{
public:
    void enqueue(char val);
    char dequeue();
    void output();
private:
    static const int ARR_NUM = 10;
    char Arr[ARR_NUM];
    int enqueueIndex = 0;
    int dequeueIndex = 0;
};