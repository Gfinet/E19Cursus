/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:11:36 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/07 13:30:59 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	char *in;
	PhoneBook phone;

	std::cin >> in;
	while (in)
	{
		if (!strcmp(in, "ADD"))
		{

		}
		else if (!strcmp(in, "SEARCH"))
		{
			
		}
		else if (!strcmp(in, "EXIT"))
		{
			break;
		}
		else
		{
			std::cout << "BAD ENTRY ! TRY AGAIN" << std::endl;
		}
	}
	return 0;
}