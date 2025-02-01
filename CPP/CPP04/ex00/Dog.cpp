/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:14:00 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:41:34 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog empty constructor is called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << "Dog copy constructor is called" << std::endl;
	*this = other;
	return;
}

// Copy assignment overload
Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog operator = is called" << std::endl;
	this->type = rhs.type;
	return *this;
}

// Default destructor
Dog::~Dog() 
{
	std::cout << "Dog destrucor is called" << std::endl;
	return;
}

void Dog::makeSound() const
{
	std::cout << "FOOD FOOD PLAY PLAY FRIEND FRIEND STILL... WAFF !" << std::endl;
}