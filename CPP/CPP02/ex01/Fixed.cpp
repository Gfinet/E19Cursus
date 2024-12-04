/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:47:54 by gfinet            #+#    #+#             */
/*   Updated: 2024/08/16 18:23:24 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::_nbBit = 8;
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	_val = 0;
}
Fixed::Fixed(const int n)
{
	std::cout << "int constructor called\n";
	
	_val = n * (1 << _nbBit);
}
Fixed::Fixed(const float n)
{
	_val = n * (1 << _nbBit);
	std::cout << "float constructor called\n";
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed&	Fixed::operator=( Fixed const &other )
{
	std::cout << "Copy Assignement operator called\n";
	if (this != &other)
		this->_val = other.getRawBits();
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_val = raw;
}

int Fixed::toInt( void ) const
{

	return (int)toFloat();
}

//number = (sign ? -1:1) * 2^(exponent) * 1.(mantissa bits)

float Fixed::toFloat( void ) const
{
	return (float)this->_val / (float)(1 << this->_nbBit);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called\n";
	return (this->_val);
}

/* ************************************************************************** */

std::ostream &operator<<( std::ostream &o, Fixed const &i )
{
	o << i.toFloat();
	return o;
}