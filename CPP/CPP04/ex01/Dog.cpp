/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:14:00 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 16:17:27 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog empty constructor is called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
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

void Dog::makeSound()
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