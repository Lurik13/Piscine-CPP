/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:47:39 by lribette          #+#    #+#             */
/*   Updated: 2024/04/13 10:22:09 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::setClapTrap(std::string name, int hitPoints, int energyPoints, \
	int attackDamage)
{
	this->_name = name;
	this->_hitPoints = hitPoints;
	this->_energyPoints = energyPoints;
	this->_attackDamage = attackDamage;
}

unsigned int ClapTrap::getHitPoints() {return this->_hitPoints;}
unsigned int ClapTrap::getEnergyPoints() {return this->_energyPoints;}

ClapTrap::ClapTrap()
{
	setClapTrap("ClapTrap", 10, 10, 0);
	std::cout << HIGHLIGHTED_WHITE << this->_name
	<< " created." << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	setClapTrap(name, 10, 10, 0);
	std::cout << HIGHLIGHTED_WHITE << this->_name
	<< " created." << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	setClapTrap(copy._name, copy._hitPoints, copy._energyPoints, copy._attackDamage);
	std::cout << HIGHLIGHTED_WHITE << this->_name
	<< " created from another instance."
	<< RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << HIGHLIGHTED_WHITE << this->_name
	<< " deleted." << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	setClapTrap(src._name, src._hitPoints, src._energyPoints, src._attackDamage);
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->getHitPoints() != 0 && this->getEnergyPoints() != 0)
	{
		std::cout << "\e[38;2;130;30;250;1mClapTrap " << this->_name
		<< " attacks " << target << ", causing " << this->_attackDamage
		<< " points of damage! 😈\n" << RESET;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "\e[1mClapTrap " << this->_name
		<< " can't attack " << target << " because it's ";
		if (this->getHitPoints() == 0)
			std::cout << "dead. ☠️\n" << RESET;
		else
			std::cout << "out of energy. 😴\n" << RESET;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << "\e[1mClapTrap " << this->_name
		<< " can't take damage. ☠️\n" << RESET;
	}
	else if (amount < this->getHitPoints())
	{
		this->_hitPoints -= amount;
		std::cout << "\e[38;2;170;0;0;1mClapTrap " << this->_name
		<< " took " << amount << " points of damage. 🤕\n"<< RESET;
	}
	else
	{
		std::cout << "\e[38;2;170;0;0;1mClapTrap " << this->_name << " took "
		<< this->getHitPoints() << " points of damage and " << "\e[7m" << "died"
		<< RESET << "\e[38;2;170;0;0;1m" << ". 😵\n" << RESET;
		this->_hitPoints = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() != 0 && this->getEnergyPoints() != 0)
	{
		std::cout << "\e[38;2;0;170;0;1mClapTrap " << this->_name << " repaired " 
		<< amount << " points.\n" << RESET;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "\e[1mClapTrap " << this->_name
		<< " can't be repaired because it's ";
		if (this->getHitPoints() == 0)
			std::cout << "dead. ☠️\n" << RESET;
		else
			std::cout << "out of energy. 😴\n" << RESET;
	}
}
