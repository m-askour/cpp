#include "iter.hpp"
void print(const int &x)
{
    std::cout << x << std::endl;
}
void change(int &x)
{
    x++;
}
void print_str(const std::string &str)
{
    std::cout << str << std::endl;
}
void change_str(std::string &str)
{
   str += "s";
}
int main()
{
    std::cout << "array of numbers" << std::endl;
    //arrat test
    //this const
    const int array[] = {50,60,70};
    ::iter(array, 3, print);
    //this change
    int arr[] = {1,2,3};
    ::iter(arr,3,print);//const reference 
    std::cout << "this is for the non-const refrence" << std::endl;
    ::iter(arr,3,change);//non-const reference
    ::iter(arr,3,print);//const reference 
    //string test
    std::cout << "strings" << std::endl;
    
    //this is const
    std::string str[]  = {"name1", "name2", "name3"};
    ::iter(str, 3, print_str);
    std::cout << "this is for the non-const refrence" << std::endl;

    //this for change
    ::iter(str, 3, change_str);
    ::iter(str, 3, print_str);
}