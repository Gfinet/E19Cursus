/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:18:11 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/27 15:16:27 by gfinet           ###   ########.fr       */
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
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
		
		void setName(const std::string &Name);
		std::string const & getName() const;
		AMateria* getMateria(int i) const;
		AMateria* getMateria(unsigned int i) const;
		unsigned int getNbMateria() const;
};


#endif 
/* ****************************************************** ICHARACTER_H */