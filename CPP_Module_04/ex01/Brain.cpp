/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:51:53 by lribette          #+#    #+#             */
/*   Updated: 2024/04/17 16:22:39 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "No idea yet.";
	std::cout << PURPLE << "Brain constructed.\n" << RESET;
}

Brain::Brain(std::string *str)
{
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = str[i];
}

Brain::Brain(Brain &copy)
{
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i] + " from copy.";
	std::cout << PURPLE << "Brain constructed from copy.\n" << RESET;
}

Brain &Brain::operator=(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}
Brain::~Brain()
{
	delete [] this->_ideas;
	std::cout << PURPLE << "Brain destructed.\n" << RESET;

}
