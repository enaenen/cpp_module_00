#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX 8

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contact[MAX];
        int index;

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void add();
        void search();
};

#endif