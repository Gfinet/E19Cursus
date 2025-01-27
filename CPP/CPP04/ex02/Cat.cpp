/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:12:44 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/27 18:05:22 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : AAnimal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat empty constructor is called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other) : AAnimal(other)
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
	delete this->brain;
	std::cout << "Cat destrucor is called" << std::endl;
	return;
}

void Cat::makeSound()
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