/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:08:10 by lribette          #+#    #+#             */
/*   Updated: 2024/04/05 19:37:24 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	Weapon	_weapon;
	std::string	_name;
public:
	HumanA(std::string name, Weapon weapon);
	~HumanA();
	void	setName(std::string name);
	std::string	getName();
	void	attack();
};

#endif