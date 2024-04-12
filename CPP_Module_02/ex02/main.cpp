/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:10 by lribette          #+#    #+#             */
/*   Updated: 2024/04/12 18:18:13 by lribette         ###   ########.fr       */
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
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "min ab : " << Fixed::min( a, b ) << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "c == b : " << (c == b) << std::endl;
	std::cout << "b < c : " << (a > b) << std::endl;
	return 0;
}
