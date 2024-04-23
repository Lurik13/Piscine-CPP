/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:12:04 by lribette          #+#    #+#             */
/*   Updated: 2024/04/23 15:43:07 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _grade_to_sign;
		const int _grade_to_execute;
	public:
		ShrubberyCreationForm(const std::string name, const int grade_to_sign, \
			const int grade_to_execute);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat &executor);
};
