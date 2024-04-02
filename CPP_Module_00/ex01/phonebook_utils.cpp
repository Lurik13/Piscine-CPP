/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:45:37 by lribette          #+#    #+#             */
/*   Updated: 2024/04/02 12:50:30 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	does_respect_name_norm(std::string str)
{
	if (!std::isupper(str[0]))
		return (0);
	int i = 1;
	for (i = 1; (str[i] && (std::isalpha(str[i]) || std::isspace(str[i]))); i++)
		if (std::isupper(str[i]))
			return (0);
	if (str[i])
		return (0);
	return (1);
}

int	does_respect_phone_norm(std::string str)
{
	int i = 0;
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (str[i] || i != 10 || str[0] != '0' || str[1] == '0')
		return (0);
	return (1);
}

std::string	add_attribute(std::string request, int norm)
{
	std::string	attribute = "";
	std::string	incorrect = request;

	incorrect[0] = tolower(request[0]);
	while (1)
	{
		std::cout << request << " : ";
		if (std::getline(std::cin, attribute) && !attribute.empty())
		{
			if (norm)
			{
				if (request == "Phone number")
				{
					if (does_respect_phone_norm(attribute))
						break ;
				}
				else if (does_respect_name_norm(attribute))
						break ;
				std::cout << ERROR << "Incorrect " << incorrect << "!" RESET << std::endl;
			}
			else
				break ;
		}
	}
	return (attribute);
}

void	ft_print_column(std::string str)
{
	int	len = str.length();
	int	spaces = 10 - len;
	
	std::cout << OUTLINE << "|" << RESET;
	if (len <= 10)
	{
		for (int i = 0; i < spaces; i++)
			std::cout << " ";
		std::cout << str;
	}
	else
	{
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
	}
}

int	ft_is_number(std::string str)
{
	for (int i = 0; str[i]; i++)
		if (!std::isdigit(str[i]))
			return (0);
	return (1);
}
