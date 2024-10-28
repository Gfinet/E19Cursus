/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:10:22 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 15:31:51 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() 
{
	this->type = "BEEUUUWAAA C'EST QUOI CE TRUC?!";
	std::cout << "Animal empty constructor is called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor is called" << std::endl;
	this->type = other.type;
	return;
}

// Copy assignment overload
Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal operator = is called" << std::endl;
	this->type = rhs.type;
	return *this;
}

// Default destructor
Animal::~Animal()
{
	std::cout << "Animal destrucor is called" << std::endl;
	return;
}

const std::string Animal::getType()
{
	return this->type;
}

void Animal::makeSound()
{
	std::cout << "Ed..ward.. want... to play ?" << std::endl;
}