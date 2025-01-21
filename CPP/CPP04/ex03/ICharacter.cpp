/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:25:43 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/21 15:27:21 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ICharacter::ICharacter()
{
	_Name = "Bobby";
	_nbMat = 0;
	for (int i=0; i<4; i++)
		_stuff[i] = 0;
}

ICharacter::ICharacter( const ICharacter & src )
{
	*this = src;
}

ICharacter::ICharacter(std::string const Name)
{
	_Name = Name;
	_nbMat = 0;
	for (int i=0; i<4; i++)
		_stuff[i] = 0;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ICharacter &				ICharacter::operator=( ICharacter const & rhs )
{
	if ( this != &rhs )
	{
		this->_Name = rhs.getName();
		this->_nbMat = rhs.getNbMateria();
		for (int i=0; i<4; i++)
		{
			if (_stuff[i])
				delete _stuff[i];
			_stuff[i] = rhs._stuff[i]->clone();
		}
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */