/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:37:38 by lribette          #+#    #+#             */
/*   Updated: 2024/04/15 18:43:46 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	private:
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &src);
		~ScavTrap();
		
		void attack(const std::string& target);
		void guardGate();
};
