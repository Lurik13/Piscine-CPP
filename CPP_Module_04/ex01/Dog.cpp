/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:12:39 by lribette          #+#    #+#             */
/*   Updated: 2024/06/26 14:38:28 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->_ideas = new Brain;
	std::cout << BROWN << _type << " constructed.\n" << RESET;
}
Dog::Dog(Dog &copy)
{
	this->_type = copy._type;
	this->_ideas = new Brain(*copy._ideas);
	std::cout << BROWN << _type << " constructed.\n" << RESET;
}
Dog &Dog::operator=(const Dog &src)
{
	this->_type = src._type;
	if (this->_ideas)
		delete this->_ideas;
	this->_ideas = new Brain(*src._ideas);
	return(*this);
}

Dog::~Dog()
{
	delete this->_ideas;
	std::cout << BROWN << _type << " destructed.\n" << RESET;
}

void	Dog::makeSound() const
{
	std::cout << "The Dog is making sound.\n";
}

std::string Dog::getType() const {return this->_type;}
