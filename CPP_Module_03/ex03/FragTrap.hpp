/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:52:26 by lribette          #+#    #+#             */
/*   Updated: 2024/04/15 18:43:37 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	private:
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &copy);
		FragTrap &operator=(const FragTrap &src);
		~FragTrap();
		
		void attack(const std::string& target);
		void highFivesGuys();
};
