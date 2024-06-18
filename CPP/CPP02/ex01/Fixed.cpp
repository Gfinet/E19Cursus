/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:47:54 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/18 19:21:36 by gfinet           ###   ########.fr       */
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
	_intVal = 0;
	_floatVal = 0;
}
Fixed::Fixed(int n)
{
	std::cout << "Default constructor called\n";
	_intVal = n;
	_floatVal = 0;
}
Fixed::Fixed(float n)
{
	int neg = 0, valI = 0;
	float reste = 0;

	std::cout << "n    " << n << '\n';
	neg = (n < 0);
	
	if (neg)
	{
		valI = -(int)n;
		reste = n + valI;
	}
	else
	{
		valI = (int)n;
		reste = n - valI;
	}
	
	std::cout << "neg  " << neg << '\n';
	std::cout << "valI " << valI << '\n';
	std::cout << "rest " << reste << '\n';
	std::cout << "Default constructor called\n";
	//_intVal = n;
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	_intVal = other._intVal;
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
		this->_intVal = other.getRawBits();
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_intVal = raw;
}

int Fixed::toInt( void ) const
{
	int val(_intVal);

	return val;
}

float Fixed::toFloat( void ) const
{
	float val(_intVal);
	//std::cout << val << "\n";
	return val;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_intVal);
}

/* ************************************************************************** */

std::ostream &operator<<( std::ostream &o, Fixed const &i )
{
	o << i.getRawBits() ; //<< " " <<  i._floatVal;
	return o;
}