#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <stack>
#include <sstream>

#define RED "\e[38;2;255;70;0;1m"

class RPN
{
	public:
		RPN(int argc = 0, char **argv = NULL);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		void polish_calculator();

	private:
		void verif_params(int argc, char **argv);
		
		std::string input;
		std::stack<long long> rpn_stack;
};
