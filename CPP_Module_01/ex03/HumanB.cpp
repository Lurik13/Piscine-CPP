/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:08:14 by lribette          #+#    #+#             */
/*   Updated: 2024/04/05 19:46:59 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::setName(std::string name) { this->_name = name; }
std::string	HumanB::getName() {return this->_name;}

HumanB::HumanB(std::string name)
{
	this->setName(name);
	this->_weapon.setType("");
}

HumanB::~HumanB(){}

void	HumanB::attack()
{
	std::cout
	<< "\033[38;2;0;120;170;1m" << this->getName() << "\033[0m"
	<< " attacks with their "
	<< "\033[38;2;170;0;0;3m" << this->_weapon.getType() << "\033[0m"
	<< std::endl;
}

void	HumanB::setWeapon(Weapon weapon){this->_weapon = weapon;}