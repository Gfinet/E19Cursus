/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:47:06 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/13 17:09:10 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.hpp"
#include <cstdlib>

Base * generate(void)
{
	Base *ret;
	int rand;

	srand(time(0));

	rand = std::rand() % 3;
	switch (rand)
	{
	case 0:
		ret = new A();
		break;
	case 1:
		ret = new B();
		break;
	case 2:
		ret = new C();
		break;
	
	default:
		ret = nullptr;
		break;
	}
	return ret;
}

void identify(Base* p)
{
	std::cout << "ptr identify : ";
	if (dynamic_cast<A*>(p))
		std::cout << "A type" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B type" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C type" << std::endl;
}

void identify(Base& p)
{
	std::cout << "ref identify : ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A type" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B type" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "C type" << std::endl;
		}
		
	}
	// try
	// {
	// 	(void)dynamic_cast<B&>(p);
	// 	std::cout << "B type" << std::endl;
	// }
	// catch(const std::exception& e){}
	// try
	// {
	// 	(void)dynamic_cast<C&>(p);
	// 	std::cout << "C type" << std::endl;
	// }
	// catch(const std::exception& e){}

}
