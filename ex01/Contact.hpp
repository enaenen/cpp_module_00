#pragma once

#include <string>

class Contact {
 private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

 public:
  Contact(void);
  Contact(std::string firstName, std::string lastName, std::string nickname,
          std::string phoneNumber, std::string darkestSecret);
  std::string getFirstName(void);
  std::string getLastName(void);
  std::string getNickname(void);
  std::string getPhoneNumber(void);
  std::string getDarkestSecret(void);
  void setFirstName(std::string input);
  void setLastName(std::string input);
  void setNickname(std::string input);
  void setPhoneNumber(std::string input);
  void setDarkestSecret(std::string input);
};
