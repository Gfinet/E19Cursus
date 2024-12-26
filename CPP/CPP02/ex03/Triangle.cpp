#include "Triangle.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Triangle::Triangle()
{
}

Triangle::Triangle(Line a, Line b, Line c): _a(a), _b(b), _c(c), _x(), _y(), _z()
{
	if (!intersection(a, c, _x, 0))
		std::cout << "ERROR : no intersections between first and last Line. " << a << " " << c << std::endl;
	if (!intersection(a, b, _y, 0))
		std::cout << "ERROR : no intersections between first and second Line. " << a << " " << b << std::endl;
	if (!intersection(b, c, _z, 0))
		std::cout << "ERROR : no intersections between second and last Line. " << b << " " << c << std::endl;
	if (!intersection(_a, _c, _x, 0) || !intersection(_a, _c, _y, 0) || !intersection(_a, _c, _z, 0))
	{
		_a = Line();
		_b = Line();
		_c = Line();
		_x = Point();
		_y = Point();
		_z = Point();
		std::cout << "Triangle has been emptyed" << std::endl;
	}
}

Triangle::Triangle(Point x, Point y, Point z) : _a(x,y), _b(y,z), _c(x,z), _x(x), _y(y), _z(z)
{
	if ((_x.get_x() == _y.get_x() && _y.get_x() == _z.get_x()))
		std::cout << "Impossible Triangle, same ord for every point." <<std::endl;
	else if (_x.get_y() == _y.get_y() && _y.get_y() == _z.get_y())
		std::cout << "Impossible Triangle, same abs for every point." << std::endl;
	if ((_x.get_x() == _y.get_x() && _y.get_x() == _z.get_x()) || (_x.get_y() == _y.get_y() && _y.get_y() == _z.get_y()))
	{
		_a = Line();
		_b = Line();
		_c = Line();
		_x = Point();
		_y = Point();
		_z = Point();
		std::cout << "Triangle has been emptyed" << std::endl;
	}
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

Fixed Triangle::get_leftest_point_abs()
{
	Fixed res;

	res = _x.get_x();
	if (res > _y.get_x())
		res = _y.get_x();
	if (res > _z.get_x())
		res = _z.get_x();
	return res;
}

Fixed Triangle::get_rightest_point_abs()
{
    Fixed res;

	res = _x.get_x();
	if (res < _y.get_x())
		res = _y.get_x();
	if (res < _z.get_x())
		res = _z.get_x();
	return res;
}

Fixed Triangle::get_top_point_ord()
{
	Fixed res;

	res = _x.get_y();
	if (res < _y.get_y())
		res = _y.get_y();
	if (res < _z.get_y())
		res = _z.get_y();
	return res;
}

Fixed Triangle::get_bot_point_ord()
{
	Fixed res;

	res = _x.get_y();
	if (res > _y.get_y())
		res = _y.get_y();
	if (res > _z.get_y())
		res = _z.get_y();
	return res;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Line Triangle::get_first_line() const
{
	return this->_a;
}
Line Triangle::get_second_line() const
{
	return this->_b;
}
Line Triangle::get_third_line() const
{
	return this->_c;
}

Point Triangle::get_first_point() const
{
	return this->_x;
}
Point Triangle::get_second_point() const
{
	return this->_y;
}
Point Triangle::get_third_point() const
{
	return this->_z;
}

/* ************************************************************************** */

int point_in_triangle(Triangle t, Point f)
{
	int nb_inter;
	Point p,tmp;
	Fixed x, y;
	Line inter;

	if ((f.get_x() == t.get_first_point().get_x() || f.get_x() == t.get_second_point().get_x() || f.get_x() == t.get_third_point().get_x())
		|| (f.get_y() == t.get_first_point().get_y() || f.get_y() == t.get_second_point().get_y() || f.get_y() == t.get_third_point().get_y()))
		return 0;
	x = t.get_leftest_point_abs() - 1;
	if (x == f.get_x())
		x--;
	y = f.get_y();
	p = Point(x, y);
	inter = Line(p, f);
	nb_inter = intersection(t.get_first_line(), inter, tmp, 0) && inter.on_line(tmp, 0);
	nb_inter += intersection(t.get_second_line(), inter, tmp, 0) && inter.on_line(tmp, 0);
	nb_inter += intersection(t.get_third_line(), inter, tmp, 0) && inter.on_line(tmp, 0);
	return (nb_inter % 2 == 0);
}