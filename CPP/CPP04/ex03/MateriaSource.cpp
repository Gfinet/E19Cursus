/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:32:18 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/21 18:13:50 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource() : IMateriaSource()
{
}

MateriaSource::MateriaSource( const MateriaSource & src ) : IMateriaSource(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i<4; i++)
		if (_stock[i])
			delete _stock[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria* tmp;

	tmp = 0;
	if (type == "ice")
		tmp = new Ice();
	else if (type == "cure")
		tmp = new Cure();
	else
		std::cout << "Unknown Materia." << std::endl;
    return tmp;
}

void MateriaSource::learnMateria(AMateria *mat)
{
	if (_nbMat == 4)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if(_stock[i] == 0)
		{
			_stock[i] = mat;
			break;
		}
	}
	_nbMat++;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */