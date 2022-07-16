#include <string>
#include <iostream>
#include <vector>

int main()
{
	std::string str;
	std::vector<std::string> v1;

	std::vector<std::string> v2;
	while (std::getline(std::cin, str, ' ')){
		v2.push_back(str);
	}
	std::cout <<"The following input was stored with whitespace as delimiter :" <<std::endl;
	for (const auto& p : v2)
		std::cout << p << std::endl;
	
}