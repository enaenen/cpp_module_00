#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook(void) { index = 0; }

PhoneBook::~PhoneBook(void) {
  std::cout << "Destroy PhoneBook..." << std::endl;
}

static std::string getStringShort(std::string str) {
  if (10 < str.length()) {
    str = str.substr(0, 9);
    str += ".";
  }
  return (str);
}

static void printTableRow(void) {
  std::cout << '|' << std::setw(10) << std::right << "index" << '|'
            << std::setw(10) << "First Name" << '|' << std::setw(10)
            << "Last Name" << '|' << std::setw(10) << "Nickname" << '|'
            << std::endl;
}

static void printTableRow(int index, Contact contact) {
  std::cout << '|' << std::setw(10) << std::right << index + 1 << '|'
            << std::setw(10) << getStringShort(contact.getFirstName()) << '|'
            << std::setw(10) << getStringShort(contact.getLastName()) << '|'
            << std::setw(10) << getStringShort(contact.getNickname()) << '|'
            << std::endl;
}

void PhoneBook::printPhoneBook(void) {
  int max = (index < MAX) ? index : MAX;
  printTableRow();
  for (int i = 0; i < max; i++) printTableRow(i, contact[i]);
  std::cout << "[SEARCH] Enter index : ";
  std::string cmd;
  std::getline(std::cin, cmd);
  if (cmd.empty()) {
    std::cout << "Invalid index" << std::endl << std::endl;
    return;
  }
  if (1 < cmd.size() || cmd[0] < '1' || '8' < cmd[0])
    std::cout << "Invalid index" << std::endl << std::endl;
  else {
    int index = cmd[0] - '0' - 1;
    if (max <= index)
      std::cout << "Invalid index" << std::endl << std::endl;
    else {
      std::cout << "First Name: " << contact[index].getFirstName() << std::endl;
      std::cout << "Last Name: " << contact[index].getLastName() << std::endl;
      std::cout << "Nickname: " << contact[index].getNickname() << std::endl;
      std::cout << "Phone Number: " << contact[index].getPhoneNumber()
                << std::endl;
      std::cout << "Darkest Secret: " << contact[index].getDarkestSecret()
                << std::endl;
    }
  }
  return;
}

void PhoneBook::updateContact(const Contact& newContact) {
  contact[index % MAX] = newContact;
  index += 1;
  if (MAX * 2 <= index) index -= 8;
}
