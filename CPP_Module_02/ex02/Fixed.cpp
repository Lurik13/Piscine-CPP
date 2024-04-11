/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:39 by lribette          #+#    #+#             */
/*   Updated: 2024/04/11 18:31:18 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator=(const Fixed &src)
{
	this->_value = src._value;
	return(*this);
}

std::ostream &operator<<(std::ostream& os, const Fixed &src)
{
	os << src.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed &src){return (this->_value > src._value);}
bool Fixed::operator<(const Fixed &src){return (this->_value < src._value);}
bool Fixed::operator>=(const Fixed &src){return (this->_value >= src._value);}
bool Fixed::operator<=(const Fixed &src){return (this->_value <= src._value);}
bool Fixed::operator==(const Fixed &src){return (this->_value == src._value);}
bool Fixed::operator!=(const Fixed &src){return (this->_value != src._value);}

Fixed &Fixed::operator+(const Fixed &src){this->_value += src._value;
	return(*this);}
Fixed &Fixed::operator-(const Fixed &src){this->_value -= src._value;
	return(*this);}
Fixed &Fixed::operator*(const Fixed &src)
{
	std::cout << "* :" << this->_value << "," << src._value << ",";
	this->_value *= src._value;
	std::cout << this->_value << std::endl;
	return(*this);}
Fixed &Fixed::operator/(const Fixed &src){this->_value /= src._value;
	return(*this);}

Fixed &Fixed::operator++(){
	_value++;
	return (*this);
}
Fixed &Fixed::operator++(int){
	std::cout << "++i V\n";
	// Fixed temp = *this;
	++*this;
	// return (temp);
	return (*this);
}
Fixed &Fixed::operator--(){
	_value--;
	return(*this);
}
Fixed &Fixed::operator--(int){
	// Fixed temp = *this;
	// --*this;
	// return (temp);
	--_value;
	return (*this);
}



Fixed::Fixed(void) {this->_value = 0;}
Fixed::Fixed(const int to_fix) {
	this->_value = to_fix << this->_fract_bit;}
Fixed::Fixed(const float to_fix) {
	this->_value = roundf(to_fix * (1 << this->_fract_bit));}
Fixed::Fixed(Fixed const &copy) {*this = copy;}
Fixed::~Fixed() {}



float	Fixed::getRawBits() {return (this->_value);}
void Fixed::setRawBits( int const raw ) {this->_value = raw;}



float Fixed::toFloat( void ) const {
	return ((float)this->_value / (float)(1 << this->_fract_bit));}
int Fixed::toInt( void ) const {
	return ((int)this->_value / (int)(1 << this->_fract_bit));}

