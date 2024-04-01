/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:31:49 by lribette          #+#    #+#             */
/*   Updated: 2024/04/01 16:02:20 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->index_contact = 0;
	return ;
}

Phonebook::~Phonebook() { return ; }

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

std::string	Phonebook::add_attribute(std::string request, int norm)
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

void	Phonebook::add_contact()
{
	static int	i = 1;
	if (i == 9)
	{
		i = 1;
		this->index_contact = 0;
	}
	
	this->contacts[this->index_contact].set_index(i);
	this->contacts[this->index_contact].set_first_name(add_attribute("First name", 1));
	this->contacts[this->index_contact].set_last_name(add_attribute("Last name", 1));
	this->contacts[this->index_contact].set_nickname(add_attribute("Nickname", 0));
	this->contacts[this->index_contact].set_phone_number(add_attribute("Phone number", 1));
	this->contacts[this->index_contact].set_darkest_secret(add_attribute("Darkest secret", 0));

	std::cout << "index = " << this->contacts[this->index_contact].get_index() << std::endl
	<< "first name = " << this->contacts[this->index_contact].get_first_name() << std::endl
	<< "last name = " << this->contacts[this->index_contact].get_last_name() << std::endl
	<< "nickname = " << this->contacts[this->index_contact].get_nickname() << std::endl
	<< "phone = " << this->contacts[this->index_contact].get_phone_number() << std::endl
	<< "darkest secret = " << this->contacts[this->index_contact].get_darkest_secret() << std::endl;

	i++;
	this->index_contact++;
}
