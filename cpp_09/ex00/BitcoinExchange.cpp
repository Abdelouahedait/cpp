#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other) {
        // Copy member variables here if there are any
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::loadData(const std::string& filename, std::map<std::string, double>& data)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open data file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate") {
        std::cerr << "Error: Invalid data file format." << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        if (line.length() < 3) continue;
        if (line[4] != '-' || line[7] != '-' || line.length() < 11 || line[10] != ',') {
            std::cerr << "Error: Invalid date format in data file." << std::endl;
            continue;
        }
        std::istringstream ss(line);
        std::string date;
        std::string rateStr;
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            try {
                double rate = std::strtod(rateStr.c_str(), NULL);
                data[date] = rate;
            } catch (const std::invalid_argument&) {
                std::cerr << "Error: Invalid exchange rate in data file." << std::endl;
            }
            // std::cout << "Loaded: " << date << " -> " << rateStr << std::endl;
        }
    }
    file.close();
}


void BitcoinExchange::processInput(const std::string& filename, const std::map<std::string, double>& _data_)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    if (line != "date | value") {
        std::cerr << "Error: Invalid input file format." << std::endl;
        return;
    }
    while(std::getline(file, line))
    {
        if (line.empty()) continue;
        size_t delimiterPos = line.find(" | ");
        if (delimiterPos == std::string::npos) {
            std::cerr << "Error: Invalid input line format." << std::endl;
            continue;
        }
        std::string date = line.substr(0, delimiterPos);
        std::string valueStr = line.substr(delimiterPos + 3);
        if (date.length() < 10 || date[4] != '-' || date[7] != '-' || date.length() != 10) {
            std::cerr << "Error: Invalid date format in input file." << std::endl;
            continue;
        }
        if (valueStr.empty()) {
            std::cerr << "Error: Missing value in input file." << std::endl;
            continue;
        }
        if (valueStr.find_first_not_of("0123456789.-") != std::string::npos) {
            std::cerr << "Error: Non-numeric value in input file." << std::endl;
            continue;
        }
        if (valueStr.find('-') != std::string::npos && valueStr.find('-') != 0) {
            std::cerr << "Error: Invalid negative value format in input file." << std::endl;
            continue;
        }
        if (valueStr.find('.') != std::string::npos) {
            size_t dotPos = valueStr.find('.');
            if (dotPos != std::string::npos && valueStr.substr(dotPos + 1).length() > 2) {
                std::cerr << "Error: Value has more than two decimal places in input file." << std::endl;
                continue;
            }
        }
        if (valueStr[0] == '-') {
            std::cerr << "Error: Negative value in input file." << std::endl;
            continue;
        }
        if (std::strtod(valueStr.c_str(), NULL) > 1000) {
            std::cerr << "Error: Value exceeds maximum limit in input file." << std::endl;
            continue;
        }
        try {
            double value = std::strtod(valueStr.c_str(), NULL);
            std::map<std::string, double>::const_iterator it = _data_.lower_bound(date);
            if (it == _data_.end() || it->first != date) {
                if (it != _data_.begin()) {
                    --it;
                } else {
                    std::cerr << "Error: No exchange rate available for date " << date << std::endl;
                    continue;
                }
            }
            double exchangeRate = it->second;
            double result = value * exchangeRate;
            std::cout << date << " => " << value << " = " << result << std::endl;
        } catch (const std::invalid_argument&) {
            std::cerr << "Error: Invalid value in input file." << std::endl;
        }
    }
    
    file.close();
}
    