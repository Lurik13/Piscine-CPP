/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:24:41 by lribette          #+#    #+#             */
/*   Updated: 2024/04/03 15:54:43 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "Lambda zombie";
	return ;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "\033[38;2;150;25;50;1m" << this->_name 
	<< "\033[0m" " died." << std::endl;
	return ;
}

std::string	Zombie::get_name() { return this->_name; }

void	Zombie::announce()
{
	std::cout << "\033[38;2;75;150;0;1m" << get_name() << "\033[0m"
	<< ": BraiiiiiiinnnzzzZ..." << std::endl;
}
