/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:00:29 by lribette          #+#    #+#             */
/*   Updated: 2024/04/23 14:52:33 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int grade_to_sign, \
	const int grade_to_execute) : _name(name), \
	_grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->_is_signed = 0;
	this->checkGrade(grade_to_sign);
	this->checkGrade(grade_to_execute);
	std::cout << "Form " << this->_name << " constructed.\n";
}

Form::Form(const Form &copy) : _name(copy._name), _is_signed(copy._is_signed), \
	_grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute)
{
	std::cout << "Form " << this->_name << " constructed from copy.\n";
}

Form &Form::operator=(const Form &src)
{
	this->_is_signed = src._is_signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " destructed.\n";
}

/* ************************************************************************** */

std::string Form::getName() const {return this->_name;}
bool Form::getIsSigned() const {return this->_is_signed;}
int Form::getGradeToSign() const {return this->_grade_to_sign;}
int Form::getGradeToExecute() const {return this->_grade_to_execute;}

void	Form::checkGrade(int grade)
{
	if (grade > 150)
		throw (Form::GradeTooLowException());
	if (grade < 1)
		throw (Form::GradeTooHighException());
}

/* ************************************************************************** */

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeToSign()
		|| b.getGrade() > this->getGradeToExecute())
	{
		b.signForm(*this);
		throw (Form::GradeTooLowException());
	}
	this->_is_signed = 1;
	b.signForm(*this);
}

std::ostream &operator<<(std::ostream &o, const Form &f)
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
