/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:25:04 by gfinet            #+#    #+#             */
/*   Updated: 2024/12/10 17:34:40 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	this->_Type = "FragTrap";
	this->_MaxHealth = 100;
	this->_Health = 100;
	this->_Energy = 100;
	this->_Attack = 30;
	std::cout << "Empty constuctor called for FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	this->_Type = "FragTrap";
	this->_MaxHealth = 100;
	this->_Health = 100;
	this->_Energy = 100;
	this->_Attack = 30;
	std::cout << "Constuctor called for FragTrap " << this->_Name << std::endl;
}

FragTrap::FragTrap( FragTrap const & src )
{
	std::cout << "copy constructor called for FragTrap" << std::endl;
	this->_Name = src._Name;
	this->_Type = src._Type;
	this->_Attack = src._Attack;
	this->_Health = src._Health;
	this->_MaxHealth = src ._MaxHealth;
	this->_Energy = src.Energy;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called for FragTrap " << this->_Name << std::endl;
}

FragTrap& FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "Assignator called for FragTrap" << std::endl;
	this->_Name = rhs._Name;
	this->_Type = rhs._Type;
	this->_Attack = rhs._Attack;
	this->_Health = rhs._Health;
	this->_MaxHealth = rhs ._MaxHealth;
	this->_Energy = rhs._Energy;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_Name << " made a High Five !" << std::endl;
}
