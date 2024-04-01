/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:22:26 by lribette          #+#    #+#             */
/*   Updated: 2024/04/01 15:38:06 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact::Contact() { return ; }
Contact::~Contact() { return ; }

int			Contact::get_index()			{ return this->index; }
std::string	Contact::get_first_name()		{ return this->first_name; }
std::string	Contact::get_last_name()		{ return this->last_name; }
std::string	Contact::get_nickname()			{ return this->nickname; }
std::string	Contact::get_phone_number()		{ return this->phone_number; }
std::string	Contact::get_darkest_secret()	{ return this->darkest_secret; }

void	Contact::set_index(int number)					{ this->index = number; }
void	Contact::set_first_name(std::string str)		{ this->first_name = str; }
void	Contact::set_last_name(std::string str)			{ this->last_name = str; }
void	Contact::set_nickname(std::string str)			{ this->nickname = str; }
void	Contact::set_phone_number(std::string str)		{ this->phone_number = str; }
void	Contact::set_darkest_secret(std::string str)	{ this->darkest_secret = str; }
