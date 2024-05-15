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

ScalarConverter::ScalarConverter() {this->_type = "";}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) {this->_type = copy._type;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	this->_type = src._type;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::setType(std::string type){this->_type = type;}
void ScalarConverter::setValue(std::string value){this->_value = value;}
std::string ScalarConverter::getType() const {return this->_type;}
std::string ScalarConverter::getValue() const {return this->_value;}



void ScalarConverter::print()
{
	std::cout << static_cast<float>(-9) << std::endl;
}
