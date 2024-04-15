/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:47:23 by lribette          #+#    #+#             */
/*   Updated: 2024/04/15 14:51:59 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define HIGHLIGHTED_WHITE "\e[38;2;255;255;255;7m"
#define RESET "\e[0m"

class ClapTrap
{
	protected:
		std::string _name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &copy);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &src);

		void setClapTrap(std::string name, int hitPoints, int energyPoints, \
			int attackDamage);
		unsigned int getHitPoints();
		unsigned int getEnergyPoints();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
