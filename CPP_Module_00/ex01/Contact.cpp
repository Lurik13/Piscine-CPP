/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:22:26 by lribette          #+#    #+#             */
/*   Updated: 2024/03/31 14:44:15 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cctype>
#include <string>

#define OUTLINE "\033[38;2;245;196;38;1m"
#define ADD "\033[38;2;52;181;74;1m ADD    \033[0m"
#define SEARCH "\033[38;2;120;80;252;1m SEARCH \033[0m"
#define EXIT "\033[38;2;193;32;32;1m EXIT   \033[0m"
#define ERROR "\033[38;2;170;0;0;1m"
#define RESET "\033[0m"

void	display_phonebook_home()
{
	std::cout << OUTLINE "╔═════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║" RESET "          ☎️  Welcome to my Phonebook! 😁         " OUTLINE "║" << std::endl;
	std::cout << "║" RESET " You can type 3 commands:                        " OUTLINE "║" << std::endl;
	std::cout << "║" RESET ADD ": Adds a contact to your phonebook.      " OUTLINE "║" << std::endl;
	std::cout << "║" RESET SEARCH ": Searchs a contact in your contact list." OUTLINE "║" << std::endl;
	std::cout << "║" RESET EXIT ": Exits the phonebook.                   " OUTLINE "║" << std::endl;
	std::cout << "╚═════════════════════════════════════════════════╝" RESET << std::endl;
	
}

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

std::string	Contact::add_attribute(std::string request)
{
	std::string	attribute = "";
	std::string	incorrect = request;

	incorrect[0] = tolower(request[0]);
	while (1)
	{
		std::cout << request << " : ";
		if (std::getline(std::cin, attribute) && !attribute.empty())
		{
			if (!request.compare("Phone number"))
			{
				if (does_respect_phone_norm(attribute))
					break ;
			}
			else if (does_respect_name_norm(attribute))
					break ;
			std::cout << ERROR << "Incorrect " << incorrect << "!" RESET << std::endl;
		}
	}
	return (attribute);
}

void	Contact::add_contact()
{
	this->first_name = add_attribute("First name");
	this->last_name = add_attribute("Last name");
	std::cout << "Nickname : ";
	std::getline(std::cin, this->nickname);
	this->phone_number = add_attribute("Phone number");
	std::cout << "Darkest secret : ";
	std::getline(std::cin, this->darkest_secret);
	std::cout << "first name = " << this->first_name << " last name = " << this->last_name << " nickname = " << this->nickname << " phone = " << this->phone_number << " darkest secret = " << darkest_secret << std::endl;
}

int	main(void)
{
	Contact	contact;
	display_phonebook_home();
	std::string input = "";
	while (input.compare("EXIT"))
	{
		if (!input.compare("ADD"))
			contact.add_contact();
		if (!input.compare("SEARCH"))
			std::cout << "Bien recu search !" << input << std::endl;
		std::getline(std::cin, input);
		// std::cin >> input;
	}
}
