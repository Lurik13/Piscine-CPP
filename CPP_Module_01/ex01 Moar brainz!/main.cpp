/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:17:42 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 12:02:05 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	is_number(char *str)
{
	for (int i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!is_number(argv[1]))
		{
			std::cout << "Wrong number." << std::endl;
			return (EXIT_FAILURE);
		}
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
