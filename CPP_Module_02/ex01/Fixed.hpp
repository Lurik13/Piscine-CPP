/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:27 by lribette          #+#    #+#             */
/*   Updated: 2024/04/11 11:36:52 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

#define RESET "\e[0m"

class Fixed
{
	private:
		int	_value;
		static const int	_fract_bit = 8;
	public:
		Fixed();
		Fixed(const int to_fix);
		Fixed(const float to_fix);
		Fixed(Fixed const &copy);
		Fixed &operator=(const Fixed &source);
		~Fixed();
		
		float	getRawBits();
		
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream& os, const Fixed &source);