#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange() : exchangeRates(), value(0), Date("")
{
}
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
{
}
static int parsing_Date(std::string Data_stor)
{
    std::string year;
    std::string month;
    std::string day;
        //separat the month month day



        //convert string to int


        //convert it agine to string


        //set it to date
}
static int parsing_value(std::string Data_stor)
{
    //convert it from string to float 


    //check is it positive and form range 0->1000


    ///set it in value

}
static int parsing_line(std::string &line)
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
    {
        std::cout << "Error: bad input ." << std::endl;
        return 1;
    }
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
}
static int first_line(std::string line)
{
    if (line == "Date | value")
        return 1;
    return 0;
}
void BitcoinExchange::readFile(const std::string &filename)
{
    std::ifstream file(filename);
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
        // std::cout << line << std::endl;
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
    //convert strign to int 
    //year-month-days 
    //max year is 4 numbers 
    //max month is the 1->12
    //max days 1->31
    return Date;
}
float BitcoinExchange::get_value() const
{
    //the value chuld start from 0->1000 and not be negative
    return value;
}