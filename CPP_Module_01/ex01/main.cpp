/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:17:42 by lribette          #+#    #+#             */
/*   Updated: 2024/04/05 09:48:44 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	number_of_zombies = std::atoi(argv[1]);
		if (number_of_zombies > 0 && number_of_zombies <= 2147483)
		{
			Zombie *horde = zombieHorde(std::atoi(argv[1]), "grrrr");
			for (int i = 0; i < std::atoi(argv[1]); i++)
				horde->announce();
			delete [] horde;
		}
		else
			std::cout << "Wrong number." << std::endl;
	}
	else
		std::cout << "./horde <number_of_zombies>" << std::endl;
}
