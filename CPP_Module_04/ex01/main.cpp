/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:24:52 by lribette          #+#    #+#             */
/*   Updated: 2024/06/26 14:41:37 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		Dog basic;
		{
			Dog tmp = basic;
		}
		std::cout << "check" << std::endl;
	}
	std::cout << "\n\n--------------------------------------\n\n\n";
	{
		const Animal* meta = new Animal();
		std::cout << "-------------------\n";
		const Animal* dog = new Dog();
		std::cout << "-------------------\n";
		const Cat* cat = new Cat();
		std::cout << "-------------------\n";
		const Cat* cat2 = cat;
		std::cout << "-------------------\n";
		
		const Animal *(animals[6]);
		for (int i = 0; i < 3; i++)
		{
			animals[i] = new Dog();
			animals[i + 3] = new Cat();
		}
		std::cout << "-------------------\n";
		for (int i = 0; i < 6; i++)
			delete animals[i];
		std::cout << "-------------------\n";

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat2->makeSound();
		std::cout << "cat2 ideas = " << cat2->getBrainIdeas() << std::endl;;
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
		const WrongCat* wcatcat = new WrongCat();
		std::cout << "------------------------\n";

		std::cout << wdog->getType() << " " << std::endl;
		std::cout << wcat->getType() << " " << std::endl;
		std::cout << wcatcat->getType() << " " << std::endl;
		wcatcat->makeSound();
		wcat->makeSound();
		wdog->makeSound();
		wmeta->makeSound();

		std::cout << "-------------------\n";
		delete wcatcat;
		std::cout << "-------------------\n";
		delete wcat;
		std::cout << "-------------------\n";
		delete wdog;
		std::cout << "-------------------\n";
		delete wmeta;
	}
}
