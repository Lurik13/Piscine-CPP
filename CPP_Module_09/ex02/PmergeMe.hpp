#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <list>
#include <algorithm>
#include <iterator>
#include <deque>
#include <vector>
#include <time.h>
#include <iomanip>
#include <ctime>

#define GREEN RESET "\e[38;2;77;181;96;1m"
#define H RESET "\e[38;2;255;255;255;1;7m"
#define GOLD "\e[38;2;212;175;55;1;7m"
#define RESET "\e[0m"

#define NO_SINGLE_NUMBER 2147483648
typedef std::deque<int>::iterator dequeIt;
typedef std::deque< std::pair<int, int> > dequePair;

typedef std::vector<int>::iterator vectorIt;
typedef std::vector< std::pair<int, int> > vectorPair;

class PmergeMe
{
	public:
		PmergeMe(int argc = 0, char **argv = NULL);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		template<typename T>
		void print_numbers(T &container, std::string str);
		void sort_numbers();


	private:
		/* PmergeMe.cpp */
		template<typename iterator>
		iterator next(iterator current);

		/* Parsing.cpp */
		void is_string_digit(char *str);
		void is_duplicate(char *str);
		void init_params(int argc, char **argv);

		/* Deque.cpp */
		dequePair even_sort_deque();
		void merge_sort_deque(dequePair &deq, int left, int right);
		void merge_deque(dequePair &deq, int left, int mid, int right);
		void insert_sort_deque(dequePair &deq_pair);
		void insert_deque(int number);
		void print_numbers_pair_deque(const dequePair &deq, const std::string &str);

		/* Vector.cpp */
		vectorPair even_sort_vector();
		void merge_sort_vector(vectorPair &deq, int left, int right);
		void merge_vector(vectorPair &deq, int left, int mid, int right);
		void insert_sort_vector(vectorPair &deq_pair);
		void insert_vector(int number);
		void print_numbers_pair_vector(const vectorPair &vec, const std::string &str);


		/********* Variables *********/
		std::deque<int> numbers_deque;
		std::vector<int> numbers_vector;
		long long single_number_deque;
		long long single_number_vector;
};

// https://www.programiz.com/dsa/merge-sort
