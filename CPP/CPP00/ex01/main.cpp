/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:11:36 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/09 17:21:23 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void get_choice(std::string *in)
{
	std::cout << "Do you want to add a contact? Type ADD" << std::endl;
	std::cout << "Do you search a contact? Type SEARCH" << std::endl;
	std::cout << "to exit, type EXIT" << std::endl;
	std::cin >> *in;
}

int main(void)
{
	std::string in = "a";
	PhoneBook phone;

	while (in.size() > 0)
	{
		get_choice(&in);
		if (!std::strcmp(in.c_str(), "ADD"))
		{
			phone.add();
		}
		else if (!std::strcmp(in.c_str(), "SEARCH"))
		{
			phone.search();
		}
		else if (!std::strcmp(in.c_str(), "EXIT"))
		{
			phone.exit();
			break;
		}
		else
		{
			std::cout << "BAD ENTRY ! TRY AGAIN" << std::endl;
		}
	}
	system("leaks My_Phone");
	return (0);
}