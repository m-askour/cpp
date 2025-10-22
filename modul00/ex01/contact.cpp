#include "headar.hpp"

void Contact::clearat()
{
    lastName.clear();
    nickname.clear();
    phoneNumber.clear();
    darkestSecret.clear();
}

void  Contact::setContact()
{
    while (firstName.empty())
    {
    std::cout << "first name: ";
    if (getline(std::cin, firstName))
    {
     if (firstName.empty())
        std::cout << "put the first name" << "\n";  
    }
    else
        exit(1);
    }
    while (lastName.empty())
    {
        std::cout << "last name: ";
        if (getline(std::cin, lastName))
        {
            if (lastName.empty())
            std::cout << "put the last name" << "\n";  
        }
        else
            exit(1);
    }
    while (nickname.empty())
    {
        std::cout<<"nicname: ";
        if (getline(std::cin, nickname))
        {
            if (nickname.empty())
                std::cout << "put the nicname" << "\n";  
        }
        else
            exit(1);

    }
    while (phoneNumber.empty())
    {
        std::cout << "Phone number: ";
        if (getline(std::cin, phoneNumber))
        {
        bool valid = true;

        for (size_t i = 0; i < phoneNumber.length(); i++)
        {
            if (!std::isdigit(static_cast<unsigned char>(phoneNumber[i])))
            {
                valid = false;
                break;
            }
        }

        if (phoneNumber.empty() || !valid)
        {
            std::cout << "Please enter a valid numeric phone number.\n";
            phoneNumber.clear();
        }
        }
        else
            exit(1);
    }
    while(darkestSecret.empty())
    {
        std::cout <<"darkestSecret: ";
        if (getline(std::cin, darkestSecret))
        {
            if (darkestSecret.empty())
            std::cout << "put the darkestSecret" << "\n";
        }
        else
            exit(1);  
    }
}

void Contact::displayBrief(int i)
{
        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        if(nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";
        std::cout << "|" << std::setw(10) << i
          << "|" << std::setw(10) << firstName
          << "|" << std::setw(10) << lastName
          << "|" << std::setw(10) << nickname << "|\n";
        std::cout << "------------------------------------------------------------\n";
}

void Contact::displayFull()
{
        std::cout << std::setw(10) << "firstName :" << firstName << "\n"
              << std::setw(10) << "lastName :" << lastName << "\n"
              << std::setw(10) <<  "nickname :"<<nickname << "\n"
              << std::setw(10) << "phoneNumber :" <<phoneNumber << "\n"
              << std::setw(10) << "darkestSecret :"<< darkestSecret << "\n";
}
