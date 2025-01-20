#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure()
{
}

Cure::Cure( const Cure & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cure const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Cure::use(Character& target) const
{
	std::cout << " heals " << target.getName() << " wounds ";
}

Cure* Cure::clone() const
{
	Cure* clon;

	clon = new Cure(*this);
	return clon;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */