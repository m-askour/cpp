#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::string Date;
    float value;
    std::map<std::string, float> exchangeRates;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    
    void readFile(const std::string &filename);
    void loadDatabase(const std::string &filename);

    float getClosestRate(const std::string &date);
    void set_date(std::string data);
    std::string get_date() const;
    void set_value(float val);
    float get_value() const;

    int parsing_Date(std::string Data_stor);
    int parsing_line(std::string &line);
    int parsing_value(std::string Data_stor);
};
