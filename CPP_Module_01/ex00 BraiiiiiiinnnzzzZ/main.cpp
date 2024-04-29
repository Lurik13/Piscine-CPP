/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:24:21 by lribette          #+#    #+#             */
/*   Updated: 2024/04/03 15:55:50 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie("Foo");
	zombie.announce();
	Zombie *Edouard = newZombie("Aaaaa");
	Edouard->announce();
	delete Edouard;
	randomChump("zzzzzzzzzzzzzzzzzzzombie");
}