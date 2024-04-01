/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:31:42 by lribette          #+#    #+#             */
/*   Updated: 2024/04/01 18:20:24 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#define OUTLINE "\033[38;2;245;196;38;1m"
#define ADD "\033[38;2;52;181;74;1mADD\033[0m"
#define SEARCH "\033[38;2;120;80;252;1mSEARCH\033[0m"
#define EXIT "\033[38;2;193;32;32;1mEXIT\033[0m"
#define ERROR "\033[38;2;170;0;0;1m"
#define BLUE "\033[38;2;75;186;220;1m"
#define RESET "\033[0m"

#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		int		index_contact;
	public:
		Phonebook();
		~Phonebook();

		void	init();
		int		add_contact();
		int		search();
};

#endif