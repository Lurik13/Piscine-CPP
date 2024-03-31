/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:31:53 by lribette          #+#    #+#             */
/*   Updated: 2024/03/31 17:51:09 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

void	display_phonebook_home()
{
	std::cout << OUTLINE "╔═════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║" RESET "          ☎️  Welcome to my Phonebook! 😁         " OUTLINE "║" << std::endl;
	std::cout << "║" RESET " You can type 3 commands:                        " OUTLINE "║" << std::endl;
	std::cout << "║" RESET ADD ": Adds a contact to the phonebook.       " OUTLINE "║" << std::endl;
	std::cout << "║" RESET SEARCH ": Searchs a contact in your contact list." OUTLINE "║" << std::endl;
	std::cout << "║" RESET EXIT ": Exits the phonebook.                   " OUTLINE "║" << std::endl;
	std::cout << "╚═════════════════════════════════════════════════╝" RESET << std::endl;
	
}

int	main(void)
{
	Contact	contact;
	display_phonebook_home();
	std::string input = "";
	while (input != "EXIT")
	{
		if (input == "ADD")
			contact.add_contact();
		if (input == "SEARCH")
			std::cout << "Bien recu search !" << input << std::endl;
		std::getline(std::cin, input);
	}
}
