#include "Fixed.hpp"

int Fixed::_nbBit = 8;
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_val = 0;
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed&	Fixed::operator=( Fixed const &other )
{
	std::cout << "Copy Assignement operator called" << std::endl;
	if (this != &other)
		this->_val = other._val;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_val = raw;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

/* ************************************************************************** */