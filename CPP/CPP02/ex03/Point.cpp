/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:18:00 by gfinet            #+#    #+#             */
/*   Updated: 2024/12/26 02:39:37 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"
#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Point::Point(): _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
}

Point::Point(Point const &src)
{
	*this = src;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
Point::~Point()
{
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &Point::operator=(Point const &rhs)
{
	_x = rhs._x;
	_y = rhs._y;
	return *this;
}
/*
** --------------------------------- METHODS ----------------------------------
*/

void	Point::set_x(float x)
{
	_x = Fixed(x);
}
void	Point::set_y(float y)
{
	_y = Fixed(y);
}
void	Point::set_x(Fixed x)
{
	_x = x;
}
void	Point::set_y(Fixed y)
{
	_y = y;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed Point::get_x(void) const
{
	return this->_x;
}
Fixed Point::get_y(void) const
{
	return this->_y;
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	o << "(" << i.get_x() << " , " << i.get_y() << ")";
	return o;
}