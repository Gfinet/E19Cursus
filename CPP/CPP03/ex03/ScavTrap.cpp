/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:25:04 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 14:52:46 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	this->Type = "ScavTrap";
	this->MaxHealth = 100;
	this->Health = 100;
	this->Energy = 50;
	this->Attack = 20;
	std::cout << "Empty constuctor called for ScavTrap " << this->Name << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	this->Type = "ScavTrap";
	this->MaxHealth = 100;
	this->Health = 100;
	this->Energy = 50;
	this->Attack = 20;
	std::cout << "Constuctor called for ScavTrap " << this->Name << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src )
{
	std::cout << "copy constructor called for ScavTrap " << this->Name << std::endl;
	this->Name = src.Name;
	this->Type = src.Type;
	this->Attack = src.Attack;
	this->Health = src.Health;
	this->MaxHealth = src.MaxHealth;
	this->Energy = src.Energy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap " << this->Name << std::endl;
}

ScavTrap& ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "Assignator called for ScavTrap " << this->Name << std::endl;
	this->Name = rhs.Name;
	this->Type = rhs.Type;
	this->Attack = rhs.Attack;
	this->Health = rhs.Health;
	this->MaxHealth = rhs.MaxHealth;
	this->Energy = rhs.Energy;
	return *this;
}

void ScavTrap::guardGate()
{
	//this->Energy--;
	std::cout << this->Type << " " << this->Name << " is now in Gate keeper mode." << std::endl;
	//std::cout << "Energy left : " << this->Energy << std::endl;
}
