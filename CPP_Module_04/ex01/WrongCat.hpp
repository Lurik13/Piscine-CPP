/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:12:00 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 18:52:35 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongCat();
		WrongCat(WrongCat &copy);
		WrongCat &operator=(const WrongCat &src);
		~WrongCat();

		void makeSound() const;
		std::string getType() const;
};
