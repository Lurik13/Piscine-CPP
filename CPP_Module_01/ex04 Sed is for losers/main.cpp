/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:19:00 by lribette          #+#    #+#             */
/*   Updated: 2024/04/08 15:02:01 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::fstream	inputFile;
		inputFile.open(argv[1], std::fstream::in);
		if (!inputFile)
		{
			std::cout << "Error while opening " << argv[1] << ".\n";
			return (1);
		}
		replace(inputFile, argv[1], argv[2], argv[3]);
		inputFile.close();
	}
	else
		std::cout << "Wrong number of params." << std::endl;
}
