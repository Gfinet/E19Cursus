/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:25:28 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/21 15:51:25 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{

	public:

		Character();
		Character( Character const & src );
		Character( std::string const & src );
		~Character();
		Character &	operator=( Character const & rhs );

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria* getMateria(int i) const;
		AMateria* getMateria(unsigned int i) const;
		unsigned int getNbMateria() const;
		void setName(const std::string &Name);
	private:

};

#endif /* ******************************************************* CHARACTER_H */