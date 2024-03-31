/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:31:42 by lribette          #+#    #+#             */
/*   Updated: 2024/03/31 17:45:59 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#define OUTLINE "\033[38;2;245;196;38;1m"
#define ADD "\033[38;2;52;181;74;1m ADD    \033[0m"
#define SEARCH "\033[38;2;120;80;252;1m SEARCH \033[0m"
#define EXIT "\033[38;2;193;32;32;1m EXIT   \033[0m"
#define ERROR "\033[38;2;170;0;0;1m"
#define RESET "\033[0m"

#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		// int		contacts_number;
	public:
};

#endif