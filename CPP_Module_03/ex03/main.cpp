/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:47:06 by lribette          #+#    #+#             */
/*   Updated: 2024/04/15 18:19:54 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap R2D2;
	ScavTrap C3PO("C-3PO");
	ScavTrap _6PO(C3PO);
	FragTrap R4P17("R4-P17");

	R2D2.attack("C-3PO");
	C3PO.takeDamage(3);
	C3PO.beRepaired(1);
	R2D2.attack("C-3PO");
	C3PO.takeDamage(3);
	C3PO.beRepaired(1);
	R2D2.attack("C-3PO");
	C3PO.takeDamage(3);
	C3PO.beRepaired(1);
	R2D2.attack("C-3PO");
	C3PO.takeDamage(3);
	C3PO.beRepaired(1);
	R2D2.attack("R5-D4");
	R2D2.attack("GNK");
	R2D2.attack("DUM");
	R2D2.attack("MSE-6");
	R2D2.attack("BD-1");
	R2D2.attack("EG-6");
	R2D2.attack("RIC-920");
	R2D2.beRepaired(100);
	_6PO.attack("R2-D2");
	R2D2.takeDamage(20);
	_6PO.guardGate();
	R4P17.highFivesGuys();
}
