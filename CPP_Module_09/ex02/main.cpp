#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pmergeme(argc, argv);
		pmergeme.sort_numbers();
	}
	catch(const std::exception& e)
	{
		std::cerr << GREEN << e.what() << '\n';
	}
	
}
