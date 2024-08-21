#pragma once

#include <iostream>
#include <stack>
#include <list>

#define BLUE "\e[38;2;0;150;250;1m"
#define GOLD "\e[38;2;245;196;38;1m"
#define PURPLE "\e[38;2;200;70;250;1;4m"
#define TOP GOLD "╔═══════════════════════════════════════════════════════════════════╗" RESET "\n"
#define LEFT GOLD "║" RESET " " BLUE
#define RIGHT RESET " " GOLD "║"
#define MIDDLE GOLD "╠═══════════════════════════════════════════════════════════════════╣" RESET "\n"
#define BOTTOM GOLD "╚═══════════════════════════════════════════════════════════════════╝" RESET "\n"
#define EMPTY_LINE "                                                                 "
#define RESET "\e[0m"

template<typename T>
class MutantStack: public std::stack<T>
{

	public:
		MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &copy);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};