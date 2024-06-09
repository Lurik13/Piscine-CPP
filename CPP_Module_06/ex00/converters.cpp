/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:35:02 by marvin            #+#    #+#             */
/*   Updated: 2024/06/09 10:35:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int whichType(std::string str)
{
	int nb_dots = 0;

	if (str.length() == 1 && !isdigit(str[0]))
	{
		return (CHAR);
	}
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '.')
			nb_dots++;
		if (nb_dots > 1 || (str[i] == '.' && (i == 0 || !str[i + 1]))
			|| (str[i] == 'f' && (i == 0 || str[i + 1]))
			|| (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			|| (str[i] == '.' && str[i + 1] && str[i + 1] == 'f')
			|| (str[i] == 'f' && nb_dots == 0))
			return (IMPOSSIBLE);
	}
	if (str.find('f') != std::string::npos)
		return (FLOAT);
	if (nb_dots > 0)
		return (DOUBLE);
	return (INT);
}

void	printChar(std::string str)
{
	std::cout << "char: " << str << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}
