/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:02:03 by lribette          #+#    #+#             */
/*   Updated: 2024/07/04 11:12:20 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int which_grade(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (str[i] && !isdigit(str[i]))
			throw (Bureaucrat::NotIntegerException());
	}
	return (std::atoi(str));
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		try
		{
			Bureaucrat bureaucrat(argv[1], which_grade(argv[2]));
			bureaucrat.incrementGrade();
			bureaucrat.decrementGrade();
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << EXCEPTION << e.what() << RESET << std::endl;
		}
	}
	else
		std::cout << EXCEPTION << "./bureaucrat <std::string name> <int grade>\n"
		<< RESET;
}