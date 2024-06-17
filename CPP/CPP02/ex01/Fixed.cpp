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
	int e = 0,f = 0;
	
	f = n >> 24;
	std::cout << "Default constructor called\n";
	_intVal = n;
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
	return (this->_intVal);
}

/* ************************************************************************** */

std::ostream &operator<<( std::ostream &o, Fixed const &i )
{
	o << i.getRawBits();
	return o;
}