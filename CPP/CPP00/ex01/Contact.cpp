/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:13:37 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/11 21:42:25 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "[Contact constructor called]" << std::endl;
	first_name = "";
	last_name = "";
	nick_name = "";
	phone_number = "";
	dark_secret = "";
}

Contact::~Contact()
{
	std::cout << "[Contact destructor called]" << std::endl;
}

Contact::Contact(const Contact &other)
{
	std::cout << "[Contact copy constuctor called]" << std::endl;
	this->set_first_name(other.first_name);
	this->set_last_name(other.last_name);
	this->set_nick_name(other.nick_name);
	this->set_phone_number(other.phone_number);
	this->set_dark_secret(other.dark_secret);
}

Contact& Contact::operator=(const Contact &other)
{
	std::cout << "[Contact assignator called]" << std::endl;
	this->first_name = other.first_name; 
	this->last_name = other.last_name; 
	this->nick_name = other.nick_name; 
	this->phone_number = other.phone_number; 
	this->dark_secret = other.dark_secret; 
	return *this;
}

void Contact::set_first_name(const std::string str)
{
	this->first_name = str;
}
void Contact::set_last_name(const std::string str)
{
	this->last_name = str;
}
void Contact::set_nick_name(const std::string str)
{
	this->nick_name = str;
}
void Contact::set_phone_number(const std::string str)
{
	this->phone_number = str;
}
void Contact::set_dark_secret(const std::string str)
{
	this->dark_secret = str;
}

const std::string Contact::get_first_name()
{
	return this->first_name;
}
const std::string Contact::get_last_name()
{
	return this->last_name;
}
const std::string Contact::get_nick_name()
{
	return this->nick_name;
}
const std::string Contact::get_phone_number()
{
	return this->phone_number;
}
const std::string Contact::get_dark_secret()
{
	return this->dark_secret;
}

const std::string Contact::get_tronc_fname()
{
	std::string temp;
	
	temp = this->first_name.substr(0, 9);
	temp += '.';
	return temp;
}

std::string Contact::get_tronc_lname()
{
	std::string temp;
	
	temp = this->last_name.substr(0, 9);
	temp += '.';
	return temp;
}

std::string Contact::get_tronc_nname()
{
	std::string temp;
	
	temp = this->nick_name.substr(0, 9);
	temp += '.';
	return temp;
}

std::string Contact::get_tronc_phnum()
{
	std::string temp;
	
	temp = this->phone_number.substr(0, 9);
	temp += '.';
	return temp;
}

std::string Contact::get_tronc_dsec()
{
	std::string temp;
	
	temp = this->dark_secret.substr(0, 9);
	temp += '.';
	return temp;
}
