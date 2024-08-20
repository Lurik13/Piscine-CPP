#include "Span.hpp"

Span::Span(unsigned int n): _size(n)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	this->_numbers = copy._numbers;
	this->_sortednumbers = copy._sortednumbers;
	this->_size = copy._size;
	return (*this);
}

Span::~Span()
{
}

void Span::sortNumbers()
{
	std::sort(this->_sortednumbers.begin(), this->_sortednumbers.end());
}

void Span::printNumbers(std::vector<int> numbers)
{
	std::vector<int>::iterator iter = numbers.begin();
	size_t i = 0;
	for (; iter != numbers.end(); ++iter)
	{
		if (i % 2 == 0)
		{
			std::cout << "\e[38;2;190;190;190;1m" << *iter << " ";
		}
		else
			std::cout << "\e[38;2;255;255;255;1m" << *iter << " ";
		i++;
	}
	std::cout << "\e[0m" << std::endl;
}

void Span::printUnsortedNumbers()
{
	printNumbers(this->_numbers);
}

void Span::printSortedNumbers()
{
	sortNumbers();
	printNumbers(this->_sortednumbers);
}

void Span::addNumber(int number)
{
	if (this->_size < this->_numbers.size() + 1)
		throw(std::runtime_error("The Span is full!"));
	this->_numbers.push_back(number);
	this->_sortednumbers.push_back(number);
}

int Span::shortestSpan()
{
	if (this->_numbers.size() <= 1)
		throw(std::runtime_error("I can't find any distance, there aren't enough numbers!"));
	sortNumbers();
	std::vector<int>::iterator iter = this->_sortednumbers.begin();
	int shortest_span = 2147483647;
	for (; iter != this->_sortednumbers.end() - 1; ++iter)
	{
		std::vector<int>::iterator temp = iter+1;
		if (*temp - *iter < shortest_span)
			shortest_span = *temp - *iter;
	}
	return (shortest_span);
}

int Span::longestSpan()
{
	if (this->_numbers.size() <= 1)
		throw(std::runtime_error("I can't find any distance, there aren't enough numbers!"));
	sortNumbers();
	std::vector<int>::iterator first = this->_sortednumbers.begin();
	std::vector<int>::iterator last = this->_sortednumbers.end() - 1;
	return (*last - *first);
}
