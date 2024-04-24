/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:13:21 by lribette          #+#    #+#             */
/*   Updated: 2024/04/24 17:02:34 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) \
	: AForm::AForm(target, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm " << this->_target << " constructed.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : \
	_target(copy._target)
{
	std::cout << "RobotomyRequestForm " << this->_target << " constructed from copy.\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << this->_target << " destructed.\n";
}


/* ************************************************************************** */


void RobotomyRequestForm::execute(const Bureaucrat &executor)
{
	if (!this->getIsSigned())
		throw (AForm::NotSignedYet());
	if (executor.getGrade() > this->getGradeToExecute())
	{
		std::cout << SIGN << executor.getName()
		<< " was unable to execute the robotomy form because he forgot his toolbox in his garage "
		<< "\e[4m(grade " << executor.getGrade() << " > grade "
		<< this->getGradeToExecute() << ")\n" << RESET;
		throw (AForm::GradeTooLowException());
	}
	
	std::cout << SIGN << executor.getName() << " executed the robotomy form.\n" << RESET;
	std::cout << EXECUTION << "Makes some drilling noises." << std::endl;
	
	srand(time(0));
	int random = std::rand() % 2;
	if (random == 0)
		std::cout << this->_target << " has been robotomized.";
	else
		std::cout << "The " << this->_target << "'s robotomy failed.";
	std::cout << RESET << std::endl;
}
