/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:14:18 by lribette          #+#    #+#             */
/*   Updated: 2024/04/24 17:06:22 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) \
	: AForm::AForm(target, 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm " << this->_target << " constructed.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : \
	_target(copy._target)
{
	std::cout << "PresidentialPardonForm " << this->_target << " constructed from copy.\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << this->_target << " destructed.\n";
}


/* ************************************************************************** */


void PresidentialPardonForm::execute(const Bureaucrat &executor)
{
	if (!this->getIsSigned())
		throw (AForm::NotSignedYet());
	if (executor.getGrade() > this->getGradeToExecute())
	{
		std::cout << SIGN << executor.getName()
		<< " didn't execute the presidential form because he got scared and ran away "
		<< "\e[4m(grade " << executor.getGrade() << " > grade "
		<< this->getGradeToExecute() << ")\n" << RESET;
		throw (AForm::GradeTooLowException());
	}
	
	std::cout << SIGN << executor.getName() << " executed the presidential form.\n" << RESET;
	std::cout << EXECUTION << this->_target << " has been pardoned by Zaphod Beeblebrox."
    << RESET << std::endl;
}
