/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:12:39 by lribette          #+#    #+#             */
/*   Updated: 2024/06/25 14:20:51 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_ideas = new Brain;
	this->_ideas->setIdeas(1, "mouahahahaha");
	std::cout << JAURANGE << _type << " constructed.\n" << RESET;
}
Cat::Cat(Cat &copy)
{
	this->_type = copy._type;
	this->_ideas = copy._ideas;
	std::cout << JAURANGE << _type << " constructed.\n" << RESET;
}
Cat &Cat::operator=(const Cat &src)
{
	this->_type = src._type;
	if (this->_ideas)
		delete this->_ideas;
	this->_ideas = new Brain(*src._ideas);
	return(*this);
}

Cat::~Cat()
{
	delete this->_ideas;
	std::cout << JAURANGE << _type << " destructed.\n" << RESET;
}

void	Cat::makeSound() const
{
	std::cout << "The cat is making sound.\n";
}

std::string Cat::getType() const {return this->_type;}

std::string Cat::getBrainIdeas() const
{
	return (this->_ideas->getIdeas());
}

void	Cat::setIdeas(int index, std::string new_idea)
{
	this->_ideas->setIdeas(index, new_idea);
}
