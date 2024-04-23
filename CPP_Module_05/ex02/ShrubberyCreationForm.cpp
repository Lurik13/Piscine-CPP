/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:12:26 by lribette          #+#    #+#             */
/*   Updated: 2024/04/23 15:49:34 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const int grade_to_sign, const int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->_is_signed = 0;
	this->checkGrade(grade_to_sign);
	this->checkGrade(grade_to_execute);
	std::cout << "ShrubberyCreationForm " << this->_name << " constructed.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : \
	_name(copy._name), _is_signed(copy._is_signed), \
	_grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute) \
{
	std::cout << "ShrubberyCreationForm " << this->_name << " constructed from copy.\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->_is_signed = src._is_signed;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->_name << " destructed.\n";
}

void execute(const Bureaucrat &executor);
