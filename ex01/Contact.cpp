#include "Contact.hpp"

Contact::Contact(void){};

 Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
 {
     this->firstName = firstName;
     this->lastName = lastName;
     this->nickname = nickname;
     this->phoneNumber = phoneNumber;
     this->darkestSecret = darkestSecret;
 };
 
 std::string Contact::getFirstName(void)
 {
     return firstName;
 }

 std::string Contact::getLastName(void)
 { 
     return lastName;
 }
 std::string Contact::getNickname(void)
 {
     return nickname;
 }

 std::string Contact::getPhoneNumber(void)
 {
     return phoneNumber;
 }
 std::string Contact::getDarkestSecret(void)
 {
     return darkestSecret;
 }  
 