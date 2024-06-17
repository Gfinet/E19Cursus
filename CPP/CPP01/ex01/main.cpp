/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:26:43 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 15:46:38 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int i = 0;
	Zombie *horde;

	horde = zombieHorde(5, "BWAAAAH");
	while (i < 5)
	{
		horde[i++].announce();
	}
		delete[] horde;
	return 0;
}