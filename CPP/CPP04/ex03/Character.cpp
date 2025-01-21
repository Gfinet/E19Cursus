/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:25:41 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/21 17:45:37 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : ICharacter()
{
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
	for (int i=0; i<4; i++)
		if (_stuff[i])
			delete _stuff[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Character &				Character::operator=( Character const & rhs )
// {
// 	if ( this != &rhs )
// 	{
// 		this->setName(rhs._Name);
// 		for (int i=0; i < 4; i++)
// 		{
// 			if (_stuff[i])
// 				delete _stuff[i];
// 			_stuff[i] = rhs.getMateria(i)->clone();
// 		}
// 		_nbMat = rhs.getNbMateria();
// 	}
// 	return *this;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::setName(const std::string &Name)
{
	this->_Name = Name;
}

void Character::equip(AMateria *m)
{	
	if (_nbMat < 4)
	{
		for (int i = 0; i < 4 ; i++)
		{
			if (!_stuff[i])
			{
				_stuff[i] = m;
				break;
			}
			
		}
		_nbMat++;
	}
}

void Character::unequip(int idx)
{
	if (_nbMat != 0)
	{
		_stuff[idx] = 0;
		_nbMat--;
	}
}

void Character::use(int idx, ICharacter &target)
{
	//std::cout << _Name ;
	if (_stuff[idx])
		_stuff[idx]->use(target);
	else
	{
		std::cout << "* farts on " << target.getName() << " *" << std::endl;	
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

AMateria* Character::getMateria(int i) const
{
	if (_stuff[i])
		return _stuff[i];
	return NULL;
}

AMateria* Character::getMateria(unsigned int i) const
{
	return getMateria((int)i);
}

unsigned int Character::getNbMateria() const
{
	return this->_nbMat;
}


std::string const &Character::getName() const
{
	return this->_Name;
}



/* ************************************************************************** */