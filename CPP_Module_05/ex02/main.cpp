/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:02:03 by lribette          #+#    #+#             */
/*   Updated: 2024/04/24 12:20:14 by lribette         ###   ########.fr       */
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
	<< LEFT	STRING	VARIABLE " bureaucratName"		RIGHT
	<< LEFT INT		VARIABLE " bureaucratGrade"		RIGHT
	<< LEFT STRING	VARIABLE " formName"			RIGHT
	// << LEFT INT		VARIABLE " formGradeToSign"		RIGHT
	// << LEFT INT		VARIABLE " formGradeToExecute"	RIGHT
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
	if (argc == 4)
	{
		try
		{
			Bureaucrat bureaucrat(argv[1], which_grade(argv[2]));
			bureaucrat.incrementGrade();
			bureaucrat.decrementGrade();
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form(argv[3]);
			std::cout << form << std::endl;
			form.beSigned(bureaucrat);
			form.execute(bureaucrat);
		}
		catch(std::exception &e)
		{
			std::cout << EXCEPTION << e.what() << std::endl;
		}
	}
	else
		help();
}