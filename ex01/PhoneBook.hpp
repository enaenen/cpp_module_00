#pragma once

#define MAX 8

#include <string>

#include "Contact.hpp"

class PhoneBook {
    private:
        int index;
        Contact contact[MAX];

    public:
        PhoneBook(void);
        ~PhoneBook(void);
		void	updateContact(const Contact &contact);
		bool	printPhoneBook(void);
};
