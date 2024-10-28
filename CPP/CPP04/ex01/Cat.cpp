/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:12:44 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 16:17:33 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat empty constructor is called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other)
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