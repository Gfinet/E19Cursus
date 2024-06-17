/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:21:55 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 15:44:16 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;
	int i = 0;
	
	horde = new Zombie[N];
	while (i < N)
	{
		horde[i] = *new Zombie(name);
		i++;
	}
	return horde;
}