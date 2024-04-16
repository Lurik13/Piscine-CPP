/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:30:35 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 18:54:09 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): _type("Dog") {
	std::cout << WHITE << _type << " constructed.\n" << RESET;}
Dog::Dog(Dog &copy): _type(copy._type) {
	std::cout << WHITE << _type << " constructed.\n" << RESET;}
Dog &Dog::operator=(const Dog &src) {this->_type = src._type; 
	return(*this);}
Dog::~Dog() {
	std::cout << WHITE << _type << " destructed.\n" << RESET;}

void	Dog::makeSound() const
{
	std::cout << "The dog is making sound.\n";
}

std::string Dog::getType() const {return this->_type;}
