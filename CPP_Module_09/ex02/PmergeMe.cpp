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

void PmergeMe::print_numbers(std::string str)
{
	std::cout << GOLD << str << RESET << std::endl;
	dequeIt it = this->numbers_deque.begin();
	int i = 0;
	for (; it != this->numbers_deque.end(); ++it)
	{
		if (i % 2 == 0)
			std::cout << "\e[38;2;190;190;190m" << *it << " ";
		else
			std::cout << "\e[38;2;255;255;255m" << *it << " ";
		++i;
	}
	std::cout << RESET << std::endl;
}

void PmergeMe::print_numbers_pair(const std::string &str, const dequePair &deq)
{
	std::cout << GOLD << str << RESET << std::endl;
	for (size_t i = 0; i < deq.size(); ++i)
	{
		std::cout << "\e[38;2;190;190;190m" << deq[i].first << " ";
		std::cout << "\e[38;2;255;255;255m" << deq[i].second << " ";
	}
	if (this->single_number != NO_SINGLE_NUMBER)
		std::cout << "\e[38;2;190;190;190m" << this->single_number;
	std::cout << RESET << std::endl;
}

dequeIt PmergeMe::next(dequeIt current)
{
	++current;
	return (current);
}
