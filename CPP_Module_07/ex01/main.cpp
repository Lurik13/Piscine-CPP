#include "iter.hpp"

int main( void )
{
	char text[] = "salut les amis";
	int numbers[] = {1, 2, 3, 4, 5, 6};

	iter(text, 15, ft_print);
	std::cout << std::endl;
	iter(numbers, 6, ft_print);
	std::cout << std::endl;
}
