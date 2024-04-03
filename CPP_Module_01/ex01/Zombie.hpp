/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:17:45 by lribette          #+#    #+#             */
/*   Updated: 2024/04/03 17:08:48 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	std::string	get_name();
	void	set_name(std::string name);
	void	announce();
	void	kill();
};

Zombie* zombieHorde( int N, std::string name );