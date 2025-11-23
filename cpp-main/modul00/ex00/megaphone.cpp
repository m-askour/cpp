#include <iostream>
#include <string>
int main (int ac, char **av)
{
    if (ac < 2)
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    int i;
    int j;
    i = 1;
    while (av[i])
    {
        std::string str = av[i]; 
        j = 0;
        while (str[j]){
            if (str[j] >= 'a' && str[j] <= 'z')
                str[j]= std::toupper(str[j]);
            j++;
        }
        std :: cout << str;
        i++;
    }
    std :: cout << "\n";
    return (0);
}
