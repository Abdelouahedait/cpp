#include "PmergeMe.hpp"

void check_digits(const std::string& str) {
    if (str.empty())
        throw std::invalid_argument("Error: Empty argument found");
    if (str.find_first_not_of("0123456789") != std::string::npos)
        throw std::invalid_argument("Error: Non-digit character found");
    if (str.length() > 10 || (str.length() == 10 && str > "2147483647"))
        throw std::out_of_range("Error: Integer value out of range");
    if (str[0] == '0' && str.length() > 1)
        throw std::invalid_argument("Error: Leading zeros are not allowed");
    if (str.length() == 1 && str[0] == '0')
        throw std::invalid_argument("Error: Zero is not allowed");
}

void check_args(int ac, char **av)
{
    if (ac < 2)
        throw std::invalid_argument("Error: Not enough arguments.");
    for (int i = 1; i < ac; ++i)
            check_digits(av[i]);
}

std::vector<size_t> jacobsthal_sequence_vector(size_t n)
{
    std::vector<size_t> j;

    j.push_back(1);
    j.push_back(3);
    while(j.size() < n)
    {
        j.push_back(j[j.size() - 1] + 2 * j[j.size() - 2]);
    }
    return j;
}


std::vector<int> Ford_Johnson_sort(const std::vector<int>& str)
{
    if (str.size() <= 1)
        return str;
    //1
    std::vector<int> main_chain; //kbir
    std::vector<int> pending;       //sgir

    for (size_t i = 0; i + 1 < str.size(); i += 2)
    {
        if (str[i] < str[i + 1])
        {
            pending.push_back(str[i]);
            main_chain.push_back(str[i + 1]);
        }
        else
        {
            main_chain.push_back(str[i]);
            pending.push_back(str[i + 1]);
        }
    }
    if (str.size() % 2 != 0)
        pending.push_back(str.back());
    //2   
    main_chain = Ford_Johnson_sort(main_chain);
    //3
    std::vector<size_t> jac = jacobsthal_sequence_vector(pending.size());
    size_t inserted = 0;
    for (size_t i = 1; i < jac.size(); ++i)
    {
        while (inserted < jac[i] && inserted < pending.size())
        {
            int val = pending[inserted];
            std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
            main_chain.insert(pos, val);
            ++inserted;
        }
    }
    return main_chain;
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
    if (vect.size() > 10)
    {
        for (size_t i = 0; i < 5; ++i)
            std::cout << vect[i] << " ";
        std::cout << "[...] ";
        for (size_t i = vect.size() - 5; i < vect.size(); ++i)
            std::cout << vect[i] << " ";
        std::cout << std::endl;
    }
    else
    {
        for (size_t i = 0; i < vect.size(); ++i)
            std::cout << vect[i] << " ";
        std::cout << std::endl;
    }

    std::cout << "After: ";
    if (res.size() > 10)
    {
        for (size_t i = 0; i < 5; ++i)
            std::cout << res[i] << " ";
        std::cout << "[...] ";
        for (size_t i = res.size() - 5; i < res.size(); ++i)
            std::cout << res[i] << " ";
        std::cout << std::endl;
    }
    else
    {
        for (size_t i = 0; i < res.size(); ++i)
            std::cout << res[i] << " ";
        std::cout << std::endl;
    }
    double time_taken = double(end - start) / CLOCKS_PER_SEC * 1000000;
    return time_taken;
}



std::deque<size_t>jacobsthal_sequence_deque(size_t n)
{
    std::deque<size_t> j;

    j.push_back(1);
    j.push_back(3);
    while(j.size() < n)
    {
        j.push_back(j[j.size() - 1] + 2 * j[j.size() - 2]);
    }
    return j;
}



std::deque<int> Ford_Johnson_sort(const std::deque<int>& str)
{
    if (str.size() <= 1)
        return str;
    std::deque<int> main_chain; //kbir
    std::deque<int> pending;       //sgir

    for (size_t i = 0; i + 1 < str.size(); i += 2)
    {
        if (str[i] < str[i + 1])
        {
            pending.push_back(str[i]);
            main_chain.push_back(str[i + 1]);
        }
        else
        {
            main_chain.push_back(str[i]);
            pending.push_back(str[i + 1]);
        }
    }
    if (str.size() % 2 != 0)
        pending.push_back(str.back());
        
    main_chain = Ford_Johnson_sort(main_chain);

    std::deque<size_t> jac = jacobsthal_sequence_deque(pending.size());
    size_t inserted = 0;
    for (size_t i = 1; i < jac.size(); ++i)
    {
        while (inserted < jac[i] && inserted < pending.size())
        {
            int val = pending[inserted];
            std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
            main_chain.insert(pos, val);
            ++inserted;
        }
    }
    return main_chain;
}

double print_sort_deque(int size, char **str)
{
    std::deque<int> vect;
    std::deque<int> res;
    for (int i = 1; i < size; ++i)
    vect.push_back(std::atol(str[i]));
    
    clock_t start = clock();
    res = Ford_Johnson_sort(vect);
    clock_t end = clock();

    // std::cout << "Before: ";
    // for (size_t i = 1; i < vect.size() + 1; ++i)
    //     std::cout << str[i] << " ";
    // std::cout << std::endl;

    // std::cout << "After: ";
    // if (res.size() > 10)
    // {
    //     for (size_t i = 0; i < 5; ++i)
    //         std::cout << res[i] << " ";
    //     std::cout << "[...] ";
    //     for (size_t i = res.size() - 5; i < res.size(); ++i)
    //         std::cout << res[i] << " ";
    //     std::cout << std::endl;
    // }
    // else
    // {
    //     for (size_t i = 0; i < res.size(); ++i)
    //         std::cout << res[i] << " ";
    //     std::cout << std::endl;
    // }
    double time_taken = double(end - start) / CLOCKS_PER_SEC * 1000000;
    return time_taken;
}