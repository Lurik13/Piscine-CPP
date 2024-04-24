/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:02:03 by lribette          #+#    #+#             */
/*   Updated: 2024/04/24 18:14:43 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	help()
{
	std::cout << EXECUTABLE << "./form" 
	<< LEFT STRING	VARIABLE " shrubberyTarget"		RIGHT
	<< LEFT STRING	VARIABLE " robotomyTarget"		RIGHT
	<< LEFT STRING	VARIABLE " presidentTarget"		RIGHT
	<< LEFT	STRING	VARIABLE " bureaucratName"		RIGHT
	<< LEFT INT		VARIABLE " bureaucratGrade"		RIGHT
	<< std::endl;
}

int which_grade(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (str[i] && !isdigit(str[i]))
			throw (Bureaucrat::WrongParamException());
	}
	return (std::atoi(str));
}

int which_sign(std::string str)
{
	if (!(str.size() == 1 && (str[0] == '0' || str[0] == '1')))
		throw (Bureaucrat::WrongParamException());
	return (str[0] - 48);
}

int main(int argc, char **argv)
{
	if (argc == 6)
	{
		try
		{
			Bureaucrat bureaucrat(argv[4], which_grade(argv[5]));
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade();
			bureaucrat.decrementGrade();
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm shrubbery(argv[1]);
			std::cout << shrubbery << std::endl;
			shrubbery.beSigned(bureaucrat);
			bureaucrat.executeForm(shrubbery);
			RobotomyRequestForm robotomy(argv[2]);
			std::cout << robotomy << std::endl;
			robotomy.beSigned(bureaucrat);
			bureaucrat.executeForm(robotomy);
			PresidentialPardonForm president(argv[3]);
			std::cout << president << std::endl;
			president.beSigned(bureaucrat);
			bureaucrat.executeForm(president);
			std::cout << president << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << EXCEPTION << e.what() << RESET << std::endl;
		}
	}
	else
		help();
}
