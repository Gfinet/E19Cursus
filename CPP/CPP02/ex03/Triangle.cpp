#include "Triangle.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Triangle::Triangle()
{
}

Triangle::Triangle(Line a, Line b, Line c): _a(a), _b(b), _c(c), _x(), _y(), _z()
{
	Point *p = NULL;

	p = intersection(a, c);
	if (p)
		_x = *p;
	else
		std::cout << "ERROR : no intersections between first and last Line." << std::endl;
	p = intersection(a, b);
	if (p)
		_y = *p;
	else
		std::cout << "ERROR : no intersections between first and second Line." << std::endl;
	p = intersection(b, c);
	if (p)
		_z = *p;
	else
		std::cout << "ERROR : no intersections between second and last Line." << std::endl;
}

Triangle::Triangle(Point x, Point y, Point z) : _a(x,y), _b(y,z), _c(x,z), _x(x), _y(y), _z(z)
{
}

Triangle::Triangle( const Triangle & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Triangle::~Triangle()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Triangle &				Triangle::operator=( Triangle const & rhs )
{
	if ( this != &rhs )
	{
		_x = rhs._x;
		_y = rhs._y;
		_z = rhs._z;
		_a = rhs._a;
		_b = rhs._b;
		_c = rhs._c;
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Triangle const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */