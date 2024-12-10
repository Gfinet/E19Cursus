#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include <iostream>
# include <string>
# include "Line.hpp"

class Triangle
{
	private:
		Line _a, _b, _c;
		Point _x, _y, _z;
	public:

		Triangle();
		Triangle(Line a, Line b, Line c);
		Triangle(Point x, Point y, Point z);
		Triangle( Triangle const & src );
		~Triangle();

		Triangle &		operator=( Triangle const & rhs );

};

std::ostream &			operator<<( std::ostream & o, Triangle const & i );

#endif /* ******************************************************** TRIANGLE_H */