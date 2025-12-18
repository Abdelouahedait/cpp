#pragma once 

#include <iostream>

void func (const std::string x) 
{
    std::cout << x << std::endl;
}

template <typename T, typename F>
void iter(T* array, const size_t length, F func)
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    } 
}