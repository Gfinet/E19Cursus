/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:25:04 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 15:03:28 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	this->Type = "FragTrap";
	this->MaxHealth = 100;
	this->Health = 100;
	this->Energy = 100;
	this->Attack = 30;
	std::cout << "Empty constuctor called for FragTrap " << this->Name << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	this->Type = "FragTrap";
	this->MaxHealth = 100;
	this->Health = 100;
	this->Energy = 100;
	this->Attack = 30;
	std::cout << "Constuctor called for FragTrap " << this->Name << std::endl;
}

FragTrap::FragTrap( FragTrap const & src )
{
	std::cout << "copy constructor called for FragTrap " << this->Name << std::endl;
	this->Type = src.Type;
	this->Name = src.Name;
	this->Attack = src.Attack;
	this->Health = src.Health;
	this->MaxHealth = src.MaxHealth;
	this->Energy = src.Energy;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called for FragTrap " << this->Name << std::endl;
}

FragTrap& FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "Assignator called for FragTrap" << std::endl;
	this->Name = rhs.Name;
	this->Type = rhs.Type;
	this->Attack = rhs.Attack;
	this->Health = rhs.Health;
	this->MaxHealth = rhs.MaxHealth;
	this->Energy = rhs.Energy;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->Type << " " << this->Name << " made a High Five !" << std::endl;
}
