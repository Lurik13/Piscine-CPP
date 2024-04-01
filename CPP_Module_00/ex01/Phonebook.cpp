/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:31:49 by lribette          #+#    #+#             */
/*   Updated: 2024/04/01 19:14:44 by lribette         ###   ########.fr       */
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

int	Phonebook::add_contact()
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

	std::cout << BLUE << this->contacts[this->index_contact].get_nickname()
	<< RESET << " has been added to the phonebook." << std::endl << std::endl;
	
	i++;
	this->index_contact++;
	return (1);
}

void	ft_print_column(std::string str)
{
	int	len = str.length();
	int	spaces = 10 - len;
	
	std::cout << OUTLINE << "|" << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << str;
}

void	Phonebook::init()
{
	for (int i = 0; i < 8; i++)
	{
		this->contacts[this->index_contact].set_index(i + 1);
		this->contacts[this->index_contact].set_first_name("");
		this->contacts[this->index_contact].set_last_name("");
		this->contacts[this->index_contact].set_nickname("");
		this->contacts[this->index_contact].set_phone_number("");
		this->contacts[this->index_contact].set_darkest_secret("");
	}
	
}

int	Phonebook::search()
{
	std::cout << "Bien recu search !" << std::endl;
	std::cout << OUTLINE
	<< "┌-------------------------------------------┐" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "i = " << i
		<< "|" RESET "         " << this->contacts[i].get_index();
		ft_print_column(this->contacts[i].get_first_name());
		ft_print_column(this->contacts[i].get_last_name());
		ft_print_column(this->contacts[i].get_nickname());
		std::cout << OUTLINE "|" << std::endl;
		std::cout << this->contacts[i].get_index() << " ";
	}
	//a faire : si strlen(str) > 10

	
	// std::cout << "│" RESET "       " ADD "     |     " SEARCH "     |     " EXIT "       " OUTLINE "│" << std::endl;
	// std::cout << "└─────────────────────────────────────────────────┘" RESET << std::endl;
	// this->contacts[0].print_contact();
	return (1);
}
