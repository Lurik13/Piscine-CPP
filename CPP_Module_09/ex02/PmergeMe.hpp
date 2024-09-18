#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>

#define GREEN RESET "\e[38;2;77;181;96;1m"
#define H RESET "\e[38;2;255;255;255;1;7m"
#define GOLD "\e[38;2;212;175;55;1;7m"
#define RESET "\e[0m"

class PmergeMe
{
	public:
		PmergeMe(int argc = 0, char **argv = NULL);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

	private:
		void is_string_digit(char *str);
		void is_duplicate(char *str);
		void init_params(int argc, char **argv);
		void print_numbers(std::string str);

		std::vector<int> numbers_vector;
};
