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

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_val);
}

/* ************************************************************************** */