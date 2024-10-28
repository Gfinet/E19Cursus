/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:25:04 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 14:48:00 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : Type("ClapTrap"), Name("Bobby"), MaxHealth(10), Health(10), Energy(10), Attack(10)
{
	std::cout << "Empty constuctor called for " << this->Type << " " << this->Name << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : Type("ClapTrap"), Name(Name), MaxHealth(10), Health(10), Energy(10), Attack(10)
{
	std::cout << "Constuctor called for " << this->Type << " " << this->Name << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src )
{
	std::cout << "copy constructor called for ClapTrap " << std::endl;
	this->Type = src.Type;
	this->Name = src.Name;
	this->Attack = src.Attack;
	this->Health = src.Health;
	this->MaxHealth = src.MaxHealth;
	this->Energy = src.Energy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for " << this->Type << " " << this->Name << std::endl;
}

ClapTrap& ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "Assignator called for " << this->Type << " " << this->Name << std::endl;
	this->Type = rhs.Type;
	this->Name = rhs.Name;
	this->MaxHealth = rhs.MaxHealth;
	this->Health = rhs.Health;
	this->Attack = rhs.Attack;
	this->Energy = rhs.Energy;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->Health == 0)
	{
		std::cout << this->Type << " " << this->Name << " trying to attack but is dead..." << std::endl;
		return ;
	}
	if (this->Energy == 0)
	{
		std::cout << this->Type << " " << this->Name << " trying to attack but has no Energy left" << std::endl;
		return;
	}
	this->Energy--;
	std::cout << this->Type << " " << this->Name << " attacks " << target ;
	std::cout << " causing " << this->Attack << " points of damage !" << std::endl;
	std::cout << "Energy left : " << this->Energy << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Health - amount < 0)
		this->Health = 0;
	else
		this->Health -= amount;
	std::cout << this->Type << " " << this->Name << " took " << amount ;
	std::cout << " points of damage !" << std::endl;
	if (this->Health > 0)
		std::cout << "Health left : " << this->Health << "HP" << std::endl;
	else
		std::cout << this->Name << " is dead.." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Health == 0)
	{
		std::cout << this->Type << " " << this->Name << " trying to heal but is dead..." << std::endl;
		return ;
	}
	if (this->Energy == 0)
	{
		std::cout << this->Type << " " << this->Name << " trying to heal but has no Energy left" << std::endl;
		return;
	}
	this->Energy--;
	if (this->Health + amount > (unsigned int)this->MaxHealth)
		this->Health = 10;
	else
		this->Health += amount;
	std::cout << this->Type << " " << this->Name << " repaired himself for " << amount << " HP " << std::endl;
	if (this->Health < this->MaxHealth)
		std::cout << "Health : " << this->Health << "HP" << std::endl;
	else
		std::cout << this->Name << " is full life ! (" << this->Health << ")" << std::endl;
	std::cout << "Energy left : " << this->Energy << std::endl;
}

std::string ClapTrap::get_Name()
{
	return this->Name;
}

int ClapTrap::get_Health()
{
	return this->Health;
}

int ClapTrap::get_Energy()
{
	return this->Energy;
}

int ClapTrap::get_Attack()
{
	return this->Attack;
}
