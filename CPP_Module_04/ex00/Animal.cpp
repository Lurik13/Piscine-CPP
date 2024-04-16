/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:20:57 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 18:50:56 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal") {
	std::cout << WHITE << _type << " constructed.\n" << RESET;}
Animal::Animal(Animal &copy): _type(copy._type) {
	std::cout << WHITE << _type << " constructed.\n" << RESET;}
Animal &Animal::operator=(const Animal &src) {this->_type = src._type; 
	return(*this);}
Animal::~Animal() {
	std::cout << WHITE << _type << " destructed.\n" << RESET;}

void	Animal::makeSound() const{
	std::cout << "Doesn't make sound.\n";}

std::string Animal::getType() const {return this->_type;}
