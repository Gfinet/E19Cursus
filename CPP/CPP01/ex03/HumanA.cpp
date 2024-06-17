/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:57:35 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 18:00:19 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon& type) : weapon(type), name(Name)
{}
HumanA::~HumanA()
{

}
void HumanA::attack()
{
	std::cout << name << " attack with ";
	std::cout << weapon.getType() << "\n";

}