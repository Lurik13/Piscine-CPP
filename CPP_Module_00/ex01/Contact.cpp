/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:22:26 by lribette          #+#    #+#             */
/*   Updated: 2024/03/31 18:03:58 by lribette         ###   ########.fr       */
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

std::string	Contact::add_attribute(std::string request, int norm)
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

void	Contact::add_contact()
{
	static int	i = 0;
	this->index = i++;
	this->first_name = add_attribute("First name", 1);
	this->last_name = add_attribute("Last name", 1);
	this->nickname = add_attribute("Nickname", 0);
	this->phone_number = add_attribute("Phone number", 1);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, this->darkest_secret);

	std::cout << "index = " << this->index << std::endl
	<< "first name = " << this->first_name << std::endl 
	<< " last name = " << this->last_name << std::endl
	<< " nickname = " << this->nickname << std::endl
	<< " phone = " << this->phone_number << std::endl
	<< " darkest secret = " << darkest_secret << std::endl;
}

int			Contact::get_index() { return this->index; }
std::string	Contact::get_first_name() { return this->first_name; }
std::string	Contact::get_last_name() { return this->last_name; }
std::string	Contact::get_nickname() { return this->nickname; }
std::string	Contact::get_phone_number() { return this->phone_number; }
std::string	Contact::get_darkest_secret() { return this->darkest_secret; }