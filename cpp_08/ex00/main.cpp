#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    for (int i = 0; i <= 10; ++i)
        vec.push_back(i);

    int v = 0;
    if (easyfind(vec, v))
    std::cout << "Value " << v << " found in vector." << std::endl;
    else
    std::cout << "Value " << v << " not found in vector." << std::endl;

    std::list<int> lst;
    for (int i = 5; i <= 15; ++i)
        lst.push_back(i);
    v = 3;
    if (easyfind(lst, v))
        std::cout << "Value " << v << " found in list." << std::endl;
    else
        std::cout << "Value " << v << " not found in list." << std::endl;

    return 0;
}