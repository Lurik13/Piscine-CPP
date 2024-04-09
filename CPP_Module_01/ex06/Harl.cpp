/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:47:48 by lribette          #+#    #+#             */
/*   Updated: 2024/04/09 10:21:52 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {return ;}

Harl::~Harl() {return ;}

void Harl::debug()
{
	std::cout << GREEN DEBUG_MSG RESET << std::endl;
}

void Harl::info()
{
	std::cout << PURPLE INFO_MSG RESET << std::endl;
}

void Harl::warning()
{
	std::cout << ORANGE WARNING_MSG RESET << std::endl;
}

void Harl::error()
{
	std::cout << RED ERROR_MSG RESET << std::endl;
}

void Harl::complain(std::string level)
{
	void	(Harl::*fxptr[])() \
		= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	lvlptr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t i = 0;

	while (level != lvlptr[i])
	{
		if (i == 4)
		{
			std::cout << WHITE NOT_FOUND RESET << std::endl;
			return ;
		}
		i++;
	}
	(this->*fxptr[i])();
}
