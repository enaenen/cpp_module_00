#include <iostream>

class TestClass {
 private:
  std::string name;
  int number;

 public:
  TestClass();
  ~TestClass();

  void setName(std::string name);
  std::string getName(void);
  void setNumber(int number);
  int getNumber(void);
};
/*
TestClass::TestClass() {
  std::cout << "Constructor Called" << std::endl;
  std::cout << name << std::endl;
  std::cout << number << std::endl;
};
*/
/*
TestClass::TestClass() : name("abcd"), number(123) {
  std::cout << "Constructor Called" << std::endl;
  std::cout << name << std::endl;
  std::cout << number << std::endl;
};
*/
TestClass::~TestClass(){};
std::string TestClass::getName() { return (this->name); };
void TestClass::setName(std::string name) { this->name = name; };
int TestClass::getNumber() { return (this->number); };
void TestClass::setNumber(int number) { this->number = number; };

int main() {
  TestClass tc;
  std::cout << tc.getName() << std::endl;
  std::cout << tc.getNumber() << std::endl;
}