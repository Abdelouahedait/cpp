#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <cstdlib>

#include <cerrno>
#include <limits>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        bool isValidDate(const std::string &date) const;
        bool isValidValue(const std::string &valueStr, float &value) const;
        void loadData(const std::string& filename, std::map<std::string, double>& data);
        void processInput(const std::string& filename, const std::map<std::string, double>& data);


};