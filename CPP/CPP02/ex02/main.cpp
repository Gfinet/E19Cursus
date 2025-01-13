/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:42:11 by Gfinet            #+#    #+#             */
/*   Updated: 2025/01/13 18:36:51 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	float x, y;
	Fixed a, e;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	e = Fixed(150.32f);
	a = Fixed( 1234.4321f );
	x = 1234.4321f;
	y = 10;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "a is " << a.toFloat() << " as floating" << std::endl;
	std::cout << "b is " << b.toFloat() << " as floating" << std::endl;
	std::cout << "c is " << c.toFloat() << " as floating" << std::endl;
	std::cout << "d is " << d.toFloat() << " as floating" << std::endl;

	std::cout << a << " : a++ " << a++ << " " << a << std::endl;
	std::cout << a << " : ++a " << ++a << " " << a << std::endl;
	std::cout << a << " : --a " << --a << " " << a << std::endl;
	std::cout << a << " : a-- " << a-- << " " << a << std::endl;
	std::cout << "a-- is " << a << std::endl << std::endl;

	std::cout << "Comparison between what Should Be (sb) and the result (is)" << std::endl;
	std::cout << "a * a is " << (a * a) << std::endl;
	std::cout << "a * a sb " << (x * x) << std::endl << std::endl;
	std::cout << "a + a is " << (a + a) << std::endl;
	std::cout << "a + a sb " << (x + x) << std::endl << std::endl;
	std::cout << "a - a is " << (a - a) << std::endl;
	std::cout << "a - a sb " << (x - x) << std::endl << std::endl;
	std::cout << "a / b is " << (a / b) << std::endl;
	std::cout << "a / b sb " << (x / y) << std::endl << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a > b sb " << (x > y) << std::endl << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a < b sb " << (x < y) << std::endl << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "a <= b sb " << (x <= y) << std::endl << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a >= b sb " << (x >= y) << std::endl << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl;
	std::cout << "a != b sb " << (x != y) << std::endl << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a == b sb " << (x == y) << std::endl;

	std::cout << "min(a,e) sb " << e << std::endl;
	std::cout << "min(a,e) is " << min(a,e) << std::endl;
	std::cout << "max(a,e) sb " << a << std::endl;
	std::cout << "max(a,e) is " << max(a,e) << std::endl << std::endl;

	std::cout << "const min(b,c) sb " << b << std::endl;
	std::cout << "const min(b,c) is " << min(b,c) << std::endl;
	std::cout << "const max(b,c) sb " << c << std::endl;
	std::cout << "const max(b,c) is " << max(b,c) << std::endl << std::endl;
	return 0;
}