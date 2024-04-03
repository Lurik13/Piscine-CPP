/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:24:48 by lribette          #+#    #+#             */
/*   Updated: 2024/04/03 15:39:55 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(std::string str);
		~Zombie();

		void		announce();
		std::string	get_name();
};

Zombie 	*newZombie(std::string name);
void 	randomChump( std::string name );
