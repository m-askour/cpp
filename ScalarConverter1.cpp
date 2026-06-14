#include"ScalarConverter1.hpp"
#include<limits>
void convert_chat(std::string literal,char c,int i, float f, double d)
{
    if(literal[0] < 0 || literal[0] > 127)
        throw std::out_of_range("out of range");
    else
        c = literal[0];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);
}
void convert_int(std::string literal, int i, float f, double d)
{
    long l = std::atol(literal.c_str());
    if(l > INT_MAX || l < INT_MIN)
        throw std::out_of_range("out of range");
    else
        i = std::atol(literal.c_str());
    d = static_cast<double>(i);
    f = static_cast<float>(i);
}
void convert_float(std::string literal, int i, float f, double d)
{
    f = std::atof(literal.c_str());
    if(std::isnan(f) || std::isinf(f))
        std::cout << "float: " << f << "f" << std::endl;
    else if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        throw std::out_of_range("out of range");
    d = static_cast<double>(f);
    i = static_cast<int>(f);
}
void convert_double(std::string literal, int i, float f, double d)
{
    d = std::atof(literal.c_str());
    if(std::isnan(d) || std::isinf(d))
        std::cout << "float: " << d << "f" << std::endl;
    else if (d == static_cast<int>(d))
        std::cout << "float: " << d << ".0f" << std::endl;
    else
        throw std::out_of_range("out of range");
    f = static_cast<float>(d);
    i = static_cast<int>(d);
}
int check_liter(std::string literal)
{
    int count_point = 0;
    int count_f;

    if(literal.empty())
        return 0;
    //it's char
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return 2;
    //it's just the param
    if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "-inf" ||
        literal == "+inff" || literal == "-inff")
        return 1;
    for(int i = 0; i < literal.size(); i++)
    {
        if (literal[i] == '.')
            count_point++;
        else if (literal[i] == 'f')
        {
            count_f++;
            if (i != literal.length() - 1) // 'f' must be last
                return 0;
        }
        else if (!std::isdigit(literal[i]) &&
                 !(i == 0 && (literal[i] == '+' || literal[i] == '-')))
            return 0;
    }
    if(count_point > 1 || count_f > 1)
        return 0;
    //it's float
    if(count_f == 1 )
        return 3;
    //it's double
    if(count_point == 1)
        return 4;
    //it's int
    return 5;
}
void ScalarConverter1::convert(std::string str)
{
    char c;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;


    //the first stipe is to know what is the type that string is bellow

    int type = check_liter(str);




    //convert the string to that actual type...



    //explicit cast to the other types
    //this is for later like nan nanf +inf -inf
        if(type == 1)
        {
                        std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;

            if (str.find('f') != std::string::npos)
            {
                std::cout << "float: " << str << std::endl;
                std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
            }
            else
            {
                std::cout << "float: " << str << "f" << std::endl;
                std::cout << "double: " << str << std::endl;
            }
            return;
        }
        else if(type == 2)
        {
            try
            {
                convert_chat(str,c, i,f, d);
            }
            catch(const std::exception& e)
            {
                std::cout << "char: impossible" << std::endl;
            }
            
        }
        else if(type == 3)//float
        {
            try
            {
                convert_float(str,i,f,d);
            }
            catch(const std::exception& e)
            {
                std::cout << "float: impossible" << std::endl;
            }
            
        }
        else if(type == 4)//double
        {
            try
            {
                convert_double(str, i,f,d);
            }

            catch(const std::exception& e)
            {
                std::cout << "double: impossible" << std::endl;
            }
            
        }
        else if(type == 5)//int
        {
            try
            {
                convert_int(str, i,f,d);
                /* code */
            }
            catch(const std::out_of_range& e)
            {
                
            }
            catch(const std::exception& e)
            {
                std::cout << "int: impossible" << std::endl;
            }
            
        }        
        else //nothign
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
    
}
