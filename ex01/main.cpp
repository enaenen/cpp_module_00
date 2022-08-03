#include "PhoneBook.hpp"
#include <iostream>

static bool setContect(Contact &contact) 
{
  std::cout << "First Name: ";
  std::string firstName;
  if (!std::getline(std::cin, firstName))
	return false;
  contact.setFirstName(firstName);
  
  std::cout << "Last Name: ";
  std::string lastName;
  if (!std::getline(std::cin, lastName))
	return false;
  contact.setLastName(lastName);
  
  std::cout << "Nickname: ";
  std::string nickname;
  if (!std::getline(std::cin, nickname))
	return false;
  contact.setNickname(nickname);
  
  std::cout << "Phone Number: ";
  std::string phoneNumber;
  if (!std::getline(std::cin, phoneNumber))
	return false;
  contact.setPhoneNumber(phoneNumber);

  std::cout << "Darkest Secret: ";
  std::string darkestSecret;
  if (!std::getline(std::cin, darkestSecret))
	return false;
  contact.setDarkestSecret(darkestSecret); 
  return true;
}

static void string_to_uppercase(std::string& str)
{
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
		<< "|        ADD        |" << std::endl
		<< "|      SEARCH       |" << std::endl
		<< "|       EXIT        |" << std::endl
		<< "---------------------" << std::endl
		<< ">>";
		if (std::getline(std::cin, cmd))
		{
			string_to_uppercase(cmd);
			if (cmd.compare("ADD") == 0)
			{
				Contact contact = Contact();
				run = setContect(contact);
				std::cout << std::endl;
				phoneBook.updateContact(contact);
			}
			else if (cmd.compare("SEARCH") == 0)
				phoneBook.printPhoneBook();
			else if (cmd.compare("EXIT") == 0)
				break;
			else
				std::cout << "Invalid Command " << std::endl << std::endl;
		}
		else
			run = false;
	}
	std::cout << "Program Ended!" << std::endl;
	return (0);
}
