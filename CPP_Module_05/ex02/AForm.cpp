/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:00:29 by lribette          #+#    #+#             */
/*   Updated: 2024/04/23 15:09:54 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, int grade_to_sign,
	int grade_to_execute, bool is_signed) : _name(name),
											_grade_to_sign(grade_to_sign),
											_grade_to_execute(grade_to_execute),
											_is_signed(is_signed)
{
	this->_is_signed = 0;
	this->checkGrade(grade_to_sign, REQUIRED_SIGN);
	this->checkGrade(grade_to_execute, REQUIRED_EXEC);
	std::cout << "AForm " << this->_name << " constructed.\n";
}

AForm::AForm(const AForm &copy) : _name(copy._name), _grade_to_sign(copy._grade_to_sign), \
	_grade_to_execute(copy._grade_to_execute), _is_signed(copy._is_signed)
{
	std::cout << "AForm " << this->_name << " constructed from copy.\n";
}

AForm &AForm::operator=(const AForm &src)
{
	this->_is_signed = src._is_signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " destructed.\n";
}

/* ************************************************************************** */

std::string AForm::getName() const {return this->_name;}
bool AForm::getIsSigned() const {return this->_is_signed;}
int AForm::getGradeToSign() const {return this->_grade_to_sign;}
int AForm::getGradeToExecute() const {return this->_grade_to_execute;}

void	AForm::checkGrade(int grade, int required)
{
	if (required == REQUIRED_SIGN && grade > 145)
		throw (AForm::GradeTooLowException());
	if (required == REQUIRED_EXEC && grade > 137)
		throw (AForm::GradeTooLowException());
	if (grade < 1)
		throw (AForm::GradeTooHighException());
}

/* ************************************************************************** */

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeToSign())
	{
		b.signForm(*this);
		throw (AForm::GradeTooLowException());
	}
	this->_is_signed = 1;
	b.signForm(*this);
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	
}

std::ostream &operator<<(std::ostream &o, const AForm &f)
{
	o << COUT << f.getName() << " is ";
	if (f.getIsSigned() == 0)
		o << "not";
	else
		o << "already";
	o << " signed.\nIt requires grade " << f.getGradeToSign() << " to sign it and "
	<< f.getGradeToExecute() << " to execute it." << RESET;
	return (o);
}
