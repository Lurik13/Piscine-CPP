/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:02:20 by lribette          #+#    #+#             */
/*   Updated: 2024/04/20 11:26:03 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

class Bureaucrat
{
	private:
		std::string _name;
		int	_grade;
	public:
		std::string GradeTooHighException();
		std::string GradeTooLowException();
		
		Bureaucrat(const std::string name, int grade);
		// Bureaucrat(Bureaucrat &copy);
		// Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		std::string getName() const;
		std::string getGrade() const;
};
