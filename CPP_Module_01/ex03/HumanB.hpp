/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:08:31 by lribette          #+#    #+#             */
/*   Updated: 2024/04/05 19:47:08 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon	_weapon;
	std::string	_name;
public:
	HumanB(std::string name);
	~HumanB();
	void	setName(std::string name);
	std::string	getName();
	void	attack();
	void	setWeapon(Weapon weapon);
};

#endif