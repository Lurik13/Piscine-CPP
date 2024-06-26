/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:26:30 by lribette          #+#    #+#             */
/*   Updated: 2024/04/17 16:27:21 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define WHITE "\e[38;2;255;255;255;7m"
#define PURPLE "\033[38;2;120;80;252;7m"
#define BROWN "\033[38;2;150;106;55;7m"
#define JAURANGE "\033[38;2;250;200;129;7m"
#define RESET "\e[0m"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(Animal &copy);
		Animal &operator=(const Animal &src);
		virtual ~Animal();

		virtual void makeSound() const;
		virtual std::string getType() const;
};
