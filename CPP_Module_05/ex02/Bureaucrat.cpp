/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:02:39 by lribette          #+#    #+#             */
/*   Updated: 2024/04/24 18:13:21 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	this->checkGrade(grade);
	std::cout << "Bureaucrat " << this->_name << " constructed with grade "
	<< this->_grade << ".\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name + "_copy"), _grade(copy._grade)
{
	std::cout << "Bureaucrat " << this->_name << " constructed with grade "
	<< this->_grade << " from copy.\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destructed.\n";
}

/* ************************************************************************** */

std::string Bureaucrat::getName() const {return this->_name;}
int Bureaucrat::getGrade() const {return this->_grade;}

void	Bureaucrat::checkGrade(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

void Bureaucrat::setGrade(int grade)
{
	Bureaucrat::checkGrade(grade);
	this->_grade = grade;
}

/* ************************************************************************** */

void Bureaucrat::incrementGrade()
{
	this->setGrade(this->getGrade() - 1);
	std::cout << INCREMENT << "After incrementing, " << this->getName()
	<< " is in grade " << this->getGrade() << ".\n" << RESET;
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(this->getGrade() + 1);
	std::cout << DECREMENT << "After decrementing, " << this->getName()
	<< " is in grade " << this->getGrade() << ".\n" << RESET;
}

void Bureaucrat::signForm(AForm &f)
{
	std::cout << SIGN << this->getName();
	if (f.getIsSigned() == 1)
		std::cout << " signed " << f.getName() << ".";
	else
		std::cout << " couldn't sign " << f.getName()
		<< " because he couldn't find his pen \e[4m(grade "
		<< this->getGrade() << " > grade " << f.getGradeToSign() << ")";
	std::cout << std::endl << RESET;
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << SIGN << this->getName() << " executed the form called "
		<< form.getName() << ".\n" << RESET;
	}
	catch(std::exception &e)
	{
		std::cout << EXCEPTION << e.what() << std::endl;
	}
	
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << COUT << b.getName() << ", bureaucrat grade " << b.getGrade()  << "." << RESET;
	return (o);
}
