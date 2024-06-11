/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:02:11 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/11 21:26:39 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "[Phone constructor called]" << std::endl;
	this->old_cont = 0;
	this->nb_cont = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "[Phone destructor called]" << std::endl;
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	int i = 0;
	Contact *tmp;

	std::cout << "[Phone copy constuctor called]" << std::endl;
	this->old_cont = other.old_cont;
	this->nb_cont = other.nb_cont;
	while (i < other.nb_cont)
	{
		tmp = new Contact(other.lst[i]);
		this->lst[i] = *tmp;
		i++;
	}
}

PhoneBook& PhoneBook::operator=(const PhoneBook &other)
{
	int i = 0;

	std::cout << "[Phone assignator called]" << std::endl;
	this->old_cont = other.old_cont;
	this->nb_cont = other.nb_cont;
	while (i < other.nb_cont)
	{
		this->lst[i] = other.lst[i];
		i++;
	}
	return *this;
}

void PhoneBook::print_top_list()
{
	std::cout << std::setw(10);
	std::cout << "Index " << '|';
	std::cout << std::setw(10);
	std::cout << "First N. " << '|';
	std::cout << std::setw(10);
	std::cout << "Last N. " << '|';
	std::cout << std::setw(10);
	std::cout << "Nick N. " << '|';
	std::cout << std::setw(10);
	std::cout << "GSM num. " << '|';
	std::cout << std::setw(10);
	std::cout << "Dark sec. " << std::endl;
}

void PhoneBook::print_contact(int i)
{
	std::cout << std::setw(10);
	std::cout << i + 1 << '|';
	std::cout << std::setw(10);
	if (this->lst[i].get_first_name().size() < 11)
		std::cout << lst[i].get_first_name() << '|';
	else
		std::cout << lst[i].get_tronc_fname() << '|' ;
	
	std::cout << std::setw(10);
	if (this->lst[i].get_last_name().size() < 11)
		std::cout << lst[i].get_last_name() << '|';
	else
		std::cout << lst[i].get_tronc_lname() << '|' ;
	
	std::cout << std::setw(10);
	if (this->lst[i].get_nick_name().size() < 11)
		std::cout << lst[i].get_nick_name() << '|';
	else
		std::cout << lst[i].get_tronc_nname() << '|' ;
	
	std::cout << std::setw(10);
	if (this->lst[i].get_phone_number().size() < 11)
		std::cout << lst[i].get_phone_number() << '|';
	else
		std::cout << lst[i].get_tronc_phnum() << '|' ;
	std::cout << std::setw(10);
	if (this->lst[i].get_dark_secret().size() < 11)
		std::cout << lst[i].get_dark_secret() << '|';
	else
		std::cout << lst[i].get_tronc_dsec() << '|' ;
	std::cout << std::endl;
}

void PhoneBook::print_info(int i)
{
	std::cout << "First Name   : " << lst[i].get_first_name() << std::endl;
	std::cout << "Last Name    : " << lst[i].get_last_name() << std::endl;
	std::cout << "Nickname     : " << lst[i].get_nick_name() << std::endl;
	std::cout << "Phone Number : " << lst[i].get_phone_number() << std::endl;
	std::cout << "Dark secret  : " << lst[i].get_dark_secret() << std::endl << std::endl;
}

void PhoneBook::set_contact(Contact c, int i)
{
	this->lst[i] = c;
	this->nb_cont++;
}

void PhoneBook::add(void)
{
	int i = 0;
	std::string str;
	Contact *new_cont = new Contact;
	
	std::cout << "What's the first name?" << std::endl; 
	std::cin >> str;
	new_cont->set_first_name(str);
	std::cout << "What's the last name?" << std::endl; 
	std::cin >> str;
	new_cont->set_last_name(str);
	std::cout << "What's the nickname?" << std::endl; 
	std::cin >> str;
	new_cont->set_nick_name(str);
	std::cout << "What's the number?" << std::endl; 
	std::cin >> str;
	new_cont->set_phone_number(str);
	std::cout << "What's the dark secret?" << std::endl; 
	std::cin >> str;
	new_cont->set_dark_secret(str);
	while ( i < this->nb_cont)
		i++;
	std::cout << "i : " << i << std::endl;
	std::cout << "old_cont : " << this->old_cont << std::endl;
	if (i == 7)
	{
		//delete &lst[old_cont];
		lst[old_cont] = *new_cont;
		old_cont++;
		old_cont *= (old_cont != 7);
	}
	else
		lst[this->nb_cont] = *new_cont;
	if (this->nb_cont < 7)
		this->nb_cont++;
}

void PhoneBook::search(void)
{
	int i = 0;
	char c = nb_cont + '0';
	std::string str;

	print_top_list();
	while (i < nb_cont)
		print_contact(i++);
	std::cout << "Which contact do you wanna get the informations?" << std::endl;
	std::cout << "Write the index of the contact or 0 to leave" << std::endl;
	std::cin >> str;
	while (1)
	{
		if (str.size() > 1 || str.size() == 0 || str[0] < '0' || str[0] > c)
		{
			std::cout << "Wrong entry" << std::endl; 
			std::cout << "Which contact do you wanna get the informations?" << std::endl; 
		}
		else if (str[0] == '0')
		{
			std::cout << "Operation canceled" << std::endl;
			break;
		}
		else
		{
			i = str[0] - '0' - 1;
			print_info(i);
			break ;
		}
		std::cin >> str;
	}
}

void PhoneBook::exit(void)
{
	std::cout << "exit" << std::endl;
}