/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:32:18 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 17:09:17 by gfinet           ###   ########.fr       */
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
		if (_stock[i] != 0)
		{
			std::cout << "Materia " << _stock[i]->getType() << " deleted" << std::endl;
			delete _stock[i];
		}
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
	int find = -1;

	tmp = 0;
	for (int i = 0; i < 4; i++)
	{
		if (_stock[i] && _stock[i]->getType() == type)
			find = i;
		if (find != -1)
			break;
	}
	if (find == -1)
		std::cout << "Unknown Materia." << std::endl;
	else if (type == "ice")
		tmp = new Ice();
	else if (type == "cure")
		tmp = new Cure();
    return tmp;
}

void MateriaSource::learnMateria(AMateria *mat)
{
	if (_nbMat == 4 || !mat)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if(_stock[i] == 0)
		{
			std::cout << "Learned materia type " << mat->getType() << std::endl;
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