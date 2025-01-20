#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria()
{
	this->_type = "ice";
}

Ice::Ice( const Ice & src ) : AMateria(src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Ice const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Ice::use(Character& target) const
{
	std::cout << " shoot an ice bolt at " << target.getName() << " ";
}

Ice* Ice::clone() const
{
	Ice* clon;

	clon = new Ice(*this);
	return clon;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */