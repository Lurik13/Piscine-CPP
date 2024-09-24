#include "PmergeMe.hpp"

void PmergeMe::is_string_digit(char *str)
{
	for (int i = 0; str[i]; ++i)
		if (!isdigit(str[i]))
			throw (std::runtime_error( \
				std::string() + "'" H + str + GREEN "' isn't a positive integer."));
}

void PmergeMe::is_duplicate(char *str)
{
	dequeIt first = this->numbers_deque.begin();
	dequeIt last = this->numbers_deque.end();
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
		this->numbers_deque.push_back(atoi(argv[i]));
	}
	this->single_number = NO_SINGLE_NUMBER;
}
