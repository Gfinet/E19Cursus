/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:14:13 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/14 18:51:42 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	this->_Type = "DiamondTrap";
	this->_MaxHealth = FragTrap::_MaxHealth;
	this->_Health = FragTrap::_Health;
	this->_Energy = ScavTrap::_Energy;
	this->_Attack = FragTrap::_Attack;
	std::cout << "Empty constuctor called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name), ScavTrap(Name), FragTrap(Name)
{
	this->_Type = "DiamondTrap";
	this->_Name = Name;
	this->_MaxHealth = FragTrap::_MaxHealth;
	this->_Health = FragTrap::_Health;
	this->_Energy = ScavTrap::_Energy;
	this->_Attack = FragTrap::_Attack;
	std::cout << "Constuctor called for DiamondTrap " << this->_Name << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "copy constructor called for DiamondTrap" << std::endl;
	this->_Type = src._Type;
	this->_Name = src._Name;
	this->_Attack = src._Attack;
	this->_Health = src._Health;
	this->_MaxHealth = src ._MaxHealth;
	this->_Energy = src._Energy;
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
	if (!this->_Health)
	{
		std::cout << "DiamondTrap " << this->_Name << " trying to talk but is dead..." << std::endl;
		return;
	}
	if (this->_Name == "Dio")
		std::cout << "KONO DIIIIIIO DA !!!" << std::endl;
	else
		std::cout << "Ore wa " << this->_Type << " " << this->_Name << " des !" << std::endl;
}

void DiamondTrap::Jattack()
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
	std::cout << "ORA ";
}
