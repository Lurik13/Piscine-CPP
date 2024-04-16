/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:38:43 by lribette          #+#    #+#             */
/*   Updated: 2024/04/15 18:00:27 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	setClapTrap("FragTrap", 100, 50, 20);
	std::cout << HIGHLIGHTED_WHITE << "FragTrap " << this->_name
	<< " created." << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) :ClapTrap(name)
{
	setClapTrap(name, 100, 50, 20);
	std::cout << HIGHLIGHTED_WHITE << "FragTrap " << this->_name
	<< " created." << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << HIGHLIGHTED_WHITE << "FragTrap " << this->_name
	<< " created from another instance." << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	setClapTrap(src._name, src._hitPoints, src._energyPoints, src._attackDamage);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << HIGHLIGHTED_WHITE << "FragTrap " << this->_name
	<< " deleted." << RESET << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->getHitPoints() != 0 && this->getEnergyPoints() != 0)
	{
		std::cout << "\e[38;2;130;30;250;1mFragTrap " << this->_name
		<< " attacks " << target << ", causing " << this->_attackDamage
		<< " points of damage! 😈\n" << RESET;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "\e[1mFragTrap " << this->_name
		<< " can't attack " << target << " because it's ";
		if (this->getHitPoints() == 0)
			std::cout << "dead. ☠️\n" << RESET;
		else
			std::cout << "out of energy. 😴\n" << RESET;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout << "\e[38;2;75;186;220;1mFragTrap " << this->_name
	<< " gives you a high five 🙌" << RESET << std::endl;
}
