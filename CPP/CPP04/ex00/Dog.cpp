/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:14:00 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 14:58:20 by gfinet           ###   ########.fr       */
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

void Dog::makeSound()
{
	std::cout << "FOOD FOOD PLAY PLAY FRIEND FRIEND STILL... WAFF !" << std::endl;
}