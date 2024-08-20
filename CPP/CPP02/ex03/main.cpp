/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:42:11 by Gfinet            #+#    #+#             */
/*   Updated: 2024/08/20 17:23:00 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point a,b(0.5f, 5.2f),c(-5,0.2f);
	Point x(-1, 0), y(1, 2);
	
	bsp(a, b, c, x);
	return 0;
}
