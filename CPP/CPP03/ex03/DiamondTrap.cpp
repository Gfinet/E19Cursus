/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:14:13 by gfinet            #+#    #+#             */
/*   Updated: 2024/12/10 17:34:40 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	this->_Type = "DiamondTrap";
	this->_MaxHealth = FragTrap::MaxHealth;
	this->_Health = FragTrap::Health;
	this->_Energy = ScavTrap::Energy;
	this->_Attack = FragTrap::Attack;
	std::cout << "Empty constuctor called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name), ScavTrap(Name), FragTrap(Name)
{
	this->_Type = "DiamondTrap";
	this->_Name = Name;
	this->_MaxHealth = FragTrap::MaxHealth;
	this->_Health = FragTrap::Health;
	this->_Energy = ScavTrap::Energy;
	this->_Attack = FragTrap::Attack;
	std::cout << "Constuctor called for DiamondTrap " << this->_Name << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src )
{
	std::cout << "copy constructor called for DiamondTrap" << std::endl;
	this->_Type = src._Type;
	this->_Name = src._Name;
	this->_Attack = src._Attack;
	this->_Health = src._Health;
	this->_MaxHealth = src ._MaxHealth;
	this->_Energy = src.Energy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called for DiamondTrap " << this->_Name << std::endl;
}

DiamondTrap& DiamondTrap::operator=( DiamondTrap const & rhs )
{
	std::cout << "Assignator called for DiamondTrap" << std::endl;
	this->_Type = rhs._Type;
	this->_Name = rhs._Name;
	this->_Attack = rhs._Attack;
	this->_Health = rhs._Health;
	this->_Energy = rhs._Energy;
	this->_MaxHealth = rhs ._MaxHealth;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Ore wa " << this->_Type << " " << this->_Name << " des !" << std::endl;
}

