/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:14:13 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 14:50:55 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	this->Type = "DiamondTrap";
	this->MaxHealth = FragTrap::MaxHealth;
	this->Health = FragTrap::Health;
	this->Energy = ScavTrap::Energy;
	this->Attack = FragTrap::Attack;
	std::cout << "Empty constuctor called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name), ScavTrap(Name), FragTrap(Name)
{
	this->Type = "DiamondTrap";
	this->Name = Name;
	this->MaxHealth = FragTrap::MaxHealth;
	this->Health = FragTrap::Health;
	this->Energy = ScavTrap::Energy;
	this->Attack = FragTrap::Attack;
	std::cout << "Constuctor called for DiamondTrap " << this->Name << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src )
{
	std::cout << "copy constructor called for DiamondTrap" << std::endl;
	this->Type = src.Type;
	this->Name = src.Name;
	this->Attack = src.Attack;
	this->Health = src.Health;
	this->MaxHealth = src.MaxHealth;
	this->Energy = src.Energy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called for DiamondTrap " << this->Name << std::endl;
}

DiamondTrap& DiamondTrap::operator=( DiamondTrap const & rhs )
{
	std::cout << "Assignator called for DiamondTrap" << std::endl;
	this->Type = rhs.Type;
	this->Name = rhs.Name;
	this->Attack = rhs.Attack;
	this->Health = rhs.Health;
	this->Energy = rhs.Energy;
	this->MaxHealth = rhs.MaxHealth;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Ore wa " << this->Type << " " << this->Name << " des !" << std::endl;
}

