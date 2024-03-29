#include <iostream>
#include <string>

std::string	ft_to_upper(std::string str)
{
	for (int i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
	return (str);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; argv[i]; i++)
			std::cout << ft_to_upper(argv[i]);
		std::cout << std::endl;
	}
}
