/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:25:04 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/14 17:47:22 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	this->_Type = "ScavTrap";
	this->_MaxHealth = 100;
	this->_Health = 100;
	this->_Energy = 50;
	this->_Attack = 20;
	std::cout << "Empty constuctor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	this->_Type = "ScavTrap";
	this->_MaxHealth = 100;
	this->_Health = 100;
	this->_Energy = 50;
	this->_Attack = 20;
	std::cout << "Constuctor called for ScavTrap " << this->_Name << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src ) :ClapTrap(src)
{
	std::cout << "copy constructor called for ScavTrap" << std::endl;
	this->_Type = src._Type;
	this->_Name = src._Name;
	this->_Attack = src._Attack;
	this->_Health = src._Health;
	this->_MaxHealth = src ._MaxHealth;
	this->_Energy = src._Energy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap " << this->_Name << std::endl;
}

ScavTrap& ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "Assignator called for ScavTrap" << std::endl;
	this->_Type = rhs._Type;
	this->_Name = rhs._Name;
	this->_Attack = rhs._Attack;
	this->_Health = rhs._Health;
	this->_MaxHealth = rhs ._MaxHealth;
	this->_Energy = rhs._Energy;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_Energy == 0)
	{
		std::cout << "ScavTrap " << this->_Name << " trying to attack but has no Energy left" << std::endl;
		return;
	}
	if (this->_Health == 0)
	{
		std::cout << "ScavTrap " << this->_Name << " trying to attack but is dead..." << std::endl;
		return;
	}
	this->_Energy--;
	std::cout << "ScavTrap " << this->_Name << " attacks " << target ;
	std::cout << " causing " << this->_Attack << " points of damage !" << std::endl;
	std::cout << "Energy left : " << this->_Energy << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_Energy == 0)
	{
		std::cout << "ScavTrap " << this->_Name << " trying to guard but has no Energy left" << std::endl;
		return;
	}
	if (this->_Health == 0)
	{
		std::cout << "ScavTrap " << this->_Name << " trying to guard but is dead..." << std::endl;
		return;
	}
	this->_Energy--;
	std::cout << "ScavTrap " << this->_Name << " is now in Gate keeper mode." << std::endl;
	std::cout << "Energy left : " << this->_Energy << std::endl;
}
