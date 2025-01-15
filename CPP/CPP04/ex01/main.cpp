/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:55 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/15 19:30:14 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
//#include "Animal.hpp"
#include "WrongCat.hpp"
//#include "WrongAnimal.hpp"

#include <iostream>
#include <string>

int main(void)
{
	/*
	{
		Animal* meta = new Animal();
		Animal* j = new Dog();
		Animal* i = new Cat();
		std::cout << std::endl;
		std::cout << "Cat type : " << i->getType() << " " << std::endl;
		std::cout << "Dog type : " << j->getType() << " " << std::endl;
		std::cout << std::endl;
		
		std::cout << "Cat sound : " << std::endl;
		i->makeSound(); //will output the cat sound!
		std::cout << "Dog sound : " << std::endl;
		j->makeSound();
		std::cout << "Animal sound ? : " << std::endl;
		meta->makeSound();
		std::cout << std::endl;
		
		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << std::endl;
		std::cout << std::endl;

		WrongAnimal* badmeta = new WrongAnimal();
		WrongAnimal* badj = new WrongCat();

		std::cout << "WrongCat sound ? : " << std::endl;
		badj->makeSound();
		std::cout << "WrongAnimal sound ? : " << std::endl;
		badmeta->makeSound();
		std::cout << std::endl;
		std::cout << std::endl;

		delete badmeta;
		delete badj;
		std::cout << std::endl;
		std::cout << std::endl;
	}*/
	{
		Animal *list[16];
		int i = -1;
		
		while (++i < 16)
		{
			if (i == 8)
				std::cout << std::endl;
			if (i < 8)
				list[i] = new Dog();
			else
				list[i] = new Cat();
		}
		std::cout << std::endl;
		std::cout << std::endl;
		i = -1;
		while (++i < 16)
		{
			if (i == 8)
				std::cout << std::endl;
			delete list[i];
		}
	}
	return 0;
}