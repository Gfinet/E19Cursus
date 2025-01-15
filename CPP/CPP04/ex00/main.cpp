/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:55 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/15 19:19:03 by gfinet           ###   ########.fr       */
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
	{
		Animal* meta = new Animal();
		Animal* j = new Dog();
		Animal* i = new Cat();
		std::cout << std::endl;
		std::cout << "Cat type : " << i->getType() << " " << std::endl;
		std::cout << "Dog type : " << j->getType() << " " << std::endl;
		std::cout << std::endl;
		
		std::cout << "Cat sound : " ;
		i->makeSound(); //will output the cat sound!
		std::cout << "Dog sound : " ;
		j->makeSound();
		std::cout << "Animal sound ? : ";
		meta->makeSound();
		std::cout << std::endl;
		
		delete meta;
		delete j;
		delete i;
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
		return 0;
	}
}