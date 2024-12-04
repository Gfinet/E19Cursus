/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:55 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 16:40:55 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
//#include "AAnimal.hpp"
#include "WrongCat.hpp"
//#include "WrongAnimal.hpp"

#include <iostream>
#include <string>

int main(void)
{
	{
		//AAnimal* meta = new Animal();
		AAnimal* j = new Dog();
		AAnimal* i = new Cat();
		std::cout << std::endl;
		std::cout << "Cat type : " << i->getType() << " " << std::endl;
		std::cout << "Dog type : " << j->getType() << " " << std::endl;
		std::cout << std::endl;
		
		std::cout << "Cat sound : " << std::endl;
		i->makeSound(); //will output the cat sound!
		std::cout << "Dog sound : " << std::endl;
		j->makeSound();
		// std::cout << "AAnimal sound ? : " << std::endl;
		// meta->makeSound();
		// std::cout << std::endl;
		
		//delete meta;
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
		std::cout << "WrongAAnimal sound ? : " << std::endl;
		badmeta->makeSound();
		std::cout << std::endl;
		std::cout << std::endl;

		delete badmeta;
		delete badj;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		AAnimal *list[16];
		int i = -1;
		
		while (++i < 16)
		{
			if (i < 8)
				list[i] = new Dog();
			else
				list[i] = new Cat();
		}
		std::cout << std::endl;
		std::cout << std::endl;
		i = -1;
		while (++i < 16)
			delete list[i];
	}
	return 0;
}