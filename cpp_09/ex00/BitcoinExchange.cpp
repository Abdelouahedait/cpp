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

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.empty())
        return false;

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    
    char *endptr;
    
    long year = std::strtol(yearStr.c_str(), &endptr, 10);
    if (*endptr != '\0') return false;
    
    long month = std::strtol(monthStr.c_str(), &endptr, 10);
    if (*endptr != '\0') return false;
    
    long day = std::strtol(dayStr.c_str(), &endptr, 10);
    if (*endptr != '\0') return false;
    
    if (year < 2009 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    return true;
}
bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value) const
{
    if (valueStr.empty())
        return false;
    
    char *endptr;
    value = std::strtof(valueStr.c_str(), &endptr);
    
    
    if (*endptr != '\0')
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    if (value < 0.0f || value > 1000.0f)
    {
        if (value < 0.0f)
            std::cerr << "Error: not a positive number." << std::endl;
        else
            std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    
    return true;
}

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
    while (std::getline(file, line)) 
    {
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
        if (!isValidDate(date)) {
            std::cerr << "Error: Invalid date => " << date << std::endl;
            continue;
        }
        float value;
        if (!isValidValue(valueStr, value))
        {
            std::cout<< "Error: Invalid value => " << valueStr << std::endl;
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
    