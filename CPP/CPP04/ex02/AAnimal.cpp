/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:10:22 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 15:31:51 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Default constructor
AAnimal::AAnimal() 
{
	this->type = "BEEUUUWAAA C'EST QUOI CE TRUC?!";
	std::cout << "AAnimal empty constructor is called" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor is called" << std::endl;
	this->type = other.type;
	return;
}

// Copy assignment overload
AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	std::cout << "AAnimal operator = is called" << std::endl;
	this->type = rhs.type;
	return *this;
}

// Default destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destrucor is called" << std::endl;
	return;
}

const std::string AAnimal::getType()
{
	return this->type;
}

void AAnimal::makeSound()
{
	std::cout << "Ed..ward.. want... to play ?" << std::endl;
}