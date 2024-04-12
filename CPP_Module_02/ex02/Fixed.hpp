/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:27 by lribette          #+#    #+#             */
/*   Updated: 2024/04/12 19:39:12 by lribette         ###   ########.fr       */
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
		~Fixed();
		
		Fixed &operator=(const Fixed &source);
		
		bool operator>(const Fixed &source) const;
		bool operator<(const Fixed &source) const;
		bool operator>=(const Fixed &source) const;
		bool operator<=(const Fixed &source) const;
		bool operator==(const Fixed &source) const;
		bool operator!=(const Fixed &source) const;

		Fixed operator+(const Fixed &source) const;
		Fixed operator-(const Fixed &source) const;
		Fixed operator*(const Fixed &source) const;
		Fixed operator/(const Fixed &source) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &nb1, Fixed &nb2);
		static const Fixed &min(const Fixed &nb1, const Fixed &nb2);
		static Fixed &max(Fixed &nb1, Fixed &nb2);
		static const Fixed &max(const Fixed &nb1, const Fixed &nb2);
		
		int	getRawBits() const;
		void	setRawBits( int const raw );
		
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream& os, const Fixed &source);