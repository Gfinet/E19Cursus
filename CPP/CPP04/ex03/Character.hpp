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

		std::string const & getName() const = 0;
		void equip(AMateria* m) = 0;
		void unequip(int idx) = 0;
		void use(int idx, ICharacter& target) = 0;
		AMateria& getMateria(int i) const;
		AMateria& getMateria(unsigned int i) const;
		unsigned int getNbMateria() const;
	private:

};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */