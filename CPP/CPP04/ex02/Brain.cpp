/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:42:18 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/27 18:05:52 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

// Default constructor
Brain::Brain()
{ 
	nbIdeas = 0;
}

// Copy constructor
Brain::Brain(const Brain &other)
{
	*this = other;
	return;
}

// Copy assignment overload
Brain &Brain::operator=(const Brain &rhs)
{
	int i = -1;
	while (++i < rhs.nbIdeas)
		this->ideas[i] = rhs.ideas[i];
	return *this;
}

// Default destructor
Brain::~Brain() {}

int Brain::getNbIdeas()
{
	return this->nbIdeas;
}

std::string Brain::getIdeas(int i)
{
	int ind;
	if (i < 0 && i > -101)
	{
		ind = 100 + i;
		return this->ideas[ind];
	}
	else if (i > 99 || i < -101)
	{
		std::cout << "Out of bound" << std::endl;
		return NULL;
	}
	else
		return this->ideas[i];
}

void Brain::addIdea(std::string idea)
{
	if (this->nbIdeas < 100)
	{
		this->ideas[nbIdeas] = idea;
		this->nbIdeas++;
		std::cout << "idea " << idea << " added." << std::endl;
		std::cout << "count of ideas : " << this->nbIdeas << std::endl;
	}
	if (this->nbIdeas == 100)
		std::cout << "Number of maximum idea reached. Can't add more." << std::endl;
}
