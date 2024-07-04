/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:02:20 by lribette          #+#    #+#             */
/*   Updated: 2024/07/04 11:44:08 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include "Form.hpp"

#define INCREMENT "\033[38;2;0;234;0;1m"
#define DECREMENT "\033[38;2;234;0;0;1m"
#define EXCEPTION "\033[38;2;172;88;255;1m\033[5m"
#define COUT "\033[38;2;50;145;255;1m"
#define SIGN "\x1b[38;2;136;87;66;1m"
#define RESET "\e[0m"

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void checkGrade(int grade);
		void setGrade(int grade);
		
		void incrementGrade();
		void decrementGrade();
		void signForm(class Form &f);


		class GradeTooLowException : public std::exception
		{
       		public:
        		virtual const char *what() const throw() {
            	   return ("Grade is too low.");
        	}
     	};
		class GradeTooHighException : public std::exception
		{
       		public:
        		virtual const char *what() const throw() {
            	   return ("Grade is too high.");
        	}
     	};
		class WrongParamException : public std::exception
		{
       		public:
        		virtual const char *what() const throw() {
					return ("Wrong parameter.");
        	}
     	};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);