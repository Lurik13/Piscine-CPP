/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:12:39 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 18:53:58 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): _type("Cat") {
	std::cout << WHITE << _type << " constructed.\n" << RESET;}
Cat::Cat(Cat &copy): _type(copy._type) {
	std::cout << WHITE << _type << " constructed.\n" << RESET;}
Cat &Cat::operator=(const Cat &src) {this->_type = src._type; 
	return(*this);}
Cat::~Cat() {
	std::cout << WHITE << _type << " destructed.\n" << RESET;}

void	Cat::makeSound() const
{
	std::cout << "The cat is making sound.\n";
}

std::string Cat::getType() const {return this->_type;}
