#include "Span.hpp"

int main (void)
{
	std::cout << "\n\n\n------------------------------------\n\n\n\n";

	try
	{
		std::cout << PURPLE "Exception when adding an extra number:\n\n\n";

		Span span(5);
		for (int i = 0; i < 6; ++i)
			span.addNumber(rand() % 1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET "\n";
	}

	std::cout << "\n\n\n------------------------------------\n\n\n\n";

	try
	{
		std::cout << PURPLE "Shortest and longest span tests for a large random number of stored integers:\n\n\n";

		srand(time(0));
		int span_size = 5 + (rand() % 13000 - 5);
		Span span(span_size);
		for (int i = 0; i < span_size; ++i)
			span.addNumber(rand() % 13000);
		span.printUnsortedNumbers();
		std::cout << "\n" BLUE "Shortest span: " RESET << span.shortestSpan() << std::endl;
		std::cout << BLUE "Longest span: " RESET << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET "\n";
	}

	std::cout << "\n\n\n------------------------------------\n\n\n\n";

	try
	{
		std::cout << PURPLE "Shortest and longest span tests for a small definite number of stored and sorted integers:\n\n\n";

		Span span(5);
		span.addNumber(63);
		span.addNumber(1);
		span.addNumber(13);
		span.addNumber(42);
		span.addNumber(4);
		span.printSortedNumbers();
		std::cout << "\n" BLUE "Shortest span: " RESET << span.shortestSpan() << std::endl;
		std::cout << BLUE "Longest span: " RESET << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET "\n";
	}

	std::cout << "\n\n\n------------------------------------\n\n\n\n";

	try
	{
		std::cout << PURPLE "Exception when there are not enough numbers:\n\n\n";

		Span span(1);
		span.addNumber(rand() % 1000);
		span.printUnsortedNumbers();
		std::cout << "\n" BLUE "Shortest span: " RESET << span.shortestSpan() << std::endl;
		std::cout << BLUE "Longest span: " RESET << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET "\n";
	}
	
	std::cout << "\n\n\n------------------------------------\n\n\n\n";

	try
	{
		std::cout << PURPLE "Copying an external vector using a range of iterators:\n\n\n";

		std::vector<int> to_copy;
		to_copy.push_back(5);
		to_copy.push_back(8);
		to_copy.push_back(13);
		to_copy.push_back(98);
		to_copy.push_back(26);
		to_copy.push_back(17);
		Span span(6);
		span.addRange(to_copy.begin(), to_copy.end());
		span.printUnsortedNumbers();
		std::cout << "\n" BLUE "Shortest span: " RESET << span.shortestSpan() << std::endl;
		std::cout << BLUE "Longest span: " RESET << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET "\n";
	}

	std::cout << "\n\n\n------------------------------------\n\n\n\n";
}
