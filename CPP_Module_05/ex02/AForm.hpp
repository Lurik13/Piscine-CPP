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
#include <fstream>

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

#define REQUIRED_SIGN 0
#define REQUIRED_EXEC 1

class AForm
{
	private:
		const std::string _name;
		const int _grade_to_sign;
		const int _grade_to_execute;
		bool _is_signed;
	public:
		AForm(const std::string name = "unnamed", int grade_to_sign = 63, \
			int grade_to_execute = 34, bool is_signed = 0);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		virtual void checkGrade(int grade, int required);
		
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
		class NotSignedYet : public std::exception
		{
       		public:
        		virtual const char *what() const throw() {
            	   return ("Not signed yet.");
        	}
     	};
};

std::ostream &operator<<(std::ostream &o, const AForm &f);
