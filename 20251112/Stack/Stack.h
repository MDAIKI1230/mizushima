#pragma once

class Stack
{
public:
    void push(char val);
    char pop();
    void output();
private:
    static const int ARR_NUM = 50;
    int index = 0;
    char arr[ARR_NUM];
};