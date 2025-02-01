/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:39:58 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:41:25 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() 
{
	this->type = "BEEUUUWAAA C'EST QUOI CE TRUC?!";
	std::cout << "WrongAnimal empty constructor is called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor is called" << std::endl;
	*this = other;
	return;
}

// Copy assignment overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "WrongAnimal operator = is called" << std::endl;
	this->type = rhs.type;
	return *this;
}

// Default destructor
WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal destrucor is called" << std::endl;
	return;
}

const std::string WrongAnimal::getType()
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Ed..ward.. want... to play ?" << std::endl;
}