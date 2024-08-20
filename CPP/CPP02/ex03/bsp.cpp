/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:33:42 by gfinet            #+#    #+#             */
/*   Updated: 2024/08/20 18:51:10 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point AB, AC, BC;
	Point Ap;

	AB.set_x(a.get_x() - b.get_x());
	AB.set_y(a.get_y() - b.get_y());

	AC.set_x(a.get_x() - c.get_x());
	AC.set_y(a.get_y() - c.get_y());

	BC.set_x(b.get_x() - c.get_x());
	BC.set_y(b.get_y() - c.get_y());

	Ap.set_x(a.get_x() - point.get_x());
	Ap.set_y(a.get_y() - point.get_y());

	std::cout << point.get_x() << "\n";
	std::cout << "AB : {" << AB.get_x() << ", " << AB.get_y() << "}\n";
	std::cout << "AC : {" << AC.get_x() << ", " << AC.get_y() << "}\n";
	std::cout << "BC : {" << BC.get_x() << ", " << BC.get_y() << "}\n";
	return (1);
}