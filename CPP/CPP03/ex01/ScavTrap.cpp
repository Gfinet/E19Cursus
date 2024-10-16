/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:25:04 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/16 20:57:11 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	this->Health = 100;
	this->Energy = 50;
	this->Attack = 20;
	std::cout << "Empty constuctor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	this->Health = 100;
	this->Energy = 50;
	this->Attack = 20;
	std::cout << "Constuctor called for ScavTrap " << this->Name << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src )
{
	std::cout << "copy constructor called for ScavTrap" << std::endl;
	this->Name = src.Name;
	this->Attack = src.Attack;
	this->Health = src.Health;
	this->Energy = src.Energy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap " << this->Name << std::endl;
}

ScavTrap& ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "Assignator called for ScavTrap" << std::endl;
	this->Name = rhs.Name;
	this->Attack = rhs.Attack;
	this->Health = rhs.Health;
	this->Energy = rhs.Energy;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->Energy == 0)
	{
		std::cout << "ScavTrap " << this->Name << " trying to attack but has no Energy left" << std::endl;
		return;
	}
	this->Energy--;
	std::cout << "ScavTrap " << this->Name << " attacks " << target ;
	std::cout << " causing " << this->Attack << " points of damage !" << std::endl;
	std::cout << "Energy left : " << this->Energy << std::endl;
}

void ScavTrap::guardGate()
{
	//this->Energy--;
	std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode." << std::endl;
	//std::cout << "Energy left : " << this->Energy << std::endl;
}
