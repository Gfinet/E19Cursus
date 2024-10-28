/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:42:07 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/22 14:59:34 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap bobby;
	ClapTrap Max("Max");
	ClapTrap Alex("Alex");
	bobby = Alex;

	
	std::cout << std::endl;
	for (int i = 0; i < 11 ; i++)
		bobby.attack("Rob");
	std::cout << std::endl;
	Max.takeDamage(9);
	Max.beRepaired(5);
	Max.takeDamage(1);
	Max.beRepaired(4);
	Max.takeDamage(10);
	Max.beRepaired(4);
	Max.attack("Rob");
	std::cout << std::endl;

	ScavTrap Omni("Omni");
	Omni.attack("Rob");
	Omni.takeDamage(50);
	Omni.beRepaired(25);
	Omni.guardGate();
	std::cout << std::endl;

	FragTrap Boom("Boom");
	Boom.attack("Rob");
	Boom.takeDamage(50);
	Boom.beRepaired(25);
	Boom.highFivesGuys();
	std::cout << std::endl;

	DiamondTrap Jojo("Jojo");
	Jojo.attack("Dio");
	Jojo.takeDamage(50);
	Jojo.beRepaired(25);
	Jojo.attack("Dio");
	Jojo.highFivesGuys();
	Jojo.guardGate();
	Jojo.whoAmI();
	std::cout << std::endl;
	
	return 0;
}
