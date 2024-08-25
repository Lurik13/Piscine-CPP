#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pmergeme(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << GREEN << e.what() << '\n';
	}
	
}
