/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:24:48 by lribette          #+#    #+#             */
/*   Updated: 2024/04/05 19:26:13 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string str);
		~Zombie();

		void		announce();
		std::string	get_name();
};

Zombie 	*newZombie(std::string name);
void 	randomChump( std::string name );
