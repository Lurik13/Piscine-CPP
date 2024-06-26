/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:12:00 by lribette          #+#    #+#             */
/*   Updated: 2024/06/25 14:17:44 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	protected:
		std::string _type;
		Brain *_ideas;
	public:
		Cat();
		Cat(Cat &copy);
		Cat &operator=(const Cat &src);
		~Cat();

		void makeSound() const;
		std::string getType() const;
		std::string getBrainIdeas() const;
		void		setIdeas(int index, std::string new_idea);
};
