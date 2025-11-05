#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "headar.hpp"
#include <string>
class PhoneBook
{
  private:
  Contact contacts[8];
  int count_cont;
  std::string ENTREE;
  public:
  PhoneBook();
  void searchContact();
};
#endif