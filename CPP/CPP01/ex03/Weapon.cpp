/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:00:02 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 17:46:16 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{

}
Weapon::Weapon(std::string name)
{
	type = name;
}

Weapon::Weapon(const Weapon &other)
{
	type = other.type;
}
const std::string& Weapon::getType()
{
	return type;
}

Weapon& Weapon::operator=(const Weapon &other)
{
	this->type = other.type;
	return *this;
}

Weapon::~Weapon()
{

}

void Weapon::setType(std::string name)
{
	type = name;
}