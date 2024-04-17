/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:12:39 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 18:53:58 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): _type("WrongCat") {
	std::cout << JAURANGE << _type << " constructed.\n" << RESET;}
WrongCat::WrongCat(WrongCat &copy): _type(copy._type) {
	std::cout << JAURANGE << _type << " constructed.\n" << RESET;}
WrongCat &WrongCat::operator=(const WrongCat &src) {this->_type = src._type; 
	return(*this);}
WrongCat::~WrongCat() {
	std::cout << JAURANGE << _type << " destructed.\n" << RESET;}

void	WrongCat::makeSound() const
{
	std::cout << "The WrongCat is making sound.\n";
}

std::string WrongCat::getType() const {return this->_type;}
