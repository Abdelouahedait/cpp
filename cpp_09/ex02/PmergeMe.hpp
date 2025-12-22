#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <stdexcept>

void check_args(int ac, char **av);
void check_digits(const std::string& str);
double print_sort_vector(int size, char **str);


std::vector<int> Ford_Johnson_sort(const std::vector<int>& str)
{
    if (str.size() <= 1)
        return str;
    std::vector<int> kbir;
    std::vector<int> sgir;

    for (size_t i = 0; i < str.size(); i += 2)
    {
        if (i + 1 >= str.size())
            sgir.push_back(str[i]);
        else
        {
            if (str[i] <= str[i + 1])
            {
                sgir.push_back(str[i]);
                kbir.push_back(str[i + 1]);
            }
            else if(str[i] > str[i + 1])
            {
                kbir.push_back(str[i]);
                sgir.push_back(str[i + 1]);
            }
        }
    }
    kbir = Ford_Johnson_sort(kbir);

    for (size_t i = 0; i < sgir.size(); ++i)
    {
        std::vector<int>::iterator pos = std::lower_bound(kbir.begin(), kbir.end(), sgir[i]);
        kbir.insert(pos, sgir[i]);
    }
    return kbir;
}

double print_sort_vector(int size, char **str)
{
    std::vector<int> vect;
    std::vector<int> res;
    for (int i = 1; i < size; ++i)
        vect.push_back(std::atol(str[i]));
    clock_t start = clock();
    res = Ford_Johnson_sort(vect);
    clock_t end = clock();
    std::cout << "Before: ";
    for (size_t i = 1; i < vect.size() + 1; ++i)
        std::cout << str[i] << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < res.size(); ++i)
        std::cout << res[i] << " ";
    std::cout << std::endl;
    double time_taken = double(end - start) / CLOCKS_PER_SEC * 1000000;
    return time_taken;

}