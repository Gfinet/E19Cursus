/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:47:54 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/24 16:26:21 by gfinet           ###   ########.fr       */
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
Fixed::Fixed(int n)
{
	std::cout << "Default constructor called\n";
	_val = n;
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
	_val = other._val;
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
	int val(_val);

	return val;
}

float Fixed::toFloat( void ) const
{
	float val(_val);
	//std::cout << val << "\n";
	return val;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_val);
}

/* ************************************************************************** */

std::ostream &operator<<( std::ostream &o, Fixed const &i )
{
	o << i.getRawBits() ; //<< " " <<  i._floatVal;
	return o;
}