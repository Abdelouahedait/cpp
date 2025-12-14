#include "ScalarConverter.hpp"
#include <typeinfo>

int main(int ac, char* av[])
{
    if (ac == 2 && isprint(av[1][0]))
    {
        
        ScalarConverter::convert(av[1]);
    }
    return 1;
}