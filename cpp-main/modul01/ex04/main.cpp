
#include <iostream>
#include <string>
#include <fstream>
int main (int ac,char **av)
{

    if (ac != 4)
    {
        std::cout<<"some param are forget\n";
        return (1);
    }
    std::string str;
    std::string input_name = av[1];
    std::string search_name = av[2];
    std::string replace_name = av[3];
    std::ifstream input(input_name.c_str());
    std::string output_file = input_name + ".replace";
    std::ofstream output(output_file.c_str());
    if (!input.is_open())
    {
        std::cout<< "erro can open file";
        return (1);
    }
    while (std::getline(input,str))
    {
        size_t pos = str.find(search_name);
        if (pos != std::string::npos)
        {
            str.erase(pos, search_name.length());
            str.insert(pos, replace_name);
        }
        output << str << "\n";
        std::cout << str << "\n";
    }
    input.close();
    output.close();
    return (0);
}