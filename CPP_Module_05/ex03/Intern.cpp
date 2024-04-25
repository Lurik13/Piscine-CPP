/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:56:28 by lribette          #+#    #+#             */
/*   Updated: 2024/04/25 16:47:30 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){std::cout << "Intern constructed.\n";}
Intern::Intern(const Intern &){std::cout << "Intern constructed from copy.\n";}
Intern &Intern::operator=(const Intern &){return *this;}
Intern::~Intern(){std::cout << "Intern destructed.\n";}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string nameptr[] = {"shrubbery", "robotomy", "presidential"};
	int i = 0;
	while (i < 3 && nameptr[i] != name)
		i++;
	if (i < 3)
		std::cout << EXECUTION << "Intern creates " << nameptr[i] << RESET << std::endl;
	else
		std::cout << EXECUTION << "Intern twiddles his thumbs." << RESET << std::endl;
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			throw Intern::FormNotFound();
	}
}
