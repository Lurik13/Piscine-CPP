/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:31:49 by lribette          #+#    #+#             */
/*   Updated: 2024/04/02 12:50:22 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->index_contact = 0;
	return ;
}
Phonebook::~Phonebook() { return ; }

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

void	Phonebook::ft_print_search()
{
	std::cout << OUTLINE
	<< "┌-------------------------------------------┐" << std::endl;
	ft_print_column("INDEX");
	ft_print_column("FIRST NAME");
	ft_print_column("LAST NAME");
	ft_print_column("NICKNAME");
	std::cout << OUTLINE << "|" << std::endl
	<< "├-------------------------------------------┤" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" RESET "         " << this->contacts[i].get_index();
		ft_print_column(this->contacts[i].get_first_name());
		ft_print_column(this->contacts[i].get_last_name());
		ft_print_column(this->contacts[i].get_nickname());
		std::cout << OUTLINE "|" << std::endl;
	}
	std::cout << OUTLINE
	<< "└-------------------------------------------┘" RESET
	<< std::endl << std::endl;
}

int	Phonebook::search()
{
	this->ft_print_search();
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
	
	//a faire : si espace ou tiret dans nom

	return (1);
}
