#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>

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

	private:
		unsigned int _size;
		std::vector<int> _numbers;
		std::vector<int> _sortednumbers;
		void printNumbers(std::vector<int> numbers);
		void sortNumbers();
};
