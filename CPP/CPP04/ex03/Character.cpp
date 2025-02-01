/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:25:41 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:44:02 by gfinet           ###   ########.fr       */
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


/*
** --------------------------------- METHODS ----------------------------------
*/



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

std::string const &Character::getName() const
{
    return this->_Name;
}



/* ************************************************************************** */