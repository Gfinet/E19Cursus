/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:47:54 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/13 19:10:13 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::_nbBit = 8;
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Fixed::Fixed()
{
	//std::cout << "Default constructor called\n";
	_val = 0;
}
Fixed::Fixed(int n)
{
	//std::cout << "Default constructor called\n";
	_val = roundf(n * (1 << _nbBit));
}
Fixed::Fixed(float n)
{
	_val = roundf(n * (1 << _nbBit));
	//std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called\n";
	_val = other._val;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
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

bool	operator>( Fixed const &first, Fixed const &other )
{
	return (first.toFloat() > other.toFloat());
}

bool	operator<( Fixed const &first, Fixed const &other )
{
	return (first.toFloat() < other.toFloat());
}

bool	operator<=( Fixed const &first, Fixed const &other )
{
	return (first.toFloat() <= other.toFloat());

}

bool	operator>=( Fixed const &first, Fixed const &other )
{
	return (first.toFloat() >= other.toFloat());
}

bool	operator==( Fixed const &first, Fixed const &other )
{
	return first.toFloat() == other.toFloat();
}

bool	operator!=( Fixed const &first, Fixed const &other )
{
	return (first.toFloat() != other.toFloat());

}

float	Fixed::operator+( Fixed const &other )
{
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-( Fixed const &other )
{
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator/( Fixed const &other )
{
	return (this->toFloat() / other.toFloat());
}

float	Fixed::operator*( Fixed const &other )
{
	return (this->toFloat() * other.toFloat());
}

// prefix increment
Fixed&	Fixed::operator++(void)
{
	_val++; // += (1 << _nBits)
	return *this;
}

// postfix increment
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	
	_val++; // += (1 << _nBits)
	return (tmp);
}

// prefix decrement
Fixed&	Fixed::operator--(void)
{
	_val--; // -= (1 << _nBits)
	return *this;
}

// postfix decrement
Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);

	_val--; // -= (1 << _nBits)
	return (tmp);
}

const Fixed& Fixed::min(Fixed const &first, Fixed const &other)
{
	if (first < other)
		return first;
	return other;
}
Fixed& Fixed::min(Fixed &first, Fixed &other)
{
	if (first < other)
		return first;
	return other;
}
const Fixed& Fixed::max(Fixed const &first, Fixed const &other)
{
	if (first > other)
		return first;
	return other;
}
Fixed& Fixed::max(Fixed  &first, Fixed  &other)
{
	if (first > other)
		return first;
	return other;
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

	return toFloat();
}

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