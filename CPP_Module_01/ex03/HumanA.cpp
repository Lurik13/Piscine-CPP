/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:08:05 by lribette          #+#    #+#             */
/*   Updated: 2024/04/05 19:43:00 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::setName(std::string name) { this->_name = name; }
std::string	HumanA::getName() {return this->_name;}

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->setName(name);
	this->_weapon = weapon;
}

HumanA::~HumanA(){}

void	HumanA::attack()
{
	std::cout
	<< "\033[38;2;0;120;170;1m" << this->getName() << "\033[0m"
	<< " attacks with their "
	<< "\033[38;2;170;0;0;3m" << this->_weapon.getType() << "\033[0m"
	<< std::endl;
}