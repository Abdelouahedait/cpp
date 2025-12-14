#pragma once 

#include <iostream>

void func (const int &x)
{
    std::cout << x << std::endl;
}

template <typename T>
void iter(T* array, const size_t length, void (*func)(T const &))
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    } 
}