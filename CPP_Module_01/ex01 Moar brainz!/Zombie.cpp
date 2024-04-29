/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:17:38 by lribette          #+#    #+#             */
/*   Updated: 2024/04/03 17:17:33 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "nobody...";
	return ;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	return ;
}

Zombie::~Zombie()
{
	return ;
}

std::string	Zombie::get_name() { return this->_name; }
void	Zombie::set_name(std::string name) { this->_name = name; }

void	Zombie::announce()
{
	std::cout << this->_name << std::endl;
}
