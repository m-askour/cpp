#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange() : Date(""), value(0.0f), exchangeRates()
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
        value = other.value;
        Date = other.Date;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{
}
static int check_year(long year)
{
    if (year < 2009 || year > 2023)
        return 1;
    return 0;
}
static int check_month(long month)
{
    if (month < 1 || month > 12)
        return 1;
    return 0;
}
static int check_day(long day)
{
    if (day < 1 || day > 31)
        return 1;
    return 0;
} 
int check_all_int(const std::string &str)
{
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}
int check_all_float(const std::string &str)
{
    int dot_count = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '.')
        {
            dot_count++;
            if (dot_count > 1)
                return 1;
        }
        else if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}
int BitcoinExchange::parsing_Date(std::string Data_stor)
{
    std::string year;
    std::string month;
    std::string day;

    size_t first = Data_stor.find('-');
    size_t second = Data_stor.find('-', first + 1);

    if (first == std::string::npos || second == std::string::npos)
    {
        std::cout << "Error: bad input." << std::endl;
        return 1;
    }
    if(check_all_int(Data_stor.substr(0, first)) || check_all_int(Data_stor.substr(first + 1, second - first - 1)) || check_all_int(Data_stor.substr(second + 1)))
    {
        std::cout << "Error: bad input." << std::endl;
        return 1;
    }
    year = Data_stor.substr(0, first);
    month = Data_stor.substr(first + 1, second - first - 1);
    day = Data_stor.substr(second + 1);

    long year_int = std::atol(year.c_str());
    long month_int = std::atol(month.c_str());
    long day_int = std::atol(day.c_str());

    if (check_year(year_int) || check_month(month_int) || check_day(day_int))
    {
        std::cout << "Error: bad input." << std::endl;
        return 1;
    }

    set_date(Data_stor);

    return 0;
}
int BitcoinExchange::parsing_value(std::string Data_stor)
{
    //convert it from string to float 
    if(check_all_float(Data_stor))
    {
        std::cout << "Error: bad input." << std::endl;
        return 1;
    }
    double value_double = strtod(Data_stor.c_str(), NULL);
    float value_float = static_cast<float>(value_double);

    
    if (value_float < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 1;
    }

    if (value_float > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 1;
    }

    set_value(value_float);
    return 0;
}
int BitcoinExchange::parsing_line(std::string &line)
{ 
    std::string Date_stor;
    std::string value_stor;
    size_t find  = line.find('|');
    if (find == std::string::npos)
    {
        std::cout << "Error: bad input ." << std::endl;
        return 1;
    }
    // we have date befor the separation
    Date_stor = line.substr(0, find);
    //remove spaces from the Date
    size_t last = Date_stor.find_last_not_of(" \t");
    if (last != std::string::npos)
        Date_stor = Date_stor.substr(0, last + 1);
    if(parsing_Date(Date_stor))
        return 1;
    // we have the value after we finde the siparation
    value_stor = line.substr(find + 1);
    //remove spaces from the value
    size_t first = value_stor.find_first_not_of(" \t");
    if (first != std::string::npos)
        value_stor = value_stor.substr(first);
    if(parsing_value(value_stor))
    {
        std::cout << "Error: bad input ." << std::endl;
        return 1;
    }
    return 0;
}
static int first_line(std::string line)
{
    if (line == "date | value")
        return 1;
    return 0;
}
void BitcoinExchange::readFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::string line;
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    if (!std::getline(file, line))
    {
        std::cout << "Error: file is empty." << std::endl;
        return;
    }
    if(!first_line(line))
    {
        std::cout << "Error: Invalid headar" << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
        // std::cout << line << std::endl;if (line == "Date | value")
        if (parsing_line(line))
            continue;
        // sepatation the part's to put it in the map line by line and separat the value
        // key1 = Date;
        // separation |
        std::string Date = get_date();
        float value = get_value();
        // key 2 = value
        exchangeRates[Date] = value;
    }
    std::map<std::string, float>::iterator it;
    for (it = exchangeRates.begin(); it != exchangeRates.end(); it++)
        std::cout << it->first << "=>" << it->second << std::endl;
}
void BitcoinExchange::set_date(std::string data) 
{
    this->Date = data;
}
void BitcoinExchange::set_value(float val) 
{
    this->value = val;
}
std::string BitcoinExchange::get_date()const
{
    return Date;
}
float BitcoinExchange::get_value() const
{
    return value;
}