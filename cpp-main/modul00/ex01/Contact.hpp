
#ifndef CONTACT_H
#define CONTACT_H

#include "headar.hpp"
#include <string>
#include <cctype>
class Contact
{
  private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
  public:
  void setContact();
  void displayBrief(int i);
  void displayFull();
  void clearat();
};

#endif