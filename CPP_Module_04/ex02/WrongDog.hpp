/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:29 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 18:52:41 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongDog();
		WrongDog(WrongDog &copy);
		WrongDog &operator=(const WrongDog &src);
		~WrongDog();

		void makeSound() const;
		std::string getType() const;
};
