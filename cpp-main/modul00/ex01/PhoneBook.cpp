#include "headar.hpp"

PhoneBook::PhoneBook() : count_cont(0){}

void PhoneBook::searchContact()
{
    while (true)
    {
        std::cout << "Type ADD, SEARCH or EXIT: ";
        
        if (std::getline(std::cin, ENTREE))
        {
            if (ENTREE == "ADD") 
            {
                if (count_cont < 8) 
                {
                    contacts[count_cont].setContact();
                    count_cont++;
                }
                else 
                {
                    contacts[0].clearat();
                    contacts[0].setContact();
                }
            }
            else if (ENTREE == "SEARCH") {
                int idx;
                if (count_cont == 0) 
                {
                    std::cout << "No contact.\n";
                    continue;
                }

                std::cout << "------------------------------------------------------------\n";
                std::cout << "|" << std::setw(10) << "Index"
                          << "|" << std::setw(10) << "First Name"
                          << "|" << std::setw(10) << "Last Name"
                          << "|" << std::setw(10) << "Nickname" << "|\n";
                std::cout << "------------------------------------------------------------\n";

                for (int i = 0; i < count_cont; i++)
                    contacts[i].displayBrief(i + 1);

                std::string input;
                std::cout << "Enter index (1-" << count_cont << "): ";
                std::getline(std::cin, input);

                idx = std::atoi(input.c_str()); 
                idx -= 1;
                std::cout << "Index entered: " << idx + 1 << "\n";

                if (idx >= 0 && idx < count_cont)
                    contacts[idx].displayFull();
                else
                    std::cout << "Invalid index. Please enter a valid number between 1 and " << count_cont << "\n";
            }
            else if (ENTREE == "EXIT")
                break;
            else
                std::cout << "Please type ADD, SEARCH, or EXIT.\n";
        } 
        else 
        {
            std::cout << "Error reading input.\n";
            break;
        }
    }
}

