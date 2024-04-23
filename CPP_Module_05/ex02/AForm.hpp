/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:59:41 by lribette          #+#    #+#             */
/*   Updated: 2024/04/23 14:52:07 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

#define EXECUTABLE "\033[38;2;255;145;5;3m"

#define WHITE "\e[38;2;255;255;255m"
#define LEFT RESET " <\e[3m"
#define RIGHT RESET ">"

#define TEXT_STRING "\033[38;2;78;201;176m"
#define STRING TEXT_STRING "std" WHITE "::" TEXT_STRING "string"

#define NUMBER "\033[38;2;83;151;208m"
#define BOOL NUMBER "bool"
#define INT NUMBER "int"

#define VARIABLE "\033[38;2;148;208;241m"

class AForm
{
	protected:
		const std::string _name;
		bool _is_signed;
		const int _grade_to_sign;
		const int _grade_to_execute;
	public:
		AForm();
		AForm(const std::string name, const int grade_to_sign, \
			const int grade_to_execute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void checkGrade(int grade);
		
		void beSigned(class Bureaucrat &b);
		virtual void execute(const Bureaucrat &executor) = 0;


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
};

std::ostream &operator<<(std::ostream &o, const AForm &f);
