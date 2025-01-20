#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "Character.hpp"

class Cure : virtual public AMateria
{

	public:

		Cure();
		Cure( Cure const & src );
		~Cure();
		Cure &operator=( Cure const & rhs );

		void use(Character& target) const;
		Cure* clone() const;
	private:

};

std::ostream &			operator<<( std::ostream & o, Cure const & i );

#endif /* ************************************************************ CURE_H */