#pragma once

#include <iostream>
#include <string>

typedef unsigned long uintptr_t;

struct Data
{
    int         n;
    std::string str;
};

class Serializ
{
    public:
        Serializ();
        Serializ(const Serializ &other);
        Serializ& operator=(const Serializ &other);
        ~Serializ();

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};