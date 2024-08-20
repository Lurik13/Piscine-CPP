#include "Span.hpp"

int main (void)
{
	std::cout << "\n\n\n------------------------------------\n\n\n\n";

	try
	{
		Span span(5);
		for (int i = 0; i < 6; ++i)
			span.addNumber(rand() % 1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[38;2;170;0;0;1m\e[4m" << e.what() << "\e[0m\n";
	}

	std::cout << "\n\n\n------------------------------------\n\n\n\n";

	try
	{
		srand(time(0));
		int span_size = 5 + (rand() % 13000 - 5);
		Span span(span_size);
		for (int i = 0; i < span_size; ++i)
			span.addNumber(rand() % 13000);
		span.printUnsortedNumbers();
		std::cout << "\e[38;2;0;150;250;1mShortest span: \e[0m" << span.shortestSpan() << std::endl;
		std::cout << "\e[38;2;0;150;250;1mLongest span: \e[0m" << span.longestSpan() << std::endl;
		// span.printSortedNumbers();
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[38;2;170;0;0;1m" << e.what() << "\e[0m\n";
	}

	std::cout << "\n\n\n------------------------------------\n\n\n\n";

	try
	{
		Span span(5);
		span.addNumber(63);
		span.addNumber(1);
		span.addNumber(13);
		span.addNumber(42);
		span.addNumber(4);
		span.printSortedNumbers();
		std::cout << "\e[38;2;0;150;250;1mShortest span: \e[0m" << span.shortestSpan() << std::endl;
		std::cout << "\e[38;2;0;150;250;1mLongest span: \e[0m" << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[38;2;170;0;0;1m" << e.what() << "\e[0m\n";
	}

	std::cout << "\n\n\n------------------------------------\n\n\n\n";

	try
	{
		Span span(1);
		span.addNumber(rand() % 1000);
		span.printUnsortedNumbers();
		std::cout << "\e[38;2;0;150;250;1mShortest span: \e[0m" << span.shortestSpan() << std::endl;
		std::cout << "\e[38;2;0;150;250;1mLongest span: \e[0m" << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[38;2;170;0;0;1m\e[4m" << e.what() << "\e[0m\n";
	}
	
	std::cout << "\n\n\n------------------------------------\n\n\n\n";
}
