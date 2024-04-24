/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:12:26 by lribette          #+#    #+#             */
/*   Updated: 2024/04/24 11:47:20 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm(), _name()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, \
	const int grade_to_sign, const int grade_to_execute) : _name(name), \
	_grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	std::cout << "-----------------------\n" << this->_name;                                                                                                                                                                         ;
	this->_is_signed = 0;
	this->checkGrade(grade_to_sign, REQUIRED_SIGN);
	this->checkGrade(grade_to_execute, REQUIRED_EXEC);
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

/* ************************************************************************** */

void	ShrubberyCreationForm::checkGrade(int grade, int required)
{
	if (required == REQUIRED_SIGN && grade > 145)
		throw (AForm::GradeTooLowException());
	if (required == REQUIRED_EXEC && grade > 137)
		throw (AForm::GradeTooLowException());
	if (grade < 1)
		throw (AForm::GradeTooHighException());
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor)
{
	std::string file_name = this->getName() + "_shrubbery";
	std::fstream outputFile;
	outputFile.open(file_name.c_str(), std::fstream::out);
	for (int i = 0; i < 5; i++)
	{
		outputFile 
		<< "          &&& &&  & &&" << std::endl
		<< "      && &\\/&\\|& ()|/ @, &&" << std::endl
		<< "      &\\/(/&/&||/& /_/)_&/_&" << std::endl
		<< "   &() &\\/&|()|/&\\/ '%' & ()" << std::endl
		<< "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl
		<< "&&   && & &| &| /& & % ()& /&&" << std::endl
		<< " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl
		<< "     &&     \\|||" << std::endl
		<< "             |||" << std::endl
		<< "             |||" << std::endl
		<< "             |||" << std::endl
		<< "       , -=-~  .-^- _" << std::endl << std::endl << std::endl;
	}
	outputFile.close();
	std::cout << SIGN << executor.getName() << " executed the shrubbery form.\n" << RESET;
}
