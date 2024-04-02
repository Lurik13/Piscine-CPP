/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:31:49 by lribette          #+#    #+#             */
/*   Updated: 2024/04/02 13:48:22 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->index_contact = 0;
	return ;
}
Phonebook::~Phonebook() { return ; }

/* ************************************************************************** */

void	Phonebook::init()
{
	for (int i = 0; i < 8; i++)
	{
		this->contacts[i].set_index(i + 1);
		this->contacts[i].set_first_name("");
		this->contacts[i].set_last_name("");
		this->contacts[i].set_nickname("");
		this->contacts[i].set_phone_number("");
		this->contacts[i].set_darkest_secret("");
	}
}

/* ************************************************************************** */

int	Phonebook::_does_respect_name_norm(std::string str)
{
	if (!std::isupper(str[0]))
		return (0);
	int i = 1;
	for (i = 1; (str[i] && std::isalpha(str[i])); i++)
		if (std::isupper(str[i]))
			return (0);
	if (str[i])
		return (0);
	return (1);
}

int	Phonebook::_does_respect_phone_norm(std::string str)
{
	int i = 0;
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (i != 10 || str[0] != '0' || str[1] == '0')
		return (0);
	return (1);
}

std::string	Phonebook::_add_attribute(std::string request, int norm)
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
					if (_does_respect_phone_norm(attribute))
						break ;
				}
				else if (_does_respect_name_norm(attribute))
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
	this->contacts[this->index_contact].set_first_name(_add_attribute("First name", 1));
	this->contacts[this->index_contact].set_last_name(_add_attribute("Last name", 1));
	this->contacts[this->index_contact].set_nickname(_add_attribute("Nickname", 0));
	this->contacts[this->index_contact].set_phone_number(_add_attribute("Phone number", 1));
	this->contacts[this->index_contact].set_darkest_secret(_add_attribute("Darkest secret", 0));

	std::cout << BLUE << this->contacts[this->index_contact].get_nickname()
	<< RESET << " has been added to the phonebook." << std::endl << std::endl;
	
	i++;
	this->index_contact++;
	return (1);
}

/* ************************************************************************** */

void	Phonebook::_print_column(std::string str)
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

void	Phonebook::_print_search()
{
	std::cout << OUTLINE
	<< "┌-------------------------------------------┐" << std::endl;
	_print_column("INDEX");
	_print_column("FIRST NAME");
	_print_column("LAST NAME");
	_print_column("NICKNAME");
	std::cout << OUTLINE << "|" << std::endl
	<< "├-------------------------------------------┤" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" RESET "         " << this->contacts[i].get_index();
		_print_column(this->contacts[i].get_first_name());
		_print_column(this->contacts[i].get_last_name());
		_print_column(this->contacts[i].get_nickname());
		std::cout << OUTLINE "|" << std::endl;
	}
	std::cout << OUTLINE
	<< "└-------------------------------------------┘" RESET
	<< std::endl << std::endl;
}

int	Phonebook::search()
{
	this->_print_search();
	while (1)
	{
		std::cout << "Contact index : ";
		std::string	index;
		std::cin >> index;
		if (index.length() == 1 && index[0] >= '1' && index[0] <= '8')
		{
			this->contacts[index[0] - 49].print_contact();
			break ;
		}
		else
			std::cout << ERROR "Incorrect index!" RESET << std::endl;
	}
	return (1);
}
