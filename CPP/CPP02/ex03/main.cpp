/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:42:11 by Gfinet            #+#    #+#             */
/*   Updated: 2024/12/10 17:17:25 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "Triangle.hpp"


#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point x(1.0f,1.0f), y(5.0f,1.0f), z(2.0f,1.0f);

	// std::cout << x << " " << y << " " << z << std::endl;
	Line a(x,y);

	a.on_line(z);
	return 0;
}
