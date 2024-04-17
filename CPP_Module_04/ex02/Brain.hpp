/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:51:13 by lribette          #+#    #+#             */
/*   Updated: 2024/04/17 15:57:16 by lribette         ###   ########.fr       */
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
};
