/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:46:59 by lribette          #+#    #+#             */
/*   Updated: 2024/04/09 10:22:57 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;
	if (argc == 2)
		harl.complain(argv[1]);
	else
		std::cout << "\033[38;2;170;0;0;1m./harlFilter <level>" << std::endl;
}