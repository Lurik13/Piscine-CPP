/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:49:25 by lribette          #+#    #+#             */
/*   Updated: 2024/05/01 15:45:13 by lribette         ###   ########.fr       */
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
	*this = src;
	return (*this);
}
ScalarConverter::~ScalarConverter() {}



void	ScalarConverter::convert(std::string str)
{
	int type = whichType(str);
	std::cout << "type = " << type << std::endl << std::endl;
	switch (type)
	{
		case CHAR:
			printChar(str);
			break;
		// case INT:
		// 	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		
		default:
			break;
	}
}