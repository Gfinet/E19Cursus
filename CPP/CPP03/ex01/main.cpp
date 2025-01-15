/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:42:07 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/14 18:57:30 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	/*
	ClapTrap bobby;
	ClapTrap Max("Max");
	ClapTrap Alex("Alex");
	bobby = Alex;
	
	std::cout << std::endl;
	for (int i = 0; i < 11 ; i++)
		bobby.attack("Rob");
	bobby.beRepaired(5);
	
	std::cout << std::endl;
	Max.takeDamage(9);
	Max.beRepaired(5);
	Max.beRepaired(5);
	Max.takeDamage(1);
	Max.takeDamage(9);
	Max.attack("Rob");
	Max.beRepaired(5);
	std::cout << std::endl;
	*/
	ScavTrap Omni("Omni"), scavi("Scavi");
	Omni.attack("Rob");
	Omni.takeDamage(50);
	Omni.beRepaired(25);
	Omni.guardGate();
	Omni.takeDamage(75);
	Omni.guardGate();
	Omni.beRepaired(25);
	for (int i=0; i < 51; i++)
		scavi.attack("Omni");
	scavi.guardGate();
	std::cout << std::endl;
	return 0;
}