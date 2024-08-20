#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>

#define BLUE "\e[38;2;0;150;250;1m"
#define RED "\e[38;2;170;0;0;1m\e[4m"
#define PURPLE "\e[38;2;200;70;250;1m"
#define RESET "\e[0m"

class Span
{
	public:
		Span(unsigned int n = 0);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void printUnsortedNumbers();
		void printSortedNumbers();
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	private:
		unsigned int _size;
		std::vector<int> _numbers;
		std::vector<int> _sortednumbers;
		void printNumbers(std::vector<int> numbers);
		void sortNumbers();
};
