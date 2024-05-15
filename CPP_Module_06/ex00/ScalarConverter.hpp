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

class ScalarConverter
{
	private:
		std::string _type;
		std::string _value;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();

		void setType(std::string type);
		void setValue(std::string value);
		std::string getType() const;
		std::string getValue() const;
		
		void print();

		// class InvalidConversion : public std::exception
		// {
		// 	public:
		// 		virtual const char *what() const throw() {
		// 			return ("Invalid conversion!");
		// 		}
		// };
};
