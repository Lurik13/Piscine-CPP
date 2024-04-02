/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:24:41 by lribette          #+#    #+#             */
/*   Updated: 2024/04/02 17:48:56 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	return ;
}

Zombie::~Zombie()	{ return ; }

std::string	Zombie::get_name() { return this->_name; }

void	Zombie::announce()
{
	std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}