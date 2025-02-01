/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:12:44 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:40:08 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat empty constructor is called" << std::endl;
	this->brain = new Brain();
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor is called" << std::endl;
	*this = other;
	return;
}

// Copy assignment overload
Cat &Cat::operator=(const Cat &rhs)
{
	int i = -1;
	std::cout << "Cat operator = is called" << std::endl;
	this->type = rhs.type;
	while (++i < rhs.brain->getNbIdeas())
		this->brain->addIdea(rhs.brain->getIdeas(i));
	return *this;
}

// Default destructor
Cat::~Cat() 
{
	std::cout << "Cat destrucor is called" << std::endl;
	delete this->brain;
	return;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Bitch !" << std::endl;
}

Brain* Cat::getBrain()
{
	return this->brain;
}

void Cat::addIdea(std::string idea)
{
	this->brain->addIdea(idea);
}

std::string Cat::getIdea(int i) const
{
    return brain->getIdeas(i);
}