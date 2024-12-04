#include "Line.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Line::Line(): _x(), _y(), _m(0), _b(0), _func()
{
}

Line::Line(const Point x, const Point y): _x(x), _y(y)
{
    _m = (float)((_x.get_x().toFloat() - _y.get_x().toFloat()) / (x.get_y().toFloat() - _y.get_y().toFloat()));
    _b = (float)(_x.get_y().toFloat()) - _m;
    _func = "y = " + std::to_string(_m) + "x + " + std::to_string(_b);
}

Line::Line( const Line & src )
{
    *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Line::~Line()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Line &				Line::operator=( Line const & rhs )
{
	if ( this != &rhs )
	{
        _x = rhs._x;
        _y = rhs._y;
        _b = rhs._b;
		_m = rhs._m;
        _func = rhs._func;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Line const & i )
{
	o << i.get_func();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Line::get_func() const
{
    return this->_func;
}

Point Line::get_x() const
{
    return this->_x;
}

Point Line::get_y() const
{
    return this->_y;
}

float Line::get_m() const
{
    return this->_m;
}

float Line::get_b() const
{
    return this->_b;
}

/* ************************************************************************** */

void intersection(Line &a, Line &b, Point *p)
{
    if ()

}