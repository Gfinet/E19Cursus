/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:25:04 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/14 17:43:25 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _Type("ClapTrap"), _Name("Bobby"), _MaxHealth(10), _Health(10), _Energy(10), _Attack(0)
{
	std::cout << "Empty constuctor called for ClapTrap " << this->_Name << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : _Type("ClapTrap"), _Name(Name), _MaxHealth(10), _Health(10), _Energy(10), _Attack(0)
{
	std::cout << "Constuctor called for ClapTrap " << this->_Name << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src )
{
	std::cout << "copy constructor called for ClapTrap " << std::endl;
	this->_Type = src._Type;
	this->_Name = src._Name;
	this->_MaxHealth = src ._MaxHealth;
	this->_Health = src._Health;
	this->_Attack = src._Attack;
	this->_Energy = src._Energy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap " << this->_Name << std::endl;
}

ClapTrap& ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "Assignator called for ClapTrap " << this->_Name << std::endl;
	this->_Type = rhs._Type;
	this->_Name = rhs._Name;
	this->_MaxHealth = rhs ._MaxHealth;
	this->_Health = rhs._Health;
	this->_Attack = rhs._Attack;
	this->_Energy = rhs._Energy;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_Health == 0)
	{
		std::cout << this->_Type << " " << this->_Name << " trying to attack but is dead..." << std::endl;
		return ;
	}
	if (this->_Energy == 0)
	{
		std::cout << this->_Type << " " << this->_Name << " trying to attack but has no Energy left" << std::endl;
		return;
	}
	this->_Energy--;
	std::cout << this->_Type << " " << this->_Name << " attacks " << target ;
	std::cout << " causing " << this->_Attack << " points of damage !" << std::endl;
	std::cout << "Energy left : " << this->_Energy << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Health - (int)amount < 0)
		this->_Health = 0;
	else
		this->_Health -= amount;
	std::cout << this->_Type << " " << this->_Name << " took " << amount ;
	std::cout << " points of damage !" << std::endl;
	if (this->_Health > 0)
		std::cout << "Health left : " << this->_Health << "HP" << std::endl;
	else
		std::cout << this->_Name << " is dead.." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Health == 0)
	{
		std::cout << this->_Type << " " << this->_Name << " trying to heal but is dead..." << std::endl;
		return ;
	}
	if (this->_Energy == 0)
	{
		std::cout << this->_Type << " " << this->_Name << " trying to heal but has no Energy left" << std::endl;
		return;
	}
	this->_Energy--;
	if (this->_Health + amount > (unsigned int)this->_MaxHealth)
		this->_Health = 10;
	else
		this->_Health += amount;
	std::cout << this->_Type << " " << this->_Name << " repaired himself for " << amount << " HP " << std::endl;
	if (this->_Health < this->_MaxHealth)
		std::cout << "Health : " << this->_Health << "HP" << std::endl;
	else
		std::cout << this->_Name << " is full life ! (" << this->_Health << ")" << std::endl;
	std::cout << "Energy left : " << this->_Energy << std::endl;
}

std::string ClapTrap::get_Name()
{
	return this->_Name;
}

int ClapTrap::get_Health()
{
	return this->_Health;
}

int ClapTrap::get_Energy()
{
	return this->_Energy;
}

int ClapTrap::get_Attack()
{
	return this->_Attack;
}
