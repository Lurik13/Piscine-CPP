/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:49:33 by lribette          #+#    #+#             */
/*   Updated: 2024/04/09 20:24:14 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(Fixed &copy)
{
	std::cout << "\033[4mCopy constructor called\033[0m" << std::endl;
	_value = copy._value;
}

Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "\033[9mCopy assignment operator called\033[0m" << std::endl;
	_value = source._value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "\033[7mDestructor called\033[0m" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "\033[3mgetRawBits member function called\033[0m" << std::endl;
	return (1);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "\033[1msetRawBits member function called\033[0m" << std::endl;
	_value = raw;
}
