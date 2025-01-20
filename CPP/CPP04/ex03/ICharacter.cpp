#include "ICharacter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ICharacter::ICharacter()
{
	_Name = "Bobby";
	_nbMat = 0;
}

ICharacter::ICharacter( const ICharacter & src )
{

}

ICharacter::ICharacter(std::string const Name)
{
	_Name = Name;
	_nbMat = 0;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ICharacter::~ICharacter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ICharacter &				ICharacter::operator=( ICharacter const & rhs )
{
	if ( this != &rhs )
	{
		this->_nbMat = rhs._nbMat;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ICharacter const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */