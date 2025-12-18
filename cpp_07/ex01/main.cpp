#include "iter.hpp"

int main()
{
    std::string tab[] = {"Hello", "World", "This", "Is", "CPP"};
    iter(tab, 5, func);
    return 0;
}