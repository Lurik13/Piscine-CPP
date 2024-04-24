/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:12:26 by lribette          #+#    #+#             */
/*   Updated: 2024/04/24 12:19:33 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) \
	: AForm::AForm(target, 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm " << this->_target << " constructed.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : \
	_target(copy._target)
{
	std::cout << "ShrubberyCreationForm " << this->_target << " constructed from copy.\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	*static_cast<AForm *>(this) = src;
	this->_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->_target << " destructed.\n";
}

/* ************************************************************************** */

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
