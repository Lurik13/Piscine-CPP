/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:00:29 by lribette          #+#    #+#             */
/*   Updated: 2024/04/22 18:56:47 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, bool is_signed, const int grade_to_sign, \
	const int grade_to_execute) : _name(name), _is_signed(is_signed), \
	_grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
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
int Form::getGradeToSign() const {return this->_grade_to_sign;}
int Form::getGradeToExecute() const {return this->_grade_to_execute;}

void	Form::checkGrade(int grade)
{
	if (grade > 150)
		throw (Form::GradeTooLowException());
	if (grade < 1)
		throw (Form::GradeTooHighException());
}

// void Form::setGrade(int grade)
// {
// 	Form::checkGrade(grade);
// 	this->_grade = grade;
// }

/* ************************************************************************** */

// void Form::incrementGrade()
// {
// 	this->setGrade(this->getGrade() - 1);
// 	std::cout << INCREMENT << "After incrementing, " << this->getName()
// 	<< " is in grade " << this->getGrade() << ".\n" << RESET;
// }

// void Form::decrementGrade()
// {
// 	this->setGrade(this->getGrade() + 1);
// 	std::cout << DECREMENT << "After decrementing, " << this->getName()
// 	<< " is in grade " << this->getGrade() << ".\n" << RESET;
// }

std::ostream &operator<<(std::ostream &o, const Form &b)
{
	o << COUT << b.getName() << ", Form grade " /*<< b.getGrade()*/  << "." << RESET;
	return (o);
}
