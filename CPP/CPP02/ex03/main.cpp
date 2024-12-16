/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:42:11 by Gfinet            #+#    #+#             */
/*   Updated: 2024/12/16 17:06:34 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "Triangle.hpp"


#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point x(2.0f,1.0f), y(5.0f,1.0f), z(2.0f,2.0f), p(3.0f, 2.5f), q(0.5f, 0.5f);
	Triangle t(x, y, z);
	Line a(x,y);

	a.on_line(z, 1);
	std::cout << t.get_leftest_point_abs() << " " << t.get_rightest_point_abs() << std::endl;
	std::cout << t.get_top_point_ord() << " " << t.get_bot_point_ord() << std::endl << std::endl;
	std::cout << "p" << p << " in t" << std::endl << point_in_triangle(t, p) << std::endl;
	std::cout << "q" << q << " in t" << std::endl << point_in_triangle(t, q) << std::endl;
	return 0;
}
