#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		RPN rpn(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n';
	}
}
