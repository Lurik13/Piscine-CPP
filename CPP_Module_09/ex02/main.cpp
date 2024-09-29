#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pmergeme(argc, argv);
		pmergeme.sort_numbers();
	}
	catch(const std::exception& e)
	{
		std::cerr << GREEN << e.what() << RESET "\n";
	}
	
}
