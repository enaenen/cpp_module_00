#include <iostream>

#define MEGAPHONE_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv)
{
	std::string str;
	if (1 < argc)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string input(argv[i]);
			for (std::size_t j = 0; j < input.length(); j++)
				str += std::toupper(input[j]);
		}
	}
	else
		str = MEGAPHONE_MSG;
	std::cout << str << std::endl;

	return (0);
}
