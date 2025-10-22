#include <iostream>


int main (int ac, char **av)
{
    if (ac < 2)
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";//cout: is the object the type ostream // std is the srandar namespace =>>it's a way to groop related name like caribals or functions
    int i;
    int j;
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j]){
            if (av[i][j] >= 'a' && av[i][j] <= 'z')
                av[i][j]= std::toupper(av[i][j]);
            j++;
        }
        std :: cout << av[i] << " ";// operator<<	Insert string into stream
        i++;
    }
    std :: cout << "\n";
    return (0);
}