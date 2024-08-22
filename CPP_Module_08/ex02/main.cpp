#include "MutantStack.hpp"
#include "MutantStack.tpp"

void responsiveness(int spaces)
{
	for (int i = 0; i < spaces; ++i)
		std::cout << " ";
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << ERROR "I need \e[7mtput cols" RESET ERROR "!" << std::endl;
		return (EXIT_FAILURE);
	}
	int responsive_spaces = (atoi(argv[1]) - 63) / 2;
	
	{
		responsiveness(responsive_spaces);
		std::cout << TOP;
		responsiveness(responsive_spaces);
		std::cout << LEFT "                " PURPLE "Tests with our MutantStack:" RESET
		<< "                  " RIGHT << std::endl;
		responsiveness(responsive_spaces);
		std::cout << LEFT EMPTY_LINE RIGHT << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		responsiveness(responsive_spaces);
		std::cout << LEFT "Top value after pushing 5 and 17: " RESET
		<< mstack.top() << "                         " RIGHT << std::endl;

		mstack.pop();
		responsiveness(responsive_spaces);
		std::cout << LEFT "Stack size after removing the top value: " RESET
		<< mstack.size() << "                   " RIGHT << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		responsiveness(responsive_spaces);
		std::cout << LEFT EMPTY_LINE RIGHT << std::endl;
		responsiveness(responsive_spaces);
		std::cout << LEFT "We stack 4 other values.                                     " << RIGHT << std::endl;

		responsiveness(responsive_spaces);
		std::cout << LEFT "Displaying the stack using our iterator: " RESET;
		MutantStack<int>::iterator first = mstack.begin();
		MutantStack<int>::iterator last = mstack.end();
		++first;
		--first;
		while (first != last)
		{
			std::cout << *first;
			++first;
			if (first != last)
				std::cout << "; ";
		}
		std::cout << "     " RIGHT << std::endl;
		responsiveness(responsive_spaces);
		std::cout << MIDDLE;
	}
	{
		responsiveness(responsive_spaces);
		std::cout << LEFT "                     " PURPLE "Tests with a list:" RESET
		<< "                      " RIGHT << std::endl;
		responsiveness(responsive_spaces);
		std::cout << LEFT EMPTY_LINE RIGHT << std::endl;

		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		responsiveness(responsive_spaces);
		std::cout << LEFT "Top value after pushing 5 and 17: " RESET
		<< mlist.back() << "                         " RIGHT << std::endl;

		mlist.pop_back();
		responsiveness(responsive_spaces);
		std::cout << LEFT "Stack size after removing the top value: " RESET
		<< mlist.size() << "                   " RIGHT << std::endl;
		
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		responsiveness(responsive_spaces);
		std::cout << LEFT EMPTY_LINE RIGHT << std::endl;
		responsiveness(responsive_spaces);
		std::cout << LEFT "We stack 4 other values.                                     " << RIGHT << std::endl;

		responsiveness(responsive_spaces);
		std::cout << LEFT "Displaying the stack using the list iterator: " RESET;
		int size = mlist.size();
		while (size)
		{
			std::cout << mlist.front();
			mlist.pop_front();
			size--;
			if (size)
				std::cout << "; ";
		}
		std::cout << RIGHT << std::endl;
		responsiveness(responsive_spaces);
		std::cout << BOTTOM;
	}
	return 0;
}

