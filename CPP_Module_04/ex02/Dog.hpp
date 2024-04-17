/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:29 by lribette          #+#    #+#             */
/*   Updated: 2024/04/17 11:44:24 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	protected:
		std::string _type;
		Brain *_ideas;
	public:
		Dog();
		Dog(Dog &copy);
		Dog &operator=(const Dog &src);
		~Dog();

		void makeSound() const;
		std::string getType() const;
};
