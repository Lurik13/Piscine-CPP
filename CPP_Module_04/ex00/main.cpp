/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:24:52 by lribette          #+#    #+#             */
/*   Updated: 2024/04/16 19:41:35 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		std::cout << "-------------------\n";
		const Animal* dog = new Dog();
		std::cout << "-------------------\n";
		const Animal* cat = new Cat();
		std::cout << "-------------------\n";

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		meta->makeSound();

		std::cout << "-------------------\n";
		delete cat;
		std::cout << "-------------------\n";
		delete dog;
		std::cout << "-------------------\n";
		delete meta;
	}
	std::cout << "\n\n--------------------------------------\n\n\n";
	{
		const WrongAnimal* wmeta = new WrongAnimal();
		std::cout << "------------------------\n";
		const WrongAnimal* wdog = new WrongDog();
		std::cout << "------------------------\n";
		const WrongAnimal* wcat = new WrongCat();
		std::cout << "------------------------\n";

		std::cout << wdog->getType() << " " << std::endl;
		std::cout << wcat->getType() << " " << std::endl;
		wcat->makeSound();
		wdog->makeSound();
		wmeta->makeSound();

		std::cout << "-------------------\n";
		delete wcat;
		std::cout << "-------------------\n";
		delete wdog;
		std::cout << "-------------------\n";
		delete wmeta;
	}
}