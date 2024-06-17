/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:53:57 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 15:16:36 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{

}
Zombie::Zombie(std::string hisName)
{
	name = hisName;
}
Zombie::~Zombie()
{
	std::cout << "Zombie " << name;
	std::cout << " goes back to cemetary\n\n";

}
Zombie& Zombie::operator=(const Zombie &other)
{
	this->name = other.name;
	return (*this);
}

void Zombie::announce()
{
	std::cout << name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ...";
	if (name == "Michael Jackson")
		std::cout << "he he...";
	std::cout << "\n";
}