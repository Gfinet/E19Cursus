/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:32:21 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/21 17:43:29 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

IMateriaSource::IMateriaSource()
{
	_nbMat = 0;
	for (int i = 0; i<4; i++)
		_stock[i] = 0;
}

IMateriaSource::IMateriaSource( const IMateriaSource & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

IMateriaSource &				IMateriaSource::operator=( IMateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i<4; i++)
		{
			if (_stock[i])
				delete _stock[i];
			if (rhs._stock[i])
				_stock[i] = rhs._stock[i]->clone();
		}
		_nbMat = rhs._nbMat;
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