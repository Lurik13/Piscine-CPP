/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:51:13 by lribette          #+#    #+#             */
/*   Updated: 2024/06/25 14:17:03 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Brain
{
	private:
		std::string *_ideas;
	public:
		Brain();
		Brain(std::string *str);
		Brain(Brain &copy);
		Brain &operator=(const Brain &src);
		~Brain();

		std::string getIdeas(void);
		void		setIdeas(int index, std::string new_idea);
};
