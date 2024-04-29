/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:08:45 by lribette          #+#    #+#             */
/*   Updated: 2024/04/05 19:39:59 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string&	Weapon::getType(){ return this->_type; }
void	Weapon::setType(std::string type){ this->_type = type; }

Weapon::Weapon(){}
Weapon::Weapon(std::string weapon){this->setType(weapon);}
Weapon::~Weapon(){}