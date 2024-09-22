#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <list>
#include <algorithm>
#include <iterator>
#include <deque>

#define GREEN RESET "\e[38;2;77;181;96;1m"
#define H RESET "\e[38;2;255;255;255;1;7m"
#define GOLD "\e[38;2;212;175;55;1;7m"
#define RESET "\e[0m"

typedef std::deque<int>::iterator dequeIt;

class PmergeMe
{
	public:
		PmergeMe(int argc = 0, char **argv = NULL);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void print_numbers(std::string str);
		void sort_numbers();
		void even_sort_deque();
		void merge_sort(std::deque<int> &deq, int left, int right);
		void merge(std::deque<int> &deq, int left, int mid, int right);

	private:
		/* PmergeMe.cpp */
		dequeIt next(dequeIt current);

		/* Parsing.cpp */
		void is_string_digit(char *str);
		void is_duplicate(char *str);
		void init_params(int argc, char **argv);

		/* Sort.cpp */

		std::deque<int> numbers_deque;
};

// https://www.programiz.com/dsa/merge-sort
