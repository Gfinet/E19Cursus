/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:28:15 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/18 00:08:42 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

Harl::Harl()
{

}
Harl::~Harl()
{

}
void Harl::debug()
{
	std::cout << "[DEBUG]\n" ;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << "\n";
}
void Harl::info()
{
	std::cout << "[INFO]" << "\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << "\n";
}
void Harl::warning()
{
	std::cout << "[WARNING]" << "\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << "\n";
}
void Harl::error()
{
	std::cout << "[ERROR]" << "\n";
	std::cout << "This is unacceptable ! I want to speak to the manager now." << "\n";
}

void test()
{
	std::cout << "test1\n";
}

void Harl::complain(std::string level)
{
	int lvl = 0;
	void (Harl::*funcs[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; 
	std::string msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while(lvl < 4)
	{
		if (!level.compare(msg[lvl]))
			(this->*funcs[lvl])();
		lvl++;
	}
}