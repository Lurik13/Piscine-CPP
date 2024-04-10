/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:48:44 by lribette          #+#    #+#             */
/*   Updated: 2024/04/10 09:22:09 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;
	
	std::cout << "a._value = " << a.getRawBits() << std::endl;
	std::cout << "b._value = " << b.getRawBits() << std::endl;
	std::cout << "c._value = " << c.getRawBits() << std::endl;
	a.setRawBits(42);
	std::cout << "a._value = " << a.getRawBits() << std::endl;
	std::cout << "b._value = " << b.getRawBits() << std::endl;
	std::cout << "c._value = " << c.getRawBits() << std::endl;
	b.setRawBits(63);
	std::cout << "a._value = " << a.getRawBits() << std::endl;
	std::cout << "b._value = " << b.getRawBits() << std::endl;
	std::cout << "c._value = " << c.getRawBits() << std::endl;
	
	return 0;
}