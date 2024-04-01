/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:31:53 by lribette          #+#    #+#             */
/*   Updated: 2024/04/01 18:37:38 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	display_phonebook_home()
{
	std::cout << OUTLINE 
	<< "╔═════════════════════════════════════════════════╗" << std::endl
	<< "║" RESET "          ☎️  Welcome to my Phonebook! 😁         " OUTLINE "║" << std::endl
	<< "║" RESET " You can type 3 commands:                        " OUTLINE "║" << std::endl
	<< "║" RESET " " ADD "    : Adds a contact to the phonebook.       " OUTLINE "║" << std::endl
	<< "║" RESET " " SEARCH " : Searchs a contact in your contact list." OUTLINE "║" << std::endl
	<< "║" RESET " " EXIT "   : Exits the phonebook.                   " OUTLINE "║" << std::endl
	<< "╚═════════════════════════════════════════════════╝" RESET << std::endl;
}

void	display_commands()
{
	std::cout << OUTLINE 
	<< "┌─────────────────────────────────────────────────┐" << std::endl
	<< "│" RESET "       " ADD "     |     " SEARCH "     |     " EXIT "       " OUTLINE "│" << std::endl
	<< "└─────────────────────────────────────────────────┘" RESET << std::endl;
}

int	main(void)
{
	Phonebook phonebook;
	display_phonebook_home();
	phonebook.init();
	std::string input = "";
	int	i = 0;
	
	while (input != "EXIT")
	{
		if (input == "ADD")
			i = phonebook.add_contact();
		if (input == "SEARCH")
			i = phonebook.search();
		if (i)
			display_commands();
		std::getline(std::cin, input);
	}
}
