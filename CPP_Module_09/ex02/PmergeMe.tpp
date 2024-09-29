#include "PmergeMe.hpp"

template<typename iterator>
iterator PmergeMe::next(iterator current)
{
    ++current;
    return (current);
}

template<typename T>
void PmergeMe::print_numbers(T &container, std::string str)
{
	std::cout << GOLD << str << RESET << std::endl;
	typename T::iterator it = container.begin();
	int i = 0;
	for (; it != container.end(); ++it)
	{
		if (i % 2 == 0)
			std::cout << "\e[38;2;190;190;190m" << *it << " ";
		else
			std::cout << "\e[38;2;255;255;255m" << *it << " ";
		++i;
	}
	std::cout << RESET << std::endl;
}
