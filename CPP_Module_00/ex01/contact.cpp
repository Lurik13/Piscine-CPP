/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:22:26 by lribette          #+#    #+#             */
/*   Updated: 2024/03/30 11:04:08 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

#define OUTLINE "\033[38;2;245;196;38;1m"
#define ADD "\033[38;2;52;181;74;1m ADD    \033[0m"
#define SEARCH "\033[38;2;120;80;252;1m SEARCH \033[0m"
#define EXIT "\033[38;2;193;32;32;1m EXIT   \033[0m"
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

int	main(void)
{
	display_phonebook_home();
	std::string input;
	std::cin >> input;
	std::cout << "mot entre : " << input << std::endl;
}