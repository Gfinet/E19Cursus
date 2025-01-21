/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:32:18 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/21 17:42:55 by gfinet           ###   ########.fr       */
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

void MateriaSource::learnMateria(AMateria *)
{
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */