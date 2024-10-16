/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:42:07 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/16 20:00:01 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	Max.takeDamage(1);
	Max.beRepaired(5);
	Max.beRepaired(5);
	std::cout << std::endl;
	return 0;
}