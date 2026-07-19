#include"MutantStack.hpp"
#include<deque>
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
    //test the deque as a default container of the stack 
    std::cout<<"deque test "<<std::endl;
    std::deque<int> deque;
    deque.push_back(5);
    deque.push_back(17);
    deque.pop_back();
    std::cout << deque.size() << std::endl;
    deque.push_back(3);
    deque.push_back(5);
    deque.push_back(737);
    deque.push_back(3);
    deque.push_back(0);
    std::deque<int>::iterator deque_it ;
    std::deque<int>::iterator deque_ite = deque.end();
    for(deque_it = deque.begin();deque_it != deque_ite;++deque_it)
    {
        std::cout<<*deque_it<<std::endl;
    }
    return 0;
}