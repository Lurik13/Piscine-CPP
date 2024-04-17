/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:20:57 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 18:50:56 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal") {
	std::cout << WHITE << _type << " constructed.\n" << RESET;}
WrongAnimal::WrongAnimal(WrongAnimal &copy): _type(copy._type) {
	std::cout << WHITE << _type << " constructed.\n" << RESET;}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {this->_type = src._type; 
	return(*this);}
WrongAnimal::~WrongAnimal() {
	std::cout << WHITE << _type << " destructed.\n" << RESET;}

void	WrongAnimal::makeSound() const{
	std::cout << "Doesn't make sound.\n";}

std::string WrongAnimal::getType() const {return this->_type;}
