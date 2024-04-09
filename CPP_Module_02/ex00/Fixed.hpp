/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:49:17 by lribette          #+#    #+#             */
/*   Updated: 2024/04/09 19:46:04 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int	_fract_bit = 8;
	public:
		Fixed();
		Fixed(Fixed &copy);
		Fixed& operator=(const Fixed &other);
		~Fixed();
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};