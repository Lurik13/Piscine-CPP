#include "RPN.hpp"

RPN::RPN(int argc, char **argv)
{
	verif_params(argc, argv);
	polish_calculator();
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(const RPN &src)
{
	*this = src;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::verif_params(int argc, char **argv)
{
	if (argc != 2)
		throw(std::runtime_error("I want a mathematical expression in Polish notation 😒"));
	this->input = argv[1];
	std::string allowed_chars = "0123456789+-/* ";
	for (size_t i = 0; this->input[i]; ++i)
	{
		if (allowed_chars.find(this->input[i]) == std::string::npos)
			throw(std::runtime_error( \
				std::string() + "I refuse the '" + this->input[i] + "' symbol 😤"));
		if ((i % 2 == 1 && this->input[i] != ' ')
			|| (i % 2 == 0 && this->input[i] == ' '))
				throw(std::runtime_error("Wrong format 🤯"));
	}
}

void RPN::polish_calculator()
{
	std::istringstream ss(this->input);
	std::string string_char;
	char c;
	int tmp;

	while (ss >> string_char)
	{
		c = string_char.c_str()[0];
		if (isdigit(c))
			this->rpn_stack.push(c - 48);
		else
		{
			if (rpn_stack.size() < 2)
				throw (std::runtime_error("Not enough numbers in the stack."));
			tmp = this->rpn_stack.top();
			this->rpn_stack.pop();
			if (c == '+')
				this->rpn_stack.top() += tmp;
			else if (c == '-')
				this->rpn_stack.top() -= tmp;
			else if (c == '/')
				this->rpn_stack.top() /= tmp;
			else if (c == '*')
				this->rpn_stack.top() *= tmp;
		}
	}
	if (this->rpn_stack.size() != 1)
		throw (std::runtime_error("Not enough operators!"));
	std::cout << this->rpn_stack.top() << std::endl;
}
