#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : ICharacter()
{
	_Name = "Bobby";
}

Character::Character( const Character & src ) : ICharacter(src)
{
}

Character::Character( const std::string& Name ) : ICharacter(Name)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->_Name = rhs.getName();
		delete[] _stuff;
		for (int i=0; i < 4; i++)
			_stuff[i] = rhs.getMateria(i).clone();
		_nbMat = rhs.getNbMateria();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
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

AMateria& Character::getMateria(int i) const
{
	return _stuff[i];
}

AMateria& Character::getMateria(unsigned int i) const
{
	return getMateria((int)i);
}

unsigned int Character::getNbMateria() const
{
	return this->_nbMat;
}

/* ************************************************************************** */