/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:49:25 by lribette          #+#    #+#             */
/*   Updated: 2024/07/25 11:19:49 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool nan(const std::string str)
{
	std::string numbers = "0123456789";
	unsigned long i = str.find_first_not_of(numbers, 0);
	int number_of_dots = 0;

	while (i != std::string::npos)
	{
		if (str[i] == '.')
		{
			if (number_of_dots != 0)
				return (EXIT_FAILURE);
			number_of_dots = 1;
			if (i + 1 == str.size() || numbers.find(str[i + 1]) == std::string::npos)
				return (EXIT_FAILURE);
		}
		else if (str[i] == 'f')
		{
			if (number_of_dots == 0 || i + 1 != str.size())
				return (EXIT_FAILURE);
		}
		else
			return(EXIT_FAILURE);
		i = str.find_first_not_of(numbers, i + 1);
	}
	return (EXIT_SUCCESS);
}

bool special(const std::string str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff"
		|| str == "-inf" || str == "-inff" || str == "inf" || str == "inff")
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	ScalarConverter::convert(const std::string str)
{
	int int_value = atoi(str.c_str());
	double double_value = strtod(str.c_str(), NULL);
	if (str.size() == 1 && !(str[0] >= '0' && str[0] <= '9'))
	{
		int_value = static_cast<int>(str[0]);
		double_value = static_cast<double>(str[0]);
	}


	std::cout << "char: ";
	if (int_value == 0 && nan(str) == EXIT_FAILURE)
		std::cout << "Impossible" << std::endl;
	else if (!(int_value >= ' ' && int_value <= '~'))
		std::cout << "Non displayable" << std::endl;
	else if (str.length() == 1 && !isdigit(str[0]))
		std::cout << "'" << str[0] << "'" << std::endl;
	else
		std::cout << "'" << static_cast<char>(int_value) << "'" << std::endl;


	std::cout << "int: ";
	if (int_value == 0 && nan(str) == EXIT_FAILURE)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << int_value << std::endl;


	std::cout << "float: ";
	if (int_value == 0 && nan(str) == EXIT_FAILURE && special(str) == EXIT_FAILURE)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<float>(double_value) << "f" << std::endl;
	
	
	std::cout << "double: ";
	if (int_value == 0 && nan(str) == EXIT_FAILURE && special(str) == EXIT_FAILURE)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<double>(double_value) << std::endl;
}
