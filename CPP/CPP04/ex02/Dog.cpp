/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:14:00 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:39:13 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() : AAnimal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog empty constructor is called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor is called" << std::endl;
	*this = other;
	return;
}

// Copy assignment overload
Dog &Dog::operator=(const Dog &rhs)
{
	int i = -1;
	std::cout << "Dog operator = is called" << std::endl;
	this->type = rhs.type;
	while (++i < rhs.brain->getNbIdeas())
		this->brain->addIdea(rhs.brain->getIdeas(i));
	return *this;
}

// Default destructor
Dog::~Dog() 
{
	delete this->brain;
	std::cout << "Dog destrucor is called" << std::endl;
	return;
}

void Dog::makeSound() const
{
	std::cout << "FOOD FOOD PLAY PLAY FRIEND FRIEND STILL... WAFF !" << std::endl;
}

Brain* Dog::getBrain()
{
	return this->brain;
}

void Dog::addIdea(std::string idea)
{
	this->brain->addIdea(idea);
}

std::string Dog::getIdea(int i) const
{
    return brain->getIdeas(i);
}