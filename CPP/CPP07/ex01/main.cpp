/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:27:17 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/14 20:40:59 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int ari[5] = {1,2,3,4,5};
	float arf[5] = {1.1,2.2,3.3,4.4,5.5};
	char arc[5] = {'a','b','c','d','e'};

	for (int i=0; i<5; i++)
		std::cout << ari[i] << " ";
	std::cout << std::endl;
	iter(ari, 5, doubleVal);
	for (int i=0; i<5; i++)
		std::cout << ari[i] << " ";
	std::cout << std::endl;
	iter(ari, 5, plusOne);
	for (int i=0; i<5; i++)
		std::cout << ari[i] << " ";
	std::cout << std::endl;
	
	for (int i=0; i<5; i++)
		std::cout << arf[i] << " ";
	std::cout << std::endl;
	iter(arf, 5, doubleVal);
	for (int i=0; i<5; i++)
		std::cout << arf[i] << " ";
	std::cout << std::endl;
	iter(arf, 5, plusOne);
	for (int i=0; i<5; i++)
		std::cout << arf[i] << " ";
	std::cout << std::endl;

	for (int i=0; i<5; i++)
		std::cout << arc[i] << " ";
	std::cout << std::endl;
	iter(arc, 5, plusOne);
	for (int i=0; i<5; i++)
		std::cout << arc[i] << " ";
	std::cout << std::endl;
	iter(arc, 5, plusOne);
	for (int i=0; i<5; i++)
		std::cout << arc[i] << " ";
	return 0;
}