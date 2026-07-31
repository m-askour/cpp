#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
class BitcoinExchange
{
private:
    std::map<std::string, float> exchangeRates;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    void readFile(const std::string &filename);
    float getExchangeRate(const std::string &date) const;
};
