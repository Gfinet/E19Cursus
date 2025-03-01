/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:42:12 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:40:42 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat empty constructor is called" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor is called" << std::endl;
	*this = other;
	return;
}

// Copy assignment overload
WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat operator = is called" << std::endl;
	this->type = rhs.type;
	return *this;
}

// Default destructor
WrongCat::~WrongCat() 
{
	std::cout << "WrongCat destrucor is called" << std::endl;
	return;
}

void WrongCat::makeSound() const
{
	std::cout << "Wiaou Citch !" << std::endl;
}