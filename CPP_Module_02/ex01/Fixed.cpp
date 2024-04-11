/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:39 by lribette          #+#    #+#             */
/*   Updated: 2024/04/11 11:44:14 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "\033[38;2;200;200;0;1m" << "Copy assignment operator= called"
	<< RESET << std::endl;
	this->_value = source._value;
	return(*this);
}

std::ostream &operator<<(std::ostream& os, const Fixed &source)
{
	os << source.toFloat();
	std::cout << "\n\033[38;2;200;200;0;1m" << "Copy assignment operator<< called"
	<< RESET;
	return (os);
}



Fixed::Fixed(void)
{
	std::cout << "\033[38;2;75;145;220;1m" << "Default constructor called"
	<< RESET << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int to_fix)
{
	std::cout << "\033[38;2;113;75;220;1m" << "Int constructor called"
	<< RESET << std::endl;
	this->_value = to_fix << this->_fract_bit;
}

Fixed::Fixed(const float to_fix)
{
	std::cout << "\033[38;2;50;170;113;1m" << "Float constructor called"
	<< RESET << std::endl;
	this->_value = roundf(to_fix * (1 << this->_fract_bit));
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "\033[38;2;25;95;170;1m" << "Copy constructor called"
	<< RESET << std::endl;
	this->_value = copy._value;
}

Fixed::~Fixed()
{
	std::cout << "\033[38;2;0;0;0;1m" << "Default destructor called"
	<< RESET << std::endl;
}



float	Fixed::getRawBits()
{
	return (this->_value);
}



float Fixed::toFloat( void ) const
{
	return ((float)this->_value / (float)(1 << this->_fract_bit));
}

int Fixed::toInt( void ) const
{
	return ((int)this->_value / (int)(1 << this->_fract_bit));
}

