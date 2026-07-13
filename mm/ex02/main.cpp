#include"MutantStack.hpp"
#include<list>
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(3);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    //test the list 
    std::cout<<"list test "<<std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(3);

    std::list<int>::iterator list_it ;
    std::list<int>::iterator list_ite = list.end();
    for(list_it = list.begin();list_it != list_ite;++list_it)
    {
        std::cout<<*list_it<<std::endl;
    }
    return 0;
}