/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:12:44 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:41:44 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat empty constructor is called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other): Animal(other)
{
	std::cout << "Cat copy constructor is called" << std::endl;
	*this = other;
	return;
}

// Copy assignment overload
Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat operator = is called" << std::endl;
	this->type = rhs.type;
	return *this;
}

// Default destructor
Cat::~Cat() 
{
	std::cout << "Cat destrucor is called" << std::endl;
	return;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Bitch !" << std::endl;
}

