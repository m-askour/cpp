
#ifndef CONTACT_H
#define CONTACT_H

#include "headar.hpp"
#include <string>

class Contact
{
  private:
  std::string firstName; // string it's an objetc the  class  string 
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
  public:
  void setContact();// this si the setter function 
  void displayBrief(int i);
  void displayFull();
  void clearat();
};

#endif