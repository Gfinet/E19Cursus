/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:11:36 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/11 21:29:01 by Gfinet           ###   ########.fr       */
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
	Contact a, b, c, d, e, f;

	a.set_first_name("John");
	b.set_first_name("Jim");
	c.set_first_name("Joe");
	d.set_first_name("Jacques");
	e.set_first_name("James");
	f.set_first_name("Jerem");

	a.set_last_name("Holt");
	b.set_last_name("Hiren");
	c.set_last_name("Hores");
	d.set_last_name("Hirac");
	e.set_last_name("Hotter");
	f.set_last_name("Hi");

	a.set_nick_name("Jo");
	b.set_nick_name("Ji");
	c.set_nick_name("JJ");
	d.set_nick_name("Jake");
	e.set_nick_name("Jammy");
	f.set_nick_name("Jar-Jar");

	a.set_phone_number("0477889910");
	b.set_phone_number("0477889910");
	c.set_phone_number("0477889910");
	d.set_phone_number("0477889910");
	e.set_phone_number("0477889910");
	f.set_phone_number("0477889910");

	a.set_dark_secret("He doesn't know how to fly");
	b.set_dark_secret("His mom told him he was a boy");
	c.set_dark_secret("His job fired him for 6 month but keep paying him for the pranks");
	d.set_dark_secret("He's an politician under cover");
	e.set_dark_secret("He's a witcher... Oh,  a witch?");
	f.set_dark_secret("He's very dumb. Yeah");

	phone.set_contact(a, 0);
	phone.set_contact(b, 1);
	phone.set_contact(c, 2);
	phone.set_contact(d, 3);
	phone.set_contact(e, 4);
	phone.set_contact(f, 5);

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