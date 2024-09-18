#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	init_params(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	*this = src;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::is_string_digit(char *str)
{
	for (int i = 0; str[i]; ++i)
		if (!isdigit(str[i]))
			throw (std::runtime_error( \
				std::string() + "'" H + str + GREEN "' isn't a positive integer."));
}

void PmergeMe::is_duplicate(char *str)
{
	std::vector<int>::iterator first = this->numbers_vector.begin();
	std::vector<int>::iterator last = this->numbers_vector.end();
	if (std::find(first, last, atoi(str)) != last)
		throw (std::runtime_error( \
			std::string() + "There are several '" H + str + GREEN "' in the given parameters."));
}

void PmergeMe::init_params(int argc, char **argv)
{
	if (argc == 1)
		throw (std::runtime_error("Not enough parameters."));
	for (int i = 1; i < argc; ++i)
	{
		is_string_digit(argv[i]);
		is_duplicate(argv[i]);
		this->numbers_vector.push_back(atoi(argv[i]));
	}
	print_numbers("Before:");
	print_numbers("After:");
}

void PmergeMe::print_numbers(std::string str)
{
	std::cout << GOLD << str << RESET << std::endl;
	std::vector<int>::iterator it = this->numbers_vector.begin();
	int i = 0;
	for (; it != this->numbers_vector.end(); ++it)
	{
		if (i % 2 == 0)
			std::cout << "\e[38;2;190;190;190m" << *it << " ";
		else
			std::cout << "\e[38;2;255;255;255m" << *it << " ";
		++i;
	}
	std::cout << std::endl;
}
