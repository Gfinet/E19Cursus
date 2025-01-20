#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
# include "Ice.hpp"
# include "Cure.hpp"

class ICharacter
{
	protected:
		unsigned int _nbMat;
		std::string _Name;
		AMateria* _stuff;

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
		virtual AMateria& getMateria(int i) const = 0;
		virtual AMateria& getMateria(unsigned int i) const = 0;
		virtual unsigned int getNbMateria() const = 0;
};

std::ostream &			operator<<( std::ostream & o, ICharacter const & i );

#endif 
/* ****************************************************** ICHARACTER_H */