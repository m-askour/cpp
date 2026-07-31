#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange():exchangeRates()
{}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        exchangeRates = other.exchangeRates;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{}
void readFile(const std::string &filename)
{}
float BitcoinExchange::getExchangeRate(const std::string &date) const
{}