/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:10:35 by lribette          #+#    #+#             */
/*   Updated: 2024/05/01 15:30:49 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

enum Type { CHAR = 0, INT, FLOAT, DOUBLE, IMPOSSIBLE };

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &src);
		virtual ~ScalarConverter() = 0;
	public:
		static void convert(std::string str);
};

int 		whichType(std::string str);
void		printChar(std::string str);