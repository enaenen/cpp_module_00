#include "PhoneBook.hpp"
#include <iostream>

Contact getContact(void) {
  std::cout << "First Name: ";
  std::string firstName;
  std::getline(std::cin, firstName);
  std::cout << "Last Name: ";
  std::string lastName;
  std::getline(std::cin, lastName);
  std::cout << "Nickname: ";
  std::string nickname;
  std::getline(std::cin, nickname);
  std::cout << "Phone Number: ";
  std::string phoneNumber;
  std::getline(std::cin, phoneNumber);
  std::cout << "Darkest Secret: ";
  std::string darkestSecret;
  std::getline(std::cin, darkestSecret);
  Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
  return contact;
}

static void string_to_uppercase(std::string& str){
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
		*it = std::toupper(*it);
}


int	main(void)
{
	PhoneBook	phoneBook;
	bool		run = true;

	while (run)
	{
		std::string cmd;
		std::cout << "----Enter Command----" << std::endl
		<< "|       ADD         |" << std::endl
		<< "|      SEARCH       |" << std::endl
		<< "|       EXIT        |" << std::endl
		<< "---------------------" << std::endl;
		if (std::getline(std::cin, cmd)){
			string_to_uppercase(cmd);
			if (cmd.compare("ADD") == 0) {
				Contact contact = getContact();
				phoneBook.updateContact(contact);
			}
			else if (cmd.compare("SEARCH") == 0){
				phoneBook.printPhoneBook();
			}
			else if (cmd.compare("EXIT") == 0)
				break;
			else
				std::cout << "Invalid Command " << std::endl;
		}
		else
			run = false;
}
	std::cout << "Program Ended!" << std::endl;
	return (0);

}