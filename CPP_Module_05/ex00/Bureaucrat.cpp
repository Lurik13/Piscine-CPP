/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:02:39 by lribette          #+#    #+#             */
/*   Updated: 2024/04/20 11:29:23 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string Bureaucrat::GradeTooHighException()
{
	return ("Grade too high.\n");
}

std::string Bureaucrat::GradeTooLowException()
{
	return ("Grade too low.\n");
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	std::cout << "Bureaucrat " << this->_name << " constructed with grade "
	<< this->_grade << ".\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destructed.\n";
}

// std::string getName() const;
// std::string getGrade() const;