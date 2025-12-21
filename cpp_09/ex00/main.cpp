#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 3)
    {
        BitcoinExchange btc;
        std::map<std::string, double> data;
        btc.loadData(av[1], data);
        btc.processInput(av[2], data);  
    }
    return 0;
}