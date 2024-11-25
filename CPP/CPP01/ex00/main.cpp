/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:07:15 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 15:18:01 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie a("Jacques"), b("JM");
	Zombie *c, *d;

	std::cout << "[on pile]\n";
	a.announce();
	b.announce();
	randomChump("Jean");
	randomChump("Bob");
	randomChump("Michael Jackson");
	
	std::cout << "\n[on stack]\n";
	c = newZombie("JustUngraved");
	d = newZombie("Bobby");

	c->announce();
	d->announce();
	std::cout << "\ndeleting JustUngraved\n";
	delete c;
	std::cout << "deleting Bobby\n";
	delete d;
	return 0;
}