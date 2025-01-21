/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:18:11 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/21 15:50:58 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# pragma once
# include <iostream>
# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	protected:
		unsigned int _nbMat;
		std::string _Name;
		AMateria* _stuff[4];

	public:
		ICharacter();
		ICharacter( ICharacter const & src );
		ICharacter(std::string const Name);
		ICharacter &operator=( ICharacter const & rhs );
		virtual ~ICharacter() {}

		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
		virtual AMateria* getMateria(int i) const = 0;
		virtual AMateria* getMateria(unsigned int i) const = 0;
		virtual unsigned int getNbMateria() const = 0;
};


#endif 
/* ****************************************************** ICHARACTER_H */