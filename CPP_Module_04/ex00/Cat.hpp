/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:12:00 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 18:52:35 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string _type;
	public:
		Cat();
		Cat(Cat &copy);
		Cat &operator=(const Cat &src);
		~Cat();

		void makeSound() const;
		std::string getType() const;
};
