/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:42:11 by Gfinet            #+#    #+#             */
/*   Updated: 2025/01/07 14:37:01 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "Triangle.hpp"


#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point x(2.0f,1.0f), y(5.0f,1.0f), z(2.0f,2.0f), p(3.0f, 2.5f), q(0.5f, 0.5f), r(4.0f, 1.0f);
	Triangle t(x, y, z);
	Line a(x,y);

	a.on_line(z, 1);
	std::cout << std::endl;
	std::cout << "p " << p << "   not in t : "  << point_in_triangle(t, p) << std::endl;
	std::cout << "q " << q << "     in t : " << point_in_triangle(t, q) << std::endl;
	std::cout << "r " << q << "     on t : " << point_in_triangle(t, r) << std::endl;

	std::cout << std::endl;
	
	std::cout << "p " << p << "   not in t : "  << bsp(x, y, z, p) << std::endl;
	std::cout << "q " << q << "     in t : " << bsp(x, y, z, q) << std::endl;
	std::cout << "r " << q << "     on t : " << bsp(x, y, z, r) << std::endl;
	return 0;
}
