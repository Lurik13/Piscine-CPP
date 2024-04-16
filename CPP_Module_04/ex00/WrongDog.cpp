/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:30:35 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 18:54:09 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog(): _type("WrongDog") {
	std::cout << WHITE << _type << " constructed.\n" << RESET;}
WrongDog::WrongDog(WrongDog &copy): _type(copy._type) {
	std::cout << WHITE << _type << " constructed.\n" << RESET;}
WrongDog &WrongDog::operator=(const WrongDog &src) {this->_type = src._type; 
	return(*this);}
WrongDog::~WrongDog() {
	std::cout << WHITE << _type << " destructed.\n" << RESET;}

void	WrongDog::makeSound() const
{
	std::cout << "The WrongDog is making sound.\n";
}

std::string WrongDog::getType() const {return this->_type;}
