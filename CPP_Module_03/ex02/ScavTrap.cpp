/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:38:43 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 09:51:42 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	setClapTrap("ScavTrap", 100, 50, 20);
	std::cout << HIGHLIGHTED_WHITE << "ScavTrap " << this->_name
	<< " created." << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) :ClapTrap(name)
{
	setClapTrap(name, 100, 50, 20);
	std::cout << HIGHLIGHTED_WHITE << "ScavTrap " << this->_name
	<< " created." << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << HIGHLIGHTED_WHITE << "ScavTrap " << this->_name
	<< " created from another instance." << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	setClapTrap(src._name, src._hitPoints, src._energyPoints, src._attackDamage);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << HIGHLIGHTED_WHITE << "ScavTrap " << this->_name
	<< " deleted." << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() != 0 && this->getEnergyPoints() != 0)
	{
		std::cout << "\e[38;2;130;30;250;1mScavTrap " << this->_name
		<< " attacks " << target << ", causing " << this->_attackDamage
		<< " points of damage! 😈\n" << RESET;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "\e[1mScavTrap " << this->_name
		<< " can't attack " << target << " because it's ";
		if (this->getHitPoints() == 0)
			std::cout << "dead. ☠️\n" << RESET;
		else
			std::cout << "out of energy. 😴\n" << RESET;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "\e[38;2;75;186;220;1mScavTrap " << this->_name
	<< " is in gate keeper mode 🛡️" << RESET << std::endl;
}
