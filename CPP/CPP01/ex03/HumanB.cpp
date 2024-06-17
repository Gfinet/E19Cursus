/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:57:35 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 18:01:48 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string Name)
{
	name = Name;
}
HumanB::~HumanB()
{

}
void HumanB::attack()
{
	std::cout << name << " attack with ";
	std::cout << weapon->getType() << "\n";

}
void HumanB::setWeapon(Weapon &type)
{
	weapon = &type;
}