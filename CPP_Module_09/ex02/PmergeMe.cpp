#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

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

void PmergeMe::sort_numbers()
{
	print_numbers(this->numbers_deque, "Before:");

	std::clock_t begin_time_deque = std::clock();
	dequePair numbers_deque_pair = even_sort_deque();
	// print_numbers(this->numbers_deque, "Even sort:");
	merge_sort_deque(numbers_deque_pair, 0, numbers_deque_pair.size() - 1);
	// print_numbers_pair_deque(numbers_deque_pair, "Merge sort:");
	this->numbers_deque.clear();
	insert_sort_deque(numbers_deque_pair);
	std::clock_t end_time_deque = std::clock();

	std::clock_t begin_time_vector = std::clock();
	vectorPair numbers_vector_pair = even_sort_vector();
	// print_numbers_pair_vector(numbers_vector_pair, "Even sort:");
	merge_sort_vector(numbers_vector_pair, 0, numbers_vector_pair.size() - 1);
	// print_numbers_pair_vector(numbers_vector_pair, "Merge sort:");
	this->numbers_vector.clear();
	insert_sort_vector(numbers_vector_pair);
	std::clock_t end_time_vector = std::clock();

	// print_numbers(this->numbers_deque, "After:");
	print_numbers(this->numbers_vector, "After:");
	double elapsed_time_deque = 1000000.0 * (end_time_deque - begin_time_deque) / CLOCKS_PER_SEC;
	std::cout << "\e[38;2;170;50;130;1m" << "Time to process a range of "
	<< this->numbers_deque.size() << " elements with std::deque : " << std::fixed
	<< std::setprecision(2) << elapsed_time_deque << "us" RESET << std::endl;

	double elapsed_time_vector = 1000000.0 * (end_time_vector - begin_time_vector) / CLOCKS_PER_SEC;
	std::cout << "\e[38;2;170;50;130;1m" << "Time to process a range of "
	<< this->numbers_vector.size() << " elements with std::vector : " << std::fixed
	<< std::setprecision(2) << elapsed_time_vector << "us" RESET << std::endl;
}

// 12 5 101 2 21 42 0
