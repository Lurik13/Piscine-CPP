/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:10 by lribette          #+#    #+#             */
/*   Updated: 2024/04/12 19:47:03 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2) );
	Fixed const c(42);
	Fixed d(42);
	std::cout << "a : " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	
	std::cout << "\e[38;2;50;150;255;1ma : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "d : " << d << "\e[0m" << std::endl;
	
	std::cout << "min ab : " << Fixed::min( a, b ) << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "b < c : " << (b < c) << std::endl;
	std::cout << "c == b : " << (c == b) << std::endl;
	std::cout << "c != d : " << (c != d) << std::endl;
	std::cout << "c + b : " << (c + b) << std::endl;
	std::cout << "c - b : " << (c - b) << std::endl;
	std::cout << "c * b : " << (c * b) << std::endl;
	std::cout << "c / b : " << (c / b) << std::endl;
	std::cout << "max ad : " << Fixed::max( a, d ) << std::endl;
	return 0;
}
