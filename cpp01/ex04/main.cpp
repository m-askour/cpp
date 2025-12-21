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
    if (search_name.empty())
    {
        std::cout <<"Error: search string is empty\n";
        return 1;
    }
    std::ifstream input(input_name.c_str());

    if (!input.is_open())
    {
        std::cout<< "erro can open file";
        return (1);
    }
    std::string output_file = input_name + ".replace";
    std::ofstream output(output_file.c_str());
    while (std::getline(input,str))
    {
        
        for(size_t pos = str.find(search_name);pos != std::string::npos;
        pos = str.find(search_name, pos))
        {
            str.erase(pos, search_name.length());
            str.insert(pos, replace_name);
            pos += replace_name.length();
        }
        output << str << "\n";
    }
    input.close();
    output.close();
    return (0);
}